/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
#line 28 "parse.y"

#include "sqliteInt.h"
#include "parse.h"

/*
** A structure for holding two integers
*/
struct twoint { int a,b; };

#line 18 "parse.c"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    sqliteParserTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is sqliteParserTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.
**    sqliteParserARGDECL       is a declaration of a 3rd argument to the
**                       parser, or null if there is no extra argument.
**    sqliteParserKRARGDECL     A version of sqliteParserARGDECL for K&R C.
**    sqliteParserANSIARGDECL   A version of sqliteParserARGDECL for ANSI C.
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
/*  */
#define YYCODETYPE unsigned char
#define YYNOCODE 162
#define YYACTIONTYPE int
#define sqliteParserTOKENTYPE Token
typedef union {
  sqliteParserTOKENTYPE yy0;
  Expr* yy132;
  int yy144;
  IdList* yy152;
  Token yy224;
  Select* yy233;
  ExprList* yy270;
  struct twoint yy303;
  int yy323;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define sqliteParserARGDECL ,pParse
#define sqliteParserXARGDECL Parse *pParse;
#define sqliteParserANSIARGDECL ,Parse *pParse
#define YYNSTATE 388
#define YYNRULE 226
#define YYERRORSYMBOL 114
#define YYERRSYMDT yy323
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)
/* Next is the action table.  Each entry in this table contains
**
**  +  An integer which is the number representing the look-ahead
**     token
**
**  +  An integer indicating what action to take.  Number (N) between
**     0 and YYNSTATE-1 mean shift the look-ahead and go to state N.
**     Numbers between YYNSTATE and YYNSTATE+YYNRULE-1 mean reduce by
**     rule N-YYNSTATE.  Number YYNSTATE+YYNRULE means that a syntax
**     error has occurred.  Number YYNSTATE+YYNRULE+1 means the parser
**     accepts its input.
**
**  +  A pointer to the next entry with the same hash value.
**
** The action table is really a series of hash tables.  Each hash
** table contains a number of entries which is a power of two.  The
** "state" table (which follows) contains information about the starting
** point and size of each hash table.
*/
struct yyActionEntry {
  YYCODETYPE   lookahead;   /* The value of the look-ahead token */
  YYACTIONTYPE action;      /* Action to take for this look-ahead */
  struct yyActionEntry *next; /* Next look-ahead with the same hash, or NULL */
};
static struct yyActionEntry yyActionTable[] = {
/* State 0 */
  {  96, 366, 0                    }, /*                 VACUUM shift  366 */
  { 129, 327, 0                    }, /*             insert_cmd shift  327 */
  {   7,   6, 0                    }, /*                  BEGIN shift  6 */
  {  35, 386, 0                    }, /*                EXPLAIN shift  386 */
  {  50, 355, &yyActionTable[   5] }, /*                 INSERT shift  355 */
  {  18,  39, 0                    }, /*                 COMMIT shift  39 */
  {  94, 312, &yyActionTable[  11] }, /*                 UPDATE shift  312 */
  { 103, 385, &yyActionTable[   2] }, /*                    cmd shift  385 */
  { 104,   1, 0                    }, /*                cmdlist shift  1 */
  {  73, 368, 0                    }, /*                 PRAGMA shift  368 */
  { 138,  78, 0                    }, /*              oneselect shift  78 */
  {  30, 302, 0                    }, /*                   DROP shift  302 */
  {  76, 357, 0                    }, /*                REPLACE shift  357 */
  {  77,  43, 0                    }, /*               ROLLBACK shift  43 */
  { 110,  45, 0                    }, /*           create_table shift  45 */
  {YYNOCODE,0,0}, /* Unused */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  { 113, 387, 0                    }, /*                   ecmd shift  387 */
  { 146, 307, &yyActionTable[   4] }, /*                 select shift  307 */
  { 115,   4, 0                    }, /*                explain shift  4 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  22, 358, 0                    }, /*                   COPY shift  358 */
  {  23, 287, 0                    }, /*                 CREATE shift  287 */
  {YYNOCODE,0,0}, /* Unused */
  {  25, 308, 0                    }, /*                 DELETE shift  308 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  { 126, 615, &yyActionTable[   6] }, /*                  input accept */
  {  31,  41, 0                    }, /*                    END shift  41 */
/* State 1 */
  {   0, 388, 0                    }, /*                      $ reduce 0 */
  {  81,   2, 0                    }, /*                   SEMI shift  2 */
/* State 2 */
  {  96, 366, 0                    }, /*                 VACUUM shift  366 */
  { 129, 327, 0                    }, /*             insert_cmd shift  327 */
  {   7,   6, 0                    }, /*                  BEGIN shift  6 */
  {  35, 386, 0                    }, /*                EXPLAIN shift  386 */
  {  50, 355, &yyActionTable[  39] }, /*                 INSERT shift  355 */
  {  18,  39, 0                    }, /*                 COMMIT shift  39 */
  {  30, 302, 0                    }, /*                   DROP shift  302 */
  { 103, 385, &yyActionTable[  36] }, /*                    cmd shift  385 */
  {YYNOCODE,0,0}, /* Unused */
  {  73, 368, 0                    }, /*                 PRAGMA shift  368 */
  { 138,  78, 0                    }, /*              oneselect shift  78 */
  {YYNOCODE,0,0}, /* Unused */
  {  76, 357, 0                    }, /*                REPLACE shift  357 */
  {  77,  43, 0                    }, /*               ROLLBACK shift  43 */
  { 110,  45, 0                    }, /*           create_table shift  45 */
  {YYNOCODE,0,0}, /* Unused */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  { 113,   3, 0                    }, /*                   ecmd shift  3 */
  { 146, 307, &yyActionTable[  38] }, /*                 select shift  307 */
  { 115,   4, 0                    }, /*                explain shift  4 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  22, 358, 0                    }, /*                   COPY shift  358 */
  {  23, 287, 0                    }, /*                 CREATE shift  287 */
  {YYNOCODE,0,0}, /* Unused */
  {  25, 308, 0                    }, /*                 DELETE shift  308 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  94, 312, &yyActionTable[  40] }, /*                 UPDATE shift  312 */
  {  31,  41, 0                    }, /*                    END shift  41 */
/* State 3 */
  {YYNOCODE,0,0}, /* Unused */
/* State 4 */
  {  96, 366, 0                    }, /*                 VACUUM shift  366 */
  { 129, 327, 0                    }, /*             insert_cmd shift  327 */
  {   7,   6, 0                    }, /*                  BEGIN shift  6 */
  {  50, 355, &yyActionTable[  71] }, /*                 INSERT shift  355 */
  {  18,  39, 0                    }, /*                 COMMIT shift  39 */
  {  30, 302, 0                    }, /*                   DROP shift  302 */
  {YYNOCODE,0,0}, /* Unused */
  { 103,   5, &yyActionTable[  69] }, /*                    cmd shift  5 */
  {YYNOCODE,0,0}, /* Unused */
  {  73, 368, 0                    }, /*                 PRAGMA shift  368 */
  { 138,  78, 0                    }, /*              oneselect shift  78 */
  {YYNOCODE,0,0}, /* Unused */
  {  76, 357, 0                    }, /*                REPLACE shift  357 */
  {  77,  43, 0                    }, /*               ROLLBACK shift  43 */
  { 110,  45, 0                    }, /*           create_table shift  45 */
  {YYNOCODE,0,0}, /* Unused */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  {YYNOCODE,0,0}, /* Unused */
  { 146, 307, &yyActionTable[  70] }, /*                 select shift  307 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  22, 358, 0                    }, /*                   COPY shift  358 */
  {  23, 287, 0                    }, /*                 CREATE shift  287 */
  {YYNOCODE,0,0}, /* Unused */
  {  25, 308, 0                    }, /*                 DELETE shift  308 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  94, 312, &yyActionTable[  72] }, /*                 UPDATE shift  312 */
  {  31,  41, 0                    }, /*                    END shift  41 */
/* State 5 */
  {YYNOCODE,0,0}, /* Unused */
/* State 6 */
  { 156,   7, 0                    }, /*              trans_opt shift  7 */
  {  89,  17, 0                    }, /*            TRANSACTION shift  17 */
/* State 7 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
  { 137,   8, &yyActionTable[ 102] }, /*                 onconf shift  8 */
/* State 8 */
  {YYNOCODE,0,0}, /* Unused */
/* State 9 */
  {  20,  10, 0                    }, /*               CONFLICT shift  10 */
/* State 10 */
  {  36,  14, 0                    }, /*                   FAIL shift  14 */
  {   1,  13, 0                    }, /*                  ABORT shift  13 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  76,  16, &yyActionTable[ 106] }, /*                REPLACE shift  16 */
  {  77,  12, 0                    }, /*               ROLLBACK shift  12 */
  {  46,  15, 0                    }, /*                 IGNORE shift  15 */
  { 143,  11, 0                    }, /*            resolvetype shift  11 */
/* State 11 */
  {YYNOCODE,0,0}, /* Unused */
/* State 12 */
  {YYNOCODE,0,0}, /* Unused */
/* State 13 */
  {YYNOCODE,0,0}, /* Unused */
/* State 14 */
  {YYNOCODE,0,0}, /* Unused */
/* State 15 */
  {YYNOCODE,0,0}, /* Unused */
/* State 16 */
  {YYNOCODE,0,0}, /* Unused */
/* State 17 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[ 122] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[ 125] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[ 128] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[ 130] }, /*                     id shift  37 */
  { 123,  18, &yyActionTable[ 131] }, /*                    ids shift  18 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 18 */
  {YYNOCODE,0,0}, /* Unused */
/* State 19 */
  {YYNOCODE,0,0}, /* Unused */
/* State 20 */
  {YYNOCODE,0,0}, /* Unused */
/* State 21 */
  {YYNOCODE,0,0}, /* Unused */
/* State 22 */
  {YYNOCODE,0,0}, /* Unused */
/* State 23 */
  {YYNOCODE,0,0}, /* Unused */
/* State 24 */
  {YYNOCODE,0,0}, /* Unused */
/* State 25 */
  {YYNOCODE,0,0}, /* Unused */
/* State 26 */
  {YYNOCODE,0,0}, /* Unused */
/* State 27 */
  {YYNOCODE,0,0}, /* Unused */
/* State 28 */
  {YYNOCODE,0,0}, /* Unused */
/* State 29 */
  {YYNOCODE,0,0}, /* Unused */
/* State 30 */
  {YYNOCODE,0,0}, /* Unused */
/* State 31 */
  {YYNOCODE,0,0}, /* Unused */
/* State 32 */
  {YYNOCODE,0,0}, /* Unused */
/* State 33 */
  {YYNOCODE,0,0}, /* Unused */
/* State 34 */
  {YYNOCODE,0,0}, /* Unused */
/* State 35 */
  {YYNOCODE,0,0}, /* Unused */
/* State 36 */
  {YYNOCODE,0,0}, /* Unused */
/* State 37 */
  {YYNOCODE,0,0}, /* Unused */
/* State 38 */
  {YYNOCODE,0,0}, /* Unused */
/* State 39 */
  { 156,  40, 0                    }, /*              trans_opt shift  40 */
  {  89,  17, 0                    }, /*            TRANSACTION shift  17 */
/* State 40 */
  {YYNOCODE,0,0}, /* Unused */
/* State 41 */
  { 156,  42, 0                    }, /*              trans_opt shift  42 */
  {  89,  17, 0                    }, /*            TRANSACTION shift  17 */
/* State 42 */
  {YYNOCODE,0,0}, /* Unused */
/* State 43 */
  { 156,  44, 0                    }, /*              trans_opt shift  44 */
  {  89,  17, 0                    }, /*            TRANSACTION shift  17 */
/* State 44 */
  {YYNOCODE,0,0}, /* Unused */
/* State 45 */
  {  60,  47, 0                    }, /*                     LP shift  47 */
  { 111,  46, 0                    }, /*      create_table_args shift  46 */
/* State 46 */
  {YYNOCODE,0,0}, /* Unused */
/* State 47 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[ 187] }, /*                 OFFSET shift  30 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  { 105, 286, &yyActionTable[ 190] }, /*                 column shift  286 */
  { 106,  53, 0                    }, /*               columnid shift  53 */
  { 107,  48, 0                    }, /*             columnlist shift  48 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[ 193] }, /*                 IGNORE shift  33 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[ 200] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[ 201] }, /*                     id shift  37 */
  { 123, 260, &yyActionTable[ 202] }, /*                    ids shift  260 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 48 */
  {  16,  51, 0                    }, /*                  COMMA shift  51 */
  { 109,  49, 0                    }, /*           conslist_opt shift  49 */
  {  78, 457, 0                    }, /*                     RP reduce 69 */
  {YYNOCODE,0,0}, /* Unused */
/* State 49 */
  {  78,  50, 0                    }, /*                     RP shift  50 */
/* State 50 */
  {YYNOCODE,0,0}, /* Unused */
/* State 51 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[ 225] }, /*                 OFFSET shift  30 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  74, 266, 0                    }, /*                PRIMARY shift  266 */
  { 105,  52, &yyActionTable[ 228] }, /*                 column shift  52 */
  { 106,  53, &yyActionTable[ 231] }, /*               columnid shift  53 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  { 108, 261, &yyActionTable[ 234] }, /*               conslist shift  261 */
  {  45,  28, &yyActionTable[ 238] }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[ 239] }, /*                 IGNORE shift  33 */
  {  13, 281, 0                    }, /*                  CHECK shift  281 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  { 122,  37, &yyActionTable[ 242] }, /*                     id shift  37 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  21, 264, 0                    }, /*             CONSTRAINT shift  264 */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[ 240] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 154, 285, &yyActionTable[ 241] }, /*                  tcons shift  285 */
  { 123, 260, &yyActionTable[ 246] }, /*                    ids shift  260 */
  {YYNOCODE,0,0}, /* Unused */
  {  93, 276, 0                    }, /*                 UNIQUE shift  276 */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 52 */
  {YYNOCODE,0,0}, /* Unused */
/* State 53 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[ 258] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[ 261] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[ 264] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[ 266] }, /*                     id shift  37 */
  { 123, 259, &yyActionTable[ 267] }, /*                    ids shift  259 */
  {YYNOCODE,0,0}, /* Unused */
  { 157,  54, 0                    }, /*                   type shift  54 */
  { 158, 246, 0                    }, /*               typename shift  246 */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 54 */
  { 101,  55, 0                    }, /*               carglist shift  55 */
/* State 55 */
  {  24, 234, 0                    }, /*                DEFAULT shift  234 */
  {  65,  60, 0                    }, /*                    NOT shift  60 */
  {  74,  63, 0                    }, /*                PRIMARY shift  63 */
  {  21,  57, &yyActionTable[ 296] }, /*             CONSTRAINT shift  57 */
  { 100,  56, 0                    }, /*                   carg shift  56 */
  {  93,  69, &yyActionTable[ 292] }, /*                 UNIQUE shift  69 */
  { 102, 233, 0                    }, /*                  ccons shift  233 */
  {  13,  71, 0                    }, /*                  CHECK shift  71 */
/* State 56 */
  {YYNOCODE,0,0}, /* Unused */
/* State 57 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[ 300] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[ 303] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[ 306] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[ 308] }, /*                     id shift  37 */
  { 123,  58, &yyActionTable[ 309] }, /*                    ids shift  58 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 58 */
  {  13,  71, 0                    }, /*                  CHECK shift  71 */
  {  65,  60, 0                    }, /*                    NOT shift  60 */
  {  74,  63, 0                    }, /*                PRIMARY shift  63 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  93,  69, &yyActionTable[ 330] }, /*                 UNIQUE shift  69 */
  { 102,  59, 0                    }, /*                  ccons shift  59 */
  {YYNOCODE,0,0}, /* Unused */
/* State 59 */
  {YYNOCODE,0,0}, /* Unused */
/* State 60 */
  {  67,  61, 0                    }, /*                   NULL shift  61 */
/* State 61 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
  { 137,  62, &yyActionTable[ 340] }, /*                 onconf shift  62 */
/* State 62 */
  {YYNOCODE,0,0}, /* Unused */
/* State 63 */
  {  56,  64, 0                    }, /*                    KEY shift  64 */
/* State 64 */
  { 152,  65, 0                    }, /*              sortorder shift  65 */
  {YYNOCODE,0,0}, /* Unused */
  {   6,  67, 0                    }, /*                    ASC shift  67 */
  {  27,  68, 0                    }, /*                   DESC shift  68 */
/* State 65 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
  { 137,  66, &yyActionTable[ 348] }, /*                 onconf shift  66 */
/* State 66 */
  {YYNOCODE,0,0}, /* Unused */
/* State 67 */
  {YYNOCODE,0,0}, /* Unused */
/* State 68 */
  {YYNOCODE,0,0}, /* Unused */
/* State 69 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
  { 137,  70, &yyActionTable[ 353] }, /*                 onconf shift  70 */
/* State 70 */
  {YYNOCODE,0,0}, /* Unused */
/* State 71 */
  {  60,  72, 0                    }, /*                     LP shift  72 */
/* State 72 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[ 359] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[ 368] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[ 372] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[ 373] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 230, &yyActionTable[ 374] }, /*                   expr shift  230 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[ 375] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[ 378] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[ 380] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[ 382] }, /*                  MINUS shift  176 */
/* State 73 */
  {  60,  74, 0                    }, /*                     LP shift  74 */
/* State 74 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  65, 172, &yyActionTable[ 390] }, /*                    NOT shift  172 */
  {YYNOCODE,0,0}, /* Unused */
  {  67, 105, 0                    }, /*                   NULL shift  105 */
  {  68,  30, 0                    }, /*                 OFFSET shift  30 */
  {YYNOCODE,0,0}, /* Unused */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {YYNOCODE,0,0}, /* Unused */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {YYNOCODE,0,0}, /* Unused */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  85, 228, 0                    }, /*                   STAR shift  228 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, 0                    }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, 0                    }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 171, 0                    }, /*                   expr shift  171 */
  { 117, 184, 0                    }, /*               expritem shift  184 */
  { 118, 226, 0                    }, /*               exprlist shift  226 */
  {YYNOCODE,0,0}, /* Unused */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  75, 0                    }, /*                     id shift  75 */
  { 123, 106, 0                    }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, 0                    }, /*                  MINUS shift  176 */
