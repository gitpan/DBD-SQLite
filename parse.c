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
#define YYNOCODE 161
#define YYACTIONTYPE int
#define sqliteParserTOKENTYPE Token
typedef union {
  sqliteParserTOKENTYPE yy0;
  Expr* yy2;
  ExprList* yy48;
  IdList* yy50;
  int yy92;
  Token yy98;
  Select* yy299;
  struct twoint yy303;
  int yy321;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define sqliteParserARGDECL ,pParse
#define sqliteParserXARGDECL Parse *pParse;
#define sqliteParserANSIARGDECL ,Parse *pParse
#define YYNSTATE 385
#define YYNRULE 221
#define YYERRORSYMBOL 114
#define YYERRSYMDT yy321
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
  {  96, 363, 0                    }, /*                 VACUUM shift  363 */
  { 129, 334, 0                    }, /*             insert_cmd shift  334 */
  {   7,   6, 0                    }, /*                  BEGIN shift  6 */
  {  35, 383, 0                    }, /*                EXPLAIN shift  383 */
  {  73, 365, 0                    }, /*                 PRAGMA shift  365 */
  { 113, 384, 0                    }, /*                   ecmd shift  384 */
  {  18,  39, 0                    }, /*                 COMMIT shift  39 */
  { 103, 382, &yyActionTable[   2] }, /*                    cmd shift  382 */
  { 104,   1, 0                    }, /*                cmdlist shift  1 */
  { 137,  78, &yyActionTable[   4] }, /*              oneselect shift  78 */
  {  94, 319, &yyActionTable[  11] }, /*                 UPDATE shift  319 */
  {  30, 309, 0                    }, /*                   DROP shift  309 */
  {  76, 354, 0                    }, /*                REPLACE shift  354 */
  {  77,  43, 0                    }, /*               ROLLBACK shift  43 */
  { 110,  45, 0                    }, /*           create_table shift  45 */
  {YYNOCODE,0,0}, /* Unused */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  { 145, 314, &yyActionTable[   5] }, /*                 select shift  314 */
  {  50, 352, &yyActionTable[   6] }, /*                 INSERT shift  352 */
  { 115,   4, 0                    }, /*                explain shift  4 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  22, 355, 0                    }, /*                   COPY shift  355 */
  {  23, 294, 0                    }, /*                 CREATE shift  294 */
  {YYNOCODE,0,0}, /* Unused */
  {  25, 315, 0                    }, /*                 DELETE shift  315 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  { 126, 607, &yyActionTable[  10] }, /*                  input accept */
  {  31,  41, 0                    }, /*                    END shift  41 */
/* State 1 */
  {   0, 385, 0                    }, /*                      $ reduce 0 */
  {  81,   2, 0                    }, /*                   SEMI shift  2 */
/* State 2 */
  {  96, 363, 0                    }, /*                 VACUUM shift  363 */
  { 129, 334, 0                    }, /*             insert_cmd shift  334 */
  {   7,   6, 0                    }, /*                  BEGIN shift  6 */
  {  35, 383, 0                    }, /*                EXPLAIN shift  383 */
  {  73, 365, 0                    }, /*                 PRAGMA shift  365 */
  { 113,   3, 0                    }, /*                   ecmd shift  3 */
  {  18,  39, 0                    }, /*                 COMMIT shift  39 */
  { 103, 382, &yyActionTable[  36] }, /*                    cmd shift  382 */
  {  30, 309, 0                    }, /*                   DROP shift  309 */
  { 137,  78, &yyActionTable[  38] }, /*              oneselect shift  78 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  76, 354, 0                    }, /*                REPLACE shift  354 */
  {  77,  43, 0                    }, /*               ROLLBACK shift  43 */
  { 110,  45, 0                    }, /*           create_table shift  45 */
  {YYNOCODE,0,0}, /* Unused */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  { 145, 314, &yyActionTable[  39] }, /*                 select shift  314 */
  {  50, 352, &yyActionTable[  40] }, /*                 INSERT shift  352 */
  { 115,   4, 0                    }, /*                explain shift  4 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  22, 355, 0                    }, /*                   COPY shift  355 */
  {  23, 294, 0                    }, /*                 CREATE shift  294 */
  {YYNOCODE,0,0}, /* Unused */
  {  25, 315, 0                    }, /*                 DELETE shift  315 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  94, 319, &yyActionTable[  42] }, /*                 UPDATE shift  319 */
  {  31,  41, 0                    }, /*                    END shift  41 */
/* State 3 */
  {YYNOCODE,0,0}, /* Unused */
/* State 4 */
  {  96, 363, 0                    }, /*                 VACUUM shift  363 */
  { 129, 334, 0                    }, /*             insert_cmd shift  334 */
  {   7,   6, 0                    }, /*                  BEGIN shift  6 */
  {  73, 365, 0                    }, /*                 PRAGMA shift  365 */
  {  18,  39, 0                    }, /*                 COMMIT shift  39 */
  {  30, 309, 0                    }, /*                   DROP shift  309 */
  {YYNOCODE,0,0}, /* Unused */
  { 103,   5, &yyActionTable[  69] }, /*                    cmd shift  5 */
  {YYNOCODE,0,0}, /* Unused */
  { 137,  78, &yyActionTable[  70] }, /*              oneselect shift  78 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  76, 354, 0                    }, /*                REPLACE shift  354 */
  {  77,  43, 0                    }, /*               ROLLBACK shift  43 */
  { 110,  45, 0                    }, /*           create_table shift  45 */
  {YYNOCODE,0,0}, /* Unused */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  { 145, 314, 0                    }, /*                 select shift  314 */
  {  50, 352, &yyActionTable[  71] }, /*                 INSERT shift  352 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  22, 355, 0                    }, /*                   COPY shift  355 */
  {  23, 294, 0                    }, /*                 CREATE shift  294 */
  {YYNOCODE,0,0}, /* Unused */
  {  25, 315, 0                    }, /*                 DELETE shift  315 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  94, 319, &yyActionTable[  72] }, /*                 UPDATE shift  319 */
  {  31,  41, 0                    }, /*                    END shift  41 */
/* State 5 */
  {YYNOCODE,0,0}, /* Unused */
/* State 6 */
  {  89,  17, 0                    }, /*            TRANSACTION shift  17 */
  { 155,   7, &yyActionTable[ 100] }, /*              trans_opt shift  7 */
/* State 7 */
  { 136,   8, 0                    }, /*                 onconf shift  8 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
/* State 8 */
  {YYNOCODE,0,0}, /* Unused */
/* State 9 */
  {  20,  10, 0                    }, /*               CONFLICT shift  10 */
/* State 10 */
  {  36,  14, 0                    }, /*                   FAIL shift  14 */
  {   1,  13, 0                    }, /*                  ABORT shift  13 */
  {  46,  15, 0                    }, /*                 IGNORE shift  15 */
  {YYNOCODE,0,0}, /* Unused */
  {  76,  16, &yyActionTable[ 106] }, /*                REPLACE shift  16 */
  {  77,  12, 0                    }, /*               ROLLBACK shift  12 */
  { 142,  11, &yyActionTable[ 108] }, /*            resolvetype shift  11 */
  {YYNOCODE,0,0}, /* Unused */
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
  {  89,  17, 0                    }, /*            TRANSACTION shift  17 */
  { 155,  40, &yyActionTable[ 173] }, /*              trans_opt shift  40 */
/* State 40 */
  {YYNOCODE,0,0}, /* Unused */
/* State 41 */
  {  89,  17, 0                    }, /*            TRANSACTION shift  17 */
  { 155,  42, &yyActionTable[ 176] }, /*              trans_opt shift  42 */
/* State 42 */
  {YYNOCODE,0,0}, /* Unused */
/* State 43 */
  {  89,  17, 0                    }, /*            TRANSACTION shift  17 */
  { 155,  44, &yyActionTable[ 179] }, /*              trans_opt shift  44 */
/* State 44 */
  {YYNOCODE,0,0}, /* Unused */
/* State 45 */
  {  60,  47, 0                    }, /*                     LP shift  47 */
  {   5, 292, 0                    }, /*                     AS shift  292 */
  {YYNOCODE,0,0}, /* Unused */
  { 111,  46, 0                    }, /*      create_table_args shift  46 */
/* State 46 */
  {YYNOCODE,0,0}, /* Unused */
/* State 47 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[ 189] }, /*                 OFFSET shift  30 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  { 105, 291, &yyActionTable[ 192] }, /*                 column shift  291 */
  { 106,  53, 0                    }, /*               columnid shift  53 */
  { 107,  48, 0                    }, /*             columnlist shift  48 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[ 195] }, /*                 IGNORE shift  33 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[ 202] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[ 203] }, /*                     id shift  37 */
  { 123, 265, &yyActionTable[ 204] }, /*                    ids shift  265 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 48 */
  {  16,  51, 0                    }, /*                  COMMA shift  51 */
  { 109,  49, 0                    }, /*           conslist_opt shift  49 */
  {  78, 455, 0                    }, /*                     RP reduce 70 */
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
  {  68,  30, &yyActionTable[ 227] }, /*                 OFFSET shift  30 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  74, 271, 0                    }, /*                PRIMARY shift  271 */
  { 105,  52, &yyActionTable[ 230] }, /*                 column shift  52 */
  { 106,  53, &yyActionTable[ 233] }, /*               columnid shift  53 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  { 108, 266, &yyActionTable[ 236] }, /*               conslist shift  266 */
  {  45,  28, &yyActionTable[ 240] }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[ 241] }, /*                 IGNORE shift  33 */
  {  13, 286, 0                    }, /*                  CHECK shift  286 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  21, 269, 0                    }, /*             CONSTRAINT shift  269 */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[ 242] }, /*                   TEMP shift  29 */
  { 153, 290, 0                    }, /*                  tcons shift  290 */
  { 122,  37, &yyActionTable[ 243] }, /*                     id shift  37 */
  { 123, 265, &yyActionTable[ 244] }, /*                    ids shift  265 */
  {YYNOCODE,0,0}, /* Unused */
  {  93, 281, 0                    }, /*                 UNIQUE shift  281 */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 52 */
  {YYNOCODE,0,0}, /* Unused */
/* State 53 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[ 260] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[ 263] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[ 266] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[ 268] }, /*                     id shift  37 */
  { 123, 264, &yyActionTable[ 269] }, /*                    ids shift  264 */
  { 156,  54, 0                    }, /*                   type shift  54 */
  { 157, 251, 0                    }, /*               typename shift  251 */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 54 */
  { 101,  55, 0                    }, /*               carglist shift  55 */
/* State 55 */
  {  24, 239, 0                    }, /*                DEFAULT shift  239 */
  {  65,  60, 0                    }, /*                    NOT shift  60 */
  {  74,  63, 0                    }, /*                PRIMARY shift  63 */
  {  21,  57, &yyActionTable[ 298] }, /*             CONSTRAINT shift  57 */
  { 100,  56, 0                    }, /*                   carg shift  56 */
  {  93,  69, &yyActionTable[ 294] }, /*                 UNIQUE shift  69 */
  { 102, 238, 0                    }, /*                  ccons shift  238 */
  {  13,  71, 0                    }, /*                  CHECK shift  71 */
/* State 56 */
  {YYNOCODE,0,0}, /* Unused */
/* State 57 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[ 302] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[ 305] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[ 308] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[ 310] }, /*                     id shift  37 */
  { 123,  58, &yyActionTable[ 311] }, /*                    ids shift  58 */
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
  {  93,  69, &yyActionTable[ 332] }, /*                 UNIQUE shift  69 */
  { 102,  59, 0                    }, /*                  ccons shift  59 */
  {YYNOCODE,0,0}, /* Unused */
/* State 59 */
  {YYNOCODE,0,0}, /* Unused */
/* State 60 */
  {  67,  61, 0                    }, /*                   NULL shift  61 */
/* State 61 */
  { 136,  62, 0                    }, /*                 onconf shift  62 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
/* State 62 */
  {YYNOCODE,0,0}, /* Unused */
/* State 63 */
  {  56,  64, 0                    }, /*                    KEY shift  64 */
/* State 64 */
  {  27,  68, 0                    }, /*                   DESC shift  68 */
  {YYNOCODE,0,0}, /* Unused */
  {   6,  67, 0                    }, /*                    ASC shift  67 */
  { 151,  65, &yyActionTable[ 346] }, /*              sortorder shift  65 */
/* State 65 */
  { 136,  66, 0                    }, /*                 onconf shift  66 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
/* State 66 */
  {YYNOCODE,0,0}, /* Unused */
/* State 67 */
  {YYNOCODE,0,0}, /* Unused */
/* State 68 */
  {YYNOCODE,0,0}, /* Unused */
/* State 69 */
  { 136,  70, 0                    }, /*                 onconf shift  70 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
/* State 70 */
  {YYNOCODE,0,0}, /* Unused */
/* State 71 */
  {  60,  72, 0                    }, /*                     LP shift  72 */
/* State 72 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[ 361] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[ 370] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[ 374] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[ 375] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 235, &yyActionTable[ 376] }, /*                   expr shift  235 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[ 377] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[ 380] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[ 382] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[ 384] }, /*                  MINUS shift  176 */
/* State 73 */
  {  60,  74, 0                    }, /*                     LP shift  74 */
/* State 74 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  65, 172, &yyActionTable[ 392] }, /*                    NOT shift  172 */
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
  {  85, 233, 0                    }, /*                   STAR shift  233 */
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
  { 118, 231, 0                    }, /*               exprlist shift  231 */
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
  {   0, 534, 0                    }, /*                      $ reduce 149 */
  {   1, 534, 0                    }, /*                  ABORT reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {   4, 534, 0                    }, /*                    AND reduce 149 */
  {   5, 534, 0                    }, /*                     AS reduce 149 */
  {   6, 534, 0                    }, /*                    ASC reduce 149 */
  {   7, 534, 0                    }, /*                  BEGIN reduce 149 */
  {   8, 534, 0                    }, /*                BETWEEN reduce 149 */
  {   9, 534, 0                    }, /*                 BITAND reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  11, 534, 0                    }, /*                  BITOR reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  13, 534, 0                    }, /*                  CHECK reduce 149 */
  {  14, 534, 0                    }, /*                CLUSTER reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  16, 534, 0                    }, /*                  COMMA reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  19, 534, 0                    }, /*                 CONCAT reduce 149 */
  {  20, 534, 0                    }, /*               CONFLICT reduce 149 */
  {  21, 534, 0                    }, /*             CONSTRAINT reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  26, 534, 0                    }, /*             DELIMITERS reduce 149 */
  {  27, 534, 0                    }, /*                   DESC reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  29, 427, 0                    }, /*                    DOT reduce 42 */
  {YYNOCODE,0,0}, /* Unused */
  {  31, 534, 0                    }, /*                    END reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  33, 534, 0                    }, /*                     EQ reduce 149 */
  {  34, 534, 0                    }, /*                 EXCEPT reduce 149 */
  {  35, 534, 0                    }, /*                EXPLAIN reduce 149 */
  {  36, 534, 0                    }, /*                   FAIL reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  38, 534, 0                    }, /*                   FROM reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  40, 534, 0                    }, /*                     GE reduce 149 */
  {  41, 534, 0                    }, /*                   GLOB reduce 149 */
  {  42, 534, 0                    }, /*                  GROUP reduce 149 */
  {  43, 534, 0                    }, /*                     GT reduce 149 */
  {  44, 534, 0                    }, /*                 HAVING reduce 149 */
  {  45, 534, 0                    }, /*                     ID reduce 149 */
  {  46, 534, 0                    }, /*                 IGNORE reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  48, 534, 0                    }, /*                     IN reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  52, 534, 0                    }, /*              INTERSECT reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  54, 534, 0                    }, /*                     IS reduce 149 */
  {  55, 534, 0                    }, /*                 ISNULL reduce 149 */
  {  56, 534, 0                    }, /*                    KEY reduce 149 */
  {  57, 534, 0                    }, /*                     LE reduce 149 */
  {  58, 534, 0                    }, /*                   LIKE reduce 149 */
  {  59, 534, 0                    }, /*                  LIMIT reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 534, 0                    }, /*                 LSHIFT reduce 149 */
  {  62, 534, 0                    }, /*                     LT reduce 149 */
  {  63, 534, 0                    }, /*                  MINUS reduce 149 */
  {  64, 534, 0                    }, /*                     NE reduce 149 */
  {  65, 534, 0                    }, /*                    NOT reduce 149 */
  {  66, 534, 0                    }, /*                NOTNULL reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  68, 534, 0                    }, /*                 OFFSET reduce 149 */
  {  69, 534, 0                    }, /*                     ON reduce 149 */
  {  70, 534, 0                    }, /*                     OR reduce 149 */
  {  71, 534, 0                    }, /*                  ORDER reduce 149 */
  {  72, 534, 0                    }, /*                   PLUS reduce 149 */
  {  73, 534, 0                    }, /*                 PRAGMA reduce 149 */
  {  74, 534, 0                    }, /*                PRIMARY reduce 149 */
  {  75, 534, 0                    }, /*                    REM reduce 149 */
  {  76, 534, 0                    }, /*                REPLACE reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  78, 534, 0                    }, /*                     RP reduce 149 */
  {  79, 534, 0                    }, /*                 RSHIFT reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  81, 534, 0                    }, /*                   SEMI reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 534, 0                    }, /*                  SLASH reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 534, 0                    }, /*                   STAR reduce 149 */
  {  86, 534, 0                    }, /*                 STRING reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  88, 534, 0                    }, /*                   TEMP reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  92, 534, 0                    }, /*                  UNION reduce 149 */
  {  93, 534, 0                    }, /*                 UNIQUE reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  96, 534, 0                    }, /*                 VACUUM reduce 149 */
  {YYNOCODE,0,0}, /* Unused */
  {  98, 534, 0                    }, /*                  WHERE reduce 149 */
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
  {   0, 538, 0                    }, /*                      $ reduce 153 */
  {   1, 538, 0                    }, /*                  ABORT reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {   4, 538, 0                    }, /*                    AND reduce 153 */
  {   5, 538, 0                    }, /*                     AS reduce 153 */
  {   6, 538, 0                    }, /*                    ASC reduce 153 */
  {   7, 538, 0                    }, /*                  BEGIN reduce 153 */
  {   8, 538, 0                    }, /*                BETWEEN reduce 153 */
  {   9, 538, 0                    }, /*                 BITAND reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  11, 538, 0                    }, /*                  BITOR reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  13, 538, 0                    }, /*                  CHECK reduce 153 */
  {  14, 538, 0                    }, /*                CLUSTER reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  16, 538, 0                    }, /*                  COMMA reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  19, 538, 0                    }, /*                 CONCAT reduce 153 */
  {  20, 538, 0                    }, /*               CONFLICT reduce 153 */
  {  21, 538, 0                    }, /*             CONSTRAINT reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  26, 538, 0                    }, /*             DELIMITERS reduce 153 */
  {  27, 538, 0                    }, /*                   DESC reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  29, 428, 0                    }, /*                    DOT reduce 43 */
  {YYNOCODE,0,0}, /* Unused */
  {  31, 538, 0                    }, /*                    END reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  33, 538, 0                    }, /*                     EQ reduce 153 */
  {  34, 538, 0                    }, /*                 EXCEPT reduce 153 */
  {  35, 538, 0                    }, /*                EXPLAIN reduce 153 */
  {  36, 538, 0                    }, /*                   FAIL reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  38, 538, 0                    }, /*                   FROM reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  40, 538, 0                    }, /*                     GE reduce 153 */
  {  41, 538, 0                    }, /*                   GLOB reduce 153 */
  {  42, 538, 0                    }, /*                  GROUP reduce 153 */
  {  43, 538, 0                    }, /*                     GT reduce 153 */
  {  44, 538, 0                    }, /*                 HAVING reduce 153 */
  {  45, 538, 0                    }, /*                     ID reduce 153 */
  {  46, 538, 0                    }, /*                 IGNORE reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  48, 538, 0                    }, /*                     IN reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  52, 538, 0                    }, /*              INTERSECT reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  54, 538, 0                    }, /*                     IS reduce 153 */
  {  55, 538, 0                    }, /*                 ISNULL reduce 153 */
  {  56, 538, 0                    }, /*                    KEY reduce 153 */
  {  57, 538, 0                    }, /*                     LE reduce 153 */
  {  58, 538, 0                    }, /*                   LIKE reduce 153 */
  {  59, 538, 0                    }, /*                  LIMIT reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 538, 0                    }, /*                 LSHIFT reduce 153 */
  {  62, 538, 0                    }, /*                     LT reduce 153 */
  {  63, 538, 0                    }, /*                  MINUS reduce 153 */
  {  64, 538, 0                    }, /*                     NE reduce 153 */
  {  65, 538, 0                    }, /*                    NOT reduce 153 */
  {  66, 538, 0                    }, /*                NOTNULL reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  68, 538, 0                    }, /*                 OFFSET reduce 153 */
  {  69, 538, 0                    }, /*                     ON reduce 153 */
  {  70, 538, 0                    }, /*                     OR reduce 153 */
  {  71, 538, 0                    }, /*                  ORDER reduce 153 */
  {  72, 538, 0                    }, /*                   PLUS reduce 153 */
  {  73, 538, 0                    }, /*                 PRAGMA reduce 153 */
  {  74, 538, 0                    }, /*                PRIMARY reduce 153 */
  {  75, 538, 0                    }, /*                    REM reduce 153 */
  {  76, 538, 0                    }, /*                REPLACE reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  78, 538, 0                    }, /*                     RP reduce 153 */
  {  79, 538, 0                    }, /*                 RSHIFT reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  81, 538, 0                    }, /*                   SEMI reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 538, 0                    }, /*                  SLASH reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 538, 0                    }, /*                   STAR reduce 153 */
  {  86, 538, 0                    }, /*                 STRING reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  88, 538, 0                    }, /*                   TEMP reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  92, 538, 0                    }, /*                  UNION reduce 153 */
  {  93, 538, 0                    }, /*                 UNIQUE reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  96, 538, 0                    }, /*                 VACUUM reduce 153 */
  {YYNOCODE,0,0}, /* Unused */
  {  98, 538, 0                    }, /*                  WHERE reduce 153 */
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
  {  65, 172, &yyActionTable[ 712] }, /*                    NOT shift  172 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  67, 105, 0                    }, /*                   NULL shift  105 */
  {  68,  30, 0                    }, /*                 OFFSET shift  30 */
  {YYNOCODE,0,0}, /* Unused */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  { 137,  78, &yyActionTable[ 714] }, /*              oneselect shift  78 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {YYNOCODE,0,0}, /* Unused */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {YYNOCODE,0,0}, /* Unused */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {YYNOCODE,0,0}, /* Unused */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  { 145,  79, 0                    }, /*                 select shift  79 */
  {YYNOCODE,0,0}, /* Unused */
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
  { 116, 229, 0                    }, /*                   expr shift  229 */
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
  {  52, 168, 0                    }, /*              INTERSECT shift  168 */
  {  78, 228, 0                    }, /*                     RP shift  228 */
  {  34, 169, 0                    }, /*                 EXCEPT shift  169 */
  {YYNOCODE,0,0}, /* Unused */
  {  92, 166, &yyActionTable[ 777] }, /*                  UNION shift  166 */
  {YYNOCODE,0,0}, /* Unused */
  { 134,  80, &yyActionTable[ 778] }, /*         multiselect_op shift  80 */
  {YYNOCODE,0,0}, /* Unused */
