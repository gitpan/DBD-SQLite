#!perl

use Test;
BEGIN { plan tests => 8 }
use DBI;

unlink('foo', 'foo-journal');
my $db = DBI->connect('dbi:SQLite:foo', '', '', 
{
    RaiseError => 1,
    PrintError => 0,
    AutoCommit => 0,
});

my $db2 = DBI->connect('dbi:SQLite:foo', '', '', 
{
    RaiseError => 1,
    PrintError => 0,
    AutoCommit => 0,
});

ok($db2->func(3000, 'busy_timeout'));

ok($db->do("CREATE TABLE Blah ( id INTEGER, val VARCHAR )"));
ok($db->commit);
ok($db->do("INSERT INTO Blah VALUES ( 1, 'Test1' )"));
my $start = time;
eval {
    $db2->do("INSERT INTO Blah VALUES ( 2, 'Test2' )");
};
ok($@);
if ($@) {
    print "# insert failed : $@";
    $db2->rollback;
}

$db->commit;
ok($db2->do("INSERT INTO Blah VALUES ( 2, 'Test2' )"));
$db2->commit;

$db2->disconnect;
undef($db2);

# Now test that two processes can write at once, assuming we commit timely.

pipe(READER, WRITER);
my $pid = fork;
if (!defined($pid)) {
    # fork failed
    skip("No fork here", 1);
    skip("No fork here", 1);
    exit;
}
if ($pid) {
    # parent
    my $db2 = DBI->connect('dbi:SQLite:foo', '', '', 
    {
        RaiseError => 1,
        PrintError => 0,
        AutoCommit => 0,
    });
    my $line = <READER>;
    chomp($line);
    ok($line, "Ready");
    $db2->func(10000, 'busy_timeout');
    ok($db2->do("INSERT INTO Blah VALUES (4, 'Test4' )"));
    $db2->commit;
    exit;
}

$db->do("INSERT INTO Blah VALUES ( 3, 'Test3' )");
print WRITER "Ready\n";
sleep(5);
$db->commit;
 