/* State 75 */
  {   0, 542, 0                    }, /*                      $ reduce 154 */
  {   1, 542, 0                    }, /*                  ABORT reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {   4, 542, 0                    }, /*                    AND reduce 154 */
  {   5, 542, 0                    }, /*                     AS reduce 154 */
  {   6, 542, 0                    }, /*                    ASC reduce 154 */
  {   7, 542, 0                    }, /*                  BEGIN reduce 154 */
  {   8, 542, 0                    }, /*                BETWEEN reduce 154 */
  {   9, 542, 0                    }, /*                 BITAND reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  11, 542, 0                    }, /*                  BITOR reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  13, 542, 0                    }, /*                  CHECK reduce 154 */
  {  14, 542, 0                    }, /*                CLUSTER reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  16, 542, 0                    }, /*                  COMMA reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  19, 542, 0                    }, /*                 CONCAT reduce 154 */
  {  20, 542, 0                    }, /*               CONFLICT reduce 154 */
  {  21, 542, 0                    }, /*             CONSTRAINT reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  26, 542, 0                    }, /*             DELIMITERS reduce 154 */
  {  27, 542, 0                    }, /*                   DESC reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  29, 429, 0                    }, /*                    DOT reduce 41 */
  {YYNOCODE,0,0}, /* Unused */
  {  31, 542, 0                    }, /*                    END reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  33, 542, 0                    }, /*                     EQ reduce 154 */
  {  34, 542, 0                    }, /*                 EXCEPT reduce 154 */
  {  35, 542, 0                    }, /*                EXPLAIN reduce 154 */
  {  36, 542, 0                    }, /*                   FAIL reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  38, 542, 0                    }, /*                   FROM reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  40, 542, 0                    }, /*                     GE reduce 154 */
  {  41, 542, 0                    }, /*                   GLOB reduce 154 */
  {  42, 542, 0                    }, /*                  GROUP reduce 154 */
  {  43, 542, 0                    }, /*                     GT reduce 154 */
  {  44, 542, 0                    }, /*                 HAVING reduce 154 */
  {  45, 542, 0                    }, /*                     ID reduce 154 */
  {  46, 542, 0                    }, /*                 IGNORE reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  48, 542, 0                    }, /*                     IN reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  52, 542, 0                    }, /*              INTERSECT reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  54, 542, 0                    }, /*                     IS reduce 154 */
  {  55, 542, 0                    }, /*                 ISNULL reduce 154 */
  {  56, 542, 0                    }, /*                    KEY reduce 154 */
  {  57, 542, 0                    }, /*                     LE reduce 154 */
  {  58, 542, 0                    }, /*                   LIKE reduce 154 */
  {  59, 542, 0                    }, /*                  LIMIT reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 542, 0                    }, /*                 LSHIFT reduce 154 */
  {  62, 542, 0                    }, /*                     LT reduce 154 */
  {  63, 542, 0                    }, /*                  MINUS reduce 154 */
  {  64, 542, 0                    }, /*                     NE reduce 154 */
  {  65, 542, 0                    }, /*                    NOT reduce 154 */
  {  66, 542, 0                    }, /*                NOTNULL reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  68, 542, 0                    }, /*                 OFFSET reduce 154 */
  {  69, 542, 0                    }, /*                     ON reduce 154 */
  {  70, 542, 0                    }, /*                     OR reduce 154 */
  {  71, 542, 0                    }, /*                  ORDER reduce 154 */
  {  72, 542, 0                    }, /*                   PLUS reduce 154 */
  {  73, 542, 0                    }, /*                 PRAGMA reduce 154 */
  {  74, 542, 0                    }, /*                PRIMARY reduce 154 */
  {  75, 542, 0                    }, /*                    REM reduce 154 */
  {  76, 542, 0                    }, /*                REPLACE reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  78, 542, 0                    }, /*                     RP reduce 154 */
  {  79, 542, 0                    }, /*                 RSHIFT reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  81, 542, 0                    }, /*                   SEMI reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 542, 0                    }, /*                  SLASH reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 542, 0                    }, /*                   STAR reduce 154 */
  {  86, 542, 0                    }, /*                 STRING reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  88, 542, 0                    }, /*                   TEMP reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  92, 542, 0                    }, /*                  UNION reduce 154 */
  {  93, 542, 0                    }, /*                 UNIQUE reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  96, 542, 0                    }, /*                 VACUUM reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {  98, 542, 0                    }, /*                  WHERE reduce 154 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
/* State 76 */
  {   0, 546, 0                    }, /*                      $ reduce 158 */
  {   1, 546, 0                    }, /*                  ABORT reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {   4, 546, 0                    }, /*                    AND reduce 158 */
  {   5, 546, 0                    }, /*                     AS reduce 158 */
  {   6, 546, 0                    }, /*                    ASC reduce 158 */
  {   7, 546, 0                    }, /*                  BEGIN reduce 158 */
  {   8, 546, 0                    }, /*                BETWEEN reduce 158 */
  {   9, 546, 0                    }, /*                 BITAND reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  11, 546, 0                    }, /*                  BITOR reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  13, 546, 0                    }, /*                  CHECK reduce 158 */
  {  14, 546, 0                    }, /*                CLUSTER reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  16, 546, 0                    }, /*                  COMMA reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  19, 546, 0                    }, /*                 CONCAT reduce 158 */
  {  20, 546, 0                    }, /*               CONFLICT reduce 158 */
  {  21, 546, 0                    }, /*             CONSTRAINT reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  26, 546, 0                    }, /*             DELIMITERS reduce 158 */
  {  27, 546, 0                    }, /*                   DESC reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  29, 430, 0                    }, /*                    DOT reduce 42 */
  {YYNOCODE,0,0}, /* Unused */
  {  31, 546, 0                    }, /*                    END reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  33, 546, 0                    }, /*                     EQ reduce 158 */
  {  34, 546, 0                    }, /*                 EXCEPT reduce 158 */
  {  35, 546, 0                    }, /*                EXPLAIN reduce 158 */
  {  36, 546, 0                    }, /*                   FAIL reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  38, 546, 0                    }, /*                   FROM reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  40, 546, 0                    }, /*                     GE reduce 158 */
  {  41, 546, 0                    }, /*                   GLOB reduce 158 */
  {  42, 546, 0                    }, /*                  GROUP reduce 158 */
  {  43, 546, 0                    }, /*                     GT reduce 158 */
  {  44, 546, 0                    }, /*                 HAVING reduce 158 */
  {  45, 546, 0                    }, /*                     ID reduce 158 */
  {  46, 546, 0                    }, /*                 IGNORE reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  48, 546, 0                    }, /*                     IN reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  52, 546, 0                    }, /*              INTERSECT reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  54, 546, 0                    }, /*                     IS reduce 158 */
  {  55, 546, 0                    }, /*                 ISNULL reduce 158 */
  {  56, 546, 0                    }, /*                    KEY reduce 158 */
  {  57, 546, 0                    }, /*                     LE reduce 158 */
  {  58, 546, 0                    }, /*                   LIKE reduce 158 */
  {  59, 546, 0                    }, /*                  LIMIT reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 546, 0                    }, /*                 LSHIFT reduce 158 */
  {  62, 546, 0                    }, /*                     LT reduce 158 */
  {  63, 546, 0                    }, /*                  MINUS reduce 158 */
  {  64, 546, 0                    }, /*                     NE reduce 158 */
  {  65, 546, 0                    }, /*                    NOT reduce 158 */
  {  66, 546, 0                    }, /*                NOTNULL reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  68, 546, 0                    }, /*                 OFFSET reduce 158 */
  {  69, 546, 0                    }, /*                     ON reduce 158 */
  {  70, 546, 0                    }, /*                     OR reduce 158 */
  {  71, 546, 0                    }, /*                  ORDER reduce 158 */
  {  72, 546, 0                    }, /*                   PLUS reduce 158 */
  {  73, 546, 0                    }, /*                 PRAGMA reduce 158 */
  {  74, 546, 0                    }, /*                PRIMARY reduce 158 */
  {  75, 546, 0                    }, /*                    REM reduce 158 */
  {  76, 546, 0                    }, /*                REPLACE reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  78, 546, 0                    }, /*                     RP reduce 158 */
  {  79, 546, 0                    }, /*                 RSHIFT reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  81, 546, 0                    }, /*                   SEMI reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 546, 0                    }, /*                  SLASH reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 546, 0                    }, /*                   STAR reduce 158 */
  {  86, 546, 0                    }, /*                 STRING reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  88, 546, 0                    }, /*                   TEMP reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  92, 546, 0                    }, /*                  UNION reduce 158 */
  {  93, 546, 0                    }, /*                 UNIQUE reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  96, 546, 0                    }, /*                 VACUUM reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {  98, 546, 0                    }, /*                  WHERE reduce 158 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
/* State 77 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  65, 172, &yyActionTable[ 710] }, /*                    NOT shift  172 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  67, 105, 0                    }, /*                   NULL shift  105 */
  {  68,  30, 0                    }, /*                 OFFSET shift  30 */
  {YYNOCODE,0,0}, /* Unused */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  { 138,  78, &yyActionTable[ 712] }, /*              oneselect shift  78 */
  {YYNOCODE,0,0}, /* Unused */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {YYNOCODE,0,0}, /* Unused */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {YYNOCODE,0,0}, /* Unused */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  {YYNOCODE,0,0}, /* Unused */
  { 146,  79, 0                    }, /*                 select shift  79 */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, 0                    }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, 0                    }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 224, 0                    }, /*                   expr shift  224 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  75, 0                    }, /*                     id shift  75 */
  { 123, 106, 0                    }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, 0                    }, /*                  MINUS shift  176 */
/* State 78 */
  {YYNOCODE,0,0}, /* Unused */
/* State 79 */
  {  92, 166, &yyActionTable[ 776] }, /*                  UNION shift  166 */
  {  52, 168, 0                    }, /*              INTERSECT shift  168 */
  {  34, 169, 0                    }, /*                 EXCEPT shift  169 */
  {YYNOCODE,0,0}, /* Unused */
  { 132,  80, &yyActionTable[ 775] }, /*                 joinop shift  80 */
  {YYNOCODE,0,0}, /* Unused */
  {  78, 223, 0                    }, /*                     RP shift  223 */
  {YYNOCODE,0,0}, /* Unused */
/* State 80 */
  { 138,  81, &yyActionTable[ 784] }, /*              oneselect shift  81 */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
/* State 81 */
  {YYNOCODE,0,0}, /* Unused */
/* State 82 */
  { 112,  83, &yyActionTable[ 787] }, /*               distinct shift  83 */
  {  28, 221, 0                    }, /*               DISTINCT shift  221 */
  {YYNOCODE,0,0}, /* Unused */
  {   3, 222, 0                    }, /*                    ALL shift  222 */
/* State 83 */
  { 144, 216, 0                    }, /*                   sclp shift  216 */
  { 145,  84, 0                    }, /*             selcollist shift  84 */
/* State 84 */
  {  16, 207, 0                    }, /*                  COMMA shift  207 */
  {YYNOCODE,0,0}, /* Unused */
  {  38, 208, 0                    }, /*                   FROM shift  208 */
  { 119,  85, 0                    }, /*                   from shift  85 */
/* State 85 */
  { 160,  86, &yyActionTable[ 797] }, /*              where_opt shift  86 */
  {  98, 205, 0                    }, /*                  WHERE shift  205 */
/* State 86 */
  { 120,  87, &yyActionTable[ 799] }, /*            groupby_opt shift  87 */
  {  42, 202, 0                    }, /*                  GROUP shift  202 */
/* State 87 */
  {  44, 200, 0                    }, /*                 HAVING shift  200 */
  { 121,  88, 0                    }, /*             having_opt shift  88 */
/* State 88 */
  { 140,  89, 0                    }, /*            orderby_opt shift  89 */
  {  71,  97, 0                    }, /*                  ORDER shift  97 */
/* State 89 */
  {  59,  91, 0                    }, /*                  LIMIT shift  91 */
  { 133,  90, &yyActionTable[ 804] }, /*              limit_opt shift  90 */
/* State 90 */
  {YYNOCODE,0,0}, /* Unused */
/* State 91 */
  {  51,  92, 0                    }, /*                INTEGER shift  92 */
/* State 92 */
  {  68,  95, &yyActionTable[ 809] }, /*                 OFFSET shift  95 */
  {  16,  96, 0                    }, /*                  COMMA shift  96 */
  { 134,  93, 0                    }, /*              limit_sep shift  93 */
  {YYNOCODE,0,0}, /* Unused */
/* State 93 */
  {  51,  94, 0                    }, /*                INTEGER shift  94 */
/* State 94 */
  {YYNOCODE,0,0}, /* Unused */
/* State 95 */
  {  51, 514, 0                    }, /*                INTEGER reduce 126 */
/* State 96 */
  {  51, 515, 0                    }, /*                INTEGER reduce 127 */
/* State 97 */
  {  12,  98, 0                    }, /*                     BY shift  98 */
/* State 98 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[ 819] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[ 828] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[ 832] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[ 833] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 103, &yyActionTable[ 834] }, /*                   expr shift  103 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  { 150, 198, &yyActionTable[ 835] }, /*               sortitem shift  198 */
  { 151,  99, 0                    }, /*               sortlist shift  99 */
  {  88,  29, &yyActionTable[ 838] }, /*                   TEMP shift  29 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  { 122,  75, &yyActionTable[ 842] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[ 846] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {  63, 176, &yyActionTable[ 847] }, /*                  MINUS shift  176 */
/* State 99 */
  {  16, 100, 0                    }, /*                  COMMA shift  100 */
/* State 100 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[ 852] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[ 861] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[ 865] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[ 866] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 103, &yyActionTable[ 867] }, /*                   expr shift  103 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  { 150, 101, &yyActionTable[ 868] }, /*               sortitem shift  101 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  88,  29, &yyActionTable[ 871] }, /*                   TEMP shift  29 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  { 122,  75, &yyActionTable[ 873] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[ 875] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[ 879] }, /*                  MINUS shift  176 */
/* State 101 */
  { 152, 102, 0                    }, /*              sortorder shift  102 */
  {YYNOCODE,0,0}, /* Unused */
  {   6,  67, 0                    }, /*                    ASC shift  67 */
  {  27,  68, 0                    }, /*                   DESC shift  68 */
/* State 102 */
  {YYNOCODE,0,0}, /* Unused */
/* State 103 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[ 890] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[ 894] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[ 892] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[ 897] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[ 899] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[ 900] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[ 901] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 104 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[ 921] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[ 930] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[ 934] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[ 935] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 111, &yyActionTable[ 936] }, /*                   expr shift  111 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[ 937] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[ 940] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[ 942] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[ 944] }, /*                  MINUS shift  176 */
/* State 105 */
  {YYNOCODE,0,0}, /* Unused */
/* State 106 */
  {  29, 107, 0                    }, /*                    DOT shift  107 */
/* State 107 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[ 955] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[ 958] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[ 961] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[ 963] }, /*                     id shift  37 */
  { 123, 108, &yyActionTable[ 964] }, /*                    ids shift  108 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 108 */
  {YYNOCODE,0,0}, /* Unused */
/* State 109 */
  {YYNOCODE,0,0}, /* Unused */
/* State 110 */
  {YYNOCODE,0,0}, /* Unused */
/* State 111 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[ 991] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {  40, 120, &yyActionTable[ 993] }, /*                     GE shift  120 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  43, 116, &yyActionTable[ 998] }, /*                     GT shift  116 */
  {  72, 141, &yyActionTable[ 992] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[ 994] }, /*                   GLOB shift  139 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  75, 149, &yyActionTable[ 995] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[1000] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 112 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1022] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1031] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1035] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1036] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 113, &yyActionTable[1037] }, /*                   expr shift  113 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1038] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1041] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1043] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1045] }, /*                  MINUS shift  176 */
/* State 113 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[1055] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[1058] }, /*                     GE shift  120 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  72, 141, &yyActionTable[1057] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[1059] }, /*                   GLOB shift  139 */
  {  43, 116, &yyActionTable[1064] }, /*                     GT shift  116 */
  {  75, 149, &yyActionTable[1062] }, /*                    REM shift  149 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[1065] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 114 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1086] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1095] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1099] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1100] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 115, &yyActionTable[1101] }, /*                   expr shift  115 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1102] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1105] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1107] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1109] }, /*                  MINUS shift  176 */
/* State 115 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  83, 147, &yyActionTable[1116] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1117] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, &yyActionTable[1118] }, /*                 RSHIFT shift  132 */
/* State 116 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1134] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1143] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1147] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1148] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 117, &yyActionTable[1149] }, /*                   expr shift  117 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1150] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1153] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1155] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1157] }, /*                  MINUS shift  176 */
/* State 117 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  83, 147, &yyActionTable[1164] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1165] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, &yyActionTable[1166] }, /*                 RSHIFT shift  132 */
/* State 118 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1182] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1191] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1195] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1196] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 119, &yyActionTable[1197] }, /*                   expr shift  119 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1198] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1201] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1203] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1205] }, /*                  MINUS shift  176 */
/* State 119 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  83, 147, &yyActionTable[1212] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1213] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, &yyActionTable[1214] }, /*                 RSHIFT shift  132 */
/* State 120 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1230] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1239] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1243] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1244] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 121, &yyActionTable[1245] }, /*                   expr shift  121 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1246] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1249] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1251] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1253] }, /*                  MINUS shift  176 */
/* State 121 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  83, 147, &yyActionTable[1260] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1261] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, &yyActionTable[1262] }, /*                 RSHIFT shift  132 */
/* State 122 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1278] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1287] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1291] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1292] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 123, &yyActionTable[1293] }, /*                   expr shift  123 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1294] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1297] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1299] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1301] }, /*                  MINUS shift  176 */
/* State 123 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  40, 120, 0                    }, /*                     GE shift  120 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  83, 147, &yyActionTable[1308] }, /*                  SLASH shift  147 */
  {  43, 116, &yyActionTable[1314] }, /*                     GT shift  116 */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  72, 141, &yyActionTable[1309] }, /*                   PLUS shift  141 */
  {  57, 118, &yyActionTable[1310] }, /*                     LE shift  118 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1312] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  79, 132, &yyActionTable[1315] }, /*                 RSHIFT shift  132 */
/* State 124 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1326] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1335] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1339] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1340] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 125, &yyActionTable[1341] }, /*                   expr shift  125 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1342] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1345] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1347] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1349] }, /*                  MINUS shift  176 */
/* State 125 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  40, 120, 0                    }, /*                     GE shift  120 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  83, 147, &yyActionTable[1356] }, /*                  SLASH shift  147 */
  {  43, 116, &yyActionTable[1362] }, /*                     GT shift  116 */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  72, 141, &yyActionTable[1357] }, /*                   PLUS shift  141 */
  {  57, 118, &yyActionTable[1358] }, /*                     LE shift  118 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1360] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  79, 132, &yyActionTable[1363] }, /*                 RSHIFT shift  132 */
/* State 126 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1374] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1383] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1387] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1388] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 127, &yyActionTable[1389] }, /*                   expr shift  127 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1390] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1393] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1395] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1397] }, /*                  MINUS shift  176 */
/* State 127 */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {  75, 149, &yyActionTable[1406] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  83, 147, &yyActionTable[1405] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 128 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1414] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1423] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1427] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1428] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 129, &yyActionTable[1429] }, /*                   expr shift  129 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1430] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1433] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1435] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1437] }, /*                  MINUS shift  176 */
/* State 129 */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {  75, 149, &yyActionTable[1446] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  83, 147, &yyActionTable[1445] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 130 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1454] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1463] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1467] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1468] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 131, &yyActionTable[1469] }, /*                   expr shift  131 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1470] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1473] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1475] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1477] }, /*                  MINUS shift  176 */
/* State 131 */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {  75, 149, &yyActionTable[1486] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  83, 147, &yyActionTable[1485] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 132 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1494] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1503] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1507] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1508] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 133, &yyActionTable[1509] }, /*                   expr shift  133 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1510] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1513] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1515] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1517] }, /*                  MINUS shift  176 */
/* State 133 */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {  75, 149, &yyActionTable[1526] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  83, 147, &yyActionTable[1525] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 134 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1534] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1543] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1547] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1548] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 135, &yyActionTable[1549] }, /*                   expr shift  135 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1550] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1553] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1555] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1557] }, /*                  MINUS shift  176 */
/* State 135 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  40, 120, 0                    }, /*                     GE shift  120 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  83, 147, &yyActionTable[1564] }, /*                  SLASH shift  147 */
  {  43, 116, &yyActionTable[1570] }, /*                     GT shift  116 */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  72, 141, &yyActionTable[1565] }, /*                   PLUS shift  141 */
  {  57, 118, &yyActionTable[1566] }, /*                     LE shift  118 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1568] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  79, 132, &yyActionTable[1571] }, /*                 RSHIFT shift  132 */
/* State 136 */
  {  48, 192, &yyActionTable[1584] }, /*                     IN shift  192 */
  {  41, 185, 0                    }, /*                   GLOB shift  185 */
  {  58, 137, 0                    }, /*                   LIKE shift  137 */
  {  67, 187, 0                    }, /*                   NULL shift  187 */
  {   8, 188, 0                    }, /*                BETWEEN shift  188 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
/* State 137 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1590] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1599] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1603] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1604] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 138, &yyActionTable[1605] }, /*                   expr shift  138 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1606] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1609] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1611] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1613] }, /*                  MINUS shift  176 */
/* State 138 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[1623] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {  40, 120, &yyActionTable[1625] }, /*                     GE shift  120 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  43, 116, &yyActionTable[1630] }, /*                     GT shift  116 */
  {  72, 141, &yyActionTable[1624] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[1626] }, /*                   GLOB shift  139 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  75, 149, &yyActionTable[1627] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[1632] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 139 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1654] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1663] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1667] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1668] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 140, &yyActionTable[1669] }, /*                   expr shift  140 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1670] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1673] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1675] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1677] }, /*                  MINUS shift  176 */
/* State 140 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  40, 120, 0                    }, /*                     GE shift  120 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  83, 147, &yyActionTable[1684] }, /*                  SLASH shift  147 */
  {  43, 116, &yyActionTable[1690] }, /*                     GT shift  116 */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  72, 141, &yyActionTable[1685] }, /*                   PLUS shift  141 */
  {  57, 118, &yyActionTable[1686] }, /*                     LE shift  118 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1688] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  79, 132, &yyActionTable[1691] }, /*                 RSHIFT shift  132 */
/* State 141 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1702] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1711] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1715] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1716] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 142, &yyActionTable[1717] }, /*                   expr shift  142 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1718] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1721] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1723] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1725] }, /*                  MINUS shift  176 */
/* State 142 */
  {  75, 149, &yyActionTable[1734] }, /*                    REM shift  149 */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  83, 147, &yyActionTable[1732] }, /*                  SLASH shift  147 */
/* State 143 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1738] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1747] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1751] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1752] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 144, &yyActionTable[1753] }, /*                   expr shift  144 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1754] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1757] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1759] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1761] }, /*                  MINUS shift  176 */
/* State 144 */
  {  75, 149, &yyActionTable[1770] }, /*                    REM shift  149 */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  83, 147, &yyActionTable[1768] }, /*                  SLASH shift  147 */
/* State 145 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1774] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1783] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1787] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1788] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 146, &yyActionTable[1789] }, /*                   expr shift  146 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1790] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1793] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1795] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1797] }, /*                  MINUS shift  176 */
/* State 146 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
/* State 147 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1807] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1816] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1820] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1821] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 148, &yyActionTable[1822] }, /*                   expr shift  148 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1823] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1826] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1828] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1830] }, /*                  MINUS shift  176 */
/* State 148 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
/* State 149 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1840] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1849] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1853] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1854] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 150, &yyActionTable[1855] }, /*                   expr shift  150 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1856] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1859] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1861] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1863] }, /*                  MINUS shift  176 */
/* State 150 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
/* State 151 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1873] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1882] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1886] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1887] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 152, &yyActionTable[1888] }, /*                   expr shift  152 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1889] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1892] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1894] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1896] }, /*                  MINUS shift  176 */
/* State 152 */
  {YYNOCODE,0,0}, /* Unused */
/* State 153 */
  {YYNOCODE,0,0}, /* Unused */
/* State 154 */
  {  65, 156, 0                    }, /*                    NOT shift  156 */
  {  67, 155, &yyActionTable[1905] }, /*                   NULL shift  155 */
/* State 155 */
  {YYNOCODE,0,0}, /* Unused */
/* State 156 */
  {  67, 157, 0                    }, /*                   NULL shift  157 */
/* State 157 */
  {YYNOCODE,0,0}, /* Unused */
/* State 158 */
  {YYNOCODE,0,0}, /* Unused */
