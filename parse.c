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
#define YYNOCODE 169
#define YYACTIONTYPE unsigned short int
#define sqliteParserTOKENTYPE Token
typedef union {
  sqliteParserTOKENTYPE yy0;
  IdList* yy82;
  ExprList* yy144;
  Expr* yy146;
  int yy172;
  struct twoint yy191;
  Token yy210;
  Select* yy219;
  int yy337;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define sqliteParserARG_SDECL Parse *pParse;
#define sqliteParserARG_PDECL ,Parse *pParse
#define sqliteParserARG_FETCH Parse *pParse = yypParser->pParse
#define sqliteParserARG_STORE yypParser->pParse = pParse
#define YYNSTATE 411
#define YYNRULE 232
#define YYERRORSYMBOL 122
#define YYERRSYMDT yy337
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
  {  75,   0, 389}, /*  1:                 PRAGMA shift  389 */
  {  26,   0, 339}, /*  2:                 DELETE shift  339 */
  {  52,   0, 376}, /*  3:                 INSERT shift  376 */
  { 153,   6, 338}, /*  4:                 select shift  338 */
  {  79,   0,  45}, /*  5:               ROLLBACK shift  45 */
  {  78,   0, 378}, /*  6:                REPLACE shift  378 */
  {  31,   0, 331}, /*  7:                   DROP shift  331 */
  {  82,  11,  84}, /*  8:                 SELECT shift  84 */
  {  83,  14, 408}, /*  9:                   SEMI shift  408 */
  { 134,   0, 644}, /* 10:                  input accept */
  {   7,   0,   6}, /* 11:                  BEGIN shift  6 */
  { 111,   0, 406}, /* 12:                    cmd shift  406 */
  { 137,  15, 358}, /* 13:             insert_cmd shift  358 */
  {  33,   0,  43}, /* 14:                    END shift  43 */
  { 112,  16,   1}, /* 15:                cmdlist shift  1 */
  {  37,   0, 409}, /* 16:                EXPLAIN shift  409 */
  {  23,   0, 379}, /* 17:                   COPY shift  379 */
  {  24,   0, 312}, /* 18:                 CREATE shift  312 */
  { 118,   0,  47}, /* 19:           create_table shift  47 */
  {  19,   0,  41}, /* 20:                 COMMIT shift  41 */
  { 145,   0,  80}, /* 21:              oneselect shift  80 */
  { 121,   0, 410}, /* 22:                   ecmd shift  410 */
  {  97,   0, 343}, /* 23:                 UPDATE shift  343 */
  { 123,  17,   3}, /* 24:                explain shift  3 */
  {  99,  18, 387}, /* 25:                 VACUUM shift  387 */
/* State 1 */
  {  24,   6, 312}, /*  1:                 CREATE shift  312 */
  { 145,   9,  80}, /*  2:              oneselect shift  80 */
  {  26,   0, 339}, /*  3:                 DELETE shift  339 */
  { 123,  13,   3}, /*  4:                explain shift  3 */
  {  52,   0, 376}, /*  5:                 INSERT shift  376 */
  {   0,   0, 411}, /*  6:                      $ reduce 0 */
  {  78,   0, 378}, /*  7:                REPLACE shift  378 */
  {  79,  15,  45}, /*  8:               ROLLBACK shift  45 */
  { 121,  17,   2}, /*  9:                   ecmd shift  2 */
  { 153,  19, 338}, /* 10:                 select shift  338 */
  {  82,   0,  84}, /* 11:                 SELECT shift  84 */
  {  83,   0, 408}, /* 12:                   SEMI shift  408 */
  {  99,  21, 387}, /* 13:                 VACUUM shift  387 */
  {  37,   0, 409}, /* 14:                EXPLAIN shift  409 */
  {  31,  22, 331}, /* 15:                   DROP shift  331 */
  { 111,   0, 406}, /* 16:                    cmd shift  406 */
  {  97,   0, 343}, /* 17:                 UPDATE shift  343 */
  { 137,   0, 358}, /* 18:             insert_cmd shift  358 */
  {  33,   0,  43}, /* 19:                    END shift  43 */
  {  19,   0,  41}, /* 20:                 COMMIT shift  41 */
  {  75,   0, 389}, /* 21:                 PRAGMA shift  389 */
  {   7,   0,   6}, /* 22:                  BEGIN shift  6 */
  { 118,   0,  47}, /* 23:           create_table shift  47 */
  {  23,   0, 379}, /* 24:                   COPY shift  379 */
/* State 3 */
  {  19,   0,  41}, /*  1:                 COMMIT shift  41 */
  { 153,   0, 338}, /*  2:                 select shift  338 */
  {  97,   9, 343}, /*  3:                 UPDATE shift  343 */
  {  79,   0,  45}, /*  4:               ROLLBACK shift  45 */
  { 137,  10, 358}, /*  5:             insert_cmd shift  358 */
  {  24,   0, 312}, /*  6:                 CREATE shift  312 */
  {  82,   0,  84}, /*  7:                 SELECT shift  84 */
  {  26,  11, 339}, /*  8:                 DELETE shift  339 */
  {  78,   0, 378}, /*  9:                REPLACE shift  378 */
  { 118,  12,  47}, /* 10:           create_table shift  47 */
  {   7,   0,   6}, /* 11:                  BEGIN shift  6 */
  {  99,  14, 387}, /* 12:                 VACUUM shift  387 */
  { 145,  16,  80}, /* 13:              oneselect shift  80 */
  {  23,   0, 379}, /* 14:                   COPY shift  379 */
  {  52,  18, 376}, /* 15:                 INSERT shift  376 */
  {  31,   0, 331}, /* 16:                   DROP shift  331 */
  { 111,   0,   4}, /* 17:                    cmd shift  4 */
  {  33,   0,  43}, /* 18:                    END shift  43 */
  {  75,   0, 389}, /* 19:                 PRAGMA shift  389 */
/* State 4 */
  {  83,   0,   5}, /*  1:                   SEMI shift  5 */
/* State 6 */
  {  92,   0,  17}, /*  1:            TRANSACTION shift  17 */
  { 163,   0,   7}, /*  2:              trans_opt shift  7 */
/* State 7 */
  { 144,   0,   8}, /*  1:                 onconf shift  8 */
  {  71,   0,   9}, /*  2:                     ON shift  9 */
  {  83,   2, 492}, /*  3:                   SEMI reduce 81 */
/* State 8 */
  {  83,   0, 418}, /*  1:                   SEMI reduce 7 */
/* State 9 */
  {  21,   0,  10}, /*  1:               CONFLICT shift  10 */
/* State 10 */
  { 150,   4,  11}, /*  1:            resolvetype shift  11 */
  {  79,   5,  12}, /*  2:               ROLLBACK shift  12 */
  {  38,   0,  14}, /*  3:                   FAIL shift  14 */
  {  78,   6,  16}, /*  4:                REPLACE shift  16 */
  {   1,   0,  13}, /*  5:                  ABORT shift  13 */
  {  48,   0,  15}, /*  6:                 IGNORE shift  15 */
/* State 17 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0,  18}, /* 17:                    ids shift  18 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 41 */
  {  83,   0, 419}, /*  1:                   SEMI reduce 8 */
  { 163,   0,  42}, /*  2:              trans_opt shift  42 */
  {  92,   1,  17}, /*  3:            TRANSACTION shift  17 */
/* State 42 */
  {  83,   0, 422}, /*  1:                   SEMI reduce 11 */
/* State 43 */
  {  83,   0, 419}, /*  1:                   SEMI reduce 8 */
  { 163,   0,  44}, /*  2:              trans_opt shift  44 */
  {  92,   1,  17}, /*  3:            TRANSACTION shift  17 */
/* State 44 */
  {  83,   0, 423}, /*  1:                   SEMI reduce 12 */
/* State 45 */
  {  83,   0, 419}, /*  1:                   SEMI reduce 8 */
  { 163,   0,  46}, /*  2:              trans_opt shift  46 */
  {  92,   1,  17}, /*  3:            TRANSACTION shift  17 */
/* State 46 */
  {  83,   0, 424}, /*  1:                   SEMI reduce 13 */
/* State 47 */
  {  62,   2,  49}, /*  1:                     LP shift  49 */
  {   5,   0, 310}, /*  2:                     AS shift  310 */
  { 119,   1,  48}, /*  3:      create_table_args shift  48 */
/* State 48 */
  {  83,   0, 425}, /*  1:                   SEMI reduce 14 */
/* State 49 */
  { 130,   4,  39}, /*  1:                     id shift  39 */
  { 131,   5, 283}, /*  2:                    ids shift  283 */
  {  28,   0,  26}, /*  3:                   DESC shift  26 */
  {  78,   0,  35}, /*  4:                REPLACE shift  35 */
  {  27,   6,  25}, /*  5:             DELIMITERS shift  25 */
  {   1,   0,  19}, /*  6:                  ABORT shift  19 */
  {  58,   9,  32}, /*  7:                    KEY shift  32 */
  {  33,  14,  27}, /*  8:                    END shift  27 */
  {   6,   0,  20}, /*  9:                    ASC shift  20 */
  { 113,   0, 309}, /* 10:                 column shift  309 */
  { 114,  15,  55}, /* 11:               columnid shift  55 */
  { 115,  17,  50}, /* 12:             columnlist shift  50 */
  {  90,  18,  36}, /* 13:                   TEMP shift  36 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  88,   0,  40}, /* 15:                 STRING shift  40 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  {  37,   0,  28}, /* 17:                EXPLAIN shift  28 */
  {  38,   0,  29}, /* 18:                   FAIL shift  29 */
  {  70,   0,  33}, /* 19:                 OFFSET shift  33 */
  {  47,  21,  30}, /* 20:                     ID shift  30 */
  {  21,   0,  23}, /* 21:               CONFLICT shift  23 */
  {  99,  20,  37}, /* 22:                 VACUUM shift  37 */
  {  48,   0,  31}, /* 23:                 IGNORE shift  31 */
  { 101,  25,  38}, /* 24:                   VIEW shift  38 */
  {  75,  26,  34}, /* 25:                 PRAGMA shift  34 */
  {  23,   0,  24}, /* 26:                   COPY shift  24 */
/* State 50 */
  { 117,   0,  51}, /*  1:           conslist_opt shift  51 */
  {  17,   0,  53}, /*  2:                  COMMA shift  53 */
  {  80,   2, 483}, /*  3:                     RP reduce 72 */
/* State 51 */
  {  80,   0,  52}, /*  1:                     RP shift  52 */
/* State 52 */
  {  83,   0, 429}, /*  1:                   SEMI reduce 18 */
/* State 53 */
  { 130,   5,  39}, /*  1:                     id shift  39 */
  {   1,   0,  19}, /*  2:                  ABORT shift  19 */
  {  33,   0,  27}, /*  3:                    END shift  27 */
  {  96,   0, 299}, /*  4:                 UNIQUE shift  299 */
  {  99,   6,  37}, /*  5:                 VACUUM shift  37 */
  {  37,  10,  28}, /*  6:                EXPLAIN shift  28 */
  { 161,   1, 308}, /*  7:                  tcons shift  308 */
  { 131,  11, 283}, /*  8:                    ids shift  283 */
  { 101,  12,  38}, /*  9:                   VIEW shift  38 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  38,  13,  29}, /* 11:                   FAIL shift  29 */
  {  70,   0,  33}, /* 12:                 OFFSET shift  33 */
  {   7,   0,  21}, /* 13:                  BEGIN shift  21 */
  {  75,   0,  34}, /* 14:                 PRAGMA shift  34 */
  {  76,  19, 289}, /* 15:                PRIMARY shift  289 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  {  78,  20,  35}, /* 17:                REPLACE shift  35 */
  {  48,   0,  31}, /* 18:                 IGNORE shift  31 */
  {  14,   0, 304}, /* 19:                  CHECK shift  304 */
  {  47,   0,  30}, /* 20:                     ID shift  30 */
  { 113,   0,  54}, /* 21:                 column shift  54 */
  { 114,  25,  55}, /* 22:               columnid shift  55 */
  {  22,   0, 287}, /* 23:             CONSTRAINT shift  287 */
  { 116,  26, 284}, /* 24:               conslist shift  284 */
  {  21,   0,  23}, /* 25:               CONFLICT shift  23 */
  {  23,   0,  24}, /* 26:                   COPY shift  24 */
  {  88,   0,  40}, /* 27:                 STRING shift  40 */
  {  58,  30,  32}, /* 28:                    KEY shift  32 */
  {  90,  31,  36}, /* 29:                   TEMP shift  36 */
  {  27,   0,  25}, /* 30:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 31:                   DESC shift  26 */
/* State 55 */
  {  75,   0,  34}, /*  1:                 PRAGMA shift  34 */
  { 101,   5,  38}, /*  2:                   VIEW shift  38 */
  {  27,   0,  25}, /*  3:             DELIMITERS shift  25 */
  {  78,  10,  35}, /*  4:                REPLACE shift  35 */
  {   1,   0,  19}, /*  5:                  ABORT shift  19 */
  { 130,   0,  39}, /*  6:                     id shift  39 */
  { 131,  11, 282}, /*  7:                    ids shift  282 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  58,  12,  32}, /*  9:                    KEY shift  32 */
  {  28,   0,  26}, /* 10:                   DESC shift  26 */
  {   6,   0,  20}, /* 11:                    ASC shift  20 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  37,   0,  28}, /* 13:                EXPLAIN shift  28 */
  {  88,  17,  40}, /* 14:                 STRING shift  40 */
  { 164,   0,  56}, /* 15:                   type shift  56 */
  { 165,  18, 269}, /* 16:               typename shift  269 */
  {  38,   0,  29}, /* 17:                   FAIL shift  29 */
  {  90,  19,  36}, /* 18:                   TEMP shift  36 */
  {  15,   0,  22}, /* 19:                CLUSTER shift  22 */
  {  23,   0,  24}, /* 20:                   COPY shift  24 */
  {  70,   0,  33}, /* 21:                 OFFSET shift  33 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  47,   0,  30}, /* 23:                     ID shift  30 */
  {  48,  20,  31}, /* 24:                 IGNORE shift  31 */
  {  99,   0,  37}, /* 25:                 VACUUM shift  37 */
/* State 56 */
  { 106,   0,  57}, /*  1:               carglist shift  57 */
/* State 57 */
  {  96,   0,  71}, /*  1:                 UNIQUE shift  71 */
  { 105,   3,  58}, /*  2:                   carg shift  58 */
  {  25,   0, 257}, /*  3:                DEFAULT shift  257 */
  {  67,   0,  62}, /*  4:                    NOT shift  62 */
  {  76,   0,  65}, /*  5:                PRIMARY shift  65 */
  {  22,   8,  59}, /*  6:             CONSTRAINT shift  59 */
  { 110,   6, 256}, /*  7:                  ccons shift  256 */
  {  14,   0,  73}, /*  8:                  CHECK shift  73 */
/* State 59 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0,  60}, /* 17:                    ids shift  60 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 60 */
  { 110,   0,  61}, /*  1:                  ccons shift  61 */
  {  96,   4,  71}, /*  2:                 UNIQUE shift  71 */
  {  67,   0,  62}, /*  3:                    NOT shift  62 */
  {  76,   0,  65}, /*  4:                PRIMARY shift  65 */
  {  14,   0,  73}, /*  5:                  CHECK shift  73 */
/* State 62 */
  {  69,   0,  63}, /*  1:                   NULL shift  63 */
/* State 63 */
  { 144,   0,  64}, /*  1:                 onconf shift  64 */
  {  71,   0,   9}, /*  2:                     ON shift  9 */
/* State 65 */
  {  58,   0,  66}, /*  1:                    KEY shift  66 */
/* State 66 */
  { 159,   3,  67}, /*  1:              sortorder shift  67 */
  {  28,   0,  70}, /*  2:                   DESC shift  70 */
  {   6,   0,  69}, /*  3:                    ASC shift  69 */
/* State 67 */
  { 144,   0,  68}, /*  1:                 onconf shift  68 */
  {  71,   0,   9}, /*  2:                     ON shift  9 */
/* State 71 */
  { 144,   0,  72}, /*  1:                 onconf shift  72 */
  {  71,   0,   9}, /*  2:                     ON shift  9 */
/* State 73 */
  {  62,   0,  74}, /*  1:                     LP shift  74 */
/* State 74 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 253}, /* 26:                   expr shift  253 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 75 */
  {  62,   0,  76}, /*  1:                     LP shift  76 */
/* State 76 */
  {   1,   0,  19}, /*  1:                  ABORT shift  19 */
  {  37,   1,  28}, /*  2:                EXPLAIN shift  28 */
  {  74,   5, 180}, /*  3:                   PLUS shift  180 */
  {  75,   6,  34}, /*  4:                 PRAGMA shift  34 */
  {  38,   0,  29}, /*  5:                   FAIL shift  29 */
  {  39,   0, 112}, /*  6:                  FLOAT shift  112 */
  {  78,   9,  35}, /*  7:                REPLACE shift  35 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {   6,   0,  20}, /*  9:                    ASC shift  20 */
  {  15,   0,  22}, /* 10:                CLUSTER shift  22 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  47,   0,  75}, /* 12:                     ID shift  75 */
  {  48,   0,  31}, /* 13:                 IGNORE shift  31 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  88,   0,  78}, /* 15:                 STRING shift  78 */
  {  87,  10, 251}, /* 16:                   STAR shift  251 */
  { 124,  15, 173}, /* 17:                   expr shift  173 */
  { 125,  20, 202}, /* 18:               expritem shift  202 */
  { 126,  21, 249}, /* 19:               exprlist shift  249 */
  {  53,   0, 111}, /* 20:                INTEGER shift  111 */
  {  90,   0,  36}, /* 21:                   TEMP shift  36 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  { 130,  25,  77}, /* 23:                     id shift  77 */
  { 131,  26, 108}, /* 24:                    ids shift  108 */
  {  58,   0,  32}, /* 25:                    KEY shift  32 */
  {  23,   0,  24}, /* 26:                   COPY shift  24 */
  {  62,   0,  79}, /* 27:                     LP shift  79 */
  {  99,  31,  37}, /* 28:                 VACUUM shift  37 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  { 101,  33,  38}, /* 30:                   VIEW shift  38 */
  {  27,   0,  25}, /* 31:             DELIMITERS shift  25 */
  {  67,   0, 174}, /* 32:                    NOT shift  174 */
  {  65,   0, 178}, /* 33:                  MINUS shift  178 */
  {  69,  36, 107}, /* 34:                   NULL shift  107 */
  {  70,   0,  33}, /* 35:                 OFFSET shift  33 */
  {  33,   0,  27}, /* 36:                    END shift  27 */
/* State 77 */
  {  30,   0, 455}, /*  1:                    DOT reduce 44 */
/* State 78 */
  {  30,   0, 456}, /*  1:                    DOT reduce 45 */
/* State 79 */
  {  37,   5,  28}, /*  1:                EXPLAIN shift  28 */
  { 145,   1,  80}, /*  2:              oneselect shift  80 */
  {  74,   6, 180}, /*  3:                   PLUS shift  180 */
  {  75,   9,  34}, /*  4:                 PRAGMA shift  34 */
  {   1,   0,  19}, /*  5:                  ABORT shift  19 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  78,  15,  35}, /*  7:                REPLACE shift  35 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  39,   0, 112}, /*  9:                  FLOAT shift  112 */
  { 153,   0,  81}, /* 10:                 select shift  81 */
  {  82,  20,  84}, /* 11:                 SELECT shift  84 */
  {  47,   0,  75}, /* 12:                     ID shift  75 */
  {  48,   0,  31}, /* 13:                 IGNORE shift  31 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {   6,   0,  20}, /* 15:                    ASC shift  20 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  { 124,  21, 247}, /* 17:                   expr shift  247 */
  {  53,   0, 111}, /* 18:                INTEGER shift  111 */
  {  90,   0,  36}, /* 19:                   TEMP shift  36 */
  {  10,   0, 176}, /* 20:                 BITNOT shift  176 */
  {  88,   0,  78}, /* 21:                 STRING shift  78 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  { 130,  25,  77}, /* 23:                     id shift  77 */
  { 131,  26, 108}, /* 24:                    ids shift  108 */
  {  58,   0,  32}, /* 25:                    KEY shift  32 */
  {  23,   0,  24}, /* 26:                   COPY shift  24 */
  {  62,   0,  79}, /* 27:                     LP shift  79 */
  {  99,  31,  37}, /* 28:                 VACUUM shift  37 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  { 101,  33,  38}, /* 30:                   VIEW shift  38 */
  {  27,   0,  25}, /* 31:             DELIMITERS shift  25 */
  {  67,   0, 174}, /* 32:                    NOT shift  174 */
  {  65,   0, 178}, /* 33:                  MINUS shift  178 */
  {  69,  36, 107}, /* 34:                   NULL shift  107 */
  {  70,   0,  33}, /* 35:                 OFFSET shift  33 */
  {  33,   0,  27}, /* 36:                    END shift  27 */
/* State 81 */
  {  95,   4, 168}, /*  1:                  UNION shift  168 */
  {  36,   0, 171}, /*  2:                 EXCEPT shift  171 */
  { 142,   0,  82}, /*  3:         multiselect_op shift  82 */
  {  80,   0, 246}, /*  4:                     RP shift  246 */
  {  54,   0, 170}, /*  5:              INTERSECT shift  170 */
/* State 82 */
  {  82,   0,  84}, /*  1:                 SELECT shift  84 */
  { 145,   0,  83}, /*  2:              oneselect shift  83 */
/* State 84 */
  { 120,   2,  85}, /*  1:               distinct shift  85 */
  {   3,   0, 245}, /*  2:                    ALL shift  245 */
  {  29,   0, 244}, /*  3:               DISTINCT shift  244 */
/* State 85 */
  { 152,   0,  86}, /*  1:             selcollist shift  86 */
  { 151,   0, 239}, /*  2:                   sclp shift  239 */
/* State 86 */
  {  40,   0, 226}, /*  1:                   FROM shift  226 */
  { 127,   1,  87}, /*  2:                   from shift  87 */
  {  17,   0, 225}, /*  3:                  COMMA shift  225 */
/* State 87 */
  { 103,   0, 223}, /*  1:                  WHERE shift  223 */
  { 167,   1,  88}, /*  2:              where_opt shift  88 */
/* State 88 */
  { 128,   2,  89}, /*  1:            groupby_opt shift  89 */
  {  44,   0, 220}, /*  2:                  GROUP shift  220 */
/* State 89 */
  {  46,   0, 218}, /*  1:                 HAVING shift  218 */
  { 129,   0,  90}, /*  2:             having_opt shift  90 */
/* State 90 */
  {  73,   0,  99}, /*  1:                  ORDER shift  99 */
  { 147,   1,  91}, /*  2:            orderby_opt shift  91 */
/* State 91 */
  {  61,   0,  93}, /*  1:                  LIMIT shift  93 */
  { 139,   1,  92}, /*  2:              limit_opt shift  92 */
/* State 93 */
  {  53,   0,  94}, /*  1:                INTEGER shift  94 */
/* State 94 */
  {  17,   0,  98}, /*  1:                  COMMA shift  98 */
  {  70,   0,  97}, /*  2:                 OFFSET shift  97 */
  { 140,   1,  95}, /*  3:              limit_sep shift  95 */
/* State 95 */
  {  53,   0,  96}, /*  1:                INTEGER shift  96 */
/* State 97 */
  {  53,   0, 544}, /*  1:                INTEGER reduce 133 */
/* State 98 */
  {  53,   0, 545}, /*  1:                INTEGER reduce 134 */
/* State 99 */
  {  12,   0, 100}, /*  1:                     BY shift  100 */
/* State 100 */
  {  70,   0,  33}, /*  1:                 OFFSET shift  33 */
  {   1,   0,  19}, /*  2:                  ABORT shift  19 */
  {  37,   0,  28}, /*  3:                EXPLAIN shift  28 */
  {  38,   0,  29}, /*  4:                   FAIL shift  29 */
  {  74,  10, 180}, /*  5:                   PLUS shift  180 */
  {  75,   0,  34}, /*  6:                 PRAGMA shift  34 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  78,   0,  35}, /*  9:                REPLACE shift  35 */
  {  39,   0, 112}, /* 10:                  FLOAT shift  112 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  13,   0, 182}, /* 12:                   CASE shift  182 */
  {  47,   0,  75}, /* 13:                     ID shift  75 */
  {  48,  12,  31}, /* 14:                 IGNORE shift  31 */
  {  88,  17,  78}, /* 15:                 STRING shift  78 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 17:                INTEGER shift  111 */
  { 157,   0, 216}, /* 18:               sortitem shift  216 */
  { 158,  15, 101}, /* 19:               sortlist shift  101 */
  { 124,   0, 105}, /* 20:                   expr shift  105 */
  {  90,   0,  36}, /* 21:                   TEMP shift  36 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  23,   0,  24}, /* 23:                   COPY shift  24 */
  {  58,  23,  32}, /* 24:                    KEY shift  32 */
  {  27,   0,  25}, /* 25:             DELIMITERS shift  25 */
  { 130,   0,  77}, /* 26:                     id shift  77 */
  { 131,   0, 108}, /* 27:                    ids shift  108 */
  {  62,  25,  79}, /* 28:                     LP shift  79 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  99,   0,  37}, /* 30:                 VACUUM shift  37 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 101,   0,  38}, /* 32:                   VIEW shift  38 */
  {  67,   0, 174}, /* 33:                    NOT shift  174 */
  {  33,   0,  27}, /* 34:                    END shift  27 */
  {  69,   0, 107}, /* 35:                   NULL shift  107 */
/* State 101 */
  {  17,   0, 102}, /*  1:                  COMMA shift  102 */
/* State 102 */
  {   1,   0,  19}, /*  1:                  ABORT shift  19 */
  {  69,   1, 107}, /*  2:                   NULL shift  107 */
  {  70,   0,  33}, /*  3:                 OFFSET shift  33 */
  {  37,   0,  28}, /*  4:                EXPLAIN shift  28 */
  {  38,   0,  29}, /*  5:                   FAIL shift  29 */
  {  39,   0, 112}, /*  6:                  FLOAT shift  112 */
  {  74,   9, 180}, /*  7:                   PLUS shift  180 */
  {  75,  10,  34}, /*  8:                 PRAGMA shift  34 */
  {   6,   0,  20}, /*  9:                    ASC shift  20 */
  {   7,   0,  21}, /* 10:                  BEGIN shift  21 */
  {  78,  12,  35}, /* 11:                REPLACE shift  35 */
  {  10,   0, 176}, /* 12:                 BITNOT shift  176 */
  {  13,   0, 182}, /* 13:                   CASE shift  182 */
  {  47,  13,  75}, /* 14:                     ID shift  75 */
  {  48,   0,  31}, /* 15:                 IGNORE shift  31 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  {  21,   0,  23}, /* 17:               CONFLICT shift  23 */
  {  90,   0,  36}, /* 18:                   TEMP shift  36 */
  {  62,  26,  79}, /* 19:                     LP shift  79 */
  {  53,   0, 111}, /* 20:                INTEGER shift  111 */
  {  88,   0,  78}, /* 21:                 STRING shift  78 */
  { 157,  17, 103}, /* 22:               sortitem shift  103 */
  { 124,  18, 105}, /* 23:                   expr shift  105 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  58,   0,  32}, /* 25:                    KEY shift  32 */
  {  28,   0,  26}, /* 26:                   DESC shift  26 */
  {  65,   0, 178}, /* 27:                  MINUS shift  178 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  { 130,  19,  77}, /* 29:                     id shift  77 */
  { 131,   0, 108}, /* 30:                    ids shift  108 */
  {  67,  33, 174}, /* 31:                    NOT shift  174 */
  {  99,  27,  37}, /* 32:                 VACUUM shift  37 */
  {  33,   0,  27}, /* 33:                    END shift  27 */
  { 101,  31,  38}, /* 34:                   VIEW shift  38 */
/* State 103 */
  { 159,   3, 104}, /*  1:              sortorder shift  104 */
  {  28,   0,  70}, /*  2:                   DESC shift  70 */
  {   6,   0,  69}, /*  3:                    ASC shift  69 */
/* State 105 */
  {   4,   0, 106}, /*  1:                    AND shift  106 */
  {  59,   0, 120}, /*  2:                     LE shift  120 */
  {   8,   0, 161}, /*  3:                BETWEEN shift  161 */
  {  81,   0, 134}, /*  4:                 RSHIFT shift  134 */
  {  56,   1, 156}, /*  5:                     IS shift  156 */
  {  57,   0, 155}, /*  6:                 ISNULL shift  155 */
  {  35,  11, 126}, /*  7:                     EQ shift  126 */
  {  85,   2, 149}, /*  8:                  SLASH shift  149 */
  {  60,   3, 136}, /*  9:                   LIKE shift  136 */
  {  87,   7, 147}, /* 10:                   STAR shift  147 */
  {   9,   0, 128}, /* 11:                 BITAND shift  128 */
  {  63,  19, 132}, /* 12:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 13:                     LT shift  116 */
  {  65,   0, 145}, /* 14:                  MINUS shift  145 */
  {  66,   0, 124}, /* 15:                     NE shift  124 */
  {  67,   0, 138}, /* 16:                    NOT shift  138 */
  {  68,  22, 160}, /* 17:                NOTNULL shift  160 */
  {  43,   0, 141}, /* 18:                   GLOB shift  141 */
  {  11,   0, 130}, /* 19:                  BITOR shift  130 */
  {  45,   0, 118}, /* 20:                     GT shift  118 */
  {  72,  24, 114}, /* 21:                     OR shift  114 */
  {  42,   0, 122}, /* 22:                     GE shift  122 */
  {  74,   0, 143}, /* 23:                   PLUS shift  143 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 25:                     IN shift  165 */
  {  77,   0, 151}, /* 26:                    REM shift  151 */
/* State 106 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 113}, /* 26:                   expr shift  113 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 108 */
  {  30,   0, 109}, /*  1:                    DOT shift  109 */
/* State 109 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 110}, /* 17:                    ids shift  110 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 113 */
  {  50,   0, 165}, /*  1:                     IN shift  165 */
  {   8,   0, 161}, /*  2:                BETWEEN shift  161 */
  {  74,   1, 143}, /*  3:                   PLUS shift  143 */
  {  57,   5, 155}, /*  4:                 ISNULL shift  155 */
  {   9,   0, 128}, /*  5:                 BITAND shift  128 */
  {  77,   0, 151}, /*  6:                    REM shift  151 */
  {  35,   8, 126}, /*  7:                     EQ shift  126 */
  {  11,   0, 130}, /*  8:                  BITOR shift  130 */
  {  56,   2, 156}, /*  9:                     IS shift  156 */
  {  81,   4, 134}, /* 10:                 RSHIFT shift  134 */
  {  63,   0, 132}, /* 11:                 LSHIFT shift  132 */
  {  59,   7, 120}, /* 12:                     LE shift  120 */
  {  60,   0, 136}, /* 13:                   LIKE shift  136 */
  {  85,   0, 149}, /* 14:                  SLASH shift  149 */
  {  42,   0, 122}, /* 15:                     GE shift  122 */
  {  87,  11, 147}, /* 16:                   STAR shift  147 */
  {  64,   0, 116}, /* 17:                     LT shift  116 */
  {  65,   0, 145}, /* 18:                  MINUS shift  145 */
  {  66,  15, 124}, /* 19:                     NE shift  124 */
  {  67,  23, 138}, /* 20:                    NOT shift  138 */
  {  68,  24, 160}, /* 21:                NOTNULL shift  160 */
  {  45,   0, 118}, /* 22:                     GT shift  118 */
  {  43,   0, 141}, /* 23:                   GLOB shift  141 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
/* State 114 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 115}, /* 26:                   expr shift  115 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 115 */
  {  50,   0, 165}, /*  1:                     IN shift  165 */
  {  56,   0, 156}, /*  2:                     IS shift  156 */
  {  77,   0, 151}, /*  3:                    REM shift  151 */
  {   9,   0, 128}, /*  4:                 BITAND shift  128 */
  {   4,   0, 106}, /*  5:                    AND shift  106 */
  {  60,  20, 136}, /*  6:                   LIKE shift  136 */
  {  81,   2, 134}, /*  7:                 RSHIFT shift  134 */
  {  57,   0, 155}, /*  8:                 ISNULL shift  155 */
  {   8,   0, 161}, /*  9:                BETWEEN shift  161 */
  {  59,   4, 120}, /* 10:                     LE shift  120 */
  {  85,   6, 149}, /* 11:                  SLASH shift  149 */
  {  11,   0, 130}, /* 12:                  BITOR shift  130 */
  {  87,   0, 147}, /* 13:                   STAR shift  147 */
  {  63,   0, 132}, /* 14:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 15:                     LT shift  116 */
  {  65,   0, 145}, /* 16:                  MINUS shift  145 */
  {  66,   0, 124}, /* 17:                     NE shift  124 */
  {  67,  22, 138}, /* 18:                    NOT shift  138 */
  {  68,  23, 160}, /* 19:                NOTNULL shift  160 */
  {  35,   0, 126}, /* 20:                     EQ shift  126 */
  {  45,  24, 118}, /* 21:                     GT shift  118 */
  {  42,   0, 122}, /* 22:                     GE shift  122 */
  {  43,   0, 141}, /* 23:                   GLOB shift  141 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
  {  74,   0, 143}, /* 25:                   PLUS shift  143 */
/* State 116 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 117}, /* 26:                   expr shift  117 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 117 */
  {  20,   0, 153}, /*  1:                 CONCAT shift  153 */
  {  81,   3, 134}, /*  2:                 RSHIFT shift  134 */
  {  11,   0, 130}, /*  3:                  BITOR shift  130 */
  {  63,   0, 132}, /*  4:                 LSHIFT shift  132 */
  {  74,   0, 143}, /*  5:                   PLUS shift  143 */
  {  85,   7, 149}, /*  6:                  SLASH shift  149 */
  {  65,   0, 145}, /*  7:                  MINUS shift  145 */
  {  87,   9, 147}, /*  8:                   STAR shift  147 */
  {  77,   0, 151}, /*  9:                    REM shift  151 */
  {   9,   0, 128}, /* 10:                 BITAND shift  128 */
/* State 118 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 119}, /* 26:                   expr shift  119 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 119 */
  {  20,   0, 153}, /*  1:                 CONCAT shift  153 */
  {  81,   3, 134}, /*  2:                 RSHIFT shift  134 */
  {  11,   0, 130}, /*  3:                  BITOR shift  130 */
  {  63,   0, 132}, /*  4:                 LSHIFT shift  132 */
  {  74,   0, 143}, /*  5:                   PLUS shift  143 */
  {  85,   7, 149}, /*  6:                  SLASH shift  149 */
  {  65,   0, 145}, /*  7:                  MINUS shift  145 */
  {  87,   9, 147}, /*  8:                   STAR shift  147 */
  {  77,   0, 151}, /*  9:                    REM shift  151 */
  {   9,   0, 128}, /* 10:                 BITAND shift  128 */
/* State 120 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 121}, /* 26:                   expr shift  121 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 121 */
  {  20,   0, 153}, /*  1:                 CONCAT shift  153 */
  {  81,   3, 134}, /*  2:                 RSHIFT shift  134 */
  {  11,   0, 130}, /*  3:                  BITOR shift  130 */
  {  63,   0, 132}, /*  4:                 LSHIFT shift  132 */
  {  74,   0, 143}, /*  5:                   PLUS shift  143 */
  {  85,   7, 149}, /*  6:                  SLASH shift  149 */
  {  65,   0, 145}, /*  7:                  MINUS shift  145 */
  {  87,   9, 147}, /*  8:                   STAR shift  147 */
  {  77,   0, 151}, /*  9:                    REM shift  151 */
  {   9,   0, 128}, /* 10:                 BITAND shift  128 */
/* State 122 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 123}, /* 26:                   expr shift  123 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 123 */
  {  20,   0, 153}, /*  1:                 CONCAT shift  153 */
  {  81,   3, 134}, /*  2:                 RSHIFT shift  134 */
  {  11,   0, 130}, /*  3:                  BITOR shift  130 */
  {  63,   0, 132}, /*  4:                 LSHIFT shift  132 */
  {  74,   0, 143}, /*  5:                   PLUS shift  143 */
  {  85,   7, 149}, /*  6:                  SLASH shift  149 */
  {  65,   0, 145}, /*  7:                  MINUS shift  145 */
  {  87,   9, 147}, /*  8:                   STAR shift  147 */
  {  77,   0, 151}, /*  9:                    REM shift  151 */
  {   9,   0, 128}, /* 10:                 BITAND shift  128 */
/* State 124 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 125}, /* 26:                   expr shift  125 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 125 */
  {  42,   0, 122}, /*  1:                     GE shift  122 */
  {  85,   0, 149}, /*  2:                  SLASH shift  149 */
  {  59,   6, 120}, /*  3:                     LE shift  120 */
  {  87,   3, 147}, /*  4:                   STAR shift  147 */
  {  74,   0, 143}, /*  5:                   PLUS shift  143 */
  {  45,   0, 118}, /*  6:                     GT shift  118 */
  {  20,   0, 153}, /*  7:                 CONCAT shift  153 */
  {  77,  11, 151}, /*  8:                    REM shift  151 */
  {  64,   0, 116}, /*  9:                     LT shift  116 */
  {  65,  13, 145}, /* 10:                  MINUS shift  145 */
  {  63,   0, 132}, /* 11:                 LSHIFT shift  132 */
  {  81,  14, 134}, /* 12:                 RSHIFT shift  134 */
  {   9,   0, 128}, /* 13:                 BITAND shift  128 */
  {  11,   0, 130}, /* 14:                  BITOR shift  130 */
/* State 126 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 127}, /* 26:                   expr shift  127 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 127 */
  {  42,   0, 122}, /*  1:                     GE shift  122 */
  {  85,   0, 149}, /*  2:                  SLASH shift  149 */
  {  59,   6, 120}, /*  3:                     LE shift  120 */
  {  87,   3, 147}, /*  4:                   STAR shift  147 */
  {  74,   0, 143}, /*  5:                   PLUS shift  143 */
  {  45,   0, 118}, /*  6:                     GT shift  118 */
  {  20,   0, 153}, /*  7:                 CONCAT shift  153 */
  {  77,  11, 151}, /*  8:                    REM shift  151 */
  {  64,   0, 116}, /*  9:                     LT shift  116 */
  {  65,  13, 145}, /* 10:                  MINUS shift  145 */
  {  63,   0, 132}, /* 11:                 LSHIFT shift  132 */
  {  81,  14, 134}, /* 12:                 RSHIFT shift  134 */
  {   9,   0, 128}, /* 13:                 BITAND shift  128 */
  {  11,   0, 130}, /* 14:                  BITOR shift  130 */
/* State 128 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 129}, /* 26:                   expr shift  129 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 129 */
  {  20,   0, 153}, /*  1:                 CONCAT shift  153 */
  {  85,   0, 149}, /*  2:                  SLASH shift  149 */
  {  74,   1, 143}, /*  3:                   PLUS shift  143 */
  {  87,   0, 147}, /*  4:                   STAR shift  147 */
  {  65,   0, 145}, /*  5:                  MINUS shift  145 */
  {  77,   5, 151}, /*  6:                    REM shift  151 */
/* State 130 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 131}, /* 26:                   expr shift  131 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 131 */
  {  20,   0, 153}, /*  1:                 CONCAT shift  153 */
  {  85,   0, 149}, /*  2:                  SLASH shift  149 */
  {  74,   1, 143}, /*  3:                   PLUS shift  143 */
  {  87,   0, 147}, /*  4:                   STAR shift  147 */
  {  65,   0, 145}, /*  5:                  MINUS shift  145 */
  {  77,   5, 151}, /*  6:                    REM shift  151 */
/* State 132 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 133}, /* 26:                   expr shift  133 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 133 */
  {  20,   0, 153}, /*  1:                 CONCAT shift  153 */
  {  85,   0, 149}, /*  2:                  SLASH shift  149 */
  {  74,   1, 143}, /*  3:                   PLUS shift  143 */
  {  87,   0, 147}, /*  4:                   STAR shift  147 */
  {  65,   0, 145}, /*  5:                  MINUS shift  145 */
  {  77,   5, 151}, /*  6:                    REM shift  151 */
/* State 134 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 135}, /* 26:                   expr shift  135 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 135 */
  {  20,   0, 153}, /*  1:                 CONCAT shift  153 */
  {  85,   0, 149}, /*  2:                  SLASH shift  149 */
  {  74,   1, 143}, /*  3:                   PLUS shift  143 */
  {  87,   0, 147}, /*  4:                   STAR shift  147 */
  {  65,   0, 145}, /*  5:                  MINUS shift  145 */
  {  77,   5, 151}, /*  6:                    REM shift  151 */
/* State 136 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 137}, /* 26:                   expr shift  137 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 137 */
  {  42,   0, 122}, /*  1:                     GE shift  122 */
  {  85,   0, 149}, /*  2:                  SLASH shift  149 */
  {  59,   6, 120}, /*  3:                     LE shift  120 */
  {  87,   3, 147}, /*  4:                   STAR shift  147 */
  {  74,   0, 143}, /*  5:                   PLUS shift  143 */
  {  45,   0, 118}, /*  6:                     GT shift  118 */
  {  20,   0, 153}, /*  7:                 CONCAT shift  153 */
  {  77,  11, 151}, /*  8:                    REM shift  151 */
  {  64,   0, 116}, /*  9:                     LT shift  116 */
  {  65,  13, 145}, /* 10:                  MINUS shift  145 */
  {  63,   0, 132}, /* 11:                 LSHIFT shift  132 */
  {  81,  14, 134}, /* 12:                 RSHIFT shift  134 */
  {   9,   0, 128}, /* 13:                 BITAND shift  128 */
  {  11,   0, 130}, /* 14:                  BITOR shift  130 */
/* State 138 */
  {  60,   2, 139}, /*  1:                   LIKE shift  139 */
  {  50,   0, 210}, /*  2:                     IN shift  210 */
  {   8,   0, 206}, /*  3:                BETWEEN shift  206 */
  {  43,   3, 203}, /*  4:                   GLOB shift  203 */
  {  69,   0, 205}, /*  5:                   NULL shift  205 */
/* State 139 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 140}, /* 26:                   expr shift  140 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 140 */
  {  50,   0, 165}, /*  1:                     IN shift  165 */
  {   8,   0, 161}, /*  2:                BETWEEN shift  161 */
  {  74,   1, 143}, /*  3:                   PLUS shift  143 */
  {  57,   5, 155}, /*  4:                 ISNULL shift  155 */
  {   9,   0, 128}, /*  5:                 BITAND shift  128 */
  {  77,   0, 151}, /*  6:                    REM shift  151 */
  {  35,   8, 126}, /*  7:                     EQ shift  126 */
  {  11,   0, 130}, /*  8:                  BITOR shift  130 */
  {  56,   2, 156}, /*  9:                     IS shift  156 */
  {  81,   4, 134}, /* 10:                 RSHIFT shift  134 */
  {  63,   0, 132}, /* 11:                 LSHIFT shift  132 */
  {  59,   7, 120}, /* 12:                     LE shift  120 */
  {  60,   0, 136}, /* 13:                   LIKE shift  136 */
  {  85,   0, 149}, /* 14:                  SLASH shift  149 */
  {  42,   0, 122}, /* 15:                     GE shift  122 */
  {  87,  11, 147}, /* 16:                   STAR shift  147 */
  {  64,   0, 116}, /* 17:                     LT shift  116 */
  {  65,   0, 145}, /* 18:                  MINUS shift  145 */
  {  66,  15, 124}, /* 19:                     NE shift  124 */
  {  67,  23, 138}, /* 20:                    NOT shift  138 */
  {  68,  24, 160}, /* 21:                NOTNULL shift  160 */
  {  45,   0, 118}, /* 22:                     GT shift  118 */
  {  43,   0, 141}, /* 23:                   GLOB shift  141 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
/* State 141 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 142}, /* 26:                   expr shift  142 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 142 */
  {  42,   0, 122}, /*  1:                     GE shift  122 */
  {  85,   0, 149}, /*  2:                  SLASH shift  149 */
  {  59,   6, 120}, /*  3:                     LE shift  120 */
  {  87,   3, 147}, /*  4:                   STAR shift  147 */
  {  74,   0, 143}, /*  5:                   PLUS shift  143 */
  {  45,   0, 118}, /*  6:                     GT shift  118 */
  {  20,   0, 153}, /*  7:                 CONCAT shift  153 */
  {  77,  11, 151}, /*  8:                    REM shift  151 */
  {  64,   0, 116}, /*  9:                     LT shift  116 */
  {  65,  13, 145}, /* 10:                  MINUS shift  145 */
  {  63,   0, 132}, /* 11:                 LSHIFT shift  132 */
  {  81,  14, 134}, /* 12:                 RSHIFT shift  134 */
  {   9,   0, 128}, /* 13:                 BITAND shift  128 */
  {  11,   0, 130}, /* 14:                  BITOR shift  130 */
/* State 143 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 144}, /* 26:                   expr shift  144 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 144 */
  {  20,   0, 153}, /*  1:                 CONCAT shift  153 */
  {  85,   3, 149}, /*  2:                  SLASH shift  149 */
  {  77,   0, 151}, /*  3:                    REM shift  151 */
  {  87,   0, 147}, /*  4:                   STAR shift  147 */
/* State 145 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 146}, /* 26:                   expr shift  146 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 146 */
  {  20,   0, 153}, /*  1:                 CONCAT shift  153 */
  {  85,   3, 149}, /*  2:                  SLASH shift  149 */
  {  77,   0, 151}, /*  3:                    REM shift  151 */
  {  87,   0, 147}, /*  4:                   STAR shift  147 */
/* State 147 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 148}, /* 26:                   expr shift  148 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 148 */
  {  20,   0, 153}, /*  1:                 CONCAT shift  153 */
/* State 149 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 150}, /* 26:                   expr shift  150 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 150 */
  {  20,   0, 153}, /*  1:                 CONCAT shift  153 */
/* State 151 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 152}, /* 26:                   expr shift  152 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 152 */
  {  20,   0, 153}, /*  1:                 CONCAT shift  153 */
/* State 153 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 154}, /* 26:                   expr shift  154 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 156 */
  {  67,   0, 158}, /*  1:                    NOT shift  158 */
  {  69,   1, 157}, /*  2:                   NULL shift  157 */
/* State 158 */
  {  69,   0, 159}, /*  1:                   NULL shift  159 */
/* State 161 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 162}, /* 26:                   expr shift  162 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 162 */
  {   4,   0, 163}, /*  1:                    AND shift  163 */
  {  59,   0, 120}, /*  2:                     LE shift  120 */
  {   8,   0, 161}, /*  3:                BETWEEN shift  161 */
  {  81,   0, 134}, /*  4:                 RSHIFT shift  134 */
  {  56,   1, 156}, /*  5:                     IS shift  156 */
  {  57,   0, 155}, /*  6:                 ISNULL shift  155 */
  {  35,  11, 126}, /*  7:                     EQ shift  126 */
  {  85,   2, 149}, /*  8:                  SLASH shift  149 */
  {  60,   3, 136}, /*  9:                   LIKE shift  136 */
  {  87,   7, 147}, /* 10:                   STAR shift  147 */
  {   9,   0, 128}, /* 11:                 BITAND shift  128 */
  {  63,  19, 132}, /* 12:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 13:                     LT shift  116 */
  {  65,   0, 145}, /* 14:                  MINUS shift  145 */
  {  66,   0, 124}, /* 15:                     NE shift  124 */
  {  67,   0, 138}, /* 16:                    NOT shift  138 */
  {  68,  22, 160}, /* 17:                NOTNULL shift  160 */
  {  43,   0, 141}, /* 18:                   GLOB shift  141 */
  {  11,   0, 130}, /* 19:                  BITOR shift  130 */
  {  45,   0, 118}, /* 20:                     GT shift  118 */
  {  72,  24, 114}, /* 21:                     OR shift  114 */
  {  42,   0, 122}, /* 22:                     GE shift  122 */
  {  74,   0, 143}, /* 23:                   PLUS shift  143 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 25:                     IN shift  165 */
  {  77,   0, 151}, /* 26:                    REM shift  151 */
/* State 163 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 164}, /* 26:                   expr shift  164 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 164 */
  {  42,   0, 122}, /*  1:                     GE shift  122 */
  {  85,   0, 149}, /*  2:                  SLASH shift  149 */
  {  59,   6, 120}, /*  3:                     LE shift  120 */
  {  87,   3, 147}, /*  4:                   STAR shift  147 */
  {  74,   0, 143}, /*  5:                   PLUS shift  143 */
  {  45,   0, 118}, /*  6:                     GT shift  118 */
  {  20,   0, 153}, /*  7:                 CONCAT shift  153 */
  {  77,  11, 151}, /*  8:                    REM shift  151 */
  {  64,   0, 116}, /*  9:                     LT shift  116 */
  {  65,  13, 145}, /* 10:                  MINUS shift  145 */
  {  63,   0, 132}, /* 11:                 LSHIFT shift  132 */
  {  81,  14, 134}, /* 12:                 RSHIFT shift  134 */
  {   9,   0, 128}, /* 13:                 BITAND shift  128 */
  {  11,   0, 130}, /* 14:                  BITOR shift  130 */
/* State 165 */
  {  62,   0, 166}, /*  1:                     LP shift  166 */
/* State 166 */
  {  38,   0,  29}, /*  1:                   FAIL shift  29 */
  { 153,   4, 167}, /*  2:                 select shift  167 */
  {  78,   0,  35}, /*  3:                REPLACE shift  35 */
  {  39,   5, 112}, /*  4:                  FLOAT shift  112 */
  {   1,   0,  19}, /*  5:                  ABORT shift  19 */
  {   6,   0,  20}, /*  6:                    ASC shift  20 */
  {  82,   6,  84}, /*  7:                 SELECT shift  84 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  48,  19,  31}, /*  9:                 IGNORE shift  31 */
  {  47,   0,  75}, /* 10:                     ID shift  75 */
  { 124,   9, 173}, /* 11:                   expr shift  173 */
  { 125,   0, 202}, /* 12:               expritem shift  202 */
  { 126,  20, 198}, /* 13:               exprlist shift  198 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  90,   0,  36}, /* 15:                   TEMP shift  36 */
  {  53,  23, 111}, /* 16:                INTEGER shift  111 */
  { 130,   0,  77}, /* 17:                     id shift  77 */
  { 131,   0, 108}, /* 18:                    ids shift  108 */
  {  10,   0, 176}, /* 19:                 BITNOT shift  176 */
  {  88,   0,  78}, /* 20:                 STRING shift  78 */
  {  58,   0,  32}, /* 21:                    KEY shift  32 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  15,   0,  22}, /* 23:                CLUSTER shift  22 */
  {  99,  27,  37}, /* 24:                 VACUUM shift  37 */
  {  62,   0,  79}, /* 25:                     LP shift  79 */
  { 101,   0,  38}, /* 26:                   VIEW shift  38 */
  {  23,   0,  24}, /* 27:                   COPY shift  24 */
  {  65,  31, 178}, /* 28:                  MINUS shift  178 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  67,   0, 174}, /* 30:                    NOT shift  174 */
  {  27,   0,  25}, /* 31:             DELIMITERS shift  25 */
  { 145,  35,  80}, /* 32:              oneselect shift  80 */
  {  70,   0,  33}, /* 33:                 OFFSET shift  33 */
  {  33,   0,  27}, /* 34:                    END shift  27 */
  {  69,   0, 107}, /* 35:                   NULL shift  107 */
  {  37,   0,  28}, /* 36:                EXPLAIN shift  28 */
  {  74,   0, 180}, /* 37:                   PLUS shift  180 */
  {  75,  36,  34}, /* 38:                 PRAGMA shift  34 */
/* State 167 */
  {  95,   4, 168}, /*  1:                  UNION shift  168 */
  {  36,   0, 171}, /*  2:                 EXCEPT shift  171 */
  { 142,   0,  82}, /*  3:         multiselect_op shift  82 */
  {  80,   0, 172}, /*  4:                     RP shift  172 */
  {  54,   0, 170}, /*  5:              INTERSECT shift  170 */
/* State 168 */
  {  82,   0, 507}, /*  1:                 SELECT reduce 96 */
  {   3,   0, 169}, /*  2:                    ALL shift  169 */
/* State 169 */
  {  82,   0, 508}, /*  1:                 SELECT reduce 97 */
/* State 170 */
  {  82,   0, 509}, /*  1:                 SELECT reduce 98 */
/* State 171 */
  {  82,   0, 510}, /*  1:                 SELECT reduce 99 */
/* State 173 */
  {   4,   0, 106}, /*  1:                    AND shift  106 */
  {  59,   0, 120}, /*  2:                     LE shift  120 */
  {   8,   0, 161}, /*  3:                BETWEEN shift  161 */
  {  81,   0, 134}, /*  4:                 RSHIFT shift  134 */
  {  56,   1, 156}, /*  5:                     IS shift  156 */
  {  57,   0, 155}, /*  6:                 ISNULL shift  155 */
  {  35,  11, 126}, /*  7:                     EQ shift  126 */
  {  85,   2, 149}, /*  8:                  SLASH shift  149 */
  {  60,   3, 136}, /*  9:                   LIKE shift  136 */
  {  87,   7, 147}, /* 10:                   STAR shift  147 */
  {   9,   0, 128}, /* 11:                 BITAND shift  128 */
  {  63,  19, 132}, /* 12:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 13:                     LT shift  116 */
  {  65,   0, 145}, /* 14:                  MINUS shift  145 */
  {  66,   0, 124}, /* 15:                     NE shift  124 */
  {  67,   0, 138}, /* 16:                    NOT shift  138 */
  {  68,  22, 160}, /* 17:                NOTNULL shift  160 */
  {  43,   0, 141}, /* 18:                   GLOB shift  141 */
  {  11,   0, 130}, /* 19:                  BITOR shift  130 */
  {  45,   0, 118}, /* 20:                     GT shift  118 */
  {  72,  24, 114}, /* 21:                     OR shift  114 */
  {  42,   0, 122}, /* 22:                     GE shift  122 */
  {  74,   0, 143}, /* 23:                   PLUS shift  143 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 25:                     IN shift  165 */
  {  77,   0, 151}, /* 26:                    REM shift  151 */
/* State 174 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 175}, /* 26:                   expr shift  175 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 175 */
  {  50,   0, 165}, /*  1:                     IN shift  165 */
  {   8,   0, 161}, /*  2:                BETWEEN shift  161 */
  {  74,   1, 143}, /*  3:                   PLUS shift  143 */
  {  57,   5, 155}, /*  4:                 ISNULL shift  155 */
  {   9,   0, 128}, /*  5:                 BITAND shift  128 */
  {  77,   0, 151}, /*  6:                    REM shift  151 */
  {  35,   8, 126}, /*  7:                     EQ shift  126 */
  {  11,   0, 130}, /*  8:                  BITOR shift  130 */
  {  56,   2, 156}, /*  9:                     IS shift  156 */
  {  81,   4, 134}, /* 10:                 RSHIFT shift  134 */
  {  63,   0, 132}, /* 11:                 LSHIFT shift  132 */
  {  59,   7, 120}, /* 12:                     LE shift  120 */
  {  60,   0, 136}, /* 13:                   LIKE shift  136 */
  {  85,   0, 149}, /* 14:                  SLASH shift  149 */
  {  42,   0, 122}, /* 15:                     GE shift  122 */
  {  87,  11, 147}, /* 16:                   STAR shift  147 */
  {  64,   0, 116}, /* 17:                     LT shift  116 */
  {  65,   0, 145}, /* 18:                  MINUS shift  145 */
  {  66,  15, 124}, /* 19:                     NE shift  124 */
  {  67,  23, 138}, /* 20:                    NOT shift  138 */
  {  68,  24, 160}, /* 21:                NOTNULL shift  160 */
  {  45,   0, 118}, /* 22:                     GT shift  118 */
  {  43,   0, 141}, /* 23:                   GLOB shift  141 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
/* State 176 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 177}, /* 26:                   expr shift  177 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 178 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 179}, /* 26:                   expr shift  179 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 180 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 181}, /* 26:                   expr shift  181 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 182 */
  {  70,   0,  33}, /*  1:                 OFFSET shift  33 */
  {   1,   0,  19}, /*  2:                  ABORT shift  19 */
  {  37,   0,  28}, /*  3:                EXPLAIN shift  28 */
  {  38,   0,  29}, /*  4:                   FAIL shift  29 */
  { 109,  10, 184}, /*  5:           case_operand shift  184 */
  {  75,   0,  34}, /*  6:                 PRAGMA shift  34 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  78,   0,  35}, /*  9:                REPLACE shift  35 */
  {  74,  12, 180}, /* 10:                   PLUS shift  180 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  39,   0, 112}, /* 12:                  FLOAT shift  112 */
  {  47,   0,  75}, /* 13:                     ID shift  75 */
  {  48,  15,  31}, /* 14:                 IGNORE shift  31 */
  {  13,   0, 182}, /* 15:                   CASE shift  182 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 17:                INTEGER shift  111 */
  {  23,   0,  24}, /* 18:                   COPY shift  24 */
  {  88,  17,  78}, /* 19:                 STRING shift  78 */
  { 124,   0, 183}, /* 20:                   expr shift  183 */
  {  90,   0,  36}, /* 21:                   TEMP shift  36 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  27,   0,  25}, /* 23:             DELIMITERS shift  25 */
  {  58,  18,  32}, /* 24:                    KEY shift  32 */
  {  67,   0, 174}, /* 25:                    NOT shift  174 */
  { 130,   0,  77}, /* 26:                     id shift  77 */
  { 131,   0, 108}, /* 27:                    ids shift  108 */
  {  62,  23,  79}, /* 28:                     LP shift  79 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  99,   0,  37}, /* 30:                 VACUUM shift  37 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 101,   0,  38}, /* 32:                   VIEW shift  38 */
  { 102,  25, 615}, /* 33:                   WHEN reduce 204 */
  {  33,   0,  27}, /* 34:                    END shift  27 */
  {  69,   0, 107}, /* 35:                   NULL shift  107 */
/* State 183 */
  {  81,   0, 134}, /*  1:                 RSHIFT shift  134 */
  {   4,   0, 106}, /*  2:                    AND shift  106 */
  {  56,   0, 156}, /*  3:                     IS shift  156 */
  {  57,   0, 155}, /*  4:                 ISNULL shift  155 */
  {  85,   2, 149}, /*  5:                  SLASH shift  149 */
  {  59,   0, 120}, /*  6:                     LE shift  120 */
  {  87,   8, 147}, /*  7:                   STAR shift  147 */
  {  60,   0, 136}, /*  8:                   LIKE shift  136 */
  {  35,  18, 126}, /*  9:                     EQ shift  126 */
  {  63,  20, 132}, /* 10:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 11:                     LT shift  116 */
  {  65,  23, 145}, /* 12:                  MINUS shift  145 */
  {  66,   0, 124}, /* 13:                     NE shift  124 */
  {  67,   0, 138}, /* 14:                    NOT shift  138 */
  {  68,   0, 160}, /* 15:                NOTNULL shift  160 */
  {  42,   0, 122}, /* 16:                     GE shift  122 */
  {  43,   0, 141}, /* 17:                   GLOB shift  141 */
  {   8,   0, 161}, /* 18:                BETWEEN shift  161 */
  {  72,  25, 114}, /* 19:                     OR shift  114 */
  {   9,   0, 128}, /* 20:                 BITAND shift  128 */
  {  74,  26, 143}, /* 21:                   PLUS shift  143 */
  { 102,   0, 614}, /* 22:                   WHEN reduce 203 */
  {  11,   0, 130}, /* 23:                  BITOR shift  130 */
  {  77,  27, 151}, /* 24:                    REM shift  151 */
  {  45,   0, 118}, /* 25:                     GT shift  118 */
  {  20,   0, 153}, /* 26:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 27:                     IN shift  165 */
/* State 184 */
  { 108,   2, 185}, /*  1:          case_exprlist shift  185 */
  { 102,   0, 194}, /*  2:                   WHEN shift  194 */
/* State 185 */
  {  32,   0, 192}, /*  1:                   ELSE shift  192 */
  {  33,   0, 613}, /*  2:                    END reduce 202 */
  { 102,   0, 188}, /*  3:                   WHEN shift  188 */
  { 107,   0, 186}, /*  4:              case_else shift  186 */
/* State 186 */
  {  33,   0, 187}, /*  1:                    END shift  187 */
/* State 188 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 189}, /* 26:                   expr shift  189 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 189 */
  {  81,   0, 134}, /*  1:                 RSHIFT shift  134 */
  {   4,   0, 106}, /*  2:                    AND shift  106 */
  {  56,   0, 156}, /*  3:                     IS shift  156 */
  {  57,   0, 155}, /*  4:                 ISNULL shift  155 */
  {  85,   2, 149}, /*  5:                  SLASH shift  149 */
  {  59,   0, 120}, /*  6:                     LE shift  120 */
  {  87,   8, 147}, /*  7:                   STAR shift  147 */
  {  60,   0, 136}, /*  8:                   LIKE shift  136 */
  {  35,  18, 126}, /*  9:                     EQ shift  126 */
  {  63,  20, 132}, /* 10:                 LSHIFT shift  132 */
  {  91,  22, 190}, /* 11:                   THEN shift  190 */
  {  65,  23, 145}, /* 12:                  MINUS shift  145 */
  {  66,   0, 124}, /* 13:                     NE shift  124 */
  {  67,   0, 138}, /* 14:                    NOT shift  138 */
  {  68,   0, 160}, /* 15:                NOTNULL shift  160 */
  {  42,   0, 122}, /* 16:                     GE shift  122 */
  {  43,   0, 141}, /* 17:                   GLOB shift  141 */
  {   8,   0, 161}, /* 18:                BETWEEN shift  161 */
  {  72,  25, 114}, /* 19:                     OR shift  114 */
  {   9,   0, 128}, /* 20:                 BITAND shift  128 */
  {  74,  26, 143}, /* 21:                   PLUS shift  143 */
  {  64,   0, 116}, /* 22:                     LT shift  116 */
  {  11,   0, 130}, /* 23:                  BITOR shift  130 */
  {  77,  27, 151}, /* 24:                    REM shift  151 */
  {  45,   0, 118}, /* 25:                     GT shift  118 */
  {  20,   0, 153}, /* 26:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 27:                     IN shift  165 */
/* State 190 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 191}, /* 26:                   expr shift  191 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 191 */
  {   4,   0, 106}, /*  1:                    AND shift  106 */
  {  59,   0, 120}, /*  2:                     LE shift  120 */
  {   8,   0, 161}, /*  3:                BETWEEN shift  161 */
  {  81,   0, 134}, /*  4:                 RSHIFT shift  134 */
  {  56,   1, 156}, /*  5:                     IS shift  156 */
  {  57,   0, 155}, /*  6:                 ISNULL shift  155 */
  {  35,  11, 126}, /*  7:                     EQ shift  126 */
  {  85,   2, 149}, /*  8:                  SLASH shift  149 */
  {  60,   3, 136}, /*  9:                   LIKE shift  136 */
  {  87,   7, 147}, /* 10:                   STAR shift  147 */
  {   9,   0, 128}, /* 11:                 BITAND shift  128 */
  {  63,  19, 132}, /* 12:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 13:                     LT shift  116 */
  {  65,   0, 145}, /* 14:                  MINUS shift  145 */
  {  66,   0, 124}, /* 15:                     NE shift  124 */
  {  67,   0, 138}, /* 16:                    NOT shift  138 */
  {  68,  22, 160}, /* 17:                NOTNULL shift  160 */
  {  43,   0, 141}, /* 18:                   GLOB shift  141 */
  {  11,   0, 130}, /* 19:                  BITOR shift  130 */
  {  45,   0, 118}, /* 20:                     GT shift  118 */
  {  72,  24, 114}, /* 21:                     OR shift  114 */
  {  42,   0, 122}, /* 22:                     GE shift  122 */
  {  74,   0, 143}, /* 23:                   PLUS shift  143 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 25:                     IN shift  165 */
  {  77,   0, 151}, /* 26:                    REM shift  151 */
/* State 192 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 193}, /* 26:                   expr shift  193 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 193 */
  {  81,   0, 134}, /*  1:                 RSHIFT shift  134 */
  {   4,   0, 106}, /*  2:                    AND shift  106 */
  {  56,   0, 156}, /*  3:                     IS shift  156 */
  {  57,   0, 155}, /*  4:                 ISNULL shift  155 */
  {  85,   2, 149}, /*  5:                  SLASH shift  149 */
  {  59,   0, 120}, /*  6:                     LE shift  120 */
  {  87,   8, 147}, /*  7:                   STAR shift  147 */
  {  60,  18, 136}, /*  8:                   LIKE shift  136 */
  {  35,  20, 126}, /*  9:                     EQ shift  126 */
  {  63,  22, 132}, /* 10:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 11:                     LT shift  116 */
  {  65,  23, 145}, /* 12:                  MINUS shift  145 */
  {  66,   0, 124}, /* 13:                     NE shift  124 */
  {  67,   0, 138}, /* 14:                    NOT shift  138 */
  {  68,   0, 160}, /* 15:                NOTNULL shift  160 */
  {  42,   0, 122}, /* 16:                     GE shift  122 */
  {  43,   0, 141}, /* 17:                   GLOB shift  141 */
  {  33,   0, 612}, /* 18:                    END reduce 201 */
  {  72,  25, 114}, /* 19:                     OR shift  114 */
  {   8,   0, 161}, /* 20:                BETWEEN shift  161 */
  {  74,  26, 143}, /* 21:                   PLUS shift  143 */
  {   9,   0, 128}, /* 22:                 BITAND shift  128 */
  {  11,   0, 130}, /* 23:                  BITOR shift  130 */
  {  77,  27, 151}, /* 24:                    REM shift  151 */
  {  45,   0, 118}, /* 25:                     GT shift  118 */
  {  20,   0, 153}, /* 26:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 27:                     IN shift  165 */
/* State 194 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 195}, /* 26:                   expr shift  195 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 195 */
  {  81,   0, 134}, /*  1:                 RSHIFT shift  134 */
  {   4,   0, 106}, /*  2:                    AND shift  106 */
  {  56,   0, 156}, /*  3:                     IS shift  156 */
  {  57,   0, 155}, /*  4:                 ISNULL shift  155 */
  {  85,   2, 149}, /*  5:                  SLASH shift  149 */
  {  59,   0, 120}, /*  6:                     LE shift  120 */
  {  87,   8, 147}, /*  7:                   STAR shift  147 */
  {  60,   0, 136}, /*  8:                   LIKE shift  136 */
  {  35,  18, 126}, /*  9:                     EQ shift  126 */
  {  63,  20, 132}, /* 10:                 LSHIFT shift  132 */
  {  91,  22, 196}, /* 11:                   THEN shift  196 */
  {  65,  23, 145}, /* 12:                  MINUS shift  145 */
  {  66,   0, 124}, /* 13:                     NE shift  124 */
  {  67,   0, 138}, /* 14:                    NOT shift  138 */
  {  68,   0, 160}, /* 15:                NOTNULL shift  160 */
  {  42,   0, 122}, /* 16:                     GE shift  122 */
  {  43,   0, 141}, /* 17:                   GLOB shift  141 */
  {   8,   0, 161}, /* 18:                BETWEEN shift  161 */
  {  72,  25, 114}, /* 19:                     OR shift  114 */
  {   9,   0, 128}, /* 20:                 BITAND shift  128 */
  {  74,  26, 143}, /* 21:                   PLUS shift  143 */
  {  64,   0, 116}, /* 22:                     LT shift  116 */
  {  11,   0, 130}, /* 23:                  BITOR shift  130 */
  {  77,  27, 151}, /* 24:                    REM shift  151 */
  {  45,   0, 118}, /* 25:                     GT shift  118 */
  {  20,   0, 153}, /* 26:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 27:                     IN shift  165 */
/* State 196 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 197}, /* 26:                   expr shift  197 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 197 */
  {   4,   0, 106}, /*  1:                    AND shift  106 */
  {  59,   0, 120}, /*  2:                     LE shift  120 */
  {   8,   0, 161}, /*  3:                BETWEEN shift  161 */
  {  81,   0, 134}, /*  4:                 RSHIFT shift  134 */
  {  56,   1, 156}, /*  5:                     IS shift  156 */
  {  57,   0, 155}, /*  6:                 ISNULL shift  155 */
  {  35,  11, 126}, /*  7:                     EQ shift  126 */
  {  85,   2, 149}, /*  8:                  SLASH shift  149 */
  {  60,   3, 136}, /*  9:                   LIKE shift  136 */
  {  87,   7, 147}, /* 10:                   STAR shift  147 */
  {   9,   0, 128}, /* 11:                 BITAND shift  128 */
  {  63,  19, 132}, /* 12:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 13:                     LT shift  116 */
  {  65,   0, 145}, /* 14:                  MINUS shift  145 */
  {  66,   0, 124}, /* 15:                     NE shift  124 */
  {  67,   0, 138}, /* 16:                    NOT shift  138 */
  {  68,  22, 160}, /* 17:                NOTNULL shift  160 */
  {  43,   0, 141}, /* 18:                   GLOB shift  141 */
  {  11,   0, 130}, /* 19:                  BITOR shift  130 */
  {  45,   0, 118}, /* 20:                     GT shift  118 */
  {  72,  24, 114}, /* 21:                     OR shift  114 */
  {  42,   0, 122}, /* 22:                     GE shift  122 */
  {  74,   0, 143}, /* 23:                   PLUS shift  143 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 25:                     IN shift  165 */
  {  77,   0, 151}, /* 26:                    REM shift  151 */
/* State 198 */
  {  80,   0, 199}, /*  1:                     RP shift  199 */
  {  17,   0, 200}, /*  2:                  COMMA shift  200 */
/* State 200 */
  {   1,   0,  19}, /*  1:                  ABORT shift  19 */
  {  69,   1, 107}, /*  2:                   NULL shift  107 */
  {  70,   0,  33}, /*  3:                 OFFSET shift  33 */
  {  37,   0,  28}, /*  4:                EXPLAIN shift  28 */
  {  38,   0,  29}, /*  5:                   FAIL shift  29 */
  {  39,   0, 112}, /*  6:                  FLOAT shift  112 */
  {  74,   9, 180}, /*  7:                   PLUS shift  180 */
  {  75,  10,  34}, /*  8:                 PRAGMA shift  34 */
  {   6,   0,  20}, /*  9:                    ASC shift  20 */
  {   7,   0,  21}, /* 10:                  BEGIN shift  21 */
  {  78,  12,  35}, /* 11:                REPLACE shift  35 */
  {  10,   0, 176}, /* 12:                 BITNOT shift  176 */
  {  13,   0, 182}, /* 13:                   CASE shift  182 */
  {  47,  13,  75}, /* 14:                     ID shift  75 */
  {  48,   0,  31}, /* 15:                 IGNORE shift  31 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  {  90,   0,  36}, /* 17:                   TEMP shift  36 */
  {  23,   0,  24}, /* 18:                   COPY shift  24 */
  {  62,  26,  79}, /* 19:                     LP shift  79 */
  {  53,   0, 111}, /* 20:                INTEGER shift  111 */
  {  88,   0,  78}, /* 21:                 STRING shift  78 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  { 124,  17, 173}, /* 23:                   expr shift  173 */
  { 125,  18, 201}, /* 24:               expritem shift  201 */
  {  58,   0,  32}, /* 25:                    KEY shift  32 */
  {  28,   0,  26}, /* 26:                   DESC shift  26 */
  {  65,   0, 178}, /* 27:                  MINUS shift  178 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  { 130,  19,  77}, /* 29:                     id shift  77 */
  { 131,   0, 108}, /* 30:                    ids shift  108 */
  {  67,  33, 174}, /* 31:                    NOT shift  174 */
  {  99,  27,  37}, /* 32:                 VACUUM shift  37 */
  {  33,   0,  27}, /* 33:                    END shift  27 */
  { 101,  31,  38}, /* 34:                   VIEW shift  38 */
/* State 203 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 204}, /* 26:                   expr shift  204 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 204 */
  {  50,   0, 165}, /*  1:                     IN shift  165 */
  {   8,   0, 161}, /*  2:                BETWEEN shift  161 */
  {  74,   1, 143}, /*  3:                   PLUS shift  143 */
  {  57,   5, 155}, /*  4:                 ISNULL shift  155 */
  {   9,   0, 128}, /*  5:                 BITAND shift  128 */
  {  77,   0, 151}, /*  6:                    REM shift  151 */
  {  35,   8, 126}, /*  7:                     EQ shift  126 */
  {  11,   0, 130}, /*  8:                  BITOR shift  130 */
  {  56,   2, 156}, /*  9:                     IS shift  156 */
  {  81,   4, 134}, /* 10:                 RSHIFT shift  134 */
  {  63,   0, 132}, /* 11:                 LSHIFT shift  132 */
  {  59,   7, 120}, /* 12:                     LE shift  120 */
  {  60,   0, 136}, /* 13:                   LIKE shift  136 */
  {  85,   0, 149}, /* 14:                  SLASH shift  149 */
  {  42,   0, 122}, /* 15:                     GE shift  122 */
  {  87,  11, 147}, /* 16:                   STAR shift  147 */
  {  64,   0, 116}, /* 17:                     LT shift  116 */
  {  65,   0, 145}, /* 18:                  MINUS shift  145 */
  {  66,  15, 124}, /* 19:                     NE shift  124 */
  {  67,  23, 138}, /* 20:                    NOT shift  138 */
  {  68,  24, 160}, /* 21:                NOTNULL shift  160 */
  {  45,   0, 118}, /* 22:                     GT shift  118 */
  {  43,   0, 141}, /* 23:                   GLOB shift  141 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
/* State 206 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 207}, /* 26:                   expr shift  207 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 207 */
  {   4,   0, 208}, /*  1:                    AND shift  208 */
  {  59,   0, 120}, /*  2:                     LE shift  120 */
  {   8,   0, 161}, /*  3:                BETWEEN shift  161 */
  {  81,   0, 134}, /*  4:                 RSHIFT shift  134 */
  {  56,   1, 156}, /*  5:                     IS shift  156 */
  {  57,   0, 155}, /*  6:                 ISNULL shift  155 */
  {  35,  11, 126}, /*  7:                     EQ shift  126 */
  {  85,   2, 149}, /*  8:                  SLASH shift  149 */
  {  60,   3, 136}, /*  9:                   LIKE shift  136 */
  {  87,   7, 147}, /* 10:                   STAR shift  147 */
  {   9,   0, 128}, /* 11:                 BITAND shift  128 */
  {  63,  19, 132}, /* 12:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 13:                     LT shift  116 */
  {  65,   0, 145}, /* 14:                  MINUS shift  145 */
  {  66,   0, 124}, /* 15:                     NE shift  124 */
  {  67,   0, 138}, /* 16:                    NOT shift  138 */
  {  68,  22, 160}, /* 17:                NOTNULL shift  160 */
  {  43,   0, 141}, /* 18:                   GLOB shift  141 */
  {  11,   0, 130}, /* 19:                  BITOR shift  130 */
  {  45,   0, 118}, /* 20:                     GT shift  118 */
  {  72,  24, 114}, /* 21:                     OR shift  114 */
  {  42,   0, 122}, /* 22:                     GE shift  122 */
  {  74,   0, 143}, /* 23:                   PLUS shift  143 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 25:                     IN shift  165 */
  {  77,   0, 151}, /* 26:                    REM shift  151 */
/* State 208 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 209}, /* 26:                   expr shift  209 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 209 */
  {  50,   0, 165}, /*  1:                     IN shift  165 */
  {   8,   0, 161}, /*  2:                BETWEEN shift  161 */
  {  74,   1, 143}, /*  3:                   PLUS shift  143 */
  {  57,   5, 155}, /*  4:                 ISNULL shift  155 */
  {   9,   0, 128}, /*  5:                 BITAND shift  128 */
  {  77,   0, 151}, /*  6:                    REM shift  151 */
  {  35,   8, 126}, /*  7:                     EQ shift  126 */
  {  11,   0, 130}, /*  8:                  BITOR shift  130 */
  {  56,   2, 156}, /*  9:                     IS shift  156 */
  {  81,   4, 134}, /* 10:                 RSHIFT shift  134 */
  {  63,   0, 132}, /* 11:                 LSHIFT shift  132 */
  {  59,   7, 120}, /* 12:                     LE shift  120 */
  {  60,   0, 136}, /* 13:                   LIKE shift  136 */
  {  85,   0, 149}, /* 14:                  SLASH shift  149 */
  {  42,   0, 122}, /* 15:                     GE shift  122 */
  {  87,  11, 147}, /* 16:                   STAR shift  147 */
  {  64,   0, 116}, /* 17:                     LT shift  116 */
  {  65,   0, 145}, /* 18:                  MINUS shift  145 */
  {  66,  15, 124}, /* 19:                     NE shift  124 */
  {  67,  23, 138}, /* 20:                    NOT shift  138 */
  {  68,  24, 160}, /* 21:                NOTNULL shift  160 */
  {  45,   0, 118}, /* 22:                     GT shift  118 */
  {  43,   0, 141}, /* 23:                   GLOB shift  141 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
/* State 210 */
  {  62,   0, 211}, /*  1:                     LP shift  211 */
/* State 211 */
  {  38,   0,  29}, /*  1:                   FAIL shift  29 */
  { 153,   4, 212}, /*  2:                 select shift  212 */
  {  78,   0,  35}, /*  3:                REPLACE shift  35 */
  {  39,   5, 112}, /*  4:                  FLOAT shift  112 */
  {   1,   0,  19}, /*  5:                  ABORT shift  19 */
  {   6,   0,  20}, /*  6:                    ASC shift  20 */
  {  82,   6,  84}, /*  7:                 SELECT shift  84 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  48,  19,  31}, /*  9:                 IGNORE shift  31 */
  {  47,   0,  75}, /* 10:                     ID shift  75 */
  { 124,   9, 173}, /* 11:                   expr shift  173 */
  { 125,   0, 202}, /* 12:               expritem shift  202 */
  { 126,  20, 214}, /* 13:               exprlist shift  214 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  90,   0,  36}, /* 15:                   TEMP shift  36 */
  {  53,  23, 111}, /* 16:                INTEGER shift  111 */
  { 130,   0,  77}, /* 17:                     id shift  77 */
  { 131,   0, 108}, /* 18:                    ids shift  108 */
  {  10,   0, 176}, /* 19:                 BITNOT shift  176 */
  {  88,   0,  78}, /* 20:                 STRING shift  78 */
  {  58,   0,  32}, /* 21:                    KEY shift  32 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  15,   0,  22}, /* 23:                CLUSTER shift  22 */
  {  99,  27,  37}, /* 24:                 VACUUM shift  37 */
  {  62,   0,  79}, /* 25:                     LP shift  79 */
  { 101,   0,  38}, /* 26:                   VIEW shift  38 */
  {  23,   0,  24}, /* 27:                   COPY shift  24 */
  {  65,  31, 178}, /* 28:                  MINUS shift  178 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  67,   0, 174}, /* 30:                    NOT shift  174 */
  {  27,   0,  25}, /* 31:             DELIMITERS shift  25 */
  { 145,  35,  80}, /* 32:              oneselect shift  80 */
  {  70,   0,  33}, /* 33:                 OFFSET shift  33 */
  {  33,   0,  27}, /* 34:                    END shift  27 */
  {  69,   0, 107}, /* 35:                   NULL shift  107 */
  {  37,   0,  28}, /* 36:                EXPLAIN shift  28 */
  {  74,   0, 180}, /* 37:                   PLUS shift  180 */
  {  75,  36,  34}, /* 38:                 PRAGMA shift  34 */
/* State 212 */
  {  95,   4, 168}, /*  1:                  UNION shift  168 */
  {  36,   0, 171}, /*  2:                 EXCEPT shift  171 */
  { 142,   0,  82}, /*  3:         multiselect_op shift  82 */
  {  80,   0, 213}, /*  4:                     RP shift  213 */
  {  54,   0, 170}, /*  5:              INTERSECT shift  170 */
/* State 214 */
  {  80,   0, 215}, /*  1:                     RP shift  215 */
  {  17,   0, 200}, /*  2:                  COMMA shift  200 */
/* State 216 */
  { 159,   3, 217}, /*  1:              sortorder shift  217 */
  {  28,   0,  70}, /*  2:                   DESC shift  70 */
  {   6,   0,  69}, /*  3:                    ASC shift  69 */
/* State 218 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 219}, /* 26:                   expr shift  219 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 219 */
  {   4,   0, 106}, /*  1:                    AND shift  106 */
  {  59,   0, 120}, /*  2:                     LE shift  120 */
  {   8,   0, 161}, /*  3:                BETWEEN shift  161 */
  {  81,   0, 134}, /*  4:                 RSHIFT shift  134 */
  {  56,   1, 156}, /*  5:                     IS shift  156 */
  {  57,   0, 155}, /*  6:                 ISNULL shift  155 */
  {  35,  11, 126}, /*  7:                     EQ shift  126 */
  {  85,   2, 149}, /*  8:                  SLASH shift  149 */
  {  60,   3, 136}, /*  9:                   LIKE shift  136 */
  {  87,   7, 147}, /* 10:                   STAR shift  147 */
  {   9,   0, 128}, /* 11:                 BITAND shift  128 */
  {  63,  19, 132}, /* 12:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 13:                     LT shift  116 */
  {  65,   0, 145}, /* 14:                  MINUS shift  145 */
  {  66,   0, 124}, /* 15:                     NE shift  124 */
  {  67,   0, 138}, /* 16:                    NOT shift  138 */
  {  68,  22, 160}, /* 17:                NOTNULL shift  160 */
  {  43,   0, 141}, /* 18:                   GLOB shift  141 */
  {  11,   0, 130}, /* 19:                  BITOR shift  130 */
  {  45,   0, 118}, /* 20:                     GT shift  118 */
  {  72,  24, 114}, /* 21:                     OR shift  114 */
  {  42,   0, 122}, /* 22:                     GE shift  122 */
  {  74,   0, 143}, /* 23:                   PLUS shift  143 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 25:                     IN shift  165 */
  {  77,   0, 151}, /* 26:                    REM shift  151 */
/* State 220 */
  {  12,   0, 221}, /*  1:                     BY shift  221 */
/* State 221 */
  {  70,   0,  33}, /*  1:                 OFFSET shift  33 */
  {   1,   0,  19}, /*  2:                  ABORT shift  19 */
  {  37,   0,  28}, /*  3:                EXPLAIN shift  28 */
  {  38,   0,  29}, /*  4:                   FAIL shift  29 */
  {  74,  10, 180}, /*  5:                   PLUS shift  180 */
  {  75,   0,  34}, /*  6:                 PRAGMA shift  34 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  78,   0,  35}, /*  9:                REPLACE shift  35 */
  {  39,   0, 112}, /* 10:                  FLOAT shift  112 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  13,   0, 182}, /* 12:                   CASE shift  182 */
  {  47,   0,  75}, /* 13:                     ID shift  75 */
  {  48,  12,  31}, /* 14:                 IGNORE shift  31 */
  {  53,   0, 111}, /* 15:                INTEGER shift  111 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  {  90,   0,  36}, /* 17:                   TEMP shift  36 */
  {  21,   0,  23}, /* 18:               CONFLICT shift  23 */
  {  88,  15,  78}, /* 19:                 STRING shift  78 */
  { 124,   0, 173}, /* 20:                   expr shift  173 */
  { 125,  17, 202}, /* 21:               expritem shift  202 */
  { 126,  18, 222}, /* 22:               exprlist shift  222 */
  {  23,   0,  24}, /* 23:                   COPY shift  24 */
  {  58,  23,  32}, /* 24:                    KEY shift  32 */
  {  27,   0,  25}, /* 25:             DELIMITERS shift  25 */
  { 130,   0,  77}, /* 26:                     id shift  77 */
  { 131,   0, 108}, /* 27:                    ids shift  108 */
  {  62,  25,  79}, /* 28:                     LP shift  79 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  99,   0,  37}, /* 30:                 VACUUM shift  37 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 101,   0,  38}, /* 32:                   VIEW shift  38 */
  {  67,   0, 174}, /* 33:                    NOT shift  174 */
  {  33,   0,  27}, /* 34:                    END shift  27 */
  {  69,   0, 107}, /* 35:                   NULL shift  107 */
/* State 222 */
  {  17,   0, 200}, /*  1:                  COMMA shift  200 */
/* State 223 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 224}, /* 26:                   expr shift  224 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 224 */
  {   4,   0, 106}, /*  1:                    AND shift  106 */
  {  59,   0, 120}, /*  2:                     LE shift  120 */
  {   8,   0, 161}, /*  3:                BETWEEN shift  161 */
  {  81,   0, 134}, /*  4:                 RSHIFT shift  134 */
  {  56,   1, 156}, /*  5:                     IS shift  156 */
  {  57,   0, 155}, /*  6:                 ISNULL shift  155 */
  {  35,  11, 126}, /*  7:                     EQ shift  126 */
  {  85,   2, 149}, /*  8:                  SLASH shift  149 */
  {  60,   3, 136}, /*  9:                   LIKE shift  136 */
  {  87,   7, 147}, /* 10:                   STAR shift  147 */
  {   9,   0, 128}, /* 11:                 BITAND shift  128 */
  {  63,  19, 132}, /* 12:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 13:                     LT shift  116 */
  {  65,   0, 145}, /* 14:                  MINUS shift  145 */
  {  66,   0, 124}, /* 15:                     NE shift  124 */
  {  67,   0, 138}, /* 16:                    NOT shift  138 */
  {  68,  22, 160}, /* 17:                NOTNULL shift  160 */
  {  43,   0, 141}, /* 18:                   GLOB shift  141 */
  {  11,   0, 130}, /* 19:                  BITOR shift  130 */
  {  45,   0, 118}, /* 20:                     GT shift  118 */
  {  72,  24, 114}, /* 21:                     OR shift  114 */
  {  42,   0, 122}, /* 22:                     GE shift  122 */
  {  74,   0, 143}, /* 23:                   PLUS shift  143 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 25:                     IN shift  165 */
  {  77,   0, 151}, /* 26:                    REM shift  151 */
/* State 226 */
  { 160,   2, 229}, /*  1:             stl_prefix shift  229 */
  { 154,   0, 227}, /*  2:             seltablist shift  227 */
/* State 227 */
  {  17,   0, 228}, /*  1:                  COMMA shift  228 */
/* State 229 */
  {  48,   0,  31}, /*  1:                 IGNORE shift  31 */
  {   1,   0,  19}, /*  2:                  ABORT shift  19 */
  {  75,   9,  34}, /*  3:                 PRAGMA shift  34 */
  {  99,   3,  37}, /*  4:                 VACUUM shift  37 */
  {  28,   0,  26}, /*  5:                   DESC shift  26 */
  { 101,   0,  38}, /*  6:                   VIEW shift  38 */
  {  78,  13,  35}, /*  7:                REPLACE shift  35 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  27,   0,  25}, /*  9:             DELIMITERS shift  25 */
  {  33,   0,  27}, /* 10:                    END shift  27 */
  { 130,  18,  39}, /* 11:                     id shift  39 */
  { 131,   0, 230}, /* 12:                    ids shift  230 */
  {   6,   0,  20}, /* 13:                    ASC shift  20 */
  {  37,   0,  28}, /* 14:                EXPLAIN shift  28 */
  {  62,  20, 234}, /* 15:                     LP shift  234 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  {  88,   0,  40}, /* 17:                 STRING shift  40 */
  {  58,   0,  32}, /* 18:                    KEY shift  32 */
  {  90,   0,  36}, /* 19:                   TEMP shift  36 */
  {  38,   0,  29}, /* 20:                   FAIL shift  29 */
  {  23,   0,  24}, /* 21:                   COPY shift  24 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  70,   0,  33}, /* 23:                 OFFSET shift  33 */
  {  47,  21,  30}, /* 24:                     ID shift  30 */
/* State 230 */
  { 104,   0, 232}, /*  1:                     as shift  232 */
  {  54,   0, 525}, /*  2:              INTERSECT reduce 114 */
  {  80,   2, 525}, /*  3:                     RP reduce 114 */
  {  17,   0, 525}, /*  4:                  COMMA reduce 114 */
  {  95,   4, 525}, /*  5:                  UNION reduce 114 */
  {  83,   7, 525}, /*  6:                   SEMI reduce 114 */
  {  44,  12, 525}, /*  7:                  GROUP reduce 114 */
  {  46,   0, 525}, /*  8:                 HAVING reduce 114 */
  {  73,   0, 525}, /*  9:                  ORDER reduce 114 */
  {  61,   0, 525}, /* 10:                  LIMIT reduce 114 */
  {  36,   0, 525}, /* 11:                 EXCEPT reduce 114 */
  {   5,   0, 231}, /* 12:                     AS shift  231 */
  { 103,   0, 525}, /* 13:                  WHERE reduce 114 */
/* State 232 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 233}, /* 17:                    ids shift  233 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 234 */
  { 153,   0, 235}, /*  1:                 select shift  235 */
  { 145,   3,  80}, /*  2:              oneselect shift  80 */
  {  82,   0,  84}, /*  3:                 SELECT shift  84 */
/* State 235 */
  {  95,   4, 168}, /*  1:                  UNION shift  168 */
  {  36,   0, 171}, /*  2:                 EXCEPT shift  171 */
  { 142,   0,  82}, /*  3:         multiselect_op shift  82 */
  {  80,   0, 236}, /*  4:                     RP shift  236 */
  {  54,   0, 170}, /*  5:              INTERSECT shift  170 */
/* State 236 */
  { 104,   0, 237}, /*  1:                     as shift  237 */
  {  54,   0, 527}, /*  2:              INTERSECT reduce 116 */
  {  80,   2, 527}, /*  3:                     RP reduce 116 */
  {  17,   0, 527}, /*  4:                  COMMA reduce 116 */
  {  95,   4, 527}, /*  5:                  UNION reduce 116 */
  {  83,   7, 527}, /*  6:                   SEMI reduce 116 */
  {  44,  12, 527}, /*  7:                  GROUP reduce 116 */
  {  46,   0, 527}, /*  8:                 HAVING reduce 116 */
  {  73,   0, 527}, /*  9:                  ORDER reduce 116 */
  {  61,   0, 527}, /* 10:                  LIMIT reduce 116 */
  {  36,   0, 527}, /* 11:                 EXCEPT reduce 116 */
  {   5,   0, 231}, /* 12:                     AS shift  231 */
  { 103,   0, 527}, /* 13:                  WHERE reduce 116 */
/* State 237 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 238}, /* 17:                    ids shift  238 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 239 */
  {   1,   0,  19}, /*  1:                  ABORT shift  19 */
  {  69,   1, 107}, /*  2:                   NULL shift  107 */
  {  70,   0,  33}, /*  3:                 OFFSET shift  33 */
  {  37,   0,  28}, /*  4:                EXPLAIN shift  28 */
  {  38,   0,  29}, /*  5:                   FAIL shift  29 */
  {  39,   0, 112}, /*  6:                  FLOAT shift  112 */
  {  74,   9, 180}, /*  7:                   PLUS shift  180 */
  {  75,  10,  34}, /*  8:                 PRAGMA shift  34 */
  {   6,   0,  20}, /*  9:                    ASC shift  20 */
  {   7,   0,  21}, /* 10:                  BEGIN shift  21 */
  {  78,  12,  35}, /* 11:                REPLACE shift  35 */
  {  10,   0, 176}, /* 12:                 BITNOT shift  176 */
  {  13,   0, 182}, /* 13:                   CASE shift  182 */
  {  47,  13,  75}, /* 14:                     ID shift  75 */
  {  48,   0,  31}, /* 15:                 IGNORE shift  31 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 17:                INTEGER shift  111 */
  {  90,   0,  36}, /* 18:                   TEMP shift  36 */
  {  62,  26,  79}, /* 19:                     LP shift  79 */
  {  87,  17, 243}, /* 20:                   STAR shift  243 */
  {  88,   0,  78}, /* 21:                 STRING shift  78 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  { 124,  18, 240}, /* 23:                   expr shift  240 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  58,   0,  32}, /* 25:                    KEY shift  32 */
  {  28,   0,  26}, /* 26:                   DESC shift  26 */
  {  65,   0, 178}, /* 27:                  MINUS shift  178 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  { 130,  19,  77}, /* 29:                     id shift  77 */
  { 131,   0, 108}, /* 30:                    ids shift  108 */
  {  67,  33, 174}, /* 31:                    NOT shift  174 */
  {  99,  27,  37}, /* 32:                 VACUUM shift  37 */
  {  33,   0,  27}, /* 33:                    END shift  27 */
  { 101,  31,  38}, /* 34:                   VIEW shift  38 */
/* State 240 */
  {  60,   0, 136}, /*  1:                   LIKE shift  136 */
  {   4,   0, 106}, /*  2:                    AND shift  106 */
  {  35,  17, 126}, /*  3:                     EQ shift  126 */
  {  63,   0, 132}, /*  4:                 LSHIFT shift  132 */
  {  64,   2, 116}, /*  5:                     LT shift  116 */
  {  65,   3, 145}, /*  6:                  MINUS shift  145 */
  {  66,   0, 124}, /*  7:                     NE shift  124 */
  {  67,   0, 138}, /*  8:                    NOT shift  138 */
  {  68,  19, 160}, /*  9:                NOTNULL shift  160 */
  {   9,   0, 128}, /* 10:                 BITAND shift  128 */
  {  40,   0, 517}, /* 11:                   FROM reduce 106 */
  {  11,   0, 130}, /* 12:                  BITOR shift  130 */
  {  72,  20, 114}, /* 13:                     OR shift  114 */
  {  43,   0, 141}, /* 14:                   GLOB shift  141 */
  { 104,  23, 241}, /* 15:                     as shift  241 */
  {  45,   0, 118}, /* 16:                     GT shift  118 */
  {   5,   0, 231}, /* 17:                     AS shift  231 */
  {  77,  24, 151}, /* 18:                    REM shift  151 */
  {   8,   0, 161}, /* 19:                BETWEEN shift  161 */
  {  42,   0, 122}, /* 20:                     GE shift  122 */
  {  50,  25, 165}, /* 21:                     IN shift  165 */
  {  81,   0, 134}, /* 22:                 RSHIFT shift  134 */
  {  74,   0, 143}, /* 23:                   PLUS shift  143 */
  {  17,   0, 517}, /* 24:                  COMMA reduce 106 */
  {  20,   0, 153}, /* 25:                 CONCAT shift  153 */
  {  85,   0, 149}, /* 26:                  SLASH shift  149 */
  {  56,   0, 156}, /* 27:                     IS shift  156 */
  {  87,  29, 147}, /* 28:                   STAR shift  147 */
  {  57,   0, 155}, /* 29:                 ISNULL shift  155 */
  {  59,   0, 120}, /* 30:                     LE shift  120 */
/* State 241 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 242}, /* 17:                    ids shift  242 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 247 */
  {  81,   0, 134}, /*  1:                 RSHIFT shift  134 */
  {   4,   0, 106}, /*  2:                    AND shift  106 */
  {  56,   0, 156}, /*  3:                     IS shift  156 */
  {  57,   0, 155}, /*  4:                 ISNULL shift  155 */
  {  85,   2, 149}, /*  5:                  SLASH shift  149 */
  {  59,   0, 120}, /*  6:                     LE shift  120 */
  {  87,   8, 147}, /*  7:                   STAR shift  147 */
  {  60,   0, 136}, /*  8:                   LIKE shift  136 */
  {  35,  18, 126}, /*  9:                     EQ shift  126 */
  {  63,  20, 132}, /* 10:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 11:                     LT shift  116 */
  {  65,  22, 145}, /* 12:                  MINUS shift  145 */
  {  66,   0, 124}, /* 13:                     NE shift  124 */
  {  67,   0, 138}, /* 14:                    NOT shift  138 */
  {  68,   0, 160}, /* 15:                NOTNULL shift  160 */
  {  42,   0, 122}, /* 16:                     GE shift  122 */
  {  43,   0, 141}, /* 17:                   GLOB shift  141 */
  {   8,   0, 161}, /* 18:                BETWEEN shift  161 */
  {  72,  23, 114}, /* 19:                     OR shift  114 */
  {   9,   0, 128}, /* 20:                 BITAND shift  128 */
  {  74,  25, 143}, /* 21:                   PLUS shift  143 */
  {  11,   0, 130}, /* 22:                  BITOR shift  130 */
  {  45,   0, 118}, /* 23:                     GT shift  118 */
  {  77,  26, 151}, /* 24:                    REM shift  151 */
  {  20,   0, 153}, /* 25:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 26:                     IN shift  165 */
  {  80,   0, 248}, /* 27:                     RP shift  248 */
/* State 249 */
  {  80,   0, 250}, /*  1:                     RP shift  250 */
  {  17,   0, 200}, /*  2:                  COMMA shift  200 */
/* State 251 */
  {  80,   0, 252}, /*  1:                     RP shift  252 */
/* State 253 */
  {  81,   0, 134}, /*  1:                 RSHIFT shift  134 */
  {   4,   0, 106}, /*  2:                    AND shift  106 */
  {  56,   0, 156}, /*  3:                     IS shift  156 */
  {  57,   0, 155}, /*  4:                 ISNULL shift  155 */
  {  85,   2, 149}, /*  5:                  SLASH shift  149 */
  {  59,   0, 120}, /*  6:                     LE shift  120 */
  {  87,   8, 147}, /*  7:                   STAR shift  147 */
  {  60,   0, 136}, /*  8:                   LIKE shift  136 */
  {  35,  18, 126}, /*  9:                     EQ shift  126 */
  {  63,  20, 132}, /* 10:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 11:                     LT shift  116 */
  {  65,  22, 145}, /* 12:                  MINUS shift  145 */
  {  66,   0, 124}, /* 13:                     NE shift  124 */
  {  67,   0, 138}, /* 14:                    NOT shift  138 */
  {  68,   0, 160}, /* 15:                NOTNULL shift  160 */
  {  42,   0, 122}, /* 16:                     GE shift  122 */
  {  43,   0, 141}, /* 17:                   GLOB shift  141 */
  {   8,   0, 161}, /* 18:                BETWEEN shift  161 */
  {  72,  23, 114}, /* 19:                     OR shift  114 */
  {   9,   0, 128}, /* 20:                 BITAND shift  128 */
  {  74,  25, 143}, /* 21:                   PLUS shift  143 */
  {  11,   0, 130}, /* 22:                  BITOR shift  130 */
  {  45,   0, 118}, /* 23:                     GT shift  118 */
  {  77,  26, 151}, /* 24:                    REM shift  151 */
  {  20,   0, 153}, /* 25:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 26:                     IN shift  165 */
  {  80,   0, 254}, /* 27:                     RP shift  254 */
/* State 254 */
  { 144,   0, 255}, /*  1:                 onconf shift  255 */
  {  71,   0,   9}, /*  2:                     ON shift  9 */
/* State 257 */
  {  74,   2, 261}, /*  1:                   PLUS shift  261 */
  {  53,   4, 260}, /*  2:                INTEGER shift  260 */
  {  65,   0, 264}, /*  3:                  MINUS shift  264 */
  {  39,   0, 267}, /*  4:                  FLOAT shift  267 */
  {  88,   1, 258}, /*  5:                 STRING shift  258 */
  {  47,   0, 259}, /*  6:                     ID shift  259 */
  {  69,   0, 268}, /*  7:                   NULL shift  268 */
/* State 261 */
  {  39,   0, 263}, /*  1:                  FLOAT shift  263 */
  {  53,   1, 262}, /*  2:                INTEGER shift  262 */
/* State 264 */
  {  39,   0, 266}, /*  1:                  FLOAT shift  266 */
  {  53,   1, 265}, /*  2:                INTEGER shift  265 */
/* State 269 */
  {  48,   0,  31}, /*  1:                 IGNORE shift  31 */
  {   1,   0,  19}, /*  2:                  ABORT shift  19 */
  {  75,   9,  34}, /*  3:                 PRAGMA shift  34 */
  {  99,   3,  37}, /*  4:                 VACUUM shift  37 */
  {  28,   0,  26}, /*  5:                   DESC shift  26 */
  { 101,   0,  38}, /*  6:                   VIEW shift  38 */
  {  78,  13,  35}, /*  7:                REPLACE shift  35 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  27,   0,  25}, /*  9:             DELIMITERS shift  25 */
  {  33,   0,  27}, /* 10:                    END shift  27 */
  { 130,  18,  39}, /* 11:                     id shift  39 */
  { 131,   0, 281}, /* 12:                    ids shift  281 */
  {   6,   0,  20}, /* 13:                    ASC shift  20 */
  {  37,   0,  28}, /* 14:                EXPLAIN shift  28 */
  {  62,  20, 270}, /* 15:                     LP shift  270 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  {  88,   0,  40}, /* 17:                 STRING shift  40 */
  {  58,   0,  32}, /* 18:                    KEY shift  32 */
  {  90,   0,  36}, /* 19:                   TEMP shift  36 */
  {  38,   0,  29}, /* 20:                   FAIL shift  29 */
  {  23,   0,  24}, /* 21:                   COPY shift  24 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  70,   0,  33}, /* 23:                 OFFSET shift  33 */
  {  47,  21,  30}, /* 24:                     ID shift  30 */
/* State 270 */
  { 156,   0, 271}, /*  1:                 signed shift  271 */
  {  65,   4, 279}, /*  2:                  MINUS shift  279 */
  {  74,   0, 277}, /*  3:                   PLUS shift  277 */
  {  53,   0, 276}, /*  4:                INTEGER shift  276 */
/* State 271 */
  {  80,   0, 272}, /*  1:                     RP shift  272 */
  {  17,   0, 273}, /*  2:                  COMMA shift  273 */
/* State 273 */
  { 156,   0, 274}, /*  1:                 signed shift  274 */
  {  65,   4, 279}, /*  2:                  MINUS shift  279 */
  {  74,   0, 277}, /*  3:                   PLUS shift  277 */
  {  53,   0, 276}, /*  4:                INTEGER shift  276 */
/* State 274 */
  {  80,   0, 275}, /*  1:                     RP shift  275 */
/* State 277 */
  {  53,   0, 278}, /*  1:                INTEGER shift  278 */
/* State 279 */
  {  53,   0, 280}, /*  1:                INTEGER shift  280 */
/* State 284 */
  { 161,   3, 307}, /*  1:                  tcons shift  307 */
  {  22,   0, 287}, /*  2:             CONSTRAINT shift  287 */
  {  14,   0, 304}, /*  3:                  CHECK shift  304 */
  {  80,   5, 484}, /*  4:                     RP reduce 73 */
  {  17,   0, 285}, /*  5:                  COMMA shift  285 */
  {  96,   0, 299}, /*  6:                 UNIQUE shift  299 */
  {  76,   0, 289}, /*  7:                PRIMARY shift  289 */
/* State 285 */
  {  96,   4, 299}, /*  1:                 UNIQUE shift  299 */
  { 161,   1, 286}, /*  2:                  tcons shift  286 */
  {  22,   0, 287}, /*  3:             CONSTRAINT shift  287 */
  {  76,   0, 289}, /*  4:                PRIMARY shift  289 */
  {  14,   0, 304}, /*  5:                  CHECK shift  304 */
/* State 287 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 288}, /* 17:                    ids shift  288 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 289 */
  {  58,   0, 290}, /*  1:                    KEY shift  290 */
/* State 290 */
  {  62,   0, 291}, /*  1:                     LP shift  291 */
/* State 291 */
  {  75,   0,  34}, /*  1:                 PRAGMA shift  34 */
  { 101,   5,  38}, /*  2:                   VIEW shift  38 */
  {  27,   0,  25}, /*  3:             DELIMITERS shift  25 */
  {  78,  10,  35}, /*  4:                REPLACE shift  35 */
  {   1,   0,  19}, /*  5:                  ABORT shift  19 */
  { 130,   0,  39}, /*  6:                     id shift  39 */
  { 131,  11, 297}, /*  7:                    ids shift  297 */
  { 132,  12, 298}, /*  8:                idxitem shift  298 */
  { 133,  15, 292}, /*  9:                idxlist shift  292 */
  {  28,   0,  26}, /* 10:                   DESC shift  26 */
  {   6,   0,  20}, /* 11:                    ASC shift  20 */
  {   7,   0,  21}, /* 12:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 13:                EXPLAIN shift  28 */
  {  88,  17,  40}, /* 14:                 STRING shift  40 */
  {  58,  18,  32}, /* 15:                    KEY shift  32 */
  {  90,  19,  36}, /* 16:                   TEMP shift  36 */
  {  38,   0,  29}, /* 17:                   FAIL shift  29 */
  {  33,   0,  27}, /* 18:                    END shift  27 */
  {  15,   0,  22}, /* 19:                CLUSTER shift  22 */
  {  23,   0,  24}, /* 20:                   COPY shift  24 */
  {  70,   0,  33}, /* 21:                 OFFSET shift  33 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  47,   0,  30}, /* 23:                     ID shift  30 */
  {  48,  20,  31}, /* 24:                 IGNORE shift  31 */
  {  99,   0,  37}, /* 25:                 VACUUM shift  37 */
/* State 292 */
  {  80,   0, 293}, /*  1:                     RP shift  293 */
  {  17,   0, 295}, /*  2:                  COMMA shift  295 */
/* State 293 */
  { 144,   0, 294}, /*  1:                 onconf shift  294 */
  {  71,   0,   9}, /*  2:                     ON shift  9 */
/* State 295 */
  {  48,   0,  31}, /*  1:                 IGNORE shift  31 */
  {   1,   0,  19}, /*  2:                  ABORT shift  19 */
  {  75,   9,  34}, /*  3:                 PRAGMA shift  34 */
  {  99,   3,  37}, /*  4:                 VACUUM shift  37 */
  {  28,   0,  26}, /*  5:                   DESC shift  26 */
  { 101,   0,  38}, /*  6:                   VIEW shift  38 */
  {  78,  18,  35}, /*  7:                REPLACE shift  35 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  27,   0,  25}, /*  9:             DELIMITERS shift  25 */
  {  33,   0,  27}, /* 10:                    END shift  27 */
  { 130,  20,  39}, /* 11:                     id shift  39 */
  { 131,   0, 297}, /* 12:                    ids shift  297 */
  { 132,   0, 296}, /* 13:                idxitem shift  296 */
  {  37,   0,  28}, /* 14:                EXPLAIN shift  28 */
  {  38,   0,  29}, /* 15:                   FAIL shift  29 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  {  88,   0,  40}, /* 17:                 STRING shift  40 */
  {   6,   0,  20}, /* 18:                    ASC shift  20 */
  {  90,   0,  36}, /* 19:                   TEMP shift  36 */
  {  58,   0,  32}, /* 20:                    KEY shift  32 */
  {  23,   0,  24}, /* 21:                   COPY shift  24 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  70,   0,  33}, /* 23:                 OFFSET shift  33 */
  {  47,  21,  30}, /* 24:                     ID shift  30 */
/* State 299 */
  {  62,   0, 300}, /*  1:                     LP shift  300 */
/* State 300 */
  {  75,   0,  34}, /*  1:                 PRAGMA shift  34 */
  { 101,   5,  38}, /*  2:                   VIEW shift  38 */
  {  27,   0,  25}, /*  3:             DELIMITERS shift  25 */
  {  78,  10,  35}, /*  4:                REPLACE shift  35 */
  {   1,   0,  19}, /*  5:                  ABORT shift  19 */
  { 130,   0,  39}, /*  6:                     id shift  39 */
  { 131,  11, 297}, /*  7:                    ids shift  297 */
  { 132,  12, 298}, /*  8:                idxitem shift  298 */
  { 133,  15, 301}, /*  9:                idxlist shift  301 */
  {  28,   0,  26}, /* 10:                   DESC shift  26 */
  {   6,   0,  20}, /* 11:                    ASC shift  20 */
  {   7,   0,  21}, /* 12:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 13:                EXPLAIN shift  28 */
  {  88,  17,  40}, /* 14:                 STRING shift  40 */
  {  58,  18,  32}, /* 15:                    KEY shift  32 */
  {  90,  19,  36}, /* 16:                   TEMP shift  36 */
  {  38,   0,  29}, /* 17:                   FAIL shift  29 */
  {  33,   0,  27}, /* 18:                    END shift  27 */
  {  15,   0,  22}, /* 19:                CLUSTER shift  22 */
  {  23,   0,  24}, /* 20:                   COPY shift  24 */
  {  70,   0,  33}, /* 21:                 OFFSET shift  33 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  47,   0,  30}, /* 23:                     ID shift  30 */
  {  48,  20,  31}, /* 24:                 IGNORE shift  31 */
  {  99,   0,  37}, /* 25:                 VACUUM shift  37 */
/* State 301 */
  {  80,   0, 302}, /*  1:                     RP shift  302 */
  {  17,   0, 295}, /*  2:                  COMMA shift  295 */
/* State 302 */
  { 144,   0, 303}, /*  1:                 onconf shift  303 */
  {  71,   0,   9}, /*  2:                     ON shift  9 */
/* State 304 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 305}, /* 26:                   expr shift  305 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 305 */
  {  56,   0, 156}, /*  1:                     IS shift  156 */
  {  85,   3, 149}, /*  2:                  SLASH shift  149 */
  {  57,   0, 155}, /*  3:                 ISNULL shift  155 */
  {  87,   6, 147}, /*  4:                   STAR shift  147 */
  { 144,   7, 306}, /*  5:                 onconf shift  306 */
  {  59,   0, 120}, /*  6:                     LE shift  120 */
  {  60,  14, 136}, /*  7:                   LIKE shift  136 */
  {  63,  20, 132}, /*  8:                 LSHIFT shift  132 */
  {  64,  24, 116}, /*  9:                     LT shift  116 */
  {  65,  25, 145}, /* 10:                  MINUS shift  145 */
  {  66,   0, 124}, /* 11:                     NE shift  124 */
  {  67,  27, 138}, /* 12:                    NOT shift  138 */
  {  68,   0, 160}, /* 13:                NOTNULL shift  160 */
  {   4,   0, 106}, /* 14:                    AND shift  106 */
  {  42,   0, 122}, /* 15:                     GE shift  122 */
  {  71,  28,   9}, /* 16:                     ON shift  9 */
  {  72,   0, 114}, /* 17:                     OR shift  114 */
  {  45,   0, 118}, /* 18:                     GT shift  118 */
  {  74,   0, 143}, /* 19:                   PLUS shift  143 */
  {  35,   0, 126}, /* 20:                     EQ shift  126 */
  {  20,   0, 153}, /* 21:                 CONCAT shift  153 */
  {  77,   0, 151}, /* 22:                    REM shift  151 */
  {  50,   0, 165}, /* 23:                     IN shift  165 */
  {   8,   0, 161}, /* 24:                BETWEEN shift  161 */
  {   9,   0, 128}, /* 25:                 BITAND shift  128 */
  {  81,   0, 134}, /* 26:                 RSHIFT shift  134 */
  {  11,   0, 130}, /* 27:                  BITOR shift  130 */
  {  43,   0, 141}, /* 28:                   GLOB shift  141 */
/* State 310 */
  { 153,   0, 311}, /*  1:                 select shift  311 */
  { 145,   3,  80}, /*  2:              oneselect shift  80 */
  {  82,   0,  84}, /*  3:                 SELECT shift  84 */
/* State 311 */
  {  95,   0, 168}, /*  1:                  UNION shift  168 */
  {  36,   0, 171}, /*  2:                 EXCEPT shift  171 */
  { 142,   0,  82}, /*  3:         multiselect_op shift  82 */
  {  83,   0, 430}, /*  4:                   SEMI reduce 19 */
  {  54,   0, 170}, /*  5:              INTERSECT shift  170 */
/* State 312 */
  {  96,   5, 330}, /*  1:                 UNIQUE shift  330 */
  { 162,   0, 313}, /*  2:                   temp shift  313 */
  {  51,   0, 622}, /*  3:                  INDEX reduce 211 */
  { 101,   0, 317}, /*  4:                   VIEW shift  317 */
  {  89,   0, 428}, /*  5:                  TABLE reduce 17 */
  { 166,   1, 321}, /*  6:             uniqueflag shift  321 */
  {  90,   0, 316}, /*  7:                   TEMP shift  316 */
/* State 313 */
  {  89,   0, 314}, /*  1:                  TABLE shift  314 */
/* State 314 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 315}, /* 17:                    ids shift  315 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 316 */
  {  89,   0, 427}, /*  1:                  TABLE reduce 16 */
/* State 317 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 318}, /* 17:                    ids shift  318 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 318 */
  {   5,   0, 319}, /*  1:                     AS shift  319 */
/* State 319 */
  { 153,   0, 320}, /*  1:                 select shift  320 */
  { 145,   3,  80}, /*  2:              oneselect shift  80 */
  {  82,   0,  84}, /*  3:                 SELECT shift  84 */
/* State 320 */
  {  95,   0, 168}, /*  1:                  UNION shift  168 */
  {  36,   0, 171}, /*  2:                 EXCEPT shift  171 */
  { 142,   0,  82}, /*  3:         multiselect_op shift  82 */
  {  83,   0, 502}, /*  4:                   SEMI reduce 91 */
  {  54,   0, 170}, /*  5:              INTERSECT shift  170 */
/* State 321 */
  {  51,   0, 322}, /*  1:                  INDEX shift  322 */
/* State 322 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 323}, /* 17:                    ids shift  323 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 323 */
  {  71,   0, 324}, /*  1:                     ON shift  324 */
/* State 324 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 325}, /* 17:                    ids shift  325 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 325 */
  {  62,   0, 326}, /*  1:                     LP shift  326 */
/* State 326 */
  {  75,   0,  34}, /*  1:                 PRAGMA shift  34 */
  { 101,   5,  38}, /*  2:                   VIEW shift  38 */
  {  27,   0,  25}, /*  3:             DELIMITERS shift  25 */
  {  78,  10,  35}, /*  4:                REPLACE shift  35 */
  {   1,   0,  19}, /*  5:                  ABORT shift  19 */
  { 130,   0,  39}, /*  6:                     id shift  39 */
  { 131,  11, 297}, /*  7:                    ids shift  297 */
  { 132,  12, 298}, /*  8:                idxitem shift  298 */
  { 133,  15, 327}, /*  9:                idxlist shift  327 */
  {  28,   0,  26}, /* 10:                   DESC shift  26 */
  {   6,   0,  20}, /* 11:                    ASC shift  20 */
  {   7,   0,  21}, /* 12:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 13:                EXPLAIN shift  28 */
  {  88,  17,  40}, /* 14:                 STRING shift  40 */
  {  58,  18,  32}, /* 15:                    KEY shift  32 */
  {  90,  19,  36}, /* 16:                   TEMP shift  36 */
  {  38,   0,  29}, /* 17:                   FAIL shift  29 */
  {  33,   0,  27}, /* 18:                    END shift  27 */
  {  15,   0,  22}, /* 19:                CLUSTER shift  22 */
  {  23,   0,  24}, /* 20:                   COPY shift  24 */
  {  70,   0,  33}, /* 21:                 OFFSET shift  33 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  47,   0,  30}, /* 23:                     ID shift  30 */
  {  48,  20,  31}, /* 24:                 IGNORE shift  31 */
  {  99,   0,  37}, /* 25:                 VACUUM shift  37 */
/* State 327 */
  {  80,   0, 328}, /*  1:                     RP shift  328 */
  {  17,   0, 295}, /*  2:                  COMMA shift  295 */
/* State 328 */
  { 144,   0, 329}, /*  1:                 onconf shift  329 */
  {  71,   0,   9}, /*  2:                     ON shift  9 */
  {  83,   2, 492}, /*  3:                   SEMI reduce 81 */
/* State 329 */
  {  83,   0, 620}, /*  1:                   SEMI reduce 209 */
/* State 330 */
  {  51,   0, 621}, /*  1:                  INDEX reduce 210 */
/* State 331 */
  {  51,   0, 336}, /*  1:                  INDEX shift  336 */
  {  89,   0, 332}, /*  2:                  TABLE shift  332 */
  { 101,   2, 334}, /*  3:                   VIEW shift  334 */
/* State 332 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 333}, /* 17:                    ids shift  333 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 333 */
  {  83,   0, 501}, /*  1:                   SEMI reduce 90 */
/* State 334 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 335}, /* 17:                    ids shift  335 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 335 */
  {  83,   0, 503}, /*  1:                   SEMI reduce 92 */
/* State 336 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 337}, /* 17:                    ids shift  337 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 337 */
  {  83,   0, 626}, /*  1:                   SEMI reduce 215 */
/* State 338 */
  {  95,   0, 168}, /*  1:                  UNION shift  168 */
  {  36,   0, 171}, /*  2:                 EXCEPT shift  171 */
  { 142,   0,  82}, /*  3:         multiselect_op shift  82 */
  {  83,   0, 504}, /*  4:                   SEMI reduce 93 */
  {  54,   0, 170}, /*  5:              INTERSECT shift  170 */
/* State 339 */
  {  40,   0, 340}, /*  1:                   FROM shift  340 */
/* State 340 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 341}, /* 17:                    ids shift  341 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 341 */
  {  83,   0, 547}, /*  1:                   SEMI reduce 136 */
  { 103,   0, 223}, /*  2:                  WHERE shift  223 */
  { 167,   1, 342}, /*  3:              where_opt shift  342 */
/* State 342 */
  {  83,   0, 546}, /*  1:                   SEMI reduce 135 */
/* State 343 */
  { 146,   2, 346}, /*  1:                 orconf shift  346 */
  {  72,   0, 344}, /*  2:                     OR shift  344 */
/* State 344 */
  { 150,   4, 345}, /*  1:            resolvetype shift  345 */
  {  79,   5,  12}, /*  2:               ROLLBACK shift  12 */
  {  38,   0,  14}, /*  3:                   FAIL shift  14 */
  {  78,   6,  16}, /*  4:                REPLACE shift  16 */
  {   1,   0,  13}, /*  5:                  ABORT shift  13 */
  {  48,   0,  15}, /*  6:                 IGNORE shift  15 */
/* State 346 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 347}, /* 17:                    ids shift  347 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 347 */
  {  84,   0, 348}, /*  1:                    SET shift  348 */
/* State 348 */
  {  48,   0,  31}, /*  1:                 IGNORE shift  31 */
  {   1,   0,  19}, /*  2:                  ABORT shift  19 */
  {  75,   9,  34}, /*  3:                 PRAGMA shift  34 */
  {  99,   3,  37}, /*  4:                 VACUUM shift  37 */
  {  28,   0,  26}, /*  5:                   DESC shift  26 */
  { 101,   0,  38}, /*  6:                   VIEW shift  38 */
  {  78,  13,  35}, /*  7:                REPLACE shift  35 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  27,   0,  25}, /*  9:             DELIMITERS shift  25 */
  {  33,   0,  27}, /* 10:                    END shift  27 */
  { 130,  18,  39}, /* 11:                     id shift  39 */
  { 155,  20, 349}, /* 12:                setlist shift  349 */
  {   6,   0,  20}, /* 13:                    ASC shift  20 */
  {  37,   0,  28}, /* 14:                EXPLAIN shift  28 */
  {  38,   0,  29}, /* 15:                   FAIL shift  29 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  {  88,   0,  40}, /* 17:                 STRING shift  40 */
  {  58,   0,  32}, /* 18:                    KEY shift  32 */
  {  90,   0,  36}, /* 19:                   TEMP shift  36 */
  { 131,   0, 355}, /* 20:                    ids shift  355 */
  {  23,   0,  24}, /* 21:                   COPY shift  24 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  70,   0,  33}, /* 23:                 OFFSET shift  33 */
  {  47,  21,  30}, /* 24:                     ID shift  30 */
/* State 349 */
  { 103,   3, 223}, /*  1:                  WHERE shift  223 */
  {  17,   0, 351}, /*  2:                  COMMA shift  351 */
  {  83,   0, 547}, /*  3:                   SEMI reduce 136 */
  { 167,   1, 350}, /*  4:              where_opt shift  350 */
/* State 350 */
  {  83,   0, 549}, /*  1:                   SEMI reduce 138 */
/* State 351 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 352}, /* 17:                    ids shift  352 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 352 */
  {  35,   0, 353}, /*  1:                     EQ shift  353 */
/* State 353 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 354}, /* 26:                   expr shift  354 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 354 */
  {   4,   0, 106}, /*  1:                    AND shift  106 */
  {  59,   0, 120}, /*  2:                     LE shift  120 */
  {   8,   0, 161}, /*  3:                BETWEEN shift  161 */
  {  81,   0, 134}, /*  4:                 RSHIFT shift  134 */
  {  56,   1, 156}, /*  5:                     IS shift  156 */
  {  57,   0, 155}, /*  6:                 ISNULL shift  155 */
  {  35,  11, 126}, /*  7:                     EQ shift  126 */
  {  85,   2, 149}, /*  8:                  SLASH shift  149 */
  {  60,   3, 136}, /*  9:                   LIKE shift  136 */
  {  87,   7, 147}, /* 10:                   STAR shift  147 */
  {   9,   0, 128}, /* 11:                 BITAND shift  128 */
  {  63,  19, 132}, /* 12:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 13:                     LT shift  116 */
  {  65,   0, 145}, /* 14:                  MINUS shift  145 */
  {  66,   0, 124}, /* 15:                     NE shift  124 */
  {  67,   0, 138}, /* 16:                    NOT shift  138 */
  {  68,  22, 160}, /* 17:                NOTNULL shift  160 */
  {  43,   0, 141}, /* 18:                   GLOB shift  141 */
  {  11,   0, 130}, /* 19:                  BITOR shift  130 */
  {  45,   0, 118}, /* 20:                     GT shift  118 */
  {  72,  24, 114}, /* 21:                     OR shift  114 */
  {  42,   0, 122}, /* 22:                     GE shift  122 */
  {  74,   0, 143}, /* 23:                   PLUS shift  143 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 25:                     IN shift  165 */
  {  77,   0, 151}, /* 26:                    REM shift  151 */
/* State 355 */
  {  35,   0, 356}, /*  1:                     EQ shift  356 */
/* State 356 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 357}, /* 26:                   expr shift  357 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 357 */
  {   4,   0, 106}, /*  1:                    AND shift  106 */
  {  59,   0, 120}, /*  2:                     LE shift  120 */
  {   8,   0, 161}, /*  3:                BETWEEN shift  161 */
  {  81,   0, 134}, /*  4:                 RSHIFT shift  134 */
  {  56,   1, 156}, /*  5:                     IS shift  156 */
  {  57,   0, 155}, /*  6:                 ISNULL shift  155 */
  {  35,  11, 126}, /*  7:                     EQ shift  126 */
  {  85,   2, 149}, /*  8:                  SLASH shift  149 */
  {  60,   3, 136}, /*  9:                   LIKE shift  136 */
  {  87,   7, 147}, /* 10:                   STAR shift  147 */
  {   9,   0, 128}, /* 11:                 BITAND shift  128 */
  {  63,  19, 132}, /* 12:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 13:                     LT shift  116 */
  {  65,   0, 145}, /* 14:                  MINUS shift  145 */
  {  66,   0, 124}, /* 15:                     NE shift  124 */
  {  67,   0, 138}, /* 16:                    NOT shift  138 */
  {  68,  22, 160}, /* 17:                NOTNULL shift  160 */
  {  43,   0, 141}, /* 18:                   GLOB shift  141 */
  {  11,   0, 130}, /* 19:                  BITOR shift  130 */
  {  45,   0, 118}, /* 20:                     GT shift  118 */
  {  72,  24, 114}, /* 21:                     OR shift  114 */
  {  42,   0, 122}, /* 22:                     GE shift  122 */
  {  74,   0, 143}, /* 23:                   PLUS shift  143 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 25:                     IN shift  165 */
  {  77,   0, 151}, /* 26:                    REM shift  151 */
/* State 358 */
  {  55,   0, 359}, /*  1:                   INTO shift  359 */
/* State 359 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 360}, /* 17:                    ids shift  360 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 360 */
  { 136,   2, 361}, /*  1:         inscollist_opt shift  361 */
  {  62,   0, 370}, /*  2:                     LP shift  370 */
/* State 361 */
  { 100,   0, 363}, /*  1:                 VALUES shift  363 */
  { 153,   4, 362}, /*  2:                 select shift  362 */
  {  82,   0,  84}, /*  3:                 SELECT shift  84 */
  { 145,   0,  80}, /*  4:              oneselect shift  80 */
/* State 362 */
  {  95,   0, 168}, /*  1:                  UNION shift  168 */
  {  36,   0, 171}, /*  2:                 EXCEPT shift  171 */
  { 142,   0,  82}, /*  3:         multiselect_op shift  82 */
  {  83,   0, 553}, /*  4:                   SEMI reduce 142 */
  {  54,   0, 170}, /*  5:              INTERSECT shift  170 */
/* State 363 */
  {  62,   0, 364}, /*  1:                     LP shift  364 */
/* State 364 */
  {   1,   0,  19}, /*  1:                  ABORT shift  19 */
  {  69,   1, 107}, /*  2:                   NULL shift  107 */
  { 138,   9, 365}, /*  3:               itemlist shift  365 */
  {  37,   0,  28}, /*  4:                EXPLAIN shift  28 */
  {  38,   0,  29}, /*  5:                   FAIL shift  29 */
  {  39,   0, 112}, /*  6:                  FLOAT shift  112 */
  {  74,  10, 180}, /*  7:                   PLUS shift  180 */
  {  75,  12,  34}, /*  8:                 PRAGMA shift  34 */
  {  70,   0,  33}, /*  9:                 OFFSET shift  33 */
  {   6,   0,  20}, /* 10:                    ASC shift  20 */
  {  78,  13,  35}, /* 11:                REPLACE shift  35 */
  {   7,   0,  21}, /* 12:                  BEGIN shift  21 */
  {  10,   0, 176}, /* 13:                 BITNOT shift  176 */
  {  47,  17,  75}, /* 14:                     ID shift  75 */
  {  48,   0,  31}, /* 15:                 IGNORE shift  31 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  {  13,   0, 182}, /* 17:                   CASE shift  182 */
  {  90,   0,  36}, /* 18:                   TEMP shift  36 */
  {  62,  26,  79}, /* 19:                     LP shift  79 */
  {  53,   0, 111}, /* 20:                INTEGER shift  111 */
  {  88,   0,  78}, /* 21:                 STRING shift  78 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  { 124,  18, 369}, /* 23:                   expr shift  369 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  58,   0,  32}, /* 25:                    KEY shift  32 */
  {  28,   0,  26}, /* 26:                   DESC shift  26 */
  {  65,   0, 178}, /* 27:                  MINUS shift  178 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  { 130,  19,  77}, /* 29:                     id shift  77 */
  { 131,   0, 108}, /* 30:                    ids shift  108 */
  {  67,  33, 174}, /* 31:                    NOT shift  174 */
  {  99,  27,  37}, /* 32:                 VACUUM shift  37 */
  {  33,   0,  27}, /* 33:                    END shift  27 */
  { 101,  31,  38}, /* 34:                   VIEW shift  38 */
/* State 365 */
  {  80,   0, 366}, /*  1:                     RP shift  366 */
  {  17,   0, 367}, /*  2:                  COMMA shift  367 */
/* State 366 */
  {  83,   0, 552}, /*  1:                   SEMI reduce 141 */
/* State 367 */
  {  99,  12,  37}, /*  1:                 VACUUM shift  37 */
  {  67,  17, 174}, /*  2:                    NOT shift  174 */
  { 101,   0,  38}, /*  3:                   VIEW shift  38 */
  {  69,   0, 107}, /*  4:                   NULL shift  107 */
  {  70,  18,  33}, /*  5:                 OFFSET shift  33 */
  {  38,   0,  29}, /*  6:                   FAIL shift  29 */
  {  39,  19, 112}, /*  7:                  FLOAT shift  112 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  74,   0, 180}, /*  9:                   PLUS shift  180 */
  {  75,   0,  34}, /* 10:                 PRAGMA shift  34 */
  {  10,   0, 176}, /* 11:                 BITNOT shift  176 */
  {  33,   0,  27}, /* 12:                    END shift  27 */
  {  78,   0,  35}, /* 13:                REPLACE shift  35 */
  {  13,   0, 182}, /* 14:                   CASE shift  182 */
  {  47,   0,  75}, /* 15:                     ID shift  75 */
  {  48,  20,  31}, /* 16:                 IGNORE shift  31 */
  {   1,   0,  19}, /* 17:                  ABORT shift  19 */
  {  37,   0,  28}, /* 18:                EXPLAIN shift  28 */
  {   6,   0,  20}, /* 19:                    ASC shift  20 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  53,   0, 111}, /* 21:                INTEGER shift  111 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  88,   0,  78}, /* 23:                 STRING shift  78 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  {  90,   0,  36}, /* 25:                   TEMP shift  36 */
  { 124,  27, 368}, /* 26:                   expr shift  368 */
  {  58,   0,  32}, /* 27:                    KEY shift  32 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
  {  62,   0,  79}, /* 30:                     LP shift  79 */
  {  65,   0, 178}, /* 31:                  MINUS shift  178 */
  { 130,   0,  77}, /* 32:                     id shift  77 */
  { 131,  31, 108}, /* 33:                    ids shift  108 */
/* State 368 */
  {   4,   0, 106}, /*  1:                    AND shift  106 */
  {  59,   0, 120}, /*  2:                     LE shift  120 */
  {   8,   0, 161}, /*  3:                BETWEEN shift  161 */
  {  81,   0, 134}, /*  4:                 RSHIFT shift  134 */
  {  56,   1, 156}, /*  5:                     IS shift  156 */
  {  57,   0, 155}, /*  6:                 ISNULL shift  155 */
  {  35,  11, 126}, /*  7:                     EQ shift  126 */
  {  85,   2, 149}, /*  8:                  SLASH shift  149 */
  {  60,   3, 136}, /*  9:                   LIKE shift  136 */
  {  87,   7, 147}, /* 10:                   STAR shift  147 */
  {   9,   0, 128}, /* 11:                 BITAND shift  128 */
  {  63,  19, 132}, /* 12:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 13:                     LT shift  116 */
  {  65,   0, 145}, /* 14:                  MINUS shift  145 */
  {  66,   0, 124}, /* 15:                     NE shift  124 */
  {  67,   0, 138}, /* 16:                    NOT shift  138 */
  {  68,  22, 160}, /* 17:                NOTNULL shift  160 */
  {  43,   0, 141}, /* 18:                   GLOB shift  141 */
  {  11,   0, 130}, /* 19:                  BITOR shift  130 */
  {  45,   0, 118}, /* 20:                     GT shift  118 */
  {  72,  24, 114}, /* 21:                     OR shift  114 */
  {  42,   0, 122}, /* 22:                     GE shift  122 */
  {  74,   0, 143}, /* 23:                   PLUS shift  143 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 25:                     IN shift  165 */
  {  77,   0, 151}, /* 26:                    REM shift  151 */
/* State 369 */
  {   4,   0, 106}, /*  1:                    AND shift  106 */
  {  59,   0, 120}, /*  2:                     LE shift  120 */
  {   8,   0, 161}, /*  3:                BETWEEN shift  161 */
  {  81,   0, 134}, /*  4:                 RSHIFT shift  134 */
  {  56,   1, 156}, /*  5:                     IS shift  156 */
  {  57,   0, 155}, /*  6:                 ISNULL shift  155 */
  {  35,  11, 126}, /*  7:                     EQ shift  126 */
  {  85,   2, 149}, /*  8:                  SLASH shift  149 */
  {  60,   3, 136}, /*  9:                   LIKE shift  136 */
  {  87,   7, 147}, /* 10:                   STAR shift  147 */
  {   9,   0, 128}, /* 11:                 BITAND shift  128 */
  {  63,  19, 132}, /* 12:                 LSHIFT shift  132 */
  {  64,   0, 116}, /* 13:                     LT shift  116 */
  {  65,   0, 145}, /* 14:                  MINUS shift  145 */
  {  66,   0, 124}, /* 15:                     NE shift  124 */
  {  67,   0, 138}, /* 16:                    NOT shift  138 */
  {  68,  22, 160}, /* 17:                NOTNULL shift  160 */
  {  43,   0, 141}, /* 18:                   GLOB shift  141 */
  {  11,   0, 130}, /* 19:                  BITOR shift  130 */
  {  45,   0, 118}, /* 20:                     GT shift  118 */
  {  72,  24, 114}, /* 21:                     OR shift  114 */
  {  42,   0, 122}, /* 22:                     GE shift  122 */
  {  74,   0, 143}, /* 23:                   PLUS shift  143 */
  {  20,   0, 153}, /* 24:                 CONCAT shift  153 */
  {  50,   0, 165}, /* 25:                     IN shift  165 */
  {  77,   0, 151}, /* 26:                    REM shift  151 */
/* State 370 */
  {  48,   0,  31}, /*  1:                 IGNORE shift  31 */
  {   1,   0,  19}, /*  2:                  ABORT shift  19 */
  {  75,   9,  34}, /*  3:                 PRAGMA shift  34 */
  {  99,   3,  37}, /*  4:                 VACUUM shift  37 */
  {  28,   0,  26}, /*  5:                   DESC shift  26 */
  { 101,   0,  38}, /*  6:                   VIEW shift  38 */
  {  78,  13,  35}, /*  7:                REPLACE shift  35 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  27,   0,  25}, /*  9:             DELIMITERS shift  25 */
  {  33,   0,  27}, /* 10:                    END shift  27 */
  { 130,  18,  39}, /* 11:                     id shift  39 */
  { 131,   0, 375}, /* 12:                    ids shift  375 */
  {   6,   0,  20}, /* 13:                    ASC shift  20 */
  {  37,   0,  28}, /* 14:                EXPLAIN shift  28 */
  {  38,   0,  29}, /* 15:                   FAIL shift  29 */
  { 135,  20, 371}, /* 16:             inscollist shift  371 */
  {  88,   0,  40}, /* 17:                 STRING shift  40 */
  {  58,   0,  32}, /* 18:                    KEY shift  32 */
  {  90,   0,  36}, /* 19:                   TEMP shift  36 */
  {  15,   0,  22}, /* 20:                CLUSTER shift  22 */
  {  23,   0,  24}, /* 21:                   COPY shift  24 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  70,   0,  33}, /* 23:                 OFFSET shift  33 */
  {  47,  21,  30}, /* 24:                     ID shift  30 */
/* State 371 */
  {  80,   0, 372}, /*  1:                     RP shift  372 */
  {  17,   0, 373}, /*  2:                  COMMA shift  373 */
/* State 373 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 374}, /* 17:                    ids shift  374 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 376 */
  {  72,   0, 344}, /*  1:                     OR shift  344 */
  {  55,   0, 494}, /*  2:                   INTO reduce 83 */
  { 146,   0, 377}, /*  3:                 orconf shift  377 */
/* State 377 */
  {  55,   0, 554}, /*  1:                   INTO reduce 143 */
/* State 378 */
  {  55,   0, 555}, /*  1:                   INTO reduce 144 */
/* State 379 */
  { 146,   2, 380}, /*  1:                 orconf shift  380 */
  {  72,   0, 344}, /*  2:                     OR shift  344 */
/* State 380 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 381}, /* 17:                    ids shift  381 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 381 */
  {  40,   0, 382}, /*  1:                   FROM shift  382 */
/* State 382 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 383}, /* 17:                    ids shift  383 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 383 */
  {  98,   0, 384}, /*  1:                  USING shift  384 */
  {  83,   0, 628}, /*  2:                   SEMI reduce 217 */
/* State 384 */
  {  27,   0, 385}, /*  1:             DELIMITERS shift  385 */
/* State 385 */
  {  88,   0, 386}, /*  1:                 STRING shift  386 */
/* State 386 */
  {  83,   0, 627}, /*  1:                   SEMI reduce 216 */
/* State 387 */
  {  48,   0,  31}, /*  1:                 IGNORE shift  31 */
  {   1,   0,  19}, /*  2:                  ABORT shift  19 */
  {  75,   9,  34}, /*  3:                 PRAGMA shift  34 */
  {  99,   3,  37}, /*  4:                 VACUUM shift  37 */
  {  28,   0,  26}, /*  5:                   DESC shift  26 */
  { 101,   0,  38}, /*  6:                   VIEW shift  38 */
  {  78,  13,  35}, /*  7:                REPLACE shift  35 */
  {   7,   0,  21}, /*  8:                  BEGIN shift  21 */
  {  27,   0,  25}, /*  9:             DELIMITERS shift  25 */
  {  33,   0,  27}, /* 10:                    END shift  27 */
  { 130,  18,  39}, /* 11:                     id shift  39 */
  { 131,  20, 388}, /* 12:                    ids shift  388 */
  {   6,   0,  20}, /* 13:                    ASC shift  20 */
  {  37,   0,  28}, /* 14:                EXPLAIN shift  28 */
  {  38,   0,  29}, /* 15:                   FAIL shift  29 */
  {  15,   0,  22}, /* 16:                CLUSTER shift  22 */
  {  88,   0,  40}, /* 17:                 STRING shift  40 */
  {  58,   0,  32}, /* 18:                    KEY shift  32 */
  {  90,   0,  36}, /* 19:                   TEMP shift  36 */
  {  83,   0, 629}, /* 20:                   SEMI reduce 218 */
  {  23,   0,  24}, /* 21:                   COPY shift  24 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  70,   0,  33}, /* 23:                 OFFSET shift  33 */
  {  47,  21,  30}, /* 24:                     ID shift  30 */
/* State 388 */
  {  83,   0, 630}, /*  1:                   SEMI reduce 219 */
/* State 389 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 390}, /* 17:                    ids shift  390 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 390 */
  {  62,   2, 403}, /*  1:                     LP shift  403 */
  {  35,   0, 391}, /*  2:                     EQ shift  391 */
  {  83,   1, 636}, /*  3:                   SEMI reduce 225 */
/* State 391 */
  {  58,   0,  32}, /*  1:                    KEY shift  32 */
  {  88,   3,  40}, /*  2:                 STRING shift  40 */
  {   1,   0,  19}, /*  3:                  ABORT shift  19 */
  { 148,   6, 394}, /*  4:               plus_num shift  394 */
  { 149,  11, 396}, /*  5:               plus_opt shift  396 */
  {  90,   0,  36}, /*  6:                   TEMP shift  36 */
  {   6,   0,  20}, /*  7:                    ASC shift  20 */
  {  65,  12, 400}, /*  8:                  MINUS shift  400 */
  {  37,   0,  28}, /*  9:                EXPLAIN shift  28 */
  {  38,   0,  29}, /* 10:                   FAIL shift  29 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   7,   0,  21}, /* 12:                  BEGIN shift  21 */
  {  99,  23,  37}, /* 13:                 VACUUM shift  37 */
  {  71,   0, 393}, /* 14:                     ON shift  393 */
  { 130,  25,  39}, /* 15:                     id shift  39 */
  { 131,  27, 392}, /* 16:                    ids shift  392 */
  {  74,   0, 402}, /* 17:                   PLUS shift  402 */
  {  75,   0,  34}, /* 18:                 PRAGMA shift  34 */
  {  47,   0,  30}, /* 19:                     ID shift  30 */
  {  48,   0,  31}, /* 20:                 IGNORE shift  31 */
  {  78,   0,  35}, /* 21:                REPLACE shift  35 */
  {  21,   0,  23}, /* 22:               CONFLICT shift  23 */
  {  70,   0,  33}, /* 23:                 OFFSET shift  33 */
  {  23,   0,  24}, /* 24:                   COPY shift  24 */
  { 101,   0,  38}, /* 25:                   VIEW shift  38 */
  { 141,   0, 395}, /* 26:              minus_num shift  395 */
  {  15,   0,  22}, /* 27:                CLUSTER shift  22 */
  {  27,   0,  25}, /* 28:             DELIMITERS shift  25 */
  {  28,   0,  26}, /* 29:                   DESC shift  26 */
/* State 392 */
  {  83,   0, 631}, /*  1:                   SEMI reduce 220 */
/* State 393 */
  {  83,   0, 632}, /*  1:                   SEMI reduce 221 */
/* State 394 */
  {  83,   0, 633}, /*  1:                   SEMI reduce 222 */
/* State 395 */
  {  83,   0, 634}, /*  1:                   SEMI reduce 223 */
/* State 396 */
  {  39,   0, 399}, /*  1:                  FLOAT shift  399 */
  {  53,   0, 398}, /*  2:                INTEGER shift  398 */
  { 143,   2, 397}, /*  3:                 number shift  397 */
/* State 397 */
  {  83,   0, 637}, /*  1:                   SEMI reduce 226 */
/* State 398 */
  {  83,   0, 639}, /*  1:                   SEMI reduce 228 */
/* State 399 */
  {  83,   0, 640}, /*  1:                   SEMI reduce 229 */
/* State 400 */
  {  39,   0, 399}, /*  1:                  FLOAT shift  399 */
  {  53,   0, 398}, /*  2:                INTEGER shift  398 */
  { 143,   2, 401}, /*  3:                 number shift  401 */
/* State 401 */
  {  83,   0, 638}, /*  1:                   SEMI reduce 227 */
/* State 403 */
  {  23,   0,  24}, /*  1:                   COPY shift  24 */
  {  70,   4,  33}, /*  2:                 OFFSET shift  33 */
  {  48,   0,  31}, /*  3:                 IGNORE shift  31 */
  {  47,   9,  30}, /*  4:                     ID shift  30 */
  {  27,   0,  25}, /*  5:             DELIMITERS shift  25 */
  {  28,   0,  26}, /*  6:                   DESC shift  26 */
  {  75,  12,  34}, /*  7:                 PRAGMA shift  34 */
  {  99,  14,  37}, /*  8:                 VACUUM shift  37 */
  {   1,   0,  19}, /*  9:                  ABORT shift  19 */
  { 101,  18,  38}, /* 10:                   VIEW shift  38 */
  {  33,   0,  27}, /* 11:                    END shift  27 */
  {   6,   0,  20}, /* 12:                    ASC shift  20 */
  {  58,   0,  32}, /* 13:                    KEY shift  32 */
  {   7,   0,  21}, /* 14:                  BEGIN shift  21 */
  {  37,   0,  28}, /* 15:                EXPLAIN shift  28 */
  { 130,  19,  39}, /* 16:                     id shift  39 */
  { 131,   0, 404}, /* 17:                    ids shift  404 */
  {  78,   0,  35}, /* 18:                REPLACE shift  35 */
  {  38,  21,  29}, /* 19:                   FAIL shift  29 */
  {  88,   0,  40}, /* 20:                 STRING shift  40 */
  {  15,   0,  22}, /* 21:                CLUSTER shift  22 */
  {  90,  23,  36}, /* 22:                   TEMP shift  36 */
  {  21,   0,  23}, /* 23:               CONFLICT shift  23 */
/* State 404 */
  {  80,   0, 405}, /*  1:                     RP shift  405 */
/* State 405 */
  {  83,   0, 635}, /*  1:                   SEMI reduce 224 */
/* State 406 */
  {  83,   0, 407}, /*  1:                   SEMI shift  407 */
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
  { &yyActionTable[0],  25, 643 },
  { &yyActionTable[25],  24, 643 },
  { &yyActionTable[49],   0, 413 },
  { &yyActionTable[49],  19, 643 },
  { &yyActionTable[68],   1, 643 },
  { &yyActionTable[69],   0, 414 },
  { &yyActionTable[69],   2, 419 },
  { &yyActionTable[71],   3, 643 },
  { &yyActionTable[74],   1, 643 },
  { &yyActionTable[75],   1, 643 },
  { &yyActionTable[76],   6, 643 },
  { &yyActionTable[82],   0, 493 },
  { &yyActionTable[82],   0, 496 },
  { &yyActionTable[82],   0, 497 },
  { &yyActionTable[82],   0, 498 },
  { &yyActionTable[82],   0, 499 },
  { &yyActionTable[82],   0, 500 },
  { &yyActionTable[82],  23, 420 },
  { &yyActionTable[105],   0, 421 },
  { &yyActionTable[105],   0, 435 },
  { &yyActionTable[105],   0, 436 },
  { &yyActionTable[105],   0, 437 },
  { &yyActionTable[105],   0, 438 },
  { &yyActionTable[105],   0, 439 },
  { &yyActionTable[105],   0, 440 },
  { &yyActionTable[105],   0, 441 },
  { &yyActionTable[105],   0, 442 },
  { &yyActionTable[105],   0, 443 },
  { &yyActionTable[105],   0, 444 },
  { &yyActionTable[105],   0, 445 },
  { &yyActionTable[105],   0, 446 },
  { &yyActionTable[105],   0, 447 },
  { &yyActionTable[105],   0, 448 },
  { &yyActionTable[105],   0, 449 },
  { &yyActionTable[105],   0, 450 },
  { &yyActionTable[105],   0, 451 },
  { &yyActionTable[105],   0, 452 },
  { &yyActionTable[105],   0, 453 },
  { &yyActionTable[105],   0, 454 },
  { &yyActionTable[105],   0, 455 },
  { &yyActionTable[105],   0, 456 },
  { &yyActionTable[105],   3, 643 },
  { &yyActionTable[108],   1, 643 },
  { &yyActionTable[109],   3, 643 },
  { &yyActionTable[112],   1, 643 },
  { &yyActionTable[113],   3, 643 },
  { &yyActionTable[116],   1, 643 },
  { &yyActionTable[117],   3, 643 },
  { &yyActionTable[120],   1, 643 },
  { &yyActionTable[121],  26, 643 },
  { &yyActionTable[147],   3, 643 },
  { &yyActionTable[150],   1, 643 },
  { &yyActionTable[151],   1, 643 },
  { &yyActionTable[152],  31, 643 },
  { &yyActionTable[183],   0, 431 },
  { &yyActionTable[183],  25, 457 },
  { &yyActionTable[208],   1, 467 },
  { &yyActionTable[209],   8, 433 },
  { &yyActionTable[217],   0, 466 },
  { &yyActionTable[217],  23, 643 },
  { &yyActionTable[240],   5, 643 },
  { &yyActionTable[245],   0, 468 },
  { &yyActionTable[245],   1, 643 },
  { &yyActionTable[246],   2, 492 },
  { &yyActionTable[248],   0, 479 },
  { &yyActionTable[248],   1, 643 },
  { &yyActionTable[249],   3, 536 },
  { &yyActionTable[252],   2, 492 },
  { &yyActionTable[254],   0, 480 },
  { &yyActionTable[254],   0, 534 },
  { &yyActionTable[254],   0, 535 },
  { &yyActionTable[254],   2, 492 },
  { &yyActionTable[256],   0, 481 },
  { &yyActionTable[256],   1, 643 },
  { &yyActionTable[257],  33, 643 },
  { &yyActionTable[290],   1, 446 },
  { &yyActionTable[291],  36, 619 },
  { &yyActionTable[327],   1, 564 },
  { &yyActionTable[328],   1, 568 },
  { &yyActionTable[329],  36, 643 },
  { &yyActionTable[365],   0, 505 },
  { &yyActionTable[365],   5, 643 },
  { &yyActionTable[370],   2, 643 },
  { &yyActionTable[372],   0, 506 },
  { &yyActionTable[372],   3, 514 },
  { &yyActionTable[375],   2, 516 },
  { &yyActionTable[377],   3, 643 },
  { &yyActionTable[380],   2, 547 },
  { &yyActionTable[382],   2, 537 },
  { &yyActionTable[384],   2, 539 },
  { &yyActionTable[386],   2, 529 },
  { &yyActionTable[388],   2, 541 },
  { &yyActionTable[390],   0, 511 },
  { &yyActionTable[390],   1, 643 },
  { &yyActionTable[391],   3, 542 },
  { &yyActionTable[394],   1, 643 },
  { &yyActionTable[395],   0, 543 },
  { &yyActionTable[395],   1, 643 },
  { &yyActionTable[396],   1, 643 },
  { &yyActionTable[397],   1, 643 },
  { &yyActionTable[398],  35, 643 },
  { &yyActionTable[433],   1, 530 },
  { &yyActionTable[434],  34, 643 },
  { &yyActionTable[468],   3, 536 },
  { &yyActionTable[471],   0, 531 },
  { &yyActionTable[471],  26, 533 },
  { &yyActionTable[497],  33, 643 },
  { &yyActionTable[530],   0, 563 },
  { &yyActionTable[530],   1, 643 },
  { &yyActionTable[531],  23, 643 },
  { &yyActionTable[554],   0, 565 },
  { &yyActionTable[554],   0, 566 },
  { &yyActionTable[554],   0, 567 },
  { &yyActionTable[554],  24, 571 },
  { &yyActionTable[578],  33, 643 },
  { &yyActionTable[611],  25, 572 },
  { &yyActionTable[636],  33, 643 },
  { &yyActionTable[669],  10, 573 },
  { &yyActionTable[679],  33, 643 },
  { &yyActionTable[712],  10, 574 },
  { &yyActionTable[722],  33, 643 },
  { &yyActionTable[755],  10, 575 },
  { &yyActionTable[765],  33, 643 },
  { &yyActionTable[798],  10, 576 },
  { &yyActionTable[808],  33, 643 },
  { &yyActionTable[841],  14, 577 },
  { &yyActionTable[855],  33, 643 },
  { &yyActionTable[888],  14, 578 },
  { &yyActionTable[902],  33, 643 },
  { &yyActionTable[935],   6, 579 },
  { &yyActionTable[941],  33, 643 },
  { &yyActionTable[974],   6, 580 },
  { &yyActionTable[980],  33, 643 },
  { &yyActionTable[1013],   6, 581 },
  { &yyActionTable[1019],  33, 643 },
  { &yyActionTable[1052],   6, 582 },
  { &yyActionTable[1058],  33, 643 },
  { &yyActionTable[1091],  14, 583 },
  { &yyActionTable[1105],   5, 643 },
  { &yyActionTable[1110],  33, 643 },
  { &yyActionTable[1143],  24, 584 },
  { &yyActionTable[1167],  33, 643 },
  { &yyActionTable[1200],  14, 585 },
  { &yyActionTable[1214],  33, 643 },
  { &yyActionTable[1247],   4, 587 },
  { &yyActionTable[1251],  33, 643 },
  { &yyActionTable[1284],   4, 588 },
  { &yyActionTable[1288],  33, 643 },
  { &yyActionTable[1321],   1, 589 },
  { &yyActionTable[1322],  33, 643 },
  { &yyActionTable[1355],   1, 590 },
  { &yyActionTable[1356],  33, 643 },
  { &yyActionTable[1389],   1, 591 },
  { &yyActionTable[1390],  33, 643 },
  { &yyActionTable[1423],   0, 592 },
  { &yyActionTable[1423],   0, 593 },
  { &yyActionTable[1423],   2, 643 },
  { &yyActionTable[1425],   0, 594 },
  { &yyActionTable[1425],   1, 643 },
  { &yyActionTable[1426],   0, 597 },
  { &yyActionTable[1426],   0, 595 },
  { &yyActionTable[1426],  33, 643 },
  { &yyActionTable[1459],  26, 643 },
  { &yyActionTable[1485],  33, 643 },
  { &yyActionTable[1518],  14, 603 },
  { &yyActionTable[1532],   1, 643 },
  { &yyActionTable[1533],  38, 619 },
  { &yyActionTable[1571],   5, 643 },
  { &yyActionTable[1576],   2, 643 },
  { &yyActionTable[1578],   1, 643 },
  { &yyActionTable[1579],   1, 643 },
  { &yyActionTable[1580],   1, 643 },
  { &yyActionTable[1581],   0, 606 },
  { &yyActionTable[1581],  26, 618 },
  { &yyActionTable[1607],  33, 643 },
  { &yyActionTable[1640],  24, 598 },
  { &yyActionTable[1664],  33, 643 },
  { &yyActionTable[1697],   0, 599 },
  { &yyActionTable[1697],  33, 643 },
  { &yyActionTable[1730],   0, 600 },
  { &yyActionTable[1730],  33, 643 },
  { &yyActionTable[1763],   0, 601 },
  { &yyActionTable[1763],  35, 643 },
  { &yyActionTable[1798],  27, 643 },
  { &yyActionTable[1825],   2, 643 },
  { &yyActionTable[1827],   4, 643 },
  { &yyActionTable[1831],   1, 643 },
  { &yyActionTable[1832],   0, 609 },
  { &yyActionTable[1832],  33, 643 },
  { &yyActionTable[1865],  27, 643 },
  { &yyActionTable[1892],  33, 643 },
  { &yyActionTable[1925],  26, 610 },
  { &yyActionTable[1951],  33, 643 },
  { &yyActionTable[1984],  27, 643 },
  { &yyActionTable[2011],  33, 643 },
  { &yyActionTable[2044],  27, 643 },
  { &yyActionTable[2071],  33, 643 },
  { &yyActionTable[2104],  26, 611 },
  { &yyActionTable[2130],   2, 643 },
  { &yyActionTable[2132],   0, 605 },
  { &yyActionTable[2132],  34, 619 },
  { &yyActionTable[2166],   0, 616 },
  { &yyActionTable[2166],   0, 617 },
  { &yyActionTable[2166],  33, 643 },
  { &yyActionTable[2199],  24, 586 },
  { &yyActionTable[2223],   0, 596 },
  { &yyActionTable[2223],  33, 643 },
  { &yyActionTable[2256],  26, 643 },
  { &yyActionTable[2282],  33, 643 },
  { &yyActionTable[2315],  24, 604 },
  { &yyActionTable[2339],   1, 643 },
  { &yyActionTable[2340],  38, 619 },
  { &yyActionTable[2378],   5, 643 },
  { &yyActionTable[2383],   0, 608 },
  { &yyActionTable[2383],   2, 643 },
  { &yyActionTable[2385],   0, 607 },
  { &yyActionTable[2385],   3, 536 },
  { &yyActionTable[2388],   0, 532 },
  { &yyActionTable[2388],  33, 643 },
  { &yyActionTable[2421],  26, 540 },
  { &yyActionTable[2447],   1, 643 },
  { &yyActionTable[2448],  35, 619 },
  { &yyActionTable[2483],   1, 538 },
  { &yyActionTable[2484],  33, 643 },
  { &yyActionTable[2517],  26, 548 },
  { &yyActionTable[2543],   0, 515 },
  { &yyActionTable[2543],   2, 524 },
  { &yyActionTable[2545],   1, 522 },
  { &yyActionTable[2546],   0, 523 },
  { &yyActionTable[2546],  24, 643 },
  { &yyActionTable[2570],  13, 520 },
  { &yyActionTable[2583],   0, 521 },
  { &yyActionTable[2583],  23, 643 },
  { &yyActionTable[2606],   0, 526 },
  { &yyActionTable[2606],   3, 643 },
  { &yyActionTable[2609],   5, 643 },
  { &yyActionTable[2614],  13, 520 },
  { &yyActionTable[2627],  23, 643 },
  { &yyActionTable[2650],   0, 528 },
  { &yyActionTable[2650],  34, 643 },
  { &yyActionTable[2684],  30, 520 },
  { &yyActionTable[2714],  23, 643 },
  { &yyActionTable[2737],   0, 518 },
  { &yyActionTable[2737],   0, 519 },
  { &yyActionTable[2737],   0, 512 },
  { &yyActionTable[2737],   0, 513 },
  { &yyActionTable[2737],   0, 602 },
  { &yyActionTable[2737],  27, 643 },
  { &yyActionTable[2764],   0, 562 },
  { &yyActionTable[2764],   2, 643 },
  { &yyActionTable[2766],   0, 569 },
  { &yyActionTable[2766],   1, 643 },
  { &yyActionTable[2767],   0, 570 },
  { &yyActionTable[2767],  27, 643 },
  { &yyActionTable[2794],   2, 492 },
  { &yyActionTable[2796],   0, 482 },
  { &yyActionTable[2796],   0, 469 },
  { &yyActionTable[2796],   7, 643 },
  { &yyActionTable[2803],   0, 470 },
  { &yyActionTable[2803],   0, 471 },
  { &yyActionTable[2803],   0, 472 },
  { &yyActionTable[2803],   2, 643 },
  { &yyActionTable[2805],   0, 473 },
  { &yyActionTable[2805],   0, 476 },
  { &yyActionTable[2805],   2, 643 },
  { &yyActionTable[2807],   0, 474 },
  { &yyActionTable[2807],   0, 477 },
  { &yyActionTable[2807],   0, 475 },
  { &yyActionTable[2807],   0, 478 },
  { &yyActionTable[2807],  24, 458 },
  { &yyActionTable[2831],   4, 643 },
  { &yyActionTable[2835],   2, 643 },
  { &yyActionTable[2837],   0, 459 },
  { &yyActionTable[2837],   4, 643 },
  { &yyActionTable[2841],   1, 643 },
  { &yyActionTable[2842],   0, 460 },
  { &yyActionTable[2842],   0, 463 },
  { &yyActionTable[2842],   1, 643 },
  { &yyActionTable[2843],   0, 464 },
  { &yyActionTable[2843],   1, 643 },
  { &yyActionTable[2844],   0, 465 },
  { &yyActionTable[2844],   0, 462 },
  { &yyActionTable[2844],   0, 461 },
  { &yyActionTable[2844],   0, 434 },
  { &yyActionTable[2844],   7, 643 },
  { &yyActionTable[2851],   5, 643 },
  { &yyActionTable[2856],   0, 485 },
  { &yyActionTable[2856],  23, 643 },
  { &yyActionTable[2879],   0, 488 },
  { &yyActionTable[2879],   1, 643 },
  { &yyActionTable[2880],   1, 643 },
  { &yyActionTable[2881],  25, 643 },
  { &yyActionTable[2906],   2, 643 },
  { &yyActionTable[2908],   2, 492 },
  { &yyActionTable[2910],   0, 489 },
  { &yyActionTable[2910],  24, 643 },
  { &yyActionTable[2934],   0, 623 },
  { &yyActionTable[2934],   0, 625 },
  { &yyActionTable[2934],   0, 624 },
  { &yyActionTable[2934],   1, 643 },
  { &yyActionTable[2935],  25, 643 },
  { &yyActionTable[2960],   2, 643 },
  { &yyActionTable[2962],   2, 492 },
  { &yyActionTable[2964],   0, 490 },
  { &yyActionTable[2964],  33, 643 },
  { &yyActionTable[2997],  28, 492 },
  { &yyActionTable[3025],   0, 491 },
  { &yyActionTable[3025],   0, 486 },
  { &yyActionTable[3025],   0, 487 },
  { &yyActionTable[3025],   0, 432 },
  { &yyActionTable[3025],   3, 643 },
  { &yyActionTable[3028],   5, 643 },
  { &yyActionTable[3033],   7, 643 },
  { &yyActionTable[3040],   1, 643 },
  { &yyActionTable[3041],  23, 643 },
  { &yyActionTable[3064],   0, 426 },
  { &yyActionTable[3064],   1, 643 },
  { &yyActionTable[3065],  23, 643 },
  { &yyActionTable[3088],   1, 643 },
  { &yyActionTable[3089],   3, 643 },
  { &yyActionTable[3092],   5, 643 },
  { &yyActionTable[3097],   1, 643 },
  { &yyActionTable[3098],  23, 643 },
  { &yyActionTable[3121],   1, 643 },
  { &yyActionTable[3122],  23, 643 },
  { &yyActionTable[3145],   1, 643 },
  { &yyActionTable[3146],  25, 643 },
  { &yyActionTable[3171],   2, 643 },
  { &yyActionTable[3173],   3, 643 },
  { &yyActionTable[3176],   1, 643 },
  { &yyActionTable[3177],   1, 643 },
  { &yyActionTable[3178],   3, 643 },
  { &yyActionTable[3181],  23, 643 },
  { &yyActionTable[3204],   1, 643 },
  { &yyActionTable[3205],  23, 643 },
  { &yyActionTable[3228],   1, 643 },
  { &yyActionTable[3229],  23, 643 },
  { &yyActionTable[3252],   1, 643 },
  { &yyActionTable[3253],   5, 643 },
  { &yyActionTable[3258],   1, 643 },
  { &yyActionTable[3259],  23, 643 },
  { &yyActionTable[3282],   3, 643 },
  { &yyActionTable[3285],   1, 643 },
  { &yyActionTable[3286],   2, 494 },
  { &yyActionTable[3288],   6, 643 },
  { &yyActionTable[3294],   0, 495 },
  { &yyActionTable[3294],  23, 643 },
  { &yyActionTable[3317],   1, 643 },
  { &yyActionTable[3318],  24, 643 },
  { &yyActionTable[3342],   4, 643 },
  { &yyActionTable[3346],   1, 643 },
  { &yyActionTable[3347],  23, 643 },
  { &yyActionTable[3370],   1, 643 },
  { &yyActionTable[3371],  33, 643 },
  { &yyActionTable[3404],  26, 550 },
  { &yyActionTable[3430],   1, 643 },
  { &yyActionTable[3431],  33, 643 },
  { &yyActionTable[3464],  26, 551 },
  { &yyActionTable[3490],   1, 643 },
  { &yyActionTable[3491],  23, 643 },
  { &yyActionTable[3514],   2, 558 },
  { &yyActionTable[3516],   4, 643 },
  { &yyActionTable[3520],   5, 643 },
  { &yyActionTable[3525],   1, 643 },
  { &yyActionTable[3526],  34, 643 },
  { &yyActionTable[3560],   2, 643 },
  { &yyActionTable[3562],   1, 643 },
  { &yyActionTable[3563],  33, 643 },
  { &yyActionTable[3596],  26, 556 },
  { &yyActionTable[3622],  26, 557 },
  { &yyActionTable[3648],  24, 643 },
  { &yyActionTable[3672],   2, 643 },
  { &yyActionTable[3674],   0, 559 },
  { &yyActionTable[3674],  23, 643 },
  { &yyActionTable[3697],   0, 560 },
  { &yyActionTable[3697],   0, 561 },
  { &yyActionTable[3697],   3, 643 },
  { &yyActionTable[3700],   1, 643 },
  { &yyActionTable[3701],   1, 643 },
  { &yyActionTable[3702],   2, 494 },
  { &yyActionTable[3704],  23, 643 },
  { &yyActionTable[3727],   1, 643 },
  { &yyActionTable[3728],  23, 643 },
  { &yyActionTable[3751],   2, 643 },
  { &yyActionTable[3753],   1, 643 },
  { &yyActionTable[3754],   1, 643 },
  { &yyActionTable[3755],   1, 643 },
  { &yyActionTable[3756],  24, 643 },
  { &yyActionTable[3780],   1, 643 },
  { &yyActionTable[3781],  23, 643 },
  { &yyActionTable[3804],   3, 643 },
  { &yyActionTable[3807],  29, 642 },
  { &yyActionTable[3836],   1, 643 },
  { &yyActionTable[3837],   1, 643 },
  { &yyActionTable[3838],   1, 643 },
  { &yyActionTable[3839],   1, 643 },
  { &yyActionTable[3840],   3, 643 },
  { &yyActionTable[3843],   1, 643 },
  { &yyActionTable[3844],   1, 643 },
  { &yyActionTable[3845],   1, 643 },
  { &yyActionTable[3846],   3, 643 },
  { &yyActionTable[3849],   1, 643 },
  { &yyActionTable[3850],   0, 641 },
  { &yyActionTable[3850],  23, 643 },
  { &yyActionTable[3873],   1, 643 },
  { &yyActionTable[3874],   1, 643 },
  { &yyActionTable[3875],   1, 643 },
  { &yyActionTable[3876],   0, 415 },
  { &yyActionTable[3876],   0, 416 },
  { &yyActionTable[3876],   0, 417 },
  { &yyActionTable[3876],   0, 412 },
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
  "BY",            "CASE",          "CHECK",         "CLUSTER",     
  "COLUMN",        "COMMA",         "COMMENT",       "COMMIT",      
  "CONCAT",        "CONFLICT",      "CONSTRAINT",    "COPY",        
  "CREATE",        "DEFAULT",       "DELETE",        "DELIMITERS",  
  "DESC",          "DISTINCT",      "DOT",           "DROP",        
  "ELSE",          "END",           "END_OF_FILE",   "EQ",          
  "EXCEPT",        "EXPLAIN",       "FAIL",          "FLOAT",       
  "FROM",          "FUNCTION",      "GE",            "GLOB",        
  "GROUP",         "GT",            "HAVING",        "ID",          
  "IGNORE",        "ILLEGAL",       "IN",            "INDEX",       
  "INSERT",        "INTEGER",       "INTERSECT",     "INTO",        
  "IS",            "ISNULL",        "KEY",           "LE",          
  "LIKE",          "LIMIT",         "LP",            "LSHIFT",      
  "LT",            "MINUS",         "NE",            "NOT",         
  "NOTNULL",       "NULL",          "OFFSET",        "ON",          
  "OR",            "ORDER",         "PLUS",          "PRAGMA",      
  "PRIMARY",       "REM",           "REPLACE",       "ROLLBACK",    
  "RP",            "RSHIFT",        "SELECT",        "SEMI",        
  "SET",           "SLASH",         "SPACE",         "STAR",        
  "STRING",        "TABLE",         "TEMP",          "THEN",        
  "TRANSACTION",   "UMINUS",        "UNCLOSED_STRING",  "UNION",       
  "UNIQUE",        "UPDATE",        "USING",         "VACUUM",      
  "VALUES",        "VIEW",          "WHEN",          "WHERE",       
  "as",            "carg",          "carglist",      "case_else",   
  "case_exprlist",  "case_operand",  "ccons",         "cmd",         
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
    case 108:
#line 532 "parse.y"
{sqliteExprListDelete((yypminor->yy144));}
#line 4889 "parse.c"
      break;
    case 124:
#line 395 "parse.y"
{sqliteExprDelete((yypminor->yy146));}
#line 4894 "parse.c"
      break;
    case 125:
#line 551 "parse.y"
{sqliteExprDelete((yypminor->yy146));}
#line 4899 "parse.c"
      break;
    case 126:
#line 549 "parse.y"
{sqliteExprListDelete((yypminor->yy144));}
#line 4904 "parse.c"
      break;
    case 127:
#line 267 "parse.y"
{sqliteIdListDelete((yypminor->yy82));}
#line 4909 "parse.c"
      break;
    case 128:
#line 313 "parse.y"
{sqliteExprListDelete((yypminor->yy144));}
#line 4914 "parse.c"
      break;
    case 129:
#line 318 "parse.y"
{sqliteExprDelete((yypminor->yy146));}
#line 4919 "parse.c"
      break;
    case 133:
#line 573 "parse.y"
{sqliteIdListDelete((yypminor->yy82));}
#line 4924 "parse.c"
      break;
    case 135:
#line 374 "parse.y"
{sqliteIdListDelete((yypminor->yy82));}
#line 4929 "parse.c"
      break;
    case 136:
#line 372 "parse.y"
{sqliteIdListDelete((yypminor->yy82));}
#line 4934 "parse.c"
      break;
    case 138:
#line 366 "parse.y"
{sqliteExprListDelete((yypminor->yy144));}
#line 4939 "parse.c"
      break;
    case 145:
#line 214 "parse.y"
{sqliteSelectDelete((yypminor->yy219));}
#line 4944 "parse.c"
      break;
    case 147:
#line 288 "parse.y"
{sqliteExprListDelete((yypminor->yy144));}
#line 4949 "parse.c"
      break;
    case 151:
#line 250 "parse.y"
{sqliteExprListDelete((yypminor->yy144));}
#line 4954 "parse.c"
      break;
    case 152:
#line 248 "parse.y"
{sqliteExprListDelete((yypminor->yy144));}
#line 4959 "parse.c"
      break;
    case 153:
#line 212 "parse.y"
{sqliteSelectDelete((yypminor->yy219));}
#line 4964 "parse.c"
      break;
    case 154:
#line 263 "parse.y"
{sqliteIdListDelete((yypminor->yy82));}
#line 4969 "parse.c"
      break;
    case 155:
#line 342 "parse.y"
{sqliteExprListDelete((yypminor->yy144));}
#line 4974 "parse.c"
      break;
    case 157:
#line 292 "parse.y"
{sqliteExprDelete((yypminor->yy146));}
#line 4979 "parse.c"
      break;
    case 158:
#line 290 "parse.y"
{sqliteExprListDelete((yypminor->yy144));}
#line 4984 "parse.c"
      break;
    case 160:
#line 265 "parse.y"
{sqliteIdListDelete((yypminor->yy82));}
#line 4989 "parse.c"
      break;
    case 167:
#line 336 "parse.y"
{sqliteExprDelete((yypminor->yy146));}
#line 4994 "parse.c"
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
  { 134, 1 },
  { 112, 1 },
  { 112, 2 },
  { 121, 3 },
  { 121, 2 },
  { 121, 1 },
  { 123, 1 },
  { 111, 3 },
  { 163, 0 },
  { 163, 1 },
  { 163, 2 },
  { 111, 2 },
  { 111, 2 },
  { 111, 2 },
  { 111, 2 },
  { 118, 4 },
  { 162, 1 },
  { 162, 0 },
  { 119, 4 },
  { 119, 2 },
  { 115, 3 },
  { 115, 1 },
  { 113, 3 },
  { 114, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 130, 1 },
  { 131, 1 },
  { 131, 1 },
  { 164, 0 },
  { 164, 1 },
  { 164, 4 },
  { 164, 6 },
  { 165, 1 },
  { 165, 2 },
  { 156, 1 },
  { 156, 2 },
  { 156, 2 },
  { 106, 2 },
  { 106, 0 },
  { 105, 3 },
  { 105, 1 },
  { 105, 2 },
  { 105, 2 },
  { 105, 2 },
  { 105, 3 },
  { 105, 3 },
  { 105, 2 },
  { 105, 3 },
  { 105, 3 },
  { 105, 2 },
  { 110, 3 },
  { 110, 4 },
  { 110, 2 },
  { 110, 5 },
  { 117, 0 },
  { 117, 2 },
  { 116, 3 },
  { 116, 2 },
  { 116, 1 },
  { 161, 2 },
  { 161, 6 },
  { 161, 5 },
  { 161, 3 },
  { 144, 0 },
  { 144, 3 },
  { 146, 0 },
  { 146, 2 },
  { 150, 1 },
  { 150, 1 },
  { 150, 1 },
  { 150, 1 },
  { 150, 1 },
  { 111, 3 },
  { 111, 5 },
  { 111, 3 },
  { 111, 1 },
  { 153, 1 },
  { 153, 3 },
  { 142, 1 },
  { 142, 2 },
  { 142, 1 },
  { 142, 1 },
  { 145, 9 },
  { 120, 1 },
  { 120, 1 },
  { 120, 0 },
  { 151, 2 },
  { 151, 0 },
  { 152, 2 },
  { 152, 4 },
  { 152, 2 },
  { 104, 0 },
  { 104, 1 },
  { 127, 2 },
  { 160, 2 },
  { 160, 0 },
  { 154, 2 },
  { 154, 4 },
  { 154, 4 },
  { 154, 6 },
  { 147, 0 },
  { 147, 3 },
  { 158, 4 },
  { 158, 2 },
  { 157, 1 },
  { 159, 1 },
  { 159, 1 },
  { 159, 0 },
  { 128, 0 },
  { 128, 3 },
  { 129, 0 },
  { 129, 2 },
  { 139, 0 },
  { 139, 2 },
  { 139, 4 },
  { 140, 1 },
  { 140, 1 },
  { 111, 4 },
  { 167, 0 },
  { 167, 2 },
  { 111, 6 },
  { 155, 5 },
  { 155, 3 },
  { 111, 8 },
  { 111, 5 },
  { 137, 2 },
  { 137, 1 },
  { 138, 3 },
  { 138, 1 },
  { 136, 0 },
  { 136, 3 },
  { 135, 3 },
  { 135, 1 },
  { 124, 3 },
  { 124, 1 },
  { 124, 1 },
  { 124, 3 },
  { 124, 1 },
  { 124, 1 },
  { 124, 1 },
  { 124, 4 },
  { 124, 4 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 4 },
  { 124, 3 },
  { 124, 4 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 3 },
  { 124, 2 },
  { 124, 3 },
  { 124, 2 },
  { 124, 3 },
  { 124, 4 },
  { 124, 2 },
  { 124, 2 },
  { 124, 2 },
  { 124, 2 },
  { 124, 3 },
  { 124, 5 },
  { 124, 6 },
  { 124, 5 },
  { 124, 5 },
  { 124, 6 },
  { 124, 6 },
  { 124, 5 },
  { 108, 5 },
  { 108, 4 },
  { 107, 2 },
  { 107, 0 },
  { 109, 1 },
  { 109, 0 },
  { 126, 3 },
  { 126, 1 },
  { 125, 1 },
  { 125, 0 },
  { 111, 10 },
  { 166, 1 },
  { 166, 0 },
  { 133, 3 },
  { 133, 1 },
  { 132, 1 },
  { 111, 3 },
  { 111, 8 },
  { 111, 5 },
  { 111, 1 },
  { 111, 2 },
  { 111, 4 },
  { 111, 4 },
  { 111, 4 },
  { 111, 4 },
  { 111, 5 },
  { 111, 2 },
  { 148, 2 },
  { 141, 2 },
  { 143, 1 },
  { 143, 1 },
  { 149, 1 },
  { 149, 0 },
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
#line 5405 "parse.c"
        /* No destructor defined for explain */
        /* No destructor defined for cmd */
        /* No destructor defined for SEMI */
        break;
      case 4:
        YYTRACE("ecmd ::= cmd SEMI")
#line 53 "parse.y"
{sqliteExec(pParse);}
#line 5414 "parse.c"
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
#line 5426 "parse.c"
        /* No destructor defined for EXPLAIN */
        break;
      case 7:
        YYTRACE("cmd ::= BEGIN trans_opt onconf")
#line 60 "parse.y"
{sqliteBeginTransaction(pParse,yymsp[0].minor.yy172);}
#line 5433 "parse.c"
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
#line 5453 "parse.c"
        /* No destructor defined for COMMIT */
        /* No destructor defined for trans_opt */
        break;
      case 12:
        YYTRACE("cmd ::= END trans_opt")
#line 65 "parse.y"
{sqliteCommitTransaction(pParse);}
#line 5461 "parse.c"
        /* No destructor defined for END */
        /* No destructor defined for trans_opt */
        break;
      case 13:
        YYTRACE("cmd ::= ROLLBACK trans_opt")
#line 66 "parse.y"
{sqliteRollbackTransaction(pParse);}
#line 5469 "parse.c"
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
   sqliteStartTable(pParse,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy210,yymsp[-2].minor.yy172);
}
#line 5484 "parse.c"
        /* No destructor defined for TABLE */
        break;
      case 16:
        YYTRACE("temp ::= TEMP")
