/* $Id: dbdimp.c,v 1.30 2003/01/27 21:50:53 matt Exp $ */

#include "SQLiteXS.h"

DBISTATE_DECLARE;

STRLEN myPL_na;

void
sqlite_init(dbistate_t *dbistate)
{
    dTHR;
    DBIS = dbistate;
}

void
sqlite_error(SV *h, int rc, char *what)
{
    dTHR;
    D_imp_xxh(h);

    SV *errstr = DBIc_ERRSTR(imp_xxh);
    sv_setiv(DBIc_ERR(imp_xxh), (IV)rc);
    sv_setpv(errstr, what);
    DBIh_EVENT2(h, ERROR_event, DBIc_ERR(imp_xxh), errstr);
    
    if (dbis->debug >= 2) {
        fprintf(DBILOGFP, "%s error %d recorded: %s\n",
            what, rc, SvPV(errstr, myPL_na));
    }
}

int
sqlite_db_login(SV *dbh, imp_dbh_t *imp_dbh, char *dbname, char *user, char *pass)
{
    dTHR;
    char *errmsg = NULL;

    if ((imp_dbh->db = sqlite_open(dbname, 0, &errmsg)) == NULL) {
        sv_setpv(DBIc_ERRSTR(imp_dbh), errmsg);
        Safefree(errmsg);
        return FALSE;
    }

    imp_dbh->in_tran = FALSE;
    imp_dbh->no_utf8_flag = FALSE;

    sqlite_busy_timeout(imp_dbh->db, SQL_TIMEOUT);

    if (sqlite_exec(imp_dbh->db, "PRAGMA empty_result_callbacks = ON",
        NULL, NULL, &errmsg)
        != SQLITE_OK)
    {
        /*  warn("failed to set pragma: %s\n", errmsg); */
        sv_setpv(DBIc_ERRSTR(imp_dbh), errmsg);
        Safefree(errmsg);
        return FALSE;
    }

    DBIc_IMPSET_on(imp_dbh);
    DBIc_ACTIVE_on(imp_dbh);

    return TRUE;
}

int
sqlite_db_disconnect (SV *dbh, imp_dbh_t *imp_dbh)
{
    dTHR;
    DBIc_ACTIVE_off(imp_dbh);

    if (DBIc_is(imp_dbh, DBIcf_AutoCommit) == FALSE) {
        sqlite_db_rollback(dbh, imp_dbh);
    }


    sqlite_close(imp_dbh->db);
    imp_dbh->db = NULL;

    return TRUE;
}

void
sqlite_db_destroy (SV *dbh, imp_dbh_t *imp_dbh)
{
    dTHR;
    if (DBIc_ACTIVE(imp_dbh)) {
        sqlite_db_disconnect(dbh, imp_dbh);
    }
    DBIc_IMPSET_off(imp_dbh);
}

int
sqlite_db_rollback(SV *dbh, imp_dbh_t *imp_dbh)
{
    dTHR;
    int retval;
    char *errmsg;

    if (DBIc_is(imp_dbh, DBIcf_AutoCommit)) {
        warn("rollback ineffective with AutoCommit");
        return TRUE;
    }

    if (imp_dbh->in_tran) {
        if (retval = sqlite_exec(imp_dbh->db, "ROLLBACK TRANSACTION",
            NULL, NULL, &errmsg)
            != SQLITE_OK)
        {
            sv_setpv(DBIc_ERRSTR(imp_dbh), errmsg);
            Safefree(errmsg);
            return retval;
        }
        imp_dbh->in_tran = FALSE;
    }

    return TRUE;
}

int
sqlite_db_commit(SV *dbh, imp_dbh_t *imp_dbh)
{
    dTHR;
    int retval;
    char *errmsg;

    if (DBIc_is(imp_dbh, DBIcf_AutoCommit)) {
        warn("commit ineffective with AutoCommit");
        return TRUE;
    }

    if (imp_dbh->in_tran) {
        if (retval = sqlite_exec(imp_dbh->db, "COMMIT TRANSACTION",
            NULL, NULL, &errmsg)
            != SQLITE_OK)
        {
            sv_setpv(DBIc_ERRSTR(imp_dbh), errmsg);
            Safefree(errmsg);
            return retval;
        }
        imp_dbh->in_tran = FALSE;
    }
    return TRUE;
}

