#!/usr/bin/perl
use strict;
BEGIN {
	$|  = 1;
	$^W = 1;
}

use t::lib::Test qw/connect_ok $sqlite_call/;
use Test::More;
use Test::NoWarnings;
use FindBin;

my $dbfile = "tmp.sqlite";

my @tests = (
  ["VirtualTable"   => qw[lib/DBD/SQLite.pm
                          lib/DBD/SQLite/VirtualTable.pm
                          lib/DBD/SQLite/VirtualTable/FileContent.pm
                          lib/DBD/SQLite/VirtualTable/PerlData.pm]],
  ["install_method" => qw[lib/DBD/SQLite.pm]],
  ['"use strict"'   => qw[inc/Test/NoWarnings.pm
                          inc/Test/NoWarnings/Warning.pm
                          lib/DBD/SQLite.pm
                          lib/DBD/SQLite/VirtualTable.pm
                          lib/DBD/SQLite/VirtualTable/FileContent.pm
                          lib/DBD/SQLite/VirtualTable/PerlData.pm
                          t/lib/Test.pm
                          util/getsqlite.pl]],
  ['"use strict" AND "use warnings"' => qw[inc/Test/NoWarnings.pm
                                           lib/DBD/SQLite/VirtualTable.pm
                                           lib/DBD/SQLite/VirtualTable/FileContent.pm
                                           lib/DBD/SQLite/VirtualTable/PerlData.pm
                                           ]],
);

plan tests => 3 + 3 * @tests;

# find out perl files in this distrib
my $distrib_dir = "$FindBin::Bin/../..";
open my $fh, "<", "$distrib_dir/MANIFEST" or die "open $distrib_dir/MANIFEST: $!";
my @files = <$fh>;
close $fh;
chomp foreach @files;
my @perl_files = grep {/\.(pl|pm|pod)$/} @files;

# open database
my $dbh = connect_ok( dbfile => $dbfile, RaiseError => 1, AutoCommit => 1 );

# create the source table and populate it
$dbh->do("CREATE TABLE files (id INTEGER PRIMARY KEY, path TEXT)");
my $sth = $dbh->prepare("INSERT INTO files(path) VALUES (?)");
$sth->execute($_) foreach @perl_files;


# create the virtual table
$dbh->$sqlite_call(create_module => fc => "DBD::SQLite::VirtualTable::FileContent");
$dbh->do(<<"");
  CREATE VIRTUAL TABLE vfc USING fc(source = files,
                                    expose = "path",
                                    root   = "$distrib_dir")

# create the fulltext indexing table and populate it
$dbh->do('CREATE VIRTUAL TABLE fts USING fts4(content="vfc")');
note "building fts index....";
$dbh->do("INSERT INTO fts(fts) VALUES ('rebuild')");
note "done";

# start tests
my $sql = "SELECT path FROM fts WHERE fts MATCH ?";
foreach my $test (@tests) {
  my ($pattern, @expected)  = @$test;
  my $paths = $dbh->selectcol_arrayref($sql, {}, $pattern);
  is_deeply([sort @$paths], \@expected, "search '$pattern'");
}

# remove one document
my $remove_path = 'lib/DBD/SQLite/VirtualTable.pm';
$dbh->do("DELETE FROM fts WHERE path='$remove_path'");


# test again
foreach my $test (@tests) {
  my ($pattern, @expected)  = @$test;
  @expected = grep {$_ ne $remove_path} @expected;
  my $paths = $dbh->selectcol_arrayref($sql, {}, $pattern);
  is_deeply([sort @$paths], \@expected, "search '$pattern' -- no $remove_path");
}

# see if data was properly stored: disconnect, reconnect and test again
$dbh->disconnect;
undef $dbh;
$dbh = connect_ok( dbfile => $dbfile, RaiseError => 1, AutoCommit => 1 );
$dbh->$sqlite_call(create_module => fc => "DBD::SQLite::VirtualTable::FileContent");

foreach my $test (@tests) {
  my ($pattern, @expected)  = @$test;
  @expected = grep {$_ ne $remove_path} @expected;
  my $paths = $dbh->selectcol_arrayref($sql, {}, $pattern);
  is_deeply([sort @$paths], \@expected, "search '$pattern' -- after reconnect");
}