/* State 80 */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  { 137,  81, 0                    }, /*              oneselect shift  81 */
/* State 81 */
  {YYNOCODE,0,0}, /* Unused */
/* State 82 */
  { 112,  83, &yyActionTable[ 789] }, /*               distinct shift  83 */
  {  28, 226, 0                    }, /*               DISTINCT shift  226 */
  {YYNOCODE,0,0}, /* Unused */
  {   3, 227, 0                    }, /*                    ALL shift  227 */
/* State 83 */
  { 144,  84, 0                    }, /*             selcollist shift  84 */
  { 143, 221, 0                    }, /*                   sclp shift  221 */
/* State 84 */
  {  16, 207, 0                    }, /*                  COMMA shift  207 */
  {YYNOCODE,0,0}, /* Unused */
  {  38, 208, 0                    }, /*                   FROM shift  208 */
  { 119,  85, 0                    }, /*                   from shift  85 */
/* State 85 */
  {  98, 205, 0                    }, /*                  WHERE shift  205 */
  { 159,  86, 0                    }, /*              where_opt shift  86 */
/* State 86 */
  { 120,  87, &yyActionTable[ 801] }, /*            groupby_opt shift  87 */
  {  42, 202, 0                    }, /*                  GROUP shift  202 */
/* State 87 */
  {  44, 200, 0                    }, /*                 HAVING shift  200 */
  { 121,  88, 0                    }, /*             having_opt shift  88 */
/* State 88 */
  {  71,  97, 0                    }, /*                  ORDER shift  97 */
  { 139,  89, &yyActionTable[ 804] }, /*            orderby_opt shift  89 */
/* State 89 */
  {  59,  91, 0                    }, /*                  LIMIT shift  91 */
  { 131,  90, &yyActionTable[ 806] }, /*              limit_opt shift  90 */
/* State 90 */
  {YYNOCODE,0,0}, /* Unused */
/* State 91 */
  {  51,  92, 0                    }, /*                INTEGER shift  92 */
/* State 92 */
  { 132,  93, &yyActionTable[ 811] }, /*              limit_sep shift  93 */
  {  68,  95, &yyActionTable[ 812] }, /*                 OFFSET shift  95 */
  {  16,  96, 0                    }, /*                  COMMA shift  96 */
  {YYNOCODE,0,0}, /* Unused */
/* State 93 */
  {  51,  94, 0                    }, /*                INTEGER shift  94 */
/* State 94 */
  {YYNOCODE,0,0}, /* Unused */
/* State 95 */
  {  51, 514, 0                    }, /*                INTEGER reduce 129 */
/* State 96 */
  {  51, 515, 0                    }, /*                INTEGER reduce 130 */
/* State 97 */
  {  12,  98, 0                    }, /*                     BY shift  98 */
/* State 98 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[ 821] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[ 830] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[ 834] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[ 835] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 103, &yyActionTable[ 836] }, /*                   expr shift  103 */
  { 149, 198, 0                    }, /*               sortitem shift  198 */
  { 150,  99, &yyActionTable[ 837] }, /*               sortlist shift  99 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  88,  29, &yyActionTable[ 842] }, /*                   TEMP shift  29 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  { 122,  75, &yyActionTable[ 844] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[ 848] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {  63, 176, &yyActionTable[ 849] }, /*                  MINUS shift  176 */
/* State 99 */
  {  16, 100, 0                    }, /*                  COMMA shift  100 */
/* State 100 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[ 854] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[ 863] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[ 867] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[ 868] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 103, &yyActionTable[ 869] }, /*                   expr shift  103 */
  { 149, 101, 0                    }, /*               sortitem shift  101 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  88,  29, &yyActionTable[ 870] }, /*                   TEMP shift  29 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  { 122,  75, &yyActionTable[ 875] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[ 877] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[ 881] }, /*                  MINUS shift  176 */
/* State 101 */
  {  27,  68, 0                    }, /*                   DESC shift  68 */
  {YYNOCODE,0,0}, /* Unused */
  {   6,  67, 0                    }, /*                    ASC shift  67 */
  { 151, 102, &yyActionTable[ 884] }, /*              sortorder shift  102 */
/* State 102 */
  {YYNOCODE,0,0}, /* Unused */
/* State 103 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[ 892] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[ 896] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[ 894] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[ 899] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[ 901] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[ 902] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[ 903] }, /*                  SLASH shift  147 */
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
  {  65, 172, &yyActionTable[ 923] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[ 932] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[ 936] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[ 937] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 111, &yyActionTable[ 938] }, /*                   expr shift  111 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[ 939] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[ 942] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[ 944] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[ 946] }, /*                  MINUS shift  176 */
/* State 105 */
  {YYNOCODE,0,0}, /* Unused */
/* State 106 */
  {  29, 107, 0                    }, /*                    DOT shift  107 */
/* State 107 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[ 957] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[ 960] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[ 963] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[ 965] }, /*                     id shift  37 */
  { 123, 108, &yyActionTable[ 966] }, /*                    ids shift  108 */
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
  {  65, 136, &yyActionTable[ 993] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {  40, 120, &yyActionTable[ 995] }, /*                     GE shift  120 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  43, 116, &yyActionTable[1000] }, /*                     GT shift  116 */
  {  72, 141, &yyActionTable[ 994] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[ 996] }, /*                   GLOB shift  139 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  75, 149, &yyActionTable[ 997] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[1002] }, /*                  SLASH shift  147 */
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
  {  65, 172, &yyActionTable[1024] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1033] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1037] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1038] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 113, &yyActionTable[1039] }, /*                   expr shift  113 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1040] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1043] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1045] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1047] }, /*                  MINUS shift  176 */
/* State 113 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[1057] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[1060] }, /*                     GE shift  120 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  72, 141, &yyActionTable[1059] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[1061] }, /*                   GLOB shift  139 */
  {  43, 116, &yyActionTable[1066] }, /*                     GT shift  116 */
  {  75, 149, &yyActionTable[1064] }, /*                    REM shift  149 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[1067] }, /*                  SLASH shift  147 */
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
  {  65, 172, &yyActionTable[1088] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1097] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1101] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1102] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 115, &yyActionTable[1103] }, /*                   expr shift  115 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1104] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1107] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1109] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1111] }, /*                  MINUS shift  176 */
/* State 115 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  83, 147, &yyActionTable[1118] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1119] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, &yyActionTable[1120] }, /*                 RSHIFT shift  132 */
/* State 116 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1136] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1145] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1149] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1150] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 117, &yyActionTable[1151] }, /*                   expr shift  117 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1152] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1155] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1157] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1159] }, /*                  MINUS shift  176 */
/* State 117 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  83, 147, &yyActionTable[1166] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1167] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, &yyActionTable[1168] }, /*                 RSHIFT shift  132 */
/* State 118 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1184] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1193] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1197] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1198] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 119, &yyActionTable[1199] }, /*                   expr shift  119 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1200] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1203] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1205] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1207] }, /*                  MINUS shift  176 */
/* State 119 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  83, 147, &yyActionTable[1214] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1215] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, &yyActionTable[1216] }, /*                 RSHIFT shift  132 */
/* State 120 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1232] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1241] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1245] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1246] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 121, &yyActionTable[1247] }, /*                   expr shift  121 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1248] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1251] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1253] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1255] }, /*                  MINUS shift  176 */
/* State 121 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  83, 147, &yyActionTable[1262] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1263] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, &yyActionTable[1264] }, /*                 RSHIFT shift  132 */
/* State 122 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1280] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1289] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1293] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1294] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 123, &yyActionTable[1295] }, /*                   expr shift  123 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1296] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1299] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1301] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1303] }, /*                  MINUS shift  176 */
/* State 123 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  40, 120, 0                    }, /*                     GE shift  120 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  83, 147, &yyActionTable[1310] }, /*                  SLASH shift  147 */
  {  43, 116, &yyActionTable[1316] }, /*                     GT shift  116 */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  72, 141, &yyActionTable[1311] }, /*                   PLUS shift  141 */
  {  57, 118, &yyActionTable[1312] }, /*                     LE shift  118 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1314] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  79, 132, &yyActionTable[1317] }, /*                 RSHIFT shift  132 */
/* State 124 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1328] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1337] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1341] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1342] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 125, &yyActionTable[1343] }, /*                   expr shift  125 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1344] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1347] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1349] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1351] }, /*                  MINUS shift  176 */
/* State 125 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  40, 120, 0                    }, /*                     GE shift  120 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  83, 147, &yyActionTable[1358] }, /*                  SLASH shift  147 */
  {  43, 116, &yyActionTable[1364] }, /*                     GT shift  116 */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  72, 141, &yyActionTable[1359] }, /*                   PLUS shift  141 */
  {  57, 118, &yyActionTable[1360] }, /*                     LE shift  118 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1362] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  79, 132, &yyActionTable[1365] }, /*                 RSHIFT shift  132 */
/* State 126 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1376] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1385] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1389] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1390] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 127, &yyActionTable[1391] }, /*                   expr shift  127 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1392] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1395] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1397] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1399] }, /*                  MINUS shift  176 */
/* State 127 */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {  75, 149, &yyActionTable[1408] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  83, 147, &yyActionTable[1407] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 128 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1416] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1425] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1429] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1430] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 129, &yyActionTable[1431] }, /*                   expr shift  129 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1432] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1435] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1437] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1439] }, /*                  MINUS shift  176 */
/* State 129 */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {  75, 149, &yyActionTable[1448] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  83, 147, &yyActionTable[1447] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 130 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1456] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1465] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1469] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1470] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 131, &yyActionTable[1471] }, /*                   expr shift  131 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1472] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1475] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1477] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1479] }, /*                  MINUS shift  176 */
/* State 131 */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {  75, 149, &yyActionTable[1488] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  83, 147, &yyActionTable[1487] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 132 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1496] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1505] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1509] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1510] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 133, &yyActionTable[1511] }, /*                   expr shift  133 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1512] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1515] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1517] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1519] }, /*                  MINUS shift  176 */
/* State 133 */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {  75, 149, &yyActionTable[1528] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  83, 147, &yyActionTable[1527] }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 134 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1536] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1545] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1549] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1550] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 135, &yyActionTable[1551] }, /*                   expr shift  135 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1552] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1555] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1557] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1559] }, /*                  MINUS shift  176 */
/* State 135 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  40, 120, 0                    }, /*                     GE shift  120 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  83, 147, &yyActionTable[1566] }, /*                  SLASH shift  147 */
  {  43, 116, &yyActionTable[1572] }, /*                     GT shift  116 */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  72, 141, &yyActionTable[1567] }, /*                   PLUS shift  141 */
  {  57, 118, &yyActionTable[1568] }, /*                     LE shift  118 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1570] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  79, 132, &yyActionTable[1573] }, /*                 RSHIFT shift  132 */
/* State 136 */
  {  48, 192, &yyActionTable[1586] }, /*                     IN shift  192 */
  {  41, 185, 0                    }, /*                   GLOB shift  185 */
  {  58, 137, 0                    }, /*                   LIKE shift  137 */
  {  67, 187, 0                    }, /*                   NULL shift  187 */
  {   8, 188, 0                    }, /*                BETWEEN shift  188 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
/* State 137 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1592] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1601] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1605] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1606] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 138, &yyActionTable[1607] }, /*                   expr shift  138 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1608] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1611] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1613] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1615] }, /*                  MINUS shift  176 */
/* State 138 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[1625] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {  40, 120, &yyActionTable[1627] }, /*                     GE shift  120 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  43, 116, &yyActionTable[1632] }, /*                     GT shift  116 */
  {  72, 141, &yyActionTable[1626] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[1628] }, /*                   GLOB shift  139 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  75, 149, &yyActionTable[1629] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[1634] }, /*                  SLASH shift  147 */
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
  {  65, 172, &yyActionTable[1656] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1665] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1669] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1670] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 140, &yyActionTable[1671] }, /*                   expr shift  140 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1672] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1675] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1677] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1679] }, /*                  MINUS shift  176 */
/* State 140 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  40, 120, 0                    }, /*                     GE shift  120 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  83, 147, &yyActionTable[1686] }, /*                  SLASH shift  147 */
  {  43, 116, &yyActionTable[1692] }, /*                     GT shift  116 */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  72, 141, &yyActionTable[1687] }, /*                   PLUS shift  141 */
  {  57, 118, &yyActionTable[1688] }, /*                     LE shift  118 */
  {YYNOCODE,0,0}, /* Unused */
  {  75, 149, &yyActionTable[1690] }, /*                    REM shift  149 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  79, 132, &yyActionTable[1693] }, /*                 RSHIFT shift  132 */
/* State 141 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1704] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1713] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1717] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1718] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 142, &yyActionTable[1719] }, /*                   expr shift  142 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1720] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1723] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1725] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1727] }, /*                  MINUS shift  176 */
/* State 142 */
  {  75, 149, &yyActionTable[1736] }, /*                    REM shift  149 */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  83, 147, &yyActionTable[1734] }, /*                  SLASH shift  147 */
/* State 143 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1740] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1749] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1753] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1754] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 144, &yyActionTable[1755] }, /*                   expr shift  144 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1756] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1759] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1761] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1763] }, /*                  MINUS shift  176 */
/* State 144 */
  {  75, 149, &yyActionTable[1772] }, /*                    REM shift  149 */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  83, 147, &yyActionTable[1770] }, /*                  SLASH shift  147 */
/* State 145 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1776] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1785] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1789] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1790] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 146, &yyActionTable[1791] }, /*                   expr shift  146 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1792] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1795] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1797] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1799] }, /*                  MINUS shift  176 */
/* State 146 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
/* State 147 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1809] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1818] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1822] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1823] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 148, &yyActionTable[1824] }, /*                   expr shift  148 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1825] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1828] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1830] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1832] }, /*                  MINUS shift  176 */
/* State 148 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
/* State 149 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1842] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1851] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1855] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1856] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 150, &yyActionTable[1857] }, /*                   expr shift  150 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1858] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1861] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1863] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1865] }, /*                  MINUS shift  176 */
/* State 150 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
/* State 151 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[1875] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1884] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1888] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1889] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 152, &yyActionTable[1890] }, /*                   expr shift  152 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1891] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1894] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1896] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1898] }, /*                  MINUS shift  176 */
/* State 152 */
  {YYNOCODE,0,0}, /* Unused */
/* State 153 */
  {YYNOCODE,0,0}, /* Unused */
/* State 154 */
  {  65, 156, 0                    }, /*                    NOT shift  156 */
  {  67, 155, &yyActionTable[1907] }, /*                   NULL shift  155 */
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
  {  65, 172, &yyActionTable[1915] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1924] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1928] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1929] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 160, &yyActionTable[1930] }, /*                   expr shift  160 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1931] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1934] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[1936] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[1938] }, /*                  MINUS shift  176 */
/* State 160 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[1948] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 161, 0                    }, /*                    AND shift  161 */
  {  40, 120, &yyActionTable[1952] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[1950] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[1955] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[1957] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[1958] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[1959] }, /*                  SLASH shift  147 */
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
  {  65, 172, &yyActionTable[1979] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[1988] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[1992] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[1993] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 162, &yyActionTable[1994] }, /*                   expr shift  162 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[1995] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[1998] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2000] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2002] }, /*                  MINUS shift  176 */