int
sqlite_discon_all(SV *drh, imp_drh_t *imp_drh)
{
    dTHR;
    /* no way to do this. Just return OK */
    return TRUE;
}

void
sqlite_st_parse_sql(imp_sth_t *imp_sth, char *statement)
{
    D_imp_dbh_from_sth;
    bool in_literal = FALSE;
    SV *chunk;
    int num_params = 0;

    chunk = NEWSV(0, strlen(statement));
    sv_setpv(chunk, "");

    /* warn("parsing: %s\n", statement); */

    while (*statement) {
        /*  warn("parse: %c => %s\n", *statement, SvPV(chunk, myPL_na)); */
        if (*statement == '\'') {
            if (in_literal) {
                /*  either end of literal, or escape */
                if (statement[1] && statement[1] == '\'') {
                    statement++;
                    sv_catpvn(chunk, "''", 2);
                }
                else {
                    sv_catpvn(chunk, "'", 1);
                    in_literal = FALSE;
                }
            }
            else {
                in_literal = TRUE;
                sv_catpvn(chunk, "'", 1);
            }
        }
        else if (*statement == '?') {
            if (in_literal) {
                sv_catpvn(chunk, "?", 1);
            }
            else {
                num_params++;
		if (!imp_dbh->no_utf8_flag) {
                    /* sv_utf8_encode(chunk); */
		}
                av_push(imp_sth->sql, chunk);
                chunk = NEWSV(0, 20);
                sv_setpvn(chunk, "", 0);
            }
        }
        else {
            sv_catpvn(chunk, statement, 1);
        }
        statement++;
    }
    av_push(imp_sth->sql, chunk);
    DBIc_NUM_PARAMS(imp_sth) = num_params;
}

int
sqlite_st_prepare (SV *sth, imp_sth_t *imp_sth,
                char *statement, SV *attribs)
{
    dTHR;
    D_imp_dbh_from_sth;

    sv_setpv(DBIc_ERRSTR(imp_dbh), "");

    imp_sth->nrow = 0;
    imp_sth->ncols = 0;
    imp_sth->params = newAV();
    imp_sth->sql = newAV();
    sqlite_st_parse_sql(imp_sth, statement);

    return TRUE;
}

char *
sqlite_quote(imp_dbh_t *imp_dbh, SV *val)
{
    char *cval = SvPV(val, myPL_na);
    SV *ret = sv_2mortal(NEWSV(0, SvCUR(val) + 2));
    if (strchr(cval, '\'')) {
        sv_setpvn(ret, "", 0);

        while (*cval) {
            if (*cval == '\'') {
                sv_catpvn(ret, "''", 2);
            }
            else {
                sv_catpvn(ret, cval, 1);
            }
            *cval++;
        }
        return SvPV(ret, myPL_na);
    }
    else {
        return cval;
    }
}

int
sqlite_st_execute (SV *sth, imp_sth_t *imp_sth)
{
    dTHR;
    D_imp_dbh_from_sth;
    SV *sql;
    I32 pos = 0;
    char *errmsg;
    int num_params = DBIc_NUM_PARAMS(imp_sth);
    I32 i;
    int retval;

    /* warn("execute\n"); */

    sv_setpv(DBIc_ERRSTR(imp_dbh), "");

    sql = sv_2mortal(newSVsv(AvARRAY(imp_sth->sql)[pos++]));

    for (i = 0; i < num_params; i++) {
        SV *value = av_shift(imp_sth->params);
        if (value && SvOK(value)) {
            /* warn("binding param: %s\n", SvPV(value, myPL_na)); */
            sv_catpvn(sql, "'", 1);
            sv_catpv(sql, sqlite_quote(imp_dbh, value));
            sv_catpvn(sql, "'", 1);
        }
        else {
            /* warn("binding NULL\n"); */
            sv_catpvn(sql, "NULL", 4);
        }
        if (value) {
            SvREFCNT_dec(value);
        }
        sv_catsv(sql, AvARRAY(imp_sth->sql)[pos++]);
    }
    /* warn("Executing: %s;\n", SvPV(sql, myPL_na)); */

    if ( (!DBIc_is(imp_dbh, DBIcf_AutoCommit)) && (!imp_dbh->in_tran) ) {
        if (retval = sqlite_exec(imp_dbh->db, "BEGIN TRANSACTION",
            NULL, NULL, &errmsg)
            != SQLITE_OK)
        {
            sqlite_error(sth, retval, errmsg);
            /* sv_setpv(DBIc_ERRSTR(imp_dbh), errmsg); */
            Safefree(errmsg);
            return -1;
        }
        imp_dbh->in_tran = TRUE;
    }

    imp_sth->results = NULL;
    if (retval = sqlite_get_table(imp_dbh->db, SvPV(sql, myPL_na), &(imp_sth->results),
        &(imp_sth->nrow), &(imp_sth->ncols), &errmsg) != SQLITE_OK)
    {
        /* warn("exec failed: %s\n", errmsg); */
        sqlite_error(sth, retval, errmsg);
        Safefree(errmsg);
        return -2;
    }

    /* warn("exec ok - %d rows\n", imp_sth->nrow); */
    DBIc_NUM_FIELDS(imp_sth) = imp_sth->ncols;
    imp_sth->c_row = 1;
    if (imp_sth->ncols != 0) {
        DBIc_ACTIVE_on(imp_sth);
    }
    else {
        sqlite_free_table(imp_sth->results);
    }
    DBIc_IMPSET_on(imp_sth);
    return imp_sth->nrow;
}

