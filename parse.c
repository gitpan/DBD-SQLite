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
** An instance of this structure holds information about the
** LIMIT clause of a SELECT statement.
*/
struct LimitVal {
  int limit;    /* The LIMIT value.  -1 if there is no limit */
  int offset;   /* The OFFSET.  0 if there is none */
};

/*
** An instance of the following structure describes the event of a
** TRIGGER.  "a" is the event type, one of TK_UPDATE, TK_INSERT,
** TK_DELETE, or TK_INSTEAD.  If the event is of the form
**
**      UPDATE ON (a,b,c)
**
** Then the "b" IdList records the list "a,b,c".
*/
struct TrigEvent { int a; IdList * b; };

#line 33 "parse.c"
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
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
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
#define YYNOCODE 212
#define YYACTIONTYPE unsigned short int
#define sqliteParserTOKENTYPE Token
typedef union {
  sqliteParserTOKENTYPE yy0;
  int yy6;
  struct {int value; int mask;} yy33;
  struct LimitVal yy70;
  Expr * yy122;
  Expr* yy154;
  SrcList* yy159;
  IdList* yy208;
  Select* yy331;
  ExprList* yy354;
  Token yy356;
  TriggerStep * yy391;
  struct TrigEvent yy398;
  int yy423;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define sqliteParserARG_SDECL Parse *pParse;
#define sqliteParserARG_PDECL ,Parse *pParse
#define sqliteParserARG_FETCH Parse *pParse = yypParser->pParse
#define sqliteParserARG_STORE yypParser->pParse = pParse
#define YYNSTATE 529
#define YYNRULE 278
#define YYERRORSYMBOL 148
#define YYERRSYMDT yy423
#define YYFALLBACK 1
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
  { 103,   0, 526}, /*  1:                   SEMI shift  526 */
  { 163,   1, 808}, /*  2:                  input accept */
  {  44,   0, 527}, /*  3:                EXPLAIN shift  527 */
  { 147,   5, 528}, /*  4:                   ecmd shift  528 */
  { 135,   0,   1}, /*  5:                cmdlist shift  1 */
  { 149,   0,   3}, /*  6:                explain shift  3 */
/* State 1 */
  {   0,   0, 529}, /*  1:                      $ reduce 0 */
  {  44,   0, 527}, /*  2:                EXPLAIN shift  527 */
  { 147,   0,   2}, /*  3:                   ecmd shift  2 */
  { 103,   0, 526}, /*  4:                   SEMI shift  526 */
  { 149,   2,   3}, /*  5:                explain shift  3 */
/* State 3 */
  { 190,   0, 476}, /*  1:                 select shift  476 */
  { 134,  11,   4}, /*  2:                    cmd shift  4 */
  {  40,   0,  24}, /*  3:                    END shift  24 */
  {  98,   0,  26}, /*  4:               ROLLBACK shift  26 */
  {  23,   0,  22}, /*  5:                 COMMIT shift  22 */
  { 119,   0, 481}, /*  6:                 UPDATE shift  481 */
  {  63,   0, 496}, /*  7:                 INSERT shift  496 */
  { 102,   0,  72}, /*  8:                 SELECT shift  72 */
  { 179,  12,  68}, /*  9:              oneselect shift  68 */
  { 142,  13,  28}, /* 10:           create_table shift  28 */
  {  96,   0, 498}, /* 11:                REPLACE shift  498 */
  { 122,  17, 507}, /* 12:                 VACUUM shift  507 */
  {  28,  18, 380}, /* 13:                 CREATE shift  380 */
  {  32,   0, 477}, /* 14:                 DELETE shift  477 */
  { 166,   0, 487}, /* 15:             insert_cmd shift  487 */
  {  91,   0, 509}, /* 16:                 PRAGMA shift  509 */
  {  27,   0, 499}, /* 17:                   COPY shift  499 */
  {   9,   0,   6}, /* 18:                  BEGIN shift  6 */
  {  37,   0, 467}, /* 19:                   DROP shift  467 */
/* State 4 */
  { 103,   0,   5}, /*  1:                   SEMI shift  5 */
/* State 6 */
  { 200,   0,   7}, /*  1:              trans_opt shift  7 */
  { 113,   0,  17}, /*  2:            TRANSACTION shift  17 */
/* State 7 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 178,   3,   8}, /*  2:                 onconf shift  8 */
  { 103,   0, 616}, /*  3:                   SEMI reduce 87 */
/* State 8 */
  { 103,   0, 536}, /*  1:                   SEMI reduce 7 */
/* State 9 */
  {  25,   0,  10}, /*  1:               CONFLICT shift  10 */
/* State 10 */
  {  96,   0,  16}, /*  1:                REPLACE shift  16 */
  { 187,   5,  11}, /*  2:            resolvetype shift  11 */
  {  98,   0,  12}, /*  3:               ROLLBACK shift  12 */
  {  57,   6,  15}, /*  4:                 IGNORE shift  15 */
  {   1,   0,  13}, /*  5:                  ABORT shift  13 */
  {  45,   0,  14}, /*  6:                   FAIL shift  14 */
/* State 17 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3,  18}, /*  4:                     nm shift  18 */
/* State 22 */
  { 113,   0,  17}, /*  1:            TRANSACTION shift  17 */
  { 103,   0, 537}, /*  2:                   SEMI reduce 8 */
  { 200,   1,  23}, /*  3:              trans_opt shift  23 */
/* State 23 */
  { 103,   0, 540}, /*  1:                   SEMI reduce 11 */
/* State 24 */
  { 113,   0,  17}, /*  1:            TRANSACTION shift  17 */
  { 103,   0, 537}, /*  2:                   SEMI reduce 8 */
  { 200,   1,  25}, /*  3:              trans_opt shift  25 */
/* State 25 */
  { 103,   0, 541}, /*  1:                   SEMI reduce 12 */
/* State 26 */
  { 113,   0,  17}, /*  1:            TRANSACTION shift  17 */
  { 103,   0, 537}, /*  2:                   SEMI reduce 8 */
  { 200,   1,  27}, /*  3:              trans_opt shift  27 */
/* State 27 */
  { 103,   0, 542}, /*  1:                   SEMI reduce 13 */
/* State 28 */
  {   6,   0, 378}, /*  1:                     AS shift  378 */
  {  76,   0,  30}, /*  2:                     LP shift  30 */
  { 143,   0,  29}, /*  3:      create_table_args shift  29 */
/* State 29 */
  { 103,   0, 543}, /*  1:                   SEMI reduce 14 */
/* State 30 */
  { 175,   3, 343}, /*  1:                     nm shift  343 */
  {  71,   0,  21}, /*  2:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 109,   0,  20}, /*  4:                 STRING shift  20 */
  { 137,   4, 377}, /*  5:                 column shift  377 */
  { 138,   0,  36}, /*  6:               columnid shift  36 */
  { 139,   0,  31}, /*  7:             columnlist shift  31 */
/* State 31 */
  { 141,   3,  32}, /*  1:           conslist_opt shift  32 */
  { 100,   0, 604}, /*  2:                     RP reduce 75 */
  {  21,   0,  34}, /*  3:                  COMMA shift  34 */
/* State 32 */
  { 100,   0,  33}, /*  1:                     RP shift  33 */
/* State 33 */
  { 103,   0, 547}, /*  1:                   SEMI reduce 18 */
/* State 34 */
  {  26,   0, 347}, /*  1:             CONSTRAINT shift  347 */
  { 118,   3, 355}, /*  2:                 UNIQUE shift  355 */
  {  92,   0, 349}, /*  3:                PRIMARY shift  349 */
  { 198,   0, 376}, /*  4:                  tcons shift  376 */
  {  56,  12,  19}, /*  5:                     ID shift  19 */
  { 109,   0,  20}, /*  6:                 STRING shift  20 */
  { 175,  13, 343}, /*  7:                     nm shift  343 */
  { 137,   0,  35}, /*  8:                 column shift  35 */
  { 138,   0,  36}, /*  9:               columnid shift  36 */
  {  48,   0, 363}, /* 10:                FOREIGN shift  363 */
  { 140,   0, 344}, /* 11:               conslist shift  344 */
  {  17,   0, 360}, /* 12:                  CHECK shift  360 */
  {  71,   0,  21}, /* 13:                JOIN_KW shift  21 */
/* State 36 */
  { 205,   0,  37}, /*  1:                   type shift  37 */
  { 206,   3, 329}, /*  2:               typename shift  329 */
  {  56,   0, 246}, /*  3:                     ID shift  246 */
  { 158,   0, 342}, /*  4:                    ids shift  342 */
  { 109,   0, 247}, /*  5:                 STRING shift  247 */
/* State 37 */
  { 129,   0,  38}, /*  1:               carglist shift  38 */
/* State 38 */
  {  26,   0,  40}, /*  1:             CONSTRAINT shift  40 */
  { 144,   3, 311}, /*  2:        defer_subclause shift  311 */
  { 118,   6,  59}, /*  3:                 UNIQUE shift  59 */
  { 133,   8, 316}, /*  4:                  ccons shift  316 */
  {  82,   9,  45}, /*  5:                    NOT shift  45 */
  {  92,   0,  53}, /*  6:                PRIMARY shift  53 */
  {  84,  10,  43}, /*  7:                   NULL shift  43 */
  {  94,  11, 289}, /*  8:             REFERENCES shift  289 */
  {  30,  13, 314}, /*  9:             DEFERRABLE shift  314 */
  {  19,   0, 312}, /* 10:                COLLATE shift  312 */
  {  29,   0, 317}, /* 11:                DEFAULT shift  317 */
  { 128,   0,  39}, /* 12:                   carg shift  39 */
  {  17,   0,  61}, /* 13:                  CHECK shift  61 */
/* State 40 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3,  41}, /*  4:                     nm shift  41 */
/* State 41 */
  {  30,   0, 314}, /*  1:             DEFERRABLE shift  314 */
  {  82,   0,  45}, /*  2:                    NOT shift  45 */
  {  92,   2,  53}, /*  3:                PRIMARY shift  53 */
  { 133,   0,  42}, /*  4:                  ccons shift  42 */
  { 144,   6, 311}, /*  5:        defer_subclause shift  311 */
  {  94,   7, 289}, /*  6:             REFERENCES shift  289 */
  {  84,   0,  43}, /*  7:                   NULL shift  43 */
  {  17,   0,  61}, /*  8:                  CHECK shift  61 */
  { 118,   0,  59}, /*  9:                 UNIQUE shift  59 */
  {  19,   0, 312}, /* 10:                COLLATE shift  312 */
/* State 43 */
  { 178,   0,  44}, /*  1:                 onconf shift  44 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 45 */
  {  84,   2,  46}, /*  1:                   NULL shift  46 */
  {  30,   0,  48}, /*  2:             DEFERRABLE shift  48 */
/* State 46 */
  { 178,   0,  47}, /*  1:                 onconf shift  47 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 48 */
  { 162,   2,  49}, /*  1: init_deferred_pred_opt shift  49 */
  {  62,   0,  50}, /*  2:              INITIALLY shift  50 */
/* State 50 */
  {  31,   0,  51}, /*  1:               DEFERRED shift  51 */
  {  59,   1,  52}, /*  2:              IMMEDIATE shift  52 */
/* State 53 */
  {  72,   0,  54}, /*  1:                    KEY shift  54 */
/* State 54 */
  {  34,   3,  58}, /*  1:                   DESC shift  58 */
  { 196,   1,  55}, /*  2:              sortorder shift  55 */
  {   7,   0,  57}, /*  3:                    ASC shift  57 */
/* State 55 */
  { 178,   0,  56}, /*  1:                 onconf shift  56 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 59 */
  { 178,   0,  60}, /*  1:                 onconf shift  60 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 61 */
  {  76,   0,  62}, /*  1:                     LP shift  62 */
/* State 62 */
  { 150,   3, 286}, /*  1:                   expr shift  286 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 63 */
  {  76,   2,  64}, /*  1:                     LP shift  64 */
  {  36,   0, 556}, /*  2:                    DOT reduce 27 */
/* State 64 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  { 109,   0,  65}, /*  2:                 STRING shift  65 */
  {  56,   0,  63}, /*  3:                     ID shift  63 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  {  76,   0,  67}, /*  5:                     LP shift  67 */
  {  80,   0, 170}, /*  6:                  MINUS shift  170 */
  { 150,   0, 165}, /*  7:                   expr shift  165 */
  { 151,   0, 210}, /*  8:               expritem shift  210 */
  { 152,   6, 282}, /*  9:               exprlist shift  282 */
  {  46,   0, 104}, /* 10:                  FLOAT shift  104 */
  {  82,  10, 166}, /* 11:                    NOT shift  166 */
  {  65,   0, 103}, /* 12:                INTEGER shift  103 */
  {  84,  15,  99}, /* 13:                   NULL shift  99 */
  { 175,   0, 100}, /* 14:                     nm shift  100 */
  {  12,   0, 168}, /* 15:                 BITNOT shift  168 */
  {  71,   0,  66}, /* 16:                JOIN_KW shift  66 */
  {  16,   0, 174}, /* 17:                   CASE shift  174 */
  { 107,  16, 284}, /* 18:                   STAR shift  284 */
/* State 65 */
  {  36,   0, 557}, /*  1:                    DOT reduce 28 */
/* State 66 */
  {  36,   0, 558}, /*  1:                    DOT reduce 29 */
/* State 67 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  { 109,   0,  65}, /*  2:                 STRING shift  65 */
  {  56,   0,  63}, /*  3:                     ID shift  63 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  {  76,   0,  67}, /*  5:                     LP shift  67 */
  {  82,   8, 166}, /*  6:                    NOT shift  166 */
  { 150,   0, 280}, /*  7:                   expr shift  280 */
  {  46,   0, 104}, /*  8:                  FLOAT shift  104 */
  {  80,   0, 170}, /*  9:                  MINUS shift  170 */
  {  84,  15,  99}, /* 10:                   NULL shift  99 */
  { 190,   6,  69}, /* 11:                 select shift  69 */
  {  65,   0, 103}, /* 12:                INTEGER shift  103 */
  { 102,  10,  72}, /* 13:                 SELECT shift  72 */
  { 175,   0, 100}, /* 14:                     nm shift  100 */
  {  12,   0, 168}, /* 15:                 BITNOT shift  168 */
  {  71,   0,  66}, /* 16:                JOIN_KW shift  66 */
  {  16,   0, 174}, /* 17:                   CASE shift  174 */
  { 179,  16,  68}, /* 18:              oneselect shift  68 */
/* State 69 */
  { 100,   0, 279}, /*  1:                     RP shift  279 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 117,   0, 160}, /*  3:                  UNION shift  160 */
  {  43,   0, 163}, /*  4:                 EXCEPT shift  163 */
  { 174,   0,  70}, /*  5:         multiselect_op shift  70 */
/* State 70 */
  { 102,   0,  72}, /*  1:                 SELECT shift  72 */
  { 179,   0,  71}, /*  2:              oneselect shift  71 */
/* State 72 */
  {  35,   0, 277}, /*  1:               DISTINCT shift  277 */
  {   4,   0, 278}, /*  2:                    ALL shift  278 */
  { 146,   1,  73}, /*  3:               distinct shift  73 */
/* State 73 */
  { 188,   0, 270}, /*  1:                   sclp shift  270 */
  { 189,   0,  74}, /*  2:             selcollist shift  74 */
/* State 74 */
  {  21,   0, 232}, /*  1:                  COMMA shift  232 */
  { 154,   3,  75}, /*  2:                   from shift  75 */
  {  49,   0, 233}, /*  3:                   FROM shift  233 */
/* State 75 */
  { 210,   2,  76}, /*  1:              where_opt shift  76 */
  { 126,   0, 230}, /*  2:                  WHERE shift  230 */
/* State 76 */
  {  53,   0, 227}, /*  1:                  GROUP shift  227 */
  { 155,   1,  77}, /*  2:            groupby_opt shift  77 */
/* State 77 */
  { 156,   0,  78}, /*  1:             having_opt shift  78 */
  {  55,   0, 225}, /*  2:                 HAVING shift  225 */
/* State 78 */
  {  89,   0,  87}, /*  1:                  ORDER shift  87 */
  { 181,   1,  79}, /*  2:            orderby_opt shift  79 */
/* State 79 */
  {  75,   0,  81}, /*  1:                  LIMIT shift  81 */
  { 171,   1,  80}, /*  2:              limit_opt shift  80 */
/* State 81 */
  {  65,   0,  82}, /*  1:                INTEGER shift  82 */
/* State 82 */
  {  21,   0,  86}, /*  1:                  COMMA shift  86 */
  { 172,   0,  83}, /*  2:              limit_sep shift  83 */
  {  86,   0,  85}, /*  3:                 OFFSET shift  85 */
/* State 83 */
  {  65,   0,  84}, /*  1:                INTEGER shift  84 */
/* State 85 */
  {  65,   0, 679}, /*  1:                INTEGER reduce 150 */
/* State 86 */
  {  65,   0, 680}, /*  1:                INTEGER reduce 151 */
/* State 87 */
  {  14,   0,  88}, /*  1:                     BY shift  88 */
/* State 88 */
  {  90,   2, 172}, /*  1:                   PLUS shift  172 */
  {  56,   0,  63}, /*  2:                     ID shift  63 */
  { 109,   0,  65}, /*  3:                 STRING shift  65 */
  {  71,   0,  66}, /*  4:                JOIN_KW shift  66 */
  {  93,   7, 184}, /*  5:                  RAISE shift  184 */
  { 175,   1, 100}, /*  6:                     nm shift  100 */
  {  76,   0,  67}, /*  7:                     LP shift  67 */
  { 194,   3, 222}, /*  8:               sortitem shift  222 */
  { 195,   5,  89}, /*  9:               sortlist shift  89 */
  {  46,  11, 104}, /* 10:                  FLOAT shift  104 */
  {  12,   0, 168}, /* 11:                 BITNOT shift  168 */
  {  82,  14, 166}, /* 12:                    NOT shift  166 */
  {  80,  10, 170}, /* 13:                  MINUS shift  170 */
  {  65,   0, 103}, /* 14:                INTEGER shift  103 */
  { 150,  12,  97}, /* 15:                   expr shift  97 */
  {  16,   0, 174}, /* 16:                   CASE shift  174 */
  {  84,  16,  99}, /* 17:                   NULL shift  99 */
/* State 89 */
  {  21,   0,  90}, /*  1:                  COMMA shift  90 */
/* State 90 */
  {  80,   4, 170}, /*  1:                  MINUS shift  170 */
  {  65,   0, 103}, /*  2:                INTEGER shift  103 */
  { 194,   6,  91}, /*  3:               sortitem shift  91 */
  {  16,   0, 174}, /*  4:                   CASE shift  174 */
  {  84,   0,  99}, /*  5:                   NULL shift  99 */
  {  82,   0, 166}, /*  6:                    NOT shift  166 */
  { 150,   0,  97}, /*  7:                   expr shift  97 */
  {  71,   0,  66}, /*  8:                JOIN_KW shift  66 */
  {  56,   0,  63}, /*  9:                     ID shift  63 */
  {  12,   0, 168}, /* 10:                 BITNOT shift  168 */
  {  90,   0, 172}, /* 11:                   PLUS shift  172 */
  {  93,   0, 184}, /* 12:                  RAISE shift  184 */
  {  76,  10,  67}, /* 13:                     LP shift  67 */
  { 109,  12,  65}, /* 14:                 STRING shift  65 */
  {  46,   0, 104}, /* 15:                  FLOAT shift  104 */
  { 175,   0, 100}, /* 16:                     nm shift  100 */
/* State 91 */
  { 136,   0,  92}, /*  1:                collate shift  92 */
  {  19,   0,  94}, /*  2:                COLLATE shift  94 */
/* State 92 */
  {  34,   3,  58}, /*  1:                   DESC shift  58 */
  { 196,   1,  93}, /*  2:              sortorder shift  93 */
  {   7,   0,  57}, /*  3:                    ASC shift  57 */
/* State 94 */
  {  56,   0,  95}, /*  1:                     ID shift  95 */
  { 157,   0,  96}, /*  2:                     id shift  96 */
/* State 97 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  60,   0, 157}, /*  7:                     IN shift  157 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  { 170,   0, 128}, /*  9:                 likeop shift  128 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   5, 143}, /* 15:                    REM shift  143 */
  {  69,  13, 147}, /* 16:                 ISNULL shift  147 */
  {  74,   0, 133}, /* 17:                   LIKE shift  133 */
  {  78,  19, 108}, /* 18:                     LT shift  108 */
  {  51,  22, 114}, /* 19:                     GE shift  114 */
  {  73,   0, 112}, /* 20:                     LE shift  112 */
  { 101,  17, 126}, /* 21:                 RSHIFT shift  126 */
  {  24,   0, 145}, /* 22:                 CONCAT shift  145 */
  {  80,   0, 137}, /* 23:                  MINUS shift  137 */
  {  77,   0, 124}, /* 24:                 LSHIFT shift  124 */
  { 105,  18, 141}, /* 25:                  SLASH shift  141 */
  {  52,   0, 134}, /* 26:                   GLOB shift  134 */
  { 107,  23, 139}, /* 27:                   STAR shift  139 */
/* State 98 */
  { 150,   3, 105}, /*  1:                   expr shift  105 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 100 */
  {  36,   0, 101}, /*  1:                    DOT shift  101 */
/* State 101 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 102}, /*  4:                     nm shift  102 */
/* State 105 */
  {  51,   0, 114}, /*  1:                     GE shift  114 */
  { 101,   1, 126}, /*  2:                 RSHIFT shift  126 */
  {  77,  10, 124}, /*  3:                 LSHIFT shift  124 */
  {  78,   0, 108}, /*  4:                     LT shift  108 */
  {  54,   0, 110}, /*  5:                     GT shift  110 */
  { 105,  13, 141}, /*  6:                  SLASH shift  141 */
  {  81,   0, 116}, /*  7:                     NE shift  116 */
  { 107,  15, 139}, /*  8:                   STAR shift  139 */
  {  83,   0, 152}, /*  9:                NOTNULL shift  152 */
  {  52,   0, 134}, /* 10:                   GLOB shift  134 */
  {  60,  17, 157}, /* 11:                     IN shift  157 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  80,   0, 137}, /* 13:                  MINUS shift  137 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  82,   0, 130}, /* 15:                    NOT shift  130 */
  {  90,   0, 135}, /* 16:                   PLUS shift  135 */
  {  10,   0, 153}, /* 17:                BETWEEN shift  153 */
  {  42,   0, 118}, /* 18:                     EQ shift  118 */
  {  68,   0, 148}, /* 19:                     IS shift  148 */
  {  69,   0, 147}, /* 20:                 ISNULL shift  147 */
  { 170,  22, 128}, /* 21:                 likeop shift  128 */
  {  95,   0, 143}, /* 22:                    REM shift  143 */
  {  24,   0, 145}, /* 23:                 CONCAT shift  145 */
  {  73,   0, 112}, /* 24:                     LE shift  112 */
  {  74,  23, 133}, /* 25:                   LIKE shift  133 */
/* State 106 */
  { 150,   3, 107}, /*  1:                   expr shift  107 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 107 */
  {  78,   7, 108}, /*  1:                     LT shift  108 */
  { 105,   0, 141}, /*  2:                  SLASH shift  141 */
  {  80,   8, 137}, /*  3:                  MINUS shift  137 */
  { 107,  10, 139}, /*  4:                   STAR shift  139 */
  {  82,   0, 130}, /*  5:                    NOT shift  130 */
  {  83,  16, 152}, /*  6:                NOTNULL shift  152 */
  {  52,   0, 134}, /*  7:                   GLOB shift  134 */
  {  54,   0, 110}, /*  8:                     GT shift  110 */
  {  60,   0, 157}, /*  9:                     IN shift  157 */
  {  81,   0, 116}, /* 10:                     NE shift  116 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  90,   0, 135}, /* 13:                   PLUS shift  135 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  { 170,   0, 128}, /* 15:                 likeop shift  128 */
  {   5,   0,  98}, /* 16:                    AND shift  98 */
  {  68,  19, 148}, /* 17:                     IS shift  148 */
  {  95,  20, 143}, /* 18:                    REM shift  143 */
  {  42,   0, 118}, /* 19:                     EQ shift  118 */
  {  69,   0, 147}, /* 20:                 ISNULL shift  147 */
  {  51,   0, 114}, /* 21:                     GE shift  114 */
  {  73,   0, 112}, /* 22:                     LE shift  112 */
  {  74,   0, 133}, /* 23:                   LIKE shift  133 */
  { 101,   0, 126}, /* 24:                 RSHIFT shift  126 */
  {  24,   0, 145}, /* 25:                 CONCAT shift  145 */
  {  77,  21, 124}, /* 26:                 LSHIFT shift  124 */
/* State 108 */
  { 150,   3, 109}, /*  1:                   expr shift  109 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 109 */
  {  77,   2, 124}, /*  1:                 LSHIFT shift  124 */
  {  11,   0, 120}, /*  2:                 BITAND shift  120 */
  { 101,   5, 126}, /*  3:                 RSHIFT shift  126 */
  {  80,   0, 137}, /*  4:                  MINUS shift  137 */
  {  90,  10, 135}, /*  5:                   PLUS shift  135 */
  { 170,   0, 128}, /*  6:                 likeop shift  128 */
  { 105,   0, 141}, /*  7:                  SLASH shift  141 */
  {  95,   0, 143}, /*  8:                    REM shift  143 */
  { 107,   0, 139}, /*  9:                   STAR shift  139 */
  {  24,  11, 145}, /* 10:                 CONCAT shift  145 */
  {  13,   0, 122}, /* 11:                  BITOR shift  122 */
/* State 110 */
  { 150,   3, 111}, /*  1:                   expr shift  111 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 111 */
  {  77,   2, 124}, /*  1:                 LSHIFT shift  124 */
  {  11,   0, 120}, /*  2:                 BITAND shift  120 */
  { 101,   5, 126}, /*  3:                 RSHIFT shift  126 */
  {  80,   0, 137}, /*  4:                  MINUS shift  137 */
  {  90,  10, 135}, /*  5:                   PLUS shift  135 */
  { 170,   0, 128}, /*  6:                 likeop shift  128 */
  { 105,   0, 141}, /*  7:                  SLASH shift  141 */
  {  95,   0, 143}, /*  8:                    REM shift  143 */
  { 107,   0, 139}, /*  9:                   STAR shift  139 */
  {  24,  11, 145}, /* 10:                 CONCAT shift  145 */
  {  13,   0, 122}, /* 11:                  BITOR shift  122 */
/* State 112 */
  { 150,   3, 113}, /*  1:                   expr shift  113 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 113 */
  {  77,   2, 124}, /*  1:                 LSHIFT shift  124 */
  {  11,   0, 120}, /*  2:                 BITAND shift  120 */
  { 101,   5, 126}, /*  3:                 RSHIFT shift  126 */
  {  80,   0, 137}, /*  4:                  MINUS shift  137 */
  {  90,  10, 135}, /*  5:                   PLUS shift  135 */
  { 170,   0, 128}, /*  6:                 likeop shift  128 */
  { 105,   0, 141}, /*  7:                  SLASH shift  141 */
  {  95,   0, 143}, /*  8:                    REM shift  143 */
  { 107,   0, 139}, /*  9:                   STAR shift  139 */
  {  24,  11, 145}, /* 10:                 CONCAT shift  145 */
  {  13,   0, 122}, /* 11:                  BITOR shift  122 */
/* State 114 */
  { 150,   3, 115}, /*  1:                   expr shift  115 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 115 */
  {  77,   2, 124}, /*  1:                 LSHIFT shift  124 */
  {  11,   0, 120}, /*  2:                 BITAND shift  120 */
  { 101,   5, 126}, /*  3:                 RSHIFT shift  126 */
  {  80,   0, 137}, /*  4:                  MINUS shift  137 */
  {  90,  10, 135}, /*  5:                   PLUS shift  135 */
  { 170,   0, 128}, /*  6:                 likeop shift  128 */
  { 105,   0, 141}, /*  7:                  SLASH shift  141 */
  {  95,   0, 143}, /*  8:                    REM shift  143 */
  { 107,   0, 139}, /*  9:                   STAR shift  139 */
  {  24,  11, 145}, /* 10:                 CONCAT shift  145 */
  {  13,   0, 122}, /* 11:                  BITOR shift  122 */
/* State 116 */
  { 150,   3, 117}, /*  1:                   expr shift  117 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 117 */
  { 105,   2, 141}, /*  1:                  SLASH shift  141 */
  {  90,   0, 135}, /*  2:                   PLUS shift  135 */
  { 107,   5, 139}, /*  3:                   STAR shift  139 */
  {  78,   0, 108}, /*  4:                     LT shift  108 */
  {  77,   0, 124}, /*  5:                 LSHIFT shift  124 */
  { 170,   8, 128}, /*  6:                 likeop shift  128 */
  {  51,   0, 114}, /*  7:                     GE shift  114 */
  {  95,   9, 143}, /*  8:                    REM shift  143 */
  {  80,   0, 137}, /*  9:                  MINUS shift  137 */
  {  54,  11, 110}, /* 10:                     GT shift  110 */
  {  24,   0, 145}, /* 11:                 CONCAT shift  145 */
  { 101,  13, 126}, /* 12:                 RSHIFT shift  126 */
  {  11,   0, 120}, /* 13:                 BITAND shift  120 */
  {  73,  15, 112}, /* 14:                     LE shift  112 */
  {  13,   0, 122}, /* 15:                  BITOR shift  122 */
/* State 118 */
  { 150,   3, 119}, /*  1:                   expr shift  119 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 119 */
  { 105,   2, 141}, /*  1:                  SLASH shift  141 */
  {  90,   0, 135}, /*  2:                   PLUS shift  135 */
  { 107,   5, 139}, /*  3:                   STAR shift  139 */
  {  78,   0, 108}, /*  4:                     LT shift  108 */
  {  77,   0, 124}, /*  5:                 LSHIFT shift  124 */
  { 170,   8, 128}, /*  6:                 likeop shift  128 */
  {  51,   0, 114}, /*  7:                     GE shift  114 */
  {  95,   9, 143}, /*  8:                    REM shift  143 */
  {  80,   0, 137}, /*  9:                  MINUS shift  137 */
  {  54,  11, 110}, /* 10:                     GT shift  110 */
  {  24,   0, 145}, /* 11:                 CONCAT shift  145 */
  { 101,  13, 126}, /* 12:                 RSHIFT shift  126 */
  {  11,   0, 120}, /* 13:                 BITAND shift  120 */
  {  73,  15, 112}, /* 14:                     LE shift  112 */
  {  13,   0, 122}, /* 15:                  BITOR shift  122 */
/* State 120 */
  { 150,   3, 121}, /*  1:                   expr shift  121 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 121 */
  { 105,   0, 141}, /*  1:                  SLASH shift  141 */
  { 107,   0, 139}, /*  2:                   STAR shift  139 */
  { 170,   2, 128}, /*  3:                 likeop shift  128 */
  {  80,   6, 137}, /*  4:                  MINUS shift  137 */
  {  95,   0, 143}, /*  5:                    REM shift  143 */
  {  24,   0, 145}, /*  6:                 CONCAT shift  145 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
/* State 122 */
  { 150,   3, 123}, /*  1:                   expr shift  123 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 123 */
  { 105,   0, 141}, /*  1:                  SLASH shift  141 */
  { 107,   0, 139}, /*  2:                   STAR shift  139 */
  { 170,   2, 128}, /*  3:                 likeop shift  128 */
  {  80,   6, 137}, /*  4:                  MINUS shift  137 */
  {  95,   0, 143}, /*  5:                    REM shift  143 */
  {  24,   0, 145}, /*  6:                 CONCAT shift  145 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
/* State 124 */
  { 150,   3, 125}, /*  1:                   expr shift  125 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 125 */
  { 105,   0, 141}, /*  1:                  SLASH shift  141 */
  { 107,   0, 139}, /*  2:                   STAR shift  139 */
  { 170,   2, 128}, /*  3:                 likeop shift  128 */
  {  80,   6, 137}, /*  4:                  MINUS shift  137 */
  {  95,   0, 143}, /*  5:                    REM shift  143 */
  {  24,   0, 145}, /*  6:                 CONCAT shift  145 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
/* State 126 */
  { 150,   3, 127}, /*  1:                   expr shift  127 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 127 */
  { 105,   0, 141}, /*  1:                  SLASH shift  141 */
  { 107,   0, 139}, /*  2:                   STAR shift  139 */
  { 170,   2, 128}, /*  3:                 likeop shift  128 */
  {  80,   6, 137}, /*  4:                  MINUS shift  137 */
  {  95,   0, 143}, /*  5:                    REM shift  143 */
  {  24,   0, 145}, /*  6:                 CONCAT shift  145 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
/* State 128 */
  { 150,   3, 129}, /*  1:                   expr shift  129 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 129 */
  { 105,   2, 141}, /*  1:                  SLASH shift  141 */
  {  90,   0, 135}, /*  2:                   PLUS shift  135 */
  { 107,   5, 139}, /*  3:                   STAR shift  139 */
  {  78,   0, 108}, /*  4:                     LT shift  108 */
  {  77,   0, 124}, /*  5:                 LSHIFT shift  124 */
  { 170,   8, 128}, /*  6:                 likeop shift  128 */
  {  51,   0, 114}, /*  7:                     GE shift  114 */
  {  95,   9, 143}, /*  8:                    REM shift  143 */
  {  80,   0, 137}, /*  9:                  MINUS shift  137 */
  {  54,  11, 110}, /* 10:                     GT shift  110 */
  {  24,   0, 145}, /* 11:                 CONCAT shift  145 */
  { 101,  13, 126}, /* 12:                 RSHIFT shift  126 */
  {  11,   0, 120}, /* 13:                 BITAND shift  120 */
  {  73,  15, 112}, /* 14:                     LE shift  112 */
  {  13,   0, 122}, /* 15:                  BITOR shift  122 */
/* State 130 */
  {  84,   2, 211}, /*  1:                   NULL shift  211 */
  {  60,   0, 216}, /*  2:                     IN shift  216 */
  { 170,   4, 131}, /*  3:                 likeop shift  131 */
  {  74,   0, 133}, /*  4:                   LIKE shift  133 */
  {  52,   6, 134}, /*  5:                   GLOB shift  134 */
  {  10,   0, 212}, /*  6:                BETWEEN shift  212 */
/* State 131 */
  { 150,   3, 132}, /*  1:                   expr shift  132 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 132 */
  { 105,   2, 141}, /*  1:                  SLASH shift  141 */
  {  90,   0, 135}, /*  2:                   PLUS shift  135 */
  { 107,   5, 139}, /*  3:                   STAR shift  139 */
  {  78,   0, 108}, /*  4:                     LT shift  108 */
  {  77,   0, 124}, /*  5:                 LSHIFT shift  124 */
  { 170,   8, 128}, /*  6:                 likeop shift  128 */
  {  51,   0, 114}, /*  7:                     GE shift  114 */
  {  95,   9, 143}, /*  8:                    REM shift  143 */
  {  80,   0, 137}, /*  9:                  MINUS shift  137 */
  {  54,  11, 110}, /* 10:                     GT shift  110 */
  {  24,   0, 145}, /* 11:                 CONCAT shift  145 */
  { 101,  13, 126}, /* 12:                 RSHIFT shift  126 */
  {  11,   0, 120}, /* 13:                 BITAND shift  120 */
  {  73,  15, 112}, /* 14:                     LE shift  112 */
  {  13,   0, 122}, /* 15:                  BITOR shift  122 */
/* State 135 */
  { 150,   3, 136}, /*  1:                   expr shift  136 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 136 */
  { 170,   2, 128}, /*  1:                 likeop shift  128 */
  { 105,   4, 141}, /*  2:                  SLASH shift  141 */
  { 107,   0, 139}, /*  3:                   STAR shift  139 */
  {  95,   0, 143}, /*  4:                    REM shift  143 */
  {  24,   0, 145}, /*  5:                 CONCAT shift  145 */
/* State 137 */
  { 150,   3, 138}, /*  1:                   expr shift  138 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 138 */
  { 170,   2, 128}, /*  1:                 likeop shift  128 */
  { 105,   4, 141}, /*  2:                  SLASH shift  141 */
  { 107,   0, 139}, /*  3:                   STAR shift  139 */
  {  95,   0, 143}, /*  4:                    REM shift  143 */
  {  24,   0, 145}, /*  5:                 CONCAT shift  145 */
/* State 139 */
  { 150,   3, 140}, /*  1:                   expr shift  140 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 140 */
  { 170,   2, 128}, /*  1:                 likeop shift  128 */
  {  24,   0, 145}, /*  2:                 CONCAT shift  145 */
/* State 141 */
  { 150,   3, 142}, /*  1:                   expr shift  142 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 142 */
  { 170,   2, 128}, /*  1:                 likeop shift  128 */
  {  24,   0, 145}, /*  2:                 CONCAT shift  145 */
/* State 143 */
  { 150,   3, 144}, /*  1:                   expr shift  144 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 144 */
  { 170,   2, 128}, /*  1:                 likeop shift  128 */
  {  24,   0, 145}, /*  2:                 CONCAT shift  145 */
/* State 145 */
  { 150,   3, 146}, /*  1:                   expr shift  146 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 146 */
  { 170,   0, 128}, /*  1:                 likeop shift  128 */
/* State 148 */
  {  84,   2, 149}, /*  1:                   NULL shift  149 */
  {  82,   0, 150}, /*  2:                    NOT shift  150 */
/* State 150 */
  {  84,   0, 151}, /*  1:                   NULL shift  151 */
/* State 153 */
  { 150,   3, 154}, /*  1:                   expr shift  154 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 154 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  {   5,   0, 155}, /*  6:                    AND shift  155 */
  {  60,   0, 157}, /*  7:                     IN shift  157 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  { 170,   0, 128}, /*  9:                 likeop shift  128 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   5, 143}, /* 15:                    REM shift  143 */
  {  69,  13, 147}, /* 16:                 ISNULL shift  147 */
  {  74,   0, 133}, /* 17:                   LIKE shift  133 */
  {  78,  19, 108}, /* 18:                     LT shift  108 */
  {  51,  22, 114}, /* 19:                     GE shift  114 */
  {  73,   0, 112}, /* 20:                     LE shift  112 */
  { 101,  17, 126}, /* 21:                 RSHIFT shift  126 */
  {  24,   0, 145}, /* 22:                 CONCAT shift  145 */
  {  80,   0, 137}, /* 23:                  MINUS shift  137 */
  {  77,   0, 124}, /* 24:                 LSHIFT shift  124 */
  { 105,  18, 141}, /* 25:                  SLASH shift  141 */
  {  52,   0, 134}, /* 26:                   GLOB shift  134 */
  { 107,  23, 139}, /* 27:                   STAR shift  139 */
/* State 155 */
  { 150,   3, 156}, /*  1:                   expr shift  156 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 156 */
  { 105,   2, 141}, /*  1:                  SLASH shift  141 */
  {  90,   0, 135}, /*  2:                   PLUS shift  135 */
  { 107,   5, 139}, /*  3:                   STAR shift  139 */
  {  78,   0, 108}, /*  4:                     LT shift  108 */
  {  77,   0, 124}, /*  5:                 LSHIFT shift  124 */
  { 170,   8, 128}, /*  6:                 likeop shift  128 */
  {  51,   0, 114}, /*  7:                     GE shift  114 */
  {  95,   9, 143}, /*  8:                    REM shift  143 */
  {  80,   0, 137}, /*  9:                  MINUS shift  137 */
  {  54,  11, 110}, /* 10:                     GT shift  110 */
  {  24,   0, 145}, /* 11:                 CONCAT shift  145 */
  { 101,  13, 126}, /* 12:                 RSHIFT shift  126 */
  {  11,   0, 120}, /* 13:                 BITAND shift  120 */
  {  73,  15, 112}, /* 14:                     LE shift  112 */
  {  13,   0, 122}, /* 15:                  BITOR shift  122 */
/* State 157 */
  {  76,   0, 158}, /*  1:                     LP shift  158 */
/* State 158 */
  {  80,   0, 170}, /*  1:                  MINUS shift  170 */
  {  82,   0, 166}, /*  2:                    NOT shift  166 */
  { 102,   2,  72}, /*  3:                 SELECT shift  72 */
  { 150,   8, 165}, /*  4:                   expr shift  165 */
  {  84,   0,  99}, /*  5:                   NULL shift  99 */
  {  65,   0, 103}, /*  6:                INTEGER shift  103 */
  {  46,   0, 104}, /*  7:                  FLOAT shift  104 */
  {  90,   0, 172}, /*  8:                   PLUS shift  172 */
  {  71,   0,  66}, /*  9:                JOIN_KW shift  66 */
  { 109,   0,  65}, /* 10:                 STRING shift  65 */
  { 190,   4, 159}, /* 11:                 select shift  159 */
  { 151,   9, 210}, /* 12:               expritem shift  210 */
  { 152,  15, 206}, /* 13:               exprlist shift  206 */
  {  93,   0, 184}, /* 14:                  RAISE shift  184 */
  {  12,   0, 168}, /* 15:                 BITNOT shift  168 */
  { 175,   0, 100}, /* 16:                     nm shift  100 */
  {  76,  18,  67}, /* 17:                     LP shift  67 */
  {  56,  19,  63}, /* 18:                     ID shift  63 */
  {  16,   0, 174}, /* 19:                   CASE shift  174 */
  { 179,   0,  68}, /* 20:              oneselect shift  68 */
/* State 159 */
  { 100,   0, 164}, /*  1:                     RP shift  164 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 117,   0, 160}, /*  3:                  UNION shift  160 */
  {  43,   0, 163}, /*  4:                 EXCEPT shift  163 */
  { 174,   0,  70}, /*  5:         multiselect_op shift  70 */
/* State 160 */
  { 102,   2, 631}, /*  1:                 SELECT reduce 102 */
  {   4,   0, 161}, /*  2:                    ALL shift  161 */
/* State 161 */
  { 102,   0, 632}, /*  1:                 SELECT reduce 103 */
/* State 162 */
  { 102,   0, 633}, /*  1:                 SELECT reduce 104 */
/* State 163 */
  { 102,   0, 634}, /*  1:                 SELECT reduce 105 */
/* State 165 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  60,   0, 157}, /*  7:                     IN shift  157 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  { 170,   0, 128}, /*  9:                 likeop shift  128 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   5, 143}, /* 15:                    REM shift  143 */
  {  69,  13, 147}, /* 16:                 ISNULL shift  147 */
  {  74,   0, 133}, /* 17:                   LIKE shift  133 */
  {  78,  19, 108}, /* 18:                     LT shift  108 */
  {  51,  22, 114}, /* 19:                     GE shift  114 */
  {  73,   0, 112}, /* 20:                     LE shift  112 */
  { 101,  17, 126}, /* 21:                 RSHIFT shift  126 */
  {  24,   0, 145}, /* 22:                 CONCAT shift  145 */
  {  80,   0, 137}, /* 23:                  MINUS shift  137 */
  {  77,   0, 124}, /* 24:                 LSHIFT shift  124 */
  { 105,  18, 141}, /* 25:                  SLASH shift  141 */
  {  52,   0, 134}, /* 26:                   GLOB shift  134 */
  { 107,  23, 139}, /* 27:                   STAR shift  139 */
/* State 166 */
  { 150,   3, 167}, /*  1:                   expr shift  167 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 167 */
  {  51,   0, 114}, /*  1:                     GE shift  114 */
  { 101,   1, 126}, /*  2:                 RSHIFT shift  126 */
  {  77,  10, 124}, /*  3:                 LSHIFT shift  124 */
  {  78,   0, 108}, /*  4:                     LT shift  108 */
  {  54,   0, 110}, /*  5:                     GT shift  110 */
  { 105,  13, 141}, /*  6:                  SLASH shift  141 */
  {  81,   0, 116}, /*  7:                     NE shift  116 */
  { 107,  15, 139}, /*  8:                   STAR shift  139 */
  {  83,   0, 152}, /*  9:                NOTNULL shift  152 */
  {  52,   0, 134}, /* 10:                   GLOB shift  134 */
  {  60,  17, 157}, /* 11:                     IN shift  157 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  80,   0, 137}, /* 13:                  MINUS shift  137 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  82,   0, 130}, /* 15:                    NOT shift  130 */
  {  90,   0, 135}, /* 16:                   PLUS shift  135 */
  {  10,   0, 153}, /* 17:                BETWEEN shift  153 */
  {  42,   0, 118}, /* 18:                     EQ shift  118 */
  {  68,   0, 148}, /* 19:                     IS shift  148 */
  {  69,   0, 147}, /* 20:                 ISNULL shift  147 */
  { 170,  22, 128}, /* 21:                 likeop shift  128 */
  {  95,   0, 143}, /* 22:                    REM shift  143 */
  {  24,   0, 145}, /* 23:                 CONCAT shift  145 */
  {  73,   0, 112}, /* 24:                     LE shift  112 */
  {  74,  23, 133}, /* 25:                   LIKE shift  133 */
/* State 168 */
  { 150,   3, 169}, /*  1:                   expr shift  169 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 169 */
  { 170,   0, 128}, /*  1:                 likeop shift  128 */
/* State 170 */
  { 150,   3, 171}, /*  1:                   expr shift  171 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 171 */
  { 170,   0, 128}, /*  1:                 likeop shift  128 */
/* State 172 */
  { 150,   3, 173}, /*  1:                   expr shift  173 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 173 */
  { 170,   0, 128}, /*  1:                 likeop shift  128 */
/* State 174 */
  {  90,   2, 172}, /*  1:                   PLUS shift  172 */
  {  56,   0,  63}, /*  2:                     ID shift  63 */
  {  76,   0,  67}, /*  3:                     LP shift  67 */
  {  71,   0,  66}, /*  4:                JOIN_KW shift  66 */
  {  46,  10, 104}, /*  5:                  FLOAT shift  104 */
  { 175,   1, 100}, /*  6:                     nm shift  100 */
  { 125,   0, 751}, /*  7:                   WHEN reduce 222 */
  { 109,   0,  65}, /*  8:                 STRING shift  65 */
  {  93,   3, 184}, /*  9:                  RAISE shift  184 */
  {  12,   0, 168}, /* 10:                 BITNOT shift  168 */
  {  82,  12, 166}, /* 11:                    NOT shift  166 */
  {  65,   0, 103}, /* 12:                INTEGER shift  103 */
  {  80,   5, 170}, /* 13:                  MINUS shift  170 */
  { 132,   0, 176}, /* 14:           case_operand shift  176 */
  { 150,  11, 175}, /* 15:                   expr shift  175 */
  {  16,   0, 174}, /* 16:                   CASE shift  174 */
  {  84,  16,  99}, /* 17:                   NULL shift  99 */
/* State 175 */
  {  60,   0, 157}, /*  1:                     IN shift  157 */
  {  11,   0, 120}, /*  2:                 BITAND shift  120 */
  { 170,   0, 128}, /*  3:                 likeop shift  128 */
  {  69,   8, 147}, /*  4:                 ISNULL shift  147 */
  {  88,   1, 106}, /*  5:                     OR shift  106 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
  {  13,   0, 122}, /*  8:                  BITOR shift  122 */
  {  73,   0, 112}, /*  9:                     LE shift  112 */
  {  77,   0, 124}, /* 10:                 LSHIFT shift  124 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  95,   2, 143}, /* 12:                    REM shift  143 */
  {  68,   0, 148}, /* 13:                     IS shift  148 */
  { 125,   4, 750}, /* 14:                   WHEN reduce 221 */
  {  42,   0, 118}, /* 15:                     EQ shift  118 */
  {  51,   0, 114}, /* 16:                     GE shift  114 */
  {  52,  20, 134}, /* 17:                   GLOB shift  134 */
  { 101,   9, 126}, /* 18:                 RSHIFT shift  126 */
  {  74,   0, 133}, /* 19:                   LIKE shift  133 */
  {  24,   0, 145}, /* 20:                 CONCAT shift  145 */
  {  54,   0, 110}, /* 21:                     GT shift  110 */
  { 105,  10, 141}, /* 22:                  SLASH shift  141 */
  {  78,   0, 108}, /* 23:                     LT shift  108 */
  { 107,  16, 139}, /* 24:                   STAR shift  139 */
  {  80,  17, 137}, /* 25:                  MINUS shift  137 */
  {  81,   0, 116}, /* 26:                     NE shift  116 */
  {  82,  21, 130}, /* 27:                    NOT shift  130 */
  {  83,   0, 152}, /* 28:                NOTNULL shift  152 */
/* State 176 */
  { 125,   0, 202}, /*  1:                   WHEN shift  202 */
  { 131,   1, 177}, /*  2:          case_exprlist shift  177 */
/* State 177 */
  {  40,   0, 749}, /*  1:                    END reduce 220 */
  { 125,   0, 180}, /*  2:                   WHEN shift  180 */
  { 130,   0, 178}, /*  3:              case_else shift  178 */
  {  39,   0, 200}, /*  4:                   ELSE shift  200 */
/* State 178 */
  {  40,   0, 179}, /*  1:                    END shift  179 */
/* State 180 */
  { 150,   3, 181}, /*  1:                   expr shift  181 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 181 */
  { 112,   0, 182}, /*  1:                   THEN shift  182 */
  {  60,   0, 157}, /*  2:                     IN shift  157 */
  { 170,   0, 128}, /*  3:                 likeop shift  128 */
  {  11,   0, 120}, /*  4:                 BITAND shift  120 */
  {  88,   2, 106}, /*  5:                     OR shift  106 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
  {  13,   0, 122}, /*  8:                  BITOR shift  122 */
  {  73,   0, 112}, /*  9:                     LE shift  112 */
  {  77,   0, 124}, /* 10:                 LSHIFT shift  124 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  95,   4, 143}, /* 12:                    REM shift  143 */
  {  68,   0, 148}, /* 13:                     IS shift  148 */
  {  69,   8, 147}, /* 14:                 ISNULL shift  147 */
  {  42,   0, 118}, /* 15:                     EQ shift  118 */
  {  51,   0, 114}, /* 16:                     GE shift  114 */
  {  52,  20, 134}, /* 17:                   GLOB shift  134 */
  { 101,   9, 126}, /* 18:                 RSHIFT shift  126 */
  {  74,   0, 133}, /* 19:                   LIKE shift  133 */
  {  24,   0, 145}, /* 20:                 CONCAT shift  145 */
  {  54,   0, 110}, /* 21:                     GT shift  110 */
  { 105,  10, 141}, /* 22:                  SLASH shift  141 */
  {  78,   0, 108}, /* 23:                     LT shift  108 */
  { 107,  16, 139}, /* 24:                   STAR shift  139 */
  {  80,  17, 137}, /* 25:                  MINUS shift  137 */
  {  81,   0, 116}, /* 26:                     NE shift  116 */
  {  82,  21, 130}, /* 27:                    NOT shift  130 */
  {  83,   0, 152}, /* 28:                NOTNULL shift  152 */
/* State 182 */
  { 150,   3, 183}, /*  1:                   expr shift  183 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 183 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  60,   0, 157}, /*  7:                     IN shift  157 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  { 170,   0, 128}, /*  9:                 likeop shift  128 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   5, 143}, /* 15:                    REM shift  143 */
  {  69,  13, 147}, /* 16:                 ISNULL shift  147 */
  {  74,   0, 133}, /* 17:                   LIKE shift  133 */
  {  78,  19, 108}, /* 18:                     LT shift  108 */
  {  51,  22, 114}, /* 19:                     GE shift  114 */
  {  73,   0, 112}, /* 20:                     LE shift  112 */
  { 101,  17, 126}, /* 21:                 RSHIFT shift  126 */
  {  24,   0, 145}, /* 22:                 CONCAT shift  145 */
  {  80,   0, 137}, /* 23:                  MINUS shift  137 */
  {  77,   0, 124}, /* 24:                 LSHIFT shift  124 */
  { 105,  18, 141}, /* 25:                  SLASH shift  141 */
  {  52,   0, 134}, /* 26:                   GLOB shift  134 */
  { 107,  23, 139}, /* 27:                   STAR shift  139 */
/* State 184 */
  {  76,   0, 185}, /*  1:                     LP shift  185 */
/* State 185 */
  {  45,   4, 196}, /*  1:                   FAIL shift  196 */
  {  57,   1, 186}, /*  2:                 IGNORE shift  186 */
  {  98,   0, 188}, /*  3:               ROLLBACK shift  188 */
  {   1,   0, 192}, /*  4:                  ABORT shift  192 */
/* State 186 */
  { 100,   0, 187}, /*  1:                     RP shift  187 */
/* State 188 */
  {  21,   0, 189}, /*  1:                  COMMA shift  189 */
/* State 189 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 190}, /*  4:                     nm shift  190 */
/* State 190 */
  { 100,   0, 191}, /*  1:                     RP shift  191 */
/* State 192 */
  {  21,   0, 193}, /*  1:                  COMMA shift  193 */
/* State 193 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 194}, /*  4:                     nm shift  194 */
/* State 194 */
  { 100,   0, 195}, /*  1:                     RP shift  195 */
/* State 196 */
  {  21,   0, 197}, /*  1:                  COMMA shift  197 */
/* State 197 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 198}, /*  4:                     nm shift  198 */
/* State 198 */
  { 100,   0, 199}, /*  1:                     RP shift  199 */
/* State 200 */
  { 150,   3, 201}, /*  1:                   expr shift  201 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 201 */
  {  60,   0, 157}, /*  1:                     IN shift  157 */
  {  11,   0, 120}, /*  2:                 BITAND shift  120 */
  { 170,   0, 128}, /*  3:                 likeop shift  128 */
  {  40,   0, 748}, /*  4:                    END reduce 219 */
  {  88,   1, 106}, /*  5:                     OR shift  106 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
  {  13,   0, 122}, /*  8:                  BITOR shift  122 */
  {  73,   0, 112}, /*  9:                     LE shift  112 */
  {  77,   0, 124}, /* 10:                 LSHIFT shift  124 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  95,   2, 143}, /* 12:                    REM shift  143 */
  {  68,   4, 148}, /* 13:                     IS shift  148 */
  {  69,   8, 147}, /* 14:                 ISNULL shift  147 */
  {  42,   0, 118}, /* 15:                     EQ shift  118 */
  {  51,   0, 114}, /* 16:                     GE shift  114 */
  {  52,  20, 134}, /* 17:                   GLOB shift  134 */
  { 101,   9, 126}, /* 18:                 RSHIFT shift  126 */
  {  74,   0, 133}, /* 19:                   LIKE shift  133 */
  {  24,   0, 145}, /* 20:                 CONCAT shift  145 */
  {  54,   0, 110}, /* 21:                     GT shift  110 */
  { 105,  10, 141}, /* 22:                  SLASH shift  141 */
  {  78,   0, 108}, /* 23:                     LT shift  108 */
  { 107,  16, 139}, /* 24:                   STAR shift  139 */
  {  80,  17, 137}, /* 25:                  MINUS shift  137 */
  {  81,   0, 116}, /* 26:                     NE shift  116 */
  {  82,  21, 130}, /* 27:                    NOT shift  130 */
  {  83,   0, 152}, /* 28:                NOTNULL shift  152 */
/* State 202 */
  { 150,   3, 203}, /*  1:                   expr shift  203 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 203 */
  { 112,   0, 204}, /*  1:                   THEN shift  204 */
  {  60,   0, 157}, /*  2:                     IN shift  157 */
  { 170,   0, 128}, /*  3:                 likeop shift  128 */
  {  11,   0, 120}, /*  4:                 BITAND shift  120 */
  {  88,   2, 106}, /*  5:                     OR shift  106 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
  {  13,   0, 122}, /*  8:                  BITOR shift  122 */
  {  73,   0, 112}, /*  9:                     LE shift  112 */
  {  77,   0, 124}, /* 10:                 LSHIFT shift  124 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  95,   4, 143}, /* 12:                    REM shift  143 */
  {  68,   0, 148}, /* 13:                     IS shift  148 */
  {  69,   8, 147}, /* 14:                 ISNULL shift  147 */
  {  42,   0, 118}, /* 15:                     EQ shift  118 */
  {  51,   0, 114}, /* 16:                     GE shift  114 */
  {  52,  20, 134}, /* 17:                   GLOB shift  134 */
  { 101,   9, 126}, /* 18:                 RSHIFT shift  126 */
  {  74,   0, 133}, /* 19:                   LIKE shift  133 */
  {  24,   0, 145}, /* 20:                 CONCAT shift  145 */
  {  54,   0, 110}, /* 21:                     GT shift  110 */
  { 105,  10, 141}, /* 22:                  SLASH shift  141 */
  {  78,   0, 108}, /* 23:                     LT shift  108 */
  { 107,  16, 139}, /* 24:                   STAR shift  139 */
  {  80,  17, 137}, /* 25:                  MINUS shift  137 */
  {  81,   0, 116}, /* 26:                     NE shift  116 */
  {  82,  21, 130}, /* 27:                    NOT shift  130 */
  {  83,   0, 152}, /* 28:                NOTNULL shift  152 */
/* State 204 */
  { 150,   3, 205}, /*  1:                   expr shift  205 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 205 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  60,   0, 157}, /*  7:                     IN shift  157 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  { 170,   0, 128}, /*  9:                 likeop shift  128 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   5, 143}, /* 15:                    REM shift  143 */
  {  69,  13, 147}, /* 16:                 ISNULL shift  147 */
  {  74,   0, 133}, /* 17:                   LIKE shift  133 */
  {  78,  19, 108}, /* 18:                     LT shift  108 */
  {  51,  22, 114}, /* 19:                     GE shift  114 */
  {  73,   0, 112}, /* 20:                     LE shift  112 */
  { 101,  17, 126}, /* 21:                 RSHIFT shift  126 */
  {  24,   0, 145}, /* 22:                 CONCAT shift  145 */
  {  80,   0, 137}, /* 23:                  MINUS shift  137 */
  {  77,   0, 124}, /* 24:                 LSHIFT shift  124 */
  { 105,  18, 141}, /* 25:                  SLASH shift  141 */
  {  52,   0, 134}, /* 26:                   GLOB shift  134 */
  { 107,  23, 139}, /* 27:                   STAR shift  139 */
/* State 206 */
  { 100,   0, 207}, /*  1:                     RP shift  207 */
  {  21,   0, 208}, /*  2:                  COMMA shift  208 */
/* State 208 */
  {  80,   4, 170}, /*  1:                  MINUS shift  170 */
  {  65,   0, 103}, /*  2:                INTEGER shift  103 */
  {  82,   0, 166}, /*  3:                    NOT shift  166 */
  {  16,   0, 174}, /*  4:                   CASE shift  174 */
  {  84,   0,  99}, /*  5:                   NULL shift  99 */
  {  71,   0,  66}, /*  6:                JOIN_KW shift  66 */
  { 150,   0, 165}, /*  7:                   expr shift  165 */
  { 151,   6, 209}, /*  8:               expritem shift  209 */
  {  56,   0,  63}, /*  9:                     ID shift  63 */
  {  12,   0, 168}, /* 10:                 BITNOT shift  168 */
  {  90,   0, 172}, /* 11:                   PLUS shift  172 */
  {  93,   0, 184}, /* 12:                  RAISE shift  184 */
  {  76,  10,  67}, /* 13:                     LP shift  67 */
  { 109,  12,  65}, /* 14:                 STRING shift  65 */
  {  46,   0, 104}, /* 15:                  FLOAT shift  104 */
  { 175,   0, 100}, /* 16:                     nm shift  100 */
/* State 212 */
  { 150,   3, 213}, /*  1:                   expr shift  213 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 213 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  {   5,   0, 214}, /*  6:                    AND shift  214 */
  {  60,   0, 157}, /*  7:                     IN shift  157 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  { 170,   0, 128}, /*  9:                 likeop shift  128 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   5, 143}, /* 15:                    REM shift  143 */
  {  69,  13, 147}, /* 16:                 ISNULL shift  147 */
  {  74,   0, 133}, /* 17:                   LIKE shift  133 */
  {  78,  19, 108}, /* 18:                     LT shift  108 */
  {  51,  22, 114}, /* 19:                     GE shift  114 */
  {  73,   0, 112}, /* 20:                     LE shift  112 */
  { 101,  17, 126}, /* 21:                 RSHIFT shift  126 */
  {  24,   0, 145}, /* 22:                 CONCAT shift  145 */
  {  80,   0, 137}, /* 23:                  MINUS shift  137 */
  {  77,   0, 124}, /* 24:                 LSHIFT shift  124 */
  { 105,  18, 141}, /* 25:                  SLASH shift  141 */
  {  52,   0, 134}, /* 26:                   GLOB shift  134 */
  { 107,  23, 139}, /* 27:                   STAR shift  139 */
/* State 214 */
  { 150,   3, 215}, /*  1:                   expr shift  215 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 215 */
  {  51,   0, 114}, /*  1:                     GE shift  114 */
  { 101,   1, 126}, /*  2:                 RSHIFT shift  126 */
  {  77,  10, 124}, /*  3:                 LSHIFT shift  124 */
  {  78,   0, 108}, /*  4:                     LT shift  108 */
  {  54,   0, 110}, /*  5:                     GT shift  110 */
  { 105,  13, 141}, /*  6:                  SLASH shift  141 */
  {  81,   0, 116}, /*  7:                     NE shift  116 */
  { 107,  15, 139}, /*  8:                   STAR shift  139 */
  {  83,   0, 152}, /*  9:                NOTNULL shift  152 */
  {  52,   0, 134}, /* 10:                   GLOB shift  134 */
  {  60,  17, 157}, /* 11:                     IN shift  157 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  80,   0, 137}, /* 13:                  MINUS shift  137 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  82,   0, 130}, /* 15:                    NOT shift  130 */
  {  90,   0, 135}, /* 16:                   PLUS shift  135 */
  {  10,   0, 153}, /* 17:                BETWEEN shift  153 */
  {  42,   0, 118}, /* 18:                     EQ shift  118 */
  {  68,   0, 148}, /* 19:                     IS shift  148 */
  {  69,   0, 147}, /* 20:                 ISNULL shift  147 */
  { 170,  22, 128}, /* 21:                 likeop shift  128 */
  {  95,   0, 143}, /* 22:                    REM shift  143 */
  {  24,   0, 145}, /* 23:                 CONCAT shift  145 */
  {  73,   0, 112}, /* 24:                     LE shift  112 */
  {  74,  23, 133}, /* 25:                   LIKE shift  133 */
/* State 216 */
  {  76,   0, 217}, /*  1:                     LP shift  217 */
/* State 217 */
  {  80,   0, 170}, /*  1:                  MINUS shift  170 */
  {  82,   0, 166}, /*  2:                    NOT shift  166 */
  { 102,   2,  72}, /*  3:                 SELECT shift  72 */
  { 150,   8, 165}, /*  4:                   expr shift  165 */
  {  84,   0,  99}, /*  5:                   NULL shift  99 */
  {  65,   0, 103}, /*  6:                INTEGER shift  103 */
  {  46,   0, 104}, /*  7:                  FLOAT shift  104 */
  {  90,   0, 172}, /*  8:                   PLUS shift  172 */
  {  71,   0,  66}, /*  9:                JOIN_KW shift  66 */
  { 109,   0,  65}, /* 10:                 STRING shift  65 */
  { 190,   4, 218}, /* 11:                 select shift  218 */
  { 151,   9, 210}, /* 12:               expritem shift  210 */
  { 152,  15, 220}, /* 13:               exprlist shift  220 */
  {  93,   0, 184}, /* 14:                  RAISE shift  184 */
  {  12,   0, 168}, /* 15:                 BITNOT shift  168 */
  { 175,   0, 100}, /* 16:                     nm shift  100 */
  {  76,  18,  67}, /* 17:                     LP shift  67 */
  {  56,  19,  63}, /* 18:                     ID shift  63 */
  {  16,   0, 174}, /* 19:                   CASE shift  174 */
  { 179,   0,  68}, /* 20:              oneselect shift  68 */
/* State 218 */
  { 100,   0, 219}, /*  1:                     RP shift  219 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 117,   0, 160}, /*  3:                  UNION shift  160 */
  {  43,   0, 163}, /*  4:                 EXCEPT shift  163 */
  { 174,   0,  70}, /*  5:         multiselect_op shift  70 */
/* State 220 */
  { 100,   0, 221}, /*  1:                     RP shift  221 */
  {  21,   0, 208}, /*  2:                  COMMA shift  208 */
/* State 222 */
  { 136,   0, 223}, /*  1:                collate shift  223 */
  {  19,   0,  94}, /*  2:                COLLATE shift  94 */
/* State 223 */
  {  34,   3,  58}, /*  1:                   DESC shift  58 */
  { 196,   1, 224}, /*  2:              sortorder shift  224 */
  {   7,   0,  57}, /*  3:                    ASC shift  57 */
/* State 225 */
  { 150,   3, 226}, /*  1:                   expr shift  226 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 226 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  60,   0, 157}, /*  7:                     IN shift  157 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  { 170,   0, 128}, /*  9:                 likeop shift  128 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   5, 143}, /* 15:                    REM shift  143 */
  {  69,  13, 147}, /* 16:                 ISNULL shift  147 */
  {  74,   0, 133}, /* 17:                   LIKE shift  133 */
  {  78,  19, 108}, /* 18:                     LT shift  108 */
  {  51,  22, 114}, /* 19:                     GE shift  114 */
  {  73,   0, 112}, /* 20:                     LE shift  112 */
  { 101,  17, 126}, /* 21:                 RSHIFT shift  126 */
  {  24,   0, 145}, /* 22:                 CONCAT shift  145 */
  {  80,   0, 137}, /* 23:                  MINUS shift  137 */
  {  77,   0, 124}, /* 24:                 LSHIFT shift  124 */
  { 105,  18, 141}, /* 25:                  SLASH shift  141 */
  {  52,   0, 134}, /* 26:                   GLOB shift  134 */
  { 107,  23, 139}, /* 27:                   STAR shift  139 */
/* State 227 */
  {  14,   0, 228}, /*  1:                     BY shift  228 */
/* State 228 */
  {  90,   2, 172}, /*  1:                   PLUS shift  172 */
  {  56,   0,  63}, /*  2:                     ID shift  63 */
  {  76,   0,  67}, /*  3:                     LP shift  67 */
  {  71,   0,  66}, /*  4:                JOIN_KW shift  66 */
  {  46,   7, 104}, /*  5:                  FLOAT shift  104 */
  { 175,   1, 100}, /*  6:                     nm shift  100 */
  {  12,   0, 168}, /*  7:                 BITNOT shift  168 */
  { 109,   0,  65}, /*  8:                 STRING shift  65 */
  {  93,   3, 184}, /*  9:                  RAISE shift  184 */
  {  82,  11, 166}, /* 10:                    NOT shift  166 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  84,  14,  99}, /* 12:                   NULL shift  99 */
  {  80,   5, 170}, /* 13:                  MINUS shift  170 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  { 150,  10, 165}, /* 15:                   expr shift  165 */
  { 151,   0, 210}, /* 16:               expritem shift  210 */
  { 152,  12, 229}, /* 17:               exprlist shift  229 */
/* State 229 */
  {  21,   0, 208}, /*  1:                  COMMA shift  208 */
/* State 230 */
  { 150,   3, 231}, /*  1:                   expr shift  231 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 231 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  60,   0, 157}, /*  7:                     IN shift  157 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  { 170,   0, 128}, /*  9:                 likeop shift  128 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   5, 143}, /* 15:                    REM shift  143 */
  {  69,  13, 147}, /* 16:                 ISNULL shift  147 */
  {  74,   0, 133}, /* 17:                   LIKE shift  133 */
  {  78,  19, 108}, /* 18:                     LT shift  108 */
  {  51,  22, 114}, /* 19:                     GE shift  114 */
  {  73,   0, 112}, /* 20:                     LE shift  112 */
  { 101,  17, 126}, /* 21:                 RSHIFT shift  126 */
  {  24,   0, 145}, /* 22:                 CONCAT shift  145 */
  {  80,   0, 137}, /* 23:                  MINUS shift  137 */
  {  77,   0, 124}, /* 24:                 LSHIFT shift  124 */
  { 105,  18, 141}, /* 25:                  SLASH shift  141 */
  {  52,   0, 134}, /* 26:                   GLOB shift  134 */
  { 107,  23, 139}, /* 27:                   STAR shift  139 */
/* State 233 */
  { 191,   0, 234}, /*  1:             seltablist shift  234 */
  { 197,   1, 244}, /*  2:             stl_prefix shift  244 */
/* State 234 */
  { 168,   0, 235}, /*  1:                 joinop shift  235 */
  {  21,   0, 236}, /*  2:                  COMMA shift  236 */
  {  70,   0, 237}, /*  3:                   JOIN shift  237 */
  {  71,   0, 238}, /*  4:                JOIN_KW shift  238 */
/* State 238 */
  { 175,   3, 240}, /*  1:                     nm shift  240 */
  {  71,   4,  21}, /*  2:                JOIN_KW shift  21 */
  {  70,   0, 239}, /*  3:                   JOIN shift  239 */
  {  56,   0,  19}, /*  4:                     ID shift  19 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 240 */
  { 175,   3, 242}, /*  1:                     nm shift  242 */
  {  71,   4,  21}, /*  2:                JOIN_KW shift  21 */
  {  70,   0, 241}, /*  3:                   JOIN shift  241 */
  {  56,   0,  19}, /*  4:                     ID shift  19 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 242 */
  {  70,   0, 243}, /*  1:                   JOIN shift  243 */
/* State 244 */
  { 175,   0, 245}, /*  1:                     nm shift  245 */
  {  76,   3, 264}, /*  2:                     LP shift  264 */
  {  71,   4,  21}, /*  3:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  4:                     ID shift  19 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 245 */
  {   6,   0, 248}, /*  1:                     AS shift  248 */
  {  56,   1, 246}, /*  2:                     ID shift  246 */
  { 127,   0, 251}, /*  3:                     as shift  251 */
  { 158,   0, 250}, /*  4:                    ids shift  250 */
  { 109,   0, 247}, /*  5:                 STRING shift  247 */
/* State 248 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 249}, /*  4:                     nm shift  249 */
/* State 251 */
  {  87,   0, 262}, /*  1:                     ON shift  262 */
  { 177,   1, 252}, /*  2:                 on_opt shift  252 */
/* State 252 */
  { 208,   0, 253}, /*  1:              using_opt shift  253 */
  { 121,   0, 254}, /*  2:                  USING shift  254 */
/* State 254 */
  {  76,   0, 255}, /*  1:                     LP shift  255 */
/* State 255 */
  { 109,   0,  20}, /*  1:                 STRING shift  20 */
  { 175,   1, 260}, /*  2:                     nm shift  260 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 159,   0, 261}, /*  4:                idxitem shift  261 */
  { 160,   0, 256}, /*  5:                idxlist shift  256 */
  {  71,   0,  21}, /*  6:                JOIN_KW shift  21 */
/* State 256 */
  { 100,   0, 257}, /*  1:                     RP shift  257 */
  {  21,   0, 258}, /*  2:                  COMMA shift  258 */
/* State 258 */
  { 175,   0, 260}, /*  1:                     nm shift  260 */
  {  71,   3,  21}, /*  2:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 109,   0,  20}, /*  4:                 STRING shift  20 */
  { 159,   4, 259}, /*  5:                idxitem shift  259 */
/* State 262 */
  { 150,   3, 263}, /*  1:                   expr shift  263 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 263 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  60,   0, 157}, /*  7:                     IN shift  157 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  { 170,   0, 128}, /*  9:                 likeop shift  128 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   5, 143}, /* 15:                    REM shift  143 */
  {  69,  13, 147}, /* 16:                 ISNULL shift  147 */
  {  74,   0, 133}, /* 17:                   LIKE shift  133 */
  {  78,  19, 108}, /* 18:                     LT shift  108 */
  {  51,  22, 114}, /* 19:                     GE shift  114 */
  {  73,   0, 112}, /* 20:                     LE shift  112 */
  { 101,  17, 126}, /* 21:                 RSHIFT shift  126 */
  {  24,   0, 145}, /* 22:                 CONCAT shift  145 */
  {  80,   0, 137}, /* 23:                  MINUS shift  137 */
  {  77,   0, 124}, /* 24:                 LSHIFT shift  124 */
  { 105,  18, 141}, /* 25:                  SLASH shift  141 */
  {  52,   0, 134}, /* 26:                   GLOB shift  134 */
  { 107,  23, 139}, /* 27:                   STAR shift  139 */
/* State 264 */
  { 102,   0,  72}, /*  1:                 SELECT shift  72 */
  { 190,   0, 265}, /*  2:                 select shift  265 */
  { 179,   0,  68}, /*  3:              oneselect shift  68 */
/* State 265 */
  { 100,   0, 266}, /*  1:                     RP shift  266 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 117,   0, 160}, /*  3:                  UNION shift  160 */
  {  43,   0, 163}, /*  4:                 EXCEPT shift  163 */
  { 174,   0,  70}, /*  5:         multiselect_op shift  70 */
/* State 266 */
  {   6,   0, 248}, /*  1:                     AS shift  248 */
  {  56,   1, 246}, /*  2:                     ID shift  246 */
  { 127,   0, 267}, /*  3:                     as shift  267 */
  { 158,   0, 250}, /*  4:                    ids shift  250 */
  { 109,   0, 247}, /*  5:                 STRING shift  247 */
/* State 267 */
  {  87,   0, 262}, /*  1:                     ON shift  262 */
  { 177,   1, 268}, /*  2:                 on_opt shift  268 */
/* State 268 */
  { 208,   0, 269}, /*  1:              using_opt shift  269 */
  { 121,   0, 254}, /*  2:                  USING shift  254 */
/* State 270 */
  {  80,   4, 170}, /*  1:                  MINUS shift  170 */
  {  65,   0, 103}, /*  2:                INTEGER shift  103 */
  {  82,   0, 166}, /*  3:                    NOT shift  166 */
  {  16,   0, 174}, /*  4:                   CASE shift  174 */
  {  84,   0,  99}, /*  5:                   NULL shift  99 */
  {  12,   0, 168}, /*  6:                 BITNOT shift  168 */
  { 150,   0, 271}, /*  7:                   expr shift  271 */
  {  71,   0,  66}, /*  8:                JOIN_KW shift  66 */
  {  56,   0,  63}, /*  9:                     ID shift  63 */
  {  93,   0, 184}, /* 10:                  RAISE shift  184 */
  {  90,   0, 172}, /* 11:                   PLUS shift  172 */
  { 107,   0, 273}, /* 12:                   STAR shift  273 */
  {  76,   6,  67}, /* 13:                     LP shift  67 */
  { 109,  10,  65}, /* 14:                 STRING shift  65 */
  {  46,   0, 104}, /* 15:                  FLOAT shift  104 */
  { 175,   0, 274}, /* 16:                     nm shift  274 */
/* State 271 */
  {  69,   2, 147}, /*  1:                 ISNULL shift  147 */
  {   5,   0,  98}, /*  2:                    AND shift  98 */
  {  73,   0, 112}, /*  3:                     LE shift  112 */
  {  74,   8, 133}, /*  4:                   LIKE shift  133 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  { 101,   1, 126}, /*  6:                 RSHIFT shift  126 */
  {   6,   0, 248}, /*  7:                     AS shift  248 */
  {  42,   9, 118}, /*  8:                     EQ shift  118 */
  {  10,   0, 153}, /*  9:                BETWEEN shift  153 */
  { 105,   3, 141}, /* 10:                  SLASH shift  141 */
  { 170,   4, 128}, /* 11:                 likeop shift  128 */
  { 107,  13, 139}, /* 12:                   STAR shift  139 */
  {  11,   0, 120}, /* 13:                 BITAND shift  120 */
  { 109,  16, 247}, /* 14:                 STRING shift  247 */
  {  78,   0, 108}, /* 15:                     LT shift  108 */
  {  77,  22, 124}, /* 16:                 LSHIFT shift  124 */
  {  80,   0, 137}, /* 17:                  MINUS shift  137 */
  {  81,   0, 116}, /* 18:                     NE shift  116 */
  {  82,   0, 130}, /* 19:                    NOT shift  130 */
  {  83,  24, 152}, /* 20:                NOTNULL shift  152 */
  {  52,   0, 134}, /* 21:                   GLOB shift  134 */
  {  13,   0, 122}, /* 22:                  BITOR shift  122 */
  {  54,   0, 110}, /* 23:                     GT shift  110 */
  {  51,   0, 114}, /* 24:                     GE shift  114 */
  {  88,  26, 106}, /* 25:                     OR shift  106 */
  {  56,  28, 246}, /* 26:                     ID shift  246 */
  {  90,   0, 135}, /* 27:                   PLUS shift  135 */
  {  24,   0, 145}, /* 28:                 CONCAT shift  145 */
  {  60,   0, 157}, /* 29:                     IN shift  157 */
  {  95,   0, 143}, /* 30:                    REM shift  143 */
  { 158,   0, 250}, /* 31:                    ids shift  250 */
  { 127,  30, 272}, /* 32:                     as shift  272 */
/* State 274 */
  {  36,   0, 275}, /*  1:                    DOT shift  275 */
/* State 275 */
  { 175,   0, 102}, /*  1:                     nm shift  102 */
  {  71,   4,  21}, /*  2:                JOIN_KW shift  21 */
  { 107,   0, 276}, /*  3:                   STAR shift  276 */
  {  56,   0,  19}, /*  4:                     ID shift  19 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 280 */
  {  60,   0, 157}, /*  1:                     IN shift  157 */
  {  11,   0, 120}, /*  2:                 BITAND shift  120 */
  { 170,   0, 128}, /*  3:                 likeop shift  128 */
  {  13,   0, 122}, /*  4:                  BITOR shift  122 */
  {  88,   1, 106}, /*  5:                     OR shift  106 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
  {  73,   0, 112}, /*  8:                     LE shift  112 */
  {  77,   0, 124}, /*  9:                 LSHIFT shift  124 */
  {  51,   0, 114}, /* 10:                     GE shift  114 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  95,   2, 143}, /* 12:                    REM shift  143 */
  {  68,   0, 148}, /* 13:                     IS shift  148 */
  {  69,   4, 147}, /* 14:                 ISNULL shift  147 */
  {  42,   0, 118}, /* 15:                     EQ shift  118 */
  {  52,  20, 134}, /* 16:                   GLOB shift  134 */
  { 100,   0, 281}, /* 17:                     RP shift  281 */
  { 101,   8, 126}, /* 18:                 RSHIFT shift  126 */
  {  74,   0, 133}, /* 19:                   LIKE shift  133 */
  {  24,   0, 145}, /* 20:                 CONCAT shift  145 */
  {  54,   0, 110}, /* 21:                     GT shift  110 */
  { 105,   9, 141}, /* 22:                  SLASH shift  141 */
  {  78,   0, 108}, /* 23:                     LT shift  108 */
  { 107,  10, 139}, /* 24:                   STAR shift  139 */
  {  80,  16, 137}, /* 25:                  MINUS shift  137 */
  {  81,   0, 116}, /* 26:                     NE shift  116 */
  {  82,  21, 130}, /* 27:                    NOT shift  130 */
  {  83,   0, 152}, /* 28:                NOTNULL shift  152 */
/* State 282 */
  { 100,   0, 283}, /*  1:                     RP shift  283 */
  {  21,   0, 208}, /*  2:                  COMMA shift  208 */
/* State 284 */
  { 100,   0, 285}, /*  1:                     RP shift  285 */
/* State 286 */
  {  60,   0, 157}, /*  1:                     IN shift  157 */
  {  11,   0, 120}, /*  2:                 BITAND shift  120 */
  { 170,   0, 128}, /*  3:                 likeop shift  128 */
  {  13,   0, 122}, /*  4:                  BITOR shift  122 */
  {  88,   1, 106}, /*  5:                     OR shift  106 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
  {  73,   0, 112}, /*  8:                     LE shift  112 */
  {  77,   0, 124}, /*  9:                 LSHIFT shift  124 */
  {  51,   0, 114}, /* 10:                     GE shift  114 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  95,   2, 143}, /* 12:                    REM shift  143 */
  {  68,   0, 148}, /* 13:                     IS shift  148 */
  {  69,   4, 147}, /* 14:                 ISNULL shift  147 */
  {  42,   0, 118}, /* 15:                     EQ shift  118 */
  {  52,  20, 134}, /* 16:                   GLOB shift  134 */
  { 100,   0, 287}, /* 17:                     RP shift  287 */
  { 101,   8, 126}, /* 18:                 RSHIFT shift  126 */
  {  74,   0, 133}, /* 19:                   LIKE shift  133 */
  {  24,   0, 145}, /* 20:                 CONCAT shift  145 */
  {  54,   0, 110}, /* 21:                     GT shift  110 */
  { 105,   9, 141}, /* 22:                  SLASH shift  141 */
  {  78,   0, 108}, /* 23:                     LT shift  108 */
  { 107,  10, 139}, /* 24:                   STAR shift  139 */
  {  80,  16, 137}, /* 25:                  MINUS shift  137 */
  {  81,   0, 116}, /* 26:                     NE shift  116 */
  {  82,  21, 130}, /* 27:                    NOT shift  130 */
  {  83,   0, 152}, /* 28:                NOTNULL shift  152 */
/* State 287 */
  { 178,   0, 288}, /*  1:                 onconf shift  288 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 289 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 290}, /*  4:                     nm shift  290 */
/* State 290 */
  {  76,   0, 308}, /*  1:                     LP shift  308 */
  { 161,   0, 291}, /*  2:            idxlist_opt shift  291 */
/* State 291 */
  { 186,   0, 292}, /*  1:                refargs shift  292 */
/* State 292 */
  {  87,   0, 296}, /*  1:                     ON shift  296 */
  {  79,   0, 294}, /*  2:                  MATCH shift  294 */
  { 185,   0, 293}, /*  3:                 refarg shift  293 */
/* State 294 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 295}, /*  4:                     nm shift  295 */
/* State 296 */
  {  63,   0, 306}, /*  1:                 INSERT shift  306 */
  {  32,   0, 297}, /*  2:                 DELETE shift  297 */
  { 119,   2, 304}, /*  3:                 UPDATE shift  304 */
/* State 297 */
  { 184,   3, 298}, /*  1:                 refact shift  298 */
  {  97,   0, 303}, /*  2:               RESTRICT shift  303 */
  { 104,   0, 299}, /*  3:                    SET shift  299 */
  {  15,   0, 302}, /*  4:                CASCADE shift  302 */
/* State 299 */
  {  84,   0, 300}, /*  1:                   NULL shift  300 */
  {  29,   0, 301}, /*  2:                DEFAULT shift  301 */
/* State 304 */
  { 184,   3, 305}, /*  1:                 refact shift  305 */
  {  97,   0, 303}, /*  2:               RESTRICT shift  303 */
  { 104,   0, 299}, /*  3:                    SET shift  299 */
  {  15,   0, 302}, /*  4:                CASCADE shift  302 */
/* State 306 */
  { 184,   3, 307}, /*  1:                 refact shift  307 */
  {  97,   0, 303}, /*  2:               RESTRICT shift  303 */
  { 104,   0, 299}, /*  3:                    SET shift  299 */
  {  15,   0, 302}, /*  4:                CASCADE shift  302 */
/* State 308 */
  { 109,   0,  20}, /*  1:                 STRING shift  20 */
  { 175,   1, 260}, /*  2:                     nm shift  260 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 159,   0, 261}, /*  4:                idxitem shift  261 */
  { 160,   0, 309}, /*  5:                idxlist shift  309 */
  {  71,   0,  21}, /*  6:                JOIN_KW shift  21 */
/* State 309 */
  { 100,   0, 310}, /*  1:                     RP shift  310 */
  {  21,   0, 258}, /*  2:                  COMMA shift  258 */
/* State 312 */
  {  56,   0,  95}, /*  1:                     ID shift  95 */
  { 157,   0, 313}, /*  2:                     id shift  313 */
/* State 314 */
  { 162,   2, 315}, /*  1: init_deferred_pred_opt shift  315 */
  {  62,   0,  50}, /*  2:              INITIALLY shift  50 */
/* State 317 */
  {  84,   2, 328}, /*  1:                   NULL shift  328 */
  {  56,   0, 319}, /*  2:                     ID shift  319 */
  {  65,   0, 320}, /*  3:                INTEGER shift  320 */
  {  80,   0, 324}, /*  4:                  MINUS shift  324 */
  { 109,   6, 318}, /*  5:                 STRING shift  318 */
  {  46,   0, 327}, /*  6:                  FLOAT shift  327 */
  {  90,   0, 321}, /*  7:                   PLUS shift  321 */
/* State 321 */
  {  46,   0, 323}, /*  1:                  FLOAT shift  323 */
  {  65,   0, 322}, /*  2:                INTEGER shift  322 */
/* State 324 */
  {  46,   0, 326}, /*  1:                  FLOAT shift  326 */
  {  65,   0, 325}, /*  2:                INTEGER shift  325 */
/* State 329 */
  {  76,   4, 330}, /*  1:                     LP shift  330 */
  { 109,   0, 247}, /*  2:                 STRING shift  247 */
  { 158,   0, 341}, /*  3:                    ids shift  341 */
  {  56,   0, 246}, /*  4:                     ID shift  246 */
/* State 330 */
  {  80,   0, 339}, /*  1:                  MINUS shift  339 */
  { 193,   4, 331}, /*  2:                 signed shift  331 */
  {  90,   0, 337}, /*  3:                   PLUS shift  337 */
  {  65,   0, 336}, /*  4:                INTEGER shift  336 */
/* State 331 */
  { 100,   0, 332}, /*  1:                     RP shift  332 */
  {  21,   0, 333}, /*  2:                  COMMA shift  333 */
/* State 333 */
  {  80,   0, 339}, /*  1:                  MINUS shift  339 */
  { 193,   4, 334}, /*  2:                 signed shift  334 */
  {  90,   0, 337}, /*  3:                   PLUS shift  337 */
  {  65,   0, 336}, /*  4:                INTEGER shift  336 */
/* State 334 */
  { 100,   0, 335}, /*  1:                     RP shift  335 */
/* State 337 */
  {  65,   0, 338}, /*  1:                INTEGER shift  338 */
/* State 339 */
  {  65,   0, 340}, /*  1:                INTEGER shift  340 */
/* State 344 */
  {  48,   0, 363}, /*  1:                FOREIGN shift  363 */
  {  17,   0, 360}, /*  2:                  CHECK shift  360 */
  {  26,   0, 347}, /*  3:             CONSTRAINT shift  347 */
  {  92,   0, 349}, /*  4:                PRIMARY shift  349 */
  { 100,   4, 605}, /*  5:                     RP reduce 76 */
  {  21,   0, 345}, /*  6:                  COMMA shift  345 */
  { 198,   8, 375}, /*  7:                  tcons shift  375 */
  { 118,   0, 355}, /*  8:                 UNIQUE shift  355 */
/* State 345 */
  { 198,   2, 346}, /*  1:                  tcons shift  346 */
  {  48,   0, 363}, /*  2:                FOREIGN shift  363 */
  {  92,   4, 349}, /*  3:                PRIMARY shift  349 */
  {  26,   0, 347}, /*  4:             CONSTRAINT shift  347 */
  { 118,   0, 355}, /*  5:                 UNIQUE shift  355 */
  {  17,   0, 360}, /*  6:                  CHECK shift  360 */
/* State 347 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 348}, /*  4:                     nm shift  348 */
/* State 349 */
  {  72,   0, 350}, /*  1:                    KEY shift  350 */
/* State 350 */
  {  76,   0, 351}, /*  1:                     LP shift  351 */
/* State 351 */
  { 109,   0,  20}, /*  1:                 STRING shift  20 */
  { 175,   1, 260}, /*  2:                     nm shift  260 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 159,   0, 261}, /*  4:                idxitem shift  261 */
  { 160,   0, 352}, /*  5:                idxlist shift  352 */
  {  71,   0,  21}, /*  6:                JOIN_KW shift  21 */
/* State 352 */
  { 100,   0, 353}, /*  1:                     RP shift  353 */
  {  21,   0, 258}, /*  2:                  COMMA shift  258 */
/* State 353 */
  { 178,   0, 354}, /*  1:                 onconf shift  354 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 355 */
  {  76,   0, 356}, /*  1:                     LP shift  356 */
/* State 356 */
  { 109,   0,  20}, /*  1:                 STRING shift  20 */
  { 175,   1, 260}, /*  2:                     nm shift  260 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 159,   0, 261}, /*  4:                idxitem shift  261 */
  { 160,   0, 357}, /*  5:                idxlist shift  357 */
  {  71,   0,  21}, /*  6:                JOIN_KW shift  21 */
/* State 357 */
  { 100,   0, 358}, /*  1:                     RP shift  358 */
  {  21,   0, 258}, /*  2:                  COMMA shift  258 */
/* State 358 */
  { 178,   0, 359}, /*  1:                 onconf shift  359 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 360 */
  { 150,   3, 361}, /*  1:                   expr shift  361 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 361 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  {  88,   0, 106}, /*  2:                     OR shift  106 */
  {  60,   0, 157}, /*  3:                     IN shift  157 */
  {  90,   0, 135}, /*  4:                   PLUS shift  135 */
  { 178,   0, 362}, /*  5:                 onconf shift  362 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  10,   0, 153}, /*  7:                BETWEEN shift  153 */
  {  11,   0, 120}, /*  8:                 BITAND shift  120 */
  {  95,   0, 143}, /*  9:                    REM shift  143 */
  {  13,   0, 122}, /* 10:                  BITOR shift  122 */
  {  68,   7, 148}, /* 11:                     IS shift  148 */
  {  69,   8, 147}, /* 12:                 ISNULL shift  147 */
  {  78,   0, 108}, /* 13:                     LT shift  108 */
  {  42,  10, 118}, /* 14:                     EQ shift  118 */
  { 101,   0, 126}, /* 15:                 RSHIFT shift  126 */
  {  73,   0, 112}, /* 16:                     LE shift  112 */
  {  74,   0, 133}, /* 17:                   LIKE shift  133 */
  {  51,   0, 114}, /* 18:                     GE shift  114 */
  { 105,   0, 141}, /* 19:                  SLASH shift  141 */
  {  77,   0, 124}, /* 20:                 LSHIFT shift  124 */
  { 107,  13, 139}, /* 21:                   STAR shift  139 */
  {  52,   0, 134}, /* 22:                   GLOB shift  134 */
  {  80,  18, 137}, /* 23:                  MINUS shift  137 */
  {  81,  22, 116}, /* 24:                     NE shift  116 */
  {  82,  27, 130}, /* 25:                    NOT shift  130 */
  { 170,  28, 128}, /* 26:                 likeop shift  128 */
  {  24,   0, 145}, /* 27:                 CONCAT shift  145 */
  {  83,  29, 152}, /* 28:                NOTNULL shift  152 */
  {  54,   0, 110}, /* 29:                     GT shift  110 */
/* State 363 */
  {  72,   0, 364}, /*  1:                    KEY shift  364 */
/* State 364 */
  {  76,   0, 365}, /*  1:                     LP shift  365 */
/* State 365 */
  { 109,   0,  20}, /*  1:                 STRING shift  20 */
  { 175,   1, 260}, /*  2:                     nm shift  260 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 159,   0, 261}, /*  4:                idxitem shift  261 */
  { 160,   0, 366}, /*  5:                idxlist shift  366 */
  {  71,   0,  21}, /*  6:                JOIN_KW shift  21 */
/* State 366 */
  { 100,   0, 367}, /*  1:                     RP shift  367 */
  {  21,   0, 258}, /*  2:                  COMMA shift  258 */
/* State 367 */
  {  94,   0, 368}, /*  1:             REFERENCES shift  368 */
/* State 368 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 369}, /*  4:                     nm shift  369 */
/* State 369 */
  {  76,   0, 308}, /*  1:                     LP shift  308 */
  { 161,   0, 370}, /*  2:            idxlist_opt shift  370 */
/* State 370 */
  { 186,   0, 371}, /*  1:                refargs shift  371 */
/* State 371 */
  {  30,   0, 314}, /*  1:             DEFERRABLE shift  314 */
  {  87,   0, 296}, /*  2:                     ON shift  296 */
  {  79,   1, 294}, /*  3:                  MATCH shift  294 */
  { 185,   2, 293}, /*  4:                 refarg shift  293 */
  { 144,   0, 374}, /*  5:        defer_subclause shift  374 */
  { 145,   7, 373}, /*  6:    defer_subclause_opt shift  373 */
  {  82,   0, 372}, /*  7:                    NOT shift  372 */
/* State 372 */
  {  30,   0,  48}, /*  1:             DEFERRABLE shift  48 */
/* State 378 */
  { 102,   0,  72}, /*  1:                 SELECT shift  72 */
  { 190,   0, 379}, /*  2:                 select shift  379 */
  { 179,   0,  68}, /*  3:              oneselect shift  68 */
/* State 379 */
  {  43,   0, 163}, /*  1:                 EXCEPT shift  163 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 117,   0, 160}, /*  3:                  UNION shift  160 */
  { 103,   1, 548}, /*  4:                   SEMI reduce 19 */
  { 174,   0,  70}, /*  5:         multiselect_op shift  70 */
/* State 380 */
  { 114,   0, 399}, /*  1:                TRIGGER shift  399 */
  { 199,   3, 381}, /*  2:                   temp shift  381 */
  {  61,   0, 758}, /*  3:                  INDEX reduce 229 */
  { 207,   6, 389}, /*  4:             uniqueflag shift  389 */
  { 118,   0, 398}, /*  5:                 UNIQUE shift  398 */
  { 111,   0, 388}, /*  6:                   TEMP shift  388 */
/* State 381 */
  { 124,   2, 384}, /*  1:                   VIEW shift  384 */
  { 110,   0, 382}, /*  2:                  TABLE shift  382 */
/* State 382 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 383}, /*  4:                     nm shift  383 */
/* State 384 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 385}, /*  4:                     nm shift  385 */
/* State 385 */
  {   6,   0, 386}, /*  1:                     AS shift  386 */
/* State 386 */
  { 102,   0,  72}, /*  1:                 SELECT shift  72 */
  { 190,   0, 387}, /*  2:                 select shift  387 */
  { 179,   0,  68}, /*  3:              oneselect shift  68 */
/* State 387 */
  {  43,   0, 163}, /*  1:                 EXCEPT shift  163 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 117,   0, 160}, /*  3:                  UNION shift  160 */
  { 103,   1, 626}, /*  4:                   SEMI reduce 97 */
  { 174,   0,  70}, /*  5:         multiselect_op shift  70 */
/* State 389 */
  {  61,   0, 390}, /*  1:                  INDEX shift  390 */
/* State 390 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 391}, /*  4:                     nm shift  391 */
/* State 391 */
  {  87,   0, 392}, /*  1:                     ON shift  392 */
/* State 392 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 393}, /*  4:                     nm shift  393 */
/* State 393 */
  {  76,   0, 394}, /*  1:                     LP shift  394 */
/* State 394 */
  { 109,   0,  20}, /*  1:                 STRING shift  20 */
  { 175,   1, 260}, /*  2:                     nm shift  260 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 159,   0, 261}, /*  4:                idxitem shift  261 */
  { 160,   0, 395}, /*  5:                idxlist shift  395 */
  {  71,   0,  21}, /*  6:                JOIN_KW shift  21 */
/* State 395 */
  { 100,   0, 396}, /*  1:                     RP shift  396 */
  {  21,   0, 258}, /*  2:                  COMMA shift  258 */
/* State 396 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 178,   3, 397}, /*  2:                 onconf shift  397 */
  { 103,   0, 616}, /*  3:                   SEMI reduce 87 */
/* State 397 */
  { 103,   0, 756}, /*  1:                   SEMI reduce 227 */
/* State 398 */
  {  61,   0, 757}, /*  1:                  INDEX reduce 228 */
/* State 399 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 400}, /*  4:                     nm shift  400 */
/* State 400 */
  { 204,   2, 401}, /*  1:           trigger_time shift  401 */
  {  64,   4, 465}, /*  2:                INSTEAD shift  465 */
  {   2,   0, 464}, /*  3:                  AFTER shift  464 */
  {   8,   0, 463}, /*  4:                 BEFORE shift  463 */
/* State 401 */
  {  32,   0, 458}, /*  1:                 DELETE shift  458 */
  { 119,   3, 460}, /*  2:                 UPDATE shift  460 */
  {  63,   0, 459}, /*  3:                 INSERT shift  459 */
  { 203,   2, 402}, /*  4:          trigger_event shift  402 */
/* State 402 */
  {  87,   0, 403}, /*  1:                     ON shift  403 */
/* State 403 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 404}, /*  4:                     nm shift  404 */
/* State 404 */
  {  47,   0, 454}, /*  1:                    FOR shift  454 */
  { 153,   1, 405}, /*  2:         foreach_clause shift  405 */
/* State 405 */
  {   9,   0, 793}, /*  1:                  BEGIN reduce 264 */
  { 125,   0, 452}, /*  2:                   WHEN shift  452 */
  { 209,   2, 406}, /*  3:            when_clause shift  406 */
/* State 406 */
  {   9,   0, 407}, /*  1:                  BEGIN shift  407 */
/* State 407 */
  {  63,   0, 429}, /*  1:                 INSERT shift  429 */
  { 190,   0, 408}, /*  2:                 select shift  408 */
  { 119,   0, 414}, /*  3:                 UPDATE shift  414 */
  { 201,   7, 411}, /*  4:            trigger_cmd shift  411 */
  { 202,   8, 409}, /*  5:       trigger_cmd_list shift  409 */
  {  32,   0, 448}, /*  6:                 DELETE shift  448 */
  { 102,   0,  72}, /*  7:                 SELECT shift  72 */
  {  40,   0, 796}, /*  8:                    END reduce 267 */
  { 179,   0,  68}, /*  9:              oneselect shift  68 */
/* State 408 */
  {  43,   0, 163}, /*  1:                 EXCEPT shift  163 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 117,   0, 160}, /*  3:                  UNION shift  160 */
  { 103,   1, 801}, /*  4:                   SEMI reduce 272 */
  { 174,   0,  70}, /*  5:         multiselect_op shift  70 */
/* State 409 */
  {  40,   0, 410}, /*  1:                    END shift  410 */
/* State 410 */
  { 103,   0, 781}, /*  1:                   SEMI reduce 252 */
/* State 411 */
  { 103,   0, 412}, /*  1:                   SEMI shift  412 */
/* State 412 */
  {  63,   0, 429}, /*  1:                 INSERT shift  429 */
  { 190,   0, 408}, /*  2:                 select shift  408 */
  { 119,   0, 414}, /*  3:                 UPDATE shift  414 */
  { 201,   7, 411}, /*  4:            trigger_cmd shift  411 */
  { 202,   8, 413}, /*  5:       trigger_cmd_list shift  413 */
  {  32,   0, 448}, /*  6:                 DELETE shift  448 */
  { 102,   0,  72}, /*  7:                 SELECT shift  72 */
  {  40,   0, 796}, /*  8:                    END reduce 267 */
  { 179,   0,  68}, /*  9:              oneselect shift  68 */
/* State 413 */
  {  40,   0, 795}, /*  1:                    END reduce 266 */
/* State 414 */
  { 180,   2, 417}, /*  1:                 orconf shift  417 */
  {  88,   0, 415}, /*  2:                     OR shift  415 */
/* State 415 */
  {  96,   0,  16}, /*  1:                REPLACE shift  16 */
  { 187,   5, 416}, /*  2:            resolvetype shift  416 */
  {  98,   0,  12}, /*  3:               ROLLBACK shift  12 */
  {  57,   6,  15}, /*  4:                 IGNORE shift  15 */
  {   1,   0,  13}, /*  5:                  ABORT shift  13 */
  {  45,   0,  14}, /*  6:                   FAIL shift  14 */
/* State 417 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 418}, /*  4:                     nm shift  418 */
/* State 418 */
  { 104,   0, 419}, /*  1:                    SET shift  419 */
/* State 419 */
  { 175,   0, 426}, /*  1:                     nm shift  426 */
  {  71,   4,  21}, /*  2:                JOIN_KW shift  21 */
  { 192,   0, 420}, /*  3:                setlist shift  420 */
  {  56,   0,  19}, /*  4:                     ID shift  19 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 420 */
  { 126,   0, 230}, /*  1:                  WHERE shift  230 */
  {  21,   0, 421}, /*  2:                  COMMA shift  421 */
  { 210,   1, 425}, /*  3:              where_opt shift  425 */
  { 103,   0, 682}, /*  4:                   SEMI reduce 153 */
/* State 421 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 422}, /*  4:                     nm shift  422 */
/* State 422 */
  {  42,   0, 423}, /*  1:                     EQ shift  423 */
/* State 423 */
  { 150,   3, 424}, /*  1:                   expr shift  424 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 424 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  60,   0, 157}, /*  7:                     IN shift  157 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  { 170,   0, 128}, /*  9:                 likeop shift  128 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   5, 143}, /* 15:                    REM shift  143 */
  {  69,  13, 147}, /* 16:                 ISNULL shift  147 */
  {  74,   0, 133}, /* 17:                   LIKE shift  133 */
  {  78,  19, 108}, /* 18:                     LT shift  108 */
  {  51,  22, 114}, /* 19:                     GE shift  114 */
  {  73,   0, 112}, /* 20:                     LE shift  112 */
  { 101,  17, 126}, /* 21:                 RSHIFT shift  126 */
  {  24,   0, 145}, /* 22:                 CONCAT shift  145 */
  {  80,   0, 137}, /* 23:                  MINUS shift  137 */
  {  77,   0, 124}, /* 24:                 LSHIFT shift  124 */
  { 105,  18, 141}, /* 25:                  SLASH shift  141 */
  {  52,   0, 134}, /* 26:                   GLOB shift  134 */
  { 107,  23, 139}, /* 27:                   STAR shift  139 */
/* State 425 */
  { 103,   0, 797}, /*  1:                   SEMI reduce 268 */
/* State 426 */
  {  42,   0, 427}, /*  1:                     EQ shift  427 */
/* State 427 */
  { 150,   3, 428}, /*  1:                   expr shift  428 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 428 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  60,   0, 157}, /*  7:                     IN shift  157 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  { 170,   0, 128}, /*  9:                 likeop shift  128 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   5, 143}, /* 15:                    REM shift  143 */
  {  69,  13, 147}, /* 16:                 ISNULL shift  147 */
  {  74,   0, 133}, /* 17:                   LIKE shift  133 */
  {  78,  19, 108}, /* 18:                     LT shift  108 */
  {  51,  22, 114}, /* 19:                     GE shift  114 */
  {  73,   0, 112}, /* 20:                     LE shift  112 */
  { 101,  17, 126}, /* 21:                 RSHIFT shift  126 */
  {  24,   0, 145}, /* 22:                 CONCAT shift  145 */
  {  80,   0, 137}, /* 23:                  MINUS shift  137 */
  {  77,   0, 124}, /* 24:                 LSHIFT shift  124 */
  { 105,  18, 141}, /* 25:                  SLASH shift  141 */
  {  52,   0, 134}, /* 26:                   GLOB shift  134 */
  { 107,  23, 139}, /* 27:                   STAR shift  139 */
/* State 429 */
  { 180,   0, 430}, /*  1:                 orconf shift  430 */
  {  88,   3, 415}, /*  2:                     OR shift  415 */
  {  67,   0, 618}, /*  3:                   INTO reduce 89 */
/* State 430 */
  {  67,   0, 431}, /*  1:                   INTO shift  431 */
/* State 431 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 432}, /*  4:                     nm shift  432 */
/* State 432 */
  {  76,   0, 433}, /*  1:                     LP shift  433 */
  { 165,   0, 439}, /*  2:         inscollist_opt shift  439 */
/* State 433 */
  { 175,   0, 438}, /*  1:                     nm shift  438 */
  {  71,   3,  21}, /*  2:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 109,   0,  20}, /*  4:                 STRING shift  20 */
  { 164,   4, 434}, /*  5:             inscollist shift  434 */
/* State 434 */
  { 100,   0, 435}, /*  1:                     RP shift  435 */
  {  21,   0, 436}, /*  2:                  COMMA shift  436 */
/* State 436 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 437}, /*  4:                     nm shift  437 */
/* State 439 */
  { 102,   0,  72}, /*  1:                 SELECT shift  72 */
  { 123,   0, 441}, /*  2:                 VALUES shift  441 */
  { 190,   1, 440}, /*  3:                 select shift  440 */
  { 179,   2,  68}, /*  4:              oneselect shift  68 */
/* State 440 */
  {  43,   0, 163}, /*  1:                 EXCEPT shift  163 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 117,   0, 160}, /*  3:                  UNION shift  160 */
  { 103,   1, 799}, /*  4:                   SEMI reduce 270 */
  { 174,   0,  70}, /*  5:         multiselect_op shift  70 */
/* State 441 */
  {  76,   0, 442}, /*  1:                     LP shift  442 */
/* State 442 */
  {  80,   4, 170}, /*  1:                  MINUS shift  170 */
  {  65,   0, 103}, /*  2:                INTEGER shift  103 */
  {  82,   0, 166}, /*  3:                    NOT shift  166 */
  {  16,   0, 174}, /*  4:                   CASE shift  174 */
  {  84,   0,  99}, /*  5:                   NULL shift  99 */
  {  71,   0,  66}, /*  6:                JOIN_KW shift  66 */
  { 150,   0, 447}, /*  7:                   expr shift  447 */
  { 167,   6, 443}, /*  8:               itemlist shift  443 */
  {  56,   0,  63}, /*  9:                     ID shift  63 */
  {  12,   0, 168}, /* 10:                 BITNOT shift  168 */
  {  90,   0, 172}, /* 11:                   PLUS shift  172 */
  {  93,   0, 184}, /* 12:                  RAISE shift  184 */
  {  76,  10,  67}, /* 13:                     LP shift  67 */
  { 109,  12,  65}, /* 14:                 STRING shift  65 */
  {  46,   0, 104}, /* 15:                  FLOAT shift  104 */
  { 175,   0, 100}, /* 16:                     nm shift  100 */
/* State 443 */
  { 100,   0, 446}, /*  1:                     RP shift  446 */
  {  21,   0, 444}, /*  2:                  COMMA shift  444 */
/* State 444 */
  { 150,   3, 445}, /*  1:                   expr shift  445 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 445 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  60,   0, 157}, /*  7:                     IN shift  157 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  { 170,   0, 128}, /*  9:                 likeop shift  128 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   5, 143}, /* 15:                    REM shift  143 */
  {  69,  13, 147}, /* 16:                 ISNULL shift  147 */
  {  74,   0, 133}, /* 17:                   LIKE shift  133 */
  {  78,  19, 108}, /* 18:                     LT shift  108 */
  {  51,  22, 114}, /* 19:                     GE shift  114 */
  {  73,   0, 112}, /* 20:                     LE shift  112 */
  { 101,  17, 126}, /* 21:                 RSHIFT shift  126 */
  {  24,   0, 145}, /* 22:                 CONCAT shift  145 */
  {  80,   0, 137}, /* 23:                  MINUS shift  137 */
  {  77,   0, 124}, /* 24:                 LSHIFT shift  124 */
  { 105,  18, 141}, /* 25:                  SLASH shift  141 */
  {  52,   0, 134}, /* 26:                   GLOB shift  134 */
  { 107,  23, 139}, /* 27:                   STAR shift  139 */
/* State 446 */
  { 103,   0, 798}, /*  1:                   SEMI reduce 269 */
/* State 447 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  60,   0, 157}, /*  7:                     IN shift  157 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  { 170,   0, 128}, /*  9:                 likeop shift  128 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   5, 143}, /* 15:                    REM shift  143 */
  {  69,  13, 147}, /* 16:                 ISNULL shift  147 */
  {  74,   0, 133}, /* 17:                   LIKE shift  133 */
  {  78,  19, 108}, /* 18:                     LT shift  108 */
  {  51,  22, 114}, /* 19:                     GE shift  114 */
  {  73,   0, 112}, /* 20:                     LE shift  112 */
  { 101,  17, 126}, /* 21:                 RSHIFT shift  126 */
  {  24,   0, 145}, /* 22:                 CONCAT shift  145 */
  {  80,   0, 137}, /* 23:                  MINUS shift  137 */
  {  77,   0, 124}, /* 24:                 LSHIFT shift  124 */
  { 105,  18, 141}, /* 25:                  SLASH shift  141 */
  {  52,   0, 134}, /* 26:                   GLOB shift  134 */
  { 107,  23, 139}, /* 27:                   STAR shift  139 */
/* State 448 */
  {  49,   0, 449}, /*  1:                   FROM shift  449 */
/* State 449 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 450}, /*  4:                     nm shift  450 */
/* State 450 */
  { 210,   3, 451}, /*  1:              where_opt shift  451 */
  { 103,   0, 682}, /*  2:                   SEMI reduce 153 */
  { 126,   0, 230}, /*  3:                  WHERE shift  230 */
/* State 451 */
  { 103,   0, 800}, /*  1:                   SEMI reduce 271 */
/* State 452 */
  { 150,   3, 453}, /*  1:                   expr shift  453 */
  {  76,   7,  67}, /*  2:                     LP shift  67 */
  {  90,   0, 172}, /*  3:                   PLUS shift  172 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,   9, 170}, /*  6:                  MINUS shift  170 */
  {  46,  14, 104}, /*  7:                  FLOAT shift  104 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  {  65,   0, 103}, /*  9:                INTEGER shift  103 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  { 175,   0, 100}, /* 11:                     nm shift  100 */
  {  71,  15,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  16,   0, 174}, /* 14:                   CASE shift  174 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 453 */
  {  60,   0, 157}, /*  1:                     IN shift  157 */
  {  11,   0, 120}, /*  2:                 BITAND shift  120 */
  { 170,   0, 128}, /*  3:                 likeop shift  128 */
  {  13,   0, 122}, /*  4:                  BITOR shift  122 */
  {  88,   1, 106}, /*  5:                     OR shift  106 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
  {  73,   0, 112}, /*  8:                     LE shift  112 */
  {  77,   0, 124}, /*  9:                 LSHIFT shift  124 */
  {   9,   0, 794}, /* 10:                  BEGIN reduce 265 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  95,   2, 143}, /* 12:                    REM shift  143 */
  {  68,   0, 148}, /* 13:                     IS shift  148 */
  {  69,   4, 147}, /* 14:                 ISNULL shift  147 */
  {  42,   0, 118}, /* 15:                     EQ shift  118 */
  {  51,   0, 114}, /* 16:                     GE shift  114 */
  {  52,  20, 134}, /* 17:                   GLOB shift  134 */
  { 101,   8, 126}, /* 18:                 RSHIFT shift  126 */
  {  74,   0, 133}, /* 19:                   LIKE shift  133 */
  {  24,   0, 145}, /* 20:                 CONCAT shift  145 */
  {  54,   0, 110}, /* 21:                     GT shift  110 */
  { 105,   9, 141}, /* 22:                  SLASH shift  141 */
  {  78,   0, 108}, /* 23:                     LT shift  108 */
  { 107,  16, 139}, /* 24:                   STAR shift  139 */
  {  80,  17, 137}, /* 25:                  MINUS shift  137 */
  {  81,   0, 116}, /* 26:                     NE shift  116 */
  {  82,  21, 130}, /* 27:                    NOT shift  130 */
  {  83,   0, 152}, /* 28:                NOTNULL shift  152 */
/* State 454 */
  {  38,   0, 455}, /*  1:                   EACH shift  455 */
/* State 455 */
  { 108,   0, 457}, /*  1:              STATEMENT shift  457 */
  {  99,   0, 456}, /*  2:                    ROW shift  456 */
/* State 458 */
  {  87,   0, 786}, /*  1:                     ON reduce 257 */
/* State 459 */
  {  87,   0, 787}, /*  1:                     ON reduce 258 */
/* State 460 */
  {  85,   0, 461}, /*  1:                     OF shift  461 */
  {  87,   1, 788}, /*  2:                     ON reduce 259 */
/* State 461 */
  { 175,   0, 438}, /*  1:                     nm shift  438 */
  {  71,   3,  21}, /*  2:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 109,   0,  20}, /*  4:                 STRING shift  20 */
  { 164,   4, 462}, /*  5:             inscollist shift  462 */
/* State 462 */
  {  21,   0, 436}, /*  1:                  COMMA shift  436 */
  {  87,   1, 789}, /*  2:                     ON reduce 260 */
/* State 465 */
  {  85,   0, 466}, /*  1:                     OF shift  466 */
/* State 467 */
  { 124,   0, 470}, /*  1:                   VIEW shift  470 */
  {  61,   0, 472}, /*  2:                  INDEX shift  472 */
  { 114,   4, 474}, /*  3:                TRIGGER shift  474 */
  { 110,   0, 468}, /*  4:                  TABLE shift  468 */
/* State 468 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 469}, /*  4:                     nm shift  469 */
/* State 469 */
  { 103,   0, 625}, /*  1:                   SEMI reduce 96 */
/* State 470 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 471}, /*  4:                     nm shift  471 */
/* State 471 */
  { 103,   0, 627}, /*  1:                   SEMI reduce 98 */
/* State 472 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 473}, /*  4:                     nm shift  473 */
/* State 473 */
  { 103,   0, 764}, /*  1:                   SEMI reduce 235 */
/* State 474 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 475}, /*  4:                     nm shift  475 */
/* State 475 */
  { 103,   0, 806}, /*  1:                   SEMI reduce 277 */
/* State 476 */
  {  43,   0, 163}, /*  1:                 EXCEPT shift  163 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 117,   0, 160}, /*  3:                  UNION shift  160 */
  { 103,   1, 628}, /*  4:                   SEMI reduce 99 */
  { 174,   0,  70}, /*  5:         multiselect_op shift  70 */
/* State 477 */
  {  49,   0, 478}, /*  1:                   FROM shift  478 */
/* State 478 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 479}, /*  4:                     nm shift  479 */
/* State 479 */
  { 210,   3, 480}, /*  1:              where_opt shift  480 */
  { 103,   0, 682}, /*  2:                   SEMI reduce 153 */
  { 126,   0, 230}, /*  3:                  WHERE shift  230 */
/* State 480 */
  { 103,   0, 681}, /*  1:                   SEMI reduce 152 */
/* State 481 */
  { 180,   2, 482}, /*  1:                 orconf shift  482 */
  {  88,   0, 415}, /*  2:                     OR shift  415 */
/* State 482 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 483}, /*  4:                     nm shift  483 */
/* State 483 */
  { 104,   0, 484}, /*  1:                    SET shift  484 */
/* State 484 */
  { 175,   0, 426}, /*  1:                     nm shift  426 */
  {  71,   4,  21}, /*  2:                JOIN_KW shift  21 */
  { 192,   0, 485}, /*  3:                setlist shift  485 */
  {  56,   0,  19}, /*  4:                     ID shift  19 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 485 */
  { 126,   0, 230}, /*  1:                  WHERE shift  230 */
  {  21,   0, 421}, /*  2:                  COMMA shift  421 */
  { 210,   1, 486}, /*  3:              where_opt shift  486 */
  { 103,   0, 682}, /*  4:                   SEMI reduce 153 */
/* State 486 */
  { 103,   0, 684}, /*  1:                   SEMI reduce 155 */
/* State 487 */
  {  67,   0, 488}, /*  1:                   INTO shift  488 */
/* State 488 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 489}, /*  4:                     nm shift  489 */
/* State 489 */
  {  76,   0, 433}, /*  1:                     LP shift  433 */
  { 165,   0, 490}, /*  2:         inscollist_opt shift  490 */
/* State 490 */
  { 102,   0,  72}, /*  1:                 SELECT shift  72 */
  { 123,   0, 492}, /*  2:                 VALUES shift  492 */
  { 190,   1, 491}, /*  3:                 select shift  491 */
  { 179,   2,  68}, /*  4:              oneselect shift  68 */
/* State 491 */
  {  43,   0, 163}, /*  1:                 EXCEPT shift  163 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 117,   0, 160}, /*  3:                  UNION shift  160 */
  { 103,   1, 688}, /*  4:                   SEMI reduce 159 */
  { 174,   0,  70}, /*  5:         multiselect_op shift  70 */
/* State 492 */
  {  76,   0, 493}, /*  1:                     LP shift  493 */
/* State 493 */
  {  80,   4, 170}, /*  1:                  MINUS shift  170 */
  {  65,   0, 103}, /*  2:                INTEGER shift  103 */
  {  82,   0, 166}, /*  3:                    NOT shift  166 */
  {  16,   0, 174}, /*  4:                   CASE shift  174 */
  {  84,   0,  99}, /*  5:                   NULL shift  99 */
  {  71,   0,  66}, /*  6:                JOIN_KW shift  66 */
  { 150,   0, 447}, /*  7:                   expr shift  447 */
  { 167,   6, 494}, /*  8:               itemlist shift  494 */
  {  56,   0,  63}, /*  9:                     ID shift  63 */
  {  12,   0, 168}, /* 10:                 BITNOT shift  168 */
  {  90,   0, 172}, /* 11:                   PLUS shift  172 */
  {  93,   0, 184}, /* 12:                  RAISE shift  184 */
  {  76,  10,  67}, /* 13:                     LP shift  67 */
  { 109,  12,  65}, /* 14:                 STRING shift  65 */
  {  46,   0, 104}, /* 15:                  FLOAT shift  104 */
  { 175,   0, 100}, /* 16:                     nm shift  100 */
/* State 494 */
  { 100,   0, 495}, /*  1:                     RP shift  495 */
  {  21,   0, 444}, /*  2:                  COMMA shift  444 */
/* State 495 */
  { 103,   0, 687}, /*  1:                   SEMI reduce 158 */
/* State 496 */
  { 180,   0, 497}, /*  1:                 orconf shift  497 */
  {  88,   3, 415}, /*  2:                     OR shift  415 */
  {  67,   0, 618}, /*  3:                   INTO reduce 89 */
/* State 497 */
  {  67,   0, 689}, /*  1:                   INTO reduce 160 */
/* State 498 */
  {  67,   0, 690}, /*  1:                   INTO reduce 161 */
/* State 499 */
  { 180,   2, 500}, /*  1:                 orconf shift  500 */
  {  88,   0, 415}, /*  2:                     OR shift  415 */
/* State 500 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 501}, /*  4:                     nm shift  501 */
/* State 501 */
  {  49,   0, 502}, /*  1:                   FROM shift  502 */
/* State 502 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 503}, /*  4:                     nm shift  503 */
/* State 503 */
  { 103,   0, 766}, /*  1:                   SEMI reduce 237 */
  { 121,   1, 504}, /*  2:                  USING shift  504 */
/* State 504 */
  {  33,   0, 505}, /*  1:             DELIMITERS shift  505 */
/* State 505 */
  { 109,   0, 506}, /*  1:                 STRING shift  506 */
/* State 506 */
  { 103,   0, 765}, /*  1:                   SEMI reduce 236 */
/* State 507 */
  { 175,   0, 508}, /*  1:                     nm shift  508 */
  {  71,   3,  21}, /*  2:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 103,   0, 767}, /*  4:                   SEMI reduce 238 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 508 */
  { 103,   0, 768}, /*  1:                   SEMI reduce 239 */
/* State 509 */
  {  56,   0, 246}, /*  1:                     ID shift  246 */
  { 109,   0, 247}, /*  2:                 STRING shift  247 */
  { 158,   1, 510}, /*  3:                    ids shift  510 */
/* State 510 */
  {  42,   0, 511}, /*  1:                     EQ shift  511 */
  { 103,   3, 774}, /*  2:                   SEMI reduce 245 */
  {  76,   0, 523}, /*  3:                     LP shift  523 */
/* State 511 */
  {  90,   5, 522}, /*  1:                   PLUS shift  522 */
  {  71,   0,  21}, /*  2:                JOIN_KW shift  21 */
  { 182,   0, 514}, /*  3:               plus_num shift  514 */
  { 183,   9, 516}, /*  4:               plus_opt shift  516 */
  {  80,   0, 520}, /*  5:                  MINUS shift  520 */
  { 175,   0, 512}, /*  6:                     nm shift  512 */
  {  56,   0,  19}, /*  7:                     ID shift  19 */
  {  87,   0, 513}, /*  8:                     ON shift  513 */
  { 173,   0, 515}, /*  9:              minus_num shift  515 */
  { 109,   0,  20}, /* 10:                 STRING shift  20 */
/* State 512 */
  { 103,   0, 769}, /*  1:                   SEMI reduce 240 */
/* State 513 */
  { 103,   0, 770}, /*  1:                   SEMI reduce 241 */
/* State 514 */
  { 103,   0, 771}, /*  1:                   SEMI reduce 242 */
/* State 515 */
  { 103,   0, 772}, /*  1:                   SEMI reduce 243 */
/* State 516 */
  {  65,   0, 518}, /*  1:                INTEGER shift  518 */
  {  46,   0, 519}, /*  2:                  FLOAT shift  519 */
  { 176,   1, 517}, /*  3:                 number shift  517 */
/* State 517 */
  { 103,   0, 775}, /*  1:                   SEMI reduce 246 */
/* State 518 */
  { 103,   0, 777}, /*  1:                   SEMI reduce 248 */
/* State 519 */
  { 103,   0, 778}, /*  1:                   SEMI reduce 249 */
/* State 520 */
  {  65,   0, 518}, /*  1:                INTEGER shift  518 */
  {  46,   0, 519}, /*  2:                  FLOAT shift  519 */
  { 176,   1, 521}, /*  3:                 number shift  521 */
/* State 521 */
  { 103,   0, 776}, /*  1:                   SEMI reduce 247 */
/* State 523 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  {  71,   0,  21}, /*  3:                JOIN_KW shift  21 */
  { 175,   3, 524}, /*  4:                     nm shift  524 */
/* State 524 */
  { 100,   0, 525}, /*  1:                     RP shift  525 */
/* State 525 */
  { 103,   0, 773}, /*  1:                   SEMI reduce 244 */
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
  { &yyActionTable[0],   6, 535 },
  { &yyActionTable[6],   5, 535 },
  { &yyActionTable[11],   0, 531 },
  { &yyActionTable[11],  19, 807 },
  { &yyActionTable[30],   1, 807 },
  { &yyActionTable[31],   0, 532 },
  { &yyActionTable[31],   2, 537 },
  { &yyActionTable[33],   3, 807 },
  { &yyActionTable[36],   1, 807 },
  { &yyActionTable[37],   1, 807 },
  { &yyActionTable[38],   6, 807 },
  { &yyActionTable[44],   0, 617 },
  { &yyActionTable[44],   0, 620 },
  { &yyActionTable[44],   0, 621 },
  { &yyActionTable[44],   0, 622 },
  { &yyActionTable[44],   0, 623 },
  { &yyActionTable[44],   0, 624 },
  { &yyActionTable[44],   4, 538 },
  { &yyActionTable[48],   0, 539 },
  { &yyActionTable[48],   0, 556 },
  { &yyActionTable[48],   0, 557 },
  { &yyActionTable[48],   0, 558 },
  { &yyActionTable[48],   3, 807 },
  { &yyActionTable[51],   1, 807 },
  { &yyActionTable[52],   3, 807 },
  { &yyActionTable[55],   1, 807 },
  { &yyActionTable[56],   3, 807 },
  { &yyActionTable[59],   1, 807 },
  { &yyActionTable[60],   3, 807 },
  { &yyActionTable[63],   1, 807 },
  { &yyActionTable[64],   7, 807 },
  { &yyActionTable[71],   3, 807 },
  { &yyActionTable[74],   1, 807 },
  { &yyActionTable[75],   1, 807 },
  { &yyActionTable[76],  13, 807 },
  { &yyActionTable[89],   0, 549 },
  { &yyActionTable[89],   5, 559 },
  { &yyActionTable[94],   1, 569 },
  { &yyActionTable[95],  13, 551 },
  { &yyActionTable[108],   0, 568 },
  { &yyActionTable[108],   4, 807 },
  { &yyActionTable[112],  10, 807 },
  { &yyActionTable[122],   0, 570 },
  { &yyActionTable[122],   2, 616 },
  { &yyActionTable[124],   0, 581 },
  { &yyActionTable[124],   2, 807 },
  { &yyActionTable[126],   2, 616 },
  { &yyActionTable[128],   0, 582 },
  { &yyActionTable[128],   2, 601 },
  { &yyActionTable[130],   0, 599 },
  { &yyActionTable[130],   2, 807 },
  { &yyActionTable[132],   0, 602 },
  { &yyActionTable[132],   0, 603 },
  { &yyActionTable[132],   1, 807 },
  { &yyActionTable[133],   3, 669 },
  { &yyActionTable[136],   2, 616 },
  { &yyActionTable[138],   0, 583 },
  { &yyActionTable[138],   0, 667 },
  { &yyActionTable[138],   0, 668 },
  { &yyActionTable[138],   2, 616 },
  { &yyActionTable[140],   0, 584 },
  { &yyActionTable[140],   1, 807 },
  { &yyActionTable[141],  15, 807 },
  { &yyActionTable[156],   2, 699 },
  { &yyActionTable[158],  18, 755 },
  { &yyActionTable[176],   1, 704 },
  { &yyActionTable[177],   1, 700 },
  { &yyActionTable[178],  18, 807 },
  { &yyActionTable[196],   0, 629 },
  { &yyActionTable[196],   5, 807 },
  { &yyActionTable[201],   2, 807 },
  { &yyActionTable[203],   0, 630 },
  { &yyActionTable[203],   3, 638 },
  { &yyActionTable[206],   2, 640 },
  { &yyActionTable[208],   3, 647 },
  { &yyActionTable[211],   2, 682 },
  { &yyActionTable[213],   2, 672 },
  { &yyActionTable[215],   2, 674 },
  { &yyActionTable[217],   2, 662 },
  { &yyActionTable[219],   2, 676 },
  { &yyActionTable[221],   0, 635 },
  { &yyActionTable[221],   1, 807 },
  { &yyActionTable[222],   3, 677 },
  { &yyActionTable[225],   1, 807 },
  { &yyActionTable[226],   0, 678 },
  { &yyActionTable[226],   1, 807 },
  { &yyActionTable[227],   1, 807 },
  { &yyActionTable[228],   1, 807 },
  { &yyActionTable[229],  17, 807 },
  { &yyActionTable[246],   1, 663 },
  { &yyActionTable[247],  16, 807 },
  { &yyActionTable[263],   2, 670 },
  { &yyActionTable[265],   3, 669 },
  { &yyActionTable[268],   0, 664 },
  { &yyActionTable[268],   2, 807 },
  { &yyActionTable[270],   0, 553 },
  { &yyActionTable[270],   0, 671 },
  { &yyActionTable[270],  27, 666 },
  { &yyActionTable[297],  15, 807 },
  { &yyActionTable[312],   0, 698 },
  { &yyActionTable[312],   1, 807 },
  { &yyActionTable[313],   4, 807 },
  { &yyActionTable[317],   0, 701 },
  { &yyActionTable[317],   0, 702 },
  { &yyActionTable[317],   0, 703 },
  { &yyActionTable[317],  25, 707 },
  { &yyActionTable[342],  15, 807 },
  { &yyActionTable[357],  26, 708 },
  { &yyActionTable[383],  15, 807 },
  { &yyActionTable[398],  11, 709 },
  { &yyActionTable[409],  15, 807 },
  { &yyActionTable[424],  11, 710 },
  { &yyActionTable[435],  15, 807 },
  { &yyActionTable[450],  11, 711 },
  { &yyActionTable[461],  15, 807 },
  { &yyActionTable[476],  11, 712 },
  { &yyActionTable[487],  15, 807 },
  { &yyActionTable[502],  15, 713 },
  { &yyActionTable[517],  15, 807 },
  { &yyActionTable[532],  15, 714 },
  { &yyActionTable[547],  15, 807 },
  { &yyActionTable[562],   7, 715 },
  { &yyActionTable[569],  15, 807 },
  { &yyActionTable[584],   7, 716 },
  { &yyActionTable[591],  15, 807 },
  { &yyActionTable[606],   7, 717 },
  { &yyActionTable[613],  15, 807 },
  { &yyActionTable[628],   7, 718 },
  { &yyActionTable[635],  15, 807 },
  { &yyActionTable[650],  15, 719 },
  { &yyActionTable[665],   6, 807 },
  { &yyActionTable[671],  15, 807 },
  { &yyActionTable[686],  15, 720 },
  { &yyActionTable[701],   0, 721 },
  { &yyActionTable[701],   0, 722 },
  { &yyActionTable[701],  15, 807 },
  { &yyActionTable[716],   5, 723 },
  { &yyActionTable[721],  15, 807 },
  { &yyActionTable[736],   5, 724 },
  { &yyActionTable[741],  15, 807 },
  { &yyActionTable[756],   2, 725 },
  { &yyActionTable[758],  15, 807 },
  { &yyActionTable[773],   2, 726 },
  { &yyActionTable[775],  15, 807 },
  { &yyActionTable[790],   2, 727 },
  { &yyActionTable[792],  15, 807 },
  { &yyActionTable[807],   1, 728 },
  { &yyActionTable[808],   0, 729 },
  { &yyActionTable[808],   2, 807 },
  { &yyActionTable[810],   0, 730 },
  { &yyActionTable[810],   1, 807 },
  { &yyActionTable[811],   0, 733 },
  { &yyActionTable[811],   0, 731 },
  { &yyActionTable[811],  15, 807 },
  { &yyActionTable[826],  27, 807 },
  { &yyActionTable[853],  15, 807 },
  { &yyActionTable[868],  15, 739 },
  { &yyActionTable[883],   1, 807 },
  { &yyActionTable[884],  20, 755 },
  { &yyActionTable[904],   5, 807 },
  { &yyActionTable[909],   2, 807 },
  { &yyActionTable[911],   1, 807 },
  { &yyActionTable[912],   1, 807 },
  { &yyActionTable[913],   1, 807 },
  { &yyActionTable[914],   0, 742 },
  { &yyActionTable[914],  27, 754 },
  { &yyActionTable[941],  15, 807 },
  { &yyActionTable[956],  25, 734 },
  { &yyActionTable[981],  15, 807 },
  { &yyActionTable[996],   1, 735 },
  { &yyActionTable[997],  15, 807 },
  { &yyActionTable[1012],   1, 736 },
  { &yyActionTable[1013],  15, 807 },
  { &yyActionTable[1028],   1, 737 },
  { &yyActionTable[1029],  17, 807 },
  { &yyActionTable[1046],  28, 807 },
  { &yyActionTable[1074],   2, 807 },
  { &yyActionTable[1076],   4, 807 },
  { &yyActionTable[1080],   1, 807 },
  { &yyActionTable[1081],   0, 745 },
  { &yyActionTable[1081],  15, 807 },
  { &yyActionTable[1096],  28, 807 },
  { &yyActionTable[1124],  15, 807 },
  { &yyActionTable[1139],  27, 746 },
  { &yyActionTable[1166],   1, 807 },
  { &yyActionTable[1167],   4, 807 },
  { &yyActionTable[1171],   1, 807 },
  { &yyActionTable[1172],   0, 802 },
  { &yyActionTable[1172],   1, 807 },
  { &yyActionTable[1173],   4, 807 },
  { &yyActionTable[1177],   1, 807 },
  { &yyActionTable[1178],   0, 803 },
  { &yyActionTable[1178],   1, 807 },
  { &yyActionTable[1179],   4, 807 },
  { &yyActionTable[1183],   1, 807 },
  { &yyActionTable[1184],   0, 804 },
  { &yyActionTable[1184],   1, 807 },
  { &yyActionTable[1185],   4, 807 },
  { &yyActionTable[1189],   1, 807 },
  { &yyActionTable[1190],   0, 805 },
  { &yyActionTable[1190],  15, 807 },
  { &yyActionTable[1205],  28, 807 },
  { &yyActionTable[1233],  15, 807 },
  { &yyActionTable[1248],  28, 807 },
  { &yyActionTable[1276],  15, 807 },
  { &yyActionTable[1291],  27, 747 },
  { &yyActionTable[1318],   2, 807 },
  { &yyActionTable[1320],   0, 741 },
  { &yyActionTable[1320],  16, 755 },
  { &yyActionTable[1336],   0, 752 },
  { &yyActionTable[1336],   0, 753 },
  { &yyActionTable[1336],   0, 732 },
  { &yyActionTable[1336],  15, 807 },
  { &yyActionTable[1351],  27, 807 },
  { &yyActionTable[1378],  15, 807 },
  { &yyActionTable[1393],  25, 740 },
  { &yyActionTable[1418],   1, 807 },
  { &yyActionTable[1419],  20, 755 },
  { &yyActionTable[1439],   5, 807 },
  { &yyActionTable[1444],   0, 744 },
  { &yyActionTable[1444],   2, 807 },
  { &yyActionTable[1446],   0, 743 },
  { &yyActionTable[1446],   2, 670 },
  { &yyActionTable[1448],   3, 669 },
  { &yyActionTable[1451],   0, 665 },
  { &yyActionTable[1451],  15, 807 },
  { &yyActionTable[1466],  27, 675 },
  { &yyActionTable[1493],   1, 807 },
  { &yyActionTable[1494],  17, 755 },
  { &yyActionTable[1511],   1, 673 },
  { &yyActionTable[1512],  15, 807 },
  { &yyActionTable[1527],  27, 683 },
  { &yyActionTable[1554],   0, 639 },
  { &yyActionTable[1554],   2, 650 },
  { &yyActionTable[1556],   4, 648 },
  { &yyActionTable[1560],   0, 649 },
  { &yyActionTable[1560],   0, 653 },
  { &yyActionTable[1560],   0, 654 },
  { &yyActionTable[1560],   5, 807 },
  { &yyActionTable[1565],   0, 655 },
  { &yyActionTable[1565],   5, 807 },
  { &yyActionTable[1570],   0, 656 },
  { &yyActionTable[1570],   1, 807 },
  { &yyActionTable[1571],   0, 657 },
  { &yyActionTable[1571],   5, 807 },
  { &yyActionTable[1576],   5, 646 },
  { &yyActionTable[1581],   0, 554 },
  { &yyActionTable[1581],   0, 555 },
  { &yyActionTable[1581],   4, 807 },
  { &yyActionTable[1585],   0, 644 },
  { &yyActionTable[1585],   0, 645 },
  { &yyActionTable[1585],   2, 659 },
  { &yyActionTable[1587],   2, 661 },
  { &yyActionTable[1589],   0, 651 },
  { &yyActionTable[1589],   1, 807 },
  { &yyActionTable[1590],   6, 807 },
  { &yyActionTable[1596],   2, 807 },
  { &yyActionTable[1598],   0, 660 },
  { &yyActionTable[1598],   5, 807 },
  { &yyActionTable[1603],   0, 761 },
  { &yyActionTable[1603],   0, 763 },
  { &yyActionTable[1603],   0, 762 },
  { &yyActionTable[1603],  15, 807 },
  { &yyActionTable[1618],  27, 658 },
  { &yyActionTable[1645],   3, 807 },
  { &yyActionTable[1648],   5, 807 },
  { &yyActionTable[1653],   5, 646 },
  { &yyActionTable[1658],   2, 659 },
  { &yyActionTable[1660],   2, 661 },
  { &yyActionTable[1662],   0, 652 },
  { &yyActionTable[1662],  16, 807 },
  { &yyActionTable[1678],  32, 646 },
  { &yyActionTable[1710],   0, 641 },
  { &yyActionTable[1710],   0, 642 },
  { &yyActionTable[1710],   1, 807 },
  { &yyActionTable[1711],   5, 807 },
  { &yyActionTable[1716],   0, 643 },
  { &yyActionTable[1716],   0, 636 },
  { &yyActionTable[1716],   0, 637 },
  { &yyActionTable[1716],   0, 738 },
  { &yyActionTable[1716],  28, 807 },
  { &yyActionTable[1744],   0, 697 },
  { &yyActionTable[1744],   2, 807 },
  { &yyActionTable[1746],   0, 705 },
  { &yyActionTable[1746],   1, 807 },
  { &yyActionTable[1747],   0, 706 },
  { &yyActionTable[1747],  28, 807 },
  { &yyActionTable[1775],   2, 616 },
  { &yyActionTable[1777],   0, 585 },
  { &yyActionTable[1777],   4, 807 },
  { &yyActionTable[1781],   2, 759 },
  { &yyActionTable[1783],   1, 589 },
  { &yyActionTable[1784],   3, 586 },
  { &yyActionTable[1787],   0, 590 },
  { &yyActionTable[1787],   4, 807 },
  { &yyActionTable[1791],   0, 591 },
  { &yyActionTable[1791],   3, 807 },
  { &yyActionTable[1794],   4, 807 },
  { &yyActionTable[1798],   0, 592 },
  { &yyActionTable[1798],   2, 807 },
  { &yyActionTable[1800],   0, 595 },
  { &yyActionTable[1800],   0, 596 },
  { &yyActionTable[1800],   0, 597 },
  { &yyActionTable[1800],   0, 598 },
  { &yyActionTable[1800],   4, 807 },
  { &yyActionTable[1804],   0, 593 },
  { &yyActionTable[1804],   4, 807 },
  { &yyActionTable[1808],   0, 594 },
  { &yyActionTable[1808],   6, 807 },
  { &yyActionTable[1814],   2, 807 },
  { &yyActionTable[1816],   0, 760 },
  { &yyActionTable[1816],   0, 587 },
  { &yyActionTable[1816],   2, 807 },
  { &yyActionTable[1818],   0, 588 },
  { &yyActionTable[1818],   2, 601 },
  { &yyActionTable[1820],   0, 600 },
  { &yyActionTable[1820],   0, 571 },
  { &yyActionTable[1820],   7, 807 },
  { &yyActionTable[1827],   0, 572 },
  { &yyActionTable[1827],   0, 573 },
  { &yyActionTable[1827],   0, 574 },
  { &yyActionTable[1827],   2, 807 },
  { &yyActionTable[1829],   0, 575 },
  { &yyActionTable[1829],   0, 578 },
  { &yyActionTable[1829],   2, 807 },
  { &yyActionTable[1831],   0, 576 },
  { &yyActionTable[1831],   0, 579 },
  { &yyActionTable[1831],   0, 577 },
  { &yyActionTable[1831],   0, 580 },
  { &yyActionTable[1831],   4, 560 },
  { &yyActionTable[1835],   4, 807 },
  { &yyActionTable[1839],   2, 807 },
  { &yyActionTable[1841],   0, 561 },
  { &yyActionTable[1841],   4, 807 },
  { &yyActionTable[1845],   1, 807 },
  { &yyActionTable[1846],   0, 562 },
  { &yyActionTable[1846],   0, 565 },
  { &yyActionTable[1846],   1, 807 },
  { &yyActionTable[1847],   0, 566 },
  { &yyActionTable[1847],   1, 807 },
  { &yyActionTable[1848],   0, 567 },
  { &yyActionTable[1848],   0, 564 },
  { &yyActionTable[1848],   0, 563 },
  { &yyActionTable[1848],   0, 552 },
  { &yyActionTable[1848],   8, 807 },
  { &yyActionTable[1856],   6, 807 },
  { &yyActionTable[1862],   0, 606 },
  { &yyActionTable[1862],   4, 807 },
  { &yyActionTable[1866],   0, 609 },
  { &yyActionTable[1866],   1, 807 },
  { &yyActionTable[1867],   1, 807 },
  { &yyActionTable[1868],   6, 807 },
  { &yyActionTable[1874],   2, 807 },
  { &yyActionTable[1876],   2, 616 },
  { &yyActionTable[1878],   0, 610 },
  { &yyActionTable[1878],   1, 807 },
  { &yyActionTable[1879],   6, 807 },
  { &yyActionTable[1885],   2, 807 },
  { &yyActionTable[1887],   2, 616 },
  { &yyActionTable[1889],   0, 611 },
  { &yyActionTable[1889],  15, 807 },
  { &yyActionTable[1904],  29, 616 },
  { &yyActionTable[1933],   0, 612 },
  { &yyActionTable[1933],   1, 807 },
  { &yyActionTable[1934],   1, 807 },
  { &yyActionTable[1935],   6, 807 },
  { &yyActionTable[1941],   2, 807 },
  { &yyActionTable[1943],   1, 807 },
  { &yyActionTable[1944],   4, 807 },
  { &yyActionTable[1948],   2, 759 },
  { &yyActionTable[1950],   1, 589 },
  { &yyActionTable[1951],   7, 614 },
  { &yyActionTable[1958],   1, 807 },
  { &yyActionTable[1959],   0, 613 },
  { &yyActionTable[1959],   0, 615 },
  { &yyActionTable[1959],   0, 607 },
  { &yyActionTable[1959],   0, 608 },
  { &yyActionTable[1959],   0, 550 },
  { &yyActionTable[1959],   3, 807 },
  { &yyActionTable[1962],   5, 807 },
  { &yyActionTable[1967],   6, 546 },
  { &yyActionTable[1973],   2, 807 },
  { &yyActionTable[1975],   4, 807 },
  { &yyActionTable[1979],   0, 544 },
  { &yyActionTable[1979],   4, 807 },
  { &yyActionTable[1983],   1, 807 },
  { &yyActionTable[1984],   3, 807 },
  { &yyActionTable[1987],   5, 807 },
  { &yyActionTable[1992],   0, 545 },
  { &yyActionTable[1992],   1, 807 },
  { &yyActionTable[1993],   4, 807 },
  { &yyActionTable[1997],   1, 807 },
  { &yyActionTable[1998],   4, 807 },
  { &yyActionTable[2002],   1, 807 },
  { &yyActionTable[2003],   6, 807 },
  { &yyActionTable[2009],   2, 807 },
  { &yyActionTable[2011],   3, 807 },
  { &yyActionTable[2014],   1, 807 },
  { &yyActionTable[2015],   1, 807 },
  { &yyActionTable[2016],   4, 807 },
  { &yyActionTable[2020],   4, 785 },
  { &yyActionTable[2024],   4, 807 },
  { &yyActionTable[2028],   1, 807 },
  { &yyActionTable[2029],   4, 807 },
  { &yyActionTable[2033],   2, 790 },
  { &yyActionTable[2035],   3, 807 },
  { &yyActionTable[2038],   1, 807 },
  { &yyActionTable[2039],   9, 807 },
  { &yyActionTable[2048],   5, 807 },
  { &yyActionTable[2053],   1, 807 },
  { &yyActionTable[2054],   1, 807 },
  { &yyActionTable[2055],   1, 807 },
  { &yyActionTable[2056],   9, 807 },
  { &yyActionTable[2065],   1, 807 },
  { &yyActionTable[2066],   2, 618 },
  { &yyActionTable[2068],   6, 807 },
  { &yyActionTable[2074],   0, 619 },
  { &yyActionTable[2074],   4, 807 },
  { &yyActionTable[2078],   1, 807 },
  { &yyActionTable[2079],   5, 807 },
  { &yyActionTable[2084],   4, 807 },
  { &yyActionTable[2088],   4, 807 },
  { &yyActionTable[2092],   1, 807 },
  { &yyActionTable[2093],  15, 807 },
  { &yyActionTable[2108],  27, 685 },
  { &yyActionTable[2135],   1, 807 },
  { &yyActionTable[2136],   1, 807 },
  { &yyActionTable[2137],  15, 807 },
  { &yyActionTable[2152],  27, 686 },
  { &yyActionTable[2179],   3, 807 },
  { &yyActionTable[2182],   1, 807 },
  { &yyActionTable[2183],   4, 807 },
  { &yyActionTable[2187],   2, 693 },
  { &yyActionTable[2189],   5, 807 },
  { &yyActionTable[2194],   2, 807 },
  { &yyActionTable[2196],   0, 694 },
  { &yyActionTable[2196],   4, 807 },
  { &yyActionTable[2200],   0, 695 },
  { &yyActionTable[2200],   0, 696 },
  { &yyActionTable[2200],   4, 807 },
  { &yyActionTable[2204],   5, 807 },
  { &yyActionTable[2209],   1, 807 },
  { &yyActionTable[2210],  16, 807 },
  { &yyActionTable[2226],   2, 807 },
  { &yyActionTable[2228],  15, 807 },
  { &yyActionTable[2243],  27, 691 },
  { &yyActionTable[2270],   1, 807 },
  { &yyActionTable[2271],  27, 692 },
  { &yyActionTable[2298],   1, 807 },
  { &yyActionTable[2299],   4, 807 },
  { &yyActionTable[2303],   3, 807 },
  { &yyActionTable[2306],   1, 807 },
  { &yyActionTable[2307],  15, 807 },
  { &yyActionTable[2322],  28, 807 },
  { &yyActionTable[2350],   1, 807 },
  { &yyActionTable[2351],   2, 807 },
  { &yyActionTable[2353],   0, 791 },
  { &yyActionTable[2353],   0, 792 },
  { &yyActionTable[2353],   1, 807 },
  { &yyActionTable[2354],   1, 807 },
  { &yyActionTable[2355],   2, 807 },
  { &yyActionTable[2357],   5, 807 },
  { &yyActionTable[2362],   2, 807 },
  { &yyActionTable[2364],   0, 782 },
  { &yyActionTable[2364],   0, 783 },
  { &yyActionTable[2364],   1, 807 },
  { &yyActionTable[2365],   0, 784 },
  { &yyActionTable[2365],   4, 807 },
  { &yyActionTable[2369],   4, 807 },
  { &yyActionTable[2373],   1, 807 },
  { &yyActionTable[2374],   4, 807 },
  { &yyActionTable[2378],   1, 807 },
  { &yyActionTable[2379],   4, 807 },
  { &yyActionTable[2383],   1, 807 },
  { &yyActionTable[2384],   4, 807 },
  { &yyActionTable[2388],   1, 807 },
  { &yyActionTable[2389],   5, 807 },
  { &yyActionTable[2394],   1, 807 },
  { &yyActionTable[2395],   4, 807 },
  { &yyActionTable[2399],   3, 807 },
  { &yyActionTable[2402],   1, 807 },
  { &yyActionTable[2403],   2, 618 },
  { &yyActionTable[2405],   4, 807 },
  { &yyActionTable[2409],   1, 807 },
  { &yyActionTable[2410],   5, 807 },
  { &yyActionTable[2415],   4, 807 },
  { &yyActionTable[2419],   1, 807 },
  { &yyActionTable[2420],   1, 807 },
  { &yyActionTable[2421],   4, 807 },
  { &yyActionTable[2425],   2, 693 },
  { &yyActionTable[2427],   4, 807 },
  { &yyActionTable[2431],   5, 807 },
  { &yyActionTable[2436],   1, 807 },
  { &yyActionTable[2437],  16, 807 },
  { &yyActionTable[2453],   2, 807 },
  { &yyActionTable[2455],   1, 807 },
  { &yyActionTable[2456],   3, 807 },
  { &yyActionTable[2459],   1, 807 },
  { &yyActionTable[2460],   1, 807 },
  { &yyActionTable[2461],   2, 618 },
  { &yyActionTable[2463],   4, 807 },
  { &yyActionTable[2467],   1, 807 },
  { &yyActionTable[2468],   4, 807 },
  { &yyActionTable[2472],   2, 807 },
  { &yyActionTable[2474],   1, 807 },
  { &yyActionTable[2475],   1, 807 },
  { &yyActionTable[2476],   1, 807 },
  { &yyActionTable[2477],   5, 807 },
  { &yyActionTable[2482],   1, 807 },
  { &yyActionTable[2483],   3, 807 },
  { &yyActionTable[2486],   3, 807 },
  { &yyActionTable[2489],  10, 780 },
  { &yyActionTable[2499],   1, 807 },
  { &yyActionTable[2500],   1, 807 },
  { &yyActionTable[2501],   1, 807 },
  { &yyActionTable[2502],   1, 807 },
  { &yyActionTable[2503],   3, 807 },
  { &yyActionTable[2506],   1, 807 },
  { &yyActionTable[2507],   1, 807 },
  { &yyActionTable[2508],   1, 807 },
  { &yyActionTable[2509],   3, 807 },
  { &yyActionTable[2512],   1, 807 },
  { &yyActionTable[2513],   0, 779 },
  { &yyActionTable[2513],   4, 807 },
  { &yyActionTable[2517],   1, 807 },
  { &yyActionTable[2518],   1, 807 },
  { &yyActionTable[2519],   0, 533 },
  { &yyActionTable[2519],   0, 534 },
  { &yyActionTable[2519],   0, 530 },
};

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammer, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
    0,  /*          $ => nothing */
   56,  /*      ABORT => ID */
   56,  /*      AFTER => ID */
    0,  /* AGG_FUNCTION => nothing */
    0,  /*        ALL => nothing */
    0,  /*        AND => nothing */
    0,  /*         AS => nothing */
   56,  /*        ASC => ID */
   56,  /*     BEFORE => ID */
   56,  /*      BEGIN => ID */
    0,  /*    BETWEEN => nothing */
    0,  /*     BITAND => nothing */
    0,  /*     BITNOT => nothing */
    0,  /*      BITOR => nothing */
    0,  /*         BY => nothing */
   56,  /*    CASCADE => ID */
    0,  /*       CASE => nothing */
    0,  /*      CHECK => nothing */
   56,  /*    CLUSTER => ID */
    0,  /*    COLLATE => nothing */
    0,  /*     COLUMN => nothing */
    0,  /*      COMMA => nothing */
    0,  /*    COMMENT => nothing */
    0,  /*     COMMIT => nothing */
    0,  /*     CONCAT => nothing */
   56,  /*   CONFLICT => ID */
    0,  /* CONSTRAINT => nothing */
   56,  /*       COPY => ID */
    0,  /*     CREATE => nothing */
    0,  /*    DEFAULT => nothing */
    0,  /* DEFERRABLE => nothing */
   56,  /*   DEFERRED => ID */
    0,  /*     DELETE => nothing */
   56,  /* DELIMITERS => ID */
   56,  /*       DESC => ID */
    0,  /*   DISTINCT => nothing */
    0,  /*        DOT => nothing */
    0,  /*       DROP => nothing */
   56,  /*       EACH => ID */
    0,  /*       ELSE => nothing */
   56,  /*        END => ID */
    0,  /* END_OF_FILE => nothing */
    0,  /*         EQ => nothing */
    0,  /*     EXCEPT => nothing */
   56,  /*    EXPLAIN => ID */
   56,  /*       FAIL => ID */
    0,  /*      FLOAT => nothing */
   56,  /*        FOR => ID */
    0,  /*    FOREIGN => nothing */
    0,  /*       FROM => nothing */
    0,  /*   FUNCTION => nothing */
    0,  /*         GE => nothing */
    0,  /*       GLOB => nothing */
    0,  /*      GROUP => nothing */
    0,  /*         GT => nothing */
    0,  /*     HAVING => nothing */
    0,  /*         ID => nothing */
   56,  /*     IGNORE => ID */
    0,  /*    ILLEGAL => nothing */
   56,  /*  IMMEDIATE => ID */
    0,  /*         IN => nothing */
    0,  /*      INDEX => nothing */
   56,  /*  INITIALLY => ID */
    0,  /*     INSERT => nothing */
   56,  /*    INSTEAD => ID */
    0,  /*    INTEGER => nothing */
    0,  /*  INTERSECT => nothing */
    0,  /*       INTO => nothing */
    0,  /*         IS => nothing */
    0,  /*     ISNULL => nothing */
    0,  /*       JOIN => nothing */
    0,  /*    JOIN_KW => nothing */
   56,  /*        KEY => ID */
    0,  /*         LE => nothing */
    0,  /*       LIKE => nothing */
    0,  /*      LIMIT => nothing */
    0,  /*         LP => nothing */
    0,  /*     LSHIFT => nothing */
    0,  /*         LT => nothing */
   56,  /*      MATCH => ID */
    0,  /*      MINUS => nothing */
    0,  /*         NE => nothing */
    0,  /*        NOT => nothing */
    0,  /*    NOTNULL => nothing */
    0,  /*       NULL => nothing */
   56,  /*         OF => ID */
   56,  /*     OFFSET => ID */
    0,  /*         ON => nothing */
    0,  /*         OR => nothing */
    0,  /*      ORDER => nothing */
    0,  /*       PLUS => nothing */
   56,  /*     PRAGMA => ID */
    0,  /*    PRIMARY => nothing */
   56,  /*      RAISE => ID */
    0,  /* REFERENCES => nothing */
    0,  /*        REM => nothing */
   56,  /*    REPLACE => ID */
   56,  /*   RESTRICT => ID */
    0,  /*   ROLLBACK => nothing */
   56,  /*        ROW => ID */
    0,  /*         RP => nothing */
    0,  /*     RSHIFT => nothing */
    0,  /*     SELECT => nothing */
    0,  /*       SEMI => nothing */
    0,  /*        SET => nothing */
    0,  /*      SLASH => nothing */
    0,  /*      SPACE => nothing */
    0,  /*       STAR => nothing */
   56,  /*  STATEMENT => ID */
    0,  /*     STRING => nothing */
    0,  /*      TABLE => nothing */
   56,  /*       TEMP => ID */
    0,  /*       THEN => nothing */
    0,  /* TRANSACTION => nothing */
   56,  /*    TRIGGER => ID */
    0,  /*     UMINUS => nothing */
    0,  /* UNCLOSED_STRING => nothing */
    0,  /*      UNION => nothing */
    0,  /*     UNIQUE => nothing */
    0,  /*     UPDATE => nothing */
    0,  /*      UPLUS => nothing */
    0,  /*      USING => nothing */
   56,  /*     VACUUM => ID */
    0,  /*     VALUES => nothing */
   56,  /*       VIEW => ID */
    0,  /*       WHEN => nothing */
    0,  /*      WHERE => nothing */
};
#endif /* YYFALLBACK */

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
#endif /* NDEBUG */

