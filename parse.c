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
#define YYNSTATE 525
#define YYNRULE 277
#define YYERRORSYMBOL 147
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
  { 134,   4,   1}, /*  1:                cmdlist shift  1 */
  { 103,   0, 522}, /*  2:                   SEMI shift  522 */
  { 146,   1, 524}, /*  3:                   ecmd shift  524 */
  {  44,   0, 523}, /*  4:                EXPLAIN shift  523 */
  { 148,   0,   3}, /*  5:                explain shift  3 */
  { 161,   0, 803}, /*  6:                  input accept */
/* State 1 */
  {   0,   0, 525}, /*  1:                      $ reduce 0 */
  { 146,   0,   2}, /*  2:                   ecmd shift  2 */
  { 103,   0, 522}, /*  3:                   SEMI shift  522 */
  { 148,   3,   3}, /*  4:                explain shift  3 */
  {  44,   0, 523}, /*  5:                EXPLAIN shift  523 */
/* State 3 */
  { 133,   0,   4}, /*  1:                    cmd shift  4 */
  {  96,   0, 494}, /*  2:                REPLACE shift  494 */
  {  40,   0,  24}, /*  3:                    END shift  24 */
  {  98,   0,  26}, /*  4:               ROLLBACK shift  26 */
  {  23,   0,  22}, /*  5:                 COMMIT shift  22 */
  { 119,   0, 477}, /*  6:                 UPDATE shift  477 */
  { 177,  11,  68}, /*  7:              oneselect shift  68 */
  { 121,  12, 503}, /*  8:                 VACUUM shift  503 */
  { 141,  15,  28}, /*  9:           create_table shift  28 */
  {  28,  17, 376}, /* 10:                 CREATE shift  376 */
  {  63,   0, 492}, /* 11:                 INSERT shift  492 */
  { 102,   0,  72}, /* 12:                 SELECT shift  72 */
  { 164,   0, 483}, /* 13:             insert_cmd shift  483 */
  {  32,   0, 473}, /* 14:                 DELETE shift  473 */
  {  27,   0, 495}, /* 15:                   COPY shift  495 */
  {  91,   0, 505}, /* 16:                 PRAGMA shift  505 */
  {   9,   0,   6}, /* 17:                  BEGIN shift  6 */
  {  37,   0, 463}, /* 18:                   DROP shift  463 */
  { 189,  18, 472}, /* 19:                 select shift  472 */
/* State 4 */
  { 103,   0,   5}, /*  1:                   SEMI shift  5 */
/* State 6 */
  { 113,   0,  17}, /*  1:            TRANSACTION shift  17 */
  { 199,   1,   7}, /*  2:              trans_opt shift  7 */
/* State 7 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 103,   0, 613}, /*  2:                   SEMI reduce 88 */
  { 176,   0,   8}, /*  3:                 onconf shift  8 */
/* State 8 */
  { 103,   0, 532}, /*  1:                   SEMI reduce 7 */
/* State 9 */
  {  25,   0,  10}, /*  1:               CONFLICT shift  10 */
/* State 10 */
  { 186,   5,  11}, /*  1:            resolvetype shift  11 */
  {   1,   0,  13}, /*  2:                  ABORT shift  13 */
  {  98,   0,  12}, /*  3:               ROLLBACK shift  12 */
  {  57,   6,  15}, /*  4:                 IGNORE shift  15 */
  {  96,   0,  16}, /*  5:                REPLACE shift  16 */
  {  45,   0,  14}, /*  6:                   FAIL shift  14 */
/* State 17 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3,  18}, /*  2:                     nm shift  18 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 22 */
  { 103,   0, 533}, /*  1:                   SEMI reduce 8 */
  { 199,   1,  23}, /*  2:              trans_opt shift  23 */
  { 113,   0,  17}, /*  3:            TRANSACTION shift  17 */
/* State 23 */
  { 103,   0, 536}, /*  1:                   SEMI reduce 11 */
/* State 24 */
  { 103,   0, 533}, /*  1:                   SEMI reduce 8 */
  { 199,   1,  25}, /*  2:              trans_opt shift  25 */
  { 113,   0,  17}, /*  3:            TRANSACTION shift  17 */
/* State 25 */
  { 103,   0, 537}, /*  1:                   SEMI reduce 12 */
/* State 26 */
  { 103,   0, 533}, /*  1:                   SEMI reduce 8 */
  { 199,   1,  27}, /*  2:              trans_opt shift  27 */
  { 113,   0,  17}, /*  3:            TRANSACTION shift  17 */
/* State 27 */
  { 103,   0, 538}, /*  1:                   SEMI reduce 13 */
/* State 28 */
  {   6,   0, 374}, /*  1:                     AS shift  374 */
  { 142,   3,  29}, /*  2:      create_table_args shift  29 */
  {  76,   0,  30}, /*  3:                     LP shift  30 */
/* State 29 */
  { 103,   0, 539}, /*  1:                   SEMI reduce 14 */
/* State 30 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  {  71,   0,  21}, /*  2:                JOIN_KW shift  21 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  { 136,   0, 373}, /*  4:                 column shift  373 */
  { 137,   3,  36}, /*  5:               columnid shift  36 */
  { 173,   7, 342}, /*  6:                     nm shift  342 */
  { 138,   0,  31}, /*  7:             columnlist shift  31 */
/* State 31 */
  {  21,   0,  34}, /*  1:                  COMMA shift  34 */
  { 100,   0, 601}, /*  2:                     RP reduce 76 */
  { 140,   0,  32}, /*  3:           conslist_opt shift  32 */
/* State 32 */
  { 100,   0,  33}, /*  1:                     RP shift  33 */
/* State 33 */
  { 103,   0, 543}, /*  1:                   SEMI reduce 18 */
/* State 34 */
  {  26,   0, 346}, /*  1:             CONSTRAINT shift  346 */
  { 118,   4, 354}, /*  2:                 UNIQUE shift  354 */
  { 197,   0, 372}, /*  3:                  tcons shift  372 */
  {  92,   0, 348}, /*  4:                PRIMARY shift  348 */
  { 173,   9, 342}, /*  5:                     nm shift  342 */
  { 109,   0,  20}, /*  6:                 STRING shift  20 */
  { 136,  11,  35}, /*  7:                 column shift  35 */
  { 137,   0,  36}, /*  8:               columnid shift  36 */
  {  56,  12,  19}, /*  9:                     ID shift  19 */
  { 139,  13, 343}, /* 10:               conslist shift  343 */
  {  71,   0,  21}, /* 11:                JOIN_KW shift  21 */
  {  17,   0, 359}, /* 12:                  CHECK shift  359 */
  {  48,   0, 362}, /* 13:                FOREIGN shift  362 */
/* State 36 */
  { 205,   0, 328}, /*  1:               typename shift  328 */
  {  56,   0, 246}, /*  2:                     ID shift  246 */
  { 157,   0, 341}, /*  3:                    ids shift  341 */
  { 109,   0, 247}, /*  4:                 STRING shift  247 */
  { 204,   4,  37}, /*  5:                   type shift  37 */
/* State 37 */
  { 128,   0,  38}, /*  1:               carglist shift  38 */
/* State 38 */
  {  84,   0,  43}, /*  1:                   NULL shift  43 */
  { 127,   5,  39}, /*  2:                   carg shift  39 */
  {  30,   0, 313}, /*  3:             DEFERRABLE shift  313 */
  { 185,   8, 289}, /*  4:             references shift  289 */
  {  29,   0, 316}, /*  5:                DEFAULT shift  316 */
  {  19,   0, 291}, /*  6:                COLLATE shift  291 */
  { 132,  10, 315}, /*  7:                  ccons shift  315 */
  { 143,  12, 290}, /*  8:        defer_subclause shift  290 */
  {  92,   0,  53}, /*  9:                PRIMARY shift  53 */
  { 118,   0,  59}, /* 10:                 UNIQUE shift  59 */
  {  94,   0, 293}, /* 11:             REFERENCES shift  293 */
  {  17,   0,  61}, /* 12:                  CHECK shift  61 */
  {  82,  14,  45}, /* 13:                    NOT shift  45 */
  {  26,   0,  40}, /* 14:             CONSTRAINT shift  40 */
/* State 40 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3,  41}, /*  2:                     nm shift  41 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 41 */
  { 143,   2, 290}, /*  1:        defer_subclause shift  290 */
  { 132,   0,  42}, /*  2:                  ccons shift  42 */
  {  17,   0,  61}, /*  3:                  CHECK shift  61 */
  {  30,  11, 313}, /*  4:             DEFERRABLE shift  313 */
  {  92,   0,  53}, /*  5:                PRIMARY shift  53 */
  {  82,   0,  45}, /*  6:                    NOT shift  45 */
  {  94,   3, 293}, /*  7:             REFERENCES shift  293 */
  {  84,   0,  43}, /*  8:                   NULL shift  43 */
  { 118,   4,  59}, /*  9:                 UNIQUE shift  59 */
  { 185,   0, 289}, /* 10:             references shift  289 */
  {  19,   0, 291}, /* 11:                COLLATE shift  291 */
/* State 43 */
  { 176,   0,  44}, /*  1:                 onconf shift  44 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 45 */
  {  84,   2,  46}, /*  1:                   NULL shift  46 */
  {  30,   0,  48}, /*  2:             DEFERRABLE shift  48 */
/* State 46 */
  { 176,   0,  47}, /*  1:                 onconf shift  47 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 48 */
  { 160,   2,  49}, /*  1: init_deferred_pred_opt shift  49 */
  {  62,   0,  50}, /*  2:              INITIALLY shift  50 */
/* State 50 */
  {  31,   0,  51}, /*  1:               DEFERRED shift  51 */
  {  59,   1,  52}, /*  2:              IMMEDIATE shift  52 */
/* State 53 */
  {  72,   0,  54}, /*  1:                    KEY shift  54 */
/* State 54 */
  { 195,   0,  55}, /*  1:              sortorder shift  55 */
  {  34,   3,  58}, /*  2:                   DESC shift  58 */
  {   7,   0,  57}, /*  3:                    ASC shift  57 */
/* State 55 */
  { 176,   0,  56}, /*  1:                 onconf shift  56 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 59 */
  { 176,   0,  60}, /*  1:                 onconf shift  60 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 61 */
  {  76,   0,  62}, /*  1:                     LP shift  62 */
/* State 62 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 286}, /* 15:                   expr shift  286 */
/* State 63 */
  {  76,   2,  64}, /*  1:                     LP shift  64 */
  {  36,   0, 552}, /*  2:                    DOT reduce 27 */
/* State 64 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  { 109,   0,  65}, /*  2:                 STRING shift  65 */
  {  56,   0,  63}, /*  3:                     ID shift  63 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  {  76,   0,  67}, /*  5:                     LP shift  67 */
  { 149,   0, 165}, /*  6:                   expr shift  165 */
  { 150,   0, 210}, /*  7:               expritem shift  210 */
  { 151,   0, 282}, /*  8:               exprlist shift  282 */
  {  80,   0, 170}, /*  9:                  MINUS shift  170 */
  {  46,   0, 104}, /* 10:                  FLOAT shift  104 */
  {  82,  10, 166}, /* 11:                    NOT shift  166 */
  { 173,  14, 100}, /* 12:                     nm shift  100 */
  {  84,  15,  99}, /* 13:                   NULL shift  99 */
  {  65,   0, 103}, /* 14:                INTEGER shift  103 */
  {  12,   0, 168}, /* 15:                 BITNOT shift  168 */
  {  71,   0,  66}, /* 16:                JOIN_KW shift  66 */
  {  16,   0, 174}, /* 17:                   CASE shift  174 */
  { 107,  16, 284}, /* 18:                   STAR shift  284 */
/* State 65 */
  {  36,   0, 553}, /*  1:                    DOT reduce 28 */
/* State 66 */
  {  36,   0, 554}, /*  1:                    DOT reduce 29 */
/* State 67 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  { 109,   0,  65}, /*  2:                 STRING shift  65 */
  {  56,   0,  63}, /*  3:                     ID shift  63 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  {  76,   0,  67}, /*  5:                     LP shift  67 */
  { 149,   0, 280}, /*  6:                   expr shift  280 */
  {  46,   0, 104}, /*  7:                  FLOAT shift  104 */
  {  65,   0, 103}, /*  8:                INTEGER shift  103 */
  {  80,   0, 170}, /*  9:                  MINUS shift  170 */
  { 189,   0,  69}, /* 10:                 select shift  69 */
  {  82,   7, 166}, /* 11:                    NOT shift  166 */
  { 173,   8, 100}, /* 12:                     nm shift  100 */
  { 102,  14,  72}, /* 13:                 SELECT shift  72 */
  {  84,  15,  99}, /* 14:                   NULL shift  99 */
  {  12,   0, 168}, /* 15:                 BITNOT shift  168 */
  { 177,   0,  68}, /* 16:              oneselect shift  68 */
  {  16,   0, 174}, /* 17:                   CASE shift  174 */
  {  71,   0,  66}, /* 18:                JOIN_KW shift  66 */
/* State 69 */
  { 100,   0, 279}, /*  1:                     RP shift  279 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 172,   5,  70}, /*  3:         multiselect_op shift  70 */
  {  43,   0, 163}, /*  4:                 EXCEPT shift  163 */
  { 117,   0, 160}, /*  5:                  UNION shift  160 */
/* State 70 */
  { 102,   0,  72}, /*  1:                 SELECT shift  72 */
  { 177,   0,  71}, /*  2:              oneselect shift  71 */
/* State 72 */
  {   4,   0, 278}, /*  1:                    ALL shift  278 */
  { 145,   1,  73}, /*  2:               distinct shift  73 */
  {  35,   0, 277}, /*  3:               DISTINCT shift  277 */
/* State 73 */
  { 188,   0,  74}, /*  1:             selcollist shift  74 */
  { 187,   0, 270}, /*  2:                   sclp shift  270 */
/* State 74 */
  { 153,   3,  75}, /*  1:                   from shift  75 */
  {  49,   0, 233}, /*  2:                   FROM shift  233 */
  {  21,   0, 232}, /*  3:                  COMMA shift  232 */
/* State 75 */
  { 125,   0, 230}, /*  1:                  WHERE shift  230 */
  { 209,   1,  76}, /*  2:              where_opt shift  76 */
/* State 76 */
  { 154,   0,  77}, /*  1:            groupby_opt shift  77 */
  {  53,   0, 227}, /*  2:                  GROUP shift  227 */
/* State 77 */
  {  55,   0, 225}, /*  1:                 HAVING shift  225 */
  { 155,   1,  78}, /*  2:             having_opt shift  78 */
/* State 78 */
  {  89,   0,  87}, /*  1:                  ORDER shift  87 */
  { 179,   1,  79}, /*  2:            orderby_opt shift  79 */
/* State 79 */
  {  75,   0,  81}, /*  1:                  LIMIT shift  81 */
  { 169,   1,  80}, /*  2:              limit_opt shift  80 */
/* State 81 */
  {  65,   0,  82}, /*  1:                INTEGER shift  82 */
/* State 82 */
  {  21,   0,  86}, /*  1:                  COMMA shift  86 */
  {  86,   0,  85}, /*  2:                 OFFSET shift  85 */
  { 170,   2,  83}, /*  3:              limit_sep shift  83 */
/* State 83 */
  {  65,   0,  84}, /*  1:                INTEGER shift  84 */
/* State 85 */
  {  65,   0, 676}, /*  1:                INTEGER reduce 151 */
/* State 86 */
  {  65,   0, 677}, /*  1:                INTEGER reduce 152 */
/* State 87 */
  {  14,   0,  88}, /*  1:                     BY shift  88 */
/* State 88 */
  {  71,   0,  66}, /*  1:                JOIN_KW shift  66 */
  {  56,   0,  63}, /*  2:                     ID shift  63 */
  { 109,   0,  65}, /*  3:                 STRING shift  65 */
  { 173,   1, 100}, /*  4:                     nm shift  100 */
  {  76,   0,  67}, /*  5:                     LP shift  67 */
  {  90,   2, 172}, /*  6:                   PLUS shift  172 */
  { 193,   0, 222}, /*  7:               sortitem shift  222 */
  { 194,   3,  89}, /*  8:               sortlist shift  89 */
  {  93,   5, 184}, /*  9:                  RAISE shift  184 */
  {  46,  11, 104}, /* 10:                  FLOAT shift  104 */
  {  12,   0, 168}, /* 11:                 BITNOT shift  168 */
  {  65,   0, 103}, /* 12:                INTEGER shift  103 */
  {  80,  10, 170}, /* 13:                  MINUS shift  170 */
  { 149,   0,  97}, /* 14:                   expr shift  97 */
  {  82,  12, 166}, /* 15:                    NOT shift  166 */
  {  16,   0, 174}, /* 16:                   CASE shift  174 */
  {  84,  16,  99}, /* 17:                   NULL shift  99 */
/* State 89 */
  {  21,   0,  90}, /*  1:                  COMMA shift  90 */
/* State 90 */
  {  80,   4, 170}, /*  1:                  MINUS shift  170 */
  { 193,   7,  91}, /*  2:               sortitem shift  91 */
  {  82,   0, 166}, /*  3:                    NOT shift  166 */
  {  16,   0, 174}, /*  4:                   CASE shift  174 */
  {  84,   0,  99}, /*  5:                   NULL shift  99 */
  { 149,   0,  97}, /*  6:                   expr shift  97 */
  {  65,   0, 103}, /*  7:                INTEGER shift  103 */
  {  71,   0,  66}, /*  8:                JOIN_KW shift  66 */
  {  56,   0,  63}, /*  9:                     ID shift  63 */
  {  12,   0, 168}, /* 10:                 BITNOT shift  168 */
  {  90,   0, 172}, /* 11:                   PLUS shift  172 */
  { 109,  16,  65}, /* 12:                 STRING shift  65 */
  {  76,  10,  67}, /* 13:                     LP shift  67 */
  { 173,  12, 100}, /* 14:                     nm shift  100 */
  {  46,   0, 104}, /* 15:                  FLOAT shift  104 */
  {  93,   0, 184}, /* 16:                  RAISE shift  184 */
/* State 91 */
  {  19,   0,  94}, /*  1:                COLLATE shift  94 */
  { 135,   1,  92}, /*  2:                collate shift  92 */
/* State 92 */
  { 195,   0,  93}, /*  1:              sortorder shift  93 */
  {  34,   3,  58}, /*  2:                   DESC shift  58 */
  {   7,   0,  57}, /*  3:                    ASC shift  57 */
/* State 94 */
  { 156,   2,  96}, /*  1:                     id shift  96 */
  {  56,   0,  95}, /*  2:                     ID shift  95 */
/* State 97 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  60,   0, 157}, /*  5:                     IN shift  157 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  { 168,   5, 128}, /*  7:                 likeop shift  128 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  {  68,   0, 148}, /*  9:                     IS shift  148 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   9, 143}, /* 15:                    REM shift  143 */
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
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 105}, /* 15:                   expr shift  105 */
/* State 100 */
  {  36,   0, 101}, /*  1:                    DOT shift  101 */
/* State 101 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 102}, /*  2:                     nm shift  102 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
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
  { 168,  22, 128}, /* 19:                 likeop shift  128 */
  {  69,   0, 147}, /* 20:                 ISNULL shift  147 */
  {  95,   0, 143}, /* 21:                    REM shift  143 */
  {  68,   0, 148}, /* 22:                     IS shift  148 */
  {  24,   0, 145}, /* 23:                 CONCAT shift  145 */
  {  73,   0, 112}, /* 24:                     LE shift  112 */
  {  74,  23, 133}, /* 25:                   LIKE shift  133 */
/* State 106 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 107}, /* 15:                   expr shift  107 */
/* State 107 */
  {  78,   7, 108}, /*  1:                     LT shift  108 */
  { 105,   0, 141}, /*  2:                  SLASH shift  141 */
  {  80,   8, 137}, /*  3:                  MINUS shift  137 */
  { 107,  10, 139}, /*  4:                   STAR shift  139 */
  {  82,   0, 130}, /*  5:                    NOT shift  130 */
  {  83,  15, 152}, /*  6:                NOTNULL shift  152 */
  {  52,   0, 134}, /*  7:                   GLOB shift  134 */
  {  54,   0, 110}, /*  8:                     GT shift  110 */
  {  60,   0, 157}, /*  9:                     IN shift  157 */
  {  81,   0, 116}, /* 10:                     NE shift  116 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  { 168,  16, 128}, /* 13:                 likeop shift  128 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {   5,   0,  98}, /* 15:                    AND shift  98 */
  {  90,   0, 135}, /* 16:                   PLUS shift  135 */
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
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 109}, /* 15:                   expr shift  109 */
/* State 109 */
  {  77,   2, 124}, /*  1:                 LSHIFT shift  124 */
  {  11,   0, 120}, /*  2:                 BITAND shift  120 */
  { 101,   5, 126}, /*  3:                 RSHIFT shift  126 */
  { 168,   6, 128}, /*  4:                 likeop shift  128 */
  {  90,  10, 135}, /*  5:                   PLUS shift  135 */
  {  80,   0, 137}, /*  6:                  MINUS shift  137 */
  { 105,   0, 141}, /*  7:                  SLASH shift  141 */
  {  95,   0, 143}, /*  8:                    REM shift  143 */
  { 107,   0, 139}, /*  9:                   STAR shift  139 */
  {  24,  11, 145}, /* 10:                 CONCAT shift  145 */
  {  13,   0, 122}, /* 11:                  BITOR shift  122 */
/* State 110 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 111}, /* 15:                   expr shift  111 */
/* State 111 */
  {  77,   2, 124}, /*  1:                 LSHIFT shift  124 */
  {  11,   0, 120}, /*  2:                 BITAND shift  120 */
  { 101,   5, 126}, /*  3:                 RSHIFT shift  126 */
  { 168,   6, 128}, /*  4:                 likeop shift  128 */
  {  90,  10, 135}, /*  5:                   PLUS shift  135 */
  {  80,   0, 137}, /*  6:                  MINUS shift  137 */
  { 105,   0, 141}, /*  7:                  SLASH shift  141 */
  {  95,   0, 143}, /*  8:                    REM shift  143 */
  { 107,   0, 139}, /*  9:                   STAR shift  139 */
  {  24,  11, 145}, /* 10:                 CONCAT shift  145 */
  {  13,   0, 122}, /* 11:                  BITOR shift  122 */
