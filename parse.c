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
#define YYNSTATE 521
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
  {  27,   0, 489}, /*  1:                   COPY shift  489 */
  {  28,   0, 370}, /*  2:                 CREATE shift  370 */
  { 177,   1,  66}, /*  3:              oneselect shift  66 */
  { 103,   2,  70}, /*  4:                 SELECT shift  70 */
  { 104,   0, 518}, /*  5:                   SEMI shift  518 */
  {   9,   0,   6}, /*  6:                  BEGIN shift  6 */
  {  37,   0, 457}, /*  7:                   DROP shift  457 */
  {  32,   0, 467}, /*  8:                 DELETE shift  467 */
  {  64,   0, 486}, /*  9:                 INSERT shift  486 */
  { 134,   6, 516}, /* 10:                    cmd shift  516 */
  { 135,   0,   1}, /* 11:                cmdlist shift  1 */
  {  40,   0,  24}, /* 12:                    END shift  24 */
  { 162,   7, 794}, /* 13:                  input accept */
  {  92,   0, 499}, /* 14:                 PRAGMA shift  499 */
  { 189,   9, 466}, /* 15:                 select shift  466 */
  { 165,  12, 477}, /* 16:             insert_cmd shift  477 */
  { 122,  19, 497}, /* 17:                 VACUUM shift  497 */
  { 142,  14,  28}, /* 18:           create_table shift  28 */
  {  97,   0, 488}, /* 19:                REPLACE shift  488 */
  {  44,   0, 519}, /* 20:                EXPLAIN shift  519 */
  { 120,   0, 471}, /* 21:                 UPDATE shift  471 */
  {  99,   0,  26}, /* 22:               ROLLBACK shift  26 */
  { 147,  17, 520}, /* 23:                   ecmd shift  520 */
  {  23,   0,  22}, /* 24:                 COMMIT shift  22 */
  { 149,  22,   3}, /* 25:                explain shift  3 */
/* State 1 */
  { 120,   7, 471}, /*  1:                 UPDATE shift  471 */
  {  97,   0, 488}, /*  2:                REPLACE shift  488 */
  { 122,   0, 497}, /*  3:                 VACUUM shift  497 */
  { 147,  11,   2}, /*  4:                   ecmd shift  2 */
  {  28,   0, 370}, /*  5:                 CREATE shift  370 */
  { 149,   0,   3}, /*  6:                explain shift  3 */
  {   0,   0, 521}, /*  7:                      $ reduce 0 */
  { 103,   0,  70}, /*  8:                 SELECT shift  70 */
  { 104,  12, 518}, /*  9:                   SEMI shift  518 */
  { 177,  13,  66}, /* 10:              oneselect shift  66 */
  {  99,  16,  26}, /* 11:               ROLLBACK shift  26 */
  {  32,   0, 467}, /* 12:                 DELETE shift  467 */
  {   9,   0,   6}, /* 13:                  BEGIN shift  6 */
  {  37,   0, 457}, /* 14:                   DROP shift  457 */
  { 134,   0, 516}, /* 15:                    cmd shift  516 */
  {  27,   0, 489}, /* 16:                   COPY shift  489 */
  {  64,  18, 486}, /* 17:                 INSERT shift  486 */
  {  40,   0,  24}, /* 18:                    END shift  24 */
  {  44,   0, 519}, /* 19:                EXPLAIN shift  519 */
  { 165,   0, 477}, /* 20:             insert_cmd shift  477 */
  {  92,  19, 499}, /* 21:                 PRAGMA shift  499 */
  { 189,  20, 466}, /* 22:                 select shift  466 */
  { 142,   0,  28}, /* 23:           create_table shift  28 */
  {  23,   0,  22}, /* 24:                 COMMIT shift  22 */
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
  { 104,   0, 606}, /*  2:                   SEMI reduce 85 */
  { 176,   2,   8}, /*  3:                 onconf shift  8 */
/* State 8 */
  { 104,   0, 528}, /*  1:                   SEMI reduce 7 */
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
  { 104,   0, 529}, /*  3:                   SEMI reduce 8 */
/* State 23 */
  { 104,   0, 532}, /*  1:                   SEMI reduce 11 */
/* State 24 */
  { 114,   0,  17}, /*  1:            TRANSACTION shift  17 */
  { 199,   0,  25}, /*  2:              trans_opt shift  25 */
  { 104,   0, 529}, /*  3:                   SEMI reduce 8 */
/* State 25 */
  { 104,   0, 533}, /*  1:                   SEMI reduce 12 */
/* State 26 */
  { 114,   0,  17}, /*  1:            TRANSACTION shift  17 */
  { 199,   0,  27}, /*  2:              trans_opt shift  27 */
  { 104,   0, 529}, /*  3:                   SEMI reduce 8 */
/* State 27 */
  { 104,   0, 534}, /*  1:                   SEMI reduce 13 */
/* State 28 */
  {   6,   0, 368}, /*  1:                     AS shift  368 */
  {  76,   0,  30}, /*  2:                     LP shift  30 */
  { 143,   0,  29}, /*  3:      create_table_args shift  29 */
/* State 29 */
  { 104,   0, 535}, /*  1:                   SEMI reduce 14 */
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
  { 101,   0, 594}, /*  3:                     RP reduce 73 */
/* State 32 */
  { 101,   0,  33}, /*  1:                     RP shift  33 */
/* State 33 */
  { 104,   0, 539}, /*  1:                   SEMI reduce 18 */
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
  {  36,   0, 546}, /*  1:                    DOT reduce 25 */
/* State 64 */
  {  36,   0, 547}, /*  1:                    DOT reduce 26 */
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
  {  66,   0, 668}, /*  1:                INTEGER reduce 147 */
/* State 84 */
  {  66,   0, 669}, /*  1:                INTEGER reduce 148 */
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
  { 103,   0, 621}, /*  2:                 SELECT reduce 100 */
/* State 158 */
  { 103,   0, 622}, /*  1:                 SELECT reduce 101 */
/* State 159 */
  { 103,   0, 623}, /*  1:                 SELECT reduce 102 */
/* State 160 */
  { 103,   0, 624}, /*  1:                 SELECT reduce 103 */
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
  { 125,   1, 739}, /*  7:                   WHEN reduce 218 */
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
  { 125,   3, 738}, /* 14:                   WHEN reduce 217 */
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
  {  40,   0, 737}, /*  1:                    END reduce 216 */
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
  {  40,   0, 736}, /*  3:                    END reduce 215 */
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
  { 101,   5, 595}, /*  4:                     RP reduce 74 */
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
  { 104,   0, 540}, /*  5:                   SEMI reduce 19 */
/* State 370 */
  { 112,   0, 374}, /*  1:                   TEMP shift  374 */
  { 198,   3, 371}, /*  2:                   temp shift  371 */
  {  62,   0, 746}, /*  3:                  INDEX reduce 225 */
  { 115,   0, 389}, /*  4:                TRIGGER shift  389 */
  { 124,   0, 375}, /*  5:                   VIEW shift  375 */
  { 111,   0, 538}, /*  6:                  TABLE reduce 17 */
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
  { 111,   0, 537}, /*  1:                  TABLE reduce 16 */
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
  { 104,   0, 616}, /*  5:                   SEMI reduce 95 */
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
  { 104,   0, 606}, /*  2:                   SEMI reduce 85 */
  { 176,   2, 387}, /*  3:                 onconf shift  387 */
/* State 387 */
  { 104,   0, 744}, /*  1:                   SEMI reduce 223 */
/* State 388 */
  {  62,   0, 745}, /*  1:                  INDEX reduce 224 */
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
  {   9,   0, 779}, /*  1:                  BEGIN reduce 258 */
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
  {  40,   0, 782}, /*  9:                    END reduce 261 */
/* State 398 */
  { 118,   2, 157}, /*  1:                  UNION shift  157 */
  {  43,   0, 160}, /*  2:                 EXCEPT shift  160 */
  {  67,   0, 159}, /*  3:              INTERSECT shift  159 */
  { 173,   1,  68}, /*  4:         multiselect_op shift  68 */
  { 104,   0, 787}, /*  5:                   SEMI reduce 266 */
/* State 399 */
  {  40,   0, 400}, /*  1:                    END shift  400 */
/* State 400 */
  { 104,   0, 767}, /*  1:                   SEMI reduce 246 */
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
  {  40,   0, 782}, /*  9:                    END reduce 261 */
/* State 403 */
  {  40,   0, 781}, /*  1:                    END reduce 260 */
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
  { 104,   0, 671}, /*  1:                   SEMI reduce 150 */
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
  { 104,   0, 783}, /*  1:                   SEMI reduce 262 */
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
  {  68,   0, 608}, /*  3:                   INTO reduce 87 */
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
  { 104,   0, 785}, /*  5:                   SEMI reduce 264 */
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
  { 104,   0, 784}, /*  1:                   SEMI reduce 263 */
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
  { 104,   0, 671}, /*  2:                   SEMI reduce 150 */
  { 209,   2, 441}, /*  3:              where_opt shift  441 */
/* State 441 */
  { 104,   0, 786}, /*  1:                   SEMI reduce 265 */
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
  {   9,   0, 780}, /* 10:                  BEGIN reduce 259 */
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
  {  87,   0, 772}, /*  1:                     ON reduce 251 */
/* State 449 */
  {  87,   0, 773}, /*  1:                     ON reduce 252 */
/* State 450 */
  {  85,   0, 451}, /*  1:                     OF shift  451 */
  {  87,   1, 774}, /*  2:                     ON reduce 253 */