#line 75 "parse.y"
{yygotominor.yy172 = 1;}
#line 5491 "parse.c"
        /* No destructor defined for TEMP */
        break;
      case 17:
        YYTRACE("temp ::=")
#line 76 "parse.y"
{yygotominor.yy172 = 0;}
#line 5498 "parse.c"
        break;
      case 18:
        YYTRACE("create_table_args ::= LP columnlist conslist_opt RP")
#line 77 "parse.y"
{
  sqliteEndTable(pParse,&yymsp[0].minor.yy0,0);
}
#line 5506 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for columnlist */
        /* No destructor defined for conslist_opt */
        break;
      case 19:
        YYTRACE("create_table_args ::= AS select")
#line 80 "parse.y"
{
  sqliteEndTable(pParse,0,yymsp[0].minor.yy219);
  sqliteSelectDelete(yymsp[0].minor.yy219);
}
#line 5518 "parse.c"
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
{sqliteAddColumn(pParse,&yymsp[0].minor.yy210);}
#line 5541 "parse.c"
        break;
      case 24:
        YYTRACE("id ::= ABORT")
#line 100 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5547 "parse.c"
        break;
      case 25:
        YYTRACE("id ::= ASC")
#line 101 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5553 "parse.c"
        break;
      case 26:
        YYTRACE("id ::= BEGIN")