/* State 159 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1913] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1922] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1926] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1927] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 160, &yyActionTable[1928] }, /*                   expr shift  160 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1929] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1932] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1934] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1936] }, /*                  MINUS shift  176 */
/* State 160 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[1946] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 161, 0                    }, /*                    AND shift  161 */
  {  40, 120, &yyActionTable[1950] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[1948] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[1953] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[1955] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[1956] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[1957] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 161 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1977] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1986] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1990] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1991] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 162, &yyActionTable[1992] }, /*                   expr shift  162 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1993] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1996] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1998] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2000] }, /*                  MINUS shift  176 */
/* State 162 */
  {   0, 581, 0                    }, /*                      $ reduce 193 */
  {   1, 581, 0                    }, /*                  ABORT reduce 193 */
  {   4, 549, 0                    }, /*                    AND reduce 161 */
  {  70, 549, 0                    }, /*                     OR reduce 161 */
  {   4, 581, &yyActionTable[2009] }, /*                    AND reduce 193 */
  {   5, 581, 0                    }, /*                     AS reduce 193 */
  {   6, 581, 0                    }, /*                    ASC reduce 193 */
  {   7, 581, 0                    }, /*                  BEGIN reduce 193 */
  {   8, 581, 0                    }, /*                BETWEEN reduce 193 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {YYNOCODE,0,0}, /* Unused */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {YYNOCODE,0,0}, /* Unused */
  {  13, 581, 0                    }, /*                  CHECK reduce 193 */
  {  14, 581, 0                    }, /*                CLUSTER reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {  16, 581, 0                    }, /*                  COMMA reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  20, 581, 0                    }, /*               CONFLICT reduce 193 */
  {  21, 581, 0                    }, /*             CONSTRAINT reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  26, 581, 0                    }, /*             DELIMITERS reduce 193 */
  {  27, 581, 0                    }, /*                   DESC reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31, 581, 0                    }, /*                    END reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {  33, 581, 0                    }, /*                     EQ reduce 193 */
  {  34, 581, 0                    }, /*                 EXCEPT reduce 193 */
  {  35, 581, 0                    }, /*                EXPLAIN reduce 193 */
  {  36, 581, 0                    }, /*                   FAIL reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {  38, 581, 0                    }, /*                   FROM reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {  40, 120, 0                    }, /*                     GE shift  120 */
  {  41, 581, 0                    }, /*                   GLOB reduce 193 */
  {  42, 581, 0                    }, /*                  GROUP reduce 193 */
  {  43, 116, 0                    }, /*                     GT shift  116 */
  {  44, 581, 0                    }, /*                 HAVING reduce 193 */
  {  45, 581, 0                    }, /*                     ID reduce 193 */
  {  46, 581, 0                    }, /*                 IGNORE reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {  48, 581, 0                    }, /*                     IN reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  52, 581, 0                    }, /*              INTERSECT reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {  54, 581, 0                    }, /*                     IS reduce 193 */
  {  55, 581, 0                    }, /*                 ISNULL reduce 193 */
  {  56, 581, 0                    }, /*                    KEY reduce 193 */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 581, 0                    }, /*                   LIKE reduce 193 */
  {  59, 581, 0                    }, /*                  LIMIT reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  64, 581, 0                    }, /*                     NE reduce 193 */
  {  65, 581, 0                    }, /*                    NOT reduce 193 */
  {  66, 581, 0                    }, /*                NOTNULL reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {  68, 581, 0                    }, /*                 OFFSET reduce 193 */
  {  69, 581, 0                    }, /*                     ON reduce 193 */
  {  70, 581, &yyActionTable[2010] }, /*                     OR reduce 193 */
  {  71, 581, 0                    }, /*                  ORDER reduce 193 */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {  73, 581, 0                    }, /*                 PRAGMA reduce 193 */
  {  74, 581, 0                    }, /*                PRIMARY reduce 193 */
  {  75, 149, 0                    }, /*                    REM shift  149 */
  {  76, 581, 0                    }, /*                REPLACE reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {  78, 581, 0                    }, /*                     RP reduce 193 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {YYNOCODE,0,0}, /* Unused */
  {  81, 581, 0                    }, /*                   SEMI reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, 0                    }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  86, 581, 0                    }, /*                 STRING reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {  88, 581, 0                    }, /*                   TEMP reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  92, 581, 0                    }, /*                  UNION reduce 193 */
  {  93, 581, 0                    }, /*                 UNIQUE reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  96, 581, 0                    }, /*                 VACUUM reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {  98, 581, 0                    }, /*                  WHERE reduce 193 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
/* State 163 */
  {  60, 164, 0                    }, /*                     LP shift  164 */
/* State 164 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  65, 172, &yyActionTable[2136] }, /*                    NOT shift  172 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  67, 105, 0                    }, /*                   NULL shift  105 */
  {  68,  30, 0                    }, /*                 OFFSET shift  30 */
  {YYNOCODE,0,0}, /* Unused */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  { 138,  78, &yyActionTable[2138] }, /*              oneselect shift  78 */
  {YYNOCODE,0,0}, /* Unused */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {YYNOCODE,0,0}, /* Unused */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {YYNOCODE,0,0}, /* Unused */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  {YYNOCODE,0,0}, /* Unused */
  { 146, 165, 0                    }, /*                 select shift  165 */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, 0                    }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, 0                    }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 171, 0                    }, /*                   expr shift  171 */
  { 117, 184, 0                    }, /*               expritem shift  184 */
  { 118, 180, 0                    }, /*               exprlist shift  180 */
  {YYNOCODE,0,0}, /* Unused */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  75, 0                    }, /*                     id shift  75 */
  { 123, 106, 0                    }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, 0                    }, /*                  MINUS shift  176 */
/* State 165 */
  {  92, 166, &yyActionTable[2201] }, /*                  UNION shift  166 */
  {  52, 168, 0                    }, /*              INTERSECT shift  168 */
  {  34, 169, 0                    }, /*                 EXCEPT shift  169 */
  {YYNOCODE,0,0}, /* Unused */
  { 132,  80, &yyActionTable[2200] }, /*                 joinop shift  80 */
  {YYNOCODE,0,0}, /* Unused */
  {  78, 170, 0                    }, /*                     RP shift  170 */
  {YYNOCODE,0,0}, /* Unused */
/* State 166 */
  {  80, 479, 0                    }, /*                 SELECT reduce 91 */
  {   3, 167, 0                    }, /*                    ALL shift  167 */
/* State 167 */
  {  80, 480, 0                    }, /*                 SELECT reduce 92 */
/* State 168 */
  {  80, 481, 0                    }, /*                 SELECT reduce 93 */
/* State 169 */
  {  80, 482, 0                    }, /*                 SELECT reduce 94 */
/* State 170 */
  {YYNOCODE,0,0}, /* Unused */
/* State 171 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[2217] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[2221] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[2219] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[2224] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[2226] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[2227] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[2228] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 172 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2248] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2257] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2261] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2262] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 173, &yyActionTable[2263] }, /*                   expr shift  173 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2264] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2267] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2269] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2271] }, /*                  MINUS shift  176 */
/* State 173 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[2281] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {  40, 120, &yyActionTable[2283] }, /*                     GE shift  120 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  43, 116, &yyActionTable[2288] }, /*                     GT shift  116 */
  {  72, 141, &yyActionTable[2282] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[2284] }, /*                   GLOB shift  139 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  75, 149, &yyActionTable[2285] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[2290] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 174 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2312] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2321] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2325] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2326] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 175, &yyActionTable[2327] }, /*                   expr shift  175 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2328] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2331] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2333] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2335] }, /*                  MINUS shift  176 */
/* State 175 */
  {YYNOCODE,0,0}, /* Unused */
/* State 176 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2345] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2354] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2358] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2359] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 177, &yyActionTable[2360] }, /*                   expr shift  177 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2361] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2364] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2366] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2368] }, /*                  MINUS shift  176 */
/* State 177 */
  {YYNOCODE,0,0}, /* Unused */
/* State 178 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2378] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2387] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2391] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2392] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 179, &yyActionTable[2393] }, /*                   expr shift  179 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2394] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2397] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2399] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2401] }, /*                  MINUS shift  176 */
/* State 179 */
  {YYNOCODE,0,0}, /* Unused */
/* State 180 */
  {  78, 181, &yyActionTable[2410] }, /*                     RP shift  181 */
  {  16, 182, 0                    }, /*                  COMMA shift  182 */
/* State 181 */
  {YYNOCODE,0,0}, /* Unused */
/* State 182 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2414] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2423] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2427] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2428] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 171, &yyActionTable[2429] }, /*                   expr shift  171 */
  { 117, 183, 0                    }, /*               expritem shift  183 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  88,  29, &yyActionTable[2430] }, /*                   TEMP shift  29 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  { 122,  75, &yyActionTable[2435] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2437] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2441] }, /*                  MINUS shift  176 */
/* State 183 */
  {YYNOCODE,0,0}, /* Unused */
/* State 184 */
  {YYNOCODE,0,0}, /* Unused */
/* State 185 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2448] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2457] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2461] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2462] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 186, &yyActionTable[2463] }, /*                   expr shift  186 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2464] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2467] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2469] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2471] }, /*                  MINUS shift  176 */
/* State 186 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[2481] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {  40, 120, &yyActionTable[2483] }, /*                     GE shift  120 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  43, 116, &yyActionTable[2488] }, /*                     GT shift  116 */
  {  72, 141, &yyActionTable[2482] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[2484] }, /*                   GLOB shift  139 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  75, 149, &yyActionTable[2485] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[2490] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 187 */
  {YYNOCODE,0,0}, /* Unused */
/* State 188 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2513] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2522] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2526] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2527] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 189, &yyActionTable[2528] }, /*                   expr shift  189 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2529] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2532] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2534] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2536] }, /*                  MINUS shift  176 */
/* State 189 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[2546] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 190, 0                    }, /*                    AND shift  190 */
  {  40, 120, &yyActionTable[2550] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[2548] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[2553] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[2555] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[2556] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[2557] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 190 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2577] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2586] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2590] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2591] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 191, &yyActionTable[2592] }, /*                   expr shift  191 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2593] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2596] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2598] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2600] }, /*                  MINUS shift  176 */
/* State 191 */
  {   0, 582, 0                    }, /*                      $ reduce 194 */
  {   1, 582, 0                    }, /*                  ABORT reduce 194 */
  {   4, 549, 0                    }, /*                    AND reduce 161 */
  {  70, 549, 0                    }, /*                     OR reduce 161 */
  {   4, 582, &yyActionTable[2609] }, /*                    AND reduce 194 */
  {   5, 582, 0                    }, /*                     AS reduce 194 */
  {   6, 582, 0                    }, /*                    ASC reduce 194 */
  {   7, 582, 0                    }, /*                  BEGIN reduce 194 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {YYNOCODE,0,0}, /* Unused */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {YYNOCODE,0,0}, /* Unused */
  {  13, 582, 0                    }, /*                  CHECK reduce 194 */
  {  14, 582, 0                    }, /*                CLUSTER reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {  16, 582, 0                    }, /*                  COMMA reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  20, 582, 0                    }, /*               CONFLICT reduce 194 */
  {  21, 582, 0                    }, /*             CONSTRAINT reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  26, 582, 0                    }, /*             DELIMITERS reduce 194 */
  {  27, 582, 0                    }, /*                   DESC reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31, 582, 0                    }, /*                    END reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {  34, 582, 0                    }, /*                 EXCEPT reduce 194 */
  {  35, 582, 0                    }, /*                EXPLAIN reduce 194 */
  {  36, 582, 0                    }, /*                   FAIL reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {  38, 582, 0                    }, /*                   FROM reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {  40, 120, 0                    }, /*                     GE shift  120 */
  {  41, 139, 0                    }, /*                   GLOB shift  139 */
  {  42, 582, 0                    }, /*                  GROUP reduce 194 */
  {  43, 116, 0                    }, /*                     GT shift  116 */
  {  44, 582, 0                    }, /*                 HAVING reduce 194 */
  {  45, 582, 0                    }, /*                     ID reduce 194 */
  {  46, 582, 0                    }, /*                 IGNORE reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  52, 582, 0                    }, /*              INTERSECT reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {  56, 582, 0                    }, /*                    KEY reduce 194 */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {  59, 582, 0                    }, /*                  LIMIT reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, 0                    }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {YYNOCODE,0,0}, /* Unused */
  {  68, 582, 0                    }, /*                 OFFSET reduce 194 */
  {  69, 582, 0                    }, /*                     ON reduce 194 */
  {  70, 582, &yyActionTable[2610] }, /*                     OR reduce 194 */
  {  71, 582, 0                    }, /*                  ORDER reduce 194 */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {  73, 582, 0                    }, /*                 PRAGMA reduce 194 */
  {  74, 582, 0                    }, /*                PRIMARY reduce 194 */
  {  75, 149, 0                    }, /*                    REM shift  149 */
  {  76, 582, 0                    }, /*                REPLACE reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {  78, 582, 0                    }, /*                     RP reduce 194 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {YYNOCODE,0,0}, /* Unused */
  {  81, 582, 0                    }, /*                   SEMI reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, 0                    }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  86, 582, 0                    }, /*                 STRING reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {  88, 582, 0                    }, /*                   TEMP reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  92, 582, 0                    }, /*                  UNION reduce 194 */
  {  93, 582, 0                    }, /*                 UNIQUE reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  96, 582, 0                    }, /*                 VACUUM reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {  98, 582, 0                    }, /*                  WHERE reduce 194 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
/* State 192 */
  {  60, 193, 0                    }, /*                     LP shift  193 */
/* State 193 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  65, 172, &yyActionTable[2736] }, /*                    NOT shift  172 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  67, 105, 0                    }, /*                   NULL shift  105 */
  {  68,  30, 0                    }, /*                 OFFSET shift  30 */
  {YYNOCODE,0,0}, /* Unused */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  { 138,  78, &yyActionTable[2738] }, /*              oneselect shift  78 */
  {YYNOCODE,0,0}, /* Unused */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {YYNOCODE,0,0}, /* Unused */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {YYNOCODE,0,0}, /* Unused */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  {YYNOCODE,0,0}, /* Unused */
  { 146, 194, 0                    }, /*                 select shift  194 */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, 0                    }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, 0                    }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 171, 0                    }, /*                   expr shift  171 */
  { 117, 184, 0                    }, /*               expritem shift  184 */
  { 118, 196, 0                    }, /*               exprlist shift  196 */
  {YYNOCODE,0,0}, /* Unused */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  75, 0                    }, /*                     id shift  75 */
  { 123, 106, 0                    }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, 0                    }, /*                  MINUS shift  176 */
/* State 194 */
  {  92, 166, &yyActionTable[2801] }, /*                  UNION shift  166 */
  {  52, 168, 0                    }, /*              INTERSECT shift  168 */
  {  34, 169, 0                    }, /*                 EXCEPT shift  169 */
  {YYNOCODE,0,0}, /* Unused */
  { 132,  80, &yyActionTable[2800] }, /*                 joinop shift  80 */
  {YYNOCODE,0,0}, /* Unused */
  {  78, 195, 0                    }, /*                     RP shift  195 */
  {YYNOCODE,0,0}, /* Unused */
/* State 195 */
  {YYNOCODE,0,0}, /* Unused */
/* State 196 */
  {  78, 197, &yyActionTable[2810] }, /*                     RP shift  197 */
  {  16, 182, 0                    }, /*                  COMMA shift  182 */
/* State 197 */
  {YYNOCODE,0,0}, /* Unused */
/* State 198 */
  { 152, 199, 0                    }, /*              sortorder shift  199 */
  {YYNOCODE,0,0}, /* Unused */
  {   6,  67, 0                    }, /*                    ASC shift  67 */
  {  27,  68, 0                    }, /*                   DESC shift  68 */
/* State 199 */
  {YYNOCODE,0,0}, /* Unused */
/* State 200 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2819] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2828] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2832] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2833] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 201, &yyActionTable[2834] }, /*                   expr shift  201 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2835] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2838] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2840] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2842] }, /*                  MINUS shift  176 */
/* State 201 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[2852] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[2856] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[2854] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[2859] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[2861] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[2862] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[2863] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 202 */
  {  12, 203, 0                    }, /*                     BY shift  203 */
/* State 203 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2884] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2893] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2897] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2898] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 171, &yyActionTable[2899] }, /*                   expr shift  171 */
  { 117, 184, 0                    }, /*               expritem shift  184 */
  { 118, 204, &yyActionTable[2900] }, /*               exprlist shift  204 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  88,  29, &yyActionTable[2905] }, /*                   TEMP shift  29 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  { 122,  75, &yyActionTable[2907] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2911] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {  63, 176, &yyActionTable[2912] }, /*                  MINUS shift  176 */
/* State 204 */
  {  16, 182, 0                    }, /*                  COMMA shift  182 */
/* State 205 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2917] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2926] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2930] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2931] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 206, &yyActionTable[2932] }, /*                   expr shift  206 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2933] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2936] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2938] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2940] }, /*                  MINUS shift  176 */
/* State 206 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[2950] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[2954] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[2952] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[2957] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[2959] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[2960] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[2961] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 207 */
  {YYNOCODE,0,0}, /* Unused */
/* State 208 */
  { 147, 209, 0                    }, /*             seltablist shift  209 */
  { 153, 211, &yyActionTable[2980] }, /*             stl_prefix shift  211 */
/* State 209 */
  {  16, 210, 0                    }, /*                  COMMA shift  210 */
/* State 210 */
  {YYNOCODE,0,0}, /* Unused */
/* State 211 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[2986] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[2989] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[2992] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[2994] }, /*                     id shift  37 */
  { 123, 212, &yyActionTable[2995] }, /*                    ids shift  212 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 212 */
  {   0, 497, 0                    }, /*                      $ reduce 109 */
  {   1, 492, 0                    }, /*                  ABORT reduce 104 */
  {   7, 492, 0                    }, /*                  BEGIN reduce 104 */
  {  14, 492, 0                    }, /*                CLUSTER reduce 104 */
  {  68, 492, 0                    }, /*                 OFFSET reduce 104 */
  {   5, 213, 0                    }, /*                     AS shift  213 */
  {   6, 492, 0                    }, /*                    ASC reduce 104 */
  {  71, 497, &yyActionTable[3018] }, /*                  ORDER reduce 109 */
  {  34, 497, 0                    }, /*                 EXCEPT reduce 109 */
  {  73, 492, 0                    }, /*                 PRAGMA reduce 104 */
  {  35, 492, 0                    }, /*                EXPLAIN reduce 104 */
  {YYNOCODE,0,0}, /* Unused */
  {  76, 492, 0                    }, /*                REPLACE reduce 104 */
  {YYNOCODE,0,0}, /* Unused */
  {  78, 497, &yyActionTable[3019] }, /*                     RP reduce 109 */
  {YYNOCODE,0,0}, /* Unused */
  {  16, 497, 0                    }, /*                  COMMA reduce 109 */
  {  81, 497, 0                    }, /*                   SEMI reduce 109 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20, 492, 0                    }, /*               CONFLICT reduce 104 */
  {YYNOCODE,0,0}, /* Unused */
  {  86, 492, 0                    }, /*                 STRING reduce 104 */
  {YYNOCODE,0,0}, /* Unused */
  {  88, 492, 0                    }, /*                   TEMP reduce 104 */
  {YYNOCODE,0,0}, /* Unused */
  {  26, 492, 0                    }, /*             DELIMITERS reduce 104 */
  {  27, 492, 0                    }, /*                   DESC reduce 104 */
  {  92, 497, 0                    }, /*                  UNION reduce 109 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31, 492, 0                    }, /*                    END reduce 104 */
  {  96, 492, 0                    }, /*                 VACUUM reduce 104 */
  {YYNOCODE,0,0}, /* Unused */
  {  98, 497, &yyActionTable[3024] }, /*                  WHERE reduce 109 */
  {  99, 214, &yyActionTable[3026] }, /*                     as shift  214 */
  {  36, 492, 0                    }, /*                   FAIL reduce 104 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  42, 497, 0                    }, /*                  GROUP reduce 109 */
  {YYNOCODE,0,0}, /* Unused */
  {  44, 497, 0                    }, /*                 HAVING reduce 109 */
  {  45, 492, 0                    }, /*                     ID reduce 104 */
  {  46, 492, 0                    }, /*                 IGNORE reduce 104 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  52, 497, 0                    }, /*              INTERSECT reduce 109 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  56, 492, 0                    }, /*                    KEY reduce 104 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  59, 497, 0                    }, /*                  LIMIT reduce 109 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
/* State 213 */
  {YYNOCODE,0,0}, /* Unused */
/* State 214 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3083] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3086] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3089] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3091] }, /*                     id shift  37 */
  { 123, 215, &yyActionTable[3092] }, /*                    ids shift  215 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 215 */
  {YYNOCODE,0,0}, /* Unused */
/* State 216 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[3116] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[3125] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[3129] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[3130] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 217, &yyActionTable[3131] }, /*                   expr shift  217 */
  {  85, 220, 0                    }, /*                   STAR shift  220 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  88,  29, &yyActionTable[3132] }, /*                   TEMP shift  29 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  { 122,  75, &yyActionTable[3137] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[3139] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[3143] }, /*                  MINUS shift  176 */