int
sqlite_st_rows (SV *sth, imp_sth_t *imp_sth)
{
    return imp_sth->nrow;
}

int
sqlite_bind_ph (SV *sth, imp_sth_t *imp_sth,
                SV *param, SV *value, IV sql_type, SV *attribs,
                                int is_inout, IV maxlen)
{
    if (is_inout) {
        croak("InOut bind params not implemented");
    }
    /* warn("bind: %s => %s\n", SvPV(param, myPL_na), SvPV(value, myPL_na)); */
    if (sql_type >= SQL_NUMERIC && sql_type <= SQL_DOUBLE) {
        av_store(imp_sth->params, SvIV(param) - 1, newSVnv(SvNV(value)));
    }
    else {
        av_store(imp_sth->params, SvIV(param) - 1, SvREFCNT_inc(value));
    }
}

AV *
sqlite_st_fetch (SV *sth, imp_sth_t *imp_sth)
{
    AV *av;
    D_imp_dbh_from_sth;
    int numFields = DBIc_NUM_FIELDS(imp_sth);
    int chopBlanks = DBIc_is(imp_sth, DBIcf_ChopBlanks);
    int current_entry = imp_sth->c_row * numFields;
    int i;

    /* warn("current_entry == %d\nnumFields == %d\nnrow == %d",
        current_entry, numFields, imp_sth->nrow); */

    if (current_entry >= ((imp_sth->nrow * numFields) + 1)) {
        sqlite_st_finish(sth, imp_sth);
        return Nullav;
    }

    av = DBIS->get_fbav(imp_sth);
    for (i = 0; i < numFields; i++) {
        char *val = imp_sth->results[current_entry + i];
        /* warn("fetching: %d == %s\n", (current_entry + i), val); */
        if (val != NULL) {
            int len = strlen(val);
            if (chopBlanks) {
                while((len > 0) && (val[len-1] == ' ')) {
                    len--;
                }
                val[len] = '\0';
            }
            sv_setpvn(AvARRAY(av)[i], val, len);
        }
        else {
            sv_setsv(AvARRAY(av)[i], Nullsv);
        }
        if (!imp_dbh->no_utf8_flag && SvPOK(AvARRAY(av)[i])) {
            /* sv_utf8_encode(AvARRAY(av)[i]); */
        }
    }
    imp_sth->c_row++;
    return av;
}

int
sqlite_st_finish (SV *sth, imp_sth_t *imp_sth)
{
    if (DBIc_ACTIVE(imp_sth)) {
        DBIc_ACTIVE_off(imp_sth);
        sqlite_free_table(imp_sth->results);
    }
    return TRUE;
}

void
sqlite_st_destroy (SV *sth, imp_sth_t *imp_sth)
{
    if (DBIc_ACTIVE(imp_sth)) {
        sqlite_st_finish(sth, imp_sth);
    }
    SvREFCNT_dec((SV*)imp_sth->sql);
    SvREFCNT_dec((SV*)imp_sth->params);
    DBIc_IMPSET_off(imp_sth);
}