#line 102 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5559 "parse.c"
        break;
      case 27:
        YYTRACE("id ::= CLUSTER")
#line 103 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5565 "parse.c"
        break;
      case 28:
        YYTRACE("id ::= CONFLICT")
#line 104 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5571 "parse.c"
        break;
      case 29:
        YYTRACE("id ::= COPY")
#line 105 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5577 "parse.c"
        break;
      case 30:
        YYTRACE("id ::= DELIMITERS")
#line 106 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5583 "parse.c"
        break;
      case 31:
        YYTRACE("id ::= DESC")
#line 107 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5589 "parse.c"
        break;
      case 32:
        YYTRACE("id ::= END")
#line 108 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5595 "parse.c"
        break;
      case 33:
        YYTRACE("id ::= EXPLAIN")
#line 109 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5601 "parse.c"
        break;
      case 34:
        YYTRACE("id ::= FAIL")
#line 110 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5607 "parse.c"
        break;
      case 35:
        YYTRACE("id ::= ID")
#line 111 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5613 "parse.c"
        break;
      case 36:
        YYTRACE("id ::= IGNORE")
#line 112 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5619 "parse.c"
        break;
      case 37:
        YYTRACE("id ::= KEY")
#line 113 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5625 "parse.c"
        break;
      case 38:
        YYTRACE("id ::= OFFSET")
