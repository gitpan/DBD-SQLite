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
**    sqliteParserARG_SDECL     A static variable declaration for the %extra_argument
**    sqliteParserARG_PDECL     A parameter declaration for the %extra_argument
**    sqliteParserARG_STORE     Code to store %extra_argument into yypParser
**    sqliteParserARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
/*  */
#define YYCODETYPE unsigned char
#define YYNOCODE 162
#define YYACTIONTYPE unsigned short int
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
#define sqliteParserARG_SDECL Parse *pParse;
#define sqliteParserARG_PDECL ,Parse *pParse
#define sqliteParserARG_FETCH Parse *pParse = yypParser->pParse
#define sqliteParserARG_STORE yypParser->pParse = pParse
#define YYNSTATE 393
#define YYNRULE 223
#define YYERRORSYMBOL 115
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
  YYCODETYPE   next;        /* Next entry + 1. Zero at end of collision chain */
  YYACTIONTYPE action;      /* Action to take for this look-ahead */
};
typedef struct yyActionEntry yyActionEntry;
static const yyActionEntry yyActionTable[] = {
/* State 0 */
  {  50,   4, 358}, /*  1:                 INSERT shift  358 */
  {  76,   0, 360}, /*  2:                REPLACE shift  360 */
  { 127,   9, 617}, /*  3:                  input accept */
  {  25,   0, 321}, /*  4:                 DELETE shift  321 */
  { 104,   0, 388}, /*  5:                    cmd shift  388 */
  { 130,  10, 340}, /*  6:             insert_cmd shift  340 */
  {  81,  13, 390}, /*  7:                   SEMI shift  390 */
  {   7,   0,   6}, /*  8:                  BEGIN shift  6 */
  {  77,   0,  43}, /*  9:               ROLLBACK shift  43 */
  { 105,  16,   1}, /* 10:                cmdlist shift  1 */
  {  35,   0, 391}, /* 11:                EXPLAIN shift  391 */
  { 111,   0,  45}, /* 12:           create_table shift  45 */
  {  31,   0,  41}, /* 13:                    END shift  41 */
  { 138,   0,  78}, /* 14:              oneselect shift  78 */
  { 114,   0, 392}, /* 15:                   ecmd shift  392 */
  {  80,  18,  82}, /* 16:                 SELECT shift  82 */
  { 116,   0,   3}, /* 17:                explain shift  3 */
  {  30,   0, 313}, /* 18:                   DROP shift  313 */
  {  18,   0,  39}, /* 19:                 COMMIT shift  39 */
  {  94,   0, 325}, /* 20:                 UPDATE shift  325 */
  {  96,   0, 369}, /* 21:                 VACUUM shift  369 */
  { 146,  21, 320}, /* 22:                 select shift  320 */
  {  22,   0, 361}, /* 23:                   COPY shift  361 */
  {  73,  25, 371}, /* 24:                 PRAGMA shift  371 */
  {  23,   0, 294}, /* 25:                 CREATE shift  294 */
/* State 1 */
  {  96,   4, 369}, /*  1:                 VACUUM shift  369 */
  {  73,  13, 371}, /*  2:                 PRAGMA shift  371 */
  { 146,  14, 320}, /*  3:                 select shift  320 */
  {   0,   0, 393}, /*  4:                      $ reduce 0 */
  {  76,   0, 360}, /*  5:                REPLACE shift  360 */
  {  77,   0,  43}, /*  6:               ROLLBACK shift  43 */
  {  30,   0, 313}, /*  7:                   DROP shift  313 */
  {  31,  15,  41}, /*  8:                    END shift  41 */
  { 104,  17, 388}, /*  9:                    cmd shift  388 */
  {  81,   0, 390}, /* 10:                   SEMI shift  390 */
  { 130,   0, 340}, /* 11:             insert_cmd shift  340 */
  {  35,   0, 391}, /* 12:                EXPLAIN shift  391 */
  {  25,   0, 321}, /* 13:                 DELETE shift  321 */
  {  50,   0, 358}, /* 14:                 INSERT shift  358 */
  {   7,   0,   6}, /* 15:                  BEGIN shift  6 */
  { 111,   0,  45}, /* 16:           create_table shift  45 */
  {  80,   0,  82}, /* 17:                 SELECT shift  82 */
  { 114,  20,   2}, /* 18:                   ecmd shift  2 */
  { 138,  18,  78}, /* 19:              oneselect shift  78 */
  {  18,   0,  39}, /* 20:                 COMMIT shift  39 */
  { 116,   0,   3}, /* 21:                explain shift  3 */
  {  22,   0, 361}, /* 22:                   COPY shift  361 */
  {  94,  22, 325}, /* 23:                 UPDATE shift  325 */
  {  23,   0, 294}, /* 24:                 CREATE shift  294 */
/* State 3 */
  {  76,   0, 360}, /*  1:                REPLACE shift  360 */
  {  96,   3, 369}, /*  2:                 VACUUM shift  369 */
  {  77,   0,  43}, /*  3:               ROLLBACK shift  43 */
  {  22,   0, 361}, /*  4:                   COPY shift  361 */
  {  80,   9,  82}, /*  5:                 SELECT shift  82 */
  { 138,   0,  78}, /*  6:              oneselect shift  78 */
  {  25,   0, 321}, /*  7:                 DELETE shift  321 */
  {   7,   0,   6}, /*  8:                  BEGIN shift  6 */
  {  23,   0, 294}, /*  9:                 CREATE shift  294 */
  { 104,   0,   4}, /* 10:                    cmd shift  4 */
  {  31,   0,  41}, /* 11:                    END shift  41 */
  {  30,   0, 313}, /* 12:                   DROP shift  313 */
  {  50,  11, 358}, /* 13:                 INSERT shift  358 */
  { 146,   0, 320}, /* 14:                 select shift  320 */
  { 111,  16,  45}, /* 15:           create_table shift  45 */
  {  73,   0, 371}, /* 16:                 PRAGMA shift  371 */
  { 130,  15, 340}, /* 17:             insert_cmd shift  340 */
  {  18,   0,  39}, /* 18:                 COMMIT shift  39 */
  {  94,  18, 325}, /* 19:                 UPDATE shift  325 */
/* State 4 */
  {  81,   0,   5}, /*  1:                   SEMI shift  5 */
/* State 6 */
  { 156,   0,   7}, /*  1:              trans_opt shift  7 */
  {  89,   0,  17}, /*  2:            TRANSACTION shift  17 */
/* State 7 */
  {  81,   2, 472}, /*  1:                   SEMI reduce 79 */
  {  69,   0,   9}, /*  2:                     ON shift  9 */
  { 137,   0,   8}, /*  3:                 onconf shift  8 */
/* State 8 */
  {  81,   0, 400}, /*  1:                   SEMI reduce 7 */
/* State 9 */
  {  20,   0,  10}, /*  1:               CONFLICT shift  10 */
/* State 10 */
  {  36,   0,  14}, /*  1:                   FAIL shift  14 */
  {   1,   0,  13}, /*  2:                  ABORT shift  13 */
  {  46,   0,  15}, /*  3:                 IGNORE shift  15 */
  {  77,   0,  12}, /*  4:               ROLLBACK shift  12 */
  {  76,   3,  16}, /*  5:                REPLACE shift  16 */
  { 143,   4,  11}, /*  6:            resolvetype shift  11 */
/* State 17 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0,  18}, /* 20:                    ids shift  18 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 39 */
  { 156,   2,  40}, /*  1:              trans_opt shift  40 */
  {  81,   0, 401}, /*  2:                   SEMI reduce 8 */
  {  89,   0,  17}, /*  3:            TRANSACTION shift  17 */
/* State 40 */
  {  81,   0, 404}, /*  1:                   SEMI reduce 11 */
/* State 41 */
  { 156,   2,  42}, /*  1:              trans_opt shift  42 */
  {  81,   0, 401}, /*  2:                   SEMI reduce 8 */
  {  89,   0,  17}, /*  3:            TRANSACTION shift  17 */
/* State 42 */
  {  81,   0, 405}, /*  1:                   SEMI reduce 12 */
/* State 43 */
  { 156,   2,  44}, /*  1:              trans_opt shift  44 */
  {  81,   0, 401}, /*  2:                   SEMI reduce 8 */
  {  89,   0,  17}, /*  3:            TRANSACTION shift  17 */
/* State 44 */
  {  81,   0, 406}, /*  1:                   SEMI reduce 13 */
/* State 45 */
  {  60,   0,  47}, /*  1:                     LP shift  47 */
  { 112,   0,  46}, /*  2:      create_table_args shift  46 */
  {   5,   0, 292}, /*  3:                     AS shift  292 */
/* State 46 */
  {  81,   0, 407}, /*  1:                   SEMI reduce 14 */
/* State 47 */
  {  96,   0,  23}, /*  1:                 VACUUM shift  23 */
  {  73,   6,  26}, /*  2:                 PRAGMA shift  26 */
  {  26,   0,  21}, /*  3:             DELIMITERS shift  21 */
  { 123,  10,  37}, /*  4:                     id shift  37 */
  { 124,  14, 265}, /*  5:                    ids shift  265 */
  {   1,   0,  32}, /*  6:                  ABORT shift  32 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {  31,  16,  25}, /*  8:                    END shift  25 */
  {  56,   0,  31}, /*  9:                    KEY shift  31 */
  {  27,   0,  19}, /* 10:                   DESC shift  19 */
  { 106,   0, 291}, /* 11:                 column shift  291 */
  { 107,  18,  53}, /* 12:               columnid shift  53 */
  { 108,  19,  48}, /* 13:             columnlist shift  48 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  86,  20,  38}, /* 15:                 STRING shift  38 */
  {   7,   0,  24}, /* 16:                  BEGIN shift  24 */
  {  88,   0,  29}, /* 17:                   TEMP shift  29 */
  {  35,   0,  22}, /* 18:                EXPLAIN shift  22 */
  {  36,   0,  35}, /* 19:                   FAIL shift  35 */
  {  14,   0,  27}, /* 20:                CLUSTER shift  27 */
  {  68,  24,  30}, /* 21:                 OFFSET shift  30 */
  {  45,   0,  28}, /* 22:                     ID shift  28 */
  {  46,   0,  33}, /* 23:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 24:               CONFLICT shift  36 */
/* State 48 */
  {  78,   0, 463}, /*  1:                     RP reduce 70 */
  {  16,   0,  51}, /*  2:                  COMMA shift  51 */
  { 110,   0,  49}, /*  3:           conslist_opt shift  49 */
/* State 49 */
  {  78,   0,  50}, /*  1:                     RP shift  50 */
/* State 50 */
  {  81,   0, 411}, /*  1:                   SEMI reduce 18 */
/* State 51 */
  {   1,   0,  32}, /*  1:                  ABORT shift  32 */
  {  88,   1,  29}, /*  2:                   TEMP shift  29 */
  {  31,   0,  25}, /*  3:                    END shift  25 */
  {  35,   5,  22}, /*  4:                EXPLAIN shift  22 */
  {   6,   0,  20}, /*  5:                    ASC shift  20 */
  {  36,  12,  35}, /*  6:                   FAIL shift  35 */
  {  93,   4, 281}, /*  7:                 UNIQUE shift  281 */
  { 123,   6,  37}, /*  8:                     id shift  37 */
  { 124,   0, 265}, /*  9:                    ids shift  265 */
  { 154,  13, 290}, /* 10:                  tcons shift  290 */
  {  68,   0,  30}, /* 11:                 OFFSET shift  30 */
  {   7,   0,  24}, /* 12:                  BEGIN shift  24 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  13,   0, 286}, /* 14:                  CHECK shift  286 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  73,   0,  26}, /* 16:                 PRAGMA shift  26 */
  {  74,  24, 271}, /* 17:                PRIMARY shift  271 */
  {  46,   0,  33}, /* 18:                 IGNORE shift  33 */
  {  76,   0,  34}, /* 19:                REPLACE shift  34 */
  { 106,   0,  52}, /* 20:                 column shift  52 */
  { 107,  25,  53}, /* 21:               columnid shift  53 */
  {  21,   0, 269}, /* 22:             CONSTRAINT shift  269 */
  { 109,   0, 266}, /* 23:               conslist shift  266 */
  {  45,   0,  28}, /* 24:                     ID shift  28 */
  {  20,   0,  36}, /* 25:               CONFLICT shift  36 */
  {  27,   0,  19}, /* 26:                   DESC shift  19 */
  {  26,   0,  21}, /* 27:             DELIMITERS shift  21 */
  {  56,  26,  31}, /* 28:                    KEY shift  31 */
  {  86,   0,  38}, /* 29:                 STRING shift  38 */
/* State 53 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  73,   6,  26}, /*  3:                 PRAGMA shift  26 */
  {  26,   0,  21}, /*  4:             DELIMITERS shift  21 */
  {  96,   3,  23}, /*  5:                 VACUUM shift  23 */
  {  27,   0,  19}, /*  6:                   DESC shift  19 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {  76,  12,  34}, /*  8:                REPLACE shift  34 */
  { 123,  16,  37}, /*  9:                     id shift  37 */
  { 124,   0, 264}, /* 10:                    ids shift  264 */
  {  56,   0,  31}, /* 11:                    KEY shift  31 */
  {   7,   0,  24}, /* 12:                  BEGIN shift  24 */
  {  35,   0,  22}, /* 13:                EXPLAIN shift  22 */
  {  36,   0,  35}, /* 14:                   FAIL shift  35 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  31,   0,  25}, /* 16:                    END shift  25 */
  {  88,   0,  29}, /* 17:                   TEMP shift  29 */
  {  86,   0,  38}, /* 18:                 STRING shift  38 */
  {  20,   0,  36}, /* 19:               CONFLICT shift  36 */
  { 157,  17,  54}, /* 20:                   type shift  54 */
  { 158,  19, 251}, /* 21:               typename shift  251 */
  {  45,   0,  28}, /* 22:                     ID shift  28 */
  {  68,  22,  30}, /* 23:                 OFFSET shift  30 */
/* State 54 */
  { 102,   0,  55}, /*  1:               carglist shift  55 */
/* State 55 */
  {  24,   0, 239}, /*  1:                DEFAULT shift  239 */
  {  65,   0,  60}, /*  2:                    NOT shift  60 */
  {  74,   0,  63}, /*  3:                PRIMARY shift  63 */
  {  93,   5,  69}, /*  4:                 UNIQUE shift  69 */
  {  21,   7,  57}, /*  5:             CONSTRAINT shift  57 */
  { 101,   4,  56}, /*  6:                   carg shift  56 */
  {  13,   0,  71}, /*  7:                  CHECK shift  71 */
  { 103,   0, 238}, /*  8:                  ccons shift  238 */
/* State 57 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0,  58}, /* 20:                    ids shift  58 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 58 */
  {  65,   0,  60}, /*  1:                    NOT shift  60 */
  {  93,   3,  69}, /*  2:                 UNIQUE shift  69 */
  {  13,   0,  71}, /*  3:                  CHECK shift  71 */
  { 103,   2,  59}, /*  4:                  ccons shift  59 */
  {  74,   0,  63}, /*  5:                PRIMARY shift  63 */
/* State 60 */
  {  67,   0,  61}, /*  1:                   NULL shift  61 */
/* State 61 */
  {  69,   0,   9}, /*  1:                     ON shift  9 */
  { 137,   1,  62}, /*  2:                 onconf shift  62 */
/* State 63 */
  {  56,   0,  64}, /*  1:                    KEY shift  64 */
/* State 64 */
  {  27,   2,  68}, /*  1:                   DESC shift  68 */
  {   6,   0,  67}, /*  2:                    ASC shift  67 */
  { 152,   0,  65}, /*  3:              sortorder shift  65 */
/* State 65 */
  {  69,   0,   9}, /*  1:                     ON shift  9 */
  { 137,   1,  66}, /*  2:                 onconf shift  66 */
/* State 69 */
  {  69,   0,   9}, /*  1:                     ON shift  9 */
  { 137,   1,  70}, /*  2:                 onconf shift  70 */
/* State 71 */
  {  60,   0,  72}, /*  1:                     LP shift  72 */
/* State 72 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 235}, /* 28:                   expr shift  235 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 73 */
  {  60,   0,  74}, /*  1:                     LP shift  74 */
/* State 74 */
  {   1,   0,  32}, /*  1:                  ABORT shift  32 */
  {  67,   1, 105}, /*  2:                   NULL shift  105 */
  {  68,   6,  30}, /*  3:                 OFFSET shift  30 */
  {  36,   0,  35}, /*  4:                   FAIL shift  35 */
  {  37,   0, 110}, /*  5:                  FLOAT shift  110 */
  {  35,   0,  22}, /*  6:                EXPLAIN shift  22 */
  {  72,   9, 178}, /*  7:                   PLUS shift  178 */
  {  73,  10,  26}, /*  8:                 PRAGMA shift  26 */
  {   6,   0,  20}, /*  9:                    ASC shift  20 */
  {   7,   0,  24}, /* 10:                  BEGIN shift  24 */
  {  76,  12,  34}, /* 11:                REPLACE shift  34 */
  {  10,   0, 174}, /* 12:                 BITNOT shift  174 */
  {  45,   0,  73}, /* 13:                     ID shift  73 */
  {  46,   0,  33}, /* 14:                 IGNORE shift  33 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  51,   0, 109}, /* 16:                INTEGER shift  109 */
  {  85,   0, 233}, /* 17:                   STAR shift  233 */
  {  86,  22,  76}, /* 18:                 STRING shift  76 */
  { 117,  16, 171}, /* 19:                   expr shift  171 */
  { 118,  17, 184}, /* 20:               expritem shift  184 */
  { 119,  18, 231}, /* 21:               exprlist shift  231 */
  {  20,   0,  36}, /* 22:               CONFLICT shift  36 */
  {  88,   0,  29}, /* 23:                   TEMP shift  29 */
  {  56,   0,  31}, /* 24:                    KEY shift  31 */
  { 123,   0,  75}, /* 25:                     id shift  75 */
  { 124,   0, 106}, /* 26:                    ids shift  106 */
  {  26,   0,  21}, /* 27:             DELIMITERS shift  21 */
  {  60,  29,  77}, /* 28:                     LP shift  77 */
  {  27,   0,  19}, /* 29:                   DESC shift  19 */
  {  63,   0, 176}, /* 30:                  MINUS shift  176 */
  {  96,  30,  23}, /* 31:                 VACUUM shift  23 */
  {  31,   0,  25}, /* 32:                    END shift  25 */
  {  65,   0, 172}, /* 33:                    NOT shift  172 */
/* State 75 */
  {  29,   0, 435}, /*  1:                    DOT reduce 42 */
/* State 76 */
  {  29,   0, 436}, /*  1:                    DOT reduce 43 */
/* State 77 */
  {   1,   0,  32}, /*  1:                  ABORT shift  32 */
  {  67,   1, 105}, /*  2:                   NULL shift  105 */
  {  68,   6,  30}, /*  3:                 OFFSET shift  30 */
  {  36,   0,  35}, /*  4:                   FAIL shift  35 */
  {  37,   0, 110}, /*  5:                  FLOAT shift  110 */
  {  35,   0,  22}, /*  6:                EXPLAIN shift  22 */
  { 138,   9,  78}, /*  7:              oneselect shift  78 */
  {  73,  10,  26}, /*  8:                 PRAGMA shift  26 */
  {  72,  12, 178}, /*  9:                   PLUS shift  178 */
  {   7,   0,  24}, /* 10:                  BEGIN shift  24 */
  {  76,  16,  34}, /* 11:                REPLACE shift  34 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  45,   0,  73}, /* 13:                     ID shift  73 */
  {  46,   0,  33}, /* 14:                 IGNORE shift  33 */
  { 146,  17,  79}, /* 15:                 select shift  79 */
  {  10,   0, 174}, /* 16:                 BITNOT shift  174 */
  {  80,  18,  82}, /* 17:                 SELECT shift  82 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 117,  20, 229}, /* 19:                   expr shift  229 */
  {  51,   0, 109}, /* 20:                INTEGER shift  109 */
  {  86,  22,  76}, /* 21:                 STRING shift  76 */
  {  20,   0,  36}, /* 22:               CONFLICT shift  36 */
  {  88,   0,  29}, /* 23:                   TEMP shift  29 */
  {  56,   0,  31}, /* 24:                    KEY shift  31 */
  { 123,   0,  75}, /* 25:                     id shift  75 */
  { 124,   0, 106}, /* 26:                    ids shift  106 */
  {  26,   0,  21}, /* 27:             DELIMITERS shift  21 */
  {  60,  29,  77}, /* 28:                     LP shift  77 */
  {  27,   0,  19}, /* 29:                   DESC shift  19 */
  {  63,   0, 176}, /* 30:                  MINUS shift  176 */
  {  96,  30,  23}, /* 31:                 VACUUM shift  23 */
  {  31,   0,  25}, /* 32:                    END shift  25 */
  {  65,   0, 172}, /* 33:                    NOT shift  172 */
/* State 79 */
  { 135,   0,  80}, /*  1:         multiselect_op shift  80 */
  {  52,   0, 168}, /*  2:              INTERSECT shift  168 */
  {  92,   2, 166}, /*  3:                  UNION shift  166 */
  {  78,   0, 228}, /*  4:                     RP shift  228 */
  {  34,   0, 169}, /*  5:                 EXCEPT shift  169 */
/* State 80 */
  { 138,   2,  81}, /*  1:              oneselect shift  81 */
  {  80,   0,  82}, /*  2:                 SELECT shift  82 */
/* State 82 */
  {   3,   0, 227}, /*  1:                    ALL shift  227 */
  {  28,   0, 226}, /*  2:               DISTINCT shift  226 */
  { 113,   0,  83}, /*  3:               distinct shift  83 */
/* State 83 */
  { 144,   0, 221}, /*  1:                   sclp shift  221 */
  { 145,   0,  84}, /*  2:             selcollist shift  84 */
/* State 84 */
  { 120,   0,  85}, /*  1:                   from shift  85 */
  {  16,   0, 207}, /*  2:                  COMMA shift  207 */
  {  38,   0, 208}, /*  3:                   FROM shift  208 */
/* State 85 */
  { 160,   0,  86}, /*  1:              where_opt shift  86 */
  {  99,   0, 205}, /*  2:                  WHERE shift  205 */
/* State 86 */
  {  42,   0, 202}, /*  1:                  GROUP shift  202 */
  { 121,   0,  87}, /*  2:            groupby_opt shift  87 */
/* State 87 */
  { 122,   2,  88}, /*  1:             having_opt shift  88 */
  {  44,   0, 200}, /*  2:                 HAVING shift  200 */
/* State 88 */
  { 140,   0,  89}, /*  1:            orderby_opt shift  89 */
  {  71,   0,  97}, /*  2:                  ORDER shift  97 */
/* State 89 */
  { 132,   0,  90}, /*  1:              limit_opt shift  90 */
  {  59,   0,  91}, /*  2:                  LIMIT shift  91 */
/* State 91 */
  {  51,   0,  92}, /*  1:                INTEGER shift  92 */
/* State 92 */
  {  16,   0,  96}, /*  1:                  COMMA shift  96 */
  { 133,   1,  93}, /*  2:              limit_sep shift  93 */
  {  68,   0,  95}, /*  3:                 OFFSET shift  95 */
/* State 93 */
  {  51,   0,  94}, /*  1:                INTEGER shift  94 */
/* State 95 */
  {  51,   0, 524}, /*  1:                INTEGER reduce 131 */
/* State 96 */
  {  51,   0, 525}, /*  1:                INTEGER reduce 132 */
/* State 97 */
  {  12,   0,  98}, /*  1:                     BY shift  98 */
/* State 98 */
  {  96,   0,  23}, /*  1:                 VACUUM shift  23 */
  {  65,   3, 172}, /*  2:                    NOT shift  172 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  {  67,  12, 105}, /*  4:                   NULL shift  105 */
  {  68,  16,  30}, /*  5:                 OFFSET shift  30 */
  {  37,   0, 110}, /*  6:                  FLOAT shift  110 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  72,   0, 178}, /*  9:                   PLUS shift  178 */
  {  73,   0,  26}, /* 10:                 PRAGMA shift  26 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  76,   0,  34}, /* 13:                REPLACE shift  34 */
  {  45,   0,  73}, /* 14:                     ID shift  73 */
  {  46,  17,  33}, /* 15:                 IGNORE shift  33 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  14,   0,  27}, /* 17:                CLUSTER shift  27 */
  {  86,   0,  76}, /* 18:                 STRING shift  76 */
  {  56,   0,  31}, /* 19:                    KEY shift  31 */
  {  51,   0, 109}, /* 20:                INTEGER shift  109 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  { 117,   0, 103}, /* 22:                   expr shift  103 */
  { 150,  18, 198}, /* 23:               sortitem shift  198 */
  { 151,   0,  99}, /* 24:               sortlist shift  99 */
  {  88,  19,  29}, /* 25:                   TEMP shift  29 */
  {  27,   0,  19}, /* 26:                   DESC shift  19 */
  {  26,   0,  21}, /* 27:             DELIMITERS shift  21 */
  { 123,  26,  75}, /* 28:                     id shift  75 */
  { 124,  30, 106}, /* 29:                    ids shift  106 */
  {  60,   0,  77}, /* 30:                     LP shift  77 */
  {  31,   0,  25}, /* 31:                    END shift  25 */
  {  63,  31, 176}, /* 32:                  MINUS shift  176 */
/* State 99 */
  {  16,   0, 100}, /*  1:                  COMMA shift  100 */
/* State 100 */
  { 124,   3, 106}, /*  1:                    ids shift  106 */
  {  63,   9, 176}, /*  2:                  MINUS shift  176 */
  {  31,   0,  25}, /*  3:                    END shift  25 */
  {  96,  10,  23}, /*  4:                 VACUUM shift  23 */
  {  35,   0,  22}, /*  5:                EXPLAIN shift  22 */
  {  67,  13, 105}, /*  6:                   NULL shift  105 */
  {  68,  14,  30}, /*  7:                 OFFSET shift  30 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {   1,   0,  32}, /*  9:                  ABORT shift  32 */
  {  65,   0, 172}, /* 10:                    NOT shift  172 */
  {  72,  17, 178}, /* 11:                   PLUS shift  178 */
  {  73,   0,  26}, /* 12:                 PRAGMA shift  26 */
  {  36,   0,  35}, /* 13:                   FAIL shift  35 */
  {  37,  18, 110}, /* 14:                  FLOAT shift  110 */
  {  76,  19,  34}, /* 15:                REPLACE shift  34 */
  {  46,   0,  33}, /* 16:                 IGNORE shift  33 */
  {  10,   0, 174}, /* 17:                 BITNOT shift  174 */
  {   6,   0,  20}, /* 18:                    ASC shift  20 */
  {  45,  20,  73}, /* 19:                     ID shift  73 */
  {  14,   0,  27}, /* 20:                CLUSTER shift  27 */
  {  51,  22, 109}, /* 21:                INTEGER shift  109 */
  {  20,   0,  36}, /* 22:               CONFLICT shift  36 */
  {  86,   0,  76}, /* 23:                 STRING shift  76 */
  {  88,  29,  29}, /* 24:                   TEMP shift  29 */
  { 117,  23, 103}, /* 25:                   expr shift  103 */
  {  56,   0,  31}, /* 26:                    KEY shift  31 */
  { 150,  24, 101}, /* 27:               sortitem shift  101 */
  {  27,   0,  19}, /* 28:                   DESC shift  19 */
  {  26,   0,  21}, /* 29:             DELIMITERS shift  21 */
  {  60,   0,  77}, /* 30:                     LP shift  77 */
  { 123,   0,  75}, /* 31:                     id shift  75 */
/* State 101 */
  {  27,   2,  68}, /*  1:                   DESC shift  68 */
  {   6,   0,  67}, /*  2:                    ASC shift  67 */
  { 152,   0, 102}, /*  3:              sortorder shift  102 */
/* State 103 */
  {  57,   0, 118}, /*  1:                     LE shift  118 */
  {  79,   0, 132}, /*  2:                 RSHIFT shift  132 */
  {  54,   0, 154}, /*  3:                     IS shift  154 */
  {  55,   0, 153}, /*  4:                 ISNULL shift  153 */
  {   4,   0, 104}, /*  5:                    AND shift  104 */
  {  83,   1, 147}, /*  6:                  SLASH shift  147 */
  {  58,   0, 134}, /*  7:                   LIKE shift  134 */
  {  85,  17, 145}, /*  8:                   STAR shift  145 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  61,  22, 130}, /* 10:                 LSHIFT shift  130 */
  {  62,   0, 114}, /* 11:                     LT shift  114 */
  {  63,  25, 143}, /* 12:                  MINUS shift  143 */
  {  64,   0, 122}, /* 13:                     NE shift  122 */
  {  65,   0, 136}, /* 14:                    NOT shift  136 */
  {  66,  26, 158}, /* 15:                NOTNULL shift  158 */
  {  41,   0, 139}, /* 16:                   GLOB shift  139 */
  {  33,   0, 124}, /* 17:                     EQ shift  124 */
  {  43,   0, 116}, /* 18:                     GT shift  116 */
  {  70,   0, 112}, /* 19:                     OR shift  112 */
  {  19,   0, 151}, /* 20:                 CONCAT shift  151 */
  {  72,   0, 141}, /* 21:                   PLUS shift  141 */
  {   9,   0, 126}, /* 22:                 BITAND shift  126 */
  {  48,   0, 163}, /* 23:                     IN shift  163 */
  {  75,   0, 149}, /* 24:                    REM shift  149 */
  {  11,   0, 128}, /* 25:                  BITOR shift  128 */
  {  40,   0, 120}, /* 26:                     GE shift  120 */
/* State 104 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 111}, /* 28:                   expr shift  111 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 106 */
  {  29,   0, 107}, /*  1:                    DOT shift  107 */
/* State 107 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 108}, /* 20:                    ids shift  108 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 111 */
  {  72,   2, 141}, /*  1:                   PLUS shift  141 */
  {  48,   0, 163}, /*  2:                     IN shift  163 */
  {  55,   0, 153}, /*  3:                 ISNULL shift  153 */
  {  75,   0, 149}, /*  4:                    REM shift  149 */
  {  33,   6, 124}, /*  5:                     EQ shift  124 */
  {   9,   0, 126}, /*  6:                 BITAND shift  126 */
  {  54,   0, 154}, /*  7:                     IS shift  154 */
  {  79,   3, 132}, /*  8:                 RSHIFT shift  132 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  57,   5, 118}, /* 10:                     LE shift  118 */
  {  58,   0, 134}, /* 11:                   LIKE shift  134 */
  {  83,  13, 147}, /* 12:                  SLASH shift  147 */
  {  11,   0, 128}, /* 13:                  BITOR shift  128 */
  {  85,  21, 145}, /* 14:                   STAR shift  145 */
  {  62,   0, 114}, /* 15:                     LT shift  114 */
  {  63,   0, 143}, /* 16:                  MINUS shift  143 */
  {  64,  22, 122}, /* 17:                     NE shift  122 */
  {  65,  23, 136}, /* 18:                    NOT shift  136 */
  {  66,   0, 158}, /* 19:                NOTNULL shift  158 */
  {  43,  24, 116}, /* 20:                     GT shift  116 */
  {  61,   0, 130}, /* 21:                 LSHIFT shift  130 */
  {  40,   0, 120}, /* 22:                     GE shift  120 */
  {  41,   0, 139}, /* 23:                   GLOB shift  139 */
  {  19,   0, 151}, /* 24:                 CONCAT shift  151 */
/* State 112 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 113}, /* 28:                   expr shift  113 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 113 */
  {  75,   0, 149}, /*  1:                    REM shift  149 */
  {  54,   3, 154}, /*  2:                     IS shift  154 */
  {   4,   0, 104}, /*  3:                    AND shift  104 */
  {  58,   7, 134}, /*  4:                   LIKE shift  134 */
  {  79,   2, 132}, /*  5:                 RSHIFT shift  132 */
  {  55,   0, 153}, /*  6:                 ISNULL shift  153 */
  {  33,  18, 124}, /*  7:                     EQ shift  124 */
  {  57,   0, 118}, /*  8:                     LE shift  118 */
  {  83,   4, 147}, /*  9:                  SLASH shift  147 */
  {   9,   0, 126}, /* 10:                 BITAND shift  126 */
  {  85,   0, 145}, /* 11:                   STAR shift  145 */
  {  61,  21, 130}, /* 12:                 LSHIFT shift  130 */
  {  62,   0, 114}, /* 13:                     LT shift  114 */
  {  63,   0, 143}, /* 14:                  MINUS shift  143 */
  {  64,   0, 122}, /* 15:                     NE shift  122 */
  {  65,  22, 136}, /* 16:                    NOT shift  136 */
  {  66,  25, 158}, /* 17:                NOTNULL shift  158 */
  {   8,   0, 159}, /* 18:                BETWEEN shift  159 */
  {  43,   0, 116}, /* 19:                     GT shift  116 */
  {  19,   0, 151}, /* 20:                 CONCAT shift  151 */
  {  11,   0, 128}, /* 21:                  BITOR shift  128 */
  {  40,   0, 120}, /* 22:                     GE shift  120 */
  {  72,   0, 141}, /* 23:                   PLUS shift  141 */
  {  48,   0, 163}, /* 24:                     IN shift  163 */
  {  41,   0, 139}, /* 25:                   GLOB shift  139 */
/* State 114 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 115}, /* 28:                   expr shift  115 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 115 */
  {  11,   0, 128}, /*  1:                  BITOR shift  128 */
  {  61,   1, 130}, /*  2:                 LSHIFT shift  130 */
  {  72,   0, 141}, /*  3:                   PLUS shift  141 */
  {  83,   5, 147}, /*  4:                  SLASH shift  147 */
  {  63,   0, 143}, /*  5:                  MINUS shift  143 */
  {  85,   7, 145}, /*  6:                   STAR shift  145 */
  {  75,   0, 149}, /*  7:                    REM shift  149 */
  {  19,   9, 151}, /*  8:                 CONCAT shift  151 */
  {   9,   0, 126}, /*  9:                 BITAND shift  126 */
  {  79,   8, 132}, /* 10:                 RSHIFT shift  132 */
/* State 116 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 117}, /* 28:                   expr shift  117 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 117 */
  {  11,   0, 128}, /*  1:                  BITOR shift  128 */
  {  61,   1, 130}, /*  2:                 LSHIFT shift  130 */
  {  72,   0, 141}, /*  3:                   PLUS shift  141 */
  {  83,   5, 147}, /*  4:                  SLASH shift  147 */
  {  63,   0, 143}, /*  5:                  MINUS shift  143 */
  {  85,   7, 145}, /*  6:                   STAR shift  145 */
  {  75,   0, 149}, /*  7:                    REM shift  149 */
  {  19,   9, 151}, /*  8:                 CONCAT shift  151 */
  {   9,   0, 126}, /*  9:                 BITAND shift  126 */
  {  79,   8, 132}, /* 10:                 RSHIFT shift  132 */
/* State 118 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 119}, /* 28:                   expr shift  119 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 119 */
  {  11,   0, 128}, /*  1:                  BITOR shift  128 */
  {  61,   1, 130}, /*  2:                 LSHIFT shift  130 */
  {  72,   0, 141}, /*  3:                   PLUS shift  141 */
  {  83,   5, 147}, /*  4:                  SLASH shift  147 */
  {  63,   0, 143}, /*  5:                  MINUS shift  143 */
  {  85,   7, 145}, /*  6:                   STAR shift  145 */
  {  75,   0, 149}, /*  7:                    REM shift  149 */
  {  19,   9, 151}, /*  8:                 CONCAT shift  151 */
  {   9,   0, 126}, /*  9:                 BITAND shift  126 */
  {  79,   8, 132}, /* 10:                 RSHIFT shift  132 */
/* State 120 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 121}, /* 28:                   expr shift  121 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 121 */
  {  11,   0, 128}, /*  1:                  BITOR shift  128 */
  {  61,   1, 130}, /*  2:                 LSHIFT shift  130 */
  {  72,   0, 141}, /*  3:                   PLUS shift  141 */
  {  83,   5, 147}, /*  4:                  SLASH shift  147 */
  {  63,   0, 143}, /*  5:                  MINUS shift  143 */
  {  85,   7, 145}, /*  6:                   STAR shift  145 */
  {  75,   0, 149}, /*  7:                    REM shift  149 */
  {  19,   9, 151}, /*  8:                 CONCAT shift  151 */
  {   9,   0, 126}, /*  9:                 BITAND shift  126 */
  {  79,   8, 132}, /* 10:                 RSHIFT shift  132 */
/* State 122 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 123}, /* 28:                   expr shift  123 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 123 */
  {  57,   4, 118}, /*  1:                     LE shift  118 */
  {  85,   1, 145}, /*  2:                   STAR shift  145 */
  {  72,   0, 141}, /*  3:                   PLUS shift  141 */
  {  43,   0, 116}, /*  4:                     GT shift  116 */
  {  61,   9, 130}, /*  5:                 LSHIFT shift  130 */
  {  75,   5, 149}, /*  6:                    REM shift  149 */
  {  62,   0, 114}, /*  7:                     LT shift  114 */
  {  63,   0, 143}, /*  8:                  MINUS shift  143 */
  {  19,   0, 151}, /*  9:                 CONCAT shift  151 */
  {  79,  11, 132}, /* 10:                 RSHIFT shift  132 */
  {   9,   0, 126}, /* 11:                 BITAND shift  126 */
  {  11,   0, 128}, /* 12:                  BITOR shift  128 */
  {  40,   0, 120}, /* 13:                     GE shift  120 */
  {  83,   0, 147}, /* 14:                  SLASH shift  147 */
/* State 124 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 125}, /* 28:                   expr shift  125 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 125 */
  {  57,   4, 118}, /*  1:                     LE shift  118 */
  {  85,   1, 145}, /*  2:                   STAR shift  145 */
  {  72,   0, 141}, /*  3:                   PLUS shift  141 */
  {  43,   0, 116}, /*  4:                     GT shift  116 */
  {  61,   9, 130}, /*  5:                 LSHIFT shift  130 */
  {  75,   5, 149}, /*  6:                    REM shift  149 */
  {  62,   0, 114}, /*  7:                     LT shift  114 */
  {  63,   0, 143}, /*  8:                  MINUS shift  143 */
  {  19,   0, 151}, /*  9:                 CONCAT shift  151 */
  {  79,  11, 132}, /* 10:                 RSHIFT shift  132 */
  {   9,   0, 126}, /* 11:                 BITAND shift  126 */
  {  11,   0, 128}, /* 12:                  BITOR shift  128 */
  {  40,   0, 120}, /* 13:                     GE shift  120 */
  {  83,   0, 147}, /* 14:                  SLASH shift  147 */
/* State 126 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 127}, /* 28:                   expr shift  127 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 127 */
  {  72,   0, 141}, /*  1:                   PLUS shift  141 */
  {  85,   3, 145}, /*  2:                   STAR shift  145 */
  {  19,   0, 151}, /*  3:                 CONCAT shift  151 */
  {  75,   5, 149}, /*  4:                    REM shift  149 */
  {  63,   0, 143}, /*  5:                  MINUS shift  143 */
  {  83,   0, 147}, /*  6:                  SLASH shift  147 */
/* State 128 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 129}, /* 28:                   expr shift  129 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 129 */
  {  72,   0, 141}, /*  1:                   PLUS shift  141 */
  {  85,   3, 145}, /*  2:                   STAR shift  145 */
  {  19,   0, 151}, /*  3:                 CONCAT shift  151 */
  {  75,   5, 149}, /*  4:                    REM shift  149 */
  {  63,   0, 143}, /*  5:                  MINUS shift  143 */
  {  83,   0, 147}, /*  6:                  SLASH shift  147 */
/* State 130 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 131}, /* 28:                   expr shift  131 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 131 */
  {  72,   0, 141}, /*  1:                   PLUS shift  141 */
  {  85,   3, 145}, /*  2:                   STAR shift  145 */
  {  19,   0, 151}, /*  3:                 CONCAT shift  151 */
  {  75,   5, 149}, /*  4:                    REM shift  149 */
  {  63,   0, 143}, /*  5:                  MINUS shift  143 */
  {  83,   0, 147}, /*  6:                  SLASH shift  147 */
/* State 132 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 133}, /* 28:                   expr shift  133 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 133 */
  {  72,   0, 141}, /*  1:                   PLUS shift  141 */
  {  85,   3, 145}, /*  2:                   STAR shift  145 */
  {  19,   0, 151}, /*  3:                 CONCAT shift  151 */
  {  75,   5, 149}, /*  4:                    REM shift  149 */
  {  63,   0, 143}, /*  5:                  MINUS shift  143 */
  {  83,   0, 147}, /*  6:                  SLASH shift  147 */
/* State 134 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 135}, /* 28:                   expr shift  135 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 135 */
  {  57,   4, 118}, /*  1:                     LE shift  118 */
  {  85,   1, 145}, /*  2:                   STAR shift  145 */
  {  72,   0, 141}, /*  3:                   PLUS shift  141 */
  {  43,   0, 116}, /*  4:                     GT shift  116 */
  {  61,   9, 130}, /*  5:                 LSHIFT shift  130 */
  {  75,   5, 149}, /*  6:                    REM shift  149 */
  {  62,   0, 114}, /*  7:                     LT shift  114 */
  {  63,   0, 143}, /*  8:                  MINUS shift  143 */
  {  19,   0, 151}, /*  9:                 CONCAT shift  151 */
  {  79,  11, 132}, /* 10:                 RSHIFT shift  132 */
  {   9,   0, 126}, /* 11:                 BITAND shift  126 */
  {  11,   0, 128}, /* 12:                  BITOR shift  128 */
  {  40,   0, 120}, /* 13:                     GE shift  120 */
  {  83,   0, 147}, /* 14:                  SLASH shift  147 */
/* State 136 */
  {  48,   5, 192}, /*  1:                     IN shift  192 */
  {  41,   0, 185}, /*  2:                   GLOB shift  185 */
  {  67,   0, 187}, /*  3:                   NULL shift  187 */
  {  58,   1, 137}, /*  4:                   LIKE shift  137 */
  {   8,   0, 188}, /*  5:                BETWEEN shift  188 */
/* State 137 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 138}, /* 28:                   expr shift  138 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 138 */
  {  72,   2, 141}, /*  1:                   PLUS shift  141 */
  {  48,   0, 163}, /*  2:                     IN shift  163 */
  {  55,   0, 153}, /*  3:                 ISNULL shift  153 */
  {  75,   0, 149}, /*  4:                    REM shift  149 */
  {  33,   6, 124}, /*  5:                     EQ shift  124 */
  {   9,   0, 126}, /*  6:                 BITAND shift  126 */
  {  54,   0, 154}, /*  7:                     IS shift  154 */
  {  79,   3, 132}, /*  8:                 RSHIFT shift  132 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  57,   5, 118}, /* 10:                     LE shift  118 */
  {  58,   0, 134}, /* 11:                   LIKE shift  134 */
  {  83,  13, 147}, /* 12:                  SLASH shift  147 */
  {  11,   0, 128}, /* 13:                  BITOR shift  128 */
  {  85,  21, 145}, /* 14:                   STAR shift  145 */
  {  62,   0, 114}, /* 15:                     LT shift  114 */
  {  63,   0, 143}, /* 16:                  MINUS shift  143 */
  {  64,  22, 122}, /* 17:                     NE shift  122 */
  {  65,  23, 136}, /* 18:                    NOT shift  136 */
  {  66,   0, 158}, /* 19:                NOTNULL shift  158 */
  {  43,  24, 116}, /* 20:                     GT shift  116 */
  {  61,   0, 130}, /* 21:                 LSHIFT shift  130 */
  {  40,   0, 120}, /* 22:                     GE shift  120 */
  {  41,   0, 139}, /* 23:                   GLOB shift  139 */
  {  19,   0, 151}, /* 24:                 CONCAT shift  151 */
/* State 139 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 140}, /* 28:                   expr shift  140 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 140 */
  {  57,   4, 118}, /*  1:                     LE shift  118 */
  {  85,   1, 145}, /*  2:                   STAR shift  145 */
  {  72,   0, 141}, /*  3:                   PLUS shift  141 */
  {  43,   0, 116}, /*  4:                     GT shift  116 */
  {  61,   9, 130}, /*  5:                 LSHIFT shift  130 */
  {  75,   5, 149}, /*  6:                    REM shift  149 */
  {  62,   0, 114}, /*  7:                     LT shift  114 */
  {  63,   0, 143}, /*  8:                  MINUS shift  143 */
  {  19,   0, 151}, /*  9:                 CONCAT shift  151 */
  {  79,  11, 132}, /* 10:                 RSHIFT shift  132 */
  {   9,   0, 126}, /* 11:                 BITAND shift  126 */
  {  11,   0, 128}, /* 12:                  BITOR shift  128 */
  {  40,   0, 120}, /* 13:                     GE shift  120 */
  {  83,   0, 147}, /* 14:                  SLASH shift  147 */
/* State 141 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 142}, /* 28:                   expr shift  142 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 142 */
  {  75,   3, 149}, /*  1:                    REM shift  149 */
  {  85,   0, 145}, /*  2:                   STAR shift  145 */
  {  19,   0, 151}, /*  3:                 CONCAT shift  151 */
  {  83,   1, 147}, /*  4:                  SLASH shift  147 */
/* State 143 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 144}, /* 28:                   expr shift  144 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 144 */
  {  75,   3, 149}, /*  1:                    REM shift  149 */
  {  85,   0, 145}, /*  2:                   STAR shift  145 */
  {  19,   0, 151}, /*  3:                 CONCAT shift  151 */
  {  83,   1, 147}, /*  4:                  SLASH shift  147 */
/* State 145 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 146}, /* 28:                   expr shift  146 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 146 */
  {  19,   0, 151}, /*  1:                 CONCAT shift  151 */
/* State 147 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 148}, /* 28:                   expr shift  148 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 148 */
  {  19,   0, 151}, /*  1:                 CONCAT shift  151 */
/* State 149 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 150}, /* 28:                   expr shift  150 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 150 */
  {  19,   0, 151}, /*  1:                 CONCAT shift  151 */
/* State 151 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 152}, /* 28:                   expr shift  152 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 154 */
  {  65,   0, 156}, /*  1:                    NOT shift  156 */
  {  67,   1, 155}, /*  2:                   NULL shift  155 */
/* State 156 */
  {  67,   0, 157}, /*  1:                   NULL shift  157 */
/* State 159 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 160}, /* 28:                   expr shift  160 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 160 */
  {  57,   0, 118}, /*  1:                     LE shift  118 */
  {  79,   0, 132}, /*  2:                 RSHIFT shift  132 */
  {  54,   0, 154}, /*  3:                     IS shift  154 */
  {  55,   0, 153}, /*  4:                 ISNULL shift  153 */
  {   4,   0, 161}, /*  5:                    AND shift  161 */
  {  83,   1, 147}, /*  6:                  SLASH shift  147 */
  {  58,   0, 134}, /*  7:                   LIKE shift  134 */
  {  85,  17, 145}, /*  8:                   STAR shift  145 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  61,  22, 130}, /* 10:                 LSHIFT shift  130 */
  {  62,   0, 114}, /* 11:                     LT shift  114 */
  {  63,  25, 143}, /* 12:                  MINUS shift  143 */
  {  64,   0, 122}, /* 13:                     NE shift  122 */
  {  65,   0, 136}, /* 14:                    NOT shift  136 */
  {  66,  26, 158}, /* 15:                NOTNULL shift  158 */
  {  41,   0, 139}, /* 16:                   GLOB shift  139 */
  {  33,   0, 124}, /* 17:                     EQ shift  124 */
  {  43,   0, 116}, /* 18:                     GT shift  116 */
  {  70,   0, 112}, /* 19:                     OR shift  112 */
  {  19,   0, 151}, /* 20:                 CONCAT shift  151 */
  {  72,   0, 141}, /* 21:                   PLUS shift  141 */
  {   9,   0, 126}, /* 22:                 BITAND shift  126 */
  {  48,   0, 163}, /* 23:                     IN shift  163 */
  {  75,   0, 149}, /* 24:                    REM shift  149 */
  {  11,   0, 128}, /* 25:                  BITOR shift  128 */
  {  40,   0, 120}, /* 26:                     GE shift  120 */
/* State 161 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 162}, /* 28:                   expr shift  162 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 162 */
  {  57,   4, 118}, /*  1:                     LE shift  118 */
  {  85,   1, 145}, /*  2:                   STAR shift  145 */
  {  72,   0, 141}, /*  3:                   PLUS shift  141 */
  {  43,   0, 116}, /*  4:                     GT shift  116 */
  {  61,   9, 130}, /*  5:                 LSHIFT shift  130 */
  {  75,   5, 149}, /*  6:                    REM shift  149 */
  {  62,   0, 114}, /*  7:                     LT shift  114 */
  {  63,   0, 143}, /*  8:                  MINUS shift  143 */
  {  19,   0, 151}, /*  9:                 CONCAT shift  151 */
  {  79,  11, 132}, /* 10:                 RSHIFT shift  132 */
  {   9,   0, 126}, /* 11:                 BITAND shift  126 */
  {  11,   0, 128}, /* 12:                  BITOR shift  128 */
  {  40,   0, 120}, /* 13:                     GE shift  120 */
  {  83,   0, 147}, /* 14:                  SLASH shift  147 */
/* State 163 */
  {  60,   0, 164}, /*  1:                     LP shift  164 */
/* State 164 */
  {  35,   0,  22}, /*  1:                EXPLAIN shift  22 */
  {  36,   5,  35}, /*  2:                   FAIL shift  35 */
  {  72,   6, 178}, /*  3:                   PLUS shift  178 */
  {  73,   0,  26}, /*  4:                 PRAGMA shift  26 */
  {   1,   0,  32}, /*  5:                  ABORT shift  32 */
  {  37,   0, 110}, /*  6:                  FLOAT shift  110 */
  { 146,   9, 165}, /*  7:                 select shift  165 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  76,  10,  34}, /*  9:                REPLACE shift  34 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  80,  16,  82}, /* 11:                 SELECT shift  82 */
  {  46,   0,  33}, /* 12:                 IGNORE shift  33 */
  { 117,   0, 171}, /* 13:                   expr shift  171 */
  { 118,   0, 184}, /* 14:               expritem shift  184 */
  { 119,  18, 180}, /* 15:               exprlist shift  180 */
  {  45,  23,  73}, /* 16:                     ID shift  73 */
  {  86,  24,  76}, /* 17:                 STRING shift  76 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,  25,  75}, /* 19:                     id shift  75 */
  { 124,   0, 106}, /* 20:                    ids shift  106 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  56,   0,  31}, /* 22:                    KEY shift  31 */
  {  10,   0, 174}, /* 23:                 BITNOT shift  174 */
  {  51,   0, 109}, /* 24:                INTEGER shift  109 */
  {  88,   0,  29}, /* 25:                   TEMP shift  29 */
  {  60,   0,  77}, /* 26:                     LP shift  77 */
  {  96,  30,  23}, /* 27:                 VACUUM shift  23 */
  {  27,   0,  19}, /* 28:                   DESC shift  19 */
  {  63,   0, 176}, /* 29:                  MINUS shift  176 */
  {  26,   0,  21}, /* 30:             DELIMITERS shift  21 */
  {  65,   0, 172}, /* 31:                    NOT shift  172 */
  {  31,   0,  25}, /* 32:                    END shift  25 */
  {  67,   0, 105}, /* 33:                   NULL shift  105 */
  { 138,  35,  78}, /* 34:              oneselect shift  78 */
  {  68,   0,  30}, /* 35:                 OFFSET shift  30 */
/* State 165 */
  { 135,   0,  80}, /*  1:         multiselect_op shift  80 */
  {  52,   0, 168}, /*  2:              INTERSECT shift  168 */
  {  92,   2, 166}, /*  3:                  UNION shift  166 */
  {  78,   0, 170}, /*  4:                     RP shift  170 */
  {  34,   0, 169}, /*  5:                 EXCEPT shift  169 */
/* State 166 */
  {  80,   0, 487}, /*  1:                 SELECT reduce 94 */
  {   3,   0, 167}, /*  2:                    ALL shift  167 */
/* State 167 */
  {  80,   0, 488}, /*  1:                 SELECT reduce 95 */
/* State 168 */
  {  80,   0, 489}, /*  1:                 SELECT reduce 96 */
/* State 169 */
  {  80,   0, 490}, /*  1:                 SELECT reduce 97 */
/* State 171 */
  {  57,   0, 118}, /*  1:                     LE shift  118 */
  {  79,   0, 132}, /*  2:                 RSHIFT shift  132 */
  {  54,   0, 154}, /*  3:                     IS shift  154 */
  {  55,   0, 153}, /*  4:                 ISNULL shift  153 */
  {   4,   0, 104}, /*  5:                    AND shift  104 */
  {  83,   1, 147}, /*  6:                  SLASH shift  147 */
  {  58,   0, 134}, /*  7:                   LIKE shift  134 */
  {  85,  17, 145}, /*  8:                   STAR shift  145 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  61,  22, 130}, /* 10:                 LSHIFT shift  130 */
  {  62,   0, 114}, /* 11:                     LT shift  114 */
  {  63,  25, 143}, /* 12:                  MINUS shift  143 */
  {  64,   0, 122}, /* 13:                     NE shift  122 */
  {  65,   0, 136}, /* 14:                    NOT shift  136 */
  {  66,  26, 158}, /* 15:                NOTNULL shift  158 */
  {  41,   0, 139}, /* 16:                   GLOB shift  139 */
  {  33,   0, 124}, /* 17:                     EQ shift  124 */
  {  43,   0, 116}, /* 18:                     GT shift  116 */
  {  70,   0, 112}, /* 19:                     OR shift  112 */
  {  19,   0, 151}, /* 20:                 CONCAT shift  151 */
  {  72,   0, 141}, /* 21:                   PLUS shift  141 */
  {   9,   0, 126}, /* 22:                 BITAND shift  126 */
  {  48,   0, 163}, /* 23:                     IN shift  163 */
  {  75,   0, 149}, /* 24:                    REM shift  149 */
  {  11,   0, 128}, /* 25:                  BITOR shift  128 */
  {  40,   0, 120}, /* 26:                     GE shift  120 */
/* State 172 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 173}, /* 28:                   expr shift  173 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 173 */
  {  72,   2, 141}, /*  1:                   PLUS shift  141 */
  {  48,   0, 163}, /*  2:                     IN shift  163 */
  {  55,   0, 153}, /*  3:                 ISNULL shift  153 */
  {  75,   0, 149}, /*  4:                    REM shift  149 */
  {  33,   6, 124}, /*  5:                     EQ shift  124 */
  {   9,   0, 126}, /*  6:                 BITAND shift  126 */
  {  54,   0, 154}, /*  7:                     IS shift  154 */
  {  79,   3, 132}, /*  8:                 RSHIFT shift  132 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  57,   5, 118}, /* 10:                     LE shift  118 */
  {  58,   0, 134}, /* 11:                   LIKE shift  134 */
  {  83,  13, 147}, /* 12:                  SLASH shift  147 */
  {  11,   0, 128}, /* 13:                  BITOR shift  128 */
  {  85,  21, 145}, /* 14:                   STAR shift  145 */
  {  62,   0, 114}, /* 15:                     LT shift  114 */
  {  63,   0, 143}, /* 16:                  MINUS shift  143 */
  {  64,  22, 122}, /* 17:                     NE shift  122 */
  {  65,  23, 136}, /* 18:                    NOT shift  136 */
  {  66,   0, 158}, /* 19:                NOTNULL shift  158 */
  {  43,  24, 116}, /* 20:                     GT shift  116 */
  {  61,   0, 130}, /* 21:                 LSHIFT shift  130 */
  {  40,   0, 120}, /* 22:                     GE shift  120 */
  {  41,   0, 139}, /* 23:                   GLOB shift  139 */
  {  19,   0, 151}, /* 24:                 CONCAT shift  151 */
/* State 174 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 175}, /* 28:                   expr shift  175 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 176 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 177}, /* 28:                   expr shift  177 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 178 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 179}, /* 28:                   expr shift  179 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 180 */
  {  78,   2, 181}, /*  1:                     RP shift  181 */
  {  16,   0, 182}, /*  2:                  COMMA shift  182 */
/* State 182 */
  { 124,   3, 106}, /*  1:                    ids shift  106 */
  {  63,   9, 176}, /*  2:                  MINUS shift  176 */
  {  31,   0,  25}, /*  3:                    END shift  25 */
  {  96,  10,  23}, /*  4:                 VACUUM shift  23 */
  {  35,   0,  22}, /*  5:                EXPLAIN shift  22 */
  {  67,  13, 105}, /*  6:                   NULL shift  105 */
  {  68,  14,  30}, /*  7:                 OFFSET shift  30 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {   1,   0,  32}, /*  9:                  ABORT shift  32 */
  {  65,   0, 172}, /* 10:                    NOT shift  172 */
  {  72,  17, 178}, /* 11:                   PLUS shift  178 */
  {  73,   0,  26}, /* 12:                 PRAGMA shift  26 */
  {  36,   0,  35}, /* 13:                   FAIL shift  35 */
  {  37,  18, 110}, /* 14:                  FLOAT shift  110 */
  {  76,  19,  34}, /* 15:                REPLACE shift  34 */
  {  46,   0,  33}, /* 16:                 IGNORE shift  33 */
  {  10,   0, 174}, /* 17:                 BITNOT shift  174 */
  {   6,   0,  20}, /* 18:                    ASC shift  20 */
  {  45,  20,  73}, /* 19:                     ID shift  73 */
  {  14,   0,  27}, /* 20:                CLUSTER shift  27 */
  {  51,  22, 109}, /* 21:                INTEGER shift  109 */
  {  20,   0,  36}, /* 22:               CONFLICT shift  36 */
  {  86,   0,  76}, /* 23:                 STRING shift  76 */
  {  56,   0,  31}, /* 24:                    KEY shift  31 */
  { 117,  23, 171}, /* 25:                   expr shift  171 */
  { 118,  24, 183}, /* 26:               expritem shift  183 */
  {  88,  29,  29}, /* 27:                   TEMP shift  29 */
  {  27,   0,  19}, /* 28:                   DESC shift  19 */
  {  26,   0,  21}, /* 29:             DELIMITERS shift  21 */
  {  60,   0,  77}, /* 30:                     LP shift  77 */
  { 123,   0,  75}, /* 31:                     id shift  75 */
/* State 185 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 186}, /* 28:                   expr shift  186 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 186 */
  {  72,   2, 141}, /*  1:                   PLUS shift  141 */
  {  48,   0, 163}, /*  2:                     IN shift  163 */
  {  55,   0, 153}, /*  3:                 ISNULL shift  153 */
  {  75,   0, 149}, /*  4:                    REM shift  149 */
  {  33,   6, 124}, /*  5:                     EQ shift  124 */
  {   9,   0, 126}, /*  6:                 BITAND shift  126 */
  {  54,   0, 154}, /*  7:                     IS shift  154 */
  {  79,   3, 132}, /*  8:                 RSHIFT shift  132 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  57,   5, 118}, /* 10:                     LE shift  118 */
  {  58,   0, 134}, /* 11:                   LIKE shift  134 */
  {  83,  13, 147}, /* 12:                  SLASH shift  147 */
  {  11,   0, 128}, /* 13:                  BITOR shift  128 */
  {  85,  21, 145}, /* 14:                   STAR shift  145 */
  {  62,   0, 114}, /* 15:                     LT shift  114 */
  {  63,   0, 143}, /* 16:                  MINUS shift  143 */
  {  64,  22, 122}, /* 17:                     NE shift  122 */
  {  65,  23, 136}, /* 18:                    NOT shift  136 */
  {  66,   0, 158}, /* 19:                NOTNULL shift  158 */
  {  43,  24, 116}, /* 20:                     GT shift  116 */
  {  61,   0, 130}, /* 21:                 LSHIFT shift  130 */
  {  40,   0, 120}, /* 22:                     GE shift  120 */
  {  41,   0, 139}, /* 23:                   GLOB shift  139 */
  {  19,   0, 151}, /* 24:                 CONCAT shift  151 */
/* State 188 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 189}, /* 28:                   expr shift  189 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 189 */
  {  57,   0, 118}, /*  1:                     LE shift  118 */
  {  79,   0, 132}, /*  2:                 RSHIFT shift  132 */
  {  54,   0, 154}, /*  3:                     IS shift  154 */
  {  55,   0, 153}, /*  4:                 ISNULL shift  153 */
  {   4,   0, 190}, /*  5:                    AND shift  190 */
  {  83,   1, 147}, /*  6:                  SLASH shift  147 */
  {  58,   0, 134}, /*  7:                   LIKE shift  134 */
  {  85,  17, 145}, /*  8:                   STAR shift  145 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  61,  22, 130}, /* 10:                 LSHIFT shift  130 */
  {  62,   0, 114}, /* 11:                     LT shift  114 */
  {  63,  25, 143}, /* 12:                  MINUS shift  143 */
  {  64,   0, 122}, /* 13:                     NE shift  122 */
  {  65,   0, 136}, /* 14:                    NOT shift  136 */
  {  66,  26, 158}, /* 15:                NOTNULL shift  158 */
  {  41,   0, 139}, /* 16:                   GLOB shift  139 */
  {  33,   0, 124}, /* 17:                     EQ shift  124 */
  {  43,   0, 116}, /* 18:                     GT shift  116 */
  {  70,   0, 112}, /* 19:                     OR shift  112 */
  {  19,   0, 151}, /* 20:                 CONCAT shift  151 */
  {  72,   0, 141}, /* 21:                   PLUS shift  141 */
  {   9,   0, 126}, /* 22:                 BITAND shift  126 */
  {  48,   0, 163}, /* 23:                     IN shift  163 */
  {  75,   0, 149}, /* 24:                    REM shift  149 */
  {  11,   0, 128}, /* 25:                  BITOR shift  128 */
  {  40,   0, 120}, /* 26:                     GE shift  120 */
/* State 190 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 191}, /* 28:                   expr shift  191 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 191 */
  {  72,   2, 141}, /*  1:                   PLUS shift  141 */
  {  48,   0, 163}, /*  2:                     IN shift  163 */
  {  55,   0, 153}, /*  3:                 ISNULL shift  153 */
  {  75,   0, 149}, /*  4:                    REM shift  149 */
  {  33,   6, 124}, /*  5:                     EQ shift  124 */
  {   9,   0, 126}, /*  6:                 BITAND shift  126 */
  {  54,   0, 154}, /*  7:                     IS shift  154 */
  {  79,   3, 132}, /*  8:                 RSHIFT shift  132 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  57,   5, 118}, /* 10:                     LE shift  118 */
  {  58,   0, 134}, /* 11:                   LIKE shift  134 */
  {  83,  13, 147}, /* 12:                  SLASH shift  147 */
  {  11,   0, 128}, /* 13:                  BITOR shift  128 */
  {  85,  21, 145}, /* 14:                   STAR shift  145 */
  {  62,   0, 114}, /* 15:                     LT shift  114 */
  {  63,   0, 143}, /* 16:                  MINUS shift  143 */
  {  64,  22, 122}, /* 17:                     NE shift  122 */
  {  65,  23, 136}, /* 18:                    NOT shift  136 */
  {  66,   0, 158}, /* 19:                NOTNULL shift  158 */
  {  43,  24, 116}, /* 20:                     GT shift  116 */
  {  61,   0, 130}, /* 21:                 LSHIFT shift  130 */
  {  40,   0, 120}, /* 22:                     GE shift  120 */
  {  41,   0, 139}, /* 23:                   GLOB shift  139 */
  {  19,   0, 151}, /* 24:                 CONCAT shift  151 */
/* State 192 */
  {  60,   0, 193}, /*  1:                     LP shift  193 */
/* State 193 */
  {  35,   0,  22}, /*  1:                EXPLAIN shift  22 */
  {  36,   5,  35}, /*  2:                   FAIL shift  35 */
  {  72,   6, 178}, /*  3:                   PLUS shift  178 */
  {  73,   0,  26}, /*  4:                 PRAGMA shift  26 */
  {   1,   0,  32}, /*  5:                  ABORT shift  32 */
  {  37,   0, 110}, /*  6:                  FLOAT shift  110 */
  { 146,   9, 194}, /*  7:                 select shift  194 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  76,  10,  34}, /*  9:                REPLACE shift  34 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  80,  16,  82}, /* 11:                 SELECT shift  82 */
  {  46,   0,  33}, /* 12:                 IGNORE shift  33 */
  { 117,   0, 171}, /* 13:                   expr shift  171 */
  { 118,   0, 184}, /* 14:               expritem shift  184 */
  { 119,  18, 196}, /* 15:               exprlist shift  196 */
  {  45,  23,  73}, /* 16:                     ID shift  73 */
  {  86,  24,  76}, /* 17:                 STRING shift  76 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,  25,  75}, /* 19:                     id shift  75 */
  { 124,   0, 106}, /* 20:                    ids shift  106 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  56,   0,  31}, /* 22:                    KEY shift  31 */
  {  10,   0, 174}, /* 23:                 BITNOT shift  174 */
  {  51,   0, 109}, /* 24:                INTEGER shift  109 */
  {  88,   0,  29}, /* 25:                   TEMP shift  29 */
  {  60,   0,  77}, /* 26:                     LP shift  77 */
  {  96,  30,  23}, /* 27:                 VACUUM shift  23 */
  {  27,   0,  19}, /* 28:                   DESC shift  19 */
  {  63,   0, 176}, /* 29:                  MINUS shift  176 */
  {  26,   0,  21}, /* 30:             DELIMITERS shift  21 */
  {  65,   0, 172}, /* 31:                    NOT shift  172 */
  {  31,   0,  25}, /* 32:                    END shift  25 */
  {  67,   0, 105}, /* 33:                   NULL shift  105 */
  { 138,  35,  78}, /* 34:              oneselect shift  78 */
  {  68,   0,  30}, /* 35:                 OFFSET shift  30 */
/* State 194 */
  { 135,   0,  80}, /*  1:         multiselect_op shift  80 */
  {  52,   0, 168}, /*  2:              INTERSECT shift  168 */
  {  92,   2, 166}, /*  3:                  UNION shift  166 */
  {  78,   0, 195}, /*  4:                     RP shift  195 */
  {  34,   0, 169}, /*  5:                 EXCEPT shift  169 */
/* State 196 */
  {  78,   2, 197}, /*  1:                     RP shift  197 */
  {  16,   0, 182}, /*  2:                  COMMA shift  182 */
/* State 198 */
  {  27,   2,  68}, /*  1:                   DESC shift  68 */
  {   6,   0,  67}, /*  2:                    ASC shift  67 */
  { 152,   0, 199}, /*  3:              sortorder shift  199 */
/* State 200 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 201}, /* 28:                   expr shift  201 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 201 */
  {  57,   0, 118}, /*  1:                     LE shift  118 */
  {  79,   0, 132}, /*  2:                 RSHIFT shift  132 */
  {  54,   0, 154}, /*  3:                     IS shift  154 */
  {  55,   0, 153}, /*  4:                 ISNULL shift  153 */
  {   4,   0, 104}, /*  5:                    AND shift  104 */
  {  83,   1, 147}, /*  6:                  SLASH shift  147 */
  {  58,   0, 134}, /*  7:                   LIKE shift  134 */
  {  85,  17, 145}, /*  8:                   STAR shift  145 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  61,  22, 130}, /* 10:                 LSHIFT shift  130 */
  {  62,   0, 114}, /* 11:                     LT shift  114 */
  {  63,  25, 143}, /* 12:                  MINUS shift  143 */
  {  64,   0, 122}, /* 13:                     NE shift  122 */
  {  65,   0, 136}, /* 14:                    NOT shift  136 */
  {  66,  26, 158}, /* 15:                NOTNULL shift  158 */
  {  41,   0, 139}, /* 16:                   GLOB shift  139 */
  {  33,   0, 124}, /* 17:                     EQ shift  124 */
  {  43,   0, 116}, /* 18:                     GT shift  116 */
  {  70,   0, 112}, /* 19:                     OR shift  112 */
  {  19,   0, 151}, /* 20:                 CONCAT shift  151 */
  {  72,   0, 141}, /* 21:                   PLUS shift  141 */
  {   9,   0, 126}, /* 22:                 BITAND shift  126 */
  {  48,   0, 163}, /* 23:                     IN shift  163 */
  {  75,   0, 149}, /* 24:                    REM shift  149 */
  {  11,   0, 128}, /* 25:                  BITOR shift  128 */
  {  40,   0, 120}, /* 26:                     GE shift  120 */
/* State 202 */
  {  12,   0, 203}, /*  1:                     BY shift  203 */
/* State 203 */
  {  96,   0,  23}, /*  1:                 VACUUM shift  23 */
  {  65,   3, 172}, /*  2:                    NOT shift  172 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  {  67,  12, 105}, /*  4:                   NULL shift  105 */
  {  68,  16,  30}, /*  5:                 OFFSET shift  30 */
  {  37,   0, 110}, /*  6:                  FLOAT shift  110 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  72,   0, 178}, /*  9:                   PLUS shift  178 */
  {  73,   0,  26}, /* 10:                 PRAGMA shift  26 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  76,   0,  34}, /* 13:                REPLACE shift  34 */
  {  45,   0,  73}, /* 14:                     ID shift  73 */
  {  46,  17,  33}, /* 15:                 IGNORE shift  33 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  14,   0,  27}, /* 17:                CLUSTER shift  27 */
  {  86,   0,  76}, /* 18:                 STRING shift  76 */
  {  56,   0,  31}, /* 19:                    KEY shift  31 */
  {  51,   0, 109}, /* 20:                INTEGER shift  109 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  { 117,   0, 171}, /* 22:                   expr shift  171 */
  { 118,  18, 184}, /* 23:               expritem shift  184 */
  { 119,   0, 204}, /* 24:               exprlist shift  204 */
  {  88,  19,  29}, /* 25:                   TEMP shift  29 */
  {  27,   0,  19}, /* 26:                   DESC shift  19 */
  {  26,   0,  21}, /* 27:             DELIMITERS shift  21 */
  { 123,  26,  75}, /* 28:                     id shift  75 */
  { 124,  30, 106}, /* 29:                    ids shift  106 */
  {  60,   0,  77}, /* 30:                     LP shift  77 */
  {  31,   0,  25}, /* 31:                    END shift  25 */
  {  63,  31, 176}, /* 32:                  MINUS shift  176 */
/* State 204 */
  {  16,   0, 182}, /*  1:                  COMMA shift  182 */
/* State 205 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 206}, /* 28:                   expr shift  206 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 206 */
  {  57,   0, 118}, /*  1:                     LE shift  118 */
  {  79,   0, 132}, /*  2:                 RSHIFT shift  132 */
  {  54,   0, 154}, /*  3:                     IS shift  154 */
  {  55,   0, 153}, /*  4:                 ISNULL shift  153 */
  {   4,   0, 104}, /*  5:                    AND shift  104 */
  {  83,   1, 147}, /*  6:                  SLASH shift  147 */
  {  58,   0, 134}, /*  7:                   LIKE shift  134 */
  {  85,  17, 145}, /*  8:                   STAR shift  145 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  61,  22, 130}, /* 10:                 LSHIFT shift  130 */
  {  62,   0, 114}, /* 11:                     LT shift  114 */
  {  63,  25, 143}, /* 12:                  MINUS shift  143 */
  {  64,   0, 122}, /* 13:                     NE shift  122 */
  {  65,   0, 136}, /* 14:                    NOT shift  136 */
  {  66,  26, 158}, /* 15:                NOTNULL shift  158 */
  {  41,   0, 139}, /* 16:                   GLOB shift  139 */
  {  33,   0, 124}, /* 17:                     EQ shift  124 */
  {  43,   0, 116}, /* 18:                     GT shift  116 */
  {  70,   0, 112}, /* 19:                     OR shift  112 */
  {  19,   0, 151}, /* 20:                 CONCAT shift  151 */
  {  72,   0, 141}, /* 21:                   PLUS shift  141 */
  {   9,   0, 126}, /* 22:                 BITAND shift  126 */
  {  48,   0, 163}, /* 23:                     IN shift  163 */
  {  75,   0, 149}, /* 24:                    REM shift  149 */
  {  11,   0, 128}, /* 25:                  BITOR shift  128 */
  {  40,   0, 120}, /* 26:                     GE shift  120 */
/* State 208 */
  { 147,   0, 209}, /*  1:             seltablist shift  209 */
  { 153,   1, 211}, /*  2:             stl_prefix shift  211 */
/* State 209 */
  {  16,   0, 210}, /*  1:                  COMMA shift  210 */
/* State 211 */
  {  88,   0,  29}, /*  1:                   TEMP shift  29 */
  {  45,   4,  28}, /*  2:                     ID shift  28 */
  {  68,  12,  30}, /*  3:                 OFFSET shift  30 */
  {   1,   0,  32}, /*  4:                  ABORT shift  32 */
  {  26,   0,  21}, /*  5:             DELIMITERS shift  21 */
  {  27,   0,  19}, /*  6:                   DESC shift  19 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {  73,  16,  26}, /*  8:                 PRAGMA shift  26 */
  {  96,   0,  23}, /*  9:                 VACUUM shift  23 */
  {  31,   0,  25}, /* 10:                    END shift  25 */
  {  76,   0,  34}, /* 11:                REPLACE shift  34 */
  {  46,   0,  33}, /* 12:                 IGNORE shift  33 */
  {  56,   0,  31}, /* 13:                    KEY shift  31 */
  { 123,  18,  37}, /* 14:                     id shift  37 */
  { 124,  19, 212}, /* 15:                    ids shift  212 */
  {   7,   0,  24}, /* 16:                  BEGIN shift  24 */
  {  60,   0, 216}, /* 17:                     LP shift  216 */
  {  35,   0,  22}, /* 18:                EXPLAIN shift  22 */
  {  36,  20,  35}, /* 19:                   FAIL shift  35 */
  {  14,   0,  27}, /* 20:                CLUSTER shift  27 */
  {  86,  22,  38}, /* 21:                 STRING shift  38 */
  {  20,   0,  36}, /* 22:               CONFLICT shift  36 */
/* State 212 */
  {  78,   3, 505}, /*  1:                     RP reduce 112 */
  {  92,   0, 505}, /*  2:                  UNION reduce 112 */
  {  52,   0, 505}, /*  3:              INTERSECT reduce 112 */
  {  81,   5, 505}, /*  4:                   SEMI reduce 112 */
  {  42,  11, 505}, /*  5:                  GROUP reduce 112 */
  {  44,  12, 505}, /*  6:                 HAVING reduce 112 */
  {  71,   0, 505}, /*  7:                  ORDER reduce 112 */
  {  59,   0, 505}, /*  8:                  LIMIT reduce 112 */
  {  99,  13, 505}, /*  9:                  WHERE reduce 112 */
  { 100,   0, 214}, /* 10:                     as shift  214 */
  {  16,   0, 505}, /* 11:                  COMMA reduce 112 */
  {   5,   0, 213}, /* 12:                     AS shift  213 */
  {  34,   0, 505}, /* 13:                 EXCEPT reduce 112 */
/* State 214 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 215}, /* 20:                    ids shift  215 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 216 */
  { 138,   0,  78}, /*  1:              oneselect shift  78 */
  {  80,   0,  82}, /*  2:                 SELECT shift  82 */
  { 146,   2, 217}, /*  3:                 select shift  217 */
/* State 217 */
  { 135,   0,  80}, /*  1:         multiselect_op shift  80 */
  {  52,   0, 168}, /*  2:              INTERSECT shift  168 */
  {  92,   2, 166}, /*  3:                  UNION shift  166 */
  {  78,   0, 218}, /*  4:                     RP shift  218 */
  {  34,   0, 169}, /*  5:                 EXCEPT shift  169 */
/* State 218 */
  {  78,   3, 507}, /*  1:                     RP reduce 114 */
  {  92,   0, 507}, /*  2:                  UNION reduce 114 */
  {  52,   0, 507}, /*  3:              INTERSECT reduce 114 */
  {  81,   5, 507}, /*  4:                   SEMI reduce 114 */
  {  42,  11, 507}, /*  5:                  GROUP reduce 114 */
  {  44,  12, 507}, /*  6:                 HAVING reduce 114 */
  {  71,   0, 507}, /*  7:                  ORDER reduce 114 */
  {  59,   0, 507}, /*  8:                  LIMIT reduce 114 */
  {  99,  13, 507}, /*  9:                  WHERE reduce 114 */
  { 100,   0, 219}, /* 10:                     as shift  219 */
  {  16,   0, 507}, /* 11:                  COMMA reduce 114 */
  {   5,   0, 213}, /* 12:                     AS shift  213 */
  {  34,   0, 507}, /* 13:                 EXCEPT reduce 114 */
/* State 219 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 220}, /* 20:                    ids shift  220 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 221 */
  { 124,   3, 106}, /*  1:                    ids shift  106 */
  {  63,   9, 176}, /*  2:                  MINUS shift  176 */
  {  31,   0,  25}, /*  3:                    END shift  25 */
  {  96,  10,  23}, /*  4:                 VACUUM shift  23 */
  {  35,   0,  22}, /*  5:                EXPLAIN shift  22 */
  {  67,  13, 105}, /*  6:                   NULL shift  105 */
  {  68,  14,  30}, /*  7:                 OFFSET shift  30 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {   1,   0,  32}, /*  9:                  ABORT shift  32 */
  {  65,   0, 172}, /* 10:                    NOT shift  172 */
  {  72,  17, 178}, /* 11:                   PLUS shift  178 */
  {  73,   0,  26}, /* 12:                 PRAGMA shift  26 */
  {  36,   0,  35}, /* 13:                   FAIL shift  35 */
  {  37,  18, 110}, /* 14:                  FLOAT shift  110 */
  {  76,  19,  34}, /* 15:                REPLACE shift  34 */
  {  46,   0,  33}, /* 16:                 IGNORE shift  33 */
  {  10,   0, 174}, /* 17:                 BITNOT shift  174 */
  {   6,   0,  20}, /* 18:                    ASC shift  20 */
  {  45,  20,  73}, /* 19:                     ID shift  73 */
  {  14,   0,  27}, /* 20:                CLUSTER shift  27 */
  {  51,  22, 109}, /* 21:                INTEGER shift  109 */
  {  20,   0,  36}, /* 22:               CONFLICT shift  36 */
  {  86,   0,  76}, /* 23:                 STRING shift  76 */
  {  85,   0, 225}, /* 24:                   STAR shift  225 */
  { 117,  23, 222}, /* 25:                   expr shift  222 */
  {  56,   0,  31}, /* 26:                    KEY shift  31 */
  {  88,  29,  29}, /* 27:                   TEMP shift  29 */
  {  27,   0,  19}, /* 28:                   DESC shift  19 */
  {  26,   0,  21}, /* 29:             DELIMITERS shift  21 */
  {  60,   0,  77}, /* 30:                     LP shift  77 */
  { 123,   0,  75}, /* 31:                     id shift  75 */
/* State 222 */
  {  33,   0, 124}, /*  1:                     EQ shift  124 */
  {  61,   0, 130}, /*  2:                 LSHIFT shift  130 */
  {  62,   0, 114}, /*  3:                     LT shift  114 */
  {  63,   1, 143}, /*  4:                  MINUS shift  143 */
  {  64,   8, 122}, /*  5:                     NE shift  122 */
  {  65,  15, 136}, /*  6:                    NOT shift  136 */
  {  66,   0, 158}, /*  7:                NOTNULL shift  158 */
  {   4,   0, 104}, /*  8:                    AND shift  104 */
  {  38,  18, 497}, /*  9:                   FROM reduce 104 */
  {   9,   0, 126}, /* 10:                 BITAND shift  126 */
  { 100,  21, 223}, /* 11:                     as shift  223 */
  {  41,  22, 139}, /* 12:                   GLOB shift  139 */
  {  72,   0, 141}, /* 13:                   PLUS shift  141 */
  {  43,   0, 116}, /* 14:                     GT shift  116 */
  {   5,   0, 213}, /* 15:                     AS shift  213 */
  {  75,   0, 149}, /* 16:                    REM shift  149 */
  {  16,   0, 497}, /* 17:                  COMMA reduce 104 */
  {   8,   0, 159}, /* 18:                BETWEEN shift  159 */
  {  48,   0, 163}, /* 19:                     IN shift  163 */
  {  79,  23, 132}, /* 20:                 RSHIFT shift  132 */
  {  70,  27, 112}, /* 21:                     OR shift  112 */
  {  11,   0, 128}, /* 22:                  BITOR shift  128 */
  {  19,   0, 151}, /* 23:                 CONCAT shift  151 */
  {  83,   0, 147}, /* 24:                  SLASH shift  147 */
  {  54,   0, 154}, /* 25:                     IS shift  154 */
  {  85,  30, 145}, /* 26:                   STAR shift  145 */
  {  40,   0, 120}, /* 27:                     GE shift  120 */
  {  57,   0, 118}, /* 28:                     LE shift  118 */
  {  58,   0, 134}, /* 29:                   LIKE shift  134 */
  {  55,   0, 153}, /* 30:                 ISNULL shift  153 */
/* State 223 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 224}, /* 20:                    ids shift  224 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 229 */
  {  54,   0, 154}, /*  1:                     IS shift  154 */
  {  55,   0, 153}, /*  2:                 ISNULL shift  153 */
  {  83,   0, 147}, /*  3:                  SLASH shift  147 */
  {  57,   0, 118}, /*  4:                     LE shift  118 */
  {  85,   6, 145}, /*  5:                   STAR shift  145 */
  {  58,  16, 134}, /*  6:                   LIKE shift  134 */
  {  33,   0, 124}, /*  7:                     EQ shift  124 */
  {  61,   0, 130}, /*  8:                 LSHIFT shift  130 */
  {  62,  18, 114}, /*  9:                     LT shift  114 */
  {  63,  21, 143}, /* 10:                  MINUS shift  143 */
  {  64,   0, 122}, /* 11:                     NE shift  122 */
  {  65,  23, 136}, /* 12:                    NOT shift  136 */
  {  66,   0, 158}, /* 13:                NOTNULL shift  158 */
  {  40,   0, 120}, /* 14:                     GE shift  120 */
  {  41,   0, 139}, /* 15:                   GLOB shift  139 */
  {   4,   0, 104}, /* 16:                    AND shift  104 */
  {  70,  24, 112}, /* 17:                     OR shift  112 */
  {   8,   0, 159}, /* 18:                BETWEEN shift  159 */
  {  72,   0, 141}, /* 19:                   PLUS shift  141 */
  {  19,   0, 151}, /* 20:                 CONCAT shift  151 */
  {   9,   0, 126}, /* 21:                 BITAND shift  126 */
  {  75,  27, 149}, /* 22:                    REM shift  149 */
  {  11,   0, 128}, /* 23:                  BITOR shift  128 */
  {  43,   0, 116}, /* 24:                     GT shift  116 */
  {  78,   0, 230}, /* 25:                     RP shift  230 */
  {  79,   0, 132}, /* 26:                 RSHIFT shift  132 */
  {  48,   0, 163}, /* 27:                     IN shift  163 */
/* State 231 */
  {  78,   2, 232}, /*  1:                     RP shift  232 */
  {  16,   0, 182}, /*  2:                  COMMA shift  182 */
/* State 233 */
  {  78,   0, 234}, /*  1:                     RP shift  234 */
/* State 235 */
  {  54,   0, 154}, /*  1:                     IS shift  154 */
  {  55,   0, 153}, /*  2:                 ISNULL shift  153 */
  {  83,   0, 147}, /*  3:                  SLASH shift  147 */
  {  57,   0, 118}, /*  4:                     LE shift  118 */
  {  85,   6, 145}, /*  5:                   STAR shift  145 */
  {  58,  16, 134}, /*  6:                   LIKE shift  134 */
  {  33,   0, 124}, /*  7:                     EQ shift  124 */
  {  61,   0, 130}, /*  8:                 LSHIFT shift  130 */
  {  62,  18, 114}, /*  9:                     LT shift  114 */
  {  63,  21, 143}, /* 10:                  MINUS shift  143 */
  {  64,   0, 122}, /* 11:                     NE shift  122 */
  {  65,  23, 136}, /* 12:                    NOT shift  136 */
  {  66,   0, 158}, /* 13:                NOTNULL shift  158 */
  {  40,   0, 120}, /* 14:                     GE shift  120 */
  {  41,   0, 139}, /* 15:                   GLOB shift  139 */
  {   4,   0, 104}, /* 16:                    AND shift  104 */
  {  70,  24, 112}, /* 17:                     OR shift  112 */
  {   8,   0, 159}, /* 18:                BETWEEN shift  159 */
  {  72,   0, 141}, /* 19:                   PLUS shift  141 */
  {  19,   0, 151}, /* 20:                 CONCAT shift  151 */
  {   9,   0, 126}, /* 21:                 BITAND shift  126 */
  {  75,  27, 149}, /* 22:                    REM shift  149 */
  {  11,   0, 128}, /* 23:                  BITOR shift  128 */
  {  43,   0, 116}, /* 24:                     GT shift  116 */
  {  78,   0, 236}, /* 25:                     RP shift  236 */
  {  79,   0, 132}, /* 26:                 RSHIFT shift  132 */
  {  48,   0, 163}, /* 27:                     IN shift  163 */
/* State 236 */
  {  69,   0,   9}, /*  1:                     ON shift  9 */
  { 137,   1, 237}, /*  2:                 onconf shift  237 */
/* State 239 */
  {  63,   0, 246}, /*  1:                  MINUS shift  246 */
  {  72,   6, 243}, /*  2:                   PLUS shift  243 */
  {  86,   2, 240}, /*  3:                 STRING shift  240 */
  {  45,   0, 241}, /*  4:                     ID shift  241 */
  {  67,   0, 250}, /*  5:                   NULL shift  250 */
  {  51,   7, 242}, /*  6:                INTEGER shift  242 */
  {  37,   0, 249}, /*  7:                  FLOAT shift  249 */
/* State 243 */
  {  37,   0, 245}, /*  1:                  FLOAT shift  245 */
  {  51,   1, 244}, /*  2:                INTEGER shift  244 */
/* State 246 */
  {  37,   0, 248}, /*  1:                  FLOAT shift  248 */
  {  51,   1, 247}, /*  2:                INTEGER shift  247 */
/* State 251 */
  {  88,   0,  29}, /*  1:                   TEMP shift  29 */
  {  45,   4,  28}, /*  2:                     ID shift  28 */
  {  68,  12,  30}, /*  3:                 OFFSET shift  30 */
  {   1,   0,  32}, /*  4:                  ABORT shift  32 */
  {  26,   0,  21}, /*  5:             DELIMITERS shift  21 */
  {  27,   0,  19}, /*  6:                   DESC shift  19 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {  73,  16,  26}, /*  8:                 PRAGMA shift  26 */
  {  96,   0,  23}, /*  9:                 VACUUM shift  23 */
  {  31,   0,  25}, /* 10:                    END shift  25 */
  {  76,   0,  34}, /* 11:                REPLACE shift  34 */
  {  46,   0,  33}, /* 12:                 IGNORE shift  33 */
  {  56,   0,  31}, /* 13:                    KEY shift  31 */
  { 123,  18,  37}, /* 14:                     id shift  37 */
  { 124,  19, 263}, /* 15:                    ids shift  263 */
  {   7,   0,  24}, /* 16:                  BEGIN shift  24 */
  {  60,   0, 252}, /* 17:                     LP shift  252 */
  {  35,   0,  22}, /* 18:                EXPLAIN shift  22 */
  {  36,  20,  35}, /* 19:                   FAIL shift  35 */
  {  14,   0,  27}, /* 20:                CLUSTER shift  27 */
  {  86,  22,  38}, /* 21:                 STRING shift  38 */
  {  20,   0,  36}, /* 22:               CONFLICT shift  36 */
/* State 252 */
  {  72,   0, 259}, /*  1:                   PLUS shift  259 */
  { 149,   0, 253}, /*  2:                 signed shift  253 */
  {  51,   0, 258}, /*  3:                INTEGER shift  258 */
  {  63,   3, 261}, /*  4:                  MINUS shift  261 */
/* State 253 */
  {  78,   2, 254}, /*  1:                     RP shift  254 */
  {  16,   0, 255}, /*  2:                  COMMA shift  255 */
/* State 255 */
  {  72,   0, 259}, /*  1:                   PLUS shift  259 */
  { 149,   0, 256}, /*  2:                 signed shift  256 */
  {  51,   0, 258}, /*  3:                INTEGER shift  258 */
  {  63,   3, 261}, /*  4:                  MINUS shift  261 */
/* State 256 */
  {  78,   0, 257}, /*  1:                     RP shift  257 */
/* State 259 */
  {  51,   0, 260}, /*  1:                INTEGER shift  260 */
/* State 261 */
  {  51,   0, 262}, /*  1:                INTEGER shift  262 */
/* State 266 */
  { 154,   4, 289}, /*  1:                  tcons shift  289 */
  {  78,   0, 464}, /*  2:                     RP reduce 71 */
  {  93,   6, 281}, /*  3:                 UNIQUE shift  281 */
  {  21,   0, 269}, /*  4:             CONSTRAINT shift  269 */
  {  74,   0, 271}, /*  5:                PRIMARY shift  271 */
  {  16,   0, 267}, /*  6:                  COMMA shift  267 */
  {  13,   0, 286}, /*  7:                  CHECK shift  286 */
/* State 267 */
  {  13,   0, 286}, /*  1:                  CHECK shift  286 */
  {  21,   0, 269}, /*  2:             CONSTRAINT shift  269 */
  {  74,   0, 271}, /*  3:                PRIMARY shift  271 */
  {  93,   1, 281}, /*  4:                 UNIQUE shift  281 */
  { 154,   3, 268}, /*  5:                  tcons shift  268 */
/* State 269 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 270}, /* 20:                    ids shift  270 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 271 */
  {  56,   0, 272}, /*  1:                    KEY shift  272 */
/* State 272 */
  {  60,   0, 273}, /*  1:                     LP shift  273 */
/* State 273 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  73,   6,  26}, /*  3:                 PRAGMA shift  26 */
  {  26,   0,  21}, /*  4:             DELIMITERS shift  21 */
  {  96,   3,  23}, /*  5:                 VACUUM shift  23 */
  {  27,   0,  19}, /*  6:                   DESC shift  19 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {  76,  16,  34}, /*  8:                REPLACE shift  34 */
  { 123,  17,  37}, /*  9:                     id shift  37 */
  { 124,   0, 279}, /* 10:                    ids shift  279 */
  { 125,  19, 280}, /* 11:                idxitem shift  280 */
  { 126,   0, 274}, /* 12:                idxlist shift  274 */
  {  35,   0,  22}, /* 13:                EXPLAIN shift  22 */
  {  36,   0,  35}, /* 14:                   FAIL shift  35 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {   7,   0,  24}, /* 16:                  BEGIN shift  24 */
  {  31,   0,  25}, /* 17:                    END shift  25 */
  {  86,   0,  38}, /* 18:                 STRING shift  38 */
  {  56,   0,  31}, /* 19:                    KEY shift  31 */
  {  88,   0,  29}, /* 20:                   TEMP shift  29 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  45,   0,  28}, /* 22:                     ID shift  28 */
  {  68,  22,  30}, /* 23:                 OFFSET shift  30 */
/* State 274 */
  {  78,   2, 275}, /*  1:                     RP shift  275 */
  {  16,   0, 277}, /*  2:                  COMMA shift  277 */
/* State 275 */
  {  69,   0,   9}, /*  1:                     ON shift  9 */
  { 137,   1, 276}, /*  2:                 onconf shift  276 */
/* State 277 */
  {  88,   0,  29}, /*  1:                   TEMP shift  29 */
  {  45,   4,  28}, /*  2:                     ID shift  28 */
  {  68,  12,  30}, /*  3:                 OFFSET shift  30 */
  {   1,   0,  32}, /*  4:                  ABORT shift  32 */
  {  26,   0,  21}, /*  5:             DELIMITERS shift  21 */
  {  27,   0,  19}, /*  6:                   DESC shift  19 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {  73,  17,  26}, /*  8:                 PRAGMA shift  26 */
  {  96,   0,  23}, /*  9:                 VACUUM shift  23 */
  {  31,   0,  25}, /* 10:                    END shift  25 */
  {  76,   0,  34}, /* 11:                REPLACE shift  34 */
  {  46,   0,  33}, /* 12:                 IGNORE shift  33 */
  {  56,   0,  31}, /* 13:                    KEY shift  31 */
  { 123,  18,  37}, /* 14:                     id shift  37 */
  { 124,  19, 279}, /* 15:                    ids shift  279 */
  { 125,   0, 278}, /* 16:                idxitem shift  278 */
  {   7,   0,  24}, /* 17:                  BEGIN shift  24 */
  {  35,   0,  22}, /* 18:                EXPLAIN shift  22 */
  {  36,  20,  35}, /* 19:                   FAIL shift  35 */
  {  14,   0,  27}, /* 20:                CLUSTER shift  27 */
  {  86,  22,  38}, /* 21:                 STRING shift  38 */
  {  20,   0,  36}, /* 22:               CONFLICT shift  36 */
/* State 281 */
  {  60,   0, 282}, /*  1:                     LP shift  282 */
/* State 282 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  73,   6,  26}, /*  3:                 PRAGMA shift  26 */
  {  26,   0,  21}, /*  4:             DELIMITERS shift  21 */
  {  96,   3,  23}, /*  5:                 VACUUM shift  23 */
  {  27,   0,  19}, /*  6:                   DESC shift  19 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {  76,  16,  34}, /*  8:                REPLACE shift  34 */
  { 123,  17,  37}, /*  9:                     id shift  37 */
  { 124,   0, 279}, /* 10:                    ids shift  279 */
  { 125,  19, 280}, /* 11:                idxitem shift  280 */
  { 126,   0, 283}, /* 12:                idxlist shift  283 */
  {  35,   0,  22}, /* 13:                EXPLAIN shift  22 */
  {  36,   0,  35}, /* 14:                   FAIL shift  35 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {   7,   0,  24}, /* 16:                  BEGIN shift  24 */
  {  31,   0,  25}, /* 17:                    END shift  25 */
  {  86,   0,  38}, /* 18:                 STRING shift  38 */
  {  56,   0,  31}, /* 19:                    KEY shift  31 */
  {  88,   0,  29}, /* 20:                   TEMP shift  29 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  45,   0,  28}, /* 22:                     ID shift  28 */
  {  68,  22,  30}, /* 23:                 OFFSET shift  30 */
/* State 283 */
  {  78,   2, 284}, /*  1:                     RP shift  284 */
  {  16,   0, 277}, /*  2:                  COMMA shift  277 */
/* State 284 */
  {  69,   0,   9}, /*  1:                     ON shift  9 */
  { 137,   1, 285}, /*  2:                 onconf shift  285 */
/* State 286 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 287}, /* 28:                   expr shift  287 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 287 */
  {  57,   0, 118}, /*  1:                     LE shift  118 */
  {  85,   1, 145}, /*  2:                   STAR shift  145 */
  {  58,   0, 134}, /*  3:                   LIKE shift  134 */
  {  33,   0, 124}, /*  4:                     EQ shift  124 */
  {   4,   0, 104}, /*  5:                    AND shift  104 */
  {  61,   4, 130}, /*  6:                 LSHIFT shift  130 */
  {  62,   0, 114}, /*  7:                     LT shift  114 */
  {  63,   0, 143}, /*  8:                  MINUS shift  143 */
  {  64,  18, 122}, /*  9:                     NE shift  122 */
  {  65,  19, 136}, /* 10:                    NOT shift  136 */
  {  66,   0, 158}, /* 11:                NOTNULL shift  158 */
  {  11,   0, 128}, /* 12:                  BITOR shift  128 */
  {  40,   0, 120}, /* 13:                     GE shift  120 */
  {  69,  22,   9}, /* 14:                     ON shift  9 */
  {  70,   0, 112}, /* 15:                     OR shift  112 */
  {  43,   0, 116}, /* 16:                     GT shift  116 */
  {  72,   0, 141}, /* 17:                   PLUS shift  141 */
  {   8,   0, 159}, /* 18:                BETWEEN shift  159 */
  {   9,   0, 126}, /* 19:                 BITAND shift  126 */
  {  75,  23, 149}, /* 20:                    REM shift  149 */
  {  48,   0, 163}, /* 21:                     IN shift  163 */
  {  41,   0, 139}, /* 22:                   GLOB shift  139 */
  {  19,   0, 151}, /* 23:                 CONCAT shift  151 */
  {  79,   0, 132}, /* 24:                 RSHIFT shift  132 */
  {  55,   0, 153}, /* 25:                 ISNULL shift  153 */
  { 137,   0, 288}, /* 26:                 onconf shift  288 */
  {  54,   0, 154}, /* 27:                     IS shift  154 */
  {  83,  25, 147}, /* 28:                  SLASH shift  147 */
/* State 292 */
  { 138,   0,  78}, /*  1:              oneselect shift  78 */
  {  80,   0,  82}, /*  2:                 SELECT shift  82 */
  { 146,   2, 293}, /*  3:                 select shift  293 */
/* State 293 */
  { 135,   0,  80}, /*  1:         multiselect_op shift  80 */
  {  81,   0, 412}, /*  2:                   SEMI reduce 19 */
  {  92,   4, 166}, /*  3:                  UNION shift  166 */
  {  52,   0, 168}, /*  4:              INTERSECT shift  168 */
  {  34,   0, 169}, /*  5:                 EXCEPT shift  169 */
/* State 294 */
  {  98,   7, 299}, /*  1:                   VIEW shift  299 */
  { 155,   0, 295}, /*  2:                   temp shift  295 */
  {  93,   0, 312}, /*  3:                 UNIQUE shift  312 */
  {  87,   0, 410}, /*  4:                  TABLE reduce 17 */
  {  88,   0, 298}, /*  5:                   TEMP shift  298 */
  { 159,   0, 303}, /*  6:             uniqueflag shift  303 */
  {  49,   0, 595}, /*  7:                  INDEX reduce 202 */
/* State 295 */
  {  87,   0, 296}, /*  1:                  TABLE shift  296 */
/* State 296 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 297}, /* 20:                    ids shift  297 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 298 */
  {  87,   0, 409}, /*  1:                  TABLE reduce 16 */
/* State 299 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 300}, /* 20:                    ids shift  300 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 300 */
  {   5,   0, 301}, /*  1:                     AS shift  301 */
/* State 301 */
  { 138,   0,  78}, /*  1:              oneselect shift  78 */
  {  80,   0,  82}, /*  2:                 SELECT shift  82 */
  { 146,   2, 302}, /*  3:                 select shift  302 */
/* State 302 */
  { 135,   0,  80}, /*  1:         multiselect_op shift  80 */
  {  81,   0, 482}, /*  2:                   SEMI reduce 89 */
  {  92,   4, 166}, /*  3:                  UNION shift  166 */
  {  52,   0, 168}, /*  4:              INTERSECT shift  168 */
  {  34,   0, 169}, /*  5:                 EXCEPT shift  169 */
/* State 303 */
  {  49,   0, 304}, /*  1:                  INDEX shift  304 */
/* State 304 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 305}, /* 20:                    ids shift  305 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 305 */
  {  69,   0, 306}, /*  1:                     ON shift  306 */
/* State 306 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 307}, /* 20:                    ids shift  307 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 307 */
  {  60,   0, 308}, /*  1:                     LP shift  308 */
/* State 308 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  73,   6,  26}, /*  3:                 PRAGMA shift  26 */
  {  26,   0,  21}, /*  4:             DELIMITERS shift  21 */
  {  96,   3,  23}, /*  5:                 VACUUM shift  23 */
  {  27,   0,  19}, /*  6:                   DESC shift  19 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {  76,  16,  34}, /*  8:                REPLACE shift  34 */
  { 123,  17,  37}, /*  9:                     id shift  37 */
  { 124,   0, 279}, /* 10:                    ids shift  279 */
  { 125,  19, 280}, /* 11:                idxitem shift  280 */
  { 126,   0, 309}, /* 12:                idxlist shift  309 */
  {  35,   0,  22}, /* 13:                EXPLAIN shift  22 */
  {  36,   0,  35}, /* 14:                   FAIL shift  35 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {   7,   0,  24}, /* 16:                  BEGIN shift  24 */
  {  31,   0,  25}, /* 17:                    END shift  25 */
  {  86,   0,  38}, /* 18:                 STRING shift  38 */
  {  56,   0,  31}, /* 19:                    KEY shift  31 */
  {  88,   0,  29}, /* 20:                   TEMP shift  29 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  45,   0,  28}, /* 22:                     ID shift  28 */
  {  68,  22,  30}, /* 23:                 OFFSET shift  30 */
/* State 309 */
  {  78,   2, 310}, /*  1:                     RP shift  310 */
  {  16,   0, 277}, /*  2:                  COMMA shift  277 */
/* State 310 */
  {  81,   2, 472}, /*  1:                   SEMI reduce 79 */
  {  69,   0,   9}, /*  2:                     ON shift  9 */
  { 137,   0, 311}, /*  3:                 onconf shift  311 */
/* State 311 */
  {  81,   0, 593}, /*  1:                   SEMI reduce 200 */
/* State 312 */
  {  49,   0, 594}, /*  1:                  INDEX reduce 201 */
/* State 313 */
  {  87,   0, 314}, /*  1:                  TABLE shift  314 */
  {  49,   0, 318}, /*  2:                  INDEX shift  318 */
  {  98,   0, 316}, /*  3:                   VIEW shift  316 */
/* State 314 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 315}, /* 20:                    ids shift  315 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 315 */
  {  81,   0, 481}, /*  1:                   SEMI reduce 88 */
/* State 316 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 317}, /* 20:                    ids shift  317 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 317 */
  {  81,   0, 483}, /*  1:                   SEMI reduce 90 */
/* State 318 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 319}, /* 20:                    ids shift  319 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 319 */
  {  81,   0, 599}, /*  1:                   SEMI reduce 206 */
/* State 320 */
  { 135,   0,  80}, /*  1:         multiselect_op shift  80 */
  {  81,   0, 484}, /*  2:                   SEMI reduce 91 */
  {  92,   4, 166}, /*  3:                  UNION shift  166 */
  {  52,   0, 168}, /*  4:              INTERSECT shift  168 */
  {  34,   0, 169}, /*  5:                 EXCEPT shift  169 */
/* State 321 */
  {  38,   0, 322}, /*  1:                   FROM shift  322 */
/* State 322 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 323}, /* 20:                    ids shift  323 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 323 */
  {  99,   3, 205}, /*  1:                  WHERE shift  205 */
  { 160,   0, 324}, /*  2:              where_opt shift  324 */
  {  81,   0, 527}, /*  3:                   SEMI reduce 134 */
/* State 324 */
  {  81,   0, 526}, /*  1:                   SEMI reduce 133 */
/* State 325 */
  {  70,   0, 326}, /*  1:                     OR shift  326 */
  { 139,   0, 328}, /*  2:                 orconf shift  328 */
/* State 326 */
  {  36,   0,  14}, /*  1:                   FAIL shift  14 */
  {   1,   0,  13}, /*  2:                  ABORT shift  13 */
  {  46,   0,  15}, /*  3:                 IGNORE shift  15 */
  {  77,   0,  12}, /*  4:               ROLLBACK shift  12 */
  {  76,   3,  16}, /*  5:                REPLACE shift  16 */
  { 143,   4, 327}, /*  6:            resolvetype shift  327 */
/* State 328 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 329}, /* 20:                    ids shift  329 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 329 */
  {  82,   0, 330}, /*  1:                    SET shift  330 */
/* State 330 */
  {  88,   0,  29}, /*  1:                   TEMP shift  29 */
  {  45,   4,  28}, /*  2:                     ID shift  28 */
  {  68,  12,  30}, /*  3:                 OFFSET shift  30 */
  {   1,   0,  32}, /*  4:                  ABORT shift  32 */
  {  26,   0,  21}, /*  5:             DELIMITERS shift  21 */
  {  27,   0,  19}, /*  6:                   DESC shift  19 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {  73,  16,  26}, /*  8:                 PRAGMA shift  26 */
  {  96,   0,  23}, /*  9:                 VACUUM shift  23 */
  {  31,   0,  25}, /* 10:                    END shift  25 */
  {  76,   0,  34}, /* 11:                REPLACE shift  34 */
  {  46,   0,  33}, /* 12:                 IGNORE shift  33 */
  {  56,   0,  31}, /* 13:                    KEY shift  31 */
  { 123,  18,  37}, /* 14:                     id shift  37 */
  { 124,  19, 337}, /* 15:                    ids shift  337 */
  {   7,   0,  24}, /* 16:                  BEGIN shift  24 */
  { 148,   0, 331}, /* 17:                setlist shift  331 */
  {  35,   0,  22}, /* 18:                EXPLAIN shift  22 */
  {  36,  20,  35}, /* 19:                   FAIL shift  35 */
  {  14,   0,  27}, /* 20:                CLUSTER shift  27 */
  {  86,  22,  38}, /* 21:                 STRING shift  38 */
  {  20,   0,  36}, /* 22:               CONFLICT shift  36 */
/* State 331 */
  { 160,   3, 332}, /*  1:              where_opt shift  332 */
  {  81,   0, 527}, /*  2:                   SEMI reduce 134 */
  {  16,   0, 333}, /*  3:                  COMMA shift  333 */
  {  99,   0, 205}, /*  4:                  WHERE shift  205 */
/* State 332 */
  {  81,   0, 529}, /*  1:                   SEMI reduce 136 */
/* State 333 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 334}, /* 20:                    ids shift  334 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 334 */
  {  33,   0, 335}, /*  1:                     EQ shift  335 */
/* State 335 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 336}, /* 28:                   expr shift  336 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 336 */
  {  57,   0, 118}, /*  1:                     LE shift  118 */
  {  79,   0, 132}, /*  2:                 RSHIFT shift  132 */
  {  54,   0, 154}, /*  3:                     IS shift  154 */
  {  55,   0, 153}, /*  4:                 ISNULL shift  153 */
  {   4,   0, 104}, /*  5:                    AND shift  104 */
  {  83,   1, 147}, /*  6:                  SLASH shift  147 */
  {  58,   0, 134}, /*  7:                   LIKE shift  134 */
  {  85,  17, 145}, /*  8:                   STAR shift  145 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  61,  22, 130}, /* 10:                 LSHIFT shift  130 */
  {  62,   0, 114}, /* 11:                     LT shift  114 */
  {  63,  25, 143}, /* 12:                  MINUS shift  143 */
  {  64,   0, 122}, /* 13:                     NE shift  122 */
  {  65,   0, 136}, /* 14:                    NOT shift  136 */
  {  66,  26, 158}, /* 15:                NOTNULL shift  158 */
  {  41,   0, 139}, /* 16:                   GLOB shift  139 */
  {  33,   0, 124}, /* 17:                     EQ shift  124 */
  {  43,   0, 116}, /* 18:                     GT shift  116 */
  {  70,   0, 112}, /* 19:                     OR shift  112 */
  {  19,   0, 151}, /* 20:                 CONCAT shift  151 */
  {  72,   0, 141}, /* 21:                   PLUS shift  141 */
  {   9,   0, 126}, /* 22:                 BITAND shift  126 */
  {  48,   0, 163}, /* 23:                     IN shift  163 */
  {  75,   0, 149}, /* 24:                    REM shift  149 */
  {  11,   0, 128}, /* 25:                  BITOR shift  128 */
  {  40,   0, 120}, /* 26:                     GE shift  120 */
/* State 337 */
  {  33,   0, 338}, /*  1:                     EQ shift  338 */
/* State 338 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 339}, /* 28:                   expr shift  339 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 339 */
  {  57,   0, 118}, /*  1:                     LE shift  118 */
  {  79,   0, 132}, /*  2:                 RSHIFT shift  132 */
  {  54,   0, 154}, /*  3:                     IS shift  154 */
  {  55,   0, 153}, /*  4:                 ISNULL shift  153 */
  {   4,   0, 104}, /*  5:                    AND shift  104 */
  {  83,   1, 147}, /*  6:                  SLASH shift  147 */
  {  58,   0, 134}, /*  7:                   LIKE shift  134 */
  {  85,  17, 145}, /*  8:                   STAR shift  145 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  61,  22, 130}, /* 10:                 LSHIFT shift  130 */
  {  62,   0, 114}, /* 11:                     LT shift  114 */
  {  63,  25, 143}, /* 12:                  MINUS shift  143 */
  {  64,   0, 122}, /* 13:                     NE shift  122 */
  {  65,   0, 136}, /* 14:                    NOT shift  136 */
  {  66,  26, 158}, /* 15:                NOTNULL shift  158 */
  {  41,   0, 139}, /* 16:                   GLOB shift  139 */
  {  33,   0, 124}, /* 17:                     EQ shift  124 */
  {  43,   0, 116}, /* 18:                     GT shift  116 */
  {  70,   0, 112}, /* 19:                     OR shift  112 */
  {  19,   0, 151}, /* 20:                 CONCAT shift  151 */
  {  72,   0, 141}, /* 21:                   PLUS shift  141 */
  {   9,   0, 126}, /* 22:                 BITAND shift  126 */
  {  48,   0, 163}, /* 23:                     IN shift  163 */
  {  75,   0, 149}, /* 24:                    REM shift  149 */
  {  11,   0, 128}, /* 25:                  BITOR shift  128 */
  {  40,   0, 120}, /* 26:                     GE shift  120 */
/* State 340 */
  {  53,   0, 341}, /*  1:                   INTO shift  341 */
/* State 341 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 342}, /* 20:                    ids shift  342 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 342 */
  {  60,   0, 352}, /*  1:                     LP shift  352 */
  { 129,   0, 343}, /*  2:         inscollist_opt shift  343 */
/* State 343 */
  {  80,   0,  82}, /*  1:                 SELECT shift  82 */
  {  97,   0, 345}, /*  2:                 VALUES shift  345 */
  { 146,   4, 344}, /*  3:                 select shift  344 */
  { 138,   0,  78}, /*  4:              oneselect shift  78 */
/* State 344 */
  { 135,   0,  80}, /*  1:         multiselect_op shift  80 */
  {  81,   0, 533}, /*  2:                   SEMI reduce 140 */
  {  92,   4, 166}, /*  3:                  UNION shift  166 */
  {  52,   0, 168}, /*  4:              INTERSECT shift  168 */
  {  34,   0, 169}, /*  5:                 EXCEPT shift  169 */
/* State 345 */
  {  60,   0, 346}, /*  1:                     LP shift  346 */
/* State 346 */
  { 124,   3, 106}, /*  1:                    ids shift  106 */
  {  63,   9, 176}, /*  2:                  MINUS shift  176 */
  {  31,   0,  25}, /*  3:                    END shift  25 */
  {  96,  10,  23}, /*  4:                 VACUUM shift  23 */
  {  35,   0,  22}, /*  5:                EXPLAIN shift  22 */
  {  67,  13, 105}, /*  6:                   NULL shift  105 */
  {  68,  14,  30}, /*  7:                 OFFSET shift  30 */
  { 131,  17, 347}, /*  8:               itemlist shift  347 */
  {   1,   0,  32}, /*  9:                  ABORT shift  32 */
  {  65,   0, 172}, /* 10:                    NOT shift  172 */
  {  72,  18, 178}, /* 11:                   PLUS shift  178 */
  {  73,   0,  26}, /* 12:                 PRAGMA shift  26 */
  {  36,   0,  35}, /* 13:                   FAIL shift  35 */
  {  37,  19, 110}, /* 14:                  FLOAT shift  110 */
  {  76,  20,  34}, /* 15:                REPLACE shift  34 */
  {  46,   0,  33}, /* 16:                 IGNORE shift  33 */
  {   7,   0,  24}, /* 17:                  BEGIN shift  24 */
  {  10,   0, 174}, /* 18:                 BITNOT shift  174 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  45,  22,  73}, /* 20:                     ID shift  73 */
  {  51,  23, 109}, /* 21:                INTEGER shift  109 */
  {  14,   0,  27}, /* 22:                CLUSTER shift  27 */
  {  20,   0,  36}, /* 23:               CONFLICT shift  36 */
  {  86,   0,  76}, /* 24:                 STRING shift  76 */
  { 117,  24, 351}, /* 25:                   expr shift  351 */
  {  56,   0,  31}, /* 26:                    KEY shift  31 */
  {  88,  29,  29}, /* 27:                   TEMP shift  29 */
  {  27,   0,  19}, /* 28:                   DESC shift  19 */
  {  26,   0,  21}, /* 29:             DELIMITERS shift  21 */
  {  60,   0,  77}, /* 30:                     LP shift  77 */
  { 123,   0,  75}, /* 31:                     id shift  75 */
/* State 347 */
  {  78,   2, 348}, /*  1:                     RP shift  348 */
  {  16,   0, 349}, /*  2:                  COMMA shift  349 */
/* State 348 */
  {  81,   0, 532}, /*  1:                   SEMI reduce 139 */
/* State 349 */
  {  60,   0,  77}, /*  1:                     LP shift  77 */
  {  31,   3,  25}, /*  2:                    END shift  25 */
  {   1,   0,  32}, /*  3:                  ABORT shift  32 */
  { 123,  10,  75}, /*  4:                     id shift  75 */
  { 124,   0, 106}, /*  5:                    ids shift  106 */
  {  65,  12, 172}, /*  6:                    NOT shift  172 */
  {  96,  18,  23}, /*  7:                 VACUUM shift  23 */
  {  67,  19, 105}, /*  8:                   NULL shift  105 */
  {  68,   0,  30}, /*  9:                 OFFSET shift  30 */
  {  63,   0, 176}, /* 10:                  MINUS shift  176 */
  {  10,   0, 174}, /* 11:                 BITNOT shift  174 */
  {  35,   0,  22}, /* 12:                EXPLAIN shift  22 */
  {  72,   0, 178}, /* 13:                   PLUS shift  178 */
  {  73,   0,  26}, /* 14:                 PRAGMA shift  26 */
  {  14,   0,  27}, /* 15:                CLUSTER shift  27 */
  {  45,   0,  73}, /* 16:                     ID shift  73 */
  {  76,  20,  34}, /* 17:                REPLACE shift  34 */
  {  36,  23,  35}, /* 18:                   FAIL shift  35 */
  {  37,  24, 110}, /* 19:                  FLOAT shift  110 */
  {  46,   0,  33}, /* 20:                 IGNORE shift  33 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  51,   0, 109}, /* 22:                INTEGER shift  109 */
  {   6,   0,  20}, /* 23:                    ASC shift  20 */
  {   7,   0,  24}, /* 24:                  BEGIN shift  24 */
  {  56,  26,  31}, /* 25:                    KEY shift  31 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  {  86,  25,  76}, /* 27:                 STRING shift  76 */
  { 117,  30, 350}, /* 28:                   expr shift  350 */
  {  88,   0,  29}, /* 29:                   TEMP shift  29 */
  {  27,   0,  19}, /* 30:                   DESC shift  19 */
/* State 350 */
  {  57,   0, 118}, /*  1:                     LE shift  118 */
  {  79,   0, 132}, /*  2:                 RSHIFT shift  132 */
  {  54,   0, 154}, /*  3:                     IS shift  154 */
  {  55,   0, 153}, /*  4:                 ISNULL shift  153 */
  {   4,   0, 104}, /*  5:                    AND shift  104 */
  {  83,   1, 147}, /*  6:                  SLASH shift  147 */
  {  58,   0, 134}, /*  7:                   LIKE shift  134 */
  {  85,  17, 145}, /*  8:                   STAR shift  145 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  61,  22, 130}, /* 10:                 LSHIFT shift  130 */
  {  62,   0, 114}, /* 11:                     LT shift  114 */
  {  63,  25, 143}, /* 12:                  MINUS shift  143 */
  {  64,   0, 122}, /* 13:                     NE shift  122 */
  {  65,   0, 136}, /* 14:                    NOT shift  136 */
  {  66,  26, 158}, /* 15:                NOTNULL shift  158 */
  {  41,   0, 139}, /* 16:                   GLOB shift  139 */
  {  33,   0, 124}, /* 17:                     EQ shift  124 */
  {  43,   0, 116}, /* 18:                     GT shift  116 */
  {  70,   0, 112}, /* 19:                     OR shift  112 */
  {  19,   0, 151}, /* 20:                 CONCAT shift  151 */
  {  72,   0, 141}, /* 21:                   PLUS shift  141 */
  {   9,   0, 126}, /* 22:                 BITAND shift  126 */
  {  48,   0, 163}, /* 23:                     IN shift  163 */
  {  75,   0, 149}, /* 24:                    REM shift  149 */
  {  11,   0, 128}, /* 25:                  BITOR shift  128 */
  {  40,   0, 120}, /* 26:                     GE shift  120 */
/* State 351 */
  {  57,   0, 118}, /*  1:                     LE shift  118 */
  {  79,   0, 132}, /*  2:                 RSHIFT shift  132 */
  {  54,   0, 154}, /*  3:                     IS shift  154 */
  {  55,   0, 153}, /*  4:                 ISNULL shift  153 */
  {   4,   0, 104}, /*  5:                    AND shift  104 */
  {  83,   1, 147}, /*  6:                  SLASH shift  147 */
  {  58,   0, 134}, /*  7:                   LIKE shift  134 */
  {  85,  17, 145}, /*  8:                   STAR shift  145 */
  {   8,   0, 159}, /*  9:                BETWEEN shift  159 */
  {  61,  22, 130}, /* 10:                 LSHIFT shift  130 */
  {  62,   0, 114}, /* 11:                     LT shift  114 */
  {  63,  25, 143}, /* 12:                  MINUS shift  143 */
  {  64,   0, 122}, /* 13:                     NE shift  122 */
  {  65,   0, 136}, /* 14:                    NOT shift  136 */
  {  66,  26, 158}, /* 15:                NOTNULL shift  158 */
  {  41,   0, 139}, /* 16:                   GLOB shift  139 */
  {  33,   0, 124}, /* 17:                     EQ shift  124 */
  {  43,   0, 116}, /* 18:                     GT shift  116 */
  {  70,   0, 112}, /* 19:                     OR shift  112 */
  {  19,   0, 151}, /* 20:                 CONCAT shift  151 */
  {  72,   0, 141}, /* 21:                   PLUS shift  141 */
  {   9,   0, 126}, /* 22:                 BITAND shift  126 */
  {  48,   0, 163}, /* 23:                     IN shift  163 */
  {  75,   0, 149}, /* 24:                    REM shift  149 */
  {  11,   0, 128}, /* 25:                  BITOR shift  128 */
  {  40,   0, 120}, /* 26:                     GE shift  120 */
/* State 352 */
  {  88,   0,  29}, /*  1:                   TEMP shift  29 */
  {  45,   4,  28}, /*  2:                     ID shift  28 */
  {  68,  12,  30}, /*  3:                 OFFSET shift  30 */
  {   1,   0,  32}, /*  4:                  ABORT shift  32 */
  {  26,   0,  21}, /*  5:             DELIMITERS shift  21 */
  {  27,   0,  19}, /*  6:                   DESC shift  19 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {  73,  16,  26}, /*  8:                 PRAGMA shift  26 */
  {  96,   0,  23}, /*  9:                 VACUUM shift  23 */
  {  31,   0,  25}, /* 10:                    END shift  25 */
  {  76,   0,  34}, /* 11:                REPLACE shift  34 */
  {  46,   0,  33}, /* 12:                 IGNORE shift  33 */
  {  56,   0,  31}, /* 13:                    KEY shift  31 */
  { 123,  17,  37}, /* 14:                     id shift  37 */
  { 124,  18, 357}, /* 15:                    ids shift  357 */
  {   7,   0,  24}, /* 16:                  BEGIN shift  24 */
  {  35,   0,  22}, /* 17:                EXPLAIN shift  22 */
  {  36,  20,  35}, /* 18:                   FAIL shift  35 */
  { 128,   0, 353}, /* 19:             inscollist shift  353 */
  {  14,   0,  27}, /* 20:                CLUSTER shift  27 */
  {  86,  22,  38}, /* 21:                 STRING shift  38 */
  {  20,   0,  36}, /* 22:               CONFLICT shift  36 */
/* State 353 */
  {  78,   2, 354}, /*  1:                     RP shift  354 */
  {  16,   0, 355}, /*  2:                  COMMA shift  355 */
/* State 355 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 356}, /* 20:                    ids shift  356 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 358 */
  {  70,   0, 326}, /*  1:                     OR shift  326 */
  { 139,   1, 359}, /*  2:                 orconf shift  359 */
  {  53,   0, 474}, /*  3:                   INTO reduce 81 */
/* State 359 */
  {  53,   0, 534}, /*  1:                   INTO reduce 141 */
/* State 360 */
  {  53,   0, 535}, /*  1:                   INTO reduce 142 */
/* State 361 */
  {  70,   0, 326}, /*  1:                     OR shift  326 */
  { 139,   0, 362}, /*  2:                 orconf shift  362 */
/* State 362 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 363}, /* 20:                    ids shift  363 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 363 */
  {  38,   0, 364}, /*  1:                   FROM shift  364 */
/* State 364 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 365}, /* 20:                    ids shift  365 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 365 */
  {  81,   0, 601}, /*  1:                   SEMI reduce 208 */
  {  95,   1, 366}, /*  2:                  USING shift  366 */
/* State 366 */
  {  26,   0, 367}, /*  1:             DELIMITERS shift  367 */
/* State 367 */
  {  86,   0, 368}, /*  1:                 STRING shift  368 */
/* State 368 */
  {  81,   0, 600}, /*  1:                   SEMI reduce 207 */
/* State 369 */
  {  88,   0,  29}, /*  1:                   TEMP shift  29 */
  {  45,   4,  28}, /*  2:                     ID shift  28 */
  {  68,  12,  30}, /*  3:                 OFFSET shift  30 */
  {   1,   0,  32}, /*  4:                  ABORT shift  32 */
  {  26,   0,  21}, /*  5:             DELIMITERS shift  21 */
  {  27,   0,  19}, /*  6:                   DESC shift  19 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {  73,  17,  26}, /*  8:                 PRAGMA shift  26 */
  {  96,   0,  23}, /*  9:                 VACUUM shift  23 */
  {  31,   0,  25}, /* 10:                    END shift  25 */
  {  76,   0,  34}, /* 11:                REPLACE shift  34 */
  {  46,   0,  33}, /* 12:                 IGNORE shift  33 */
  {  56,   0,  31}, /* 13:                    KEY shift  31 */
  { 123,  18,  37}, /* 14:                     id shift  37 */
  { 124,  19, 370}, /* 15:                    ids shift  370 */
  {  81,   0, 602}, /* 16:                   SEMI reduce 209 */
  {   7,   0,  24}, /* 17:                  BEGIN shift  24 */
  {  35,   0,  22}, /* 18:                EXPLAIN shift  22 */
  {  36,  20,  35}, /* 19:                   FAIL shift  35 */
  {  14,   0,  27}, /* 20:                CLUSTER shift  27 */
  {  86,  22,  38}, /* 21:                 STRING shift  38 */
  {  20,   0,  36}, /* 22:               CONFLICT shift  36 */
/* State 370 */
  {  81,   0, 603}, /*  1:                   SEMI reduce 210 */
/* State 371 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 372}, /* 20:                    ids shift  372 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 372 */
  {  81,   2, 609}, /*  1:                   SEMI reduce 216 */
  {  60,   3, 385}, /*  2:                     LP shift  385 */
  {  33,   0, 373}, /*  3:                     EQ shift  373 */
/* State 373 */
  {  27,   0,  19}, /*  1:                   DESC shift  19 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  56,   0,  31}, /*  3:                    KEY shift  31 */
  {   6,   0,  20}, /*  4:                    ASC shift  20 */
  {  31,   0,  25}, /*  5:                    END shift  25 */
  {  86,   0,  38}, /*  6:                 STRING shift  38 */
  { 141,   4, 376}, /*  7:               plus_num shift  376 */
  { 142,  11, 378}, /*  8:               plus_opt shift  378 */
  {  35,   0,  22}, /*  9:                EXPLAIN shift  22 */
  {  63,  12, 382}, /* 10:                  MINUS shift  382 */
  {  88,  13,  29}, /* 11:                   TEMP shift  29 */
  {  36,   0,  35}, /* 12:                   FAIL shift  35 */
  {   7,   0,  24}, /* 13:                  BEGIN shift  24 */
  {  14,   0,  27}, /* 14:                CLUSTER shift  27 */
  {  68,  14,  30}, /* 15:                 OFFSET shift  30 */
  { 123,  18,  37}, /* 16:                     id shift  37 */
  { 124,   0, 374}, /* 17:                    ids shift  374 */
  {  96,  22,  23}, /* 18:                 VACUUM shift  23 */
  {  72,  24, 384}, /* 19:                   PLUS shift  384 */
  {  73,  25,  26}, /* 20:                 PRAGMA shift  26 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
  {  69,   0, 375}, /* 22:                     ON shift  375 */
  {  76,   0,  34}, /* 23:                REPLACE shift  34 */
  {  45,   0,  28}, /* 24:                     ID shift  28 */
  {  46,   0,  33}, /* 25:                 IGNORE shift  33 */
  {  26,   0,  21}, /* 26:             DELIMITERS shift  21 */
  { 134,  26, 377}, /* 27:              minus_num shift  377 */
/* State 374 */
  {  81,   0, 604}, /*  1:                   SEMI reduce 211 */
/* State 375 */
  {  81,   0, 605}, /*  1:                   SEMI reduce 212 */
/* State 376 */
  {  81,   0, 606}, /*  1:                   SEMI reduce 213 */
/* State 377 */
  {  81,   0, 607}, /*  1:                   SEMI reduce 214 */
/* State 378 */
  {  51,   0, 380}, /*  1:                INTEGER shift  380 */
  { 136,   3, 379}, /*  2:                 number shift  379 */
  {  37,   0, 381}, /*  3:                  FLOAT shift  381 */
/* State 379 */
  {  81,   0, 610}, /*  1:                   SEMI reduce 217 */
/* State 380 */
  {  81,   0, 612}, /*  1:                   SEMI reduce 219 */
/* State 381 */
  {  81,   0, 613}, /*  1:                   SEMI reduce 220 */
/* State 382 */
  {  51,   0, 380}, /*  1:                INTEGER shift  380 */
  { 136,   3, 383}, /*  2:                 number shift  383 */
  {  37,   0, 381}, /*  3:                  FLOAT shift  381 */
/* State 383 */
  {  81,   0, 611}, /*  1:                   SEMI reduce 218 */
/* State 385 */
  {  46,   0,  33}, /*  1:                 IGNORE shift  33 */
  {   1,   0,  32}, /*  2:                  ABORT shift  32 */
  {  86,   0,  38}, /*  3:                 STRING shift  38 */
  {  45,   0,  28}, /*  4:                     ID shift  28 */
  {  88,   1,  29}, /*  5:                   TEMP shift  29 */
  {  68,   9,  30}, /*  6:                 OFFSET shift  30 */
  {  27,  10,  19}, /*  7:                   DESC shift  19 */
  {   7,   0,  24}, /*  8:                  BEGIN shift  24 */
  {  26,   0,  21}, /*  9:             DELIMITERS shift  21 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  73,  12,  26}, /* 11:                 PRAGMA shift  26 */
  {  31,   0,  25}, /* 12:                    END shift  25 */
  {  96,   0,  23}, /* 13:                 VACUUM shift  23 */
  {  76,   0,  34}, /* 14:                REPLACE shift  34 */
  {  56,  17,  31}, /* 15:                    KEY shift  31 */
  {  36,   0,  35}, /* 16:                   FAIL shift  35 */
  {  35,  18,  22}, /* 17:                EXPLAIN shift  22 */
  {  14,   0,  27}, /* 18:                CLUSTER shift  27 */
  { 123,   0,  37}, /* 19:                     id shift  37 */
  { 124,   0, 386}, /* 20:                    ids shift  386 */
  {  20,   0,  36}, /* 21:               CONFLICT shift  36 */
/* State 386 */
  {  78,   0, 387}, /*  1:                     RP shift  387 */
/* State 387 */
  {  81,   0, 608}, /*  1:                   SEMI reduce 215 */
/* State 388 */
  {  81,   0, 389}, /*  1:                   SEMI shift  389 */
};

