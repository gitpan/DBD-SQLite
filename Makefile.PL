require DBI;
require DBI::DBD;
die "Your DBI Version is too old - require at least 1.03"
    unless $DBI::VERSION >= 1.03;
use ExtUtils::MakeMaker;
use Config;
use strict;
eval {
    require DBD::SQLite;
    if ($DBD::SQLite::VERSION < 1.0) {
        print <<EOT;
Your version of DBD::SQLite currently installed ($DBD::SQLite::VERSION) uses
the old sqlite database format. This version of DBD::SQLite will *NOT*
open these files, and installing this module may cause problems on your
system. If this is a live environment you should upgrade with caution.
EOT
        if (prompt("Continue?", "N") !~ /^y/i) {
            print "Exiting\n";
            exit -1;
        }
    }
};

WriteMakefile(
    'NAME'          => 'DBD::SQLite',
    'VERSION_FROM'  => 'lib/DBD/SQLite.pm', # finds $VERSION
    'PREREQ_PM'     => {DBI => 1.21}, # e.g., Module::Name => 1.1
    'OBJECT'        => '$(O_FILES)',
    'INC'           => '-I$(DBI_INSTARCH_DIR)',
    'OPTIMIZE'      => "-O2 -DNDEBUG=1 -DSQLITE_PTR_SZ=$Config{ptrsize}",
    'clean'         => { FILES => 'SQLite.xsi config.h' },
);

package MY;
sub postamble { 
  DBI::DBD::dbd_postamble(@_);
}
sub libscan {
    my ($self, $path) = @_;
    ($path =~ m/\~$/) ? undef : $path;
}
