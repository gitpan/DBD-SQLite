use DBI 1.03;
use DBI::DBD;
use ExtUtils::MakeMaker;
use strict;

WriteMakefile(
    'NAME'          => 'DBD::SQLite',
    'VERSION_FROM'  => 'lib/DBD/SQLite.pm', # finds $VERSION
    'PREREQ_PM'     => {}, # e.g., Module::Name => 1.1
    'OBJECT'        => '$(O_FILES)',
    'INC'           => '-I$(DBI_INSTARCH_DIR)',
    'clean'         => { FILES => 'SQLite.xsi' },
);

sub MY::postamble {
    return dbd_postamble();
}