/* The state table contains information needed to look up the correct
** action in the action table, given the current state of the parser.
** Information needed includes:
**
**  +  A pointer to the start of the action hash table in yyActionTable.
**
**  +  The number of entries in the action hash table.
**
**  +  The default action.  This is the action to take if no entry for
**     the given look-ahead is found in the action hash table.
*/
struct yyStateEntry {
  const yyActionEntry *hashtbl;  /* Start of the hash table in yyActionTable */
  YYCODETYPE nEntry;             /* Number of entries in action hash table */
  YYACTIONTYPE actionDefault;    /* Default action if look-ahead not found */
};
typedef struct yyStateEntry yyStateEntry;
static const yyStateEntry yyStateTable[] = {
  { &yyActionTable[0],  25, 616 },
  { &yyActionTable[25],  24, 616 },
  { &yyActionTable[49],   0, 395 },
  { &yyActionTable[49],  19, 616 },
  { &yyActionTable[68],   1, 616 },
  { &yyActionTable[69],   0, 396 },
  { &yyActionTable[69],   2, 401 },
  { &yyActionTable[71],   3, 616 },
  { &yyActionTable[74],   1, 616 },
  { &yyActionTable[75],   1, 616 },
  { &yyActionTable[76],   6, 616 },
  { &yyActionTable[82],   0, 473 },
  { &yyActionTable[82],   0, 476 },
  { &yyActionTable[82],   0, 477 },
  { &yyActionTable[82],   0, 478 },
  { &yyActionTable[82],   0, 479 },
  { &yyActionTable[82],   0, 480 },
  { &yyActionTable[82],  21, 402 },
  { &yyActionTable[103],   0, 403 },
  { &yyActionTable[103],   0, 417 },
  { &yyActionTable[103],   0, 418 },
  { &yyActionTable[103],   0, 419 },
  { &yyActionTable[103],   0, 420 },
  { &yyActionTable[103],   0, 421 },
  { &yyActionTable[103],   0, 422 },
  { &yyActionTable[103],   0, 423 },
  { &yyActionTable[103],   0, 424 },
  { &yyActionTable[103],   0, 425 },
  { &yyActionTable[103],   0, 426 },
  { &yyActionTable[103],   0, 427 },
  { &yyActionTable[103],   0, 428 },
  { &yyActionTable[103],   0, 429 },
  { &yyActionTable[103],   0, 430 },
  { &yyActionTable[103],   0, 431 },
  { &yyActionTable[103],   0, 432 },
  { &yyActionTable[103],   0, 433 },
  { &yyActionTable[103],   0, 434 },
  { &yyActionTable[103],   0, 435 },
  { &yyActionTable[103],   0, 436 },
  { &yyActionTable[103],   3, 616 },
  { &yyActionTable[106],   1, 616 },
  { &yyActionTable[107],   3, 616 },
  { &yyActionTable[110],   1, 616 },
  { &yyActionTable[111],   3, 616 },
  { &yyActionTable[114],   1, 616 },
  { &yyActionTable[115],   3, 616 },
  { &yyActionTable[118],   1, 616 },
  { &yyActionTable[119],  24, 616 },
  { &yyActionTable[143],   3, 616 },
  { &yyActionTable[146],   1, 616 },
  { &yyActionTable[147],   1, 616 },
  { &yyActionTable[148],  29, 616 },
  { &yyActionTable[177],   0, 413 },
  { &yyActionTable[177],  23, 437 },
  { &yyActionTable[200],   1, 447 },
  { &yyActionTable[201],   8, 415 },
  { &yyActionTable[209],   0, 446 },
  { &yyActionTable[209],  21, 616 },
  { &yyActionTable[230],   5, 616 },
  { &yyActionTable[235],   0, 448 },
  { &yyActionTable[235],   1, 616 },
  { &yyActionTable[236],   2, 472 },
  { &yyActionTable[238],   0, 459 },
  { &yyActionTable[238],   1, 616 },
  { &yyActionTable[239],   3, 516 },
  { &yyActionTable[242],   2, 472 },
  { &yyActionTable[244],   0, 460 },
  { &yyActionTable[244],   0, 514 },
  { &yyActionTable[244],   0, 515 },
  { &yyActionTable[244],   2, 472 },
  { &yyActionTable[246],   0, 461 },
  { &yyActionTable[246],   1, 616 },
  { &yyActionTable[247],  30, 616 },
  { &yyActionTable[277],   1, 426 },
  { &yyActionTable[278],  33, 592 },
  { &yyActionTable[311],   1, 544 },
  { &yyActionTable[312],   1, 548 },
  { &yyActionTable[313],  33, 616 },
  { &yyActionTable[346],   0, 485 },
  { &yyActionTable[346],   5, 616 },
  { &yyActionTable[351],   2, 616 },
  { &yyActionTable[353],   0, 486 },
  { &yyActionTable[353],   3, 494 },
  { &yyActionTable[356],   2, 496 },
  { &yyActionTable[358],   3, 616 },
  { &yyActionTable[361],   2, 527 },
  { &yyActionTable[363],   2, 517 },
  { &yyActionTable[365],   2, 519 },
  { &yyActionTable[367],   2, 509 },
  { &yyActionTable[369],   2, 521 },
  { &yyActionTable[371],   0, 491 },
  { &yyActionTable[371],   1, 616 },
  { &yyActionTable[372],   3, 522 },
  { &yyActionTable[375],   1, 616 },
  { &yyActionTable[376],   0, 523 },
  { &yyActionTable[376],   1, 616 },
  { &yyActionTable[377],   1, 616 },
  { &yyActionTable[378],   1, 616 },
  { &yyActionTable[379],  32, 616 },
  { &yyActionTable[411],   1, 510 },
  { &yyActionTable[412],  31, 616 },
  { &yyActionTable[443],   3, 516 },
  { &yyActionTable[446],   0, 511 },
  { &yyActionTable[446],  26, 513 },
  { &yyActionTable[472],  30, 616 },
  { &yyActionTable[502],   0, 543 },
  { &yyActionTable[502],   1, 616 },
  { &yyActionTable[503],  21, 616 },
  { &yyActionTable[524],   0, 545 },
  { &yyActionTable[524],   0, 546 },
  { &yyActionTable[524],   0, 547 },
  { &yyActionTable[524],  24, 551 },
  { &yyActionTable[548],  30, 616 },
  { &yyActionTable[578],  25, 552 },
  { &yyActionTable[603],  30, 616 },
  { &yyActionTable[633],  10, 553 },
  { &yyActionTable[643],  30, 616 },
  { &yyActionTable[673],  10, 554 },
  { &yyActionTable[683],  30, 616 },
  { &yyActionTable[713],  10, 555 },
  { &yyActionTable[723],  30, 616 },
  { &yyActionTable[753],  10, 556 },
  { &yyActionTable[763],  30, 616 },
  { &yyActionTable[793],  14, 557 },
  { &yyActionTable[807],  30, 616 },
  { &yyActionTable[837],  14, 558 },
  { &yyActionTable[851],  30, 616 },
  { &yyActionTable[881],   6, 559 },
  { &yyActionTable[887],  30, 616 },
  { &yyActionTable[917],   6, 560 },
  { &yyActionTable[923],  30, 616 },
  { &yyActionTable[953],   6, 561 },
  { &yyActionTable[959],  30, 616 },
  { &yyActionTable[989],   6, 562 },
  { &yyActionTable[995],  30, 616 },
  { &yyActionTable[1025],  14, 563 },
  { &yyActionTable[1039],   5, 616 },
  { &yyActionTable[1044],  30, 616 },
  { &yyActionTable[1074],  24, 564 },
  { &yyActionTable[1098],  30, 616 },
  { &yyActionTable[1128],  14, 565 },
  { &yyActionTable[1142],  30, 616 },
  { &yyActionTable[1172],   4, 567 },
  { &yyActionTable[1176],  30, 616 },
  { &yyActionTable[1206],   4, 568 },
  { &yyActionTable[1210],  30, 616 },
  { &yyActionTable[1240],   1, 569 },
  { &yyActionTable[1241],  30, 616 },
  { &yyActionTable[1271],   1, 570 },
  { &yyActionTable[1272],  30, 616 },
  { &yyActionTable[1302],   1, 571 },
  { &yyActionTable[1303],  30, 616 },
  { &yyActionTable[1333],   0, 572 },
  { &yyActionTable[1333],   0, 573 },
  { &yyActionTable[1333],   2, 616 },
  { &yyActionTable[1335],   0, 574 },
  { &yyActionTable[1335],   1, 616 },
  { &yyActionTable[1336],   0, 577 },
  { &yyActionTable[1336],   0, 575 },
  { &yyActionTable[1336],  30, 616 },
  { &yyActionTable[1366],  26, 616 },
  { &yyActionTable[1392],  30, 616 },
  { &yyActionTable[1422],  14, 583 },
  { &yyActionTable[1436],   1, 616 },
  { &yyActionTable[1437],  35, 592 },
  { &yyActionTable[1472],   5, 616 },
  { &yyActionTable[1477],   2, 616 },
  { &yyActionTable[1479],   1, 616 },
  { &yyActionTable[1480],   1, 616 },
  { &yyActionTable[1481],   1, 616 },
  { &yyActionTable[1482],   0, 586 },
  { &yyActionTable[1482],  26, 591 },
  { &yyActionTable[1508],  30, 616 },
  { &yyActionTable[1538],  24, 578 },
  { &yyActionTable[1562],  30, 616 },
  { &yyActionTable[1592],   0, 579 },
  { &yyActionTable[1592],  30, 616 },
  { &yyActionTable[1622],   0, 580 },
  { &yyActionTable[1622],  30, 616 },
  { &yyActionTable[1652],   0, 581 },
  { &yyActionTable[1652],   2, 616 },
  { &yyActionTable[1654],   0, 585 },
  { &yyActionTable[1654],  31, 592 },
  { &yyActionTable[1685],   0, 589 },
  { &yyActionTable[1685],   0, 590 },
  { &yyActionTable[1685],  30, 616 },
  { &yyActionTable[1715],  24, 566 },
  { &yyActionTable[1739],   0, 576 },
  { &yyActionTable[1739],  30, 616 },
  { &yyActionTable[1769],  26, 616 },
  { &yyActionTable[1795],  30, 616 },
  { &yyActionTable[1825],  24, 584 },
  { &yyActionTable[1849],   1, 616 },
  { &yyActionTable[1850],  35, 592 },
  { &yyActionTable[1885],   5, 616 },
  { &yyActionTable[1890],   0, 588 },
  { &yyActionTable[1890],   2, 616 },
  { &yyActionTable[1892],   0, 587 },
  { &yyActionTable[1892],   3, 516 },
  { &yyActionTable[1895],   0, 512 },
  { &yyActionTable[1895],  30, 616 },
  { &yyActionTable[1925],  26, 520 },
  { &yyActionTable[1951],   1, 616 },
  { &yyActionTable[1952],  32, 592 },
  { &yyActionTable[1984],   1, 518 },
  { &yyActionTable[1985],  30, 616 },
  { &yyActionTable[2015],  26, 528 },
  { &yyActionTable[2041],   0, 495 },
  { &yyActionTable[2041],   2, 504 },
  { &yyActionTable[2043],   1, 502 },
  { &yyActionTable[2044],   0, 503 },
  { &yyActionTable[2044],  22, 616 },
  { &yyActionTable[2066],  13, 500 },
  { &yyActionTable[2079],   0, 501 },
  { &yyActionTable[2079],  21, 616 },
  { &yyActionTable[2100],   0, 506 },
  { &yyActionTable[2100],   3, 616 },
  { &yyActionTable[2103],   5, 616 },
  { &yyActionTable[2108],  13, 500 },
  { &yyActionTable[2121],  21, 616 },
  { &yyActionTable[2142],   0, 508 },
  { &yyActionTable[2142],  31, 616 },
  { &yyActionTable[2173],  30, 500 },
  { &yyActionTable[2203],  21, 616 },
  { &yyActionTable[2224],   0, 498 },
  { &yyActionTable[2224],   0, 499 },
  { &yyActionTable[2224],   0, 492 },
  { &yyActionTable[2224],   0, 493 },
  { &yyActionTable[2224],   0, 582 },
  { &yyActionTable[2224],  27, 616 },
  { &yyActionTable[2251],   0, 542 },
  { &yyActionTable[2251],   2, 616 },
  { &yyActionTable[2253],   0, 549 },
  { &yyActionTable[2253],   1, 616 },
  { &yyActionTable[2254],   0, 550 },
  { &yyActionTable[2254],  27, 616 },
  { &yyActionTable[2281],   2, 472 },
  { &yyActionTable[2283],   0, 462 },
  { &yyActionTable[2283],   0, 449 },
  { &yyActionTable[2283],   7, 616 },
  { &yyActionTable[2290],   0, 450 },
  { &yyActionTable[2290],   0, 451 },
  { &yyActionTable[2290],   0, 452 },
  { &yyActionTable[2290],   2, 616 },
  { &yyActionTable[2292],   0, 453 },
  { &yyActionTable[2292],   0, 456 },
  { &yyActionTable[2292],   2, 616 },
  { &yyActionTable[2294],   0, 454 },
  { &yyActionTable[2294],   0, 457 },
  { &yyActionTable[2294],   0, 455 },
  { &yyActionTable[2294],   0, 458 },
  { &yyActionTable[2294],  22, 438 },
  { &yyActionTable[2316],   4, 616 },
  { &yyActionTable[2320],   2, 616 },
  { &yyActionTable[2322],   0, 439 },
  { &yyActionTable[2322],   4, 616 },
  { &yyActionTable[2326],   1, 616 },
  { &yyActionTable[2327],   0, 440 },
  { &yyActionTable[2327],   0, 443 },
  { &yyActionTable[2327],   1, 616 },
  { &yyActionTable[2328],   0, 444 },
  { &yyActionTable[2328],   1, 616 },
  { &yyActionTable[2329],   0, 445 },
  { &yyActionTable[2329],   0, 442 },
  { &yyActionTable[2329],   0, 441 },
  { &yyActionTable[2329],   0, 416 },
  { &yyActionTable[2329],   7, 616 },
  { &yyActionTable[2336],   5, 616 },
  { &yyActionTable[2341],   0, 465 },
  { &yyActionTable[2341],  21, 616 },
  { &yyActionTable[2362],   0, 468 },
  { &yyActionTable[2362],   1, 616 },
  { &yyActionTable[2363],   1, 616 },
  { &yyActionTable[2364],  23, 616 },
  { &yyActionTable[2387],   2, 616 },
  { &yyActionTable[2389],   2, 472 },
  { &yyActionTable[2391],   0, 469 },
  { &yyActionTable[2391],  22, 616 },
  { &yyActionTable[2413],   0, 596 },
  { &yyActionTable[2413],   0, 598 },
  { &yyActionTable[2413],   0, 597 },
  { &yyActionTable[2413],   1, 616 },
  { &yyActionTable[2414],  23, 616 },
  { &yyActionTable[2437],   2, 616 },
  { &yyActionTable[2439],   2, 472 },
  { &yyActionTable[2441],   0, 470 },
  { &yyActionTable[2441],  30, 616 },
  { &yyActionTable[2471],  28, 472 },
  { &yyActionTable[2499],   0, 471 },
  { &yyActionTable[2499],   0, 466 },
  { &yyActionTable[2499],   0, 467 },
  { &yyActionTable[2499],   0, 414 },
  { &yyActionTable[2499],   3, 616 },
  { &yyActionTable[2502],   5, 616 },
  { &yyActionTable[2507],   7, 616 },
  { &yyActionTable[2514],   1, 616 },
  { &yyActionTable[2515],  21, 616 },
  { &yyActionTable[2536],   0, 408 },
  { &yyActionTable[2536],   1, 616 },
  { &yyActionTable[2537],  21, 616 },
  { &yyActionTable[2558],   1, 616 },
  { &yyActionTable[2559],   3, 616 },
  { &yyActionTable[2562],   5, 616 },
  { &yyActionTable[2567],   1, 616 },
  { &yyActionTable[2568],  21, 616 },
  { &yyActionTable[2589],   1, 616 },
  { &yyActionTable[2590],  21, 616 },
  { &yyActionTable[2611],   1, 616 },
  { &yyActionTable[2612],  23, 616 },
  { &yyActionTable[2635],   2, 616 },
  { &yyActionTable[2637],   3, 616 },
  { &yyActionTable[2640],   1, 616 },
  { &yyActionTable[2641],   1, 616 },
  { &yyActionTable[2642],   3, 616 },
  { &yyActionTable[2645],  21, 616 },
  { &yyActionTable[2666],   1, 616 },
  { &yyActionTable[2667],  21, 616 },
  { &yyActionTable[2688],   1, 616 },
  { &yyActionTable[2689],  21, 616 },
  { &yyActionTable[2710],   1, 616 },
  { &yyActionTable[2711],   5, 616 },
  { &yyActionTable[2716],   1, 616 },
  { &yyActionTable[2717],  21, 616 },
  { &yyActionTable[2738],   3, 616 },
  { &yyActionTable[2741],   1, 616 },
  { &yyActionTable[2742],   2, 474 },
  { &yyActionTable[2744],   6, 616 },
  { &yyActionTable[2750],   0, 475 },
  { &yyActionTable[2750],  21, 616 },
  { &yyActionTable[2771],   1, 616 },
  { &yyActionTable[2772],  22, 616 },
  { &yyActionTable[2794],   4, 616 },
  { &yyActionTable[2798],   1, 616 },
  { &yyActionTable[2799],  21, 616 },
  { &yyActionTable[2820],   1, 616 },
  { &yyActionTable[2821],  30, 616 },
  { &yyActionTable[2851],  26, 530 },
  { &yyActionTable[2877],   1, 616 },
  { &yyActionTable[2878],  30, 616 },
  { &yyActionTable[2908],  26, 531 },
  { &yyActionTable[2934],   1, 616 },
  { &yyActionTable[2935],  21, 616 },
  { &yyActionTable[2956],   2, 538 },
  { &yyActionTable[2958],   4, 616 },
  { &yyActionTable[2962],   5, 616 },
  { &yyActionTable[2967],   1, 616 },
  { &yyActionTable[2968],  31, 616 },
  { &yyActionTable[2999],   2, 616 },
  { &yyActionTable[3001],   1, 616 },
  { &yyActionTable[3002],  30, 616 },
  { &yyActionTable[3032],  26, 536 },
  { &yyActionTable[3058],  26, 537 },
  { &yyActionTable[3084],  22, 616 },
  { &yyActionTable[3106],   2, 616 },
  { &yyActionTable[3108],   0, 539 },
  { &yyActionTable[3108],  21, 616 },
  { &yyActionTable[3129],   0, 540 },
  { &yyActionTable[3129],   0, 541 },
  { &yyActionTable[3129],   3, 616 },
  { &yyActionTable[3132],   1, 616 },
  { &yyActionTable[3133],   1, 616 },
  { &yyActionTable[3134],   2, 474 },
  { &yyActionTable[3136],  21, 616 },
  { &yyActionTable[3157],   1, 616 },
  { &yyActionTable[3158],  21, 616 },
  { &yyActionTable[3179],   2, 616 },
  { &yyActionTable[3181],   1, 616 },
  { &yyActionTable[3182],   1, 616 },
  { &yyActionTable[3183],   1, 616 },
  { &yyActionTable[3184],  22, 616 },
  { &yyActionTable[3206],   1, 616 },
  { &yyActionTable[3207],  21, 616 },
  { &yyActionTable[3228],   3, 616 },
  { &yyActionTable[3231],  27, 615 },
  { &yyActionTable[3258],   1, 616 },
  { &yyActionTable[3259],   1, 616 },
  { &yyActionTable[3260],   1, 616 },
  { &yyActionTable[3261],   1, 616 },
  { &yyActionTable[3262],   3, 616 },
  { &yyActionTable[3265],   1, 616 },
  { &yyActionTable[3266],   1, 616 },
  { &yyActionTable[3267],   1, 616 },
  { &yyActionTable[3268],   3, 616 },
  { &yyActionTable[3271],   1, 616 },
  { &yyActionTable[3272],   0, 614 },
  { &yyActionTable[3272],  21, 616 },
  { &yyActionTable[3293],   1, 616 },
  { &yyActionTable[3294],   1, 616 },
  { &yyActionTable[3295],   1, 616 },
  { &yyActionTable[3296],   0, 397 },
  { &yyActionTable[3296],   0, 398 },
  { &yyActionTable[3296],   0, 399 },
  { &yyActionTable[3296],   0, 394 },
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
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
  int yyerrcnt;                 /* Shifts left before out of the error */
  yyStackEntry *yytop;          /* Pointer to the top stack element */
  sqliteParserARG_SDECL                /* A place to hold %extra_argument */
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
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
static const char *yyTokenName[] = { 
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
  "VACUUM",        "VALUES",        "VIEW",          "WHERE",       
  "as",            "carg",          "carglist",      "ccons",       
  "cmd",           "cmdlist",       "column",        "columnid",    
  "columnlist",    "conslist",      "conslist_opt",  "create_table",
  "create_table_args",  "distinct",      "ecmd",          "error",       
  "explain",       "expr",          "expritem",      "exprlist",    
  "from",          "groupby_opt",   "having_opt",    "id",          
  "ids",           "idxitem",       "idxlist",       "input",       
  "inscollist",    "inscollist_opt",  "insert_cmd",    "itemlist",    
  "limit_opt",     "limit_sep",     "minus_num",     "multiselect_op",
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
void *sqliteParserAlloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
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
    case 117:
#line 393 "parse.y"
{sqliteExprDelete((yypminor->yy132));}
#line 4275 "parse.c"
      break;
    case 118:
#line 528 "parse.y"
{sqliteExprDelete((yypminor->yy132));}
#line 4280 "parse.c"
      break;
    case 119:
#line 526 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 4285 "parse.c"
      break;
    case 120:
#line 265 "parse.y"
{sqliteIdListDelete((yypminor->yy152));}
#line 4290 "parse.c"
      break;
    case 121:
#line 311 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 4295 "parse.c"
      break;
    case 122:
#line 316 "parse.y"
{sqliteExprDelete((yypminor->yy132));}
#line 4300 "parse.c"
      break;
    case 126:
#line 550 "parse.y"
{sqliteIdListDelete((yypminor->yy152));}
#line 4305 "parse.c"
      break;
    case 128:
#line 372 "parse.y"
{sqliteIdListDelete((yypminor->yy152));}
#line 4310 "parse.c"
      break;
    case 129:
#line 370 "parse.y"
{sqliteIdListDelete((yypminor->yy152));}
#line 4315 "parse.c"
      break;
    case 131:
#line 364 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 4320 "parse.c"
      break;
    case 138:
#line 212 "parse.y"
{sqliteSelectDelete((yypminor->yy233));}
#line 4325 "parse.c"
      break;
    case 140:
#line 286 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 4330 "parse.c"
      break;
    case 144:
#line 248 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 4335 "parse.c"
      break;
    case 145:
#line 246 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 4340 "parse.c"
      break;
    case 146:
#line 210 "parse.y"
{sqliteSelectDelete((yypminor->yy233));}
#line 4345 "parse.c"
      break;
    case 147:
#line 261 "parse.y"
{sqliteIdListDelete((yypminor->yy152));}
#line 4350 "parse.c"
      break;
    case 148:
#line 340 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 4355 "parse.c"
      break;
    case 150:
#line 290 "parse.y"
{sqliteExprDelete((yypminor->yy132));}
#line 4360 "parse.c"
      break;
    case 151:
#line 288 "parse.y"
{sqliteExprListDelete((yypminor->yy270));}
#line 4365 "parse.c"
      break;
    case 153:
#line 263 "parse.y"
{sqliteIdListDelete((yypminor->yy152));}
#line 4370 "parse.c"
      break;
    case 160:
#line 334 "parse.y"
{sqliteExprDelete((yypminor->yy132));}
#line 4375 "parse.c"
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

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[pParser->yytop->major]);
  }