/* State 112 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 113}, /* 15:                   expr shift  113 */
/* State 113 */
  {  77,   2, 124}, /*  1:                 LSHIFT shift  124 */
  {  11,   0, 120}, /*  2:                 BITAND shift  120 */
  { 101,   5, 126}, /*  3:                 RSHIFT shift  126 */
  { 168,   6, 128}, /*  4:                 likeop shift  128 */
  {  90,  10, 135}, /*  5:                   PLUS shift  135 */
  {  80,   0, 137}, /*  6:                  MINUS shift  137 */
  { 105,   0, 141}, /*  7:                  SLASH shift  141 */
  {  95,   0, 143}, /*  8:                    REM shift  143 */
  { 107,   0, 139}, /*  9:                   STAR shift  139 */
  {  24,  11, 145}, /* 10:                 CONCAT shift  145 */
  {  13,   0, 122}, /* 11:                  BITOR shift  122 */
/* State 114 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 115}, /* 15:                   expr shift  115 */
/* State 115 */
  {  77,   2, 124}, /*  1:                 LSHIFT shift  124 */
  {  11,   0, 120}, /*  2:                 BITAND shift  120 */
  { 101,   5, 126}, /*  3:                 RSHIFT shift  126 */
  { 168,   6, 128}, /*  4:                 likeop shift  128 */
  {  90,  10, 135}, /*  5:                   PLUS shift  135 */
  {  80,   0, 137}, /*  6:                  MINUS shift  137 */
  { 105,   0, 141}, /*  7:                  SLASH shift  141 */
  {  95,   0, 143}, /*  8:                    REM shift  143 */
  { 107,   0, 139}, /*  9:                   STAR shift  139 */
  {  24,  11, 145}, /* 10:                 CONCAT shift  145 */
  {  13,   0, 122}, /* 11:                  BITOR shift  122 */
/* State 116 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 117}, /* 15:                   expr shift  117 */
/* State 117 */
  { 105,   2, 141}, /*  1:                  SLASH shift  141 */
  {  90,   0, 135}, /*  2:                   PLUS shift  135 */
  { 107,   5, 139}, /*  3:                   STAR shift  139 */
  { 168,   8, 128}, /*  4:                 likeop shift  128 */
  {  77,   0, 124}, /*  5:                 LSHIFT shift  124 */
  {  95,   9, 143}, /*  6:                    REM shift  143 */
  {  51,   0, 114}, /*  7:                     GE shift  114 */
  {  78,   0, 108}, /*  8:                     LT shift  108 */
  {  80,   0, 137}, /*  9:                  MINUS shift  137 */
  {  54,  11, 110}, /* 10:                     GT shift  110 */
  {  24,   0, 145}, /* 11:                 CONCAT shift  145 */
  { 101,  13, 126}, /* 12:                 RSHIFT shift  126 */
  {  11,   0, 120}, /* 13:                 BITAND shift  120 */
  {  73,  15, 112}, /* 14:                     LE shift  112 */
  {  13,   0, 122}, /* 15:                  BITOR shift  122 */
/* State 118 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 119}, /* 15:                   expr shift  119 */
/* State 119 */
  { 105,   2, 141}, /*  1:                  SLASH shift  141 */
  {  90,   0, 135}, /*  2:                   PLUS shift  135 */
  { 107,   5, 139}, /*  3:                   STAR shift  139 */
  { 168,   8, 128}, /*  4:                 likeop shift  128 */
  {  77,   0, 124}, /*  5:                 LSHIFT shift  124 */
  {  95,   9, 143}, /*  6:                    REM shift  143 */
  {  51,   0, 114}, /*  7:                     GE shift  114 */
  {  78,   0, 108}, /*  8:                     LT shift  108 */
  {  80,   0, 137}, /*  9:                  MINUS shift  137 */
  {  54,  11, 110}, /* 10:                     GT shift  110 */
  {  24,   0, 145}, /* 11:                 CONCAT shift  145 */
  { 101,  13, 126}, /* 12:                 RSHIFT shift  126 */
  {  11,   0, 120}, /* 13:                 BITAND shift  120 */
  {  73,  15, 112}, /* 14:                     LE shift  112 */
  {  13,   0, 122}, /* 15:                  BITOR shift  122 */
/* State 120 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 121}, /* 15:                   expr shift  121 */
/* State 121 */
  { 168,   2, 128}, /*  1:                 likeop shift  128 */
  { 105,   0, 141}, /*  2:                  SLASH shift  141 */
  { 107,   0, 139}, /*  3:                   STAR shift  139 */
  {  80,   6, 137}, /*  4:                  MINUS shift  137 */
  {  95,   0, 143}, /*  5:                    REM shift  143 */
  {  24,   0, 145}, /*  6:                 CONCAT shift  145 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
/* State 122 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 123}, /* 15:                   expr shift  123 */
/* State 123 */
  { 168,   2, 128}, /*  1:                 likeop shift  128 */
  { 105,   0, 141}, /*  2:                  SLASH shift  141 */
  { 107,   0, 139}, /*  3:                   STAR shift  139 */
  {  80,   6, 137}, /*  4:                  MINUS shift  137 */
  {  95,   0, 143}, /*  5:                    REM shift  143 */
  {  24,   0, 145}, /*  6:                 CONCAT shift  145 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
/* State 124 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 125}, /* 15:                   expr shift  125 */
/* State 125 */
  { 168,   2, 128}, /*  1:                 likeop shift  128 */
  { 105,   0, 141}, /*  2:                  SLASH shift  141 */
  { 107,   0, 139}, /*  3:                   STAR shift  139 */
  {  80,   6, 137}, /*  4:                  MINUS shift  137 */
  {  95,   0, 143}, /*  5:                    REM shift  143 */
  {  24,   0, 145}, /*  6:                 CONCAT shift  145 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
/* State 126 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 127}, /* 15:                   expr shift  127 */
/* State 127 */
  { 168,   2, 128}, /*  1:                 likeop shift  128 */
  { 105,   0, 141}, /*  2:                  SLASH shift  141 */
  { 107,   0, 139}, /*  3:                   STAR shift  139 */
  {  80,   6, 137}, /*  4:                  MINUS shift  137 */
  {  95,   0, 143}, /*  5:                    REM shift  143 */
  {  24,   0, 145}, /*  6:                 CONCAT shift  145 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
/* State 128 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 129}, /* 15:                   expr shift  129 */
/* State 129 */
  { 105,   2, 141}, /*  1:                  SLASH shift  141 */
  {  90,   0, 135}, /*  2:                   PLUS shift  135 */
  { 107,   5, 139}, /*  3:                   STAR shift  139 */
  { 168,   8, 128}, /*  4:                 likeop shift  128 */
  {  77,   0, 124}, /*  5:                 LSHIFT shift  124 */
  {  95,   9, 143}, /*  6:                    REM shift  143 */
  {  51,   0, 114}, /*  7:                     GE shift  114 */
  {  78,   0, 108}, /*  8:                     LT shift  108 */
  {  80,   0, 137}, /*  9:                  MINUS shift  137 */
  {  54,  11, 110}, /* 10:                     GT shift  110 */
  {  24,   0, 145}, /* 11:                 CONCAT shift  145 */
  { 101,  13, 126}, /* 12:                 RSHIFT shift  126 */
  {  11,   0, 120}, /* 13:                 BITAND shift  120 */
  {  73,  15, 112}, /* 14:                     LE shift  112 */
  {  13,   0, 122}, /* 15:                  BITOR shift  122 */
/* State 130 */
  { 168,   2, 131}, /*  1:                 likeop shift  131 */
  {  84,   4, 211}, /*  2:                   NULL shift  211 */
  {  74,   0, 133}, /*  3:                   LIKE shift  133 */
  {  60,   0, 216}, /*  4:                     IN shift  216 */
  {  52,   6, 134}, /*  5:                   GLOB shift  134 */
  {  10,   0, 212}, /*  6:                BETWEEN shift  212 */
/* State 131 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 132}, /* 15:                   expr shift  132 */
/* State 132 */
  { 105,   2, 141}, /*  1:                  SLASH shift  141 */
  {  90,   0, 135}, /*  2:                   PLUS shift  135 */
  { 107,   5, 139}, /*  3:                   STAR shift  139 */
  { 168,   8, 128}, /*  4:                 likeop shift  128 */
  {  77,   0, 124}, /*  5:                 LSHIFT shift  124 */
  {  95,   9, 143}, /*  6:                    REM shift  143 */
  {  51,   0, 114}, /*  7:                     GE shift  114 */
  {  78,   0, 108}, /*  8:                     LT shift  108 */
  {  80,   0, 137}, /*  9:                  MINUS shift  137 */
  {  54,  11, 110}, /* 10:                     GT shift  110 */
  {  24,   0, 145}, /* 11:                 CONCAT shift  145 */
  { 101,  13, 126}, /* 12:                 RSHIFT shift  126 */
  {  11,   0, 120}, /* 13:                 BITAND shift  120 */
  {  73,  15, 112}, /* 14:                     LE shift  112 */
  {  13,   0, 122}, /* 15:                  BITOR shift  122 */
/* State 135 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 136}, /* 15:                   expr shift  136 */
/* State 136 */
  { 105,   2, 141}, /*  1:                  SLASH shift  141 */
  {  95,   0, 143}, /*  2:                    REM shift  143 */
  { 107,   0, 139}, /*  3:                   STAR shift  139 */
  { 168,   0, 128}, /*  4:                 likeop shift  128 */
  {  24,   0, 145}, /*  5:                 CONCAT shift  145 */
/* State 137 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 138}, /* 15:                   expr shift  138 */
/* State 138 */
  { 105,   2, 141}, /*  1:                  SLASH shift  141 */
  {  95,   0, 143}, /*  2:                    REM shift  143 */
  { 107,   0, 139}, /*  3:                   STAR shift  139 */
  { 168,   0, 128}, /*  4:                 likeop shift  128 */
  {  24,   0, 145}, /*  5:                 CONCAT shift  145 */
/* State 139 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 140}, /* 15:                   expr shift  140 */
/* State 140 */
  { 168,   2, 128}, /*  1:                 likeop shift  128 */
  {  24,   0, 145}, /*  2:                 CONCAT shift  145 */
/* State 141 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 142}, /* 15:                   expr shift  142 */
/* State 142 */
  { 168,   2, 128}, /*  1:                 likeop shift  128 */
  {  24,   0, 145}, /*  2:                 CONCAT shift  145 */
/* State 143 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 144}, /* 15:                   expr shift  144 */
/* State 144 */
  { 168,   2, 128}, /*  1:                 likeop shift  128 */
  {  24,   0, 145}, /*  2:                 CONCAT shift  145 */
/* State 145 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 146}, /* 15:                   expr shift  146 */
/* State 146 */
  { 168,   0, 128}, /*  1:                 likeop shift  128 */
/* State 148 */
  {  84,   2, 149}, /*  1:                   NULL shift  149 */
  {  82,   0, 150}, /*  2:                    NOT shift  150 */
/* State 150 */
  {  84,   0, 151}, /*  1:                   NULL shift  151 */
/* State 153 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 154}, /* 15:                   expr shift  154 */
/* State 154 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  60,   0, 157}, /*  5:                     IN shift  157 */
  {   5,   0, 155}, /*  6:                    AND shift  155 */
  { 168,   5, 128}, /*  7:                 likeop shift  128 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  {  68,   0, 148}, /*  9:                     IS shift  148 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   9, 143}, /* 15:                    REM shift  143 */
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
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 156}, /* 15:                   expr shift  156 */
/* State 156 */
  { 105,   2, 141}, /*  1:                  SLASH shift  141 */
  {  90,   0, 135}, /*  2:                   PLUS shift  135 */
  { 107,   5, 139}, /*  3:                   STAR shift  139 */
  { 168,   8, 128}, /*  4:                 likeop shift  128 */
  {  77,   0, 124}, /*  5:                 LSHIFT shift  124 */
  {  95,   9, 143}, /*  6:                    REM shift  143 */
  {  51,   0, 114}, /*  7:                     GE shift  114 */
  {  78,   0, 108}, /*  8:                     LT shift  108 */
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
  { 149,   8, 165}, /*  4:                   expr shift  165 */
  {  84,   0,  99}, /*  5:                   NULL shift  99 */
  {  65,   0, 103}, /*  6:                INTEGER shift  103 */
  {  46,   0, 104}, /*  7:                  FLOAT shift  104 */
  { 109,   0,  65}, /*  8:                 STRING shift  65 */
  {  90,   0, 172}, /*  9:                   PLUS shift  172 */
  { 189,   4, 159}, /* 10:                 select shift  159 */
  { 150,   9, 210}, /* 11:               expritem shift  210 */
  { 151,  15, 206}, /* 12:               exprlist shift  206 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  { 173,  16, 100}, /* 14:                     nm shift  100 */
  {  71,   0,  66}, /* 15:                JOIN_KW shift  66 */
  {  93,   0, 184}, /* 16:                  RAISE shift  184 */
  {  76,  19,  67}, /* 17:                     LP shift  67 */
  { 177,   0,  68}, /* 18:              oneselect shift  68 */
  {  56,  20,  63}, /* 19:                     ID shift  63 */
  {  16,   0, 174}, /* 20:                   CASE shift  174 */
/* State 159 */
  { 100,   0, 164}, /*  1:                     RP shift  164 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 172,   5,  70}, /*  3:         multiselect_op shift  70 */
  {  43,   0, 163}, /*  4:                 EXCEPT shift  163 */
  { 117,   0, 160}, /*  5:                  UNION shift  160 */
/* State 160 */
  { 102,   2, 628}, /*  1:                 SELECT reduce 103 */
  {   4,   0, 161}, /*  2:                    ALL shift  161 */
/* State 161 */
  { 102,   0, 629}, /*  1:                 SELECT reduce 104 */
/* State 162 */
  { 102,   0, 630}, /*  1:                 SELECT reduce 105 */
/* State 163 */
  { 102,   0, 631}, /*  1:                 SELECT reduce 106 */
/* State 165 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  60,   0, 157}, /*  5:                     IN shift  157 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  { 168,   5, 128}, /*  7:                 likeop shift  128 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  {  68,   0, 148}, /*  9:                     IS shift  148 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   9, 143}, /* 15:                    REM shift  143 */
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
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 167}, /* 15:                   expr shift  167 */
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
  { 168,  22, 128}, /* 19:                 likeop shift  128 */
  {  69,   0, 147}, /* 20:                 ISNULL shift  147 */
  {  95,   0, 143}, /* 21:                    REM shift  143 */
  {  68,   0, 148}, /* 22:                     IS shift  148 */
  {  24,   0, 145}, /* 23:                 CONCAT shift  145 */
  {  73,   0, 112}, /* 24:                     LE shift  112 */
  {  74,  23, 133}, /* 25:                   LIKE shift  133 */
/* State 168 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 169}, /* 15:                   expr shift  169 */
/* State 169 */
  { 168,   0, 128}, /*  1:                 likeop shift  128 */
/* State 170 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 171}, /* 15:                   expr shift  171 */
/* State 171 */
  { 168,   0, 128}, /*  1:                 likeop shift  128 */
/* State 172 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 173}, /* 15:                   expr shift  173 */
/* State 173 */
  { 168,   0, 128}, /*  1:                 likeop shift  128 */
/* State 174 */
  {  71,   0,  66}, /*  1:                JOIN_KW shift  66 */
  {  90,   3, 172}, /*  2:                   PLUS shift  172 */
  {  56,   0,  63}, /*  3:                     ID shift  63 */
  { 173,   1, 100}, /*  4:                     nm shift  100 */
  {  76,   0,  67}, /*  5:                     LP shift  67 */
  { 124,   2, 748}, /*  6:                   WHEN reduce 223 */
  {  80,  10, 170}, /*  7:                  MINUS shift  170 */
  { 109,   0,  65}, /*  8:                 STRING shift  65 */
  {  93,   5, 184}, /*  9:                  RAISE shift  184 */
  {  46,  11, 104}, /* 10:                  FLOAT shift  104 */
  {  12,   0, 168}, /* 11:                 BITNOT shift  168 */
  {  65,   0, 103}, /* 12:                INTEGER shift  103 */
  { 131,   7, 176}, /* 13:           case_operand shift  176 */
  { 149,   0, 175}, /* 14:                   expr shift  175 */
  {  82,  12, 166}, /* 15:                    NOT shift  166 */
  {  16,   0, 174}, /* 16:                   CASE shift  174 */
  {  84,  16,  99}, /* 17:                   NULL shift  99 */
/* State 175 */
  { 168,   0, 128}, /*  1:                 likeop shift  128 */
  {  60,   0, 157}, /*  2:                     IN shift  157 */
  {  11,   0, 120}, /*  3:                 BITAND shift  120 */
  {  68,   0, 148}, /*  4:                     IS shift  148 */
  {  88,   2, 106}, /*  5:                     OR shift  106 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
  {  13,   0, 122}, /*  8:                  BITOR shift  122 */
  {  73,   0, 112}, /*  9:                     LE shift  112 */
  {  77,   0, 124}, /* 10:                 LSHIFT shift  124 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  95,   3, 143}, /* 12:                    REM shift  143 */
  { 124,   4, 747}, /* 13:                   WHEN reduce 222 */
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
/* State 176 */
  { 130,   2, 177}, /*  1:          case_exprlist shift  177 */
  { 124,   0, 202}, /*  2:                   WHEN shift  202 */
/* State 177 */
  { 124,   3, 180}, /*  1:                   WHEN shift  180 */
  { 129,   0, 178}, /*  2:              case_else shift  178 */
  {  40,   0, 746}, /*  3:                    END reduce 221 */
  {  39,   0, 200}, /*  4:                   ELSE shift  200 */
/* State 178 */
  {  40,   0, 179}, /*  1:                    END shift  179 */
/* State 180 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 181}, /* 15:                   expr shift  181 */
/* State 181 */
  { 168,   2, 128}, /*  1:                 likeop shift  128 */
  { 112,   0, 182}, /*  2:                   THEN shift  182 */
  {  60,   0, 157}, /*  3:                     IN shift  157 */
  {  11,   0, 120}, /*  4:                 BITAND shift  120 */
  {  88,   3, 106}, /*  5:                     OR shift  106 */
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
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 183}, /* 15:                   expr shift  183 */
/* State 183 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  60,   0, 157}, /*  5:                     IN shift  157 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  { 168,   5, 128}, /*  7:                 likeop shift  128 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  {  68,   0, 148}, /*  9:                     IS shift  148 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   9, 143}, /* 15:                    REM shift  143 */
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
  { 173,   3, 190}, /*  2:                     nm shift  190 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 190 */
  { 100,   0, 191}, /*  1:                     RP shift  191 */
/* State 192 */
  {  21,   0, 193}, /*  1:                  COMMA shift  193 */
/* State 193 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 194}, /*  2:                     nm shift  194 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 194 */
  { 100,   0, 195}, /*  1:                     RP shift  195 */
/* State 196 */
  {  21,   0, 197}, /*  1:                  COMMA shift  197 */
/* State 197 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 198}, /*  2:                     nm shift  198 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 198 */
  { 100,   0, 199}, /*  1:                     RP shift  199 */
/* State 200 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 201}, /* 15:                   expr shift  201 */
/* State 201 */
  { 168,   0, 128}, /*  1:                 likeop shift  128 */
  {  60,   0, 157}, /*  2:                     IN shift  157 */
  {  11,   0, 120}, /*  3:                 BITAND shift  120 */
  {  40,   0, 745}, /*  4:                    END reduce 220 */
  {  88,   2, 106}, /*  5:                     OR shift  106 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
  {  13,   0, 122}, /*  8:                  BITOR shift  122 */
  {  73,   0, 112}, /*  9:                     LE shift  112 */
  {  77,   0, 124}, /* 10:                 LSHIFT shift  124 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  95,   3, 143}, /* 12:                    REM shift  143 */
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
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 203}, /* 15:                   expr shift  203 */
/* State 203 */
  { 168,   2, 128}, /*  1:                 likeop shift  128 */
  { 112,   0, 204}, /*  2:                   THEN shift  204 */
  {  60,   0, 157}, /*  3:                     IN shift  157 */
  {  11,   0, 120}, /*  4:                 BITAND shift  120 */
  {  88,   3, 106}, /*  5:                     OR shift  106 */
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
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 205}, /* 15:                   expr shift  205 */
/* State 205 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  60,   0, 157}, /*  5:                     IN shift  157 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  { 168,   5, 128}, /*  7:                 likeop shift  128 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  {  68,   0, 148}, /*  9:                     IS shift  148 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   9, 143}, /* 15:                    REM shift  143 */
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
  { 149,   0, 165}, /*  6:                   expr shift  165 */
  { 150,   0, 209}, /*  7:               expritem shift  209 */
  {  71,   0,  66}, /*  8:                JOIN_KW shift  66 */
  {  56,   0,  63}, /*  9:                     ID shift  63 */
  {  12,   0, 168}, /* 10:                 BITNOT shift  168 */
  {  90,   0, 172}, /* 11:                   PLUS shift  172 */
  { 109,  16,  65}, /* 12:                 STRING shift  65 */
  {  76,  10,  67}, /* 13:                     LP shift  67 */
  { 173,  12, 100}, /* 14:                     nm shift  100 */
  {  46,   0, 104}, /* 15:                  FLOAT shift  104 */
  {  93,   0, 184}, /* 16:                  RAISE shift  184 */
/* State 212 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 213}, /* 15:                   expr shift  213 */
/* State 213 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  60,   0, 157}, /*  5:                     IN shift  157 */
  {   5,   0, 214}, /*  6:                    AND shift  214 */
  { 168,   5, 128}, /*  7:                 likeop shift  128 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  {  68,   0, 148}, /*  9:                     IS shift  148 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   9, 143}, /* 15:                    REM shift  143 */
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
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 215}, /* 15:                   expr shift  215 */
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
  { 168,  22, 128}, /* 19:                 likeop shift  128 */
  {  69,   0, 147}, /* 20:                 ISNULL shift  147 */
  {  95,   0, 143}, /* 21:                    REM shift  143 */
  {  68,   0, 148}, /* 22:                     IS shift  148 */
  {  24,   0, 145}, /* 23:                 CONCAT shift  145 */
  {  73,   0, 112}, /* 24:                     LE shift  112 */
  {  74,  23, 133}, /* 25:                   LIKE shift  133 */
/* State 216 */
  {  76,   0, 217}, /*  1:                     LP shift  217 */
/* State 217 */
  {  80,   0, 170}, /*  1:                  MINUS shift  170 */
  {  82,   0, 166}, /*  2:                    NOT shift  166 */
  { 102,   2,  72}, /*  3:                 SELECT shift  72 */
  { 149,   8, 165}, /*  4:                   expr shift  165 */
  {  84,   0,  99}, /*  5:                   NULL shift  99 */
  {  65,   0, 103}, /*  6:                INTEGER shift  103 */
  {  46,   0, 104}, /*  7:                  FLOAT shift  104 */
  { 109,   0,  65}, /*  8:                 STRING shift  65 */
  {  90,   0, 172}, /*  9:                   PLUS shift  172 */
  { 189,   4, 218}, /* 10:                 select shift  218 */
  { 150,   9, 210}, /* 11:               expritem shift  210 */
  { 151,  15, 220}, /* 12:               exprlist shift  220 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  { 173,  16, 100}, /* 14:                     nm shift  100 */
  {  71,   0,  66}, /* 15:                JOIN_KW shift  66 */
  {  93,   0, 184}, /* 16:                  RAISE shift  184 */
  {  76,  19,  67}, /* 17:                     LP shift  67 */
  { 177,   0,  68}, /* 18:              oneselect shift  68 */
  {  56,  20,  63}, /* 19:                     ID shift  63 */
  {  16,   0, 174}, /* 20:                   CASE shift  174 */