int
sqlite_st_blob_read (SV *sth, imp_sth_t *imp_sth,
                int field, long offset, long len, SV *destrv, long destoffset)
{
}

int
sqlite_db_STORE_attrib (SV *dbh, imp_dbh_t *imp_dbh, SV *keysv, SV *valuesv)
{
    dTHR;
    char *key = SvPV(keysv, myPL_na);
    char *errmsg;
    int retval;

    if (strncmp(key, "AutoCommit", 10) == 0) {
        if (SvTRUE(valuesv)) {
            /* commit tran? */
            if ( (!DBIc_is(imp_dbh, DBIcf_AutoCommit)) && (imp_dbh->in_tran) ) {
                if (retval = sqlite_exec(imp_dbh->db, "COMMIT TRANSACTION",
                    NULL, NULL, &errmsg)
                    != SQLITE_OK)
                {
                    sv_setpv(DBIc_ERRSTR(imp_dbh), errmsg);
                    Safefree(errmsg);
                    return retval;
                }
                imp_dbh->in_tran = FALSE;
            }
        }
        DBIc_set(imp_dbh, DBIcf_AutoCommit, SvTRUE(valuesv));
        return TRUE;
    }
    else if (strncmp(key, "NoUTF8Flag", 10) == 0) {
        warn("NoUTF8Flag is deprecated due to perl unicode weirdness\n");
        if (SvTRUE(valuesv)) {
            imp_dbh->no_utf8_flag = TRUE;
        }
        else {
            imp_dbh->no_utf8_flag = FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

SV *
sqlite_db_FETCH_attrib (SV *dbh, imp_dbh_t *imp_dbh, SV *keysv)
{
    dTHR;
    char *key = SvPV(keysv, myPL_na);

    if (strncmp(key, "AutoCommit", 10) == 0) {
        /* warn("fetching autocommit\n"); */
        return newSViv(DBIc_is(imp_dbh, DBIcf_AutoCommit));
    }
    if (strncmp(key, "NoUTF8Flag", 10) == 0) {
        return newSViv(imp_dbh->no_utf8_flag ? 1 : 0);
    }
    return NULL;
}

int
sqlite_db_STORE_attrib_k (SV *dbh, imp_dbh_t *imp_dbh, SV *keysv, int dbikey, SV *valuesv)
{
    dTHR;
    return FALSE;
}

SV *
sqlite_db_FETCH_attrib_k (SV *dbh, imp_dbh_t *imp_dbh, SV *keysv, int dbikey)
{
    dTHR;
    return NULL;
}

int
sqlite_st_STORE_attrib (SV *sth, imp_sth_t *imp_sth, SV *keysv, SV *valuesv)
{
    char *key = SvPV(keysv, myPL_na);

    if (strEQ(key, "ChopBlanks")) {
        DBIc_set(imp_sth, DBIcf_ChopBlanks, SvIV(valuesv));
        return TRUE;
    }
    return FALSE;
}

SV *
sqlite_st_FETCH_attrib (SV *sth, imp_sth_t *imp_sth, SV *keysv)
{
    char *key = SvPV(keysv, myPL_na);
    SV *retsv = NULL;
    int i;

    if (!imp_sth->results) {
        return retsv;
    }

    i = DBIc_NUM_FIELDS(imp_sth);

    if (strEQ(key, "NAME")) {
        AV *av = newAV();
        retsv = sv_2mortal(newRV(sv_2mortal((SV*)av)));
        while (--i >= 0) {
            av_store(av, i, newSVpv(imp_sth->results[i], 0));
        }
    }
    else if (strEQ(key, "NUM_OF_FIELDS")) {
        retsv = sv_2mortal(newSViv(imp_sth->ncols));
    }
    else if (strEQ(key, "ChopBlanks")) {
        retsv = sv_2mortal(newSViv(DBIc_has(imp_sth, DBIcf_ChopBlanks)));
    }

    return retsv;
}

int
sqlite_st_STORE_attrib_k (SV *sth, imp_sth_t *imp_sth, SV *keysv, int dbikey, SV *valuesv)
{
}

SV *
sqlite_st_FETCH_attrib_k (SV *sth, imp_sth_t *imp_sth, SV *keysv, int dbikey)
{
}