#endif
  yymajor = pParser->yytop->major;
  yy_destructor( yymajor, &pParser->yytop->minor);
  pParser->yyidx--;
  pParser->yytop--;
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
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
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
  const yyStateEntry *pState;   /* Appropriate entry in the state table */
  const yyActionEntry *pAction; /* Action appropriate for the look-ahead */
 
  /* if( pParser->yyidx<0 ) return YY_NO_ACTION;  */
  pState = &yyStateTable[pParser->yytop->stateno];
  if( pState->nEntry==0 ){
    return pState->actionDefault;
  }else if( iLookAhead!=YYNOCODE ){
    pAction = &pState->hashtbl[iLookAhead % pState->nEntry];
    while( 1 ){
      if( pAction->lookahead==iLookAhead ) return pAction->action;
      if( pAction->next==0 ) return pState->actionDefault;
      pAction = &pState->hashtbl[pAction->next-1];
    }
  }else if( pState->hashtbl->lookahead!=YYNOCODE ){
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
  yypParser->yyidx++;
  yypParser->yytop++;
  if( yypParser->yyidx>=YYSTACKDEPTH ){
     sqliteParserARG_FETCH;
     yypParser->yyidx--;
     yypParser->yytop--;
#ifndef NDEBUG
     if( yyTraceFILE ){
       fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
     }
#endif
     while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     sqliteParserARG_STORE; /* Suppress warning about unused %extra_argument var */
     return;
  }
  yypParser->yytop->stateno = yyNewState;
  yypParser->yytop->major = yyMajor;
  yypParser->yytop->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
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
  { 127, 1 },
  { 105, 1 },
  { 105, 2 },
  { 114, 3 },
  { 114, 2 },
  { 114, 1 },
  { 116, 1 },
  { 104, 3 },
  { 156, 0 },
  { 156, 1 },
  { 156, 2 },
  { 104, 2 },
  { 104, 2 },
  { 104, 2 },
  { 104, 2 },
  { 111, 4 },
  { 155, 1 },
  { 155, 0 },
  { 112, 4 },
  { 112, 2 },
  { 108, 3 },
  { 108, 1 },
  { 106, 3 },
  { 107, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 123, 1 },
  { 124, 1 },
  { 124, 1 },
  { 157, 0 },
  { 157, 1 },
  { 157, 4 },
  { 157, 6 },
  { 158, 1 },
  { 158, 2 },
  { 149, 1 },
  { 149, 2 },
  { 149, 2 },
  { 102, 2 },
  { 102, 0 },
  { 101, 3 },
  { 101, 1 },
  { 101, 2 },
  { 101, 2 },
  { 101, 2 },
  { 101, 3 },
  { 101, 3 },
  { 101, 2 },
  { 101, 3 },
  { 101, 3 },
  { 101, 2 },
  { 103, 3 },
  { 103, 4 },
  { 103, 2 },
  { 103, 5 },
  { 110, 0 },
  { 110, 2 },
  { 109, 3 },
  { 109, 2 },
  { 109, 1 },
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
  { 104, 3 },
  { 104, 5 },
  { 104, 3 },
  { 104, 1 },
  { 146, 1 },
  { 146, 3 },
  { 135, 1 },
  { 135, 2 },
  { 135, 1 },
  { 135, 1 },
  { 138, 9 },
  { 113, 1 },
  { 113, 1 },
  { 113, 0 },
  { 144, 2 },
  { 144, 0 },
  { 145, 2 },
  { 145, 4 },
  { 145, 2 },
  { 100, 0 },
  { 100, 1 },
  { 120, 2 },
  { 153, 2 },
  { 153, 0 },
  { 147, 2 },
  { 147, 4 },
  { 147, 4 },
  { 147, 6 },
  { 140, 0 },
  { 140, 3 },
  { 151, 4 },
  { 151, 2 },
  { 150, 1 },
  { 152, 1 },
  { 152, 1 },
  { 152, 0 },
  { 121, 0 },
  { 121, 3 },
  { 122, 0 },
  { 122, 2 },
  { 132, 0 },
  { 132, 2 },
  { 132, 4 },
  { 133, 1 },
  { 133, 1 },
  { 104, 4 },
  { 160, 0 },
  { 160, 2 },
  { 104, 6 },
  { 148, 5 },
  { 148, 3 },
  { 104, 8 },
  { 104, 5 },
  { 130, 2 },
  { 130, 1 },
  { 131, 3 },
  { 131, 1 },
  { 129, 0 },
  { 129, 3 },
  { 128, 3 },
  { 128, 1 },
  { 117, 3 },
  { 117, 1 },
  { 117, 1 },
  { 117, 3 },
  { 117, 1 },
  { 117, 1 },
  { 117, 1 },
  { 117, 4 },
  { 117, 4 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 4 },
  { 117, 3 },
  { 117, 4 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 3 },
  { 117, 2 },
  { 117, 3 },
  { 117, 2 },
  { 117, 3 },
  { 117, 4 },
  { 117, 2 },
  { 117, 2 },
  { 117, 2 },
  { 117, 2 },
  { 117, 3 },
  { 117, 5 },
  { 117, 6 },
  { 117, 5 },
  { 117, 5 },
  { 117, 6 },
  { 117, 6 },
  { 119, 3 },
  { 119, 1 },
  { 118, 1 },
  { 118, 0 },
  { 104, 10 },
  { 159, 1 },
  { 159, 0 },
  { 126, 3 },
  { 126, 1 },
  { 125, 1 },
  { 104, 3 },
  { 104, 8 },
  { 104, 5 },
  { 104, 1 },
  { 104, 2 },
  { 104, 4 },
  { 104, 4 },
  { 104, 4 },
  { 104, 4 },
  { 104, 5 },
  { 104, 2 },
  { 141, 2 },
  { 134, 2 },
  { 136, 1 },
  { 136, 1 },
  { 142, 1 },
  { 142, 0 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  sqliteParserARG_FETCH;
  yymsp = yypParser->yytop;
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
        YYTRACE("cmdlist ::= cmdlist ecmd")
        /* No destructor defined for cmdlist */
        /* No destructor defined for ecmd */
        break;
      case 3:
        YYTRACE("ecmd ::= explain cmd SEMI")
#line 52 "parse.y"
{sqliteExec(pParse);}
#line 4777 "parse.c"
        /* No destructor defined for explain */
        /* No destructor defined for cmd */
        /* No destructor defined for SEMI */
        break;
      case 4:
        YYTRACE("ecmd ::= cmd SEMI")
#line 53 "parse.y"
{sqliteExec(pParse);}
#line 4786 "parse.c"
        /* No destructor defined for cmd */
        /* No destructor defined for SEMI */
        break;
      case 5:
        YYTRACE("ecmd ::= SEMI")
        /* No destructor defined for SEMI */
        break;
      case 6:
        YYTRACE("explain ::= EXPLAIN")
#line 55 "parse.y"
{pParse->explain = 1;}
#line 4798 "parse.c"
        /* No destructor defined for EXPLAIN */
        break;
      case 7:
        YYTRACE("cmd ::= BEGIN trans_opt onconf")
#line 60 "parse.y"
{sqliteBeginTransaction(pParse,yymsp[0].minor.yy144);}
#line 4805 "parse.c"
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
#line 4825 "parse.c"
        /* No destructor defined for COMMIT */
        /* No destructor defined for trans_opt */
        break;
      case 12:
        YYTRACE("cmd ::= END trans_opt")
#line 65 "parse.y"
{sqliteCommitTransaction(pParse);}
#line 4833 "parse.c"
        /* No destructor defined for END */
        /* No destructor defined for trans_opt */
        break;
      case 13:
        YYTRACE("cmd ::= ROLLBACK trans_opt")
#line 66 "parse.y"
{sqliteRollbackTransaction(pParse);}
#line 4841 "parse.c"
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
   sqliteStartTable(pParse,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy224,yymsp[-2].minor.yy144);
}
#line 4856 "parse.c"
        /* No destructor defined for TABLE */
        break;
      case 16:
        YYTRACE("temp ::= TEMP")
#line 75 "parse.y"
{yygotominor.yy144 = 1;}
#line 4863 "parse.c"
        /* No destructor defined for TEMP */
        break;
      case 17:
        YYTRACE("temp ::=")
#line 76 "parse.y"
{yygotominor.yy144 = 0;}
#line 4870 "parse.c"
        break;
      case 18:
        YYTRACE("create_table_args ::= LP columnlist conslist_opt RP")
#line 77 "parse.y"
{
  sqliteEndTable(pParse,&yymsp[0].minor.yy0,0);
}
#line 4878 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for columnlist */
        /* No destructor defined for conslist_opt */
        break;
      case 19:
        YYTRACE("create_table_args ::= AS select")
#line 80 "parse.y"
{
  sqliteEndTable(pParse,0,yymsp[0].minor.yy233);
  sqliteSelectDelete(yymsp[0].minor.yy233);
}
#line 4890 "parse.c"
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
{sqliteAddColumn(pParse,&yymsp[0].minor.yy224);}
#line 4913 "parse.c"
        break;
      case 24:
        YYTRACE("id ::= DESC")
#line 100 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 4919 "parse.c"
        break;
      case 25:
        YYTRACE("id ::= ASC")
#line 101 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 4925 "parse.c"
        break;
      case 26:
        YYTRACE("id ::= DELIMITERS")
#line 102 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 4931 "parse.c"
        break;
      case 27:
        YYTRACE("id ::= EXPLAIN")
#line 103 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 4937 "parse.c"
        break;
      case 28:
        YYTRACE("id ::= VACUUM")
#line 104 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 4943 "parse.c"
        break;
      case 29:
        YYTRACE("id ::= BEGIN")
#line 105 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 4949 "parse.c"
        break;
      case 30:
        YYTRACE("id ::= END")
#line 106 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 4955 "parse.c"
        break;
      case 31:
        YYTRACE("id ::= PRAGMA")
#line 107 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 4961 "parse.c"
        break;
      case 32:
        YYTRACE("id ::= CLUSTER")
#line 108 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 4967 "parse.c"
        break;
      case 33:
        YYTRACE("id ::= ID")
#line 109 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 4973 "parse.c"
        break;
      case 34:
        YYTRACE("id ::= TEMP")
#line 110 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 4979 "parse.c"
        break;
      case 35:
        YYTRACE("id ::= OFFSET")
#line 111 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 4985 "parse.c"
        break;
      case 36:
        YYTRACE("id ::= KEY")
#line 112 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 4991 "parse.c"
        break;
      case 37:
        YYTRACE("id ::= ABORT")
#line 113 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 4997 "parse.c"
        break;
      case 38:
        YYTRACE("id ::= IGNORE")
#line 114 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 5003 "parse.c"
        break;
      case 39:
        YYTRACE("id ::= REPLACE")
#line 115 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 5009 "parse.c"
        break;
      case 40:
        YYTRACE("id ::= FAIL")
#line 116 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 5015 "parse.c"
        break;
      case 41:
        YYTRACE("id ::= CONFLICT")
#line 117 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 5021 "parse.c"
        break;
      case 42:
        YYTRACE("ids ::= id")
#line 122 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy224;}
#line 5027 "parse.c"
        break;
      case 43:
        YYTRACE("ids ::= STRING")
#line 123 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 5033 "parse.c"
        break;
      case 44:
        YYTRACE("type ::=")
        break;
      case 45:
        YYTRACE("type ::= typename")
#line 126 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[0].minor.yy224,&yymsp[0].minor.yy224);}
#line 5042 "parse.c"
        break;
      case 46:
        YYTRACE("type ::= typename LP signed RP")
#line 127 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-3].minor.yy224,&yymsp[0].minor.yy0);}
#line 5048 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        break;
      case 47:
        YYTRACE("type ::= typename LP signed COMMA signed RP")
#line 129 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-5].minor.yy224,&yymsp[0].minor.yy0);}
#line 5056 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        /* No destructor defined for COMMA */
        /* No destructor defined for signed */
        break;
      case 48:
        YYTRACE("typename ::= ids")
#line 131 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy224;}
#line 5066 "parse.c"
        break;
      case 49:
        YYTRACE("typename ::= typename ids")
#line 132 "parse.y"
{yygotominor.yy224 = yymsp[-1].minor.yy224;}
#line 5072 "parse.c"
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
#line 5111 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 58:
        YYTRACE("carg ::= DEFAULT ID")
#line 141 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5118 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 59:
        YYTRACE("carg ::= DEFAULT INTEGER")
#line 142 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5125 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 60:
        YYTRACE("carg ::= DEFAULT PLUS INTEGER")
#line 143 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5132 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 61:
        YYTRACE("carg ::= DEFAULT MINUS INTEGER")
#line 144 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 5140 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 62:
        YYTRACE("carg ::= DEFAULT FLOAT")
#line 145 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5148 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 63:
        YYTRACE("carg ::= DEFAULT PLUS FLOAT")
#line 146 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5155 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 64:
        YYTRACE("carg ::= DEFAULT MINUS FLOAT")
#line 147 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 5163 "parse.c"
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
{sqliteAddNotNull(pParse, yymsp[0].minor.yy144);}
#line 5176 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for NULL */
        break;
      case 67:
        YYTRACE("ccons ::= PRIMARY KEY sortorder onconf")
#line 154 "parse.y"
{sqliteAddPrimaryKey(pParse,0,yymsp[0].minor.yy144);}
#line 5184 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for sortorder */
        break;
      case 68:
        YYTRACE("ccons ::= UNIQUE onconf")
#line 155 "parse.y"
{sqliteCreateIndex(pParse,0,0,0,yymsp[0].minor.yy144,0,0);}
#line 5193 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 69:
        YYTRACE("ccons ::= CHECK LP expr RP onconf")
        /* No destructor defined for CHECK */
        /* No destructor defined for LP */
  yy_destructor(117,&yymsp[-2].minor);
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
{sqliteAddPrimaryKey(pParse,yymsp[-2].minor.yy152,yymsp[0].minor.yy144);}
#line 5236 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 77:
        YYTRACE("tcons ::= UNIQUE LP idxlist RP onconf")
#line 170 "parse.y"
{sqliteCreateIndex(pParse,0,0,yymsp[-2].minor.yy152,yymsp[0].minor.yy144,0,0);}
#line 5246 "parse.c"
        /* No destructor defined for UNIQUE */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 78:
        YYTRACE("tcons ::= CHECK expr onconf")
        /* No destructor defined for CHECK */
  yy_destructor(117,&yymsp[-1].minor);
        /* No destructor defined for onconf */
        break;
      case 79:
        YYTRACE("onconf ::=")
#line 179 "parse.y"
{ yygotominor.yy144 = OE_Default; }
#line 5261 "parse.c"
        break;
      case 80:
        YYTRACE("onconf ::= ON CONFLICT resolvetype")
#line 180 "parse.y"
{ yygotominor.yy144 = yymsp[0].minor.yy144; }
#line 5267 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for CONFLICT */
        break;
      case 81:
        YYTRACE("orconf ::=")
#line 181 "parse.y"
{ yygotominor.yy144 = OE_Default; }
#line 5275 "parse.c"
        break;
      case 82:
        YYTRACE("orconf ::= OR resolvetype")
#line 182 "parse.y"
{ yygotominor.yy144 = yymsp[0].minor.yy144; }
#line 5281 "parse.c"
        /* No destructor defined for OR */
        break;
      case 83:
        YYTRACE("resolvetype ::= ROLLBACK")
#line 183 "parse.y"
{ yygotominor.yy144 = OE_Rollback; }
#line 5288 "parse.c"
        /* No destructor defined for ROLLBACK */
        break;
      case 84:
        YYTRACE("resolvetype ::= ABORT")
#line 184 "parse.y"
{ yygotominor.yy144 = OE_Abort; }
#line 5295 "parse.c"
        /* No destructor defined for ABORT */
        break;
      case 85:
        YYTRACE("resolvetype ::= FAIL")
#line 185 "parse.y"
{ yygotominor.yy144 = OE_Fail; }
#line 5302 "parse.c"
        /* No destructor defined for FAIL */
        break;
      case 86:
        YYTRACE("resolvetype ::= IGNORE")
#line 186 "parse.y"
{ yygotominor.yy144 = OE_Ignore; }
#line 5309 "parse.c"
        /* No destructor defined for IGNORE */
        break;
      case 87:
        YYTRACE("resolvetype ::= REPLACE")
#line 187 "parse.y"
{ yygotominor.yy144 = OE_Replace; }
#line 5316 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 88:
        YYTRACE("cmd ::= DROP TABLE ids")
#line 191 "parse.y"
{sqliteDropTable(pParse,&yymsp[0].minor.yy224,0);}
#line 5323 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for TABLE */
        break;
      case 89:
        YYTRACE("cmd ::= CREATE VIEW ids AS select")
#line 195 "parse.y"
{
  sqliteCreateView(pParse, &yymsp[-4].minor.yy0, &yymsp[-2].minor.yy224, yymsp[0].minor.yy233);
}
#line 5333 "parse.c"
        /* No destructor defined for VIEW */
        /* No destructor defined for AS */
        break;
      case 90:
        YYTRACE("cmd ::= DROP VIEW ids")
#line 198 "parse.y"
{
  sqliteDropTable(pParse, &yymsp[0].minor.yy224, 1);
}
#line 5343 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for VIEW */
        break;
      case 91:
        YYTRACE("cmd ::= select")
#line 204 "parse.y"
{
  sqliteSelect(pParse, yymsp[0].minor.yy233, SRT_Callback, 0, 0, 0, 0);
  sqliteSelectDelete(yymsp[0].minor.yy233);
}
#line 5354 "parse.c"
        break;
      case 92:
        YYTRACE("select ::= oneselect")
#line 214 "parse.y"
{yygotominor.yy233 = yymsp[0].minor.yy233;}
#line 5360 "parse.c"
        break;
      case 93:
        YYTRACE("select ::= select multiselect_op oneselect")
#line 215 "parse.y"
{
  if( yymsp[0].minor.yy233 ){
    yymsp[0].minor.yy233->op = yymsp[-1].minor.yy144;
    yymsp[0].minor.yy233->pPrior = yymsp[-2].minor.yy233;
  }
  yygotominor.yy233 = yymsp[0].minor.yy233;
}
#line 5372 "parse.c"
        break;
      case 94:
        YYTRACE("multiselect_op ::= UNION")
#line 223 "parse.y"
{yygotominor.yy144 = TK_UNION;}
#line 5378 "parse.c"
        /* No destructor defined for UNION */
        break;
      case 95:
        YYTRACE("multiselect_op ::= UNION ALL")
#line 224 "parse.y"
{yygotominor.yy144 = TK_ALL;}
#line 5385 "parse.c"
        /* No destructor defined for UNION */
        /* No destructor defined for ALL */
        break;
      case 96:
        YYTRACE("multiselect_op ::= INTERSECT")
#line 225 "parse.y"
{yygotominor.yy144 = TK_INTERSECT;}
#line 5393 "parse.c"
        /* No destructor defined for INTERSECT */
        break;
      case 97:
        YYTRACE("multiselect_op ::= EXCEPT")
#line 226 "parse.y"
{yygotominor.yy144 = TK_EXCEPT;}
#line 5400 "parse.c"
        /* No destructor defined for EXCEPT */
        break;
      case 98:
        YYTRACE("oneselect ::= SELECT distinct selcollist from where_opt groupby_opt having_opt orderby_opt limit_opt")
#line 228 "parse.y"
{
  yygotominor.yy233 = sqliteSelectNew(yymsp[-6].minor.yy270,yymsp[-5].minor.yy152,yymsp[-4].minor.yy132,yymsp[-3].minor.yy270,yymsp[-2].minor.yy132,yymsp[-1].minor.yy270,yymsp[-7].minor.yy144,yymsp[0].minor.yy303.a,yymsp[0].minor.yy303.b);
}
#line 5409 "parse.c"
        /* No destructor defined for SELECT */
        break;
      case 99:
        YYTRACE("distinct ::= DISTINCT")
#line 236 "parse.y"
{yygotominor.yy144 = 1;}
#line 5416 "parse.c"
        /* No destructor defined for DISTINCT */
        break;
      case 100:
        YYTRACE("distinct ::= ALL")
#line 237 "parse.y"
{yygotominor.yy144 = 0;}
#line 5423 "parse.c"
        /* No destructor defined for ALL */
        break;
      case 101:
        YYTRACE("distinct ::=")
#line 238 "parse.y"
{yygotominor.yy144 = 0;}
#line 5430 "parse.c"
        break;
      case 102:
        YYTRACE("sclp ::= selcollist COMMA")
#line 249 "parse.y"
{yygotominor.yy270 = yymsp[-1].minor.yy270;}
#line 5436 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 103:
        YYTRACE("sclp ::=")
#line 250 "parse.y"
{yygotominor.yy270 = 0;}
#line 5443 "parse.c"
        break;
      case 104:
        YYTRACE("selcollist ::= sclp expr")
#line 251 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(yymsp[-1].minor.yy270,yymsp[0].minor.yy132,0);}
#line 5449 "parse.c"
        break;
      case 105:
        YYTRACE("selcollist ::= sclp expr as ids")
#line 252 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(yymsp[-3].minor.yy270,yymsp[-2].minor.yy132,&yymsp[0].minor.yy224);}
#line 5455 "parse.c"
        /* No destructor defined for as */
        break;
      case 106:
        YYTRACE("selcollist ::= sclp STAR")
#line 253 "parse.y"
{
  yygotominor.yy270 = sqliteExprListAppend(yymsp[-1].minor.yy270, sqliteExpr(TK_ALL, 0, 0, 0), 0);
}
#line 5464 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 107:
        YYTRACE("as ::=")
        break;
      case 108:
        YYTRACE("as ::= AS")
        /* No destructor defined for AS */
        break;
      case 109:
        YYTRACE("from ::= FROM seltablist")
#line 267 "parse.y"
{yygotominor.yy152 = yymsp[0].minor.yy152;}
#line 5478 "parse.c"
        /* No destructor defined for FROM */
        break;
      case 110:
        YYTRACE("stl_prefix ::= seltablist COMMA")
#line 268 "parse.y"
{yygotominor.yy152 = yymsp[-1].minor.yy152;}
#line 5485 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 111:
        YYTRACE("stl_prefix ::=")
#line 269 "parse.y"
{yygotominor.yy152 = 0;}
#line 5492 "parse.c"
        break;
      case 112:
        YYTRACE("seltablist ::= stl_prefix ids")
#line 270 "parse.y"
{yygotominor.yy152 = sqliteIdListAppend(yymsp[-1].minor.yy152,&yymsp[0].minor.yy224);}
#line 5498 "parse.c"
        break;
      case 113:
        YYTRACE("seltablist ::= stl_prefix ids as ids")
#line 271 "parse.y"
{
  yygotominor.yy152 = sqliteIdListAppend(yymsp[-3].minor.yy152,&yymsp[-2].minor.yy224);
  sqliteIdListAddAlias(yygotominor.yy152,&yymsp[0].minor.yy224);
}
#line 5507 "parse.c"
        /* No destructor defined for as */
        break;
      case 114:
        YYTRACE("seltablist ::= stl_prefix LP select RP")
#line 275 "parse.y"
{
  yygotominor.yy152 = sqliteIdListAppend(yymsp[-3].minor.yy152,0);
  yygotominor.yy152->a[yygotominor.yy152->nId-1].pSelect = yymsp[-1].minor.yy233;
}
#line 5517 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 115:
        YYTRACE("seltablist ::= stl_prefix LP select RP as ids")
#line 279 "parse.y"
{
  yygotominor.yy152 = sqliteIdListAppend(yymsp[-5].minor.yy152,0);
  yygotominor.yy152->a[yygotominor.yy152->nId-1].pSelect = yymsp[-3].minor.yy233;
  sqliteIdListAddAlias(yygotominor.yy152,&yymsp[0].minor.yy224);
}
#line 5529 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        /* No destructor defined for as */
        break;
      case 116:
        YYTRACE("orderby_opt ::=")
#line 292 "parse.y"
{yygotominor.yy270 = 0;}
#line 5538 "parse.c"
        break;
      case 117:
        YYTRACE("orderby_opt ::= ORDER BY sortlist")
#line 293 "parse.y"
{yygotominor.yy270 = yymsp[0].minor.yy270;}
#line 5544 "parse.c"
        /* No destructor defined for ORDER */
        /* No destructor defined for BY */
        break;
      case 118:
        YYTRACE("sortlist ::= sortlist COMMA sortitem sortorder")
#line 294 "parse.y"
{
  yygotominor.yy270 = sqliteExprListAppend(yymsp[-3].minor.yy270,yymsp[-1].minor.yy132,0);
  if( yygotominor.yy270 ) yygotominor.yy270->a[yygotominor.yy270->nExpr-1].sortOrder = yymsp[0].minor.yy144;  /* 0=ascending, 1=decending */
}
#line 5555 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 119:
        YYTRACE("sortlist ::= sortitem sortorder")
#line 298 "parse.y"
{
  yygotominor.yy270 = sqliteExprListAppend(0,yymsp[-1].minor.yy132,0);
  if( yygotominor.yy270 ) yygotominor.yy270->a[0].sortOrder = yymsp[0].minor.yy144;
}
#line 5565 "parse.c"
        break;
      case 120:
        YYTRACE("sortitem ::= expr")
#line 302 "parse.y"
{yygotominor.yy132 = yymsp[0].minor.yy132;}
#line 5571 "parse.c"
        break;
      case 121:
        YYTRACE("sortorder ::= ASC")
#line 306 "parse.y"
{yygotominor.yy144 = 0;}
#line 5577 "parse.c"
        /* No destructor defined for ASC */
        break;
      case 122:
        YYTRACE("sortorder ::= DESC")
#line 307 "parse.y"
{yygotominor.yy144 = 1;}
#line 5584 "parse.c"
        /* No destructor defined for DESC */
        break;
      case 123:
        YYTRACE("sortorder ::=")
#line 308 "parse.y"
{yygotominor.yy144 = 0;}
#line 5591 "parse.c"
        break;
      case 124:
        YYTRACE("groupby_opt ::=")
#line 312 "parse.y"
{yygotominor.yy270 = 0;}
#line 5597 "parse.c"
        break;
      case 125:
        YYTRACE("groupby_opt ::= GROUP BY exprlist")
#line 313 "parse.y"
{yygotominor.yy270 = yymsp[0].minor.yy270;}
#line 5603 "parse.c"
        /* No destructor defined for GROUP */
        /* No destructor defined for BY */
        break;
      case 126:
        YYTRACE("having_opt ::=")
#line 317 "parse.y"
{yygotominor.yy132 = 0;}
#line 5611 "parse.c"
        break;
      case 127:
        YYTRACE("having_opt ::= HAVING expr")
#line 318 "parse.y"
{yygotominor.yy132 = yymsp[0].minor.yy132;}
#line 5617 "parse.c"
        /* No destructor defined for HAVING */
        break;
      case 128:
        YYTRACE("limit_opt ::=")
#line 321 "parse.y"
{yygotominor.yy303.a = -1; yygotominor.yy303.b = 0;}
#line 5624 "parse.c"
        break;
      case 129:
        YYTRACE("limit_opt ::= LIMIT INTEGER")
#line 322 "parse.y"
{yygotominor.yy303.a = atoi(yymsp[0].minor.yy0.z); yygotominor.yy303.b = 0;}
#line 5630 "parse.c"
        /* No destructor defined for LIMIT */
        break;
      case 130:
        YYTRACE("limit_opt ::= LIMIT INTEGER limit_sep INTEGER")
#line 324 "parse.y"
{yygotominor.yy303.a = atoi(yymsp[-2].minor.yy0.z); yygotominor.yy303.b = atoi(yymsp[0].minor.yy0.z);}
#line 5637 "parse.c"
        /* No destructor defined for LIMIT */
        /* No destructor defined for limit_sep */
        break;
      case 131:
        YYTRACE("limit_sep ::= OFFSET")
        /* No destructor defined for OFFSET */
        break;
      case 132:
        YYTRACE("limit_sep ::= COMMA")
        /* No destructor defined for COMMA */
        break;
      case 133:
        YYTRACE("cmd ::= DELETE FROM ids where_opt")
#line 331 "parse.y"
{sqliteDeleteFrom(pParse, &yymsp[-1].minor.yy224, yymsp[0].minor.yy132);}
#line 5653 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 134:
        YYTRACE("where_opt ::=")
#line 336 "parse.y"
{yygotominor.yy132 = 0;}
#line 5661 "parse.c"
        break;
      case 135:
        YYTRACE("where_opt ::= WHERE expr")
#line 337 "parse.y"
{yygotominor.yy132 = yymsp[0].minor.yy132;}
#line 5667 "parse.c"
        /* No destructor defined for WHERE */
        break;
      case 136:
        YYTRACE("cmd ::= UPDATE orconf ids SET setlist where_opt")
#line 345 "parse.y"
{sqliteUpdate(pParse,&yymsp[-3].minor.yy224,yymsp[-1].minor.yy270,yymsp[0].minor.yy132,yymsp[-4].minor.yy144);}
#line 5674 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 137:
        YYTRACE("setlist ::= setlist COMMA ids EQ expr")
#line 348 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(yymsp[-4].minor.yy270,yymsp[0].minor.yy132,&yymsp[-2].minor.yy224);}
#line 5682 "parse.c"
        /* No destructor defined for COMMA */
        /* No destructor defined for EQ */
        break;
      case 138:
        YYTRACE("setlist ::= ids EQ expr")
#line 349 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(0,yymsp[0].minor.yy132,&yymsp[-2].minor.yy224);}
#line 5690 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 139:
        YYTRACE("cmd ::= insert_cmd INTO ids inscollist_opt VALUES LP itemlist RP")
#line 354 "parse.y"
{sqliteInsert(pParse, &yymsp[-5].minor.yy224, yymsp[-1].minor.yy270, 0, yymsp[-4].minor.yy152, yymsp[-7].minor.yy144);}
#line 5697 "parse.c"
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 140:
        YYTRACE("cmd ::= insert_cmd INTO ids inscollist_opt select")
#line 356 "parse.y"
{sqliteInsert(pParse, &yymsp[-2].minor.yy224, 0, yymsp[0].minor.yy233, yymsp[-1].minor.yy152, yymsp[-4].minor.yy144);}
#line 5707 "parse.c"
        /* No destructor defined for INTO */
        break;
      case 141:
        YYTRACE("insert_cmd ::= INSERT orconf")
#line 359 "parse.y"
{yygotominor.yy144 = yymsp[0].minor.yy144;}
#line 5714 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 142:
        YYTRACE("insert_cmd ::= REPLACE")
#line 360 "parse.y"
{yygotominor.yy144 = OE_Replace;}
#line 5721 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 143:
        YYTRACE("itemlist ::= itemlist COMMA expr")
#line 366 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(yymsp[-2].minor.yy270,yymsp[0].minor.yy132,0);}
#line 5728 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 144:
        YYTRACE("itemlist ::= expr")
#line 367 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(0,yymsp[0].minor.yy132,0);}
#line 5735 "parse.c"
        break;
      case 145:
        YYTRACE("inscollist_opt ::=")
#line 374 "parse.y"
{yygotominor.yy152 = 0;}
#line 5741 "parse.c"
        break;
      case 146:
        YYTRACE("inscollist_opt ::= LP inscollist RP")
#line 375 "parse.y"
{yygotominor.yy152 = yymsp[-1].minor.yy152;}
#line 5747 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 147:
        YYTRACE("inscollist ::= inscollist COMMA ids")
#line 376 "parse.y"
{yygotominor.yy152 = sqliteIdListAppend(yymsp[-2].minor.yy152,&yymsp[0].minor.yy224);}
#line 5755 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 148:
        YYTRACE("inscollist ::= ids")
#line 377 "parse.y"
{yygotominor.yy152 = sqliteIdListAppend(0,&yymsp[0].minor.yy224);}
#line 5762 "parse.c"
        break;
      case 149:
        YYTRACE("expr ::= LP expr RP")
#line 395 "parse.y"
{yygotominor.yy132 = yymsp[-1].minor.yy132; sqliteExprSpan(yygotominor.yy132,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);}
#line 5768 "parse.c"
        break;
      case 150:
        YYTRACE("expr ::= NULL")
#line 396 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_NULL, 0, 0, &yymsp[0].minor.yy0);}
#line 5774 "parse.c"
        break;
      case 151:
        YYTRACE("expr ::= id")
#line 397 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy224);}
#line 5780 "parse.c"
        break;
      case 152:
        YYTRACE("expr ::= ids DOT ids")
#line 398 "parse.y"
{
  Expr *temp1 = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy224);
  Expr *temp2 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy224);
  yygotominor.yy132 = sqliteExpr(TK_DOT, temp1, temp2, 0);
}
#line 5790 "parse.c"
        /* No destructor defined for DOT */
        break;
      case 153:
        YYTRACE("expr ::= INTEGER")
