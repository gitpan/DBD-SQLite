# -*- perl -*-

require 5.004;
use strict;

require DBI;
require Benchmark;

my $haveFileSpec = eval { require File::Spec };
my $table_dir;
if ($haveFileSpec) {
    $table_dir = File::Spec->catdir(File::Spec->curdir(), 'output');
} else {
    $table_dir = "output";
}
if (! -d $table_dir  &&  ! mkdir $table_dir, 0755) {
    die "Cannot create 'output' directory: $!";
}


my($i);
sub TimeMe ($$$$) {
    my($startMsg, $endMsg, $code, $count) = @_;
    printf("\n%s\n", $startMsg);
    my($t1) = Benchmark->new();
    $@ = '';
    eval {
	for ($i = 0;  $i < $count;  $i++) {
	    &$code;
	}
    };
    if ($@) {
	print "Test failed, message: $@\n";
    } else {
	my($td) = Benchmark::timediff(Benchmark->new(), $t1);
	my($dur) = $td->cpu_a;
	printf($endMsg, $count, $dur, $count / $dur);
	print "\n";
    }
}


TimeMe("Testing empty loop speed ...",
       "%d iterations in %.1f cpu+sys seconds (%d per sec)",
       sub {},
       100000);


unlink $haveFileSpec ?
    File::Spec->catfile($table_dir, 'database') : "output/database";

TimeMe("Testing connect/disconnect speed ...",
       "%d connections in %.1f cpu+sys seconds (%d per sec)",
       sub {
	   my $dbh = DBI->connect("DBI:SQLite:dbname=$table_dir/database", undef, undef,
			       { 'RaiseError' => 1 });
	   $dbh->disconnect();
       },
    2000);

unlink $haveFileSpec ?
    File::Spec->catfile($table_dir, 'bench') : "output/bench";

unlink $haveFileSpec ?
    File::Spec->catfile($table_dir, 'database') : "output/database";

my $dbh = DBI->connect("DBI:SQLite:dbname=".File::Spec->catfile($table_dir, "database"), undef, undef,
                    { 'RaiseError' => 1 });

TimeMe("Testing CREATE/DROP TABLE speed ...",
       "%d files in %.1f cpu+sys seconds (%d per sec)",
       sub {
	   $dbh->do("CREATE TABLE bench (id INTEGER, name CHAR(40),"
		    . " firstname CHAR(40), address CHAR(40),"
		    . " zip CHAR(10), city CHAR(40), email CHAR(40))");
	   $dbh->do("DROP TABLE bench");
       },
    500);

$dbh->do("CREATE TABLE bench (id INTEGER, name CHAR(40),"
    . " firstname CHAR(40), address CHAR(40),"
    . " zip CHAR(10), city CHAR(40), email CHAR(40))");
my(@vals) = (0 .. 499);
my($num);
TimeMe("Testing INSERT speed ...",
       "%d rows in %.1f cpu+sys seconds (%d per sec)",
       sub {
	   ($num) = splice(@vals, int(rand(@vals)), 1);
	   $dbh->do("INSERT INTO bench VALUES (?, 'Wiedmann', 'Jochen',"
		    . " 'Am Eisteich 9', '72555', 'Metzingen',"
		    . " 'joe\@ispsoft.de')", undef, $num);
       },
    500);

my($sth);
TimeMe("Testing SELECT speed ...",
       "%d single rows in %.1f cpu+sys seconds (%.1f per sec)",
       sub {
	   $num = int(rand(500));
	   $sth = $dbh->prepare("SELECT * FROM bench WHERE id = $num");
	   $sth->execute();
	   $sth->fetch() or die "Expected result for id = $num";
       },
    100);


TimeMe("Testing SELECT speed (multiple rows) ...",
       "%d times 100 rows in %.1f cpu+sys seconds (%.1f per sec)",
       sub {
	   $num = int(rand(400));
	   $sth = $dbh->prepare("SELECT * FROM bench WHERE id >= $num"
				. " AND id < " . ($num+100));
	   $sth->execute();
	   ($sth->rows() == 100)
	       or die "Expected 100 rows for id = $num, got " . $sth->rows();
	   while ($sth->fetch()) {
	   }
       },
    100);

print "Creating table with 100_000 rows\n";
$dbh->do("CREATE TABLE largerandom ( id INTEGER NOT NULL PRIMARY KEY, val CHAR(40) NOT NULL )");
$dbh->{AutoCommit} = 0;
print "First generating 100_000 random strings\n";
my @foo;
for (1..100_000) {
    push @foo, join('', map {chr(rand(57)+65)} (1..8));
}

my $i = 0;
my $sth = $dbh->prepare("INSERT INTO largerandom (val) VALUES (?)");
TimeMe("Now inserting ...",
       "%d rows in %.1f cpu+sys seconds (%.1f per sec)",
        sub {
            my $random = $foo[$i++];
            unless ($i % 10000) {
                print("inserting row $i\n");
                $dbh->commit;
            }
            $sth->execute($random);
        },
        100_000,
        );

$dbh->commit;
$sth->finish;

$dbh->do("CREATE INDEX idx_lr_val ON largerandom (val)");
$dbh->commit;

TimeMe("Testing SELECT speed (large table) ...",
       "%d times 10000 rows in %.1f cpu+sys seconds (%.1f per sec)",
       sub {
        my $sth = $dbh->prepare("SELECT * FROM largerandom LIMIT 10000");
        $sth->execute();
        ($sth->rows() == 10000)
           or die "Expected 10000 rows for id = $num, got " . $sth->rows();
        1 while $sth->fetch();
       },
    100);

$dbh->disconnect;
