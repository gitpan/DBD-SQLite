use Test;
plan tests => 3;

use DBI;
unlink('foo');
my $dbh = DBI->connect("dbi:SQLite:dbname=foo", "", "", { RaiseError => 1 });
ok($dbh);

$dbh->do("CREATE TABLE foo (id integer primary key)");
$dbh->do("INSERT INTO foo VALUES (1)");
$dbh->do("INSERT INTO foo VALUES (2)");
$dbh->do("INSERT INTO foo VALUES (3)");
$dbh->do("INSERT INTO foo VALUES (4)");

my $sth = $dbh->prepare("SELECT * FROM foo");
$sth->execute;

while (my $row = $sth->fetch) {
    ok($row);
    last if $row->[0] == 2;
}

$sth->finish;

$dbh->disconnect;