#line 403 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_INTEGER, 0, 0, &yymsp[0].minor.yy0);}
#line 5797 "parse.c"
        break;
      case 154:
        YYTRACE("expr ::= FLOAT")
#line 404 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_FLOAT, 0, 0, &yymsp[0].minor.yy0);}
#line 5803 "parse.c"
        break;
      case 155:
        YYTRACE("expr ::= STRING")
#line 405 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_STRING, 0, 0, &yymsp[0].minor.yy0);}
#line 5809 "parse.c"
        break;
      case 156:
        YYTRACE("expr ::= ID LP exprlist RP")
#line 406 "parse.y"
{
  yygotominor.yy132 = sqliteExprFunction(yymsp[-1].minor.yy270, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 5818 "parse.c"
        /* No destructor defined for LP */
        break;
      case 157:
        YYTRACE("expr ::= ID LP STAR RP")
#line 410 "parse.y"
{
  yygotominor.yy132 = sqliteExprFunction(0, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 5828 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for STAR */
        break;
      case 158:
        YYTRACE("expr ::= expr AND expr")
#line 414 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_AND, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5836 "parse.c"
        /* No destructor defined for AND */
        break;
      case 159:
        YYTRACE("expr ::= expr OR expr")
#line 415 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_OR, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5843 "parse.c"
        /* No destructor defined for OR */
        break;
      case 160:
        YYTRACE("expr ::= expr LT expr")
#line 416 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_LT, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5850 "parse.c"
        /* No destructor defined for LT */
        break;
      case 161:
        YYTRACE("expr ::= expr GT expr")
#line 417 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_GT, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5857 "parse.c"
        /* No destructor defined for GT */
        break;
      case 162:
        YYTRACE("expr ::= expr LE expr")
#line 418 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_LE, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5864 "parse.c"
        /* No destructor defined for LE */
        break;
      case 163:
        YYTRACE("expr ::= expr GE expr")
#line 419 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_GE, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5871 "parse.c"
        /* No destructor defined for GE */
        break;
      case 164:
        YYTRACE("expr ::= expr NE expr")
#line 420 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_NE, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5878 "parse.c"
        /* No destructor defined for NE */
        break;
      case 165:
        YYTRACE("expr ::= expr EQ expr")
#line 421 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_EQ, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5885 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 166:
        YYTRACE("expr ::= expr BITAND expr")
#line 422 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_BITAND, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5892 "parse.c"
        /* No destructor defined for BITAND */
        break;
      case 167:
        YYTRACE("expr ::= expr BITOR expr")
#line 423 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_BITOR, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5899 "parse.c"
        /* No destructor defined for BITOR */
        break;
      case 168:
        YYTRACE("expr ::= expr LSHIFT expr")
#line 424 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_LSHIFT, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5906 "parse.c"
        /* No destructor defined for LSHIFT */
        break;
      case 169:
        YYTRACE("expr ::= expr RSHIFT expr")
#line 425 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_RSHIFT, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5913 "parse.c"
        /* No destructor defined for RSHIFT */
        break;
      case 170:
        YYTRACE("expr ::= expr LIKE expr")
#line 426 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_LIKE, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5920 "parse.c"
        /* No destructor defined for LIKE */
        break;
      case 171:
        YYTRACE("expr ::= expr NOT LIKE expr")
#line 427 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_LIKE, yymsp[-3].minor.yy132, yymsp[0].minor.yy132, 0);
  yygotominor.yy132 = sqliteExpr(TK_NOT, yygotominor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-3].minor.yy132->span,&yymsp[0].minor.yy132->span);
}
#line 5931 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for LIKE */
        break;
      case 172:
        YYTRACE("expr ::= expr GLOB expr")
#line 432 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_GLOB,yymsp[-2].minor.yy132,yymsp[0].minor.yy132,0);}
#line 5939 "parse.c"
        /* No destructor defined for GLOB */
        break;
      case 173:
        YYTRACE("expr ::= expr NOT GLOB expr")
#line 433 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_GLOB, yymsp[-3].minor.yy132, yymsp[0].minor.yy132, 0);
  yygotominor.yy132 = sqliteExpr(TK_NOT, yygotominor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-3].minor.yy132->span,&yymsp[0].minor.yy132->span);
}
#line 5950 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for GLOB */
        break;
      case 174:
        YYTRACE("expr ::= expr PLUS expr")