#ifndef NDEBUG
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
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *yyTokenName[] = { 
  "$",             "ABORT",         "AFTER",         "AGG_FUNCTION",
  "ALL",           "AND",           "AS",            "ASC",         
  "BEFORE",        "BEGIN",         "BETWEEN",       "BITAND",      
  "BITNOT",        "BITOR",         "BY",            "CASCADE",     
  "CASE",          "CHECK",         "CLUSTER",       "COLLATE",     
  "COLUMN",        "COMMA",         "COMMENT",       "COMMIT",      
  "CONCAT",        "CONFLICT",      "CONSTRAINT",    "COPY",        
  "CREATE",        "DEFAULT",       "DEFERRABLE",    "DEFERRED",    
  "DELETE",        "DELIMITERS",    "DESC",          "DISTINCT",    
  "DOT",           "DROP",          "EACH",          "ELSE",        
  "END",           "END_OF_FILE",   "EQ",            "EXCEPT",      
  "EXPLAIN",       "FAIL",          "FLOAT",         "FOR",         
  "FOREIGN",       "FROM",          "FUNCTION",      "GE",          
  "GLOB",          "GROUP",         "GT",            "HAVING",      
  "ID",            "IGNORE",        "ILLEGAL",       "IMMEDIATE",   
  "IN",            "INDEX",         "INITIALLY",     "INSERT",      
  "INSTEAD",       "INTEGER",       "INTERSECT",     "INTO",        
  "IS",            "ISNULL",        "JOIN",          "JOIN_KW",     
  "KEY",           "LE",            "LIKE",          "LIMIT",       
  "LP",            "LSHIFT",        "LT",            "MATCH",       
  "MINUS",         "NE",            "NOT",           "NOTNULL",     
  "NULL",          "OF",            "OFFSET",        "ON",          
  "OR",            "ORDER",         "PLUS",          "PRAGMA",      
  "PRIMARY",       "RAISE",         "REFERENCES",    "REM",         
  "REPLACE",       "RESTRICT",      "ROLLBACK",      "ROW",         
  "RP",            "RSHIFT",        "SELECT",        "SEMI",        
  "SET",           "SLASH",         "SPACE",         "STAR",        
  "STATEMENT",     "STRING",        "TABLE",         "TEMP",        
  "THEN",          "TRANSACTION",   "TRIGGER",       "UMINUS",      
  "UNCLOSED_STRING",  "UNION",         "UNIQUE",        "UPDATE",      
  "UPLUS",         "USING",         "VACUUM",        "VALUES",      
  "VIEW",          "WHEN",          "WHERE",         "as",          
  "carg",          "carglist",      "case_else",     "case_exprlist",
  "case_operand",  "ccons",         "cmd",           "cmdlist",     
  "collate",       "column",        "columnid",      "columnlist",  
  "conslist",      "conslist_opt",  "create_table",  "create_table_args",
  "defer_subclause",  "defer_subclause_opt",  "distinct",      "ecmd",        
  "error",         "explain",       "expr",          "expritem",    
  "exprlist",      "foreach_clause",  "from",          "groupby_opt", 
  "having_opt",    "id",            "ids",           "idxitem",     
  "idxlist",       "idxlist_opt",   "init_deferred_pred_opt",  "input",       
  "inscollist",    "inscollist_opt",  "insert_cmd",    "itemlist",    
  "joinop",        "joinop2",       "likeop",        "limit_opt",   
  "limit_sep",     "minus_num",     "multiselect_op",  "nm",          
  "number",        "on_opt",        "onconf",        "oneselect",   
  "orconf",        "orderby_opt",   "plus_num",      "plus_opt",    
  "refact",        "refarg",        "refargs",       "resolvetype", 
  "sclp",          "selcollist",    "select",        "seltablist",  
  "setlist",       "signed",        "sortitem",      "sortlist",    
  "sortorder",     "stl_prefix",    "tcons",         "temp",        
  "trans_opt",     "trigger_cmd",   "trigger_cmd_list",  "trigger_event",
  "trigger_time",  "type",          "typename",      "uniqueflag",  
  "using_opt",     "when_clause",   "where_opt",   
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *yyRuleName[] = {
 /*   0 */ "input ::= cmdlist",
 /*   1 */ "cmdlist ::= ecmd",
 /*   2 */ "cmdlist ::= cmdlist ecmd",
 /*   3 */ "ecmd ::= explain cmd SEMI",
 /*   4 */ "ecmd ::= SEMI",
 /*   5 */ "explain ::= EXPLAIN",
 /*   6 */ "explain ::=",
 /*   7 */ "cmd ::= BEGIN trans_opt onconf",
 /*   8 */ "trans_opt ::=",
 /*   9 */ "trans_opt ::= TRANSACTION",
 /*  10 */ "trans_opt ::= TRANSACTION nm",
 /*  11 */ "cmd ::= COMMIT trans_opt",
 /*  12 */ "cmd ::= END trans_opt",
 /*  13 */ "cmd ::= ROLLBACK trans_opt",
 /*  14 */ "cmd ::= create_table create_table_args",
 /*  15 */ "create_table ::= CREATE temp TABLE nm",
 /*  16 */ "temp ::= TEMP",
 /*  17 */ "temp ::=",
 /*  18 */ "create_table_args ::= LP columnlist conslist_opt RP",
 /*  19 */ "create_table_args ::= AS select",
 /*  20 */ "columnlist ::= columnlist COMMA column",
 /*  21 */ "columnlist ::= column",
 /*  22 */ "column ::= columnid type carglist",
 /*  23 */ "columnid ::= nm",
 /*  24 */ "id ::= ID",
 /*  25 */ "ids ::= ID",
 /*  26 */ "ids ::= STRING",
 /*  27 */ "nm ::= ID",
 /*  28 */ "nm ::= STRING",
 /*  29 */ "nm ::= JOIN_KW",
 /*  30 */ "type ::=",
 /*  31 */ "type ::= typename",
 /*  32 */ "type ::= typename LP signed RP",
 /*  33 */ "type ::= typename LP signed COMMA signed RP",
 /*  34 */ "typename ::= ids",
 /*  35 */ "typename ::= typename ids",
 /*  36 */ "signed ::= INTEGER",
 /*  37 */ "signed ::= PLUS INTEGER",
 /*  38 */ "signed ::= MINUS INTEGER",
 /*  39 */ "carglist ::= carglist carg",
 /*  40 */ "carglist ::=",
 /*  41 */ "carg ::= CONSTRAINT nm ccons",
 /*  42 */ "carg ::= ccons",
 /*  43 */ "carg ::= DEFAULT STRING",
 /*  44 */ "carg ::= DEFAULT ID",
 /*  45 */ "carg ::= DEFAULT INTEGER",
 /*  46 */ "carg ::= DEFAULT PLUS INTEGER",
 /*  47 */ "carg ::= DEFAULT MINUS INTEGER",
 /*  48 */ "carg ::= DEFAULT FLOAT",
 /*  49 */ "carg ::= DEFAULT PLUS FLOAT",
 /*  50 */ "carg ::= DEFAULT MINUS FLOAT",
 /*  51 */ "carg ::= DEFAULT NULL",
 /*  52 */ "ccons ::= NULL onconf",
 /*  53 */ "ccons ::= NOT NULL onconf",
 /*  54 */ "ccons ::= PRIMARY KEY sortorder onconf",
 /*  55 */ "ccons ::= UNIQUE onconf",
 /*  56 */ "ccons ::= CHECK LP expr RP onconf",
 /*  57 */ "ccons ::= REFERENCES nm idxlist_opt refargs",
 /*  58 */ "ccons ::= defer_subclause",
 /*  59 */ "ccons ::= COLLATE id",
 /*  60 */ "refargs ::=",
 /*  61 */ "refargs ::= refargs refarg",
 /*  62 */ "refarg ::= MATCH nm",
 /*  63 */ "refarg ::= ON DELETE refact",
 /*  64 */ "refarg ::= ON UPDATE refact",
 /*  65 */ "refarg ::= ON INSERT refact",
 /*  66 */ "refact ::= SET NULL",
 /*  67 */ "refact ::= SET DEFAULT",
 /*  68 */ "refact ::= CASCADE",
 /*  69 */ "refact ::= RESTRICT",
 /*  70 */ "defer_subclause ::= NOT DEFERRABLE init_deferred_pred_opt",
 /*  71 */ "defer_subclause ::= DEFERRABLE init_deferred_pred_opt",
 /*  72 */ "init_deferred_pred_opt ::=",
 /*  73 */ "init_deferred_pred_opt ::= INITIALLY DEFERRED",
 /*  74 */ "init_deferred_pred_opt ::= INITIALLY IMMEDIATE",
 /*  75 */ "conslist_opt ::=",
 /*  76 */ "conslist_opt ::= COMMA conslist",
 /*  77 */ "conslist ::= conslist COMMA tcons",
 /*  78 */ "conslist ::= conslist tcons",
 /*  79 */ "conslist ::= tcons",
 /*  80 */ "tcons ::= CONSTRAINT nm",
 /*  81 */ "tcons ::= PRIMARY KEY LP idxlist RP onconf",
 /*  82 */ "tcons ::= UNIQUE LP idxlist RP onconf",
 /*  83 */ "tcons ::= CHECK expr onconf",
 /*  84 */ "tcons ::= FOREIGN KEY LP idxlist RP REFERENCES nm idxlist_opt refargs defer_subclause_opt",
 /*  85 */ "defer_subclause_opt ::=",
 /*  86 */ "defer_subclause_opt ::= defer_subclause",
 /*  87 */ "onconf ::=",
 /*  88 */ "onconf ::= ON CONFLICT resolvetype",
 /*  89 */ "orconf ::=",
 /*  90 */ "orconf ::= OR resolvetype",
 /*  91 */ "resolvetype ::= ROLLBACK",
 /*  92 */ "resolvetype ::= ABORT",
 /*  93 */ "resolvetype ::= FAIL",
 /*  94 */ "resolvetype ::= IGNORE",
 /*  95 */ "resolvetype ::= REPLACE",
 /*  96 */ "cmd ::= DROP TABLE nm",
 /*  97 */ "cmd ::= CREATE temp VIEW nm AS select",
 /*  98 */ "cmd ::= DROP VIEW nm",
 /*  99 */ "cmd ::= select",
 /* 100 */ "select ::= oneselect",
 /* 101 */ "select ::= select multiselect_op oneselect",
 /* 102 */ "multiselect_op ::= UNION",
 /* 103 */ "multiselect_op ::= UNION ALL",
 /* 104 */ "multiselect_op ::= INTERSECT",
 /* 105 */ "multiselect_op ::= EXCEPT",
 /* 106 */ "oneselect ::= SELECT distinct selcollist from where_opt groupby_opt having_opt orderby_opt limit_opt",
 /* 107 */ "distinct ::= DISTINCT",
 /* 108 */ "distinct ::= ALL",
 /* 109 */ "distinct ::=",
 /* 110 */ "sclp ::= selcollist COMMA",
 /* 111 */ "sclp ::=",
 /* 112 */ "selcollist ::= sclp expr as",
 /* 113 */ "selcollist ::= sclp STAR",
 /* 114 */ "selcollist ::= sclp nm DOT STAR",
 /* 115 */ "as ::= AS nm",
 /* 116 */ "as ::= ids",
 /* 117 */ "as ::=",
 /* 118 */ "from ::=",
 /* 119 */ "from ::= FROM seltablist",
 /* 120 */ "stl_prefix ::= seltablist joinop",
 /* 121 */ "stl_prefix ::=",
 /* 122 */ "seltablist ::= stl_prefix nm as on_opt using_opt",
 /* 123 */ "seltablist ::= stl_prefix LP select RP as on_opt using_opt",
 /* 124 */ "joinop ::= COMMA",
 /* 125 */ "joinop ::= JOIN",
 /* 126 */ "joinop ::= JOIN_KW JOIN",
 /* 127 */ "joinop ::= JOIN_KW nm JOIN",
 /* 128 */ "joinop ::= JOIN_KW nm nm JOIN",
 /* 129 */ "on_opt ::= ON expr",
 /* 130 */ "on_opt ::=",
 /* 131 */ "using_opt ::= USING LP idxlist RP",
 /* 132 */ "using_opt ::=",
 /* 133 */ "orderby_opt ::=",
 /* 134 */ "orderby_opt ::= ORDER BY sortlist",
 /* 135 */ "sortlist ::= sortlist COMMA sortitem collate sortorder",
 /* 136 */ "sortlist ::= sortitem collate sortorder",
 /* 137 */ "sortitem ::= expr",
 /* 138 */ "sortorder ::= ASC",
 /* 139 */ "sortorder ::= DESC",
 /* 140 */ "sortorder ::=",
 /* 141 */ "collate ::=",
 /* 142 */ "collate ::= COLLATE id",
 /* 143 */ "groupby_opt ::=",
 /* 144 */ "groupby_opt ::= GROUP BY exprlist",
 /* 145 */ "having_opt ::=",
 /* 146 */ "having_opt ::= HAVING expr",
 /* 147 */ "limit_opt ::=",
 /* 148 */ "limit_opt ::= LIMIT INTEGER",
 /* 149 */ "limit_opt ::= LIMIT INTEGER limit_sep INTEGER",
 /* 150 */ "limit_sep ::= OFFSET",
 /* 151 */ "limit_sep ::= COMMA",
 /* 152 */ "cmd ::= DELETE FROM nm where_opt",
 /* 153 */ "where_opt ::=",
 /* 154 */ "where_opt ::= WHERE expr",
 /* 155 */ "cmd ::= UPDATE orconf nm SET setlist where_opt",
 /* 156 */ "setlist ::= setlist COMMA nm EQ expr",
 /* 157 */ "setlist ::= nm EQ expr",
 /* 158 */ "cmd ::= insert_cmd INTO nm inscollist_opt VALUES LP itemlist RP",
 /* 159 */ "cmd ::= insert_cmd INTO nm inscollist_opt select",
 /* 160 */ "insert_cmd ::= INSERT orconf",
 /* 161 */ "insert_cmd ::= REPLACE",
 /* 162 */ "itemlist ::= itemlist COMMA expr",
 /* 163 */ "itemlist ::= expr",
 /* 164 */ "inscollist_opt ::=",
 /* 165 */ "inscollist_opt ::= LP inscollist RP",
 /* 166 */ "inscollist ::= inscollist COMMA nm",
 /* 167 */ "inscollist ::= nm",
 /* 168 */ "expr ::= LP expr RP",
 /* 169 */ "expr ::= NULL",
 /* 170 */ "expr ::= ID",
 /* 171 */ "expr ::= JOIN_KW",
 /* 172 */ "expr ::= nm DOT nm",
 /* 173 */ "expr ::= INTEGER",
 /* 174 */ "expr ::= FLOAT",
 /* 175 */ "expr ::= STRING",
 /* 176 */ "expr ::= ID LP exprlist RP",
 /* 177 */ "expr ::= ID LP STAR RP",
 /* 178 */ "expr ::= expr AND expr",
 /* 179 */ "expr ::= expr OR expr",
 /* 180 */ "expr ::= expr LT expr",
 /* 181 */ "expr ::= expr GT expr",
 /* 182 */ "expr ::= expr LE expr",
 /* 183 */ "expr ::= expr GE expr",
 /* 184 */ "expr ::= expr NE expr",
 /* 185 */ "expr ::= expr EQ expr",
 /* 186 */ "expr ::= expr BITAND expr",
 /* 187 */ "expr ::= expr BITOR expr",
 /* 188 */ "expr ::= expr LSHIFT expr",
 /* 189 */ "expr ::= expr RSHIFT expr",
 /* 190 */ "expr ::= expr likeop expr",
 /* 191 */ "expr ::= expr NOT likeop expr",
 /* 192 */ "likeop ::= LIKE",
 /* 193 */ "likeop ::= GLOB",
 /* 194 */ "expr ::= expr PLUS expr",
 /* 195 */ "expr ::= expr MINUS expr",
 /* 196 */ "expr ::= expr STAR expr",
 /* 197 */ "expr ::= expr SLASH expr",
 /* 198 */ "expr ::= expr REM expr",
 /* 199 */ "expr ::= expr CONCAT expr",
 /* 200 */ "expr ::= expr ISNULL",
 /* 201 */ "expr ::= expr IS NULL",
 /* 202 */ "expr ::= expr NOTNULL",
 /* 203 */ "expr ::= expr NOT NULL",
 /* 204 */ "expr ::= expr IS NOT NULL",
 /* 205 */ "expr ::= NOT expr",
 /* 206 */ "expr ::= BITNOT expr",
 /* 207 */ "expr ::= MINUS expr",
 /* 208 */ "expr ::= PLUS expr",
 /* 209 */ "expr ::= LP select RP",
 /* 210 */ "expr ::= expr BETWEEN expr AND expr",
 /* 211 */ "expr ::= expr NOT BETWEEN expr AND expr",
 /* 212 */ "expr ::= expr IN LP exprlist RP",
 /* 213 */ "expr ::= expr IN LP select RP",
 /* 214 */ "expr ::= expr NOT IN LP exprlist RP",
 /* 215 */ "expr ::= expr NOT IN LP select RP",
 /* 216 */ "expr ::= CASE case_operand case_exprlist case_else END",
 /* 217 */ "case_exprlist ::= case_exprlist WHEN expr THEN expr",
 /* 218 */ "case_exprlist ::= WHEN expr THEN expr",
 /* 219 */ "case_else ::= ELSE expr",
 /* 220 */ "case_else ::=",
 /* 221 */ "case_operand ::= expr",
 /* 222 */ "case_operand ::=",
 /* 223 */ "exprlist ::= exprlist COMMA expritem",
 /* 224 */ "exprlist ::= expritem",
 /* 225 */ "expritem ::= expr",
 /* 226 */ "expritem ::=",
 /* 227 */ "cmd ::= CREATE uniqueflag INDEX nm ON nm LP idxlist RP onconf",
 /* 228 */ "uniqueflag ::= UNIQUE",
 /* 229 */ "uniqueflag ::=",
 /* 230 */ "idxlist_opt ::=",
 /* 231 */ "idxlist_opt ::= LP idxlist RP",
 /* 232 */ "idxlist ::= idxlist COMMA idxitem",
 /* 233 */ "idxlist ::= idxitem",
 /* 234 */ "idxitem ::= nm",
 /* 235 */ "cmd ::= DROP INDEX nm",
 /* 236 */ "cmd ::= COPY orconf nm FROM nm USING DELIMITERS STRING",
 /* 237 */ "cmd ::= COPY orconf nm FROM nm",
 /* 238 */ "cmd ::= VACUUM",
 /* 239 */ "cmd ::= VACUUM nm",
 /* 240 */ "cmd ::= PRAGMA ids EQ nm",
 /* 241 */ "cmd ::= PRAGMA ids EQ ON",
 /* 242 */ "cmd ::= PRAGMA ids EQ plus_num",
 /* 243 */ "cmd ::= PRAGMA ids EQ minus_num",
 /* 244 */ "cmd ::= PRAGMA ids LP nm RP",
 /* 245 */ "cmd ::= PRAGMA ids",
 /* 246 */ "plus_num ::= plus_opt number",
 /* 247 */ "minus_num ::= MINUS number",
 /* 248 */ "number ::= INTEGER",
 /* 249 */ "number ::= FLOAT",
 /* 250 */ "plus_opt ::= PLUS",
 /* 251 */ "plus_opt ::=",
 /* 252 */ "cmd ::= CREATE TRIGGER nm trigger_time trigger_event ON nm foreach_clause when_clause BEGIN trigger_cmd_list END",
 /* 253 */ "trigger_time ::= BEFORE",
 /* 254 */ "trigger_time ::= AFTER",
 /* 255 */ "trigger_time ::= INSTEAD OF",
 /* 256 */ "trigger_time ::=",
 /* 257 */ "trigger_event ::= DELETE",
 /* 258 */ "trigger_event ::= INSERT",
 /* 259 */ "trigger_event ::= UPDATE",
 /* 260 */ "trigger_event ::= UPDATE OF inscollist",
 /* 261 */ "foreach_clause ::=",
 /* 262 */ "foreach_clause ::= FOR EACH ROW",
 /* 263 */ "foreach_clause ::= FOR EACH STATEMENT",
 /* 264 */ "when_clause ::=",
 /* 265 */ "when_clause ::= WHEN expr",
 /* 266 */ "trigger_cmd_list ::= trigger_cmd SEMI trigger_cmd_list",
 /* 267 */ "trigger_cmd_list ::=",
 /* 268 */ "trigger_cmd ::= UPDATE orconf nm SET setlist where_opt",
 /* 269 */ "trigger_cmd ::= INSERT orconf INTO nm inscollist_opt VALUES LP itemlist RP",
 /* 270 */ "trigger_cmd ::= INSERT orconf INTO nm inscollist_opt select",
 /* 271 */ "trigger_cmd ::= DELETE FROM nm where_opt",
 /* 272 */ "trigger_cmd ::= select",
 /* 273 */ "expr ::= RAISE LP IGNORE RP",
 /* 274 */ "expr ::= RAISE LP ROLLBACK COMMA nm RP",
 /* 275 */ "expr ::= RAISE LP ABORT COMMA nm RP",
 /* 276 */ "expr ::= RAISE LP FAIL COMMA nm RP",
 /* 277 */ "cmd ::= DROP TRIGGER nm",
};
#endif /* NDEBUG */

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
    case 131:
#line 650 "parse.y"
{sqliteExprListDelete((yypminor->yy354));}
#line 4211 "parse.c"
      break;
    case 150:
#line 504 "parse.y"
{sqliteExprDelete((yypminor->yy154));}
#line 4216 "parse.c"
      break;
    case 151:
#line 669 "parse.y"
{sqliteExprDelete((yypminor->yy154));}
#line 4221 "parse.c"
      break;
    case 152:
#line 667 "parse.y"
{sqliteExprListDelete((yypminor->yy354));}
#line 4226 "parse.c"
      break;
    case 154:
#line 332 "parse.y"
{sqliteSrcListDelete((yypminor->yy159));}
#line 4231 "parse.c"
      break;
    case 155:
#line 422 "parse.y"
{sqliteExprListDelete((yypminor->yy354));}
#line 4236 "parse.c"
      break;
    case 156:
#line 427 "parse.y"
{sqliteExprDelete((yypminor->yy154));}
#line 4241 "parse.c"
      break;
    case 160:
#line 691 "parse.y"
{sqliteIdListDelete((yypminor->yy208));}
#line 4246 "parse.c"
      break;
    case 161:
#line 693 "parse.y"
{sqliteIdListDelete((yypminor->yy208));}
#line 4251 "parse.c"
      break;
    case 164:
#line 483 "parse.y"
{sqliteIdListDelete((yypminor->yy208));}
#line 4256 "parse.c"
      break;
    case 165:
#line 481 "parse.y"
{sqliteIdListDelete((yypminor->yy208));}
#line 4261 "parse.c"
      break;
    case 167:
#line 475 "parse.y"
{sqliteExprListDelete((yypminor->yy354));}
#line 4266 "parse.c"
      break;
    case 177:
#line 383 "parse.y"
{sqliteExprDelete((yypminor->yy154));}
#line 4271 "parse.c"
      break;
    case 179:
#line 267 "parse.y"
{sqliteSelectDelete((yypminor->yy331));}
#line 4276 "parse.c"
      break;
    case 181:
#line 394 "parse.y"
{sqliteExprListDelete((yypminor->yy354));}
#line 4281 "parse.c"
      break;
    case 188:
#line 303 "parse.y"
{sqliteExprListDelete((yypminor->yy354));}
#line 4286 "parse.c"
      break;
    case 189:
#line 301 "parse.y"
{sqliteExprListDelete((yypminor->yy354));}
#line 4291 "parse.c"
      break;
    case 190:
#line 265 "parse.y"
{sqliteSelectDelete((yypminor->yy331));}
#line 4296 "parse.c"
      break;
    case 191:
#line 328 "parse.y"
{sqliteSrcListDelete((yypminor->yy159));}
#line 4301 "parse.c"
      break;
    case 192:
#line 451 "parse.y"
{sqliteExprListDelete((yypminor->yy354));}
#line 4306 "parse.c"
      break;
    case 194:
#line 398 "parse.y"
{sqliteExprDelete((yypminor->yy154));}
#line 4311 "parse.c"
      break;
    case 195:
#line 396 "parse.y"
{sqliteExprListDelete((yypminor->yy354));}
#line 4316 "parse.c"
      break;
    case 197:
#line 330 "parse.y"
{sqliteSrcListDelete((yypminor->yy159));}
#line 4321 "parse.c"
      break;
    case 203:
#line 752 "parse.y"
{sqliteIdListDelete((yypminor->yy398).b);}
#line 4326 "parse.c"
      break;
    case 208:
#line 388 "parse.y"
{sqliteIdListDelete((yypminor->yy208));}
#line 4331 "parse.c"
      break;
    case 210:
#line 445 "parse.y"
{sqliteExprDelete((yypminor->yy154));}
#line 4336 "parse.c"
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
  int iFallback;                /* Fallback token */
 
  /* if( pParser->yyidx<0 ) return YY_NO_ACTION;  */
  pState = &yyStateTable[pParser->yytop->stateno];
  if( pState->nEntry==0 ){
    return pState->actionDefault;
  }else if( iLookAhead!=YYNOCODE ){
    pAction = &pState->hashtbl[iLookAhead % pState->nEntry];
    while( 1 ){
      if( pAction->lookahead==iLookAhead ) return pAction->action;
      if( pAction->next==0 ) break;
      pAction = &pState->hashtbl[pAction->next-1];
    }
#ifdef YYFALLBACK
    if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
           && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
           yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
      }
#endif
      return yy_find_parser_action(pParser, iFallback);
    }
