use Test;
BEGIN { plan tests => 1 }
use DBI;
my $dbh = DBI->connect("dbi:SQLite:dbname=foo", "", "");
ok($dbh);
$dbh->disconnect;

