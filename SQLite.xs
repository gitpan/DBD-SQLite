/* $Id: SQLite.xs,v 1.4 2002/02/27 19:25:22 matt Exp $ */

#include "SQLiteXS.h"

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