#line 438 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_PLUS, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5958 "parse.c"
        /* No destructor defined for PLUS */
        break;
      case 175:
        YYTRACE("expr ::= expr MINUS expr")
#line 439 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_MINUS, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5965 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 176:
        YYTRACE("expr ::= expr STAR expr")
#line 440 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_STAR, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5972 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 177:
        YYTRACE("expr ::= expr SLASH expr")
#line 441 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_SLASH, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5979 "parse.c"
        /* No destructor defined for SLASH */
        break;
      case 178:
        YYTRACE("expr ::= expr REM expr")
#line 442 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_REM, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5986 "parse.c"
        /* No destructor defined for REM */
        break;
      case 179:
        YYTRACE("expr ::= expr CONCAT expr")
#line 443 "parse.y"
{yygotominor.yy132 = sqliteExpr(TK_CONCAT, yymsp[-2].minor.yy132, yymsp[0].minor.yy132, 0);}
#line 5993 "parse.c"
        /* No destructor defined for CONCAT */
        break;
      case 180:
        YYTRACE("expr ::= expr ISNULL")
#line 444 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_ISNULL, yymsp[-1].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-1].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 6003 "parse.c"
        break;
      case 181:
        YYTRACE("expr ::= expr IS NULL")
#line 448 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_ISNULL, yymsp[-2].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-2].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 6012 "parse.c"
        /* No destructor defined for IS */
        break;
      case 182:
        YYTRACE("expr ::= expr NOTNULL")