#line 114 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5631 "parse.c"
        break;
      case 39:
        YYTRACE("id ::= PRAGMA")
#line 115 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5637 "parse.c"
        break;
      case 40:
        YYTRACE("id ::= REPLACE")
#line 116 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5643 "parse.c"
        break;
      case 41:
        YYTRACE("id ::= TEMP")
#line 117 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5649 "parse.c"
        break;
      case 42:
        YYTRACE("id ::= VACUUM")
#line 118 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5655 "parse.c"
        break;
      case 43:
        YYTRACE("id ::= VIEW")
#line 119 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5661 "parse.c"
        break;
      case 44:
        YYTRACE("ids ::= id")
#line 124 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy210;}
#line 5667 "parse.c"
        break;
      case 45:
        YYTRACE("ids ::= STRING")
#line 125 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 5673 "parse.c"
        break;
      case 46:
        YYTRACE("type ::=")
        break;
      case 47:
        YYTRACE("type ::= typename")
#line 128 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[0].minor.yy210,&yymsp[0].minor.yy210);}
#line 5682 "parse.c"
        break;
      case 48:
        YYTRACE("type ::= typename LP signed RP")
#line 129 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-3].minor.yy210,&yymsp[0].minor.yy0);}
#line 5688 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        break;
      case 49:
        YYTRACE("type ::= typename LP signed COMMA signed RP")
