use Test;
BEGIN { plan tests => 2 }
use DBI;
my $dbh = DBI->connect("dbi:SQLite:dbname=foo", "", "");
ok($dbh);
ok($dbh->{sqlite_version});
print "# sqlite_version=$dbh->{sqlite_version}\n";
$dbh->disconnect;

