use strict;

package static_aggregate;

my $count;

sub init {
    $count = 0;
}

sub step {
    $count++;
}

sub finalize {
    return $count;
}

package obj_aggregate;

sub new {
    bless {}, shift;
}

sub init {
    $_[0]{count} = 0;
}

sub step {
    $_[0]{count}++
        if defined $_[1];
}

sub finalize {
    return $_[0]{count};
}

package fail_aggregate;

sub new {
        bless { fail => $_[1] }, $_[0];
}

sub init {
    die "init() failed on request"
        if $_[0]{fail} eq 'init';
}

sub step {
    die "step() failed on request"
        if $_[0]{fail} eq 'step';
}

sub finalize {
    die "finalize() failed on request"
        if $_[0]{fail} eq 'finalize';
}

package main;

use Test;
BEGIN { plan tests => 14 }
use DBI;

my $dbh = DBI->connect("dbi:SQLite:dbname=foo", "", "", { PrintError => 0 } );
ok($dbh);

$dbh->do( "DROP TABLE aggr_test;" );
$dbh->do( "CREATE TABLE aggr_test ( field )" );
foreach my $val ( qw/NULL 1 'test'/ ) {
    $dbh->do( "INSERT INTO aggr_test VALUES ( $val )" );
}

$dbh->func( "static_aggr", 0, "static_aggregate", "create_aggregate" );
my $result = $dbh->selectrow_arrayref( "SELECT static_aggr() FROM aggr_test" );
ok( $result && $result->[0] == 3 );
# Make sure that the init() function is called correctly
$result = $dbh->selectrow_arrayref( "SELECT static_aggr() FROM aggr_test" );
ok( $result && $result->[0] == 3 );

# Test aggregate on empty table
$dbh->do( "DROP TABLE aggr_empty_test;" );
$dbh->do( "CREATE TABLE aggr_empty_test ( field )" );
$result = $dbh->selectrow_arrayref( "SELECT static_aggr() FROM aggr_empty_test" );
ok( $result && $result->[0] == 0 );
# Make sure that the init() function is called correctly
$result = $dbh->selectrow_arrayref( "SELECT static_aggr() FROM aggr_empty_test" );
ok( $result && $result->[0] == 0 );

my $obj = new obj_aggregate();
$dbh->func( "defined", 1, $obj, "create_aggregate" );
$result = $dbh->selectrow_arrayref( "SELECT defined(field) FROM aggr_test" );
ok( $result && $result->[0] == 2 );
$result = $dbh->selectrow_arrayref( "SELECT defined(field) FROM aggr_test" );
ok( $result && $result->[0] == 2 );
$result = $dbh->selectrow_arrayref( "SELECT defined(field) FROM aggr_empty_test" );
ok( $result && $result->[0] == 0 );
$result = $dbh->selectrow_arrayref( "SELECT defined(field) FROM aggr_empty_test" );
ok( $result && $result->[0] == 0 );

my $last_warn;
local $SIG{__WARN__} = sub { $last_warn = join "", @_ };
foreach my $fail ( qw/init step finalize/ ) {
    $last_warn = '';    
    my $aggr = new fail_aggregate( $fail );
    $dbh->func( "fail_$fail", -1, $aggr, 'create_aggregate' );
    $result = $dbh->selectrow_arrayref( "SELECT fail_$fail() FROM aggr_test" );
#   ok( !$result && $DBI::errstr =~ /$fail\(\) failed on request/ );
    ok( !defined $result->[0] && $last_warn =~ /$fail\(\) failed on request/ );

    # No need to check this one, since step() will never be called
    # on an empty table
    next if $fail eq 'step';
    $result = $dbh->selectrow_arrayref( "SELECT fail_$fail() FROM aggr_empty_test" );
#    ok( !$result && $DBI::errstr =~ /$fail\(\) failed on request/ );
    ok( !defined $result->[0] && $last_warn =~ /$fail\(\) failed on request/ );
}