/* State 162 */
  {   0, 573, 0                    }, /*                      $ reduce 188 */
  {   1, 573, 0                    }, /*                  ABORT reduce 188 */
  {   4, 541, 0                    }, /*                    AND reduce 156 */
  {  70, 541, 0                    }, /*                     OR reduce 156 */
  {   4, 573, &yyActionTable[2011] }, /*                    AND reduce 188 */
  {   5, 573, 0                    }, /*                     AS reduce 188 */
  {   6, 573, 0                    }, /*                    ASC reduce 188 */
  {   7, 573, 0                    }, /*                  BEGIN reduce 188 */
  {   8, 573, 0                    }, /*                BETWEEN reduce 188 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {YYNOCODE,0,0}, /* Unused */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {YYNOCODE,0,0}, /* Unused */
  {  13, 573, 0                    }, /*                  CHECK reduce 188 */
  {  14, 573, 0                    }, /*                CLUSTER reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {  16, 573, 0                    }, /*                  COMMA reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  20, 573, 0                    }, /*               CONFLICT reduce 188 */
  {  21, 573, 0                    }, /*             CONSTRAINT reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  26, 573, 0                    }, /*             DELIMITERS reduce 188 */
  {  27, 573, 0                    }, /*                   DESC reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31, 573, 0                    }, /*                    END reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {  33, 573, 0                    }, /*                     EQ reduce 188 */
  {  34, 573, 0                    }, /*                 EXCEPT reduce 188 */
  {  35, 573, 0                    }, /*                EXPLAIN reduce 188 */
  {  36, 573, 0                    }, /*                   FAIL reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {  38, 573, 0                    }, /*                   FROM reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {  40, 120, 0                    }, /*                     GE shift  120 */
  {  41, 573, 0                    }, /*                   GLOB reduce 188 */
  {  42, 573, 0                    }, /*                  GROUP reduce 188 */
  {  43, 116, 0                    }, /*                     GT shift  116 */
  {  44, 573, 0                    }, /*                 HAVING reduce 188 */
  {  45, 573, 0                    }, /*                     ID reduce 188 */
  {  46, 573, 0                    }, /*                 IGNORE reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {  48, 573, 0                    }, /*                     IN reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  52, 573, 0                    }, /*              INTERSECT reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {  54, 573, 0                    }, /*                     IS reduce 188 */
  {  55, 573, 0                    }, /*                 ISNULL reduce 188 */
  {  56, 573, 0                    }, /*                    KEY reduce 188 */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 573, 0                    }, /*                   LIKE reduce 188 */
  {  59, 573, 0                    }, /*                  LIMIT reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  64, 573, 0                    }, /*                     NE reduce 188 */
  {  65, 573, 0                    }, /*                    NOT reduce 188 */
  {  66, 573, 0                    }, /*                NOTNULL reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {  68, 573, 0                    }, /*                 OFFSET reduce 188 */
  {  69, 573, 0                    }, /*                     ON reduce 188 */
  {  70, 573, &yyActionTable[2012] }, /*                     OR reduce 188 */
  {  71, 573, 0                    }, /*                  ORDER reduce 188 */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {  73, 573, 0                    }, /*                 PRAGMA reduce 188 */
  {  74, 573, 0                    }, /*                PRIMARY reduce 188 */
  {  75, 149, 0                    }, /*                    REM shift  149 */
  {  76, 573, 0                    }, /*                REPLACE reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {  78, 573, 0                    }, /*                     RP reduce 188 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {YYNOCODE,0,0}, /* Unused */
  {  81, 573, 0                    }, /*                   SEMI reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, 0                    }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  86, 573, 0                    }, /*                 STRING reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {  88, 573, 0                    }, /*                   TEMP reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  92, 573, 0                    }, /*                  UNION reduce 188 */
  {  93, 573, 0                    }, /*                 UNIQUE reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  96, 573, 0                    }, /*                 VACUUM reduce 188 */
  {YYNOCODE,0,0}, /* Unused */
  {  98, 573, 0                    }, /*                  WHERE reduce 188 */
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
  {  65, 172, &yyActionTable[2138] }, /*                    NOT shift  172 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  67, 105, 0                    }, /*                   NULL shift  105 */
  {  68,  30, 0                    }, /*                 OFFSET shift  30 */
  {YYNOCODE,0,0}, /* Unused */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  { 137,  78, &yyActionTable[2140] }, /*              oneselect shift  78 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {YYNOCODE,0,0}, /* Unused */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {YYNOCODE,0,0}, /* Unused */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {YYNOCODE,0,0}, /* Unused */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  { 145, 165, 0                    }, /*                 select shift  165 */
  {YYNOCODE,0,0}, /* Unused */
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
  {  52, 168, 0                    }, /*              INTERSECT shift  168 */
  {  78, 170, 0                    }, /*                     RP shift  170 */
  {  34, 169, 0                    }, /*                 EXCEPT shift  169 */
  {YYNOCODE,0,0}, /* Unused */
  {  92, 166, &yyActionTable[2202] }, /*                  UNION shift  166 */
  {YYNOCODE,0,0}, /* Unused */
  { 134,  80, &yyActionTable[2203] }, /*         multiselect_op shift  80 */
  {YYNOCODE,0,0}, /* Unused */
/* State 166 */
  {  80, 477, 0                    }, /*                 SELECT reduce 92 */
  {   3, 167, 0                    }, /*                    ALL shift  167 */
/* State 167 */
  {  80, 478, 0                    }, /*                 SELECT reduce 93 */
/* State 168 */
  {  80, 479, 0                    }, /*                 SELECT reduce 94 */
/* State 169 */
  {  80, 480, 0                    }, /*                 SELECT reduce 95 */
/* State 170 */
  {YYNOCODE,0,0}, /* Unused */
/* State 171 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[2219] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[2223] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[2221] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[2226] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[2228] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[2229] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[2230] }, /*                  SLASH shift  147 */
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
  {  65, 172, &yyActionTable[2250] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2259] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2263] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2264] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 173, &yyActionTable[2265] }, /*                   expr shift  173 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2266] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2269] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2271] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2273] }, /*                  MINUS shift  176 */
/* State 173 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[2283] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {  40, 120, &yyActionTable[2285] }, /*                     GE shift  120 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  43, 116, &yyActionTable[2290] }, /*                     GT shift  116 */
  {  72, 141, &yyActionTable[2284] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[2286] }, /*                   GLOB shift  139 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  75, 149, &yyActionTable[2287] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[2292] }, /*                  SLASH shift  147 */
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
  {  65, 172, &yyActionTable[2314] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2323] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2327] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2328] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 175, &yyActionTable[2329] }, /*                   expr shift  175 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2330] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2333] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2335] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2337] }, /*                  MINUS shift  176 */
/* State 175 */
  {YYNOCODE,0,0}, /* Unused */
/* State 176 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2347] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2356] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2360] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2361] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 177, &yyActionTable[2362] }, /*                   expr shift  177 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2363] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2366] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2368] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2370] }, /*                  MINUS shift  176 */
/* State 177 */
  {YYNOCODE,0,0}, /* Unused */
/* State 178 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2380] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2389] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2393] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2394] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 179, &yyActionTable[2395] }, /*                   expr shift  179 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2396] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2399] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2401] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2403] }, /*                  MINUS shift  176 */
/* State 179 */
  {YYNOCODE,0,0}, /* Unused */
/* State 180 */
  {  78, 181, &yyActionTable[2412] }, /*                     RP shift  181 */
  {  16, 182, 0                    }, /*                  COMMA shift  182 */
/* State 181 */
  {YYNOCODE,0,0}, /* Unused */
/* State 182 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2416] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2425] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2429] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2430] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 171, &yyActionTable[2431] }, /*                   expr shift  171 */
  { 117, 183, 0                    }, /*               expritem shift  183 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  88,  29, &yyActionTable[2432] }, /*                   TEMP shift  29 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  { 122,  75, &yyActionTable[2437] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2439] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2443] }, /*                  MINUS shift  176 */
/* State 183 */
  {YYNOCODE,0,0}, /* Unused */
/* State 184 */
  {YYNOCODE,0,0}, /* Unused */
/* State 185 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2450] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2459] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2463] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2464] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 186, &yyActionTable[2465] }, /*                   expr shift  186 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2466] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2469] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2471] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2473] }, /*                  MINUS shift  176 */
/* State 186 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[2483] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {  40, 120, &yyActionTable[2485] }, /*                     GE shift  120 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  43, 116, &yyActionTable[2490] }, /*                     GT shift  116 */
  {  72, 141, &yyActionTable[2484] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[2486] }, /*                   GLOB shift  139 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  75, 149, &yyActionTable[2487] }, /*                    REM shift  149 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[2492] }, /*                  SLASH shift  147 */
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
  {  65, 172, &yyActionTable[2515] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2524] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2528] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2529] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 189, &yyActionTable[2530] }, /*                   expr shift  189 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2531] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2534] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2536] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2538] }, /*                  MINUS shift  176 */
/* State 189 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[2548] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 190, 0                    }, /*                    AND shift  190 */
  {  40, 120, &yyActionTable[2552] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[2550] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[2555] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[2557] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[2558] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[2559] }, /*                  SLASH shift  147 */
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
  {  65, 172, &yyActionTable[2579] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2588] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2592] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2593] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 191, &yyActionTable[2594] }, /*                   expr shift  191 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2595] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2598] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2600] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2602] }, /*                  MINUS shift  176 */
/* State 191 */
  {   0, 574, 0                    }, /*                      $ reduce 189 */
  {   1, 574, 0                    }, /*                  ABORT reduce 189 */
  {   4, 541, 0                    }, /*                    AND reduce 156 */
  {  70, 541, 0                    }, /*                     OR reduce 156 */
  {   4, 574, &yyActionTable[2611] }, /*                    AND reduce 189 */
  {   5, 574, 0                    }, /*                     AS reduce 189 */
  {   6, 574, 0                    }, /*                    ASC reduce 189 */
  {   7, 574, 0                    }, /*                  BEGIN reduce 189 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {YYNOCODE,0,0}, /* Unused */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {YYNOCODE,0,0}, /* Unused */
  {  13, 574, 0                    }, /*                  CHECK reduce 189 */
  {  14, 574, 0                    }, /*                CLUSTER reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {  16, 574, 0                    }, /*                  COMMA reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  20, 574, 0                    }, /*               CONFLICT reduce 189 */
  {  21, 574, 0                    }, /*             CONSTRAINT reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  26, 574, 0                    }, /*             DELIMITERS reduce 189 */
  {  27, 574, 0                    }, /*                   DESC reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31, 574, 0                    }, /*                    END reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {  34, 574, 0                    }, /*                 EXCEPT reduce 189 */
  {  35, 574, 0                    }, /*                EXPLAIN reduce 189 */
  {  36, 574, 0                    }, /*                   FAIL reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {  38, 574, 0                    }, /*                   FROM reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {  40, 120, 0                    }, /*                     GE shift  120 */
  {  41, 139, 0                    }, /*                   GLOB shift  139 */
  {  42, 574, 0                    }, /*                  GROUP reduce 189 */
  {  43, 116, 0                    }, /*                     GT shift  116 */
  {  44, 574, 0                    }, /*                 HAVING reduce 189 */
  {  45, 574, 0                    }, /*                     ID reduce 189 */
  {  46, 574, 0                    }, /*                 IGNORE reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  52, 574, 0                    }, /*              INTERSECT reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {  56, 574, 0                    }, /*                    KEY reduce 189 */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {  59, 574, 0                    }, /*                  LIMIT reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, 0                    }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {YYNOCODE,0,0}, /* Unused */
  {  68, 574, 0                    }, /*                 OFFSET reduce 189 */
  {  69, 574, 0                    }, /*                     ON reduce 189 */
  {  70, 574, &yyActionTable[2612] }, /*                     OR reduce 189 */
  {  71, 574, 0                    }, /*                  ORDER reduce 189 */
  {  72, 141, 0                    }, /*                   PLUS shift  141 */
  {  73, 574, 0                    }, /*                 PRAGMA reduce 189 */
  {  74, 574, 0                    }, /*                PRIMARY reduce 189 */
  {  75, 149, 0                    }, /*                    REM shift  149 */
  {  76, 574, 0                    }, /*                REPLACE reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {  78, 574, 0                    }, /*                     RP reduce 189 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {YYNOCODE,0,0}, /* Unused */
  {  81, 574, 0                    }, /*                   SEMI reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, 0                    }, /*                  SLASH shift  147 */
  {YYNOCODE,0,0}, /* Unused */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  86, 574, 0                    }, /*                 STRING reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {  88, 574, 0                    }, /*                   TEMP reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  92, 574, 0                    }, /*                  UNION reduce 189 */
  {  93, 574, 0                    }, /*                 UNIQUE reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  96, 574, 0                    }, /*                 VACUUM reduce 189 */
  {YYNOCODE,0,0}, /* Unused */
  {  98, 574, 0                    }, /*                  WHERE reduce 189 */
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
  {  65, 172, &yyActionTable[2738] }, /*                    NOT shift  172 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  67, 105, 0                    }, /*                   NULL shift  105 */
  {  68,  30, 0                    }, /*                 OFFSET shift  30 */
  {YYNOCODE,0,0}, /* Unused */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  { 137,  78, &yyActionTable[2740] }, /*              oneselect shift  78 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {YYNOCODE,0,0}, /* Unused */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {YYNOCODE,0,0}, /* Unused */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {YYNOCODE,0,0}, /* Unused */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  { 145, 194, 0                    }, /*                 select shift  194 */
  {YYNOCODE,0,0}, /* Unused */
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
  {  52, 168, 0                    }, /*              INTERSECT shift  168 */
  {  78, 195, 0                    }, /*                     RP shift  195 */
  {  34, 169, 0                    }, /*                 EXCEPT shift  169 */
  {YYNOCODE,0,0}, /* Unused */
  {  92, 166, &yyActionTable[2802] }, /*                  UNION shift  166 */
  {YYNOCODE,0,0}, /* Unused */
  { 134,  80, &yyActionTable[2803] }, /*         multiselect_op shift  80 */
  {YYNOCODE,0,0}, /* Unused */
/* State 195 */
  {YYNOCODE,0,0}, /* Unused */
/* State 196 */
  {  78, 197, &yyActionTable[2812] }, /*                     RP shift  197 */
  {  16, 182, 0                    }, /*                  COMMA shift  182 */
/* State 197 */
  {YYNOCODE,0,0}, /* Unused */
/* State 198 */
  {  27,  68, 0                    }, /*                   DESC shift  68 */
  {YYNOCODE,0,0}, /* Unused */
  {   6,  67, 0                    }, /*                    ASC shift  67 */
  { 151, 199, &yyActionTable[2814] }, /*              sortorder shift  199 */
/* State 199 */
  {YYNOCODE,0,0}, /* Unused */
/* State 200 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2821] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2830] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2834] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2835] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 201, &yyActionTable[2836] }, /*                   expr shift  201 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2837] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2840] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2842] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2844] }, /*                  MINUS shift  176 */
/* State 201 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[2854] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[2858] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[2856] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[2861] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[2863] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[2864] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[2865] }, /*                  SLASH shift  147 */
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
  {  65, 172, &yyActionTable[2886] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2895] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2899] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2900] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 171, &yyActionTable[2901] }, /*                   expr shift  171 */
  { 117, 184, 0                    }, /*               expritem shift  184 */
  { 118, 204, &yyActionTable[2902] }, /*               exprlist shift  204 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  88,  29, &yyActionTable[2907] }, /*                   TEMP shift  29 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  { 122,  75, &yyActionTable[2909] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2913] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {  63, 176, &yyActionTable[2914] }, /*                  MINUS shift  176 */
/* State 204 */
  {  16, 182, 0                    }, /*                  COMMA shift  182 */
/* State 205 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[2919] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[2928] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[2932] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[2933] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 206, &yyActionTable[2934] }, /*                   expr shift  206 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[2935] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[2938] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[2940] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[2942] }, /*                  MINUS shift  176 */
/* State 206 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[2952] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[2956] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[2954] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[2959] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[2961] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[2962] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[2963] }, /*                  SLASH shift  147 */
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
  { 152, 211, &yyActionTable[2983] }, /*             stl_prefix shift  211 */
  { 146, 209, 0                    }, /*             seltablist shift  209 */
/* State 209 */
  {  16, 210, 0                    }, /*                  COMMA shift  210 */
/* State 210 */
  {YYNOCODE,0,0}, /* Unused */
/* State 211 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[2988] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[2991] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[2994] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[2996] }, /*                     id shift  37 */
  { 123, 212, &yyActionTable[2997] }, /*                    ids shift  212 */
  {  60, 216, 0                    }, /*                     LP shift  216 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 212 */
  {   0, 495, 0                    }, /*                      $ reduce 110 */
  {   1, 490, 0                    }, /*                  ABORT reduce 105 */
  {   7, 490, 0                    }, /*                  BEGIN reduce 105 */
  {  14, 490, 0                    }, /*                CLUSTER reduce 105 */
  {  68, 490, 0                    }, /*                 OFFSET reduce 105 */
  {   5, 213, 0                    }, /*                     AS shift  213 */
  {   6, 490, 0                    }, /*                    ASC reduce 105 */
  {  71, 495, &yyActionTable[3020] }, /*                  ORDER reduce 110 */
  {  34, 495, 0                    }, /*                 EXCEPT reduce 110 */
  {  73, 490, 0                    }, /*                 PRAGMA reduce 105 */
  {  35, 490, 0                    }, /*                EXPLAIN reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {  76, 490, 0                    }, /*                REPLACE reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {  78, 495, &yyActionTable[3021] }, /*                     RP reduce 110 */
  {YYNOCODE,0,0}, /* Unused */
  {  16, 495, 0                    }, /*                  COMMA reduce 110 */
  {  81, 495, 0                    }, /*                   SEMI reduce 110 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20, 490, 0                    }, /*               CONFLICT reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {  86, 490, 0                    }, /*                 STRING reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {  88, 490, 0                    }, /*                   TEMP reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {  26, 490, 0                    }, /*             DELIMITERS reduce 105 */
  {  27, 490, 0                    }, /*                   DESC reduce 105 */
  {  92, 495, 0                    }, /*                  UNION reduce 110 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31, 490, 0                    }, /*                    END reduce 105 */
  {  96, 490, 0                    }, /*                 VACUUM reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {  98, 495, &yyActionTable[3026] }, /*                  WHERE reduce 110 */
  {  99, 214, &yyActionTable[3028] }, /*                     as shift  214 */
  {  36, 490, 0                    }, /*                   FAIL reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  42, 495, 0                    }, /*                  GROUP reduce 110 */
  {YYNOCODE,0,0}, /* Unused */
  {  44, 495, 0                    }, /*                 HAVING reduce 110 */
  {  45, 490, 0                    }, /*                     ID reduce 105 */
  {  46, 490, 0                    }, /*                 IGNORE reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  52, 495, 0                    }, /*              INTERSECT reduce 110 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  56, 490, 0                    }, /*                    KEY reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  59, 495, 0                    }, /*                  LIMIT reduce 110 */
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
  {  68,  30, &yyActionTable[3085] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3088] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3091] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3093] }, /*                     id shift  37 */
  { 123, 215, &yyActionTable[3094] }, /*                    ids shift  215 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 215 */
  {YYNOCODE,0,0}, /* Unused */
/* State 216 */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  { 145, 217, &yyActionTable[3118] }, /*                 select shift  217 */
  { 137,  78, 0                    }, /*              oneselect shift  78 */
  {YYNOCODE,0,0}, /* Unused */
/* State 217 */
  {  52, 168, 0                    }, /*              INTERSECT shift  168 */
  {  78, 218, 0                    }, /*                     RP shift  218 */
  {  34, 169, 0                    }, /*                 EXCEPT shift  169 */
  {YYNOCODE,0,0}, /* Unused */
  {  92, 166, &yyActionTable[3120] }, /*                  UNION shift  166 */
  {YYNOCODE,0,0}, /* Unused */
  { 134,  80, &yyActionTable[3121] }, /*         multiselect_op shift  80 */
  {YYNOCODE,0,0}, /* Unused */
/* State 218 */
  {   0, 497, 0                    }, /*                      $ reduce 112 */
  {   1, 490, 0                    }, /*                  ABORT reduce 105 */
  {   7, 490, 0                    }, /*                  BEGIN reduce 105 */
  {  14, 490, 0                    }, /*                CLUSTER reduce 105 */
  {  68, 490, 0                    }, /*                 OFFSET reduce 105 */
  {   5, 213, 0                    }, /*                     AS shift  213 */
  {   6, 490, 0                    }, /*                    ASC reduce 105 */
  {  71, 497, &yyActionTable[3130] }, /*                  ORDER reduce 112 */
  {  34, 497, 0                    }, /*                 EXCEPT reduce 112 */
  {  73, 490, 0                    }, /*                 PRAGMA reduce 105 */
  {  35, 490, 0                    }, /*                EXPLAIN reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {  76, 490, 0                    }, /*                REPLACE reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {  78, 497, &yyActionTable[3131] }, /*                     RP reduce 112 */
  {YYNOCODE,0,0}, /* Unused */
  {  16, 497, 0                    }, /*                  COMMA reduce 112 */
  {  81, 497, 0                    }, /*                   SEMI reduce 112 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20, 490, 0                    }, /*               CONFLICT reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {  86, 490, 0                    }, /*                 STRING reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {  88, 490, 0                    }, /*                   TEMP reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {  26, 490, 0                    }, /*             DELIMITERS reduce 105 */
  {  27, 490, 0                    }, /*                   DESC reduce 105 */
  {  92, 497, 0                    }, /*                  UNION reduce 112 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31, 490, 0                    }, /*                    END reduce 105 */
  {  96, 490, 0                    }, /*                 VACUUM reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {  98, 497, &yyActionTable[3136] }, /*                  WHERE reduce 112 */
  {  99, 219, &yyActionTable[3138] }, /*                     as shift  219 */
  {  36, 490, 0                    }, /*                   FAIL reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  42, 497, 0                    }, /*                  GROUP reduce 112 */
  {YYNOCODE,0,0}, /* Unused */
  {  44, 497, 0                    }, /*                 HAVING reduce 112 */
  {  45, 490, 0                    }, /*                     ID reduce 105 */
  {  46, 490, 0                    }, /*                 IGNORE reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  52, 497, 0                    }, /*              INTERSECT reduce 112 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  56, 490, 0                    }, /*                    KEY reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  59, 497, 0                    }, /*                  LIMIT reduce 112 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
/* State 219 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3194] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3197] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3200] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3202] }, /*                     id shift  37 */
  { 123, 220, &yyActionTable[3203] }, /*                    ids shift  220 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 220 */
  {YYNOCODE,0,0}, /* Unused */