/* State 451 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  {  57,   0,  19}, /*  2:                     ID shift  19 */
  { 157,   2,  20}, /*  3:                     id shift  20 */
  { 163,   5, 452}, /*  4:             inscollist shift  452 */
  { 158,   0, 428}, /*  5:                    ids shift  428 */
/* State 452 */
  {  21,   0, 426}, /*  1:                  COMMA shift  426 */
  {  87,   1, 775}, /*  2:                     ON reduce 254 */
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
  { 104,   0, 615}, /*  1:                   SEMI reduce 94 */
/* State 460 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 461}, /*  3:                    ids shift  461 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 461 */
  { 104,   0, 617}, /*  1:                   SEMI reduce 96 */
/* State 462 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 463}, /*  3:                    ids shift  463 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 463 */
  { 104,   0, 750}, /*  1:                   SEMI reduce 229 */
/* State 464 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 465}, /*  3:                    ids shift  465 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 465 */
  { 104,   0, 792}, /*  1:                   SEMI reduce 271 */
/* State 466 */
  { 118,   2, 157}, /*  1:                  UNION shift  157 */
  {  43,   0, 160}, /*  2:                 EXCEPT shift  160 */
  {  67,   0, 159}, /*  3:              INTERSECT shift  159 */
  { 173,   1,  68}, /*  4:         multiselect_op shift  68 */
  { 104,   0, 618}, /*  5:                   SEMI reduce 97 */
/* State 467 */
  {  49,   0, 468}, /*  1:                   FROM shift  468 */
/* State 468 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 469}, /*  3:                    ids shift  469 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 469 */
  { 126,   0, 226}, /*  1:                  WHERE shift  226 */
  { 104,   0, 671}, /*  2:                   SEMI reduce 150 */
  { 209,   2, 470}, /*  3:              where_opt shift  470 */
/* State 470 */
  { 104,   0, 670}, /*  1:                   SEMI reduce 149 */
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
  { 104,   0, 671}, /*  1:                   SEMI reduce 150 */
  { 209,   4, 476}, /*  2:              where_opt shift  476 */
  { 126,   0, 226}, /*  3:                  WHERE shift  226 */
  {  21,   0, 411}, /*  4:                  COMMA shift  411 */
/* State 476 */
  { 104,   0, 673}, /*  1:                   SEMI reduce 152 */
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
  { 104,   0, 677}, /*  5:                   SEMI reduce 156 */
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
  { 104,   0, 676}, /*  1:                   SEMI reduce 155 */
/* State 486 */
  {  88,   0, 405}, /*  1:                     OR shift  405 */
  { 178,   1, 487}, /*  2:                 orconf shift  487 */
  {  68,   0, 608}, /*  3:                   INTO reduce 87 */
/* State 487 */
  {  68,   0, 678}, /*  1:                   INTO reduce 157 */
/* State 488 */
  {  68,   0, 679}, /*  1:                   INTO reduce 158 */
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
  { 104,   0, 752}, /*  1:                   SEMI reduce 231 */
  { 121,   0, 494}, /*  2:                  USING shift  494 */
/* State 494 */
  {  33,   0, 495}, /*  1:             DELIMITERS shift  495 */
/* State 495 */
  { 110,   0, 496}, /*  1:                 STRING shift  496 */
/* State 496 */
  { 104,   0, 751}, /*  1:                   SEMI reduce 230 */
/* State 497 */
  { 110,   0,  21}, /*  1:                 STRING shift  21 */
  {  57,   0,  19}, /*  2:                     ID shift  19 */
  { 157,   2,  20}, /*  3:                     id shift  20 */
  { 158,   0, 498}, /*  4:                    ids shift  498 */
  { 104,   0, 753}, /*  5:                   SEMI reduce 232 */
/* State 498 */
  { 104,   0, 754}, /*  1:                   SEMI reduce 233 */
/* State 499 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 500}, /*  3:                    ids shift  500 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 500 */
  {  42,   0, 501}, /*  1:                     EQ shift  501 */
  {  76,   0, 513}, /*  2:                     LP shift  513 */
  { 104,   0, 760}, /*  3:                   SEMI reduce 239 */
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
  { 104,   0, 755}, /*  1:                   SEMI reduce 234 */
/* State 503 */
  { 104,   0, 756}, /*  1:                   SEMI reduce 235 */
/* State 504 */
  { 104,   0, 757}, /*  1:                   SEMI reduce 236 */
/* State 505 */
  { 104,   0, 758}, /*  1:                   SEMI reduce 237 */
/* State 506 */
  { 174,   3, 507}, /*  1:                 number shift  507 */
  {  46,   0, 509}, /*  2:                  FLOAT shift  509 */
  {  66,   0, 508}, /*  3:                INTEGER shift  508 */
/* State 507 */
  { 104,   0, 761}, /*  1:                   SEMI reduce 240 */
/* State 508 */
  { 104,   0, 763}, /*  1:                   SEMI reduce 242 */
/* State 509 */
  { 104,   0, 764}, /*  1:                   SEMI reduce 243 */
/* State 510 */
  { 174,   3, 511}, /*  1:                 number shift  511 */
  {  46,   0, 509}, /*  2:                  FLOAT shift  509 */
  {  66,   0, 508}, /*  3:                INTEGER shift  508 */
/* State 511 */
  { 104,   0, 762}, /*  1:                   SEMI reduce 241 */
/* State 513 */
  {  57,   0,  19}, /*  1:                     ID shift  19 */
  { 157,   1,  20}, /*  2:                     id shift  20 */
  { 158,   4, 514}, /*  3:                    ids shift  514 */
  { 110,   0,  21}, /*  4:                 STRING shift  21 */
/* State 514 */
  { 101,   0, 515}, /*  1:                     RP shift  515 */
/* State 515 */
  { 104,   0, 759}, /*  1:                   SEMI reduce 238 */