/* State 218 */
  { 100,   0, 219}, /*  1:                     RP shift  219 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 172,   5,  70}, /*  3:         multiselect_op shift  70 */
  {  43,   0, 163}, /*  4:                 EXCEPT shift  163 */
  { 117,   0, 160}, /*  5:                  UNION shift  160 */
/* State 220 */
  { 100,   0, 221}, /*  1:                     RP shift  221 */
  {  21,   0, 208}, /*  2:                  COMMA shift  208 */
/* State 222 */
  {  19,   0,  94}, /*  1:                COLLATE shift  94 */
  { 135,   1, 223}, /*  2:                collate shift  223 */
/* State 223 */
  { 195,   0, 224}, /*  1:              sortorder shift  224 */
  {  34,   3,  58}, /*  2:                   DESC shift  58 */
  {   7,   0,  57}, /*  3:                    ASC shift  57 */
/* State 225 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 226}, /* 15:                   expr shift  226 */
/* State 226 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  60,   0, 157}, /*  5:                     IN shift  157 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  { 168,   5, 128}, /*  7:                 likeop shift  128 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  {  68,   0, 148}, /*  9:                     IS shift  148 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   9, 143}, /* 15:                    REM shift  143 */
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
  {  71,   0,  66}, /*  1:                JOIN_KW shift  66 */
  {  56,   0,  63}, /*  2:                     ID shift  63 */
  {  76,   0,  67}, /*  3:                     LP shift  67 */
  { 173,   1, 100}, /*  4:                     nm shift  100 */
  {  46,   7, 104}, /*  5:                  FLOAT shift  104 */
  {  90,   2, 172}, /*  6:                   PLUS shift  172 */
  {  12,   0, 168}, /*  7:                 BITNOT shift  168 */
  { 109,   0,  65}, /*  8:                 STRING shift  65 */
  {  93,   3, 184}, /*  9:                  RAISE shift  184 */
  {  82,  11, 166}, /* 10:                    NOT shift  166 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  16,   0, 174}, /* 12:                   CASE shift  174 */
  {  80,   5, 170}, /* 13:                  MINUS shift  170 */
  { 149,   0, 165}, /* 14:                   expr shift  165 */
  { 150,  10, 210}, /* 15:               expritem shift  210 */
  { 151,   0, 229}, /* 16:               exprlist shift  229 */
  {  84,  12,  99}, /* 17:                   NULL shift  99 */
/* State 229 */
  {  21,   0, 208}, /*  1:                  COMMA shift  208 */
/* State 230 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 231}, /* 15:                   expr shift  231 */
/* State 231 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  60,   0, 157}, /*  5:                     IN shift  157 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  { 168,   5, 128}, /*  7:                 likeop shift  128 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  {  68,   0, 148}, /*  9:                     IS shift  148 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   9, 143}, /* 15:                    REM shift  143 */
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
  { 196,   2, 244}, /*  1:             stl_prefix shift  244 */
  { 190,   0, 234}, /*  2:             seltablist shift  234 */
/* State 234 */
  {  70,   0, 237}, /*  1:                   JOIN shift  237 */
  {  21,   0, 236}, /*  2:                  COMMA shift  236 */
  { 166,   1, 235}, /*  3:                 joinop shift  235 */
  {  71,   0, 238}, /*  4:                JOIN_KW shift  238 */
/* State 238 */
  {  70,   0, 239}, /*  1:                   JOIN shift  239 */
  {  71,   3,  21}, /*  2:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 173,   0, 240}, /*  4:                     nm shift  240 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 240 */
  {  70,   0, 241}, /*  1:                   JOIN shift  241 */
  {  71,   3,  21}, /*  2:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 173,   0, 242}, /*  4:                     nm shift  242 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 242 */
  {  70,   0, 243}, /*  1:                   JOIN shift  243 */
/* State 244 */
  {  71,   3,  21}, /*  1:                JOIN_KW shift  21 */
  {  76,   1, 264}, /*  2:                     LP shift  264 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 173,   0, 245}, /*  4:                     nm shift  245 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 245 */
  {  56,   4, 246}, /*  1:                     ID shift  246 */
  { 126,   1, 251}, /*  2:                     as shift  251 */
  { 157,   0, 250}, /*  3:                    ids shift  250 */
  {   6,   0, 248}, /*  4:                     AS shift  248 */
  { 109,   0, 247}, /*  5:                 STRING shift  247 */
/* State 248 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 249}, /*  2:                     nm shift  249 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 251 */
  {  87,   0, 262}, /*  1:                     ON shift  262 */
  { 175,   1, 252}, /*  2:                 on_opt shift  252 */
/* State 252 */
  { 120,   0, 254}, /*  1:                  USING shift  254 */
  { 207,   0, 253}, /*  2:              using_opt shift  253 */
/* State 254 */
  {  76,   0, 255}, /*  1:                     LP shift  255 */
/* State 255 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  { 158,   1, 261}, /*  3:                idxitem shift  261 */
  { 159,   0, 256}, /*  4:                idxlist shift  256 */
  {  71,   0,  21}, /*  5:                JOIN_KW shift  21 */
  { 173,   5, 260}, /*  6:                     nm shift  260 */
/* State 256 */
  { 100,   0, 257}, /*  1:                     RP shift  257 */
  {  21,   0, 258}, /*  2:                  COMMA shift  258 */
/* State 258 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  {  71,   1,  21}, /*  2:                JOIN_KW shift  21 */
  { 158,   0, 259}, /*  3:                idxitem shift  259 */
  { 173,   3, 260}, /*  4:                     nm shift  260 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 262 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 263}, /* 15:                   expr shift  263 */
/* State 263 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  60,   0, 157}, /*  5:                     IN shift  157 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  { 168,   5, 128}, /*  7:                 likeop shift  128 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  {  68,   0, 148}, /*  9:                     IS shift  148 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   9, 143}, /* 15:                    REM shift  143 */
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
  { 189,   2, 265}, /*  1:                 select shift  265 */
  { 177,   3,  68}, /*  2:              oneselect shift  68 */
  { 102,   0,  72}, /*  3:                 SELECT shift  72 */
/* State 265 */
  { 100,   0, 266}, /*  1:                     RP shift  266 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 172,   5,  70}, /*  3:         multiselect_op shift  70 */
  {  43,   0, 163}, /*  4:                 EXCEPT shift  163 */
  { 117,   0, 160}, /*  5:                  UNION shift  160 */
/* State 266 */
  {  56,   4, 246}, /*  1:                     ID shift  246 */
  { 126,   1, 267}, /*  2:                     as shift  267 */
  { 157,   0, 250}, /*  3:                    ids shift  250 */
  {   6,   0, 248}, /*  4:                     AS shift  248 */
  { 109,   0, 247}, /*  5:                 STRING shift  247 */
/* State 267 */
  {  87,   0, 262}, /*  1:                     ON shift  262 */
  { 175,   1, 268}, /*  2:                 on_opt shift  268 */
/* State 268 */
  { 120,   0, 254}, /*  1:                  USING shift  254 */
  { 207,   0, 269}, /*  2:              using_opt shift  269 */
/* State 270 */
  {  80,   4, 170}, /*  1:                  MINUS shift  170 */
  {  65,   0, 103}, /*  2:                INTEGER shift  103 */
  {  82,   0, 166}, /*  3:                    NOT shift  166 */
  {  16,   0, 174}, /*  4:                   CASE shift  174 */
  {  84,   0,  99}, /*  5:                   NULL shift  99 */
  { 149,   0, 271}, /*  6:                   expr shift  271 */
  {  12,   0, 168}, /*  7:                 BITNOT shift  168 */
  {  71,   0,  66}, /*  8:                JOIN_KW shift  66 */
  {  56,   0,  63}, /*  9:                     ID shift  63 */
  { 109,  16,  65}, /* 10:                 STRING shift  65 */
  {  90,   0, 172}, /* 11:                   PLUS shift  172 */
  { 107,   0, 273}, /* 12:                   STAR shift  273 */
  {  76,   7,  67}, /* 13:                     LP shift  67 */
  { 173,  10, 274}, /* 14:                     nm shift  274 */
  {  46,   0, 104}, /* 15:                  FLOAT shift  104 */
  {  93,   0, 184}, /* 16:                  RAISE shift  184 */
/* State 271 */
  {  69,   2, 147}, /*  1:                 ISNULL shift  147 */
  {   5,   0,  98}, /*  2:                    AND shift  98 */
  {  73,   0, 112}, /*  3:                     LE shift  112 */
  {  42,   8, 118}, /*  4:                     EQ shift  118 */
  {  68,   0, 148}, /*  5:                     IS shift  148 */
  { 101,   1, 126}, /*  6:                 RSHIFT shift  126 */
  {   6,   0, 248}, /*  7:                     AS shift  248 */
  {  10,   0, 153}, /*  8:                BETWEEN shift  153 */
  { 168,   0, 128}, /*  9:                 likeop shift  128 */
  { 105,   3, 141}, /* 10:                  SLASH shift  141 */
  {  74,   4, 133}, /* 11:                   LIKE shift  133 */
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
  { 157,   0, 250}, /* 30:                    ids shift  250 */
  { 126,   0, 272}, /* 31:                     as shift  272 */
  {  95,   0, 143}, /* 32:                    REM shift  143 */
/* State 274 */
  {  36,   0, 275}, /*  1:                    DOT shift  275 */
/* State 275 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  {  71,   1,  21}, /*  2:                JOIN_KW shift  21 */
  { 107,   0, 276}, /*  3:                   STAR shift  276 */
  { 173,   0, 102}, /*  4:                     nm shift  102 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 280 */
  { 168,   0, 128}, /*  1:                 likeop shift  128 */
  {  60,   0, 157}, /*  2:                     IN shift  157 */
  {  11,   0, 120}, /*  3:                 BITAND shift  120 */
  {  13,   0, 122}, /*  4:                  BITOR shift  122 */
  {  88,   2, 106}, /*  5:                     OR shift  106 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
  {  73,   0, 112}, /*  8:                     LE shift  112 */
  {  77,   0, 124}, /*  9:                 LSHIFT shift  124 */
  {  51,   0, 114}, /* 10:                     GE shift  114 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  95,   3, 143}, /* 12:                    REM shift  143 */
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
  { 168,   0, 128}, /*  1:                 likeop shift  128 */
  {  60,   0, 157}, /*  2:                     IN shift  157 */
  {  11,   0, 120}, /*  3:                 BITAND shift  120 */
  {  13,   0, 122}, /*  4:                  BITOR shift  122 */
  {  88,   2, 106}, /*  5:                     OR shift  106 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
  {  73,   0, 112}, /*  8:                     LE shift  112 */
  {  77,   0, 124}, /*  9:                 LSHIFT shift  124 */
  {  51,   0, 114}, /* 10:                     GE shift  114 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  95,   3, 143}, /* 12:                    REM shift  143 */
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
  { 176,   0, 288}, /*  1:                 onconf shift  288 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 291 */
  { 156,   2, 292}, /*  1:                     id shift  292 */
  {  56,   0,  95}, /*  2:                     ID shift  95 */
/* State 293 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 294}, /*  2:                     nm shift  294 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 294 */
  { 184,   2, 312}, /*  1:                refargs shift  312 */
  {  76,   0, 295}, /*  2:                     LP shift  295 */
/* State 295 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  { 158,   1, 261}, /*  3:                idxitem shift  261 */
  { 159,   0, 296}, /*  4:                idxlist shift  296 */
  {  71,   0,  21}, /*  5:                JOIN_KW shift  21 */
  { 173,   5, 260}, /*  6:                     nm shift  260 */
/* State 296 */
  { 100,   0, 297}, /*  1:                     RP shift  297 */
  {  21,   0, 258}, /*  2:                  COMMA shift  258 */
/* State 297 */
  { 184,   0, 298}, /*  1:                refargs shift  298 */
/* State 298 */
  { 183,   3, 299}, /*  1:                 refarg shift  299 */
  {  79,   0, 300}, /*  2:                  MATCH shift  300 */
  {  87,   0, 302}, /*  3:                     ON shift  302 */
/* State 300 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 301}, /*  2:                     nm shift  301 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 302 */
  {  32,   0, 303}, /*  1:                 DELETE shift  303 */
  { 119,   0, 310}, /*  2:                 UPDATE shift  310 */
/* State 303 */
  { 104,   0, 305}, /*  1:                    SET shift  305 */
  {  97,   0, 309}, /*  2:               RESTRICT shift  309 */
  { 182,   0, 304}, /*  3:                 refact shift  304 */
  {  15,   0, 308}, /*  4:                CASCADE shift  308 */
/* State 305 */
  {  84,   0, 306}, /*  1:                   NULL shift  306 */
  {  29,   0, 307}, /*  2:                DEFAULT shift  307 */
/* State 310 */
  { 104,   0, 305}, /*  1:                    SET shift  305 */
  {  97,   0, 309}, /*  2:               RESTRICT shift  309 */
  { 182,   0, 311}, /*  3:                 refact shift  311 */
  {  15,   0, 308}, /*  4:                CASCADE shift  308 */
/* State 312 */
  { 183,   3, 299}, /*  1:                 refarg shift  299 */
  {  79,   0, 300}, /*  2:                  MATCH shift  300 */
  {  87,   0, 302}, /*  3:                     ON shift  302 */
/* State 313 */
  { 160,   2, 314}, /*  1: init_deferred_pred_opt shift  314 */
  {  62,   0,  50}, /*  2:              INITIALLY shift  50 */
/* State 316 */
  {  84,   2, 327}, /*  1:                   NULL shift  327 */
  {  56,   0, 318}, /*  2:                     ID shift  318 */
  {  65,   0, 319}, /*  3:                INTEGER shift  319 */
  {  80,   0, 323}, /*  4:                  MINUS shift  323 */
  { 109,   6, 317}, /*  5:                 STRING shift  317 */
  {  46,   0, 326}, /*  6:                  FLOAT shift  326 */
  {  90,   0, 320}, /*  7:                   PLUS shift  320 */
/* State 320 */
  {  46,   0, 322}, /*  1:                  FLOAT shift  322 */
  {  65,   0, 321}, /*  2:                INTEGER shift  321 */
/* State 323 */
  {  46,   0, 325}, /*  1:                  FLOAT shift  325 */
  {  65,   0, 324}, /*  2:                INTEGER shift  324 */
/* State 328 */
  {  76,   3, 329}, /*  1:                     LP shift  329 */
  { 157,   4, 340}, /*  2:                    ids shift  340 */
  {  56,   0, 246}, /*  3:                     ID shift  246 */
  { 109,   0, 247}, /*  4:                 STRING shift  247 */
/* State 329 */
  { 192,   4, 330}, /*  1:                 signed shift  330 */
  {  65,   0, 335}, /*  2:                INTEGER shift  335 */
  {  90,   0, 336}, /*  3:                   PLUS shift  336 */
  {  80,   0, 338}, /*  4:                  MINUS shift  338 */
/* State 330 */
  { 100,   0, 331}, /*  1:                     RP shift  331 */
  {  21,   0, 332}, /*  2:                  COMMA shift  332 */
/* State 332 */
  { 192,   4, 333}, /*  1:                 signed shift  333 */
  {  65,   0, 335}, /*  2:                INTEGER shift  335 */
  {  90,   0, 336}, /*  3:                   PLUS shift  336 */
  {  80,   0, 338}, /*  4:                  MINUS shift  338 */
/* State 333 */
  { 100,   0, 334}, /*  1:                     RP shift  334 */
/* State 336 */
  {  65,   0, 337}, /*  1:                INTEGER shift  337 */
/* State 338 */
  {  65,   0, 339}, /*  1:                INTEGER shift  339 */
/* State 343 */
  {  48,   0, 362}, /*  1:                FOREIGN shift  362 */
  {  17,   0, 359}, /*  2:                  CHECK shift  359 */
  {  26,   0, 346}, /*  3:             CONSTRAINT shift  346 */
  {  92,   0, 348}, /*  4:                PRIMARY shift  348 */
  { 100,   4, 602}, /*  5:                     RP reduce 77 */
  { 197,   8, 371}, /*  6:                  tcons shift  371 */
  { 118,   0, 354}, /*  7:                 UNIQUE shift  354 */
  {  21,   0, 344}, /*  8:                  COMMA shift  344 */
/* State 344 */
  {  48,   0, 362}, /*  1:                FOREIGN shift  362 */
  {  26,   0, 346}, /*  2:             CONSTRAINT shift  346 */
  {  92,   2, 348}, /*  3:                PRIMARY shift  348 */
  {  17,   0, 359}, /*  4:                  CHECK shift  359 */
  { 118,   0, 354}, /*  5:                 UNIQUE shift  354 */
  { 197,   4, 345}, /*  6:                  tcons shift  345 */
/* State 346 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 347}, /*  2:                     nm shift  347 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 348 */
  {  72,   0, 349}, /*  1:                    KEY shift  349 */
/* State 349 */
  {  76,   0, 350}, /*  1:                     LP shift  350 */
/* State 350 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  { 158,   1, 261}, /*  3:                idxitem shift  261 */
  { 159,   0, 351}, /*  4:                idxlist shift  351 */
  {  71,   0,  21}, /*  5:                JOIN_KW shift  21 */
  { 173,   5, 260}, /*  6:                     nm shift  260 */
/* State 351 */
  { 100,   0, 352}, /*  1:                     RP shift  352 */
  {  21,   0, 258}, /*  2:                  COMMA shift  258 */
/* State 352 */
  { 176,   0, 353}, /*  1:                 onconf shift  353 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 354 */
  {  76,   0, 355}, /*  1:                     LP shift  355 */
/* State 355 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  { 158,   1, 261}, /*  3:                idxitem shift  261 */
  { 159,   0, 356}, /*  4:                idxlist shift  356 */
  {  71,   0,  21}, /*  5:                JOIN_KW shift  21 */
  { 173,   5, 260}, /*  6:                     nm shift  260 */
/* State 356 */
  { 100,   0, 357}, /*  1:                     RP shift  357 */
  {  21,   0, 258}, /*  2:                  COMMA shift  258 */
/* State 357 */
  { 176,   0, 358}, /*  1:                 onconf shift  358 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 359 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 360}, /* 15:                   expr shift  360 */
/* State 360 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  {  88,   0, 106}, /*  2:                     OR shift  106 */
  { 176,   5, 361}, /*  3:                 onconf shift  361 */
  {  90,   0, 135}, /*  4:                   PLUS shift  135 */
  {  60,   0, 157}, /*  5:                     IN shift  157 */
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
  {  81,  27, 116}, /* 22:                     NE shift  116 */
  {  80,  18, 137}, /* 23:                  MINUS shift  137 */
  { 168,  22, 128}, /* 24:                 likeop shift  128 */
  {  82,  28, 130}, /* 25:                    NOT shift  130 */
  {  83,  29, 152}, /* 26:                NOTNULL shift  152 */
  {  52,   0, 134}, /* 27:                   GLOB shift  134 */
  {  24,   0, 145}, /* 28:                 CONCAT shift  145 */
  {  54,   0, 110}, /* 29:                     GT shift  110 */
/* State 362 */
  {  72,   0, 363}, /*  1:                    KEY shift  363 */
/* State 363 */
  {  76,   0, 364}, /*  1:                     LP shift  364 */
/* State 364 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  { 158,   1, 261}, /*  3:                idxitem shift  261 */
  { 159,   0, 365}, /*  4:                idxlist shift  365 */
  {  71,   0,  21}, /*  5:                JOIN_KW shift  21 */
  { 173,   5, 260}, /*  6:                     nm shift  260 */
/* State 365 */
  { 100,   0, 366}, /*  1:                     RP shift  366 */
  {  21,   0, 258}, /*  2:                  COMMA shift  258 */
/* State 366 */
  {  94,   0, 293}, /*  1:             REFERENCES shift  293 */
  { 185,   0, 367}, /*  2:             references shift  367 */
/* State 367 */
  { 144,   0, 369}, /*  1:    defer_subclause_opt shift  369 */
  {  30,   0, 313}, /*  2:             DEFERRABLE shift  313 */
  {  82,   2, 368}, /*  3:                    NOT shift  368 */
  { 143,   0, 370}, /*  4:        defer_subclause shift  370 */
/* State 368 */
  {  30,   0,  48}, /*  1:             DEFERRABLE shift  48 */
/* State 374 */
  { 189,   2, 375}, /*  1:                 select shift  375 */
  { 177,   3,  68}, /*  2:              oneselect shift  68 */
  { 102,   0,  72}, /*  3:                 SELECT shift  72 */
/* State 375 */
  { 117,   0, 160}, /*  1:                  UNION shift  160 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 172,   1,  70}, /*  3:         multiselect_op shift  70 */
  { 103,   5, 544}, /*  4:                   SEMI reduce 19 */
  {  43,   0, 163}, /*  5:                 EXCEPT shift  163 */
/* State 376 */
  { 198,   6, 377}, /*  1:                   temp shift  377 */
  {  61,   0, 755}, /*  2:                  INDEX reduce 230 */
  { 206,   0, 385}, /*  3:             uniqueflag shift  385 */
  { 111,   0, 384}, /*  4:                   TEMP shift  384 */
  { 118,   0, 394}, /*  5:                 UNIQUE shift  394 */
  { 114,   0, 395}, /*  6:                TRIGGER shift  395 */
/* State 377 */
  { 110,   0, 378}, /*  1:                  TABLE shift  378 */
  { 123,   0, 380}, /*  2:                   VIEW shift  380 */
/* State 378 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 379}, /*  2:                     nm shift  379 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 380 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 381}, /*  2:                     nm shift  381 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 381 */
  {   6,   0, 382}, /*  1:                     AS shift  382 */
/* State 382 */
  { 189,   2, 383}, /*  1:                 select shift  383 */
  { 177,   3,  68}, /*  2:              oneselect shift  68 */
  { 102,   0,  72}, /*  3:                 SELECT shift  72 */
/* State 383 */
  { 117,   0, 160}, /*  1:                  UNION shift  160 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 172,   1,  70}, /*  3:         multiselect_op shift  70 */
  { 103,   5, 623}, /*  4:                   SEMI reduce 98 */
  {  43,   0, 163}, /*  5:                 EXCEPT shift  163 */
/* State 385 */
  {  61,   0, 386}, /*  1:                  INDEX shift  386 */