/* State 221 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[3227] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[3236] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[3240] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[3241] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 222, &yyActionTable[3242] }, /*                   expr shift  222 */
  {  85, 225, 0                    }, /*                   STAR shift  225 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  88,  29, &yyActionTable[3243] }, /*                   TEMP shift  29 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  { 122,  75, &yyActionTable[3248] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[3250] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[3254] }, /*                  MINUS shift  176 */
/* State 222 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[3260] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {   1, 490, 0                    }, /*                  ABORT reduce 105 */
  {  68, 490, &yyActionTable[3267] }, /*                 OFFSET reduce 105 */
  {   5, 213, 0                    }, /*                     AS shift  213 */
  {  70, 112, &yyActionTable[3270] }, /*                     OR shift  112 */
  {   7, 490, 0                    }, /*                  BEGIN reduce 105 */
  {  72, 141, &yyActionTable[3274] }, /*                   PLUS shift  141 */
  {  73, 490, &yyActionTable[3275] }, /*                 PRAGMA reduce 105 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  75, 149, &yyActionTable[3280] }, /*                    REM shift  149 */
  {  76, 490, 0                    }, /*                REPLACE reduce 105 */
  {   6, 490, 0                    }, /*                    ASC reduce 105 */
  {  14, 490, 0                    }, /*                CLUSTER reduce 105 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  16, 487, 0                    }, /*                  COMMA reduce 102 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  83, 147, &yyActionTable[3282] }, /*                  SLASH shift  147 */
  {  20, 490, 0                    }, /*               CONFLICT reduce 105 */
  {  85, 145, 0                    }, /*                   STAR shift  145 */
  {  86, 490, 0                    }, /*                 STRING reduce 105 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  88, 490, 0                    }, /*                   TEMP reduce 105 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  26, 490, 0                    }, /*             DELIMITERS reduce 105 */
  {  27, 490, 0                    }, /*                   DESC reduce 105 */
  {  35, 490, 0                    }, /*                EXPLAIN reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31, 490, 0                    }, /*                    END reduce 105 */
  {  96, 490, 0                    }, /*                 VACUUM reduce 105 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {YYNOCODE,0,0}, /* Unused */
  {  99, 223, &yyActionTable[3285] }, /*                     as shift  223 */
  {  36, 490, 0                    }, /*                   FAIL reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {  38, 487, 0                    }, /*                   FROM reduce 102 */
  {YYNOCODE,0,0}, /* Unused */
  {  40, 120, 0                    }, /*                     GE shift  120 */
  {  41, 139, 0                    }, /*                   GLOB shift  139 */
  {YYNOCODE,0,0}, /* Unused */
  {  43, 116, 0                    }, /*                     GT shift  116 */
  {YYNOCODE,0,0}, /* Unused */
  {  45, 490, 0                    }, /*                     ID reduce 105 */
  {  46, 490, 0                    }, /*                 IGNORE reduce 105 */
  {YYNOCODE,0,0}, /* Unused */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  54, 154, 0                    }, /*                     IS shift  154 */
  {  55, 153, 0                    }, /*                 ISNULL shift  153 */
  {  56, 490, 0                    }, /*                    KEY reduce 105 */
  {  57, 118, 0                    }, /*                     LE shift  118 */
  {  58, 134, 0                    }, /*                   LIKE shift  134 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  61, 130, 0                    }, /*                 LSHIFT shift  130 */
  {  62, 114, 0                    }, /*                     LT shift  114 */
  {  63, 143, 0                    }, /*                  MINUS shift  143 */
/* State 223 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3323] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3326] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3329] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3331] }, /*                     id shift  37 */
  { 123, 224, &yyActionTable[3332] }, /*                    ids shift  224 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 224 */
  {YYNOCODE,0,0}, /* Unused */
/* State 225 */
  {YYNOCODE,0,0}, /* Unused */
/* State 226 */
  {YYNOCODE,0,0}, /* Unused */
/* State 227 */
  {YYNOCODE,0,0}, /* Unused */
/* State 228 */
  {YYNOCODE,0,0}, /* Unused */
/* State 229 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[3361] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[3365] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[3363] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[3368] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[3370] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[3371] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  78, 230, 0                    }, /*                     RP shift  230 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[3375] }, /*                  SLASH shift  147 */
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
/* State 230 */
  {YYNOCODE,0,0}, /* Unused */
/* State 231 */
  {  78, 232, &yyActionTable[3392] }, /*                     RP shift  232 */
  {  16, 182, 0                    }, /*                  COMMA shift  182 */
/* State 232 */
  {YYNOCODE,0,0}, /* Unused */
/* State 233 */
  {  78, 234, 0                    }, /*                     RP shift  234 */
/* State 234 */
  {YYNOCODE,0,0}, /* Unused */
/* State 235 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[3399] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[3403] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[3401] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[3406] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[3408] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[3409] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  78, 236, 0                    }, /*                     RP shift  236 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[3413] }, /*                  SLASH shift  147 */
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
/* State 236 */
  { 136, 237, 0                    }, /*                 onconf shift  237 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
/* State 237 */
  {YYNOCODE,0,0}, /* Unused */
/* State 238 */
  {YYNOCODE,0,0}, /* Unused */
/* State 239 */
  {  72, 243, 0                    }, /*                   PLUS shift  243 */
  {  51, 242, 0                    }, /*                INTEGER shift  242 */
  {  37, 249, 0                    }, /*                  FLOAT shift  249 */
  {  67, 250, &yyActionTable[3433] }, /*                   NULL shift  250 */
  {YYNOCODE,0,0}, /* Unused */
  {  45, 241, &yyActionTable[3434] }, /*                     ID shift  241 */
  {  86, 240, 0                    }, /*                 STRING shift  240 */
  {  63, 246, 0                    }, /*                  MINUS shift  246 */
/* State 240 */
  {YYNOCODE,0,0}, /* Unused */
/* State 241 */
  {YYNOCODE,0,0}, /* Unused */
/* State 242 */
  {YYNOCODE,0,0}, /* Unused */
/* State 243 */
  {  37, 245, 0                    }, /*                  FLOAT shift  245 */
  {  51, 244, &yyActionTable[3443] }, /*                INTEGER shift  244 */
/* State 244 */
  {YYNOCODE,0,0}, /* Unused */
/* State 245 */
  {YYNOCODE,0,0}, /* Unused */
/* State 246 */
  {  37, 248, 0                    }, /*                  FLOAT shift  248 */
  {  51, 247, &yyActionTable[3447] }, /*                INTEGER shift  247 */
/* State 247 */
  {YYNOCODE,0,0}, /* Unused */
/* State 248 */
  {YYNOCODE,0,0}, /* Unused */
/* State 249 */
  {YYNOCODE,0,0}, /* Unused */
/* State 250 */
  {YYNOCODE,0,0}, /* Unused */
/* State 251 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3455] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3458] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3461] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3463] }, /*                     id shift  37 */
  { 123, 263, &yyActionTable[3464] }, /*                    ids shift  263 */
  {  60, 252, 0                    }, /*                     LP shift  252 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 252 */
  { 148, 253, &yyActionTable[3486] }, /*                 signed shift  253 */
  {  72, 259, 0                    }, /*                   PLUS shift  259 */
  {  51, 258, 0                    }, /*                INTEGER shift  258 */
  {  63, 261, &yyActionTable[3487] }, /*                  MINUS shift  261 */
/* State 253 */
  {  78, 254, &yyActionTable[3490] }, /*                     RP shift  254 */
  {  16, 255, 0                    }, /*                  COMMA shift  255 */
/* State 254 */
  {YYNOCODE,0,0}, /* Unused */
/* State 255 */
  { 148, 256, &yyActionTable[3493] }, /*                 signed shift  256 */
  {  72, 259, 0                    }, /*                   PLUS shift  259 */
  {  51, 258, 0                    }, /*                INTEGER shift  258 */
  {  63, 261, &yyActionTable[3494] }, /*                  MINUS shift  261 */
/* State 256 */
  {  78, 257, 0                    }, /*                     RP shift  257 */
/* State 257 */
  {YYNOCODE,0,0}, /* Unused */
/* State 258 */
  {YYNOCODE,0,0}, /* Unused */
/* State 259 */
  {  51, 260, 0                    }, /*                INTEGER shift  260 */
/* State 260 */
  {YYNOCODE,0,0}, /* Unused */
/* State 261 */
  {  51, 262, 0                    }, /*                INTEGER shift  262 */
/* State 262 */
  {YYNOCODE,0,0}, /* Unused */
/* State 263 */
  {YYNOCODE,0,0}, /* Unused */
/* State 264 */
  {YYNOCODE,0,0}, /* Unused */
/* State 265 */
  {YYNOCODE,0,0}, /* Unused */
/* State 266 */
  {  16, 267, 0                    }, /*                  COMMA shift  267 */
  { 153, 289, 0                    }, /*                  tcons shift  289 */
  {  74, 271, 0                    }, /*                PRIMARY shift  271 */
  {  21, 269, &yyActionTable[3510] }, /*             CONSTRAINT shift  269 */
  {  13, 286, 0                    }, /*                  CHECK shift  286 */
  {  93, 281, &yyActionTable[3509] }, /*                 UNIQUE shift  281 */
  {  78, 456, 0                    }, /*                     RP reduce 71 */
  {YYNOCODE,0,0}, /* Unused */
/* State 267 */
  {  21, 269, &yyActionTable[3517] }, /*             CONSTRAINT shift  269 */
  { 153, 268, 0                    }, /*                  tcons shift  268 */
  {  74, 271, 0                    }, /*                PRIMARY shift  271 */
  {  13, 286, 0                    }, /*                  CHECK shift  286 */
  {YYNOCODE,0,0}, /* Unused */
  {  93, 281, &yyActionTable[3514] }, /*                 UNIQUE shift  281 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
/* State 268 */
  {YYNOCODE,0,0}, /* Unused */
/* State 269 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3525] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3528] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3531] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3533] }, /*                     id shift  37 */
  { 123, 270, &yyActionTable[3534] }, /*                    ids shift  270 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 270 */
  {YYNOCODE,0,0}, /* Unused */
/* State 271 */
  {  56, 272, 0                    }, /*                    KEY shift  272 */
/* State 272 */
  {  60, 273, 0                    }, /*                     LP shift  273 */
/* State 273 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3560] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3563] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3566] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3568] }, /*                     id shift  37 */
  { 123, 279, &yyActionTable[3569] }, /*                    ids shift  279 */
  { 124, 280, 0                    }, /*                idxitem shift  280 */
  { 125, 274, 0                    }, /*                idxlist shift  274 */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 274 */
  {  78, 275, &yyActionTable[3591] }, /*                     RP shift  275 */
  {  16, 277, 0                    }, /*                  COMMA shift  277 */
/* State 275 */
  { 136, 276, 0                    }, /*                 onconf shift  276 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
/* State 276 */
  {YYNOCODE,0,0}, /* Unused */
/* State 277 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3597] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3600] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3603] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3605] }, /*                     id shift  37 */
  { 123, 279, &yyActionTable[3606] }, /*                    ids shift  279 */
  { 124, 278, 0                    }, /*                idxitem shift  278 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 278 */
  {YYNOCODE,0,0}, /* Unused */
/* State 279 */
  {YYNOCODE,0,0}, /* Unused */
/* State 280 */
  {YYNOCODE,0,0}, /* Unused */
/* State 281 */
  {  60, 282, 0                    }, /*                     LP shift  282 */
/* State 282 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3633] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3636] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3639] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3641] }, /*                     id shift  37 */
  { 123, 279, &yyActionTable[3642] }, /*                    ids shift  279 */
  { 124, 280, 0                    }, /*                idxitem shift  280 */
  { 125, 283, 0                    }, /*                idxlist shift  283 */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 283 */
  {  78, 284, &yyActionTable[3664] }, /*                     RP shift  284 */
  {  16, 277, 0                    }, /*                  COMMA shift  277 */
/* State 284 */
  { 136, 285, 0                    }, /*                 onconf shift  285 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
/* State 285 */
  {YYNOCODE,0,0}, /* Unused */
/* State 286 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[3670] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[3679] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[3683] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[3684] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 287, &yyActionTable[3685] }, /*                   expr shift  287 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[3686] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[3689] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[3691] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[3693] }, /*                  MINUS shift  176 */
/* State 287 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[3703] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {  72, 141, &yyActionTable[3710] }, /*                   PLUS shift  141 */
  { 136, 288, &yyActionTable[3707] }, /*                 onconf shift  288 */
  {  41, 139, &yyActionTable[3712] }, /*                   GLOB shift  139 */
  {  40, 120, &yyActionTable[3713] }, /*                     GE shift  120 */
  {  75, 149, &yyActionTable[3714] }, /*                    REM shift  149 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  43, 116, &yyActionTable[3717] }, /*                     GT shift  116 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  83, 147, &yyActionTable[3718] }, /*                  SLASH shift  147 */
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
/* State 288 */
  {YYNOCODE,0,0}, /* Unused */
/* State 289 */
  {YYNOCODE,0,0}, /* Unused */
/* State 290 */
  {YYNOCODE,0,0}, /* Unused */
/* State 291 */
  {YYNOCODE,0,0}, /* Unused */
/* State 292 */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  { 145, 293, &yyActionTable[3738] }, /*                 select shift  293 */
  { 137,  78, 0                    }, /*              oneselect shift  78 */
  {YYNOCODE,0,0}, /* Unused */
/* State 293 */
  {  92, 166, &yyActionTable[3741] }, /*                  UNION shift  166 */
  {  52, 168, 0                    }, /*              INTERSECT shift  168 */
  { 134,  80, &yyActionTable[3743] }, /*         multiselect_op shift  80 */
  {  34, 169, 0                    }, /*                 EXCEPT shift  169 */
/* State 294 */
  {  88, 298, 0                    }, /*                   TEMP shift  298 */
  {  49, 585, 0                    }, /*                  INDEX reduce 200 */
  { 154, 295, 0                    }, /*                   temp shift  295 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  93, 308, 0                    }, /*                 UNIQUE shift  308 */
  { 158, 299, 0                    }, /*             uniqueflag shift  299 */
  {  87, 402, 0                    }, /*                  TABLE reduce 17 */
/* State 295 */
  {  87, 296, 0                    }, /*                  TABLE shift  296 */
/* State 296 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3755] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3758] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3761] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3763] }, /*                     id shift  37 */
  { 123, 297, &yyActionTable[3764] }, /*                    ids shift  297 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 297 */
  {YYNOCODE,0,0}, /* Unused */
/* State 298 */
  {  87, 401, 0                    }, /*                  TABLE reduce 16 */
/* State 299 */
  {  49, 300, 0                    }, /*                  INDEX shift  300 */
/* State 300 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3790] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3793] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3796] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3798] }, /*                     id shift  37 */
  { 123, 301, &yyActionTable[3799] }, /*                    ids shift  301 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 301 */
  {  69, 302, 0                    }, /*                     ON shift  302 */
/* State 302 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3823] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3826] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3829] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3831] }, /*                     id shift  37 */
  { 123, 303, &yyActionTable[3832] }, /*                    ids shift  303 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 303 */
  {  60, 304, 0                    }, /*                     LP shift  304 */
/* State 304 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3856] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3859] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3862] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3864] }, /*                     id shift  37 */
  { 123, 279, &yyActionTable[3865] }, /*                    ids shift  279 */
  { 124, 280, 0                    }, /*                idxitem shift  280 */
  { 125, 305, 0                    }, /*                idxlist shift  305 */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 305 */
  {  78, 306, &yyActionTable[3887] }, /*                     RP shift  306 */
  {  16, 277, 0                    }, /*                  COMMA shift  277 */
/* State 306 */
  { 136, 307, 0                    }, /*                 onconf shift  307 */
  {  69,   9, 0                    }, /*                     ON shift  9 */
/* State 307 */
  {YYNOCODE,0,0}, /* Unused */
/* State 308 */
  {  49, 584, 0                    }, /*                  INDEX reduce 199 */
/* State 309 */
  {  49, 312, 0                    }, /*                  INDEX shift  312 */
  {  87, 310, &yyActionTable[3892] }, /*                  TABLE shift  310 */
/* State 310 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3896] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3899] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3902] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3904] }, /*                     id shift  37 */
  { 123, 311, &yyActionTable[3905] }, /*                    ids shift  311 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 311 */
  {YYNOCODE,0,0}, /* Unused */
/* State 312 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3929] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3932] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3935] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3937] }, /*                     id shift  37 */
  { 123, 313, &yyActionTable[3938] }, /*                    ids shift  313 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 313 */
  {YYNOCODE,0,0}, /* Unused */
/* State 314 */
  {  92, 166, &yyActionTable[3961] }, /*                  UNION shift  166 */
  {  52, 168, 0                    }, /*              INTERSECT shift  168 */
  { 134,  80, &yyActionTable[3963] }, /*         multiselect_op shift  80 */
  {  34, 169, 0                    }, /*                 EXCEPT shift  169 */
/* State 315 */
  {  38, 316, 0                    }, /*                   FROM shift  316 */
/* State 316 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[3967] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[3970] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[3973] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[3975] }, /*                     id shift  37 */
  { 123, 317, &yyActionTable[3976] }, /*                    ids shift  317 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 317 */
  {  98, 205, 0                    }, /*                  WHERE shift  205 */
  { 159, 318, 0                    }, /*              where_opt shift  318 */
/* State 318 */
  {YYNOCODE,0,0}, /* Unused */
/* State 319 */
  { 138, 322, &yyActionTable[4001] }, /*                 orconf shift  322 */
  {  70, 320, 0                    }, /*                     OR shift  320 */
/* State 320 */
  {  36,  14, 0                    }, /*                   FAIL shift  14 */
  {   1,  13, 0                    }, /*                  ABORT shift  13 */
  {  46,  15, 0                    }, /*                 IGNORE shift  15 */
  {YYNOCODE,0,0}, /* Unused */
  {  76,  16, &yyActionTable[4002] }, /*                REPLACE shift  16 */
  {  77,  12, 0                    }, /*               ROLLBACK shift  12 */
  { 142, 321, &yyActionTable[4004] }, /*            resolvetype shift  321 */
  {YYNOCODE,0,0}, /* Unused */
/* State 321 */
  {YYNOCODE,0,0}, /* Unused */
/* State 322 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4013] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4016] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4019] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4021] }, /*                     id shift  37 */
  { 123, 323, &yyActionTable[4022] }, /*                    ids shift  323 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 323 */
  {  82, 324, 0                    }, /*                    SET shift  324 */
/* State 324 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4046] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4049] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  { 147, 325, 0                    }, /*                setlist shift  325 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4052] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4054] }, /*                     id shift  37 */
  { 123, 331, &yyActionTable[4055] }, /*                    ids shift  331 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 325 */
  {  16, 327, 0                    }, /*                  COMMA shift  327 */
  {YYNOCODE,0,0}, /* Unused */
  {  98, 205, 0                    }, /*                  WHERE shift  205 */
  { 159, 326, 0                    }, /*              where_opt shift  326 */
/* State 326 */
  {YYNOCODE,0,0}, /* Unused */
/* State 327 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4083] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4086] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4089] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4091] }, /*                     id shift  37 */
  { 123, 328, &yyActionTable[4092] }, /*                    ids shift  328 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 328 */
  {  33, 329, 0                    }, /*                     EQ shift  329 */
/* State 329 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[4116] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[4125] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[4129] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[4130] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 330, &yyActionTable[4131] }, /*                   expr shift  330 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[4132] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[4135] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[4137] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[4139] }, /*                  MINUS shift  176 */
/* State 330 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[4149] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[4153] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[4151] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[4156] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[4158] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[4159] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[4160] }, /*                  SLASH shift  147 */
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
/* State 331 */
  {  33, 332, 0                    }, /*                     EQ shift  332 */
/* State 332 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[4181] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[4190] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[4194] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[4195] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 333, &yyActionTable[4196] }, /*                   expr shift  333 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[4197] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[4200] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[4202] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[4204] }, /*                  MINUS shift  176 */
/* State 333 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[4214] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[4218] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[4216] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[4221] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[4223] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[4224] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[4225] }, /*                  SLASH shift  147 */
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
/* State 334 */
  {  53, 335, 0                    }, /*                   INTO shift  335 */
/* State 335 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4246] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4249] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4252] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4254] }, /*                     id shift  37 */
  { 123, 336, &yyActionTable[4255] }, /*                    ids shift  336 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 336 */
  { 128, 337, &yyActionTable[4277] }, /*         inscollist_opt shift  337 */
  {  60, 346, 0                    }, /*                     LP shift  346 */