/* State 217 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[3149] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {   1, 492, 0                    }, /*                  ABORT reduce 104 */
  {  68, 492, &yyActionTable[3156] }, /*                 OFFSET reduce 104 */
  {   5, 213, 0                    }, /*                     AS shift  213 */
  {  70, 112, &yyActionTable[3159] }, /*                     OR shift  112 */
  {   7, 492, 0                    }, /*                  BEGIN reduce 104 */
  {  72, 141, &yyActionTable[3163] }, /*                   PLUS shift  141 */
  {  73, 492, &yyActionTable[3164] }, /*                 PRAGMA reduce 104 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  75, 149, &yyActionTable[3169] }, /*                    REM shift  149 */
  {  76, 492, 0                    }, /*                REPLACE reduce 104 */
  {   6, 492, 0                    }, /*                    ASC reduce 104 */
  {  14, 492, 0                    }, /*                CLUSTER reduce 104 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  16, 489, 0                    }, /*                  COMMA reduce 101 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  83, 147, &yyActionTable[3171] }, /*                  SLASH shift  147 */
  {  20, 492, 0                    }, /*               CONFLICT reduce 104 */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  86, 492, 0                    }, /*                 STRING reduce 104 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  88, 492, 0                    }, /*                   TEMP reduce 104 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  26, 492, 0                    }, /*             DELIMITERS reduce 104 */
  {  27, 492, 0                    }, /*                   DESC reduce 104 */
  {  35, 492, 0                    }, /*                EXPLAIN reduce 104 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31, 492, 0                    }, /*                    END reduce 104 */
  {  96, 492, 0                    }, /*                 VACUUM reduce 104 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {YYNOCODE,0,0}, /* Unused */
  {  99, 218, &yyActionTable[3174] }, /*                     as shift  218 */
  {  36, 492, 0                    }, /*                   FAIL reduce 104 */
  {YYNOCODE,0,0}, /* Unused */
  {  38, 489, 0                    }, /*                   FROM reduce 101 */
  {YYNOCODE,0,0}, /* Unused */
  {  40, 120, 0                    }, /*                     GE shift  120 */
  {  41, 139, 0                    }, /*                   GLOB shift  139 */
  {YYNOCODE,0,0}, /* Unused */
  {  43, 116, 0                    }, /*                     GT shift  116 */
  {YYNOCODE,0,0}, /* Unused */
  {  45, 492, 0                    }, /*                     ID reduce 104 */
  {  46, 492, 0                    }, /*                 IGNORE reduce 104 */
  {YYNOCODE,0,0}, /* Unused */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {  56, 492, 0                    }, /*                    KEY reduce 104 */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 218 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3212] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3215] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3218] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3220] }, /*                     id shift  37 */
  { 123, 219, &yyActionTable[3221] }, /*                    ids shift  219 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 219 */
  {YYNOCODE,0,0}, /* Unused */
/* State 220 */
  {YYNOCODE,0,0}, /* Unused */
/* State 221 */
  {YYNOCODE,0,0}, /* Unused */
/* State 222 */
  {YYNOCODE,0,0}, /* Unused */
/* State 223 */
  {YYNOCODE,0,0}, /* Unused */
/* State 224 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[3250] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[3254] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[3252] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[3257] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[3259] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[3260] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  78, 225, 0                    }, /*                     RP shift  225 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[3264] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 225 */
  {YYNOCODE,0,0}, /* Unused */
/* State 226 */
  {  78, 227, &yyActionTable[3281] }, /*                     RP shift  227 */
  {  16, 182, 0                    }, /*                  COMMA shift  182 */
/* State 227 */
  {YYNOCODE,0,0}, /* Unused */
/* State 228 */
  {  78, 229, 0                    }, /*                     RP shift  229 */
/* State 229 */
  {YYNOCODE,0,0}, /* Unused */
/* State 230 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[3288] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[3292] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[3290] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[3295] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[3297] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[3298] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  78, 231, 0                    }, /*                     RP shift  231 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[3302] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 231 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
  { 137, 232, &yyActionTable[3317] }, /*                 onconf shift  232 */
/* State 232 */
  {YYNOCODE,0,0}, /* Unused */
/* State 233 */
  {YYNOCODE,0,0}, /* Unused */
/* State 234 */
  {  72, 238, 0                    }, /*                   PLUS shift  238 */
  {  51, 237, 0                    }, /*                INTEGER shift  237 */
  {  37, 244, 0                    }, /*                  FLOAT shift  244 */
  {  67, 245, &yyActionTable[3322] }, /*                   NULL shift  245 */
  {YYNOCODE,0,0}, /* Unused */
  {  45, 236, &yyActionTable[3323] }, /*                     ID shift  236 */
  {  86, 235, 0                    }, /*                 STRING shift  235 */
  {  63, 241, 0                    }, /*                  MINUS shift  241 */
/* State 235 */
  {YYNOCODE,0,0}, /* Unused */
/* State 236 */
  {YYNOCODE,0,0}, /* Unused */
/* State 237 */
  {YYNOCODE,0,0}, /* Unused */
/* State 238 */
  {  37, 240, 0                    }, /*                  FLOAT shift  240 */
  {  51, 239, &yyActionTable[3332] }, /*                INTEGER shift  239 */
/* State 239 */
  {YYNOCODE,0,0}, /* Unused */
/* State 240 */
  {YYNOCODE,0,0}, /* Unused */
/* State 241 */
  {  37, 243, 0                    }, /*                  FLOAT shift  243 */
  {  51, 242, &yyActionTable[3336] }, /*                INTEGER shift  242 */
/* State 242 */
  {YYNOCODE,0,0}, /* Unused */
/* State 243 */
  {YYNOCODE,0,0}, /* Unused */
/* State 244 */
  {YYNOCODE,0,0}, /* Unused */
/* State 245 */
  {YYNOCODE,0,0}, /* Unused */
/* State 246 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3344] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3347] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3350] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3352] }, /*                     id shift  37 */
  { 123, 258, &yyActionTable[3353] }, /*                    ids shift  258 */
  {  60, 247, 0                    }, /*                     LP shift  247 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 247 */
  {  72, 254, 0                    }, /*                   PLUS shift  254 */
  { 149, 248, 0                    }, /*                 signed shift  248 */
  {  51, 253, 0                    }, /*                INTEGER shift  253 */
  {  63, 256, &yyActionTable[3376] }, /*                  MINUS shift  256 */
/* State 248 */
  {  78, 249, &yyActionTable[3379] }, /*                     RP shift  249 */
  {  16, 250, 0                    }, /*                  COMMA shift  250 */
/* State 249 */
  {YYNOCODE,0,0}, /* Unused */
/* State 250 */
  {  72, 254, 0                    }, /*                   PLUS shift  254 */
  { 149, 251, 0                    }, /*                 signed shift  251 */
  {  51, 253, 0                    }, /*                INTEGER shift  253 */
  {  63, 256, &yyActionTable[3383] }, /*                  MINUS shift  256 */
/* State 251 */
  {  78, 252, 0                    }, /*                     RP shift  252 */
/* State 252 */
  {YYNOCODE,0,0}, /* Unused */
/* State 253 */
  {YYNOCODE,0,0}, /* Unused */
/* State 254 */
  {  51, 255, 0                    }, /*                INTEGER shift  255 */
/* State 255 */
  {YYNOCODE,0,0}, /* Unused */
/* State 256 */
  {  51, 257, 0                    }, /*                INTEGER shift  257 */
/* State 257 */
  {YYNOCODE,0,0}, /* Unused */
/* State 258 */
  {YYNOCODE,0,0}, /* Unused */
/* State 259 */
  {YYNOCODE,0,0}, /* Unused */
/* State 260 */
  {YYNOCODE,0,0}, /* Unused */
/* State 261 */
  {  16, 262, 0                    }, /*                  COMMA shift  262 */
  {  74, 266, 0                    }, /*                PRIMARY shift  266 */
  { 154, 284, &yyActionTable[3396] }, /*                  tcons shift  284 */
  {  21, 264, &yyActionTable[3399] }, /*             CONSTRAINT shift  264 */
  {  13, 281, 0                    }, /*                  CHECK shift  281 */
  {  93, 276, &yyActionTable[3398] }, /*                 UNIQUE shift  276 */
  {  78, 458, 0                    }, /*                     RP reduce 70 */
  {YYNOCODE,0,0}, /* Unused */
/* State 262 */
  {  74, 266, 0                    }, /*                PRIMARY shift  266 */
  {  21, 264, &yyActionTable[3406] }, /*             CONSTRAINT shift  264 */
  { 154, 263, &yyActionTable[3403] }, /*                  tcons shift  263 */
  {  13, 281, 0                    }, /*                  CHECK shift  281 */
  {YYNOCODE,0,0}, /* Unused */
  {  93, 276, &yyActionTable[3404] }, /*                 UNIQUE shift  276 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
/* State 263 */
  {YYNOCODE,0,0}, /* Unused */
/* State 264 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3414] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3417] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3420] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3422] }, /*                     id shift  37 */
  { 123, 265, &yyActionTable[3423] }, /*                    ids shift  265 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 265 */
  {YYNOCODE,0,0}, /* Unused */
/* State 266 */
  {  56, 267, 0                    }, /*                    KEY shift  267 */
/* State 267 */
  {  60, 268, 0                    }, /*                     LP shift  268 */
/* State 268 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3449] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3452] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3455] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3457] }, /*                     id shift  37 */
  { 123, 274, &yyActionTable[3458] }, /*                    ids shift  274 */
  { 124, 275, 0                    }, /*                idxitem shift  275 */
  { 125, 269, 0                    }, /*                idxlist shift  269 */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 269 */
  {  78, 270, &yyActionTable[3480] }, /*                     RP shift  270 */
  {  16, 272, 0                    }, /*                  COMMA shift  272 */
/* State 270 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
  { 137, 271, &yyActionTable[3481] }, /*                 onconf shift  271 */
/* State 271 */
  {YYNOCODE,0,0}, /* Unused */
/* State 272 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3486] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3489] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3492] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3494] }, /*                     id shift  37 */
  { 123, 274, &yyActionTable[3495] }, /*                    ids shift  274 */
  { 124, 273, 0                    }, /*                idxitem shift  273 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 273 */
  {YYNOCODE,0,0}, /* Unused */
/* State 274 */
  {YYNOCODE,0,0}, /* Unused */
/* State 275 */
  {YYNOCODE,0,0}, /* Unused */
/* State 276 */
  {  60, 277, 0                    }, /*                     LP shift  277 */
/* State 277 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3522] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3525] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3528] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3530] }, /*                     id shift  37 */
  { 123, 274, &yyActionTable[3531] }, /*                    ids shift  274 */
  { 124, 275, 0                    }, /*                idxitem shift  275 */
  { 125, 278, 0                    }, /*                idxlist shift  278 */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 278 */
  {  78, 279, &yyActionTable[3553] }, /*                     RP shift  279 */
  {  16, 272, 0                    }, /*                  COMMA shift  272 */
/* State 279 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
  { 137, 280, &yyActionTable[3554] }, /*                 onconf shift  280 */
/* State 280 */
  {YYNOCODE,0,0}, /* Unused */
/* State 281 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[3559] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[3568] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[3572] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[3573] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 282, &yyActionTable[3574] }, /*                   expr shift  282 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[3575] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[3578] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[3580] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[3582] }, /*                  MINUS shift  176 */
/* State 282 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[3592] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {  40, 120, &yyActionTable[3599] }, /*                     GE shift  120 */
  {  72, 141, &yyActionTable[3596] }, /*                   PLUS shift  141 */
  { 137, 283, &yyActionTable[3601] }, /*                 onconf shift  283 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  75, 149, &yyActionTable[3602] }, /*                    REM shift  149 */
  {  41, 139, &yyActionTable[3603] }, /*                   GLOB shift  139 */
  {  43, 116, &yyActionTable[3606] }, /*                     GT shift  116 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  83, 147, &yyActionTable[3607] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 283 */
  {YYNOCODE,0,0}, /* Unused */
/* State 284 */
  {YYNOCODE,0,0}, /* Unused */
/* State 285 */
  {YYNOCODE,0,0}, /* Unused */
/* State 286 */
  {YYNOCODE,0,0}, /* Unused */
/* State 287 */
  {  88, 291, 0                    }, /*                   TEMP shift  291 */
  {  49, 593, 0                    }, /*                  INDEX reduce 205 */
  {  87, 405, 0                    }, /*                  TABLE reduce 17 */
  { 155, 288, 0                    }, /*                   temp shift  288 */
  {YYNOCODE,0,0}, /* Unused */
  {  93, 301, 0                    }, /*                 UNIQUE shift  301 */
  {YYNOCODE,0,0}, /* Unused */
  { 159, 292, &yyActionTable[3627] }, /*             uniqueflag shift  292 */
/* State 288 */
  {  87, 289, 0                    }, /*                  TABLE shift  289 */
/* State 289 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3636] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3639] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3642] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3644] }, /*                     id shift  37 */
  { 123, 290, &yyActionTable[3645] }, /*                    ids shift  290 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 290 */
  {  60, 403, 0                    }, /*                     LP reduce 15 */
/* State 291 */
  {  87, 404, 0                    }, /*                  TABLE reduce 16 */
/* State 292 */
  {  49, 293, 0                    }, /*                  INDEX shift  293 */
/* State 293 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3671] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3674] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3677] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3679] }, /*                     id shift  37 */
  { 123, 294, &yyActionTable[3680] }, /*                    ids shift  294 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 294 */
  {  69, 295, 0                    }, /*                     ON shift  295 */
/* State 295 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3704] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3707] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3710] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3712] }, /*                     id shift  37 */
  { 123, 296, &yyActionTable[3713] }, /*                    ids shift  296 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 296 */
  {  60, 297, 0                    }, /*                     LP shift  297 */
/* State 297 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3737] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3740] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3743] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3745] }, /*                     id shift  37 */
  { 123, 274, &yyActionTable[3746] }, /*                    ids shift  274 */
  { 124, 275, 0                    }, /*                idxitem shift  275 */
  { 125, 298, 0                    }, /*                idxlist shift  298 */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 298 */
  {  78, 299, &yyActionTable[3768] }, /*                     RP shift  299 */
  {  16, 272, 0                    }, /*                  COMMA shift  272 */
/* State 299 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
  { 137, 300, &yyActionTable[3769] }, /*                 onconf shift  300 */
/* State 300 */
  {YYNOCODE,0,0}, /* Unused */
/* State 301 */
  {  49, 592, 0                    }, /*                  INDEX reduce 204 */
/* State 302 */
  {  49, 305, 0                    }, /*                  INDEX shift  305 */
  {  87, 303, &yyActionTable[3773] }, /*                  TABLE shift  303 */
/* State 303 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3777] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3780] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3783] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3785] }, /*                     id shift  37 */
  { 123, 304, &yyActionTable[3786] }, /*                    ids shift  304 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 304 */
  {YYNOCODE,0,0}, /* Unused */
/* State 305 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3810] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3813] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3816] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3818] }, /*                     id shift  37 */
  { 123, 306, &yyActionTable[3819] }, /*                    ids shift  306 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 306 */
  {YYNOCODE,0,0}, /* Unused */
/* State 307 */
  { 132,  80, &yyActionTable[3842] }, /*                 joinop shift  80 */
  {  92, 166, &yyActionTable[3844] }, /*                  UNION shift  166 */
  {  34, 169, 0                    }, /*                 EXCEPT shift  169 */
  {  52, 168, 0                    }, /*              INTERSECT shift  168 */
/* State 308 */
  {  38, 309, 0                    }, /*                   FROM shift  309 */
/* State 309 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3848] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3851] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3854] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3856] }, /*                     id shift  37 */
  { 123, 310, &yyActionTable[3857] }, /*                    ids shift  310 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 310 */
  { 160, 311, &yyActionTable[3879] }, /*              where_opt shift  311 */
  {  98, 205, 0                    }, /*                  WHERE shift  205 */
/* State 311 */
  {YYNOCODE,0,0}, /* Unused */
/* State 312 */
  {  70, 313, 0                    }, /*                     OR shift  313 */
  { 139, 315, 0                    }, /*                 orconf shift  315 */
/* State 313 */
  {  36,  14, 0                    }, /*                   FAIL shift  14 */
  {   1,  13, 0                    }, /*                  ABORT shift  13 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  76,  16, &yyActionTable[3883] }, /*                REPLACE shift  16 */
  {  77,  12, 0                    }, /*               ROLLBACK shift  12 */
  {  46,  15, 0                    }, /*                 IGNORE shift  15 */
  { 143, 314, 0                    }, /*            resolvetype shift  314 */
/* State 314 */
  {YYNOCODE,0,0}, /* Unused */
/* State 315 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3894] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3897] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3900] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3902] }, /*                     id shift  37 */
  { 123, 316, &yyActionTable[3903] }, /*                    ids shift  316 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 316 */
  {  82, 317, 0                    }, /*                    SET shift  317 */
/* State 317 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3927] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3930] }, /*                 IGNORE shift  33 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  { 148, 318, &yyActionTable[3933] }, /*                setlist shift  318 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3935] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3936] }, /*                     id shift  37 */
  { 123, 324, &yyActionTable[3940] }, /*                    ids shift  324 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 318 */
  { 160, 319, &yyActionTable[3958] }, /*              where_opt shift  319 */
  {  16, 320, 0                    }, /*                  COMMA shift  320 */
  {  98, 205, 0                    }, /*                  WHERE shift  205 */
  {YYNOCODE,0,0}, /* Unused */
/* State 319 */
  {YYNOCODE,0,0}, /* Unused */
/* State 320 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3964] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3967] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3970] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3972] }, /*                     id shift  37 */
  { 123, 321, &yyActionTable[3973] }, /*                    ids shift  321 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 321 */
  {  33, 322, 0                    }, /*                     EQ shift  322 */
/* State 322 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[3997] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[4006] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[4010] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[4011] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 323, &yyActionTable[4012] }, /*                   expr shift  323 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[4013] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[4016] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[4018] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[4020] }, /*                  MINUS shift  176 */
/* State 323 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[4030] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[4034] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[4032] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[4037] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[4039] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[4040] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[4041] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 324 */
  {  33, 325, 0                    }, /*                     EQ shift  325 */
/* State 325 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[4062] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[4071] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[4075] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[4076] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 326, &yyActionTable[4077] }, /*                   expr shift  326 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[4078] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[4081] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[4083] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[4085] }, /*                  MINUS shift  176 */
/* State 326 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[4095] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[4099] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[4097] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[4102] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[4104] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[4105] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[4106] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {YYNOCODE,0,0}, /* Unused */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 327 */
  {  53, 328, 0                    }, /*                   INTO shift  328 */
/* State 328 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4127] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4130] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4133] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4135] }, /*                     id shift  37 */
  { 123, 329, &yyActionTable[4136] }, /*                    ids shift  329 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 329 */
  { 128, 330, &yyActionTable[4158] }, /*         inscollist_opt shift  330 */
  {  60, 349, 0                    }, /*                     LP shift  349 */
/* State 330 */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  {  97, 332, 0                    }, /*                 VALUES shift  332 */
  { 146, 331, &yyActionTable[4162] }, /*                 select shift  331 */
  { 138,  78, 0                    }, /*              oneselect shift  78 */
/* State 331 */
  { 132,  80, &yyActionTable[4164] }, /*                 joinop shift  80 */
  {  92, 166, &yyActionTable[4166] }, /*                  UNION shift  166 */
  {  34, 169, 0                    }, /*                 EXCEPT shift  169 */
  {  52, 168, 0                    }, /*              INTERSECT shift  168 */
/* State 332 */
  {  60, 333, 0                    }, /*                     LP shift  333 */
/* State 333 */
  {  72, 339, 0                    }, /*                   PLUS shift  339 */
  {  67, 347, &yyActionTable[4172] }, /*                   NULL shift  347 */
  { 130, 348, 0                    }, /*                   item shift  348 */
  { 131, 334, &yyActionTable[4169] }, /*               itemlist shift  334 */
  {  51, 338, 0                    }, /*                INTEGER shift  338 */
  {  37, 345, 0                    }, /*                  FLOAT shift  345 */
  {  86, 346, 0                    }, /*                 STRING shift  346 */
  {  63, 342, 0                    }, /*                  MINUS shift  342 */
/* State 334 */
  {  78, 335, &yyActionTable[4177] }, /*                     RP shift  335 */
  {  16, 336, 0                    }, /*                  COMMA shift  336 */
/* State 335 */
  {YYNOCODE,0,0}, /* Unused */
/* State 336 */
  {  72, 339, 0                    }, /*                   PLUS shift  339 */
  {  51, 338, 0                    }, /*                INTEGER shift  338 */
  { 130, 337, 0                    }, /*                   item shift  337 */
  {  67, 347, &yyActionTable[4180] }, /*                   NULL shift  347 */
  {YYNOCODE,0,0}, /* Unused */
  {  37, 345, 0                    }, /*                  FLOAT shift  345 */
  {  86, 346, 0                    }, /*                 STRING shift  346 */
  {  63, 342, 0                    }, /*                  MINUS shift  342 */
/* State 337 */
  {YYNOCODE,0,0}, /* Unused */
/* State 338 */
  {YYNOCODE,0,0}, /* Unused */
/* State 339 */
  {  37, 341, 0                    }, /*                  FLOAT shift  341 */
  {  51, 340, &yyActionTable[4189] }, /*                INTEGER shift  340 */
/* State 340 */
  {YYNOCODE,0,0}, /* Unused */
/* State 341 */
  {YYNOCODE,0,0}, /* Unused */
/* State 342 */
  {  37, 344, 0                    }, /*                  FLOAT shift  344 */
  {  51, 343, &yyActionTable[4193] }, /*                INTEGER shift  343 */
/* State 343 */
  {YYNOCODE,0,0}, /* Unused */
/* State 344 */
  {YYNOCODE,0,0}, /* Unused */
/* State 345 */
  {YYNOCODE,0,0}, /* Unused */
/* State 346 */
  {YYNOCODE,0,0}, /* Unused */
/* State 347 */
  {YYNOCODE,0,0}, /* Unused */
/* State 348 */
  {YYNOCODE,0,0}, /* Unused */