/* State 516 */
  { 104,   0, 517}, /*  1:                   SEMI shift  517 */
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
  { &yyActionTable[0],  25, 793 },
  { &yyActionTable[25],  24, 793 },
  { &yyActionTable[49],   0, 523 },
  { &yyActionTable[49],  19, 793 },
  { &yyActionTable[68],   1, 793 },
  { &yyActionTable[69],   0, 524 },
  { &yyActionTable[69],   2, 529 },
  { &yyActionTable[71],   3, 793 },
  { &yyActionTable[74],   1, 793 },
  { &yyActionTable[75],   1, 793 },
  { &yyActionTable[76],   6, 793 },
  { &yyActionTable[82],   0, 607 },
  { &yyActionTable[82],   0, 610 },
  { &yyActionTable[82],   0, 611 },
  { &yyActionTable[82],   0, 612 },
  { &yyActionTable[82],   0, 613 },
  { &yyActionTable[82],   0, 614 },
  { &yyActionTable[82],   4, 530 },
  { &yyActionTable[86],   0, 531 },
  { &yyActionTable[86],   0, 545 },
  { &yyActionTable[86],   0, 546 },
  { &yyActionTable[86],   0, 547 },
  { &yyActionTable[86],   3, 793 },
  { &yyActionTable[89],   1, 793 },
  { &yyActionTable[90],   3, 793 },
  { &yyActionTable[93],   1, 793 },
  { &yyActionTable[94],   3, 793 },
  { &yyActionTable[97],   1, 793 },
  { &yyActionTable[98],   3, 793 },
  { &yyActionTable[101],   1, 793 },
  { &yyActionTable[102],   7, 793 },
  { &yyActionTable[109],   3, 793 },
  { &yyActionTable[112],   1, 793 },
  { &yyActionTable[113],   1, 793 },
  { &yyActionTable[114],  13, 793 },
  { &yyActionTable[127],   0, 541 },
  { &yyActionTable[127],   6, 548 },
  { &yyActionTable[133],   1, 558 },
  { &yyActionTable[134],  13, 543 },
  { &yyActionTable[147],   0, 557 },
  { &yyActionTable[147],   4, 793 },
  { &yyActionTable[151],  10, 793 },
  { &yyActionTable[161],   0, 559 },
  { &yyActionTable[161],   2, 793 },
  { &yyActionTable[163],   2, 606 },
  { &yyActionTable[165],   0, 570 },
  { &yyActionTable[165],   2, 591 },
  { &yyActionTable[167],   0, 589 },
  { &yyActionTable[167],   2, 793 },
  { &yyActionTable[169],   0, 592 },
  { &yyActionTable[169],   0, 593 },
  { &yyActionTable[169],   1, 793 },
  { &yyActionTable[170],   3, 658 },
  { &yyActionTable[173],   2, 606 },
  { &yyActionTable[175],   0, 571 },
  { &yyActionTable[175],   0, 656 },
  { &yyActionTable[175],   0, 657 },
  { &yyActionTable[175],   2, 606 },
  { &yyActionTable[177],   0, 572 },
  { &yyActionTable[177],   1, 793 },
  { &yyActionTable[178],  15, 793 },
  { &yyActionTable[193],   1, 545 },
  { &yyActionTable[194],  18, 743 },
  { &yyActionTable[212],   1, 688 },
  { &yyActionTable[213],   1, 692 },
  { &yyActionTable[214],  18, 793 },
  { &yyActionTable[232],   0, 619 },
  { &yyActionTable[232],   5, 793 },
  { &yyActionTable[237],   2, 793 },
  { &yyActionTable[239],   0, 620 },
  { &yyActionTable[239],   3, 628 },
  { &yyActionTable[242],   2, 630 },
  { &yyActionTable[244],   3, 636 },
  { &yyActionTable[247],   2, 671 },
  { &yyActionTable[249],   2, 661 },
  { &yyActionTable[251],   2, 663 },
  { &yyActionTable[253],   2, 651 },
  { &yyActionTable[255],   2, 665 },
  { &yyActionTable[257],   0, 625 },
  { &yyActionTable[257],   1, 793 },
  { &yyActionTable[258],   3, 666 },
  { &yyActionTable[261],   1, 793 },
  { &yyActionTable[262],   0, 667 },
  { &yyActionTable[262],   1, 793 },
  { &yyActionTable[263],   1, 793 },
  { &yyActionTable[264],   1, 793 },
  { &yyActionTable[265],  17, 793 },
  { &yyActionTable[282],   1, 652 },
  { &yyActionTable[283],  16, 793 },
  { &yyActionTable[299],   2, 659 },
  { &yyActionTable[301],   3, 658 },
  { &yyActionTable[304],   0, 653 },
  { &yyActionTable[304],   2, 793 },
  { &yyActionTable[306],   0, 660 },
  { &yyActionTable[306],  27, 655 },
  { &yyActionTable[333],  15, 793 },
  { &yyActionTable[348],   0, 687 },
  { &yyActionTable[348],   1, 793 },
  { &yyActionTable[349],   4, 793 },
  { &yyActionTable[353],   0, 689 },
  { &yyActionTable[353],   0, 690 },
  { &yyActionTable[353],   0, 691 },
  { &yyActionTable[353],  25, 695 },
  { &yyActionTable[378],  15, 793 },
  { &yyActionTable[393],  26, 696 },
  { &yyActionTable[419],  15, 793 },
  { &yyActionTable[434],  11, 697 },
  { &yyActionTable[445],  15, 793 },
  { &yyActionTable[460],  11, 698 },
  { &yyActionTable[471],  15, 793 },
  { &yyActionTable[486],  11, 699 },
  { &yyActionTable[497],  15, 793 },
  { &yyActionTable[512],  11, 700 },
  { &yyActionTable[523],  15, 793 },
  { &yyActionTable[538],  15, 701 },
  { &yyActionTable[553],  15, 793 },
  { &yyActionTable[568],  15, 702 },
  { &yyActionTable[583],  15, 793 },
  { &yyActionTable[598],   7, 703 },
  { &yyActionTable[605],  15, 793 },
  { &yyActionTable[620],   7, 704 },
  { &yyActionTable[627],  15, 793 },
  { &yyActionTable[642],   7, 705 },
  { &yyActionTable[649],  15, 793 },
  { &yyActionTable[664],   7, 706 },
  { &yyActionTable[671],  15, 793 },
  { &yyActionTable[686],  15, 707 },
  { &yyActionTable[701],   6, 793 },
  { &yyActionTable[707],  15, 793 },
  { &yyActionTable[722],  15, 708 },
  { &yyActionTable[737],   0, 709 },
  { &yyActionTable[737],   0, 710 },
  { &yyActionTable[737],  15, 793 },
  { &yyActionTable[752],   5, 711 },
  { &yyActionTable[757],  15, 793 },
  { &yyActionTable[772],   5, 712 },
  { &yyActionTable[777],  15, 793 },
  { &yyActionTable[792],   2, 713 },
  { &yyActionTable[794],  15, 793 },
  { &yyActionTable[809],   2, 714 },
  { &yyActionTable[811],  15, 793 },
  { &yyActionTable[826],   2, 715 },
  { &yyActionTable[828],  15, 793 },
  { &yyActionTable[843],   1, 716 },
  { &yyActionTable[844],   0, 717 },
  { &yyActionTable[844],   2, 793 },
  { &yyActionTable[846],   0, 718 },
  { &yyActionTable[846],   1, 793 },
  { &yyActionTable[847],   0, 721 },
  { &yyActionTable[847],   0, 719 },
  { &yyActionTable[847],  15, 793 },
  { &yyActionTable[862],  27, 793 },
  { &yyActionTable[889],  15, 793 },
  { &yyActionTable[904],  15, 727 },
  { &yyActionTable[919],   1, 793 },
  { &yyActionTable[920],  20, 743 },
  { &yyActionTable[940],   5, 793 },
  { &yyActionTable[945],   2, 793 },
  { &yyActionTable[947],   1, 793 },
  { &yyActionTable[948],   1, 793 },
  { &yyActionTable[949],   1, 793 },
  { &yyActionTable[950],   0, 730 },
  { &yyActionTable[950],  27, 742 },
  { &yyActionTable[977],  15, 793 },
  { &yyActionTable[992],  25, 722 },
  { &yyActionTable[1017],  15, 793 },
  { &yyActionTable[1032],   1, 723 },
  { &yyActionTable[1033],  15, 793 },
  { &yyActionTable[1048],   1, 724 },
  { &yyActionTable[1049],  15, 793 },
  { &yyActionTable[1064],   1, 725 },
  { &yyActionTable[1065],  17, 793 },
  { &yyActionTable[1082],  28, 793 },
  { &yyActionTable[1110],   2, 793 },
  { &yyActionTable[1112],   4, 793 },
  { &yyActionTable[1116],   1, 793 },
  { &yyActionTable[1117],   0, 733 },
  { &yyActionTable[1117],  15, 793 },
  { &yyActionTable[1132],  28, 793 },
  { &yyActionTable[1160],  15, 793 },
  { &yyActionTable[1175],  27, 734 },
  { &yyActionTable[1202],   1, 793 },
  { &yyActionTable[1203],   4, 793 },
  { &yyActionTable[1207],   1, 793 },
  { &yyActionTable[1208],   0, 788 },
  { &yyActionTable[1208],   1, 793 },
  { &yyActionTable[1209],   4, 793 },
  { &yyActionTable[1213],   1, 793 },
  { &yyActionTable[1214],   0, 789 },
  { &yyActionTable[1214],   1, 793 },
  { &yyActionTable[1215],   4, 793 },
  { &yyActionTable[1219],   1, 793 },
  { &yyActionTable[1220],   0, 790 },
  { &yyActionTable[1220],   1, 793 },
  { &yyActionTable[1221],   4, 793 },
  { &yyActionTable[1225],   1, 793 },
  { &yyActionTable[1226],   0, 791 },
  { &yyActionTable[1226],  15, 793 },
  { &yyActionTable[1241],  28, 793 },
  { &yyActionTable[1269],  15, 793 },
  { &yyActionTable[1284],  28, 793 },
  { &yyActionTable[1312],  15, 793 },
  { &yyActionTable[1327],  27, 735 },
  { &yyActionTable[1354],   2, 793 },
  { &yyActionTable[1356],   0, 729 },
  { &yyActionTable[1356],  16, 743 },
  { &yyActionTable[1372],   0, 740 },
  { &yyActionTable[1372],   0, 741 },
  { &yyActionTable[1372],   0, 720 },
  { &yyActionTable[1372],  15, 793 },
  { &yyActionTable[1387],  27, 793 },
  { &yyActionTable[1414],  15, 793 },
  { &yyActionTable[1429],  25, 728 },
  { &yyActionTable[1454],   1, 793 },
  { &yyActionTable[1455],  20, 743 },
  { &yyActionTable[1475],   5, 793 },
  { &yyActionTable[1480],   0, 732 },
  { &yyActionTable[1480],   2, 793 },
  { &yyActionTable[1482],   0, 731 },
  { &yyActionTable[1482],   3, 658 },
  { &yyActionTable[1485],   0, 654 },
  { &yyActionTable[1485],  15, 793 },
  { &yyActionTable[1500],  27, 664 },
  { &yyActionTable[1527],   1, 793 },
  { &yyActionTable[1528],  17, 743 },
  { &yyActionTable[1545],   1, 662 },
  { &yyActionTable[1546],  15, 793 },
  { &yyActionTable[1561],  27, 672 },
  { &yyActionTable[1588],   0, 629 },
  { &yyActionTable[1588],   2, 639 },
  { &yyActionTable[1590],   4, 637 },
  { &yyActionTable[1594],   0, 638 },
  { &yyActionTable[1594],   0, 642 },
  { &yyActionTable[1594],   0, 643 },
  { &yyActionTable[1594],   2, 793 },
  { &yyActionTable[1596],   0, 644 },
  { &yyActionTable[1596],   2, 793 },
  { &yyActionTable[1598],   0, 645 },
  { &yyActionTable[1598],   1, 793 },
  { &yyActionTable[1599],   0, 646 },
  { &yyActionTable[1599],   5, 793 },
  { &yyActionTable[1604],   2, 635 },
  { &yyActionTable[1606],   4, 793 },
  { &yyActionTable[1610],   0, 634 },
  { &yyActionTable[1610],   2, 648 },
  { &yyActionTable[1612],   2, 650 },
  { &yyActionTable[1614],   0, 640 },
  { &yyActionTable[1614],   1, 793 },
  { &yyActionTable[1615],   6, 793 },
  { &yyActionTable[1621],   2, 793 },
  { &yyActionTable[1623],   0, 649 },
  { &yyActionTable[1623],   5, 793 },
  { &yyActionTable[1628],   0, 747 },
  { &yyActionTable[1628],   0, 749 },
  { &yyActionTable[1628],   0, 748 },
  { &yyActionTable[1628],  15, 793 },
  { &yyActionTable[1643],  27, 647 },
  { &yyActionTable[1670],   3, 793 },
  { &yyActionTable[1673],   5, 793 },
  { &yyActionTable[1678],   2, 635 },
  { &yyActionTable[1680],   2, 648 },
  { &yyActionTable[1682],   2, 650 },
  { &yyActionTable[1684],   0, 641 },
  { &yyActionTable[1684],  16, 793 },
  { &yyActionTable[1700],  29, 635 },
  { &yyActionTable[1729],   0, 631 },
  { &yyActionTable[1729],   0, 632 },
  { &yyActionTable[1729],   1, 793 },
  { &yyActionTable[1730],   5, 793 },
  { &yyActionTable[1735],   0, 633 },
  { &yyActionTable[1735],   0, 626 },
  { &yyActionTable[1735],   0, 627 },
  { &yyActionTable[1735],   0, 726 },
  { &yyActionTable[1735],  28, 793 },
  { &yyActionTable[1763],   0, 686 },
  { &yyActionTable[1763],   2, 793 },
  { &yyActionTable[1765],   0, 693 },
  { &yyActionTable[1765],   1, 793 },
  { &yyActionTable[1766],   0, 694 },
  { &yyActionTable[1766],  28, 793 },
  { &yyActionTable[1794],   2, 606 },
  { &yyActionTable[1796],   0, 573 },
  { &yyActionTable[1796],   0, 574 },
  { &yyActionTable[1796],   0, 575 },
  { &yyActionTable[1796],   2, 793 },
  { &yyActionTable[1798],   0, 576 },
  { &yyActionTable[1798],   4, 793 },
  { &yyActionTable[1802],   2, 579 },
  { &yyActionTable[1804],   6, 793 },
  { &yyActionTable[1810],   2, 793 },
  { &yyActionTable[1812],   1, 579 },
  { &yyActionTable[1813],   3, 577 },
  { &yyActionTable[1816],   0, 580 },
  { &yyActionTable[1816],   2, 793 },
  { &yyActionTable[1818],   0, 581 },
  { &yyActionTable[1818],   0, 582 },
  { &yyActionTable[1818],   2, 793 },
  { &yyActionTable[1820],   4, 793 },
  { &yyActionTable[1824],   0, 583 },
  { &yyActionTable[1824],   2, 793 },
  { &yyActionTable[1826],   0, 585 },
  { &yyActionTable[1826],   0, 586 },
  { &yyActionTable[1826],   0, 587 },
  { &yyActionTable[1826],   0, 588 },
  { &yyActionTable[1826],   4, 793 },
  { &yyActionTable[1830],   0, 584 },
  { &yyActionTable[1830],   3, 578 },
  { &yyActionTable[1833],   2, 591 },
  { &yyActionTable[1835],   0, 590 },
  { &yyActionTable[1835],   0, 560 },
  { &yyActionTable[1835],   7, 793 },
  { &yyActionTable[1842],   0, 561 },
  { &yyActionTable[1842],   0, 562 },
  { &yyActionTable[1842],   0, 563 },
  { &yyActionTable[1842],   2, 793 },
  { &yyActionTable[1844],   0, 564 },
  { &yyActionTable[1844],   0, 567 },
  { &yyActionTable[1844],   2, 793 },
  { &yyActionTable[1846],   0, 565 },
  { &yyActionTable[1846],   0, 568 },
  { &yyActionTable[1846],   0, 566 },
  { &yyActionTable[1846],   0, 569 },
  { &yyActionTable[1846],   5, 549 },
  { &yyActionTable[1851],   4, 793 },
  { &yyActionTable[1855],   2, 793 },
  { &yyActionTable[1857],   0, 550 },
  { &yyActionTable[1857],   4, 793 },
  { &yyActionTable[1861],   1, 793 },
  { &yyActionTable[1862],   0, 551 },
  { &yyActionTable[1862],   0, 554 },
  { &yyActionTable[1862],   1, 793 },
  { &yyActionTable[1863],   0, 555 },
  { &yyActionTable[1863],   1, 793 },
  { &yyActionTable[1864],   0, 556 },
  { &yyActionTable[1864],   0, 553 },
  { &yyActionTable[1864],   0, 552 },
  { &yyActionTable[1864],   0, 544 },
  { &yyActionTable[1864],   8, 793 },
  { &yyActionTable[1872],   6, 793 },
  { &yyActionTable[1878],   0, 596 },
  { &yyActionTable[1878],   4, 793 },
  { &yyActionTable[1882],   0, 599 },
  { &yyActionTable[1882],   1, 793 },
  { &yyActionTable[1883],   1, 793 },
  { &yyActionTable[1884],   6, 793 },
  { &yyActionTable[1890],   2, 793 },
  { &yyActionTable[1892],   2, 606 },
  { &yyActionTable[1894],   0, 600 },
  { &yyActionTable[1894],   1, 793 },
  { &yyActionTable[1895],   6, 793 },
  { &yyActionTable[1901],   2, 793 },
  { &yyActionTable[1903],   2, 606 },
  { &yyActionTable[1905],   0, 601 },
  { &yyActionTable[1905],  15, 793 },
  { &yyActionTable[1920],  29, 606 },
  { &yyActionTable[1949],   0, 602 },
  { &yyActionTable[1949],   1, 793 },
  { &yyActionTable[1950],   1, 793 },
  { &yyActionTable[1951],   6, 793 },
  { &yyActionTable[1957],   2, 793 },
  { &yyActionTable[1959],   2, 793 },
  { &yyActionTable[1961],   4, 604 },
  { &yyActionTable[1965],   1, 793 },
  { &yyActionTable[1966],   0, 603 },
  { &yyActionTable[1966],   0, 605 },
  { &yyActionTable[1966],   0, 597 },
  { &yyActionTable[1966],   0, 598 },
  { &yyActionTable[1966],   0, 542 },
  { &yyActionTable[1966],   3, 793 },
  { &yyActionTable[1969],   5, 793 },
  { &yyActionTable[1974],   8, 793 },
  { &yyActionTable[1982],   1, 793 },
  { &yyActionTable[1983],   4, 793 },
  { &yyActionTable[1987],   0, 536 },
  { &yyActionTable[1987],   1, 793 },
  { &yyActionTable[1988],   4, 793 },
  { &yyActionTable[1992],   1, 793 },
  { &yyActionTable[1993],   3, 793 },
  { &yyActionTable[1996],   5, 793 },
  { &yyActionTable[2001],   1, 793 },
  { &yyActionTable[2002],   4, 793 },
  { &yyActionTable[2006],   1, 793 },
  { &yyActionTable[2007],   4, 793 },
  { &yyActionTable[2011],   1, 793 },
  { &yyActionTable[2012],   6, 793 },
  { &yyActionTable[2018],   2, 793 },
  { &yyActionTable[2020],   3, 793 },
  { &yyActionTable[2023],   1, 793 },
  { &yyActionTable[2024],   1, 793 },
  { &yyActionTable[2025],   4, 793 },
  { &yyActionTable[2029],   4, 771 },
  { &yyActionTable[2033],   4, 793 },
  { &yyActionTable[2037],   1, 793 },
  { &yyActionTable[2038],   4, 793 },
  { &yyActionTable[2042],   2, 776 },
  { &yyActionTable[2044],   3, 793 },
  { &yyActionTable[2047],   1, 793 },
  { &yyActionTable[2048],   9, 793 },
  { &yyActionTable[2057],   5, 793 },
  { &yyActionTable[2062],   1, 793 },
  { &yyActionTable[2063],   1, 793 },
  { &yyActionTable[2064],   1, 793 },
  { &yyActionTable[2065],   9, 793 },
  { &yyActionTable[2074],   1, 793 },
  { &yyActionTable[2075],   2, 608 },
  { &yyActionTable[2077],   6, 793 },
  { &yyActionTable[2083],   0, 609 },
  { &yyActionTable[2083],   4, 793 },
  { &yyActionTable[2087],   1, 793 },
  { &yyActionTable[2088],   5, 793 },
  { &yyActionTable[2093],   4, 793 },
  { &yyActionTable[2097],   4, 793 },
  { &yyActionTable[2101],   1, 793 },
  { &yyActionTable[2102],  15, 793 },
  { &yyActionTable[2117],  27, 674 },
  { &yyActionTable[2144],   1, 793 },
  { &yyActionTable[2145],   1, 793 },
  { &yyActionTable[2146],  15, 793 },
  { &yyActionTable[2161],  27, 675 },
  { &yyActionTable[2188],   3, 793 },
  { &yyActionTable[2191],   1, 793 },
  { &yyActionTable[2192],   4, 793 },
  { &yyActionTable[2196],   2, 682 },
  { &yyActionTable[2198],   5, 793 },
  { &yyActionTable[2203],   2, 793 },
  { &yyActionTable[2205],   0, 683 },
  { &yyActionTable[2205],   4, 793 },
  { &yyActionTable[2209],   0, 684 },
  { &yyActionTable[2209],   0, 685 },
  { &yyActionTable[2209],   4, 793 },
  { &yyActionTable[2213],   5, 793 },
  { &yyActionTable[2218],   1, 793 },
  { &yyActionTable[2219],  16, 793 },
  { &yyActionTable[2235],   2, 793 },
  { &yyActionTable[2237],  15, 793 },
  { &yyActionTable[2252],  27, 680 },
  { &yyActionTable[2279],   1, 793 },
  { &yyActionTable[2280],  27, 681 },
  { &yyActionTable[2307],   1, 793 },
  { &yyActionTable[2308],   4, 793 },
  { &yyActionTable[2312],   3, 793 },
  { &yyActionTable[2315],   1, 793 },
  { &yyActionTable[2316],  15, 793 },
  { &yyActionTable[2331],  28, 793 },
  { &yyActionTable[2359],   1, 793 },
  { &yyActionTable[2360],   2, 793 },
  { &yyActionTable[2362],   0, 777 },
  { &yyActionTable[2362],   0, 778 },
  { &yyActionTable[2362],   1, 793 },
  { &yyActionTable[2363],   1, 793 },
  { &yyActionTable[2364],   2, 793 },
  { &yyActionTable[2366],   5, 793 },
  { &yyActionTable[2371],   2, 793 },
  { &yyActionTable[2373],   0, 768 },
  { &yyActionTable[2373],   0, 769 },
  { &yyActionTable[2373],   1, 793 },
  { &yyActionTable[2374],   0, 770 },
  { &yyActionTable[2374],   4, 793 },
  { &yyActionTable[2378],   4, 793 },
  { &yyActionTable[2382],   1, 793 },
  { &yyActionTable[2383],   4, 793 },
  { &yyActionTable[2387],   1, 793 },
  { &yyActionTable[2388],   4, 793 },
  { &yyActionTable[2392],   1, 793 },
  { &yyActionTable[2393],   4, 793 },
  { &yyActionTable[2397],   1, 793 },
  { &yyActionTable[2398],   5, 793 },
  { &yyActionTable[2403],   1, 793 },
  { &yyActionTable[2404],   4, 793 },
  { &yyActionTable[2408],   3, 793 },
  { &yyActionTable[2411],   1, 793 },
  { &yyActionTable[2412],   2, 608 },
  { &yyActionTable[2414],   4, 793 },
  { &yyActionTable[2418],   1, 793 },
  { &yyActionTable[2419],   5, 793 },
  { &yyActionTable[2424],   4, 793 },
  { &yyActionTable[2428],   1, 793 },
  { &yyActionTable[2429],   1, 793 },
  { &yyActionTable[2430],   4, 793 },
  { &yyActionTable[2434],   2, 682 },
  { &yyActionTable[2436],   4, 793 },
  { &yyActionTable[2440],   5, 793 },
  { &yyActionTable[2445],   1, 793 },
  { &yyActionTable[2446],  16, 793 },
  { &yyActionTable[2462],   2, 793 },
  { &yyActionTable[2464],   1, 793 },
  { &yyActionTable[2465],   3, 793 },
  { &yyActionTable[2468],   1, 793 },
  { &yyActionTable[2469],   1, 793 },
  { &yyActionTable[2470],   2, 608 },
  { &yyActionTable[2472],   4, 793 },
  { &yyActionTable[2476],   1, 793 },
  { &yyActionTable[2477],   4, 793 },
  { &yyActionTable[2481],   2, 793 },
  { &yyActionTable[2483],   1, 793 },
  { &yyActionTable[2484],   1, 793 },
  { &yyActionTable[2485],   1, 793 },
  { &yyActionTable[2486],   5, 793 },
  { &yyActionTable[2491],   1, 793 },
  { &yyActionTable[2492],   4, 793 },
  { &yyActionTable[2496],   3, 793 },
  { &yyActionTable[2499],  10, 766 },
  { &yyActionTable[2509],   1, 793 },
  { &yyActionTable[2510],   1, 793 },
  { &yyActionTable[2511],   1, 793 },
  { &yyActionTable[2512],   1, 793 },
  { &yyActionTable[2513],   3, 793 },
  { &yyActionTable[2516],   1, 793 },
  { &yyActionTable[2517],   1, 793 },
  { &yyActionTable[2518],   1, 793 },
  { &yyActionTable[2519],   3, 793 },
  { &yyActionTable[2522],   1, 793 },
  { &yyActionTable[2523],   0, 765 },
  { &yyActionTable[2523],   4, 793 },
  { &yyActionTable[2527],   1, 793 },
  { &yyActionTable[2528],   1, 793 },
  { &yyActionTable[2529],   1, 793 },
  { &yyActionTable[2530],   0, 525 },
  { &yyActionTable[2530],   0, 526 },
  { &yyActionTable[2530],   0, 527 },
  { &yyActionTable[2530],   0, 522 },
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
 /*   4 */ "ecmd ::= cmd SEMI",
 /*   5 */ "ecmd ::= SEMI",
 /*   6 */ "explain ::= EXPLAIN",
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
#line 4204 "parse.c"
      break;
    case 150:
#line 487 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4209 "parse.c"
      break;
    case 151:
#line 646 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4214 "parse.c"
      break;
    case 152:
#line 644 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4219 "parse.c"
      break;
    case 154:
#line 312 "parse.y"
{sqliteSrcListDelete((yypminor->yy7));}
#line 4224 "parse.c"
      break;
    case 155:
#line 405 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4229 "parse.c"
      break;
    case 156:
#line 410 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4234 "parse.c"
      break;
    case 160:
#line 668 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4239 "parse.c"
      break;
    case 163:
#line 466 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4244 "parse.c"
      break;
    case 164:
#line 464 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4249 "parse.c"
      break;
    case 166:
#line 458 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4254 "parse.c"
      break;
    case 175:
#line 366 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4259 "parse.c"
      break;
    case 177:
#line 248 "parse.y"
{sqliteSelectDelete((yypminor->yy219));}
#line 4264 "parse.c"
      break;
    case 179:
#line 377 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4269 "parse.c"
      break;
    case 187:
#line 284 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4274 "parse.c"
      break;
    case 188:
#line 282 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4279 "parse.c"
      break;
    case 189:
#line 246 "parse.y"
{sqliteSelectDelete((yypminor->yy219));}
#line 4284 "parse.c"
      break;
    case 190:
#line 308 "parse.y"
{sqliteSrcListDelete((yypminor->yy7));}
#line 4289 "parse.c"
      break;
    case 191:
#line 434 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4294 "parse.c"
      break;
    case 193:
#line 381 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4299 "parse.c"
      break;
    case 194:
#line 379 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4304 "parse.c"
      break;
    case 196:
#line 310 "parse.y"
{sqliteSrcListDelete((yypminor->yy7));}
#line 4309 "parse.c"
      break;
    case 202:
#line 725 "parse.y"
{sqliteIdListDelete((yypminor->yy90).b);}
#line 4314 "parse.c"
      break;
    case 207:
#line 371 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4319 "parse.c"
      break;
    case 209:
#line 428 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4324 "parse.c"
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
  { 147, 2 },
  { 147, 1 },
  { 149, 1 },
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
#line 4791 "parse.c"
        /* No destructor defined for explain */
        /* No destructor defined for cmd */
        /* No destructor defined for SEMI */
        break;
      case 4:
#line 68 "parse.y"
{sqliteExec(pParse);}
#line 4799 "parse.c"
        /* No destructor defined for cmd */
        /* No destructor defined for SEMI */
        break;
      case 5:
        /* No destructor defined for SEMI */
        break;
      case 6:
#line 70 "parse.y"
{pParse->explain = 1;}
#line 4809 "parse.c"
        /* No destructor defined for EXPLAIN */
        break;
      case 7:
#line 75 "parse.y"
{sqliteBeginTransaction(pParse,yymsp[0].minor.yy172);}
#line 4815 "parse.c"
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
#line 4831 "parse.c"
        /* No destructor defined for COMMIT */
        /* No destructor defined for trans_opt */
        break;
      case 12:
#line 80 "parse.y"
{sqliteCommitTransaction(pParse);}
#line 4838 "parse.c"
        /* No destructor defined for END */
        /* No destructor defined for trans_opt */
        break;
      case 13:
#line 81 "parse.y"
{sqliteRollbackTransaction(pParse);}
#line 4845 "parse.c"
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
#line 4858 "parse.c"
        /* No destructor defined for TABLE */
        break;
      case 16:
#line 90 "parse.y"
{yygotominor.yy172 = 1;}
#line 4864 "parse.c"
        /* No destructor defined for TEMP */
        break;
      case 17:
#line 91 "parse.y"
{yygotominor.yy172 = 0;}
#line 4870 "parse.c"
        break;
      case 18:
#line 92 "parse.y"
{
  sqliteEndTable(pParse,&yymsp[0].minor.yy0,0);
}
#line 4877 "parse.c"
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
#line 4888 "parse.c"
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
#line 4907 "parse.c"
        break;
      case 24:
#line 113 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4912 "parse.c"
        break;
      case 25:
#line 129 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 4917 "parse.c"
        break;
      case 26:
#line 130 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4922 "parse.c"
        break;
      case 27:
        break;
      case 28:
#line 133 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[0].minor.yy378,&yymsp[0].minor.yy378);}
#line 4929 "parse.c"
        break;
      case 29:
#line 134 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-3].minor.yy378,&yymsp[0].minor.yy0);}
#line 4934 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        break;
      case 30:
#line 136 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-5].minor.yy378,&yymsp[0].minor.yy0);}
#line 4941 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        /* No destructor defined for COMMA */
        /* No destructor defined for signed */
        break;
      case 31:
#line 138 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 4950 "parse.c"
        break;
      case 32:
#line 139 "parse.y"
{yygotominor.yy378 = yymsp[-1].minor.yy378;}
#line 4955 "parse.c"
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
#line 4986 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 41:
#line 148 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 4992 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 42:
#line 149 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 4998 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 43:
#line 150 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5004 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 44:
#line 151 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 5011 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 45:
#line 152 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5018 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 46:
#line 153 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5024 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 47:
#line 154 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 5031 "parse.c"
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
#line 5042 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for NULL */
        break;
      case 50:
#line 161 "parse.y"
{sqliteAddPrimaryKey(pParse,0,yymsp[0].minor.yy172);}
#line 5049 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for sortorder */
        break;
      case 51:
#line 162 "parse.y"
{sqliteCreateIndex(pParse,0,0,0,yymsp[0].minor.yy172,0,0);}
#line 5057 "parse.c"
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
#line 5078 "parse.c"
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
#line 5176 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 80:
#line 203 "parse.y"
{sqliteCreateIndex(pParse,0,0,yymsp[-2].minor.yy250,yymsp[0].minor.yy172,0,0);}
#line 5185 "parse.c"
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
#line 5212 "parse.c"
        break;
      case 86:
#line 216 "parse.y"
{ yygotominor.yy172 = yymsp[0].minor.yy172; }
#line 5217 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for CONFLICT */
        break;
      case 87:
#line 217 "parse.y"
{ yygotominor.yy172 = OE_Default; }
#line 5224 "parse.c"
        break;
      case 88:
#line 218 "parse.y"
{ yygotominor.yy172 = yymsp[0].minor.yy172; }
#line 5229 "parse.c"
        /* No destructor defined for OR */
        break;
      case 89:
#line 219 "parse.y"
{ yygotominor.yy172 = OE_Rollback; }
#line 5235 "parse.c"
        /* No destructor defined for ROLLBACK */
        break;
      case 90:
#line 220 "parse.y"
{ yygotominor.yy172 = OE_Abort; }
#line 5241 "parse.c"
        /* No destructor defined for ABORT */
        break;
      case 91:
#line 221 "parse.y"
{ yygotominor.yy172 = OE_Fail; }
#line 5247 "parse.c"
        /* No destructor defined for FAIL */
        break;
      case 92:
#line 222 "parse.y"
{ yygotominor.yy172 = OE_Ignore; }
#line 5253 "parse.c"
        /* No destructor defined for IGNORE */
        break;
      case 93:
#line 223 "parse.y"
{ yygotominor.yy172 = OE_Replace; }
#line 5259 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 94:
#line 227 "parse.y"
{sqliteDropTable(pParse,&yymsp[0].minor.yy378,0);}
#line 5265 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for TABLE */
        break;
      case 95:
#line 231 "parse.y"
{
  sqliteCreateView(pParse, &yymsp[-4].minor.yy0, &yymsp[-2].minor.yy378, yymsp[0].minor.yy219);
}
#line 5274 "parse.c"
        /* No destructor defined for VIEW */
        /* No destructor defined for AS */
        break;
      case 96:
#line 234 "parse.y"
{
  sqliteDropTable(pParse, &yymsp[0].minor.yy378, 1);
}
#line 5283 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for VIEW */
        break;
      case 97:
#line 240 "parse.y"
{
  sqliteSelect(pParse, yymsp[0].minor.yy219, SRT_Callback, 0, 0, 0, 0);
  sqliteSelectDelete(yymsp[0].minor.yy219);
}
#line 5293 "parse.c"
        break;
      case 98:
#line 250 "parse.y"
{yygotominor.yy219 = yymsp[0].minor.yy219;}
#line 5298 "parse.c"
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
#line 5309 "parse.c"
        break;
      case 100:
#line 259 "parse.y"
{yygotominor.yy172 = TK_UNION;}
#line 5314 "parse.c"
        /* No destructor defined for UNION */
        break;
      case 101:
#line 260 "parse.y"
{yygotominor.yy172 = TK_ALL;}
#line 5320 "parse.c"
        /* No destructor defined for UNION */
        /* No destructor defined for ALL */
        break;
      case 102:
#line 261 "parse.y"
{yygotominor.yy172 = TK_INTERSECT;}
#line 5327 "parse.c"
        /* No destructor defined for INTERSECT */
        break;
      case 103:
#line 262 "parse.y"
{yygotominor.yy172 = TK_EXCEPT;}
#line 5333 "parse.c"
        /* No destructor defined for EXCEPT */
        break;
      case 104:
#line 264 "parse.y"
{
  yygotominor.yy219 = sqliteSelectNew(yymsp[-6].minor.yy228,yymsp[-5].minor.yy7,yymsp[-4].minor.yy62,yymsp[-3].minor.yy228,yymsp[-2].minor.yy62,yymsp[-1].minor.yy228,yymsp[-7].minor.yy172,yymsp[0].minor.yy6.limit,yymsp[0].minor.yy6.offset);
}
#line 5341 "parse.c"
        /* No destructor defined for SELECT */
        break;
      case 105:
#line 272 "parse.y"
{yygotominor.yy172 = 1;}
#line 5347 "parse.c"
        /* No destructor defined for DISTINCT */
        break;
      case 106:
#line 273 "parse.y"
{yygotominor.yy172 = 0;}
#line 5353 "parse.c"
        /* No destructor defined for ALL */
        break;
      case 107:
#line 274 "parse.y"
{yygotominor.yy172 = 0;}
#line 5359 "parse.c"
        break;
      case 108:
#line 285 "parse.y"
{yygotominor.yy228 = yymsp[-1].minor.yy228;}
#line 5364 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 109:
#line 286 "parse.y"
{yygotominor.yy228 = 0;}
#line 5370 "parse.c"
        break;
      case 110:
#line 287 "parse.y"
{
   yygotominor.yy228 = sqliteExprListAppend(yymsp[-2].minor.yy228,yymsp[-1].minor.yy62,yymsp[0].minor.yy378.n?&yymsp[0].minor.yy378:0);
}
#line 5377 "parse.c"
        break;
      case 111:
#line 290 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-1].minor.yy228, sqliteExpr(TK_ALL, 0, 0, 0), 0);
}
#line 5384 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 112:
#line 293 "parse.y"
{
  Expr *pRight = sqliteExpr(TK_ALL, 0, 0, 0);
  Expr *pLeft = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy378);
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-3].minor.yy228, sqliteExpr(TK_DOT, pLeft, pRight, 0), 0);
}
#line 5394 "parse.c"
        /* No destructor defined for DOT */
        /* No destructor defined for STAR */
        break;
      case 113:
#line 303 "parse.y"
{ yygotominor.yy378 = yymsp[0].minor.yy378; }
#line 5401 "parse.c"
        /* No destructor defined for AS */
        break;
      case 114:
#line 304 "parse.y"
{ yygotominor.yy378.n = 0; }
#line 5407 "parse.c"
        break;
      case 115:
#line 316 "parse.y"
{yygotominor.yy7 = sqliteMalloc(sizeof(*yygotominor.yy7));}
#line 5412 "parse.c"
        break;
      case 116:
#line 317 "parse.y"
{yygotominor.yy7 = yymsp[0].minor.yy7;}
#line 5417 "parse.c"
        /* No destructor defined for FROM */
        break;
      case 117:
#line 322 "parse.y"
{
   yygotominor.yy7 = yymsp[-1].minor.yy7;
   if( yygotominor.yy7 && yygotominor.yy7->nSrc>0 ) yygotominor.yy7->a[yygotominor.yy7->nSrc-1].jointype = yymsp[0].minor.yy172;
}
#line 5426 "parse.c"
        break;
      case 118:
#line 326 "parse.y"
{yygotominor.yy7 = 0;}
#line 5431 "parse.c"
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
#line 5447 "parse.c"
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
#line 5468 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 121:
#line 359 "parse.y"
{ yygotominor.yy172 = JT_INNER; }
#line 5475 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 122:
#line 360 "parse.y"
{ yygotominor.yy172 = JT_INNER; }
#line 5481 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 123:
#line 361 "parse.y"
{ yygotominor.yy172 = sqliteJoinType(pParse,&yymsp[-1].minor.yy0,0,0); }
#line 5487 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 124:
#line 362 "parse.y"
{ yygotominor.yy172 = sqliteJoinType(pParse,&yymsp[-2].minor.yy0,&yymsp[-1].minor.yy0,0); }
#line 5493 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 125:
#line 363 "parse.y"
{ yygotominor.yy172 = sqliteJoinType(pParse,&yymsp[-3].minor.yy0,&yymsp[-2].minor.yy0,&yymsp[-1].minor.yy0); }
#line 5499 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 126:
#line 367 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5505 "parse.c"
        /* No destructor defined for ON */
        break;
      case 127:
#line 368 "parse.y"
{yygotominor.yy62 = 0;}
#line 5511 "parse.c"
        break;
      case 128:
#line 372 "parse.y"
{yygotominor.yy250 = yymsp[-1].minor.yy250;}
#line 5516 "parse.c"
        /* No destructor defined for USING */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 129:
#line 373 "parse.y"
{yygotominor.yy250 = 0;}
#line 5524 "parse.c"
        break;
      case 130:
#line 383 "parse.y"
{yygotominor.yy228 = 0;}
#line 5529 "parse.c"
        break;
      case 131:
#line 384 "parse.y"
{yygotominor.yy228 = yymsp[0].minor.yy228;}
#line 5534 "parse.c"
        /* No destructor defined for ORDER */
        /* No destructor defined for BY */
        break;
      case 132:
#line 385 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-4].minor.yy228,yymsp[-2].minor.yy62,0);
  if( yygotominor.yy228 ) yygotominor.yy228->a[yygotominor.yy228->nExpr-1].sortOrder = yymsp[-1].minor.yy172+yymsp[0].minor.yy172;
}
#line 5544 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 133:
#line 389 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(0,yymsp[-1].minor.yy62,0);
  if( yygotominor.yy228 ) yygotominor.yy228->a[0].sortOrder = yymsp[0].minor.yy172;
}
#line 5553 "parse.c"
        break;
      case 134:
#line 393 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5558 "parse.c"
        break;
      case 135:
#line 398 "parse.y"
{yygotominor.yy172 = SQLITE_SO_ASC;}
#line 5563 "parse.c"
        /* No destructor defined for ASC */
        break;
      case 136:
#line 399 "parse.y"
{yygotominor.yy172 = SQLITE_SO_DESC;}
#line 5569 "parse.c"
        /* No destructor defined for DESC */
        break;
      case 137:
#line 400 "parse.y"
{yygotominor.yy172 = SQLITE_SO_ASC;}
#line 5575 "parse.c"
        break;
      case 138:
#line 401 "parse.y"
{yygotominor.yy172 = SQLITE_SO_UNK;}
#line 5580 "parse.c"
        break;
      case 139:
#line 402 "parse.y"
{yygotominor.yy172 = sqliteCollateType(pParse, &yymsp[0].minor.yy378);}
#line 5585 "parse.c"
        /* No destructor defined for COLLATE */
        break;
      case 140:
#line 406 "parse.y"
{yygotominor.yy228 = 0;}
#line 5591 "parse.c"
        break;
      case 141:
#line 407 "parse.y"
{yygotominor.yy228 = yymsp[0].minor.yy228;}
#line 5596 "parse.c"
        /* No destructor defined for GROUP */
        /* No destructor defined for BY */
        break;
      case 142:
#line 411 "parse.y"
{yygotominor.yy62 = 0;}
#line 5603 "parse.c"
        break;
      case 143:
#line 412 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5608 "parse.c"
        /* No destructor defined for HAVING */
        break;
      case 144:
#line 415 "parse.y"
{yygotominor.yy6.limit = -1; yygotominor.yy6.offset = 0;}
#line 5614 "parse.c"
        break;
      case 145:
#line 416 "parse.y"
{yygotominor.yy6.limit = atoi(yymsp[0].minor.yy0.z); yygotominor.yy6.offset = 0;}
#line 5619 "parse.c"
        /* No destructor defined for LIMIT */
        break;
      case 146:
#line 418 "parse.y"
{yygotominor.yy6.limit = atoi(yymsp[-2].minor.yy0.z); yygotominor.yy6.offset = atoi(yymsp[0].minor.yy0.z);}
#line 5625 "parse.c"
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
#line 5638 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 150:
#line 430 "parse.y"
{yygotominor.yy62 = 0;}
#line 5645 "parse.c"
        break;
      case 151:
#line 431 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5650 "parse.c"
        /* No destructor defined for WHERE */
        break;
      case 152:
#line 439 "parse.y"
{sqliteUpdate(pParse,&yymsp[-3].minor.yy378,yymsp[-1].minor.yy228,yymsp[0].minor.yy62,yymsp[-4].minor.yy172);}
#line 5656 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 153:
#line 442 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(yymsp[-4].minor.yy228,yymsp[0].minor.yy62,&yymsp[-2].minor.yy378);}
#line 5663 "parse.c"
        /* No destructor defined for COMMA */
        /* No destructor defined for EQ */
        break;
      case 154:
#line 443 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(0,yymsp[0].minor.yy62,&yymsp[-2].minor.yy378);}
#line 5670 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 155:
#line 448 "parse.y"
{sqliteInsert(pParse, &yymsp[-5].minor.yy378, yymsp[-1].minor.yy228, 0, yymsp[-4].minor.yy250, yymsp[-7].minor.yy172);}
#line 5676 "parse.c"
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 156:
#line 450 "parse.y"
{sqliteInsert(pParse, &yymsp[-2].minor.yy378, 0, yymsp[0].minor.yy219, yymsp[-1].minor.yy250, yymsp[-4].minor.yy172);}
#line 5685 "parse.c"
        /* No destructor defined for INTO */
        break;
      case 157:
#line 453 "parse.y"
{yygotominor.yy172 = yymsp[0].minor.yy172;}
#line 5691 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 158:
#line 454 "parse.y"
{yygotominor.yy172 = OE_Replace;}
#line 5697 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 159:
#line 460 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(yymsp[-2].minor.yy228,yymsp[0].minor.yy62,0);}
#line 5703 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 160:
#line 461 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(0,yymsp[0].minor.yy62,0);}
#line 5709 "parse.c"
        break;
      case 161:
#line 468 "parse.y"
{yygotominor.yy250 = 0;}
#line 5714 "parse.c"
        break;
      case 162:
#line 469 "parse.y"
{yygotominor.yy250 = yymsp[-1].minor.yy250;}
#line 5719 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 163:
#line 470 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(yymsp[-2].minor.yy250,&yymsp[0].minor.yy378);}
#line 5726 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 164:
#line 471 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(0,&yymsp[0].minor.yy378);}
#line 5732 "parse.c"
        break;
      case 165:
#line 489 "parse.y"
{yygotominor.yy62 = yymsp[-1].minor.yy62; sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);}
#line 5737 "parse.c"
        break;
      case 166:
#line 490 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_NULL, 0, 0, &yymsp[0].minor.yy0);}
#line 5742 "parse.c"
        break;
      case 167:
#line 491 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy378);}
#line 5747 "parse.c"
        break;
      case 168:
#line 492 "parse.y"
{
  Expr *temp1 = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy378);
  Expr *temp2 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy378);
  yygotominor.yy62 = sqliteExpr(TK_DOT, temp1, temp2, 0);
}
#line 5756 "parse.c"
        /* No destructor defined for DOT */
        break;
      case 169:
#line 497 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_INTEGER, 0, 0, &yymsp[0].minor.yy0);}
#line 5762 "parse.c"
        break;
      case 170:
#line 498 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_FLOAT, 0, 0, &yymsp[0].minor.yy0);}
#line 5767 "parse.c"
        break;
      case 171:
#line 499 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_STRING, 0, 0, &yymsp[0].minor.yy0);}
#line 5772 "parse.c"
        break;
      case 172:
#line 500 "parse.y"
{
  yygotominor.yy62 = sqliteExprFunction(yymsp[-1].minor.yy228, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 5780 "parse.c"
        /* No destructor defined for LP */
        break;
      case 173:
#line 504 "parse.y"
{
  yygotominor.yy62 = sqliteExprFunction(0, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 5789 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for STAR */
        break;
      case 174:
#line 508 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_AND, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5796 "parse.c"
        /* No destructor defined for AND */
        break;
      case 175:
#line 509 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_OR, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5802 "parse.c"
        /* No destructor defined for OR */
        break;
      case 176:
#line 510 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_LT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5808 "parse.c"
        /* No destructor defined for LT */
        break;
      case 177:
#line 511 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_GT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5814 "parse.c"
        /* No destructor defined for GT */
        break;
      case 178:
#line 512 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_LE, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5820 "parse.c"
        /* No destructor defined for LE */
        break;
      case 179:
#line 513 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_GE, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5826 "parse.c"
        /* No destructor defined for GE */
        break;
      case 180:
#line 514 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_NE, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5832 "parse.c"
        /* No destructor defined for NE */
        break;
      case 181:
#line 515 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_EQ, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5838 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 182:
#line 516 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_BITAND, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5844 "parse.c"
        /* No destructor defined for BITAND */
        break;
      case 183:
#line 517 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_BITOR, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5850 "parse.c"
        /* No destructor defined for BITOR */
        break;
      case 184:
#line 518 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_LSHIFT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5856 "parse.c"
        /* No destructor defined for LSHIFT */
        break;
      case 185:
#line 519 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_RSHIFT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5862 "parse.c"
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
#line 5873 "parse.c"
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
#line 5884 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 188:
#line 533 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 5890 "parse.c"
        break;
      case 189:
#line 534 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 5895 "parse.c"
        break;
      case 190:
#line 535 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_PLUS, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5900 "parse.c"
        /* No destructor defined for PLUS */
        break;
      case 191:
#line 536 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_MINUS, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5906 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 192:
#line 537 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_STAR, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5912 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 193:
#line 538 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_SLASH, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5918 "parse.c"
        /* No destructor defined for SLASH */
        break;
      case 194:
#line 539 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_REM, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5924 "parse.c"
        /* No destructor defined for REM */
        break;
      case 195:
#line 540 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_CONCAT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5930 "parse.c"
        /* No destructor defined for CONCAT */
        break;
      case 196:
#line 541 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_ISNULL, yymsp[-1].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5939 "parse.c"
        break;
      case 197:
#line 545 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_ISNULL, yymsp[-2].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5947 "parse.c"
        /* No destructor defined for IS */
        break;
      case 198:
#line 549 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOTNULL, yymsp[-1].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5956 "parse.c"
        break;
      case 199:
#line 553 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOTNULL, yymsp[-2].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5964 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 200:
#line 557 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOTNULL, yymsp[-3].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5973 "parse.c"
        /* No destructor defined for IS */
        /* No destructor defined for NOT */
        break;
      case 201:
#line 561 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOT, yymsp[0].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 5983 "parse.c"
        break;
      case 202:
#line 565 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_BITNOT, yymsp[0].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 5991 "parse.c"
        break;
      case 203:
#line 569 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_UMINUS, yymsp[0].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 5999 "parse.c"
        break;
      case 204:
#line 573 "parse.y"
{
  yygotominor.yy62 = yymsp[0].minor.yy62;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 6007 "parse.c"
        break;
      case 205:
#line 577 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_SELECT, 0, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pSelect = yymsp[-1].minor.yy219;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);
}
#line 6016 "parse.c"
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
#line 6027 "parse.c"
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
#line 6041 "parse.c"
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
#line 6053 "parse.c"
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
#line 6064 "parse.c"
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
#line 6076 "parse.c"
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
#line 6089 "parse.c"
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
#line 6101 "parse.c"
        break;
      case 213:
#line 628 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-4].minor.yy228, yymsp[-2].minor.yy62, 0);
  yygotominor.yy228 = sqliteExprListAppend(yygotominor.yy228, yymsp[0].minor.yy62, 0);
}
#line 6109 "parse.c"
        /* No destructor defined for WHEN */
        /* No destructor defined for THEN */
        break;
      case 214:
#line 632 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(0, yymsp[-2].minor.yy62, 0);
  yygotominor.yy228 = sqliteExprListAppend(yygotominor.yy228, yymsp[0].minor.yy62, 0);
}
#line 6119 "parse.c"
        /* No destructor defined for WHEN */
        /* No destructor defined for THEN */
        break;
      case 215:
#line 637 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 6126 "parse.c"
        /* No destructor defined for ELSE */
        break;
      case 216:
#line 638 "parse.y"
{yygotominor.yy62 = 0;}
#line 6132 "parse.c"
        break;
      case 217:
#line 640 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 6137 "parse.c"
        break;
      case 218:
#line 641 "parse.y"
{yygotominor.yy62 = 0;}
#line 6142 "parse.c"
        break;
      case 219:
#line 649 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(yymsp[-2].minor.yy228,yymsp[0].minor.yy62,0);}
#line 6147 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 220:
#line 650 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(0,yymsp[0].minor.yy62,0);}
#line 6153 "parse.c"
        break;
      case 221:
#line 651 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 6158 "parse.c"
        break;
      case 222:
#line 652 "parse.y"
{yygotominor.yy62 = 0;}
#line 6163 "parse.c"
        break;
      case 223:
#line 657 "parse.y"
{
  if( yymsp[-8].minor.yy172!=OE_None ) yymsp[-8].minor.yy172 = yymsp[0].minor.yy172;
  if( yymsp[-8].minor.yy172==OE_Default) yymsp[-8].minor.yy172 = OE_Abort;
  sqliteCreateIndex(pParse, &yymsp[-6].minor.yy378, &yymsp[-4].minor.yy378, yymsp[-2].minor.yy250, yymsp[-8].minor.yy172, &yymsp[-9].minor.yy0, &yymsp[-1].minor.yy0);
}
#line 6172 "parse.c"
        /* No destructor defined for INDEX */
        /* No destructor defined for ON */
        /* No destructor defined for LP */
        break;
      case 224:
#line 664 "parse.y"
{ yygotominor.yy172 = OE_Abort; }
#line 6180 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 225:
#line 665 "parse.y"
{ yygotominor.yy172 = OE_None; }
#line 6186 "parse.c"
        break;
      case 226:
#line 672 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(yymsp[-2].minor.yy250,&yymsp[0].minor.yy378);}
#line 6191 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 227:
#line 674 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(0,&yymsp[0].minor.yy378);}
#line 6197 "parse.c"
        break;
      case 228:
#line 675 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 6202 "parse.c"
        break;
      case 229:
#line 680 "parse.y"
{sqliteDropIndex(pParse, &yymsp[0].minor.yy378);}
#line 6207 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for INDEX */
        break;
      case 230:
#line 686 "parse.y"
{sqliteCopy(pParse,&yymsp[-5].minor.yy378,&yymsp[-3].minor.yy378,&yymsp[0].minor.yy0,yymsp[-6].minor.yy172);}
#line 6214 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        /* No destructor defined for USING */
        /* No destructor defined for DELIMITERS */
        break;
      case 231:
#line 688 "parse.y"
{sqliteCopy(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,0,yymsp[-3].minor.yy172);}
#line 6223 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        break;
      case 232:
#line 692 "parse.y"
{sqliteVacuum(pParse,0);}
#line 6230 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 233:
#line 693 "parse.y"
{sqliteVacuum(pParse,&yymsp[0].minor.yy378);}
#line 6236 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 234:
#line 697 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,0);}
#line 6242 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 235:
#line 698 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy0,0);}
#line 6249 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 236:
#line 699 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,0);}
#line 6256 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 237:
#line 700 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,1);}
#line 6263 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 238:
#line 701 "parse.y"
{sqlitePragma(pParse,&yymsp[-3].minor.yy378,&yymsp[-1].minor.yy378,0);}
#line 6270 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 239:
#line 702 "parse.y"
{sqlitePragma(pParse,&yymsp[0].minor.yy378,&yymsp[0].minor.yy378,0);}
#line 6278 "parse.c"
        /* No destructor defined for PRAGMA */
        break;
      case 240:
#line 703 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 6284 "parse.c"
        /* No destructor defined for plus_opt */
        break;
      case 241:
#line 704 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 6290 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 242:
#line 705 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 6296 "parse.c"
        break;
      case 243:
#line 706 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 6301 "parse.c"
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
#line 6314 "parse.c"
        /* No destructor defined for TRIGGER */
        /* No destructor defined for ON */
        /* No destructor defined for BEGIN */
        break;
      case 247:
#line 719 "parse.y"
{ yygotominor.yy172 = TK_BEFORE; }
#line 6322 "parse.c"
        /* No destructor defined for BEFORE */
        break;
      case 248:
#line 720 "parse.y"
{ yygotominor.yy172 = TK_AFTER;  }
#line 6328 "parse.c"
        /* No destructor defined for AFTER */
        break;
      case 249:
#line 721 "parse.y"
{ yygotominor.yy172 = TK_INSTEAD;}
#line 6334 "parse.c"
        /* No destructor defined for INSTEAD */
        /* No destructor defined for OF */
        break;
      case 250:
#line 722 "parse.y"
{ yygotominor.yy172 = TK_BEFORE; }
#line 6341 "parse.c"
        break;
      case 251:
#line 726 "parse.y"
{ yygotominor.yy90.a = TK_DELETE; yygotominor.yy90.b = 0; }
#line 6346 "parse.c"
        /* No destructor defined for DELETE */
        break;
      case 252:
#line 727 "parse.y"
{ yygotominor.yy90.a = TK_INSERT; yygotominor.yy90.b = 0; }
#line 6352 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 253:
#line 728 "parse.y"
{ yygotominor.yy90.a = TK_UPDATE; yygotominor.yy90.b = 0;}
#line 6358 "parse.c"
        /* No destructor defined for UPDATE */
        break;
      case 254:
#line 729 "parse.y"
{yygotominor.yy90.a = TK_UPDATE; yygotominor.yy90.b = yymsp[0].minor.yy250; }
#line 6364 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for OF */
        break;
      case 255:
#line 732 "parse.y"
{ yygotominor.yy172 = TK_ROW; }
#line 6371 "parse.c"
        break;
      case 256:
#line 733 "parse.y"
{ yygotominor.yy172 = TK_ROW; }
#line 6376 "parse.c"
        /* No destructor defined for FOR */
        /* No destructor defined for EACH */
        /* No destructor defined for ROW */
        break;
      case 257:
#line 734 "parse.y"
{ yygotominor.yy172 = TK_STATEMENT; }
#line 6384 "parse.c"
        /* No destructor defined for FOR */
        /* No destructor defined for EACH */
        /* No destructor defined for STATEMENT */
        break;
      case 258:
#line 737 "parse.y"
{ yygotominor.yy308 = 0; }
#line 6392 "parse.c"
        break;
      case 259:
#line 738 "parse.y"
{ yygotominor.yy308 = yymsp[0].minor.yy62; }
#line 6397 "parse.c"
        /* No destructor defined for WHEN */
        break;
      case 260:
#line 741 "parse.y"
{
  yymsp[-2].minor.yy311->pNext = yymsp[0].minor.yy311 ; yygotominor.yy311 = yymsp[-2].minor.yy311; }
#line 6404 "parse.c"
        /* No destructor defined for SEMI */
        break;
      case 261:
#line 743 "parse.y"
{ yygotominor.yy311 = 0; }
#line 6410 "parse.c"
        break;
      case 262:
#line 748 "parse.y"
{ yygotominor.yy311 = sqliteTriggerUpdateStep(&yymsp[-3].minor.yy378, yymsp[-1].minor.yy228, yymsp[0].minor.yy62, yymsp[-4].minor.yy172); }
#line 6415 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 263:
#line 753 "parse.y"
{yygotominor.yy311 = sqliteTriggerInsertStep(&yymsp[-5].minor.yy378, yymsp[-4].minor.yy250, yymsp[-1].minor.yy228, 0, yymsp[-7].minor.yy172);}
#line 6422 "parse.c"
        /* No destructor defined for INSERT */
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 264:
#line 756 "parse.y"
{yygotominor.yy311 = sqliteTriggerInsertStep(&yymsp[-2].minor.yy378, yymsp[-1].minor.yy250, 0, yymsp[0].minor.yy219, yymsp[-4].minor.yy172);}
#line 6432 "parse.c"
        /* No destructor defined for INSERT */
        /* No destructor defined for INTO */
        break;
      case 265:
#line 760 "parse.y"
{yygotominor.yy311 = sqliteTriggerDeleteStep(&yymsp[-1].minor.yy378, yymsp[0].minor.yy62);}
#line 6439 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 266:
#line 763 "parse.y"
{yygotominor.yy311 = sqliteTriggerSelectStep(yymsp[0].minor.yy219); }
#line 6446 "parse.c"
        break;
      case 267:
#line 766 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, 0); 
    yygotominor.yy62->iColumn = OE_Ignore; sqliteExprSpan(yygotominor.yy62, &yymsp[-3].minor.yy0, &yymsp[0].minor.yy0);}
#line 6452 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for IGNORE */
        break;
      case 268:
#line 769 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy378); 
    yygotominor.yy62->iColumn = OE_Rollback; sqliteExprSpan(yygotominor.yy62, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);}
#line 6460 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for ROLLBACK */
        /* No destructor defined for COMMA */
        break;
      case 269:
#line 772 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy378); 
    yygotominor.yy62->iColumn = OE_Abort; sqliteExprSpan(yygotominor.yy62, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);}
#line 6469 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for ABORT */
        /* No destructor defined for COMMA */
        break;
      case 270:
#line 775 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy378); 
    yygotominor.yy62->iColumn = OE_Fail; sqliteExprSpan(yygotominor.yy62, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);}
#line 6478 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for FAIL */
        /* No destructor defined for COMMA */
        break;
      case 271:
#line 779 "parse.y"
{
    sqliteDropTrigger(pParse,&yymsp[0].minor.yy378,0);
}
#line 6488 "parse.c"
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

#line 6538 "parse.c"
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
