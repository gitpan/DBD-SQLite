use Test;
BEGIN { plan tests => 4 }
use DBI;
my $dbh = DBI->connect("dbi:SQLite:dbname=foo", "", "");
ok($dbh);
my $sth = $dbh->prepare("INSERT INTO f VALUES (?, ?, ?)");
ok($sth);
ok($sth->execute("Fred", "Bloggs", "fred\@bloggs.com"));
ok($dbh->func('last_insert_rowid'));
$sth->finish;
$dbh->disconnect;