#line 131 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-5].minor.yy210,&yymsp[0].minor.yy0);}
#line 5696 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        /* No destructor defined for COMMA */
        /* No destructor defined for signed */
        break;
      case 50:
        YYTRACE("typename ::= ids")
#line 133 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy210;}
#line 5706 "parse.c"
        break;
      case 51:
        YYTRACE("typename ::= typename ids")
#line 134 "parse.y"
{yygotominor.yy210 = yymsp[-1].minor.yy210;}
#line 5712 "parse.c"
        /* No destructor defined for ids */
        break;
      case 52:
        YYTRACE("signed ::= INTEGER")
        /* No destructor defined for INTEGER */
        break;
      case 53:
        YYTRACE("signed ::= PLUS INTEGER")
        /* No destructor defined for PLUS */
        /* No destructor defined for INTEGER */
        break;
      case 54:
        YYTRACE("signed ::= MINUS INTEGER")
        /* No destructor defined for MINUS */
        /* No destructor defined for INTEGER */
        break;
      case 55:
        YYTRACE("carglist ::= carglist carg")
        /* No destructor defined for carglist */
        /* No destructor defined for carg */
        break;
      case 56:
        YYTRACE("carglist ::=")
        break;
      case 57:
        YYTRACE("carg ::= CONSTRAINT ids ccons")
        /* No destructor defined for CONSTRAINT */
        /* No destructor defined for ids */
        /* No destructor defined for ccons */
        break;
      case 58:
        YYTRACE("carg ::= ccons")
        /* No destructor defined for ccons */
        break;
      case 59:
        YYTRACE("carg ::= DEFAULT STRING")