#line 452 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_NOTNULL, yymsp[-1].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-1].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 6022 "parse.c"
        break;
      case 183:
        YYTRACE("expr ::= expr NOT NULL")
#line 456 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_NOTNULL, yymsp[-2].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-2].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 6031 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 184:
        YYTRACE("expr ::= expr IS NOT NULL")
#line 460 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_NOTNULL, yymsp[-3].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-3].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 6041 "parse.c"
        /* No destructor defined for IS */
        /* No destructor defined for NOT */
        break;
      case 185:
        YYTRACE("expr ::= NOT expr")
#line 464 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_NOT, yymsp[0].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy132->span);
}
#line 6052 "parse.c"
        break;
      case 186:
        YYTRACE("expr ::= BITNOT expr")
#line 468 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_BITNOT, yymsp[0].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy132->span);
}
#line 6061 "parse.c"
        break;
      case 187:
        YYTRACE("expr ::= MINUS expr")
#line 472 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_UMINUS, yymsp[0].minor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy132->span);
}
#line 6070 "parse.c"
        break;
      case 188:
        YYTRACE("expr ::= PLUS expr")
#line 476 "parse.y"
{
  yygotominor.yy132 = yymsp[0].minor.yy132;
  sqliteExprSpan(yygotominor.yy132,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy132->span);
}
#line 6079 "parse.c"
        break;
      case 189:
        YYTRACE("expr ::= LP select RP")