/* State 337 */
  {  80,  82, 0                    }, /*                 SELECT shift  82 */
  { 145, 338, &yyActionTable[4280] }, /*                 select shift  338 */
  { 137,  78, &yyActionTable[4281] }, /*              oneselect shift  78 */
  {  97, 339, 0                    }, /*                 VALUES shift  339 */
/* State 338 */
  {  92, 166, &yyActionTable[4283] }, /*                  UNION shift  166 */
  {  52, 168, 0                    }, /*              INTERSECT shift  168 */
  { 134,  80, &yyActionTable[4285] }, /*         multiselect_op shift  80 */
  {  34, 169, 0                    }, /*                 EXCEPT shift  169 */
/* State 339 */
  {  60, 340, 0                    }, /*                     LP shift  340 */
/* State 340 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[4298] }, /*                    NOT shift  172 */
  { 130, 341, 0                    }, /*               itemlist shift  341 */
  {  67, 105, &yyActionTable[4302] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[4303] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[4304] }, /*                 IGNORE shift  33 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 345, &yyActionTable[4305] }, /*                   expr shift  345 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  88,  29, &yyActionTable[4308] }, /*                   TEMP shift  29 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  { 122,  75, &yyActionTable[4310] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[4312] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[4316] }, /*                  MINUS shift  176 */
/* State 341 */
  {  78, 342, &yyActionTable[4320] }, /*                     RP shift  342 */
  {  16, 343, 0                    }, /*                  COMMA shift  343 */
/* State 342 */
  {YYNOCODE,0,0}, /* Unused */
/* State 343 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {  65, 172, &yyActionTable[4324] }, /*                    NOT shift  172 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  67, 105, &yyActionTable[4333] }, /*                   NULL shift  105 */
  {  68,  30, &yyActionTable[4337] }, /*                 OFFSET shift  30 */
  {  37, 110, 0                    }, /*                  FLOAT shift  110 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 178, 0                    }, /*                   PLUS shift  178 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  10, 174, 0                    }, /*                 BITNOT shift  174 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  73, 0                    }, /*                     ID shift  73 */
  {  46,  33, &yyActionTable[4338] }, /*                 IGNORE shift  33 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  51, 109, 0                    }, /*                INTEGER shift  109 */
  { 116, 344, &yyActionTable[4339] }, /*                   expr shift  344 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  86,  76, 0                    }, /*                 STRING shift  76 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  88,  29, &yyActionTable[4340] }, /*                   TEMP shift  29 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  { 122,  75, &yyActionTable[4343] }, /*                     id shift  75 */
  { 123, 106, &yyActionTable[4345] }, /*                    ids shift  106 */
  {  60,  77, 0                    }, /*                     LP shift  77 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 176, &yyActionTable[4347] }, /*                  MINUS shift  176 */
/* State 344 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[4357] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[4361] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[4359] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[4364] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[4366] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[4367] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[4368] }, /*                  SLASH shift  147 */
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
/* State 345 */
  {  64, 122, 0                    }, /*                     NE shift  122 */
  {  65, 136, &yyActionTable[4389] }, /*                    NOT shift  136 */
  {  66, 158, 0                    }, /*                NOTNULL shift  158 */
  {  33, 124, 0                    }, /*                     EQ shift  124 */
  {   4, 104, 0                    }, /*                    AND shift  104 */
  {  40, 120, &yyActionTable[4393] }, /*                     GE shift  120 */
  {  70, 112, 0                    }, /*                     OR shift  112 */
  {   8, 159, 0                    }, /*                BETWEEN shift  159 */
  {  72, 141, &yyActionTable[4391] }, /*                   PLUS shift  141 */
  {  41, 139, &yyActionTable[4396] }, /*                   GLOB shift  139 */
  {   9, 126, 0                    }, /*                 BITAND shift  126 */
  {  75, 149, &yyActionTable[4398] }, /*                    REM shift  149 */
  {  43, 116, &yyActionTable[4399] }, /*                     GT shift  116 */
  {  11, 128, 0                    }, /*                  BITOR shift  128 */
  {  19, 151, 0                    }, /*                 CONCAT shift  151 */
  {  79, 132, 0                    }, /*                 RSHIFT shift  132 */
  {  48, 163, 0                    }, /*                     IN shift  163 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  83, 147, &yyActionTable[4400] }, /*                  SLASH shift  147 */
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
/* State 346 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4420] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4423] }, /*                 IGNORE shift  33 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4426] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4428] }, /*                     id shift  37 */
  { 123, 351, &yyActionTable[4429] }, /*                    ids shift  351 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  { 127, 347, &yyActionTable[4433] }, /*             inscollist shift  347 */
/* State 347 */
  {  78, 348, &yyActionTable[4451] }, /*                     RP shift  348 */
  {  16, 349, 0                    }, /*                  COMMA shift  349 */
/* State 348 */
  {YYNOCODE,0,0}, /* Unused */
/* State 349 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4455] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4458] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4461] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4463] }, /*                     id shift  37 */
  { 123, 350, &yyActionTable[4464] }, /*                    ids shift  350 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 350 */
  {YYNOCODE,0,0}, /* Unused */
/* State 351 */
  {YYNOCODE,0,0}, /* Unused */
/* State 352 */
  {  70, 320, 0                    }, /*                     OR shift  320 */
  {  53, 466, 0                    }, /*                   INTO reduce 81 */
  { 138, 353, &yyActionTable[4487] }, /*                 orconf shift  353 */
  {YYNOCODE,0,0}, /* Unused */
/* State 353 */
  {  53, 524, 0                    }, /*                   INTO reduce 139 */
/* State 354 */
  {  53, 525, 0                    }, /*                   INTO reduce 140 */
/* State 355 */
  { 138, 356, &yyActionTable[4494] }, /*                 orconf shift  356 */
  {  70, 320, 0                    }, /*                     OR shift  320 */
/* State 356 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4497] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4500] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4503] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4505] }, /*                     id shift  37 */
  { 123, 357, &yyActionTable[4506] }, /*                    ids shift  357 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 357 */
  {  38, 358, 0                    }, /*                   FROM shift  358 */
/* State 358 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4530] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4533] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4536] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4538] }, /*                     id shift  37 */
  { 123, 359, &yyActionTable[4539] }, /*                    ids shift  359 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 359 */
  {  95, 360, 0                    }, /*                  USING shift  360 */
/* State 360 */
  {  26, 361, 0                    }, /*             DELIMITERS shift  361 */
/* State 361 */
  {  86, 362, 0                    }, /*                 STRING shift  362 */
/* State 362 */
  {YYNOCODE,0,0}, /* Unused */
/* State 363 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4566] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4569] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4572] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4574] }, /*                     id shift  37 */
  { 123, 364, &yyActionTable[4575] }, /*                    ids shift  364 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 364 */
  {YYNOCODE,0,0}, /* Unused */
/* State 365 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4599] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4602] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4605] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4607] }, /*                     id shift  37 */
  { 123, 366, &yyActionTable[4608] }, /*                    ids shift  366 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 366 */
  {  60, 379, 0                    }, /*                     LP shift  379 */
  {  33, 367, 0                    }, /*                     EQ shift  367 */
/* State 367 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4633] }, /*                 OFFSET shift  30 */
  { 133, 371, &yyActionTable[4641] }, /*              minus_num shift  371 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  72, 378, 0                    }, /*                   PLUS shift  378 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  69, 369, 0                    }, /*                     ON shift  369 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  { 140, 370, &yyActionTable[4642] }, /*               plus_num shift  370 */
  { 141, 372, &yyActionTable[4646] }, /*               plus_opt shift  372 */
  {  46,  33, &yyActionTable[4647] }, /*                 IGNORE shift  33 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {  31,  25, 0                    }, /*                    END shift  25 */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4648] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4649] }, /*                     id shift  37 */
  { 123, 368, &yyActionTable[4650] }, /*                    ids shift  368 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  63, 376, &yyActionTable[4652] }, /*                  MINUS shift  376 */
/* State 368 */
  {YYNOCODE,0,0}, /* Unused */
/* State 369 */
  {YYNOCODE,0,0}, /* Unused */
/* State 370 */
  {YYNOCODE,0,0}, /* Unused */
/* State 371 */
  {YYNOCODE,0,0}, /* Unused */
/* State 372 */
  {  51, 374, 0                    }, /*                INTEGER shift  374 */
  {  37, 375, 0                    }, /*                  FLOAT shift  375 */
  {YYNOCODE,0,0}, /* Unused */
  { 135, 373, &yyActionTable[4667] }, /*                 number shift  373 */
/* State 373 */
  {YYNOCODE,0,0}, /* Unused */
/* State 374 */
  {YYNOCODE,0,0}, /* Unused */
/* State 375 */
  {YYNOCODE,0,0}, /* Unused */
/* State 376 */
  {  51, 374, 0                    }, /*                INTEGER shift  374 */
  {  37, 375, 0                    }, /*                  FLOAT shift  375 */
  {YYNOCODE,0,0}, /* Unused */
  { 135, 377, &yyActionTable[4674] }, /*                 number shift  377 */
/* State 377 */
  {YYNOCODE,0,0}, /* Unused */
/* State 378 */
  {YYNOCODE,0,0}, /* Unused */
/* State 379 */
  {  96,  23, 0                    }, /*                 VACUUM shift  23 */
  {   1,  32, 0                    }, /*                  ABORT shift  32 */
  {  36,  35, 0                    }, /*                   FAIL shift  35 */
  {  35,  22, 0                    }, /*                EXPLAIN shift  22 */
  {  68,  30, &yyActionTable[4682] }, /*                 OFFSET shift  30 */
  {  14,  27, 0                    }, /*                CLUSTER shift  27 */
  {   6,  20, 0                    }, /*                    ASC shift  20 */
  {   7,  24, 0                    }, /*                  BEGIN shift  24 */
  {  56,  31, 0                    }, /*                    KEY shift  31 */
  {  73,  26, 0                    }, /*                 PRAGMA shift  26 */
  {  26,  21, 0                    }, /*             DELIMITERS shift  21 */
  {  27,  19, 0                    }, /*                   DESC shift  19 */
  {  76,  34, 0                    }, /*                REPLACE shift  34 */
  {  45,  28, 0                    }, /*                     ID shift  28 */
  {  46,  33, &yyActionTable[4685] }, /*                 IGNORE shift  33 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  20,  36, 0                    }, /*               CONFLICT shift  36 */
  {YYNOCODE,0,0}, /* Unused */
  {  86,  38, 0                    }, /*                 STRING shift  38 */
  {YYNOCODE,0,0}, /* Unused */
  {  88,  29, &yyActionTable[4688] }, /*                   TEMP shift  29 */
  {YYNOCODE,0,0}, /* Unused */
  { 122,  37, &yyActionTable[4690] }, /*                     id shift  37 */
  { 123, 380, &yyActionTable[4691] }, /*                    ids shift  380 */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {YYNOCODE,0,0}, /* Unused */
  {  31,  25, 0                    }, /*                    END shift  25 */
/* State 380 */
  {  78, 381, 0                    }, /*                     RP shift  381 */
/* State 381 */
  {YYNOCODE,0,0}, /* Unused */
/* State 382 */
  {YYNOCODE,0,0}, /* Unused */
/* State 383 */
  {YYNOCODE,0,0}, /* Unused */
