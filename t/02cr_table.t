use Test;
BEGIN { plan tests => 2 }
use DBI;
my $dbh = DBI->connect("dbi:SQLite:dbname=foo", "", "");
ok($dbh);
$dbh->{AutoCommit} = 1;
$dbh->do("CREATE TABLE f (f1, f2, f3)");
my $sth = $dbh->prepare("SELECT * FROM f");
ok($sth->execute());
my $names = $sth->{NAME};
print(join(', ', @$names), "\n");
$sth->finish;
$dbh->disconnect;