/* State 349 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4203] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4206] }, /*                 IGNORE shift  33 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4209] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4211] }, /*                     id shift  37 */
  { 123, 354, &yyActionTable[4212] }, /*                    ids shift  354 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  { 127, 350, &yyActionTable[4216] }, /*             inscollist shift  350 */
/* State 350 */
  {  78, 351, &yyActionTable[4234] }, /*                     RP shift  351 */
  {  16, 352, 0                    }, /*                  COMMA shift  352 */
/* State 351 */
  {YYNOCODE,0,0}, /* Unused */
/* State 352 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4238] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4241] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4244] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4246] }, /*                     id shift  37 */
  { 123, 353, &yyActionTable[4247] }, /*                    ids shift  353 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 353 */
  {YYNOCODE,0,0}, /* Unused */
/* State 354 */
  {YYNOCODE,0,0}, /* Unused */
/* State 355 */
  {YYNOCODE,0,0}, /* Unused */
  {  53, 468, 0                    }, /*                   INTO reduce 80 */
  {  70, 313, 0                    }, /*                     OR shift  313 */
  { 139, 356, 0                    }, /*                 orconf shift  356 */
/* State 356 */
  {  53, 524, 0                    }, /*                   INTO reduce 136 */
/* State 357 */
  {  53, 525, 0                    }, /*                   INTO reduce 137 */
/* State 358 */
  {  70, 313, 0                    }, /*                     OR shift  313 */
  { 139, 359, 0                    }, /*                 orconf shift  359 */
/* State 359 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4280] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4283] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4286] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4288] }, /*                     id shift  37 */
  { 123, 360, &yyActionTable[4289] }, /*                    ids shift  360 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 360 */
  {  38, 361, 0                    }, /*                   FROM shift  361 */
/* State 361 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4313] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4316] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4319] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4321] }, /*                     id shift  37 */
  { 123, 362, &yyActionTable[4322] }, /*                    ids shift  362 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 362 */
  {  95, 363, 0                    }, /*                  USING shift  363 */
/* State 363 */
  {  26, 364, 0                    }, /*             DELIMITERS shift  364 */
/* State 364 */
  {  86, 365, 0                    }, /*                 STRING shift  365 */
/* State 365 */
  {YYNOCODE,0,0}, /* Unused */
/* State 366 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4349] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4352] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4355] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4357] }, /*                     id shift  37 */
  { 123, 367, &yyActionTable[4358] }, /*                    ids shift  367 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 367 */
  {YYNOCODE,0,0}, /* Unused */
/* State 368 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4382] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4385] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4388] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4390] }, /*                     id shift  37 */
  { 123, 369, &yyActionTable[4391] }, /*                    ids shift  369 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 369 */
  {  60, 382, 0                    }, /*                     LP shift  382 */
  {  33, 370, 0                    }, /*                     EQ shift  370 */
/* State 370 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4416] }, /*                 OFFSET shift  30 */
  {  69, 372, 0                    }, /*                     ON shift  372 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  { 135, 374, &yyActionTable[4424] }, /*              minus_num shift  374 */
  {  72, 381, 0                    }, /*                   PLUS shift  381 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  { 141, 373, &yyActionTable[4425] }, /*               plus_num shift  373 */
  { 142, 375, &yyActionTable[4429] }, /*               plus_opt shift  375 */
  {  46,  33, &yyActionTable[4430] }, /*                 IGNORE shift  33 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4431] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4432] }, /*                     id shift  37 */
  { 123, 371, &yyActionTable[4433] }, /*                    ids shift  371 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 379, &yyActionTable[4435] }, /*                  MINUS shift  379 */
/* State 371 */
  {YYNOCODE,0,0}, /* Unused */
/* State 372 */
  {YYNOCODE,0,0}, /* Unused */
/* State 373 */
  {YYNOCODE,0,0}, /* Unused */
/* State 374 */
  {YYNOCODE,0,0}, /* Unused */
/* State 375 */
  { 136, 376, 0                    }, /*                 number shift  376 */
  {  37, 378, 0                    }, /*                  FLOAT shift  378 */
  {YYNOCODE,0,0}, /* Unused */
  {  51, 377, 0                    }, /*                INTEGER shift  377 */
/* State 376 */
  {YYNOCODE,0,0}, /* Unused */
/* State 377 */
  {YYNOCODE,0,0}, /* Unused */
/* State 378 */
  {YYNOCODE,0,0}, /* Unused */
/* State 379 */
  { 136, 380, 0                    }, /*                 number shift  380 */
  {  37, 378, 0                    }, /*                  FLOAT shift  378 */
  {YYNOCODE,0,0}, /* Unused */
  {  51, 377, 0                    }, /*                INTEGER shift  377 */
/* State 380 */
  {YYNOCODE,0,0}, /* Unused */
/* State 381 */
  {YYNOCODE,0,0}, /* Unused */
/* State 382 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4465] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4468] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4471] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4473] }, /*                     id shift  37 */
  { 123, 383, &yyActionTable[4474] }, /*                    ids shift  383 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 383 */
  {  78, 384, 0                    }, /*                     RP shift  384 */
/* State 384 */
  {YYNOCODE,0,0}, /* Unused */
/* State 385 */
  {YYNOCODE,0,0}, /* Unused */
/* State 386 */
  {YYNOCODE,0,0}, /* Unused */
/* State 387 */
  {YYNOCODE,0,0}, /* Unused */
};

/* The state table contains information needed to look up the correct
** action in the action table, given the current state of the parser.
** Information needed includes:
**
**  +  A pointer to the start of the action hash table in yyActionTable.
**
**  +  A mask used to hash the look-ahead token.  The mask is an integer
**     which is one less than the size of the hash table.  
**
**  +  The default action.  This is the action to take if no entry for
**     the given look-ahead is found in the action hash table.
*/
struct yyStateEntry {
  struct yyActionEntry *hashtbl; /* Start of the hash table in yyActionTable */
  int mask;                      /* Mask used for hashing the look-ahead */
  YYACTIONTYPE actionDefault;    /* Default action if look-ahead not found */
};
static struct yyStateEntry yyStateTable[] = {
  { &yyActionTable[0], 31, 393},
  { &yyActionTable[32], 1, 614},
  { &yyActionTable[34], 31, 393},
  { &yyActionTable[66], 0, 390},
  { &yyActionTable[67], 31, 614},
  { &yyActionTable[99], 0, 391},
  { &yyActionTable[100], 1, 396},
  { &yyActionTable[102], 1, 466},
  { &yyActionTable[104], 0, 395},
  { &yyActionTable[105], 0, 614},
  { &yyActionTable[106], 7, 614},
  { &yyActionTable[114], 0, 467},
  { &yyActionTable[115], 0, 470},
  { &yyActionTable[116], 0, 471},
  { &yyActionTable[117], 0, 472},
  { &yyActionTable[118], 0, 473},
  { &yyActionTable[119], 0, 474},
  { &yyActionTable[120], 31, 397},
  { &yyActionTable[152], 0, 398},
  { &yyActionTable[153], 0, 411},
  { &yyActionTable[154], 0, 412},
  { &yyActionTable[155], 0, 413},
  { &yyActionTable[156], 0, 414},
  { &yyActionTable[157], 0, 415},
  { &yyActionTable[158], 0, 416},
  { &yyActionTable[159], 0, 417},
  { &yyActionTable[160], 0, 418},
  { &yyActionTable[161], 0, 419},
  { &yyActionTable[162], 0, 420},
  { &yyActionTable[163], 0, 421},
  { &yyActionTable[164], 0, 422},
  { &yyActionTable[165], 0, 423},
  { &yyActionTable[166], 0, 424},
  { &yyActionTable[167], 0, 425},
  { &yyActionTable[168], 0, 426},
  { &yyActionTable[169], 0, 427},
  { &yyActionTable[170], 0, 428},
  { &yyActionTable[171], 0, 429},
  { &yyActionTable[172], 0, 430},
  { &yyActionTable[173], 1, 396},
  { &yyActionTable[175], 0, 399},
  { &yyActionTable[176], 1, 396},
  { &yyActionTable[178], 0, 400},
  { &yyActionTable[179], 1, 396},
  { &yyActionTable[181], 0, 401},
  { &yyActionTable[182], 1, 614},
  { &yyActionTable[184], 0, 402},
  { &yyActionTable[185], 31, 614},
  { &yyActionTable[217], 3, 614},
  { &yyActionTable[221], 0, 614},
  { &yyActionTable[222], 0, 406},
  { &yyActionTable[223], 31, 614},
  { &yyActionTable[255], 0, 407},
  { &yyActionTable[256], 31, 431},
  { &yyActionTable[288], 0, 441},
  { &yyActionTable[289], 7, 409},
  { &yyActionTable[297], 0, 440},
  { &yyActionTable[298], 31, 614},
  { &yyActionTable[330], 7, 614},
  { &yyActionTable[338], 0, 442},
  { &yyActionTable[339], 0, 614},
  { &yyActionTable[340], 1, 466},
  { &yyActionTable[342], 0, 453},
  { &yyActionTable[343], 0, 614},
  { &yyActionTable[344], 3, 506},
  { &yyActionTable[348], 1, 466},
  { &yyActionTable[350], 0, 454},
  { &yyActionTable[351], 0, 504},
  { &yyActionTable[352], 0, 505},
  { &yyActionTable[353], 1, 466},
  { &yyActionTable[355], 0, 455},
  { &yyActionTable[356], 0, 614},
  { &yyActionTable[357], 31, 614},
  { &yyActionTable[389], 0, 420},
  { &yyActionTable[390], 63, 590},
  { &yyActionTable[454], 127, 614},
  { &yyActionTable[582], 127, 614},
  { &yyActionTable[710], 63, 614},
  { &yyActionTable[774], 0, 477},
  { &yyActionTable[775], 7, 614},
  { &yyActionTable[783], 1, 614},
  { &yyActionTable[785], 0, 478},
  { &yyActionTable[786], 3, 486},
  { &yyActionTable[790], 1, 488},
  { &yyActionTable[792], 3, 614},
  { &yyActionTable[796], 1, 517},
  { &yyActionTable[798], 1, 507},
  { &yyActionTable[800], 1, 509},
  { &yyActionTable[802], 1, 499},
  { &yyActionTable[804], 1, 511},
  { &yyActionTable[806], 0, 483},
  { &yyActionTable[807], 0, 614},
  { &yyActionTable[808], 3, 512},
  { &yyActionTable[812], 0, 614},
  { &yyActionTable[813], 0, 513},
  { &yyActionTable[814], 0, 614},
  { &yyActionTable[815], 0, 614},
  { &yyActionTable[816], 0, 614},
  { &yyActionTable[817], 31, 614},
  { &yyActionTable[849], 0, 500},
  { &yyActionTable[850], 31, 614},
  { &yyActionTable[882], 3, 506},
  { &yyActionTable[886], 0, 501},
  { &yyActionTable[887], 31, 503},
  { &yyActionTable[919], 31, 614},
  { &yyActionTable[951], 0, 541},
  { &yyActionTable[952], 0, 614},
  { &yyActionTable[953], 31, 614},
  { &yyActionTable[985], 0, 543},
  { &yyActionTable[986], 0, 544},
  { &yyActionTable[987], 0, 545},
  { &yyActionTable[988], 31, 549},
  { &yyActionTable[1020], 31, 614},
  { &yyActionTable[1052], 31, 550},
  { &yyActionTable[1084], 31, 614},
  { &yyActionTable[1116], 15, 551},
  { &yyActionTable[1132], 31, 614},
  { &yyActionTable[1164], 15, 552},
  { &yyActionTable[1180], 31, 614},
  { &yyActionTable[1212], 15, 553},
  { &yyActionTable[1228], 31, 614},
  { &yyActionTable[1260], 15, 554},
  { &yyActionTable[1276], 31, 614},
  { &yyActionTable[1308], 15, 555},
  { &yyActionTable[1324], 31, 614},
  { &yyActionTable[1356], 15, 556},
  { &yyActionTable[1372], 31, 614},
  { &yyActionTable[1404], 7, 557},
  { &yyActionTable[1412], 31, 614},
  { &yyActionTable[1444], 7, 558},
  { &yyActionTable[1452], 31, 614},
  { &yyActionTable[1484], 7, 559},
  { &yyActionTable[1492], 31, 614},
  { &yyActionTable[1524], 7, 560},
  { &yyActionTable[1532], 31, 614},
  { &yyActionTable[1564], 15, 561},
  { &yyActionTable[1580], 7, 614},
  { &yyActionTable[1588], 31, 614},
  { &yyActionTable[1620], 31, 562},
  { &yyActionTable[1652], 31, 614},
  { &yyActionTable[1684], 15, 563},
  { &yyActionTable[1700], 31, 614},
  { &yyActionTable[1732], 3, 565},
  { &yyActionTable[1736], 31, 614},
  { &yyActionTable[1768], 3, 566},
  { &yyActionTable[1772], 31, 614},
  { &yyActionTable[1804], 0, 567},
  { &yyActionTable[1805], 31, 614},
  { &yyActionTable[1837], 0, 568},
  { &yyActionTable[1838], 31, 614},
  { &yyActionTable[1870], 0, 569},
  { &yyActionTable[1871], 31, 614},
  { &yyActionTable[1903], 0, 570},
  { &yyActionTable[1904], 0, 571},
  { &yyActionTable[1905], 1, 614},
  { &yyActionTable[1907], 0, 572},
  { &yyActionTable[1908], 0, 614},
  { &yyActionTable[1909], 0, 575},
  { &yyActionTable[1910], 0, 573},
  { &yyActionTable[1911], 31, 614},
  { &yyActionTable[1943], 31, 614},
  { &yyActionTable[1975], 31, 614},
  { &yyActionTable[2007], 127, 614},
  { &yyActionTable[2135], 0, 614},
  { &yyActionTable[2136], 63, 590},
  { &yyActionTable[2200], 7, 614},
  { &yyActionTable[2208], 1, 614},
  { &yyActionTable[2210], 0, 614},
  { &yyActionTable[2211], 0, 614},
  { &yyActionTable[2212], 0, 614},
  { &yyActionTable[2213], 0, 584},
  { &yyActionTable[2214], 31, 589},
  { &yyActionTable[2246], 31, 614},
  { &yyActionTable[2278], 31, 576},
  { &yyActionTable[2310], 31, 614},
  { &yyActionTable[2342], 0, 577},
  { &yyActionTable[2343], 31, 614},
  { &yyActionTable[2375], 0, 578},
  { &yyActionTable[2376], 31, 614},
  { &yyActionTable[2408], 0, 579},
  { &yyActionTable[2409], 1, 614},
  { &yyActionTable[2411], 0, 583},
  { &yyActionTable[2412], 31, 590},
  { &yyActionTable[2444], 0, 587},
  { &yyActionTable[2445], 0, 588},
  { &yyActionTable[2446], 31, 614},
  { &yyActionTable[2478], 31, 564},
  { &yyActionTable[2510], 0, 574},
  { &yyActionTable[2511], 31, 614},
  { &yyActionTable[2543], 31, 614},
  { &yyActionTable[2575], 31, 614},
  { &yyActionTable[2607], 127, 614},
  { &yyActionTable[2735], 0, 614},
  { &yyActionTable[2736], 63, 590},
  { &yyActionTable[2800], 7, 614},
  { &yyActionTable[2808], 0, 586},
  { &yyActionTable[2809], 1, 614},
  { &yyActionTable[2811], 0, 585},
  { &yyActionTable[2812], 3, 506},
  { &yyActionTable[2816], 0, 502},
  { &yyActionTable[2817], 31, 614},
  { &yyActionTable[2849], 31, 510},
  { &yyActionTable[2881], 0, 614},
  { &yyActionTable[2882], 31, 590},
  { &yyActionTable[2914], 0, 508},
  { &yyActionTable[2915], 31, 614},
  { &yyActionTable[2947], 31, 518},
  { &yyActionTable[2979], 0, 487},
  { &yyActionTable[2980], 1, 496},
  { &yyActionTable[2982], 0, 494},
  { &yyActionTable[2983], 0, 495},
  { &yyActionTable[2984], 31, 614},
  { &yyActionTable[3016], 63, 614},
  { &yyActionTable[3080], 0, 493},
  { &yyActionTable[3081], 31, 614},
  { &yyActionTable[3113], 0, 498},
  { &yyActionTable[3114], 31, 614},
  { &yyActionTable[3146], 63, 614},
  { &yyActionTable[3210], 31, 614},
  { &yyActionTable[3242], 0, 490},
  { &yyActionTable[3243], 0, 491},
  { &yyActionTable[3244], 0, 484},
  { &yyActionTable[3245], 0, 485},
  { &yyActionTable[3246], 0, 580},
  { &yyActionTable[3247], 31, 614},
  { &yyActionTable[3279], 0, 540},
  { &yyActionTable[3280], 1, 614},
  { &yyActionTable[3282], 0, 547},
  { &yyActionTable[3283], 0, 614},
  { &yyActionTable[3284], 0, 548},
  { &yyActionTable[3285], 31, 614},
  { &yyActionTable[3317], 1, 466},
  { &yyActionTable[3319], 0, 456},
  { &yyActionTable[3320], 0, 443},
  { &yyActionTable[3321], 7, 614},
  { &yyActionTable[3329], 0, 444},
  { &yyActionTable[3330], 0, 445},
  { &yyActionTable[3331], 0, 446},
  { &yyActionTable[3332], 1, 614},
  { &yyActionTable[3334], 0, 447},
  { &yyActionTable[3335], 0, 450},
  { &yyActionTable[3336], 1, 614},
  { &yyActionTable[3338], 0, 448},
  { &yyActionTable[3339], 0, 451},
  { &yyActionTable[3340], 0, 449},
  { &yyActionTable[3341], 0, 452},
  { &yyActionTable[3342], 31, 432},
  { &yyActionTable[3374], 3, 614},
  { &yyActionTable[3378], 1, 614},
  { &yyActionTable[3380], 0, 433},
  { &yyActionTable[3381], 3, 614},
  { &yyActionTable[3385], 0, 614},
  { &yyActionTable[3386], 0, 434},
  { &yyActionTable[3387], 0, 437},
  { &yyActionTable[3388], 0, 614},
  { &yyActionTable[3389], 0, 438},
  { &yyActionTable[3390], 0, 614},
  { &yyActionTable[3391], 0, 439},
  { &yyActionTable[3392], 0, 436},
  { &yyActionTable[3393], 0, 435},
  { &yyActionTable[3394], 0, 410},
  { &yyActionTable[3395], 7, 614},
  { &yyActionTable[3403], 7, 614},
  { &yyActionTable[3411], 0, 459},
  { &yyActionTable[3412], 31, 614},
  { &yyActionTable[3444], 0, 462},
  { &yyActionTable[3445], 0, 614},
  { &yyActionTable[3446], 0, 614},
  { &yyActionTable[3447], 31, 614},
  { &yyActionTable[3479], 1, 614},
  { &yyActionTable[3481], 1, 466},
  { &yyActionTable[3483], 0, 463},
  { &yyActionTable[3484], 31, 614},
  { &yyActionTable[3516], 0, 594},
  { &yyActionTable[3517], 0, 596},
  { &yyActionTable[3518], 0, 595},
  { &yyActionTable[3519], 0, 614},
  { &yyActionTable[3520], 31, 614},
  { &yyActionTable[3552], 1, 614},
  { &yyActionTable[3554], 1, 466},
  { &yyActionTable[3556], 0, 464},
  { &yyActionTable[3557], 31, 614},
  { &yyActionTable[3589], 31, 466},
  { &yyActionTable[3621], 0, 465},
  { &yyActionTable[3622], 0, 460},
  { &yyActionTable[3623], 0, 461},
  { &yyActionTable[3624], 0, 408},
  { &yyActionTable[3625], 7, 614},
  { &yyActionTable[3633], 0, 614},
  { &yyActionTable[3634], 31, 614},
  { &yyActionTable[3666], 0, 614},
  { &yyActionTable[3667], 0, 614},
  { &yyActionTable[3668], 0, 614},
  { &yyActionTable[3669], 31, 614},
  { &yyActionTable[3701], 0, 614},
  { &yyActionTable[3702], 31, 614},
  { &yyActionTable[3734], 0, 614},
  { &yyActionTable[3735], 31, 614},
  { &yyActionTable[3767], 1, 614},
  { &yyActionTable[3769], 1, 466},
  { &yyActionTable[3771], 0, 591},
  { &yyActionTable[3772], 0, 614},
  { &yyActionTable[3773], 1, 614},
  { &yyActionTable[3775], 31, 614},
  { &yyActionTable[3807], 0, 475},
  { &yyActionTable[3808], 31, 614},
  { &yyActionTable[3840], 0, 597},
  { &yyActionTable[3841], 3, 476},
  { &yyActionTable[3845], 0, 614},
  { &yyActionTable[3846], 31, 614},
  { &yyActionTable[3878], 1, 517},
  { &yyActionTable[3880], 0, 516},
  { &yyActionTable[3881], 1, 468},
  { &yyActionTable[3883], 7, 614},
  { &yyActionTable[3891], 0, 469},
  { &yyActionTable[3892], 31, 614},
  { &yyActionTable[3924], 0, 614},
  { &yyActionTable[3925], 31, 614},
  { &yyActionTable[3957], 3, 517},
  { &yyActionTable[3961], 0, 519},
  { &yyActionTable[3962], 31, 614},
  { &yyActionTable[3994], 0, 614},
  { &yyActionTable[3995], 31, 614},
  { &yyActionTable[4027], 31, 520},
  { &yyActionTable[4059], 0, 614},
  { &yyActionTable[4060], 31, 614},
  { &yyActionTable[4092], 31, 521},
  { &yyActionTable[4124], 0, 614},
  { &yyActionTable[4125], 31, 614},
  { &yyActionTable[4157], 1, 536},
  { &yyActionTable[4159], 3, 614},
  { &yyActionTable[4163], 3, 523},
  { &yyActionTable[4167], 0, 614},
  { &yyActionTable[4168], 7, 614},
  { &yyActionTable[4176], 1, 614},
  { &yyActionTable[4178], 0, 522},
  { &yyActionTable[4179], 7, 614},
  { &yyActionTable[4187], 0, 526},
  { &yyActionTable[4188], 0, 528},
  { &yyActionTable[4189], 1, 614},
  { &yyActionTable[4191], 0, 529},
  { &yyActionTable[4192], 0, 532},
  { &yyActionTable[4193], 1, 614},
  { &yyActionTable[4195], 0, 530},
  { &yyActionTable[4196], 0, 533},
  { &yyActionTable[4197], 0, 531},
  { &yyActionTable[4198], 0, 534},
  { &yyActionTable[4199], 0, 535},
  { &yyActionTable[4200], 0, 527},
  { &yyActionTable[4201], 31, 614},
  { &yyActionTable[4233], 1, 614},
  { &yyActionTable[4235], 0, 537},
  { &yyActionTable[4236], 31, 614},
  { &yyActionTable[4268], 0, 538},
  { &yyActionTable[4269], 0, 539},
  { &yyActionTable[4270], 3, 614},
  { &yyActionTable[4274], 0, 614},
  { &yyActionTable[4275], 0, 614},
  { &yyActionTable[4276], 1, 468},
  { &yyActionTable[4278], 31, 614},
  { &yyActionTable[4310], 0, 614},
  { &yyActionTable[4311], 31, 614},
  { &yyActionTable[4343], 0, 599},
  { &yyActionTable[4344], 0, 614},
  { &yyActionTable[4345], 0, 614},
  { &yyActionTable[4346], 0, 598},
  { &yyActionTable[4347], 31, 600},
  { &yyActionTable[4379], 0, 601},
  { &yyActionTable[4380], 31, 614},
  { &yyActionTable[4412], 1, 607},
  { &yyActionTable[4414], 31, 613},
  { &yyActionTable[4446], 0, 602},
  { &yyActionTable[4447], 0, 603},
  { &yyActionTable[4448], 0, 604},
  { &yyActionTable[4449], 0, 605},
  { &yyActionTable[4450], 3, 614},
  { &yyActionTable[4454], 0, 608},
  { &yyActionTable[4455], 0, 610},
  { &yyActionTable[4456], 0, 611},
  { &yyActionTable[4457], 3, 614},
  { &yyActionTable[4461], 0, 609},
  { &yyActionTable[4462], 0, 612},
  { &yyActionTable[4463], 31, 614},
  { &yyActionTable[4495], 0, 614},
  { &yyActionTable[4496], 0, 606},
  { &yyActionTable[4497], 0, 392},
  { &yyActionTable[4498], 0, 394},
  { &yyActionTable[4499], 0, 389},
};

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  int stateno;       /* The state-number */
  int major;         /* The major token value.  This is the code
                     ** number for the token at this stack level */
  YYMINORTYPE minor; /* The user-supplied minor token value.  This
                     ** is the value of the token  */
};

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int idx;                            /* Index of top element in stack */
  int errcnt;                         /* Shifts left before out of the error */
  struct yyStackEntry *top;           /* Pointer to the top stack element */
  struct yyStackEntry stack[YYSTACKDEPTH];  /* The parser's stack */
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;

