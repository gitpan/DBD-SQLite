eval {
    require DBI;
    require DBI::DBD;
    die "Your DBI Version is too old - require at least 1.03"
        unless $DBI::VERSION >= 1.03;
};
use ExtUtils::MakeMaker;
use Config;
use strict;
eval {
    require DBD::SQLite;
    if ($DBD::SQLite::VERSION < 1.0) {
        print <<EOT;

**** WARNING **** WARNING **** WARNING **** WARNING **** WARNING ****

Your version of DBD::SQLite currently installed ($DBD::SQLite::VERSION) uses
the old sqlite database format. This version of DBD::SQLite will *NOT*
open these files, and installing this module may cause problems on your
system. If this is a live environment you should upgrade with caution.

To upgrade a database, download and install both sqlite 2.x and 3.x from
http://www.sqlite.org/ and issue:

  sqlite OLD.DB .dump | sqlite3 NEW.DB

DBD::SQLite will NOT automatically upgrade a database for you, and using
this version against an old SQLite database WILL lead to database
corruption.

EOT
        if (prompt("Continue?", "N") !~ /^y/i) {
            print "Exiting\n";
            exit -1;
        }
    }
};

my $nlid = $DBI::VERSION > 1.42 ? '' : '-Dno_last_insert_id';

WriteMakefile(
    'NAME'          => 'DBD::SQLite',
    'VERSION_FROM'  => 'lib/DBD/SQLite.pm', # finds $VERSION
    'PREREQ_PM'     => {DBI => 1.21}, # e.g., Module::Name => 1.1
    'OBJECT'        => '$(O_FILES)',
    'INC'           => '-I$(DBI_INSTARCH_DIR)',
    'OPTIMIZE'      => "-O2",
    'DEFINE'        => "-DNDEBUG=1 -DSQLITE_PTR_SZ=$Config{ptrsize}" .
                       ($Config{d_usleep} ? " -DHAVE_USLEEP=1" : "") .
                       ($DBI::VERSION > 1.42 ? '' : ' -Dno_last_insert_id'),
    'clean'         => { FILES => 'SQLite.xsi config.h' },
    'PL_FILES'      => {},
    'EXE_FILES'     => [],
);

package MY;
sub postamble { 
  DBI::DBD::dbd_postamble(@_);
}
sub libscan {
    my ($self, $path) = @_;
    ($path =~ m/\~$/) ? undef : $path;
}