/* State 386 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 387}, /*  2:                     nm shift  387 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 387 */
  {  87,   0, 388}, /*  1:                     ON shift  388 */
/* State 388 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 389}, /*  2:                     nm shift  389 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 389 */
  {  76,   0, 390}, /*  1:                     LP shift  390 */
/* State 390 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  { 158,   1, 261}, /*  3:                idxitem shift  261 */
  { 159,   0, 391}, /*  4:                idxlist shift  391 */
  {  71,   0,  21}, /*  5:                JOIN_KW shift  21 */
  { 173,   5, 260}, /*  6:                     nm shift  260 */
/* State 391 */
  { 100,   0, 392}, /*  1:                     RP shift  392 */
  {  21,   0, 258}, /*  2:                  COMMA shift  258 */
/* State 392 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 103,   0, 613}, /*  2:                   SEMI reduce 88 */
  { 176,   0, 393}, /*  3:                 onconf shift  393 */
/* State 393 */
  { 103,   0, 753}, /*  1:                   SEMI reduce 228 */
/* State 394 */
  {  61,   0, 754}, /*  1:                  INDEX reduce 229 */
/* State 395 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 396}, /*  2:                     nm shift  396 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 396 */
  {  64,   2, 461}, /*  1:                INSTEAD shift  461 */
  {   8,   0, 459}, /*  2:                 BEFORE shift  459 */
  {   2,   0, 460}, /*  3:                  AFTER shift  460 */
  { 203,   0, 397}, /*  4:           trigger_time shift  397 */
/* State 397 */
  {  32,   0, 454}, /*  1:                 DELETE shift  454 */
  {  63,   0, 455}, /*  2:                 INSERT shift  455 */
  { 202,   0, 398}, /*  3:          trigger_event shift  398 */
  { 119,   2, 456}, /*  4:                 UPDATE shift  456 */
/* State 398 */
  {  87,   0, 399}, /*  1:                     ON shift  399 */
/* State 399 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 400}, /*  2:                     nm shift  400 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 400 */
  { 152,   0, 401}, /*  1:         foreach_clause shift  401 */
  {  47,   0, 450}, /*  2:                    FOR shift  450 */
/* State 401 */
  {   9,   0, 788}, /*  1:                  BEGIN reduce 263 */
  { 208,   3, 402}, /*  2:            when_clause shift  402 */
  { 124,   0, 448}, /*  3:                   WHEN shift  448 */
/* State 402 */
  {   9,   0, 403}, /*  1:                  BEGIN shift  403 */
/* State 403 */
  { 189,   2, 404}, /*  1:                 select shift  404 */
  {  63,   0, 425}, /*  2:                 INSERT shift  425 */
  { 200,   8, 407}, /*  3:            trigger_cmd shift  407 */
  { 201,   9, 405}, /*  4:       trigger_cmd_list shift  405 */
  {  40,   0, 791}, /*  5:                    END reduce 266 */
  {  32,   0, 444}, /*  6:                 DELETE shift  444 */
  { 177,   0,  68}, /*  7:              oneselect shift  68 */
  { 119,   0, 410}, /*  8:                 UPDATE shift  410 */
  { 102,   0,  72}, /*  9:                 SELECT shift  72 */
/* State 404 */
  { 117,   0, 160}, /*  1:                  UNION shift  160 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 172,   1,  70}, /*  3:         multiselect_op shift  70 */
  { 103,   5, 796}, /*  4:                   SEMI reduce 271 */
  {  43,   0, 163}, /*  5:                 EXCEPT shift  163 */
/* State 405 */
  {  40,   0, 406}, /*  1:                    END shift  406 */
/* State 406 */
  { 103,   0, 776}, /*  1:                   SEMI reduce 251 */
/* State 407 */
  { 103,   0, 408}, /*  1:                   SEMI shift  408 */
/* State 408 */
  { 189,   2, 404}, /*  1:                 select shift  404 */
  {  63,   0, 425}, /*  2:                 INSERT shift  425 */
  { 200,   8, 407}, /*  3:            trigger_cmd shift  407 */
  { 201,   9, 409}, /*  4:       trigger_cmd_list shift  409 */
  {  40,   0, 791}, /*  5:                    END reduce 266 */
  {  32,   0, 444}, /*  6:                 DELETE shift  444 */
  { 177,   0,  68}, /*  7:              oneselect shift  68 */
  { 119,   0, 410}, /*  8:                 UPDATE shift  410 */
  { 102,   0,  72}, /*  9:                 SELECT shift  72 */
/* State 409 */
  {  40,   0, 790}, /*  1:                    END reduce 265 */
/* State 410 */
  { 178,   2, 413}, /*  1:                 orconf shift  413 */
  {  88,   0, 411}, /*  2:                     OR shift  411 */
/* State 411 */
  { 186,   5, 412}, /*  1:            resolvetype shift  412 */
  {   1,   0,  13}, /*  2:                  ABORT shift  13 */
  {  98,   0,  12}, /*  3:               ROLLBACK shift  12 */
  {  57,   6,  15}, /*  4:                 IGNORE shift  15 */
  {  96,   0,  16}, /*  5:                REPLACE shift  16 */
  {  45,   0,  14}, /*  6:                   FAIL shift  14 */
/* State 413 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 414}, /*  2:                     nm shift  414 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 414 */
  { 104,   0, 415}, /*  1:                    SET shift  415 */
/* State 415 */
  {  71,   3,  21}, /*  1:                JOIN_KW shift  21 */
  { 191,   1, 416}, /*  2:                setlist shift  416 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 173,   0, 422}, /*  4:                     nm shift  422 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 416 */
  { 125,   3, 230}, /*  1:                  WHERE shift  230 */
  { 209,   1, 421}, /*  2:              where_opt shift  421 */
  {  21,   0, 417}, /*  3:                  COMMA shift  417 */
  { 103,   0, 679}, /*  4:                   SEMI reduce 154 */
/* State 417 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 418}, /*  2:                     nm shift  418 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 418 */
  {  42,   0, 419}, /*  1:                     EQ shift  419 */
/* State 419 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 420}, /* 15:                   expr shift  420 */
/* State 420 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  60,   0, 157}, /*  5:                     IN shift  157 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  { 168,   5, 128}, /*  7:                 likeop shift  128 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  {  68,   0, 148}, /*  9:                     IS shift  148 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   9, 143}, /* 15:                    REM shift  143 */
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
/* State 421 */
  { 103,   0, 792}, /*  1:                   SEMI reduce 267 */
/* State 422 */
  {  42,   0, 423}, /*  1:                     EQ shift  423 */
/* State 423 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 424}, /* 15:                   expr shift  424 */
/* State 424 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  60,   0, 157}, /*  5:                     IN shift  157 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  { 168,   5, 128}, /*  7:                 likeop shift  128 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  {  68,   0, 148}, /*  9:                     IS shift  148 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   9, 143}, /* 15:                    REM shift  143 */
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
  {  88,   3, 411}, /*  1:                     OR shift  411 */
  { 178,   1, 426}, /*  2:                 orconf shift  426 */
  {  67,   0, 615}, /*  3:                   INTO reduce 90 */
/* State 426 */
  {  67,   0, 427}, /*  1:                   INTO shift  427 */
/* State 427 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 428}, /*  2:                     nm shift  428 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 428 */
  {  76,   0, 429}, /*  1:                     LP shift  429 */
  { 163,   0, 435}, /*  2:         inscollist_opt shift  435 */
/* State 429 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  {  71,   1,  21}, /*  2:                JOIN_KW shift  21 */
  { 162,   0, 430}, /*  3:             inscollist shift  430 */
  { 173,   0, 434}, /*  4:                     nm shift  434 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 430 */
  { 100,   0, 431}, /*  1:                     RP shift  431 */
  {  21,   0, 432}, /*  2:                  COMMA shift  432 */
/* State 432 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 433}, /*  2:                     nm shift  433 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 435 */
  { 177,   0,  68}, /*  1:              oneselect shift  68 */
  { 189,   1, 436}, /*  2:                 select shift  436 */
  { 122,   4, 437}, /*  3:                 VALUES shift  437 */
  { 102,   0,  72}, /*  4:                 SELECT shift  72 */
/* State 436 */
  { 117,   0, 160}, /*  1:                  UNION shift  160 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 172,   1,  70}, /*  3:         multiselect_op shift  70 */
  { 103,   5, 794}, /*  4:                   SEMI reduce 269 */
  {  43,   0, 163}, /*  5:                 EXCEPT shift  163 */
/* State 437 */
  {  76,   0, 438}, /*  1:                     LP shift  438 */
/* State 438 */
  {  80,   4, 170}, /*  1:                  MINUS shift  170 */
  {  65,   0, 103}, /*  2:                INTEGER shift  103 */
  {  82,   0, 166}, /*  3:                    NOT shift  166 */
  {  16,   0, 174}, /*  4:                   CASE shift  174 */
  {  84,   0,  99}, /*  5:                   NULL shift  99 */
  { 165,   7, 439}, /*  6:               itemlist shift  439 */
  { 149,   0, 443}, /*  7:                   expr shift  443 */
  {  71,   0,  66}, /*  8:                JOIN_KW shift  66 */
  {  56,   0,  63}, /*  9:                     ID shift  63 */
  {  12,   0, 168}, /* 10:                 BITNOT shift  168 */
  {  90,   0, 172}, /* 11:                   PLUS shift  172 */
  { 109,  16,  65}, /* 12:                 STRING shift  65 */
  {  76,  10,  67}, /* 13:                     LP shift  67 */
  { 173,  12, 100}, /* 14:                     nm shift  100 */
  {  46,   0, 104}, /* 15:                  FLOAT shift  104 */
  {  93,   0, 184}, /* 16:                  RAISE shift  184 */
/* State 439 */
  { 100,   0, 442}, /*  1:                     RP shift  442 */
  {  21,   0, 440}, /*  2:                  COMMA shift  440 */
/* State 440 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 441}, /* 15:                   expr shift  441 */
/* State 441 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  60,   0, 157}, /*  5:                     IN shift  157 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  { 168,   5, 128}, /*  7:                 likeop shift  128 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  {  68,   0, 148}, /*  9:                     IS shift  148 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   9, 143}, /* 15:                    REM shift  143 */
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
/* State 442 */
  { 103,   0, 793}, /*  1:                   SEMI reduce 268 */
/* State 443 */
  {  81,   4, 116}, /*  1:                     NE shift  116 */
  {  82,   0, 130}, /*  2:                    NOT shift  130 */
  {  83,   0, 152}, /*  3:                NOTNULL shift  152 */
  {  54,   0, 110}, /*  4:                     GT shift  110 */
  {  60,   0, 157}, /*  5:                     IN shift  157 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  { 168,   5, 128}, /*  7:                 likeop shift  128 */
  {  88,   0, 106}, /*  8:                     OR shift  106 */
  {  68,   0, 148}, /*  9:                     IS shift  148 */
  {  90,   0, 135}, /* 10:                   PLUS shift  135 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  11,   0, 120}, /* 12:                 BITAND shift  120 */
  {  42,   0, 118}, /* 13:                     EQ shift  118 */
  {  13,   0, 122}, /* 14:                  BITOR shift  122 */
  {  95,   9, 143}, /* 15:                    REM shift  143 */
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
/* State 444 */
  {  49,   0, 445}, /*  1:                   FROM shift  445 */
/* State 445 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 446}, /*  2:                     nm shift  446 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 446 */
  { 125,   0, 230}, /*  1:                  WHERE shift  230 */
  { 103,   0, 679}, /*  2:                   SEMI reduce 154 */
  { 209,   1, 447}, /*  3:              where_opt shift  447 */
/* State 447 */
  { 103,   0, 795}, /*  1:                   SEMI reduce 270 */
/* State 448 */
  {  90,   0, 172}, /*  1:                   PLUS shift  172 */
  {  76,   3,  67}, /*  2:                     LP shift  67 */
  {  46,   7, 104}, /*  3:                  FLOAT shift  104 */
  {  93,   0, 184}, /*  4:                  RAISE shift  184 */
  { 109,   0,  65}, /*  5:                 STRING shift  65 */
  {  80,  11, 170}, /*  6:                  MINUS shift  170 */
  {  16,   0, 174}, /*  7:                   CASE shift  174 */
  {  82,   0, 166}, /*  8:                    NOT shift  166 */
  { 173,   0, 100}, /*  9:                     nm shift  100 */
  {  84,   0,  99}, /* 10:                   NULL shift  99 */
  {  65,   0, 103}, /* 11:                INTEGER shift  103 */
  {  71,  14,  66}, /* 12:                JOIN_KW shift  66 */
  {  12,   0, 168}, /* 13:                 BITNOT shift  168 */
  {  56,   0,  63}, /* 14:                     ID shift  63 */
  { 149,   0, 449}, /* 15:                   expr shift  449 */
/* State 449 */
  { 168,   0, 128}, /*  1:                 likeop shift  128 */
  {  60,   0, 157}, /*  2:                     IN shift  157 */
  {  11,   0, 120}, /*  3:                 BITAND shift  120 */
  {  13,   0, 122}, /*  4:                  BITOR shift  122 */
  {  88,   2, 106}, /*  5:                     OR shift  106 */
  {   5,   0,  98}, /*  6:                    AND shift  98 */
  {  90,   0, 135}, /*  7:                   PLUS shift  135 */
  {  73,   0, 112}, /*  8:                     LE shift  112 */
  {  77,   0, 124}, /*  9:                 LSHIFT shift  124 */
  {   9,   0, 789}, /* 10:                  BEGIN reduce 264 */
  {  10,   0, 153}, /* 11:                BETWEEN shift  153 */
  {  95,   3, 143}, /* 12:                    REM shift  143 */
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
/* State 450 */
  {  38,   0, 451}, /*  1:                   EACH shift  451 */
/* State 451 */
  { 108,   0, 453}, /*  1:              STATEMENT shift  453 */
  {  99,   0, 452}, /*  2:                    ROW shift  452 */
/* State 454 */
  {  87,   0, 781}, /*  1:                     ON reduce 256 */
/* State 455 */
  {  87,   0, 782}, /*  1:                     ON reduce 257 */
/* State 456 */
  {  85,   0, 457}, /*  1:                     OF shift  457 */
  {  87,   1, 783}, /*  2:                     ON reduce 258 */
/* State 457 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  {  71,   1,  21}, /*  2:                JOIN_KW shift  21 */
  { 162,   0, 458}, /*  3:             inscollist shift  458 */
  { 173,   0, 434}, /*  4:                     nm shift  434 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 458 */
  {  21,   0, 432}, /*  1:                  COMMA shift  432 */
  {  87,   1, 784}, /*  2:                     ON reduce 259 */
/* State 461 */
  {  85,   0, 462}, /*  1:                     OF shift  462 */
/* State 463 */
  { 110,   0, 464}, /*  1:                  TABLE shift  464 */
  {  61,   0, 468}, /*  2:                  INDEX shift  468 */
  { 114,   1, 470}, /*  3:                TRIGGER shift  470 */
  { 123,   0, 466}, /*  4:                   VIEW shift  466 */
/* State 464 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 465}, /*  2:                     nm shift  465 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 465 */
  { 103,   0, 622}, /*  1:                   SEMI reduce 97 */
/* State 466 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 467}, /*  2:                     nm shift  467 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 467 */
  { 103,   0, 624}, /*  1:                   SEMI reduce 99 */
/* State 468 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 469}, /*  2:                     nm shift  469 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 469 */
  { 103,   0, 759}, /*  1:                   SEMI reduce 234 */
/* State 470 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 471}, /*  2:                     nm shift  471 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 471 */
  { 103,   0, 801}, /*  1:                   SEMI reduce 276 */
/* State 472 */
  { 117,   0, 160}, /*  1:                  UNION shift  160 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 172,   1,  70}, /*  3:         multiselect_op shift  70 */
  { 103,   5, 625}, /*  4:                   SEMI reduce 100 */
  {  43,   0, 163}, /*  5:                 EXCEPT shift  163 */
/* State 473 */
  {  49,   0, 474}, /*  1:                   FROM shift  474 */
/* State 474 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 475}, /*  2:                     nm shift  475 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 475 */
  { 125,   0, 230}, /*  1:                  WHERE shift  230 */
  { 103,   0, 679}, /*  2:                   SEMI reduce 154 */
  { 209,   1, 476}, /*  3:              where_opt shift  476 */
/* State 476 */
  { 103,   0, 678}, /*  1:                   SEMI reduce 153 */
/* State 477 */
  { 178,   2, 478}, /*  1:                 orconf shift  478 */
  {  88,   0, 411}, /*  2:                     OR shift  411 */
/* State 478 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 479}, /*  2:                     nm shift  479 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 479 */
  { 104,   0, 480}, /*  1:                    SET shift  480 */
/* State 480 */
  {  71,   3,  21}, /*  1:                JOIN_KW shift  21 */
  { 191,   1, 481}, /*  2:                setlist shift  481 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 173,   0, 422}, /*  4:                     nm shift  422 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 481 */
  { 125,   3, 230}, /*  1:                  WHERE shift  230 */
  { 209,   1, 482}, /*  2:              where_opt shift  482 */
  {  21,   0, 417}, /*  3:                  COMMA shift  417 */
  { 103,   0, 679}, /*  4:                   SEMI reduce 154 */
/* State 482 */
  { 103,   0, 681}, /*  1:                   SEMI reduce 156 */
/* State 483 */
  {  67,   0, 484}, /*  1:                   INTO shift  484 */
/* State 484 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 485}, /*  2:                     nm shift  485 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 485 */
  {  76,   0, 429}, /*  1:                     LP shift  429 */
  { 163,   0, 486}, /*  2:         inscollist_opt shift  486 */
/* State 486 */
  { 177,   0,  68}, /*  1:              oneselect shift  68 */
  { 189,   1, 487}, /*  2:                 select shift  487 */
  { 122,   4, 488}, /*  3:                 VALUES shift  488 */
  { 102,   0,  72}, /*  4:                 SELECT shift  72 */
/* State 487 */
  { 117,   0, 160}, /*  1:                  UNION shift  160 */
  {  66,   0, 162}, /*  2:              INTERSECT shift  162 */
  { 172,   1,  70}, /*  3:         multiselect_op shift  70 */
  { 103,   5, 685}, /*  4:                   SEMI reduce 160 */
  {  43,   0, 163}, /*  5:                 EXCEPT shift  163 */
/* State 488 */
  {  76,   0, 489}, /*  1:                     LP shift  489 */
/* State 489 */
  {  80,   4, 170}, /*  1:                  MINUS shift  170 */
  {  65,   0, 103}, /*  2:                INTEGER shift  103 */
  {  82,   0, 166}, /*  3:                    NOT shift  166 */
  {  16,   0, 174}, /*  4:                   CASE shift  174 */
  {  84,   0,  99}, /*  5:                   NULL shift  99 */
  { 165,   7, 490}, /*  6:               itemlist shift  490 */
  { 149,   0, 443}, /*  7:                   expr shift  443 */
  {  71,   0,  66}, /*  8:                JOIN_KW shift  66 */
  {  56,   0,  63}, /*  9:                     ID shift  63 */
  {  12,   0, 168}, /* 10:                 BITNOT shift  168 */
  {  90,   0, 172}, /* 11:                   PLUS shift  172 */
  { 109,  16,  65}, /* 12:                 STRING shift  65 */
  {  76,  10,  67}, /* 13:                     LP shift  67 */
  { 173,  12, 100}, /* 14:                     nm shift  100 */
  {  46,   0, 104}, /* 15:                  FLOAT shift  104 */
  {  93,   0, 184}, /* 16:                  RAISE shift  184 */
/* State 490 */
  { 100,   0, 491}, /*  1:                     RP shift  491 */
  {  21,   0, 440}, /*  2:                  COMMA shift  440 */
/* State 491 */
  { 103,   0, 684}, /*  1:                   SEMI reduce 159 */
/* State 492 */
  {  88,   3, 411}, /*  1:                     OR shift  411 */
  { 178,   1, 493}, /*  2:                 orconf shift  493 */
  {  67,   0, 615}, /*  3:                   INTO reduce 90 */
/* State 493 */
  {  67,   0, 686}, /*  1:                   INTO reduce 161 */
/* State 494 */
  {  67,   0, 687}, /*  1:                   INTO reduce 162 */
/* State 495 */
  { 178,   2, 496}, /*  1:                 orconf shift  496 */
  {  88,   0, 411}, /*  2:                     OR shift  411 */
/* State 496 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 497}, /*  2:                     nm shift  497 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 497 */
  {  49,   0, 498}, /*  1:                   FROM shift  498 */
/* State 498 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 499}, /*  2:                     nm shift  499 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 499 */
  { 120,   0, 500}, /*  1:                  USING shift  500 */
  { 103,   0, 761}, /*  2:                   SEMI reduce 236 */
/* State 500 */
  {  33,   0, 501}, /*  1:             DELIMITERS shift  501 */
/* State 501 */
  { 109,   0, 502}, /*  1:                 STRING shift  502 */
/* State 502 */
  { 103,   0, 760}, /*  1:                   SEMI reduce 235 */
/* State 503 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  {  71,   1,  21}, /*  2:                JOIN_KW shift  21 */
  { 103,   0, 762}, /*  3:                   SEMI reduce 237 */
  { 173,   3, 504}, /*  4:                     nm shift  504 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 504 */
  { 103,   0, 763}, /*  1:                   SEMI reduce 238 */
/* State 505 */
  { 109,   0, 247}, /*  1:                 STRING shift  247 */
  { 157,   1, 506}, /*  2:                    ids shift  506 */
  {  56,   0, 246}, /*  3:                     ID shift  246 */
/* State 506 */
  {  42,   0, 507}, /*  1:                     EQ shift  507 */
  { 103,   3, 769}, /*  2:                   SEMI reduce 244 */
  {  76,   0, 519}, /*  3:                     LP shift  519 */
/* State 507 */
  { 180,   3, 510}, /*  1:               plus_num shift  510 */
  { 181,   5, 512}, /*  2:               plus_opt shift  512 */
  {  90,   6, 518}, /*  3:                   PLUS shift  518 */
  { 173,   0, 508}, /*  4:                     nm shift  508 */
  { 171,   9, 511}, /*  5:              minus_num shift  511 */
  {  80,   0, 516}, /*  6:                  MINUS shift  516 */
  {  56,   0,  19}, /*  7:                     ID shift  19 */
  {  87,   0, 509}, /*  8:                     ON shift  509 */
  {  71,   0,  21}, /*  9:                JOIN_KW shift  21 */
  { 109,   0,  20}, /* 10:                 STRING shift  20 */
/* State 508 */
  { 103,   0, 764}, /*  1:                   SEMI reduce 239 */
/* State 509 */
  { 103,   0, 765}, /*  1:                   SEMI reduce 240 */
