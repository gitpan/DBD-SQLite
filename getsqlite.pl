use strict;
use LWP::Simple qw(getstore);
use Fatal qw(chdir);

my $version = shift || die "Usage: getsqlite.pl <version>\n";

print("downloading http://www.hwaci.com/sw/sqlite/sqlite-$version.tar.gz\n");
if (getstore(
	"http://www.hwaci.com/sw/sqlite/sqlite-$version.tar.gz", 
	"sqlite.tar.gz") != 200) {
   die "Failed to download";
}
print("done\n");

xsystem("rm -fR sqlite");
xsystem("tar zxvf sqlite.tar.gz");
chdir("sqlite");
xsystem("sh configure --enable-utf8");
xsystem("make parse.c sqlite.h opcodes.h opcodes.c");

while (<DATA>) {
    chomp;
    xsystem("cp $_ ../");
}

exit(0);

sub xsystem {
    local $, = ", ";
    print("@_\n");
    my $ret = system(@_);
    if ($ret != 0) {
       die "system(@_) failed: $?";
    }
}

__DATA__
parse.c
parse.h
sqlite.h
opcodes.h
opcodes.c
src/auth.c
src/btree.h
src/btree.c
src/build.c
src/delete.c
src/expr.c
src/func.c
src/hash.c
src/hash.h
src/insert.c
src/main.c
src/os.c
src/os.h
src/pager.c
src/pager.h
src/printf.c
src/random.c
src/select.c
src/sqliteInt.h
src/table.c
src/trigger.c
src/tokenize.c
src/update.c
src/util.c
src/vdbe.c
src/vdbe.h
src/where.c