/* State 384 */
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
  { &yyActionTable[0], 31, 390},
  { &yyActionTable[32], 1, 606},
  { &yyActionTable[34], 31, 390},
  { &yyActionTable[66], 0, 387},
  { &yyActionTable[67], 31, 606},
  { &yyActionTable[99], 0, 388},
  { &yyActionTable[100], 1, 393},
  { &yyActionTable[102], 1, 464},
  { &yyActionTable[104], 0, 392},
  { &yyActionTable[105], 0, 606},
  { &yyActionTable[106], 7, 606},
  { &yyActionTable[114], 0, 465},
  { &yyActionTable[115], 0, 468},
  { &yyActionTable[116], 0, 469},
  { &yyActionTable[117], 0, 470},
  { &yyActionTable[118], 0, 471},
  { &yyActionTable[119], 0, 472},
  { &yyActionTable[120], 31, 394},
  { &yyActionTable[152], 0, 395},
  { &yyActionTable[153], 0, 409},
  { &yyActionTable[154], 0, 410},
  { &yyActionTable[155], 0, 411},
  { &yyActionTable[156], 0, 412},
  { &yyActionTable[157], 0, 413},
  { &yyActionTable[158], 0, 414},
  { &yyActionTable[159], 0, 415},
  { &yyActionTable[160], 0, 416},
  { &yyActionTable[161], 0, 417},
  { &yyActionTable[162], 0, 418},
  { &yyActionTable[163], 0, 419},
  { &yyActionTable[164], 0, 420},
  { &yyActionTable[165], 0, 421},
  { &yyActionTable[166], 0, 422},
  { &yyActionTable[167], 0, 423},
  { &yyActionTable[168], 0, 424},
  { &yyActionTable[169], 0, 425},
  { &yyActionTable[170], 0, 426},
  { &yyActionTable[171], 0, 427},
  { &yyActionTable[172], 0, 428},
  { &yyActionTable[173], 1, 393},
  { &yyActionTable[175], 0, 396},
  { &yyActionTable[176], 1, 393},
  { &yyActionTable[178], 0, 397},
  { &yyActionTable[179], 1, 393},
  { &yyActionTable[181], 0, 398},
  { &yyActionTable[182], 3, 606},
  { &yyActionTable[186], 0, 399},
  { &yyActionTable[187], 31, 606},
  { &yyActionTable[219], 3, 606},
  { &yyActionTable[223], 0, 606},
  { &yyActionTable[224], 0, 403},
  { &yyActionTable[225], 31, 606},
  { &yyActionTable[257], 0, 405},
  { &yyActionTable[258], 31, 429},
  { &yyActionTable[290], 0, 439},
  { &yyActionTable[291], 7, 407},
  { &yyActionTable[299], 0, 438},
  { &yyActionTable[300], 31, 606},
  { &yyActionTable[332], 7, 606},
  { &yyActionTable[340], 0, 440},
  { &yyActionTable[341], 0, 606},
  { &yyActionTable[342], 1, 464},
  { &yyActionTable[344], 0, 451},
  { &yyActionTable[345], 0, 606},
  { &yyActionTable[346], 3, 506},
  { &yyActionTable[350], 1, 464},
  { &yyActionTable[352], 0, 452},
  { &yyActionTable[353], 0, 504},
  { &yyActionTable[354], 0, 505},
  { &yyActionTable[355], 1, 464},
  { &yyActionTable[357], 0, 453},
  { &yyActionTable[358], 0, 606},
  { &yyActionTable[359], 31, 606},
  { &yyActionTable[391], 0, 418},
  { &yyActionTable[392], 63, 582},
  { &yyActionTable[456], 127, 606},
  { &yyActionTable[584], 127, 606},
  { &yyActionTable[712], 63, 606},
  { &yyActionTable[776], 0, 475},
  { &yyActionTable[777], 7, 606},
  { &yyActionTable[785], 1, 606},
  { &yyActionTable[787], 0, 476},
  { &yyActionTable[788], 3, 484},
  { &yyActionTable[792], 1, 486},
  { &yyActionTable[794], 3, 606},
  { &yyActionTable[798], 1, 517},
  { &yyActionTable[800], 1, 507},
  { &yyActionTable[802], 1, 509},
  { &yyActionTable[804], 1, 499},
  { &yyActionTable[806], 1, 511},
  { &yyActionTable[808], 0, 481},
  { &yyActionTable[809], 0, 606},
  { &yyActionTable[810], 3, 512},
  { &yyActionTable[814], 0, 606},
  { &yyActionTable[815], 0, 513},
  { &yyActionTable[816], 0, 606},
  { &yyActionTable[817], 0, 606},
  { &yyActionTable[818], 0, 606},
  { &yyActionTable[819], 31, 606},
  { &yyActionTable[851], 0, 500},
  { &yyActionTable[852], 31, 606},
  { &yyActionTable[884], 3, 506},
  { &yyActionTable[888], 0, 501},
  { &yyActionTable[889], 31, 503},
  { &yyActionTable[921], 31, 606},
  { &yyActionTable[953], 0, 533},
  { &yyActionTable[954], 0, 606},
  { &yyActionTable[955], 31, 606},
  { &yyActionTable[987], 0, 535},
  { &yyActionTable[988], 0, 536},
  { &yyActionTable[989], 0, 537},
  { &yyActionTable[990], 31, 541},
  { &yyActionTable[1022], 31, 606},
  { &yyActionTable[1054], 31, 542},
  { &yyActionTable[1086], 31, 606},
  { &yyActionTable[1118], 15, 543},
  { &yyActionTable[1134], 31, 606},
  { &yyActionTable[1166], 15, 544},
  { &yyActionTable[1182], 31, 606},
  { &yyActionTable[1214], 15, 545},
  { &yyActionTable[1230], 31, 606},
  { &yyActionTable[1262], 15, 546},
  { &yyActionTable[1278], 31, 606},
  { &yyActionTable[1310], 15, 547},
  { &yyActionTable[1326], 31, 606},
  { &yyActionTable[1358], 15, 548},
  { &yyActionTable[1374], 31, 606},
  { &yyActionTable[1406], 7, 549},
  { &yyActionTable[1414], 31, 606},
  { &yyActionTable[1446], 7, 550},
  { &yyActionTable[1454], 31, 606},
  { &yyActionTable[1486], 7, 551},
  { &yyActionTable[1494], 31, 606},
  { &yyActionTable[1526], 7, 552},
  { &yyActionTable[1534], 31, 606},
  { &yyActionTable[1566], 15, 553},
  { &yyActionTable[1582], 7, 606},
  { &yyActionTable[1590], 31, 606},
  { &yyActionTable[1622], 31, 554},
  { &yyActionTable[1654], 31, 606},
  { &yyActionTable[1686], 15, 555},
  { &yyActionTable[1702], 31, 606},
  { &yyActionTable[1734], 3, 557},
  { &yyActionTable[1738], 31, 606},
  { &yyActionTable[1770], 3, 558},
  { &yyActionTable[1774], 31, 606},
  { &yyActionTable[1806], 0, 559},
  { &yyActionTable[1807], 31, 606},
  { &yyActionTable[1839], 0, 560},
  { &yyActionTable[1840], 31, 606},
  { &yyActionTable[1872], 0, 561},
  { &yyActionTable[1873], 31, 606},
  { &yyActionTable[1905], 0, 562},
  { &yyActionTable[1906], 0, 563},
  { &yyActionTable[1907], 1, 606},
  { &yyActionTable[1909], 0, 564},
  { &yyActionTable[1910], 0, 606},
  { &yyActionTable[1911], 0, 567},
  { &yyActionTable[1912], 0, 565},
  { &yyActionTable[1913], 31, 606},
  { &yyActionTable[1945], 31, 606},
  { &yyActionTable[1977], 31, 606},
  { &yyActionTable[2009], 127, 606},
  { &yyActionTable[2137], 0, 606},
  { &yyActionTable[2138], 63, 582},
  { &yyActionTable[2202], 7, 606},
  { &yyActionTable[2210], 1, 606},
  { &yyActionTable[2212], 0, 606},
  { &yyActionTable[2213], 0, 606},
  { &yyActionTable[2214], 0, 606},
  { &yyActionTable[2215], 0, 576},
  { &yyActionTable[2216], 31, 581},
  { &yyActionTable[2248], 31, 606},
  { &yyActionTable[2280], 31, 568},
  { &yyActionTable[2312], 31, 606},
  { &yyActionTable[2344], 0, 569},
  { &yyActionTable[2345], 31, 606},
  { &yyActionTable[2377], 0, 570},
  { &yyActionTable[2378], 31, 606},
  { &yyActionTable[2410], 0, 571},
  { &yyActionTable[2411], 1, 606},
  { &yyActionTable[2413], 0, 575},
  { &yyActionTable[2414], 31, 582},
  { &yyActionTable[2446], 0, 579},
  { &yyActionTable[2447], 0, 580},
  { &yyActionTable[2448], 31, 606},
  { &yyActionTable[2480], 31, 556},
  { &yyActionTable[2512], 0, 566},
  { &yyActionTable[2513], 31, 606},
  { &yyActionTable[2545], 31, 606},
  { &yyActionTable[2577], 31, 606},
  { &yyActionTable[2609], 127, 606},
  { &yyActionTable[2737], 0, 606},
  { &yyActionTable[2738], 63, 582},
  { &yyActionTable[2802], 7, 606},
  { &yyActionTable[2810], 0, 578},
  { &yyActionTable[2811], 1, 606},
  { &yyActionTable[2813], 0, 577},
  { &yyActionTable[2814], 3, 506},
  { &yyActionTable[2818], 0, 502},
  { &yyActionTable[2819], 31, 606},
  { &yyActionTable[2851], 31, 510},
  { &yyActionTable[2883], 0, 606},
  { &yyActionTable[2884], 31, 582},
  { &yyActionTable[2916], 0, 508},
  { &yyActionTable[2917], 31, 606},
  { &yyActionTable[2949], 31, 518},
  { &yyActionTable[2981], 0, 485},
  { &yyActionTable[2982], 1, 494},
  { &yyActionTable[2984], 0, 492},
  { &yyActionTable[2985], 0, 493},
  { &yyActionTable[2986], 31, 606},
  { &yyActionTable[3018], 63, 606},
  { &yyActionTable[3082], 0, 491},
  { &yyActionTable[3083], 31, 606},
  { &yyActionTable[3115], 0, 496},
  { &yyActionTable[3116], 3, 606},
  { &yyActionTable[3120], 7, 606},
  { &yyActionTable[3128], 63, 606},
  { &yyActionTable[3192], 31, 606},
  { &yyActionTable[3224], 0, 498},
  { &yyActionTable[3225], 31, 606},
  { &yyActionTable[3257], 63, 606},
  { &yyActionTable[3321], 31, 606},
  { &yyActionTable[3353], 0, 488},
  { &yyActionTable[3354], 0, 489},
  { &yyActionTable[3355], 0, 482},
  { &yyActionTable[3356], 0, 483},
  { &yyActionTable[3357], 0, 572},
  { &yyActionTable[3358], 31, 606},
  { &yyActionTable[3390], 0, 532},
  { &yyActionTable[3391], 1, 606},
  { &yyActionTable[3393], 0, 539},
  { &yyActionTable[3394], 0, 606},
  { &yyActionTable[3395], 0, 540},
  { &yyActionTable[3396], 31, 606},
  { &yyActionTable[3428], 1, 464},
  { &yyActionTable[3430], 0, 454},
  { &yyActionTable[3431], 0, 441},
  { &yyActionTable[3432], 7, 606},
  { &yyActionTable[3440], 0, 442},
  { &yyActionTable[3441], 0, 443},
  { &yyActionTable[3442], 0, 444},
  { &yyActionTable[3443], 1, 606},
  { &yyActionTable[3445], 0, 445},
  { &yyActionTable[3446], 0, 448},
  { &yyActionTable[3447], 1, 606},
  { &yyActionTable[3449], 0, 446},
  { &yyActionTable[3450], 0, 449},
  { &yyActionTable[3451], 0, 447},
  { &yyActionTable[3452], 0, 450},
  { &yyActionTable[3453], 31, 430},
  { &yyActionTable[3485], 3, 606},
  { &yyActionTable[3489], 1, 606},
  { &yyActionTable[3491], 0, 431},
  { &yyActionTable[3492], 3, 606},
  { &yyActionTable[3496], 0, 606},
  { &yyActionTable[3497], 0, 432},
  { &yyActionTable[3498], 0, 435},
  { &yyActionTable[3499], 0, 606},
  { &yyActionTable[3500], 0, 436},
  { &yyActionTable[3501], 0, 606},
  { &yyActionTable[3502], 0, 437},
  { &yyActionTable[3503], 0, 434},
  { &yyActionTable[3504], 0, 433},
  { &yyActionTable[3505], 0, 408},
  { &yyActionTable[3506], 7, 606},
  { &yyActionTable[3514], 7, 606},
  { &yyActionTable[3522], 0, 457},
  { &yyActionTable[3523], 31, 606},
  { &yyActionTable[3555], 0, 460},
  { &yyActionTable[3556], 0, 606},
  { &yyActionTable[3557], 0, 606},
  { &yyActionTable[3558], 31, 606},
  { &yyActionTable[3590], 1, 606},
  { &yyActionTable[3592], 1, 464},
  { &yyActionTable[3594], 0, 461},
  { &yyActionTable[3595], 31, 606},
  { &yyActionTable[3627], 0, 586},
  { &yyActionTable[3628], 0, 588},
  { &yyActionTable[3629], 0, 587},
  { &yyActionTable[3630], 0, 606},
  { &yyActionTable[3631], 31, 606},
  { &yyActionTable[3663], 1, 606},
  { &yyActionTable[3665], 1, 464},
  { &yyActionTable[3667], 0, 462},
  { &yyActionTable[3668], 31, 606},
  { &yyActionTable[3700], 31, 464},
  { &yyActionTable[3732], 0, 463},
  { &yyActionTable[3733], 0, 458},
  { &yyActionTable[3734], 0, 459},
  { &yyActionTable[3735], 0, 406},
  { &yyActionTable[3736], 3, 606},
  { &yyActionTable[3740], 3, 404},
  { &yyActionTable[3744], 7, 606},
  { &yyActionTable[3752], 0, 606},
  { &yyActionTable[3753], 31, 606},
  { &yyActionTable[3785], 0, 400},
  { &yyActionTable[3786], 0, 606},
  { &yyActionTable[3787], 0, 606},
  { &yyActionTable[3788], 31, 606},
  { &yyActionTable[3820], 0, 606},
  { &yyActionTable[3821], 31, 606},
  { &yyActionTable[3853], 0, 606},
  { &yyActionTable[3854], 31, 606},
  { &yyActionTable[3886], 1, 606},
  { &yyActionTable[3888], 1, 464},
  { &yyActionTable[3890], 0, 583},
  { &yyActionTable[3891], 0, 606},
  { &yyActionTable[3892], 1, 606},
  { &yyActionTable[3894], 31, 606},
  { &yyActionTable[3926], 0, 473},
  { &yyActionTable[3927], 31, 606},
  { &yyActionTable[3959], 0, 589},
  { &yyActionTable[3960], 3, 474},
  { &yyActionTable[3964], 0, 606},
  { &yyActionTable[3965], 31, 606},
  { &yyActionTable[3997], 1, 517},
  { &yyActionTable[3999], 0, 516},
  { &yyActionTable[4000], 1, 466},
  { &yyActionTable[4002], 7, 606},
  { &yyActionTable[4010], 0, 467},
  { &yyActionTable[4011], 31, 606},
  { &yyActionTable[4043], 0, 606},
  { &yyActionTable[4044], 31, 606},
  { &yyActionTable[4076], 3, 517},
  { &yyActionTable[4080], 0, 519},
  { &yyActionTable[4081], 31, 606},
  { &yyActionTable[4113], 0, 606},
  { &yyActionTable[4114], 31, 606},
  { &yyActionTable[4146], 31, 520},
  { &yyActionTable[4178], 0, 606},
  { &yyActionTable[4179], 31, 606},
  { &yyActionTable[4211], 31, 521},
  { &yyActionTable[4243], 0, 606},
  { &yyActionTable[4244], 31, 606},
  { &yyActionTable[4276], 1, 528},
  { &yyActionTable[4278], 3, 606},
  { &yyActionTable[4282], 3, 523},
  { &yyActionTable[4286], 0, 606},
  { &yyActionTable[4287], 31, 606},
  { &yyActionTable[4319], 1, 606},
  { &yyActionTable[4321], 0, 522},
  { &yyActionTable[4322], 31, 606},
  { &yyActionTable[4354], 31, 526},
  { &yyActionTable[4386], 31, 527},
  { &yyActionTable[4418], 31, 606},
  { &yyActionTable[4450], 1, 606},
  { &yyActionTable[4452], 0, 529},
  { &yyActionTable[4453], 31, 606},
  { &yyActionTable[4485], 0, 530},
  { &yyActionTable[4486], 0, 531},
  { &yyActionTable[4487], 3, 606},
  { &yyActionTable[4491], 0, 606},
  { &yyActionTable[4492], 0, 606},
  { &yyActionTable[4493], 1, 466},
  { &yyActionTable[4495], 31, 606},
  { &yyActionTable[4527], 0, 606},
  { &yyActionTable[4528], 31, 606},
  { &yyActionTable[4560], 0, 591},
  { &yyActionTable[4561], 0, 606},
  { &yyActionTable[4562], 0, 606},
  { &yyActionTable[4563], 0, 590},
  { &yyActionTable[4564], 31, 592},
  { &yyActionTable[4596], 0, 593},
  { &yyActionTable[4597], 31, 606},
  { &yyActionTable[4629], 1, 599},
  { &yyActionTable[4631], 31, 605},
  { &yyActionTable[4663], 0, 594},
  { &yyActionTable[4664], 0, 595},
  { &yyActionTable[4665], 0, 596},
  { &yyActionTable[4666], 0, 597},
  { &yyActionTable[4667], 3, 606},
  { &yyActionTable[4671], 0, 600},
  { &yyActionTable[4672], 0, 602},
  { &yyActionTable[4673], 0, 603},
  { &yyActionTable[4674], 3, 606},
  { &yyActionTable[4678], 0, 601},
  { &yyActionTable[4679], 0, 604},
  { &yyActionTable[4680], 31, 606},
  { &yyActionTable[4712], 0, 606},
  { &yyActionTable[4713], 0, 598},
  { &yyActionTable[4714], 0, 389},
  { &yyActionTable[4715], 0, 391},
  { &yyActionTable[4716], 0, 386},
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
  "inscollist_opt",  "insert_cmd",    "itemlist",      "limit_opt",   
  "limit_sep",     "minus_num",     "multiselect_op",  "number",      
  "onconf",        "oneselect",     "orconf",        "orderby_opt", 
  "plus_num",      "plus_opt",      "resolvetype",   "sclp",        
  "selcollist",    "select",        "seltablist",    "setlist",     
  "signed",        "sortitem",      "sortlist",      "sortorder",   
  "stl_prefix",    "tcons",         "temp",          "trans_opt",   
  "type",          "typename",      "uniqueflag",    "where_opt",   
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
#line 384 "parse.y"
{sqliteExprDelete((yypminor->yy2));}
#line 5790 "parse.c"
      break;
    case 117:
#line 519 "parse.y"
{sqliteExprDelete((yypminor->yy2));}
#line 5795 "parse.c"
      break;
    case 118:
#line 517 "parse.y"
{sqliteExprListDelete((yypminor->yy48));}
#line 5800 "parse.c"
      break;
    case 119:
#line 256 "parse.y"
{sqliteIdListDelete((yypminor->yy50));}
#line 5805 "parse.c"
      break;
    case 120:
#line 302 "parse.y"
{sqliteExprListDelete((yypminor->yy48));}
#line 5810 "parse.c"
      break;
    case 121:
#line 307 "parse.y"
{sqliteExprDelete((yypminor->yy2));}
#line 5815 "parse.c"
      break;
    case 125:
#line 541 "parse.y"
{sqliteIdListDelete((yypminor->yy50));}
#line 5820 "parse.c"
      break;
    case 127:
#line 363 "parse.y"
{sqliteIdListDelete((yypminor->yy50));}
#line 5825 "parse.c"
      break;
    case 128:
#line 361 "parse.y"
{sqliteIdListDelete((yypminor->yy50));}
#line 5830 "parse.c"
      break;
    case 130:
#line 355 "parse.y"
{sqliteExprListDelete((yypminor->yy48));}
#line 5835 "parse.c"
      break;
    case 137:
#line 203 "parse.y"
{sqliteSelectDelete((yypminor->yy299));}
#line 5840 "parse.c"
      break;
    case 139:
#line 277 "parse.y"
{sqliteExprListDelete((yypminor->yy48));}
#line 5845 "parse.c"
      break;
    case 143:
#line 239 "parse.y"
{sqliteExprListDelete((yypminor->yy48));}
#line 5850 "parse.c"
      break;
    case 144:
#line 237 "parse.y"
{sqliteExprListDelete((yypminor->yy48));}
#line 5855 "parse.c"
      break;
    case 145:
#line 201 "parse.y"
{sqliteSelectDelete((yypminor->yy299));}
#line 5860 "parse.c"
      break;
    case 146:
#line 252 "parse.y"
{sqliteIdListDelete((yypminor->yy50));}
#line 5865 "parse.c"
      break;
    case 147:
#line 331 "parse.y"
{sqliteExprListDelete((yypminor->yy48));}
#line 5870 "parse.c"
      break;
    case 149:
#line 281 "parse.y"
{sqliteExprDelete((yypminor->yy2));}
#line 5875 "parse.c"
      break;
    case 150:
#line 279 "parse.y"
{sqliteExprListDelete((yypminor->yy48));}
#line 5880 "parse.c"
      break;
    case 152:
#line 254 "parse.y"
{sqliteIdListDelete((yypminor->yy50));}
#line 5885 "parse.c"
      break;
    case 159:
#line 325 "parse.y"
{sqliteExprDelete((yypminor->yy2));}
#line 5890 "parse.c"
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
  { 155, 0 },
  { 155, 1 },
  { 155, 2 },
  { 103, 2 },
  { 103, 2 },
  { 103, 2 },
  { 103, 2 },
  { 110, 4 },
  { 154, 1 },
  { 154, 0 },
  { 111, 4 },
  { 111, 2 },
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
  { 156, 0 },
  { 156, 1 },
  { 156, 4 },
  { 156, 6 },
  { 157, 1 },
  { 157, 2 },
  { 148, 1 },
  { 148, 2 },
  { 148, 2 },
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
  { 153, 2 },
  { 153, 6 },
  { 153, 5 },
  { 153, 3 },
  { 136, 0 },
  { 136, 3 },
  { 138, 0 },
  { 138, 2 },
  { 142, 1 },
  { 142, 1 },
  { 142, 1 },
  { 142, 1 },
  { 142, 1 },
  { 103, 3 },
  { 103, 1 },
  { 145, 1 },
  { 145, 3 },
  { 134, 1 },
  { 134, 2 },
  { 134, 1 },
  { 134, 1 },
  { 137, 9 },
  { 112, 1 },
  { 112, 1 },
  { 112, 0 },
  { 143, 2 },
  { 143, 0 },
  { 144, 2 },
  { 144, 4 },
  { 144, 2 },
  { 99, 0 },
  { 99, 1 },
  { 119, 2 },
  { 152, 2 },
  { 152, 0 },
  { 146, 2 },
  { 146, 4 },
  { 146, 4 },
  { 146, 6 },
  { 139, 0 },
  { 139, 3 },
  { 150, 4 },
  { 150, 2 },
  { 149, 1 },
  { 151, 1 },
  { 151, 1 },
  { 151, 0 },
  { 120, 0 },
  { 120, 3 },
  { 121, 0 },
  { 121, 2 },
  { 131, 0 },
  { 131, 2 },
  { 131, 4 },
  { 132, 1 },
  { 132, 1 },
  { 103, 4 },
  { 159, 0 },
  { 159, 2 },
  { 103, 6 },
  { 147, 5 },
  { 147, 3 },
  { 103, 8 },
  { 103, 5 },
  { 129, 2 },
  { 129, 1 },
  { 130, 3 },
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
  { 158, 1 },
  { 158, 0 },
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
  { 140, 2 },
  { 133, 2 },
  { 135, 1 },
  { 135, 1 },
  { 141, 1 },
  { 141, 0 },
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
#line 6286 "parse.c"
        /* No destructor defined for explain */
        /* No destructor defined for cmd */
        break;
      case 4:
        YYTRACE("ecmd ::= cmd")
#line 53 "parse.y"
{sqliteExec(pParse);}
#line 6294 "parse.c"
        /* No destructor defined for cmd */
        break;
      case 5:
        YYTRACE("ecmd ::=")
        break;
      case 6:
        YYTRACE("explain ::= EXPLAIN")
#line 55 "parse.y"
{pParse->explain = 1;}
#line 6304 "parse.c"
        /* No destructor defined for EXPLAIN */
        break;
      case 7:
        YYTRACE("cmd ::= BEGIN trans_opt onconf")
#line 60 "parse.y"
{sqliteBeginTransaction(pParse,yymsp[0].minor.yy92);}
#line 6311 "parse.c"
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
#line 6331 "parse.c"
        /* No destructor defined for COMMIT */
        /* No destructor defined for trans_opt */
        break;
      case 12:
        YYTRACE("cmd ::= END trans_opt")
#line 65 "parse.y"
{sqliteCommitTransaction(pParse);}
#line 6339 "parse.c"
        /* No destructor defined for END */
        /* No destructor defined for trans_opt */
        break;
      case 13:
        YYTRACE("cmd ::= ROLLBACK trans_opt")
#line 66 "parse.y"
{sqliteRollbackTransaction(pParse);}
#line 6347 "parse.c"
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
#line 71 "parse.y"
{
   sqliteStartTable(pParse,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy98,yymsp[-2].minor.yy92);
}
#line 6362 "parse.c"
        /* No destructor defined for TABLE */
        break;
      case 16:
        YYTRACE("temp ::= TEMP")
#line 75 "parse.y"
{yygotominor.yy92 = 1;}
#line 6369 "parse.c"
        /* No destructor defined for TEMP */
        break;
      case 17:
        YYTRACE("temp ::=")
#line 76 "parse.y"
{yygotominor.yy92 = 0;}
#line 6376 "parse.c"
        break;
      case 18:
        YYTRACE("create_table_args ::= LP columnlist conslist_opt RP")
#line 77 "parse.y"
{
  sqliteEndTable(pParse,&yymsp[0].minor.yy0,0);
}
#line 6384 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for columnlist */
        /* No destructor defined for conslist_opt */
        break;
      case 19:
        YYTRACE("create_table_args ::= AS select")
#line 80 "parse.y"
{
  sqliteEndTable(pParse,0,yymsp[0].minor.yy299);
  sqliteSelectDelete(yymsp[0].minor.yy299);
}
#line 6396 "parse.c"
        /* No destructor defined for AS */
        break;
      case 20:
        YYTRACE("columnlist ::= columnlist COMMA column")
        /* No destructor defined for columnlist */
        /* No destructor defined for COMMA */
        /* No destructor defined for column */
        break;
      case 21:
        YYTRACE("columnlist ::= column")
        /* No destructor defined for column */
        break;
      case 22:
        YYTRACE("column ::= columnid type carglist")
        /* No destructor defined for columnid */
        /* No destructor defined for type */
        /* No destructor defined for carglist */
        break;
      case 23:
        YYTRACE("columnid ::= ids")
#line 92 "parse.y"
{sqliteAddColumn(pParse,&yymsp[0].minor.yy98);}
#line 6419 "parse.c"
        break;
      case 24:
        YYTRACE("id ::= DESC")
#line 100 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6425 "parse.c"
        break;
      case 25:
        YYTRACE("id ::= ASC")
#line 101 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6431 "parse.c"
        break;
      case 26:
        YYTRACE("id ::= DELIMITERS")
#line 102 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6437 "parse.c"
        break;
      case 27:
        YYTRACE("id ::= EXPLAIN")
#line 103 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6443 "parse.c"
        break;
      case 28:
        YYTRACE("id ::= VACUUM")
#line 104 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6449 "parse.c"
        break;
      case 29:
        YYTRACE("id ::= BEGIN")
#line 105 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6455 "parse.c"
        break;
      case 30:
        YYTRACE("id ::= END")
#line 106 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6461 "parse.c"
        break;
      case 31:
        YYTRACE("id ::= PRAGMA")
#line 107 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6467 "parse.c"
        break;
      case 32:
        YYTRACE("id ::= CLUSTER")
#line 108 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6473 "parse.c"
        break;
      case 33:
        YYTRACE("id ::= ID")
#line 109 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6479 "parse.c"
        break;
      case 34:
        YYTRACE("id ::= TEMP")
#line 110 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6485 "parse.c"
        break;
      case 35:
        YYTRACE("id ::= OFFSET")
#line 111 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6491 "parse.c"
        break;
      case 36:
        YYTRACE("id ::= KEY")
#line 112 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6497 "parse.c"
        break;
      case 37:
        YYTRACE("id ::= ABORT")
#line 113 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6503 "parse.c"
        break;
      case 38:
        YYTRACE("id ::= IGNORE")
#line 114 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6509 "parse.c"
        break;
      case 39:
        YYTRACE("id ::= REPLACE")
#line 115 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6515 "parse.c"
        break;
      case 40:
        YYTRACE("id ::= FAIL")
#line 116 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6521 "parse.c"
        break;
      case 41:
        YYTRACE("id ::= CONFLICT")
#line 117 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6527 "parse.c"
        break;
      case 42:
        YYTRACE("ids ::= id")
