/* $Id: SQLite.xs,v 1.3 2002/02/22 14:19:41 matt Exp $ */

#include "sqlite.h"

DBISTATE_DECLARE;

MODULE = DBD::SQLite          PACKAGE = DBD::SQLite::db

PROTOTYPES: DISABLE

AV *
list_tables(dbh)
    SV *dbh
    CODE:
    {
        RETVAL = newAV();
    }
    OUTPUT:
        RETVAL

int
last_insert_rowid(dbh)
    SV *dbh
    CODE:
    {
        D_imp_dbh(dbh);
        RETVAL = sqlite_last_insert_rowid(imp_dbh->db);
    }
    OUTPUT:
        RETVAL

MODULE = DBD::SQLite          PACKAGE = DBD::SQLite::st

PROTOTYPES: DISABLE

MODULE = DBD::SQLite          PACKAGE = DBD::SQLite

INCLUDE: SQLite.xsi