#endif
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
  { 163, 1 },
  { 135, 1 },
  { 135, 2 },
  { 147, 3 },
  { 147, 1 },
  { 149, 1 },
  { 149, 0 },
  { 134, 3 },
  { 200, 0 },
  { 200, 1 },
  { 200, 2 },
  { 134, 2 },
  { 134, 2 },
  { 134, 2 },
  { 134, 2 },
  { 142, 4 },
  { 199, 1 },
  { 199, 0 },
  { 143, 4 },
  { 143, 2 },
  { 139, 3 },
  { 139, 1 },
  { 137, 3 },
  { 138, 1 },
  { 157, 1 },
  { 158, 1 },
  { 158, 1 },
  { 175, 1 },
  { 175, 1 },
  { 175, 1 },
  { 205, 0 },
  { 205, 1 },
  { 205, 4 },
  { 205, 6 },
  { 206, 1 },
  { 206, 2 },
  { 193, 1 },
  { 193, 2 },
  { 193, 2 },
  { 129, 2 },
  { 129, 0 },
  { 128, 3 },
  { 128, 1 },
  { 128, 2 },
  { 128, 2 },
  { 128, 2 },
  { 128, 3 },
  { 128, 3 },
  { 128, 2 },
  { 128, 3 },
  { 128, 3 },
  { 128, 2 },
  { 133, 2 },
  { 133, 3 },
  { 133, 4 },
  { 133, 2 },
  { 133, 5 },
  { 133, 4 },
  { 133, 1 },
  { 133, 2 },
  { 186, 0 },
  { 186, 2 },
  { 185, 2 },
  { 185, 3 },
  { 185, 3 },
  { 185, 3 },
  { 184, 2 },
  { 184, 2 },
  { 184, 1 },
  { 184, 1 },
  { 144, 3 },
  { 144, 2 },
  { 162, 0 },
  { 162, 2 },
  { 162, 2 },
  { 141, 0 },
  { 141, 2 },
  { 140, 3 },
  { 140, 2 },
  { 140, 1 },
  { 198, 2 },
  { 198, 6 },
  { 198, 5 },
  { 198, 3 },
  { 198, 10 },
  { 145, 0 },
  { 145, 1 },
  { 178, 0 },
  { 178, 3 },
  { 180, 0 },
  { 180, 2 },
  { 187, 1 },
  { 187, 1 },
  { 187, 1 },
  { 187, 1 },
  { 187, 1 },
  { 134, 3 },
  { 134, 6 },
  { 134, 3 },
  { 134, 1 },
  { 190, 1 },
  { 190, 3 },
  { 174, 1 },
  { 174, 2 },
  { 174, 1 },
  { 174, 1 },
  { 179, 9 },
  { 146, 1 },
  { 146, 1 },
  { 146, 0 },
  { 188, 2 },
  { 188, 0 },
  { 189, 3 },
  { 189, 2 },
  { 189, 4 },
  { 127, 2 },
  { 127, 1 },
  { 127, 0 },
  { 154, 0 },
  { 154, 2 },
  { 197, 2 },
  { 197, 0 },
  { 191, 5 },
  { 191, 7 },
  { 168, 1 },
  { 168, 1 },
  { 168, 2 },
  { 168, 3 },
  { 168, 4 },
  { 177, 2 },
  { 177, 0 },
  { 208, 4 },
  { 208, 0 },
  { 181, 0 },
  { 181, 3 },
  { 195, 5 },
  { 195, 3 },
  { 194, 1 },
  { 196, 1 },
  { 196, 1 },
  { 196, 0 },
  { 136, 0 },
  { 136, 2 },
  { 155, 0 },
  { 155, 3 },
  { 156, 0 },
  { 156, 2 },
  { 171, 0 },
  { 171, 2 },
  { 171, 4 },
  { 172, 1 },
  { 172, 1 },
  { 134, 4 },
  { 210, 0 },
  { 210, 2 },
  { 134, 6 },
  { 192, 5 },
  { 192, 3 },
  { 134, 8 },
  { 134, 5 },
  { 166, 2 },
  { 166, 1 },
  { 167, 3 },
  { 167, 1 },
  { 165, 0 },
  { 165, 3 },
  { 164, 3 },
  { 164, 1 },
  { 150, 3 },
  { 150, 1 },
  { 150, 1 },
  { 150, 1 },
  { 150, 3 },
  { 150, 1 },
  { 150, 1 },
  { 150, 1 },
  { 150, 4 },
  { 150, 4 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 4 },
  { 170, 1 },
  { 170, 1 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 3 },
  { 150, 2 },
  { 150, 3 },
  { 150, 2 },
  { 150, 3 },
  { 150, 4 },
  { 150, 2 },
  { 150, 2 },
  { 150, 2 },
  { 150, 2 },
  { 150, 3 },
  { 150, 5 },
  { 150, 6 },
  { 150, 5 },
  { 150, 5 },
  { 150, 6 },
  { 150, 6 },
  { 150, 5 },
  { 131, 5 },
  { 131, 4 },
  { 130, 2 },
  { 130, 0 },
  { 132, 1 },
  { 132, 0 },
  { 152, 3 },
  { 152, 1 },
  { 151, 1 },
  { 151, 0 },
  { 134, 10 },
  { 207, 1 },
  { 207, 0 },
  { 161, 0 },
  { 161, 3 },
  { 160, 3 },
  { 160, 1 },
  { 159, 1 },
  { 134, 3 },
  { 134, 8 },
  { 134, 5 },
  { 134, 1 },
  { 134, 2 },
  { 134, 4 },
  { 134, 4 },
  { 134, 4 },
  { 134, 4 },
  { 134, 5 },
  { 134, 2 },
  { 182, 2 },
  { 173, 2 },
  { 176, 1 },
  { 176, 1 },
  { 183, 1 },
  { 183, 0 },
  { 134, 12 },
  { 204, 1 },
  { 204, 1 },
  { 204, 2 },
  { 204, 0 },
  { 203, 1 },
  { 203, 1 },
  { 203, 1 },
  { 203, 3 },
  { 153, 0 },
  { 153, 3 },
  { 153, 3 },
  { 209, 0 },
  { 209, 2 },
  { 202, 3 },
  { 202, 0 },
  { 201, 6 },
  { 201, 9 },
  { 201, 6 },
  { 201, 4 },
  { 201, 1 },
  { 150, 4 },
  { 150, 6 },
  { 150, 6 },
  { 150, 6 },
  { 134, 3 },
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
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<sizeof(yyRuleName)/sizeof(yyRuleName[0]) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0:
        /* No destructor defined for cmdlist */
        break;
      case 1:
        /* No destructor defined for ecmd */
        break;
      case 2:
        /* No destructor defined for cmdlist */
        /* No destructor defined for ecmd */
        break;
      case 3:
#line 67 "parse.y"
{sqliteExec(pParse);}
#line 4809 "parse.c"
        /* No destructor defined for explain */
        /* No destructor defined for cmd */
        /* No destructor defined for SEMI */
        break;
      case 4:
        /* No destructor defined for SEMI */
        break;
      case 5:
#line 69 "parse.y"
{ sqliteBeginParse(pParse, 1); }
#line 4820 "parse.c"
        /* No destructor defined for EXPLAIN */
        break;
      case 6:
#line 70 "parse.y"
{ sqliteBeginParse(pParse, 0); }
#line 4826 "parse.c"
        break;
      case 7:
#line 75 "parse.y"
{sqliteBeginTransaction(pParse,yymsp[0].minor.yy6);}
#line 4831 "parse.c"
        /* No destructor defined for BEGIN */
        /* No destructor defined for trans_opt */
        break;
      case 8:
        break;
      case 9:
        /* No destructor defined for TRANSACTION */
        break;
      case 10:
        /* No destructor defined for TRANSACTION */
        /* No destructor defined for nm */
        break;
      case 11:
#line 79 "parse.y"
{sqliteCommitTransaction(pParse);}
#line 4847 "parse.c"
        /* No destructor defined for COMMIT */
        /* No destructor defined for trans_opt */
        break;
      case 12:
#line 80 "parse.y"
{sqliteCommitTransaction(pParse);}
#line 4854 "parse.c"
        /* No destructor defined for END */
        /* No destructor defined for trans_opt */
        break;
      case 13:
#line 81 "parse.y"
{sqliteRollbackTransaction(pParse);}
#line 4861 "parse.c"
        /* No destructor defined for ROLLBACK */
        /* No destructor defined for trans_opt */
        break;
      case 14:
        /* No destructor defined for create_table */
        /* No destructor defined for create_table_args */
        break;
      case 15:
#line 86 "parse.y"
{
   sqliteStartTable(pParse,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy356,yymsp[-2].minor.yy6);
}
#line 4874 "parse.c"
        /* No destructor defined for TABLE */
        break;
      case 16:
#line 90 "parse.y"
{yygotominor.yy6 = pParse->isTemp || !pParse->initFlag;}
#line 4880 "parse.c"
        /* No destructor defined for TEMP */
        break;
      case 17:
#line 91 "parse.y"
{yygotominor.yy6 = pParse->isTemp;}
#line 4886 "parse.c"
        break;
      case 18:
#line 92 "parse.y"
{
  sqliteEndTable(pParse,&yymsp[0].minor.yy0,0);
}
#line 4893 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for columnlist */
        /* No destructor defined for conslist_opt */
        break;
      case 19:
#line 95 "parse.y"
{
  sqliteEndTable(pParse,0,yymsp[0].minor.yy331);
  sqliteSelectDelete(yymsp[0].minor.yy331);
}
#line 4904 "parse.c"
        /* No destructor defined for AS */
        break;
      case 20:
        /* No destructor defined for columnlist */
        /* No destructor defined for COMMA */
        /* No destructor defined for column */
        break;
      case 21:
        /* No destructor defined for column */
        break;
      case 22:
        /* No destructor defined for columnid */
        /* No destructor defined for type */
        /* No destructor defined for carglist */
        break;
      case 23:
#line 107 "parse.y"
{sqliteAddColumn(pParse,&yymsp[0].minor.yy356);}
#line 4923 "parse.c"
        break;
      case 24:
#line 113 "parse.y"
{yygotominor.yy356 = yymsp[0].minor.yy0;}
#line 4928 "parse.c"
        break;
      case 25:
#line 129 "parse.y"
{yygotominor.yy356 = yymsp[0].minor.yy0;}
#line 4933 "parse.c"
        break;
      case 26:
#line 130 "parse.y"
{yygotominor.yy356 = yymsp[0].minor.yy0;}
#line 4938 "parse.c"
        break;
      case 27:
#line 135 "parse.y"
{yygotominor.yy356 = yymsp[0].minor.yy0;}
#line 4943 "parse.c"
        break;
      case 28:
#line 136 "parse.y"
{yygotominor.yy356 = yymsp[0].minor.yy0;}
#line 4948 "parse.c"
        break;
      case 29:
#line 137 "parse.y"
{yygotominor.yy356 = yymsp[0].minor.yy0;}
#line 4953 "parse.c"
        break;
      case 30:
        break;
      case 31:
#line 140 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[0].minor.yy356,&yymsp[0].minor.yy356);}
#line 4960 "parse.c"
        break;
      case 32:
#line 141 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-3].minor.yy356,&yymsp[0].minor.yy0);}
#line 4965 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        break;
      case 33:
#line 143 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-5].minor.yy356,&yymsp[0].minor.yy0);}
#line 4972 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        /* No destructor defined for COMMA */
        /* No destructor defined for signed */
        break;
      case 34:
#line 145 "parse.y"
{yygotominor.yy356 = yymsp[0].minor.yy356;}
#line 4981 "parse.c"
        break;
      case 35:
#line 146 "parse.y"
{yygotominor.yy356 = yymsp[-1].minor.yy356;}
#line 4986 "parse.c"
        /* No destructor defined for ids */
        break;
      case 36:
        /* No destructor defined for INTEGER */
        break;
      case 37:
        /* No destructor defined for PLUS */
        /* No destructor defined for INTEGER */
        break;
      case 38:
        /* No destructor defined for MINUS */
        /* No destructor defined for INTEGER */
        break;
      case 39:
        /* No destructor defined for carglist */
        /* No destructor defined for carg */
        break;
      case 40:
        break;
      case 41:
        /* No destructor defined for CONSTRAINT */
        /* No destructor defined for nm */
        /* No destructor defined for ccons */
        break;
      case 42:
        /* No destructor defined for ccons */
        break;
      case 43:
#line 154 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5017 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 44:
#line 155 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5023 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 45:
#line 156 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5029 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 46:
#line 157 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5035 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 47:
#line 158 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 5042 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 48:
#line 159 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5049 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 49:
#line 160 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5055 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 50:
#line 161 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 5062 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 51:
        /* No destructor defined for DEFAULT */
        /* No destructor defined for NULL */
        break;
      case 52:
        /* No destructor defined for NULL */
        /* No destructor defined for onconf */
        break;
      case 53:
#line 168 "parse.y"
{sqliteAddNotNull(pParse, yymsp[0].minor.yy6);}
#line 5077 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for NULL */
        break;
      case 54:
#line 169 "parse.y"
{sqliteAddPrimaryKey(pParse,0,yymsp[0].minor.yy6);}
#line 5084 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for sortorder */
        break;
      case 55:
#line 170 "parse.y"
{sqliteCreateIndex(pParse,0,0,0,yymsp[0].minor.yy6,0,0);}
#line 5092 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 56:
        /* No destructor defined for CHECK */
        /* No destructor defined for LP */
  yy_destructor(150,&yymsp[-2].minor);
        /* No destructor defined for RP */
        /* No destructor defined for onconf */
        break;
      case 57:
#line 173 "parse.y"
{sqliteCreateForeignKey(pParse,0,&yymsp[-2].minor.yy356,yymsp[-1].minor.yy208,yymsp[0].minor.yy6);}
#line 5105 "parse.c"
        /* No destructor defined for REFERENCES */
        break;
      case 58:
#line 174 "parse.y"
{sqliteDeferForeignKey(pParse,yymsp[0].minor.yy6);}
#line 5111 "parse.c"
        break;
      case 59:
#line 175 "parse.y"
{
   sqliteAddCollateType(pParse, sqliteCollateType(pParse, &yymsp[0].minor.yy356));
}
#line 5118 "parse.c"
        /* No destructor defined for COLLATE */
        break;
      case 60:
#line 185 "parse.y"
{ yygotominor.yy6 = OE_Restrict * 0x010101; }
#line 5124 "parse.c"
        break;
      case 61:
#line 186 "parse.y"
{ yygotominor.yy6 = (yymsp[-1].minor.yy6 & yymsp[0].minor.yy33.mask) | yymsp[0].minor.yy33.value; }
#line 5129 "parse.c"
        break;
      case 62:
#line 188 "parse.y"
{ yygotominor.yy33.value = 0;     yygotominor.yy33.mask = 0x000000; }
#line 5134 "parse.c"
        /* No destructor defined for MATCH */
        /* No destructor defined for nm */
        break;
      case 63:
#line 189 "parse.y"
{ yygotominor.yy33.value = yymsp[0].minor.yy6;     yygotominor.yy33.mask = 0x0000ff; }
#line 5141 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for DELETE */
        break;
      case 64:
#line 190 "parse.y"
{ yygotominor.yy33.value = yymsp[0].minor.yy6<<8;  yygotominor.yy33.mask = 0x00ff00; }
#line 5148 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for UPDATE */
        break;
      case 65:
#line 191 "parse.y"
{ yygotominor.yy33.value = yymsp[0].minor.yy6<<16; yygotominor.yy33.mask = 0xff0000; }
#line 5155 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for INSERT */
        break;
      case 66:
#line 193 "parse.y"
{ yygotominor.yy6 = OE_SetNull; }
#line 5162 "parse.c"
        /* No destructor defined for SET */
        /* No destructor defined for NULL */
        break;
      case 67:
#line 194 "parse.y"
{ yygotominor.yy6 = OE_SetDflt; }
#line 5169 "parse.c"
        /* No destructor defined for SET */
        /* No destructor defined for DEFAULT */
        break;
      case 68:
#line 195 "parse.y"
{ yygotominor.yy6 = OE_Cascade; }
#line 5176 "parse.c"
        /* No destructor defined for CASCADE */
        break;
      case 69:
#line 196 "parse.y"
{ yygotominor.yy6 = OE_Restrict; }
#line 5182 "parse.c"
        /* No destructor defined for RESTRICT */
        break;
      case 70:
#line 198 "parse.y"
{yygotominor.yy6 = yymsp[0].minor.yy6;}
#line 5188 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for DEFERRABLE */
        break;
      case 71:
#line 199 "parse.y"
{yygotominor.yy6 = yymsp[0].minor.yy6;}
#line 5195 "parse.c"
        /* No destructor defined for DEFERRABLE */
        break;
      case 72:
#line 201 "parse.y"
{yygotominor.yy6 = 0;}
#line 5201 "parse.c"
        break;
      case 73:
#line 202 "parse.y"
{yygotominor.yy6 = 1;}
#line 5206 "parse.c"
        /* No destructor defined for INITIALLY */
        /* No destructor defined for DEFERRED */
        break;
      case 74:
#line 203 "parse.y"
{yygotominor.yy6 = 0;}
#line 5213 "parse.c"
        /* No destructor defined for INITIALLY */
        /* No destructor defined for IMMEDIATE */
        break;
      case 75:
        break;
      case 76:
        /* No destructor defined for COMMA */
        /* No destructor defined for conslist */
        break;
      case 77:
        /* No destructor defined for conslist */
        /* No destructor defined for COMMA */
        /* No destructor defined for tcons */
        break;
      case 78:
        /* No destructor defined for conslist */
        /* No destructor defined for tcons */
        break;
      case 79:
        /* No destructor defined for tcons */
        break;
      case 80:
        /* No destructor defined for CONSTRAINT */
        /* No destructor defined for nm */
        break;
      case 81:
#line 215 "parse.y"
{sqliteAddPrimaryKey(pParse,yymsp[-2].minor.yy208,yymsp[0].minor.yy6);}
#line 5242 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 82:
#line 217 "parse.y"
{sqliteCreateIndex(pParse,0,0,yymsp[-2].minor.yy208,yymsp[0].minor.yy6,0,0);}
#line 5251 "parse.c"
        /* No destructor defined for UNIQUE */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 83:
        /* No destructor defined for CHECK */
  yy_destructor(150,&yymsp[-1].minor);
        /* No destructor defined for onconf */
        break;
      case 84:
#line 220 "parse.y"
{
    sqliteCreateForeignKey(pParse, yymsp[-6].minor.yy208, &yymsp[-3].minor.yy356, yymsp[-2].minor.yy208, yymsp[-1].minor.yy6);
    sqliteDeferForeignKey(pParse, yymsp[0].minor.yy6);
}
#line 5267 "parse.c"
        /* No destructor defined for FOREIGN */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        /* No destructor defined for REFERENCES */
        break;
      case 85:
#line 225 "parse.y"
{yygotominor.yy6 = 0;}
#line 5277 "parse.c"
        break;
      case 86:
#line 226 "parse.y"
{yygotominor.yy6 = yymsp[0].minor.yy6;}
#line 5282 "parse.c"
        break;
      case 87:
#line 234 "parse.y"
{ yygotominor.yy6 = OE_Default; }
#line 5287 "parse.c"
        break;
      case 88:
#line 235 "parse.y"
{ yygotominor.yy6 = yymsp[0].minor.yy6; }
#line 5292 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for CONFLICT */
        break;
      case 89:
#line 236 "parse.y"
{ yygotominor.yy6 = OE_Default; }
#line 5299 "parse.c"
        break;
      case 90:
#line 237 "parse.y"
{ yygotominor.yy6 = yymsp[0].minor.yy6; }
#line 5304 "parse.c"
        /* No destructor defined for OR */
        break;
      case 91:
#line 238 "parse.y"
{ yygotominor.yy6 = OE_Rollback; }
#line 5310 "parse.c"
        /* No destructor defined for ROLLBACK */
        break;
      case 92:
#line 239 "parse.y"
{ yygotominor.yy6 = OE_Abort; }
#line 5316 "parse.c"
        /* No destructor defined for ABORT */
        break;
      case 93:
#line 240 "parse.y"
{ yygotominor.yy6 = OE_Fail; }
#line 5322 "parse.c"
        /* No destructor defined for FAIL */
        break;
      case 94:
#line 241 "parse.y"
{ yygotominor.yy6 = OE_Ignore; }
#line 5328 "parse.c"
        /* No destructor defined for IGNORE */
        break;
      case 95:
#line 242 "parse.y"
{ yygotominor.yy6 = OE_Replace; }
#line 5334 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 96:
#line 246 "parse.y"
{sqliteDropTable(pParse,&yymsp[0].minor.yy356,0);}
#line 5340 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for TABLE */
        break;
      case 97:
#line 250 "parse.y"
{
  sqliteCreateView(pParse, &yymsp[-5].minor.yy0, &yymsp[-2].minor.yy356, yymsp[0].minor.yy331, yymsp[-4].minor.yy6);
}
#line 5349 "parse.c"
        /* No destructor defined for VIEW */
        /* No destructor defined for AS */
        break;
      case 98:
#line 253 "parse.y"
{
  sqliteDropTable(pParse, &yymsp[0].minor.yy356, 1);
}
#line 5358 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for VIEW */
        break;
      case 99:
#line 259 "parse.y"
{
  sqliteSelect(pParse, yymsp[0].minor.yy331, SRT_Callback, 0, 0, 0, 0);
  sqliteSelectDelete(yymsp[0].minor.yy331);
}
#line 5368 "parse.c"
        break;
      case 100:
#line 269 "parse.y"
{yygotominor.yy331 = yymsp[0].minor.yy331;}
#line 5373 "parse.c"
        break;
      case 101:
#line 270 "parse.y"
{
  if( yymsp[0].minor.yy331 ){
    yymsp[0].minor.yy331->op = yymsp[-1].minor.yy6;
    yymsp[0].minor.yy331->pPrior = yymsp[-2].minor.yy331;
  }
  yygotominor.yy331 = yymsp[0].minor.yy331;
}
#line 5384 "parse.c"
        break;
      case 102:
#line 278 "parse.y"
{yygotominor.yy6 = TK_UNION;}
#line 5389 "parse.c"
        /* No destructor defined for UNION */
        break;
      case 103:
#line 279 "parse.y"
{yygotominor.yy6 = TK_ALL;}
#line 5395 "parse.c"
        /* No destructor defined for UNION */
        /* No destructor defined for ALL */
        break;
      case 104:
#line 280 "parse.y"
{yygotominor.yy6 = TK_INTERSECT;}
#line 5402 "parse.c"
        /* No destructor defined for INTERSECT */
        break;
      case 105:
#line 281 "parse.y"
{yygotominor.yy6 = TK_EXCEPT;}
#line 5408 "parse.c"
        /* No destructor defined for EXCEPT */
        break;
      case 106:
#line 283 "parse.y"
{
  yygotominor.yy331 = sqliteSelectNew(yymsp[-6].minor.yy354,yymsp[-5].minor.yy159,yymsp[-4].minor.yy154,yymsp[-3].minor.yy354,yymsp[-2].minor.yy154,yymsp[-1].minor.yy354,yymsp[-7].minor.yy6,yymsp[0].minor.yy70.limit,yymsp[0].minor.yy70.offset);
}
#line 5416 "parse.c"
        /* No destructor defined for SELECT */
        break;
      case 107:
#line 291 "parse.y"
{yygotominor.yy6 = 1;}
#line 5422 "parse.c"
        /* No destructor defined for DISTINCT */
        break;
      case 108:
#line 292 "parse.y"
{yygotominor.yy6 = 0;}
#line 5428 "parse.c"
        /* No destructor defined for ALL */
        break;
      case 109:
#line 293 "parse.y"
{yygotominor.yy6 = 0;}
#line 5434 "parse.c"
        break;
      case 110:
#line 304 "parse.y"
{yygotominor.yy354 = yymsp[-1].minor.yy354;}
#line 5439 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 111:
#line 305 "parse.y"
{yygotominor.yy354 = 0;}
#line 5445 "parse.c"
        break;
      case 112:
#line 306 "parse.y"
{
   yygotominor.yy354 = sqliteExprListAppend(yymsp[-2].minor.yy354,yymsp[-1].minor.yy154,yymsp[0].minor.yy356.n?&yymsp[0].minor.yy356:0);
}
#line 5452 "parse.c"
        break;
      case 113:
#line 309 "parse.y"
{
  yygotominor.yy354 = sqliteExprListAppend(yymsp[-1].minor.yy354, sqliteExpr(TK_ALL, 0, 0, 0), 0);
}
#line 5459 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 114:
#line 312 "parse.y"
{
  Expr *pRight = sqliteExpr(TK_ALL, 0, 0, 0);
  Expr *pLeft = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy356);
  yygotominor.yy354 = sqliteExprListAppend(yymsp[-3].minor.yy354, sqliteExpr(TK_DOT, pLeft, pRight, 0), 0);
}
#line 5469 "parse.c"
        /* No destructor defined for DOT */
        /* No destructor defined for STAR */
        break;
      case 115:
#line 322 "parse.y"
{ yygotominor.yy356 = yymsp[0].minor.yy356; }
#line 5476 "parse.c"
        /* No destructor defined for AS */
        break;
      case 116:
#line 323 "parse.y"
{ yygotominor.yy356 = yymsp[0].minor.yy356; }
#line 5482 "parse.c"
        break;
      case 117:
#line 324 "parse.y"
{ yygotominor.yy356.n = 0; }
#line 5487 "parse.c"
        break;
      case 118:
#line 336 "parse.y"
{yygotominor.yy159 = sqliteMalloc(sizeof(*yygotominor.yy159));}
#line 5492 "parse.c"
        break;
      case 119:
#line 337 "parse.y"
{yygotominor.yy159 = yymsp[0].minor.yy159;}
#line 5497 "parse.c"
        /* No destructor defined for FROM */
        break;
      case 120:
#line 342 "parse.y"
{
   yygotominor.yy159 = yymsp[-1].minor.yy159;
   if( yygotominor.yy159 && yygotominor.yy159->nSrc>0 ) yygotominor.yy159->a[yygotominor.yy159->nSrc-1].jointype = yymsp[0].minor.yy6;
}
#line 5506 "parse.c"
        break;
      case 121:
#line 346 "parse.y"
{yygotominor.yy159 = 0;}
#line 5511 "parse.c"
        break;
      case 122:
#line 347 "parse.y"
{
  yygotominor.yy159 = sqliteSrcListAppend(yymsp[-4].minor.yy159,&yymsp[-3].minor.yy356);
  if( yymsp[-2].minor.yy356.n ) sqliteSrcListAddAlias(yygotominor.yy159,&yymsp[-2].minor.yy356);
  if( yymsp[-1].minor.yy154 ){
    if( yygotominor.yy159 && yygotominor.yy159->nSrc>1 ){ yygotominor.yy159->a[yygotominor.yy159->nSrc-2].pOn = yymsp[-1].minor.yy154; }
    else { sqliteExprDelete(yymsp[-1].minor.yy154); }
  }
  if( yymsp[0].minor.yy208 ){
    if( yygotominor.yy159 && yygotominor.yy159->nSrc>1 ){ yygotominor.yy159->a[yygotominor.yy159->nSrc-2].pUsing = yymsp[0].minor.yy208; }
    else { sqliteIdListDelete(yymsp[0].minor.yy208); }
  }
}
#line 5527 "parse.c"
        break;
      case 123:
#line 359 "parse.y"
{
  yygotominor.yy159 = sqliteSrcListAppend(yymsp[-6].minor.yy159,0);
  yygotominor.yy159->a[yygotominor.yy159->nSrc-1].pSelect = yymsp[-4].minor.yy331;
  if( yymsp[-2].minor.yy356.n ) sqliteSrcListAddAlias(yygotominor.yy159,&yymsp[-2].minor.yy356);
  if( yymsp[-1].minor.yy154 ){
    if( yygotominor.yy159 && yygotominor.yy159->nSrc>1 ){ yygotominor.yy159->a[yygotominor.yy159->nSrc-2].pOn = yymsp[-1].minor.yy154; }
    else { sqliteExprDelete(yymsp[-1].minor.yy154); }
  }
  if( yymsp[0].minor.yy208 ){
    if( yygotominor.yy159 && yygotominor.yy159->nSrc>1 ){ yygotominor.yy159->a[yygotominor.yy159->nSrc-2].pUsing = yymsp[0].minor.yy208; }
    else { sqliteIdListDelete(yymsp[0].minor.yy208); }
  }
}
#line 5544 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 124:
#line 375 "parse.y"
{ yygotominor.yy6 = JT_INNER; }
#line 5551 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 125:
#line 376 "parse.y"
{ yygotominor.yy6 = JT_INNER; }
#line 5557 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 126:
#line 377 "parse.y"
{ yygotominor.yy6 = sqliteJoinType(pParse,&yymsp[-1].minor.yy0,0,0); }
#line 5563 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 127:
#line 378 "parse.y"
{ yygotominor.yy6 = sqliteJoinType(pParse,&yymsp[-2].minor.yy0,&yymsp[-1].minor.yy356,0); }
#line 5569 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 128:
#line 380 "parse.y"
{ yygotominor.yy6 = sqliteJoinType(pParse,&yymsp[-3].minor.yy0,&yymsp[-2].minor.yy356,&yymsp[-1].minor.yy356); }
#line 5575 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 129:
#line 384 "parse.y"
{yygotominor.yy154 = yymsp[0].minor.yy154;}
#line 5581 "parse.c"
        /* No destructor defined for ON */
        break;
      case 130:
#line 385 "parse.y"
{yygotominor.yy154 = 0;}
#line 5587 "parse.c"
        break;
      case 131:
#line 389 "parse.y"
{yygotominor.yy208 = yymsp[-1].minor.yy208;}
#line 5592 "parse.c"
        /* No destructor defined for USING */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 132:
#line 390 "parse.y"
{yygotominor.yy208 = 0;}
#line 5600 "parse.c"
        break;
      case 133:
#line 400 "parse.y"
{yygotominor.yy354 = 0;}
#line 5605 "parse.c"
        break;
      case 134:
#line 401 "parse.y"
{yygotominor.yy354 = yymsp[0].minor.yy354;}
#line 5610 "parse.c"
        /* No destructor defined for ORDER */
        /* No destructor defined for BY */
        break;
      case 135:
#line 402 "parse.y"
{
  yygotominor.yy354 = sqliteExprListAppend(yymsp[-4].minor.yy354,yymsp[-2].minor.yy154,0);
  if( yygotominor.yy354 ) yygotominor.yy354->a[yygotominor.yy354->nExpr-1].sortOrder = yymsp[-1].minor.yy6+yymsp[0].minor.yy6;
}
#line 5620 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 136:
#line 406 "parse.y"
{
  yygotominor.yy354 = sqliteExprListAppend(0,yymsp[-2].minor.yy154,0);
  if( yygotominor.yy354 ) yygotominor.yy354->a[0].sortOrder = yymsp[-1].minor.yy6+yymsp[0].minor.yy6;
}
#line 5629 "parse.c"
        break;
      case 137:
#line 410 "parse.y"
{yygotominor.yy154 = yymsp[0].minor.yy154;}
#line 5634 "parse.c"
        break;
      case 138:
#line 415 "parse.y"
{yygotominor.yy6 = SQLITE_SO_ASC;}
#line 5639 "parse.c"
        /* No destructor defined for ASC */
        break;
      case 139:
#line 416 "parse.y"
{yygotominor.yy6 = SQLITE_SO_DESC;}
#line 5645 "parse.c"
        /* No destructor defined for DESC */
        break;
      case 140:
#line 417 "parse.y"
{yygotominor.yy6 = SQLITE_SO_ASC;}
#line 5651 "parse.c"
        break;
      case 141:
#line 418 "parse.y"
{yygotominor.yy6 = SQLITE_SO_UNK;}
#line 5656 "parse.c"
        break;
      case 142:
#line 419 "parse.y"
{yygotominor.yy6 = sqliteCollateType(pParse, &yymsp[0].minor.yy356);}
#line 5661 "parse.c"
        /* No destructor defined for COLLATE */
        break;
      case 143:
#line 423 "parse.y"
{yygotominor.yy354 = 0;}
#line 5667 "parse.c"
        break;
      case 144:
#line 424 "parse.y"
{yygotominor.yy354 = yymsp[0].minor.yy354;}
#line 5672 "parse.c"
        /* No destructor defined for GROUP */
        /* No destructor defined for BY */
        break;
      case 145:
#line 428 "parse.y"
{yygotominor.yy154 = 0;}
#line 5679 "parse.c"
        break;
      case 146:
#line 429 "parse.y"
{yygotominor.yy154 = yymsp[0].minor.yy154;}
#line 5684 "parse.c"
        /* No destructor defined for HAVING */
        break;
      case 147:
#line 432 "parse.y"
{yygotominor.yy70.limit = -1; yygotominor.yy70.offset = 0;}
#line 5690 "parse.c"
        break;
      case 148:
#line 433 "parse.y"
{yygotominor.yy70.limit = atoi(yymsp[0].minor.yy0.z); yygotominor.yy70.offset = 0;}
#line 5695 "parse.c"
        /* No destructor defined for LIMIT */
        break;
      case 149:
#line 435 "parse.y"
{yygotominor.yy70.limit = atoi(yymsp[-2].minor.yy0.z); yygotominor.yy70.offset = atoi(yymsp[0].minor.yy0.z);}
#line 5701 "parse.c"
        /* No destructor defined for LIMIT */
        /* No destructor defined for limit_sep */
        break;
      case 150:
        /* No destructor defined for OFFSET */
        break;
      case 151:
        /* No destructor defined for COMMA */
        break;
      case 152:
#line 442 "parse.y"
{sqliteDeleteFrom(pParse, &yymsp[-1].minor.yy356, yymsp[0].minor.yy154);}
#line 5714 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 153:
#line 447 "parse.y"
{yygotominor.yy154 = 0;}
#line 5721 "parse.c"
        break;
      case 154:
#line 448 "parse.y"
{yygotominor.yy154 = yymsp[0].minor.yy154;}
#line 5726 "parse.c"
        /* No destructor defined for WHERE */
        break;
      case 155:
#line 456 "parse.y"
{sqliteUpdate(pParse,&yymsp[-3].minor.yy356,yymsp[-1].minor.yy354,yymsp[0].minor.yy154,yymsp[-4].minor.yy6);}
#line 5732 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 156:
#line 459 "parse.y"
{yygotominor.yy354 = sqliteExprListAppend(yymsp[-4].minor.yy354,yymsp[0].minor.yy154,&yymsp[-2].minor.yy356);}
#line 5739 "parse.c"
        /* No destructor defined for COMMA */
        /* No destructor defined for EQ */
        break;
      case 157:
#line 460 "parse.y"
{yygotominor.yy354 = sqliteExprListAppend(0,yymsp[0].minor.yy154,&yymsp[-2].minor.yy356);}
#line 5746 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 158:
#line 465 "parse.y"
{sqliteInsert(pParse, &yymsp[-5].minor.yy356, yymsp[-1].minor.yy354, 0, yymsp[-4].minor.yy208, yymsp[-7].minor.yy6);}
#line 5752 "parse.c"
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 159:
#line 467 "parse.y"
{sqliteInsert(pParse, &yymsp[-2].minor.yy356, 0, yymsp[0].minor.yy331, yymsp[-1].minor.yy208, yymsp[-4].minor.yy6);}
#line 5761 "parse.c"
        /* No destructor defined for INTO */
        break;
      case 160:
#line 470 "parse.y"
{yygotominor.yy6 = yymsp[0].minor.yy6;}
#line 5767 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 161:
#line 471 "parse.y"
{yygotominor.yy6 = OE_Replace;}
#line 5773 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 162:
#line 477 "parse.y"
{yygotominor.yy354 = sqliteExprListAppend(yymsp[-2].minor.yy354,yymsp[0].minor.yy154,0);}
#line 5779 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 163:
#line 478 "parse.y"
{yygotominor.yy354 = sqliteExprListAppend(0,yymsp[0].minor.yy154,0);}
#line 5785 "parse.c"
        break;
      case 164:
#line 485 "parse.y"
{yygotominor.yy208 = 0;}
#line 5790 "parse.c"
        break;
      case 165:
#line 486 "parse.y"
{yygotominor.yy208 = yymsp[-1].minor.yy208;}
#line 5795 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 166:
#line 487 "parse.y"
{yygotominor.yy208 = sqliteIdListAppend(yymsp[-2].minor.yy208,&yymsp[0].minor.yy356);}
#line 5802 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 167:
#line 488 "parse.y"
{yygotominor.yy208 = sqliteIdListAppend(0,&yymsp[0].minor.yy356);}
#line 5808 "parse.c"
        break;
      case 168:
#line 506 "parse.y"
{yygotominor.yy154 = yymsp[-1].minor.yy154; sqliteExprSpan(yygotominor.yy154,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);}
#line 5813 "parse.c"
        break;
      case 169:
#line 507 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_NULL, 0, 0, &yymsp[0].minor.yy0);}
#line 5818 "parse.c"
        break;
      case 170:
#line 508 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy0);}
#line 5823 "parse.c"
        break;
      case 171:
#line 509 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy0);}
#line 5828 "parse.c"
        break;
      case 172:
#line 510 "parse.y"
{
  Expr *temp1 = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy356);
  Expr *temp2 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy356);
  yygotominor.yy154 = sqliteExpr(TK_DOT, temp1, temp2, 0);
}
#line 5837 "parse.c"
        /* No destructor defined for DOT */
        break;
      case 173:
#line 515 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_INTEGER, 0, 0, &yymsp[0].minor.yy0);}
#line 5843 "parse.c"
        break;
      case 174:
#line 516 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_FLOAT, 0, 0, &yymsp[0].minor.yy0);}
#line 5848 "parse.c"
        break;
      case 175:
#line 517 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_STRING, 0, 0, &yymsp[0].minor.yy0);}
#line 5853 "parse.c"
        break;
      case 176:
#line 518 "parse.y"
{
  yygotominor.yy154 = sqliteExprFunction(yymsp[-1].minor.yy354, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
  if( yygotominor.yy154 ) yygotominor.yy154->token.base = 1;
}
#line 5862 "parse.c"
        /* No destructor defined for LP */
        break;
      case 177:
#line 523 "parse.y"
{
  yygotominor.yy154 = sqliteExprFunction(0, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
  if( yygotominor.yy154 ) yygotominor.yy154->token.base = 1;
}
#line 5872 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for STAR */
        break;
      case 178:
#line 528 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_AND, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5879 "parse.c"
        /* No destructor defined for AND */
        break;
      case 179:
#line 529 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_OR, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5885 "parse.c"
        /* No destructor defined for OR */
        break;
      case 180:
#line 530 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_LT, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5891 "parse.c"
        /* No destructor defined for LT */
        break;
      case 181:
#line 531 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_GT, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5897 "parse.c"
        /* No destructor defined for GT */
        break;
      case 182:
#line 532 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_LE, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5903 "parse.c"
        /* No destructor defined for LE */
        break;
      case 183:
#line 533 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_GE, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5909 "parse.c"
        /* No destructor defined for GE */
        break;
      case 184:
#line 534 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_NE, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5915 "parse.c"
        /* No destructor defined for NE */
        break;
      case 185:
#line 535 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_EQ, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5921 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 186:
#line 536 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_BITAND, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5927 "parse.c"
        /* No destructor defined for BITAND */
        break;
      case 187:
#line 537 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_BITOR, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5933 "parse.c"
        /* No destructor defined for BITOR */
        break;
      case 188:
#line 538 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_LSHIFT, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5939 "parse.c"
        /* No destructor defined for LSHIFT */
        break;
      case 189:
#line 539 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_RSHIFT, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5945 "parse.c"
        /* No destructor defined for RSHIFT */
        break;
      case 190:
#line 540 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[0].minor.yy154, 0);
  pList = sqliteExprListAppend(pList, yymsp[-2].minor.yy154, 0);
  yygotominor.yy154 = sqliteExprFunction(pList, 0);
  if( yygotominor.yy154 ) yygotominor.yy154->op = yymsp[-1].minor.yy6;
  sqliteExprSpan(yygotominor.yy154, &yymsp[-2].minor.yy154->token, &yymsp[0].minor.yy154->token);
}
#line 5957 "parse.c"
        break;
      case 191:
#line 547 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[0].minor.yy154, 0);
  pList = sqliteExprListAppend(pList, yymsp[-3].minor.yy154, 0);
  yygotominor.yy154 = sqliteExprFunction(pList, 0);
  if( yygotominor.yy154 ) yygotominor.yy154->op = yymsp[-1].minor.yy6;
  yygotominor.yy154 = sqliteExpr(TK_NOT, yygotominor.yy154, 0, 0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-3].minor.yy154->token,&yymsp[0].minor.yy154->token);
}
#line 5969 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 192:
#line 556 "parse.y"
{yygotominor.yy6 = TK_LIKE;}
#line 5975 "parse.c"
        /* No destructor defined for LIKE */
        break;
      case 193:
#line 557 "parse.y"
{yygotominor.yy6 = TK_GLOB;}
#line 5981 "parse.c"
        /* No destructor defined for GLOB */
        break;
      case 194:
#line 558 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_PLUS, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5987 "parse.c"
        /* No destructor defined for PLUS */
        break;
      case 195:
#line 559 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_MINUS, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5993 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 196:
#line 560 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_STAR, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 5999 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 197:
#line 561 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_SLASH, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 6005 "parse.c"
        /* No destructor defined for SLASH */
        break;
      case 198:
#line 562 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_REM, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 6011 "parse.c"
        /* No destructor defined for REM */
        break;
      case 199:
#line 563 "parse.y"
{yygotominor.yy154 = sqliteExpr(TK_CONCAT, yymsp[-2].minor.yy154, yymsp[0].minor.yy154, 0);}
#line 6017 "parse.c"
        /* No destructor defined for CONCAT */
        break;
      case 200:
#line 564 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_ISNULL, yymsp[-1].minor.yy154, 0, 0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-1].minor.yy154->token,&yymsp[0].minor.yy0);
}
#line 6026 "parse.c"
        break;
      case 201:
#line 568 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_ISNULL, yymsp[-2].minor.yy154, 0, 0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-2].minor.yy154->token,&yymsp[0].minor.yy0);
}
#line 6034 "parse.c"
        /* No destructor defined for IS */
        break;
      case 202:
#line 572 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_NOTNULL, yymsp[-1].minor.yy154, 0, 0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-1].minor.yy154->token,&yymsp[0].minor.yy0);
}
#line 6043 "parse.c"
        break;
      case 203:
#line 576 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_NOTNULL, yymsp[-2].minor.yy154, 0, 0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-2].minor.yy154->token,&yymsp[0].minor.yy0);
}
#line 6051 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 204:
#line 580 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_NOTNULL, yymsp[-3].minor.yy154, 0, 0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-3].minor.yy154->token,&yymsp[0].minor.yy0);
}
#line 6060 "parse.c"
        /* No destructor defined for IS */
        /* No destructor defined for NOT */
        break;
      case 205:
#line 584 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_NOT, yymsp[0].minor.yy154, 0, 0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy154->token);
}
#line 6070 "parse.c"
        break;
      case 206:
#line 588 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_BITNOT, yymsp[0].minor.yy154, 0, 0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy154->token);
}
#line 6078 "parse.c"
        break;
      case 207:
#line 592 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_UMINUS, yymsp[0].minor.yy154, 0, 0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy154->token);
}
#line 6086 "parse.c"
        break;
      case 208:
#line 596 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_UPLUS, yymsp[0].minor.yy154, 0, 0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy154->token);
}
#line 6094 "parse.c"
        break;
      case 209:
#line 600 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_SELECT, 0, 0, 0);
  if( yygotominor.yy154 ) yygotominor.yy154->pSelect = yymsp[-1].minor.yy331;
  sqliteExprSpan(yygotominor.yy154,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);
}
#line 6103 "parse.c"
        break;
      case 210:
#line 605 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy154, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy154, 0);
  yygotominor.yy154 = sqliteExpr(TK_BETWEEN, yymsp[-4].minor.yy154, 0, 0);
  if( yygotominor.yy154 ) yygotominor.yy154->pList = pList;
  sqliteExprSpan(yygotominor.yy154,&yymsp[-4].minor.yy154->token,&yymsp[0].minor.yy154->token);
}
#line 6114 "parse.c"
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 211:
#line 612 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy154, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy154, 0);
  yygotominor.yy154 = sqliteExpr(TK_BETWEEN, yymsp[-5].minor.yy154, 0, 0);
  if( yygotominor.yy154 ) yygotominor.yy154->pList = pList;
  yygotominor.yy154 = sqliteExpr(TK_NOT, yygotominor.yy154, 0, 0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-5].minor.yy154->token,&yymsp[0].minor.yy154->token);
}
#line 6128 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 212:
#line 620 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_IN, yymsp[-4].minor.yy154, 0, 0);
  if( yygotominor.yy154 ) yygotominor.yy154->pList = yymsp[-1].minor.yy354;
  sqliteExprSpan(yygotominor.yy154,&yymsp[-4].minor.yy154->token,&yymsp[0].minor.yy0);
}
#line 6140 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 213:
#line 625 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_IN, yymsp[-4].minor.yy154, 0, 0);
  if( yygotominor.yy154 ) yygotominor.yy154->pSelect = yymsp[-1].minor.yy331;
  sqliteExprSpan(yygotominor.yy154,&yymsp[-4].minor.yy154->token,&yymsp[0].minor.yy0);
}
#line 6151 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 214:
#line 630 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_IN, yymsp[-5].minor.yy154, 0, 0);
  if( yygotominor.yy154 ) yygotominor.yy154->pList = yymsp[-1].minor.yy354;
  yygotominor.yy154 = sqliteExpr(TK_NOT, yygotominor.yy154, 0, 0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-5].minor.yy154->token,&yymsp[0].minor.yy0);
}
#line 6163 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 215:
#line 636 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_IN, yymsp[-5].minor.yy154, 0, 0);
  if( yygotominor.yy154 ) yygotominor.yy154->pSelect = yymsp[-1].minor.yy331;
  yygotominor.yy154 = sqliteExpr(TK_NOT, yygotominor.yy154, 0, 0);
  sqliteExprSpan(yygotominor.yy154,&yymsp[-5].minor.yy154->token,&yymsp[0].minor.yy0);
}
#line 6176 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 216:
#line 644 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_CASE, yymsp[-3].minor.yy154, yymsp[-1].minor.yy154, 0);
  if( yygotominor.yy154 ) yygotominor.yy154->pList = yymsp[-2].minor.yy354;
  sqliteExprSpan(yygotominor.yy154, &yymsp[-4].minor.yy0, &yymsp[0].minor.yy0);
}
#line 6188 "parse.c"
        break;
      case 217:
#line 651 "parse.y"
{
  yygotominor.yy354 = sqliteExprListAppend(yymsp[-4].minor.yy354, yymsp[-2].minor.yy154, 0);
  yygotominor.yy354 = sqliteExprListAppend(yygotominor.yy354, yymsp[0].minor.yy154, 0);
}
#line 6196 "parse.c"
        /* No destructor defined for WHEN */
        /* No destructor defined for THEN */
        break;
      case 218:
#line 655 "parse.y"
{
  yygotominor.yy354 = sqliteExprListAppend(0, yymsp[-2].minor.yy154, 0);
  yygotominor.yy354 = sqliteExprListAppend(yygotominor.yy354, yymsp[0].minor.yy154, 0);
}
#line 6206 "parse.c"
        /* No destructor defined for WHEN */
        /* No destructor defined for THEN */
        break;
      case 219:
#line 660 "parse.y"
{yygotominor.yy154 = yymsp[0].minor.yy154;}
#line 6213 "parse.c"
        /* No destructor defined for ELSE */
        break;
      case 220:
#line 661 "parse.y"
{yygotominor.yy154 = 0;}
#line 6219 "parse.c"
        break;
      case 221:
#line 663 "parse.y"
{yygotominor.yy154 = yymsp[0].minor.yy154;}
#line 6224 "parse.c"
        break;
      case 222:
#line 664 "parse.y"
{yygotominor.yy154 = 0;}
#line 6229 "parse.c"
        break;
      case 223:
#line 672 "parse.y"
{yygotominor.yy354 = sqliteExprListAppend(yymsp[-2].minor.yy354,yymsp[0].minor.yy154,0);}
#line 6234 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 224:
#line 673 "parse.y"
{yygotominor.yy354 = sqliteExprListAppend(0,yymsp[0].minor.yy154,0);}
#line 6240 "parse.c"
        break;
      case 225:
#line 674 "parse.y"
{yygotominor.yy154 = yymsp[0].minor.yy154;}
#line 6245 "parse.c"
        break;
      case 226:
#line 675 "parse.y"
{yygotominor.yy154 = 0;}
#line 6250 "parse.c"
        break;
      case 227:
#line 680 "parse.y"
{
  if( yymsp[-8].minor.yy6!=OE_None ) yymsp[-8].minor.yy6 = yymsp[0].minor.yy6;
  if( yymsp[-8].minor.yy6==OE_Default) yymsp[-8].minor.yy6 = OE_Abort;
  sqliteCreateIndex(pParse, &yymsp[-6].minor.yy356, &yymsp[-4].minor.yy356, yymsp[-2].minor.yy208, yymsp[-8].minor.yy6, &yymsp[-9].minor.yy0, &yymsp[-1].minor.yy0);
}
#line 6259 "parse.c"
        /* No destructor defined for INDEX */
        /* No destructor defined for ON */
        /* No destructor defined for LP */
        break;
      case 228:
#line 687 "parse.y"
{ yygotominor.yy6 = OE_Abort; }
#line 6267 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 229:
#line 688 "parse.y"
{ yygotominor.yy6 = OE_None; }
#line 6273 "parse.c"
        break;
      case 230:
#line 696 "parse.y"
{yygotominor.yy208 = 0;}
#line 6278 "parse.c"
        break;
      case 231:
#line 697 "parse.y"
{yygotominor.yy208 = yymsp[-1].minor.yy208;}
#line 6283 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 232:
#line 698 "parse.y"
{yygotominor.yy208 = sqliteIdListAppend(yymsp[-2].minor.yy208,&yymsp[0].minor.yy356);}
#line 6290 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 233:
#line 699 "parse.y"
{yygotominor.yy208 = sqliteIdListAppend(0,&yymsp[0].minor.yy356);}
#line 6296 "parse.c"
        break;
      case 234:
#line 700 "parse.y"
{yygotominor.yy356 = yymsp[0].minor.yy356;}
#line 6301 "parse.c"
        break;
      case 235:
#line 705 "parse.y"
{sqliteDropIndex(pParse, &yymsp[0].minor.yy356);}
#line 6306 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for INDEX */
        break;
      case 236:
#line 711 "parse.y"
{sqliteCopy(pParse,&yymsp[-5].minor.yy356,&yymsp[-3].minor.yy356,&yymsp[0].minor.yy0,yymsp[-6].minor.yy6);}
#line 6313 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        /* No destructor defined for USING */
        /* No destructor defined for DELIMITERS */
        break;
      case 237:
#line 713 "parse.y"
{sqliteCopy(pParse,&yymsp[-2].minor.yy356,&yymsp[0].minor.yy356,0,yymsp[-3].minor.yy6);}
#line 6322 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        break;
      case 238:
#line 717 "parse.y"
{sqliteVacuum(pParse,0);}
#line 6329 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 239:
#line 718 "parse.y"
{sqliteVacuum(pParse,&yymsp[0].minor.yy356);}
#line 6335 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 240:
#line 722 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy356,&yymsp[0].minor.yy356,0);}
#line 6341 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 241:
#line 723 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy356,&yymsp[0].minor.yy0,0);}
#line 6348 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 242:
#line 724 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy356,&yymsp[0].minor.yy356,0);}
#line 6355 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 243:
#line 725 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy356,&yymsp[0].minor.yy356,1);}
#line 6362 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 244:
#line 726 "parse.y"
{sqlitePragma(pParse,&yymsp[-3].minor.yy356,&yymsp[-1].minor.yy356,0);}
#line 6369 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 245:
#line 727 "parse.y"
{sqlitePragma(pParse,&yymsp[0].minor.yy356,&yymsp[0].minor.yy356,0);}
#line 6377 "parse.c"
        /* No destructor defined for PRAGMA */
        break;
      case 246:
#line 728 "parse.y"
{yygotominor.yy356 = yymsp[0].minor.yy356;}
#line 6383 "parse.c"
        /* No destructor defined for plus_opt */
        break;
      case 247:
#line 729 "parse.y"
{yygotominor.yy356 = yymsp[0].minor.yy356;}
#line 6389 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 248:
#line 730 "parse.y"
{yygotominor.yy356 = yymsp[0].minor.yy0;}
#line 6395 "parse.c"
        break;
      case 249:
#line 731 "parse.y"
{yygotominor.yy356 = yymsp[0].minor.yy0;}
#line 6400 "parse.c"
        break;
      case 250:
        /* No destructor defined for PLUS */
        break;
      case 251:
        break;
      case 252:
#line 738 "parse.y"
{
  Token all;
  all.z = yymsp[-11].minor.yy0.z;
  all.n = (yymsp[0].minor.yy0.z - yymsp[-11].minor.yy0.z) + yymsp[0].minor.yy0.n;
  sqliteCreateTrigger(pParse, &yymsp[-9].minor.yy356, yymsp[-8].minor.yy6, yymsp[-7].minor.yy398.a, yymsp[-7].minor.yy398.b, &yymsp[-5].minor.yy356, yymsp[-4].minor.yy6, yymsp[-3].minor.yy122, yymsp[-1].minor.yy391, &all);
}
#line 6415 "parse.c"
        /* No destructor defined for TRIGGER */
        /* No destructor defined for ON */
        /* No destructor defined for BEGIN */
        break;
      case 253:
#line 746 "parse.y"
{ yygotominor.yy6 = TK_BEFORE; }
#line 6423 "parse.c"
        /* No destructor defined for BEFORE */
        break;
      case 254:
#line 747 "parse.y"
{ yygotominor.yy6 = TK_AFTER;  }
#line 6429 "parse.c"
        /* No destructor defined for AFTER */
        break;
      case 255:
#line 748 "parse.y"
{ yygotominor.yy6 = TK_INSTEAD;}
#line 6435 "parse.c"
        /* No destructor defined for INSTEAD */
        /* No destructor defined for OF */
        break;
      case 256:
#line 749 "parse.y"
{ yygotominor.yy6 = TK_BEFORE; }
#line 6442 "parse.c"
        break;
      case 257:
#line 753 "parse.y"
{ yygotominor.yy398.a = TK_DELETE; yygotominor.yy398.b = 0; }
#line 6447 "parse.c"
        /* No destructor defined for DELETE */
        break;
      case 258:
#line 754 "parse.y"
{ yygotominor.yy398.a = TK_INSERT; yygotominor.yy398.b = 0; }
#line 6453 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 259:
#line 755 "parse.y"
{ yygotominor.yy398.a = TK_UPDATE; yygotominor.yy398.b = 0;}
#line 6459 "parse.c"
        /* No destructor defined for UPDATE */
        break;
      case 260:
#line 756 "parse.y"
{yygotominor.yy398.a = TK_UPDATE; yygotominor.yy398.b = yymsp[0].minor.yy208; }
#line 6465 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for OF */
        break;
      case 261:
#line 759 "parse.y"
{ yygotominor.yy6 = TK_ROW; }
#line 6472 "parse.c"
        break;
      case 262:
#line 760 "parse.y"
{ yygotominor.yy6 = TK_ROW; }
#line 6477 "parse.c"
        /* No destructor defined for FOR */
        /* No destructor defined for EACH */
        /* No destructor defined for ROW */
        break;
      case 263:
#line 761 "parse.y"
{ yygotominor.yy6 = TK_STATEMENT; }
#line 6485 "parse.c"
        /* No destructor defined for FOR */
        /* No destructor defined for EACH */
        /* No destructor defined for STATEMENT */
        break;
      case 264:
#line 764 "parse.y"
{ yygotominor.yy122 = 0; }
#line 6493 "parse.c"
        break;
      case 265:
#line 765 "parse.y"
{ yygotominor.yy122 = yymsp[0].minor.yy154; }
#line 6498 "parse.c"
        /* No destructor defined for WHEN */
        break;
      case 266:
#line 768 "parse.y"
{
  yymsp[-2].minor.yy391->pNext = yymsp[0].minor.yy391 ; yygotominor.yy391 = yymsp[-2].minor.yy391; }
#line 6505 "parse.c"
        /* No destructor defined for SEMI */
        break;
      case 267:
#line 770 "parse.y"
{ yygotominor.yy391 = 0; }
#line 6511 "parse.c"
        break;
      case 268:
#line 775 "parse.y"
{ yygotominor.yy391 = sqliteTriggerUpdateStep(&yymsp[-3].minor.yy356, yymsp[-1].minor.yy354, yymsp[0].minor.yy154, yymsp[-4].minor.yy6); }
#line 6516 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 269:
#line 780 "parse.y"
{yygotominor.yy391 = sqliteTriggerInsertStep(&yymsp[-5].minor.yy356, yymsp[-4].minor.yy208, yymsp[-1].minor.yy354, 0, yymsp[-7].minor.yy6);}
#line 6523 "parse.c"
        /* No destructor defined for INSERT */
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 270:
#line 783 "parse.y"
{yygotominor.yy391 = sqliteTriggerInsertStep(&yymsp[-2].minor.yy356, yymsp[-1].minor.yy208, 0, yymsp[0].minor.yy331, yymsp[-4].minor.yy6);}
#line 6533 "parse.c"
        /* No destructor defined for INSERT */
        /* No destructor defined for INTO */
        break;
      case 271:
#line 787 "parse.y"
{yygotominor.yy391 = sqliteTriggerDeleteStep(&yymsp[-1].minor.yy356, yymsp[0].minor.yy154);}
#line 6540 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 272:
#line 790 "parse.y"
{yygotominor.yy391 = sqliteTriggerSelectStep(yymsp[0].minor.yy331); }
#line 6547 "parse.c"
        break;
      case 273:
#line 793 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_RAISE, 0, 0, 0); 
  yygotominor.yy154->iColumn = OE_Ignore;
  /* sqliteExprSpan(yygotominor.yy154, &yymsp[-3].minor.yy0, &yymsp[0].minor.yy0); */
}
#line 6556 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for IGNORE */
        break;
      case 274:
#line 798 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy356); 
  yygotominor.yy154->iColumn = OE_Rollback;
  /* sqliteExprSpan(yygotominor.yy154, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0); */
}
#line 6567 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for ROLLBACK */
        /* No destructor defined for COMMA */
        break;
      case 275:
#line 803 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy356); 
  yygotominor.yy154->iColumn = OE_Abort;
  /* sqliteExprSpan(yygotominor.yy154, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0); */
}
#line 6579 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for ABORT */
        /* No destructor defined for COMMA */
        break;
      case 276:
#line 808 "parse.y"
{
  yygotominor.yy154 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy356); 
  yygotominor.yy154->iColumn = OE_Fail;
  /* sqliteExprSpan(yygotominor.yy154, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0); */
}
#line 6591 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for FAIL */
        /* No destructor defined for COMMA */
        break;
      case 277:
#line 815 "parse.y"
{
    sqliteDropTrigger(pParse,&yymsp[0].minor.yy356,0);
}
#line 6601 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for TRIGGER */
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

#line 6651 "parse.c"
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