/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void sqliteParserTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}

/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static char *yyTokenName[] = { 
  "$",             "ABORT",         "AGG_FUNCTION",  "ALL",         
  "AND",           "AS",            "ASC",           "BEGIN",       
  "BETWEEN",       "BITAND",        "BITNOT",        "BITOR",       
  "BY",            "CHECK",         "CLUSTER",       "COLUMN",      
  "COMMA",         "COMMENT",       "COMMIT",        "CONCAT",      
  "CONFLICT",      "CONSTRAINT",    "COPY",          "CREATE",      
  "DEFAULT",       "DELETE",        "DELIMITERS",    "DESC",        
  "DISTINCT",      "DOT",           "DROP",          "END",         
  "END_OF_FILE",   "EQ",            "EXCEPT",        "EXPLAIN",     
  "FAIL",          "FLOAT",         "FROM",          "FUNCTION",    
  "GE",            "GLOB",          "GROUP",         "GT",          
  "HAVING",        "ID",            "IGNORE",        "ILLEGAL",     
  "IN",            "INDEX",         "INSERT",        "INTEGER",     
  "INTERSECT",     "INTO",          "IS",            "ISNULL",      
  "KEY",           "LE",            "LIKE",          "LIMIT",       
  "LP",            "LSHIFT",        "LT",            "MINUS",       
  "NE",            "NOT",           "NOTNULL",       "NULL",        
  "OFFSET",        "ON",            "OR",            "ORDER",       
  "PLUS",          "PRAGMA",        "PRIMARY",       "REM",         
  "REPLACE",       "ROLLBACK",      "RP",            "RSHIFT",      
  "SELECT",        "SEMI",          "SET",           "SLASH",       
  "SPACE",         "STAR",          "STRING",        "TABLE",       
  "TEMP",          "TRANSACTION",   "UMINUS",        "UNCLOSED_STRING",
  "UNION",         "UNIQUE",        "UPDATE",        "USING",       
  "VACUUM",        "VALUES",        "WHERE",         "as",          
  "carg",          "carglist",      "ccons",         "cmd",         
  "cmdlist",       "column",        "columnid",      "columnlist",  
  "conslist",      "conslist_opt",  "create_table",  "create_table_args",
  "distinct",      "ecmd",          "error",         "explain",     
  "expr",          "expritem",      "exprlist",      "from",        
  "groupby_opt",   "having_opt",    "id",            "ids",         
  "idxitem",       "idxlist",       "input",         "inscollist",  
  "inscollist_opt",  "insert_cmd",    "item",          "itemlist",    
  "joinop",        "limit_opt",     "limit_sep",     "minus_num",   
  "number",        "onconf",        "oneselect",     "orconf",      
  "orderby_opt",   "plus_num",      "plus_opt",      "resolvetype", 
  "sclp",          "selcollist",    "select",        "seltablist",  
  "setlist",       "signed",        "sortitem",      "sortlist",    
  "sortorder",     "stl_prefix",    "tcons",         "temp",        
  "trans_opt",     "type",          "typename",      "uniqueflag",  
  "where_opt",   
};
#define YYTRACE(X) if( yyTraceFILE ) fprintf(yyTraceFILE,"%sReduce [%s].\n",yyTracePrompt,X);
#else
#define YYTRACE(X)
#endif


/*
** This function returns the symbolic name associated with a token
** value.
*/
const char *sqliteParserTokenName(int tokenType){
#ifndef NDEBUG
  if( tokenType>0 && tokenType<(sizeof(yyTokenName)/sizeof(yyTokenName[0])) ){
    return yyTokenName[tokenType];
  }else{
    return "Unknown";
  }
#else
  return "";
#endif
}

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to sqliteParser and sqliteParserFree.
*/
void *sqliteParserAlloc(void *(*mallocProc)(int)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (int)sizeof(yyParser) );
  if( pParser ){
    pParser->idx = -1;
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(YYCODETYPE yymajor, YYMINORTYPE *yypminor){
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    case 116:
#line 385 "parse.y"
{sqliteExprDelete((yypminor->yy132));}
#line 5580 "parse.c"
      break;
    case 117:
#line 520 "parse.y"
{sqliteExprDelete((yypminor->yy132));}
#line 5585 "parse.c"
      break;
    case 118:
#line 518 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 5590 "parse.c"
      break;
    case 119:
#line 250 "parse.y"
{sqliteIdListDelete((yypminor->yy152));}
#line 5595 "parse.c"
      break;
    case 120:
#line 287 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 5600 "parse.c"
      break;
    case 121:
#line 292 "parse.y"
{sqliteExprDelete((yypminor->yy132));}
#line 5605 "parse.c"
      break;
    case 125:
#line 542 "parse.y"
{sqliteIdListDelete((yypminor->yy152));}
#line 5610 "parse.c"
      break;
    case 127:
#line 364 "parse.y"
{sqliteIdListDelete((yypminor->yy152));}
#line 5615 "parse.c"
      break;
    case 128:
#line 362 "parse.y"
{sqliteIdListDelete((yypminor->yy152));}
#line 5620 "parse.c"
      break;
    case 130:
#line 342 "parse.y"
{sqliteExprDelete((yypminor->yy132));}
#line 5625 "parse.c"
      break;
    case 131:
#line 340 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 5630 "parse.c"
      break;
    case 138:
#line 197 "parse.y"
{sqliteSelectDelete((yypminor->yy233));}
#line 5635 "parse.c"
      break;
    case 140:
#line 262 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 5640 "parse.c"
      break;
    case 144:
#line 233 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 5645 "parse.c"
      break;
    case 145:
#line 231 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 5650 "parse.c"
      break;
    case 146:
#line 195 "parse.y"
{sqliteSelectDelete((yypminor->yy233));}
#line 5655 "parse.c"
      break;
    case 147:
#line 246 "parse.y"
{sqliteIdListDelete((yypminor->yy152));}
#line 5660 "parse.c"
      break;
    case 148:
#line 316 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 5665 "parse.c"
      break;
    case 150:
#line 266 "parse.y"
{sqliteExprDelete((yypminor->yy132));}
#line 5670 "parse.c"
      break;
    case 151:
#line 264 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 5675 "parse.c"
      break;
    case 153:
#line 248 "parse.y"
{sqliteIdListDelete((yypminor->yy152));}
#line 5680 "parse.c"
      break;
    case 160:
#line 310 "parse.y"
{sqliteExprDelete((yypminor->yy132));}
#line 5685 "parse.c"
      break;
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;

  if( pParser->idx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->idx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[pParser->top->major]);
  }
#endif
  yymajor = pParser->top->major;
  yy_destructor( yymajor, &pParser->top->minor);
  pParser->idx--;
  pParser->top--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from sqliteParserAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void sqliteParserFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->idx>=0 ) yy_pop_parser_stack(pParser);
  (*freeProc)((void*)pParser);
}

/*
** Find the appropriate action for a parser given the look-ahead token.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_parser_action(
  yyParser *pParser,        /* The parser */
  int iLookAhead             /* The look-ahead token */
){
  struct yyStateEntry *pState;   /* Appropriate entry in the state table */
  struct yyActionEntry *pAction; /* Action appropriate for the look-ahead */
 
  /* if( pParser->idx<0 ) return YY_NO_ACTION;  */
  pState = &yyStateTable[pParser->top->stateno];
  if( iLookAhead!=YYNOCODE ){
    pAction = &pState->hashtbl[iLookAhead & pState->mask];
    while( pAction ){
      if( pAction->lookahead==iLookAhead ) return pAction->action;
      pAction = pAction->next;
    }
  }else if( pState->mask!=0 || pState->hashtbl->lookahead!=YYNOCODE ){
    return YY_NO_ACTION;
  }
  return pState->actionDefault;
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer ot the minor token to shift in */
){
  yypParser->idx++;
  yypParser->top++;
  if( yypParser->idx>=YYSTACKDEPTH ){
     yypParser->idx--;
     yypParser->top--;
#ifndef NDEBUG
     if( yyTraceFILE ){
       fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
     }
#endif
     while( yypParser->idx>=0 ) yy_pop_parser_stack(yypParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     return;
  }
  yypParser->top->stateno = yyNewState;
  yypParser->top->major = yyMajor;
  yypParser->top->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->idx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->idx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->stack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 126, 1 },
  { 104, 1 },
  { 104, 3 },
  { 113, 2 },
  { 113, 1 },
  { 113, 0 },
  { 115, 1 },
  { 103, 3 },
  { 156, 0 },
  { 156, 1 },
  { 156, 2 },
  { 103, 2 },
  { 103, 2 },
  { 103, 2 },
  { 103, 2 },
  { 110, 4 },
  { 155, 1 },
  { 155, 0 },
  { 111, 4 },
  { 107, 3 },
  { 107, 1 },
  { 105, 3 },
  { 106, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 123, 1 },
  { 123, 1 },
  { 157, 0 },
  { 157, 1 },
  { 157, 4 },
  { 157, 6 },
  { 158, 1 },
  { 158, 2 },
  { 149, 1 },
  { 149, 2 },
  { 149, 2 },
  { 101, 2 },
  { 101, 0 },
  { 100, 3 },
  { 100, 1 },
  { 100, 2 },
  { 100, 2 },
  { 100, 2 },
  { 100, 3 },
  { 100, 3 },
  { 100, 2 },
  { 100, 3 },
  { 100, 3 },
  { 100, 2 },
  { 102, 3 },
  { 102, 4 },
  { 102, 2 },
  { 102, 5 },
  { 109, 0 },
  { 109, 2 },
  { 108, 3 },
  { 108, 2 },
  { 108, 1 },
  { 154, 2 },
  { 154, 6 },
  { 154, 5 },
  { 154, 3 },
  { 137, 0 },
  { 137, 3 },
  { 139, 0 },
  { 139, 2 },
  { 143, 1 },
  { 143, 1 },
  { 143, 1 },
  { 143, 1 },
  { 143, 1 },
  { 103, 3 },
  { 103, 1 },
  { 146, 1 },
  { 146, 3 },
  { 132, 1 },
  { 132, 2 },
  { 132, 1 },
  { 132, 1 },
  { 138, 9 },
  { 112, 1 },
  { 112, 1 },
  { 112, 0 },
  { 144, 2 },
  { 144, 0 },
  { 145, 2 },
  { 145, 4 },
  { 145, 2 },
  { 99, 0 },
  { 99, 1 },
  { 119, 2 },
  { 153, 2 },
  { 153, 0 },
  { 147, 2 },
  { 147, 4 },
  { 140, 0 },
  { 140, 3 },
  { 151, 4 },
  { 151, 2 },
  { 150, 1 },
  { 152, 1 },
  { 152, 1 },
  { 152, 0 },
  { 120, 0 },
  { 120, 3 },
  { 121, 0 },
  { 121, 2 },
  { 133, 0 },
  { 133, 2 },
  { 133, 4 },
  { 134, 1 },
  { 134, 1 },
  { 103, 4 },
  { 160, 0 },
  { 160, 2 },
  { 103, 6 },
  { 148, 5 },
  { 148, 3 },
  { 103, 8 },
  { 103, 5 },
  { 129, 2 },
  { 129, 1 },
  { 131, 3 },
  { 131, 1 },
  { 130, 1 },
  { 130, 2 },
  { 130, 2 },
  { 130, 1 },
  { 130, 2 },
  { 130, 2 },
  { 130, 1 },
  { 130, 1 },
  { 128, 0 },
  { 128, 3 },
  { 127, 3 },
  { 127, 1 },
  { 116, 3 },
  { 116, 1 },
  { 116, 1 },
  { 116, 3 },
  { 116, 1 },
  { 116, 1 },
  { 116, 1 },
  { 116, 4 },
  { 116, 4 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 4 },
  { 116, 3 },
  { 116, 4 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 3 },
  { 116, 2 },
  { 116, 3 },
  { 116, 2 },
  { 116, 3 },
  { 116, 4 },
  { 116, 2 },
  { 116, 2 },
  { 116, 2 },
  { 116, 2 },
  { 116, 3 },
  { 116, 5 },
  { 116, 6 },
  { 116, 5 },
  { 116, 5 },
  { 116, 6 },
  { 116, 6 },
  { 118, 3 },
  { 118, 1 },
  { 117, 1 },
  { 117, 0 },
  { 103, 10 },
  { 159, 1 },
  { 159, 0 },
  { 125, 3 },
  { 125, 1 },
  { 124, 1 },
  { 103, 3 },
  { 103, 8 },
  { 103, 5 },
  { 103, 1 },
  { 103, 2 },
  { 103, 4 },
  { 103, 4 },
  { 103, 4 },
  { 103, 4 },
  { 103, 5 },
  { 103, 2 },
  { 141, 2 },
  { 135, 2 },
  { 136, 1 },
  { 136, 1 },
  { 142, 1 },
  { 142, 0 },
};

static void yy_accept(yyParser *  sqliteParserANSIARGDECL);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
  sqliteParserANSIARGDECL
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  struct yyStackEntry *yymsp;     /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  yymsp = yypParser->top;
  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **     YYTRACE("<text of the rule>");
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0:
        YYTRACE("input ::= cmdlist")
        /* No destructor defined for cmdlist */
        break;
      case 1:
        YYTRACE("cmdlist ::= ecmd")
        /* No destructor defined for ecmd */
        break;
      case 2:
        YYTRACE("cmdlist ::= cmdlist SEMI ecmd")
        /* No destructor defined for cmdlist */
        /* No destructor defined for SEMI */
        /* No destructor defined for ecmd */
        break;
      case 3:
        YYTRACE("ecmd ::= explain cmd")
#line 52 "parse.y"
{sqliteExec(pParse);}
#line 6086 "parse.c"
        /* No destructor defined for explain */
        /* No destructor defined for cmd */
        break;
      case 4:
        YYTRACE("ecmd ::= cmd")
#line 53 "parse.y"
{sqliteExec(pParse);}
#line 6094 "parse.c"
        /* No destructor defined for cmd */
        break;
      case 5:
        YYTRACE("ecmd ::=")
        break;
      case 6:
        YYTRACE("explain ::= EXPLAIN")
#line 55 "parse.y"
{pParse->explain = 1;}
#line 6104 "parse.c"
        /* No destructor defined for EXPLAIN */
        break;
      case 7:
        YYTRACE("cmd ::= BEGIN trans_opt onconf")
#line 60 "parse.y"
{sqliteBeginTransaction(pParse,yymsp[0].minor.yy144);}
#line 6111 "parse.c"
        /* No destructor defined for BEGIN */
        /* No destructor defined for trans_opt */
        break;
      case 8:
        YYTRACE("trans_opt ::=")
        break;
      case 9:
        YYTRACE("trans_opt ::= TRANSACTION")
        /* No destructor defined for TRANSACTION */
        break;
      case 10:
        YYTRACE("trans_opt ::= TRANSACTION ids")
        /* No destructor defined for TRANSACTION */
        /* No destructor defined for ids */
        break;
      case 11:
        YYTRACE("cmd ::= COMMIT trans_opt")
#line 64 "parse.y"
{sqliteCommitTransaction(pParse);}
#line 6131 "parse.c"
        /* No destructor defined for COMMIT */
        /* No destructor defined for trans_opt */
        break;
      case 12:
        YYTRACE("cmd ::= END trans_opt")
#line 65 "parse.y"
{sqliteCommitTransaction(pParse);}
#line 6139 "parse.c"
        /* No destructor defined for END */
        /* No destructor defined for trans_opt */
        break;
      case 13:
        YYTRACE("cmd ::= ROLLBACK trans_opt")
#line 66 "parse.y"
{sqliteRollbackTransaction(pParse);}
#line 6147 "parse.c"
        /* No destructor defined for ROLLBACK */
        /* No destructor defined for trans_opt */
        break;
      case 14:
        YYTRACE("cmd ::= create_table create_table_args")
        /* No destructor defined for create_table */
        /* No destructor defined for create_table_args */
        break;
      case 15:
        YYTRACE("create_table ::= CREATE temp TABLE ids")
#line 72 "parse.y"
{sqliteStartTable(pParse,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy224,yymsp[-2].minor.yy144);}
#line 6160 "parse.c"
        /* No destructor defined for TABLE */
        break;
      case 16:
        YYTRACE("temp ::= TEMP")
#line 74 "parse.y"
{yygotominor.yy144 = 1;}
#line 6167 "parse.c"
        /* No destructor defined for TEMP */
        break;
      case 17:
        YYTRACE("temp ::=")
#line 75 "parse.y"
{yygotominor.yy144 = 0;}
#line 6174 "parse.c"
        break;
      case 18:
        YYTRACE("create_table_args ::= LP columnlist conslist_opt RP")
#line 77 "parse.y"
{sqliteEndTable(pParse,&yymsp[0].minor.yy0);}
#line 6180 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for columnlist */
        /* No destructor defined for conslist_opt */
        break;
      case 19:
        YYTRACE("columnlist ::= columnlist COMMA column")
        /* No destructor defined for columnlist */
        /* No destructor defined for COMMA */
        /* No destructor defined for column */
        break;
      case 20:
        YYTRACE("columnlist ::= column")
        /* No destructor defined for column */
        break;
      case 21:
        YYTRACE("column ::= columnid type carglist")
        /* No destructor defined for columnid */
        /* No destructor defined for type */
        /* No destructor defined for carglist */
        break;
      case 22:
        YYTRACE("columnid ::= ids")
#line 86 "parse.y"
{sqliteAddColumn(pParse,&yymsp[0].minor.yy224);}
#line 6205 "parse.c"
        break;
      case 23:
        YYTRACE("id ::= DESC")
#line 94 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6211 "parse.c"
        break;
      case 24:
        YYTRACE("id ::= ASC")
#line 95 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6217 "parse.c"
        break;
      case 25:
        YYTRACE("id ::= DELIMITERS")
#line 96 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6223 "parse.c"
        break;
      case 26:
        YYTRACE("id ::= EXPLAIN")
#line 97 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6229 "parse.c"
        break;
      case 27:
        YYTRACE("id ::= VACUUM")
#line 98 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6235 "parse.c"
        break;
      case 28:
        YYTRACE("id ::= BEGIN")
#line 99 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6241 "parse.c"
        break;
      case 29:
        YYTRACE("id ::= END")