#line 122 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy98;}
#line 6533 "parse.c"
        break;
      case 43:
        YYTRACE("ids ::= STRING")
#line 123 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 6539 "parse.c"
        break;
      case 44:
        YYTRACE("type ::=")
        break;
      case 45:
        YYTRACE("type ::= typename")
#line 126 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[0].minor.yy98,&yymsp[0].minor.yy98);}
#line 6548 "parse.c"
        break;
      case 46:
        YYTRACE("type ::= typename LP signed RP")
#line 127 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-3].minor.yy98,&yymsp[0].minor.yy0);}
#line 6554 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        break;
      case 47:
        YYTRACE("type ::= typename LP signed COMMA signed RP")
#line 129 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-5].minor.yy98,&yymsp[0].minor.yy0);}
#line 6562 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        /* No destructor defined for COMMA */
        /* No destructor defined for signed */
        break;
      case 48:
        YYTRACE("typename ::= ids")
#line 131 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy98;}
#line 6572 "parse.c"
        break;
      case 49:
        YYTRACE("typename ::= typename ids")
#line 132 "parse.y"
{yygotominor.yy98 = yymsp[-1].minor.yy98;}
#line 6578 "parse.c"
        /* No destructor defined for ids */
        break;
      case 50:
        YYTRACE("signed ::= INTEGER")
        /* No destructor defined for INTEGER */
        break;
      case 51:
        YYTRACE("signed ::= PLUS INTEGER")
        /* No destructor defined for PLUS */
        /* No destructor defined for INTEGER */
        break;
      case 52:
        YYTRACE("signed ::= MINUS INTEGER")
        /* No destructor defined for MINUS */
        /* No destructor defined for INTEGER */
        break;
      case 53:
        YYTRACE("carglist ::= carglist carg")
        /* No destructor defined for carglist */
        /* No destructor defined for carg */
        break;
      case 54:
        YYTRACE("carglist ::=")
        break;
      case 55:
        YYTRACE("carg ::= CONSTRAINT ids ccons")
        /* No destructor defined for CONSTRAINT */
        /* No destructor defined for ids */
        /* No destructor defined for ccons */
        break;
      case 56:
        YYTRACE("carg ::= ccons")
        /* No destructor defined for ccons */
        break;
      case 57:
        YYTRACE("carg ::= DEFAULT STRING")
#line 140 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 6617 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 58:
        YYTRACE("carg ::= DEFAULT ID")
#line 141 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 6624 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 59:
        YYTRACE("carg ::= DEFAULT INTEGER")
#line 142 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 6631 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 60:
        YYTRACE("carg ::= DEFAULT PLUS INTEGER")
#line 143 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 6638 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 61:
        YYTRACE("carg ::= DEFAULT MINUS INTEGER")
#line 144 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 6646 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 62:
        YYTRACE("carg ::= DEFAULT FLOAT")
#line 145 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 6654 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 63:
        YYTRACE("carg ::= DEFAULT PLUS FLOAT")
#line 146 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 6661 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 64:
        YYTRACE("carg ::= DEFAULT MINUS FLOAT")
#line 147 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 6669 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 65:
        YYTRACE("carg ::= DEFAULT NULL")
        /* No destructor defined for DEFAULT */
        /* No destructor defined for NULL */
        break;
      case 66:
        YYTRACE("ccons ::= NOT NULL onconf")
#line 153 "parse.y"
{sqliteAddNotNull(pParse, yymsp[0].minor.yy92);}
#line 6682 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for NULL */
        break;
      case 67:
        YYTRACE("ccons ::= PRIMARY KEY sortorder onconf")
#line 154 "parse.y"
{sqliteAddPrimaryKey(pParse,0,yymsp[0].minor.yy92);}
#line 6690 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for sortorder */
        break;
      case 68:
        YYTRACE("ccons ::= UNIQUE onconf")
#line 155 "parse.y"
{sqliteCreateIndex(pParse,0,0,0,yymsp[0].minor.yy92,0,0);}
#line 6699 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 69:
        YYTRACE("ccons ::= CHECK LP expr RP onconf")
        /* No destructor defined for CHECK */
        /* No destructor defined for LP */
  yy_destructor(116,&yymsp[-2].minor);
        /* No destructor defined for RP */
        /* No destructor defined for onconf */
        break;
      case 70:
        YYTRACE("conslist_opt ::=")
        break;
      case 71:
        YYTRACE("conslist_opt ::= COMMA conslist")
        /* No destructor defined for COMMA */
        /* No destructor defined for conslist */
        break;
      case 72:
        YYTRACE("conslist ::= conslist COMMA tcons")
        /* No destructor defined for conslist */
        /* No destructor defined for COMMA */
        /* No destructor defined for tcons */
        break;
      case 73:
        YYTRACE("conslist ::= conslist tcons")
        /* No destructor defined for conslist */
        /* No destructor defined for tcons */
        break;
      case 74:
        YYTRACE("conslist ::= tcons")
        /* No destructor defined for tcons */
        break;
      case 75:
        YYTRACE("tcons ::= CONSTRAINT ids")
        /* No destructor defined for CONSTRAINT */
        /* No destructor defined for ids */
        break;
      case 76:
        YYTRACE("tcons ::= PRIMARY KEY LP idxlist RP onconf")
#line 168 "parse.y"
{sqliteAddPrimaryKey(pParse,yymsp[-2].minor.yy50,yymsp[0].minor.yy92);}
#line 6742 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 77:
        YYTRACE("tcons ::= UNIQUE LP idxlist RP onconf")
#line 170 "parse.y"
{sqliteCreateIndex(pParse,0,0,yymsp[-2].minor.yy50,yymsp[0].minor.yy92,0,0);}
#line 6752 "parse.c"
        /* No destructor defined for UNIQUE */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 78:
        YYTRACE("tcons ::= CHECK expr onconf")
        /* No destructor defined for CHECK */
  yy_destructor(116,&yymsp[-1].minor);
        /* No destructor defined for onconf */
        break;
      case 79:
        YYTRACE("onconf ::=")
#line 179 "parse.y"
{ yygotominor.yy92 = OE_Default; }
#line 6767 "parse.c"
        break;
      case 80:
        YYTRACE("onconf ::= ON CONFLICT resolvetype")
#line 180 "parse.y"
{ yygotominor.yy92 = yymsp[0].minor.yy92; }
#line 6773 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for CONFLICT */
        break;
      case 81:
        YYTRACE("orconf ::=")
#line 181 "parse.y"
{ yygotominor.yy92 = OE_Default; }
#line 6781 "parse.c"
        break;
      case 82:
        YYTRACE("orconf ::= OR resolvetype")
#line 182 "parse.y"
{ yygotominor.yy92 = yymsp[0].minor.yy92; }
#line 6787 "parse.c"
        /* No destructor defined for OR */
        break;
      case 83:
        YYTRACE("resolvetype ::= ROLLBACK")
#line 183 "parse.y"
{ yygotominor.yy92 = OE_Rollback; }
#line 6794 "parse.c"
        /* No destructor defined for ROLLBACK */
        break;
      case 84:
        YYTRACE("resolvetype ::= ABORT")
#line 184 "parse.y"
{ yygotominor.yy92 = OE_Abort; }
#line 6801 "parse.c"
        /* No destructor defined for ABORT */
        break;
      case 85:
        YYTRACE("resolvetype ::= FAIL")
#line 185 "parse.y"
{ yygotominor.yy92 = OE_Fail; }
#line 6808 "parse.c"
        /* No destructor defined for FAIL */
        break;
      case 86:
        YYTRACE("resolvetype ::= IGNORE")
#line 186 "parse.y"
{ yygotominor.yy92 = OE_Ignore; }
#line 6815 "parse.c"
        /* No destructor defined for IGNORE */
        break;
      case 87:
        YYTRACE("resolvetype ::= REPLACE")
#line 187 "parse.y"
{ yygotominor.yy92 = OE_Replace; }
#line 6822 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 88:
        YYTRACE("cmd ::= DROP TABLE ids")
#line 191 "parse.y"
{sqliteDropTable(pParse,&yymsp[0].minor.yy98);}
#line 6829 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for TABLE */
        break;
      case 89:
        YYTRACE("cmd ::= select")
#line 195 "parse.y"
{
  sqliteSelect(pParse, yymsp[0].minor.yy299, SRT_Callback, 0);
  sqliteSelectDelete(yymsp[0].minor.yy299);
}
#line 6840 "parse.c"
        break;
      case 90:
        YYTRACE("select ::= oneselect")
#line 205 "parse.y"
{yygotominor.yy299 = yymsp[0].minor.yy299;}
#line 6846 "parse.c"
        break;
      case 91:
        YYTRACE("select ::= select multiselect_op oneselect")
#line 206 "parse.y"
{
  if( yymsp[0].minor.yy299 ){
    yymsp[0].minor.yy299->op = yymsp[-1].minor.yy92;
    yymsp[0].minor.yy299->pPrior = yymsp[-2].minor.yy299;
  }
  yygotominor.yy299 = yymsp[0].minor.yy299;
}
#line 6858 "parse.c"
        break;
      case 92:
        YYTRACE("multiselect_op ::= UNION")
#line 214 "parse.y"
{yygotominor.yy92 = TK_UNION;}
#line 6864 "parse.c"
        /* No destructor defined for UNION */
        break;
      case 93:
        YYTRACE("multiselect_op ::= UNION ALL")
#line 215 "parse.y"
{yygotominor.yy92 = TK_ALL;}
#line 6871 "parse.c"
        /* No destructor defined for UNION */
        /* No destructor defined for ALL */
        break;
      case 94:
        YYTRACE("multiselect_op ::= INTERSECT")
#line 216 "parse.y"
{yygotominor.yy92 = TK_INTERSECT;}
#line 6879 "parse.c"
        /* No destructor defined for INTERSECT */
        break;
      case 95:
        YYTRACE("multiselect_op ::= EXCEPT")
#line 217 "parse.y"
{yygotominor.yy92 = TK_EXCEPT;}
#line 6886 "parse.c"
        /* No destructor defined for EXCEPT */
        break;
      case 96:
        YYTRACE("oneselect ::= SELECT distinct selcollist from where_opt groupby_opt having_opt orderby_opt limit_opt")
#line 219 "parse.y"
{
  yygotominor.yy299 = sqliteSelectNew(yymsp[-6].minor.yy48,yymsp[-5].minor.yy50,yymsp[-4].minor.yy2,yymsp[-3].minor.yy48,yymsp[-2].minor.yy2,yymsp[-1].minor.yy48,yymsp[-7].minor.yy92,yymsp[0].minor.yy303.a,yymsp[0].minor.yy303.b);
}
#line 6895 "parse.c"
        /* No destructor defined for SELECT */
        break;
      case 97:
        YYTRACE("distinct ::= DISTINCT")
#line 227 "parse.y"
{yygotominor.yy92 = 1;}
#line 6902 "parse.c"
        /* No destructor defined for DISTINCT */
        break;
      case 98:
        YYTRACE("distinct ::= ALL")
#line 228 "parse.y"
{yygotominor.yy92 = 0;}
#line 6909 "parse.c"
        /* No destructor defined for ALL */
        break;
      case 99:
        YYTRACE("distinct ::=")
#line 229 "parse.y"
{yygotominor.yy92 = 0;}
#line 6916 "parse.c"
        break;
      case 100:
        YYTRACE("sclp ::= selcollist COMMA")
#line 240 "parse.y"
{yygotominor.yy48 = yymsp[-1].minor.yy48;}
#line 6922 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 101:
        YYTRACE("sclp ::=")
#line 241 "parse.y"
{yygotominor.yy48 = 0;}
#line 6929 "parse.c"
        break;
      case 102:
        YYTRACE("selcollist ::= sclp expr")
#line 242 "parse.y"
{yygotominor.yy48 = sqliteExprListAppend(yymsp[-1].minor.yy48,yymsp[0].minor.yy2,0);}
#line 6935 "parse.c"
        break;
      case 103:
        YYTRACE("selcollist ::= sclp expr as ids")
#line 243 "parse.y"
{yygotominor.yy48 = sqliteExprListAppend(yymsp[-3].minor.yy48,yymsp[-2].minor.yy2,&yymsp[0].minor.yy98);}
#line 6941 "parse.c"
        /* No destructor defined for as */
        break;
      case 104:
        YYTRACE("selcollist ::= sclp STAR")
#line 244 "parse.y"
{
  yygotominor.yy48 = sqliteExprListAppend(yymsp[-1].minor.yy48, sqliteExpr(TK_ALL, 0, 0, 0), 0);
}
#line 6950 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 105:
        YYTRACE("as ::=")
        break;
      case 106:
        YYTRACE("as ::= AS")
        /* No destructor defined for AS */
        break;
      case 107:
        YYTRACE("from ::= FROM seltablist")
#line 258 "parse.y"
{yygotominor.yy50 = yymsp[0].minor.yy50;}
#line 6964 "parse.c"
        /* No destructor defined for FROM */
        break;
      case 108:
        YYTRACE("stl_prefix ::= seltablist COMMA")
#line 259 "parse.y"
{yygotominor.yy50 = yymsp[-1].minor.yy50;}
#line 6971 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 109:
        YYTRACE("stl_prefix ::=")
#line 260 "parse.y"
{yygotominor.yy50 = 0;}
#line 6978 "parse.c"
        break;
      case 110:
        YYTRACE("seltablist ::= stl_prefix ids")
#line 261 "parse.y"
{yygotominor.yy50 = sqliteIdListAppend(yymsp[-1].minor.yy50,&yymsp[0].minor.yy98);}
#line 6984 "parse.c"
        break;
      case 111:
        YYTRACE("seltablist ::= stl_prefix ids as ids")
#line 262 "parse.y"
{
  yygotominor.yy50 = sqliteIdListAppend(yymsp[-3].minor.yy50,&yymsp[-2].minor.yy98);
  sqliteIdListAddAlias(yygotominor.yy50,&yymsp[0].minor.yy98);
}
#line 6993 "parse.c"
        /* No destructor defined for as */
        break;
      case 112:
        YYTRACE("seltablist ::= stl_prefix LP select RP")
#line 266 "parse.y"
{
  yygotominor.yy50 = sqliteIdListAppend(yymsp[-3].minor.yy50,0);
  yygotominor.yy50->a[yygotominor.yy50->nId-1].pSelect = yymsp[-1].minor.yy299;
}
#line 7003 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 113:
        YYTRACE("seltablist ::= stl_prefix LP select RP as ids")
#line 270 "parse.y"
{
  yygotominor.yy50 = sqliteIdListAppend(yymsp[-5].minor.yy50,0);
  yygotominor.yy50->a[yygotominor.yy50->nId-1].pSelect = yymsp[-3].minor.yy299;
  sqliteIdListAddAlias(yygotominor.yy50,&yymsp[0].minor.yy98);
}
#line 7015 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        /* No destructor defined for as */
        break;
      case 114:
        YYTRACE("orderby_opt ::=")
#line 283 "parse.y"
{yygotominor.yy48 = 0;}
#line 7024 "parse.c"
        break;
      case 115:
        YYTRACE("orderby_opt ::= ORDER BY sortlist")
#line 284 "parse.y"
{yygotominor.yy48 = yymsp[0].minor.yy48;}
#line 7030 "parse.c"
        /* No destructor defined for ORDER */
        /* No destructor defined for BY */
        break;
      case 116:
        YYTRACE("sortlist ::= sortlist COMMA sortitem sortorder")
#line 285 "parse.y"
{
  yygotominor.yy48 = sqliteExprListAppend(yymsp[-3].minor.yy48,yymsp[-1].minor.yy2,0);
  if( yygotominor.yy48 ) yygotominor.yy48->a[yygotominor.yy48->nExpr-1].sortOrder = yymsp[0].minor.yy92;  /* 0=ascending, 1=decending */
}
#line 7041 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 117:
        YYTRACE("sortlist ::= sortitem sortorder")
#line 289 "parse.y"
{
  yygotominor.yy48 = sqliteExprListAppend(0,yymsp[-1].minor.yy2,0);
  if( yygotominor.yy48 ) yygotominor.yy48->a[0].sortOrder = yymsp[0].minor.yy92;
}
#line 7051 "parse.c"
        break;
      case 118:
        YYTRACE("sortitem ::= expr")
#line 293 "parse.y"
{yygotominor.yy2 = yymsp[0].minor.yy2;}
#line 7057 "parse.c"
        break;
      case 119:
        YYTRACE("sortorder ::= ASC")
#line 297 "parse.y"
{yygotominor.yy92 = 0;}
#line 7063 "parse.c"
        /* No destructor defined for ASC */
        break;
      case 120:
        YYTRACE("sortorder ::= DESC")
#line 298 "parse.y"
{yygotominor.yy92 = 1;}
#line 7070 "parse.c"
        /* No destructor defined for DESC */
        break;
      case 121:
        YYTRACE("sortorder ::=")
#line 299 "parse.y"
{yygotominor.yy92 = 0;}
#line 7077 "parse.c"
        break;
      case 122:
        YYTRACE("groupby_opt ::=")
#line 303 "parse.y"
{yygotominor.yy48 = 0;}
#line 7083 "parse.c"
        break;
      case 123:
        YYTRACE("groupby_opt ::= GROUP BY exprlist")
#line 304 "parse.y"
{yygotominor.yy48 = yymsp[0].minor.yy48;}
#line 7089 "parse.c"
        /* No destructor defined for GROUP */
        /* No destructor defined for BY */
        break;
      case 124:
        YYTRACE("having_opt ::=")
#line 308 "parse.y"
{yygotominor.yy2 = 0;}
#line 7097 "parse.c"
        break;
      case 125:
        YYTRACE("having_opt ::= HAVING expr")
#line 309 "parse.y"
{yygotominor.yy2 = yymsp[0].minor.yy2;}
#line 7103 "parse.c"
        /* No destructor defined for HAVING */
        break;
      case 126:
        YYTRACE("limit_opt ::=")
#line 312 "parse.y"
{yygotominor.yy303.a = -1; yygotominor.yy303.b = 0;}
#line 7110 "parse.c"
        break;
      case 127:
        YYTRACE("limit_opt ::= LIMIT INTEGER")
#line 313 "parse.y"
{yygotominor.yy303.a = atoi(yymsp[0].minor.yy0.z); yygotominor.yy303.b = 0;}
#line 7116 "parse.c"
        /* No destructor defined for LIMIT */
        break;
      case 128:
        YYTRACE("limit_opt ::= LIMIT INTEGER limit_sep INTEGER")
#line 315 "parse.y"
{yygotominor.yy303.a = atoi(yymsp[-2].minor.yy0.z); yygotominor.yy303.b = atoi(yymsp[0].minor.yy0.z);}
#line 7123 "parse.c"
        /* No destructor defined for LIMIT */
        /* No destructor defined for limit_sep */
        break;
      case 129:
        YYTRACE("limit_sep ::= OFFSET")
        /* No destructor defined for OFFSET */
        break;
      case 130:
        YYTRACE("limit_sep ::= COMMA")
        /* No destructor defined for COMMA */
        break;
      case 131:
        YYTRACE("cmd ::= DELETE FROM ids where_opt")
#line 322 "parse.y"
{sqliteDeleteFrom(pParse, &yymsp[-1].minor.yy98, yymsp[0].minor.yy2);}
#line 7139 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 132:
        YYTRACE("where_opt ::=")
#line 327 "parse.y"
{yygotominor.yy2 = 0;}
#line 7147 "parse.c"
        break;
      case 133:
        YYTRACE("where_opt ::= WHERE expr")
#line 328 "parse.y"
{yygotominor.yy2 = yymsp[0].minor.yy2;}
#line 7153 "parse.c"
        /* No destructor defined for WHERE */
        break;
      case 134:
        YYTRACE("cmd ::= UPDATE orconf ids SET setlist where_opt")
#line 336 "parse.y"
{sqliteUpdate(pParse,&yymsp[-3].minor.yy98,yymsp[-1].minor.yy48,yymsp[0].minor.yy2,yymsp[-4].minor.yy92);}
#line 7160 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 135:
        YYTRACE("setlist ::= setlist COMMA ids EQ expr")
#line 339 "parse.y"
{yygotominor.yy48 = sqliteExprListAppend(yymsp[-4].minor.yy48,yymsp[0].minor.yy2,&yymsp[-2].minor.yy98);}
#line 7168 "parse.c"
        /* No destructor defined for COMMA */
        /* No destructor defined for EQ */
        break;
      case 136:
        YYTRACE("setlist ::= ids EQ expr")