#line 142 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5751 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 60:
        YYTRACE("carg ::= DEFAULT ID")
#line 143 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5758 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 61:
        YYTRACE("carg ::= DEFAULT INTEGER")
#line 144 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5765 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 62:
        YYTRACE("carg ::= DEFAULT PLUS INTEGER")
#line 145 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5772 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 63:
        YYTRACE("carg ::= DEFAULT MINUS INTEGER")
#line 146 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 5780 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 64:
        YYTRACE("carg ::= DEFAULT FLOAT")
#line 147 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5788 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 65:
        YYTRACE("carg ::= DEFAULT PLUS FLOAT")
#line 148 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5795 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 66:
        YYTRACE("carg ::= DEFAULT MINUS FLOAT")
#line 149 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 5803 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 67:
        YYTRACE("carg ::= DEFAULT NULL")
        /* No destructor defined for DEFAULT */
        /* No destructor defined for NULL */
        break;
      case 68:
        YYTRACE("ccons ::= NOT NULL onconf")
#line 155 "parse.y"
{sqliteAddNotNull(pParse, yymsp[0].minor.yy172);}
#line 5816 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for NULL */
        break;
      case 69:
        YYTRACE("ccons ::= PRIMARY KEY sortorder onconf")
#line 156 "parse.y"
{sqliteAddPrimaryKey(pParse,0,yymsp[0].minor.yy172);}
#line 5824 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for sortorder */
        break;
      case 70:
        YYTRACE("ccons ::= UNIQUE onconf")