#line 100 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6247 "parse.c"
        break;
      case 30:
        YYTRACE("id ::= PRAGMA")
#line 101 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6253 "parse.c"
        break;
      case 31:
        YYTRACE("id ::= CLUSTER")
#line 102 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6259 "parse.c"
        break;
      case 32:
        YYTRACE("id ::= ID")
#line 103 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6265 "parse.c"
        break;
      case 33:
        YYTRACE("id ::= TEMP")
#line 104 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6271 "parse.c"
        break;
      case 34:
        YYTRACE("id ::= OFFSET")
#line 105 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6277 "parse.c"
        break;
      case 35:
        YYTRACE("id ::= KEY")
#line 106 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6283 "parse.c"
        break;
      case 36:
        YYTRACE("id ::= ABORT")
#line 107 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6289 "parse.c"
        break;
      case 37:
        YYTRACE("id ::= IGNORE")
#line 108 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6295 "parse.c"
        break;
      case 38:
        YYTRACE("id ::= REPLACE")
#line 109 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6301 "parse.c"
        break;
      case 39:
        YYTRACE("id ::= FAIL")
#line 110 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6307 "parse.c"
        break;
      case 40:
        YYTRACE("id ::= CONFLICT")
#line 111 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6313 "parse.c"
        break;
      case 41:
        YYTRACE("ids ::= id")
#line 116 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy224;}
#line 6319 "parse.c"
        break;
      case 42:
        YYTRACE("ids ::= STRING")
#line 117 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6325 "parse.c"
        break;
      case 43:
        YYTRACE("type ::=")
        break;
      case 44:
        YYTRACE("type ::= typename")
#line 120 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[0].minor.yy224,&yymsp[0].minor.yy224);}
#line 6334 "parse.c"
        break;
      case 45:
        YYTRACE("type ::= typename LP signed RP")
#line 121 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-3].minor.yy224,&yymsp[0].minor.yy0);}
#line 6340 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        break;
      case 46:
        YYTRACE("type ::= typename LP signed COMMA signed RP")
#line 123 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-5].minor.yy224,&yymsp[0].minor.yy0);}
#line 6348 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        /* No destructor defined for COMMA */
        /* No destructor defined for signed */
        break;
      case 47:
        YYTRACE("typename ::= ids")
#line 125 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy224;}
#line 6358 "parse.c"
        break;
      case 48:
        YYTRACE("typename ::= typename ids")
#line 126 "parse.y"
{yygotominor.yy224 = yymsp[-1].minor.yy224;}
#line 6364 "parse.c"
        /* No destructor defined for ids */
        break;
      case 49:
        YYTRACE("signed ::= INTEGER")
        /* No destructor defined for INTEGER */
        break;
      case 50:
        YYTRACE("signed ::= PLUS INTEGER")
        /* No destructor defined for PLUS */
        /* No destructor defined for INTEGER */
        break;
      case 51:
        YYTRACE("signed ::= MINUS INTEGER")
        /* No destructor defined for MINUS */
        /* No destructor defined for INTEGER */
        break;
      case 52:
        YYTRACE("carglist ::= carglist carg")
        /* No destructor defined for carglist */
        /* No destructor defined for carg */
        break;
      case 53:
        YYTRACE("carglist ::=")
        break;
      case 54:
        YYTRACE("carg ::= CONSTRAINT ids ccons")
        /* No destructor defined for CONSTRAINT */
        /* No destructor defined for ids */
        /* No destructor defined for ccons */
        break;
      case 55:
        YYTRACE("carg ::= ccons")
        /* No destructor defined for ccons */
        break;
      case 56:
        YYTRACE("carg ::= DEFAULT STRING")
#line 134 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 6403 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 57:
        YYTRACE("carg ::= DEFAULT ID")
#line 135 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 6410 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 58:
        YYTRACE("carg ::= DEFAULT INTEGER")
#line 136 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 6417 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 59:
        YYTRACE("carg ::= DEFAULT PLUS INTEGER")
#line 137 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 6424 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 60:
        YYTRACE("carg ::= DEFAULT MINUS INTEGER")
#line 138 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 6432 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 61:
        YYTRACE("carg ::= DEFAULT FLOAT")
#line 139 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 6440 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 62:
        YYTRACE("carg ::= DEFAULT PLUS FLOAT")
#line 140 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 6447 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 63:
        YYTRACE("carg ::= DEFAULT MINUS FLOAT")
#line 141 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 6455 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 64:
        YYTRACE("carg ::= DEFAULT NULL")
        /* No destructor defined for DEFAULT */
        /* No destructor defined for NULL */
        break;
      case 65:
        YYTRACE("ccons ::= NOT NULL onconf")
#line 147 "parse.y"
{sqliteAddNotNull(pParse, yymsp[0].minor.yy144);}
#line 6468 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for NULL */
        break;
      case 66:
        YYTRACE("ccons ::= PRIMARY KEY sortorder onconf")
#line 148 "parse.y"
{sqliteAddPrimaryKey(pParse,0,yymsp[0].minor.yy144);}
#line 6476 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for sortorder */
        break;
      case 67:
        YYTRACE("ccons ::= UNIQUE onconf")
#line 149 "parse.y"
{sqliteCreateIndex(pParse,0,0,0,yymsp[0].minor.yy144,0,0);}
#line 6485 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 68:
        YYTRACE("ccons ::= CHECK LP expr RP onconf")
        /* No destructor defined for CHECK */
        /* No destructor defined for LP */
  yy_destructor(116,&yymsp[-2].minor);
        /* No destructor defined for RP */
        /* No destructor defined for onconf */
        break;
      case 69:
        YYTRACE("conslist_opt ::=")
        break;
      case 70:
        YYTRACE("conslist_opt ::= COMMA conslist")
        /* No destructor defined for COMMA */
        /* No destructor defined for conslist */
        break;
      case 71:
        YYTRACE("conslist ::= conslist COMMA tcons")
        /* No destructor defined for conslist */
        /* No destructor defined for COMMA */
        /* No destructor defined for tcons */
        break;
      case 72:
        YYTRACE("conslist ::= conslist tcons")
        /* No destructor defined for conslist */
        /* No destructor defined for tcons */
        break;
      case 73:
        YYTRACE("conslist ::= tcons")
        /* No destructor defined for tcons */
        break;
      case 74:
        YYTRACE("tcons ::= CONSTRAINT ids")
        /* No destructor defined for CONSTRAINT */
        /* No destructor defined for ids */
        break;
      case 75:
        YYTRACE("tcons ::= PRIMARY KEY LP idxlist RP onconf")
#line 162 "parse.y"
{sqliteAddPrimaryKey(pParse,yymsp[-2].minor.yy152,yymsp[0].minor.yy144);}
#line 6528 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 76:
        YYTRACE("tcons ::= UNIQUE LP idxlist RP onconf")
#line 164 "parse.y"
{sqliteCreateIndex(pParse,0,0,yymsp[-2].minor.yy152,yymsp[0].minor.yy144,0,0);}
#line 6538 "parse.c"
        /* No destructor defined for UNIQUE */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 77:
        YYTRACE("tcons ::= CHECK expr onconf")
        /* No destructor defined for CHECK */
  yy_destructor(116,&yymsp[-1].minor);
        /* No destructor defined for onconf */
        break;
      case 78:
        YYTRACE("onconf ::=")
#line 173 "parse.y"
{ yygotominor.yy144 = OE_Default; }
#line 6553 "parse.c"
        break;
      case 79:
        YYTRACE("onconf ::= ON CONFLICT resolvetype")
#line 174 "parse.y"
{ yygotominor.yy144 = yymsp[0].minor.yy144; }
#line 6559 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for CONFLICT */
        break;
      case 80:
        YYTRACE("orconf ::=")
#line 175 "parse.y"
{ yygotominor.yy144 = OE_Default; }
#line 6567 "parse.c"
        break;
      case 81:
        YYTRACE("orconf ::= OR resolvetype")
#line 176 "parse.y"
{ yygotominor.yy144 = yymsp[0].minor.yy144; }
#line 6573 "parse.c"
        /* No destructor defined for OR */
        break;
      case 82:
        YYTRACE("resolvetype ::= ROLLBACK")
#line 177 "parse.y"
{ yygotominor.yy144 = OE_Rollback; }
#line 6580 "parse.c"
        /* No destructor defined for ROLLBACK */
        break;
      case 83:
        YYTRACE("resolvetype ::= ABORT")
#line 178 "parse.y"
{ yygotominor.yy144 = OE_Abort; }
#line 6587 "parse.c"
        /* No destructor defined for ABORT */
        break;
      case 84:
        YYTRACE("resolvetype ::= FAIL")
#line 179 "parse.y"
{ yygotominor.yy144 = OE_Fail; }
#line 6594 "parse.c"
        /* No destructor defined for FAIL */
        break;
      case 85:
        YYTRACE("resolvetype ::= IGNORE")
#line 180 "parse.y"
{ yygotominor.yy144 = OE_Ignore; }
#line 6601 "parse.c"
        /* No destructor defined for IGNORE */
        break;
      case 86:
        YYTRACE("resolvetype ::= REPLACE")
#line 181 "parse.y"
{ yygotominor.yy144 = OE_Replace; }
#line 6608 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 87:
        YYTRACE("cmd ::= DROP TABLE ids")
#line 185 "parse.y"
{sqliteDropTable(pParse,&yymsp[0].minor.yy224);}
#line 6615 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for TABLE */
        break;
      case 88:
        YYTRACE("cmd ::= select")
#line 189 "parse.y"
{
  sqliteSelect(pParse, yymsp[0].minor.yy233, SRT_Callback, 0);
  sqliteSelectDelete(yymsp[0].minor.yy233);
}
#line 6626 "parse.c"
        break;
      case 89:
        YYTRACE("select ::= oneselect")
#line 199 "parse.y"
{yygotominor.yy233 = yymsp[0].minor.yy233;}
#line 6632 "parse.c"
        break;
      case 90:
        YYTRACE("select ::= select joinop oneselect")
#line 200 "parse.y"
{
  if( yymsp[0].minor.yy233 ){
    yymsp[0].minor.yy233->op = yymsp[-1].minor.yy144;
    yymsp[0].minor.yy233->pPrior = yymsp[-2].minor.yy233;
  }
  yygotominor.yy233 = yymsp[0].minor.yy233;
}
#line 6644 "parse.c"
        break;
      case 91:
        YYTRACE("joinop ::= UNION")
#line 208 "parse.y"
{yygotominor.yy144 = TK_UNION;}
#line 6650 "parse.c"
        /* No destructor defined for UNION */
        break;
      case 92:
        YYTRACE("joinop ::= UNION ALL")
#line 209 "parse.y"
{yygotominor.yy144 = TK_ALL;}
#line 6657 "parse.c"
        /* No destructor defined for UNION */
        /* No destructor defined for ALL */
        break;
      case 93:
        YYTRACE("joinop ::= INTERSECT")
#line 210 "parse.y"
{yygotominor.yy144 = TK_INTERSECT;}
#line 6665 "parse.c"
        /* No destructor defined for INTERSECT */
        break;
      case 94:
        YYTRACE("joinop ::= EXCEPT")
#line 211 "parse.y"
{yygotominor.yy144 = TK_EXCEPT;}
#line 6672 "parse.c"
        /* No destructor defined for EXCEPT */
        break;
      case 95:
        YYTRACE("oneselect ::= SELECT distinct selcollist from where_opt groupby_opt having_opt orderby_opt limit_opt")
#line 213 "parse.y"
{
  yygotominor.yy233 = sqliteSelectNew(yymsp[-6].minor.yy270,yymsp[-5].minor.yy152,yymsp[-4].minor.yy132,yymsp[-3].minor.yy270,yymsp[-2].minor.yy132,yymsp[-1].minor.yy270,yymsp[-7].minor.yy144,yymsp[0].minor.yy303.a,yymsp[0].minor.yy303.b);
}
#line 6681 "parse.c"
        /* No destructor defined for SELECT */
        break;
      case 96:
        YYTRACE("distinct ::= DISTINCT")
#line 221 "parse.y"
{yygotominor.yy144 = 1;}
#line 6688 "parse.c"
        /* No destructor defined for DISTINCT */
        break;
      case 97:
        YYTRACE("distinct ::= ALL")
#line 222 "parse.y"
{yygotominor.yy144 = 0;}
#line 6695 "parse.c"
        /* No destructor defined for ALL */
        break;
      case 98:
        YYTRACE("distinct ::=")
#line 223 "parse.y"
{yygotominor.yy144 = 0;}
#line 6702 "parse.c"
        break;
      case 99:
        YYTRACE("sclp ::= selcollist COMMA")
#line 234 "parse.y"
{yygotominor.yy270 = yymsp[-1].minor.yy270;}
#line 6708 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 100:
        YYTRACE("sclp ::=")
#line 235 "parse.y"
{yygotominor.yy270 = 0;}
#line 6715 "parse.c"
        break;
      case 101:
        YYTRACE("selcollist ::= sclp expr")
#line 236 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(yymsp[-1].minor.yy270,yymsp[0].minor.yy132,0);}
#line 6721 "parse.c"
        break;
      case 102:
        YYTRACE("selcollist ::= sclp expr as ids")
#line 237 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(yymsp[-3].minor.yy270,yymsp[-2].minor.yy132,&yymsp[0].minor.yy224);}
#line 6727 "parse.c"
        /* No destructor defined for as */
        break;
      case 103:
        YYTRACE("selcollist ::= sclp STAR")
#line 238 "parse.y"
{
  yygotominor.yy270 = sqliteExprListAppend(yymsp[-1].minor.yy270, sqliteExpr(TK_ALL, 0, 0, 0), 0);
}
#line 6736 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 104:
        YYTRACE("as ::=")
        break;
      case 105:
        YYTRACE("as ::= AS")
        /* No destructor defined for AS */
        break;
      case 106:
        YYTRACE("from ::= FROM seltablist")
#line 252 "parse.y"
{yygotominor.yy152 = yymsp[0].minor.yy152;}
#line 6750 "parse.c"
        /* No destructor defined for FROM */
        break;
      case 107:
        YYTRACE("stl_prefix ::= seltablist COMMA")
#line 253 "parse.y"
{yygotominor.yy152 = yymsp[-1].minor.yy152;}
#line 6757 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 108:
        YYTRACE("stl_prefix ::=")
#line 254 "parse.y"
{yygotominor.yy152 = 0;}
#line 6764 "parse.c"
        break;
      case 109:
        YYTRACE("seltablist ::= stl_prefix ids")
#line 255 "parse.y"
{yygotominor.yy152 = sqliteIdListAppend(yymsp[-1].minor.yy152,&yymsp[0].minor.yy224);}
#line 6770 "parse.c"
        break;
      case 110:
        YYTRACE("seltablist ::= stl_prefix ids as ids")
#line 256 "parse.y"
{
  yygotominor.yy152 = sqliteIdListAppend(yymsp[-3].minor.yy152,&yymsp[-2].minor.yy224);
  sqliteIdListAddAlias(yygotominor.yy152,&yymsp[0].minor.yy224);
}
#line 6779 "parse.c"
        /* No destructor defined for as */
        break;
      case 111:
        YYTRACE("orderby_opt ::=")
#line 268 "parse.y"
{yygotominor.yy270 = 0;}
#line 6786 "parse.c"
        break;
      case 112:
        YYTRACE("orderby_opt ::= ORDER BY sortlist")
#line 269 "parse.y"
{yygotominor.yy270 = yymsp[0].minor.yy270;}
#line 6792 "parse.c"
        /* No destructor defined for ORDER */
        /* No destructor defined for BY */
        break;
      case 113:
        YYTRACE("sortlist ::= sortlist COMMA sortitem sortorder")
#line 270 "parse.y"
{
  yygotominor.yy270 = sqliteExprListAppend(yymsp[-3].minor.yy270,yymsp[-1].minor.yy132,0);
  if( yygotominor.yy270 ) yygotominor.yy270->a[yygotominor.yy270->nExpr-1].sortOrder = yymsp[0].minor.yy144;  /* 0=ascending, 1=decending */
}
#line 6803 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 114:
        YYTRACE("sortlist ::= sortitem sortorder")
#line 274 "parse.y"
{
  yygotominor.yy270 = sqliteExprListAppend(0,yymsp[-1].minor.yy132,0);
  if( yygotominor.yy270 ) yygotominor.yy270->a[0].sortOrder = yymsp[0].minor.yy144;
}
#line 6813 "parse.c"
        break;
      case 115:
        YYTRACE("sortitem ::= expr")
#line 278 "parse.y"
{yygotominor.yy132 = yymsp[0].minor.yy132;}
#line 6819 "parse.c"
        break;
      case 116:
        YYTRACE("sortorder ::= ASC")
#line 282 "parse.y"
{yygotominor.yy144 = 0;}
#line 6825 "parse.c"
        /* No destructor defined for ASC */
        break;
      case 117:
        YYTRACE("sortorder ::= DESC")
#line 283 "parse.y"
{yygotominor.yy144 = 1;}
#line 6832 "parse.c"
        /* No destructor defined for DESC */
        break;
      case 118:
        YYTRACE("sortorder ::=")
#line 284 "parse.y"
{yygotominor.yy144 = 0;}
#line 6839 "parse.c"
        break;
      case 119:
        YYTRACE("groupby_opt ::=")
#line 288 "parse.y"
{yygotominor.yy270 = 0;}
#line 6845 "parse.c"
        break;
      case 120:
        YYTRACE("groupby_opt ::= GROUP BY exprlist")
#line 289 "parse.y"
{yygotominor.yy270 = yymsp[0].minor.yy270;}
#line 6851 "parse.c"
        /* No destructor defined for GROUP */
        /* No destructor defined for BY */
        break;
      case 121:
        YYTRACE("having_opt ::=")
#line 293 "parse.y"
{yygotominor.yy132 = 0;}
#line 6859 "parse.c"
        break;
      case 122:
        YYTRACE("having_opt ::= HAVING expr")
#line 294 "parse.y"
{yygotominor.yy132 = yymsp[0].minor.yy132;}
#line 6865 "parse.c"
        /* No destructor defined for HAVING */
        break;
      case 123:
        YYTRACE("limit_opt ::=")
#line 297 "parse.y"
{yygotominor.yy303.a = -1; yygotominor.yy303.b = 0;}
#line 6872 "parse.c"
        break;
      case 124:
        YYTRACE("limit_opt ::= LIMIT INTEGER")
#line 298 "parse.y"
{yygotominor.yy303.a = atoi(yymsp[0].minor.yy0.z); yygotominor.yy303.b = 0;}
#line 6878 "parse.c"
        /* No destructor defined for LIMIT */
        break;
      case 125:
        YYTRACE("limit_opt ::= LIMIT INTEGER limit_sep INTEGER")
#line 300 "parse.y"
{yygotominor.yy303.a = atoi(yymsp[-2].minor.yy0.z); yygotominor.yy303.b = atoi(yymsp[0].minor.yy0.z);}
#line 6885 "parse.c"
        /* No destructor defined for LIMIT */
        /* No destructor defined for limit_sep */
        break;
      case 126:
        YYTRACE("limit_sep ::= OFFSET")
        /* No destructor defined for OFFSET */
        break;
      case 127:
        YYTRACE("limit_sep ::= COMMA")
        /* No destructor defined for COMMA */
        break;
      case 128:
        YYTRACE("cmd ::= DELETE FROM ids where_opt")
#line 307 "parse.y"
{sqliteDeleteFrom(pParse, &yymsp[-1].minor.yy224, yymsp[0].minor.yy132);}
#line 6901 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 129:
        YYTRACE("where_opt ::=")
#line 312 "parse.y"
{yygotominor.yy132 = 0;}
#line 6909 "parse.c"
        break;
      case 130:
        YYTRACE("where_opt ::= WHERE expr")
#line 313 "parse.y"
{yygotominor.yy132 = yymsp[0].minor.yy132;}
#line 6915 "parse.c"
        /* No destructor defined for WHERE */
        break;
      case 131:
        YYTRACE("cmd ::= UPDATE orconf ids SET setlist where_opt")
#line 321 "parse.y"
{sqliteUpdate(pParse,&yymsp[-3].minor.yy224,yymsp[-1].minor.yy270,yymsp[0].minor.yy132,yymsp[-4].minor.yy144);}
#line 6922 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 132:
        YYTRACE("setlist ::= setlist COMMA ids EQ expr")
#line 324 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(yymsp[-4].minor.yy270,yymsp[0].minor.yy132,&yymsp[-2].minor.yy224);}
#line 6930 "parse.c"
        /* No destructor defined for COMMA */
        /* No destructor defined for EQ */
        break;
      case 133:
        YYTRACE("setlist ::= ids EQ expr")
#line 325 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(0,yymsp[0].minor.yy132,&yymsp[-2].minor.yy224);}
#line 6938 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 134:
        YYTRACE("cmd ::= insert_cmd INTO ids inscollist_opt VALUES LP itemlist RP")
#line 330 "parse.y"
{sqliteInsert(pParse, &yymsp[-5].minor.yy224, yymsp[-1].minor.yy270, 0, yymsp[-4].minor.yy152, yymsp[-7].minor.yy144);}
#line 6945 "parse.c"
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 135:
        YYTRACE("cmd ::= insert_cmd INTO ids inscollist_opt select")
#line 332 "parse.y"
{sqliteInsert(pParse, &yymsp[-2].minor.yy224, 0, yymsp[0].minor.yy233, yymsp[-1].minor.yy152, yymsp[-4].minor.yy144);}
#line 6955 "parse.c"
        /* No destructor defined for INTO */
        break;
      case 136:
        YYTRACE("insert_cmd ::= INSERT orconf")