#line 480 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_SELECT, 0, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pSelect = yymsp[-1].minor.yy233;
  sqliteExprSpan(yygotominor.yy132,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);
}
#line 6089 "parse.c"
        break;
      case 190:
        YYTRACE("expr ::= expr BETWEEN expr AND expr")
#line 485 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy132, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy132, 0);
  yygotominor.yy132 = sqliteExpr(TK_BETWEEN, yymsp[-4].minor.yy132, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pList = pList;
  sqliteExprSpan(yygotominor.yy132,&yymsp[-4].minor.yy132->span,&yymsp[0].minor.yy132->span);
}
#line 6101 "parse.c"
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 191:
        YYTRACE("expr ::= expr NOT BETWEEN expr AND expr")
#line 492 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy132, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy132, 0);
  yygotominor.yy132 = sqliteExpr(TK_BETWEEN, yymsp[-5].minor.yy132, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pList = pList;
  yygotominor.yy132 = sqliteExpr(TK_NOT, yygotominor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-5].minor.yy132->span,&yymsp[0].minor.yy132->span);
}
#line 6116 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 192:
        YYTRACE("expr ::= expr IN LP exprlist RP")
#line 500 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_IN, yymsp[-4].minor.yy132, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pList = yymsp[-1].minor.yy270;
  sqliteExprSpan(yygotominor.yy132,&yymsp[-4].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 6129 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 193:
        YYTRACE("expr ::= expr IN LP select RP")
#line 505 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_IN, yymsp[-4].minor.yy132, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pSelect = yymsp[-1].minor.yy233;
  sqliteExprSpan(yygotominor.yy132,&yymsp[-4].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 6141 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 194:
        YYTRACE("expr ::= expr NOT IN LP exprlist RP")
#line 510 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_IN, yymsp[-5].minor.yy132, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pList = yymsp[-1].minor.yy270;
  yygotominor.yy132 = sqliteExpr(TK_NOT, yygotominor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-5].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 6154 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 195:
        YYTRACE("expr ::= expr NOT IN LP select RP")
#line 516 "parse.y"
{
  yygotominor.yy132 = sqliteExpr(TK_IN, yymsp[-5].minor.yy132, 0, 0);
  if( yygotominor.yy132 ) yygotominor.yy132->pSelect = yymsp[-1].minor.yy233;
  yygotominor.yy132 = sqliteExpr(TK_NOT, yygotominor.yy132, 0, 0);
  sqliteExprSpan(yygotominor.yy132,&yymsp[-5].minor.yy132->span,&yymsp[0].minor.yy0);
}
#line 6168 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 196:
        YYTRACE("exprlist ::= exprlist COMMA expritem")
#line 531 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(yymsp[-2].minor.yy270,yymsp[0].minor.yy132,0);}
#line 6177 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 197:
        YYTRACE("exprlist ::= expritem")
#line 532 "parse.y"
{yygotominor.yy270 = sqliteExprListAppend(0,yymsp[0].minor.yy132,0);}
#line 6184 "parse.c"
        break;
      case 198:
        YYTRACE("expritem ::= expr")
#line 533 "parse.y"
{yygotominor.yy132 = yymsp[0].minor.yy132;}
#line 6190 "parse.c"
        break;
      case 199:
        YYTRACE("expritem ::=")
#line 534 "parse.y"
{yygotominor.yy132 = 0;}
#line 6196 "parse.c"
        break;
      case 200:
        YYTRACE("cmd ::= CREATE uniqueflag INDEX ids ON ids LP idxlist RP onconf")
#line 539 "parse.y"
{
  if( yymsp[-8].minor.yy144!=OE_None ) yymsp[-8].minor.yy144 = yymsp[0].minor.yy144;
  if( yymsp[-8].minor.yy144==OE_Default) yymsp[-8].minor.yy144 = OE_Abort;
  sqliteCreateIndex(pParse, &yymsp[-6].minor.yy224, &yymsp[-4].minor.yy224, yymsp[-2].minor.yy152, yymsp[-8].minor.yy144, &yymsp[-9].minor.yy0, &yymsp[-1].minor.yy0);
}
#line 6206 "parse.c"
        /* No destructor defined for INDEX */
        /* No destructor defined for ON */
        /* No destructor defined for LP */
        break;
      case 201:
        YYTRACE("uniqueflag ::= UNIQUE")
#line 546 "parse.y"
{ yygotominor.yy144 = OE_Abort; }
#line 6215 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 202:
        YYTRACE("uniqueflag ::=")
#line 547 "parse.y"
{ yygotominor.yy144 = OE_None; }
#line 6222 "parse.c"
        break;
      case 203:
        YYTRACE("idxlist ::= idxlist COMMA idxitem")
#line 554 "parse.y"
{yygotominor.yy152 = sqliteIdListAppend(yymsp[-2].minor.yy152,&yymsp[0].minor.yy224);}
#line 6228 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 204:
        YYTRACE("idxlist ::= idxitem")
#line 556 "parse.y"
{yygotominor.yy152 = sqliteIdListAppend(0,&yymsp[0].minor.yy224);}
#line 6235 "parse.c"
        break;
      case 205:
        YYTRACE("idxitem ::= ids")
#line 557 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy224;}
#line 6241 "parse.c"
        break;
      case 206:
        YYTRACE("cmd ::= DROP INDEX ids")
#line 562 "parse.y"
{sqliteDropIndex(pParse, &yymsp[0].minor.yy224);}
#line 6247 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for INDEX */
        break;
      case 207:
        YYTRACE("cmd ::= COPY orconf ids FROM ids USING DELIMITERS STRING")
#line 568 "parse.y"
{sqliteCopy(pParse,&yymsp[-5].minor.yy224,&yymsp[-3].minor.yy224,&yymsp[0].minor.yy0,yymsp[-6].minor.yy144);}
#line 6255 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        /* No destructor defined for USING */
        /* No destructor defined for DELIMITERS */
        break;
      case 208:
        YYTRACE("cmd ::= COPY orconf ids FROM ids")
#line 570 "parse.y"
{sqliteCopy(pParse,&yymsp[-2].minor.yy224,&yymsp[0].minor.yy224,0,yymsp[-3].minor.yy144);}
#line 6265 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        break;
      case 209:
        YYTRACE("cmd ::= VACUUM")
#line 574 "parse.y"
{sqliteVacuum(pParse,0);}
#line 6273 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 210:
        YYTRACE("cmd ::= VACUUM ids")
#line 575 "parse.y"
{sqliteVacuum(pParse,&yymsp[0].minor.yy224);}
#line 6280 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 211:
        YYTRACE("cmd ::= PRAGMA ids EQ ids")
#line 579 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy224,&yymsp[0].minor.yy224,0);}
#line 6287 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 212:
        YYTRACE("cmd ::= PRAGMA ids EQ ON")
#line 580 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy224,&yymsp[0].minor.yy0,0);}
#line 6295 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 213:
        YYTRACE("cmd ::= PRAGMA ids EQ plus_num")
#line 581 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy224,&yymsp[0].minor.yy224,0);}
#line 6303 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 214:
        YYTRACE("cmd ::= PRAGMA ids EQ minus_num")
#line 582 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy224,&yymsp[0].minor.yy224,1);}
#line 6311 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 215:
        YYTRACE("cmd ::= PRAGMA ids LP ids RP")
#line 583 "parse.y"
{sqlitePragma(pParse,&yymsp[-3].minor.yy224,&yymsp[-1].minor.yy224,0);}
#line 6319 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 216:
        YYTRACE("cmd ::= PRAGMA ids")
#line 584 "parse.y"
{sqlitePragma(pParse,&yymsp[0].minor.yy224,&yymsp[0].minor.yy224,0);}
#line 6328 "parse.c"
        /* No destructor defined for PRAGMA */
        break;
      case 217:
        YYTRACE("plus_num ::= plus_opt number")
#line 585 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy224;}
#line 6335 "parse.c"
        /* No destructor defined for plus_opt */
        break;
      case 218:
        YYTRACE("minus_num ::= MINUS number")
#line 586 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy224;}
#line 6342 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 219:
        YYTRACE("number ::= INTEGER")
#line 587 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6349 "parse.c"
        break;
      case 220:
        YYTRACE("number ::= FLOAT")
#line 588 "parse.y"
{yygotominor.yy224 = yymsp[0].minor.yy0;}
#line 6355 "parse.c"
        break;
      case 221:
        YYTRACE("plus_opt ::= PLUS")
        /* No destructor defined for PLUS */
        break;
      case 222:
        YYTRACE("plus_opt ::=")
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yypParser->yytop -= yysize;
  yyact = yy_find_parser_action(yypParser,yygoto);
  if( yyact < YYNSTATE ){
    yy_shift(yypParser,yyact,yygoto,&yygotominor);
  }else if( yyact == YYNSTATE + YYNRULE + 1 ){
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  sqliteParserARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  sqliteParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  sqliteParserARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 23 "parse.y"

  sqliteSetString(&pParse->zErrMsg,"syntax error",0);
  pParse->sErrToken = TOKEN;

#line 6410 "parse.c"
  sqliteParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  sqliteParserARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  sqliteParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
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
  sqliteParserARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
    if( yymajor==0 ) return;
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yytop = &yypParser->yystack[0];
    yypParser->yytop->stateno = 0;
    yypParser->yytop->major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  sqliteParserARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_parser_action(yypParser,yymajor);
    if( yyact<YYNSTATE ){
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      if( yyendofinput && yypParser->yyidx>=0 ){
        yymajor = 0;
      }else{
        yymajor = YYNOCODE;
      }
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
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
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      if( yypParser->yytop->major==YYERRORSYMBOL || yyerrorhit ){
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
          yypParser->yyidx >= 0 &&
          yypParser->yytop->major != YYERRORSYMBOL &&
          (yyact = yy_find_parser_action(yypParser,YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yypParser->yytop->major!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
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
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }else{
      yy_accept(yypParser);
      yymajor = YYNOCODE;
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}