#line 157 "parse.y"
{sqliteCreateIndex(pParse,0,0,0,yymsp[0].minor.yy172,0,0);}
#line 5833 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 71:
        YYTRACE("ccons ::= CHECK LP expr RP onconf")
        /* No destructor defined for CHECK */
        /* No destructor defined for LP */
  yy_destructor(124,&yymsp[-2].minor);
        /* No destructor defined for RP */
        /* No destructor defined for onconf */
        break;
      case 72:
        YYTRACE("conslist_opt ::=")
        break;
      case 73:
        YYTRACE("conslist_opt ::= COMMA conslist")
        /* No destructor defined for COMMA */
        /* No destructor defined for conslist */
        break;
      case 74:
        YYTRACE("conslist ::= conslist COMMA tcons")
        /* No destructor defined for conslist */
        /* No destructor defined for COMMA */
        /* No destructor defined for tcons */
        break;
      case 75:
        YYTRACE("conslist ::= conslist tcons")
        /* No destructor defined for conslist */
        /* No destructor defined for tcons */
        break;
      case 76:
        YYTRACE("conslist ::= tcons")
        /* No destructor defined for tcons */
        break;
      case 77:
        YYTRACE("tcons ::= CONSTRAINT ids")
        /* No destructor defined for CONSTRAINT */
        /* No destructor defined for ids */
        break;
      case 78:
        YYTRACE("tcons ::= PRIMARY KEY LP idxlist RP onconf")
#line 170 "parse.y"
{sqliteAddPrimaryKey(pParse,yymsp[-2].minor.yy82,yymsp[0].minor.yy172);}
#line 5876 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 79:
        YYTRACE("tcons ::= UNIQUE LP idxlist RP onconf")
#line 172 "parse.y"
{sqliteCreateIndex(pParse,0,0,yymsp[-2].minor.yy82,yymsp[0].minor.yy172,0,0);}
#line 5886 "parse.c"
        /* No destructor defined for UNIQUE */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 80:
        YYTRACE("tcons ::= CHECK expr onconf")
        /* No destructor defined for CHECK */
  yy_destructor(124,&yymsp[-1].minor);
        /* No destructor defined for onconf */
        break;
      case 81:
        YYTRACE("onconf ::=")
#line 181 "parse.y"
{ yygotominor.yy172 = OE_Default; }
#line 5901 "parse.c"
        break;
      case 82:
        YYTRACE("onconf ::= ON CONFLICT resolvetype")
#line 182 "parse.y"
{ yygotominor.yy172 = yymsp[0].minor.yy172; }
#line 5907 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for CONFLICT */
        break;
      case 83:
        YYTRACE("orconf ::=")
#line 183 "parse.y"
{ yygotominor.yy172 = OE_Default; }
#line 5915 "parse.c"
        break;
      case 84:
        YYTRACE("orconf ::= OR resolvetype")
#line 184 "parse.y"
{ yygotominor.yy172 = yymsp[0].minor.yy172; }
#line 5921 "parse.c"
        /* No destructor defined for OR */
        break;
      case 85:
        YYTRACE("resolvetype ::= ROLLBACK")
#line 185 "parse.y"
{ yygotominor.yy172 = OE_Rollback; }
#line 5928 "parse.c"
        /* No destructor defined for ROLLBACK */
        break;
      case 86:
        YYTRACE("resolvetype ::= ABORT")
#line 186 "parse.y"
{ yygotominor.yy172 = OE_Abort; }
#line 5935 "parse.c"
        /* No destructor defined for ABORT */
        break;
      case 87:
        YYTRACE("resolvetype ::= FAIL")
#line 187 "parse.y"
{ yygotominor.yy172 = OE_Fail; }
#line 5942 "parse.c"
        /* No destructor defined for FAIL */
        break;
      case 88:
        YYTRACE("resolvetype ::= IGNORE")
#line 188 "parse.y"
{ yygotominor.yy172 = OE_Ignore; }
#line 5949 "parse.c"
        /* No destructor defined for IGNORE */
        break;
      case 89:
        YYTRACE("resolvetype ::= REPLACE")
#line 189 "parse.y"
{ yygotominor.yy172 = OE_Replace; }
#line 5956 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 90:
        YYTRACE("cmd ::= DROP TABLE ids")
#line 193 "parse.y"
{sqliteDropTable(pParse,&yymsp[0].minor.yy210,0);}
#line 5963 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for TABLE */
        break;
      case 91:
        YYTRACE("cmd ::= CREATE VIEW ids AS select")
#line 197 "parse.y"
{
  sqliteCreateView(pParse, &yymsp[-4].minor.yy0, &yymsp[-2].minor.yy210, yymsp[0].minor.yy219);
}
#line 5973 "parse.c"
        /* No destructor defined for VIEW */
        /* No destructor defined for AS */
        break;
      case 92:
        YYTRACE("cmd ::= DROP VIEW ids")
#line 200 "parse.y"
{
  sqliteDropTable(pParse, &yymsp[0].minor.yy210, 1);
}
#line 5983 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for VIEW */
        break;
      case 93:
        YYTRACE("cmd ::= select")
#line 206 "parse.y"
{
  sqliteSelect(pParse, yymsp[0].minor.yy219, SRT_Callback, 0, 0, 0, 0);
  sqliteSelectDelete(yymsp[0].minor.yy219);
}
#line 5994 "parse.c"
        break;
      case 94:
        YYTRACE("select ::= oneselect")
#line 216 "parse.y"
{yygotominor.yy219 = yymsp[0].minor.yy219;}
#line 6000 "parse.c"
        break;
      case 95:
        YYTRACE("select ::= select multiselect_op oneselect")
#line 217 "parse.y"
{
  if( yymsp[0].minor.yy219 ){
    yymsp[0].minor.yy219->op = yymsp[-1].minor.yy172;
    yymsp[0].minor.yy219->pPrior = yymsp[-2].minor.yy219;
  }
  yygotominor.yy219 = yymsp[0].minor.yy219;
}
#line 6012 "parse.c"
        break;
      case 96:
        YYTRACE("multiselect_op ::= UNION")
#line 225 "parse.y"
{yygotominor.yy172 = TK_UNION;}
#line 6018 "parse.c"
        /* No destructor defined for UNION */
        break;
      case 97:
        YYTRACE("multiselect_op ::= UNION ALL")
#line 226 "parse.y"
{yygotominor.yy172 = TK_ALL;}
#line 6025 "parse.c"
        /* No destructor defined for UNION */
        /* No destructor defined for ALL */
        break;
      case 98:
        YYTRACE("multiselect_op ::= INTERSECT")
#line 227 "parse.y"
{yygotominor.yy172 = TK_INTERSECT;}
#line 6033 "parse.c"
        /* No destructor defined for INTERSECT */
        break;
      case 99:
        YYTRACE("multiselect_op ::= EXCEPT")
#line 228 "parse.y"
{yygotominor.yy172 = TK_EXCEPT;}
#line 6040 "parse.c"
        /* No destructor defined for EXCEPT */
        break;
      case 100:
        YYTRACE("oneselect ::= SELECT distinct selcollist from where_opt groupby_opt having_opt orderby_opt limit_opt")
#line 230 "parse.y"
{
  yygotominor.yy219 = sqliteSelectNew(yymsp[-6].minor.yy144,yymsp[-5].minor.yy82,yymsp[-4].minor.yy146,yymsp[-3].minor.yy144,yymsp[-2].minor.yy146,yymsp[-1].minor.yy144,yymsp[-7].minor.yy172,yymsp[0].minor.yy191.a,yymsp[0].minor.yy191.b);
}
#line 6049 "parse.c"
        /* No destructor defined for SELECT */
        break;
      case 101:
        YYTRACE("distinct ::= DISTINCT")
#line 238 "parse.y"
{yygotominor.yy172 = 1;}
#line 6056 "parse.c"
        /* No destructor defined for DISTINCT */
        break;
      case 102:
        YYTRACE("distinct ::= ALL")
#line 239 "parse.y"
{yygotominor.yy172 = 0;}
#line 6063 "parse.c"
        /* No destructor defined for ALL */
        break;
      case 103:
        YYTRACE("distinct ::=")
#line 240 "parse.y"
{yygotominor.yy172 = 0;}
#line 6070 "parse.c"
        break;
      case 104:
        YYTRACE("sclp ::= selcollist COMMA")
#line 251 "parse.y"
{yygotominor.yy144 = yymsp[-1].minor.yy144;}
#line 6076 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 105:
        YYTRACE("sclp ::=")
#line 252 "parse.y"
{yygotominor.yy144 = 0;}
#line 6083 "parse.c"
        break;
      case 106:
        YYTRACE("selcollist ::= sclp expr")
#line 253 "parse.y"
{yygotominor.yy144 = sqliteExprListAppend(yymsp[-1].minor.yy144,yymsp[0].minor.yy146,0);}
#line 6089 "parse.c"
        break;
      case 107:
        YYTRACE("selcollist ::= sclp expr as ids")
#line 254 "parse.y"
{yygotominor.yy144 = sqliteExprListAppend(yymsp[-3].minor.yy144,yymsp[-2].minor.yy146,&yymsp[0].minor.yy210);}
#line 6095 "parse.c"
        /* No destructor defined for as */
        break;
      case 108:
        YYTRACE("selcollist ::= sclp STAR")
#line 255 "parse.y"
{
  yygotominor.yy144 = sqliteExprListAppend(yymsp[-1].minor.yy144, sqliteExpr(TK_ALL, 0, 0, 0), 0);
}
#line 6104 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 109:
        YYTRACE("as ::=")
        break;
      case 110:
        YYTRACE("as ::= AS")
        /* No destructor defined for AS */
        break;
      case 111:
        YYTRACE("from ::= FROM seltablist")
#line 269 "parse.y"
{yygotominor.yy82 = yymsp[0].minor.yy82;}
#line 6118 "parse.c"
        /* No destructor defined for FROM */
        break;
      case 112:
        YYTRACE("stl_prefix ::= seltablist COMMA")
#line 270 "parse.y"
{yygotominor.yy82 = yymsp[-1].minor.yy82;}
#line 6125 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 113:
        YYTRACE("stl_prefix ::=")
#line 271 "parse.y"
{yygotominor.yy82 = 0;}
#line 6132 "parse.c"
        break;
      case 114:
        YYTRACE("seltablist ::= stl_prefix ids")
#line 272 "parse.y"
{yygotominor.yy82 = sqliteIdListAppend(yymsp[-1].minor.yy82,&yymsp[0].minor.yy210);}
#line 6138 "parse.c"
        break;
      case 115:
        YYTRACE("seltablist ::= stl_prefix ids as ids")
#line 273 "parse.y"
{
  yygotominor.yy82 = sqliteIdListAppend(yymsp[-3].minor.yy82,&yymsp[-2].minor.yy210);
  sqliteIdListAddAlias(yygotominor.yy82,&yymsp[0].minor.yy210);
}
#line 6147 "parse.c"
        /* No destructor defined for as */
        break;
      case 116:
        YYTRACE("seltablist ::= stl_prefix LP select RP")
#line 277 "parse.y"
{
  yygotominor.yy82 = sqliteIdListAppend(yymsp[-3].minor.yy82,0);
  yygotominor.yy82->a[yygotominor.yy82->nId-1].pSelect = yymsp[-1].minor.yy219;
}
#line 6157 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 117:
        YYTRACE("seltablist ::= stl_prefix LP select RP as ids")
#line 281 "parse.y"
{
  yygotominor.yy82 = sqliteIdListAppend(yymsp[-5].minor.yy82,0);
  yygotominor.yy82->a[yygotominor.yy82->nId-1].pSelect = yymsp[-3].minor.yy219;
  sqliteIdListAddAlias(yygotominor.yy82,&yymsp[0].minor.yy210);
}
#line 6169 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        /* No destructor defined for as */
        break;
      case 118:
        YYTRACE("orderby_opt ::=")
#line 294 "parse.y"
{yygotominor.yy144 = 0;}
#line 6178 "parse.c"
        break;
      case 119:
        YYTRACE("orderby_opt ::= ORDER BY sortlist")
#line 295 "parse.y"
{yygotominor.yy144 = yymsp[0].minor.yy144;}
#line 6184 "parse.c"
        /* No destructor defined for ORDER */
        /* No destructor defined for BY */
        break;
      case 120:
        YYTRACE("sortlist ::= sortlist COMMA sortitem sortorder")
