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
    'OPTIMIZE'      => '-O6 -DNDEBUG=1',
    'clean'         => { FILES => 'SQLite.xsi config.h' },
);

package MY;
sub top_targets {
  my $class = shift;
  my $default = $class->SUPER::top_targets;
  $default =~ s/config :: Makefile/config :: Makefile config.h/;
  
  return $default . <<'EOT';

config.h:       
	echo '#include <stdio.h>' >temp.c
	echo 'int main(){printf(' >>temp.c
	echo '"#define SQLITE_PTR_SZ %d\n",sizeof(char*));' >>temp.c
	echo 'exit(0);}' >>temp.c
	$(CC) -o temp temp.c
	./temp >config.h
	rm -f temp.c temp

EOT
}

sub postamble { 
  DBI::DBD::dbd_postamble(@_);
}
sub libscan {
    my ($self, $path) = @_;
    ($path =~ m/\~$/) ? undef : $path;
}