#line 340 "parse.y"
{yygotominor.yy48 = sqliteExprListAppend(0,yymsp[0].minor.yy2,&yymsp[-2].minor.yy98);}
#line 7176 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 137:
        YYTRACE("cmd ::= insert_cmd INTO ids inscollist_opt VALUES LP itemlist RP")
#line 345 "parse.y"
{sqliteInsert(pParse, &yymsp[-5].minor.yy98, yymsp[-1].minor.yy48, 0, yymsp[-4].minor.yy50, yymsp[-7].minor.yy92);}
#line 7183 "parse.c"
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 138:
        YYTRACE("cmd ::= insert_cmd INTO ids inscollist_opt select")
#line 347 "parse.y"
{sqliteInsert(pParse, &yymsp[-2].minor.yy98, 0, yymsp[0].minor.yy299, yymsp[-1].minor.yy50, yymsp[-4].minor.yy92);}
#line 7193 "parse.c"
        /* No destructor defined for INTO */
        break;
      case 139:
        YYTRACE("insert_cmd ::= INSERT orconf")
#line 350 "parse.y"
{yygotominor.yy92 = yymsp[0].minor.yy92;}
#line 7200 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 140:
        YYTRACE("insert_cmd ::= REPLACE")
#line 351 "parse.y"
{yygotominor.yy92 = OE_Replace;}
#line 7207 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 141:
        YYTRACE("itemlist ::= itemlist COMMA expr")
#line 357 "parse.y"
{yygotominor.yy48 = sqliteExprListAppend(yymsp[-2].minor.yy48,yymsp[0].minor.yy2,0);}
#line 7214 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 142:
        YYTRACE("itemlist ::= expr")
#line 358 "parse.y"
{yygotominor.yy48 = sqliteExprListAppend(0,yymsp[0].minor.yy2,0);}
#line 7221 "parse.c"
        break;
      case 143:
        YYTRACE("inscollist_opt ::=")
#line 365 "parse.y"
{yygotominor.yy50 = 0;}
#line 7227 "parse.c"
        break;
      case 144:
        YYTRACE("inscollist_opt ::= LP inscollist RP")
#line 366 "parse.y"
{yygotominor.yy50 = yymsp[-1].minor.yy50;}
#line 7233 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 145:
        YYTRACE("inscollist ::= inscollist COMMA ids")
#line 367 "parse.y"
{yygotominor.yy50 = sqliteIdListAppend(yymsp[-2].minor.yy50,&yymsp[0].minor.yy98);}
#line 7241 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 146:
        YYTRACE("inscollist ::= ids")
#line 368 "parse.y"
{yygotominor.yy50 = sqliteIdListAppend(0,&yymsp[0].minor.yy98);}
#line 7248 "parse.c"
        break;
      case 147:
        YYTRACE("expr ::= LP expr RP")
#line 386 "parse.y"
{yygotominor.yy2 = yymsp[-1].minor.yy2; sqliteExprSpan(yygotominor.yy2,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);}
#line 7254 "parse.c"
        break;
      case 148:
        YYTRACE("expr ::= NULL")
#line 387 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_NULL, 0, 0, &yymsp[0].minor.yy0);}
#line 7260 "parse.c"
        break;
      case 149:
        YYTRACE("expr ::= id")
#line 388 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy98);}
#line 7266 "parse.c"
        break;
      case 150:
        YYTRACE("expr ::= ids DOT ids")
#line 389 "parse.y"
{
  Expr *temp1 = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy98);
  Expr *temp2 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy98);
  yygotominor.yy2 = sqliteExpr(TK_DOT, temp1, temp2, 0);
}
#line 7276 "parse.c"
        /* No destructor defined for DOT */
        break;
      case 151:
        YYTRACE("expr ::= INTEGER")
#line 394 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_INTEGER, 0, 0, &yymsp[0].minor.yy0);}
#line 7283 "parse.c"
        break;
      case 152:
        YYTRACE("expr ::= FLOAT")
#line 395 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_FLOAT, 0, 0, &yymsp[0].minor.yy0);}
#line 7289 "parse.c"
        break;
      case 153:
        YYTRACE("expr ::= STRING")
#line 396 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_STRING, 0, 0, &yymsp[0].minor.yy0);}
#line 7295 "parse.c"
        break;
      case 154:
        YYTRACE("expr ::= ID LP exprlist RP")
#line 397 "parse.y"
{
  yygotominor.yy2 = sqliteExprFunction(yymsp[-1].minor.yy48, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 7304 "parse.c"
        /* No destructor defined for LP */
        break;
      case 155:
        YYTRACE("expr ::= ID LP STAR RP")
#line 401 "parse.y"
{
  yygotominor.yy2 = sqliteExprFunction(0, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 7314 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for STAR */
        break;
      case 156:
        YYTRACE("expr ::= expr AND expr")
#line 405 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_AND, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7322 "parse.c"
        /* No destructor defined for AND */
        break;
      case 157:
        YYTRACE("expr ::= expr OR expr")
#line 406 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_OR, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7329 "parse.c"
        /* No destructor defined for OR */
        break;
      case 158:
        YYTRACE("expr ::= expr LT expr")
#line 407 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_LT, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7336 "parse.c"
        /* No destructor defined for LT */
        break;
      case 159:
        YYTRACE("expr ::= expr GT expr")
#line 408 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_GT, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7343 "parse.c"
        /* No destructor defined for GT */
        break;
      case 160:
        YYTRACE("expr ::= expr LE expr")
#line 409 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_LE, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7350 "parse.c"
        /* No destructor defined for LE */
        break;
      case 161:
        YYTRACE("expr ::= expr GE expr")
#line 410 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_GE, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7357 "parse.c"
        /* No destructor defined for GE */
        break;
      case 162:
        YYTRACE("expr ::= expr NE expr")
#line 411 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_NE, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7364 "parse.c"
        /* No destructor defined for NE */
        break;
      case 163:
        YYTRACE("expr ::= expr EQ expr")
#line 412 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_EQ, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7371 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 164:
        YYTRACE("expr ::= expr BITAND expr")
#line 413 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_BITAND, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7378 "parse.c"
        /* No destructor defined for BITAND */
        break;
      case 165:
        YYTRACE("expr ::= expr BITOR expr")
#line 414 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_BITOR, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7385 "parse.c"
        /* No destructor defined for BITOR */
        break;
      case 166:
        YYTRACE("expr ::= expr LSHIFT expr")
#line 415 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_LSHIFT, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7392 "parse.c"
        /* No destructor defined for LSHIFT */
        break;
      case 167:
        YYTRACE("expr ::= expr RSHIFT expr")
#line 416 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_RSHIFT, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7399 "parse.c"
        /* No destructor defined for RSHIFT */
        break;
      case 168:
        YYTRACE("expr ::= expr LIKE expr")
#line 417 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_LIKE, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7406 "parse.c"
        /* No destructor defined for LIKE */
        break;
      case 169:
        YYTRACE("expr ::= expr NOT LIKE expr")
#line 418 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_LIKE, yymsp[-3].minor.yy2, yymsp[0].minor.yy2, 0);
  yygotominor.yy2 = sqliteExpr(TK_NOT, yygotominor.yy2, 0, 0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-3].minor.yy2->span,&yymsp[0].minor.yy2->span);
}
#line 7417 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for LIKE */
        break;
      case 170:
        YYTRACE("expr ::= expr GLOB expr")
#line 423 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_GLOB,yymsp[-2].minor.yy2,yymsp[0].minor.yy2,0);}
#line 7425 "parse.c"
        /* No destructor defined for GLOB */
        break;
      case 171:
        YYTRACE("expr ::= expr NOT GLOB expr")
#line 424 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_GLOB, yymsp[-3].minor.yy2, yymsp[0].minor.yy2, 0);
  yygotominor.yy2 = sqliteExpr(TK_NOT, yygotominor.yy2, 0, 0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-3].minor.yy2->span,&yymsp[0].minor.yy2->span);
}
#line 7436 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for GLOB */
        break;
      case 172:
        YYTRACE("expr ::= expr PLUS expr")
#line 429 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_PLUS, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7444 "parse.c"
        /* No destructor defined for PLUS */
        break;
      case 173:
        YYTRACE("expr ::= expr MINUS expr")
#line 430 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_MINUS, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7451 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 174:
        YYTRACE("expr ::= expr STAR expr")
#line 431 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_STAR, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7458 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 175:
        YYTRACE("expr ::= expr SLASH expr")
#line 432 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_SLASH, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7465 "parse.c"
        /* No destructor defined for SLASH */
        break;
      case 176:
        YYTRACE("expr ::= expr REM expr")
#line 433 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_REM, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7472 "parse.c"
        /* No destructor defined for REM */
        break;
      case 177:
        YYTRACE("expr ::= expr CONCAT expr")
#line 434 "parse.y"
{yygotominor.yy2 = sqliteExpr(TK_CONCAT, yymsp[-2].minor.yy2, yymsp[0].minor.yy2, 0);}
#line 7479 "parse.c"
        /* No destructor defined for CONCAT */
        break;
      case 178:
        YYTRACE("expr ::= expr ISNULL")
#line 435 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_ISNULL, yymsp[-1].minor.yy2, 0, 0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-1].minor.yy2->span,&yymsp[0].minor.yy0);
}
#line 7489 "parse.c"
        break;
      case 179:
        YYTRACE("expr ::= expr IS NULL")
#line 439 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_ISNULL, yymsp[-2].minor.yy2, 0, 0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-2].minor.yy2->span,&yymsp[0].minor.yy0);
}
#line 7498 "parse.c"
        /* No destructor defined for IS */
        break;
      case 180:
        YYTRACE("expr ::= expr NOTNULL")
#line 443 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_NOTNULL, yymsp[-1].minor.yy2, 0, 0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-1].minor.yy2->span,&yymsp[0].minor.yy0);
}
#line 7508 "parse.c"
        break;
      case 181:
        YYTRACE("expr ::= expr NOT NULL")
#line 447 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_NOTNULL, yymsp[-2].minor.yy2, 0, 0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-2].minor.yy2->span,&yymsp[0].minor.yy0);
}
#line 7517 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 182:
        YYTRACE("expr ::= expr IS NOT NULL")
#line 451 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_NOTNULL, yymsp[-3].minor.yy2, 0, 0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-3].minor.yy2->span,&yymsp[0].minor.yy0);
}
#line 7527 "parse.c"
        /* No destructor defined for IS */
        /* No destructor defined for NOT */
        break;
      case 183:
        YYTRACE("expr ::= NOT expr")
#line 455 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_NOT, yymsp[0].minor.yy2, 0, 0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy2->span);
}
#line 7538 "parse.c"
        break;
      case 184:
        YYTRACE("expr ::= BITNOT expr")
#line 459 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_BITNOT, yymsp[0].minor.yy2, 0, 0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy2->span);
}
#line 7547 "parse.c"
        break;
      case 185:
        YYTRACE("expr ::= MINUS expr")
#line 463 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_UMINUS, yymsp[0].minor.yy2, 0, 0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy2->span);
}
#line 7556 "parse.c"
        break;
      case 186:
        YYTRACE("expr ::= PLUS expr")
#line 467 "parse.y"
{
  yygotominor.yy2 = yymsp[0].minor.yy2;
  sqliteExprSpan(yygotominor.yy2,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy2->span);
}
#line 7565 "parse.c"
        break;
      case 187:
        YYTRACE("expr ::= LP select RP")
#line 471 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_SELECT, 0, 0, 0);
  if( yygotominor.yy2 ) yygotominor.yy2->pSelect = yymsp[-1].minor.yy299;
  sqliteExprSpan(yygotominor.yy2,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);
}
#line 7575 "parse.c"
        break;
      case 188:
        YYTRACE("expr ::= expr BETWEEN expr AND expr")
#line 476 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy2, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy2, 0);
  yygotominor.yy2 = sqliteExpr(TK_BETWEEN, yymsp[-4].minor.yy2, 0, 0);
  if( yygotominor.yy2 ) yygotominor.yy2->pList = pList;
  sqliteExprSpan(yygotominor.yy2,&yymsp[-4].minor.yy2->span,&yymsp[0].minor.yy2->span);
}
#line 7587 "parse.c"
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 189:
        YYTRACE("expr ::= expr NOT BETWEEN expr AND expr")
#line 483 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy2, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy2, 0);
  yygotominor.yy2 = sqliteExpr(TK_BETWEEN, yymsp[-5].minor.yy2, 0, 0);
  if( yygotominor.yy2 ) yygotominor.yy2->pList = pList;
  yygotominor.yy2 = sqliteExpr(TK_NOT, yygotominor.yy2, 0, 0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-5].minor.yy2->span,&yymsp[0].minor.yy2->span);
}
#line 7602 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 190:
        YYTRACE("expr ::= expr IN LP exprlist RP")
#line 491 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_IN, yymsp[-4].minor.yy2, 0, 0);
  if( yygotominor.yy2 ) yygotominor.yy2->pList = yymsp[-1].minor.yy48;
  sqliteExprSpan(yygotominor.yy2,&yymsp[-4].minor.yy2->span,&yymsp[0].minor.yy0);
}
#line 7615 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 191:
        YYTRACE("expr ::= expr IN LP select RP")
#line 496 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_IN, yymsp[-4].minor.yy2, 0, 0);
  if( yygotominor.yy2 ) yygotominor.yy2->pSelect = yymsp[-1].minor.yy299;
  sqliteExprSpan(yygotominor.yy2,&yymsp[-4].minor.yy2->span,&yymsp[0].minor.yy0);
}
#line 7627 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 192:
        YYTRACE("expr ::= expr NOT IN LP exprlist RP")
#line 501 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_IN, yymsp[-5].minor.yy2, 0, 0);
  if( yygotominor.yy2 ) yygotominor.yy2->pList = yymsp[-1].minor.yy48;
  yygotominor.yy2 = sqliteExpr(TK_NOT, yygotominor.yy2, 0, 0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-5].minor.yy2->span,&yymsp[0].minor.yy0);
}
#line 7640 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 193:
        YYTRACE("expr ::= expr NOT IN LP select RP")
#line 507 "parse.y"
{
  yygotominor.yy2 = sqliteExpr(TK_IN, yymsp[-5].minor.yy2, 0, 0);
  if( yygotominor.yy2 ) yygotominor.yy2->pSelect = yymsp[-1].minor.yy299;
  yygotominor.yy2 = sqliteExpr(TK_NOT, yygotominor.yy2, 0, 0);
  sqliteExprSpan(yygotominor.yy2,&yymsp[-5].minor.yy2->span,&yymsp[0].minor.yy0);
}
#line 7654 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 194:
        YYTRACE("exprlist ::= exprlist COMMA expritem")
#line 522 "parse.y"
{yygotominor.yy48 = sqliteExprListAppend(yymsp[-2].minor.yy48,yymsp[0].minor.yy2,0);}
#line 7663 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 195:
        YYTRACE("exprlist ::= expritem")
#line 523 "parse.y"
{yygotominor.yy48 = sqliteExprListAppend(0,yymsp[0].minor.yy2,0);}
#line 7670 "parse.c"
        break;
      case 196:
        YYTRACE("expritem ::= expr")
#line 524 "parse.y"
{yygotominor.yy2 = yymsp[0].minor.yy2;}
#line 7676 "parse.c"
        break;
      case 197:
        YYTRACE("expritem ::=")
#line 525 "parse.y"
{yygotominor.yy2 = 0;}
#line 7682 "parse.c"
        break;
      case 198:
        YYTRACE("cmd ::= CREATE uniqueflag INDEX ids ON ids LP idxlist RP onconf")
#line 530 "parse.y"
{
  if( yymsp[-8].minor.yy92!=OE_None ) yymsp[-8].minor.yy92 = yymsp[0].minor.yy92;
  if( yymsp[-8].minor.yy92==OE_Default) yymsp[-8].minor.yy92 = OE_Abort;
  sqliteCreateIndex(pParse, &yymsp[-6].minor.yy98, &yymsp[-4].minor.yy98, yymsp[-2].minor.yy50, yymsp[-8].minor.yy92, &yymsp[-9].minor.yy0, &yymsp[-1].minor.yy0);
}
#line 7692 "parse.c"
        /* No destructor defined for INDEX */
        /* No destructor defined for ON */
        /* No destructor defined for LP */
        break;
      case 199:
        YYTRACE("uniqueflag ::= UNIQUE")
#line 537 "parse.y"
{ yygotominor.yy92 = OE_Abort; }
#line 7701 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 200:
        YYTRACE("uniqueflag ::=")
#line 538 "parse.y"
{ yygotominor.yy92 = OE_None; }
#line 7708 "parse.c"
        break;
      case 201:
        YYTRACE("idxlist ::= idxlist COMMA idxitem")
#line 545 "parse.y"
{yygotominor.yy50 = sqliteIdListAppend(yymsp[-2].minor.yy50,&yymsp[0].minor.yy98);}
#line 7714 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 202:
        YYTRACE("idxlist ::= idxitem")
#line 547 "parse.y"
{yygotominor.yy50 = sqliteIdListAppend(0,&yymsp[0].minor.yy98);}
#line 7721 "parse.c"
        break;
      case 203:
        YYTRACE("idxitem ::= ids")
#line 548 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy98;}
#line 7727 "parse.c"
        break;
      case 204:
        YYTRACE("cmd ::= DROP INDEX ids")
#line 553 "parse.y"
{sqliteDropIndex(pParse, &yymsp[0].minor.yy98);}
#line 7733 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for INDEX */
        break;
      case 205:
        YYTRACE("cmd ::= COPY orconf ids FROM ids USING DELIMITERS STRING")
#line 559 "parse.y"
{sqliteCopy(pParse,&yymsp[-5].minor.yy98,&yymsp[-3].minor.yy98,&yymsp[0].minor.yy0,yymsp[-6].minor.yy92);}
#line 7741 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        /* No destructor defined for USING */
        /* No destructor defined for DELIMITERS */
        break;
      case 206:
        YYTRACE("cmd ::= COPY orconf ids FROM ids")
#line 561 "parse.y"
{sqliteCopy(pParse,&yymsp[-2].minor.yy98,&yymsp[0].minor.yy98,0,yymsp[-3].minor.yy92);}
#line 7751 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        break;
      case 207:
        YYTRACE("cmd ::= VACUUM")
#line 565 "parse.y"
{sqliteVacuum(pParse,0);}
#line 7759 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 208:
        YYTRACE("cmd ::= VACUUM ids")
#line 566 "parse.y"
{sqliteVacuum(pParse,&yymsp[0].minor.yy98);}
#line 7766 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 209:
        YYTRACE("cmd ::= PRAGMA ids EQ ids")
#line 570 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy98,&yymsp[0].minor.yy98,0);}
#line 7773 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 210:
        YYTRACE("cmd ::= PRAGMA ids EQ ON")
#line 571 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy98,&yymsp[0].minor.yy0,0);}
#line 7781 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 211:
        YYTRACE("cmd ::= PRAGMA ids EQ plus_num")
#line 572 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy98,&yymsp[0].minor.yy98,0);}
#line 7789 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 212:
        YYTRACE("cmd ::= PRAGMA ids EQ minus_num")
#line 573 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy98,&yymsp[0].minor.yy98,1);}
#line 7797 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 213:
        YYTRACE("cmd ::= PRAGMA ids LP ids RP")
#line 574 "parse.y"
{sqlitePragma(pParse,&yymsp[-3].minor.yy98,&yymsp[-1].minor.yy98,0);}
#line 7805 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 214:
        YYTRACE("cmd ::= PRAGMA ids")
#line 575 "parse.y"
{sqlitePragma(pParse,&yymsp[0].minor.yy98,&yymsp[-1].minor.yy0,0);}
#line 7814 "parse.c"
        break;
      case 215:
        YYTRACE("plus_num ::= plus_opt number")
#line 576 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy98;}
#line 7820 "parse.c"
        /* No destructor defined for plus_opt */
        break;
      case 216:
        YYTRACE("minus_num ::= MINUS number")
#line 577 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy98;}
#line 7827 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 217:
        YYTRACE("number ::= INTEGER")
#line 578 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 7834 "parse.c"
        break;
      case 218:
        YYTRACE("number ::= FLOAT")
#line 579 "parse.y"
{yygotominor.yy98 = yymsp[0].minor.yy0;}
#line 7840 "parse.c"
        break;
      case 219:
        YYTRACE("plus_opt ::= PLUS")
        /* No destructor defined for PLUS */
        break;
      case 220:
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

#line 7894 "parse.c"
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
