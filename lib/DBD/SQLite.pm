# $Id: SQLite.pm,v 1.6 2002/02/19 17:35:42 matt Exp $

package DBD::SQLite;
use strict;

use DBI;

use vars qw($err $errstr $state $drh $VERSION @ISA);
$VERSION = '0.05';

use DynaLoader();
@ISA = ('DynaLoader');

__PACKAGE__->bootstrap($VERSION);

$err = 0;
$errstr = "";
$state = "";

$drh = undef;

sub driver {
    return $drh if $drh;
    my ($class, $attr) = @_;

    $class .= "::dr";

    $drh = DBI::_new_drh($class, {
        Name        => 'SQLite',
        Version     => $VERSION,
        Err         => \$DBD::SQLite::err,
        Errstr      => \$DBD::SQLite::errstr,
        State       => \$DBD::SQLite::state,
        Attribution => 'DBD::SQLite by Matt Sergeant',
    });

    return $drh;
}

package DBD::SQLite::dr;

sub connect {
    my ($drh, $dbname, $user, $auth, $attr) = @_;

    my $dbh = DBI::_new_dbh($drh, {
        Name => $dbname,
        USER => $user,
        CURRENT_USER => $user,
        });

    my $real_dbname = $dbname;
    if ($dbname =~ /=/) {
        foreach my $attrib (split(/;/, $dbname)) {
            my ($k, $v) = split(/=/, $attrib, 2);
            if ($k eq 'dbname') {
                $real_dbname = $v;
            }
            else {
                # TODO: add to attribs
            }
        }
    }
    DBD::SQLite::db::_login($dbh, $real_dbname, $user, $auth)
        or return undef;

    return $dbh;
}

package DBD::SQLite::db;

sub prepare {
    my ($dbh, $statement, @attribs) = @_;

    my $sth = DBI::_new_sth($dbh, {
        Statement => $statement,
    });

    DBD::SQLite::st::_prepare($sth, $statement, @attribs)
        or return undef;

    return $sth;
}

1;
__END__

=head1 NAME

DBD::SQLite - Self Contained RDBMS in a DBI Driver

=head1 SYNOPSIS

  use DBI;
  my $dbh = DBI->connect("dbi:SQLite:dbname=dbfile","","");

=head1 DESCRIPTION

SQLite is a public domain RDBMS database engine that you can find
at http://www.hwaci.com/sw/sqlite/.

Rather than ask you to install SQLite first, because SQLite is public
domain, DBD::SQLite includes the entire thing in the distribution. So
in order to get a fast transaction capable RDBMS working for your
perl project you simply have to install this module, and B<nothing>
else.

SQLite supports the following features:

=over 4

=item Implements a large subset of SQL92

See http://www.hwaci.com/sw/sqlite/lang.html for details.

=item A complete DB in a single disk file

Everything for your database is stored in a single disk file, making it
easier to move things around than with DBD::CSV.

=item Atomic commit and rollback

Yes, DBD::SQLite is small and light, but it supports full transactions!

=back

There's lots more to it, but this is early development stages, so please
refer to the docs on the SQLite web page, listed above, for SQL details.

=head1 BUGS

Likely to be many, please use http://rt.cpan.org/ for reporting bugs.

=head1 AUTHOR

Matt Sergeant, matt@sergeant.org

=head1 SEE ALSO

L<DBI>.

=cut
