eval {
    require DBI;
    require DBI::DBD;
};
use ExtUtils::MakeMaker;
use strict;

WriteMakefile(
    'NAME'          => 'DBD::SQLite',
    'VERSION_FROM'  => 'lib/DBD/SQLite.pm', # finds $VERSION
    'PREREQ_PM'     => {DBI => 1.03}, # e.g., Module::Name => 1.1
    'OBJECT'        => '$(O_FILES)',
    'INC'           => '-I$(DBI_INSTARCH_DIR)',
    'clean'         => { FILES => 'SQLite.xsi' },
);

package MY;
sub postamble { DBI::DBD::dbd_postamble(@_); }
sub libscan {
    my ($self, $path) = @_;
    ($path =~ m/\~$/) ? undef : $path;
}