#line 335 "parse.y"
{yygotominor.yy144 = yymsp[0].minor.yy144;}
#line 6962 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 137:
        YYTRACE("insert_cmd ::= REPLACE")
#line 336 "parse.y"
{yygotominor.yy144 = OE_Replace;}
#line 6969 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 138:
        YYTRACE("itemlist ::= itemlist COMMA item")
#line 344 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(yymsp[-2].minor.yy270,yymsp[0].minor.yy132,0);}
#line 6976 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 139:
        YYTRACE("itemlist ::= item")
#line 345 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(0,yymsp[0].minor.yy132,0);}
#line 6983 "parse.c"
        break;
      case 140:
        YYTRACE("item ::= INTEGER")
#line 346 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_INTEGER, 0, 0, &yymsp[0].minor.yy0);}
#line 6989 "parse.c"
        break;
      case 141:
        YYTRACE("item ::= PLUS INTEGER")
#line 347 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_INTEGER, 0, 0, &yymsp[0].minor.yy0);}
#line 6995 "parse.c"
        /* No destructor defined for PLUS */
        break;
      case 142:
        YYTRACE("item ::= MINUS INTEGER")
#line 348 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_UMINUS, 0, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pLeft = sqliteExpr(TK_INTEGER, 0, 0, &yymsp[0].minor.yy0);
}
#line 7005 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 143:
        YYTRACE("item ::= FLOAT")
#line 352 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_FLOAT, 0, 0, &yymsp[0].minor.yy0);}
#line 7012 "parse.c"
        break;
      case 144:
        YYTRACE("item ::= PLUS FLOAT")
#line 353 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_FLOAT, 0, 0, &yymsp[0].minor.yy0);}
#line 7018 "parse.c"
        /* No destructor defined for PLUS */
        break;
      case 145:
        YYTRACE("item ::= MINUS FLOAT")
#line 354 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_UMINUS, 0, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pLeft = sqliteExpr(TK_FLOAT, 0, 0, &yymsp[0].minor.yy0);
}
#line 7028 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 146:
        YYTRACE("item ::= STRING")
#line 358 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_STRING, 0, 0, &yymsp[0].minor.yy0);}
#line 7035 "parse.c"
        break;
      case 147:
        YYTRACE("item ::= NULL")
#line 359 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_NULL, 0, 0, 0);}
#line 7041 "parse.c"
        /* No destructor defined for NULL */
        break;
      case 148:
        YYTRACE("inscollist_opt ::=")
#line 366 "parse.y"
{yygotominor.yy152 = 0;}
#line 7048 "parse.c"
        break;
      case 149:
        YYTRACE("inscollist_opt ::= LP inscollist RP")
#line 367 "parse.y"
{yygotominor.yy152 = yymsp[-1].minor.yy152;}
#line 7054 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 150:
        YYTRACE("inscollist ::= inscollist COMMA ids")
#line 368 "parse.y"
{yygotominor.yy152 = sqliteIdListAppend(yymsp[-2].minor.yy152,&yymsp[0].minor.yy224);}
#line 7062 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 151:
        YYTRACE("inscollist ::= ids")
#line 369 "parse.y"
{yygotominor.yy152 = sqliteIdListAppend(0,&yymsp[0].minor.yy224);}
#line 7069 "parse.c"
        break;
      case 152:
        YYTRACE("expr ::= LP expr RP")
#line 387 "parse.y"
{yygotominor.yy132 = yymsp[-1].minor.yy132; sqliteExprSpan(yygotominor.yy132,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);}
#line 7075 "parse.c"
        break;
      case 153:
        YYTRACE("expr ::= NULL")
#line 388 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_NULL, 0, 0, &yymsp[0].minor.yy0);}
#line 7081 "parse.c"
        break;
      case 154:
        YYTRACE("expr ::= id")
#line 389 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy224);}
#line 7087 "parse.c"
        break;
      case 155:
        YYTRACE("expr ::= ids DOT ids")
#line 390 "parse.y"
{
  Expr *temp1 = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy224);
  Expr *temp2 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy224);
  yygotominor.yy132 = sqliteExpr(TK_DOT, temp1, temp2, 0);
}
#line 7097 "parse.c"
        /* No destructor defined for DOT */
        break;
      case 156:
        YYTRACE("expr ::= INTEGER")
#line 395 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_INTEGER, 0, 0, &yymsp[0].minor.yy0);}
#line 7104 "parse.c"
        break;
      case 157:
        YYTRACE("expr ::= FLOAT")
#line 396 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_FLOAT, 0, 0, &yymsp[0].minor.yy0);}
#line 7110 "parse.c"
        break;
      case 158:
        YYTRACE("expr ::= STRING")
#line 397 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_STRING, 0, 0, &yymsp[0].minor.yy0);}
#line 7116 "parse.c"
        break;
      case 159:
        YYTRACE("expr ::= ID LP exprlist RP")
#line 398 "parse.y"
{
  yygotominor.yy132 = sqliteExprFunction(yymsp[-1].minor.yy270, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 7125 "parse.c"
        /* No destructor defined for LP */
        break;
      case 160:
        YYTRACE("expr ::= ID LP STAR RP")
#line 402 "parse.y"
{
  yygotominor.yy132 = sqliteExprFunction(0, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 7135 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for STAR */
        break;
      case 161:
        YYTRACE("expr ::= expr AND expr")
#line 406 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_AND, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7143 "parse.c"
        /* No destructor defined for AND */
        break;
      case 162:
        YYTRACE("expr ::= expr OR expr")
#line 407 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_OR, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7150 "parse.c"
        /* No destructor defined for OR */
        break;
      case 163:
        YYTRACE("expr ::= expr LT expr")
#line 408 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_LT, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7157 "parse.c"
        /* No destructor defined for LT */
        break;
      case 164:
        YYTRACE("expr ::= expr GT expr")
#line 409 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_GT, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7164 "parse.c"
        /* No destructor defined for GT */
        break;
      case 165:
        YYTRACE("expr ::= expr LE expr")
#line 410 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_LE, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7171 "parse.c"
        /* No destructor defined for LE */
        break;
      case 166:
        YYTRACE("expr ::= expr GE expr")
#line 411 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_GE, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7178 "parse.c"
        /* No destructor defined for GE */
        break;
      case 167:
        YYTRACE("expr ::= expr NE expr")
#line 412 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_NE, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7185 "parse.c"
        /* No destructor defined for NE */
        break;
      case 168:
        YYTRACE("expr ::= expr EQ expr")
#line 413 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_EQ, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7192 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 169:
        YYTRACE("expr ::= expr BITAND expr")
#line 414 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_BITAND, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7199 "parse.c"
        /* No destructor defined for BITAND */
        break;
      case 170:
        YYTRACE("expr ::= expr BITOR expr")
#line 415 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_BITOR, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7206 "parse.c"
        /* No destructor defined for BITOR */
        break;
      case 171:
        YYTRACE("expr ::= expr LSHIFT expr")
#line 416 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_LSHIFT, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7213 "parse.c"
        /* No destructor defined for LSHIFT */
        break;
      case 172:
        YYTRACE("expr ::= expr RSHIFT expr")
#line 417 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_RSHIFT, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7220 "parse.c"
        /* No destructor defined for RSHIFT */
        break;
      case 173:
        YYTRACE("expr ::= expr LIKE expr")
#line 418 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_LIKE, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7227 "parse.c"
        /* No destructor defined for LIKE */
        break;
      case 174:
        YYTRACE("expr ::= expr NOT LIKE expr")
#line 419 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_LIKE, yymsp[-3].minor.yy132, yymsp[0].minor.yy132, 0);
  yygotominor.yy132 = sqliteExpr(TK_NOT, yygotominor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-3].minor.yy132->span,&yymsp[0].minor.yy132->span);
}
#line 7238 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for LIKE */
        break;
      case 175:
        YYTRACE("expr ::= expr GLOB expr")
#line 424 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_GLOB,yymsp[-2].minor.yy132,yymsp[0].minor.yy132,0);}
#line 7246 "parse.c"
        /* No destructor defined for GLOB */
        break;
      case 176:
        YYTRACE("expr ::= expr NOT GLOB expr")
#line 425 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_GLOB, yymsp[-3].minor.yy132, yymsp[0].minor.yy132, 0);
  yygotominor.yy132 = sqliteExpr(TK_NOT, yygotominor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-3].minor.yy132->span,&yymsp[0].minor.yy132->span);
}
#line 7257 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for GLOB */
        break;
      case 177:
        YYTRACE("expr ::= expr PLUS expr")
#line 430 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_PLUS, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7265 "parse.c"
        /* No destructor defined for PLUS */
        break;
      case 178:
        YYTRACE("expr ::= expr MINUS expr")
#line 431 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_MINUS, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7272 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 179:
        YYTRACE("expr ::= expr STAR expr")
#line 432 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_STAR, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7279 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 180:
        YYTRACE("expr ::= expr SLASH expr")
#line 433 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_SLASH, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7286 "parse.c"
        /* No destructor defined for SLASH */
        break;
      case 181:
        YYTRACE("expr ::= expr REM expr")
#line 434 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_REM, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7293 "parse.c"
        /* No destructor defined for REM */
        break;
      case 182:
        YYTRACE("expr ::= expr CONCAT expr")
#line 435 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_CONCAT, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 7300 "parse.c"
        /* No destructor defined for CONCAT */
        break;
      case 183:
        YYTRACE("expr ::= expr ISNULL")
#line 436 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_ISNULL, yymsp[-1].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-1].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 7310 "parse.c"
        break;
      case 184:
        YYTRACE("expr ::= expr IS NULL")
#line 440 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_ISNULL, yymsp[-2].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-2].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 7319 "parse.c"
        /* No destructor defined for IS */
        break;
      case 185:
        YYTRACE("expr ::= expr NOTNULL")
#line 444 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_NOTNULL, yymsp[-1].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-1].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 7329 "parse.c"
        break;
      case 186:
        YYTRACE("expr ::= expr NOT NULL")
#line 448 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_NOTNULL, yymsp[-2].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-2].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 7338 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 187:
        YYTRACE("expr ::= expr IS NOT NULL")
#line 452 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_NOTNULL, yymsp[-3].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-3].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 7348 "parse.c"
        /* No destructor defined for IS */
        /* No destructor defined for NOT */
        break;
      case 188:
        YYTRACE("expr ::= NOT expr")
#line 456 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_NOT, yymsp[0].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy132->span);
}
#line 7359 "parse.c"
        break;
      case 189:
        YYTRACE("expr ::= BITNOT expr")
#line 460 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_BITNOT, yymsp[0].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy132->span);
}
#line 7368 "parse.c"
        break;
      case 190:
        YYTRACE("expr ::= MINUS expr")
#line 464 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_UMINUS, yymsp[0].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy132->span);
}
#line 7377 "parse.c"
        break;
      case 191:
        YYTRACE("expr ::= PLUS expr")
#line 468 "parse.y"
{
  yygotominor.yy132 = yymsp[0].minor.yy132;
  sqliteExprSpan(yygotominor.yy132,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy132->span);
}
#line 7386 "parse.c"
        break;
      case 192:
        YYTRACE("expr ::= LP select RP")
#line 472 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_SELECT, 0, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pSelect = yymsp[-1].minor.yy233;
  sqliteExprSpan(yygotominor.yy132,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);
}
#line 7396 "parse.c"
        break;
      case 193:
        YYTRACE("expr ::= expr BETWEEN expr AND expr")
#line 477 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy132, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy132, 0);
  yygotominor.yy132 = sqliteExpr(TK_BETWEEN, yymsp[-4].minor.yy132, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pList = pList;
  sqliteExprSpan(yygotominor.yy132,&yymsp[-4].minor.yy132->span,&yymsp[0].minor.yy132->span);
}
#line 7408 "parse.c"
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 194:
        YYTRACE("expr ::= expr NOT BETWEEN expr AND expr")
#line 484 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy132, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy132, 0);
  yygotominor.yy132 = sqliteExpr(TK_BETWEEN, yymsp[-5].minor.yy132, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pList = pList;
  yygotominor.yy132 = sqliteExpr(TK_NOT, yygotominor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-5].minor.yy132->span,&yymsp[0].minor.yy132->span);
}
#line 7423 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 195:
        YYTRACE("expr ::= expr IN LP exprlist RP")
#line 492 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_IN, yymsp[-4].minor.yy132, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pList = yymsp[-1].minor.yy270;
  sqliteExprSpan(yygotominor.yy132,&yymsp[-4].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 7436 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 196:
        YYTRACE("expr ::= expr IN LP select RP")
#line 497 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_IN, yymsp[-4].minor.yy132, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pSelect = yymsp[-1].minor.yy233;
  sqliteExprSpan(yygotominor.yy132,&yymsp[-4].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 7448 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 197:
        YYTRACE("expr ::= expr NOT IN LP exprlist RP")
#line 502 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_IN, yymsp[-5].minor.yy132, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pList = yymsp[-1].minor.yy270;
  yygotominor.yy132 = sqliteExpr(TK_NOT, yygotominor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-5].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 7461 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 198:
        YYTRACE("expr ::= expr NOT IN LP select RP")
#line 508 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_IN, yymsp[-5].minor.yy132, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pSelect = yymsp[-1].minor.yy233;
  yygotominor.yy132 = sqliteExpr(TK_NOT, yygotominor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-5].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 7475 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 199:
        YYTRACE("exprlist ::= exprlist COMMA expritem")
#line 523 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(yymsp[-2].minor.yy270,yymsp[0].minor.yy132,0);}
#line 7484 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 200:
        YYTRACE("exprlist ::= expritem")
#line 524 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(0,yymsp[0].minor.yy132,0);}
#line 7491 "parse.c"
        break;
      case 201:
        YYTRACE("expritem ::= expr")
#line 525 "parse.y"
{yygotominor.yy132 = yymsp[0].minor.yy132;}
#line 7497 "parse.c"
        break;
      case 202:
        YYTRACE("expritem ::=")
#line 526 "parse.y"
{yygotominor.yy132 = 0;}
#line 7503 "parse.c"
        break;
      case 203:
        YYTRACE("cmd ::= CREATE uniqueflag INDEX ids ON ids LP idxlist RP onconf")
#line 531 "parse.y"
{
  if( yymsp[-8].minor.yy144!=OE_None ) yymsp[-8].minor.yy144 = yymsp[0].minor.yy144;
  if( yymsp[-8].minor.yy144==OE_Default) yymsp[-8].minor.yy144 = OE_Abort;
  sqliteCreateIndex(pParse, &yymsp[-6].minor.yy224, &yymsp[-4].minor.yy224, yymsp[-2].minor.yy152, yymsp[-8].minor.yy144, &yymsp[-9].minor.yy0, &yymsp[-1].minor.yy0);
}
#line 7513 "parse.c"
        /* No destructor defined for INDEX */
        /* No destructor defined for ON */
        /* No destructor defined for LP */
        break;
      case 204:
        YYTRACE("uniqueflag ::= UNIQUE")
#line 538 "parse.y"
{ yygotominor.yy144 = OE_Abort; }
#line 7522 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 205:
        YYTRACE("uniqueflag ::=")
#line 539 "parse.y"
{ yygotominor.yy144 = OE_None; }
#line 7529 "parse.c"
        break;
      case 206:
        YYTRACE("idxlist ::= idxlist COMMA idxitem")
#line 546 "parse.y"
{yygotominor.yy152 = sqliteIdListAppend(yymsp[-2].minor.yy152,&yymsp[0].minor.yy224);}
#line 7535 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 207:
        YYTRACE("idxlist ::= idxitem")
#line 548 "parse.y"
{yygotominor.yy152 = sqliteIdListAppend(0,&yymsp[0].minor.yy224);}
#line 7542 "parse.c"
        break;
      case 208:
        YYTRACE("idxitem ::= ids")
#line 549 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy224;}
#line 7548 "parse.c"
        break;
      case 209:
        YYTRACE("cmd ::= DROP INDEX ids")
#line 554 "parse.y"
{sqliteDropIndex(pParse, &yymsp[0].minor.yy224);}
#line 7554 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for INDEX */
        break;
      case 210:
        YYTRACE("cmd ::= COPY orconf ids FROM ids USING DELIMITERS STRING")
#line 560 "parse.y"
{sqliteCopy(pParse,&yymsp[-5].minor.yy224,&yymsp[-3].minor.yy224,&yymsp[0].minor.yy0,yymsp[-6].minor.yy144);}
#line 7562 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        /* No destructor defined for USING */
        /* No destructor defined for DELIMITERS */
        break;
      case 211:
        YYTRACE("cmd ::= COPY orconf ids FROM ids")
#line 562 "parse.y"
{sqliteCopy(pParse,&yymsp[-2].minor.yy224,&yymsp[0].minor.yy224,0,yymsp[-3].minor.yy144);}
#line 7572 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        break;
      case 212:
        YYTRACE("cmd ::= VACUUM")
#line 566 "parse.y"
{sqliteVacuum(pParse,0);}
#line 7580 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 213:
        YYTRACE("cmd ::= VACUUM ids")
#line 567 "parse.y"
{sqliteVacuum(pParse,&yymsp[0].minor.yy224);}
#line 7587 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 214:
        YYTRACE("cmd ::= PRAGMA ids EQ ids")
#line 571 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy224,&yymsp[0].minor.yy224,0);}
#line 7594 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 215:
        YYTRACE("cmd ::= PRAGMA ids EQ ON")
#line 572 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy224,&yymsp[0].minor.yy0,0);}
#line 7602 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 216:
        YYTRACE("cmd ::= PRAGMA ids EQ plus_num")
#line 573 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy224,&yymsp[0].minor.yy224,0);}
#line 7610 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 217:
        YYTRACE("cmd ::= PRAGMA ids EQ minus_num")
#line 574 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy224,&yymsp[0].minor.yy224,1);}
#line 7618 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 218:
        YYTRACE("cmd ::= PRAGMA ids LP ids RP")
#line 575 "parse.y"
{sqlitePragma(pParse,&yymsp[-3].minor.yy224,&yymsp[-1].minor.yy224,0);}
#line 7626 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 219:
        YYTRACE("cmd ::= PRAGMA ids")
#line 576 "parse.y"
{sqlitePragma(pParse,&yymsp[0].minor.yy224,&yymsp[-1].minor.yy0,0);}
#line 7635 "parse.c"
        break;
      case 220:
        YYTRACE("plus_num ::= plus_opt number")
#line 577 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy224;}
#line 7641 "parse.c"
        /* No destructor defined for plus_opt */
        break;
      case 221:
        YYTRACE("minus_num ::= MINUS number")
#line 578 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy224;}
#line 7648 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 222:
        YYTRACE("number ::= INTEGER")
#line 579 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 7655 "parse.c"
        break;
      case 223:
        YYTRACE("number ::= FLOAT")
#line 580 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 7661 "parse.c"
        break;
      case 224:
        YYTRACE("plus_opt ::= PLUS")
        /* No destructor defined for PLUS */
        break;
      case 225:
        YYTRACE("plus_opt ::=")
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->idx -= yysize;
  yypParser->top -= yysize;
  yyact = yy_find_parser_action(yypParser,yygoto);
  if( yyact < YYNSTATE ){
    yy_shift(yypParser,yyact,yygoto,&yygotominor);
  }else if( yyact == YYNSTATE + YYNRULE + 1 ){
    yy_accept(yypParser sqliteParserARGDECL);
  }
}

/*
** The following code executes when the parse fails
*/
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
  sqliteParserANSIARGDECL              /* Extra arguments (if any) */
){
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->idx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
  sqliteParserANSIARGDECL               /* Extra arguments (if any) */
){
#define TOKEN (yyminor.yy0)
#line 23 "parse.y"

  sqliteSetString(&pParse->zErrMsg,"syntax error",0);
  pParse->sErrToken = TOKEN;

#line 7715 "parse.c"
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
  sqliteParserANSIARGDECL              /* Extra arguments (if any) */
){
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->idx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "sqliteParserAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void sqliteParser(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  sqliteParserTOKENTYPE yyminor       /* The value for the token */
  sqliteParserANSIARGDECL
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->idx<0 ){
    if( yymajor==0 ) return;
    yypParser->idx = 0;
    yypParser->errcnt = -1;
    yypParser->top = &yypParser->stack[0];
    yypParser->top->stateno = 0;
    yypParser->top->major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_parser_action(yypParser,yymajor);
    if( yyact<YYNSTATE ){
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->errcnt--;
      if( yyendofinput && yypParser->idx>=0 ){
        yymajor = 0;
      }else{
        yymajor = YYNOCODE;
      }
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE sqliteParserARGDECL);
    }else if( yyact == YY_ERROR_ACTION ){
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->errcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion sqliteParserARGDECL);
      }
      if( yypParser->top->major==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->idx >= 0 &&
          yypParser->top->major != YYERRORSYMBOL &&
          (yyact = yy_find_parser_action(yypParser,YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->idx < 0 || yymajor==0 ){
          yy_destructor(yymajor,&yyminorunion);
          yy_parse_failed(yypParser sqliteParserARGDECL);
          yymajor = YYNOCODE;
        }else if( yypParser->top->major!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->errcnt = 3;
      yyerrorhit = 1;
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->errcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion sqliteParserARGDECL);
      }
      yypParser->errcnt = 3;
      yy_destructor(yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser sqliteParserARGDECL);
      }
      yymajor = YYNOCODE;
#endif
    }else{
      yy_accept(yypParser sqliteParserARGDECL);
      yymajor = YYNOCODE;
    }
  }while( yymajor!=YYNOCODE && yypParser->idx>=0 );
  return;
}