/* State 510 */
  { 103,   0, 766}, /*  1:                   SEMI reduce 241 */
/* State 511 */
  { 103,   0, 767}, /*  1:                   SEMI reduce 242 */
/* State 512 */
  { 174,   0, 513}, /*  1:                 number shift  513 */
  {  46,   0, 515}, /*  2:                  FLOAT shift  515 */
  {  65,   0, 514}, /*  3:                INTEGER shift  514 */
/* State 513 */
  { 103,   0, 770}, /*  1:                   SEMI reduce 245 */
/* State 514 */
  { 103,   0, 772}, /*  1:                   SEMI reduce 247 */
/* State 515 */
  { 103,   0, 773}, /*  1:                   SEMI reduce 248 */
/* State 516 */
  { 174,   0, 517}, /*  1:                 number shift  517 */
  {  46,   0, 515}, /*  2:                  FLOAT shift  515 */
  {  65,   0, 514}, /*  3:                INTEGER shift  514 */
/* State 517 */
  { 103,   0, 771}, /*  1:                   SEMI reduce 246 */
/* State 519 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 520}, /*  2:                     nm shift  520 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 520 */
  { 100,   0, 521}, /*  1:                     RP shift  521 */
/* State 521 */
  { 103,   0, 768}, /*  1:                   SEMI reduce 243 */
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
  { &yyActionTable[0],   6, 531 },
  { &yyActionTable[6],   5, 531 },
  { &yyActionTable[11],   0, 527 },
  { &yyActionTable[11],  19, 802 },
  { &yyActionTable[30],   1, 802 },
  { &yyActionTable[31],   0, 528 },
  { &yyActionTable[31],   2, 533 },
  { &yyActionTable[33],   3, 802 },
  { &yyActionTable[36],   1, 802 },
  { &yyActionTable[37],   1, 802 },
  { &yyActionTable[38],   6, 802 },
  { &yyActionTable[44],   0, 614 },
  { &yyActionTable[44],   0, 617 },
  { &yyActionTable[44],   0, 618 },
  { &yyActionTable[44],   0, 619 },
  { &yyActionTable[44],   0, 620 },
  { &yyActionTable[44],   0, 621 },
  { &yyActionTable[44],   4, 534 },
  { &yyActionTable[48],   0, 535 },
  { &yyActionTable[48],   0, 552 },
  { &yyActionTable[48],   0, 553 },
  { &yyActionTable[48],   0, 554 },
  { &yyActionTable[48],   3, 802 },
  { &yyActionTable[51],   1, 802 },
  { &yyActionTable[52],   3, 802 },
  { &yyActionTable[55],   1, 802 },
  { &yyActionTable[56],   3, 802 },
  { &yyActionTable[59],   1, 802 },
  { &yyActionTable[60],   3, 802 },
  { &yyActionTable[63],   1, 802 },
  { &yyActionTable[64],   7, 802 },
  { &yyActionTable[71],   3, 802 },
  { &yyActionTable[74],   1, 802 },
  { &yyActionTable[75],   1, 802 },
  { &yyActionTable[76],  13, 802 },
  { &yyActionTable[89],   0, 545 },
  { &yyActionTable[89],   5, 555 },
  { &yyActionTable[94],   1, 565 },
  { &yyActionTable[95],  14, 547 },
  { &yyActionTable[109],   0, 564 },
  { &yyActionTable[109],   4, 802 },
  { &yyActionTable[113],  11, 802 },
  { &yyActionTable[124],   0, 566 },
  { &yyActionTable[124],   2, 613 },
  { &yyActionTable[126],   0, 577 },
  { &yyActionTable[126],   2, 802 },
  { &yyActionTable[128],   2, 613 },
  { &yyActionTable[130],   0, 578 },
  { &yyActionTable[130],   2, 598 },
  { &yyActionTable[132],   0, 596 },
  { &yyActionTable[132],   2, 802 },
  { &yyActionTable[134],   0, 599 },
  { &yyActionTable[134],   0, 600 },
  { &yyActionTable[134],   1, 802 },
  { &yyActionTable[135],   3, 666 },
  { &yyActionTable[138],   2, 613 },
  { &yyActionTable[140],   0, 579 },
  { &yyActionTable[140],   0, 664 },
  { &yyActionTable[140],   0, 665 },
  { &yyActionTable[140],   2, 613 },
  { &yyActionTable[142],   0, 580 },
  { &yyActionTable[142],   1, 802 },
  { &yyActionTable[143],  15, 802 },
  { &yyActionTable[158],   2, 696 },
  { &yyActionTable[160],  18, 752 },
  { &yyActionTable[178],   1, 701 },
  { &yyActionTable[179],   1, 697 },
  { &yyActionTable[180],  18, 802 },
  { &yyActionTable[198],   0, 626 },
  { &yyActionTable[198],   5, 802 },
  { &yyActionTable[203],   2, 802 },
  { &yyActionTable[205],   0, 627 },
  { &yyActionTable[205],   3, 635 },
  { &yyActionTable[208],   2, 637 },
  { &yyActionTable[210],   3, 644 },
  { &yyActionTable[213],   2, 679 },
  { &yyActionTable[215],   2, 669 },
  { &yyActionTable[217],   2, 671 },
  { &yyActionTable[219],   2, 659 },
  { &yyActionTable[221],   2, 673 },
  { &yyActionTable[223],   0, 632 },
  { &yyActionTable[223],   1, 802 },
  { &yyActionTable[224],   3, 674 },
  { &yyActionTable[227],   1, 802 },
  { &yyActionTable[228],   0, 675 },
  { &yyActionTable[228],   1, 802 },
  { &yyActionTable[229],   1, 802 },
  { &yyActionTable[230],   1, 802 },
  { &yyActionTable[231],  17, 802 },
  { &yyActionTable[248],   1, 660 },
  { &yyActionTable[249],  16, 802 },
  { &yyActionTable[265],   2, 667 },
  { &yyActionTable[267],   3, 666 },
  { &yyActionTable[270],   0, 661 },
  { &yyActionTable[270],   2, 802 },
  { &yyActionTable[272],   0, 549 },
  { &yyActionTable[272],   0, 668 },
  { &yyActionTable[272],  27, 663 },
  { &yyActionTable[299],  15, 802 },
  { &yyActionTable[314],   0, 695 },
  { &yyActionTable[314],   1, 802 },
  { &yyActionTable[315],   4, 802 },
  { &yyActionTable[319],   0, 698 },
  { &yyActionTable[319],   0, 699 },
  { &yyActionTable[319],   0, 700 },
  { &yyActionTable[319],  25, 704 },
  { &yyActionTable[344],  15, 802 },
  { &yyActionTable[359],  26, 705 },
  { &yyActionTable[385],  15, 802 },
  { &yyActionTable[400],  11, 706 },
  { &yyActionTable[411],  15, 802 },
  { &yyActionTable[426],  11, 707 },
  { &yyActionTable[437],  15, 802 },
  { &yyActionTable[452],  11, 708 },
  { &yyActionTable[463],  15, 802 },
  { &yyActionTable[478],  11, 709 },
  { &yyActionTable[489],  15, 802 },
  { &yyActionTable[504],  15, 710 },
  { &yyActionTable[519],  15, 802 },
  { &yyActionTable[534],  15, 711 },
  { &yyActionTable[549],  15, 802 },
  { &yyActionTable[564],   7, 712 },
  { &yyActionTable[571],  15, 802 },
  { &yyActionTable[586],   7, 713 },
  { &yyActionTable[593],  15, 802 },
  { &yyActionTable[608],   7, 714 },
  { &yyActionTable[615],  15, 802 },
  { &yyActionTable[630],   7, 715 },
  { &yyActionTable[637],  15, 802 },
  { &yyActionTable[652],  15, 716 },
  { &yyActionTable[667],   6, 802 },
  { &yyActionTable[673],  15, 802 },
  { &yyActionTable[688],  15, 717 },
  { &yyActionTable[703],   0, 718 },
  { &yyActionTable[703],   0, 719 },
  { &yyActionTable[703],  15, 802 },
  { &yyActionTable[718],   5, 720 },
  { &yyActionTable[723],  15, 802 },
  { &yyActionTable[738],   5, 721 },
  { &yyActionTable[743],  15, 802 },
  { &yyActionTable[758],   2, 722 },
  { &yyActionTable[760],  15, 802 },
  { &yyActionTable[775],   2, 723 },
  { &yyActionTable[777],  15, 802 },
  { &yyActionTable[792],   2, 724 },
  { &yyActionTable[794],  15, 802 },
  { &yyActionTable[809],   1, 725 },
  { &yyActionTable[810],   0, 726 },
  { &yyActionTable[810],   2, 802 },
  { &yyActionTable[812],   0, 727 },
  { &yyActionTable[812],   1, 802 },
  { &yyActionTable[813],   0, 730 },
  { &yyActionTable[813],   0, 728 },
  { &yyActionTable[813],  15, 802 },
  { &yyActionTable[828],  27, 802 },
  { &yyActionTable[855],  15, 802 },
  { &yyActionTable[870],  15, 736 },
  { &yyActionTable[885],   1, 802 },
  { &yyActionTable[886],  20, 752 },
  { &yyActionTable[906],   5, 802 },
  { &yyActionTable[911],   2, 802 },
  { &yyActionTable[913],   1, 802 },
  { &yyActionTable[914],   1, 802 },
  { &yyActionTable[915],   1, 802 },
  { &yyActionTable[916],   0, 739 },
  { &yyActionTable[916],  27, 751 },
  { &yyActionTable[943],  15, 802 },
  { &yyActionTable[958],  25, 731 },
  { &yyActionTable[983],  15, 802 },
  { &yyActionTable[998],   1, 732 },
  { &yyActionTable[999],  15, 802 },
  { &yyActionTable[1014],   1, 733 },
  { &yyActionTable[1015],  15, 802 },
  { &yyActionTable[1030],   1, 734 },
  { &yyActionTable[1031],  17, 802 },
  { &yyActionTable[1048],  28, 802 },
  { &yyActionTable[1076],   2, 802 },
  { &yyActionTable[1078],   4, 802 },
  { &yyActionTable[1082],   1, 802 },
  { &yyActionTable[1083],   0, 742 },
  { &yyActionTable[1083],  15, 802 },
  { &yyActionTable[1098],  28, 802 },
  { &yyActionTable[1126],  15, 802 },
  { &yyActionTable[1141],  27, 743 },
  { &yyActionTable[1168],   1, 802 },
  { &yyActionTable[1169],   4, 802 },
  { &yyActionTable[1173],   1, 802 },
  { &yyActionTable[1174],   0, 797 },
  { &yyActionTable[1174],   1, 802 },
  { &yyActionTable[1175],   4, 802 },
  { &yyActionTable[1179],   1, 802 },
  { &yyActionTable[1180],   0, 798 },
  { &yyActionTable[1180],   1, 802 },
  { &yyActionTable[1181],   4, 802 },
  { &yyActionTable[1185],   1, 802 },
  { &yyActionTable[1186],   0, 799 },
  { &yyActionTable[1186],   1, 802 },
  { &yyActionTable[1187],   4, 802 },
  { &yyActionTable[1191],   1, 802 },
  { &yyActionTable[1192],   0, 800 },
  { &yyActionTable[1192],  15, 802 },
  { &yyActionTable[1207],  28, 802 },
  { &yyActionTable[1235],  15, 802 },
  { &yyActionTable[1250],  28, 802 },
  { &yyActionTable[1278],  15, 802 },
  { &yyActionTable[1293],  27, 744 },
  { &yyActionTable[1320],   2, 802 },
  { &yyActionTable[1322],   0, 738 },
  { &yyActionTable[1322],  16, 752 },
  { &yyActionTable[1338],   0, 749 },
  { &yyActionTable[1338],   0, 750 },
  { &yyActionTable[1338],   0, 729 },
  { &yyActionTable[1338],  15, 802 },
  { &yyActionTable[1353],  27, 802 },
  { &yyActionTable[1380],  15, 802 },
  { &yyActionTable[1395],  25, 737 },
  { &yyActionTable[1420],   1, 802 },
  { &yyActionTable[1421],  20, 752 },
  { &yyActionTable[1441],   5, 802 },
  { &yyActionTable[1446],   0, 741 },
  { &yyActionTable[1446],   2, 802 },
  { &yyActionTable[1448],   0, 740 },
  { &yyActionTable[1448],   2, 667 },
  { &yyActionTable[1450],   3, 666 },
  { &yyActionTable[1453],   0, 662 },
  { &yyActionTable[1453],  15, 802 },
  { &yyActionTable[1468],  27, 672 },
  { &yyActionTable[1495],   1, 802 },
  { &yyActionTable[1496],  17, 752 },
  { &yyActionTable[1513],   1, 670 },
  { &yyActionTable[1514],  15, 802 },
  { &yyActionTable[1529],  27, 680 },
  { &yyActionTable[1556],   0, 636 },
  { &yyActionTable[1556],   2, 647 },
  { &yyActionTable[1558],   4, 645 },
  { &yyActionTable[1562],   0, 646 },
  { &yyActionTable[1562],   0, 650 },
  { &yyActionTable[1562],   0, 651 },
  { &yyActionTable[1562],   5, 802 },
  { &yyActionTable[1567],   0, 652 },
  { &yyActionTable[1567],   5, 802 },
  { &yyActionTable[1572],   0, 653 },
  { &yyActionTable[1572],   1, 802 },
  { &yyActionTable[1573],   0, 654 },
  { &yyActionTable[1573],   5, 802 },
  { &yyActionTable[1578],   5, 643 },
  { &yyActionTable[1583],   0, 550 },
  { &yyActionTable[1583],   0, 551 },
  { &yyActionTable[1583],   4, 802 },
  { &yyActionTable[1587],   0, 641 },
  { &yyActionTable[1587],   0, 642 },
  { &yyActionTable[1587],   2, 656 },
  { &yyActionTable[1589],   2, 658 },
  { &yyActionTable[1591],   0, 648 },
  { &yyActionTable[1591],   1, 802 },
  { &yyActionTable[1592],   6, 802 },
  { &yyActionTable[1598],   2, 802 },
  { &yyActionTable[1600],   0, 657 },
  { &yyActionTable[1600],   5, 802 },
  { &yyActionTable[1605],   0, 756 },
  { &yyActionTable[1605],   0, 758 },
  { &yyActionTable[1605],   0, 757 },
  { &yyActionTable[1605],  15, 802 },
  { &yyActionTable[1620],  27, 655 },
  { &yyActionTable[1647],   3, 802 },
  { &yyActionTable[1650],   5, 802 },
  { &yyActionTable[1655],   5, 643 },
  { &yyActionTable[1660],   2, 656 },
  { &yyActionTable[1662],   2, 658 },
  { &yyActionTable[1664],   0, 649 },
  { &yyActionTable[1664],  16, 802 },
  { &yyActionTable[1680],  32, 643 },
  { &yyActionTable[1712],   0, 638 },
  { &yyActionTable[1712],   0, 639 },
  { &yyActionTable[1712],   1, 802 },
  { &yyActionTable[1713],   5, 802 },
  { &yyActionTable[1718],   0, 640 },
  { &yyActionTable[1718],   0, 633 },
  { &yyActionTable[1718],   0, 634 },
  { &yyActionTable[1718],   0, 735 },
  { &yyActionTable[1718],  28, 802 },
  { &yyActionTable[1746],   0, 694 },
  { &yyActionTable[1746],   2, 802 },
  { &yyActionTable[1748],   0, 702 },
  { &yyActionTable[1748],   1, 802 },
  { &yyActionTable[1749],   0, 703 },
  { &yyActionTable[1749],  28, 802 },
  { &yyActionTable[1777],   2, 613 },
  { &yyActionTable[1779],   0, 581 },
  { &yyActionTable[1779],   0, 582 },
  { &yyActionTable[1779],   0, 583 },
  { &yyActionTable[1779],   2, 802 },
  { &yyActionTable[1781],   0, 584 },
  { &yyActionTable[1781],   4, 802 },
  { &yyActionTable[1785],   2, 587 },
  { &yyActionTable[1787],   6, 802 },
  { &yyActionTable[1793],   2, 802 },
  { &yyActionTable[1795],   1, 587 },
  { &yyActionTable[1796],   3, 585 },
  { &yyActionTable[1799],   0, 588 },
  { &yyActionTable[1799],   4, 802 },
  { &yyActionTable[1803],   0, 589 },
  { &yyActionTable[1803],   2, 802 },
  { &yyActionTable[1805],   4, 802 },
  { &yyActionTable[1809],   0, 590 },
  { &yyActionTable[1809],   2, 802 },
  { &yyActionTable[1811],   0, 592 },
  { &yyActionTable[1811],   0, 593 },
  { &yyActionTable[1811],   0, 594 },
  { &yyActionTable[1811],   0, 595 },
  { &yyActionTable[1811],   4, 802 },
  { &yyActionTable[1815],   0, 591 },
  { &yyActionTable[1815],   3, 586 },
  { &yyActionTable[1818],   2, 598 },
  { &yyActionTable[1820],   0, 597 },
  { &yyActionTable[1820],   0, 567 },
  { &yyActionTable[1820],   7, 802 },
  { &yyActionTable[1827],   0, 568 },
  { &yyActionTable[1827],   0, 569 },
  { &yyActionTable[1827],   0, 570 },
  { &yyActionTable[1827],   2, 802 },
  { &yyActionTable[1829],   0, 571 },
  { &yyActionTable[1829],   0, 574 },
  { &yyActionTable[1829],   2, 802 },
  { &yyActionTable[1831],   0, 572 },
  { &yyActionTable[1831],   0, 575 },
  { &yyActionTable[1831],   0, 573 },
  { &yyActionTable[1831],   0, 576 },
  { &yyActionTable[1831],   4, 556 },
  { &yyActionTable[1835],   4, 802 },
  { &yyActionTable[1839],   2, 802 },
  { &yyActionTable[1841],   0, 557 },
  { &yyActionTable[1841],   4, 802 },
  { &yyActionTable[1845],   1, 802 },
  { &yyActionTable[1846],   0, 558 },
  { &yyActionTable[1846],   0, 561 },
  { &yyActionTable[1846],   1, 802 },
  { &yyActionTable[1847],   0, 562 },
  { &yyActionTable[1847],   1, 802 },
  { &yyActionTable[1848],   0, 563 },
  { &yyActionTable[1848],   0, 560 },
  { &yyActionTable[1848],   0, 559 },
  { &yyActionTable[1848],   0, 548 },
  { &yyActionTable[1848],   8, 802 },
  { &yyActionTable[1856],   6, 802 },
  { &yyActionTable[1862],   0, 603 },
  { &yyActionTable[1862],   4, 802 },
  { &yyActionTable[1866],   0, 606 },
  { &yyActionTable[1866],   1, 802 },
  { &yyActionTable[1867],   1, 802 },
  { &yyActionTable[1868],   6, 802 },
  { &yyActionTable[1874],   2, 802 },
  { &yyActionTable[1876],   2, 613 },
  { &yyActionTable[1878],   0, 607 },
  { &yyActionTable[1878],   1, 802 },
  { &yyActionTable[1879],   6, 802 },
  { &yyActionTable[1885],   2, 802 },
  { &yyActionTable[1887],   2, 613 },
  { &yyActionTable[1889],   0, 608 },
  { &yyActionTable[1889],  15, 802 },
  { &yyActionTable[1904],  29, 613 },
  { &yyActionTable[1933],   0, 609 },
  { &yyActionTable[1933],   1, 802 },
  { &yyActionTable[1934],   1, 802 },
  { &yyActionTable[1935],   6, 802 },
  { &yyActionTable[1941],   2, 802 },
  { &yyActionTable[1943],   2, 802 },
  { &yyActionTable[1945],   4, 611 },
  { &yyActionTable[1949],   1, 802 },
  { &yyActionTable[1950],   0, 610 },
  { &yyActionTable[1950],   0, 612 },
  { &yyActionTable[1950],   0, 604 },
  { &yyActionTable[1950],   0, 605 },
  { &yyActionTable[1950],   0, 546 },
  { &yyActionTable[1950],   3, 802 },
  { &yyActionTable[1953],   5, 802 },
  { &yyActionTable[1958],   6, 542 },
  { &yyActionTable[1964],   2, 802 },
  { &yyActionTable[1966],   4, 802 },
  { &yyActionTable[1970],   0, 540 },
  { &yyActionTable[1970],   4, 802 },
  { &yyActionTable[1974],   1, 802 },
  { &yyActionTable[1975],   3, 802 },
  { &yyActionTable[1978],   5, 802 },
  { &yyActionTable[1983],   0, 541 },
  { &yyActionTable[1983],   1, 802 },
  { &yyActionTable[1984],   4, 802 },
  { &yyActionTable[1988],   1, 802 },
  { &yyActionTable[1989],   4, 802 },
  { &yyActionTable[1993],   1, 802 },
  { &yyActionTable[1994],   6, 802 },
  { &yyActionTable[2000],   2, 802 },
  { &yyActionTable[2002],   3, 802 },
  { &yyActionTable[2005],   1, 802 },
  { &yyActionTable[2006],   1, 802 },
  { &yyActionTable[2007],   4, 802 },
  { &yyActionTable[2011],   4, 780 },
  { &yyActionTable[2015],   4, 802 },
  { &yyActionTable[2019],   1, 802 },
  { &yyActionTable[2020],   4, 802 },
  { &yyActionTable[2024],   2, 785 },
  { &yyActionTable[2026],   3, 802 },
  { &yyActionTable[2029],   1, 802 },
  { &yyActionTable[2030],   9, 802 },
  { &yyActionTable[2039],   5, 802 },
  { &yyActionTable[2044],   1, 802 },
  { &yyActionTable[2045],   1, 802 },
  { &yyActionTable[2046],   1, 802 },
  { &yyActionTable[2047],   9, 802 },
  { &yyActionTable[2056],   1, 802 },
  { &yyActionTable[2057],   2, 615 },
  { &yyActionTable[2059],   6, 802 },
  { &yyActionTable[2065],   0, 616 },
  { &yyActionTable[2065],   4, 802 },
  { &yyActionTable[2069],   1, 802 },
  { &yyActionTable[2070],   5, 802 },
  { &yyActionTable[2075],   4, 802 },
  { &yyActionTable[2079],   4, 802 },
  { &yyActionTable[2083],   1, 802 },
  { &yyActionTable[2084],  15, 802 },
  { &yyActionTable[2099],  27, 682 },
  { &yyActionTable[2126],   1, 802 },
  { &yyActionTable[2127],   1, 802 },
  { &yyActionTable[2128],  15, 802 },
  { &yyActionTable[2143],  27, 683 },
  { &yyActionTable[2170],   3, 802 },
  { &yyActionTable[2173],   1, 802 },
  { &yyActionTable[2174],   4, 802 },
  { &yyActionTable[2178],   2, 690 },
  { &yyActionTable[2180],   5, 802 },
  { &yyActionTable[2185],   2, 802 },
  { &yyActionTable[2187],   0, 691 },
  { &yyActionTable[2187],   4, 802 },
  { &yyActionTable[2191],   0, 692 },
  { &yyActionTable[2191],   0, 693 },
  { &yyActionTable[2191],   4, 802 },
  { &yyActionTable[2195],   5, 802 },
  { &yyActionTable[2200],   1, 802 },
  { &yyActionTable[2201],  16, 802 },
  { &yyActionTable[2217],   2, 802 },
  { &yyActionTable[2219],  15, 802 },
  { &yyActionTable[2234],  27, 688 },
  { &yyActionTable[2261],   1, 802 },
  { &yyActionTable[2262],  27, 689 },
  { &yyActionTable[2289],   1, 802 },
  { &yyActionTable[2290],   4, 802 },
  { &yyActionTable[2294],   3, 802 },
  { &yyActionTable[2297],   1, 802 },
  { &yyActionTable[2298],  15, 802 },
  { &yyActionTable[2313],  28, 802 },
  { &yyActionTable[2341],   1, 802 },
  { &yyActionTable[2342],   2, 802 },
  { &yyActionTable[2344],   0, 786 },
  { &yyActionTable[2344],   0, 787 },
  { &yyActionTable[2344],   1, 802 },
  { &yyActionTable[2345],   1, 802 },
  { &yyActionTable[2346],   2, 802 },
  { &yyActionTable[2348],   5, 802 },
  { &yyActionTable[2353],   2, 802 },
  { &yyActionTable[2355],   0, 777 },
  { &yyActionTable[2355],   0, 778 },
  { &yyActionTable[2355],   1, 802 },
  { &yyActionTable[2356],   0, 779 },
  { &yyActionTable[2356],   4, 802 },
  { &yyActionTable[2360],   4, 802 },
  { &yyActionTable[2364],   1, 802 },
  { &yyActionTable[2365],   4, 802 },
  { &yyActionTable[2369],   1, 802 },
  { &yyActionTable[2370],   4, 802 },
  { &yyActionTable[2374],   1, 802 },
  { &yyActionTable[2375],   4, 802 },
  { &yyActionTable[2379],   1, 802 },
  { &yyActionTable[2380],   5, 802 },
  { &yyActionTable[2385],   1, 802 },
  { &yyActionTable[2386],   4, 802 },
  { &yyActionTable[2390],   3, 802 },
  { &yyActionTable[2393],   1, 802 },
  { &yyActionTable[2394],   2, 615 },
  { &yyActionTable[2396],   4, 802 },
  { &yyActionTable[2400],   1, 802 },
  { &yyActionTable[2401],   5, 802 },
  { &yyActionTable[2406],   4, 802 },
  { &yyActionTable[2410],   1, 802 },
  { &yyActionTable[2411],   1, 802 },
  { &yyActionTable[2412],   4, 802 },
  { &yyActionTable[2416],   2, 690 },
  { &yyActionTable[2418],   4, 802 },
  { &yyActionTable[2422],   5, 802 },
  { &yyActionTable[2427],   1, 802 },
  { &yyActionTable[2428],  16, 802 },
  { &yyActionTable[2444],   2, 802 },
  { &yyActionTable[2446],   1, 802 },
  { &yyActionTable[2447],   3, 802 },
  { &yyActionTable[2450],   1, 802 },
  { &yyActionTable[2451],   1, 802 },
  { &yyActionTable[2452],   2, 615 },
  { &yyActionTable[2454],   4, 802 },
  { &yyActionTable[2458],   1, 802 },
  { &yyActionTable[2459],   4, 802 },
  { &yyActionTable[2463],   2, 802 },
  { &yyActionTable[2465],   1, 802 },
  { &yyActionTable[2466],   1, 802 },
  { &yyActionTable[2467],   1, 802 },
  { &yyActionTable[2468],   5, 802 },
  { &yyActionTable[2473],   1, 802 },
  { &yyActionTable[2474],   3, 802 },
  { &yyActionTable[2477],   3, 802 },
  { &yyActionTable[2480],  10, 775 },
  { &yyActionTable[2490],   1, 802 },
  { &yyActionTable[2491],   1, 802 },
  { &yyActionTable[2492],   1, 802 },
  { &yyActionTable[2493],   1, 802 },
  { &yyActionTable[2494],   3, 802 },
  { &yyActionTable[2497],   1, 802 },
  { &yyActionTable[2498],   1, 802 },
  { &yyActionTable[2499],   1, 802 },
  { &yyActionTable[2500],   3, 802 },
  { &yyActionTable[2503],   1, 802 },
  { &yyActionTable[2504],   0, 774 },
  { &yyActionTable[2504],   4, 802 },
  { &yyActionTable[2508],   1, 802 },
  { &yyActionTable[2509],   1, 802 },
  { &yyActionTable[2510],   0, 529 },
  { &yyActionTable[2510],   0, 530 },
  { &yyActionTable[2510],   0, 526 },
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
   56,  /*    COLLATE => ID */
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
  "USING",         "VACUUM",        "VALUES",        "VIEW",        
  "WHEN",          "WHERE",         "as",            "carg",        
  "carglist",      "case_else",     "case_exprlist",  "case_operand",
  "ccons",         "cmd",           "cmdlist",       "collate",     
  "column",        "columnid",      "columnlist",    "conslist",    
  "conslist_opt",  "create_table",  "create_table_args",  "defer_subclause",
  "defer_subclause_opt",  "distinct",      "ecmd",          "error",       
  "explain",       "expr",          "expritem",      "exprlist",    
  "foreach_clause",  "from",          "groupby_opt",   "having_opt",  
  "id",            "ids",           "idxitem",       "idxlist",     
  "init_deferred_pred_opt",  "input",         "inscollist",    "inscollist_opt",
  "insert_cmd",    "itemlist",      "joinop",        "joinop2",     
  "likeop",        "limit_opt",     "limit_sep",     "minus_num",   
  "multiselect_op",  "nm",            "number",        "on_opt",      
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
 /*  57 */ "ccons ::= references",
 /*  58 */ "ccons ::= defer_subclause",
 /*  59 */ "ccons ::= COLLATE id",
 /*  60 */ "references ::= REFERENCES nm LP idxlist RP refargs",
 /*  61 */ "references ::= REFERENCES nm refargs",
 /*  62 */ "refargs ::=",
 /*  63 */ "refargs ::= refargs refarg",
 /*  64 */ "refarg ::= MATCH nm",
 /*  65 */ "refarg ::= ON DELETE refact",
 /*  66 */ "refarg ::= ON UPDATE refact",
 /*  67 */ "refact ::= SET NULL",
 /*  68 */ "refact ::= SET DEFAULT",
 /*  69 */ "refact ::= CASCADE",
 /*  70 */ "refact ::= RESTRICT",
 /*  71 */ "defer_subclause ::= NOT DEFERRABLE init_deferred_pred_opt",
 /*  72 */ "defer_subclause ::= DEFERRABLE init_deferred_pred_opt",
 /*  73 */ "init_deferred_pred_opt ::=",
 /*  74 */ "init_deferred_pred_opt ::= INITIALLY DEFERRED",
 /*  75 */ "init_deferred_pred_opt ::= INITIALLY IMMEDIATE",
 /*  76 */ "conslist_opt ::=",
 /*  77 */ "conslist_opt ::= COMMA conslist",
 /*  78 */ "conslist ::= conslist COMMA tcons",
 /*  79 */ "conslist ::= conslist tcons",
 /*  80 */ "conslist ::= tcons",
 /*  81 */ "tcons ::= CONSTRAINT nm",
 /*  82 */ "tcons ::= PRIMARY KEY LP idxlist RP onconf",
 /*  83 */ "tcons ::= UNIQUE LP idxlist RP onconf",
 /*  84 */ "tcons ::= CHECK expr onconf",
 /*  85 */ "tcons ::= FOREIGN KEY LP idxlist RP references defer_subclause_opt",
 /*  86 */ "defer_subclause_opt ::=",
 /*  87 */ "defer_subclause_opt ::= defer_subclause",
 /*  88 */ "onconf ::=",
 /*  89 */ "onconf ::= ON CONFLICT resolvetype",
 /*  90 */ "orconf ::=",
 /*  91 */ "orconf ::= OR resolvetype",
 /*  92 */ "resolvetype ::= ROLLBACK",
 /*  93 */ "resolvetype ::= ABORT",
 /*  94 */ "resolvetype ::= FAIL",
 /*  95 */ "resolvetype ::= IGNORE",
 /*  96 */ "resolvetype ::= REPLACE",
 /*  97 */ "cmd ::= DROP TABLE nm",
 /*  98 */ "cmd ::= CREATE temp VIEW nm AS select",
 /*  99 */ "cmd ::= DROP VIEW nm",
 /* 100 */ "cmd ::= select",
 /* 101 */ "select ::= oneselect",
 /* 102 */ "select ::= select multiselect_op oneselect",
 /* 103 */ "multiselect_op ::= UNION",
 /* 104 */ "multiselect_op ::= UNION ALL",
 /* 105 */ "multiselect_op ::= INTERSECT",
 /* 106 */ "multiselect_op ::= EXCEPT",
 /* 107 */ "oneselect ::= SELECT distinct selcollist from where_opt groupby_opt having_opt orderby_opt limit_opt",
 /* 108 */ "distinct ::= DISTINCT",
 /* 109 */ "distinct ::= ALL",
 /* 110 */ "distinct ::=",
 /* 111 */ "sclp ::= selcollist COMMA",
 /* 112 */ "sclp ::=",
 /* 113 */ "selcollist ::= sclp expr as",
 /* 114 */ "selcollist ::= sclp STAR",
 /* 115 */ "selcollist ::= sclp nm DOT STAR",
 /* 116 */ "as ::= AS nm",
 /* 117 */ "as ::= ids",
 /* 118 */ "as ::=",
 /* 119 */ "from ::=",
 /* 120 */ "from ::= FROM seltablist",
 /* 121 */ "stl_prefix ::= seltablist joinop",
 /* 122 */ "stl_prefix ::=",
 /* 123 */ "seltablist ::= stl_prefix nm as on_opt using_opt",
 /* 124 */ "seltablist ::= stl_prefix LP select RP as on_opt using_opt",
 /* 125 */ "joinop ::= COMMA",
 /* 126 */ "joinop ::= JOIN",
 /* 127 */ "joinop ::= JOIN_KW JOIN",
 /* 128 */ "joinop ::= JOIN_KW nm JOIN",
 /* 129 */ "joinop ::= JOIN_KW nm nm JOIN",
 /* 130 */ "on_opt ::= ON expr",
 /* 131 */ "on_opt ::=",
 /* 132 */ "using_opt ::= USING LP idxlist RP",
 /* 133 */ "using_opt ::=",
 /* 134 */ "orderby_opt ::=",
 /* 135 */ "orderby_opt ::= ORDER BY sortlist",
 /* 136 */ "sortlist ::= sortlist COMMA sortitem collate sortorder",
 /* 137 */ "sortlist ::= sortitem collate sortorder",
 /* 138 */ "sortitem ::= expr",
 /* 139 */ "sortorder ::= ASC",
 /* 140 */ "sortorder ::= DESC",
 /* 141 */ "sortorder ::=",
 /* 142 */ "collate ::=",
 /* 143 */ "collate ::= COLLATE id",
 /* 144 */ "groupby_opt ::=",
 /* 145 */ "groupby_opt ::= GROUP BY exprlist",
 /* 146 */ "having_opt ::=",
 /* 147 */ "having_opt ::= HAVING expr",
 /* 148 */ "limit_opt ::=",
 /* 149 */ "limit_opt ::= LIMIT INTEGER",
 /* 150 */ "limit_opt ::= LIMIT INTEGER limit_sep INTEGER",
 /* 151 */ "limit_sep ::= OFFSET",
 /* 152 */ "limit_sep ::= COMMA",
 /* 153 */ "cmd ::= DELETE FROM nm where_opt",
 /* 154 */ "where_opt ::=",
 /* 155 */ "where_opt ::= WHERE expr",
 /* 156 */ "cmd ::= UPDATE orconf nm SET setlist where_opt",
 /* 157 */ "setlist ::= setlist COMMA nm EQ expr",
 /* 158 */ "setlist ::= nm EQ expr",
 /* 159 */ "cmd ::= insert_cmd INTO nm inscollist_opt VALUES LP itemlist RP",
 /* 160 */ "cmd ::= insert_cmd INTO nm inscollist_opt select",
 /* 161 */ "insert_cmd ::= INSERT orconf",
 /* 162 */ "insert_cmd ::= REPLACE",
 /* 163 */ "itemlist ::= itemlist COMMA expr",
 /* 164 */ "itemlist ::= expr",
 /* 165 */ "inscollist_opt ::=",
 /* 166 */ "inscollist_opt ::= LP inscollist RP",
 /* 167 */ "inscollist ::= inscollist COMMA nm",
 /* 168 */ "inscollist ::= nm",
 /* 169 */ "expr ::= LP expr RP",
 /* 170 */ "expr ::= NULL",
 /* 171 */ "expr ::= ID",
 /* 172 */ "expr ::= JOIN_KW",
 /* 173 */ "expr ::= nm DOT nm",
 /* 174 */ "expr ::= INTEGER",
 /* 175 */ "expr ::= FLOAT",
 /* 176 */ "expr ::= STRING",
 /* 177 */ "expr ::= ID LP exprlist RP",
 /* 178 */ "expr ::= ID LP STAR RP",
 /* 179 */ "expr ::= expr AND expr",
 /* 180 */ "expr ::= expr OR expr",
 /* 181 */ "expr ::= expr LT expr",
 /* 182 */ "expr ::= expr GT expr",
 /* 183 */ "expr ::= expr LE expr",
 /* 184 */ "expr ::= expr GE expr",
 /* 185 */ "expr ::= expr NE expr",
 /* 186 */ "expr ::= expr EQ expr",
 /* 187 */ "expr ::= expr BITAND expr",
 /* 188 */ "expr ::= expr BITOR expr",
 /* 189 */ "expr ::= expr LSHIFT expr",
 /* 190 */ "expr ::= expr RSHIFT expr",
 /* 191 */ "expr ::= expr likeop expr",
 /* 192 */ "expr ::= expr NOT likeop expr",
 /* 193 */ "likeop ::= LIKE",
 /* 194 */ "likeop ::= GLOB",
 /* 195 */ "expr ::= expr PLUS expr",
 /* 196 */ "expr ::= expr MINUS expr",
 /* 197 */ "expr ::= expr STAR expr",
 /* 198 */ "expr ::= expr SLASH expr",
 /* 199 */ "expr ::= expr REM expr",
 /* 200 */ "expr ::= expr CONCAT expr",
 /* 201 */ "expr ::= expr ISNULL",
 /* 202 */ "expr ::= expr IS NULL",
 /* 203 */ "expr ::= expr NOTNULL",
 /* 204 */ "expr ::= expr NOT NULL",
 /* 205 */ "expr ::= expr IS NOT NULL",
 /* 206 */ "expr ::= NOT expr",
 /* 207 */ "expr ::= BITNOT expr",
 /* 208 */ "expr ::= MINUS expr",
 /* 209 */ "expr ::= PLUS expr",
 /* 210 */ "expr ::= LP select RP",
 /* 211 */ "expr ::= expr BETWEEN expr AND expr",
 /* 212 */ "expr ::= expr NOT BETWEEN expr AND expr",
 /* 213 */ "expr ::= expr IN LP exprlist RP",
 /* 214 */ "expr ::= expr IN LP select RP",
 /* 215 */ "expr ::= expr NOT IN LP exprlist RP",
 /* 216 */ "expr ::= expr NOT IN LP select RP",
 /* 217 */ "expr ::= CASE case_operand case_exprlist case_else END",
 /* 218 */ "case_exprlist ::= case_exprlist WHEN expr THEN expr",
 /* 219 */ "case_exprlist ::= WHEN expr THEN expr",
 /* 220 */ "case_else ::= ELSE expr",
 /* 221 */ "case_else ::=",
 /* 222 */ "case_operand ::= expr",
 /* 223 */ "case_operand ::=",
 /* 224 */ "exprlist ::= exprlist COMMA expritem",
 /* 225 */ "exprlist ::= expritem",
 /* 226 */ "expritem ::= expr",
 /* 227 */ "expritem ::=",
 /* 228 */ "cmd ::= CREATE uniqueflag INDEX nm ON nm LP idxlist RP onconf",
 /* 229 */ "uniqueflag ::= UNIQUE",
 /* 230 */ "uniqueflag ::=",
 /* 231 */ "idxlist ::= idxlist COMMA idxitem",
 /* 232 */ "idxlist ::= idxitem",
 /* 233 */ "idxitem ::= nm",
 /* 234 */ "cmd ::= DROP INDEX nm",
 /* 235 */ "cmd ::= COPY orconf nm FROM nm USING DELIMITERS STRING",
 /* 236 */ "cmd ::= COPY orconf nm FROM nm",
 /* 237 */ "cmd ::= VACUUM",
 /* 238 */ "cmd ::= VACUUM nm",
 /* 239 */ "cmd ::= PRAGMA ids EQ nm",
 /* 240 */ "cmd ::= PRAGMA ids EQ ON",
 /* 241 */ "cmd ::= PRAGMA ids EQ plus_num",
 /* 242 */ "cmd ::= PRAGMA ids EQ minus_num",
 /* 243 */ "cmd ::= PRAGMA ids LP nm RP",
 /* 244 */ "cmd ::= PRAGMA ids",
 /* 245 */ "plus_num ::= plus_opt number",
 /* 246 */ "minus_num ::= MINUS number",
 /* 247 */ "number ::= INTEGER",
 /* 248 */ "number ::= FLOAT",
 /* 249 */ "plus_opt ::= PLUS",
 /* 250 */ "plus_opt ::=",
 /* 251 */ "cmd ::= CREATE TRIGGER nm trigger_time trigger_event ON nm foreach_clause when_clause BEGIN trigger_cmd_list END",
 /* 252 */ "trigger_time ::= BEFORE",
 /* 253 */ "trigger_time ::= AFTER",
 /* 254 */ "trigger_time ::= INSTEAD OF",
 /* 255 */ "trigger_time ::=",
 /* 256 */ "trigger_event ::= DELETE",
 /* 257 */ "trigger_event ::= INSERT",
 /* 258 */ "trigger_event ::= UPDATE",
 /* 259 */ "trigger_event ::= UPDATE OF inscollist",
 /* 260 */ "foreach_clause ::=",
 /* 261 */ "foreach_clause ::= FOR EACH ROW",
 /* 262 */ "foreach_clause ::= FOR EACH STATEMENT",
 /* 263 */ "when_clause ::=",
 /* 264 */ "when_clause ::= WHEN expr",
 /* 265 */ "trigger_cmd_list ::= trigger_cmd SEMI trigger_cmd_list",
 /* 266 */ "trigger_cmd_list ::=",
 /* 267 */ "trigger_cmd ::= UPDATE orconf nm SET setlist where_opt",
 /* 268 */ "trigger_cmd ::= INSERT orconf INTO nm inscollist_opt VALUES LP itemlist RP",
 /* 269 */ "trigger_cmd ::= INSERT orconf INTO nm inscollist_opt select",
 /* 270 */ "trigger_cmd ::= DELETE FROM nm where_opt",
 /* 271 */ "trigger_cmd ::= select",
 /* 272 */ "expr ::= RAISE LP IGNORE RP",
 /* 273 */ "expr ::= RAISE LP ROLLBACK COMMA nm RP",
 /* 274 */ "expr ::= RAISE LP ABORT COMMA nm RP",
 /* 275 */ "expr ::= RAISE LP FAIL COMMA nm RP",
 /* 276 */ "cmd ::= DROP TRIGGER nm",
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
    case 130:
#line 633 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4192 "parse.c"
      break;
    case 149:
#line 492 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4197 "parse.c"
      break;
    case 150:
#line 652 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4202 "parse.c"
      break;
    case 151:
#line 650 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4207 "parse.c"
      break;
    case 153:
#line 320 "parse.y"
{sqliteSrcListDelete((yypminor->yy7));}
#line 4212 "parse.c"
      break;
    case 154:
#line 410 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4217 "parse.c"
      break;
    case 155:
#line 415 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4222 "parse.c"
      break;
    case 159:
#line 674 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4227 "parse.c"
      break;
    case 162:
#line 471 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4232 "parse.c"
      break;
    case 163:
#line 469 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4237 "parse.c"
      break;
    case 165:
#line 463 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4242 "parse.c"
      break;
    case 175:
#line 371 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4247 "parse.c"
      break;
    case 177:
#line 255 "parse.y"
{sqliteSelectDelete((yypminor->yy219));}
#line 4252 "parse.c"
      break;
    case 179:
#line 382 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4257 "parse.c"
      break;
    case 187:
#line 291 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4262 "parse.c"
      break;
    case 188:
#line 289 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4267 "parse.c"
      break;
    case 189:
#line 253 "parse.y"
{sqliteSelectDelete((yypminor->yy219));}
#line 4272 "parse.c"
      break;
    case 190:
#line 316 "parse.y"
{sqliteSrcListDelete((yypminor->yy7));}
#line 4277 "parse.c"
      break;
    case 191:
#line 439 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4282 "parse.c"
      break;
    case 193:
#line 386 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4287 "parse.c"
      break;
    case 194:
#line 384 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4292 "parse.c"
      break;
    case 196:
#line 318 "parse.y"
{sqliteSrcListDelete((yypminor->yy7));}
#line 4297 "parse.c"
      break;
    case 202:
#line 731 "parse.y"
{sqliteIdListDelete((yypminor->yy90).b);}
#line 4302 "parse.c"
      break;
    case 207:
#line 376 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4307 "parse.c"
      break;
    case 209:
#line 433 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4312 "parse.c"
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
  { 161, 1 },
  { 134, 1 },
  { 134, 2 },
  { 146, 3 },
  { 146, 1 },
  { 148, 1 },
  { 148, 0 },
  { 133, 3 },
  { 199, 0 },
  { 199, 1 },
  { 199, 2 },
  { 133, 2 },
  { 133, 2 },
  { 133, 2 },
  { 133, 2 },
  { 141, 4 },
  { 198, 1 },
  { 198, 0 },
  { 142, 4 },
  { 142, 2 },
  { 138, 3 },
  { 138, 1 },
  { 136, 3 },
  { 137, 1 },
  { 156, 1 },
  { 157, 1 },
  { 157, 1 },
  { 173, 1 },
  { 173, 1 },
  { 173, 1 },
  { 204, 0 },
  { 204, 1 },
  { 204, 4 },
  { 204, 6 },
  { 205, 1 },
  { 205, 2 },
  { 192, 1 },
  { 192, 2 },
  { 192, 2 },
  { 128, 2 },
  { 128, 0 },
  { 127, 3 },
  { 127, 1 },
  { 127, 2 },
  { 127, 2 },
  { 127, 2 },
  { 127, 3 },
  { 127, 3 },
  { 127, 2 },
  { 127, 3 },
  { 127, 3 },
  { 127, 2 },
  { 132, 2 },
  { 132, 3 },
  { 132, 4 },
  { 132, 2 },
  { 132, 5 },
  { 132, 1 },
  { 132, 1 },
  { 132, 2 },
  { 185, 6 },
  { 185, 3 },
  { 184, 0 },
  { 184, 2 },
  { 183, 2 },
  { 183, 3 },
  { 183, 3 },
  { 182, 2 },
  { 182, 2 },
  { 182, 1 },
  { 182, 1 },
  { 143, 3 },
  { 143, 2 },
  { 160, 0 },
  { 160, 2 },
  { 160, 2 },
  { 140, 0 },
  { 140, 2 },
  { 139, 3 },
  { 139, 2 },
  { 139, 1 },
  { 197, 2 },
  { 197, 6 },
  { 197, 5 },
  { 197, 3 },
  { 197, 7 },
  { 144, 0 },
  { 144, 1 },
  { 176, 0 },
  { 176, 3 },
  { 178, 0 },
  { 178, 2 },
  { 186, 1 },
  { 186, 1 },
  { 186, 1 },
  { 186, 1 },
  { 186, 1 },
  { 133, 3 },
  { 133, 6 },
  { 133, 3 },
  { 133, 1 },
  { 189, 1 },
  { 189, 3 },
  { 172, 1 },
  { 172, 2 },
  { 172, 1 },
  { 172, 1 },
  { 177, 9 },
  { 145, 1 },
  { 145, 1 },
  { 145, 0 },
  { 187, 2 },
  { 187, 0 },
  { 188, 3 },
  { 188, 2 },
  { 188, 4 },
  { 126, 2 },
  { 126, 1 },
  { 126, 0 },
  { 153, 0 },
  { 153, 2 },
  { 196, 2 },
  { 196, 0 },
  { 190, 5 },
  { 190, 7 },
  { 166, 1 },
  { 166, 1 },
  { 166, 2 },
  { 166, 3 },
  { 166, 4 },
  { 175, 2 },
  { 175, 0 },
  { 207, 4 },
  { 207, 0 },
  { 179, 0 },
  { 179, 3 },
  { 194, 5 },
  { 194, 3 },
  { 193, 1 },
  { 195, 1 },
  { 195, 1 },
  { 195, 0 },
  { 135, 0 },
  { 135, 2 },
  { 154, 0 },
  { 154, 3 },
  { 155, 0 },
  { 155, 2 },
  { 169, 0 },
  { 169, 2 },
  { 169, 4 },
  { 170, 1 },
  { 170, 1 },
  { 133, 4 },
  { 209, 0 },
  { 209, 2 },
  { 133, 6 },
  { 191, 5 },
  { 191, 3 },
  { 133, 8 },
  { 133, 5 },
  { 164, 2 },
  { 164, 1 },
  { 165, 3 },
  { 165, 1 },
  { 163, 0 },
  { 163, 3 },
  { 162, 3 },
  { 162, 1 },
  { 149, 3 },
  { 149, 1 },
  { 149, 1 },
  { 149, 1 },
  { 149, 3 },
  { 149, 1 },
  { 149, 1 },
  { 149, 1 },
  { 149, 4 },
  { 149, 4 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 4 },
  { 168, 1 },
  { 168, 1 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 3 },
  { 149, 2 },
  { 149, 3 },
  { 149, 2 },
  { 149, 3 },
  { 149, 4 },
  { 149, 2 },
  { 149, 2 },
  { 149, 2 },
  { 149, 2 },
  { 149, 3 },
  { 149, 5 },
  { 149, 6 },
  { 149, 5 },
  { 149, 5 },
  { 149, 6 },
  { 149, 6 },
  { 149, 5 },
  { 130, 5 },
  { 130, 4 },
  { 129, 2 },
  { 129, 0 },
  { 131, 1 },
  { 131, 0 },
  { 151, 3 },
  { 151, 1 },
  { 150, 1 },
  { 150, 0 },
  { 133, 10 },
  { 206, 1 },
  { 206, 0 },
  { 159, 3 },
  { 159, 1 },
  { 158, 1 },
  { 133, 3 },
  { 133, 8 },
  { 133, 5 },
  { 133, 1 },
  { 133, 2 },
  { 133, 4 },
  { 133, 4 },
  { 133, 4 },
  { 133, 4 },
  { 133, 5 },
  { 133, 2 },
  { 180, 2 },
  { 171, 2 },
  { 174, 1 },
  { 174, 1 },
  { 181, 1 },
  { 181, 0 },
  { 133, 12 },
  { 203, 1 },
  { 203, 1 },
  { 203, 2 },
  { 203, 0 },
  { 202, 1 },
  { 202, 1 },
  { 202, 1 },
  { 202, 3 },
  { 152, 0 },
  { 152, 3 },
  { 152, 3 },
  { 208, 0 },
  { 208, 2 },
  { 201, 3 },
  { 201, 0 },
  { 200, 6 },
  { 200, 9 },
  { 200, 6 },
  { 200, 4 },
  { 200, 1 },
  { 149, 4 },
  { 149, 6 },
  { 149, 6 },
  { 149, 6 },
  { 133, 3 },
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
#line 4784 "parse.c"
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
#line 4795 "parse.c"
        /* No destructor defined for EXPLAIN */
        break;
      case 6:
#line 70 "parse.y"
{ sqliteBeginParse(pParse, 0); }
#line 4801 "parse.c"
        break;
      case 7:
#line 75 "parse.y"
{sqliteBeginTransaction(pParse,yymsp[0].minor.yy172);}
#line 4806 "parse.c"
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
#line 4822 "parse.c"
        /* No destructor defined for COMMIT */
        /* No destructor defined for trans_opt */
        break;
      case 12:
#line 80 "parse.y"
{sqliteCommitTransaction(pParse);}
#line 4829 "parse.c"
        /* No destructor defined for END */
        /* No destructor defined for trans_opt */
        break;
      case 13:
#line 81 "parse.y"
{sqliteRollbackTransaction(pParse);}
#line 4836 "parse.c"
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
#line 4849 "parse.c"
        /* No destructor defined for TABLE */
        break;
      case 16:
#line 90 "parse.y"
{yygotominor.yy172 = pParse->isTemp || !pParse->initFlag;}
#line 4855 "parse.c"
        /* No destructor defined for TEMP */
        break;
      case 17:
#line 91 "parse.y"
{yygotominor.yy172 = pParse->isTemp;}
#line 4861 "parse.c"
        break;
      case 18:
#line 92 "parse.y"
{
  sqliteEndTable(pParse,&yymsp[0].minor.yy0,0);
}
#line 4868 "parse.c"
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
#line 4879 "parse.c"
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
#line 4898 "parse.c"
        break;
      case 24:
#line 113 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4903 "parse.c"
        break;
      case 25:
#line 129 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4908 "parse.c"
        break;
      case 26:
#line 130 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4913 "parse.c"
        break;
      case 27:
#line 135 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4918 "parse.c"
        break;
      case 28:
#line 136 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4923 "parse.c"
        break;
      case 29:
#line 137 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4928 "parse.c"
        break;
      case 30:
        break;
      case 31:
#line 140 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[0].minor.yy378,&yymsp[0].minor.yy378);}
#line 4935 "parse.c"
        break;
      case 32:
#line 141 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-3].minor.yy378,&yymsp[0].minor.yy0);}
#line 4940 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        break;
      case 33:
#line 143 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-5].minor.yy378,&yymsp[0].minor.yy0);}
#line 4947 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        /* No destructor defined for COMMA */
        /* No destructor defined for signed */
        break;
      case 34:
#line 145 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 4956 "parse.c"
        break;
      case 35:
#line 146 "parse.y"
{yygotominor.yy378 = yymsp[-1].minor.yy378;}
#line 4961 "parse.c"
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
#line 4992 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 44:
#line 155 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 4998 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 45:
#line 156 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5004 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 46:
#line 157 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5010 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 47:
#line 158 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 5017 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 48:
#line 159 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5024 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 49:
#line 160 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5030 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 50:
#line 161 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 5037 "parse.c"
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
{sqliteAddNotNull(pParse, yymsp[0].minor.yy172);}
#line 5052 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for NULL */
        break;
      case 54:
#line 169 "parse.y"
{sqliteAddPrimaryKey(pParse,0,yymsp[0].minor.yy172);}
#line 5059 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for sortorder */
        break;
      case 55:
#line 170 "parse.y"
{sqliteCreateIndex(pParse,0,0,0,yymsp[0].minor.yy172,0,0);}
#line 5067 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 56:
        /* No destructor defined for CHECK */
        /* No destructor defined for LP */
  yy_destructor(149,&yymsp[-2].minor);
        /* No destructor defined for RP */
        /* No destructor defined for onconf */
        break;
      case 57:
        /* No destructor defined for references */
        break;
      case 58:
        /* No destructor defined for defer_subclause */
        break;
      case 59:
#line 174 "parse.y"
{
   sqliteAddCollateType(pParse, sqliteCollateType(pParse, &yymsp[0].minor.yy378));
}
#line 5088 "parse.c"
        /* No destructor defined for COLLATE */
        break;
      case 60:
        /* No destructor defined for REFERENCES */
        /* No destructor defined for nm */
        /* No destructor defined for LP */
  yy_destructor(159,&yymsp[-2].minor);
        /* No destructor defined for RP */
        /* No destructor defined for refargs */
        break;
      case 61:
        /* No destructor defined for REFERENCES */
        /* No destructor defined for nm */
        /* No destructor defined for refargs */
        break;
      case 62:
        break;
      case 63:
        /* No destructor defined for refargs */
        /* No destructor defined for refarg */
        break;
      case 64:
        /* No destructor defined for MATCH */
        /* No destructor defined for nm */
        break;
      case 65:
        /* No destructor defined for ON */
        /* No destructor defined for DELETE */
        /* No destructor defined for refact */
        break;
      case 66:
        /* No destructor defined for ON */
        /* No destructor defined for UPDATE */
        /* No destructor defined for refact */
        break;
      case 67:
        /* No destructor defined for SET */
        /* No destructor defined for NULL */
        break;
      case 68:
        /* No destructor defined for SET */
        /* No destructor defined for DEFAULT */
        break;
      case 69:
        /* No destructor defined for CASCADE */
        break;
      case 70:
        /* No destructor defined for RESTRICT */
        break;
      case 71:
        /* No destructor defined for NOT */
        /* No destructor defined for DEFERRABLE */
        /* No destructor defined for init_deferred_pred_opt */
        break;
      case 72:
        /* No destructor defined for DEFERRABLE */
        /* No destructor defined for init_deferred_pred_opt */
        break;
      case 73:
        break;
      case 74:
        /* No destructor defined for INITIALLY */
        /* No destructor defined for DEFERRED */
        break;
      case 75:
        /* No destructor defined for INITIALLY */
        /* No destructor defined for IMMEDIATE */
        break;
      case 76:
        break;
      case 77:
        /* No destructor defined for COMMA */
        /* No destructor defined for conslist */
        break;
      case 78:
        /* No destructor defined for conslist */
        /* No destructor defined for COMMA */
        /* No destructor defined for tcons */
        break;
      case 79:
        /* No destructor defined for conslist */
        /* No destructor defined for tcons */
        break;
      case 80:
        /* No destructor defined for tcons */
        break;
      case 81:
        /* No destructor defined for CONSTRAINT */
        /* No destructor defined for nm */
        break;
      case 82:
#line 208 "parse.y"
{sqliteAddPrimaryKey(pParse,yymsp[-2].minor.yy250,yymsp[0].minor.yy172);}
#line 5182 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 83:
#line 210 "parse.y"
{sqliteCreateIndex(pParse,0,0,yymsp[-2].minor.yy250,yymsp[0].minor.yy172,0,0);}
#line 5191 "parse.c"
        /* No destructor defined for UNIQUE */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 84:
        /* No destructor defined for CHECK */
  yy_destructor(149,&yymsp[-1].minor);
        /* No destructor defined for onconf */
        break;
      case 85:
        /* No destructor defined for FOREIGN */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
  yy_destructor(159,&yymsp[-3].minor);
        /* No destructor defined for RP */
        /* No destructor defined for references */
        /* No destructor defined for defer_subclause_opt */
        break;
      case 86:
        break;
      case 87:
        /* No destructor defined for defer_subclause */
        break;
      case 88:
#line 222 "parse.y"
{ yygotominor.yy172 = OE_Default; }
#line 5218 "parse.c"
        break;
      case 89:
#line 223 "parse.y"
{ yygotominor.yy172 = yymsp[0].minor.yy172; }
#line 5223 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for CONFLICT */
        break;
      case 90:
#line 224 "parse.y"
{ yygotominor.yy172 = OE_Default; }
#line 5230 "parse.c"
        break;
      case 91:
#line 225 "parse.y"
{ yygotominor.yy172 = yymsp[0].minor.yy172; }
#line 5235 "parse.c"
        /* No destructor defined for OR */
        break;
      case 92:
#line 226 "parse.y"
{ yygotominor.yy172 = OE_Rollback; }
#line 5241 "parse.c"
        /* No destructor defined for ROLLBACK */
        break;
      case 93:
#line 227 "parse.y"
{ yygotominor.yy172 = OE_Abort; }
#line 5247 "parse.c"
        /* No destructor defined for ABORT */
        break;
      case 94:
#line 228 "parse.y"
{ yygotominor.yy172 = OE_Fail; }
#line 5253 "parse.c"
        /* No destructor defined for FAIL */
        break;
      case 95:
#line 229 "parse.y"
{ yygotominor.yy172 = OE_Ignore; }
#line 5259 "parse.c"
        /* No destructor defined for IGNORE */
        break;
      case 96:
#line 230 "parse.y"
{ yygotominor.yy172 = OE_Replace; }
#line 5265 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 97:
#line 234 "parse.y"
{sqliteDropTable(pParse,&yymsp[0].minor.yy378,0);}
#line 5271 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for TABLE */
        break;
      case 98:
#line 238 "parse.y"
{
  sqliteCreateView(pParse, &yymsp[-5].minor.yy0, &yymsp[-2].minor.yy378, yymsp[0].minor.yy219, yymsp[-4].minor.yy172);
}
#line 5280 "parse.c"
        /* No destructor defined for VIEW */
        /* No destructor defined for AS */
        break;
      case 99:
#line 241 "parse.y"
{
  sqliteDropTable(pParse, &yymsp[0].minor.yy378, 1);
}
#line 5289 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for VIEW */
        break;
      case 100:
#line 247 "parse.y"
{
  sqliteSelect(pParse, yymsp[0].minor.yy219, SRT_Callback, 0, 0, 0, 0);
  sqliteSelectDelete(yymsp[0].minor.yy219);
}
#line 5299 "parse.c"
        break;
      case 101:
#line 257 "parse.y"
{yygotominor.yy219 = yymsp[0].minor.yy219;}
#line 5304 "parse.c"
        break;
      case 102:
#line 258 "parse.y"
{
  if( yymsp[0].minor.yy219 ){
    yymsp[0].minor.yy219->op = yymsp[-1].minor.yy172;
    yymsp[0].minor.yy219->pPrior = yymsp[-2].minor.yy219;
  }
  yygotominor.yy219 = yymsp[0].minor.yy219;
}
#line 5315 "parse.c"
        break;
      case 103:
#line 266 "parse.y"
{yygotominor.yy172 = TK_UNION;}
#line 5320 "parse.c"
        /* No destructor defined for UNION */
        break;
      case 104:
#line 267 "parse.y"
{yygotominor.yy172 = TK_ALL;}
#line 5326 "parse.c"
        /* No destructor defined for UNION */
        /* No destructor defined for ALL */
        break;
      case 105:
#line 268 "parse.y"
{yygotominor.yy172 = TK_INTERSECT;}
#line 5333 "parse.c"
        /* No destructor defined for INTERSECT */
        break;
      case 106:
#line 269 "parse.y"
{yygotominor.yy172 = TK_EXCEPT;}
#line 5339 "parse.c"
        /* No destructor defined for EXCEPT */
        break;
      case 107:
#line 271 "parse.y"
{
  yygotominor.yy219 = sqliteSelectNew(yymsp[-6].minor.yy228,yymsp[-5].minor.yy7,yymsp[-4].minor.yy62,yymsp[-3].minor.yy228,yymsp[-2].minor.yy62,yymsp[-1].minor.yy228,yymsp[-7].minor.yy172,yymsp[0].minor.yy6.limit,yymsp[0].minor.yy6.offset);
}
#line 5347 "parse.c"
        /* No destructor defined for SELECT */
        break;
      case 108:
#line 279 "parse.y"
{yygotominor.yy172 = 1;}
#line 5353 "parse.c"
        /* No destructor defined for DISTINCT */
        break;
      case 109:
#line 280 "parse.y"
{yygotominor.yy172 = 0;}
#line 5359 "parse.c"
        /* No destructor defined for ALL */
        break;
      case 110:
#line 281 "parse.y"
{yygotominor.yy172 = 0;}
#line 5365 "parse.c"
        break;
      case 111:
#line 292 "parse.y"
{yygotominor.yy228 = yymsp[-1].minor.yy228;}
#line 5370 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 112:
#line 293 "parse.y"
{yygotominor.yy228 = 0;}
#line 5376 "parse.c"
        break;
      case 113:
#line 294 "parse.y"
{
   yygotominor.yy228 = sqliteExprListAppend(yymsp[-2].minor.yy228,yymsp[-1].minor.yy62,yymsp[0].minor.yy378.n?&yymsp[0].minor.yy378:0);
}
#line 5383 "parse.c"
        break;
      case 114:
#line 297 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-1].minor.yy228, sqliteExpr(TK_ALL, 0, 0, 0), 0);
}
#line 5390 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 115:
#line 300 "parse.y"
{
  Expr *pRight = sqliteExpr(TK_ALL, 0, 0, 0);
  Expr *pLeft = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy378);
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-3].minor.yy228, sqliteExpr(TK_DOT, pLeft, pRight, 0), 0);
}
#line 5400 "parse.c"
        /* No destructor defined for DOT */
        /* No destructor defined for STAR */
        break;
      case 116:
#line 310 "parse.y"
{ yygotominor.yy378 = yymsp[0].minor.yy378; }
#line 5407 "parse.c"
        /* No destructor defined for AS */
        break;
      case 117:
#line 311 "parse.y"
{ yygotominor.yy378 = yymsp[0].minor.yy378; }
#line 5413 "parse.c"
        break;
      case 118:
#line 312 "parse.y"
{ yygotominor.yy378.n = 0; }
#line 5418 "parse.c"
        break;
      case 119:
#line 324 "parse.y"
{yygotominor.yy7 = sqliteMalloc(sizeof(*yygotominor.yy7));}
#line 5423 "parse.c"
        break;
      case 120:
#line 325 "parse.y"
{yygotominor.yy7 = yymsp[0].minor.yy7;}
#line 5428 "parse.c"
        /* No destructor defined for FROM */
        break;
      case 121:
#line 330 "parse.y"
{
   yygotominor.yy7 = yymsp[-1].minor.yy7;
   if( yygotominor.yy7 && yygotominor.yy7->nSrc>0 ) yygotominor.yy7->a[yygotominor.yy7->nSrc-1].jointype = yymsp[0].minor.yy172;
}
#line 5437 "parse.c"
        break;
      case 122:
#line 334 "parse.y"
{yygotominor.yy7 = 0;}
#line 5442 "parse.c"
        break;
      case 123:
#line 335 "parse.y"
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
#line 5458 "parse.c"
        break;
      case 124:
#line 347 "parse.y"
{
  yygotominor.yy7 = sqliteSrcListAppend(yymsp[-6].minor.yy7,0);
  yygotominor.yy7->a[yygotominor.yy7->nSrc-1].pSelect = yymsp[-4].minor.yy219;
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
#line 5475 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 125:
#line 363 "parse.y"
{ yygotominor.yy172 = JT_INNER; }
#line 5482 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 126:
#line 364 "parse.y"
{ yygotominor.yy172 = JT_INNER; }
#line 5488 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 127:
#line 365 "parse.y"
{ yygotominor.yy172 = sqliteJoinType(pParse,&yymsp[-1].minor.yy0,0,0); }
#line 5494 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 128:
#line 366 "parse.y"
{ yygotominor.yy172 = sqliteJoinType(pParse,&yymsp[-2].minor.yy0,&yymsp[-1].minor.yy378,0); }
#line 5500 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 129:
#line 368 "parse.y"
{ yygotominor.yy172 = sqliteJoinType(pParse,&yymsp[-3].minor.yy0,&yymsp[-2].minor.yy378,&yymsp[-1].minor.yy378); }
#line 5506 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 130:
#line 372 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5512 "parse.c"
        /* No destructor defined for ON */
        break;
      case 131:
#line 373 "parse.y"
{yygotominor.yy62 = 0;}
#line 5518 "parse.c"
        break;
      case 132:
#line 377 "parse.y"
{yygotominor.yy250 = yymsp[-1].minor.yy250;}
#line 5523 "parse.c"
        /* No destructor defined for USING */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 133:
#line 378 "parse.y"
{yygotominor.yy250 = 0;}
#line 5531 "parse.c"
        break;
      case 134:
#line 388 "parse.y"
{yygotominor.yy228 = 0;}
#line 5536 "parse.c"
        break;
      case 135:
#line 389 "parse.y"
{yygotominor.yy228 = yymsp[0].minor.yy228;}
#line 5541 "parse.c"
        /* No destructor defined for ORDER */
        /* No destructor defined for BY */
        break;
      case 136:
#line 390 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-4].minor.yy228,yymsp[-2].minor.yy62,0);
  if( yygotominor.yy228 ) yygotominor.yy228->a[yygotominor.yy228->nExpr-1].sortOrder = yymsp[-1].minor.yy172+yymsp[0].minor.yy172;
}
#line 5551 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 137:
#line 394 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(0,yymsp[-2].minor.yy62,0);
  if( yygotominor.yy228 ) yygotominor.yy228->a[0].sortOrder = yymsp[-1].minor.yy172+yymsp[0].minor.yy172;
}
#line 5560 "parse.c"
        break;
      case 138:
#line 398 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5565 "parse.c"
        break;
      case 139:
#line 403 "parse.y"
{yygotominor.yy172 = SQLITE_SO_ASC;}
#line 5570 "parse.c"
        /* No destructor defined for ASC */
        break;
      case 140:
#line 404 "parse.y"
{yygotominor.yy172 = SQLITE_SO_DESC;}
#line 5576 "parse.c"
        /* No destructor defined for DESC */
        break;
      case 141:
#line 405 "parse.y"
{yygotominor.yy172 = SQLITE_SO_ASC;}
#line 5582 "parse.c"
        break;
      case 142:
#line 406 "parse.y"
{yygotominor.yy172 = SQLITE_SO_UNK;}
#line 5587 "parse.c"
        break;
      case 143:
#line 407 "parse.y"
{yygotominor.yy172 = sqliteCollateType(pParse, &yymsp[0].minor.yy378);}
#line 5592 "parse.c"
        /* No destructor defined for COLLATE */
        break;
      case 144:
#line 411 "parse.y"
{yygotominor.yy228 = 0;}
#line 5598 "parse.c"
        break;
      case 145:
#line 412 "parse.y"
{yygotominor.yy228 = yymsp[0].minor.yy228;}
#line 5603 "parse.c"
        /* No destructor defined for GROUP */
        /* No destructor defined for BY */
        break;
      case 146:
#line 416 "parse.y"
{yygotominor.yy62 = 0;}
#line 5610 "parse.c"
        break;
      case 147:
#line 417 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5615 "parse.c"
        /* No destructor defined for HAVING */
        break;
      case 148:
#line 420 "parse.y"
{yygotominor.yy6.limit = -1; yygotominor.yy6.offset = 0;}
#line 5621 "parse.c"
        break;
      case 149:
#line 421 "parse.y"
{yygotominor.yy6.limit = atoi(yymsp[0].minor.yy0.z); yygotominor.yy6.offset = 0;}
#line 5626 "parse.c"
        /* No destructor defined for LIMIT */
        break;
      case 150:
#line 423 "parse.y"
{yygotominor.yy6.limit = atoi(yymsp[-2].minor.yy0.z); yygotominor.yy6.offset = atoi(yymsp[0].minor.yy0.z);}
#line 5632 "parse.c"
        /* No destructor defined for LIMIT */
        /* No destructor defined for limit_sep */
        break;
      case 151:
        /* No destructor defined for OFFSET */
        break;
      case 152:
        /* No destructor defined for COMMA */
        break;
      case 153:
#line 430 "parse.y"
{sqliteDeleteFrom(pParse, &yymsp[-1].minor.yy378, yymsp[0].minor.yy62);}
#line 5645 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 154:
#line 435 "parse.y"
{yygotominor.yy62 = 0;}
#line 5652 "parse.c"
        break;
      case 155:
#line 436 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5657 "parse.c"
        /* No destructor defined for WHERE */
        break;
      case 156:
#line 444 "parse.y"
{sqliteUpdate(pParse,&yymsp[-3].minor.yy378,yymsp[-1].minor.yy228,yymsp[0].minor.yy62,yymsp[-4].minor.yy172);}
#line 5663 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 157:
#line 447 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(yymsp[-4].minor.yy228,yymsp[0].minor.yy62,&yymsp[-2].minor.yy378);}
#line 5670 "parse.c"
        /* No destructor defined for COMMA */
        /* No destructor defined for EQ */
        break;
      case 158:
#line 448 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(0,yymsp[0].minor.yy62,&yymsp[-2].minor.yy378);}
#line 5677 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 159:
#line 453 "parse.y"
{sqliteInsert(pParse, &yymsp[-5].minor.yy378, yymsp[-1].minor.yy228, 0, yymsp[-4].minor.yy250, yymsp[-7].minor.yy172);}
#line 5683 "parse.c"
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 160:
#line 455 "parse.y"
{sqliteInsert(pParse, &yymsp[-2].minor.yy378, 0, yymsp[0].minor.yy219, yymsp[-1].minor.yy250, yymsp[-4].minor.yy172);}
#line 5692 "parse.c"
        /* No destructor defined for INTO */
        break;
      case 161:
#line 458 "parse.y"
{yygotominor.yy172 = yymsp[0].minor.yy172;}
#line 5698 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 162:
#line 459 "parse.y"
{yygotominor.yy172 = OE_Replace;}
#line 5704 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 163:
#line 465 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(yymsp[-2].minor.yy228,yymsp[0].minor.yy62,0);}
#line 5710 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 164:
#line 466 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(0,yymsp[0].minor.yy62,0);}
#line 5716 "parse.c"
        break;
      case 165:
#line 473 "parse.y"
{yygotominor.yy250 = 0;}
#line 5721 "parse.c"
        break;
      case 166:
#line 474 "parse.y"
{yygotominor.yy250 = yymsp[-1].minor.yy250;}
#line 5726 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 167:
#line 475 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(yymsp[-2].minor.yy250,&yymsp[0].minor.yy378);}
#line 5733 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 168:
#line 476 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(0,&yymsp[0].minor.yy378);}
#line 5739 "parse.c"
        break;
      case 169:
#line 494 "parse.y"
{yygotominor.yy62 = yymsp[-1].minor.yy62; sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);}
#line 5744 "parse.c"
        break;
      case 170:
#line 495 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_NULL, 0, 0, &yymsp[0].minor.yy0);}
#line 5749 "parse.c"
        break;
      case 171:
#line 496 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy0);}
#line 5754 "parse.c"
        break;
      case 172:
#line 497 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy0);}
#line 5759 "parse.c"
        break;
      case 173:
#line 498 "parse.y"
{
  Expr *temp1 = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy378);
  Expr *temp2 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy378);
  yygotominor.yy62 = sqliteExpr(TK_DOT, temp1, temp2, 0);
}
#line 5768 "parse.c"
        /* No destructor defined for DOT */
        break;
      case 174:
#line 503 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_INTEGER, 0, 0, &yymsp[0].minor.yy0);}
#line 5774 "parse.c"
        break;
      case 175:
#line 504 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_FLOAT, 0, 0, &yymsp[0].minor.yy0);}
#line 5779 "parse.c"
        break;
      case 176:
#line 505 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_STRING, 0, 0, &yymsp[0].minor.yy0);}
#line 5784 "parse.c"
        break;
      case 177:
#line 506 "parse.y"
{
  yygotominor.yy62 = sqliteExprFunction(yymsp[-1].minor.yy228, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 5792 "parse.c"
        /* No destructor defined for LP */
        break;
      case 178:
#line 510 "parse.y"
{
  yygotominor.yy62 = sqliteExprFunction(0, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 5801 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for STAR */
        break;
      case 179:
#line 514 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_AND, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5808 "parse.c"
        /* No destructor defined for AND */
        break;
      case 180:
#line 515 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_OR, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5814 "parse.c"
        /* No destructor defined for OR */
        break;
      case 181:
#line 516 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_LT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5820 "parse.c"
        /* No destructor defined for LT */
        break;
      case 182:
#line 517 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_GT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5826 "parse.c"
        /* No destructor defined for GT */
        break;
      case 183:
#line 518 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_LE, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5832 "parse.c"
        /* No destructor defined for LE */
        break;
      case 184:
#line 519 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_GE, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5838 "parse.c"
        /* No destructor defined for GE */
        break;
      case 185:
#line 520 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_NE, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5844 "parse.c"
        /* No destructor defined for NE */
        break;
      case 186:
#line 521 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_EQ, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5850 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 187:
#line 522 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_BITAND, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5856 "parse.c"
        /* No destructor defined for BITAND */
        break;
      case 188:
#line 523 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_BITOR, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5862 "parse.c"
        /* No destructor defined for BITOR */
        break;
      case 189:
#line 524 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_LSHIFT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5868 "parse.c"
        /* No destructor defined for LSHIFT */
        break;
      case 190:
#line 525 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_RSHIFT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5874 "parse.c"
        /* No destructor defined for RSHIFT */
        break;
      case 191:
#line 526 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[0].minor.yy62, 0);
  pList = sqliteExprListAppend(pList, yymsp[-2].minor.yy62, 0);
  yygotominor.yy62 = sqliteExprFunction(pList, &yymsp[-1].minor.yy378);
  sqliteExprSpan(yygotominor.yy62, &yymsp[-2].minor.yy62->span, &yymsp[0].minor.yy62->span);
}
#line 5885 "parse.c"
        break;
      case 192:
#line 532 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[0].minor.yy62, 0);
  pList = sqliteExprListAppend(pList, yymsp[-3].minor.yy62, 0);
  yygotominor.yy62 = sqliteExprFunction(pList, &yymsp[-1].minor.yy378);
  yygotominor.yy62 = sqliteExpr(TK_NOT, yygotominor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy62->span,&yymsp[0].minor.yy62->span);
}
#line 5896 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 193:
#line 539 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 5902 "parse.c"
        break;
      case 194:
#line 540 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 5907 "parse.c"
        break;
      case 195:
#line 541 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_PLUS, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5912 "parse.c"
        /* No destructor defined for PLUS */
        break;
      case 196:
#line 542 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_MINUS, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5918 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 197:
#line 543 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_STAR, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5924 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 198:
#line 544 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_SLASH, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5930 "parse.c"
        /* No destructor defined for SLASH */
        break;
      case 199:
#line 545 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_REM, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5936 "parse.c"
        /* No destructor defined for REM */
        break;
      case 200:
#line 546 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_CONCAT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5942 "parse.c"
        /* No destructor defined for CONCAT */
        break;
      case 201:
#line 547 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_ISNULL, yymsp[-1].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5951 "parse.c"
        break;
      case 202:
#line 551 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_ISNULL, yymsp[-2].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5959 "parse.c"
        /* No destructor defined for IS */
        break;
      case 203:
#line 555 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOTNULL, yymsp[-1].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5968 "parse.c"
        break;
      case 204:
#line 559 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOTNULL, yymsp[-2].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5976 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 205:
#line 563 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOTNULL, yymsp[-3].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5985 "parse.c"
        /* No destructor defined for IS */
        /* No destructor defined for NOT */
        break;
      case 206:
#line 567 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOT, yymsp[0].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 5995 "parse.c"
        break;
      case 207:
#line 571 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_BITNOT, yymsp[0].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 6003 "parse.c"
        break;
      case 208:
#line 575 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_UMINUS, yymsp[0].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 6011 "parse.c"
        break;
      case 209:
#line 579 "parse.y"
{
  yygotominor.yy62 = yymsp[0].minor.yy62;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 6019 "parse.c"
        break;
      case 210:
#line 583 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_SELECT, 0, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pSelect = yymsp[-1].minor.yy219;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);
}
#line 6028 "parse.c"
        break;
      case 211:
#line 588 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy62, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy62, 0);
  yygotominor.yy62 = sqliteExpr(TK_BETWEEN, yymsp[-4].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = pList;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-4].minor.yy62->span,&yymsp[0].minor.yy62->span);
}
#line 6039 "parse.c"
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 212:
#line 595 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy62, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy62, 0);
  yygotominor.yy62 = sqliteExpr(TK_BETWEEN, yymsp[-5].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = pList;
  yygotominor.yy62 = sqliteExpr(TK_NOT, yygotominor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-5].minor.yy62->span,&yymsp[0].minor.yy62->span);
}
#line 6053 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 213:
#line 603 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_IN, yymsp[-4].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = yymsp[-1].minor.yy228;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-4].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 6065 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 214:
#line 608 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_IN, yymsp[-4].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pSelect = yymsp[-1].minor.yy219;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-4].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 6076 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 215:
#line 613 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_IN, yymsp[-5].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = yymsp[-1].minor.yy228;
  yygotominor.yy62 = sqliteExpr(TK_NOT, yygotominor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-5].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 6088 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 216:
#line 619 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_IN, yymsp[-5].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pSelect = yymsp[-1].minor.yy219;
  yygotominor.yy62 = sqliteExpr(TK_NOT, yygotominor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-5].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 6101 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 217:
#line 627 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_CASE, yymsp[-3].minor.yy62, yymsp[-1].minor.yy62, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = yymsp[-2].minor.yy228;
  sqliteExprSpan(yygotominor.yy62, &yymsp[-4].minor.yy0, &yymsp[0].minor.yy0);
}
#line 6113 "parse.c"
        break;
      case 218:
#line 634 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-4].minor.yy228, yymsp[-2].minor.yy62, 0);
  yygotominor.yy228 = sqliteExprListAppend(yygotominor.yy228, yymsp[0].minor.yy62, 0);
}
#line 6121 "parse.c"
        /* No destructor defined for WHEN */
        /* No destructor defined for THEN */
        break;
      case 219:
#line 638 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(0, yymsp[-2].minor.yy62, 0);
  yygotominor.yy228 = sqliteExprListAppend(yygotominor.yy228, yymsp[0].minor.yy62, 0);
}
#line 6131 "parse.c"
        /* No destructor defined for WHEN */
        /* No destructor defined for THEN */
        break;
      case 220:
#line 643 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 6138 "parse.c"
        /* No destructor defined for ELSE */
        break;
      case 221:
#line 644 "parse.y"
{yygotominor.yy62 = 0;}
#line 6144 "parse.c"
        break;
      case 222:
#line 646 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 6149 "parse.c"
        break;
      case 223:
#line 647 "parse.y"
{yygotominor.yy62 = 0;}
#line 6154 "parse.c"
        break;
      case 224:
#line 655 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(yymsp[-2].minor.yy228,yymsp[0].minor.yy62,0);}
#line 6159 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 225:
#line 656 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(0,yymsp[0].minor.yy62,0);}
#line 6165 "parse.c"
        break;
      case 226:
#line 657 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 6170 "parse.c"
        break;
      case 227:
#line 658 "parse.y"
{yygotominor.yy62 = 0;}
#line 6175 "parse.c"
        break;
      case 228:
#line 663 "parse.y"
{
  if( yymsp[-8].minor.yy172!=OE_None ) yymsp[-8].minor.yy172 = yymsp[0].minor.yy172;
  if( yymsp[-8].minor.yy172==OE_Default) yymsp[-8].minor.yy172 = OE_Abort;
  sqliteCreateIndex(pParse, &yymsp[-6].minor.yy378, &yymsp[-4].minor.yy378, yymsp[-2].minor.yy250, yymsp[-8].minor.yy172, &yymsp[-9].minor.yy0, &yymsp[-1].minor.yy0);
}
#line 6184 "parse.c"
        /* No destructor defined for INDEX */
        /* No destructor defined for ON */
        /* No destructor defined for LP */
        break;
      case 229:
#line 670 "parse.y"
{ yygotominor.yy172 = OE_Abort; }
#line 6192 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 230:
#line 671 "parse.y"
{ yygotominor.yy172 = OE_None; }
#line 6198 "parse.c"
        break;
      case 231:
#line 678 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(yymsp[-2].minor.yy250,&yymsp[0].minor.yy378);}
#line 6203 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 232:
#line 680 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(0,&yymsp[0].minor.yy378);}
#line 6209 "parse.c"
        break;
      case 233:
#line 681 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 6214 "parse.c"
        break;
      case 234:
#line 686 "parse.y"
{sqliteDropIndex(pParse, &yymsp[0].minor.yy378);}
#line 6219 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for INDEX */
        break;
      case 235:
#line 692 "parse.y"
{sqliteCopy(pParse,&yymsp[-5].minor.yy378,&yymsp[-3].minor.yy378,&yymsp[0].minor.yy0,yymsp[-6].minor.yy172);}
#line 6226 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        /* No destructor defined for USING */
        /* No destructor defined for DELIMITERS */
        break;
      case 236:
#line 694 "parse.y"
{sqliteCopy(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,0,yymsp[-3].minor.yy172);}
#line 6235 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        break;
      case 237:
#line 698 "parse.y"
{sqliteVacuum(pParse,0);}
#line 6242 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 238:
#line 699 "parse.y"
{sqliteVacuum(pParse,&yymsp[0].minor.yy378);}
#line 6248 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 239:
#line 703 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,0);}
#line 6254 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 240:
#line 704 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy0,0);}
#line 6261 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 241:
#line 705 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,0);}
#line 6268 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 242:
#line 706 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,1);}
#line 6275 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 243:
#line 707 "parse.y"
{sqlitePragma(pParse,&yymsp[-3].minor.yy378,&yymsp[-1].minor.yy378,0);}
#line 6282 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 244:
#line 708 "parse.y"
{sqlitePragma(pParse,&yymsp[0].minor.yy378,&yymsp[0].minor.yy378,0);}
#line 6290 "parse.c"
        /* No destructor defined for PRAGMA */
        break;
      case 245:
#line 709 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 6296 "parse.c"
        /* No destructor defined for plus_opt */
        break;
      case 246:
#line 710 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 6302 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 247:
#line 711 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 6308 "parse.c"
        break;
      case 248:
#line 712 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 6313 "parse.c"
        break;
      case 249:
        /* No destructor defined for PLUS */
        break;
      case 250:
        break;
      case 251:
#line 719 "parse.y"
{
  sqliteCreateTrigger(pParse, &yymsp[-9].minor.yy378, yymsp[-8].minor.yy172, yymsp[-7].minor.yy90.a, yymsp[-7].minor.yy90.b, &yymsp[-5].minor.yy378, yymsp[-4].minor.yy172, yymsp[-3].minor.yy308, yymsp[-1].minor.yy311, 
      yymsp[-11].minor.yy0.z, (int)(yymsp[0].minor.yy0.z - yymsp[-11].minor.yy0.z) + yymsp[0].minor.yy0.n );
}
#line 6326 "parse.c"
        /* No destructor defined for TRIGGER */
        /* No destructor defined for ON */
        /* No destructor defined for BEGIN */
        break;
      case 252:
#line 725 "parse.y"
{ yygotominor.yy172 = TK_BEFORE; }
#line 6334 "parse.c"
        /* No destructor defined for BEFORE */
        break;
      case 253:
#line 726 "parse.y"
{ yygotominor.yy172 = TK_AFTER;  }
#line 6340 "parse.c"
        /* No destructor defined for AFTER */
        break;
      case 254:
#line 727 "parse.y"
{ yygotominor.yy172 = TK_INSTEAD;}
#line 6346 "parse.c"
        /* No destructor defined for INSTEAD */
        /* No destructor defined for OF */
        break;
      case 255:
#line 728 "parse.y"
{ yygotominor.yy172 = TK_BEFORE; }
#line 6353 "parse.c"
        break;
      case 256:
#line 732 "parse.y"
{ yygotominor.yy90.a = TK_DELETE; yygotominor.yy90.b = 0; }
#line 6358 "parse.c"
        /* No destructor defined for DELETE */
        break;
      case 257:
#line 733 "parse.y"
{ yygotominor.yy90.a = TK_INSERT; yygotominor.yy90.b = 0; }
#line 6364 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 258:
#line 734 "parse.y"
{ yygotominor.yy90.a = TK_UPDATE; yygotominor.yy90.b = 0;}
#line 6370 "parse.c"
        /* No destructor defined for UPDATE */
        break;
      case 259:
#line 735 "parse.y"
{yygotominor.yy90.a = TK_UPDATE; yygotominor.yy90.b = yymsp[0].minor.yy250; }
#line 6376 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for OF */
        break;
      case 260:
#line 738 "parse.y"
{ yygotominor.yy172 = TK_ROW; }
#line 6383 "parse.c"
        break;
      case 261:
#line 739 "parse.y"
{ yygotominor.yy172 = TK_ROW; }
#line 6388 "parse.c"
        /* No destructor defined for FOR */
        /* No destructor defined for EACH */
        /* No destructor defined for ROW */
        break;
      case 262:
#line 740 "parse.y"
{ yygotominor.yy172 = TK_STATEMENT; }
#line 6396 "parse.c"
        /* No destructor defined for FOR */
        /* No destructor defined for EACH */
        /* No destructor defined for STATEMENT */
        break;
      case 263:
#line 743 "parse.y"
{ yygotominor.yy308 = 0; }
#line 6404 "parse.c"
        break;
      case 264:
#line 744 "parse.y"
{ yygotominor.yy308 = yymsp[0].minor.yy62; }
#line 6409 "parse.c"
        /* No destructor defined for WHEN */
        break;
      case 265:
#line 747 "parse.y"
{
  yymsp[-2].minor.yy311->pNext = yymsp[0].minor.yy311 ; yygotominor.yy311 = yymsp[-2].minor.yy311; }
#line 6416 "parse.c"
        /* No destructor defined for SEMI */
        break;
      case 266:
#line 749 "parse.y"
{ yygotominor.yy311 = 0; }
#line 6422 "parse.c"
        break;
      case 267:
#line 754 "parse.y"
{ yygotominor.yy311 = sqliteTriggerUpdateStep(&yymsp[-3].minor.yy378, yymsp[-1].minor.yy228, yymsp[0].minor.yy62, yymsp[-4].minor.yy172); }
#line 6427 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 268:
#line 759 "parse.y"
{yygotominor.yy311 = sqliteTriggerInsertStep(&yymsp[-5].minor.yy378, yymsp[-4].minor.yy250, yymsp[-1].minor.yy228, 0, yymsp[-7].minor.yy172);}
#line 6434 "parse.c"
        /* No destructor defined for INSERT */
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 269:
#line 762 "parse.y"
{yygotominor.yy311 = sqliteTriggerInsertStep(&yymsp[-2].minor.yy378, yymsp[-1].minor.yy250, 0, yymsp[0].minor.yy219, yymsp[-4].minor.yy172);}
#line 6444 "parse.c"
        /* No destructor defined for INSERT */
        /* No destructor defined for INTO */
        break;
      case 270:
#line 766 "parse.y"
{yygotominor.yy311 = sqliteTriggerDeleteStep(&yymsp[-1].minor.yy378, yymsp[0].minor.yy62);}
#line 6451 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 271:
#line 769 "parse.y"
{yygotominor.yy311 = sqliteTriggerSelectStep(yymsp[0].minor.yy219); }
#line 6458 "parse.c"
        break;
      case 272:
#line 772 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, 0); 
    yygotominor.yy62->iColumn = OE_Ignore; sqliteExprSpan(yygotominor.yy62, &yymsp[-3].minor.yy0, &yymsp[0].minor.yy0);}
#line 6464 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for IGNORE */
        break;
      case 273:
#line 775 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy378); 
    yygotominor.yy62->iColumn = OE_Rollback; sqliteExprSpan(yygotominor.yy62, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);}
#line 6472 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for ROLLBACK */
        /* No destructor defined for COMMA */
        break;
      case 274:
#line 778 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy378); 
    yygotominor.yy62->iColumn = OE_Abort; sqliteExprSpan(yygotominor.yy62, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);}
#line 6481 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for ABORT */
        /* No destructor defined for COMMA */
        break;
      case 275:
#line 781 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy378); 
    yygotominor.yy62->iColumn = OE_Fail; sqliteExprSpan(yygotominor.yy62, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);}
#line 6490 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for FAIL */
        /* No destructor defined for COMMA */
        break;
      case 276:
#line 785 "parse.y"
{
    sqliteDropTrigger(pParse,&yymsp[0].minor.yy378,0);
}
#line 6500 "parse.c"
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

#line 6550 "parse.c"
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
