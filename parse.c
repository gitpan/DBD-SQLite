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
#define YYNOCODE 211
#define YYACTIONTYPE unsigned short int
#define sqliteParserTOKENTYPE Token
typedef union {
  sqliteParserTOKENTYPE yy0;
  struct LimitVal yy6;
  SrcList* yy7;
  Expr* yy62;
  struct TrigEvent yy90;
  int yy172;
  Select* yy219;
  ExprList* yy228;
  IdList* yy250;
  Expr * yy308;
  TriggerStep * yy311;
  Token yy378;
  int yy421;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define sqliteParserARG_SDECL Parse *pParse;
#define sqliteParserARG_PDECL ,Parse *pParse
#define sqliteParserARG_FETCH Parse *pParse = yypParser->pParse
#define sqliteParserARG_STORE yypParser->pParse = pParse
#define YYNSTATE 519
#define YYNRULE 272
#define YYERRORSYMBOL 148
#define YYERRSYMDT yy421
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
  { 162,   0, 792}, /*  1:                  input accept */
  {  44,   0, 517}, /*  2:                EXPLAIN shift  517 */
  { 104,   2, 516}, /*  3:                   SEMI shift  516 */
  { 147,   5, 518}, /*  4:                   ecmd shift  518 */
  { 135,   0,   1}, /*  5:                cmdlist shift  1 */
  { 149,   0,   3}, /*  6:                explain shift  3 */
/* State 1 */
  {   0,   0, 519}, /*  1:                      $ reduce 0 */
  { 104,   4, 516}, /*  2:                   SEMI shift  516 */
  { 147,   0,   2}, /*  3:                   ecmd shift  2 */
  {  44,   0, 517}, /*  4:                EXPLAIN shift  517 */
  { 149,   2,   3}, /*  5:                explain shift  3 */
/* State 3 */
  {  40,   0,  24}, /*  1:                    END shift  24 */
  { 134,   0,   4}, /*  2:                    cmd shift  4 */
  {  97,   1, 488}, /*  3:                REPLACE shift  488 */
  {  23,   0,  22}, /*  4:                 COMMIT shift  22 */
  {  99,   4,  26}, /*  5:               ROLLBACK shift  26 */
  { 120,   0, 471}, /*  6:                 UPDATE shift  471 */
  { 177,   6,  66}, /*  7:              oneselect shift  66 */
  {  64,   0, 486}, /*  8:                 INSERT shift  486 */
  { 122,  11, 497}, /*  9:                 VACUUM shift  497 */
  { 142,  12,  28}, /* 10:           create_table shift  28 */
  { 103,  13,  70}, /* 11:                 SELECT shift  70 */
  {  28,  15, 370}, /* 12:                 CREATE shift  370 */
  {  27,   0, 489}, /* 13:                   COPY shift  489 */
  { 165,  16, 477}, /* 14:             insert_cmd shift  477 */
  {   9,   0,   6}, /* 15:                  BEGIN shift  6 */
  {  32,   0, 467}, /* 16:                 DELETE shift  467 */
  {  92,   0, 499}, /* 17:                 PRAGMA shift  499 */
  {  37,   0, 457}, /* 18:                   DROP shift  457 */
  { 189,  18, 466}, /* 19:                 select shift  466 */
/* State 4 */
  { 104,   0,   5}, /*  1:                   SEMI shift  5 */
/* State 6 */
  { 114,   0,  17}, /*  1:            TRANSACTION shift  17 */
  { 199,   0,   7}, /*  2:              trans_opt shift  7 */
/* State 7 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 104,   0, 604}, /*  2:                   SEMI reduce 85 */
  { 176,   2,   8}, /*  3:                 onconf shift  8 */
/* State 8 */
  { 104,   0, 526}, /*  1:                   SEMI reduce 7 */
/* State 9 */
  {  25,   0,  10}, /*  1:               CONFLICT shift  10 */
/* State 10 */
  { 186,   0,  11}, /*  1:            resolvetype shift  11 */
  {  97,   3,  16}, /*  2:                REPLACE shift  16 */
  {   1,   0,  13}, /*  3:                  ABORT shift  13 */
  {  99,   6,  12}, /*  4:               ROLLBACK shift  12 */
  {  58,   0,  15}, /*  5:                 IGNORE shift  15 */
  {  45,   0,  14}, /*  6:                   FAIL shift  14 */
/* State 17 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4,  18}, /*  3:                    ids shift  18 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 22 */
  { 114,   0,  17}, /*  1:            TRANSACTION shift  17 */
  { 199,   0,  23}, /*  2:              trans_opt shift  23 */
  { 104,   0, 527}, /*  3:                   SEMI reduce 8 */
/* State 23 */
  { 104,   0, 530}, /*  1:                   SEMI reduce 11 */
/* State 24 */
  { 114,   0,  17}, /*  1:            TRANSACTION shift  17 */
  { 199,   0,  25}, /*  2:              trans_opt shift  25 */
  { 104,   0, 527}, /*  3:                   SEMI reduce 8 */
/* State 25 */
  { 104,   0, 531}, /*  1:                   SEMI reduce 12 */
/* State 26 */
  { 114,   0,  17}, /*  1:            TRANSACTION shift  17 */
  { 199,   0,  27}, /*  2:              trans_opt shift  27 */
  { 104,   0, 527}, /*  3:                   SEMI reduce 8 */
/* State 27 */
  { 104,   0, 532}, /*  1:                   SEMI reduce 13 */
/* State 28 */
  {   6,   0, 368}, /*  1:                     AS shift  368 */
  {  76,   0,  30}, /*  2:                     LP shift  30 */
  { 143,   0,  29}, /*  3:      create_table_args shift  29 */
/* State 29 */
  { 104,   0, 533}, /*  1:                   SEMI reduce 14 */
/* State 30 */
  { 137,   0, 367}, /*  1:                 column shift  367 */
  {  57,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  21}, /*  3:                 STRING shift  21 */
  { 157,   0,  20}, /*  4:                     id shift  20 */
  { 158,   1, 336}, /*  5:                    ids shift  336 */
  { 138,   3,  36}, /*  6:               columnid shift  36 */
  { 139,   0,  31}, /*  7:             columnlist shift  31 */
/* State 31 */
  { 141,   2,  32}, /*  1:           conslist_opt shift  32 */
  {  21,   0,  34}, /*  2:                  COMMA shift  34 */
  { 101,   0, 592}, /*  3:                     RP reduce 73 */
/* State 32 */
  { 101,   0,  33}, /*  1:                     RP shift  33 */
/* State 33 */
  { 104,   0, 537}, /*  1:                   SEMI reduce 18 */
/* State 34 */
  {  26,   0, 340}, /*  1:             CONSTRAINT shift  340 */
  { 157,   0,  20}, /*  2:                     id shift  20 */
  { 197,   4, 366}, /*  3:                  tcons shift  366 */
  { 158,  12, 336}, /*  4:                    ids shift  336 */
  {  17,   0, 353}, /*  5:                  CHECK shift  353 */
  {  57,   0,  19}, /*  6:                     ID shift  19 */
  { 110,   0,  21}, /*  7:                 STRING shift  21 */
  { 137,   0,  35}, /*  8:                 column shift  35 */
  { 138,   0,  36}, /*  9:               columnid shift  36 */
  {  48,   0, 356}, /* 10:                FOREIGN shift  356 */
  { 140,   0, 337}, /* 11:               conslist shift  337 */
  { 119,  13, 348}, /* 12:                 UNIQUE shift  348 */
  {  93,   0, 342}, /* 13:                PRIMARY shift  342 */
/* State 36 */
  { 204,   0,  37}, /*  1:                   type shift  37 */
  { 205,   5, 322}, /*  2:               typename shift  322 */
  { 158,   6, 335}, /*  3:                    ids shift  335 */
  {  57,   0,  19}, /*  4:                     ID shift  19 */
  { 157,   0,  20}, /*  5:                     id shift  20 */
  { 110,   0,  21}, /*  6:                 STRING shift  21 */
/* State 37 */
  { 129,   0,  38}, /*  1:               carglist shift  38 */
/* State 38 */
  {  26,   0,  40}, /*  1:             CONSTRAINT shift  40 */
  { 144,   0, 283}, /*  2:        defer_subclause shift  283 */
  { 119,   6,  57}, /*  3:                 UNIQUE shift  57 */
  { 185,   8, 282}, /*  4:             references shift  282 */
  {  95,   9, 286}, /*  5:             REFERENCES shift  286 */
  {  93,   0,  51}, /*  6:                PRIMARY shift  51 */
  {  19,   0, 284}, /*  7:                COLLATE shift  284 */
  { 133,  10, 309}, /*  8:                  ccons shift  309 */
  {  82,  11,  43}, /*  9:                    NOT shift  43 */
  {  29,   0, 310}, /* 10:                DEFAULT shift  310 */
  {  30,  13, 307}, /* 11:             DEFERRABLE shift  307 */
  { 128,   0,  39}, /* 12:                   carg shift  39 */
  {  17,   0,  59}, /* 13:                  CHECK shift  59 */
/* State 40 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4,  41}, /*  3:                    ids shift  41 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 41 */
  {  30,   0, 307}, /*  1:             DEFERRABLE shift  307 */
  {  93,   0,  51}, /*  2:                PRIMARY shift  51 */
  {  82,   0,  43}, /*  3:                    NOT shift  43 */
  { 133,   2,  42}, /*  4:                  ccons shift  42 */
  { 144,   0, 283}, /*  5:        defer_subclause shift  283 */
  { 185,   7, 282}, /*  6:             references shift  282 */
  {  95,   0, 286}, /*  7:             REFERENCES shift  286 */
  {  17,   0,  59}, /*  8:                  CHECK shift  59 */
  {  19,   0, 284}, /*  9:                COLLATE shift  284 */
  { 119,   9,  57}, /* 10:                 UNIQUE shift  57 */
/* State 43 */
  {  84,   2,  44}, /*  1:                   NULL shift  44 */
  {  30,   0,  46}, /*  2:             DEFERRABLE shift  46 */
/* State 44 */
  { 176,   0,  45}, /*  1:                 onconf shift  45 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 46 */
  {  63,   0,  48}, /*  1:              INITIALLY shift  48 */
  { 161,   1,  47}, /*  2: init_deferred_pred_opt shift  47 */
/* State 48 */
  {  60,   0,  50}, /*  1:              IMMEDIATE shift  50 */
  {  31,   0,  49}, /*  2:               DEFERRED shift  49 */
/* State 51 */
  {  72,   0,  52}, /*  1:                    KEY shift  52 */
/* State 52 */
  { 195,   0,  53}, /*  1:              sortorder shift  53 */
  {  34,   3,  56}, /*  2:                   DESC shift  56 */
  {   7,   0,  55}, /*  3:                    ASC shift  55 */
/* State 53 */
  { 176,   0,  54}, /*  1:                 onconf shift  54 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 57 */
  { 176,   0,  58}, /*  1:                 onconf shift  58 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 59 */
  {  76,   0,  60}, /*  1:                     LP shift  60 */
/* State 60 */
  { 150,   0, 279}, /*  1:                   expr shift  279 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 61 */
  {  76,   0,  62}, /*  1:                     LP shift  62 */
/* State 62 */
  { 108,   0, 277}, /*  1:                   STAR shift  277 */
  {  91,   0, 169}, /*  2:                   PLUS shift  169 */
  { 110,   0,  64}, /*  3:                 STRING shift  64 */
  {  57,   0,  61}, /*  4:                     ID shift  61 */
  {  94,   6, 181}, /*  5:                  RAISE shift  181 */
  {  76,   0,  65}, /*  6:                     LP shift  65 */
  { 150,   0, 162}, /*  7:                   expr shift  162 */
  { 151,   0, 207}, /*  8:               expritem shift  207 */
  { 152,  10, 275}, /*  9:               exprlist shift  275 */
  {  80,   0, 167}, /* 10:                  MINUS shift  167 */
  {  82,  12, 163}, /* 11:                    NOT shift  163 */
  {  46,   0, 101}, /* 12:                  FLOAT shift  101 */
  {  84,  16,  96}, /* 13:                   NULL shift  96 */
  { 157,   0,  63}, /* 14:                     id shift  63 */
  { 158,   0,  97}, /* 15:                    ids shift  97 */
  {  66,  18, 100}, /* 16:                INTEGER shift  100 */
  {  16,   0, 171}, /* 17:                   CASE shift  171 */
  {  12,   0, 165}, /* 18:                 BITNOT shift  165 */
/* State 63 */
  {  36,   0, 544}, /*  1:                    DOT reduce 25 */
/* State 64 */
  {  36,   0, 545}, /*  1:                    DOT reduce 26 */
/* State 65 */
  {  76,   0,  65}, /*  1:                     LP shift  65 */
  {  91,   0, 169}, /*  2:                   PLUS shift  169 */
  { 110,   0,  64}, /*  3:                 STRING shift  64 */
  {  57,   0,  61}, /*  4:                     ID shift  61 */
  {  94,   1, 181}, /*  5:                  RAISE shift  181 */
  {  46,   0, 101}, /*  6:                  FLOAT shift  101 */
  { 150,   0, 273}, /*  7:                   expr shift  273 */
  {  66,  12, 100}, /*  8:                INTEGER shift  100 */
  {  80,   0, 167}, /*  9:                  MINUS shift  167 */
  { 189,   0,  67}, /* 10:                 select shift  67 */
  {  82,   6, 163}, /* 11:                    NOT shift  163 */
  {  12,   0, 165}, /* 12:                 BITNOT shift  165 */
  {  84,   8,  96}, /* 13:                   NULL shift  96 */
  { 157,  18,  63}, /* 14:                     id shift  63 */
  { 158,   0,  97}, /* 15:                    ids shift  97 */
  { 177,   0,  66}, /* 16:              oneselect shift  66 */
  {  16,   0, 171}, /* 17:                   CASE shift  171 */
  { 103,   0,  70}, /* 18:                 SELECT shift  70 */
/* State 67 */
  { 118,   5, 157}, /*  1:                  UNION shift  157 */
  { 101,   0, 272}, /*  2:                     RP shift  272 */
  {  67,   0, 159}, /*  3:              INTERSECT shift  159 */
  { 173,   1,  68}, /*  4:         multiselect_op shift  68 */
  {  43,   0, 160}, /*  5:                 EXCEPT shift  160 */
/* State 68 */
  { 103,   0,  70}, /*  1:                 SELECT shift  70 */
  { 177,   1,  69}, /*  2:              oneselect shift  69 */
/* State 70 */
  {  35,   0, 270}, /*  1:               DISTINCT shift  270 */
  {   4,   0, 271}, /*  2:                    ALL shift  271 */
  { 146,   1,  71}, /*  3:               distinct shift  71 */
/* State 71 */
  { 188,   0,  72}, /*  1:             selcollist shift  72 */
  { 187,   0, 263}, /*  2:                   sclp shift  263 */
/* State 72 */
  {  21,   0, 228}, /*  1:                  COMMA shift  228 */
  { 154,   3,  73}, /*  2:                   from shift  73 */
  {  49,   0, 229}, /*  3:                   FROM shift  229 */
/* State 73 */
  { 126,   0, 226}, /*  1:                  WHERE shift  226 */
  { 209,   0,  74}, /*  2:              where_opt shift  74 */
/* State 74 */
  {  54,   0, 223}, /*  1:                  GROUP shift  223 */
  { 155,   0,  75}, /*  2:            groupby_opt shift  75 */
/* State 75 */
  { 156,   2,  76}, /*  1:             having_opt shift  76 */
  {  56,   0, 221}, /*  2:                 HAVING shift  221 */
/* State 76 */
  {  89,   0,  85}, /*  1:                  ORDER shift  85 */
  { 179,   1,  77}, /*  2:            orderby_opt shift  77 */
/* State 77 */
  { 170,   0,  78}, /*  1:              limit_opt shift  78 */
  {  75,   0,  79}, /*  2:                  LIMIT shift  79 */
/* State 79 */
  {  66,   0,  80}, /*  1:                INTEGER shift  80 */
/* State 80 */
  { 171,   2,  81}, /*  1:              limit_sep shift  81 */
  {  21,   0,  84}, /*  2:                  COMMA shift  84 */
  {  86,   0,  83}, /*  3:                 OFFSET shift  83 */
/* State 81 */
  {  66,   0,  82}, /*  1:                INTEGER shift  82 */
/* State 83 */
  {  66,   0, 666}, /*  1:                INTEGER reduce 147 */
/* State 84 */
  {  66,   0, 667}, /*  1:                INTEGER reduce 148 */
/* State 85 */
  {  14,   0,  86}, /*  1:                     BY shift  86 */
/* State 86 */
  {  91,   2, 169}, /*  1:                   PLUS shift  169 */
  {  57,   0,  61}, /*  2:                     ID shift  61 */
  {  76,   0,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  { 157,   0,  63}, /*  5:                     id shift  63 */
  { 158,   0,  97}, /*  6:                    ids shift  97 */
  { 193,   1, 219}, /*  7:               sortitem shift  219 */
  { 194,   0,  87}, /*  8:               sortlist shift  87 */
  { 110,   3,  64}, /*  9:                 STRING shift  64 */
  {  94,   0, 181}, /* 10:                  RAISE shift  181 */
  {  12,   0, 165}, /* 11:                 BITNOT shift  165 */
  {  82,   0, 163}, /* 12:                    NOT shift  163 */
  {  80,   4, 167}, /* 13:                  MINUS shift  167 */
  {  16,   0, 171}, /* 14:                   CASE shift  171 */
  { 150,  12,  94}, /* 15:                   expr shift  94 */
  {  66,   0, 100}, /* 16:                INTEGER shift  100 */
  {  84,  14,  96}, /* 17:                   NULL shift  96 */
/* State 87 */
  {  21,   0,  88}, /*  1:                  COMMA shift  88 */
/* State 88 */
  {  80,   4, 167}, /*  1:                  MINUS shift  167 */
  { 193,   0,  89}, /*  2:               sortitem shift  89 */
  {  82,   6, 163}, /*  3:                    NOT shift  163 */
  {  16,   0, 171}, /*  4:                   CASE shift  171 */
  {  84,   0,  96}, /*  5:                   NULL shift  96 */
  {  66,   0, 100}, /*  6:                INTEGER shift  100 */
  { 150,   0,  94}, /*  7:                   expr shift  94 */
  {  12,   0, 165}, /*  8:                 BITNOT shift  165 */
  { 110,  11,  64}, /*  9:                 STRING shift  64 */
  {  57,   0,  61}, /* 10:                     ID shift  61 */
  {  94,  16, 181}, /* 11:                  RAISE shift  181 */
  {  91,   0, 169}, /* 12:                   PLUS shift  169 */
  {  76,   8,  65}, /* 13:                     LP shift  65 */
  { 157,   0,  63}, /* 14:                     id shift  63 */
  { 158,   9,  97}, /* 15:                    ids shift  97 */
  {  46,   0, 101}, /* 16:                  FLOAT shift  101 */
/* State 89 */
  { 136,   0,  90}, /*  1:                collate shift  90 */
  {  19,   0,  92}, /*  2:                COLLATE shift  92 */
/* State 90 */
  { 195,   0,  91}, /*  1:              sortorder shift  91 */
  {  34,   3,  56}, /*  2:                   DESC shift  56 */
  {   7,   0,  55}, /*  3:                    ASC shift  55 */
/* State 92 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  93}, /*  2:                     id shift  93 */
/* State 94 */
  { 108,   4, 136}, /*  1:                   STAR shift  136 */
  {  82,   5, 127}, /*  2:                    NOT shift  127 */
  {  83,   0, 149}, /*  3:                NOTNULL shift  149 */
  {  81,   0, 113}, /*  4:                     NE shift  113 */
  {  55,   0, 107}, /*  5:                     GT shift  107 */
  {   5,   0,  95}, /*  6:                    AND shift  95 */
  {  88,   9, 103}, /*  7:                     OR shift  103 */
  { 169,   7, 125}, /*  8:                 likeop shift  125 */
  {  61,   0, 154}, /*  9:                     IN shift  154 */
  {  10,   0, 150}, /* 10:                BETWEEN shift  150 */
  {  91,  10, 132}, /* 11:                   PLUS shift  132 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  69,  15, 145}, /* 13:                     IS shift  145 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  42,   0, 115}, /* 15:                     EQ shift  115 */
  {  96,  13, 140}, /* 16:                    REM shift  140 */
  {  70,   0, 144}, /* 17:                 ISNULL shift  144 */
  {  24,   0, 142}, /* 18:                 CONCAT shift  142 */
  {  52,   0, 111}, /* 19:                     GE shift  111 */
  {  73,   0, 109}, /* 20:                     LE shift  109 */
  {  74,   0, 130}, /* 21:                   LIKE shift  130 */
  { 102,   0, 123}, /* 22:                 RSHIFT shift  123 */
  {  53,   0, 131}, /* 23:                   GLOB shift  131 */
  {  77,   0, 121}, /* 24:                 LSHIFT shift  121 */
  {  78,  18, 105}, /* 25:                     LT shift  105 */
  { 106,  19, 138}, /* 26:                  SLASH shift  138 */
  {  80,  23, 134}, /* 27:                  MINUS shift  134 */
/* State 95 */
  { 150,   0, 102}, /*  1:                   expr shift  102 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 97 */
  {  36,   0,  98}, /*  1:                    DOT shift  98 */
/* State 98 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4,  99}, /*  3:                    ids shift  99 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 102 */
  {  77,   2, 121}, /*  1:                 LSHIFT shift  121 */
  {  52,   0, 111}, /*  2:                     GE shift  111 */
  { 102,   1, 123}, /*  3:                 RSHIFT shift  123 */
  {  78,   5, 105}, /*  4:                     LT shift  105 */
  {  53,   0, 131}, /*  5:                   GLOB shift  131 */
  {  80,  10, 134}, /*  6:                  MINUS shift  134 */
  { 106,  13, 138}, /*  7:                  SLASH shift  138 */
  {  82,   0, 127}, /*  8:                    NOT shift  127 */
  { 108,  15, 136}, /*  9:                   STAR shift  136 */
  {  55,   0, 107}, /* 10:                     GT shift  107 */
  {  10,   0, 150}, /* 11:                BETWEEN shift  150 */
  {  61,  16, 154}, /* 12:                     IN shift  154 */
  {  81,   0, 113}, /* 13:                     NE shift  113 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  83,   0, 149}, /* 15:                NOTNULL shift  149 */
  {  11,   0, 117}, /* 16:                 BITAND shift  117 */
  {  91,   0, 132}, /* 17:                   PLUS shift  132 */
  {  42,   0, 115}, /* 18:                     EQ shift  115 */
  {  69,   0, 145}, /* 19:                     IS shift  145 */
  { 169,  19, 125}, /* 20:                 likeop shift  125 */
  {  70,   0, 144}, /* 21:                 ISNULL shift  144 */
  {  96,   0, 140}, /* 22:                    REM shift  140 */
  {  24,   0, 142}, /* 23:                 CONCAT shift  142 */
  {  73,   0, 109}, /* 24:                     LE shift  109 */
  {  74,  23, 130}, /* 25:                   LIKE shift  130 */
/* State 103 */
  { 150,   0, 104}, /*  1:                   expr shift  104 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 104 */
  {  78,   7, 105}, /*  1:                     LT shift  105 */
  {  53,   0, 131}, /*  2:                   GLOB shift  131 */
  { 106,   8, 138}, /*  3:                  SLASH shift  138 */
  {  81,   9, 113}, /*  4:                     NE shift  113 */
  { 108,  13, 136}, /*  5:                   STAR shift  136 */
  {  83,  15, 149}, /*  6:                NOTNULL shift  149 */
  {  52,   0, 111}, /*  7:                     GE shift  111 */
  {  80,   0, 134}, /*  8:                  MINUS shift  134 */
  {  55,   0, 107}, /*  9:                     GT shift  107 */
  {  61,   0, 154}, /* 10:                     IN shift  154 */
  {  10,   0, 150}, /* 11:                BETWEEN shift  150 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  82,   0, 127}, /* 13:                    NOT shift  127 */
  { 169,  16, 125}, /* 14:                 likeop shift  125 */
  {   5,   0,  95}, /* 15:                    AND shift  95 */
  {  91,  20, 132}, /* 16:                   PLUS shift  132 */
  {  42,   0, 115}, /* 17:                     EQ shift  115 */
  {  69,   0, 145}, /* 18:                     IS shift  145 */
  {  96,  21, 140}, /* 19:                    REM shift  140 */
  {  13,   0, 119}, /* 20:                  BITOR shift  119 */
  {  70,   0, 144}, /* 21:                 ISNULL shift  144 */
  {  73,   0, 109}, /* 22:                     LE shift  109 */
  {  74,   0, 130}, /* 23:                   LIKE shift  130 */
  {  24,   0, 142}, /* 24:                 CONCAT shift  142 */
  { 102,  24, 123}, /* 25:                 RSHIFT shift  123 */
  {  77,   0, 121}, /* 26:                 LSHIFT shift  121 */
/* State 105 */
  { 150,   0, 106}, /*  1:                   expr shift  106 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 106 */
  {  77,   2, 121}, /*  1:                 LSHIFT shift  121 */
  {  11,   0, 117}, /*  2:                 BITAND shift  117 */
  {  24,   6, 142}, /*  3:                 CONCAT shift  142 */
  { 102,   7, 123}, /*  4:                 RSHIFT shift  123 */
  { 169,   0, 125}, /*  5:                 likeop shift  125 */
  {  13,   0, 119}, /*  6:                  BITOR shift  119 */
  {  91,  11, 132}, /*  7:                   PLUS shift  132 */
  { 106,   0, 138}, /*  8:                  SLASH shift  138 */
  {  96,   0, 140}, /*  9:                    REM shift  140 */
  { 108,   0, 136}, /* 10:                   STAR shift  136 */
  {  80,   0, 134}, /* 11:                  MINUS shift  134 */
/* State 107 */
  { 150,   0, 108}, /*  1:                   expr shift  108 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 108 */
  {  77,   2, 121}, /*  1:                 LSHIFT shift  121 */
  {  11,   0, 117}, /*  2:                 BITAND shift  117 */
  {  24,   6, 142}, /*  3:                 CONCAT shift  142 */
  { 102,   7, 123}, /*  4:                 RSHIFT shift  123 */
  { 169,   0, 125}, /*  5:                 likeop shift  125 */
  {  13,   0, 119}, /*  6:                  BITOR shift  119 */
  {  91,  11, 132}, /*  7:                   PLUS shift  132 */
  { 106,   0, 138}, /*  8:                  SLASH shift  138 */
  {  96,   0, 140}, /*  9:                    REM shift  140 */
  { 108,   0, 136}, /* 10:                   STAR shift  136 */
  {  80,   0, 134}, /* 11:                  MINUS shift  134 */
/* State 109 */
  { 150,   0, 110}, /*  1:                   expr shift  110 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 110 */
  {  77,   2, 121}, /*  1:                 LSHIFT shift  121 */
  {  11,   0, 117}, /*  2:                 BITAND shift  117 */
  {  24,   6, 142}, /*  3:                 CONCAT shift  142 */
  { 102,   7, 123}, /*  4:                 RSHIFT shift  123 */
  { 169,   0, 125}, /*  5:                 likeop shift  125 */
  {  13,   0, 119}, /*  6:                  BITOR shift  119 */
  {  91,  11, 132}, /*  7:                   PLUS shift  132 */
  { 106,   0, 138}, /*  8:                  SLASH shift  138 */
  {  96,   0, 140}, /*  9:                    REM shift  140 */
  { 108,   0, 136}, /* 10:                   STAR shift  136 */
  {  80,   0, 134}, /* 11:                  MINUS shift  134 */
/* State 111 */
  { 150,   0, 112}, /*  1:                   expr shift  112 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 112 */
  {  77,   2, 121}, /*  1:                 LSHIFT shift  121 */
  {  11,   0, 117}, /*  2:                 BITAND shift  117 */
  {  24,   6, 142}, /*  3:                 CONCAT shift  142 */
  { 102,   7, 123}, /*  4:                 RSHIFT shift  123 */
  { 169,   0, 125}, /*  5:                 likeop shift  125 */
  {  13,   0, 119}, /*  6:                  BITOR shift  119 */
  {  91,  11, 132}, /*  7:                   PLUS shift  132 */
  { 106,   0, 138}, /*  8:                  SLASH shift  138 */
  {  96,   0, 140}, /*  9:                    REM shift  140 */
  { 108,   0, 136}, /* 10:                   STAR shift  136 */
  {  80,   0, 134}, /* 11:                  MINUS shift  134 */
/* State 113 */
  { 150,   0, 114}, /*  1:                   expr shift  114 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 114 */
  {  91,   0, 132}, /*  1:                   PLUS shift  132 */
  { 106,   1, 138}, /*  2:                  SLASH shift  138 */
  {  77,   0, 121}, /*  3:                 LSHIFT shift  121 */
  { 108,   9, 136}, /*  4:                   STAR shift  136 */
  { 169,   0, 125}, /*  5:                 likeop shift  125 */
  {  80,   0, 134}, /*  6:                  MINUS shift  134 */
  {  96,   0, 140}, /*  7:                    REM shift  140 */
  {  52,   0, 111}, /*  8:                     GE shift  111 */
  {  78,   0, 105}, /*  9:                     LT shift  105 */
  {  24,   0, 142}, /* 10:                 CONCAT shift  142 */
  {  55,   0, 107}, /* 11:                     GT shift  107 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  { 102,   0, 123}, /* 13:                 RSHIFT shift  123 */
  {  73,  15, 109}, /* 14:                     LE shift  109 */
  {  13,   0, 119}, /* 15:                  BITOR shift  119 */
/* State 115 */
  { 150,   0, 116}, /*  1:                   expr shift  116 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 116 */
  {  91,   0, 132}, /*  1:                   PLUS shift  132 */
  { 106,   1, 138}, /*  2:                  SLASH shift  138 */
  {  77,   0, 121}, /*  3:                 LSHIFT shift  121 */
  { 108,   9, 136}, /*  4:                   STAR shift  136 */
  { 169,   0, 125}, /*  5:                 likeop shift  125 */
  {  80,   0, 134}, /*  6:                  MINUS shift  134 */
  {  96,   0, 140}, /*  7:                    REM shift  140 */
  {  52,   0, 111}, /*  8:                     GE shift  111 */
  {  78,   0, 105}, /*  9:                     LT shift  105 */
  {  24,   0, 142}, /* 10:                 CONCAT shift  142 */
  {  55,   0, 107}, /* 11:                     GT shift  107 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  { 102,   0, 123}, /* 13:                 RSHIFT shift  123 */
  {  73,  15, 109}, /* 14:                     LE shift  109 */
  {  13,   0, 119}, /* 15:                  BITOR shift  119 */
/* State 117 */
  { 150,   0, 118}, /*  1:                   expr shift  118 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 118 */
  {  91,   0, 132}, /*  1:                   PLUS shift  132 */
  { 169,   3, 125}, /*  2:                 likeop shift  125 */
  { 106,   0, 138}, /*  3:                  SLASH shift  138 */
  { 108,   5, 136}, /*  4:                   STAR shift  136 */
  {  80,   7, 134}, /*  5:                  MINUS shift  134 */
  {  96,   0, 140}, /*  6:                    REM shift  140 */
  {  24,   0, 142}, /*  7:                 CONCAT shift  142 */
/* State 119 */
  { 150,   0, 120}, /*  1:                   expr shift  120 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 120 */
  {  91,   0, 132}, /*  1:                   PLUS shift  132 */
  { 169,   3, 125}, /*  2:                 likeop shift  125 */
  { 106,   0, 138}, /*  3:                  SLASH shift  138 */
  { 108,   5, 136}, /*  4:                   STAR shift  136 */
  {  80,   7, 134}, /*  5:                  MINUS shift  134 */
  {  96,   0, 140}, /*  6:                    REM shift  140 */
  {  24,   0, 142}, /*  7:                 CONCAT shift  142 */
/* State 121 */
  { 150,   0, 122}, /*  1:                   expr shift  122 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 122 */
  {  91,   0, 132}, /*  1:                   PLUS shift  132 */
  { 169,   3, 125}, /*  2:                 likeop shift  125 */
  { 106,   0, 138}, /*  3:                  SLASH shift  138 */
  { 108,   5, 136}, /*  4:                   STAR shift  136 */
  {  80,   7, 134}, /*  5:                  MINUS shift  134 */
  {  96,   0, 140}, /*  6:                    REM shift  140 */
  {  24,   0, 142}, /*  7:                 CONCAT shift  142 */
/* State 123 */
  { 150,   0, 124}, /*  1:                   expr shift  124 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 124 */
  {  91,   0, 132}, /*  1:                   PLUS shift  132 */
  { 169,   3, 125}, /*  2:                 likeop shift  125 */
  { 106,   0, 138}, /*  3:                  SLASH shift  138 */
  { 108,   5, 136}, /*  4:                   STAR shift  136 */
  {  80,   7, 134}, /*  5:                  MINUS shift  134 */
  {  96,   0, 140}, /*  6:                    REM shift  140 */
  {  24,   0, 142}, /*  7:                 CONCAT shift  142 */
/* State 125 */
  { 150,   0, 126}, /*  1:                   expr shift  126 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 126 */
  {  91,   0, 132}, /*  1:                   PLUS shift  132 */
  { 106,   1, 138}, /*  2:                  SLASH shift  138 */
  {  77,   0, 121}, /*  3:                 LSHIFT shift  121 */
  { 108,   9, 136}, /*  4:                   STAR shift  136 */
  { 169,   0, 125}, /*  5:                 likeop shift  125 */
  {  80,   0, 134}, /*  6:                  MINUS shift  134 */
  {  96,   0, 140}, /*  7:                    REM shift  140 */
  {  52,   0, 111}, /*  8:                     GE shift  111 */
  {  78,   0, 105}, /*  9:                     LT shift  105 */
  {  24,   0, 142}, /* 10:                 CONCAT shift  142 */
  {  55,   0, 107}, /* 11:                     GT shift  107 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  { 102,   0, 123}, /* 13:                 RSHIFT shift  123 */
  {  73,  15, 109}, /* 14:                     LE shift  109 */
  {  13,   0, 119}, /* 15:                  BITOR shift  119 */
/* State 127 */
  {  84,   0, 208}, /*  1:                   NULL shift  208 */
  { 169,   4, 128}, /*  2:                 likeop shift  128 */
  {  74,   0, 130}, /*  3:                   LIKE shift  130 */
  {  61,   0, 213}, /*  4:                     IN shift  213 */
  {  10,   0, 209}, /*  5:                BETWEEN shift  209 */
  {  53,   0, 131}, /*  6:                   GLOB shift  131 */
/* State 128 */
  { 150,   0, 129}, /*  1:                   expr shift  129 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 129 */
  {  91,   0, 132}, /*  1:                   PLUS shift  132 */
  { 106,   1, 138}, /*  2:                  SLASH shift  138 */
  {  77,   0, 121}, /*  3:                 LSHIFT shift  121 */
  { 108,   9, 136}, /*  4:                   STAR shift  136 */
  { 169,   0, 125}, /*  5:                 likeop shift  125 */
  {  80,   0, 134}, /*  6:                  MINUS shift  134 */
  {  96,   0, 140}, /*  7:                    REM shift  140 */
  {  52,   0, 111}, /*  8:                     GE shift  111 */
  {  78,   0, 105}, /*  9:                     LT shift  105 */
  {  24,   0, 142}, /* 10:                 CONCAT shift  142 */
  {  55,   0, 107}, /* 11:                     GT shift  107 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  { 102,   0, 123}, /* 13:                 RSHIFT shift  123 */
  {  73,  15, 109}, /* 14:                     LE shift  109 */
  {  13,   0, 119}, /* 15:                  BITOR shift  119 */
/* State 132 */
  { 150,   0, 133}, /*  1:                   expr shift  133 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 133 */
  {  96,   0, 140}, /*  1:                    REM shift  140 */
  { 106,   1, 138}, /*  2:                  SLASH shift  138 */
  {  24,   0, 142}, /*  3:                 CONCAT shift  142 */
  { 108,   0, 136}, /*  4:                   STAR shift  136 */
  { 169,   3, 125}, /*  5:                 likeop shift  125 */
/* State 134 */
  { 150,   0, 135}, /*  1:                   expr shift  135 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 135 */
  {  96,   0, 140}, /*  1:                    REM shift  140 */
  { 106,   1, 138}, /*  2:                  SLASH shift  138 */
  {  24,   0, 142}, /*  3:                 CONCAT shift  142 */
  { 108,   0, 136}, /*  4:                   STAR shift  136 */
  { 169,   3, 125}, /*  5:                 likeop shift  125 */
/* State 136 */
  { 150,   0, 137}, /*  1:                   expr shift  137 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 137 */
  {  24,   0, 142}, /*  1:                 CONCAT shift  142 */
  { 169,   0, 125}, /*  2:                 likeop shift  125 */
/* State 138 */
  { 150,   0, 139}, /*  1:                   expr shift  139 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 139 */
  {  24,   0, 142}, /*  1:                 CONCAT shift  142 */
  { 169,   0, 125}, /*  2:                 likeop shift  125 */
/* State 140 */
  { 150,   0, 141}, /*  1:                   expr shift  141 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 141 */
  {  24,   0, 142}, /*  1:                 CONCAT shift  142 */
  { 169,   0, 125}, /*  2:                 likeop shift  125 */
/* State 142 */
  { 150,   0, 143}, /*  1:                   expr shift  143 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 143 */
  { 169,   0, 125}, /*  1:                 likeop shift  125 */
/* State 145 */
  {  84,   2, 146}, /*  1:                   NULL shift  146 */
  {  82,   0, 147}, /*  2:                    NOT shift  147 */
/* State 147 */
  {  84,   0, 148}, /*  1:                   NULL shift  148 */
/* State 150 */
  { 150,   0, 151}, /*  1:                   expr shift  151 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 151 */
  { 108,   4, 136}, /*  1:                   STAR shift  136 */
  {  82,   5, 127}, /*  2:                    NOT shift  127 */
  {  83,   0, 149}, /*  3:                NOTNULL shift  149 */
  {  81,   0, 113}, /*  4:                     NE shift  113 */
  {  55,   0, 107}, /*  5:                     GT shift  107 */
  {   5,   0, 152}, /*  6:                    AND shift  152 */
  {  88,   9, 103}, /*  7:                     OR shift  103 */
  { 169,   7, 125}, /*  8:                 likeop shift  125 */
  {  61,   0, 154}, /*  9:                     IN shift  154 */
  {  10,   0, 150}, /* 10:                BETWEEN shift  150 */
  {  91,  10, 132}, /* 11:                   PLUS shift  132 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  69,  15, 145}, /* 13:                     IS shift  145 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  42,   0, 115}, /* 15:                     EQ shift  115 */
  {  96,  13, 140}, /* 16:                    REM shift  140 */
  {  70,   0, 144}, /* 17:                 ISNULL shift  144 */
  {  24,   0, 142}, /* 18:                 CONCAT shift  142 */
  {  52,   0, 111}, /* 19:                     GE shift  111 */
  {  73,   0, 109}, /* 20:                     LE shift  109 */
  {  74,   0, 130}, /* 21:                   LIKE shift  130 */
  { 102,   0, 123}, /* 22:                 RSHIFT shift  123 */
  {  53,   0, 131}, /* 23:                   GLOB shift  131 */
  {  77,   0, 121}, /* 24:                 LSHIFT shift  121 */
  {  78,  18, 105}, /* 25:                     LT shift  105 */
  { 106,  19, 138}, /* 26:                  SLASH shift  138 */
  {  80,  23, 134}, /* 27:                  MINUS shift  134 */
/* State 152 */
  { 150,   0, 153}, /*  1:                   expr shift  153 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 153 */
  {  91,   0, 132}, /*  1:                   PLUS shift  132 */
  { 106,   1, 138}, /*  2:                  SLASH shift  138 */
  {  77,   0, 121}, /*  3:                 LSHIFT shift  121 */
  { 108,   9, 136}, /*  4:                   STAR shift  136 */
  { 169,   0, 125}, /*  5:                 likeop shift  125 */
  {  80,   0, 134}, /*  6:                  MINUS shift  134 */
  {  96,   0, 140}, /*  7:                    REM shift  140 */
  {  52,   0, 111}, /*  8:                     GE shift  111 */
  {  78,   0, 105}, /*  9:                     LT shift  105 */
  {  24,   0, 142}, /* 10:                 CONCAT shift  142 */
  {  55,   0, 107}, /* 11:                     GT shift  107 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  { 102,   0, 123}, /* 13:                 RSHIFT shift  123 */
  {  73,  15, 109}, /* 14:                     LE shift  109 */
  {  13,   0, 119}, /* 15:                  BITOR shift  119 */
/* State 154 */
  {  76,   0, 155}, /*  1:                     LP shift  155 */
/* State 155 */
  {  80,   0, 167}, /*  1:                  MINUS shift  167 */
  {  46,   0, 101}, /*  2:                  FLOAT shift  101 */
  {  82,   0, 163}, /*  3:                    NOT shift  163 */
  { 103,   0,  70}, /*  4:                 SELECT shift  70 */
  {  84,   0,  96}, /*  5:                   NULL shift  96 */
  { 110,   0,  64}, /*  6:                 STRING shift  64 */
  {  66,   2, 100}, /*  7:                INTEGER shift  100 */
  {  91,   0, 169}, /*  8:                   PLUS shift  169 */
  {  12,   0, 165}, /*  9:                 BITNOT shift  165 */
  { 189,   0, 156}, /* 10:                 select shift  156 */
  { 150,   6, 162}, /* 11:                   expr shift  162 */
  { 151,   8, 207}, /* 12:               expritem shift  207 */
  { 152,   9, 203}, /* 13:               exprlist shift  203 */
  {  16,   0, 171}, /* 14:                   CASE shift  171 */
  {  94,   0, 181}, /* 15:                  RAISE shift  181 */
  { 157,  20,  63}, /* 16:                     id shift  63 */
  {  76,  14,  65}, /* 17:                     LP shift  65 */
  { 177,  16,  66}, /* 18:              oneselect shift  66 */
  { 158,   0,  97}, /* 19:                    ids shift  97 */
  {  57,   0,  61}, /* 20:                     ID shift  61 */
/* State 156 */
  { 118,   5, 157}, /*  1:                  UNION shift  157 */
  { 101,   0, 161}, /*  2:                     RP shift  161 */
  {  67,   0, 159}, /*  3:              INTERSECT shift  159 */
  { 173,   1,  68}, /*  4:         multiselect_op shift  68 */
  {  43,   0, 160}, /*  5:                 EXCEPT shift  160 */
/* State 157 */
  {   4,   0, 158}, /*  1:                    ALL shift  158 */
  { 103,   0, 619}, /*  2:                 SELECT reduce 100 */
/* State 158 */
  { 103,   0, 620}, /*  1:                 SELECT reduce 101 */
/* State 159 */
  { 103,   0, 621}, /*  1:                 SELECT reduce 102 */
/* State 160 */
  { 103,   0, 622}, /*  1:                 SELECT reduce 103 */
/* State 162 */
  { 108,   4, 136}, /*  1:                   STAR shift  136 */
  {  82,   5, 127}, /*  2:                    NOT shift  127 */
  {  83,   0, 149}, /*  3:                NOTNULL shift  149 */
  {  81,   0, 113}, /*  4:                     NE shift  113 */
  {  55,   0, 107}, /*  5:                     GT shift  107 */
  {   5,   0,  95}, /*  6:                    AND shift  95 */
  {  88,   9, 103}, /*  7:                     OR shift  103 */
  { 169,   7, 125}, /*  8:                 likeop shift  125 */
  {  61,   0, 154}, /*  9:                     IN shift  154 */
  {  10,   0, 150}, /* 10:                BETWEEN shift  150 */
  {  91,  10, 132}, /* 11:                   PLUS shift  132 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  69,  15, 145}, /* 13:                     IS shift  145 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  42,   0, 115}, /* 15:                     EQ shift  115 */
  {  96,  13, 140}, /* 16:                    REM shift  140 */
  {  70,   0, 144}, /* 17:                 ISNULL shift  144 */
  {  24,   0, 142}, /* 18:                 CONCAT shift  142 */
  {  52,   0, 111}, /* 19:                     GE shift  111 */
  {  73,   0, 109}, /* 20:                     LE shift  109 */
  {  74,   0, 130}, /* 21:                   LIKE shift  130 */
  { 102,   0, 123}, /* 22:                 RSHIFT shift  123 */
  {  53,   0, 131}, /* 23:                   GLOB shift  131 */
  {  77,   0, 121}, /* 24:                 LSHIFT shift  121 */
  {  78,  18, 105}, /* 25:                     LT shift  105 */
  { 106,  19, 138}, /* 26:                  SLASH shift  138 */
  {  80,  23, 134}, /* 27:                  MINUS shift  134 */
/* State 163 */
  { 150,   0, 164}, /*  1:                   expr shift  164 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 164 */
  {  77,   2, 121}, /*  1:                 LSHIFT shift  121 */
  {  52,   0, 111}, /*  2:                     GE shift  111 */
  { 102,   1, 123}, /*  3:                 RSHIFT shift  123 */
  {  78,   5, 105}, /*  4:                     LT shift  105 */
  {  53,   0, 131}, /*  5:                   GLOB shift  131 */
  {  80,  10, 134}, /*  6:                  MINUS shift  134 */
  { 106,  13, 138}, /*  7:                  SLASH shift  138 */
  {  82,   0, 127}, /*  8:                    NOT shift  127 */
  { 108,  15, 136}, /*  9:                   STAR shift  136 */
  {  55,   0, 107}, /* 10:                     GT shift  107 */
  {  10,   0, 150}, /* 11:                BETWEEN shift  150 */
  {  61,  16, 154}, /* 12:                     IN shift  154 */
  {  81,   0, 113}, /* 13:                     NE shift  113 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  83,   0, 149}, /* 15:                NOTNULL shift  149 */
  {  11,   0, 117}, /* 16:                 BITAND shift  117 */
  {  91,   0, 132}, /* 17:                   PLUS shift  132 */
  {  42,   0, 115}, /* 18:                     EQ shift  115 */
  {  69,   0, 145}, /* 19:                     IS shift  145 */
  { 169,  19, 125}, /* 20:                 likeop shift  125 */
  {  70,   0, 144}, /* 21:                 ISNULL shift  144 */
  {  96,   0, 140}, /* 22:                    REM shift  140 */
  {  24,   0, 142}, /* 23:                 CONCAT shift  142 */
  {  73,   0, 109}, /* 24:                     LE shift  109 */
  {  74,  23, 130}, /* 25:                   LIKE shift  130 */
/* State 165 */
  { 150,   0, 166}, /*  1:                   expr shift  166 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 166 */
  { 169,   0, 125}, /*  1:                 likeop shift  125 */
/* State 167 */
  { 150,   0, 168}, /*  1:                   expr shift  168 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 168 */
  { 169,   0, 125}, /*  1:                 likeop shift  125 */
/* State 169 */
  { 150,   0, 170}, /*  1:                   expr shift  170 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 170 */
  { 169,   0, 125}, /*  1:                 likeop shift  125 */
/* State 171 */
  {  91,   2, 169}, /*  1:                   PLUS shift  169 */
  {  57,   0,  61}, /*  2:                     ID shift  61 */
  {  76,   0,  65}, /*  3:                     LP shift  65 */
  {  46,   8, 101}, /*  4:                  FLOAT shift  101 */
  { 157,   0,  63}, /*  5:                     id shift  63 */
  { 158,   0,  97}, /*  6:                    ids shift  97 */
  { 125,   1, 737}, /*  7:                   WHEN reduce 218 */
  {  12,   0, 165}, /*  8:                 BITNOT shift  165 */
  { 110,   3,  64}, /*  9:                 STRING shift  64 */
  {  94,   0, 181}, /* 10:                  RAISE shift  181 */
  {  82,   0, 163}, /* 11:                    NOT shift  163 */
  {  16,   0, 171}, /* 12:                   CASE shift  171 */
  {  80,   4, 167}, /* 13:                  MINUS shift  167 */
  { 132,   0, 173}, /* 14:           case_operand shift  173 */
  { 150,  11, 172}, /* 15:                   expr shift  172 */
  {  66,   0, 100}, /* 16:                INTEGER shift  100 */
  {  84,  12,  96}, /* 17:                   NULL shift  96 */
/* State 172 */
  {   5,   0,  95}, /*  1:                    AND shift  95 */
  { 169,   0, 125}, /*  2:                 likeop shift  125 */
  {  69,   4, 145}, /*  3:                     IS shift  145 */
  {  13,   0, 119}, /*  4:                  BITOR shift  119 */
  {  88,   0, 103}, /*  5:                     OR shift  103 */
  {  61,   1, 154}, /*  6:                     IN shift  154 */
  {  42,   0, 115}, /*  7:                     EQ shift  115 */
  {  91,   0, 132}, /*  8:                   PLUS shift  132 */
  {  74,   0, 130}, /*  9:                   LIKE shift  130 */
  {  78,   0, 105}, /* 10:                     LT shift  105 */
  {  10,   0, 150}, /* 11:                BETWEEN shift  150 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  96,   0, 140}, /* 13:                    REM shift  140 */
  { 125,   3, 736}, /* 14:                   WHEN reduce 217 */
  {  70,   7, 144}, /* 15:                 ISNULL shift  144 */
  {  80,  17, 134}, /* 16:                  MINUS shift  134 */
  {  52,  20, 111}, /* 17:                     GE shift  111 */
  {  73,   0, 109}, /* 18:                     LE shift  109 */
  { 102,   9, 123}, /* 19:                 RSHIFT shift  123 */
  {  24,   0, 142}, /* 20:                 CONCAT shift  142 */
  {  53,   0, 131}, /* 21:                   GLOB shift  131 */
  {  77,   0, 121}, /* 22:                 LSHIFT shift  121 */
  { 106,  10, 138}, /* 23:                  SLASH shift  138 */
  {  55,   0, 107}, /* 24:                     GT shift  107 */
  { 108,  16, 136}, /* 25:                   STAR shift  136 */
  {  81,  21, 113}, /* 26:                     NE shift  113 */
  {  82,   0, 127}, /* 27:                    NOT shift  127 */
  {  83,  24, 149}, /* 28:                NOTNULL shift  149 */
/* State 173 */
  { 125,   0, 199}, /*  1:                   WHEN shift  199 */
  { 131,   1, 174}, /*  2:          case_exprlist shift  174 */
/* State 174 */
  {  40,   0, 735}, /*  1:                    END reduce 216 */
  { 125,   0, 177}, /*  2:                   WHEN shift  177 */
  { 130,   0, 175}, /*  3:              case_else shift  175 */
  {  39,   0, 197}, /*  4:                   ELSE shift  197 */
/* State 175 */
  {  40,   0, 176}, /*  1:                    END shift  176 */
/* State 177 */
  { 150,   0, 178}, /*  1:                   expr shift  178 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 178 */
  { 113,   0, 179}, /*  1:                   THEN shift  179 */
  { 169,   1, 125}, /*  2:                 likeop shift  125 */
  {   5,   0,  95}, /*  3:                    AND shift  95 */
  {  13,   0, 119}, /*  4:                  BITOR shift  119 */
  {  88,   0, 103}, /*  5:                     OR shift  103 */
  {  61,   3, 154}, /*  6:                     IN shift  154 */
  {  42,   0, 115}, /*  7:                     EQ shift  115 */
  {  91,   0, 132}, /*  8:                   PLUS shift  132 */
  {  74,   0, 130}, /*  9:                   LIKE shift  130 */
  {  78,   0, 105}, /* 10:                     LT shift  105 */
  {  10,   0, 150}, /* 11:                BETWEEN shift  150 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  96,   0, 140}, /* 13:                    REM shift  140 */
  {  69,   4, 145}, /* 14:                     IS shift  145 */
  {  70,   7, 144}, /* 15:                 ISNULL shift  144 */
  {  80,  17, 134}, /* 16:                  MINUS shift  134 */
  {  52,  20, 111}, /* 17:                     GE shift  111 */
  {  73,   0, 109}, /* 18:                     LE shift  109 */
  { 102,   9, 123}, /* 19:                 RSHIFT shift  123 */
  {  24,   0, 142}, /* 20:                 CONCAT shift  142 */
  {  53,   0, 131}, /* 21:                   GLOB shift  131 */
  {  77,   0, 121}, /* 22:                 LSHIFT shift  121 */
  { 106,  10, 138}, /* 23:                  SLASH shift  138 */
  {  55,   0, 107}, /* 24:                     GT shift  107 */
  { 108,  16, 136}, /* 25:                   STAR shift  136 */
  {  81,  21, 113}, /* 26:                     NE shift  113 */
  {  82,   0, 127}, /* 27:                    NOT shift  127 */
  {  83,  24, 149}, /* 28:                NOTNULL shift  149 */
/* State 179 */
  { 150,   0, 180}, /*  1:                   expr shift  180 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 180 */
  { 108,   4, 136}, /*  1:                   STAR shift  136 */
  {  82,   5, 127}, /*  2:                    NOT shift  127 */
  {  83,   0, 149}, /*  3:                NOTNULL shift  149 */
  {  81,   0, 113}, /*  4:                     NE shift  113 */
  {  55,   0, 107}, /*  5:                     GT shift  107 */
  {   5,   0,  95}, /*  6:                    AND shift  95 */
  {  88,   9, 103}, /*  7:                     OR shift  103 */
  { 169,   7, 125}, /*  8:                 likeop shift  125 */
  {  61,   0, 154}, /*  9:                     IN shift  154 */
  {  10,   0, 150}, /* 10:                BETWEEN shift  150 */
  {  91,  10, 132}, /* 11:                   PLUS shift  132 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  69,  15, 145}, /* 13:                     IS shift  145 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  42,   0, 115}, /* 15:                     EQ shift  115 */
  {  96,  13, 140}, /* 16:                    REM shift  140 */
  {  70,   0, 144}, /* 17:                 ISNULL shift  144 */
  {  24,   0, 142}, /* 18:                 CONCAT shift  142 */
  {  52,   0, 111}, /* 19:                     GE shift  111 */
  {  73,   0, 109}, /* 20:                     LE shift  109 */
  {  74,   0, 130}, /* 21:                   LIKE shift  130 */
  { 102,   0, 123}, /* 22:                 RSHIFT shift  123 */
  {  53,   0, 131}, /* 23:                   GLOB shift  131 */
  {  77,   0, 121}, /* 24:                 LSHIFT shift  121 */
  {  78,  18, 105}, /* 25:                     LT shift  105 */
  { 106,  19, 138}, /* 26:                  SLASH shift  138 */
  {  80,  23, 134}, /* 27:                  MINUS shift  134 */
/* State 181 */
  {  76,   0, 182}, /*  1:                     LP shift  182 */
/* State 182 */
  {   1,   0, 189}, /*  1:                  ABORT shift  189 */
  {  45,   1, 193}, /*  2:                   FAIL shift  193 */
  {  58,   0, 183}, /*  3:                 IGNORE shift  183 */
  {  99,   0, 185}, /*  4:               ROLLBACK shift  185 */
/* State 183 */
  { 101,   0, 184}, /*  1:                     RP shift  184 */
/* State 185 */
  {  21,   0, 186}, /*  1:                  COMMA shift  186 */
/* State 186 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 187}, /*  3:                    ids shift  187 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 187 */
  { 101,   0, 188}, /*  1:                     RP shift  188 */
/* State 189 */
  {  21,   0, 190}, /*  1:                  COMMA shift  190 */
/* State 190 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 191}, /*  3:                    ids shift  191 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 191 */
  { 101,   0, 192}, /*  1:                     RP shift  192 */
/* State 193 */
  {  21,   0, 194}, /*  1:                  COMMA shift  194 */
/* State 194 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 195}, /*  3:                    ids shift  195 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 195 */
  { 101,   0, 196}, /*  1:                     RP shift  196 */
/* State 197 */
  { 150,   0, 198}, /*  1:                   expr shift  198 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 198 */
  {   5,   0,  95}, /*  1:                    AND shift  95 */
  { 169,   0, 125}, /*  2:                 likeop shift  125 */
  {  40,   0, 734}, /*  3:                    END reduce 215 */
  {  13,   0, 119}, /*  4:                  BITOR shift  119 */
  {  88,   0, 103}, /*  5:                     OR shift  103 */
  {  61,   1, 154}, /*  6:                     IN shift  154 */
  {  42,   0, 115}, /*  7:                     EQ shift  115 */
  {  91,   0, 132}, /*  8:                   PLUS shift  132 */
  {  74,   0, 130}, /*  9:                   LIKE shift  130 */
  {  78,   0, 105}, /* 10:                     LT shift  105 */
  {  10,   0, 150}, /* 11:                BETWEEN shift  150 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  96,   3, 140}, /* 13:                    REM shift  140 */
  {  69,   4, 145}, /* 14:                     IS shift  145 */
  {  70,   7, 144}, /* 15:                 ISNULL shift  144 */
  {  80,  17, 134}, /* 16:                  MINUS shift  134 */
  {  52,  20, 111}, /* 17:                     GE shift  111 */
  {  73,   0, 109}, /* 18:                     LE shift  109 */
  { 102,   9, 123}, /* 19:                 RSHIFT shift  123 */
  {  24,   0, 142}, /* 20:                 CONCAT shift  142 */
  {  53,   0, 131}, /* 21:                   GLOB shift  131 */
  {  77,   0, 121}, /* 22:                 LSHIFT shift  121 */
  { 106,  10, 138}, /* 23:                  SLASH shift  138 */
  {  55,   0, 107}, /* 24:                     GT shift  107 */
  { 108,  16, 136}, /* 25:                   STAR shift  136 */
  {  81,  21, 113}, /* 26:                     NE shift  113 */
  {  82,   0, 127}, /* 27:                    NOT shift  127 */
  {  83,  24, 149}, /* 28:                NOTNULL shift  149 */
/* State 199 */
  { 150,   0, 200}, /*  1:                   expr shift  200 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 200 */
  { 113,   0, 201}, /*  1:                   THEN shift  201 */
  { 169,   1, 125}, /*  2:                 likeop shift  125 */
  {   5,   0,  95}, /*  3:                    AND shift  95 */
  {  13,   0, 119}, /*  4:                  BITOR shift  119 */
  {  88,   0, 103}, /*  5:                     OR shift  103 */
  {  61,   3, 154}, /*  6:                     IN shift  154 */
  {  42,   0, 115}, /*  7:                     EQ shift  115 */
  {  91,   0, 132}, /*  8:                   PLUS shift  132 */
  {  74,   0, 130}, /*  9:                   LIKE shift  130 */
  {  78,   0, 105}, /* 10:                     LT shift  105 */
  {  10,   0, 150}, /* 11:                BETWEEN shift  150 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  96,   0, 140}, /* 13:                    REM shift  140 */
  {  69,   4, 145}, /* 14:                     IS shift  145 */
  {  70,   7, 144}, /* 15:                 ISNULL shift  144 */
  {  80,  17, 134}, /* 16:                  MINUS shift  134 */
  {  52,  20, 111}, /* 17:                     GE shift  111 */
  {  73,   0, 109}, /* 18:                     LE shift  109 */
  { 102,   9, 123}, /* 19:                 RSHIFT shift  123 */
  {  24,   0, 142}, /* 20:                 CONCAT shift  142 */
  {  53,   0, 131}, /* 21:                   GLOB shift  131 */
  {  77,   0, 121}, /* 22:                 LSHIFT shift  121 */
  { 106,  10, 138}, /* 23:                  SLASH shift  138 */
  {  55,   0, 107}, /* 24:                     GT shift  107 */
  { 108,  16, 136}, /* 25:                   STAR shift  136 */
  {  81,  21, 113}, /* 26:                     NE shift  113 */
  {  82,   0, 127}, /* 27:                    NOT shift  127 */
  {  83,  24, 149}, /* 28:                NOTNULL shift  149 */
/* State 201 */
  { 150,   0, 202}, /*  1:                   expr shift  202 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 202 */
  { 108,   4, 136}, /*  1:                   STAR shift  136 */
  {  82,   5, 127}, /*  2:                    NOT shift  127 */
  {  83,   0, 149}, /*  3:                NOTNULL shift  149 */
  {  81,   0, 113}, /*  4:                     NE shift  113 */
  {  55,   0, 107}, /*  5:                     GT shift  107 */
  {   5,   0,  95}, /*  6:                    AND shift  95 */
  {  88,   9, 103}, /*  7:                     OR shift  103 */
  { 169,   7, 125}, /*  8:                 likeop shift  125 */
  {  61,   0, 154}, /*  9:                     IN shift  154 */
  {  10,   0, 150}, /* 10:                BETWEEN shift  150 */
  {  91,  10, 132}, /* 11:                   PLUS shift  132 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  69,  15, 145}, /* 13:                     IS shift  145 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  42,   0, 115}, /* 15:                     EQ shift  115 */
  {  96,  13, 140}, /* 16:                    REM shift  140 */
  {  70,   0, 144}, /* 17:                 ISNULL shift  144 */
  {  24,   0, 142}, /* 18:                 CONCAT shift  142 */
  {  52,   0, 111}, /* 19:                     GE shift  111 */
  {  73,   0, 109}, /* 20:                     LE shift  109 */
  {  74,   0, 130}, /* 21:                   LIKE shift  130 */
  { 102,   0, 123}, /* 22:                 RSHIFT shift  123 */
  {  53,   0, 131}, /* 23:                   GLOB shift  131 */
  {  77,   0, 121}, /* 24:                 LSHIFT shift  121 */
  {  78,  18, 105}, /* 25:                     LT shift  105 */
  { 106,  19, 138}, /* 26:                  SLASH shift  138 */
  {  80,  23, 134}, /* 27:                  MINUS shift  134 */
/* State 203 */
  {  21,   0, 205}, /*  1:                  COMMA shift  205 */
  { 101,   1, 204}, /*  2:                     RP shift  204 */
/* State 205 */
  {  80,   2, 167}, /*  1:                  MINUS shift  167 */
  {  16,   0, 171}, /*  2:                   CASE shift  171 */
  {  82,   4, 163}, /*  3:                    NOT shift  163 */
  {  66,   0, 100}, /*  4:                INTEGER shift  100 */
  {  84,   0,  96}, /*  5:                   NULL shift  96 */
  {  12,   0, 165}, /*  6:                 BITNOT shift  165 */
  { 150,   0, 162}, /*  7:                   expr shift  162 */
  { 151,   0, 206}, /*  8:               expritem shift  206 */
  { 110,  11,  64}, /*  9:                 STRING shift  64 */
  {  57,   0,  61}, /* 10:                     ID shift  61 */
  {  94,  16, 181}, /* 11:                  RAISE shift  181 */
  {  91,   0, 169}, /* 12:                   PLUS shift  169 */
  {  76,   6,  65}, /* 13:                     LP shift  65 */
  { 157,   0,  63}, /* 14:                     id shift  63 */
  { 158,   9,  97}, /* 15:                    ids shift  97 */
  {  46,   0, 101}, /* 16:                  FLOAT shift  101 */
/* State 209 */
  { 150,   0, 210}, /*  1:                   expr shift  210 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 210 */
  { 108,   4, 136}, /*  1:                   STAR shift  136 */
  {  82,   5, 127}, /*  2:                    NOT shift  127 */
  {  83,   0, 149}, /*  3:                NOTNULL shift  149 */
  {  81,   0, 113}, /*  4:                     NE shift  113 */
  {  55,   0, 107}, /*  5:                     GT shift  107 */
  {   5,   0, 211}, /*  6:                    AND shift  211 */
  {  88,   9, 103}, /*  7:                     OR shift  103 */
  { 169,   7, 125}, /*  8:                 likeop shift  125 */
  {  61,   0, 154}, /*  9:                     IN shift  154 */
  {  10,   0, 150}, /* 10:                BETWEEN shift  150 */
  {  91,  10, 132}, /* 11:                   PLUS shift  132 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  69,  15, 145}, /* 13:                     IS shift  145 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  42,   0, 115}, /* 15:                     EQ shift  115 */
  {  96,  13, 140}, /* 16:                    REM shift  140 */
  {  70,   0, 144}, /* 17:                 ISNULL shift  144 */
  {  24,   0, 142}, /* 18:                 CONCAT shift  142 */
  {  52,   0, 111}, /* 19:                     GE shift  111 */
  {  73,   0, 109}, /* 20:                     LE shift  109 */
  {  74,   0, 130}, /* 21:                   LIKE shift  130 */
  { 102,   0, 123}, /* 22:                 RSHIFT shift  123 */
  {  53,   0, 131}, /* 23:                   GLOB shift  131 */
  {  77,   0, 121}, /* 24:                 LSHIFT shift  121 */
  {  78,  18, 105}, /* 25:                     LT shift  105 */
  { 106,  19, 138}, /* 26:                  SLASH shift  138 */
  {  80,  23, 134}, /* 27:                  MINUS shift  134 */
/* State 211 */
  { 150,   0, 212}, /*  1:                   expr shift  212 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 212 */
  {  77,   2, 121}, /*  1:                 LSHIFT shift  121 */
  {  52,   0, 111}, /*  2:                     GE shift  111 */
  { 102,   1, 123}, /*  3:                 RSHIFT shift  123 */
  {  78,   5, 105}, /*  4:                     LT shift  105 */
  {  53,   0, 131}, /*  5:                   GLOB shift  131 */
  {  80,  10, 134}, /*  6:                  MINUS shift  134 */
  { 106,  13, 138}, /*  7:                  SLASH shift  138 */
  {  82,   0, 127}, /*  8:                    NOT shift  127 */
  { 108,  15, 136}, /*  9:                   STAR shift  136 */
  {  55,   0, 107}, /* 10:                     GT shift  107 */
  {  10,   0, 150}, /* 11:                BETWEEN shift  150 */
  {  61,  16, 154}, /* 12:                     IN shift  154 */
  {  81,   0, 113}, /* 13:                     NE shift  113 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  83,   0, 149}, /* 15:                NOTNULL shift  149 */
  {  11,   0, 117}, /* 16:                 BITAND shift  117 */
  {  91,   0, 132}, /* 17:                   PLUS shift  132 */
  {  42,   0, 115}, /* 18:                     EQ shift  115 */
  {  69,   0, 145}, /* 19:                     IS shift  145 */
  { 169,  19, 125}, /* 20:                 likeop shift  125 */
  {  70,   0, 144}, /* 21:                 ISNULL shift  144 */
  {  96,   0, 140}, /* 22:                    REM shift  140 */
  {  24,   0, 142}, /* 23:                 CONCAT shift  142 */
  {  73,   0, 109}, /* 24:                     LE shift  109 */
  {  74,  23, 130}, /* 25:                   LIKE shift  130 */
/* State 213 */
  {  76,   0, 214}, /*  1:                     LP shift  214 */
/* State 214 */
  {  80,   0, 167}, /*  1:                  MINUS shift  167 */
  {  46,   0, 101}, /*  2:                  FLOAT shift  101 */
  {  82,   0, 163}, /*  3:                    NOT shift  163 */
  { 103,   0,  70}, /*  4:                 SELECT shift  70 */
  {  84,   0,  96}, /*  5:                   NULL shift  96 */
  { 110,   0,  64}, /*  6:                 STRING shift  64 */
  {  66,   2, 100}, /*  7:                INTEGER shift  100 */
  {  91,   0, 169}, /*  8:                   PLUS shift  169 */
  {  12,   0, 165}, /*  9:                 BITNOT shift  165 */
  { 189,   0, 215}, /* 10:                 select shift  215 */
  { 150,   6, 162}, /* 11:                   expr shift  162 */
  { 151,   8, 207}, /* 12:               expritem shift  207 */
  { 152,   9, 217}, /* 13:               exprlist shift  217 */
  {  16,   0, 171}, /* 14:                   CASE shift  171 */
  {  94,   0, 181}, /* 15:                  RAISE shift  181 */
  { 157,  20,  63}, /* 16:                     id shift  63 */
  {  76,  14,  65}, /* 17:                     LP shift  65 */
  { 177,  16,  66}, /* 18:              oneselect shift  66 */
  { 158,   0,  97}, /* 19:                    ids shift  97 */
  {  57,   0,  61}, /* 20:                     ID shift  61 */
/* State 215 */
  { 118,   5, 157}, /*  1:                  UNION shift  157 */
  { 101,   0, 216}, /*  2:                     RP shift  216 */
  {  67,   0, 159}, /*  3:              INTERSECT shift  159 */
  { 173,   1,  68}, /*  4:         multiselect_op shift  68 */
  {  43,   0, 160}, /*  5:                 EXCEPT shift  160 */
/* State 217 */
  {  21,   0, 205}, /*  1:                  COMMA shift  205 */
  { 101,   1, 218}, /*  2:                     RP shift  218 */
/* State 219 */
  { 195,   0, 220}, /*  1:              sortorder shift  220 */
  {  34,   3,  56}, /*  2:                   DESC shift  56 */
  {   7,   0,  55}, /*  3:                    ASC shift  55 */
/* State 221 */
  { 150,   0, 222}, /*  1:                   expr shift  222 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 222 */
  { 108,   4, 136}, /*  1:                   STAR shift  136 */
  {  82,   5, 127}, /*  2:                    NOT shift  127 */
  {  83,   0, 149}, /*  3:                NOTNULL shift  149 */
  {  81,   0, 113}, /*  4:                     NE shift  113 */
  {  55,   0, 107}, /*  5:                     GT shift  107 */
  {   5,   0,  95}, /*  6:                    AND shift  95 */
  {  88,   9, 103}, /*  7:                     OR shift  103 */
  { 169,   7, 125}, /*  8:                 likeop shift  125 */
  {  61,   0, 154}, /*  9:                     IN shift  154 */
  {  10,   0, 150}, /* 10:                BETWEEN shift  150 */
  {  91,  10, 132}, /* 11:                   PLUS shift  132 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  69,  15, 145}, /* 13:                     IS shift  145 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  42,   0, 115}, /* 15:                     EQ shift  115 */
  {  96,  13, 140}, /* 16:                    REM shift  140 */
  {  70,   0, 144}, /* 17:                 ISNULL shift  144 */
  {  24,   0, 142}, /* 18:                 CONCAT shift  142 */
  {  52,   0, 111}, /* 19:                     GE shift  111 */
  {  73,   0, 109}, /* 20:                     LE shift  109 */
  {  74,   0, 130}, /* 21:                   LIKE shift  130 */
  { 102,   0, 123}, /* 22:                 RSHIFT shift  123 */
  {  53,   0, 131}, /* 23:                   GLOB shift  131 */
  {  77,   0, 121}, /* 24:                 LSHIFT shift  121 */
  {  78,  18, 105}, /* 25:                     LT shift  105 */
  { 106,  19, 138}, /* 26:                  SLASH shift  138 */
  {  80,  23, 134}, /* 27:                  MINUS shift  134 */
/* State 223 */
  {  14,   0, 224}, /*  1:                     BY shift  224 */
/* State 224 */
  {  57,   0,  61}, /*  1:                     ID shift  61 */
  {  76,   0,  65}, /*  2:                     LP shift  65 */
  {  46,   4, 101}, /*  3:                  FLOAT shift  101 */
  {  12,   0, 165}, /*  4:                 BITNOT shift  165 */
  { 157,   0,  63}, /*  5:                     id shift  63 */
  { 158,   0,  97}, /*  6:                    ids shift  97 */
  {  91,   1, 169}, /*  7:                   PLUS shift  169 */
  {  82,   0, 163}, /*  8:                    NOT shift  163 */
  { 110,   2,  64}, /*  9:                 STRING shift  64 */
  {  94,   0, 181}, /* 10:                  RAISE shift  181 */
  {  66,   0, 100}, /* 11:                INTEGER shift  100 */
  {  84,  14,  96}, /* 12:                   NULL shift  96 */
  {  80,   3, 167}, /* 13:                  MINUS shift  167 */
  {  16,   0, 171}, /* 14:                   CASE shift  171 */
  { 150,   8, 162}, /* 15:                   expr shift  162 */
  { 151,  11, 207}, /* 16:               expritem shift  207 */
  { 152,  12, 225}, /* 17:               exprlist shift  225 */
/* State 225 */
  {  21,   0, 205}, /*  1:                  COMMA shift  205 */
/* State 226 */
  { 150,   0, 227}, /*  1:                   expr shift  227 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 227 */
  { 108,   4, 136}, /*  1:                   STAR shift  136 */
  {  82,   5, 127}, /*  2:                    NOT shift  127 */
  {  83,   0, 149}, /*  3:                NOTNULL shift  149 */
  {  81,   0, 113}, /*  4:                     NE shift  113 */
  {  55,   0, 107}, /*  5:                     GT shift  107 */
  {   5,   0,  95}, /*  6:                    AND shift  95 */
  {  88,   9, 103}, /*  7:                     OR shift  103 */
  { 169,   7, 125}, /*  8:                 likeop shift  125 */
  {  61,   0, 154}, /*  9:                     IN shift  154 */
  {  10,   0, 150}, /* 10:                BETWEEN shift  150 */
  {  91,  10, 132}, /* 11:                   PLUS shift  132 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  69,  15, 145}, /* 13:                     IS shift  145 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  42,   0, 115}, /* 15:                     EQ shift  115 */
  {  96,  13, 140}, /* 16:                    REM shift  140 */
  {  70,   0, 144}, /* 17:                 ISNULL shift  144 */
  {  24,   0, 142}, /* 18:                 CONCAT shift  142 */
  {  52,   0, 111}, /* 19:                     GE shift  111 */
  {  73,   0, 109}, /* 20:                     LE shift  109 */
  {  74,   0, 130}, /* 21:                   LIKE shift  130 */
  { 102,   0, 123}, /* 22:                 RSHIFT shift  123 */
  {  53,   0, 131}, /* 23:                   GLOB shift  131 */
  {  77,   0, 121}, /* 24:                 LSHIFT shift  121 */
  {  78,  18, 105}, /* 25:                     LT shift  105 */
  { 106,  19, 138}, /* 26:                  SLASH shift  138 */
  {  80,  23, 134}, /* 27:                  MINUS shift  134 */
/* State 229 */
  { 196,   2, 240}, /*  1:             stl_prefix shift  240 */
  { 190,   0, 230}, /*  2:             seltablist shift  230 */
/* State 230 */
  {  21,   0, 232}, /*  1:                  COMMA shift  232 */
  {  57,   1, 234}, /*  2:                     ID shift  234 */
  {  71,   0, 233}, /*  3:                   JOIN shift  233 */
  { 167,   3, 231}, /*  4:                 joinop shift  231 */
/* State 234 */
  {  57,   0, 236}, /*  1:                     ID shift  236 */
  {  71,   1, 235}, /*  2:                   JOIN shift  235 */
/* State 236 */
  {  57,   0, 238}, /*  1:                     ID shift  238 */
  {  71,   1, 237}, /*  2:                   JOIN shift  237 */
/* State 238 */
  {  71,   0, 239}, /*  1:                   JOIN shift  239 */
/* State 240 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  {  76,   0, 257}, /*  2:                     LP shift  257 */
  { 157,   5,  20}, /*  3:                     id shift  20 */
  { 158,   0, 241}, /*  4:                    ids shift  241 */
  {  57,   0,  19}, /*  5:                     ID shift  19 */
/* State 241 */
  {   6,   0, 242}, /*  1:                     AS shift  242 */
  { 127,   0, 244}, /*  2:                     as shift  244 */
/* State 242 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 243}, /*  3:                    ids shift  243 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 244 */
  {  87,   0, 255}, /*  1:                     ON shift  255 */
  { 175,   1, 245}, /*  2:                 on_opt shift  245 */
/* State 245 */
  { 121,   0, 247}, /*  1:                  USING shift  247 */
  { 207,   1, 246}, /*  2:              using_opt shift  246 */
/* State 247 */
  {  76,   0, 248}, /*  1:                     LP shift  248 */
/* State 248 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  { 157,   0,  20}, /*  2:                     id shift  20 */
  { 158,   1, 253}, /*  3:                    ids shift  253 */
  { 159,   6, 254}, /*  4:                idxitem shift  254 */
  { 160,   0, 249}, /*  5:                idxlist shift  249 */
  {  57,   0,  19}, /*  6:                     ID shift  19 */
/* State 249 */
  {  21,   0, 251}, /*  1:                  COMMA shift  251 */
  { 101,   1, 250}, /*  2:                     RP shift  250 */
/* State 251 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  {  57,   0,  19}, /*  2:                     ID shift  19 */
  { 157,   2,  20}, /*  3:                     id shift  20 */
  { 158,   0, 253}, /*  4:                    ids shift  253 */
  { 159,   0, 252}, /*  5:                idxitem shift  252 */
/* State 255 */
  { 150,   0, 256}, /*  1:                   expr shift  256 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 256 */
  { 108,   4, 136}, /*  1:                   STAR shift  136 */
  {  82,   5, 127}, /*  2:                    NOT shift  127 */
  {  83,   0, 149}, /*  3:                NOTNULL shift  149 */
  {  81,   0, 113}, /*  4:                     NE shift  113 */
  {  55,   0, 107}, /*  5:                     GT shift  107 */
  {   5,   0,  95}, /*  6:                    AND shift  95 */
  {  88,   9, 103}, /*  7:                     OR shift  103 */
  { 169,   7, 125}, /*  8:                 likeop shift  125 */
  {  61,   0, 154}, /*  9:                     IN shift  154 */
  {  10,   0, 150}, /* 10:                BETWEEN shift  150 */
  {  91,  10, 132}, /* 11:                   PLUS shift  132 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  69,  15, 145}, /* 13:                     IS shift  145 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  42,   0, 115}, /* 15:                     EQ shift  115 */
  {  96,  13, 140}, /* 16:                    REM shift  140 */
  {  70,   0, 144}, /* 17:                 ISNULL shift  144 */
  {  24,   0, 142}, /* 18:                 CONCAT shift  142 */
  {  52,   0, 111}, /* 19:                     GE shift  111 */
  {  73,   0, 109}, /* 20:                     LE shift  109 */
  {  74,   0, 130}, /* 21:                   LIKE shift  130 */
  { 102,   0, 123}, /* 22:                 RSHIFT shift  123 */
  {  53,   0, 131}, /* 23:                   GLOB shift  131 */
  {  77,   0, 121}, /* 24:                 LSHIFT shift  121 */
  {  78,  18, 105}, /* 25:                     LT shift  105 */
  { 106,  19, 138}, /* 26:                  SLASH shift  138 */
  {  80,  23, 134}, /* 27:                  MINUS shift  134 */
/* State 257 */
  { 189,   3, 258}, /*  1:                 select shift  258 */
  { 103,   0,  70}, /*  2:                 SELECT shift  70 */
  { 177,   0,  66}, /*  3:              oneselect shift  66 */
/* State 258 */
  { 118,   5, 157}, /*  1:                  UNION shift  157 */
  { 101,   0, 259}, /*  2:                     RP shift  259 */
  {  67,   0, 159}, /*  3:              INTERSECT shift  159 */
  { 173,   1,  68}, /*  4:         multiselect_op shift  68 */
  {  43,   0, 160}, /*  5:                 EXCEPT shift  160 */
/* State 259 */
  {   6,   0, 242}, /*  1:                     AS shift  242 */
  { 127,   0, 260}, /*  2:                     as shift  260 */
/* State 260 */
  {  87,   0, 255}, /*  1:                     ON shift  255 */
  { 175,   1, 261}, /*  2:                 on_opt shift  261 */
/* State 261 */
  { 121,   0, 247}, /*  1:                  USING shift  247 */
  { 207,   1, 262}, /*  2:              using_opt shift  262 */
/* State 263 */
  {  80,   2, 167}, /*  1:                  MINUS shift  167 */
  {  16,   0, 171}, /*  2:                   CASE shift  171 */
  {  82,   4, 163}, /*  3:                    NOT shift  163 */
  {  66,   0, 100}, /*  4:                INTEGER shift  100 */
  {  84,   0,  96}, /*  5:                   NULL shift  96 */
  {  76,   8,  65}, /*  6:                     LP shift  65 */
  { 150,   0, 264}, /*  7:                   expr shift  264 */
  {  12,   0, 165}, /*  8:                 BITNOT shift  165 */
  { 110,  11,  64}, /*  9:                 STRING shift  64 */
  {  57,   0,  61}, /* 10:                     ID shift  61 */
  {  94,  16, 181}, /* 11:                  RAISE shift  181 */
  {  91,   0, 169}, /* 12:                   PLUS shift  169 */
  { 108,   6, 266}, /* 13:                   STAR shift  266 */
  { 157,   0,  63}, /* 14:                     id shift  63 */
  { 158,   9, 267}, /* 15:                    ids shift  267 */
  {  46,   0, 101}, /* 16:                  FLOAT shift  101 */
/* State 264 */
  {  69,   3, 145}, /*  1:                     IS shift  145 */
  {  88,   0, 103}, /*  2:                     OR shift  103 */
  {  11,   0, 117}, /*  3:                 BITAND shift  117 */
  {  61,   0, 154}, /*  4:                     IN shift  154 */
  {  91,   0, 132}, /*  5:                   PLUS shift  132 */
  {   5,   0,  95}, /*  6:                    AND shift  95 */
  {   6,   0, 242}, /*  7:                     AS shift  242 */
  {  13,   0, 119}, /*  8:                  BITOR shift  119 */
  {  73,   0, 109}, /*  9:                     LE shift  109 */
  {  96,   0, 140}, /* 10:                    REM shift  140 */
  {  10,   0, 150}, /* 11:                BETWEEN shift  150 */
  { 127,   1, 265}, /* 12:                     as shift  265 */
  {  70,   0, 144}, /* 13:                 ISNULL shift  144 */
  {  42,   8, 115}, /* 14:                     EQ shift  115 */
  {  77,   0, 121}, /* 15:                 LSHIFT shift  121 */
  { 102,   9, 123}, /* 16:                 RSHIFT shift  123 */
  {  74,   0, 130}, /* 17:                   LIKE shift  130 */
  {  52,   0, 111}, /* 18:                     GE shift  111 */
  {  82,  28, 127}, /* 19:                    NOT shift  127 */
  { 106,  15, 138}, /* 20:                  SLASH shift  138 */
  {  78,   0, 105}, /* 21:                     LT shift  105 */
  { 108,   0, 136}, /* 22:                   STAR shift  136 */
  {  80,   0, 134}, /* 23:                  MINUS shift  134 */
  {  81,  18, 113}, /* 24:                     NE shift  113 */
  { 169,  19, 125}, /* 25:                 likeop shift  125 */
  {  83,   0, 149}, /* 26:                NOTNULL shift  149 */
  {  55,   0, 107}, /* 27:                     GT shift  107 */
  {  53,  29, 131}, /* 28:                   GLOB shift  131 */
  {  24,   0, 142}, /* 29:                 CONCAT shift  142 */
/* State 267 */
  {  36,   0, 268}, /*  1:                    DOT shift  268 */
/* State 268 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  {  57,   0,  19}, /*  2:                     ID shift  19 */
  { 157,   2,  20}, /*  3:                     id shift  20 */
  { 158,   5,  99}, /*  4:                    ids shift  99 */
  { 108,   0, 269}, /*  5:                   STAR shift  269 */
/* State 273 */
  {   5,   0,  95}, /*  1:                    AND shift  95 */
  { 169,   0, 125}, /*  2:                 likeop shift  125 */
  {  13,   0, 119}, /*  3:                  BITOR shift  119 */
  {  42,   0, 115}, /*  4:                     EQ shift  115 */
  {  88,   0, 103}, /*  5:                     OR shift  103 */
  {  61,   1, 154}, /*  6:                     IN shift  154 */
  {  73,   0, 109}, /*  7:                     LE shift  109 */
  {  91,   0, 132}, /*  8:                   PLUS shift  132 */
  {  74,   0, 130}, /*  9:                   LIKE shift  130 */
  {  78,   0, 105}, /* 10:                     LT shift  105 */
  {  10,   0, 150}, /* 11:                BETWEEN shift  150 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  96,   0, 140}, /* 13:                    REM shift  140 */
  {  69,   3, 145}, /* 14:                     IS shift  145 */
  {  70,   4, 144}, /* 15:                 ISNULL shift  144 */
  {  80,  17, 134}, /* 16:                  MINUS shift  134 */
  {  52,  20, 111}, /* 17:                     GE shift  111 */
  { 101,   7, 274}, /* 18:                     RP shift  274 */
  { 102,   9, 123}, /* 19:                 RSHIFT shift  123 */
  {  24,   0, 142}, /* 20:                 CONCAT shift  142 */
  {  53,   0, 131}, /* 21:                   GLOB shift  131 */
  {  77,   0, 121}, /* 22:                 LSHIFT shift  121 */
  { 106,  10, 138}, /* 23:                  SLASH shift  138 */
  {  55,   0, 107}, /* 24:                     GT shift  107 */
  { 108,  16, 136}, /* 25:                   STAR shift  136 */
  {  81,  21, 113}, /* 26:                     NE shift  113 */
  {  82,   0, 127}, /* 27:                    NOT shift  127 */
  {  83,  24, 149}, /* 28:                NOTNULL shift  149 */
/* State 275 */
  {  21,   0, 205}, /*  1:                  COMMA shift  205 */
  { 101,   1, 276}, /*  2:                     RP shift  276 */
/* State 277 */
  { 101,   0, 278}, /*  1:                     RP shift  278 */
/* State 279 */
  {   5,   0,  95}, /*  1:                    AND shift  95 */
  { 169,   0, 125}, /*  2:                 likeop shift  125 */
  {  13,   0, 119}, /*  3:                  BITOR shift  119 */
  {  42,   0, 115}, /*  4:                     EQ shift  115 */
  {  88,   0, 103}, /*  5:                     OR shift  103 */
  {  61,   1, 154}, /*  6:                     IN shift  154 */
  {  73,   0, 109}, /*  7:                     LE shift  109 */
  {  91,   0, 132}, /*  8:                   PLUS shift  132 */
  {  74,   0, 130}, /*  9:                   LIKE shift  130 */
  {  78,   0, 105}, /* 10:                     LT shift  105 */
  {  10,   0, 150}, /* 11:                BETWEEN shift  150 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  96,   0, 140}, /* 13:                    REM shift  140 */
  {  69,   3, 145}, /* 14:                     IS shift  145 */
  {  70,   4, 144}, /* 15:                 ISNULL shift  144 */
  {  80,  17, 134}, /* 16:                  MINUS shift  134 */
  {  52,  20, 111}, /* 17:                     GE shift  111 */
  { 101,   7, 280}, /* 18:                     RP shift  280 */
  { 102,   9, 123}, /* 19:                 RSHIFT shift  123 */
  {  24,   0, 142}, /* 20:                 CONCAT shift  142 */
  {  53,   0, 131}, /* 21:                   GLOB shift  131 */
  {  77,   0, 121}, /* 22:                 LSHIFT shift  121 */
  { 106,  10, 138}, /* 23:                  SLASH shift  138 */
  {  55,   0, 107}, /* 24:                     GT shift  107 */
  { 108,  16, 136}, /* 25:                   STAR shift  136 */
  {  81,  21, 113}, /* 26:                     NE shift  113 */
  {  82,   0, 127}, /* 27:                    NOT shift  127 */
  {  83,  24, 149}, /* 28:                NOTNULL shift  149 */
/* State 280 */
  { 176,   0, 281}, /*  1:                 onconf shift  281 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 284 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1, 285}, /*  2:                     id shift  285 */
/* State 286 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 287}, /*  3:                    ids shift  287 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 287 */
  { 184,   2, 306}, /*  1:                refargs shift  306 */
  {  76,   0, 288}, /*  2:                     LP shift  288 */
/* State 288 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  { 157,   0,  20}, /*  2:                     id shift  20 */
  { 158,   1, 253}, /*  3:                    ids shift  253 */
  { 159,   6, 254}, /*  4:                idxitem shift  254 */
  { 160,   0, 289}, /*  5:                idxlist shift  289 */
  {  57,   0,  19}, /*  6:                     ID shift  19 */
/* State 289 */
  {  21,   0, 251}, /*  1:                  COMMA shift  251 */
  { 101,   1, 290}, /*  2:                     RP shift  290 */
/* State 290 */
  { 184,   0, 291}, /*  1:                refargs shift  291 */
/* State 291 */
  { 183,   3, 292}, /*  1:                 refarg shift  292 */
  {  79,   0, 293}, /*  2:                  MATCH shift  293 */
  {  87,   0, 296}, /*  3:                     ON shift  296 */
/* State 293 */
  {  90,   2, 295}, /*  1:                PARTIAL shift  295 */
  {  50,   0, 294}, /*  2:                   FULL shift  294 */
/* State 296 */
  { 120,   2, 304}, /*  1:                 UPDATE shift  304 */
  {  32,   0, 297}, /*  2:                 DELETE shift  297 */
/* State 297 */
  {  98,   0, 303}, /*  1:               RESTRICT shift  303 */
  { 105,   0, 299}, /*  2:                    SET shift  299 */
  { 182,   1, 298}, /*  3:                 refact shift  298 */
  {  15,   0, 302}, /*  4:                CASCADE shift  302 */
/* State 299 */
  {  84,   0, 300}, /*  1:                   NULL shift  300 */
  {  29,   0, 301}, /*  2:                DEFAULT shift  301 */
/* State 304 */
  {  98,   0, 303}, /*  1:               RESTRICT shift  303 */
  { 105,   0, 299}, /*  2:                    SET shift  299 */
  { 182,   1, 305}, /*  3:                 refact shift  305 */
  {  15,   0, 302}, /*  4:                CASCADE shift  302 */
/* State 306 */
  { 183,   3, 292}, /*  1:                 refarg shift  292 */
  {  79,   0, 293}, /*  2:                  MATCH shift  293 */
  {  87,   0, 296}, /*  3:                     ON shift  296 */
/* State 307 */
  {  63,   0,  48}, /*  1:              INITIALLY shift  48 */
  { 161,   1, 308}, /*  2: init_deferred_pred_opt shift  308 */
/* State 310 */
  {  91,   3, 314}, /*  1:                   PLUS shift  314 */
  {  57,   0, 312}, /*  2:                     ID shift  312 */
  {  84,   0, 321}, /*  3:                   NULL shift  321 */
  {  80,   7, 317}, /*  4:                  MINUS shift  317 */
  {  46,   0, 320}, /*  5:                  FLOAT shift  320 */
  { 110,   0, 311}, /*  6:                 STRING shift  311 */
  {  66,   0, 313}, /*  7:                INTEGER shift  313 */
/* State 314 */
  {  66,   2, 315}, /*  1:                INTEGER shift  315 */
  {  46,   0, 316}, /*  2:                  FLOAT shift  316 */
/* State 317 */
  {  66,   2, 318}, /*  1:                INTEGER shift  318 */
  {  46,   0, 319}, /*  2:                  FLOAT shift  319 */
/* State 322 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  {  76,   0, 323}, /*  2:                     LP shift  323 */
  { 157,   5,  20}, /*  3:                     id shift  20 */
  { 158,   0, 334}, /*  4:                    ids shift  334 */
  {  57,   0,  19}, /*  5:                     ID shift  19 */
/* State 323 */
  { 192,   2, 324}, /*  1:                 signed shift  324 */
  {  80,   0, 332}, /*  2:                  MINUS shift  332 */
  {  66,   0, 329}, /*  3:                INTEGER shift  329 */
  {  91,   0, 330}, /*  4:                   PLUS shift  330 */
/* State 324 */
  {  21,   0, 326}, /*  1:                  COMMA shift  326 */
  { 101,   1, 325}, /*  2:                     RP shift  325 */
/* State 326 */
  { 192,   2, 327}, /*  1:                 signed shift  327 */
  {  80,   0, 332}, /*  2:                  MINUS shift  332 */
  {  66,   0, 329}, /*  3:                INTEGER shift  329 */
  {  91,   0, 330}, /*  4:                   PLUS shift  330 */
/* State 327 */
  { 101,   0, 328}, /*  1:                     RP shift  328 */
/* State 330 */
  {  66,   0, 331}, /*  1:                INTEGER shift  331 */
/* State 332 */
  {  66,   0, 333}, /*  1:                INTEGER shift  333 */
/* State 337 */
  {  48,   0, 356}, /*  1:                FOREIGN shift  356 */
  {  17,   0, 353}, /*  2:                  CHECK shift  353 */
  {  26,   0, 340}, /*  3:             CONSTRAINT shift  340 */
  { 101,   5, 593}, /*  4:                     RP reduce 74 */
  {  93,   7, 342}, /*  5:                PRIMARY shift  342 */
  { 197,   4, 365}, /*  6:                  tcons shift  365 */
  {  21,   0, 338}, /*  7:                  COMMA shift  338 */
  { 119,   0, 348}, /*  8:                 UNIQUE shift  348 */
/* State 338 */
  {  48,   0, 356}, /*  1:                FOREIGN shift  356 */
  { 119,   5, 348}, /*  2:                 UNIQUE shift  348 */
  {  26,   0, 340}, /*  3:             CONSTRAINT shift  340 */
  {  93,   0, 342}, /*  4:                PRIMARY shift  342 */
  {  17,   0, 353}, /*  5:                  CHECK shift  353 */
  { 197,   2, 339}, /*  6:                  tcons shift  339 */
/* State 340 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 341}, /*  3:                    ids shift  341 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 342 */
  {  72,   0, 343}, /*  1:                    KEY shift  343 */
/* State 343 */
  {  76,   0, 344}, /*  1:                     LP shift  344 */
/* State 344 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  { 157,   0,  20}, /*  2:                     id shift  20 */
  { 158,   1, 253}, /*  3:                    ids shift  253 */
  { 159,   6, 254}, /*  4:                idxitem shift  254 */
  { 160,   0, 345}, /*  5:                idxlist shift  345 */
  {  57,   0,  19}, /*  6:                     ID shift  19 */
/* State 345 */
  {  21,   0, 251}, /*  1:                  COMMA shift  251 */
  { 101,   1, 346}, /*  2:                     RP shift  346 */
/* State 346 */
  { 176,   0, 347}, /*  1:                 onconf shift  347 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 348 */
  {  76,   0, 349}, /*  1:                     LP shift  349 */
/* State 349 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  { 157,   0,  20}, /*  2:                     id shift  20 */
  { 158,   1, 253}, /*  3:                    ids shift  253 */
  { 159,   6, 254}, /*  4:                idxitem shift  254 */
  { 160,   0, 350}, /*  5:                idxlist shift  350 */
  {  57,   0,  19}, /*  6:                     ID shift  19 */
/* State 350 */
  {  21,   0, 251}, /*  1:                  COMMA shift  251 */
  { 101,   1, 351}, /*  2:                     RP shift  351 */
/* State 351 */
  { 176,   0, 352}, /*  1:                 onconf shift  352 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 353 */
  { 150,   0, 354}, /*  1:                   expr shift  354 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 354 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  {  88,   0, 103}, /*  2:                     OR shift  103 */
  { 176,   0, 355}, /*  3:                 onconf shift  355 */
  {  61,   0, 154}, /*  4:                     IN shift  154 */
  {  91,   0, 132}, /*  5:                   PLUS shift  132 */
  {   5,   0,  95}, /*  6:                    AND shift  95 */
  {  11,   0, 117}, /*  7:                 BITAND shift  117 */
  {  13,   0, 119}, /*  8:                  BITOR shift  119 */
  {  73,   0, 109}, /*  9:                     LE shift  109 */
  {  96,   0, 140}, /* 10:                    REM shift  140 */
  {  10,   0, 150}, /* 11:                BETWEEN shift  150 */
  {  69,   7, 145}, /* 12:                     IS shift  145 */
  {  70,   0, 144}, /* 13:                 ISNULL shift  144 */
  {  42,   8, 115}, /* 14:                     EQ shift  115 */
  {  77,   0, 121}, /* 15:                 LSHIFT shift  121 */
  { 102,   9, 123}, /* 16:                 RSHIFT shift  123 */
  {  74,   0, 130}, /* 17:                   LIKE shift  130 */
  {  52,   0, 111}, /* 18:                     GE shift  111 */
  {  82,  28, 127}, /* 19:                    NOT shift  127 */
  { 106,  15, 138}, /* 20:                  SLASH shift  138 */
  {  78,   0, 105}, /* 21:                     LT shift  105 */
  { 108,   0, 136}, /* 22:                   STAR shift  136 */
  {  80,   0, 134}, /* 23:                  MINUS shift  134 */
  {  81,  18, 113}, /* 24:                     NE shift  113 */
  { 169,  19, 125}, /* 25:                 likeop shift  125 */
  {  83,   0, 149}, /* 26:                NOTNULL shift  149 */
  {  55,   0, 107}, /* 27:                     GT shift  107 */
  {  53,  29, 131}, /* 28:                   GLOB shift  131 */
  {  24,   0, 142}, /* 29:                 CONCAT shift  142 */
/* State 356 */
  {  72,   0, 357}, /*  1:                    KEY shift  357 */
/* State 357 */
  {  76,   0, 358}, /*  1:                     LP shift  358 */
/* State 358 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  { 157,   0,  20}, /*  2:                     id shift  20 */
  { 158,   1, 253}, /*  3:                    ids shift  253 */
  { 159,   6, 254}, /*  4:                idxitem shift  254 */
  { 160,   0, 359}, /*  5:                idxlist shift  359 */
  {  57,   0,  19}, /*  6:                     ID shift  19 */
/* State 359 */
  {  21,   0, 251}, /*  1:                  COMMA shift  251 */
  { 101,   1, 360}, /*  2:                     RP shift  360 */
/* State 360 */
  {  95,   0, 286}, /*  1:             REFERENCES shift  286 */
  { 185,   1, 361}, /*  2:             references shift  361 */
/* State 361 */
  { 144,   0, 364}, /*  1:        defer_subclause shift  364 */
  { 145,   0, 363}, /*  2:    defer_subclause_opt shift  363 */
  {  82,   4, 362}, /*  3:                    NOT shift  362 */
  {  30,   0, 307}, /*  4:             DEFERRABLE shift  307 */
/* State 362 */
  {  30,   0,  46}, /*  1:             DEFERRABLE shift  46 */
/* State 368 */
  { 189,   3, 369}, /*  1:                 select shift  369 */
  { 103,   0,  70}, /*  2:                 SELECT shift  70 */
  { 177,   0,  66}, /*  3:              oneselect shift  66 */
/* State 369 */
  { 118,   2, 157}, /*  1:                  UNION shift  157 */
  {  43,   0, 160}, /*  2:                 EXCEPT shift  160 */
  {  67,   0, 159}, /*  3:              INTERSECT shift  159 */
  { 173,   1,  68}, /*  4:         multiselect_op shift  68 */
  { 104,   0, 538}, /*  5:                   SEMI reduce 19 */
/* State 370 */
  { 112,   0, 374}, /*  1:                   TEMP shift  374 */
  { 198,   3, 371}, /*  2:                   temp shift  371 */
  {  62,   0, 744}, /*  3:                  INDEX reduce 225 */
  { 115,   0, 389}, /*  4:                TRIGGER shift  389 */
  { 124,   0, 375}, /*  5:                   VIEW shift  375 */
  { 111,   0, 536}, /*  6:                  TABLE reduce 17 */
  { 206,   2, 379}, /*  7:             uniqueflag shift  379 */
  { 119,   6, 388}, /*  8:                 UNIQUE shift  388 */
/* State 371 */
  { 111,   0, 372}, /*  1:                  TABLE shift  372 */
/* State 372 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 373}, /*  3:                    ids shift  373 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 374 */
  { 111,   0, 535}, /*  1:                  TABLE reduce 16 */
/* State 375 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 376}, /*  3:                    ids shift  376 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 376 */
  {   6,   0, 377}, /*  1:                     AS shift  377 */
/* State 377 */
  { 189,   3, 378}, /*  1:                 select shift  378 */
  { 103,   0,  70}, /*  2:                 SELECT shift  70 */
  { 177,   0,  66}, /*  3:              oneselect shift  66 */
/* State 378 */
  { 118,   2, 157}, /*  1:                  UNION shift  157 */
  {  43,   0, 160}, /*  2:                 EXCEPT shift  160 */
  {  67,   0, 159}, /*  3:              INTERSECT shift  159 */
  { 173,   1,  68}, /*  4:         multiselect_op shift  68 */
  { 104,   0, 614}, /*  5:                   SEMI reduce 95 */
/* State 379 */
  {  62,   0, 380}, /*  1:                  INDEX shift  380 */
/* State 380 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 381}, /*  3:                    ids shift  381 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 381 */
  {  87,   0, 382}, /*  1:                     ON shift  382 */
/* State 382 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 383}, /*  3:                    ids shift  383 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 383 */
  {  76,   0, 384}, /*  1:                     LP shift  384 */
/* State 384 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  { 157,   0,  20}, /*  2:                     id shift  20 */
  { 158,   1, 253}, /*  3:                    ids shift  253 */
  { 159,   6, 254}, /*  4:                idxitem shift  254 */
  { 160,   0, 385}, /*  5:                idxlist shift  385 */
  {  57,   0,  19}, /*  6:                     ID shift  19 */
/* State 385 */
  {  21,   0, 251}, /*  1:                  COMMA shift  251 */
  { 101,   1, 386}, /*  2:                     RP shift  386 */
/* State 386 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 104,   0, 604}, /*  2:                   SEMI reduce 85 */
  { 176,   2, 387}, /*  3:                 onconf shift  387 */
/* State 387 */
  { 104,   0, 742}, /*  1:                   SEMI reduce 223 */
/* State 388 */
  {  62,   0, 743}, /*  1:                  INDEX reduce 224 */
/* State 389 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 390}, /*  3:                    ids shift  390 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 390 */
  {   8,   0, 453}, /*  1:                 BEFORE shift  453 */
  {  65,   0, 455}, /*  2:                INSTEAD shift  455 */
  {   2,   0, 454}, /*  3:                  AFTER shift  454 */
  { 203,   0, 391}, /*  4:           trigger_time shift  391 */
/* State 391 */
  { 120,   2, 450}, /*  1:                 UPDATE shift  450 */
  {  64,   4, 449}, /*  2:                 INSERT shift  449 */
  { 202,   0, 392}, /*  3:          trigger_event shift  392 */
  {  32,   0, 448}, /*  4:                 DELETE shift  448 */
/* State 392 */
  {  87,   0, 393}, /*  1:                     ON shift  393 */
/* State 393 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 394}, /*  3:                    ids shift  394 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 394 */
  {  47,   0, 444}, /*  1:                    FOR shift  444 */
  { 153,   1, 395}, /*  2:         foreach_clause shift  395 */
/* State 395 */
  {   9,   0, 777}, /*  1:                  BEGIN reduce 258 */
  { 208,   0, 396}, /*  2:            when_clause shift  396 */
  { 125,   0, 442}, /*  3:                   WHEN shift  442 */
/* State 396 */
  {   9,   0, 397}, /*  1:                  BEGIN shift  397 */
/* State 397 */
  { 189,   0, 398}, /*  1:                 select shift  398 */
  {  64,   0, 419}, /*  2:                 INSERT shift  419 */
  { 200,   0, 401}, /*  3:            trigger_cmd shift  401 */
  { 201,   8, 399}, /*  4:       trigger_cmd_list shift  399 */
  { 103,   9,  70}, /*  5:                 SELECT shift  70 */
  {  32,   0, 438}, /*  6:                 DELETE shift  438 */
  { 177,   0,  66}, /*  7:              oneselect shift  66 */
  { 120,   0, 404}, /*  8:                 UPDATE shift  404 */
  {  40,   0, 780}, /*  9:                    END reduce 261 */
/* State 398 */
  { 118,   2, 157}, /*  1:                  UNION shift  157 */
  {  43,   0, 160}, /*  2:                 EXCEPT shift  160 */
  {  67,   0, 159}, /*  3:              INTERSECT shift  159 */
  { 173,   1,  68}, /*  4:         multiselect_op shift  68 */
  { 104,   0, 785}, /*  5:                   SEMI reduce 266 */
/* State 399 */
  {  40,   0, 400}, /*  1:                    END shift  400 */
/* State 400 */
  { 104,   0, 765}, /*  1:                   SEMI reduce 246 */
/* State 401 */
  { 104,   0, 402}, /*  1:                   SEMI shift  402 */
/* State 402 */
  { 189,   0, 398}, /*  1:                 select shift  398 */
  {  64,   0, 419}, /*  2:                 INSERT shift  419 */
  { 200,   0, 401}, /*  3:            trigger_cmd shift  401 */
  { 201,   8, 403}, /*  4:       trigger_cmd_list shift  403 */
  { 103,   9,  70}, /*  5:                 SELECT shift  70 */
  {  32,   0, 438}, /*  6:                 DELETE shift  438 */
  { 177,   0,  66}, /*  7:              oneselect shift  66 */
  { 120,   0, 404}, /*  8:                 UPDATE shift  404 */
  {  40,   0, 780}, /*  9:                    END reduce 261 */
/* State 403 */
  {  40,   0, 779}, /*  1:                    END reduce 260 */
/* State 404 */
  { 178,   2, 407}, /*  1:                 orconf shift  407 */
  {  88,   0, 405}, /*  2:                     OR shift  405 */
/* State 405 */
  { 186,   0, 406}, /*  1:            resolvetype shift  406 */
  {  97,   3,  16}, /*  2:                REPLACE shift  16 */
  {   1,   0,  13}, /*  3:                  ABORT shift  13 */
  {  99,   6,  12}, /*  4:               ROLLBACK shift  12 */
  {  58,   0,  15}, /*  5:                 IGNORE shift  15 */
  {  45,   0,  14}, /*  6:                   FAIL shift  14 */
/* State 407 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 408}, /*  3:                    ids shift  408 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 408 */
  { 105,   0, 409}, /*  1:                    SET shift  409 */
/* State 409 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  { 191,   0, 410}, /*  2:                setlist shift  410 */
  { 157,   5,  20}, /*  3:                     id shift  20 */
  { 158,   0, 416}, /*  4:                    ids shift  416 */
  {  57,   0,  19}, /*  5:                     ID shift  19 */
/* State 410 */
  { 104,   0, 669}, /*  1:                   SEMI reduce 150 */
  { 209,   4, 415}, /*  2:              where_opt shift  415 */
  { 126,   0, 226}, /*  3:                  WHERE shift  226 */
  {  21,   0, 411}, /*  4:                  COMMA shift  411 */
/* State 411 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 412}, /*  3:                    ids shift  412 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 412 */
  {  42,   0, 413}, /*  1:                     EQ shift  413 */
/* State 413 */
  { 150,   0, 414}, /*  1:                   expr shift  414 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 414 */
  { 108,   4, 136}, /*  1:                   STAR shift  136 */
  {  82,   5, 127}, /*  2:                    NOT shift  127 */
  {  83,   0, 149}, /*  3:                NOTNULL shift  149 */
  {  81,   0, 113}, /*  4:                     NE shift  113 */
  {  55,   0, 107}, /*  5:                     GT shift  107 */
  {   5,   0,  95}, /*  6:                    AND shift  95 */
  {  88,   9, 103}, /*  7:                     OR shift  103 */
  { 169,   7, 125}, /*  8:                 likeop shift  125 */
  {  61,   0, 154}, /*  9:                     IN shift  154 */
  {  10,   0, 150}, /* 10:                BETWEEN shift  150 */
  {  91,  10, 132}, /* 11:                   PLUS shift  132 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  69,  15, 145}, /* 13:                     IS shift  145 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  42,   0, 115}, /* 15:                     EQ shift  115 */
  {  96,  13, 140}, /* 16:                    REM shift  140 */
  {  70,   0, 144}, /* 17:                 ISNULL shift  144 */
  {  24,   0, 142}, /* 18:                 CONCAT shift  142 */
  {  52,   0, 111}, /* 19:                     GE shift  111 */
  {  73,   0, 109}, /* 20:                     LE shift  109 */
  {  74,   0, 130}, /* 21:                   LIKE shift  130 */
  { 102,   0, 123}, /* 22:                 RSHIFT shift  123 */
  {  53,   0, 131}, /* 23:                   GLOB shift  131 */
  {  77,   0, 121}, /* 24:                 LSHIFT shift  121 */
  {  78,  18, 105}, /* 25:                     LT shift  105 */
  { 106,  19, 138}, /* 26:                  SLASH shift  138 */
  {  80,  23, 134}, /* 27:                  MINUS shift  134 */
/* State 415 */
  { 104,   0, 781}, /*  1:                   SEMI reduce 262 */
/* State 416 */
  {  42,   0, 417}, /*  1:                     EQ shift  417 */
/* State 417 */
  { 150,   0, 418}, /*  1:                   expr shift  418 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 418 */
  { 108,   4, 136}, /*  1:                   STAR shift  136 */
  {  82,   5, 127}, /*  2:                    NOT shift  127 */
  {  83,   0, 149}, /*  3:                NOTNULL shift  149 */
  {  81,   0, 113}, /*  4:                     NE shift  113 */
  {  55,   0, 107}, /*  5:                     GT shift  107 */
  {   5,   0,  95}, /*  6:                    AND shift  95 */
  {  88,   9, 103}, /*  7:                     OR shift  103 */
  { 169,   7, 125}, /*  8:                 likeop shift  125 */
  {  61,   0, 154}, /*  9:                     IN shift  154 */
  {  10,   0, 150}, /* 10:                BETWEEN shift  150 */
  {  91,  10, 132}, /* 11:                   PLUS shift  132 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  69,  15, 145}, /* 13:                     IS shift  145 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  42,   0, 115}, /* 15:                     EQ shift  115 */
  {  96,  13, 140}, /* 16:                    REM shift  140 */
  {  70,   0, 144}, /* 17:                 ISNULL shift  144 */
  {  24,   0, 142}, /* 18:                 CONCAT shift  142 */
  {  52,   0, 111}, /* 19:                     GE shift  111 */
  {  73,   0, 109}, /* 20:                     LE shift  109 */
  {  74,   0, 130}, /* 21:                   LIKE shift  130 */
  { 102,   0, 123}, /* 22:                 RSHIFT shift  123 */
  {  53,   0, 131}, /* 23:                   GLOB shift  131 */
  {  77,   0, 121}, /* 24:                 LSHIFT shift  121 */
  {  78,  18, 105}, /* 25:                     LT shift  105 */
  { 106,  19, 138}, /* 26:                  SLASH shift  138 */
  {  80,  23, 134}, /* 27:                  MINUS shift  134 */
/* State 419 */
  {  88,   0, 405}, /*  1:                     OR shift  405 */
  { 178,   1, 420}, /*  2:                 orconf shift  420 */
  {  68,   0, 606}, /*  3:                   INTO reduce 87 */
/* State 420 */
  {  68,   0, 421}, /*  1:                   INTO shift  421 */
/* State 421 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 422}, /*  3:                    ids shift  422 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 422 */
  { 164,   2, 429}, /*  1:         inscollist_opt shift  429 */
  {  76,   0, 423}, /*  2:                     LP shift  423 */
/* State 423 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  {  57,   0,  19}, /*  2:                     ID shift  19 */
  { 157,   2,  20}, /*  3:                     id shift  20 */
  { 163,   5, 424}, /*  4:             inscollist shift  424 */
  { 158,   0, 428}, /*  5:                    ids shift  428 */
/* State 424 */
  {  21,   0, 426}, /*  1:                  COMMA shift  426 */
  { 101,   1, 425}, /*  2:                     RP shift  425 */
/* State 426 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 427}, /*  3:                    ids shift  427 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 429 */
  { 177,   0,  66}, /*  1:              oneselect shift  66 */
  { 189,   1, 430}, /*  2:                 select shift  430 */
  { 103,   0,  70}, /*  3:                 SELECT shift  70 */
  { 123,   3, 431}, /*  4:                 VALUES shift  431 */
/* State 430 */
  { 118,   2, 157}, /*  1:                  UNION shift  157 */
  {  43,   0, 160}, /*  2:                 EXCEPT shift  160 */
  {  67,   0, 159}, /*  3:              INTERSECT shift  159 */
  { 173,   1,  68}, /*  4:         multiselect_op shift  68 */
  { 104,   0, 783}, /*  5:                   SEMI reduce 264 */
/* State 431 */
  {  76,   0, 432}, /*  1:                     LP shift  432 */
/* State 432 */
  {  80,   2, 167}, /*  1:                  MINUS shift  167 */
  {  16,   0, 171}, /*  2:                   CASE shift  171 */
  {  82,   4, 163}, /*  3:                    NOT shift  163 */
  {  66,   0, 100}, /*  4:                INTEGER shift  100 */
  {  84,   0,  96}, /*  5:                   NULL shift  96 */
  { 150,   0, 437}, /*  6:                   expr shift  437 */
  { 166,   6, 433}, /*  7:               itemlist shift  433 */
  {  12,   0, 165}, /*  8:                 BITNOT shift  165 */
  { 110,  11,  64}, /*  9:                 STRING shift  64 */
  {  57,   0,  61}, /* 10:                     ID shift  61 */
  {  94,  16, 181}, /* 11:                  RAISE shift  181 */
  {  91,   0, 169}, /* 12:                   PLUS shift  169 */
  {  76,   8,  65}, /* 13:                     LP shift  65 */
  { 157,   0,  63}, /* 14:                     id shift  63 */
  { 158,   9,  97}, /* 15:                    ids shift  97 */
  {  46,   0, 101}, /* 16:                  FLOAT shift  101 */
/* State 433 */
  {  21,   0, 434}, /*  1:                  COMMA shift  434 */
  { 101,   1, 436}, /*  2:                     RP shift  436 */
/* State 434 */
  { 150,   0, 435}, /*  1:                   expr shift  435 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 435 */
  { 108,   4, 136}, /*  1:                   STAR shift  136 */
  {  82,   5, 127}, /*  2:                    NOT shift  127 */
  {  83,   0, 149}, /*  3:                NOTNULL shift  149 */
  {  81,   0, 113}, /*  4:                     NE shift  113 */
  {  55,   0, 107}, /*  5:                     GT shift  107 */
  {   5,   0,  95}, /*  6:                    AND shift  95 */
  {  88,   9, 103}, /*  7:                     OR shift  103 */
  { 169,   7, 125}, /*  8:                 likeop shift  125 */
  {  61,   0, 154}, /*  9:                     IN shift  154 */
  {  10,   0, 150}, /* 10:                BETWEEN shift  150 */
  {  91,  10, 132}, /* 11:                   PLUS shift  132 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  69,  15, 145}, /* 13:                     IS shift  145 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  42,   0, 115}, /* 15:                     EQ shift  115 */
  {  96,  13, 140}, /* 16:                    REM shift  140 */
  {  70,   0, 144}, /* 17:                 ISNULL shift  144 */
  {  24,   0, 142}, /* 18:                 CONCAT shift  142 */
  {  52,   0, 111}, /* 19:                     GE shift  111 */
  {  73,   0, 109}, /* 20:                     LE shift  109 */
  {  74,   0, 130}, /* 21:                   LIKE shift  130 */
  { 102,   0, 123}, /* 22:                 RSHIFT shift  123 */
  {  53,   0, 131}, /* 23:                   GLOB shift  131 */
  {  77,   0, 121}, /* 24:                 LSHIFT shift  121 */
  {  78,  18, 105}, /* 25:                     LT shift  105 */
  { 106,  19, 138}, /* 26:                  SLASH shift  138 */
  {  80,  23, 134}, /* 27:                  MINUS shift  134 */
/* State 436 */
  { 104,   0, 782}, /*  1:                   SEMI reduce 263 */
/* State 437 */
  { 108,   4, 136}, /*  1:                   STAR shift  136 */
  {  82,   5, 127}, /*  2:                    NOT shift  127 */
  {  83,   0, 149}, /*  3:                NOTNULL shift  149 */
  {  81,   0, 113}, /*  4:                     NE shift  113 */
  {  55,   0, 107}, /*  5:                     GT shift  107 */
  {   5,   0,  95}, /*  6:                    AND shift  95 */
  {  88,   9, 103}, /*  7:                     OR shift  103 */
  { 169,   7, 125}, /*  8:                 likeop shift  125 */
  {  61,   0, 154}, /*  9:                     IN shift  154 */
  {  10,   0, 150}, /* 10:                BETWEEN shift  150 */
  {  91,  10, 132}, /* 11:                   PLUS shift  132 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  69,  15, 145}, /* 13:                     IS shift  145 */
  {  13,   0, 119}, /* 14:                  BITOR shift  119 */
  {  42,   0, 115}, /* 15:                     EQ shift  115 */
  {  96,  13, 140}, /* 16:                    REM shift  140 */
  {  70,   0, 144}, /* 17:                 ISNULL shift  144 */
  {  24,   0, 142}, /* 18:                 CONCAT shift  142 */
  {  52,   0, 111}, /* 19:                     GE shift  111 */
  {  73,   0, 109}, /* 20:                     LE shift  109 */
  {  74,   0, 130}, /* 21:                   LIKE shift  130 */
  { 102,   0, 123}, /* 22:                 RSHIFT shift  123 */
  {  53,   0, 131}, /* 23:                   GLOB shift  131 */
  {  77,   0, 121}, /* 24:                 LSHIFT shift  121 */
  {  78,  18, 105}, /* 25:                     LT shift  105 */
  { 106,  19, 138}, /* 26:                  SLASH shift  138 */
  {  80,  23, 134}, /* 27:                  MINUS shift  134 */
/* State 438 */
  {  49,   0, 439}, /*  1:                   FROM shift  439 */
/* State 439 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 440}, /*  3:                    ids shift  440 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 440 */
  { 126,   0, 226}, /*  1:                  WHERE shift  226 */
  { 104,   0, 669}, /*  2:                   SEMI reduce 150 */
  { 209,   2, 441}, /*  3:              where_opt shift  441 */
/* State 441 */
  { 104,   0, 784}, /*  1:                   SEMI reduce 265 */
/* State 442 */
  { 150,   0, 443}, /*  1:                   expr shift  443 */
  {  91,   3, 169}, /*  2:                   PLUS shift  169 */
  {  76,   4,  65}, /*  3:                     LP shift  65 */
  {  46,  11, 101}, /*  4:                  FLOAT shift  101 */
  {  94,   0, 181}, /*  5:                  RAISE shift  181 */
  { 110,  12,  64}, /*  6:                 STRING shift  64 */
  {  66,   0, 100}, /*  7:                INTEGER shift  100 */
  { 157,  14,  63}, /*  8:                     id shift  63 */
  { 158,   0,  97}, /*  9:                    ids shift  97 */
  {  84,   0,  96}, /* 10:                   NULL shift  96 */
  {  16,   0, 171}, /* 11:                   CASE shift  171 */
  {  80,   0, 167}, /* 12:                  MINUS shift  167 */
  {  57,  15,  61}, /* 13:                     ID shift  61 */
  {  82,   0, 163}, /* 14:                    NOT shift  163 */
  {  12,   0, 165}, /* 15:                 BITNOT shift  165 */
/* State 443 */
  {   5,   0,  95}, /*  1:                    AND shift  95 */
  { 169,   0, 125}, /*  2:                 likeop shift  125 */
  {  13,   0, 119}, /*  3:                  BITOR shift  119 */
  {  42,   0, 115}, /*  4:                     EQ shift  115 */
  {  88,   0, 103}, /*  5:                     OR shift  103 */
  {  61,   1, 154}, /*  6:                     IN shift  154 */
  {  74,   0, 130}, /*  7:                   LIKE shift  130 */
  {  91,   0, 132}, /*  8:                   PLUS shift  132 */
  {  78,   0, 105}, /*  9:                     LT shift  105 */
  {   9,   0, 778}, /* 10:                  BEGIN reduce 259 */
  {  10,   0, 150}, /* 11:                BETWEEN shift  150 */
  {  11,   0, 117}, /* 12:                 BITAND shift  117 */
  {  96,   0, 140}, /* 13:                    REM shift  140 */
  {  69,   3, 145}, /* 14:                     IS shift  145 */
  {  70,   4, 144}, /* 15:                 ISNULL shift  144 */
  {  80,  17, 134}, /* 16:                  MINUS shift  134 */
  {  52,  20, 111}, /* 17:                     GE shift  111 */
  {  73,   0, 109}, /* 18:                     LE shift  109 */
  { 102,   7, 123}, /* 19:                 RSHIFT shift  123 */
  {  24,   0, 142}, /* 20:                 CONCAT shift  142 */
  {  53,   0, 131}, /* 21:                   GLOB shift  131 */
  {  77,   0, 121}, /* 22:                 LSHIFT shift  121 */
  { 106,   9, 138}, /* 23:                  SLASH shift  138 */
  {  55,   0, 107}, /* 24:                     GT shift  107 */
  { 108,  16, 136}, /* 25:                   STAR shift  136 */
  {  81,  21, 113}, /* 26:                     NE shift  113 */
  {  82,   0, 127}, /* 27:                    NOT shift  127 */
  {  83,  24, 149}, /* 28:                NOTNULL shift  149 */
/* State 444 */
  {  38,   0, 445}, /*  1:                   EACH shift  445 */
/* State 445 */
  { 100,   0, 446}, /*  1:                    ROW shift  446 */
  { 109,   0, 447}, /*  2:              STATEMENT shift  447 */
/* State 448 */
  {  87,   0, 770}, /*  1:                     ON reduce 251 */
/* State 449 */
  {  87,   0, 771}, /*  1:                     ON reduce 252 */
/* State 450 */
  {  85,   0, 451}, /*  1:                     OF shift  451 */
  {  87,   1, 772}, /*  2:                     ON reduce 253 */
/* State 451 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  {  57,   0,  19}, /*  2:                     ID shift  19 */
  { 157,   2,  20}, /*  3:                     id shift  20 */
  { 163,   5, 452}, /*  4:             inscollist shift  452 */
  { 158,   0, 428}, /*  5:                    ids shift  428 */
/* State 452 */
  {  21,   0, 426}, /*  1:                  COMMA shift  426 */
  {  87,   1, 773}, /*  2:                     ON reduce 254 */
/* State 455 */
  {  85,   0, 456}, /*  1:                     OF shift  456 */
/* State 457 */
  { 124,   0, 460}, /*  1:                   VIEW shift  460 */
  { 111,   0, 458}, /*  2:                  TABLE shift  458 */
  {  62,   0, 462}, /*  3:                  INDEX shift  462 */
  { 115,   2, 464}, /*  4:                TRIGGER shift  464 */
/* State 458 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 459}, /*  3:                    ids shift  459 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 459 */
  { 104,   0, 613}, /*  1:                   SEMI reduce 94 */
/* State 460 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 461}, /*  3:                    ids shift  461 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 461 */
  { 104,   0, 615}, /*  1:                   SEMI reduce 96 */
/* State 462 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 463}, /*  3:                    ids shift  463 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 463 */
  { 104,   0, 748}, /*  1:                   SEMI reduce 229 */
/* State 464 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 465}, /*  3:                    ids shift  465 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 465 */
  { 104,   0, 790}, /*  1:                   SEMI reduce 271 */
/* State 466 */
  { 118,   2, 157}, /*  1:                  UNION shift  157 */
  {  43,   0, 160}, /*  2:                 EXCEPT shift  160 */
  {  67,   0, 159}, /*  3:              INTERSECT shift  159 */
  { 173,   1,  68}, /*  4:         multiselect_op shift  68 */
  { 104,   0, 616}, /*  5:                   SEMI reduce 97 */
/* State 467 */
  {  49,   0, 468}, /*  1:                   FROM shift  468 */
/* State 468 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 469}, /*  3:                    ids shift  469 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 469 */
  { 126,   0, 226}, /*  1:                  WHERE shift  226 */
  { 104,   0, 669}, /*  2:                   SEMI reduce 150 */
  { 209,   2, 470}, /*  3:              where_opt shift  470 */
/* State 470 */
  { 104,   0, 668}, /*  1:                   SEMI reduce 149 */
/* State 471 */
  { 178,   2, 472}, /*  1:                 orconf shift  472 */
  {  88,   0, 405}, /*  2:                     OR shift  405 */
/* State 472 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 473}, /*  3:                    ids shift  473 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 473 */
  { 105,   0, 474}, /*  1:                    SET shift  474 */
/* State 474 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  { 191,   0, 475}, /*  2:                setlist shift  475 */
  { 157,   5,  20}, /*  3:                     id shift  20 */
  { 158,   0, 416}, /*  4:                    ids shift  416 */
  {  57,   0,  19}, /*  5:                     ID shift  19 */
/* State 475 */
  { 104,   0, 669}, /*  1:                   SEMI reduce 150 */
  { 209,   4, 476}, /*  2:              where_opt shift  476 */
  { 126,   0, 226}, /*  3:                  WHERE shift  226 */
  {  21,   0, 411}, /*  4:                  COMMA shift  411 */
/* State 476 */
  { 104,   0, 671}, /*  1:                   SEMI reduce 152 */
/* State 477 */
  {  68,   0, 478}, /*  1:                   INTO shift  478 */
/* State 478 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 479}, /*  3:                    ids shift  479 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 479 */
  { 164,   2, 480}, /*  1:         inscollist_opt shift  480 */
  {  76,   0, 423}, /*  2:                     LP shift  423 */
/* State 480 */
  { 177,   0,  66}, /*  1:              oneselect shift  66 */
  { 189,   1, 481}, /*  2:                 select shift  481 */
  { 103,   0,  70}, /*  3:                 SELECT shift  70 */
  { 123,   3, 482}, /*  4:                 VALUES shift  482 */
/* State 481 */
  { 118,   2, 157}, /*  1:                  UNION shift  157 */
  {  43,   0, 160}, /*  2:                 EXCEPT shift  160 */
  {  67,   0, 159}, /*  3:              INTERSECT shift  159 */
  { 173,   1,  68}, /*  4:         multiselect_op shift  68 */
  { 104,   0, 675}, /*  5:                   SEMI reduce 156 */
/* State 482 */
  {  76,   0, 483}, /*  1:                     LP shift  483 */
/* State 483 */
  {  80,   2, 167}, /*  1:                  MINUS shift  167 */
  {  16,   0, 171}, /*  2:                   CASE shift  171 */
  {  82,   4, 163}, /*  3:                    NOT shift  163 */
  {  66,   0, 100}, /*  4:                INTEGER shift  100 */
  {  84,   0,  96}, /*  5:                   NULL shift  96 */
  { 150,   0, 437}, /*  6:                   expr shift  437 */
  { 166,   6, 484}, /*  7:               itemlist shift  484 */
  {  12,   0, 165}, /*  8:                 BITNOT shift  165 */
  { 110,  11,  64}, /*  9:                 STRING shift  64 */
  {  57,   0,  61}, /* 10:                     ID shift  61 */
  {  94,  16, 181}, /* 11:                  RAISE shift  181 */
  {  91,   0, 169}, /* 12:                   PLUS shift  169 */
  {  76,   8,  65}, /* 13:                     LP shift  65 */
  { 157,   0,  63}, /* 14:                     id shift  63 */
  { 158,   9,  97}, /* 15:                    ids shift  97 */
  {  46,   0, 101}, /* 16:                  FLOAT shift  101 */
/* State 484 */
  {  21,   0, 434}, /*  1:                  COMMA shift  434 */
  { 101,   1, 485}, /*  2:                     RP shift  485 */
/* State 485 */
  { 104,   0, 674}, /*  1:                   SEMI reduce 155 */
/* State 486 */
  {  88,   0, 405}, /*  1:                     OR shift  405 */
  { 178,   1, 487}, /*  2:                 orconf shift  487 */
  {  68,   0, 606}, /*  3:                   INTO reduce 87 */
/* State 487 */
  {  68,   0, 676}, /*  1:                   INTO reduce 157 */
/* State 488 */
  {  68,   0, 677}, /*  1:                   INTO reduce 158 */
/* State 489 */
  { 178,   2, 490}, /*  1:                 orconf shift  490 */
  {  88,   0, 405}, /*  2:                     OR shift  405 */
/* State 490 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 491}, /*  3:                    ids shift  491 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 491 */
  {  49,   0, 492}, /*  1:                   FROM shift  492 */
/* State 492 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 493}, /*  3:                    ids shift  493 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 493 */
  { 104,   0, 750}, /*  1:                   SEMI reduce 231 */
  { 121,   0, 494}, /*  2:                  USING shift  494 */
/* State 494 */
  {  33,   0, 495}, /*  1:             DELIMITERS shift  495 */
/* State 495 */
  { 110,   0, 496}, /*  1:                 STRING shift  496 */
/* State 496 */
  { 104,   0, 749}, /*  1:                   SEMI reduce 230 */
/* State 497 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  {  57,   0,  19}, /*  2:                     ID shift  19 */
  { 157,   2,  20}, /*  3:                     id shift  20 */
  { 158,   0, 498}, /*  4:                    ids shift  498 */
  { 104,   0, 751}, /*  5:                   SEMI reduce 232 */
/* State 498 */
  { 104,   0, 752}, /*  1:                   SEMI reduce 233 */
/* State 499 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 500}, /*  3:                    ids shift  500 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 500 */
  {  42,   0, 501}, /*  1:                     EQ shift  501 */
  {  76,   0, 513}, /*  2:                     LP shift  513 */
  { 104,   0, 758}, /*  3:                   SEMI reduce 239 */
/* State 501 */
  { 180,   4, 504}, /*  1:               plus_num shift  504 */
  { 181,   5, 506}, /*  2:               plus_opt shift  506 */
  { 172,   0, 505}, /*  3:              minus_num shift  505 */
  { 110,   6,  21}, /*  4:                 STRING shift  21 */
  {  91,   0, 512}, /*  5:                   PLUS shift  512 */
  {  80,   0, 510}, /*  6:                  MINUS shift  510 */
  {  87,  10, 503}, /*  7:                     ON shift  503 */
  { 157,   7,  20}, /*  8:                     id shift  20 */
  { 158,   0, 502}, /*  9:                    ids shift  502 */
  {  57,   0,  19}, /* 10:                     ID shift  19 */
/* State 502 */
  { 104,   0, 753}, /*  1:                   SEMI reduce 234 */
/* State 503 */
  { 104,   0, 754}, /*  1:                   SEMI reduce 235 */
/* State 504 */
  { 104,   0, 755}, /*  1:                   SEMI reduce 236 */
/* State 505 */
  { 104,   0, 756}, /*  1:                   SEMI reduce 237 */
/* State 506 */
  { 174,   3, 507}, /*  1:                 number shift  507 */
  {  46,   0, 509}, /*  2:                  FLOAT shift  509 */
  {  66,   0, 508}, /*  3:                INTEGER shift  508 */
/* State 507 */
  { 104,   0, 759}, /*  1:                   SEMI reduce 240 */
/* State 508 */
  { 104,   0, 761}, /*  1:                   SEMI reduce 242 */
/* State 509 */
  { 104,   0, 762}, /*  1:                   SEMI reduce 243 */
/* State 510 */
  { 174,   3, 511}, /*  1:                 number shift  511 */
  {  46,   0, 509}, /*  2:                  FLOAT shift  509 */
  {  66,   0, 508}, /*  3:                INTEGER shift  508 */
/* State 511 */
  { 104,   0, 760}, /*  1:                   SEMI reduce 241 */
/* State 513 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 514}, /*  3:                    ids shift  514 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 514 */
  { 101,   0, 515}, /*  1:                     RP shift  515 */
/* State 515 */
  { 104,   0, 757}, /*  1:                   SEMI reduce 238 */
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
  { &yyActionTable[0],   6, 525 },
  { &yyActionTable[6],   5, 525 },
  { &yyActionTable[11],   0, 521 },
  { &yyActionTable[11],  19, 791 },
  { &yyActionTable[30],   1, 791 },
  { &yyActionTable[31],   0, 522 },
  { &yyActionTable[31],   2, 527 },
  { &yyActionTable[33],   3, 791 },
  { &yyActionTable[36],   1, 791 },
  { &yyActionTable[37],   1, 791 },
  { &yyActionTable[38],   6, 791 },
  { &yyActionTable[44],   0, 605 },
  { &yyActionTable[44],   0, 608 },
  { &yyActionTable[44],   0, 609 },
  { &yyActionTable[44],   0, 610 },
  { &yyActionTable[44],   0, 611 },
  { &yyActionTable[44],   0, 612 },
  { &yyActionTable[44],   4, 528 },
  { &yyActionTable[48],   0, 529 },
  { &yyActionTable[48],   0, 543 },
  { &yyActionTable[48],   0, 544 },
  { &yyActionTable[48],   0, 545 },
  { &yyActionTable[48],   3, 791 },
  { &yyActionTable[51],   1, 791 },
  { &yyActionTable[52],   3, 791 },
  { &yyActionTable[55],   1, 791 },
  { &yyActionTable[56],   3, 791 },
  { &yyActionTable[59],   1, 791 },
  { &yyActionTable[60],   3, 791 },
  { &yyActionTable[63],   1, 791 },
  { &yyActionTable[64],   7, 791 },
  { &yyActionTable[71],   3, 791 },
  { &yyActionTable[74],   1, 791 },
  { &yyActionTable[75],   1, 791 },
  { &yyActionTable[76],  13, 791 },
  { &yyActionTable[89],   0, 539 },
  { &yyActionTable[89],   6, 546 },
  { &yyActionTable[95],   1, 556 },
  { &yyActionTable[96],  13, 541 },
  { &yyActionTable[109],   0, 555 },
  { &yyActionTable[109],   4, 791 },
  { &yyActionTable[113],  10, 791 },
  { &yyActionTable[123],   0, 557 },
  { &yyActionTable[123],   2, 791 },
  { &yyActionTable[125],   2, 604 },
  { &yyActionTable[127],   0, 568 },
  { &yyActionTable[127],   2, 589 },
  { &yyActionTable[129],   0, 587 },
  { &yyActionTable[129],   2, 791 },
  { &yyActionTable[131],   0, 590 },
  { &yyActionTable[131],   0, 591 },
  { &yyActionTable[131],   1, 791 },
  { &yyActionTable[132],   3, 656 },
  { &yyActionTable[135],   2, 604 },
  { &yyActionTable[137],   0, 569 },
  { &yyActionTable[137],   0, 654 },
  { &yyActionTable[137],   0, 655 },
  { &yyActionTable[137],   2, 604 },
  { &yyActionTable[139],   0, 570 },
  { &yyActionTable[139],   1, 791 },
  { &yyActionTable[140],  15, 791 },
  { &yyActionTable[155],   1, 543 },
  { &yyActionTable[156],  18, 741 },
  { &yyActionTable[174],   1, 686 },
  { &yyActionTable[175],   1, 690 },
  { &yyActionTable[176],  18, 791 },
  { &yyActionTable[194],   0, 617 },
  { &yyActionTable[194],   5, 791 },
  { &yyActionTable[199],   2, 791 },
  { &yyActionTable[201],   0, 618 },
  { &yyActionTable[201],   3, 626 },
  { &yyActionTable[204],   2, 628 },
  { &yyActionTable[206],   3, 634 },
  { &yyActionTable[209],   2, 669 },
  { &yyActionTable[211],   2, 659 },
  { &yyActionTable[213],   2, 661 },
  { &yyActionTable[215],   2, 649 },
  { &yyActionTable[217],   2, 663 },
  { &yyActionTable[219],   0, 623 },
  { &yyActionTable[219],   1, 791 },
  { &yyActionTable[220],   3, 664 },
  { &yyActionTable[223],   1, 791 },
  { &yyActionTable[224],   0, 665 },
  { &yyActionTable[224],   1, 791 },
  { &yyActionTable[225],   1, 791 },
  { &yyActionTable[226],   1, 791 },
  { &yyActionTable[227],  17, 791 },
  { &yyActionTable[244],   1, 650 },
  { &yyActionTable[245],  16, 791 },
  { &yyActionTable[261],   2, 657 },
  { &yyActionTable[263],   3, 656 },
  { &yyActionTable[266],   0, 651 },
  { &yyActionTable[266],   2, 791 },
  { &yyActionTable[268],   0, 658 },
  { &yyActionTable[268],  27, 653 },
  { &yyActionTable[295],  15, 791 },
  { &yyActionTable[310],   0, 685 },
  { &yyActionTable[310],   1, 791 },
  { &yyActionTable[311],   4, 791 },
  { &yyActionTable[315],   0, 687 },
  { &yyActionTable[315],   0, 688 },
  { &yyActionTable[315],   0, 689 },
  { &yyActionTable[315],  25, 693 },
  { &yyActionTable[340],  15, 791 },
  { &yyActionTable[355],  26, 694 },
  { &yyActionTable[381],  15, 791 },
  { &yyActionTable[396],  11, 695 },
  { &yyActionTable[407],  15, 791 },
  { &yyActionTable[422],  11, 696 },
  { &yyActionTable[433],  15, 791 },
  { &yyActionTable[448],  11, 697 },
  { &yyActionTable[459],  15, 791 },
  { &yyActionTable[474],  11, 698 },
  { &yyActionTable[485],  15, 791 },
  { &yyActionTable[500],  15, 699 },
  { &yyActionTable[515],  15, 791 },
  { &yyActionTable[530],  15, 700 },
  { &yyActionTable[545],  15, 791 },
  { &yyActionTable[560],   7, 701 },
  { &yyActionTable[567],  15, 791 },
  { &yyActionTable[582],   7, 702 },
  { &yyActionTable[589],  15, 791 },
  { &yyActionTable[604],   7, 703 },
  { &yyActionTable[611],  15, 791 },
  { &yyActionTable[626],   7, 704 },
  { &yyActionTable[633],  15, 791 },
  { &yyActionTable[648],  15, 705 },
  { &yyActionTable[663],   6, 791 },
  { &yyActionTable[669],  15, 791 },
  { &yyActionTable[684],  15, 706 },
  { &yyActionTable[699],   0, 707 },
  { &yyActionTable[699],   0, 708 },
  { &yyActionTable[699],  15, 791 },
  { &yyActionTable[714],   5, 709 },
  { &yyActionTable[719],  15, 791 },
  { &yyActionTable[734],   5, 710 },
  { &yyActionTable[739],  15, 791 },
  { &yyActionTable[754],   2, 711 },
  { &yyActionTable[756],  15, 791 },
  { &yyActionTable[771],   2, 712 },
  { &yyActionTable[773],  15, 791 },
  { &yyActionTable[788],   2, 713 },
  { &yyActionTable[790],  15, 791 },
  { &yyActionTable[805],   1, 714 },
  { &yyActionTable[806],   0, 715 },
  { &yyActionTable[806],   2, 791 },
  { &yyActionTable[808],   0, 716 },
  { &yyActionTable[808],   1, 791 },
  { &yyActionTable[809],   0, 719 },
  { &yyActionTable[809],   0, 717 },
  { &yyActionTable[809],  15, 791 },
  { &yyActionTable[824],  27, 791 },
  { &yyActionTable[851],  15, 791 },
  { &yyActionTable[866],  15, 725 },
  { &yyActionTable[881],   1, 791 },
  { &yyActionTable[882],  20, 741 },
  { &yyActionTable[902],   5, 791 },
  { &yyActionTable[907],   2, 791 },
  { &yyActionTable[909],   1, 791 },
  { &yyActionTable[910],   1, 791 },
  { &yyActionTable[911],   1, 791 },
  { &yyActionTable[912],   0, 728 },
  { &yyActionTable[912],  27, 740 },
  { &yyActionTable[939],  15, 791 },
  { &yyActionTable[954],  25, 720 },
  { &yyActionTable[979],  15, 791 },
  { &yyActionTable[994],   1, 721 },
  { &yyActionTable[995],  15, 791 },
  { &yyActionTable[1010],   1, 722 },
  { &yyActionTable[1011],  15, 791 },
  { &yyActionTable[1026],   1, 723 },
  { &yyActionTable[1027],  17, 791 },
  { &yyActionTable[1044],  28, 791 },
  { &yyActionTable[1072],   2, 791 },
  { &yyActionTable[1074],   4, 791 },
  { &yyActionTable[1078],   1, 791 },
  { &yyActionTable[1079],   0, 731 },
  { &yyActionTable[1079],  15, 791 },
  { &yyActionTable[1094],  28, 791 },
  { &yyActionTable[1122],  15, 791 },
  { &yyActionTable[1137],  27, 732 },
  { &yyActionTable[1164],   1, 791 },
  { &yyActionTable[1165],   4, 791 },
  { &yyActionTable[1169],   1, 791 },
  { &yyActionTable[1170],   0, 786 },
  { &yyActionTable[1170],   1, 791 },
  { &yyActionTable[1171],   4, 791 },
  { &yyActionTable[1175],   1, 791 },
  { &yyActionTable[1176],   0, 787 },
  { &yyActionTable[1176],   1, 791 },
  { &yyActionTable[1177],   4, 791 },
  { &yyActionTable[1181],   1, 791 },
  { &yyActionTable[1182],   0, 788 },
  { &yyActionTable[1182],   1, 791 },
  { &yyActionTable[1183],   4, 791 },
  { &yyActionTable[1187],   1, 791 },
  { &yyActionTable[1188],   0, 789 },
  { &yyActionTable[1188],  15, 791 },
  { &yyActionTable[1203],  28, 791 },
  { &yyActionTable[1231],  15, 791 },
  { &yyActionTable[1246],  28, 791 },
  { &yyActionTable[1274],  15, 791 },
  { &yyActionTable[1289],  27, 733 },
  { &yyActionTable[1316],   2, 791 },
  { &yyActionTable[1318],   0, 727 },
  { &yyActionTable[1318],  16, 741 },
  { &yyActionTable[1334],   0, 738 },
  { &yyActionTable[1334],   0, 739 },
  { &yyActionTable[1334],   0, 718 },
  { &yyActionTable[1334],  15, 791 },
  { &yyActionTable[1349],  27, 791 },
  { &yyActionTable[1376],  15, 791 },
  { &yyActionTable[1391],  25, 726 },
  { &yyActionTable[1416],   1, 791 },
  { &yyActionTable[1417],  20, 741 },
  { &yyActionTable[1437],   5, 791 },
  { &yyActionTable[1442],   0, 730 },
  { &yyActionTable[1442],   2, 791 },
  { &yyActionTable[1444],   0, 729 },
  { &yyActionTable[1444],   3, 656 },
  { &yyActionTable[1447],   0, 652 },
  { &yyActionTable[1447],  15, 791 },
  { &yyActionTable[1462],  27, 662 },
  { &yyActionTable[1489],   1, 791 },
  { &yyActionTable[1490],  17, 741 },
  { &yyActionTable[1507],   1, 660 },
  { &yyActionTable[1508],  15, 791 },
  { &yyActionTable[1523],  27, 670 },
  { &yyActionTable[1550],   0, 627 },
  { &yyActionTable[1550],   2, 637 },
  { &yyActionTable[1552],   4, 635 },
  { &yyActionTable[1556],   0, 636 },
  { &yyActionTable[1556],   0, 640 },
  { &yyActionTable[1556],   0, 641 },
  { &yyActionTable[1556],   2, 791 },
  { &yyActionTable[1558],   0, 642 },
  { &yyActionTable[1558],   2, 791 },
  { &yyActionTable[1560],   0, 643 },
  { &yyActionTable[1560],   1, 791 },
  { &yyActionTable[1561],   0, 644 },
  { &yyActionTable[1561],   5, 791 },
  { &yyActionTable[1566],   2, 633 },
  { &yyActionTable[1568],   4, 791 },
  { &yyActionTable[1572],   0, 632 },
  { &yyActionTable[1572],   2, 646 },
  { &yyActionTable[1574],   2, 648 },
  { &yyActionTable[1576],   0, 638 },
  { &yyActionTable[1576],   1, 791 },
  { &yyActionTable[1577],   6, 791 },
  { &yyActionTable[1583],   2, 791 },
  { &yyActionTable[1585],   0, 647 },
  { &yyActionTable[1585],   5, 791 },
  { &yyActionTable[1590],   0, 745 },
  { &yyActionTable[1590],   0, 747 },
  { &yyActionTable[1590],   0, 746 },
  { &yyActionTable[1590],  15, 791 },
  { &yyActionTable[1605],  27, 645 },
  { &yyActionTable[1632],   3, 791 },
  { &yyActionTable[1635],   5, 791 },
  { &yyActionTable[1640],   2, 633 },
  { &yyActionTable[1642],   2, 646 },
  { &yyActionTable[1644],   2, 648 },
  { &yyActionTable[1646],   0, 639 },
  { &yyActionTable[1646],  16, 791 },
  { &yyActionTable[1662],  29, 633 },
  { &yyActionTable[1691],   0, 629 },
  { &yyActionTable[1691],   0, 630 },
  { &yyActionTable[1691],   1, 791 },
  { &yyActionTable[1692],   5, 791 },
  { &yyActionTable[1697],   0, 631 },
  { &yyActionTable[1697],   0, 624 },
  { &yyActionTable[1697],   0, 625 },
  { &yyActionTable[1697],   0, 724 },
  { &yyActionTable[1697],  28, 791 },
  { &yyActionTable[1725],   0, 684 },
  { &yyActionTable[1725],   2, 791 },
  { &yyActionTable[1727],   0, 691 },
  { &yyActionTable[1727],   1, 791 },
  { &yyActionTable[1728],   0, 692 },
  { &yyActionTable[1728],  28, 791 },
  { &yyActionTable[1756],   2, 604 },
  { &yyActionTable[1758],   0, 571 },
  { &yyActionTable[1758],   0, 572 },
  { &yyActionTable[1758],   0, 573 },
  { &yyActionTable[1758],   2, 791 },
  { &yyActionTable[1760],   0, 574 },
  { &yyActionTable[1760],   4, 791 },
  { &yyActionTable[1764],   2, 577 },
  { &yyActionTable[1766],   6, 791 },
  { &yyActionTable[1772],   2, 791 },
  { &yyActionTable[1774],   1, 577 },
  { &yyActionTable[1775],   3, 575 },
  { &yyActionTable[1778],   0, 578 },
  { &yyActionTable[1778],   2, 791 },
  { &yyActionTable[1780],   0, 579 },
  { &yyActionTable[1780],   0, 580 },
  { &yyActionTable[1780],   2, 791 },
  { &yyActionTable[1782],   4, 791 },
  { &yyActionTable[1786],   0, 581 },
  { &yyActionTable[1786],   2, 791 },
  { &yyActionTable[1788],   0, 583 },
  { &yyActionTable[1788],   0, 584 },
  { &yyActionTable[1788],   0, 585 },
  { &yyActionTable[1788],   0, 586 },
  { &yyActionTable[1788],   4, 791 },
  { &yyActionTable[1792],   0, 582 },
  { &yyActionTable[1792],   3, 576 },
  { &yyActionTable[1795],   2, 589 },
  { &yyActionTable[1797],   0, 588 },
  { &yyActionTable[1797],   0, 558 },
  { &yyActionTable[1797],   7, 791 },
  { &yyActionTable[1804],   0, 559 },
  { &yyActionTable[1804],   0, 560 },
  { &yyActionTable[1804],   0, 561 },
  { &yyActionTable[1804],   2, 791 },
  { &yyActionTable[1806],   0, 562 },
  { &yyActionTable[1806],   0, 565 },
  { &yyActionTable[1806],   2, 791 },
  { &yyActionTable[1808],   0, 563 },
  { &yyActionTable[1808],   0, 566 },
  { &yyActionTable[1808],   0, 564 },
  { &yyActionTable[1808],   0, 567 },
  { &yyActionTable[1808],   5, 547 },
  { &yyActionTable[1813],   4, 791 },
  { &yyActionTable[1817],   2, 791 },
  { &yyActionTable[1819],   0, 548 },
  { &yyActionTable[1819],   4, 791 },
  { &yyActionTable[1823],   1, 791 },
  { &yyActionTable[1824],   0, 549 },
  { &yyActionTable[1824],   0, 552 },
  { &yyActionTable[1824],   1, 791 },
  { &yyActionTable[1825],   0, 553 },
  { &yyActionTable[1825],   1, 791 },
  { &yyActionTable[1826],   0, 554 },
  { &yyActionTable[1826],   0, 551 },
  { &yyActionTable[1826],   0, 550 },
  { &yyActionTable[1826],   0, 542 },
  { &yyActionTable[1826],   8, 791 },
  { &yyActionTable[1834],   6, 791 },
  { &yyActionTable[1840],   0, 594 },
  { &yyActionTable[1840],   4, 791 },
  { &yyActionTable[1844],   0, 597 },
  { &yyActionTable[1844],   1, 791 },
  { &yyActionTable[1845],   1, 791 },
  { &yyActionTable[1846],   6, 791 },
  { &yyActionTable[1852],   2, 791 },
  { &yyActionTable[1854],   2, 604 },
  { &yyActionTable[1856],   0, 598 },
  { &yyActionTable[1856],   1, 791 },
  { &yyActionTable[1857],   6, 791 },
  { &yyActionTable[1863],   2, 791 },
  { &yyActionTable[1865],   2, 604 },
  { &yyActionTable[1867],   0, 599 },
  { &yyActionTable[1867],  15, 791 },
  { &yyActionTable[1882],  29, 604 },
  { &yyActionTable[1911],   0, 600 },
  { &yyActionTable[1911],   1, 791 },
  { &yyActionTable[1912],   1, 791 },
  { &yyActionTable[1913],   6, 791 },
  { &yyActionTable[1919],   2, 791 },
  { &yyActionTable[1921],   2, 791 },
  { &yyActionTable[1923],   4, 602 },
  { &yyActionTable[1927],   1, 791 },
  { &yyActionTable[1928],   0, 601 },
  { &yyActionTable[1928],   0, 603 },
  { &yyActionTable[1928],   0, 595 },
  { &yyActionTable[1928],   0, 596 },
  { &yyActionTable[1928],   0, 540 },
  { &yyActionTable[1928],   3, 791 },
  { &yyActionTable[1931],   5, 791 },
  { &yyActionTable[1936],   8, 791 },
  { &yyActionTable[1944],   1, 791 },
  { &yyActionTable[1945],   4, 791 },
  { &yyActionTable[1949],   0, 534 },
  { &yyActionTable[1949],   1, 791 },
  { &yyActionTable[1950],   4, 791 },
  { &yyActionTable[1954],   1, 791 },
  { &yyActionTable[1955],   3, 791 },
  { &yyActionTable[1958],   5, 791 },
  { &yyActionTable[1963],   1, 791 },
  { &yyActionTable[1964],   4, 791 },
  { &yyActionTable[1968],   1, 791 },
  { &yyActionTable[1969],   4, 791 },
  { &yyActionTable[1973],   1, 791 },
  { &yyActionTable[1974],   6, 791 },
  { &yyActionTable[1980],   2, 791 },
  { &yyActionTable[1982],   3, 791 },
  { &yyActionTable[1985],   1, 791 },
  { &yyActionTable[1986],   1, 791 },
  { &yyActionTable[1987],   4, 791 },
  { &yyActionTable[1991],   4, 769 },
  { &yyActionTable[1995],   4, 791 },
  { &yyActionTable[1999],   1, 791 },
  { &yyActionTable[2000],   4, 791 },
  { &yyActionTable[2004],   2, 774 },
  { &yyActionTable[2006],   3, 791 },
  { &yyActionTable[2009],   1, 791 },
  { &yyActionTable[2010],   9, 791 },
  { &yyActionTable[2019],   5, 791 },
  { &yyActionTable[2024],   1, 791 },
  { &yyActionTable[2025],   1, 791 },
  { &yyActionTable[2026],   1, 791 },
  { &yyActionTable[2027],   9, 791 },
  { &yyActionTable[2036],   1, 791 },
  { &yyActionTable[2037],   2, 606 },
  { &yyActionTable[2039],   6, 791 },
  { &yyActionTable[2045],   0, 607 },
  { &yyActionTable[2045],   4, 791 },
  { &yyActionTable[2049],   1, 791 },
  { &yyActionTable[2050],   5, 791 },
  { &yyActionTable[2055],   4, 791 },
  { &yyActionTable[2059],   4, 791 },
  { &yyActionTable[2063],   1, 791 },
  { &yyActionTable[2064],  15, 791 },
  { &yyActionTable[2079],  27, 672 },
  { &yyActionTable[2106],   1, 791 },
  { &yyActionTable[2107],   1, 791 },
  { &yyActionTable[2108],  15, 791 },
  { &yyActionTable[2123],  27, 673 },
  { &yyActionTable[2150],   3, 791 },
  { &yyActionTable[2153],   1, 791 },
  { &yyActionTable[2154],   4, 791 },
  { &yyActionTable[2158],   2, 680 },
  { &yyActionTable[2160],   5, 791 },
  { &yyActionTable[2165],   2, 791 },
  { &yyActionTable[2167],   0, 681 },
  { &yyActionTable[2167],   4, 791 },
  { &yyActionTable[2171],   0, 682 },
  { &yyActionTable[2171],   0, 683 },
  { &yyActionTable[2171],   4, 791 },
  { &yyActionTable[2175],   5, 791 },
  { &yyActionTable[2180],   1, 791 },
  { &yyActionTable[2181],  16, 791 },
  { &yyActionTable[2197],   2, 791 },
  { &yyActionTable[2199],  15, 791 },
  { &yyActionTable[2214],  27, 678 },
  { &yyActionTable[2241],   1, 791 },
  { &yyActionTable[2242],  27, 679 },
  { &yyActionTable[2269],   1, 791 },
  { &yyActionTable[2270],   4, 791 },
  { &yyActionTable[2274],   3, 791 },
  { &yyActionTable[2277],   1, 791 },
  { &yyActionTable[2278],  15, 791 },
  { &yyActionTable[2293],  28, 791 },
  { &yyActionTable[2321],   1, 791 },
  { &yyActionTable[2322],   2, 791 },
  { &yyActionTable[2324],   0, 775 },
  { &yyActionTable[2324],   0, 776 },
  { &yyActionTable[2324],   1, 791 },
  { &yyActionTable[2325],   1, 791 },
  { &yyActionTable[2326],   2, 791 },
  { &yyActionTable[2328],   5, 791 },
  { &yyActionTable[2333],   2, 791 },
  { &yyActionTable[2335],   0, 766 },
  { &yyActionTable[2335],   0, 767 },
  { &yyActionTable[2335],   1, 791 },
  { &yyActionTable[2336],   0, 768 },
  { &yyActionTable[2336],   4, 791 },
  { &yyActionTable[2340],   4, 791 },
  { &yyActionTable[2344],   1, 791 },
  { &yyActionTable[2345],   4, 791 },
  { &yyActionTable[2349],   1, 791 },
  { &yyActionTable[2350],   4, 791 },
  { &yyActionTable[2354],   1, 791 },
  { &yyActionTable[2355],   4, 791 },
  { &yyActionTable[2359],   1, 791 },
  { &yyActionTable[2360],   5, 791 },
  { &yyActionTable[2365],   1, 791 },
  { &yyActionTable[2366],   4, 791 },
  { &yyActionTable[2370],   3, 791 },
  { &yyActionTable[2373],   1, 791 },
  { &yyActionTable[2374],   2, 606 },
  { &yyActionTable[2376],   4, 791 },
  { &yyActionTable[2380],   1, 791 },
  { &yyActionTable[2381],   5, 791 },
  { &yyActionTable[2386],   4, 791 },
  { &yyActionTable[2390],   1, 791 },
  { &yyActionTable[2391],   1, 791 },
  { &yyActionTable[2392],   4, 791 },
  { &yyActionTable[2396],   2, 680 },
  { &yyActionTable[2398],   4, 791 },
  { &yyActionTable[2402],   5, 791 },
  { &yyActionTable[2407],   1, 791 },
  { &yyActionTable[2408],  16, 791 },
  { &yyActionTable[2424],   2, 791 },
  { &yyActionTable[2426],   1, 791 },
  { &yyActionTable[2427],   3, 791 },
  { &yyActionTable[2430],   1, 791 },
  { &yyActionTable[2431],   1, 791 },
  { &yyActionTable[2432],   2, 606 },
  { &yyActionTable[2434],   4, 791 },
  { &yyActionTable[2438],   1, 791 },
  { &yyActionTable[2439],   4, 791 },
  { &yyActionTable[2443],   2, 791 },
  { &yyActionTable[2445],   1, 791 },
  { &yyActionTable[2446],   1, 791 },
  { &yyActionTable[2447],   1, 791 },
  { &yyActionTable[2448],   5, 791 },
  { &yyActionTable[2453],   1, 791 },
  { &yyActionTable[2454],   4, 791 },
  { &yyActionTable[2458],   3, 791 },
  { &yyActionTable[2461],  10, 764 },
  { &yyActionTable[2471],   1, 791 },
  { &yyActionTable[2472],   1, 791 },
  { &yyActionTable[2473],   1, 791 },
  { &yyActionTable[2474],   1, 791 },
  { &yyActionTable[2475],   3, 791 },
  { &yyActionTable[2478],   1, 791 },
  { &yyActionTable[2479],   1, 791 },
  { &yyActionTable[2480],   1, 791 },
  { &yyActionTable[2481],   3, 791 },
  { &yyActionTable[2484],   1, 791 },
  { &yyActionTable[2485],   0, 763 },
  { &yyActionTable[2485],   4, 791 },
  { &yyActionTable[2489],   1, 791 },
  { &yyActionTable[2490],   1, 791 },
  { &yyActionTable[2491],   0, 523 },
  { &yyActionTable[2491],   0, 524 },
  { &yyActionTable[2491],   0, 520 },
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
   57,  /*      ABORT => ID */
   57,  /*      AFTER => ID */
    0,  /* AGG_FUNCTION => nothing */
    0,  /*        ALL => nothing */
    0,  /*        AND => nothing */
    0,  /*         AS => nothing */
   57,  /*        ASC => ID */
   57,  /*     BEFORE => ID */
   57,  /*      BEGIN => ID */
    0,  /*    BETWEEN => nothing */
    0,  /*     BITAND => nothing */
    0,  /*     BITNOT => nothing */
    0,  /*      BITOR => nothing */
    0,  /*         BY => nothing */
   57,  /*    CASCADE => ID */
    0,  /*       CASE => nothing */
    0,  /*      CHECK => nothing */
   57,  /*    CLUSTER => ID */
   57,  /*    COLLATE => ID */
    0,  /*     COLUMN => nothing */
    0,  /*      COMMA => nothing */
    0,  /*    COMMENT => nothing */
    0,  /*     COMMIT => nothing */
    0,  /*     CONCAT => nothing */
   57,  /*   CONFLICT => ID */
    0,  /* CONSTRAINT => nothing */
   57,  /*       COPY => ID */
    0,  /*     CREATE => nothing */
    0,  /*    DEFAULT => nothing */
    0,  /* DEFERRABLE => nothing */
   57,  /*   DEFERRED => ID */
    0,  /*     DELETE => nothing */
   57,  /* DELIMITERS => ID */
   57,  /*       DESC => ID */
    0,  /*   DISTINCT => nothing */
    0,  /*        DOT => nothing */
    0,  /*       DROP => nothing */
   57,  /*       EACH => ID */
    0,  /*       ELSE => nothing */
   57,  /*        END => ID */
    0,  /* END_OF_FILE => nothing */
    0,  /*         EQ => nothing */
    0,  /*     EXCEPT => nothing */
   57,  /*    EXPLAIN => ID */
   57,  /*       FAIL => ID */
    0,  /*      FLOAT => nothing */
   57,  /*        FOR => ID */
    0,  /*    FOREIGN => nothing */
    0,  /*       FROM => nothing */
   57,  /*       FULL => ID */
    0,  /*   FUNCTION => nothing */
    0,  /*         GE => nothing */
    0,  /*       GLOB => nothing */
    0,  /*      GROUP => nothing */
    0,  /*         GT => nothing */
    0,  /*     HAVING => nothing */
    0,  /*         ID => nothing */
   57,  /*     IGNORE => ID */
    0,  /*    ILLEGAL => nothing */
   57,  /*  IMMEDIATE => ID */
    0,  /*         IN => nothing */
    0,  /*      INDEX => nothing */
   57,  /*  INITIALLY => ID */
    0,  /*     INSERT => nothing */
   57,  /*    INSTEAD => ID */
    0,  /*    INTEGER => nothing */
    0,  /*  INTERSECT => nothing */
    0,  /*       INTO => nothing */
    0,  /*         IS => nothing */
    0,  /*     ISNULL => nothing */
   57,  /*       JOIN => ID */
   57,  /*        KEY => ID */
    0,  /*         LE => nothing */
    0,  /*       LIKE => nothing */
    0,  /*      LIMIT => nothing */
    0,  /*         LP => nothing */
    0,  /*     LSHIFT => nothing */
    0,  /*         LT => nothing */
   57,  /*      MATCH => ID */
    0,  /*      MINUS => nothing */
    0,  /*         NE => nothing */
    0,  /*        NOT => nothing */
    0,  /*    NOTNULL => nothing */
    0,  /*       NULL => nothing */
   57,  /*         OF => ID */
   57,  /*     OFFSET => ID */
    0,  /*         ON => nothing */
    0,  /*         OR => nothing */
    0,  /*      ORDER => nothing */
   57,  /*    PARTIAL => ID */
    0,  /*       PLUS => nothing */
   57,  /*     PRAGMA => ID */
    0,  /*    PRIMARY => nothing */
   57,  /*      RAISE => ID */
    0,  /* REFERENCES => nothing */
    0,  /*        REM => nothing */
   57,  /*    REPLACE => ID */
   57,  /*   RESTRICT => ID */
    0,  /*   ROLLBACK => nothing */
   57,  /*        ROW => ID */
    0,  /*         RP => nothing */
    0,  /*     RSHIFT => nothing */
    0,  /*     SELECT => nothing */
    0,  /*       SEMI => nothing */
    0,  /*        SET => nothing */
    0,  /*      SLASH => nothing */
    0,  /*      SPACE => nothing */
    0,  /*       STAR => nothing */
   57,  /*  STATEMENT => ID */
    0,  /*     STRING => nothing */
    0,  /*      TABLE => nothing */
   57,  /*       TEMP => ID */
    0,  /*       THEN => nothing */
    0,  /* TRANSACTION => nothing */
   57,  /*    TRIGGER => ID */
    0,  /*     UMINUS => nothing */
    0,  /* UNCLOSED_STRING => nothing */
    0,  /*      UNION => nothing */
    0,  /*     UNIQUE => nothing */
    0,  /*     UPDATE => nothing */
    0,  /*      USING => nothing */
   57,  /*     VACUUM => ID */
    0,  /*     VALUES => nothing */
   57,  /*       VIEW => ID */
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
  "FOREIGN",       "FROM",          "FULL",          "FUNCTION",    
  "GE",            "GLOB",          "GROUP",         "GT",          
  "HAVING",        "ID",            "IGNORE",        "ILLEGAL",     
  "IMMEDIATE",     "IN",            "INDEX",         "INITIALLY",   
  "INSERT",        "INSTEAD",       "INTEGER",       "INTERSECT",   
  "INTO",          "IS",            "ISNULL",        "JOIN",        
  "KEY",           "LE",            "LIKE",          "LIMIT",       
  "LP",            "LSHIFT",        "LT",            "MATCH",       
  "MINUS",         "NE",            "NOT",           "NOTNULL",     
  "NULL",          "OF",            "OFFSET",        "ON",          
  "OR",            "ORDER",         "PARTIAL",       "PLUS",        
  "PRAGMA",        "PRIMARY",       "RAISE",         "REFERENCES",  
  "REM",           "REPLACE",       "RESTRICT",      "ROLLBACK",    
  "ROW",           "RP",            "RSHIFT",        "SELECT",      
  "SEMI",          "SET",           "SLASH",         "SPACE",       
  "STAR",          "STATEMENT",     "STRING",        "TABLE",       
  "TEMP",          "THEN",          "TRANSACTION",   "TRIGGER",     
  "UMINUS",        "UNCLOSED_STRING",  "UNION",         "UNIQUE",      
  "UPDATE",        "USING",         "VACUUM",        "VALUES",      
  "VIEW",          "WHEN",          "WHERE",         "as",          
  "carg",          "carglist",      "case_else",     "case_exprlist",
  "case_operand",  "ccons",         "cmd",           "cmdlist",     
  "collate",       "column",        "columnid",      "columnlist",  
  "conslist",      "conslist_opt",  "create_table",  "create_table_args",
  "defer_subclause",  "defer_subclause_opt",  "distinct",      "ecmd",        
  "error",         "explain",       "expr",          "expritem",    
  "exprlist",      "foreach_clause",  "from",          "groupby_opt", 
  "having_opt",    "id",            "ids",           "idxitem",     
  "idxlist",       "init_deferred_pred_opt",  "input",         "inscollist",  
  "inscollist_opt",  "insert_cmd",    "itemlist",      "joinop",      
  "joinop2",       "likeop",        "limit_opt",     "limit_sep",   
  "minus_num",     "multiselect_op",  "number",        "on_opt",      
  "onconf",        "oneselect",     "orconf",        "orderby_opt", 
  "plus_num",      "plus_opt",      "refact",        "refarg",      
  "refargs",       "references",    "resolvetype",   "sclp",        
  "selcollist",    "select",        "seltablist",    "setlist",     
  "signed",        "sortitem",      "sortlist",      "sortorder",   
  "stl_prefix",    "tcons",         "temp",          "trans_opt",   
  "trigger_cmd",   "trigger_cmd_list",  "trigger_event",  "trigger_time",
  "type",          "typename",      "uniqueflag",    "using_opt",   
  "when_clause",   "where_opt",   
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
 /*  10 */ "trans_opt ::= TRANSACTION ids",
 /*  11 */ "cmd ::= COMMIT trans_opt",
 /*  12 */ "cmd ::= END trans_opt",
 /*  13 */ "cmd ::= ROLLBACK trans_opt",
 /*  14 */ "cmd ::= create_table create_table_args",
 /*  15 */ "create_table ::= CREATE temp TABLE ids",
 /*  16 */ "temp ::= TEMP",
 /*  17 */ "temp ::=",
 /*  18 */ "create_table_args ::= LP columnlist conslist_opt RP",
 /*  19 */ "create_table_args ::= AS select",
 /*  20 */ "columnlist ::= columnlist COMMA column",
 /*  21 */ "columnlist ::= column",
 /*  22 */ "column ::= columnid type carglist",
 /*  23 */ "columnid ::= ids",
 /*  24 */ "id ::= ID",
 /*  25 */ "ids ::= id",
 /*  26 */ "ids ::= STRING",
 /*  27 */ "type ::=",
 /*  28 */ "type ::= typename",
 /*  29 */ "type ::= typename LP signed RP",
 /*  30 */ "type ::= typename LP signed COMMA signed RP",
 /*  31 */ "typename ::= ids",
 /*  32 */ "typename ::= typename ids",
 /*  33 */ "signed ::= INTEGER",
 /*  34 */ "signed ::= PLUS INTEGER",
 /*  35 */ "signed ::= MINUS INTEGER",
 /*  36 */ "carglist ::= carglist carg",
 /*  37 */ "carglist ::=",
 /*  38 */ "carg ::= CONSTRAINT ids ccons",
 /*  39 */ "carg ::= ccons",
 /*  40 */ "carg ::= DEFAULT STRING",
 /*  41 */ "carg ::= DEFAULT ID",
 /*  42 */ "carg ::= DEFAULT INTEGER",
 /*  43 */ "carg ::= DEFAULT PLUS INTEGER",
 /*  44 */ "carg ::= DEFAULT MINUS INTEGER",
 /*  45 */ "carg ::= DEFAULT FLOAT",
 /*  46 */ "carg ::= DEFAULT PLUS FLOAT",
 /*  47 */ "carg ::= DEFAULT MINUS FLOAT",
 /*  48 */ "carg ::= DEFAULT NULL",
 /*  49 */ "ccons ::= NOT NULL onconf",
 /*  50 */ "ccons ::= PRIMARY KEY sortorder onconf",
 /*  51 */ "ccons ::= UNIQUE onconf",
 /*  52 */ "ccons ::= CHECK LP expr RP onconf",
 /*  53 */ "ccons ::= references",
 /*  54 */ "ccons ::= defer_subclause",
 /*  55 */ "ccons ::= COLLATE id",
 /*  56 */ "references ::= REFERENCES ids LP idxlist RP refargs",
 /*  57 */ "references ::= REFERENCES ids refargs",
 /*  58 */ "refargs ::=",
 /*  59 */ "refargs ::= refargs refarg",
 /*  60 */ "refarg ::= MATCH FULL",
 /*  61 */ "refarg ::= MATCH PARTIAL",
 /*  62 */ "refarg ::= ON DELETE refact",
 /*  63 */ "refarg ::= ON UPDATE refact",
 /*  64 */ "refact ::= SET NULL",
 /*  65 */ "refact ::= SET DEFAULT",
 /*  66 */ "refact ::= CASCADE",
 /*  67 */ "refact ::= RESTRICT",
 /*  68 */ "defer_subclause ::= NOT DEFERRABLE init_deferred_pred_opt",
 /*  69 */ "defer_subclause ::= DEFERRABLE init_deferred_pred_opt",
 /*  70 */ "init_deferred_pred_opt ::=",
 /*  71 */ "init_deferred_pred_opt ::= INITIALLY DEFERRED",
 /*  72 */ "init_deferred_pred_opt ::= INITIALLY IMMEDIATE",
 /*  73 */ "conslist_opt ::=",
 /*  74 */ "conslist_opt ::= COMMA conslist",
 /*  75 */ "conslist ::= conslist COMMA tcons",
 /*  76 */ "conslist ::= conslist tcons",
 /*  77 */ "conslist ::= tcons",
 /*  78 */ "tcons ::= CONSTRAINT ids",
 /*  79 */ "tcons ::= PRIMARY KEY LP idxlist RP onconf",
 /*  80 */ "tcons ::= UNIQUE LP idxlist RP onconf",
 /*  81 */ "tcons ::= CHECK expr onconf",
 /*  82 */ "tcons ::= FOREIGN KEY LP idxlist RP references defer_subclause_opt",
 /*  83 */ "defer_subclause_opt ::=",
 /*  84 */ "defer_subclause_opt ::= defer_subclause",
 /*  85 */ "onconf ::=",
 /*  86 */ "onconf ::= ON CONFLICT resolvetype",
 /*  87 */ "orconf ::=",
 /*  88 */ "orconf ::= OR resolvetype",
 /*  89 */ "resolvetype ::= ROLLBACK",
 /*  90 */ "resolvetype ::= ABORT",
 /*  91 */ "resolvetype ::= FAIL",
 /*  92 */ "resolvetype ::= IGNORE",
 /*  93 */ "resolvetype ::= REPLACE",
 /*  94 */ "cmd ::= DROP TABLE ids",
 /*  95 */ "cmd ::= CREATE VIEW ids AS select",
 /*  96 */ "cmd ::= DROP VIEW ids",
 /*  97 */ "cmd ::= select",
 /*  98 */ "select ::= oneselect",
 /*  99 */ "select ::= select multiselect_op oneselect",
 /* 100 */ "multiselect_op ::= UNION",
 /* 101 */ "multiselect_op ::= UNION ALL",
 /* 102 */ "multiselect_op ::= INTERSECT",
 /* 103 */ "multiselect_op ::= EXCEPT",
 /* 104 */ "oneselect ::= SELECT distinct selcollist from where_opt groupby_opt having_opt orderby_opt limit_opt",
 /* 105 */ "distinct ::= DISTINCT",
 /* 106 */ "distinct ::= ALL",
 /* 107 */ "distinct ::=",
 /* 108 */ "sclp ::= selcollist COMMA",
 /* 109 */ "sclp ::=",
 /* 110 */ "selcollist ::= sclp expr as",
 /* 111 */ "selcollist ::= sclp STAR",
 /* 112 */ "selcollist ::= sclp ids DOT STAR",
 /* 113 */ "as ::= AS ids",
 /* 114 */ "as ::=",
 /* 115 */ "from ::=",
 /* 116 */ "from ::= FROM seltablist",
 /* 117 */ "stl_prefix ::= seltablist joinop",
 /* 118 */ "stl_prefix ::=",
 /* 119 */ "seltablist ::= stl_prefix ids as on_opt using_opt",
 /* 120 */ "seltablist ::= stl_prefix LP select RP as on_opt using_opt",
 /* 121 */ "joinop ::= COMMA",
 /* 122 */ "joinop ::= JOIN",
 /* 123 */ "joinop ::= ID JOIN",
 /* 124 */ "joinop ::= ID ID JOIN",
 /* 125 */ "joinop ::= ID ID ID JOIN",
 /* 126 */ "on_opt ::= ON expr",
 /* 127 */ "on_opt ::=",
 /* 128 */ "using_opt ::= USING LP idxlist RP",
 /* 129 */ "using_opt ::=",
 /* 130 */ "orderby_opt ::=",
 /* 131 */ "orderby_opt ::= ORDER BY sortlist",
 /* 132 */ "sortlist ::= sortlist COMMA sortitem collate sortorder",
 /* 133 */ "sortlist ::= sortitem sortorder",
 /* 134 */ "sortitem ::= expr",
 /* 135 */ "sortorder ::= ASC",
 /* 136 */ "sortorder ::= DESC",
 /* 137 */ "sortorder ::=",
 /* 138 */ "collate ::=",
 /* 139 */ "collate ::= COLLATE id",
 /* 140 */ "groupby_opt ::=",
 /* 141 */ "groupby_opt ::= GROUP BY exprlist",
 /* 142 */ "having_opt ::=",
 /* 143 */ "having_opt ::= HAVING expr",
 /* 144 */ "limit_opt ::=",
 /* 145 */ "limit_opt ::= LIMIT INTEGER",
 /* 146 */ "limit_opt ::= LIMIT INTEGER limit_sep INTEGER",
 /* 147 */ "limit_sep ::= OFFSET",
 /* 148 */ "limit_sep ::= COMMA",
 /* 149 */ "cmd ::= DELETE FROM ids where_opt",
 /* 150 */ "where_opt ::=",
 /* 151 */ "where_opt ::= WHERE expr",
 /* 152 */ "cmd ::= UPDATE orconf ids SET setlist where_opt",
 /* 153 */ "setlist ::= setlist COMMA ids EQ expr",
 /* 154 */ "setlist ::= ids EQ expr",
 /* 155 */ "cmd ::= insert_cmd INTO ids inscollist_opt VALUES LP itemlist RP",
 /* 156 */ "cmd ::= insert_cmd INTO ids inscollist_opt select",
 /* 157 */ "insert_cmd ::= INSERT orconf",
 /* 158 */ "insert_cmd ::= REPLACE",
 /* 159 */ "itemlist ::= itemlist COMMA expr",
 /* 160 */ "itemlist ::= expr",
 /* 161 */ "inscollist_opt ::=",
 /* 162 */ "inscollist_opt ::= LP inscollist RP",
 /* 163 */ "inscollist ::= inscollist COMMA ids",
 /* 164 */ "inscollist ::= ids",
 /* 165 */ "expr ::= LP expr RP",
 /* 166 */ "expr ::= NULL",
 /* 167 */ "expr ::= id",
 /* 168 */ "expr ::= ids DOT ids",
 /* 169 */ "expr ::= INTEGER",
 /* 170 */ "expr ::= FLOAT",
 /* 171 */ "expr ::= STRING",
 /* 172 */ "expr ::= ID LP exprlist RP",
 /* 173 */ "expr ::= ID LP STAR RP",
 /* 174 */ "expr ::= expr AND expr",
 /* 175 */ "expr ::= expr OR expr",
 /* 176 */ "expr ::= expr LT expr",
 /* 177 */ "expr ::= expr GT expr",
 /* 178 */ "expr ::= expr LE expr",
 /* 179 */ "expr ::= expr GE expr",
 /* 180 */ "expr ::= expr NE expr",
 /* 181 */ "expr ::= expr EQ expr",
 /* 182 */ "expr ::= expr BITAND expr",
 /* 183 */ "expr ::= expr BITOR expr",
 /* 184 */ "expr ::= expr LSHIFT expr",
 /* 185 */ "expr ::= expr RSHIFT expr",
 /* 186 */ "expr ::= expr likeop expr",
 /* 187 */ "expr ::= expr NOT likeop expr",
 /* 188 */ "likeop ::= LIKE",
 /* 189 */ "likeop ::= GLOB",
 /* 190 */ "expr ::= expr PLUS expr",
 /* 191 */ "expr ::= expr MINUS expr",
 /* 192 */ "expr ::= expr STAR expr",
 /* 193 */ "expr ::= expr SLASH expr",
 /* 194 */ "expr ::= expr REM expr",
 /* 195 */ "expr ::= expr CONCAT expr",
 /* 196 */ "expr ::= expr ISNULL",
 /* 197 */ "expr ::= expr IS NULL",
 /* 198 */ "expr ::= expr NOTNULL",
 /* 199 */ "expr ::= expr NOT NULL",
 /* 200 */ "expr ::= expr IS NOT NULL",
 /* 201 */ "expr ::= NOT expr",
 /* 202 */ "expr ::= BITNOT expr",
 /* 203 */ "expr ::= MINUS expr",
 /* 204 */ "expr ::= PLUS expr",
 /* 205 */ "expr ::= LP select RP",
 /* 206 */ "expr ::= expr BETWEEN expr AND expr",
 /* 207 */ "expr ::= expr NOT BETWEEN expr AND expr",
 /* 208 */ "expr ::= expr IN LP exprlist RP",
 /* 209 */ "expr ::= expr IN LP select RP",
 /* 210 */ "expr ::= expr NOT IN LP exprlist RP",
 /* 211 */ "expr ::= expr NOT IN LP select RP",
 /* 212 */ "expr ::= CASE case_operand case_exprlist case_else END",
 /* 213 */ "case_exprlist ::= case_exprlist WHEN expr THEN expr",
 /* 214 */ "case_exprlist ::= WHEN expr THEN expr",
 /* 215 */ "case_else ::= ELSE expr",
 /* 216 */ "case_else ::=",
 /* 217 */ "case_operand ::= expr",
 /* 218 */ "case_operand ::=",
 /* 219 */ "exprlist ::= exprlist COMMA expritem",
 /* 220 */ "exprlist ::= expritem",
 /* 221 */ "expritem ::= expr",
 /* 222 */ "expritem ::=",
 /* 223 */ "cmd ::= CREATE uniqueflag INDEX ids ON ids LP idxlist RP onconf",
 /* 224 */ "uniqueflag ::= UNIQUE",
 /* 225 */ "uniqueflag ::=",
 /* 226 */ "idxlist ::= idxlist COMMA idxitem",
 /* 227 */ "idxlist ::= idxitem",
 /* 228 */ "idxitem ::= ids",
 /* 229 */ "cmd ::= DROP INDEX ids",
 /* 230 */ "cmd ::= COPY orconf ids FROM ids USING DELIMITERS STRING",
 /* 231 */ "cmd ::= COPY orconf ids FROM ids",
 /* 232 */ "cmd ::= VACUUM",
 /* 233 */ "cmd ::= VACUUM ids",
 /* 234 */ "cmd ::= PRAGMA ids EQ ids",
 /* 235 */ "cmd ::= PRAGMA ids EQ ON",
 /* 236 */ "cmd ::= PRAGMA ids EQ plus_num",
 /* 237 */ "cmd ::= PRAGMA ids EQ minus_num",
 /* 238 */ "cmd ::= PRAGMA ids LP ids RP",
 /* 239 */ "cmd ::= PRAGMA ids",
 /* 240 */ "plus_num ::= plus_opt number",
 /* 241 */ "minus_num ::= MINUS number",
 /* 242 */ "number ::= INTEGER",
 /* 243 */ "number ::= FLOAT",
 /* 244 */ "plus_opt ::= PLUS",
 /* 245 */ "plus_opt ::=",
 /* 246 */ "cmd ::= CREATE TRIGGER ids trigger_time trigger_event ON ids foreach_clause when_clause BEGIN trigger_cmd_list END",
 /* 247 */ "trigger_time ::= BEFORE",
 /* 248 */ "trigger_time ::= AFTER",
 /* 249 */ "trigger_time ::= INSTEAD OF",
 /* 250 */ "trigger_time ::=",
 /* 251 */ "trigger_event ::= DELETE",
 /* 252 */ "trigger_event ::= INSERT",
 /* 253 */ "trigger_event ::= UPDATE",
 /* 254 */ "trigger_event ::= UPDATE OF inscollist",
 /* 255 */ "foreach_clause ::=",
 /* 256 */ "foreach_clause ::= FOR EACH ROW",
 /* 257 */ "foreach_clause ::= FOR EACH STATEMENT",
 /* 258 */ "when_clause ::=",
 /* 259 */ "when_clause ::= WHEN expr",
 /* 260 */ "trigger_cmd_list ::= trigger_cmd SEMI trigger_cmd_list",
 /* 261 */ "trigger_cmd_list ::=",
 /* 262 */ "trigger_cmd ::= UPDATE orconf ids SET setlist where_opt",
 /* 263 */ "trigger_cmd ::= INSERT orconf INTO ids inscollist_opt VALUES LP itemlist RP",
 /* 264 */ "trigger_cmd ::= INSERT orconf INTO ids inscollist_opt select",
 /* 265 */ "trigger_cmd ::= DELETE FROM ids where_opt",
 /* 266 */ "trigger_cmd ::= select",
 /* 267 */ "expr ::= RAISE LP IGNORE RP",
 /* 268 */ "expr ::= RAISE LP ROLLBACK COMMA ids RP",
 /* 269 */ "expr ::= RAISE LP ABORT COMMA ids RP",
 /* 270 */ "expr ::= RAISE LP FAIL COMMA ids RP",
 /* 271 */ "cmd ::= DROP TRIGGER ids",
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
#line 627 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4162 "parse.c"
      break;
    case 150:
#line 487 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4167 "parse.c"
      break;
    case 151:
#line 646 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4172 "parse.c"
      break;
    case 152:
#line 644 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4177 "parse.c"
      break;
    case 154:
#line 312 "parse.y"
{sqliteSrcListDelete((yypminor->yy7));}
#line 4182 "parse.c"
      break;
    case 155:
#line 405 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4187 "parse.c"
      break;
    case 156:
#line 410 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4192 "parse.c"
      break;
    case 160:
#line 668 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4197 "parse.c"
      break;
    case 163:
#line 466 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4202 "parse.c"
      break;
    case 164:
#line 464 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4207 "parse.c"
      break;
    case 166:
#line 458 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4212 "parse.c"
      break;
    case 175:
#line 366 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4217 "parse.c"
      break;
    case 177:
#line 248 "parse.y"
{sqliteSelectDelete((yypminor->yy219));}
#line 4222 "parse.c"
      break;
    case 179:
#line 377 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4227 "parse.c"
      break;
    case 187:
#line 284 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4232 "parse.c"
      break;
    case 188:
#line 282 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4237 "parse.c"
      break;
    case 189:
#line 246 "parse.y"
{sqliteSelectDelete((yypminor->yy219));}
#line 4242 "parse.c"
      break;
    case 190:
#line 308 "parse.y"
{sqliteSrcListDelete((yypminor->yy7));}
#line 4247 "parse.c"
      break;
    case 191:
#line 434 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4252 "parse.c"
      break;
    case 193:
#line 381 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4257 "parse.c"
      break;
    case 194:
#line 379 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4262 "parse.c"
      break;
    case 196:
#line 310 "parse.y"
{sqliteSrcListDelete((yypminor->yy7));}
#line 4267 "parse.c"
      break;
    case 202:
#line 725 "parse.y"
{sqliteIdListDelete((yypminor->yy90).b);}
#line 4272 "parse.c"
      break;
    case 207:
#line 371 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4277 "parse.c"
      break;
    case 209:
#line 428 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4282 "parse.c"
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
  { 162, 1 },
  { 135, 1 },
  { 135, 2 },
  { 147, 3 },
  { 147, 1 },
  { 149, 1 },
  { 149, 0 },
  { 134, 3 },
  { 199, 0 },
  { 199, 1 },
  { 199, 2 },
  { 134, 2 },
  { 134, 2 },
  { 134, 2 },
  { 134, 2 },
  { 142, 4 },
  { 198, 1 },
  { 198, 0 },
  { 143, 4 },
  { 143, 2 },
  { 139, 3 },
  { 139, 1 },
  { 137, 3 },
  { 138, 1 },
  { 157, 1 },
  { 158, 1 },
  { 158, 1 },
  { 204, 0 },
  { 204, 1 },
  { 204, 4 },
  { 204, 6 },
  { 205, 1 },
  { 205, 2 },
  { 192, 1 },
  { 192, 2 },
  { 192, 2 },
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
  { 133, 3 },
  { 133, 4 },
  { 133, 2 },
  { 133, 5 },
  { 133, 1 },
  { 133, 1 },
  { 133, 2 },
  { 185, 6 },
  { 185, 3 },
  { 184, 0 },
  { 184, 2 },
  { 183, 2 },
  { 183, 2 },
  { 183, 3 },
  { 183, 3 },
  { 182, 2 },
  { 182, 2 },
  { 182, 1 },
  { 182, 1 },
  { 144, 3 },
  { 144, 2 },
  { 161, 0 },
  { 161, 2 },
  { 161, 2 },
  { 141, 0 },
  { 141, 2 },
  { 140, 3 },
  { 140, 2 },
  { 140, 1 },
  { 197, 2 },
  { 197, 6 },
  { 197, 5 },
  { 197, 3 },
  { 197, 7 },
  { 145, 0 },
  { 145, 1 },
  { 176, 0 },
  { 176, 3 },
  { 178, 0 },
  { 178, 2 },
  { 186, 1 },
  { 186, 1 },
  { 186, 1 },
  { 186, 1 },
  { 186, 1 },
  { 134, 3 },
  { 134, 5 },
  { 134, 3 },
  { 134, 1 },
  { 189, 1 },
  { 189, 3 },
  { 173, 1 },
  { 173, 2 },
  { 173, 1 },
  { 173, 1 },
  { 177, 9 },
  { 146, 1 },
  { 146, 1 },
  { 146, 0 },
  { 187, 2 },
  { 187, 0 },
  { 188, 3 },
  { 188, 2 },
  { 188, 4 },
  { 127, 2 },
  { 127, 0 },
  { 154, 0 },
  { 154, 2 },
  { 196, 2 },
  { 196, 0 },
  { 190, 5 },
  { 190, 7 },
  { 167, 1 },
  { 167, 1 },
  { 167, 2 },
  { 167, 3 },
  { 167, 4 },
  { 175, 2 },
  { 175, 0 },
  { 207, 4 },
  { 207, 0 },
  { 179, 0 },
  { 179, 3 },
  { 194, 5 },
  { 194, 2 },
  { 193, 1 },
  { 195, 1 },
  { 195, 1 },
  { 195, 0 },
  { 136, 0 },
  { 136, 2 },
  { 155, 0 },
  { 155, 3 },
  { 156, 0 },
  { 156, 2 },
  { 170, 0 },
  { 170, 2 },
  { 170, 4 },
  { 171, 1 },
  { 171, 1 },
  { 134, 4 },
  { 209, 0 },
  { 209, 2 },
  { 134, 6 },
  { 191, 5 },
  { 191, 3 },
  { 134, 8 },
  { 134, 5 },
  { 165, 2 },
  { 165, 1 },
  { 166, 3 },
  { 166, 1 },
  { 164, 0 },
  { 164, 3 },
  { 163, 3 },
  { 163, 1 },
  { 150, 3 },
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
  { 169, 1 },
  { 169, 1 },
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
  { 206, 1 },
  { 206, 0 },
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
  { 180, 2 },
  { 172, 2 },
  { 174, 1 },
  { 174, 1 },
  { 181, 1 },
  { 181, 0 },
  { 134, 12 },
  { 203, 1 },
  { 203, 1 },
  { 203, 2 },
  { 203, 0 },
  { 202, 1 },
  { 202, 1 },
  { 202, 1 },
  { 202, 3 },
  { 153, 0 },
  { 153, 3 },
  { 153, 3 },
  { 208, 0 },
  { 208, 2 },
  { 201, 3 },
  { 201, 0 },
  { 200, 6 },
  { 200, 9 },
  { 200, 6 },
  { 200, 4 },
  { 200, 1 },
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
#line 4749 "parse.c"
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
#line 4760 "parse.c"
        /* No destructor defined for EXPLAIN */
        break;
      case 6:
#line 70 "parse.y"
{ sqliteBeginParse(pParse, 0); }
#line 4766 "parse.c"
        break;
      case 7:
#line 75 "parse.y"
{sqliteBeginTransaction(pParse,yymsp[0].minor.yy172);}
#line 4771 "parse.c"
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
        /* No destructor defined for ids */
        break;
      case 11:
#line 79 "parse.y"
{sqliteCommitTransaction(pParse);}
#line 4787 "parse.c"
        /* No destructor defined for COMMIT */
        /* No destructor defined for trans_opt */
        break;
      case 12:
#line 80 "parse.y"
{sqliteCommitTransaction(pParse);}
#line 4794 "parse.c"
        /* No destructor defined for END */
        /* No destructor defined for trans_opt */
        break;
      case 13:
#line 81 "parse.y"
{sqliteRollbackTransaction(pParse);}
#line 4801 "parse.c"
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
   sqliteStartTable(pParse,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy378,yymsp[-2].minor.yy172);
}
#line 4814 "parse.c"
        /* No destructor defined for TABLE */
        break;
      case 16:
#line 90 "parse.y"
{yygotominor.yy172 = pParse->isTemp || !pParse->initFlag;}
#line 4820 "parse.c"
        /* No destructor defined for TEMP */
        break;
      case 17:
#line 91 "parse.y"
{yygotominor.yy172 = pParse->isTemp;}
#line 4826 "parse.c"
        break;
      case 18:
#line 92 "parse.y"
{
  sqliteEndTable(pParse,&yymsp[0].minor.yy0,0);
}
#line 4833 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for columnlist */
        /* No destructor defined for conslist_opt */
        break;
      case 19:
#line 95 "parse.y"
{
  sqliteEndTable(pParse,0,yymsp[0].minor.yy219);
  sqliteSelectDelete(yymsp[0].minor.yy219);
}
#line 4844 "parse.c"
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
{sqliteAddColumn(pParse,&yymsp[0].minor.yy378);}
#line 4863 "parse.c"
        break;
      case 24:
#line 113 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4868 "parse.c"
        break;
      case 25:
#line 129 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 4873 "parse.c"
        break;
      case 26:
#line 130 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4878 "parse.c"
        break;
      case 27:
        break;
      case 28:
#line 133 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[0].minor.yy378,&yymsp[0].minor.yy378);}
#line 4885 "parse.c"
        break;
      case 29:
#line 134 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-3].minor.yy378,&yymsp[0].minor.yy0);}
#line 4890 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        break;
      case 30:
#line 136 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-5].minor.yy378,&yymsp[0].minor.yy0);}
#line 4897 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        /* No destructor defined for COMMA */
        /* No destructor defined for signed */
        break;
      case 31:
#line 138 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 4906 "parse.c"
        break;
      case 32:
#line 139 "parse.y"
{yygotominor.yy378 = yymsp[-1].minor.yy378;}
#line 4911 "parse.c"
        /* No destructor defined for ids */
        break;
      case 33:
        /* No destructor defined for INTEGER */
        break;
      case 34:
        /* No destructor defined for PLUS */
        /* No destructor defined for INTEGER */
        break;
      case 35:
        /* No destructor defined for MINUS */
        /* No destructor defined for INTEGER */
        break;
      case 36:
        /* No destructor defined for carglist */
        /* No destructor defined for carg */
        break;
      case 37:
        break;
      case 38:
        /* No destructor defined for CONSTRAINT */
        /* No destructor defined for ids */
        /* No destructor defined for ccons */
        break;
      case 39:
        /* No destructor defined for ccons */
        break;
      case 40:
#line 147 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 4942 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 41:
#line 148 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 4948 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 42:
#line 149 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 4954 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 43:
#line 150 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 4960 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 44:
#line 151 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 4967 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 45:
#line 152 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 4974 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 46:
#line 153 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 4980 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 47:
#line 154 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 4987 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 48:
        /* No destructor defined for DEFAULT */
        /* No destructor defined for NULL */
        break;
      case 49:
#line 160 "parse.y"
{sqliteAddNotNull(pParse, yymsp[0].minor.yy172);}
#line 4998 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for NULL */
        break;
      case 50:
#line 161 "parse.y"
{sqliteAddPrimaryKey(pParse,0,yymsp[0].minor.yy172);}
#line 5005 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for sortorder */
        break;
      case 51:
#line 162 "parse.y"
{sqliteCreateIndex(pParse,0,0,0,yymsp[0].minor.yy172,0,0);}
#line 5013 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 52:
        /* No destructor defined for CHECK */
        /* No destructor defined for LP */
  yy_destructor(150,&yymsp[-2].minor);
        /* No destructor defined for RP */
        /* No destructor defined for onconf */
        break;
      case 53:
        /* No destructor defined for references */
        break;
      case 54:
        /* No destructor defined for defer_subclause */
        break;
      case 55:
#line 166 "parse.y"
{
   sqliteAddCollateType(pParse, sqliteCollateType(pParse, &yymsp[0].minor.yy378));
}
#line 5034 "parse.c"
        /* No destructor defined for COLLATE */
        break;
      case 56:
        /* No destructor defined for REFERENCES */
        /* No destructor defined for ids */
        /* No destructor defined for LP */
  yy_destructor(160,&yymsp[-2].minor);
        /* No destructor defined for RP */
        /* No destructor defined for refargs */
        break;
      case 57:
        /* No destructor defined for REFERENCES */
        /* No destructor defined for ids */
        /* No destructor defined for refargs */
        break;
      case 58:
        break;
      case 59:
        /* No destructor defined for refargs */
        /* No destructor defined for refarg */
        break;
      case 60:
        /* No destructor defined for MATCH */
        /* No destructor defined for FULL */
        break;
      case 61:
        /* No destructor defined for MATCH */
        /* No destructor defined for PARTIAL */
        break;
      case 62:
        /* No destructor defined for ON */
        /* No destructor defined for DELETE */
        /* No destructor defined for refact */
        break;
      case 63:
        /* No destructor defined for ON */
        /* No destructor defined for UPDATE */
        /* No destructor defined for refact */
        break;
      case 64:
        /* No destructor defined for SET */
        /* No destructor defined for NULL */
        break;
      case 65:
        /* No destructor defined for SET */
        /* No destructor defined for DEFAULT */
        break;
      case 66:
        /* No destructor defined for CASCADE */
        break;
      case 67:
        /* No destructor defined for RESTRICT */
        break;
      case 68:
        /* No destructor defined for NOT */
        /* No destructor defined for DEFERRABLE */
        /* No destructor defined for init_deferred_pred_opt */
        break;
      case 69:
        /* No destructor defined for DEFERRABLE */
        /* No destructor defined for init_deferred_pred_opt */
        break;
      case 70:
        break;
      case 71:
        /* No destructor defined for INITIALLY */
        /* No destructor defined for DEFERRED */
        break;
      case 72:
        /* No destructor defined for INITIALLY */
        /* No destructor defined for IMMEDIATE */
        break;
      case 73:
        break;
      case 74:
        /* No destructor defined for COMMA */
        /* No destructor defined for conslist */
        break;
      case 75:
        /* No destructor defined for conslist */
        /* No destructor defined for COMMA */
        /* No destructor defined for tcons */
        break;
      case 76:
        /* No destructor defined for conslist */
        /* No destructor defined for tcons */
        break;
      case 77:
        /* No destructor defined for tcons */
        break;
      case 78:
        /* No destructor defined for CONSTRAINT */
        /* No destructor defined for ids */
        break;
      case 79:
#line 201 "parse.y"
{sqliteAddPrimaryKey(pParse,yymsp[-2].minor.yy250,yymsp[0].minor.yy172);}
#line 5132 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 80:
#line 203 "parse.y"
{sqliteCreateIndex(pParse,0,0,yymsp[-2].minor.yy250,yymsp[0].minor.yy172,0,0);}
#line 5141 "parse.c"
        /* No destructor defined for UNIQUE */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 81:
        /* No destructor defined for CHECK */
  yy_destructor(150,&yymsp[-1].minor);
        /* No destructor defined for onconf */
        break;
      case 82:
        /* No destructor defined for FOREIGN */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
  yy_destructor(160,&yymsp[-3].minor);
        /* No destructor defined for RP */
        /* No destructor defined for references */
        /* No destructor defined for defer_subclause_opt */
        break;
      case 83:
        break;
      case 84:
        /* No destructor defined for defer_subclause */
        break;
      case 85:
#line 215 "parse.y"
{ yygotominor.yy172 = OE_Default; }
#line 5168 "parse.c"
        break;
      case 86:
#line 216 "parse.y"
{ yygotominor.yy172 = yymsp[0].minor.yy172; }
#line 5173 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for CONFLICT */
        break;
      case 87:
#line 217 "parse.y"
{ yygotominor.yy172 = OE_Default; }
#line 5180 "parse.c"
        break;
      case 88:
#line 218 "parse.y"
{ yygotominor.yy172 = yymsp[0].minor.yy172; }
#line 5185 "parse.c"
        /* No destructor defined for OR */
        break;
      case 89:
#line 219 "parse.y"
{ yygotominor.yy172 = OE_Rollback; }
#line 5191 "parse.c"
        /* No destructor defined for ROLLBACK */
        break;
      case 90:
#line 220 "parse.y"
{ yygotominor.yy172 = OE_Abort; }
#line 5197 "parse.c"
        /* No destructor defined for ABORT */
        break;
      case 91:
#line 221 "parse.y"
{ yygotominor.yy172 = OE_Fail; }
#line 5203 "parse.c"
        /* No destructor defined for FAIL */
        break;
      case 92:
#line 222 "parse.y"
{ yygotominor.yy172 = OE_Ignore; }
#line 5209 "parse.c"
        /* No destructor defined for IGNORE */
        break;
      case 93:
#line 223 "parse.y"
{ yygotominor.yy172 = OE_Replace; }
#line 5215 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 94:
#line 227 "parse.y"
{sqliteDropTable(pParse,&yymsp[0].minor.yy378,0);}
#line 5221 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for TABLE */
        break;
      case 95:
#line 231 "parse.y"
{
  sqliteCreateView(pParse, &yymsp[-4].minor.yy0, &yymsp[-2].minor.yy378, yymsp[0].minor.yy219);
}
#line 5230 "parse.c"
        /* No destructor defined for VIEW */
        /* No destructor defined for AS */
        break;
      case 96:
#line 234 "parse.y"
{
  sqliteDropTable(pParse, &yymsp[0].minor.yy378, 1);
}
#line 5239 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for VIEW */
        break;
      case 97:
#line 240 "parse.y"
{
  sqliteSelect(pParse, yymsp[0].minor.yy219, SRT_Callback, 0, 0, 0, 0);
  sqliteSelectDelete(yymsp[0].minor.yy219);
}
#line 5249 "parse.c"
        break;
      case 98:
#line 250 "parse.y"
{yygotominor.yy219 = yymsp[0].minor.yy219;}
#line 5254 "parse.c"
        break;
      case 99:
#line 251 "parse.y"
{
  if( yymsp[0].minor.yy219 ){
    yymsp[0].minor.yy219->op = yymsp[-1].minor.yy172;
    yymsp[0].minor.yy219->pPrior = yymsp[-2].minor.yy219;
  }
  yygotominor.yy219 = yymsp[0].minor.yy219;
}
#line 5265 "parse.c"
        break;
      case 100:
#line 259 "parse.y"
{yygotominor.yy172 = TK_UNION;}
#line 5270 "parse.c"
        /* No destructor defined for UNION */
        break;
      case 101:
#line 260 "parse.y"
{yygotominor.yy172 = TK_ALL;}
#line 5276 "parse.c"
        /* No destructor defined for UNION */
        /* No destructor defined for ALL */
        break;
      case 102:
#line 261 "parse.y"
{yygotominor.yy172 = TK_INTERSECT;}
#line 5283 "parse.c"
        /* No destructor defined for INTERSECT */
        break;
      case 103:
#line 262 "parse.y"
{yygotominor.yy172 = TK_EXCEPT;}
#line 5289 "parse.c"
        /* No destructor defined for EXCEPT */
        break;
      case 104:
#line 264 "parse.y"
{
  yygotominor.yy219 = sqliteSelectNew(yymsp[-6].minor.yy228,yymsp[-5].minor.yy7,yymsp[-4].minor.yy62,yymsp[-3].minor.yy228,yymsp[-2].minor.yy62,yymsp[-1].minor.yy228,yymsp[-7].minor.yy172,yymsp[0].minor.yy6.limit,yymsp[0].minor.yy6.offset);
}
#line 5297 "parse.c"
        /* No destructor defined for SELECT */
        break;
      case 105:
#line 272 "parse.y"
{yygotominor.yy172 = 1;}
#line 5303 "parse.c"
        /* No destructor defined for DISTINCT */
        break;
      case 106:
#line 273 "parse.y"
{yygotominor.yy172 = 0;}
#line 5309 "parse.c"
        /* No destructor defined for ALL */
        break;
      case 107:
#line 274 "parse.y"
{yygotominor.yy172 = 0;}
#line 5315 "parse.c"
        break;
      case 108:
#line 285 "parse.y"
{yygotominor.yy228 = yymsp[-1].minor.yy228;}
#line 5320 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 109:
#line 286 "parse.y"
{yygotominor.yy228 = 0;}
#line 5326 "parse.c"
        break;
      case 110:
#line 287 "parse.y"
{
   yygotominor.yy228 = sqliteExprListAppend(yymsp[-2].minor.yy228,yymsp[-1].minor.yy62,yymsp[0].minor.yy378.n?&yymsp[0].minor.yy378:0);
}
#line 5333 "parse.c"
        break;
      case 111:
#line 290 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-1].minor.yy228, sqliteExpr(TK_ALL, 0, 0, 0), 0);
}
#line 5340 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 112:
#line 293 "parse.y"
{
  Expr *pRight = sqliteExpr(TK_ALL, 0, 0, 0);
  Expr *pLeft = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy378);
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-3].minor.yy228, sqliteExpr(TK_DOT, pLeft, pRight, 0), 0);
}
#line 5350 "parse.c"
        /* No destructor defined for DOT */
        /* No destructor defined for STAR */
        break;
      case 113:
#line 303 "parse.y"
{ yygotominor.yy378 = yymsp[0].minor.yy378; }
#line 5357 "parse.c"
        /* No destructor defined for AS */
        break;
      case 114:
#line 304 "parse.y"
{ yygotominor.yy378.n = 0; }
#line 5363 "parse.c"
        break;
      case 115:
#line 316 "parse.y"
{yygotominor.yy7 = sqliteMalloc(sizeof(*yygotominor.yy7));}
#line 5368 "parse.c"
        break;
      case 116:
#line 317 "parse.y"
{yygotominor.yy7 = yymsp[0].minor.yy7;}
#line 5373 "parse.c"
        /* No destructor defined for FROM */
        break;
      case 117:
#line 322 "parse.y"
{
   yygotominor.yy7 = yymsp[-1].minor.yy7;
   if( yygotominor.yy7 && yygotominor.yy7->nSrc>0 ) yygotominor.yy7->a[yygotominor.yy7->nSrc-1].jointype = yymsp[0].minor.yy172;
}
#line 5382 "parse.c"
        break;
      case 118:
#line 326 "parse.y"
{yygotominor.yy7 = 0;}
#line 5387 "parse.c"
        break;
      case 119:
#line 327 "parse.y"
{
  yygotominor.yy7 = sqliteSrcListAppend(yymsp[-4].minor.yy7,&yymsp[-3].minor.yy378);
  if( yymsp[-2].minor.yy378.n ) sqliteSrcListAddAlias(yygotominor.yy7,&yymsp[-2].minor.yy378);
  if( yymsp[-1].minor.yy62 ){
    if( yygotominor.yy7 && yygotominor.yy7->nSrc>1 ){ yygotominor.yy7->a[yygotominor.yy7->nSrc-2].pOn = yymsp[-1].minor.yy62; }
    else { sqliteExprDelete(yymsp[-1].minor.yy62); }
  }
  if( yymsp[0].minor.yy250 ){
    if( yygotominor.yy7 && yygotominor.yy7->nSrc>1 ){ yygotominor.yy7->a[yygotominor.yy7->nSrc-2].pUsing = yymsp[0].minor.yy250; }
    else { sqliteIdListDelete(yymsp[0].minor.yy250); }
  }
}
#line 5403 "parse.c"
        break;
      case 120:
#line 339 "parse.y"
{
  yygotominor.yy7 = sqliteSrcListAppend(yymsp[-6].minor.yy7,0);
  yygotominor.yy7->a[yygotominor.yy7->nSrc-1].pSelect = yymsp[-4].minor.yy219;
  if( yymsp[-4].minor.yy219->pOrderBy ){
    sqliteExprListDelete(yymsp[-4].minor.yy219->pOrderBy);
    yymsp[-4].minor.yy219->pOrderBy = 0;
  }
  if( yymsp[-2].minor.yy378.n ) sqliteSrcListAddAlias(yygotominor.yy7,&yymsp[-2].minor.yy378);
  if( yymsp[-1].minor.yy62 ){
    if( yygotominor.yy7 && yygotominor.yy7->nSrc>1 ){ yygotominor.yy7->a[yygotominor.yy7->nSrc-2].pOn = yymsp[-1].minor.yy62; }
    else { sqliteExprDelete(yymsp[-1].minor.yy62); }
  }
  if( yymsp[0].minor.yy250 ){
    if( yygotominor.yy7 && yygotominor.yy7->nSrc>1 ){ yygotominor.yy7->a[yygotominor.yy7->nSrc-2].pUsing = yymsp[0].minor.yy250; }
    else { sqliteIdListDelete(yymsp[0].minor.yy250); }
  }
}
#line 5424 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 121:
#line 359 "parse.y"
{ yygotominor.yy172 = JT_INNER; }
#line 5431 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 122:
#line 360 "parse.y"
{ yygotominor.yy172 = JT_INNER; }
#line 5437 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 123:
#line 361 "parse.y"
{ yygotominor.yy172 = sqliteJoinType(pParse,&yymsp[-1].minor.yy0,0,0); }
#line 5443 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 124:
#line 362 "parse.y"
{ yygotominor.yy172 = sqliteJoinType(pParse,&yymsp[-2].minor.yy0,&yymsp[-1].minor.yy0,0); }
#line 5449 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 125:
#line 363 "parse.y"
{ yygotominor.yy172 = sqliteJoinType(pParse,&yymsp[-3].minor.yy0,&yymsp[-2].minor.yy0,&yymsp[-1].minor.yy0); }
#line 5455 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 126:
#line 367 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5461 "parse.c"
        /* No destructor defined for ON */
        break;
      case 127:
#line 368 "parse.y"
{yygotominor.yy62 = 0;}
#line 5467 "parse.c"
        break;
      case 128:
#line 372 "parse.y"
{yygotominor.yy250 = yymsp[-1].minor.yy250;}
#line 5472 "parse.c"
        /* No destructor defined for USING */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 129:
#line 373 "parse.y"
{yygotominor.yy250 = 0;}
#line 5480 "parse.c"
        break;
      case 130:
#line 383 "parse.y"
{yygotominor.yy228 = 0;}
#line 5485 "parse.c"
        break;
      case 131:
#line 384 "parse.y"
{yygotominor.yy228 = yymsp[0].minor.yy228;}
#line 5490 "parse.c"
        /* No destructor defined for ORDER */
        /* No destructor defined for BY */
        break;
      case 132:
#line 385 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-4].minor.yy228,yymsp[-2].minor.yy62,0);
  if( yygotominor.yy228 ) yygotominor.yy228->a[yygotominor.yy228->nExpr-1].sortOrder = yymsp[-1].minor.yy172+yymsp[0].minor.yy172;
}
#line 5500 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 133:
#line 389 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(0,yymsp[-1].minor.yy62,0);
  if( yygotominor.yy228 ) yygotominor.yy228->a[0].sortOrder = yymsp[0].minor.yy172;
}
#line 5509 "parse.c"
        break;
      case 134:
#line 393 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5514 "parse.c"
        break;
      case 135:
#line 398 "parse.y"
{yygotominor.yy172 = SQLITE_SO_ASC;}
#line 5519 "parse.c"
        /* No destructor defined for ASC */
        break;
      case 136:
#line 399 "parse.y"
{yygotominor.yy172 = SQLITE_SO_DESC;}
#line 5525 "parse.c"
        /* No destructor defined for DESC */
        break;
      case 137:
#line 400 "parse.y"
{yygotominor.yy172 = SQLITE_SO_ASC;}
#line 5531 "parse.c"
        break;
      case 138:
#line 401 "parse.y"
{yygotominor.yy172 = SQLITE_SO_UNK;}
#line 5536 "parse.c"
        break;
      case 139:
#line 402 "parse.y"
{yygotominor.yy172 = sqliteCollateType(pParse, &yymsp[0].minor.yy378);}
#line 5541 "parse.c"
        /* No destructor defined for COLLATE */
        break;
      case 140:
#line 406 "parse.y"
{yygotominor.yy228 = 0;}
#line 5547 "parse.c"
        break;
      case 141:
#line 407 "parse.y"
{yygotominor.yy228 = yymsp[0].minor.yy228;}
#line 5552 "parse.c"
        /* No destructor defined for GROUP */
        /* No destructor defined for BY */
        break;
      case 142:
#line 411 "parse.y"
{yygotominor.yy62 = 0;}
#line 5559 "parse.c"
        break;
      case 143:
#line 412 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5564 "parse.c"
        /* No destructor defined for HAVING */
        break;
      case 144:
#line 415 "parse.y"
{yygotominor.yy6.limit = -1; yygotominor.yy6.offset = 0;}
#line 5570 "parse.c"
        break;
      case 145:
#line 416 "parse.y"
{yygotominor.yy6.limit = atoi(yymsp[0].minor.yy0.z); yygotominor.yy6.offset = 0;}
#line 5575 "parse.c"
        /* No destructor defined for LIMIT */
        break;
      case 146:
#line 418 "parse.y"
{yygotominor.yy6.limit = atoi(yymsp[-2].minor.yy0.z); yygotominor.yy6.offset = atoi(yymsp[0].minor.yy0.z);}
#line 5581 "parse.c"
        /* No destructor defined for LIMIT */
        /* No destructor defined for limit_sep */
        break;
      case 147:
        /* No destructor defined for OFFSET */
        break;
      case 148:
        /* No destructor defined for COMMA */
        break;
      case 149:
#line 425 "parse.y"
{sqliteDeleteFrom(pParse, &yymsp[-1].minor.yy378, yymsp[0].minor.yy62);}
#line 5594 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 150:
#line 430 "parse.y"
{yygotominor.yy62 = 0;}
#line 5601 "parse.c"
        break;
      case 151:
#line 431 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5606 "parse.c"
        /* No destructor defined for WHERE */
        break;
      case 152:
#line 439 "parse.y"
{sqliteUpdate(pParse,&yymsp[-3].minor.yy378,yymsp[-1].minor.yy228,yymsp[0].minor.yy62,yymsp[-4].minor.yy172);}
#line 5612 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 153:
#line 442 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(yymsp[-4].minor.yy228,yymsp[0].minor.yy62,&yymsp[-2].minor.yy378);}
#line 5619 "parse.c"
        /* No destructor defined for COMMA */
        /* No destructor defined for EQ */
        break;
      case 154:
#line 443 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(0,yymsp[0].minor.yy62,&yymsp[-2].minor.yy378);}
#line 5626 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 155:
#line 448 "parse.y"
{sqliteInsert(pParse, &yymsp[-5].minor.yy378, yymsp[-1].minor.yy228, 0, yymsp[-4].minor.yy250, yymsp[-7].minor.yy172);}
#line 5632 "parse.c"
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 156:
#line 450 "parse.y"
{sqliteInsert(pParse, &yymsp[-2].minor.yy378, 0, yymsp[0].minor.yy219, yymsp[-1].minor.yy250, yymsp[-4].minor.yy172);}
#line 5641 "parse.c"
        /* No destructor defined for INTO */
        break;
      case 157:
#line 453 "parse.y"
{yygotominor.yy172 = yymsp[0].minor.yy172;}
#line 5647 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 158:
#line 454 "parse.y"
{yygotominor.yy172 = OE_Replace;}
#line 5653 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 159:
#line 460 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(yymsp[-2].minor.yy228,yymsp[0].minor.yy62,0);}
#line 5659 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 160:
#line 461 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(0,yymsp[0].minor.yy62,0);}
#line 5665 "parse.c"
        break;
      case 161:
#line 468 "parse.y"
{yygotominor.yy250 = 0;}
#line 5670 "parse.c"
        break;
      case 162:
#line 469 "parse.y"
{yygotominor.yy250 = yymsp[-1].minor.yy250;}
#line 5675 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 163:
#line 470 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(yymsp[-2].minor.yy250,&yymsp[0].minor.yy378);}
#line 5682 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 164:
#line 471 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(0,&yymsp[0].minor.yy378);}
#line 5688 "parse.c"
        break;
      case 165:
#line 489 "parse.y"
{yygotominor.yy62 = yymsp[-1].minor.yy62; sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);}
#line 5693 "parse.c"
        break;
      case 166:
#line 490 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_NULL, 0, 0, &yymsp[0].minor.yy0);}
#line 5698 "parse.c"
        break;
      case 167:
#line 491 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy378);}
#line 5703 "parse.c"
        break;
      case 168:
#line 492 "parse.y"
{
  Expr *temp1 = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy378);
  Expr *temp2 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy378);
  yygotominor.yy62 = sqliteExpr(TK_DOT, temp1, temp2, 0);
}
#line 5712 "parse.c"
        /* No destructor defined for DOT */
        break;
      case 169:
#line 497 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_INTEGER, 0, 0, &yymsp[0].minor.yy0);}
#line 5718 "parse.c"
        break;
      case 170:
#line 498 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_FLOAT, 0, 0, &yymsp[0].minor.yy0);}
#line 5723 "parse.c"
        break;
      case 171:
#line 499 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_STRING, 0, 0, &yymsp[0].minor.yy0);}
#line 5728 "parse.c"
        break;
      case 172:
#line 500 "parse.y"
{
  yygotominor.yy62 = sqliteExprFunction(yymsp[-1].minor.yy228, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 5736 "parse.c"
        /* No destructor defined for LP */
        break;
      case 173:
#line 504 "parse.y"
{
  yygotominor.yy62 = sqliteExprFunction(0, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 5745 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for STAR */
        break;
      case 174:
#line 508 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_AND, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5752 "parse.c"
        /* No destructor defined for AND */
        break;
      case 175:
#line 509 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_OR, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5758 "parse.c"
        /* No destructor defined for OR */
        break;
      case 176:
#line 510 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_LT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5764 "parse.c"
        /* No destructor defined for LT */
        break;
      case 177:
#line 511 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_GT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5770 "parse.c"
        /* No destructor defined for GT */
        break;
      case 178:
#line 512 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_LE, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5776 "parse.c"
        /* No destructor defined for LE */
        break;
      case 179:
#line 513 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_GE, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5782 "parse.c"
        /* No destructor defined for GE */
        break;
      case 180:
#line 514 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_NE, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5788 "parse.c"
        /* No destructor defined for NE */
        break;
      case 181:
#line 515 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_EQ, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5794 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 182:
#line 516 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_BITAND, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5800 "parse.c"
        /* No destructor defined for BITAND */
        break;
      case 183:
#line 517 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_BITOR, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5806 "parse.c"
        /* No destructor defined for BITOR */
        break;
      case 184:
#line 518 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_LSHIFT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5812 "parse.c"
        /* No destructor defined for LSHIFT */
        break;
      case 185:
#line 519 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_RSHIFT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5818 "parse.c"
        /* No destructor defined for RSHIFT */
        break;
      case 186:
#line 520 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[0].minor.yy62, 0);
  pList = sqliteExprListAppend(pList, yymsp[-2].minor.yy62, 0);
  yygotominor.yy62 = sqliteExprFunction(pList, &yymsp[-1].minor.yy378);
  sqliteExprSpan(yygotominor.yy62, &yymsp[-2].minor.yy62->span, &yymsp[0].minor.yy62->span);
}
#line 5829 "parse.c"
        break;
      case 187:
#line 526 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[0].minor.yy62, 0);
  pList = sqliteExprListAppend(pList, yymsp[-3].minor.yy62, 0);
  yygotominor.yy62 = sqliteExprFunction(pList, &yymsp[-1].minor.yy378);
  yygotominor.yy62 = sqliteExpr(TK_NOT, yygotominor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy62->span,&yymsp[0].minor.yy62->span);
}
#line 5840 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 188:
#line 533 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 5846 "parse.c"
        break;
      case 189:
#line 534 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 5851 "parse.c"
        break;
      case 190:
#line 535 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_PLUS, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5856 "parse.c"
        /* No destructor defined for PLUS */
        break;
      case 191:
#line 536 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_MINUS, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5862 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 192:
#line 537 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_STAR, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5868 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 193:
#line 538 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_SLASH, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5874 "parse.c"
        /* No destructor defined for SLASH */
        break;
      case 194:
#line 539 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_REM, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5880 "parse.c"
        /* No destructor defined for REM */
        break;
      case 195:
#line 540 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_CONCAT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5886 "parse.c"
        /* No destructor defined for CONCAT */
        break;
      case 196:
#line 541 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_ISNULL, yymsp[-1].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5895 "parse.c"
        break;
      case 197:
#line 545 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_ISNULL, yymsp[-2].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5903 "parse.c"
        /* No destructor defined for IS */
        break;
      case 198:
#line 549 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOTNULL, yymsp[-1].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5912 "parse.c"
        break;
      case 199:
#line 553 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOTNULL, yymsp[-2].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5920 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 200:
#line 557 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOTNULL, yymsp[-3].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5929 "parse.c"
        /* No destructor defined for IS */
        /* No destructor defined for NOT */
        break;
      case 201:
#line 561 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOT, yymsp[0].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 5939 "parse.c"
        break;
      case 202:
#line 565 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_BITNOT, yymsp[0].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 5947 "parse.c"
        break;
      case 203:
#line 569 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_UMINUS, yymsp[0].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 5955 "parse.c"
        break;
      case 204:
#line 573 "parse.y"
{
  yygotominor.yy62 = yymsp[0].minor.yy62;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 5963 "parse.c"
        break;
      case 205:
#line 577 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_SELECT, 0, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pSelect = yymsp[-1].minor.yy219;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);
}
#line 5972 "parse.c"
        break;
      case 206:
#line 582 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy62, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy62, 0);
  yygotominor.yy62 = sqliteExpr(TK_BETWEEN, yymsp[-4].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = pList;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-4].minor.yy62->span,&yymsp[0].minor.yy62->span);
}
#line 5983 "parse.c"
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 207:
#line 589 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy62, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy62, 0);
  yygotominor.yy62 = sqliteExpr(TK_BETWEEN, yymsp[-5].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = pList;
  yygotominor.yy62 = sqliteExpr(TK_NOT, yygotominor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-5].minor.yy62->span,&yymsp[0].minor.yy62->span);
}
#line 5997 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 208:
#line 597 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_IN, yymsp[-4].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = yymsp[-1].minor.yy228;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-4].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 6009 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 209:
#line 602 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_IN, yymsp[-4].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pSelect = yymsp[-1].minor.yy219;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-4].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 6020 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 210:
#line 607 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_IN, yymsp[-5].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = yymsp[-1].minor.yy228;
  yygotominor.yy62 = sqliteExpr(TK_NOT, yygotominor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-5].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 6032 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 211:
#line 613 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_IN, yymsp[-5].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pSelect = yymsp[-1].minor.yy219;
  yygotominor.yy62 = sqliteExpr(TK_NOT, yygotominor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-5].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 6045 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 212:
#line 621 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_CASE, yymsp[-3].minor.yy62, yymsp[-1].minor.yy62, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = yymsp[-2].minor.yy228;
  sqliteExprSpan(yygotominor.yy62, &yymsp[-4].minor.yy0, &yymsp[0].minor.yy0);
}
#line 6057 "parse.c"
        break;
      case 213:
#line 628 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-4].minor.yy228, yymsp[-2].minor.yy62, 0);
  yygotominor.yy228 = sqliteExprListAppend(yygotominor.yy228, yymsp[0].minor.yy62, 0);
}
#line 6065 "parse.c"
        /* No destructor defined for WHEN */
        /* No destructor defined for THEN */
        break;
      case 214:
#line 632 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(0, yymsp[-2].minor.yy62, 0);
  yygotominor.yy228 = sqliteExprListAppend(yygotominor.yy228, yymsp[0].minor.yy62, 0);
}
#line 6075 "parse.c"
        /* No destructor defined for WHEN */
        /* No destructor defined for THEN */
        break;
      case 215:
#line 637 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 6082 "parse.c"
        /* No destructor defined for ELSE */
        break;
      case 216:
#line 638 "parse.y"
{yygotominor.yy62 = 0;}
#line 6088 "parse.c"
        break;
      case 217:
#line 640 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 6093 "parse.c"
        break;
      case 218:
#line 641 "parse.y"
{yygotominor.yy62 = 0;}
#line 6098 "parse.c"
        break;
      case 219:
#line 649 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(yymsp[-2].minor.yy228,yymsp[0].minor.yy62,0);}
#line 6103 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 220:
#line 650 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(0,yymsp[0].minor.yy62,0);}
#line 6109 "parse.c"
        break;
      case 221:
#line 651 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 6114 "parse.c"
        break;
      case 222:
#line 652 "parse.y"
{yygotominor.yy62 = 0;}
#line 6119 "parse.c"
        break;
      case 223:
#line 657 "parse.y"
{
  if( yymsp[-8].minor.yy172!=OE_None ) yymsp[-8].minor.yy172 = yymsp[0].minor.yy172;
  if( yymsp[-8].minor.yy172==OE_Default) yymsp[-8].minor.yy172 = OE_Abort;
  sqliteCreateIndex(pParse, &yymsp[-6].minor.yy378, &yymsp[-4].minor.yy378, yymsp[-2].minor.yy250, yymsp[-8].minor.yy172, &yymsp[-9].minor.yy0, &yymsp[-1].minor.yy0);
}
#line 6128 "parse.c"
        /* No destructor defined for INDEX */
        /* No destructor defined for ON */
        /* No destructor defined for LP */
        break;
      case 224:
#line 664 "parse.y"
{ yygotominor.yy172 = OE_Abort; }
#line 6136 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 225:
#line 665 "parse.y"
{ yygotominor.yy172 = OE_None; }
#line 6142 "parse.c"
        break;
      case 226:
#line 672 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(yymsp[-2].minor.yy250,&yymsp[0].minor.yy378);}
#line 6147 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 227:
#line 674 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(0,&yymsp[0].minor.yy378);}
#line 6153 "parse.c"
        break;
      case 228:
#line 675 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 6158 "parse.c"
        break;
      case 229:
#line 680 "parse.y"
{sqliteDropIndex(pParse, &yymsp[0].minor.yy378);}
#line 6163 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for INDEX */
        break;
      case 230:
#line 686 "parse.y"
{sqliteCopy(pParse,&yymsp[-5].minor.yy378,&yymsp[-3].minor.yy378,&yymsp[0].minor.yy0,yymsp[-6].minor.yy172);}
#line 6170 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        /* No destructor defined for USING */
        /* No destructor defined for DELIMITERS */
        break;
      case 231:
#line 688 "parse.y"
{sqliteCopy(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,0,yymsp[-3].minor.yy172);}
#line 6179 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        break;
      case 232:
#line 692 "parse.y"
{sqliteVacuum(pParse,0);}
#line 6186 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 233:
#line 693 "parse.y"
{sqliteVacuum(pParse,&yymsp[0].minor.yy378);}
#line 6192 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 234:
#line 697 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,0);}
#line 6198 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 235:
#line 698 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy0,0);}
#line 6205 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 236:
#line 699 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,0);}
#line 6212 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 237:
#line 700 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,1);}
#line 6219 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 238:
#line 701 "parse.y"
{sqlitePragma(pParse,&yymsp[-3].minor.yy378,&yymsp[-1].minor.yy378,0);}
#line 6226 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 239:
#line 702 "parse.y"
{sqlitePragma(pParse,&yymsp[0].minor.yy378,&yymsp[0].minor.yy378,0);}
#line 6234 "parse.c"
        /* No destructor defined for PRAGMA */
        break;
      case 240:
#line 703 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 6240 "parse.c"
        /* No destructor defined for plus_opt */
        break;
      case 241:
#line 704 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 6246 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 242:
#line 705 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 6252 "parse.c"
        break;
      case 243:
#line 706 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 6257 "parse.c"
        break;
      case 244:
        /* No destructor defined for PLUS */
        break;
      case 245:
        break;
      case 246:
#line 713 "parse.y"
{
  sqliteCreateTrigger(pParse, &yymsp[-9].minor.yy378, yymsp[-8].minor.yy172, yymsp[-7].minor.yy90.a, yymsp[-7].minor.yy90.b, &yymsp[-5].minor.yy378, yymsp[-4].minor.yy172, yymsp[-3].minor.yy308, yymsp[-1].minor.yy311, 
      yymsp[-11].minor.yy0.z, (int)(yymsp[0].minor.yy0.z - yymsp[-11].minor.yy0.z) + yymsp[0].minor.yy0.n );
}
#line 6270 "parse.c"
        /* No destructor defined for TRIGGER */
        /* No destructor defined for ON */
        /* No destructor defined for BEGIN */
        break;
      case 247:
#line 719 "parse.y"
{ yygotominor.yy172 = TK_BEFORE; }
#line 6278 "parse.c"
        /* No destructor defined for BEFORE */
        break;
      case 248:
#line 720 "parse.y"
{ yygotominor.yy172 = TK_AFTER;  }
#line 6284 "parse.c"
        /* No destructor defined for AFTER */
        break;
      case 249:
#line 721 "parse.y"
{ yygotominor.yy172 = TK_INSTEAD;}
#line 6290 "parse.c"
        /* No destructor defined for INSTEAD */
        /* No destructor defined for OF */
        break;
      case 250:
#line 722 "parse.y"
{ yygotominor.yy172 = TK_BEFORE; }
#line 6297 "parse.c"
        break;
      case 251:
#line 726 "parse.y"
{ yygotominor.yy90.a = TK_DELETE; yygotominor.yy90.b = 0; }
#line 6302 "parse.c"
        /* No destructor defined for DELETE */
        break;
      case 252:
#line 727 "parse.y"
{ yygotominor.yy90.a = TK_INSERT; yygotominor.yy90.b = 0; }
#line 6308 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 253:
#line 728 "parse.y"
{ yygotominor.yy90.a = TK_UPDATE; yygotominor.yy90.b = 0;}
#line 6314 "parse.c"
        /* No destructor defined for UPDATE */
        break;
      case 254:
#line 729 "parse.y"
{yygotominor.yy90.a = TK_UPDATE; yygotominor.yy90.b = yymsp[0].minor.yy250; }
#line 6320 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for OF */
        break;
      case 255:
#line 732 "parse.y"
{ yygotominor.yy172 = TK_ROW; }
#line 6327 "parse.c"
        break;
      case 256:
#line 733 "parse.y"
{ yygotominor.yy172 = TK_ROW; }
#line 6332 "parse.c"
        /* No destructor defined for FOR */
        /* No destructor defined for EACH */
        /* No destructor defined for ROW */
        break;
      case 257:
#line 734 "parse.y"
{ yygotominor.yy172 = TK_STATEMENT; }
#line 6340 "parse.c"
        /* No destructor defined for FOR */
        /* No destructor defined for EACH */
        /* No destructor defined for STATEMENT */
        break;
      case 258:
#line 737 "parse.y"
{ yygotominor.yy308 = 0; }
#line 6348 "parse.c"
        break;
      case 259:
#line 738 "parse.y"
{ yygotominor.yy308 = yymsp[0].minor.yy62; }
#line 6353 "parse.c"
        /* No destructor defined for WHEN */
        break;
      case 260:
#line 741 "parse.y"
{
  yymsp[-2].minor.yy311->pNext = yymsp[0].minor.yy311 ; yygotominor.yy311 = yymsp[-2].minor.yy311; }
#line 6360 "parse.c"
        /* No destructor defined for SEMI */
        break;
      case 261:
#line 743 "parse.y"
{ yygotominor.yy311 = 0; }
#line 6366 "parse.c"
        break;
      case 262:
#line 748 "parse.y"
{ yygotominor.yy311 = sqliteTriggerUpdateStep(&yymsp[-3].minor.yy378, yymsp[-1].minor.yy228, yymsp[0].minor.yy62, yymsp[-4].minor.yy172); }
#line 6371 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 263:
#line 753 "parse.y"
{yygotominor.yy311 = sqliteTriggerInsertStep(&yymsp[-5].minor.yy378, yymsp[-4].minor.yy250, yymsp[-1].minor.yy228, 0, yymsp[-7].minor.yy172);}
#line 6378 "parse.c"
        /* No destructor defined for INSERT */
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 264:
#line 756 "parse.y"
{yygotominor.yy311 = sqliteTriggerInsertStep(&yymsp[-2].minor.yy378, yymsp[-1].minor.yy250, 0, yymsp[0].minor.yy219, yymsp[-4].minor.yy172);}
#line 6388 "parse.c"
        /* No destructor defined for INSERT */
        /* No destructor defined for INTO */
        break;
      case 265:
#line 760 "parse.y"
{yygotominor.yy311 = sqliteTriggerDeleteStep(&yymsp[-1].minor.yy378, yymsp[0].minor.yy62);}
#line 6395 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 266:
#line 763 "parse.y"
{yygotominor.yy311 = sqliteTriggerSelectStep(yymsp[0].minor.yy219); }
#line 6402 "parse.c"
        break;
      case 267:
#line 766 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, 0); 
    yygotominor.yy62->iColumn = OE_Ignore; sqliteExprSpan(yygotominor.yy62, &yymsp[-3].minor.yy0, &yymsp[0].minor.yy0);}
#line 6408 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for IGNORE */
        break;
      case 268:
#line 769 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy378); 
    yygotominor.yy62->iColumn = OE_Rollback; sqliteExprSpan(yygotominor.yy62, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);}
#line 6416 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for ROLLBACK */
        /* No destructor defined for COMMA */
        break;
      case 269:
#line 772 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy378); 
    yygotominor.yy62->iColumn = OE_Abort; sqliteExprSpan(yygotominor.yy62, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);}
#line 6425 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for ABORT */
        /* No destructor defined for COMMA */
        break;
      case 270:
#line 775 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy378); 
    yygotominor.yy62->iColumn = OE_Fail; sqliteExprSpan(yygotominor.yy62, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);}
#line 6434 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for FAIL */
        /* No destructor defined for COMMA */
        break;
      case 271:
#line 779 "parse.y"
{
    sqliteDropTrigger(pParse,&yymsp[0].minor.yy378,0);
}
#line 6444 "parse.c"
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

#line 6494 "parse.c"
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