#line 296 "parse.y"
{
  yygotominor.yy144 = sqliteExprListAppend(yymsp[-3].minor.yy144,yymsp[-1].minor.yy146,0);
  if( yygotominor.yy144 ) yygotominor.yy144->a[yygotominor.yy144->nExpr-1].sortOrder = yymsp[0].minor.yy172;  /* 0=ascending, 1=decending */
}
#line 6195 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 121:
        YYTRACE("sortlist ::= sortitem sortorder")
#line 300 "parse.y"
{
  yygotominor.yy144 = sqliteExprListAppend(0,yymsp[-1].minor.yy146,0);
  if( yygotominor.yy144 ) yygotominor.yy144->a[0].sortOrder = yymsp[0].minor.yy172;
}
#line 6205 "parse.c"
        break;
      case 122:
        YYTRACE("sortitem ::= expr")
#line 304 "parse.y"
{yygotominor.yy146 = yymsp[0].minor.yy146;}
#line 6211 "parse.c"
        break;
      case 123:
        YYTRACE("sortorder ::= ASC")
#line 308 "parse.y"
{yygotominor.yy172 = 0;}
#line 6217 "parse.c"
        /* No destructor defined for ASC */
        break;
      case 124:
        YYTRACE("sortorder ::= DESC")
#line 309 "parse.y"
{yygotominor.yy172 = 1;}
#line 6224 "parse.c"
        /* No destructor defined for DESC */
        break;
      case 125:
        YYTRACE("sortorder ::=")
#line 310 "parse.y"
{yygotominor.yy172 = 0;}
#line 6231 "parse.c"
        break;
      case 126:
        YYTRACE("groupby_opt ::=")
#line 314 "parse.y"
{yygotominor.yy144 = 0;}
#line 6237 "parse.c"
        break;
      case 127:
        YYTRACE("groupby_opt ::= GROUP BY exprlist")
#line 315 "parse.y"
{yygotominor.yy144 = yymsp[0].minor.yy144;}
#line 6243 "parse.c"
        /* No destructor defined for GROUP */
        /* No destructor defined for BY */
        break;
      case 128:
        YYTRACE("having_opt ::=")
#line 319 "parse.y"
{yygotominor.yy146 = 0;}
#line 6251 "parse.c"
        break;
      case 129:
        YYTRACE("having_opt ::= HAVING expr")
#line 320 "parse.y"
{yygotominor.yy146 = yymsp[0].minor.yy146;}
#line 6257 "parse.c"
        /* No destructor defined for HAVING */
        break;
      case 130:
        YYTRACE("limit_opt ::=")
#line 323 "parse.y"
{yygotominor.yy191.a = -1; yygotominor.yy191.b = 0;}
#line 6264 "parse.c"
        break;
      case 131:
        YYTRACE("limit_opt ::= LIMIT INTEGER")
#line 324 "parse.y"
{yygotominor.yy191.a = atoi(yymsp[0].minor.yy0.z); yygotominor.yy191.b = 0;}
#line 6270 "parse.c"
        /* No destructor defined for LIMIT */
        break;
      case 132:
        YYTRACE("limit_opt ::= LIMIT INTEGER limit_sep INTEGER")
#line 326 "parse.y"
{yygotominor.yy191.a = atoi(yymsp[-2].minor.yy0.z); yygotominor.yy191.b = atoi(yymsp[0].minor.yy0.z);}
#line 6277 "parse.c"
        /* No destructor defined for LIMIT */
        /* No destructor defined for limit_sep */
        break;
      case 133:
        YYTRACE("limit_sep ::= OFFSET")
        /* No destructor defined for OFFSET */
        break;
      case 134:
        YYTRACE("limit_sep ::= COMMA")
        /* No destructor defined for COMMA */
        break;
      case 135:
        YYTRACE("cmd ::= DELETE FROM ids where_opt")
#line 333 "parse.y"
{sqliteDeleteFrom(pParse, &yymsp[-1].minor.yy210, yymsp[0].minor.yy146);}
#line 6293 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 136:
        YYTRACE("where_opt ::=")
#line 338 "parse.y"
{yygotominor.yy146 = 0;}
#line 6301 "parse.c"
        break;
      case 137:
        YYTRACE("where_opt ::= WHERE expr")
#line 339 "parse.y"
{yygotominor.yy146 = yymsp[0].minor.yy146;}
#line 6307 "parse.c"
        /* No destructor defined for WHERE */
        break;
      case 138:
        YYTRACE("cmd ::= UPDATE orconf ids SET setlist where_opt")
#line 347 "parse.y"
{sqliteUpdate(pParse,&yymsp[-3].minor.yy210,yymsp[-1].minor.yy144,yymsp[0].minor.yy146,yymsp[-4].minor.yy172);}
#line 6314 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 139:
        YYTRACE("setlist ::= setlist COMMA ids EQ expr")
#line 350 "parse.y"
{yygotominor.yy144 = sqliteExprListAppend(yymsp[-4].minor.yy144,yymsp[0].minor.yy146,&yymsp[-2].minor.yy210);}
#line 6322 "parse.c"
        /* No destructor defined for COMMA */
        /* No destructor defined for EQ */
        break;
      case 140:
        YYTRACE("setlist ::= ids EQ expr")
#line 351 "parse.y"
{yygotominor.yy144 = sqliteExprListAppend(0,yymsp[0].minor.yy146,&yymsp[-2].minor.yy210);}
#line 6330 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 141:
        YYTRACE("cmd ::= insert_cmd INTO ids inscollist_opt VALUES LP itemlist RP")
#line 356 "parse.y"
{sqliteInsert(pParse, &yymsp[-5].minor.yy210, yymsp[-1].minor.yy144, 0, yymsp[-4].minor.yy82, yymsp[-7].minor.yy172);}
#line 6337 "parse.c"
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 142:
        YYTRACE("cmd ::= insert_cmd INTO ids inscollist_opt select")
#line 358 "parse.y"
{sqliteInsert(pParse, &yymsp[-2].minor.yy210, 0, yymsp[0].minor.yy219, yymsp[-1].minor.yy82, yymsp[-4].minor.yy172);}
#line 6347 "parse.c"
        /* No destructor defined for INTO */
        break;
      case 143:
        YYTRACE("insert_cmd ::= INSERT orconf")
#line 361 "parse.y"
{yygotominor.yy172 = yymsp[0].minor.yy172;}
#line 6354 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 144:
        YYTRACE("insert_cmd ::= REPLACE")
#line 362 "parse.y"
{yygotominor.yy172 = OE_Replace;}
#line 6361 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 145:
        YYTRACE("itemlist ::= itemlist COMMA expr")
#line 368 "parse.y"
{yygotominor.yy144 = sqliteExprListAppend(yymsp[-2].minor.yy144,yymsp[0].minor.yy146,0);}
#line 6368 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 146:
        YYTRACE("itemlist ::= expr")
#line 369 "parse.y"
{yygotominor.yy144 = sqliteExprListAppend(0,yymsp[0].minor.yy146,0);}
#line 6375 "parse.c"
        break;
      case 147:
        YYTRACE("inscollist_opt ::=")
#line 376 "parse.y"
{yygotominor.yy82 = 0;}
#line 6381 "parse.c"
        break;
      case 148:
        YYTRACE("inscollist_opt ::= LP inscollist RP")
#line 377 "parse.y"
{yygotominor.yy82 = yymsp[-1].minor.yy82;}
#line 6387 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 149:
        YYTRACE("inscollist ::= inscollist COMMA ids")
#line 378 "parse.y"
{yygotominor.yy82 = sqliteIdListAppend(yymsp[-2].minor.yy82,&yymsp[0].minor.yy210);}
#line 6395 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 150:
        YYTRACE("inscollist ::= ids")
#line 379 "parse.y"
{yygotominor.yy82 = sqliteIdListAppend(0,&yymsp[0].minor.yy210);}
#line 6402 "parse.c"
        break;
      case 151:
        YYTRACE("expr ::= LP expr RP")
#line 397 "parse.y"
{yygotominor.yy146 = yymsp[-1].minor.yy146; sqliteExprSpan(yygotominor.yy146,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);}
#line 6408 "parse.c"
        break;
      case 152:
        YYTRACE("expr ::= NULL")
#line 398 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_NULL, 0, 0, &yymsp[0].minor.yy0);}
#line 6414 "parse.c"
        break;
      case 153:
        YYTRACE("expr ::= id")
#line 399 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy210);}
#line 6420 "parse.c"
        break;
      case 154:
        YYTRACE("expr ::= ids DOT ids")
#line 400 "parse.y"
{
  Expr *temp1 = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy210);
  Expr *temp2 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy210);
  yygotominor.yy146 = sqliteExpr(TK_DOT, temp1, temp2, 0);
}
#line 6430 "parse.c"
        /* No destructor defined for DOT */
        break;
      case 155:
        YYTRACE("expr ::= INTEGER")
#line 405 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_INTEGER, 0, 0, &yymsp[0].minor.yy0);}
#line 6437 "parse.c"
        break;
      case 156:
        YYTRACE("expr ::= FLOAT")
#line 406 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_FLOAT, 0, 0, &yymsp[0].minor.yy0);}
#line 6443 "parse.c"
        break;
      case 157:
        YYTRACE("expr ::= STRING")
#line 407 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_STRING, 0, 0, &yymsp[0].minor.yy0);}
#line 6449 "parse.c"
        break;
      case 158:
        YYTRACE("expr ::= ID LP exprlist RP")
#line 408 "parse.y"
{
  yygotominor.yy146 = sqliteExprFunction(yymsp[-1].minor.yy144, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 6458 "parse.c"
        /* No destructor defined for LP */
        break;
      case 159:
        YYTRACE("expr ::= ID LP STAR RP")
#line 412 "parse.y"
{
  yygotominor.yy146 = sqliteExprFunction(0, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 6468 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for STAR */
        break;
      case 160:
        YYTRACE("expr ::= expr AND expr")
#line 416 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_AND, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6476 "parse.c"
        /* No destructor defined for AND */
        break;
      case 161:
        YYTRACE("expr ::= expr OR expr")
#line 417 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_OR, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6483 "parse.c"
        /* No destructor defined for OR */
        break;
      case 162:
        YYTRACE("expr ::= expr LT expr")
#line 418 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_LT, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6490 "parse.c"
        /* No destructor defined for LT */
        break;
      case 163:
        YYTRACE("expr ::= expr GT expr")
#line 419 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_GT, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6497 "parse.c"
        /* No destructor defined for GT */
        break;
      case 164:
        YYTRACE("expr ::= expr LE expr")
#line 420 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_LE, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6504 "parse.c"
        /* No destructor defined for LE */
        break;
      case 165:
        YYTRACE("expr ::= expr GE expr")
#line 421 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_GE, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6511 "parse.c"
        /* No destructor defined for GE */
        break;
      case 166:
        YYTRACE("expr ::= expr NE expr")
#line 422 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_NE, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6518 "parse.c"
        /* No destructor defined for NE */
        break;
      case 167:
        YYTRACE("expr ::= expr EQ expr")
#line 423 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_EQ, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6525 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 168:
        YYTRACE("expr ::= expr BITAND expr")
#line 424 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_BITAND, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6532 "parse.c"
        /* No destructor defined for BITAND */
        break;
      case 169:
        YYTRACE("expr ::= expr BITOR expr")
#line 425 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_BITOR, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6539 "parse.c"
        /* No destructor defined for BITOR */
        break;
      case 170:
        YYTRACE("expr ::= expr LSHIFT expr")
#line 426 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_LSHIFT, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6546 "parse.c"
        /* No destructor defined for LSHIFT */
        break;
      case 171:
        YYTRACE("expr ::= expr RSHIFT expr")
#line 427 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_RSHIFT, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6553 "parse.c"
        /* No destructor defined for RSHIFT */
        break;
      case 172:
        YYTRACE("expr ::= expr LIKE expr")
#line 428 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_LIKE, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6560 "parse.c"
        /* No destructor defined for LIKE */
        break;
      case 173:
        YYTRACE("expr ::= expr NOT LIKE expr")
#line 429 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_LIKE, yymsp[-3].minor.yy146, yymsp[0].minor.yy146, 0);
  yygotominor.yy146 = sqliteExpr(TK_NOT, yygotominor.yy146, 0, 0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-3].minor.yy146->span,&yymsp[0].minor.yy146->span);
}
#line 6571 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for LIKE */
        break;
      case 174:
        YYTRACE("expr ::= expr GLOB expr")
#line 434 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_GLOB,yymsp[-2].minor.yy146,yymsp[0].minor.yy146,0);}
#line 6579 "parse.c"
        /* No destructor defined for GLOB */
        break;
      case 175:
        YYTRACE("expr ::= expr NOT GLOB expr")
#line 435 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_GLOB, yymsp[-3].minor.yy146, yymsp[0].minor.yy146, 0);
  yygotominor.yy146 = sqliteExpr(TK_NOT, yygotominor.yy146, 0, 0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-3].minor.yy146->span,&yymsp[0].minor.yy146->span);
}
#line 6590 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for GLOB */
        break;
      case 176:
        YYTRACE("expr ::= expr PLUS expr")
#line 440 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_PLUS, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6598 "parse.c"
        /* No destructor defined for PLUS */
        break;
      case 177:
        YYTRACE("expr ::= expr MINUS expr")
#line 441 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_MINUS, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6605 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 178:
        YYTRACE("expr ::= expr STAR expr")
#line 442 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_STAR, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6612 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 179:
        YYTRACE("expr ::= expr SLASH expr")
#line 443 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_SLASH, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6619 "parse.c"
        /* No destructor defined for SLASH */
        break;
      case 180:
        YYTRACE("expr ::= expr REM expr")
#line 444 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_REM, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6626 "parse.c"
        /* No destructor defined for REM */
        break;
      case 181:
        YYTRACE("expr ::= expr CONCAT expr")
#line 445 "parse.y"
{yygotominor.yy146 = sqliteExpr(TK_CONCAT, yymsp[-2].minor.yy146, yymsp[0].minor.yy146, 0);}
#line 6633 "parse.c"
        /* No destructor defined for CONCAT */
        break;
      case 182:
        YYTRACE("expr ::= expr ISNULL")
#line 446 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_ISNULL, yymsp[-1].minor.yy146, 0, 0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-1].minor.yy146->span,&yymsp[0].minor.yy0);
}
#line 6643 "parse.c"
        break;
      case 183:
        YYTRACE("expr ::= expr IS NULL")
#line 450 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_ISNULL, yymsp[-2].minor.yy146, 0, 0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-2].minor.yy146->span,&yymsp[0].minor.yy0);
}
#line 6652 "parse.c"
        /* No destructor defined for IS */
        break;
      case 184:
        YYTRACE("expr ::= expr NOTNULL")
#line 454 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_NOTNULL, yymsp[-1].minor.yy146, 0, 0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-1].minor.yy146->span,&yymsp[0].minor.yy0);
}
#line 6662 "parse.c"
        break;
      case 185:
        YYTRACE("expr ::= expr NOT NULL")
#line 458 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_NOTNULL, yymsp[-2].minor.yy146, 0, 0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-2].minor.yy146->span,&yymsp[0].minor.yy0);
}
#line 6671 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 186:
        YYTRACE("expr ::= expr IS NOT NULL")
#line 462 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_NOTNULL, yymsp[-3].minor.yy146, 0, 0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-3].minor.yy146->span,&yymsp[0].minor.yy0);
}
#line 6681 "parse.c"
        /* No destructor defined for IS */
        /* No destructor defined for NOT */
        break;
      case 187:
        YYTRACE("expr ::= NOT expr")
#line 466 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_NOT, yymsp[0].minor.yy146, 0, 0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy146->span);
}
#line 6692 "parse.c"
        break;
      case 188:
        YYTRACE("expr ::= BITNOT expr")
#line 470 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_BITNOT, yymsp[0].minor.yy146, 0, 0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy146->span);
}
#line 6701 "parse.c"
        break;
      case 189:
        YYTRACE("expr ::= MINUS expr")
#line 474 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_UMINUS, yymsp[0].minor.yy146, 0, 0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy146->span);
}
#line 6710 "parse.c"
        break;
      case 190:
        YYTRACE("expr ::= PLUS expr")
#line 478 "parse.y"
{
  yygotominor.yy146 = yymsp[0].minor.yy146;
  sqliteExprSpan(yygotominor.yy146,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy146->span);
}
#line 6719 "parse.c"
        break;
      case 191:
        YYTRACE("expr ::= LP select RP")
#line 482 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_SELECT, 0, 0, 0);
  if( yygotominor.yy146 ) yygotominor.yy146->pSelect = yymsp[-1].minor.yy219;
  sqliteExprSpan(yygotominor.yy146,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);
}
#line 6729 "parse.c"
        break;
      case 192:
        YYTRACE("expr ::= expr BETWEEN expr AND expr")
#line 487 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy146, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy146, 0);
  yygotominor.yy146 = sqliteExpr(TK_BETWEEN, yymsp[-4].minor.yy146, 0, 0);
  if( yygotominor.yy146 ) yygotominor.yy146->pList = pList;
  sqliteExprSpan(yygotominor.yy146,&yymsp[-4].minor.yy146->span,&yymsp[0].minor.yy146->span);
}
#line 6741 "parse.c"
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 193:
        YYTRACE("expr ::= expr NOT BETWEEN expr AND expr")
#line 494 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy146, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy146, 0);
  yygotominor.yy146 = sqliteExpr(TK_BETWEEN, yymsp[-5].minor.yy146, 0, 0);
  if( yygotominor.yy146 ) yygotominor.yy146->pList = pList;
  yygotominor.yy146 = sqliteExpr(TK_NOT, yygotominor.yy146, 0, 0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-5].minor.yy146->span,&yymsp[0].minor.yy146->span);
}
#line 6756 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 194:
        YYTRACE("expr ::= expr IN LP exprlist RP")
#line 502 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_IN, yymsp[-4].minor.yy146, 0, 0);
  if( yygotominor.yy146 ) yygotominor.yy146->pList = yymsp[-1].minor.yy144;
  sqliteExprSpan(yygotominor.yy146,&yymsp[-4].minor.yy146->span,&yymsp[0].minor.yy0);
}
#line 6769 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 195:
        YYTRACE("expr ::= expr IN LP select RP")
#line 507 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_IN, yymsp[-4].minor.yy146, 0, 0);
  if( yygotominor.yy146 ) yygotominor.yy146->pSelect = yymsp[-1].minor.yy219;
  sqliteExprSpan(yygotominor.yy146,&yymsp[-4].minor.yy146->span,&yymsp[0].minor.yy0);
}
#line 6781 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 196:
        YYTRACE("expr ::= expr NOT IN LP exprlist RP")
#line 512 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_IN, yymsp[-5].minor.yy146, 0, 0);
  if( yygotominor.yy146 ) yygotominor.yy146->pList = yymsp[-1].minor.yy144;
  yygotominor.yy146 = sqliteExpr(TK_NOT, yygotominor.yy146, 0, 0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-5].minor.yy146->span,&yymsp[0].minor.yy0);
}
#line 6794 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 197:
        YYTRACE("expr ::= expr NOT IN LP select RP")
#line 518 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_IN, yymsp[-5].minor.yy146, 0, 0);
  if( yygotominor.yy146 ) yygotominor.yy146->pSelect = yymsp[-1].minor.yy219;
  yygotominor.yy146 = sqliteExpr(TK_NOT, yygotominor.yy146, 0, 0);
  sqliteExprSpan(yygotominor.yy146,&yymsp[-5].minor.yy146->span,&yymsp[0].minor.yy0);
}
#line 6808 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 198:
        YYTRACE("expr ::= CASE case_operand case_exprlist case_else END")
#line 526 "parse.y"
{
  yygotominor.yy146 = sqliteExpr(TK_CASE, yymsp[-3].minor.yy146, yymsp[-1].minor.yy146, 0);
  if( yygotominor.yy146 ) yygotominor.yy146->pList = yymsp[-2].minor.yy144;
  sqliteExprSpan(yygotominor.yy146, &yymsp[-4].minor.yy0, &yymsp[0].minor.yy0);
}
#line 6821 "parse.c"
        break;
      case 199:
        YYTRACE("case_exprlist ::= case_exprlist WHEN expr THEN expr")
#line 533 "parse.y"
{
  yygotominor.yy144 = sqliteExprListAppend(yymsp[-4].minor.yy144, yymsp[-2].minor.yy146, 0);
  yygotominor.yy144 = sqliteExprListAppend(yygotominor.yy144, yymsp[0].minor.yy146, 0);
}
#line 6830 "parse.c"
        /* No destructor defined for WHEN */
        /* No destructor defined for THEN */
        break;
      case 200:
        YYTRACE("case_exprlist ::= WHEN expr THEN expr")
#line 537 "parse.y"
{
  yygotominor.yy144 = sqliteExprListAppend(0, yymsp[-2].minor.yy146, 0);
  yygotominor.yy144 = sqliteExprListAppend(yygotominor.yy144, yymsp[0].minor.yy146, 0);
}
#line 6841 "parse.c"
        /* No destructor defined for WHEN */
        /* No destructor defined for THEN */
        break;
      case 201:
        YYTRACE("case_else ::= ELSE expr")
#line 542 "parse.y"
{yygotominor.yy146 = yymsp[0].minor.yy146;}
#line 6849 "parse.c"
        /* No destructor defined for ELSE */
        break;
      case 202:
        YYTRACE("case_else ::=")
#line 543 "parse.y"
{yygotominor.yy146 = 0;}
#line 6856 "parse.c"
        break;
      case 203:
        YYTRACE("case_operand ::= expr")
#line 545 "parse.y"
{yygotominor.yy146 = yymsp[0].minor.yy146;}
#line 6862 "parse.c"
        break;
      case 204:
        YYTRACE("case_operand ::=")
#line 546 "parse.y"
{yygotominor.yy146 = 0;}
#line 6868 "parse.c"
        break;
      case 205:
        YYTRACE("exprlist ::= exprlist COMMA expritem")
#line 554 "parse.y"
{yygotominor.yy144 = sqliteExprListAppend(yymsp[-2].minor.yy144,yymsp[0].minor.yy146,0);}
#line 6874 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 206:
        YYTRACE("exprlist ::= expritem")
#line 555 "parse.y"
{yygotominor.yy144 = sqliteExprListAppend(0,yymsp[0].minor.yy146,0);}
#line 6881 "parse.c"
        break;
      case 207:
        YYTRACE("expritem ::= expr")
#line 556 "parse.y"
{yygotominor.yy146 = yymsp[0].minor.yy146;}
#line 6887 "parse.c"
        break;
      case 208:
        YYTRACE("expritem ::=")
#line 557 "parse.y"
{yygotominor.yy146 = 0;}
#line 6893 "parse.c"
        break;
      case 209:
        YYTRACE("cmd ::= CREATE uniqueflag INDEX ids ON ids LP idxlist RP onconf")
#line 562 "parse.y"
{
  if( yymsp[-8].minor.yy172!=OE_None ) yymsp[-8].minor.yy172 = yymsp[0].minor.yy172;
  if( yymsp[-8].minor.yy172==OE_Default) yymsp[-8].minor.yy172 = OE_Abort;
  sqliteCreateIndex(pParse, &yymsp[-6].minor.yy210, &yymsp[-4].minor.yy210, yymsp[-2].minor.yy82, yymsp[-8].minor.yy172, &yymsp[-9].minor.yy0, &yymsp[-1].minor.yy0);
}
#line 6903 "parse.c"
        /* No destructor defined for INDEX */
        /* No destructor defined for ON */
        /* No destructor defined for LP */
        break;
      case 210:
        YYTRACE("uniqueflag ::= UNIQUE")
#line 569 "parse.y"
{ yygotominor.yy172 = OE_Abort; }
#line 6912 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 211:
        YYTRACE("uniqueflag ::=")
#line 570 "parse.y"
{ yygotominor.yy172 = OE_None; }
#line 6919 "parse.c"
        break;
      case 212:
        YYTRACE("idxlist ::= idxlist COMMA idxitem")
#line 577 "parse.y"
{yygotominor.yy82 = sqliteIdListAppend(yymsp[-2].minor.yy82,&yymsp[0].minor.yy210);}
#line 6925 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 213:
        YYTRACE("idxlist ::= idxitem")
#line 579 "parse.y"
{yygotominor.yy82 = sqliteIdListAppend(0,&yymsp[0].minor.yy210);}
#line 6932 "parse.c"
        break;
      case 214:
        YYTRACE("idxitem ::= ids")
#line 580 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy210;}
#line 6938 "parse.c"
        break;
      case 215:
        YYTRACE("cmd ::= DROP INDEX ids")
#line 585 "parse.y"
{sqliteDropIndex(pParse, &yymsp[0].minor.yy210);}
#line 6944 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for INDEX */
        break;
      case 216:
        YYTRACE("cmd ::= COPY orconf ids FROM ids USING DELIMITERS STRING")
#line 591 "parse.y"
{sqliteCopy(pParse,&yymsp[-5].minor.yy210,&yymsp[-3].minor.yy210,&yymsp[0].minor.yy0,yymsp[-6].minor.yy172);}
#line 6952 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        /* No destructor defined for USING */
        /* No destructor defined for DELIMITERS */
        break;
      case 217:
        YYTRACE("cmd ::= COPY orconf ids FROM ids")
#line 593 "parse.y"
{sqliteCopy(pParse,&yymsp[-2].minor.yy210,&yymsp[0].minor.yy210,0,yymsp[-3].minor.yy172);}
#line 6962 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        break;
      case 218:
        YYTRACE("cmd ::= VACUUM")
#line 597 "parse.y"
{sqliteVacuum(pParse,0);}
#line 6970 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 219:
        YYTRACE("cmd ::= VACUUM ids")
#line 598 "parse.y"
{sqliteVacuum(pParse,&yymsp[0].minor.yy210);}
#line 6977 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 220:
        YYTRACE("cmd ::= PRAGMA ids EQ ids")
#line 602 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy210,&yymsp[0].minor.yy210,0);}
#line 6984 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 221:
        YYTRACE("cmd ::= PRAGMA ids EQ ON")
#line 603 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy210,&yymsp[0].minor.yy0,0);}
#line 6992 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 222:
        YYTRACE("cmd ::= PRAGMA ids EQ plus_num")
#line 604 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy210,&yymsp[0].minor.yy210,0);}
#line 7000 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 223:
        YYTRACE("cmd ::= PRAGMA ids EQ minus_num")
#line 605 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy210,&yymsp[0].minor.yy210,1);}
#line 7008 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 224:
        YYTRACE("cmd ::= PRAGMA ids LP ids RP")
#line 606 "parse.y"
{sqlitePragma(pParse,&yymsp[-3].minor.yy210,&yymsp[-1].minor.yy210,0);}
#line 7016 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 225:
        YYTRACE("cmd ::= PRAGMA ids")
#line 607 "parse.y"
{sqlitePragma(pParse,&yymsp[0].minor.yy210,&yymsp[0].minor.yy210,0);}
#line 7025 "parse.c"
        /* No destructor defined for PRAGMA */
        break;
      case 226:
        YYTRACE("plus_num ::= plus_opt number")
#line 608 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy210;}
#line 7032 "parse.c"
        /* No destructor defined for plus_opt */
        break;
      case 227:
        YYTRACE("minus_num ::= MINUS number")
#line 609 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy210;}
#line 7039 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 228:
        YYTRACE("number ::= INTEGER")
#line 610 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 7046 "parse.c"
        break;
      case 229:
        YYTRACE("number ::= FLOAT")
#line 611 "parse.y"
{yygotominor.yy210 = yymsp[0].minor.yy0;}
#line 7052 "parse.c"
        break;
      case 230:
        YYTRACE("plus_opt ::= PLUS")
        /* No destructor defined for PLUS */
        break;
      case 231:
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

#line 7107 "parse.c"
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
