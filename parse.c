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
#define YYNOCODE 213
#define YYACTIONTYPE unsigned short int
#define sqliteParserTOKENTYPE Token
typedef union {
  sqliteParserTOKENTYPE yy0;
  Token yy58;
  Select* yy91;
  struct {int value; int mask;} yy99;
  TriggerStep * yy111;
  struct TrigEvent yy146;
  IdList* yy154;
  Expr* yy202;
  ExprList* yy256;
  int yy276;
  SrcList* yy395;
  struct LimitVal yy406;
  Expr * yy412;
  int yy425;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define sqliteParserARG_SDECL Parse *pParse;
#define sqliteParserARG_PDECL ,Parse *pParse
#define sqliteParserARG_FETCH Parse *pParse = yypParser->pParse
#define sqliteParserARG_STORE yypParser->pParse = pParse
#define YYNSTATE 530
#define YYNRULE 279
#define YYERRORSYMBOL 149
#define YYERRSYMDT yy425
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
  { 150,   0,   3}, /*  1:                explain shift  3 */
  { 104,   4, 527}, /*  2:                   SEMI shift  527 */
  { 164,   2, 810}, /*  3:                  input accept */
  {  44,   0, 528}, /*  4:                EXPLAIN shift  528 */
  { 148,   6, 529}, /*  5:                   ecmd shift  529 */
  { 136,   0,   1}, /*  6:                cmdlist shift  1 */
/* State 1 */
  { 150,   2,   3}, /*  1:                explain shift  3 */
  {   0,   0, 530}, /*  2:                      $ reduce 0 */
  {  44,   0, 528}, /*  3:                EXPLAIN shift  528 */
  { 148,   0,   2}, /*  4:                   ecmd shift  2 */
  { 104,   3, 527}, /*  5:                   SEMI shift  527 */
/* State 3 */
  {  97,   4, 499}, /*  1:                REPLACE shift  499 */
  { 191,   0, 477}, /*  2:                 select shift  477 */
  { 135,   1,   4}, /*  3:                    cmd shift  4 */
  {  40,   0,  24}, /*  4:                    END shift  24 */
  {  99,   6,  26}, /*  5:               ROLLBACK shift  26 */
  {  23,   0,  22}, /*  6:                 COMMIT shift  22 */
  { 120,   8, 482}, /*  7:                 UPDATE shift  482 */
  {  63,   0, 497}, /*  8:                 INSERT shift  497 */
  { 103,  12,  72}, /*  9:                 SELECT shift  72 */
  { 180,  13,  68}, /* 10:              oneselect shift  68 */
  { 143,   0,  28}, /* 11:           create_table shift  28 */
  {  27,   0, 500}, /* 12:                   COPY shift  500 */
  { 123,  15, 508}, /* 13:                 VACUUM shift  508 */
  {  32,   0, 478}, /* 14:                 DELETE shift  478 */
  {  28,  18, 381}, /* 15:                 CREATE shift  381 */
  { 167,   0, 488}, /* 16:             insert_cmd shift  488 */
  {  92,   0, 510}, /* 17:                 PRAGMA shift  510 */
  {   9,   0,   6}, /* 18:                  BEGIN shift  6 */
  {  37,   0, 468}, /* 19:                   DROP shift  468 */
/* State 4 */
  { 104,   0,   5}, /*  1:                   SEMI shift  5 */
/* State 6 */
  { 114,   0,  17}, /*  1:            TRANSACTION shift  17 */
  { 201,   0,   7}, /*  2:              trans_opt shift  7 */
/* State 7 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 104,   0, 617}, /*  2:                   SEMI reduce 87 */
  { 179,   2,   8}, /*  3:                 onconf shift  8 */
/* State 8 */
  { 104,   0, 537}, /*  1:                   SEMI reduce 7 */
/* State 9 */
  {  25,   0,  10}, /*  1:               CONFLICT shift  10 */
/* State 10 */
  {   1,   0,  13}, /*  1:                  ABORT shift  13 */
  {  97,   1,  16}, /*  2:                REPLACE shift  16 */
  { 188,   0,  11}, /*  3:            resolvetype shift  11 */
  {  99,   5,  12}, /*  4:               ROLLBACK shift  12 */
  {  57,   6,  15}, /*  5:                 IGNORE shift  15 */
  {  45,   0,  14}, /*  6:                   FAIL shift  14 */
/* State 17 */
  { 176,   2,  18}, /*  1:                     nm shift  18 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 22 */
  { 201,   2,  23}, /*  1:              trans_opt shift  23 */
  { 114,   0,  17}, /*  2:            TRANSACTION shift  17 */
  { 104,   0, 538}, /*  3:                   SEMI reduce 8 */
/* State 23 */
  { 104,   0, 541}, /*  1:                   SEMI reduce 11 */
/* State 24 */
  { 201,   2,  25}, /*  1:              trans_opt shift  25 */
  { 114,   0,  17}, /*  2:            TRANSACTION shift  17 */
  { 104,   0, 538}, /*  3:                   SEMI reduce 8 */
/* State 25 */
  { 104,   0, 542}, /*  1:                   SEMI reduce 12 */
/* State 26 */
  { 201,   2,  27}, /*  1:              trans_opt shift  27 */
  { 114,   0,  17}, /*  2:            TRANSACTION shift  17 */
  { 104,   0, 538}, /*  3:                   SEMI reduce 8 */
/* State 27 */
  { 104,   0, 543}, /*  1:                   SEMI reduce 13 */
/* State 28 */
  { 144,   3,  29}, /*  1:      create_table_args shift  29 */
  {  76,   0,  30}, /*  2:                     LP shift  30 */
  {   6,   0, 379}, /*  3:                     AS shift  379 */
/* State 29 */
  { 104,   0, 544}, /*  1:                   SEMI reduce 14 */
/* State 30 */
  { 140,   3,  31}, /*  1:             columnlist shift  31 */
  { 176,   4, 344}, /*  2:                     nm shift  344 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
  { 110,   0,  20}, /*  5:                 STRING shift  20 */
  { 138,   5, 378}, /*  6:                 column shift  378 */
  { 139,   0,  36}, /*  7:               columnid shift  36 */
/* State 31 */
  {  21,   0,  34}, /*  1:                  COMMA shift  34 */
  { 142,   0,  32}, /*  2:           conslist_opt shift  32 */
  { 101,   0, 605}, /*  3:                     RP reduce 75 */
/* State 32 */
  { 101,   0,  33}, /*  1:                     RP shift  33 */
/* State 33 */
  { 104,   0, 548}, /*  1:                   SEMI reduce 18 */
/* State 34 */
  {  26,   0, 348}, /*  1:             CONSTRAINT shift  348 */
  {  93,   0, 350}, /*  2:                PRIMARY shift  350 */
  { 119,   2, 356}, /*  3:                 UNIQUE shift  356 */
  {  56,   6,  19}, /*  4:                     ID shift  19 */
  { 199,   4, 377}, /*  5:                  tcons shift  377 */
  {  17,   0, 361}, /*  6:                  CHECK shift  361 */
  { 110,  11,  20}, /*  7:                 STRING shift  20 */
  { 176,   0, 344}, /*  8:                     nm shift  344 */
  { 138,   0,  35}, /*  9:                 column shift  35 */
  { 139,  13,  36}, /* 10:               columnid shift  36 */
  {  71,   0,  21}, /* 11:                JOIN_KW shift  21 */
  { 141,   0, 345}, /* 12:               conslist shift  345 */
  {  48,   0, 364}, /* 13:                FOREIGN shift  364 */
/* State 36 */
  { 110,   0, 248}, /*  1:                 STRING shift  248 */
  { 206,   4,  37}, /*  2:                   type shift  37 */
  { 207,   0, 330}, /*  3:               typename shift  330 */
  {  56,   0, 247}, /*  4:                     ID shift  247 */
  { 159,   0, 343}, /*  5:                    ids shift  343 */
/* State 37 */
  { 130,   0,  38}, /*  1:               carglist shift  38 */
/* State 38 */
  {  26,   0,  40}, /*  1:             CONSTRAINT shift  40 */
  { 119,   6,  59}, /*  2:                 UNIQUE shift  59 */
  { 145,   2, 312}, /*  3:        defer_subclause shift  312 */
  {  29,   0, 318}, /*  4:                DEFAULT shift  318 */
  { 134,   8, 317}, /*  5:                  ccons shift  317 */
  {  93,   0,  53}, /*  6:                PRIMARY shift  53 */
  {  84,   9,  43}, /*  7:                   NULL shift  43 */
  {  95,  10, 290}, /*  8:             REFERENCES shift  290 */
  {  19,   0, 313}, /*  9:                COLLATE shift  313 */
  {  82,  11,  45}, /* 10:                    NOT shift  45 */
  {  30,  12, 315}, /* 11:             DEFERRABLE shift  315 */
  {  17,   0,  61}, /* 12:                  CHECK shift  61 */
  { 129,   0,  39}, /* 13:                   carg shift  39 */
/* State 40 */
  { 176,   2,  41}, /*  1:                     nm shift  41 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 41 */
  {  30,   0, 315}, /*  1:             DEFERRABLE shift  315 */
  {  84,   0,  43}, /*  2:                   NULL shift  43 */
  {  82,   0,  45}, /*  3:                    NOT shift  45 */
  {  93,   0,  53}, /*  4:                PRIMARY shift  53 */
  { 134,   2,  42}, /*  5:                  ccons shift  42 */
  { 145,   7, 312}, /*  6:        defer_subclause shift  312 */
  {  95,   0, 290}, /*  7:             REFERENCES shift  290 */
  {  17,   0,  61}, /*  8:                  CHECK shift  61 */
  {  19,   0, 313}, /*  9:                COLLATE shift  313 */
  { 119,   9,  59}, /* 10:                 UNIQUE shift  59 */
/* State 43 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 179,   1,  44}, /*  2:                 onconf shift  44 */
/* State 45 */
  {  84,   2,  46}, /*  1:                   NULL shift  46 */
  {  30,   0,  48}, /*  2:             DEFERRABLE shift  48 */
/* State 46 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 179,   1,  47}, /*  2:                 onconf shift  47 */
/* State 48 */
  {  62,   0,  50}, /*  1:              INITIALLY shift  50 */
  { 163,   0,  49}, /*  2: init_deferred_pred_opt shift  49 */
/* State 50 */
  {  31,   0,  51}, /*  1:               DEFERRED shift  51 */
  {  59,   1,  52}, /*  2:              IMMEDIATE shift  52 */
/* State 53 */
  {  72,   0,  54}, /*  1:                    KEY shift  54 */
/* State 54 */
  {   7,   0,  57}, /*  1:                    ASC shift  57 */
  {  34,   1,  58}, /*  2:                   DESC shift  58 */
  { 197,   0,  55}, /*  3:              sortorder shift  55 */
/* State 55 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 179,   1,  56}, /*  2:                 onconf shift  56 */
/* State 59 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 179,   1,  60}, /*  2:                 onconf shift  60 */
/* State 61 */
  {  76,   0,  62}, /*  1:                     LP shift  62 */
/* State 62 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 287}, /*  2:                   expr shift  287 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 63 */
  {  76,   2,  64}, /*  1:                     LP shift  64 */
  {  36,   0, 557}, /*  2:                    DOT reduce 27 */
/* State 64 */
  { 108,   0, 285}, /*  1:                   STAR shift  285 */
  {  91,   0, 173}, /*  2:                   PLUS shift  173 */
  { 110,   4,  65}, /*  3:                 STRING shift  65 */
  {  56,   0,  63}, /*  4:                     ID shift  63 */
  {  94,   6, 185}, /*  5:                  RAISE shift  185 */
  {  76,   0,  67}, /*  6:                     LP shift  67 */
  {  80,   0, 171}, /*  7:                  MINUS shift  171 */
  { 151,   0, 164}, /*  8:                   expr shift  164 */
  { 152,   7, 211}, /*  9:               expritem shift  211 */
  { 153,   0, 283}, /* 10:               exprlist shift  283 */
  {  82,  14, 167}, /* 11:                    NOT shift  167 */
  {  65,   0, 165}, /* 12:                INTEGER shift  165 */
  {  84,  16, 100}, /* 13:                   NULL shift  100 */
  {  46,   0, 166}, /* 14:                  FLOAT shift  166 */
  { 176,   0, 101}, /* 15:                     nm shift  101 */
  {  12,   0, 169}, /* 16:                 BITNOT shift  169 */
  {  16,   0, 175}, /* 17:                   CASE shift  175 */
  {  71,   0,  66}, /* 18:                JOIN_KW shift  66 */
/* State 65 */
  {  36,   0, 558}, /*  1:                    DOT reduce 28 */
/* State 66 */
  {  36,   0, 559}, /*  1:                    DOT reduce 29 */
/* State 67 */
  { 180,   0,  68}, /*  1:              oneselect shift  68 */
  {  91,   0, 173}, /*  2:                   PLUS shift  173 */
  { 110,   4,  65}, /*  3:                 STRING shift  65 */
  {  56,   0,  63}, /*  4:                     ID shift  63 */
  {  94,   6, 185}, /*  5:                  RAISE shift  185 */
  {  76,   0,  67}, /*  6:                     LP shift  67 */
  {  46,   0, 166}, /*  7:                  FLOAT shift  166 */
  { 151,   0, 281}, /*  8:                   expr shift  281 */
  {  80,   0, 171}, /*  9:                  MINUS shift  171 */
  {  65,   0, 165}, /* 10:                INTEGER shift  165 */
  {  82,   7, 167}, /* 11:                    NOT shift  167 */
  { 191,  10,  69}, /* 12:                 select shift  69 */
  {  84,  16, 100}, /* 13:                   NULL shift  100 */
  { 103,   0,  72}, /* 14:                 SELECT shift  72 */
  { 176,   0, 101}, /* 15:                     nm shift  101 */
  {  12,   0, 169}, /* 16:                 BITNOT shift  169 */
  {  16,   0, 175}, /* 17:                   CASE shift  175 */
  {  71,   0,  66}, /* 18:                JOIN_KW shift  66 */
/* State 69 */
  { 175,   0,  70}, /*  1:         multiselect_op shift  70 */
  { 101,   3, 280}, /*  2:                     RP shift  280 */
  {  66,   0, 161}, /*  3:              INTERSECT shift  161 */
  { 118,   5, 159}, /*  4:                  UNION shift  159 */
  {  43,   0, 162}, /*  5:                 EXCEPT shift  162 */
/* State 70 */
  { 180,   0,  71}, /*  1:              oneselect shift  71 */
  { 103,   0,  72}, /*  2:                 SELECT shift  72 */
/* State 72 */
  { 147,   0,  73}, /*  1:               distinct shift  73 */
  {   4,   0, 279}, /*  2:                    ALL shift  279 */
  {  35,   0, 278}, /*  3:               DISTINCT shift  278 */
/* State 73 */
  { 190,   0,  74}, /*  1:             selcollist shift  74 */
  { 189,   0, 271}, /*  2:                   sclp shift  271 */
/* State 74 */
  {  21,   0, 233}, /*  1:                  COMMA shift  233 */
  {  49,   0, 234}, /*  2:                   FROM shift  234 */
  { 155,   0,  75}, /*  3:                   from shift  75 */
/* State 75 */
  { 127,   0, 231}, /*  1:                  WHERE shift  231 */
  { 211,   1,  76}, /*  2:              where_opt shift  76 */
/* State 76 */
  { 156,   0,  77}, /*  1:            groupby_opt shift  77 */
  {  53,   0, 228}, /*  2:                  GROUP shift  228 */
/* State 77 */
  {  55,   0, 226}, /*  1:                 HAVING shift  226 */
  { 157,   1,  78}, /*  2:             having_opt shift  78 */
/* State 78 */
  { 182,   2,  79}, /*  1:            orderby_opt shift  79 */
  {  90,   0,  87}, /*  2:                  ORDER shift  87 */
/* State 79 */
  { 172,   0,  80}, /*  1:              limit_opt shift  80 */
  {  75,   0,  81}, /*  2:                  LIMIT shift  81 */
/* State 81 */
  {  65,   0,  82}, /*  1:                INTEGER shift  82 */
/* State 82 */
  {  21,   0,  86}, /*  1:                  COMMA shift  86 */
  {  86,   0,  85}, /*  2:                 OFFSET shift  85 */
  { 173,   2,  83}, /*  3:              limit_sep shift  83 */
/* State 83 */
  {  65,   0,  84}, /*  1:                INTEGER shift  84 */
/* State 85 */
  {  65,   0, 680}, /*  1:                INTEGER reduce 150 */
/* State 86 */
  {  65,   0, 681}, /*  1:                INTEGER reduce 151 */
/* State 87 */
  {  14,   0,  88}, /*  1:                     BY shift  88 */
/* State 88 */
  {  91,   0, 173}, /*  1:                   PLUS shift  173 */
  { 110,   3,  65}, /*  2:                 STRING shift  65 */
  {  76,   0,  67}, /*  3:                     LP shift  67 */
  {  71,   0,  66}, /*  4:                JOIN_KW shift  66 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  {  56,   0,  63}, /*  6:                     ID shift  63 */
  { 176,   1, 101}, /*  7:                     nm shift  101 */
  {  46,  11, 166}, /*  8:                  FLOAT shift  166 */
  { 195,   2, 223}, /*  9:               sortitem shift  223 */
  { 196,   5,  89}, /* 10:               sortlist shift  89 */
  {  12,   0, 169}, /* 11:                 BITNOT shift  169 */
  {  65,   0, 165}, /* 12:                INTEGER shift  165 */
  {  80,   8, 171}, /* 13:                  MINUS shift  171 */
  {  16,   0, 175}, /* 14:                   CASE shift  175 */
  {  82,  12, 167}, /* 15:                    NOT shift  167 */
  { 151,   0,  97}, /* 16:                   expr shift  97 */
  {  84,  14, 100}, /* 17:                   NULL shift  100 */
/* State 89 */
  {  21,   0,  90}, /*  1:                  COMMA shift  90 */
/* State 90 */
  { 176,   6, 101}, /*  1:                     nm shift  101 */
  {  65,   0, 165}, /*  2:                INTEGER shift  165 */
  {  82,   0, 167}, /*  3:                    NOT shift  167 */
  { 195,   0,  91}, /*  4:               sortitem shift  91 */
  {  84,   0, 100}, /*  5:                   NULL shift  100 */
  {  80,   7, 171}, /*  6:                  MINUS shift  171 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  { 151,  10,  97}, /*  8:                   expr shift  97 */
  {  56,   0,  63}, /*  9:                     ID shift  63 */
  {  71,   0,  66}, /* 10:                JOIN_KW shift  66 */
  {  12,   0, 169}, /* 11:                 BITNOT shift  169 */
  {  91,   0, 173}, /* 12:                   PLUS shift  173 */
  {  76,  11,  67}, /* 13:                     LP shift  67 */
  {  94,  16, 185}, /* 14:                  RAISE shift  185 */
  { 110,  14,  65}, /* 15:                 STRING shift  65 */
  {  46,   0, 166}, /* 16:                  FLOAT shift  166 */
/* State 91 */
  {  19,   0,  94}, /*  1:                COLLATE shift  94 */
  { 137,   1,  92}, /*  2:                collate shift  92 */
/* State 92 */
  {   7,   0,  57}, /*  1:                    ASC shift  57 */
  {  34,   1,  58}, /*  2:                   DESC shift  58 */
  { 197,   0,  93}, /*  3:              sortorder shift  93 */
/* State 94 */
  { 158,   2,  96}, /*  1:                     id shift  96 */
  {  56,   0,  95}, /*  2:                     ID shift  95 */
/* State 97 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {   5,   0,  99}, /*  2:                    AND shift  99 */
  {  68,   0, 147}, /*  3:                     IS shift  147 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  88,   1, 105}, /*  5:                     OR shift  105 */
  {  89,   2,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  {  13,   0, 121}, /*  7:                  BITOR shift  121 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  74,   0, 132}, /*  9:                   LIKE shift  132 */
  {  78,   0, 107}, /* 10:                     LT shift  107 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  {  96,   3, 142}, /* 13:                    REM shift  142 */
  {  69,   7, 146}, /* 14:                 ISNULL shift  146 */
  {  42,   0, 117}, /* 15:                     EQ shift  117 */
  {  80,  17, 136}, /* 16:                  MINUS shift  136 */
  {  52,  20, 133}, /* 17:                   GLOB shift  133 */
  {  73,   0, 111}, /* 18:                     LE shift  111 */
  { 102,   9, 125}, /* 19:                 RSHIFT shift  125 */
  {  24,   0, 144}, /* 20:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 21:                     GT shift  109 */
  {  77,   0, 123}, /* 22:                 LSHIFT shift  123 */
  { 106,  10, 140}, /* 23:                  SLASH shift  140 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 108,  16, 138}, /* 25:                   STAR shift  138 */
  {  81,   0, 115}, /* 26:                     NE shift  115 */
  {  82,  21, 129}, /* 27:                    NOT shift  129 */
  {  83,   0, 151}, /* 28:                NOTNULL shift  151 */
/* State 99 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 104}, /*  2:                   expr shift  104 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 101 */
  {  36,   0, 102}, /*  1:                    DOT shift  102 */
/* State 102 */
  { 176,   2, 103}, /*  1:                     nm shift  103 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 104 */
  {  78,   2, 107}, /*  1:                     LT shift  107 */
  {  52,   0, 133}, /*  2:                   GLOB shift  133 */
  { 106,   7, 140}, /*  3:                  SLASH shift  140 */
  {  81,   0, 115}, /*  4:                     NE shift  115 */
  { 108,   8, 138}, /*  5:                   STAR shift  138 */
  {  83,   0, 151}, /*  6:                NOTNULL shift  151 */
  {  80,  10, 136}, /*  7:                  MINUS shift  136 */
  {  82,   0, 129}, /*  8:                    NOT shift  129 */
  {  60,   0, 156}, /*  9:                     IN shift  156 */
  {  54,   0, 109}, /* 10:                     GT shift  109 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  89,  13,  98}, /* 12:      ORACLE_OUTER_JOIN shift  98 */
  {  11,   0, 119}, /* 13:                 BITAND shift  119 */
  {  91,  15, 134}, /* 14:                   PLUS shift  134 */
  {  13,   0, 121}, /* 15:                  BITOR shift  121 */
  { 171,   0, 127}, /* 16:                 likeop shift  127 */
  {  68,  20, 147}, /* 17:                     IS shift  147 */
  {  69,   0, 146}, /* 18:                 ISNULL shift  146 */
  {  96,   0, 142}, /* 19:                    REM shift  142 */
  {  42,   0, 117}, /* 20:                     EQ shift  117 */
  {  24,   0, 144}, /* 21:                 CONCAT shift  144 */
  {  73,   0, 111}, /* 22:                     LE shift  111 */
  {  74,   0, 132}, /* 23:                   LIKE shift  132 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 102,  21, 125}, /* 25:                 RSHIFT shift  125 */
  {  77,  24, 123}, /* 26:                 LSHIFT shift  123 */
/* State 105 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 106}, /*  2:                   expr shift  106 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 106 */
  { 108,   4, 138}, /*  1:                   STAR shift  138 */
  {  82,   0, 129}, /*  2:                    NOT shift  129 */
  {  83,   0, 151}, /*  3:                NOTNULL shift  151 */
  {  81,   5, 115}, /*  4:                     NE shift  115 */
  {  54,   0, 109}, /*  5:                     GT shift  109 */
  {   5,   0,  99}, /*  6:                    AND shift  99 */
  {  60,   0, 156}, /*  7:                     IN shift  156 */
  {  10,   0, 152}, /*  8:                BETWEEN shift  152 */
  {  89,   0,  98}, /*  9:      ORACLE_OUTER_JOIN shift  98 */
  { 171,   0, 127}, /* 10:                 likeop shift  127 */
  {  91,   8, 134}, /* 11:                   PLUS shift  134 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  {  69,  17, 146}, /* 13:                 ISNULL shift  146 */
  {  13,   0, 121}, /* 14:                  BITOR shift  121 */
  {  68,   0, 147}, /* 15:                     IS shift  147 */
  {  96,  13, 142}, /* 16:                    REM shift  142 */
  {  42,   0, 117}, /* 17:                     EQ shift  117 */
  {  51,  19, 113}, /* 18:                     GE shift  113 */
  {  24,   0, 144}, /* 19:                 CONCAT shift  144 */
  {  73,   0, 111}, /* 20:                     LE shift  111 */
  {  74,   0, 132}, /* 21:                   LIKE shift  132 */
  { 102,   0, 125}, /* 22:                 RSHIFT shift  125 */
  {  52,   0, 133}, /* 23:                   GLOB shift  133 */
  {  77,   0, 123}, /* 24:                 LSHIFT shift  123 */
  {  78,  18, 107}, /* 25:                     LT shift  107 */
  { 106,  23, 140}, /* 26:                  SLASH shift  140 */
  {  80,   0, 136}, /* 27:                  MINUS shift  136 */
/* State 107 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 108}, /*  2:                   expr shift  108 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 108 */
  { 108,   3, 138}, /*  1:                   STAR shift  138 */
  {  13,   0, 121}, /*  2:                  BITOR shift  121 */
  {  96,   5, 142}, /*  3:                    REM shift  142 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  24,   0, 144}, /*  5:                 CONCAT shift  144 */
  {  89,  10,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  { 102,   0, 125}, /*  7:                 RSHIFT shift  125 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  80,   0, 136}, /*  9:                  MINUS shift  136 */
  {  77,   0, 123}, /* 10:                 LSHIFT shift  123 */
  { 106,   0, 140}, /* 11:                  SLASH shift  140 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
/* State 109 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 110}, /*  2:                   expr shift  110 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 110 */
  { 108,   3, 138}, /*  1:                   STAR shift  138 */
  {  13,   0, 121}, /*  2:                  BITOR shift  121 */
  {  96,   5, 142}, /*  3:                    REM shift  142 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  24,   0, 144}, /*  5:                 CONCAT shift  144 */
  {  89,  10,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  { 102,   0, 125}, /*  7:                 RSHIFT shift  125 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  80,   0, 136}, /*  9:                  MINUS shift  136 */
  {  77,   0, 123}, /* 10:                 LSHIFT shift  123 */
  { 106,   0, 140}, /* 11:                  SLASH shift  140 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
/* State 111 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 112}, /*  2:                   expr shift  112 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 112 */
  { 108,   3, 138}, /*  1:                   STAR shift  138 */
  {  13,   0, 121}, /*  2:                  BITOR shift  121 */
  {  96,   5, 142}, /*  3:                    REM shift  142 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  24,   0, 144}, /*  5:                 CONCAT shift  144 */
  {  89,  10,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  { 102,   0, 125}, /*  7:                 RSHIFT shift  125 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  80,   0, 136}, /*  9:                  MINUS shift  136 */
  {  77,   0, 123}, /* 10:                 LSHIFT shift  123 */
  { 106,   0, 140}, /* 11:                  SLASH shift  140 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
/* State 113 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 114}, /*  2:                   expr shift  114 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 114 */
  { 108,   3, 138}, /*  1:                   STAR shift  138 */
  {  13,   0, 121}, /*  2:                  BITOR shift  121 */
  {  96,   5, 142}, /*  3:                    REM shift  142 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  24,   0, 144}, /*  5:                 CONCAT shift  144 */
  {  89,  10,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  { 102,   0, 125}, /*  7:                 RSHIFT shift  125 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  80,   0, 136}, /*  9:                  MINUS shift  136 */
  {  77,   0, 123}, /* 10:                 LSHIFT shift  123 */
  { 106,   0, 140}, /* 11:                  SLASH shift  140 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
/* State 115 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 116}, /*  2:                   expr shift  116 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 116 */
  {  96,   2, 142}, /*  1:                    REM shift  142 */
  {  80,   0, 136}, /*  2:                  MINUS shift  136 */
  {  54,   0, 109}, /*  3:                     GT shift  109 */
  {  51,   0, 113}, /*  4:                     GE shift  113 */
  {  73,   0, 111}, /*  5:                     LE shift  111 */
  {  91,   8, 134}, /*  6:                   PLUS shift  134 */
  { 102,   3, 125}, /*  7:                 RSHIFT shift  125 */
  {  11,   0, 119}, /*  8:                 BITAND shift  119 */
  {  24,   0, 144}, /*  9:                 CONCAT shift  144 */
  {  89,   5,  98}, /* 10:      ORACLE_OUTER_JOIN shift  98 */
  { 106,   0, 140}, /* 11:                  SLASH shift  140 */
  { 171,   6, 127}, /* 12:                 likeop shift  127 */
  { 108,   0, 138}, /* 13:                   STAR shift  138 */
  {  77,  16, 123}, /* 14:                 LSHIFT shift  123 */
  {  78,   0, 107}, /* 15:                     LT shift  107 */
  {  13,   0, 121}, /* 16:                  BITOR shift  121 */
/* State 117 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 118}, /*  2:                   expr shift  118 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 118 */
  {  96,   2, 142}, /*  1:                    REM shift  142 */
  {  80,   0, 136}, /*  2:                  MINUS shift  136 */
  {  54,   0, 109}, /*  3:                     GT shift  109 */
  {  51,   0, 113}, /*  4:                     GE shift  113 */
  {  73,   0, 111}, /*  5:                     LE shift  111 */
  {  91,   8, 134}, /*  6:                   PLUS shift  134 */
  { 102,   3, 125}, /*  7:                 RSHIFT shift  125 */
  {  11,   0, 119}, /*  8:                 BITAND shift  119 */
  {  24,   0, 144}, /*  9:                 CONCAT shift  144 */
  {  89,   5,  98}, /* 10:      ORACLE_OUTER_JOIN shift  98 */
  { 106,   0, 140}, /* 11:                  SLASH shift  140 */
  { 171,   6, 127}, /* 12:                 likeop shift  127 */
  { 108,   0, 138}, /* 13:                   STAR shift  138 */
  {  77,  16, 123}, /* 14:                 LSHIFT shift  123 */
  {  78,   0, 107}, /* 15:                     LT shift  107 */
  {  13,   0, 121}, /* 16:                  BITOR shift  121 */
/* State 119 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 120}, /*  2:                   expr shift  120 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 120 */
  {  96,   6, 142}, /*  1:                    REM shift  142 */
  {  89,   0,  98}, /*  2:      ORACLE_OUTER_JOIN shift  98 */
  { 106,   0, 140}, /*  3:                  SLASH shift  140 */
  { 171,   7, 127}, /*  4:                 likeop shift  127 */
  { 108,   0, 138}, /*  5:                   STAR shift  138 */
  {  80,   8, 136}, /*  6:                  MINUS shift  136 */
  {  91,   0, 134}, /*  7:                   PLUS shift  134 */
  {  24,   0, 144}, /*  8:                 CONCAT shift  144 */
/* State 121 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 122}, /*  2:                   expr shift  122 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 122 */
  {  96,   6, 142}, /*  1:                    REM shift  142 */
  {  89,   0,  98}, /*  2:      ORACLE_OUTER_JOIN shift  98 */
  { 106,   0, 140}, /*  3:                  SLASH shift  140 */
  { 171,   7, 127}, /*  4:                 likeop shift  127 */
  { 108,   0, 138}, /*  5:                   STAR shift  138 */
  {  80,   8, 136}, /*  6:                  MINUS shift  136 */
  {  91,   0, 134}, /*  7:                   PLUS shift  134 */
  {  24,   0, 144}, /*  8:                 CONCAT shift  144 */
/* State 123 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 124}, /*  2:                   expr shift  124 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 124 */
  {  96,   6, 142}, /*  1:                    REM shift  142 */
  {  89,   0,  98}, /*  2:      ORACLE_OUTER_JOIN shift  98 */
  { 106,   0, 140}, /*  3:                  SLASH shift  140 */
  { 171,   7, 127}, /*  4:                 likeop shift  127 */
  { 108,   0, 138}, /*  5:                   STAR shift  138 */
  {  80,   8, 136}, /*  6:                  MINUS shift  136 */
  {  91,   0, 134}, /*  7:                   PLUS shift  134 */
  {  24,   0, 144}, /*  8:                 CONCAT shift  144 */
/* State 125 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 126}, /*  2:                   expr shift  126 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 126 */
  {  96,   6, 142}, /*  1:                    REM shift  142 */
  {  89,   0,  98}, /*  2:      ORACLE_OUTER_JOIN shift  98 */
  { 106,   0, 140}, /*  3:                  SLASH shift  140 */
  { 171,   7, 127}, /*  4:                 likeop shift  127 */
  { 108,   0, 138}, /*  5:                   STAR shift  138 */
  {  80,   8, 136}, /*  6:                  MINUS shift  136 */
  {  91,   0, 134}, /*  7:                   PLUS shift  134 */
  {  24,   0, 144}, /*  8:                 CONCAT shift  144 */
/* State 127 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 128}, /*  2:                   expr shift  128 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 128 */
  {  96,   2, 142}, /*  1:                    REM shift  142 */
  {  80,   0, 136}, /*  2:                  MINUS shift  136 */
  {  54,   0, 109}, /*  3:                     GT shift  109 */
  {  51,   0, 113}, /*  4:                     GE shift  113 */
  {  73,   0, 111}, /*  5:                     LE shift  111 */
  {  91,   8, 134}, /*  6:                   PLUS shift  134 */
  { 102,   3, 125}, /*  7:                 RSHIFT shift  125 */
  {  11,   0, 119}, /*  8:                 BITAND shift  119 */
  {  24,   0, 144}, /*  9:                 CONCAT shift  144 */
  {  89,   5,  98}, /* 10:      ORACLE_OUTER_JOIN shift  98 */
  { 106,   0, 140}, /* 11:                  SLASH shift  140 */
  { 171,   6, 127}, /* 12:                 likeop shift  127 */
  { 108,   0, 138}, /* 13:                   STAR shift  138 */
  {  77,  16, 123}, /* 14:                 LSHIFT shift  123 */
  {  78,   0, 107}, /* 15:                     LT shift  107 */
  {  13,   0, 121}, /* 16:                  BITOR shift  121 */
/* State 129 */
  {  84,   2, 212}, /*  1:                   NULL shift  212 */
  {  60,   0, 217}, /*  2:                     IN shift  217 */
  {  74,   0, 132}, /*  3:                   LIKE shift  132 */
  { 171,   0, 130}, /*  4:                 likeop shift  130 */
  {  52,   6, 133}, /*  5:                   GLOB shift  133 */
  {  10,   0, 213}, /*  6:                BETWEEN shift  213 */
/* State 130 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 131}, /*  2:                   expr shift  131 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 131 */
  {  96,   2, 142}, /*  1:                    REM shift  142 */
  {  80,   0, 136}, /*  2:                  MINUS shift  136 */
  {  54,   0, 109}, /*  3:                     GT shift  109 */
  {  51,   0, 113}, /*  4:                     GE shift  113 */
  {  73,   0, 111}, /*  5:                     LE shift  111 */
  {  91,   8, 134}, /*  6:                   PLUS shift  134 */
  { 102,   3, 125}, /*  7:                 RSHIFT shift  125 */
  {  11,   0, 119}, /*  8:                 BITAND shift  119 */
  {  24,   0, 144}, /*  9:                 CONCAT shift  144 */
  {  89,   5,  98}, /* 10:      ORACLE_OUTER_JOIN shift  98 */
  { 106,   0, 140}, /* 11:                  SLASH shift  140 */
  { 171,   6, 127}, /* 12:                 likeop shift  127 */
  { 108,   0, 138}, /* 13:                   STAR shift  138 */
  {  77,  16, 123}, /* 14:                 LSHIFT shift  123 */
  {  78,   0, 107}, /* 15:                     LT shift  107 */
  {  13,   0, 121}, /* 16:                  BITOR shift  121 */
/* State 134 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 135}, /*  2:                   expr shift  135 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 135 */
  { 108,   2, 138}, /*  1:                   STAR shift  138 */
  {  96,   3, 142}, /*  2:                    REM shift  142 */
  {  24,   0, 144}, /*  3:                 CONCAT shift  144 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  { 106,   0, 140}, /*  5:                  SLASH shift  140 */
  {  89,   0,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
/* State 136 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 137}, /*  2:                   expr shift  137 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 137 */
  { 108,   2, 138}, /*  1:                   STAR shift  138 */
  {  96,   3, 142}, /*  2:                    REM shift  142 */
  {  24,   0, 144}, /*  3:                 CONCAT shift  144 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  { 106,   0, 140}, /*  5:                  SLASH shift  140 */
  {  89,   0,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
/* State 138 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 139}, /*  2:                   expr shift  139 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 139 */
  { 171,   2, 127}, /*  1:                 likeop shift  127 */
  {  24,   0, 144}, /*  2:                 CONCAT shift  144 */
  {  89,   0,  98}, /*  3:      ORACLE_OUTER_JOIN shift  98 */
/* State 140 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 141}, /*  2:                   expr shift  141 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 141 */
  { 171,   2, 127}, /*  1:                 likeop shift  127 */
  {  24,   0, 144}, /*  2:                 CONCAT shift  144 */
  {  89,   0,  98}, /*  3:      ORACLE_OUTER_JOIN shift  98 */
/* State 142 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 143}, /*  2:                   expr shift  143 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 143 */
  { 171,   2, 127}, /*  1:                 likeop shift  127 */
  {  24,   0, 144}, /*  2:                 CONCAT shift  144 */
  {  89,   0,  98}, /*  3:      ORACLE_OUTER_JOIN shift  98 */
/* State 144 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 145}, /*  2:                   expr shift  145 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 145 */
  {  89,   0,  98}, /*  1:      ORACLE_OUTER_JOIN shift  98 */
  { 171,   1, 127}, /*  2:                 likeop shift  127 */
/* State 147 */
  {  84,   2, 148}, /*  1:                   NULL shift  148 */
  {  82,   0, 149}, /*  2:                    NOT shift  149 */
/* State 149 */
  {  84,   0, 150}, /*  1:                   NULL shift  150 */
/* State 152 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 153}, /*  2:                   expr shift  153 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 153 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {   5,   0, 154}, /*  2:                    AND shift  154 */
  {  68,   0, 147}, /*  3:                     IS shift  147 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  88,   1, 105}, /*  5:                     OR shift  105 */
  {  89,   2,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  {  13,   0, 121}, /*  7:                  BITOR shift  121 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  74,   0, 132}, /*  9:                   LIKE shift  132 */
  {  78,   0, 107}, /* 10:                     LT shift  107 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  {  96,   3, 142}, /* 13:                    REM shift  142 */
  {  69,   7, 146}, /* 14:                 ISNULL shift  146 */
  {  42,   0, 117}, /* 15:                     EQ shift  117 */
  {  80,  17, 136}, /* 16:                  MINUS shift  136 */
  {  52,  20, 133}, /* 17:                   GLOB shift  133 */
  {  73,   0, 111}, /* 18:                     LE shift  111 */
  { 102,   9, 125}, /* 19:                 RSHIFT shift  125 */
  {  24,   0, 144}, /* 20:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 21:                     GT shift  109 */
  {  77,   0, 123}, /* 22:                 LSHIFT shift  123 */
  { 106,  10, 140}, /* 23:                  SLASH shift  140 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 108,  16, 138}, /* 25:                   STAR shift  138 */
  {  81,   0, 115}, /* 26:                     NE shift  115 */
  {  82,  21, 129}, /* 27:                    NOT shift  129 */
  {  83,   0, 151}, /* 28:                NOTNULL shift  151 */
/* State 154 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 155}, /*  2:                   expr shift  155 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 155 */
  {  96,   2, 142}, /*  1:                    REM shift  142 */
  {  80,   0, 136}, /*  2:                  MINUS shift  136 */
  {  54,   0, 109}, /*  3:                     GT shift  109 */
  {  51,   0, 113}, /*  4:                     GE shift  113 */
  {  73,   0, 111}, /*  5:                     LE shift  111 */
  {  91,   8, 134}, /*  6:                   PLUS shift  134 */
  { 102,   3, 125}, /*  7:                 RSHIFT shift  125 */
  {  11,   0, 119}, /*  8:                 BITAND shift  119 */
  {  24,   0, 144}, /*  9:                 CONCAT shift  144 */
  {  89,   5,  98}, /* 10:      ORACLE_OUTER_JOIN shift  98 */
  { 106,   0, 140}, /* 11:                  SLASH shift  140 */
  { 171,   6, 127}, /* 12:                 likeop shift  127 */
  { 108,   0, 138}, /* 13:                   STAR shift  138 */
  {  77,  16, 123}, /* 14:                 LSHIFT shift  123 */
  {  78,   0, 107}, /* 15:                     LT shift  107 */
  {  13,   0, 121}, /* 16:                  BITOR shift  121 */
/* State 156 */
  {  76,   0, 157}, /*  1:                     LP shift  157 */
/* State 157 */
  { 180,   2,  68}, /*  1:              oneselect shift  68 */
  {  80,   0, 171}, /*  2:                  MINUS shift  171 */
  {  82,   0, 167}, /*  3:                    NOT shift  167 */
  { 103,   0,  72}, /*  4:                 SELECT shift  72 */
  {  84,   0, 100}, /*  5:                   NULL shift  100 */
  {  65,   0, 165}, /*  6:                INTEGER shift  165 */
  {  46,   0, 166}, /*  7:                  FLOAT shift  166 */
  { 151,   9, 164}, /*  8:                   expr shift  164 */
  {  91,  10, 173}, /*  9:                   PLUS shift  173 */
  {  71,   0,  66}, /* 10:                JOIN_KW shift  66 */
  { 110,   0,  65}, /* 11:                 STRING shift  65 */
  { 191,   8, 158}, /* 12:                 select shift  158 */
  { 152,  16, 211}, /* 13:               expritem shift  211 */
  { 153,   0, 207}, /* 14:               exprlist shift  207 */
  {  94,   0, 185}, /* 15:                  RAISE shift  185 */
  {  12,   0, 169}, /* 16:                 BITNOT shift  169 */
  { 176,  18, 101}, /* 17:                     nm shift  101 */
  {  76,  19,  67}, /* 18:                     LP shift  67 */
  {  56,  20,  63}, /* 19:                     ID shift  63 */
  {  16,   0, 175}, /* 20:                   CASE shift  175 */
/* State 158 */
  { 175,   0,  70}, /*  1:         multiselect_op shift  70 */
  { 101,   3, 163}, /*  2:                     RP shift  163 */
  {  66,   0, 161}, /*  3:              INTERSECT shift  161 */
  { 118,   5, 159}, /*  4:                  UNION shift  159 */
  {  43,   0, 162}, /*  5:                 EXCEPT shift  162 */
/* State 159 */
  {   4,   0, 160}, /*  1:                    ALL shift  160 */
  { 103,   0, 632}, /*  2:                 SELECT reduce 102 */
/* State 160 */
  { 103,   0, 633}, /*  1:                 SELECT reduce 103 */
/* State 161 */
  { 103,   0, 634}, /*  1:                 SELECT reduce 104 */
/* State 162 */
  { 103,   0, 635}, /*  1:                 SELECT reduce 105 */
/* State 164 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {   5,   0,  99}, /*  2:                    AND shift  99 */
  {  68,   0, 147}, /*  3:                     IS shift  147 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  88,   1, 105}, /*  5:                     OR shift  105 */
  {  89,   2,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  {  13,   0, 121}, /*  7:                  BITOR shift  121 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  74,   0, 132}, /*  9:                   LIKE shift  132 */
  {  78,   0, 107}, /* 10:                     LT shift  107 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  {  96,   3, 142}, /* 13:                    REM shift  142 */
  {  69,   7, 146}, /* 14:                 ISNULL shift  146 */
  {  42,   0, 117}, /* 15:                     EQ shift  117 */
  {  80,  17, 136}, /* 16:                  MINUS shift  136 */
  {  52,  20, 133}, /* 17:                   GLOB shift  133 */
  {  73,   0, 111}, /* 18:                     LE shift  111 */
  { 102,   9, 125}, /* 19:                 RSHIFT shift  125 */
  {  24,   0, 144}, /* 20:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 21:                     GT shift  109 */
  {  77,   0, 123}, /* 22:                 LSHIFT shift  123 */
  { 106,  10, 140}, /* 23:                  SLASH shift  140 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 108,  16, 138}, /* 25:                   STAR shift  138 */
  {  81,   0, 115}, /* 26:                     NE shift  115 */
  {  82,  21, 129}, /* 27:                    NOT shift  129 */
  {  83,   0, 151}, /* 28:                NOTNULL shift  151 */
/* State 167 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 168}, /*  2:                   expr shift  168 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 168 */
  {  78,   2, 107}, /*  1:                     LT shift  107 */
  {  52,   0, 133}, /*  2:                   GLOB shift  133 */
  { 106,   7, 140}, /*  3:                  SLASH shift  140 */
  {  81,   0, 115}, /*  4:                     NE shift  115 */
  { 108,   8, 138}, /*  5:                   STAR shift  138 */
  {  83,   0, 151}, /*  6:                NOTNULL shift  151 */
  {  80,  10, 136}, /*  7:                  MINUS shift  136 */
  {  82,   0, 129}, /*  8:                    NOT shift  129 */
  {  60,   0, 156}, /*  9:                     IN shift  156 */
  {  54,   0, 109}, /* 10:                     GT shift  109 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  89,  13,  98}, /* 12:      ORACLE_OUTER_JOIN shift  98 */
  {  11,   0, 119}, /* 13:                 BITAND shift  119 */
  {  91,  15, 134}, /* 14:                   PLUS shift  134 */
  {  13,   0, 121}, /* 15:                  BITOR shift  121 */
  { 171,   0, 127}, /* 16:                 likeop shift  127 */
  {  68,  20, 147}, /* 17:                     IS shift  147 */
  {  69,   0, 146}, /* 18:                 ISNULL shift  146 */
  {  96,   0, 142}, /* 19:                    REM shift  142 */
  {  42,   0, 117}, /* 20:                     EQ shift  117 */
  {  24,   0, 144}, /* 21:                 CONCAT shift  144 */
  {  73,   0, 111}, /* 22:                     LE shift  111 */
  {  74,   0, 132}, /* 23:                   LIKE shift  132 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 102,  21, 125}, /* 25:                 RSHIFT shift  125 */
  {  77,  24, 123}, /* 26:                 LSHIFT shift  123 */
/* State 169 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 170}, /*  2:                   expr shift  170 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 170 */
  {  89,   0,  98}, /*  1:      ORACLE_OUTER_JOIN shift  98 */
  { 171,   1, 127}, /*  2:                 likeop shift  127 */
/* State 171 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 172}, /*  2:                   expr shift  172 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 172 */
  {  89,   0,  98}, /*  1:      ORACLE_OUTER_JOIN shift  98 */
  { 171,   1, 127}, /*  2:                 likeop shift  127 */
/* State 173 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 174}, /*  2:                   expr shift  174 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 174 */
  {  89,   0,  98}, /*  1:      ORACLE_OUTER_JOIN shift  98 */
  { 171,   1, 127}, /*  2:                 likeop shift  127 */
/* State 175 */
  {  91,   0, 173}, /*  1:                   PLUS shift  173 */
  {  76,   0,  67}, /*  2:                     LP shift  67 */
  {  46,   5, 166}, /*  3:                  FLOAT shift  166 */
  {  71,   0,  66}, /*  4:                JOIN_KW shift  66 */
  {  12,   0, 169}, /*  5:                 BITNOT shift  169 */
  {  56,   0,  63}, /*  6:                     ID shift  63 */
  { 176,   1, 101}, /*  7:                     nm shift  101 */
  { 126,   0, 753}, /*  8:                   WHEN reduce 223 */
  { 110,   2,  65}, /*  9:                 STRING shift  65 */
  {  94,   0, 185}, /* 10:                  RAISE shift  185 */
  {  82,  12, 167}, /* 11:                    NOT shift  167 */
  {  65,   0, 165}, /* 12:                INTEGER shift  165 */
  {  80,   3, 171}, /* 13:                  MINUS shift  171 */
  {  16,   0, 175}, /* 14:                   CASE shift  175 */
  { 133,  11, 177}, /* 15:           case_operand shift  177 */
  { 151,   0, 176}, /* 16:                   expr shift  176 */
  {  84,  14, 100}, /* 17:                   NULL shift  100 */
/* State 176 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {  88,   0, 105}, /*  2:                     OR shift  105 */
  {  89,   1,  98}, /*  3:      ORACLE_OUTER_JOIN shift  98 */
  {  68,   7, 147}, /*  4:                     IS shift  147 */
  {  91,   0, 134}, /*  5:                   PLUS shift  134 */
  {   5,   0,  99}, /*  6:                    AND shift  99 */
  {  10,   0, 152}, /*  7:                BETWEEN shift  152 */
  {  11,   0, 119}, /*  8:                 BITAND shift  119 */
  {  13,   0, 121}, /*  9:                  BITOR shift  121 */
  {  96,   0, 142}, /* 10:                    REM shift  142 */
  { 126,   4, 752}, /* 11:                   WHEN reduce 222 */
  {  69,   8, 146}, /* 12:                 ISNULL shift  146 */
  {  73,   0, 111}, /* 13:                     LE shift  111 */
  {  42,   9, 117}, /* 14:                     EQ shift  117 */
  {  77,   0, 123}, /* 15:                 LSHIFT shift  123 */
  { 102,  13, 125}, /* 16:                 RSHIFT shift  125 */
  {  74,   0, 132}, /* 17:                   LIKE shift  132 */
  {  51,   0, 113}, /* 18:                     GE shift  113 */
  {  52,   0, 133}, /* 19:                   GLOB shift  133 */
  { 106,  15, 140}, /* 20:                  SLASH shift  140 */
  {  78,   0, 107}, /* 21:                     LT shift  107 */
  { 108,   0, 138}, /* 22:                   STAR shift  138 */
  {  80,  18, 136}, /* 23:                  MINUS shift  136 */
  {  81,  19, 115}, /* 24:                     NE shift  115 */
  {  82,  28, 129}, /* 25:                    NOT shift  129 */
  {  83,  29, 151}, /* 26:                NOTNULL shift  151 */
  { 171,   0, 127}, /* 27:                 likeop shift  127 */
  {  24,   0, 144}, /* 28:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 29:                     GT shift  109 */
/* State 177 */
  { 132,   2, 178}, /*  1:          case_exprlist shift  178 */
  { 126,   0, 203}, /*  2:                   WHEN shift  203 */
/* State 178 */
  {  40,   0, 751}, /*  1:                    END reduce 221 */
  {  39,   0, 201}, /*  2:                   ELSE shift  201 */
  { 126,   0, 181}, /*  3:                   WHEN shift  181 */
  { 131,   2, 179}, /*  4:              case_else shift  179 */
/* State 179 */
  {  40,   0, 180}, /*  1:                    END shift  180 */
/* State 181 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 182}, /*  2:                   expr shift  182 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 182 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {  88,   0, 105}, /*  2:                     OR shift  105 */
  {  89,   1,  98}, /*  3:      ORACLE_OUTER_JOIN shift  98 */
  {  10,   0, 152}, /*  4:                BETWEEN shift  152 */
  {  91,   0, 134}, /*  5:                   PLUS shift  134 */
  {   5,   0,  99}, /*  6:                    AND shift  99 */
  {  11,   0, 119}, /*  7:                 BITAND shift  119 */
  {  13,   0, 121}, /*  8:                  BITOR shift  121 */
  {  73,   0, 111}, /*  9:                     LE shift  111 */
  {  96,   0, 142}, /* 10:                    REM shift  142 */
  {  68,   4, 147}, /* 11:                     IS shift  147 */
  {  69,   7, 146}, /* 12:                 ISNULL shift  146 */
  {  77,   0, 123}, /* 13:                 LSHIFT shift  123 */
  {  42,   8, 117}, /* 14:                     EQ shift  117 */
  {  51,   0, 113}, /* 15:                     GE shift  113 */
  { 102,   9, 125}, /* 16:                 RSHIFT shift  125 */
  {  74,   0, 132}, /* 17:                   LIKE shift  132 */
  {  52,   0, 133}, /* 18:                   GLOB shift  133 */
  {  24,   0, 144}, /* 19:                 CONCAT shift  144 */
  { 106,  13, 140}, /* 20:                  SLASH shift  140 */
  {  78,   0, 107}, /* 21:                     LT shift  107 */
  { 108,   0, 138}, /* 22:                   STAR shift  138 */
  {  80,  15, 136}, /* 23:                  MINUS shift  136 */
  {  81,  18, 115}, /* 24:                     NE shift  115 */
  {  82,  19, 129}, /* 25:                    NOT shift  129 */
  {  83,  28, 151}, /* 26:                NOTNULL shift  151 */
  { 171,  29, 127}, /* 27:                 likeop shift  127 */
  {  54,   0, 109}, /* 28:                     GT shift  109 */
  { 113,   0, 183}, /* 29:                   THEN shift  183 */
/* State 183 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 184}, /*  2:                   expr shift  184 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 184 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {   5,   0,  99}, /*  2:                    AND shift  99 */
  {  68,   0, 147}, /*  3:                     IS shift  147 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  88,   1, 105}, /*  5:                     OR shift  105 */
  {  89,   2,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  {  13,   0, 121}, /*  7:                  BITOR shift  121 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  74,   0, 132}, /*  9:                   LIKE shift  132 */
  {  78,   0, 107}, /* 10:                     LT shift  107 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  {  96,   3, 142}, /* 13:                    REM shift  142 */
  {  69,   7, 146}, /* 14:                 ISNULL shift  146 */
  {  42,   0, 117}, /* 15:                     EQ shift  117 */
  {  80,  17, 136}, /* 16:                  MINUS shift  136 */
  {  52,  20, 133}, /* 17:                   GLOB shift  133 */
  {  73,   0, 111}, /* 18:                     LE shift  111 */
  { 102,   9, 125}, /* 19:                 RSHIFT shift  125 */
  {  24,   0, 144}, /* 20:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 21:                     GT shift  109 */
  {  77,   0, 123}, /* 22:                 LSHIFT shift  123 */
  { 106,  10, 140}, /* 23:                  SLASH shift  140 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 108,  16, 138}, /* 25:                   STAR shift  138 */
  {  81,   0, 115}, /* 26:                     NE shift  115 */
  {  82,  21, 129}, /* 27:                    NOT shift  129 */
  {  83,   0, 151}, /* 28:                NOTNULL shift  151 */
/* State 185 */
  {  76,   0, 186}, /*  1:                     LP shift  186 */
/* State 186 */
  {  45,   3, 197}, /*  1:                   FAIL shift  197 */
  {  57,   1, 187}, /*  2:                 IGNORE shift  187 */
  {   1,   0, 193}, /*  3:                  ABORT shift  193 */
  {  99,   0, 189}, /*  4:               ROLLBACK shift  189 */
/* State 187 */
  { 101,   0, 188}, /*  1:                     RP shift  188 */
/* State 189 */
  {  21,   0, 190}, /*  1:                  COMMA shift  190 */
/* State 190 */
  { 176,   2, 191}, /*  1:                     nm shift  191 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 191 */
  { 101,   0, 192}, /*  1:                     RP shift  192 */
/* State 193 */
  {  21,   0, 194}, /*  1:                  COMMA shift  194 */
/* State 194 */
  { 176,   2, 195}, /*  1:                     nm shift  195 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 195 */
  { 101,   0, 196}, /*  1:                     RP shift  196 */
/* State 197 */
  {  21,   0, 198}, /*  1:                  COMMA shift  198 */
/* State 198 */
  { 176,   2, 199}, /*  1:                     nm shift  199 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 199 */
  { 101,   0, 200}, /*  1:                     RP shift  200 */
/* State 201 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 202}, /*  2:                   expr shift  202 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 202 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {  88,   0, 105}, /*  2:                     OR shift  105 */
  {  89,   1,  98}, /*  3:      ORACLE_OUTER_JOIN shift  98 */
  {  10,   0, 152}, /*  4:                BETWEEN shift  152 */
  {  91,   0, 134}, /*  5:                   PLUS shift  134 */
  {   5,   0,  99}, /*  6:                    AND shift  99 */
  {  40,   8, 750}, /*  7:                    END reduce 220 */
  {  11,   0, 119}, /*  8:                 BITAND shift  119 */
  {  13,   0, 121}, /*  9:                  BITOR shift  121 */
  {  96,   0, 142}, /* 10:                    REM shift  142 */
  {  68,   4, 147}, /* 11:                     IS shift  147 */
  {  69,   7, 146}, /* 12:                 ISNULL shift  146 */
  {  73,   0, 111}, /* 13:                     LE shift  111 */
  {  42,   9, 117}, /* 14:                     EQ shift  117 */
  {  77,   0, 123}, /* 15:                 LSHIFT shift  123 */
  { 102,  13, 125}, /* 16:                 RSHIFT shift  125 */
  {  74,   0, 132}, /* 17:                   LIKE shift  132 */
  {  51,   0, 113}, /* 18:                     GE shift  113 */
  {  52,   0, 133}, /* 19:                   GLOB shift  133 */
  { 106,  15, 140}, /* 20:                  SLASH shift  140 */
  {  78,   0, 107}, /* 21:                     LT shift  107 */
  { 108,   0, 138}, /* 22:                   STAR shift  138 */
  {  80,  18, 136}, /* 23:                  MINUS shift  136 */
  {  81,  19, 115}, /* 24:                     NE shift  115 */
  {  82,  28, 129}, /* 25:                    NOT shift  129 */
  {  83,  29, 151}, /* 26:                NOTNULL shift  151 */
  { 171,   0, 127}, /* 27:                 likeop shift  127 */
  {  24,   0, 144}, /* 28:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 29:                     GT shift  109 */
/* State 203 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 204}, /*  2:                   expr shift  204 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 204 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {  88,   0, 105}, /*  2:                     OR shift  105 */
  {  89,   1,  98}, /*  3:      ORACLE_OUTER_JOIN shift  98 */
  {  10,   0, 152}, /*  4:                BETWEEN shift  152 */
  {  91,   0, 134}, /*  5:                   PLUS shift  134 */
  {   5,   0,  99}, /*  6:                    AND shift  99 */
  {  11,   0, 119}, /*  7:                 BITAND shift  119 */
  {  13,   0, 121}, /*  8:                  BITOR shift  121 */
  {  73,   0, 111}, /*  9:                     LE shift  111 */
  {  96,   0, 142}, /* 10:                    REM shift  142 */
  {  68,   4, 147}, /* 11:                     IS shift  147 */
  {  69,   7, 146}, /* 12:                 ISNULL shift  146 */
  {  77,   0, 123}, /* 13:                 LSHIFT shift  123 */
  {  42,   8, 117}, /* 14:                     EQ shift  117 */
  {  51,   0, 113}, /* 15:                     GE shift  113 */
  { 102,   9, 125}, /* 16:                 RSHIFT shift  125 */
  {  74,   0, 132}, /* 17:                   LIKE shift  132 */
  {  52,   0, 133}, /* 18:                   GLOB shift  133 */
  {  24,   0, 144}, /* 19:                 CONCAT shift  144 */
  { 106,  13, 140}, /* 20:                  SLASH shift  140 */
  {  78,   0, 107}, /* 21:                     LT shift  107 */
  { 108,   0, 138}, /* 22:                   STAR shift  138 */
  {  80,  15, 136}, /* 23:                  MINUS shift  136 */
  {  81,  18, 115}, /* 24:                     NE shift  115 */
  {  82,  19, 129}, /* 25:                    NOT shift  129 */
  {  83,  28, 151}, /* 26:                NOTNULL shift  151 */
  { 171,  29, 127}, /* 27:                 likeop shift  127 */
  {  54,   0, 109}, /* 28:                     GT shift  109 */
  { 113,   0, 205}, /* 29:                   THEN shift  205 */
/* State 205 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 206}, /*  2:                   expr shift  206 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 206 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {   5,   0,  99}, /*  2:                    AND shift  99 */
  {  68,   0, 147}, /*  3:                     IS shift  147 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  88,   1, 105}, /*  5:                     OR shift  105 */
  {  89,   2,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  {  13,   0, 121}, /*  7:                  BITOR shift  121 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  74,   0, 132}, /*  9:                   LIKE shift  132 */
  {  78,   0, 107}, /* 10:                     LT shift  107 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  {  96,   3, 142}, /* 13:                    REM shift  142 */
  {  69,   7, 146}, /* 14:                 ISNULL shift  146 */
  {  42,   0, 117}, /* 15:                     EQ shift  117 */
  {  80,  17, 136}, /* 16:                  MINUS shift  136 */
  {  52,  20, 133}, /* 17:                   GLOB shift  133 */
  {  73,   0, 111}, /* 18:                     LE shift  111 */
  { 102,   9, 125}, /* 19:                 RSHIFT shift  125 */
  {  24,   0, 144}, /* 20:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 21:                     GT shift  109 */
  {  77,   0, 123}, /* 22:                 LSHIFT shift  123 */
  { 106,  10, 140}, /* 23:                  SLASH shift  140 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 108,  16, 138}, /* 25:                   STAR shift  138 */
  {  81,   0, 115}, /* 26:                     NE shift  115 */
  {  82,  21, 129}, /* 27:                    NOT shift  129 */
  {  83,   0, 151}, /* 28:                NOTNULL shift  151 */
/* State 207 */
  {  21,   0, 209}, /*  1:                  COMMA shift  209 */
  { 101,   1, 208}, /*  2:                     RP shift  208 */
/* State 209 */
  { 176,   4, 101}, /*  1:                     nm shift  101 */
  {  65,   0, 165}, /*  2:                INTEGER shift  165 */
  {  82,   0, 167}, /*  3:                    NOT shift  167 */
  {  80,   6, 171}, /*  4:                  MINUS shift  171 */
  {  84,   0, 100}, /*  5:                   NULL shift  100 */
  {  16,   0, 175}, /*  6:                   CASE shift  175 */
  {  71,   0,  66}, /*  7:                JOIN_KW shift  66 */
  { 151,   7, 164}, /*  8:                   expr shift  164 */
  { 152,  10, 210}, /*  9:               expritem shift  210 */
  {  56,   0,  63}, /* 10:                     ID shift  63 */
  {  12,   0, 169}, /* 11:                 BITNOT shift  169 */
  {  91,   0, 173}, /* 12:                   PLUS shift  173 */
  {  76,  11,  67}, /* 13:                     LP shift  67 */
  {  94,  16, 185}, /* 14:                  RAISE shift  185 */
  { 110,  14,  65}, /* 15:                 STRING shift  65 */
  {  46,   0, 166}, /* 16:                  FLOAT shift  166 */
/* State 213 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 214}, /*  2:                   expr shift  214 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 214 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {   5,   0, 215}, /*  2:                    AND shift  215 */
  {  68,   0, 147}, /*  3:                     IS shift  147 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  88,   1, 105}, /*  5:                     OR shift  105 */
  {  89,   2,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  {  13,   0, 121}, /*  7:                  BITOR shift  121 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  74,   0, 132}, /*  9:                   LIKE shift  132 */
  {  78,   0, 107}, /* 10:                     LT shift  107 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  {  96,   3, 142}, /* 13:                    REM shift  142 */
  {  69,   7, 146}, /* 14:                 ISNULL shift  146 */
  {  42,   0, 117}, /* 15:                     EQ shift  117 */
  {  80,  17, 136}, /* 16:                  MINUS shift  136 */
  {  52,  20, 133}, /* 17:                   GLOB shift  133 */
  {  73,   0, 111}, /* 18:                     LE shift  111 */
  { 102,   9, 125}, /* 19:                 RSHIFT shift  125 */
  {  24,   0, 144}, /* 20:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 21:                     GT shift  109 */
  {  77,   0, 123}, /* 22:                 LSHIFT shift  123 */
  { 106,  10, 140}, /* 23:                  SLASH shift  140 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 108,  16, 138}, /* 25:                   STAR shift  138 */
  {  81,   0, 115}, /* 26:                     NE shift  115 */
  {  82,  21, 129}, /* 27:                    NOT shift  129 */
  {  83,   0, 151}, /* 28:                NOTNULL shift  151 */
/* State 215 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 216}, /*  2:                   expr shift  216 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 216 */
  {  78,   2, 107}, /*  1:                     LT shift  107 */
  {  52,   0, 133}, /*  2:                   GLOB shift  133 */
  { 106,   7, 140}, /*  3:                  SLASH shift  140 */
  {  81,   0, 115}, /*  4:                     NE shift  115 */
  { 108,   8, 138}, /*  5:                   STAR shift  138 */
  {  83,   0, 151}, /*  6:                NOTNULL shift  151 */
  {  80,  10, 136}, /*  7:                  MINUS shift  136 */
  {  82,   0, 129}, /*  8:                    NOT shift  129 */
  {  60,   0, 156}, /*  9:                     IN shift  156 */
  {  54,   0, 109}, /* 10:                     GT shift  109 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  89,  13,  98}, /* 12:      ORACLE_OUTER_JOIN shift  98 */
  {  11,   0, 119}, /* 13:                 BITAND shift  119 */
  {  91,  15, 134}, /* 14:                   PLUS shift  134 */
  {  13,   0, 121}, /* 15:                  BITOR shift  121 */
  { 171,   0, 127}, /* 16:                 likeop shift  127 */
  {  68,  20, 147}, /* 17:                     IS shift  147 */
  {  69,   0, 146}, /* 18:                 ISNULL shift  146 */
  {  96,   0, 142}, /* 19:                    REM shift  142 */
  {  42,   0, 117}, /* 20:                     EQ shift  117 */
  {  24,   0, 144}, /* 21:                 CONCAT shift  144 */
  {  73,   0, 111}, /* 22:                     LE shift  111 */
  {  74,   0, 132}, /* 23:                   LIKE shift  132 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 102,  21, 125}, /* 25:                 RSHIFT shift  125 */
  {  77,  24, 123}, /* 26:                 LSHIFT shift  123 */
/* State 217 */
  {  76,   0, 218}, /*  1:                     LP shift  218 */
/* State 218 */
  { 180,   2,  68}, /*  1:              oneselect shift  68 */
  {  80,   0, 171}, /*  2:                  MINUS shift  171 */
  {  82,   0, 167}, /*  3:                    NOT shift  167 */
  { 103,   0,  72}, /*  4:                 SELECT shift  72 */
  {  84,   0, 100}, /*  5:                   NULL shift  100 */
  {  65,   0, 165}, /*  6:                INTEGER shift  165 */
  {  46,   0, 166}, /*  7:                  FLOAT shift  166 */
  { 151,   9, 164}, /*  8:                   expr shift  164 */
  {  91,  10, 173}, /*  9:                   PLUS shift  173 */
  {  71,   0,  66}, /* 10:                JOIN_KW shift  66 */
  { 110,   0,  65}, /* 11:                 STRING shift  65 */
  { 191,   8, 219}, /* 12:                 select shift  219 */
  { 152,  16, 211}, /* 13:               expritem shift  211 */
  { 153,   0, 221}, /* 14:               exprlist shift  221 */
  {  94,   0, 185}, /* 15:                  RAISE shift  185 */
  {  12,   0, 169}, /* 16:                 BITNOT shift  169 */
  { 176,  18, 101}, /* 17:                     nm shift  101 */
  {  76,  19,  67}, /* 18:                     LP shift  67 */
  {  56,  20,  63}, /* 19:                     ID shift  63 */
  {  16,   0, 175}, /* 20:                   CASE shift  175 */
/* State 219 */
  { 175,   0,  70}, /*  1:         multiselect_op shift  70 */
  { 101,   3, 220}, /*  2:                     RP shift  220 */
  {  66,   0, 161}, /*  3:              INTERSECT shift  161 */
  { 118,   5, 159}, /*  4:                  UNION shift  159 */
  {  43,   0, 162}, /*  5:                 EXCEPT shift  162 */
/* State 221 */
  {  21,   0, 209}, /*  1:                  COMMA shift  209 */
  { 101,   1, 222}, /*  2:                     RP shift  222 */
/* State 223 */
  {  19,   0,  94}, /*  1:                COLLATE shift  94 */
  { 137,   1, 224}, /*  2:                collate shift  224 */
/* State 224 */
  {   7,   0,  57}, /*  1:                    ASC shift  57 */
  {  34,   1,  58}, /*  2:                   DESC shift  58 */
  { 197,   0, 225}, /*  3:              sortorder shift  225 */
/* State 226 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 227}, /*  2:                   expr shift  227 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 227 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {   5,   0,  99}, /*  2:                    AND shift  99 */
  {  68,   0, 147}, /*  3:                     IS shift  147 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  88,   1, 105}, /*  5:                     OR shift  105 */
  {  89,   2,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  {  13,   0, 121}, /*  7:                  BITOR shift  121 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  74,   0, 132}, /*  9:                   LIKE shift  132 */
  {  78,   0, 107}, /* 10:                     LT shift  107 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  {  96,   3, 142}, /* 13:                    REM shift  142 */
  {  69,   7, 146}, /* 14:                 ISNULL shift  146 */
  {  42,   0, 117}, /* 15:                     EQ shift  117 */
  {  80,  17, 136}, /* 16:                  MINUS shift  136 */
  {  52,  20, 133}, /* 17:                   GLOB shift  133 */
  {  73,   0, 111}, /* 18:                     LE shift  111 */
  { 102,   9, 125}, /* 19:                 RSHIFT shift  125 */
  {  24,   0, 144}, /* 20:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 21:                     GT shift  109 */
  {  77,   0, 123}, /* 22:                 LSHIFT shift  123 */
  { 106,  10, 140}, /* 23:                  SLASH shift  140 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 108,  16, 138}, /* 25:                   STAR shift  138 */
  {  81,   0, 115}, /* 26:                     NE shift  115 */
  {  82,  21, 129}, /* 27:                    NOT shift  129 */
  {  83,   0, 151}, /* 28:                NOTNULL shift  151 */
/* State 228 */
  {  14,   0, 229}, /*  1:                     BY shift  229 */
/* State 229 */
  { 153,   0, 230}, /*  1:               exprlist shift  230 */
  {  91,   0, 173}, /*  2:                   PLUS shift  173 */
  {  76,   0,  67}, /*  3:                     LP shift  67 */
  {  71,   0,  66}, /*  4:                JOIN_KW shift  66 */
  {  46,   8, 166}, /*  5:                  FLOAT shift  166 */
  {  56,   0,  63}, /*  6:                     ID shift  63 */
  { 176,   2, 101}, /*  7:                     nm shift  101 */
  {  12,   0, 169}, /*  8:                 BITNOT shift  169 */
  { 110,   3,  65}, /*  9:                 STRING shift  65 */
  {  94,   0, 185}, /* 10:                  RAISE shift  185 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  {  84,  14, 100}, /* 12:                   NULL shift  100 */
  {  80,   5, 171}, /* 13:                  MINUS shift  171 */
  {  16,   0, 175}, /* 14:                   CASE shift  175 */
  {  82,  11, 167}, /* 15:                    NOT shift  167 */
  { 151,   0, 164}, /* 16:                   expr shift  164 */
  { 152,  12, 211}, /* 17:               expritem shift  211 */
/* State 230 */
  {  21,   0, 209}, /*  1:                  COMMA shift  209 */
/* State 231 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 232}, /*  2:                   expr shift  232 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 232 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {   5,   0,  99}, /*  2:                    AND shift  99 */
  {  68,   0, 147}, /*  3:                     IS shift  147 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  88,   1, 105}, /*  5:                     OR shift  105 */
  {  89,   2,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  {  13,   0, 121}, /*  7:                  BITOR shift  121 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  74,   0, 132}, /*  9:                   LIKE shift  132 */
  {  78,   0, 107}, /* 10:                     LT shift  107 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  {  96,   3, 142}, /* 13:                    REM shift  142 */
  {  69,   7, 146}, /* 14:                 ISNULL shift  146 */
  {  42,   0, 117}, /* 15:                     EQ shift  117 */
  {  80,  17, 136}, /* 16:                  MINUS shift  136 */
  {  52,  20, 133}, /* 17:                   GLOB shift  133 */
  {  73,   0, 111}, /* 18:                     LE shift  111 */
  { 102,   9, 125}, /* 19:                 RSHIFT shift  125 */
  {  24,   0, 144}, /* 20:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 21:                     GT shift  109 */
  {  77,   0, 123}, /* 22:                 LSHIFT shift  123 */
  { 106,  10, 140}, /* 23:                  SLASH shift  140 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 108,  16, 138}, /* 25:                   STAR shift  138 */
  {  81,   0, 115}, /* 26:                     NE shift  115 */
  {  82,  21, 129}, /* 27:                    NOT shift  129 */
  {  83,   0, 151}, /* 28:                NOTNULL shift  151 */
/* State 234 */
  { 198,   2, 245}, /*  1:             stl_prefix shift  245 */
  { 192,   0, 235}, /*  2:             seltablist shift  235 */
/* State 235 */
  {  21,   0, 237}, /*  1:                  COMMA shift  237 */
  { 169,   1, 236}, /*  2:                 joinop shift  236 */
  {  70,   0, 238}, /*  3:                   JOIN shift  238 */
  {  71,   0, 239}, /*  4:                JOIN_KW shift  239 */
/* State 239 */
  { 110,   3,  20}, /*  1:                 STRING shift  20 */
  { 176,   4, 241}, /*  2:                     nm shift  241 */
  {  70,   0, 240}, /*  3:                   JOIN shift  240 */
  {  71,   5,  21}, /*  4:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  5:                     ID shift  19 */
/* State 241 */
  { 110,   3,  20}, /*  1:                 STRING shift  20 */
  { 176,   4, 243}, /*  2:                     nm shift  243 */
  {  70,   0, 242}, /*  3:                   JOIN shift  242 */
  {  71,   5,  21}, /*  4:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  5:                     ID shift  19 */
/* State 243 */
  {  70,   0, 244}, /*  1:                   JOIN shift  244 */
/* State 245 */
  { 110,   0,  20}, /*  1:                 STRING shift  20 */
  { 176,   3, 246}, /*  2:                     nm shift  246 */
  {  76,   4, 265}, /*  3:                     LP shift  265 */
  {  71,   5,  21}, /*  4:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  5:                     ID shift  19 */
/* State 246 */
  { 110,   0, 248}, /*  1:                 STRING shift  248 */
  {  56,   3, 247}, /*  2:                     ID shift  247 */
  {   6,   0, 249}, /*  3:                     AS shift  249 */
  { 128,   0, 252}, /*  4:                     as shift  252 */
  { 159,   0, 251}, /*  5:                    ids shift  251 */
/* State 249 */
  { 176,   2, 250}, /*  1:                     nm shift  250 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 252 */
  { 178,   0, 253}, /*  1:                 on_opt shift  253 */
  {  87,   0, 263}, /*  2:                     ON shift  263 */
/* State 253 */
  { 122,   0, 255}, /*  1:                  USING shift  255 */
  { 209,   0, 254}, /*  2:              using_opt shift  254 */
/* State 255 */
  {  76,   0, 256}, /*  1:                     LP shift  256 */
/* State 256 */
  { 110,   2,  20}, /*  1:                 STRING shift  20 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 176,   1, 261}, /*  3:                     nm shift  261 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
  { 160,   0, 262}, /*  5:                idxitem shift  262 */
  { 161,   4, 257}, /*  6:                idxlist shift  257 */
/* State 257 */
  {  21,   0, 259}, /*  1:                  COMMA shift  259 */
  { 101,   1, 258}, /*  2:                     RP shift  258 */
/* State 259 */
  { 160,   3, 260}, /*  1:                idxitem shift  260 */
  { 176,   4, 261}, /*  2:                     nm shift  261 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   5,  21}, /*  4:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  5:                     ID shift  19 */
/* State 263 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 264}, /*  2:                   expr shift  264 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 264 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {   5,   0,  99}, /*  2:                    AND shift  99 */
  {  68,   0, 147}, /*  3:                     IS shift  147 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  88,   1, 105}, /*  5:                     OR shift  105 */
  {  89,   2,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  {  13,   0, 121}, /*  7:                  BITOR shift  121 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  74,   0, 132}, /*  9:                   LIKE shift  132 */
  {  78,   0, 107}, /* 10:                     LT shift  107 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  {  96,   3, 142}, /* 13:                    REM shift  142 */
  {  69,   7, 146}, /* 14:                 ISNULL shift  146 */
  {  42,   0, 117}, /* 15:                     EQ shift  117 */
  {  80,  17, 136}, /* 16:                  MINUS shift  136 */
  {  52,  20, 133}, /* 17:                   GLOB shift  133 */
  {  73,   0, 111}, /* 18:                     LE shift  111 */
  { 102,   9, 125}, /* 19:                 RSHIFT shift  125 */
  {  24,   0, 144}, /* 20:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 21:                     GT shift  109 */
  {  77,   0, 123}, /* 22:                 LSHIFT shift  123 */
  { 106,  10, 140}, /* 23:                  SLASH shift  140 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 108,  16, 138}, /* 25:                   STAR shift  138 */
  {  81,   0, 115}, /* 26:                     NE shift  115 */
  {  82,  21, 129}, /* 27:                    NOT shift  129 */
  {  83,   0, 151}, /* 28:                NOTNULL shift  151 */
/* State 265 */
  { 180,   0,  68}, /*  1:              oneselect shift  68 */
  { 103,   0,  72}, /*  2:                 SELECT shift  72 */
  { 191,   0, 266}, /*  3:                 select shift  266 */
/* State 266 */
  { 175,   0,  70}, /*  1:         multiselect_op shift  70 */
  { 101,   3, 267}, /*  2:                     RP shift  267 */
  {  66,   0, 161}, /*  3:              INTERSECT shift  161 */
  { 118,   5, 159}, /*  4:                  UNION shift  159 */
  {  43,   0, 162}, /*  5:                 EXCEPT shift  162 */
/* State 267 */
  { 110,   0, 248}, /*  1:                 STRING shift  248 */
  {  56,   3, 247}, /*  2:                     ID shift  247 */
  {   6,   0, 249}, /*  3:                     AS shift  249 */
  { 128,   0, 268}, /*  4:                     as shift  268 */
  { 159,   0, 251}, /*  5:                    ids shift  251 */
/* State 268 */
  { 178,   0, 269}, /*  1:                 on_opt shift  269 */
  {  87,   0, 263}, /*  2:                     ON shift  263 */
/* State 269 */
  { 122,   0, 255}, /*  1:                  USING shift  255 */
  { 209,   0, 270}, /*  2:              using_opt shift  270 */
/* State 271 */
  { 176,   4, 275}, /*  1:                     nm shift  275 */
  {  65,   0, 165}, /*  2:                INTEGER shift  165 */
  {  82,   0, 167}, /*  3:                    NOT shift  167 */
  {  80,   6, 171}, /*  4:                  MINUS shift  171 */
  {  84,   0, 100}, /*  5:                   NULL shift  100 */
  {  16,   0, 175}, /*  6:                   CASE shift  175 */
  {  71,   0,  66}, /*  7:                JOIN_KW shift  66 */
  { 151,   7, 272}, /*  8:                   expr shift  272 */
  {  56,   0,  63}, /*  9:                     ID shift  63 */
  {  76,  11,  67}, /* 10:                     LP shift  67 */
  {  12,   0, 169}, /* 11:                 BITNOT shift  169 */
  {  91,   0, 173}, /* 12:                   PLUS shift  173 */
  { 108,  10, 274}, /* 13:                   STAR shift  274 */
  {  94,  16, 185}, /* 14:                  RAISE shift  185 */
  { 110,  14,  65}, /* 15:                 STRING shift  65 */
  {  46,   0, 166}, /* 16:                  FLOAT shift  166 */
/* State 272 */
  {  69,   0, 146}, /*  1:                 ISNULL shift  146 */
  {   6,   0, 249}, /*  2:                     AS shift  249 */
  {  68,   0, 147}, /*  3:                     IS shift  147 */
  { 102,   1, 125}, /*  4:                 RSHIFT shift  125 */
  {  73,   0, 111}, /*  5:                     LE shift  111 */
  {   5,   0,  99}, /*  6:                    AND shift  99 */
  { 171,   2, 127}, /*  7:                 likeop shift  127 */
  { 106,   5, 140}, /*  8:                  SLASH shift  140 */
  {  74,   0, 132}, /*  9:                   LIKE shift  132 */
  { 108,  21, 138}, /* 10:                   STAR shift  138 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  { 110,  27, 248}, /* 12:                 STRING shift  248 */
  {  78,   0, 107}, /* 13:                     LT shift  107 */
  {  13,   0, 121}, /* 14:                  BITOR shift  121 */
  {  80,   0, 136}, /* 15:                  MINUS shift  136 */
  {  81,   0, 115}, /* 16:                     NE shift  115 */
  {  82,   0, 129}, /* 17:                    NOT shift  129 */
  {  83,   0, 151}, /* 18:                NOTNULL shift  151 */
  {  51,   0, 113}, /* 19:                     GE shift  113 */
  {  52,   0, 133}, /* 20:                   GLOB shift  133 */
  {  42,   0, 117}, /* 21:                     EQ shift  117 */
  {  54,   0, 109}, /* 22:                     GT shift  109 */
  {  88,   0, 105}, /* 23:                     OR shift  105 */
  {  89,  29,  98}, /* 24:      ORACLE_OUTER_JOIN shift  98 */
  {  24,   0, 144}, /* 25:                 CONCAT shift  144 */
  {  91,   0, 134}, /* 26:                   PLUS shift  134 */
  {  77,  32, 123}, /* 27:                 LSHIFT shift  123 */
  { 159,  33, 251}, /* 28:                    ids shift  251 */
  {  56,   0, 247}, /* 29:                     ID shift  247 */
  { 128,   0, 273}, /* 30:                     as shift  273 */
  {  96,   0, 142}, /* 31:                    REM shift  142 */
  {  11,   0, 119}, /* 32:                 BITAND shift  119 */
  {  60,   0, 156}, /* 33:                     IN shift  156 */
/* State 275 */
  {  36,   0, 276}, /*  1:                    DOT shift  276 */
/* State 276 */
  { 110,   0,  20}, /*  1:                 STRING shift  20 */
  { 176,   3, 103}, /*  2:                     nm shift  103 */
  {  71,   5,  21}, /*  3:                JOIN_KW shift  21 */
  { 108,   0, 277}, /*  4:                   STAR shift  277 */
  {  56,   0,  19}, /*  5:                     ID shift  19 */
/* State 281 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {  88,   0, 105}, /*  2:                     OR shift  105 */
  {  89,   1,  98}, /*  3:      ORACLE_OUTER_JOIN shift  98 */
  {  10,   0, 152}, /*  4:                BETWEEN shift  152 */
  {  91,   0, 134}, /*  5:                   PLUS shift  134 */
  {   5,   0,  99}, /*  6:                    AND shift  99 */
  {  11,   0, 119}, /*  7:                 BITAND shift  119 */
  {  13,   0, 121}, /*  8:                  BITOR shift  121 */
  {  73,   0, 111}, /*  9:                     LE shift  111 */
  {  96,   0, 142}, /* 10:                    REM shift  142 */
  {  68,   4, 147}, /* 11:                     IS shift  147 */
  {  69,   7, 146}, /* 12:                 ISNULL shift  146 */
  {  77,   0, 123}, /* 13:                 LSHIFT shift  123 */
  {  42,   8, 117}, /* 14:                     EQ shift  117 */
  { 101,   0, 282}, /* 15:                     RP shift  282 */
  { 102,   9, 125}, /* 16:                 RSHIFT shift  125 */
  {  74,   0, 132}, /* 17:                   LIKE shift  132 */
  {  51,   0, 113}, /* 18:                     GE shift  113 */
  {  52,   0, 133}, /* 19:                   GLOB shift  133 */
  { 106,  13, 140}, /* 20:                  SLASH shift  140 */
  {  78,   0, 107}, /* 21:                     LT shift  107 */
  { 108,   0, 138}, /* 22:                   STAR shift  138 */
  {  80,  18, 136}, /* 23:                  MINUS shift  136 */
  {  81,  19, 115}, /* 24:                     NE shift  115 */
  {  82,  28, 129}, /* 25:                    NOT shift  129 */
  {  83,  29, 151}, /* 26:                NOTNULL shift  151 */
  { 171,   0, 127}, /* 27:                 likeop shift  127 */
  {  24,   0, 144}, /* 28:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 29:                     GT shift  109 */
/* State 283 */
  {  21,   0, 209}, /*  1:                  COMMA shift  209 */
  { 101,   1, 284}, /*  2:                     RP shift  284 */
/* State 285 */
  { 101,   0, 286}, /*  1:                     RP shift  286 */
/* State 287 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {  88,   0, 105}, /*  2:                     OR shift  105 */
  {  89,   1,  98}, /*  3:      ORACLE_OUTER_JOIN shift  98 */
  {  10,   0, 152}, /*  4:                BETWEEN shift  152 */
  {  91,   0, 134}, /*  5:                   PLUS shift  134 */
  {   5,   0,  99}, /*  6:                    AND shift  99 */
  {  11,   0, 119}, /*  7:                 BITAND shift  119 */
  {  13,   0, 121}, /*  8:                  BITOR shift  121 */
  {  73,   0, 111}, /*  9:                     LE shift  111 */
  {  96,   0, 142}, /* 10:                    REM shift  142 */
  {  68,   4, 147}, /* 11:                     IS shift  147 */
  {  69,   7, 146}, /* 12:                 ISNULL shift  146 */
  {  77,   0, 123}, /* 13:                 LSHIFT shift  123 */
  {  42,   8, 117}, /* 14:                     EQ shift  117 */
  { 101,   0, 288}, /* 15:                     RP shift  288 */
  { 102,   9, 125}, /* 16:                 RSHIFT shift  125 */
  {  74,   0, 132}, /* 17:                   LIKE shift  132 */
  {  51,   0, 113}, /* 18:                     GE shift  113 */
  {  52,   0, 133}, /* 19:                   GLOB shift  133 */
  { 106,  13, 140}, /* 20:                  SLASH shift  140 */
  {  78,   0, 107}, /* 21:                     LT shift  107 */
  { 108,   0, 138}, /* 22:                   STAR shift  138 */
  {  80,  18, 136}, /* 23:                  MINUS shift  136 */
  {  81,  19, 115}, /* 24:                     NE shift  115 */
  {  82,  28, 129}, /* 25:                    NOT shift  129 */
  {  83,  29, 151}, /* 26:                NOTNULL shift  151 */
  { 171,   0, 127}, /* 27:                 likeop shift  127 */
  {  24,   0, 144}, /* 28:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 29:                     GT shift  109 */
/* State 288 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 179,   1, 289}, /*  2:                 onconf shift  289 */
/* State 290 */
  { 176,   2, 291}, /*  1:                     nm shift  291 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 291 */
  { 162,   2, 292}, /*  1:            idxlist_opt shift  292 */
  {  76,   0, 309}, /*  2:                     LP shift  309 */
/* State 292 */
  { 187,   0, 293}, /*  1:                refargs shift  293 */
/* State 293 */
  { 186,   3, 294}, /*  1:                 refarg shift  294 */
  {  79,   0, 295}, /*  2:                  MATCH shift  295 */
  {  87,   0, 297}, /*  3:                     ON shift  297 */
/* State 295 */
  { 176,   2, 296}, /*  1:                     nm shift  296 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 297 */
  { 120,   2, 305}, /*  1:                 UPDATE shift  305 */
  {  63,   0, 307}, /*  2:                 INSERT shift  307 */
  {  32,   0, 298}, /*  3:                 DELETE shift  298 */
/* State 298 */
  { 105,   0, 300}, /*  1:                    SET shift  300 */
  { 185,   1, 299}, /*  2:                 refact shift  299 */
  {  98,   0, 304}, /*  3:               RESTRICT shift  304 */
  {  15,   0, 303}, /*  4:                CASCADE shift  303 */
/* State 300 */
  {  84,   0, 301}, /*  1:                   NULL shift  301 */
  {  29,   0, 302}, /*  2:                DEFAULT shift  302 */
/* State 305 */
  { 105,   0, 300}, /*  1:                    SET shift  300 */
  { 185,   1, 306}, /*  2:                 refact shift  306 */
  {  98,   0, 304}, /*  3:               RESTRICT shift  304 */
  {  15,   0, 303}, /*  4:                CASCADE shift  303 */
/* State 307 */
  { 105,   0, 300}, /*  1:                    SET shift  300 */
  { 185,   1, 308}, /*  2:                 refact shift  308 */
  {  98,   0, 304}, /*  3:               RESTRICT shift  304 */
  {  15,   0, 303}, /*  4:                CASCADE shift  303 */
/* State 309 */
  { 110,   2,  20}, /*  1:                 STRING shift  20 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 176,   1, 261}, /*  3:                     nm shift  261 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
  { 160,   0, 262}, /*  5:                idxitem shift  262 */
  { 161,   4, 310}, /*  6:                idxlist shift  310 */
/* State 310 */
  {  21,   0, 259}, /*  1:                  COMMA shift  259 */
  { 101,   1, 311}, /*  2:                     RP shift  311 */
/* State 313 */
  { 158,   2, 314}, /*  1:                     id shift  314 */
  {  56,   0,  95}, /*  2:                     ID shift  95 */
/* State 315 */
  {  62,   0,  50}, /*  1:              INITIALLY shift  50 */
  { 163,   0, 316}, /*  2: init_deferred_pred_opt shift  316 */
/* State 318 */
  {  91,   2, 322}, /*  1:                   PLUS shift  322 */
  {  84,   7, 329}, /*  2:                   NULL shift  329 */
  {  65,   0, 321}, /*  3:                INTEGER shift  321 */
  {  80,   0, 325}, /*  4:                  MINUS shift  325 */
  {  46,   0, 328}, /*  5:                  FLOAT shift  328 */
  { 110,   0, 319}, /*  6:                 STRING shift  319 */
  {  56,   0, 320}, /*  7:                     ID shift  320 */
/* State 322 */
  {  46,   0, 324}, /*  1:                  FLOAT shift  324 */
  {  65,   0, 323}, /*  2:                INTEGER shift  323 */
/* State 325 */
  {  46,   0, 327}, /*  1:                  FLOAT shift  327 */
  {  65,   0, 326}, /*  2:                INTEGER shift  326 */
/* State 330 */
  {  76,   2, 331}, /*  1:                     LP shift  331 */
  {  56,   0, 247}, /*  2:                     ID shift  247 */
  { 110,   0, 248}, /*  3:                 STRING shift  248 */
  { 159,   0, 342}, /*  4:                    ids shift  342 */
/* State 331 */
  {  80,   0, 340}, /*  1:                  MINUS shift  340 */
  {  65,   0, 337}, /*  2:                INTEGER shift  337 */
  { 194,   0, 332}, /*  3:                 signed shift  332 */
  {  91,   0, 338}, /*  4:                   PLUS shift  338 */
/* State 332 */
  {  21,   0, 334}, /*  1:                  COMMA shift  334 */
  { 101,   1, 333}, /*  2:                     RP shift  333 */
/* State 334 */
  {  80,   0, 340}, /*  1:                  MINUS shift  340 */
  {  65,   0, 337}, /*  2:                INTEGER shift  337 */
  { 194,   0, 335}, /*  3:                 signed shift  335 */
  {  91,   0, 338}, /*  4:                   PLUS shift  338 */
/* State 335 */
  { 101,   0, 336}, /*  1:                     RP shift  336 */
/* State 338 */
  {  65,   0, 339}, /*  1:                INTEGER shift  339 */
/* State 340 */
  {  65,   0, 341}, /*  1:                INTEGER shift  341 */
/* State 345 */
  {  48,   0, 364}, /*  1:                FOREIGN shift  364 */
  {  17,   0, 361}, /*  2:                  CHECK shift  361 */
  {  26,   0, 348}, /*  3:             CONSTRAINT shift  348 */
  {  93,   5, 350}, /*  4:                PRIMARY shift  350 */
  {  21,   0, 346}, /*  5:                  COMMA shift  346 */
  { 101,   4, 606}, /*  6:                     RP reduce 76 */
  { 119,   0, 356}, /*  7:                 UNIQUE shift  356 */
  { 199,   7, 376}, /*  8:                  tcons shift  376 */
/* State 346 */
  {  48,   0, 364}, /*  1:                FOREIGN shift  364 */
  { 199,   0, 347}, /*  2:                  tcons shift  347 */
  {  26,   0, 348}, /*  3:             CONSTRAINT shift  348 */
  {  93,   0, 350}, /*  4:                PRIMARY shift  350 */
  {  17,   0, 361}, /*  5:                  CHECK shift  361 */
  { 119,   5, 356}, /*  6:                 UNIQUE shift  356 */
/* State 348 */
  { 176,   2, 349}, /*  1:                     nm shift  349 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 350 */
  {  72,   0, 351}, /*  1:                    KEY shift  351 */
/* State 351 */
  {  76,   0, 352}, /*  1:                     LP shift  352 */
/* State 352 */
  { 110,   2,  20}, /*  1:                 STRING shift  20 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 176,   1, 261}, /*  3:                     nm shift  261 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
  { 160,   0, 262}, /*  5:                idxitem shift  262 */
  { 161,   4, 353}, /*  6:                idxlist shift  353 */
/* State 353 */
  {  21,   0, 259}, /*  1:                  COMMA shift  259 */
  { 101,   1, 354}, /*  2:                     RP shift  354 */
/* State 354 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 179,   1, 355}, /*  2:                 onconf shift  355 */
/* State 356 */
  {  76,   0, 357}, /*  1:                     LP shift  357 */
/* State 357 */
  { 110,   2,  20}, /*  1:                 STRING shift  20 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 176,   1, 261}, /*  3:                     nm shift  261 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
  { 160,   0, 262}, /*  5:                idxitem shift  262 */
  { 161,   4, 358}, /*  6:                idxlist shift  358 */
/* State 358 */
  {  21,   0, 259}, /*  1:                  COMMA shift  259 */
  { 101,   1, 359}, /*  2:                     RP shift  359 */
/* State 359 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 179,   1, 360}, /*  2:                 onconf shift  360 */
/* State 361 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 362}, /*  2:                   expr shift  362 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 362 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {  91,   0, 134}, /*  2:                   PLUS shift  134 */
  {  42,   0, 117}, /*  3:                     EQ shift  117 */
  {  13,   0, 121}, /*  4:                  BITOR shift  121 */
  {  78,   0, 107}, /*  5:                     LT shift  107 */
  {   5,   0,  99}, /*  6:                    AND shift  99 */
  {  96,   0, 142}, /*  7:                    REM shift  142 */
  {  81,  16, 115}, /*  8:                     NE shift  115 */
  {  68,   0, 147}, /*  9:                     IS shift  147 */
  {  69,   0, 146}, /* 10:                 ISNULL shift  146 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  { 102,   3, 125}, /* 13:                 RSHIFT shift  125 */
  {  73,   4, 111}, /* 14:                     LE shift  111 */
  {  74,   0, 132}, /* 15:                   LIKE shift  132 */
  {  51,   0, 113}, /* 16:                     GE shift  113 */
  { 106,   0, 140}, /* 17:                  SLASH shift  140 */
  {  77,   0, 123}, /* 18:                 LSHIFT shift  123 */
  { 108,   5, 138}, /* 19:                   STAR shift  138 */
  {  52,   0, 133}, /* 20:                   GLOB shift  133 */
  {  80,   0, 136}, /* 21:                  MINUS shift  136 */
  { 171,   8, 127}, /* 22:                 likeop shift  127 */
  {  82,  20, 129}, /* 23:                    NOT shift  129 */
  {  83,   0, 151}, /* 24:                NOTNULL shift  151 */
  {  54,  26, 109}, /* 25:                     GT shift  109 */
  {  24,   0, 144}, /* 26:                 CONCAT shift  144 */
  {  89,   0,  98}, /* 27:      ORACLE_OUTER_JOIN shift  98 */
  {  87,   0,   9}, /* 28:                     ON shift  9 */
  {  88,   0, 105}, /* 29:                     OR shift  105 */
  { 179,  27, 363}, /* 30:                 onconf shift  363 */
/* State 364 */
  {  72,   0, 365}, /*  1:                    KEY shift  365 */
/* State 365 */
  {  76,   0, 366}, /*  1:                     LP shift  366 */
/* State 366 */
  { 110,   2,  20}, /*  1:                 STRING shift  20 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 176,   1, 261}, /*  3:                     nm shift  261 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
  { 160,   0, 262}, /*  5:                idxitem shift  262 */
  { 161,   4, 367}, /*  6:                idxlist shift  367 */
/* State 367 */
  {  21,   0, 259}, /*  1:                  COMMA shift  259 */
  { 101,   1, 368}, /*  2:                     RP shift  368 */
/* State 368 */
  {  95,   0, 369}, /*  1:             REFERENCES shift  369 */
/* State 369 */
  { 176,   2, 370}, /*  1:                     nm shift  370 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 370 */
  { 162,   2, 371}, /*  1:            idxlist_opt shift  371 */
  {  76,   0, 309}, /*  2:                     LP shift  309 */
/* State 371 */
  { 187,   0, 372}, /*  1:                refargs shift  372 */
/* State 372 */
  {  30,   0, 315}, /*  1:             DEFERRABLE shift  315 */
  {  82,   0, 373}, /*  2:                    NOT shift  373 */
  {  79,   1, 295}, /*  3:                  MATCH shift  295 */
  {  87,   0, 297}, /*  4:                     ON shift  297 */
  { 186,   0, 294}, /*  5:                 refarg shift  294 */
  { 145,   2, 375}, /*  6:        defer_subclause shift  375 */
  { 146,   0, 374}, /*  7:    defer_subclause_opt shift  374 */
/* State 373 */
  {  30,   0,  48}, /*  1:             DEFERRABLE shift  48 */
/* State 379 */
  { 180,   0,  68}, /*  1:              oneselect shift  68 */
  { 103,   0,  72}, /*  2:                 SELECT shift  72 */
  { 191,   0, 380}, /*  3:                 select shift  380 */
/* State 380 */
  { 175,   0,  70}, /*  1:         multiselect_op shift  70 */
  {  66,   0, 161}, /*  2:              INTERSECT shift  161 */
  {  43,   0, 162}, /*  3:                 EXCEPT shift  162 */
  { 118,   3, 159}, /*  4:                  UNION shift  159 */
  { 104,   0, 549}, /*  5:                   SEMI reduce 19 */
/* State 381 */
  {  61,   0, 760}, /*  1:                  INDEX reduce 230 */
  { 115,   1, 400}, /*  2:                TRIGGER shift  400 */
  { 200,   0, 382}, /*  3:                   temp shift  382 */
  { 112,   0, 389}, /*  4:                   TEMP shift  389 */
  { 208,   4, 390}, /*  5:             uniqueflag shift  390 */
  { 119,   0, 399}, /*  6:                 UNIQUE shift  399 */
/* State 382 */
  { 111,   0, 383}, /*  1:                  TABLE shift  383 */
  { 125,   1, 385}, /*  2:                   VIEW shift  385 */
/* State 383 */
  { 176,   2, 384}, /*  1:                     nm shift  384 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 385 */
  { 176,   2, 386}, /*  1:                     nm shift  386 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 386 */
  {   6,   0, 387}, /*  1:                     AS shift  387 */
/* State 387 */
  { 180,   0,  68}, /*  1:              oneselect shift  68 */
  { 103,   0,  72}, /*  2:                 SELECT shift  72 */
  { 191,   0, 388}, /*  3:                 select shift  388 */
/* State 388 */
  { 175,   0,  70}, /*  1:         multiselect_op shift  70 */
  {  66,   0, 161}, /*  2:              INTERSECT shift  161 */
  {  43,   0, 162}, /*  3:                 EXCEPT shift  162 */
  { 118,   3, 159}, /*  4:                  UNION shift  159 */
  { 104,   0, 627}, /*  5:                   SEMI reduce 97 */
/* State 390 */
  {  61,   0, 391}, /*  1:                  INDEX shift  391 */
/* State 391 */
  { 176,   2, 392}, /*  1:                     nm shift  392 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 392 */
  {  87,   0, 393}, /*  1:                     ON shift  393 */
/* State 393 */
  { 176,   2, 394}, /*  1:                     nm shift  394 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 394 */
  {  76,   0, 395}, /*  1:                     LP shift  395 */
/* State 395 */
  { 110,   2,  20}, /*  1:                 STRING shift  20 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 176,   1, 261}, /*  3:                     nm shift  261 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
  { 160,   0, 262}, /*  5:                idxitem shift  262 */
  { 161,   4, 396}, /*  6:                idxlist shift  396 */
/* State 396 */
  {  21,   0, 259}, /*  1:                  COMMA shift  259 */
  { 101,   1, 397}, /*  2:                     RP shift  397 */
/* State 397 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 104,   0, 617}, /*  2:                   SEMI reduce 87 */
  { 179,   2, 398}, /*  3:                 onconf shift  398 */
/* State 398 */
  { 104,   0, 758}, /*  1:                   SEMI reduce 228 */
/* State 399 */
  {  61,   0, 759}, /*  1:                  INDEX reduce 229 */
/* State 400 */
  { 176,   2, 401}, /*  1:                     nm shift  401 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 401 */
  {  64,   4, 466}, /*  1:                INSTEAD shift  466 */
  { 205,   0, 402}, /*  2:           trigger_time shift  402 */
  {   2,   0, 465}, /*  3:                  AFTER shift  465 */
  {   8,   0, 464}, /*  4:                 BEFORE shift  464 */
/* State 402 */
  { 204,   2, 403}, /*  1:          trigger_event shift  403 */
  { 120,   3, 461}, /*  2:                 UPDATE shift  461 */
  {  32,   0, 459}, /*  3:                 DELETE shift  459 */
  {  63,   0, 460}, /*  4:                 INSERT shift  460 */
/* State 403 */
  {  87,   0, 404}, /*  1:                     ON shift  404 */
/* State 404 */
  { 176,   2, 405}, /*  1:                     nm shift  405 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 405 */
  { 154,   0, 406}, /*  1:         foreach_clause shift  406 */
  {  47,   0, 455}, /*  2:                    FOR shift  455 */
/* State 406 */
  { 210,   2, 407}, /*  1:            when_clause shift  407 */
  { 126,   3, 453}, /*  2:                   WHEN shift  453 */
  {   9,   0, 795}, /*  3:                  BEGIN reduce 265 */
/* State 407 */
  {   9,   0, 408}, /*  1:                  BEGIN shift  408 */
/* State 408 */
  { 180,   2,  68}, /*  1:              oneselect shift  68 */
  {  63,   0, 430}, /*  2:                 INSERT shift  430 */
  { 191,   0, 409}, /*  3:                 select shift  409 */
  { 120,   0, 415}, /*  4:                 UPDATE shift  415 */
  { 202,   7, 412}, /*  5:            trigger_cmd shift  412 */
  { 203,   8, 410}, /*  6:       trigger_cmd_list shift  410 */
  { 103,   9,  72}, /*  7:                 SELECT shift  72 */
  {  32,   0, 449}, /*  8:                 DELETE shift  449 */
  {  40,   0, 798}, /*  9:                    END reduce 268 */
/* State 409 */
  { 175,   0,  70}, /*  1:         multiselect_op shift  70 */
  {  66,   0, 161}, /*  2:              INTERSECT shift  161 */
  {  43,   0, 162}, /*  3:                 EXCEPT shift  162 */
  { 118,   3, 159}, /*  4:                  UNION shift  159 */
  { 104,   0, 803}, /*  5:                   SEMI reduce 273 */
/* State 410 */
  {  40,   0, 411}, /*  1:                    END shift  411 */
/* State 411 */
  { 104,   0, 783}, /*  1:                   SEMI reduce 253 */
/* State 412 */
  { 104,   0, 413}, /*  1:                   SEMI shift  413 */
/* State 413 */
  { 180,   2,  68}, /*  1:              oneselect shift  68 */
  {  63,   0, 430}, /*  2:                 INSERT shift  430 */
  { 191,   0, 409}, /*  3:                 select shift  409 */
  { 120,   0, 415}, /*  4:                 UPDATE shift  415 */
  { 202,   7, 412}, /*  5:            trigger_cmd shift  412 */
  { 203,   8, 414}, /*  6:       trigger_cmd_list shift  414 */
  { 103,   9,  72}, /*  7:                 SELECT shift  72 */
  {  32,   0, 449}, /*  8:                 DELETE shift  449 */
  {  40,   0, 798}, /*  9:                    END reduce 268 */
/* State 414 */
  {  40,   0, 797}, /*  1:                    END reduce 267 */
/* State 415 */
  {  88,   0, 416}, /*  1:                     OR shift  416 */
  { 181,   0, 418}, /*  2:                 orconf shift  418 */
/* State 416 */
  {   1,   0,  13}, /*  1:                  ABORT shift  13 */
  {  97,   1,  16}, /*  2:                REPLACE shift  16 */
  { 188,   0, 417}, /*  3:            resolvetype shift  417 */
  {  99,   5,  12}, /*  4:               ROLLBACK shift  12 */
  {  57,   6,  15}, /*  5:                 IGNORE shift  15 */
  {  45,   0,  14}, /*  6:                   FAIL shift  14 */
/* State 418 */
  { 176,   2, 419}, /*  1:                     nm shift  419 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 419 */
  { 105,   0, 420}, /*  1:                    SET shift  420 */
/* State 420 */
  { 110,   0,  20}, /*  1:                 STRING shift  20 */
  { 176,   3, 427}, /*  2:                     nm shift  427 */
  {  71,   5,  21}, /*  3:                JOIN_KW shift  21 */
  { 193,   0, 421}, /*  4:                setlist shift  421 */
  {  56,   0,  19}, /*  5:                     ID shift  19 */
/* State 421 */
  { 104,   0, 683}, /*  1:                   SEMI reduce 153 */
  {  21,   0, 422}, /*  2:                  COMMA shift  422 */
  { 127,   0, 231}, /*  3:                  WHERE shift  231 */
  { 211,   3, 426}, /*  4:              where_opt shift  426 */
/* State 422 */
  { 176,   2, 423}, /*  1:                     nm shift  423 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 423 */
  {  42,   0, 424}, /*  1:                     EQ shift  424 */
/* State 424 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 425}, /*  2:                   expr shift  425 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 425 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {   5,   0,  99}, /*  2:                    AND shift  99 */
  {  68,   0, 147}, /*  3:                     IS shift  147 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  88,   1, 105}, /*  5:                     OR shift  105 */
  {  89,   2,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  {  13,   0, 121}, /*  7:                  BITOR shift  121 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  74,   0, 132}, /*  9:                   LIKE shift  132 */
  {  78,   0, 107}, /* 10:                     LT shift  107 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  {  96,   3, 142}, /* 13:                    REM shift  142 */
  {  69,   7, 146}, /* 14:                 ISNULL shift  146 */
  {  42,   0, 117}, /* 15:                     EQ shift  117 */
  {  80,  17, 136}, /* 16:                  MINUS shift  136 */
  {  52,  20, 133}, /* 17:                   GLOB shift  133 */
  {  73,   0, 111}, /* 18:                     LE shift  111 */
  { 102,   9, 125}, /* 19:                 RSHIFT shift  125 */
  {  24,   0, 144}, /* 20:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 21:                     GT shift  109 */
  {  77,   0, 123}, /* 22:                 LSHIFT shift  123 */
  { 106,  10, 140}, /* 23:                  SLASH shift  140 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 108,  16, 138}, /* 25:                   STAR shift  138 */
  {  81,   0, 115}, /* 26:                     NE shift  115 */
  {  82,  21, 129}, /* 27:                    NOT shift  129 */
  {  83,   0, 151}, /* 28:                NOTNULL shift  151 */
/* State 426 */
  { 104,   0, 799}, /*  1:                   SEMI reduce 269 */
/* State 427 */
  {  42,   0, 428}, /*  1:                     EQ shift  428 */
/* State 428 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 429}, /*  2:                   expr shift  429 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 429 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {   5,   0,  99}, /*  2:                    AND shift  99 */
  {  68,   0, 147}, /*  3:                     IS shift  147 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  88,   1, 105}, /*  5:                     OR shift  105 */
  {  89,   2,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  {  13,   0, 121}, /*  7:                  BITOR shift  121 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  74,   0, 132}, /*  9:                   LIKE shift  132 */
  {  78,   0, 107}, /* 10:                     LT shift  107 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  {  96,   3, 142}, /* 13:                    REM shift  142 */
  {  69,   7, 146}, /* 14:                 ISNULL shift  146 */
  {  42,   0, 117}, /* 15:                     EQ shift  117 */
  {  80,  17, 136}, /* 16:                  MINUS shift  136 */
  {  52,  20, 133}, /* 17:                   GLOB shift  133 */
  {  73,   0, 111}, /* 18:                     LE shift  111 */
  { 102,   9, 125}, /* 19:                 RSHIFT shift  125 */
  {  24,   0, 144}, /* 20:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 21:                     GT shift  109 */
  {  77,   0, 123}, /* 22:                 LSHIFT shift  123 */
  { 106,  10, 140}, /* 23:                  SLASH shift  140 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 108,  16, 138}, /* 25:                   STAR shift  138 */
  {  81,   0, 115}, /* 26:                     NE shift  115 */
  {  82,  21, 129}, /* 27:                    NOT shift  129 */
  {  83,   0, 151}, /* 28:                NOTNULL shift  151 */
/* State 430 */
  {  88,   3, 416}, /*  1:                     OR shift  416 */
  { 181,   1, 431}, /*  2:                 orconf shift  431 */
  {  67,   0, 619}, /*  3:                   INTO reduce 89 */
/* State 431 */
  {  67,   0, 432}, /*  1:                   INTO shift  432 */
/* State 432 */
  { 176,   2, 433}, /*  1:                     nm shift  433 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 433 */
  { 166,   2, 440}, /*  1:         inscollist_opt shift  440 */
  {  76,   0, 434}, /*  2:                     LP shift  434 */
/* State 434 */
  { 165,   3, 435}, /*  1:             inscollist shift  435 */
  { 176,   4, 439}, /*  2:                     nm shift  439 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   5,  21}, /*  4:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  5:                     ID shift  19 */
/* State 435 */
  {  21,   0, 437}, /*  1:                  COMMA shift  437 */
  { 101,   1, 436}, /*  2:                     RP shift  436 */
/* State 437 */
  { 176,   2, 438}, /*  1:                     nm shift  438 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 440 */
  { 180,   2,  68}, /*  1:              oneselect shift  68 */
  { 124,   0, 442}, /*  2:                 VALUES shift  442 */
  { 103,   0,  72}, /*  3:                 SELECT shift  72 */
  { 191,   3, 441}, /*  4:                 select shift  441 */
/* State 441 */
  { 175,   0,  70}, /*  1:         multiselect_op shift  70 */
  {  66,   0, 161}, /*  2:              INTERSECT shift  161 */
  {  43,   0, 162}, /*  3:                 EXCEPT shift  162 */
  { 118,   3, 159}, /*  4:                  UNION shift  159 */
  { 104,   0, 801}, /*  5:                   SEMI reduce 271 */
/* State 442 */
  {  76,   0, 443}, /*  1:                     LP shift  443 */
/* State 443 */
  { 176,   4, 101}, /*  1:                     nm shift  101 */
  {  65,   0, 165}, /*  2:                INTEGER shift  165 */
  {  82,   0, 167}, /*  3:                    NOT shift  167 */
  {  80,   6, 171}, /*  4:                  MINUS shift  171 */
  {  84,   0, 100}, /*  5:                   NULL shift  100 */
  {  16,   0, 175}, /*  6:                   CASE shift  175 */
  {  71,   0,  66}, /*  7:                JOIN_KW shift  66 */
  { 151,   7, 448}, /*  8:                   expr shift  448 */
  { 168,  10, 444}, /*  9:               itemlist shift  444 */
  {  56,   0,  63}, /* 10:                     ID shift  63 */
  {  12,   0, 169}, /* 11:                 BITNOT shift  169 */
  {  91,   0, 173}, /* 12:                   PLUS shift  173 */
  {  76,  11,  67}, /* 13:                     LP shift  67 */
  {  94,  16, 185}, /* 14:                  RAISE shift  185 */
  { 110,  14,  65}, /* 15:                 STRING shift  65 */
  {  46,   0, 166}, /* 16:                  FLOAT shift  166 */
/* State 444 */
  {  21,   0, 445}, /*  1:                  COMMA shift  445 */
  { 101,   1, 447}, /*  2:                     RP shift  447 */
/* State 445 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 446}, /*  2:                   expr shift  446 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 446 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {   5,   0,  99}, /*  2:                    AND shift  99 */
  {  68,   0, 147}, /*  3:                     IS shift  147 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  88,   1, 105}, /*  5:                     OR shift  105 */
  {  89,   2,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  {  13,   0, 121}, /*  7:                  BITOR shift  121 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  74,   0, 132}, /*  9:                   LIKE shift  132 */
  {  78,   0, 107}, /* 10:                     LT shift  107 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  {  96,   3, 142}, /* 13:                    REM shift  142 */
  {  69,   7, 146}, /* 14:                 ISNULL shift  146 */
  {  42,   0, 117}, /* 15:                     EQ shift  117 */
  {  80,  17, 136}, /* 16:                  MINUS shift  136 */
  {  52,  20, 133}, /* 17:                   GLOB shift  133 */
  {  73,   0, 111}, /* 18:                     LE shift  111 */
  { 102,   9, 125}, /* 19:                 RSHIFT shift  125 */
  {  24,   0, 144}, /* 20:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 21:                     GT shift  109 */
  {  77,   0, 123}, /* 22:                 LSHIFT shift  123 */
  { 106,  10, 140}, /* 23:                  SLASH shift  140 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 108,  16, 138}, /* 25:                   STAR shift  138 */
  {  81,   0, 115}, /* 26:                     NE shift  115 */
  {  82,  21, 129}, /* 27:                    NOT shift  129 */
  {  83,   0, 151}, /* 28:                NOTNULL shift  151 */
/* State 447 */
  { 104,   0, 800}, /*  1:                   SEMI reduce 270 */
/* State 448 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {   5,   0,  99}, /*  2:                    AND shift  99 */
  {  68,   0, 147}, /*  3:                     IS shift  147 */
  { 171,   0, 127}, /*  4:                 likeop shift  127 */
  {  88,   1, 105}, /*  5:                     OR shift  105 */
  {  89,   2,  98}, /*  6:      ORACLE_OUTER_JOIN shift  98 */
  {  13,   0, 121}, /*  7:                  BITOR shift  121 */
  {  91,   0, 134}, /*  8:                   PLUS shift  134 */
  {  74,   0, 132}, /*  9:                   LIKE shift  132 */
  {  78,   0, 107}, /* 10:                     LT shift  107 */
  {  10,   0, 152}, /* 11:                BETWEEN shift  152 */
  {  11,   0, 119}, /* 12:                 BITAND shift  119 */
  {  96,   3, 142}, /* 13:                    REM shift  142 */
  {  69,   7, 146}, /* 14:                 ISNULL shift  146 */
  {  42,   0, 117}, /* 15:                     EQ shift  117 */
  {  80,  17, 136}, /* 16:                  MINUS shift  136 */
  {  52,  20, 133}, /* 17:                   GLOB shift  133 */
  {  73,   0, 111}, /* 18:                     LE shift  111 */
  { 102,   9, 125}, /* 19:                 RSHIFT shift  125 */
  {  24,   0, 144}, /* 20:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 21:                     GT shift  109 */
  {  77,   0, 123}, /* 22:                 LSHIFT shift  123 */
  { 106,  10, 140}, /* 23:                  SLASH shift  140 */
  {  51,   0, 113}, /* 24:                     GE shift  113 */
  { 108,  16, 138}, /* 25:                   STAR shift  138 */
  {  81,   0, 115}, /* 26:                     NE shift  115 */
  {  82,  21, 129}, /* 27:                    NOT shift  129 */
  {  83,   0, 151}, /* 28:                NOTNULL shift  151 */
/* State 449 */
  {  49,   0, 450}, /*  1:                   FROM shift  450 */
/* State 450 */
  { 176,   2, 451}, /*  1:                     nm shift  451 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 451 */
  { 127,   0, 231}, /*  1:                  WHERE shift  231 */
  { 211,   1, 452}, /*  2:              where_opt shift  452 */
  { 104,   0, 683}, /*  3:                   SEMI reduce 153 */
/* State 452 */
  { 104,   0, 802}, /*  1:                   SEMI reduce 272 */
/* State 453 */
  {  91,   3, 173}, /*  1:                   PLUS shift  173 */
  { 151,   1, 454}, /*  2:                   expr shift  454 */
  {  76,   4,  67}, /*  3:                     LP shift  67 */
  {  46,   7, 166}, /*  4:                  FLOAT shift  166 */
  {  94,   0, 185}, /*  5:                  RAISE shift  185 */
  { 110,   9,  65}, /*  6:                 STRING shift  65 */
  {  16,   0, 175}, /*  7:                   CASE shift  175 */
  {  82,   0, 167}, /*  8:                    NOT shift  167 */
  {  80,  11, 171}, /*  9:                  MINUS shift  171 */
  {  84,   0, 100}, /* 10:                   NULL shift  100 */
  {  65,   0, 165}, /* 11:                INTEGER shift  165 */
  { 176,  14, 101}, /* 12:                     nm shift  101 */
  {  12,   0, 169}, /* 13:                 BITNOT shift  169 */
  {  71,  15,  66}, /* 14:                JOIN_KW shift  66 */
  {  56,   0,  63}, /* 15:                     ID shift  63 */
/* State 454 */
  {  60,   0, 156}, /*  1:                     IN shift  156 */
  {  88,   0, 105}, /*  2:                     OR shift  105 */
  {  89,   1,  98}, /*  3:      ORACLE_OUTER_JOIN shift  98 */
  {   9,   0, 796}, /*  4:                  BEGIN reduce 266 */
  {  91,   0, 134}, /*  5:                   PLUS shift  134 */
  {   5,   0,  99}, /*  6:                    AND shift  99 */
  {  10,   0, 152}, /*  7:                BETWEEN shift  152 */
  {  11,   0, 119}, /*  8:                 BITAND shift  119 */
  {  13,   0, 121}, /*  9:                  BITOR shift  121 */
  {  96,   4, 142}, /* 10:                    REM shift  142 */
  {  68,   7, 147}, /* 11:                     IS shift  147 */
  {  69,   8, 146}, /* 12:                 ISNULL shift  146 */
  {  73,   0, 111}, /* 13:                     LE shift  111 */
  {  42,   9, 117}, /* 14:                     EQ shift  117 */
  {  77,   0, 123}, /* 15:                 LSHIFT shift  123 */
  { 102,  13, 125}, /* 16:                 RSHIFT shift  125 */
  {  74,   0, 132}, /* 17:                   LIKE shift  132 */
  {  51,   0, 113}, /* 18:                     GE shift  113 */
  {  52,   0, 133}, /* 19:                   GLOB shift  133 */
  { 106,  15, 140}, /* 20:                  SLASH shift  140 */
  {  78,   0, 107}, /* 21:                     LT shift  107 */
  { 108,   0, 138}, /* 22:                   STAR shift  138 */
  {  80,  18, 136}, /* 23:                  MINUS shift  136 */
  {  81,  19, 115}, /* 24:                     NE shift  115 */
  {  82,  28, 129}, /* 25:                    NOT shift  129 */
  {  83,  29, 151}, /* 26:                NOTNULL shift  151 */
  { 171,   0, 127}, /* 27:                 likeop shift  127 */
  {  24,   0, 144}, /* 28:                 CONCAT shift  144 */
  {  54,   0, 109}, /* 29:                     GT shift  109 */
/* State 455 */
  {  38,   0, 456}, /*  1:                   EACH shift  456 */
/* State 456 */
  { 100,   0, 457}, /*  1:                    ROW shift  457 */
  { 109,   0, 458}, /*  2:              STATEMENT shift  458 */
/* State 459 */
  {  87,   0, 788}, /*  1:                     ON reduce 258 */
/* State 460 */
  {  87,   0, 789}, /*  1:                     ON reduce 259 */
/* State 461 */
  {  85,   0, 462}, /*  1:                     OF shift  462 */
  {  87,   1, 790}, /*  2:                     ON reduce 260 */
/* State 462 */
  { 165,   3, 463}, /*  1:             inscollist shift  463 */
  { 176,   4, 439}, /*  2:                     nm shift  439 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   5,  21}, /*  4:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  5:                     ID shift  19 */
/* State 463 */
  {  21,   0, 437}, /*  1:                  COMMA shift  437 */
  {  87,   1, 791}, /*  2:                     ON reduce 261 */
/* State 466 */
  {  85,   0, 467}, /*  1:                     OF shift  467 */
/* State 468 */
  {  61,   0, 473}, /*  1:                  INDEX shift  473 */
  { 125,   1, 471}, /*  2:                   VIEW shift  471 */
  { 111,   0, 469}, /*  3:                  TABLE shift  469 */
  { 115,   3, 475}, /*  4:                TRIGGER shift  475 */
/* State 469 */
  { 176,   2, 470}, /*  1:                     nm shift  470 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 470 */
  { 104,   0, 626}, /*  1:                   SEMI reduce 96 */
/* State 471 */
  { 176,   2, 472}, /*  1:                     nm shift  472 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 472 */
  { 104,   0, 628}, /*  1:                   SEMI reduce 98 */
/* State 473 */
  { 176,   2, 474}, /*  1:                     nm shift  474 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 474 */
  { 104,   0, 766}, /*  1:                   SEMI reduce 236 */
/* State 475 */
  { 176,   2, 476}, /*  1:                     nm shift  476 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 476 */
  { 104,   0, 808}, /*  1:                   SEMI reduce 278 */
/* State 477 */
  { 175,   0,  70}, /*  1:         multiselect_op shift  70 */
  {  66,   0, 161}, /*  2:              INTERSECT shift  161 */
  {  43,   0, 162}, /*  3:                 EXCEPT shift  162 */
  { 118,   3, 159}, /*  4:                  UNION shift  159 */
  { 104,   0, 629}, /*  5:                   SEMI reduce 99 */
/* State 478 */
  {  49,   0, 479}, /*  1:                   FROM shift  479 */
/* State 479 */
  { 176,   2, 480}, /*  1:                     nm shift  480 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 480 */
  { 127,   0, 231}, /*  1:                  WHERE shift  231 */
  { 211,   1, 481}, /*  2:              where_opt shift  481 */
  { 104,   0, 683}, /*  3:                   SEMI reduce 153 */
/* State 481 */
  { 104,   0, 682}, /*  1:                   SEMI reduce 152 */
/* State 482 */
  {  88,   0, 416}, /*  1:                     OR shift  416 */
  { 181,   0, 483}, /*  2:                 orconf shift  483 */
/* State 483 */
  { 176,   2, 484}, /*  1:                     nm shift  484 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 484 */
  { 105,   0, 485}, /*  1:                    SET shift  485 */
/* State 485 */
  { 110,   0,  20}, /*  1:                 STRING shift  20 */
  { 176,   3, 427}, /*  2:                     nm shift  427 */
  {  71,   5,  21}, /*  3:                JOIN_KW shift  21 */
  { 193,   0, 486}, /*  4:                setlist shift  486 */
  {  56,   0,  19}, /*  5:                     ID shift  19 */
/* State 486 */
  { 104,   0, 683}, /*  1:                   SEMI reduce 153 */
  {  21,   0, 422}, /*  2:                  COMMA shift  422 */
  { 127,   0, 231}, /*  3:                  WHERE shift  231 */
  { 211,   3, 487}, /*  4:              where_opt shift  487 */
/* State 487 */
  { 104,   0, 685}, /*  1:                   SEMI reduce 155 */
/* State 488 */
  {  67,   0, 489}, /*  1:                   INTO shift  489 */
/* State 489 */
  { 176,   2, 490}, /*  1:                     nm shift  490 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 490 */
  { 166,   2, 491}, /*  1:         inscollist_opt shift  491 */
  {  76,   0, 434}, /*  2:                     LP shift  434 */
/* State 491 */
  { 180,   2,  68}, /*  1:              oneselect shift  68 */
  { 124,   0, 493}, /*  2:                 VALUES shift  493 */
  { 103,   0,  72}, /*  3:                 SELECT shift  72 */
  { 191,   3, 492}, /*  4:                 select shift  492 */
/* State 492 */
  { 175,   0,  70}, /*  1:         multiselect_op shift  70 */
  {  66,   0, 161}, /*  2:              INTERSECT shift  161 */
  {  43,   0, 162}, /*  3:                 EXCEPT shift  162 */
  { 118,   3, 159}, /*  4:                  UNION shift  159 */
  { 104,   0, 689}, /*  5:                   SEMI reduce 159 */
/* State 493 */
  {  76,   0, 494}, /*  1:                     LP shift  494 */
/* State 494 */
  { 176,   4, 101}, /*  1:                     nm shift  101 */
  {  65,   0, 165}, /*  2:                INTEGER shift  165 */
  {  82,   0, 167}, /*  3:                    NOT shift  167 */
  {  80,   6, 171}, /*  4:                  MINUS shift  171 */
  {  84,   0, 100}, /*  5:                   NULL shift  100 */
  {  16,   0, 175}, /*  6:                   CASE shift  175 */
  {  71,   0,  66}, /*  7:                JOIN_KW shift  66 */
  { 151,   7, 448}, /*  8:                   expr shift  448 */
  { 168,  10, 495}, /*  9:               itemlist shift  495 */
  {  56,   0,  63}, /* 10:                     ID shift  63 */
  {  12,   0, 169}, /* 11:                 BITNOT shift  169 */
  {  91,   0, 173}, /* 12:                   PLUS shift  173 */
  {  76,  11,  67}, /* 13:                     LP shift  67 */
  {  94,  16, 185}, /* 14:                  RAISE shift  185 */
  { 110,  14,  65}, /* 15:                 STRING shift  65 */
  {  46,   0, 166}, /* 16:                  FLOAT shift  166 */
/* State 495 */
  {  21,   0, 445}, /*  1:                  COMMA shift  445 */
  { 101,   1, 496}, /*  2:                     RP shift  496 */
/* State 496 */
  { 104,   0, 688}, /*  1:                   SEMI reduce 158 */
/* State 497 */
  {  88,   3, 416}, /*  1:                     OR shift  416 */
  { 181,   1, 498}, /*  2:                 orconf shift  498 */
  {  67,   0, 619}, /*  3:                   INTO reduce 89 */
/* State 498 */
  {  67,   0, 690}, /*  1:                   INTO reduce 160 */
/* State 499 */
  {  67,   0, 691}, /*  1:                   INTO reduce 161 */
/* State 500 */
  {  88,   0, 416}, /*  1:                     OR shift  416 */
  { 181,   0, 501}, /*  2:                 orconf shift  501 */
/* State 501 */
  { 176,   2, 502}, /*  1:                     nm shift  502 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 502 */
  {  49,   0, 503}, /*  1:                   FROM shift  503 */
/* State 503 */
  { 176,   2, 504}, /*  1:                     nm shift  504 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 504 */
  { 122,   2, 505}, /*  1:                  USING shift  505 */
  { 104,   0, 768}, /*  2:                   SEMI reduce 238 */
/* State 505 */
  {  33,   0, 506}, /*  1:             DELIMITERS shift  506 */
/* State 506 */
  { 110,   0, 507}, /*  1:                 STRING shift  507 */
/* State 507 */
  { 104,   0, 767}, /*  1:                   SEMI reduce 237 */
/* State 508 */
  { 110,   0,  20}, /*  1:                 STRING shift  20 */
  { 176,   3, 509}, /*  2:                     nm shift  509 */
  {  71,   4,  21}, /*  3:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  4:                     ID shift  19 */
  { 104,   0, 769}, /*  5:                   SEMI reduce 239 */
/* State 509 */
  { 104,   0, 770}, /*  1:                   SEMI reduce 240 */
/* State 510 */
  { 159,   0, 511}, /*  1:                    ids shift  511 */
  {  56,   0, 247}, /*  2:                     ID shift  247 */
  { 110,   2, 248}, /*  3:                 STRING shift  248 */
/* State 511 */
  {  42,   0, 512}, /*  1:                     EQ shift  512 */
  {  76,   0, 524}, /*  2:                     LP shift  524 */
  { 104,   0, 776}, /*  3:                   SEMI reduce 246 */
/* State 512 */
  { 110,   3,  20}, /*  1:                 STRING shift  20 */
  {  91,   6, 523}, /*  2:                   PLUS shift  523 */
  {  80,   0, 521}, /*  3:                  MINUS shift  521 */
  { 183,   0, 515}, /*  4:               plus_num shift  515 */
  { 184,   9, 517}, /*  5:               plus_opt shift  517 */
  {  71,   0,  21}, /*  6:                JOIN_KW shift  21 */
  { 176,  10, 513}, /*  7:                     nm shift  513 */
  {  87,   0, 514}, /*  8:                     ON shift  514 */
  { 174,   0, 516}, /*  9:              minus_num shift  516 */
  {  56,   0,  19}, /* 10:                     ID shift  19 */
/* State 513 */
  { 104,   0, 771}, /*  1:                   SEMI reduce 241 */
/* State 514 */
  { 104,   0, 772}, /*  1:                   SEMI reduce 242 */
/* State 515 */
  { 104,   0, 773}, /*  1:                   SEMI reduce 243 */
/* State 516 */
  { 104,   0, 774}, /*  1:                   SEMI reduce 244 */
/* State 517 */
  { 177,   0, 518}, /*  1:                 number shift  518 */
  {  46,   0, 520}, /*  2:                  FLOAT shift  520 */
  {  65,   0, 519}, /*  3:                INTEGER shift  519 */
/* State 518 */
  { 104,   0, 777}, /*  1:                   SEMI reduce 247 */
/* State 519 */
  { 104,   0, 779}, /*  1:                   SEMI reduce 249 */
/* State 520 */
  { 104,   0, 780}, /*  1:                   SEMI reduce 250 */
/* State 521 */
  { 177,   0, 522}, /*  1:                 number shift  522 */
  {  46,   0, 520}, /*  2:                  FLOAT shift  520 */
  {  65,   0, 519}, /*  3:                INTEGER shift  519 */
/* State 522 */
  { 104,   0, 778}, /*  1:                   SEMI reduce 248 */
/* State 524 */
  { 176,   2, 525}, /*  1:                     nm shift  525 */
  {  56,   0,  19}, /*  2:                     ID shift  19 */
  { 110,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 525 */
  { 101,   0, 526}, /*  1:                     RP shift  526 */
/* State 526 */
  { 104,   0, 775}, /*  1:                   SEMI reduce 245 */
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
  { &yyActionTable[0],   6, 536 },
  { &yyActionTable[6],   5, 536 },
  { &yyActionTable[11],   0, 532 },
  { &yyActionTable[11],  19, 809 },
  { &yyActionTable[30],   1, 809 },
  { &yyActionTable[31],   0, 533 },
  { &yyActionTable[31],   2, 538 },
  { &yyActionTable[33],   3, 809 },
  { &yyActionTable[36],   1, 809 },
  { &yyActionTable[37],   1, 809 },
  { &yyActionTable[38],   6, 809 },
  { &yyActionTable[44],   0, 618 },
  { &yyActionTable[44],   0, 621 },
  { &yyActionTable[44],   0, 622 },
  { &yyActionTable[44],   0, 623 },
  { &yyActionTable[44],   0, 624 },
  { &yyActionTable[44],   0, 625 },
  { &yyActionTable[44],   4, 539 },
  { &yyActionTable[48],   0, 540 },
  { &yyActionTable[48],   0, 557 },
  { &yyActionTable[48],   0, 558 },
  { &yyActionTable[48],   0, 559 },
  { &yyActionTable[48],   3, 809 },
  { &yyActionTable[51],   1, 809 },
  { &yyActionTable[52],   3, 809 },
  { &yyActionTable[55],   1, 809 },
  { &yyActionTable[56],   3, 809 },
  { &yyActionTable[59],   1, 809 },
  { &yyActionTable[60],   3, 809 },
  { &yyActionTable[63],   1, 809 },
  { &yyActionTable[64],   7, 809 },
  { &yyActionTable[71],   3, 809 },
  { &yyActionTable[74],   1, 809 },
  { &yyActionTable[75],   1, 809 },
  { &yyActionTable[76],  13, 809 },
  { &yyActionTable[89],   0, 550 },
  { &yyActionTable[89],   5, 560 },
  { &yyActionTable[94],   1, 570 },
  { &yyActionTable[95],  13, 552 },
  { &yyActionTable[108],   0, 569 },
  { &yyActionTable[108],   4, 809 },
  { &yyActionTable[112],  10, 809 },
  { &yyActionTable[122],   0, 571 },
  { &yyActionTable[122],   2, 617 },
  { &yyActionTable[124],   0, 582 },
  { &yyActionTable[124],   2, 809 },
  { &yyActionTable[126],   2, 617 },
  { &yyActionTable[128],   0, 583 },
  { &yyActionTable[128],   2, 602 },
  { &yyActionTable[130],   0, 600 },
  { &yyActionTable[130],   2, 809 },
  { &yyActionTable[132],   0, 603 },
  { &yyActionTable[132],   0, 604 },
  { &yyActionTable[132],   1, 809 },
  { &yyActionTable[133],   3, 670 },
  { &yyActionTable[136],   2, 617 },
  { &yyActionTable[138],   0, 584 },
  { &yyActionTable[138],   0, 668 },
  { &yyActionTable[138],   0, 669 },
  { &yyActionTable[138],   2, 617 },
  { &yyActionTable[140],   0, 585 },
  { &yyActionTable[140],   1, 809 },
  { &yyActionTable[141],  15, 809 },
  { &yyActionTable[156],   2, 700 },
  { &yyActionTable[158],  18, 757 },
  { &yyActionTable[176],   1, 706 },
  { &yyActionTable[177],   1, 701 },
  { &yyActionTable[178],  18, 809 },
  { &yyActionTable[196],   0, 630 },
  { &yyActionTable[196],   5, 809 },
  { &yyActionTable[201],   2, 809 },
  { &yyActionTable[203],   0, 631 },
  { &yyActionTable[203],   3, 639 },
  { &yyActionTable[206],   2, 641 },
  { &yyActionTable[208],   3, 648 },
  { &yyActionTable[211],   2, 683 },
  { &yyActionTable[213],   2, 673 },
  { &yyActionTable[215],   2, 675 },
  { &yyActionTable[217],   2, 663 },
  { &yyActionTable[219],   2, 677 },
  { &yyActionTable[221],   0, 636 },
  { &yyActionTable[221],   1, 809 },
  { &yyActionTable[222],   3, 678 },
  { &yyActionTable[225],   1, 809 },
  { &yyActionTable[226],   0, 679 },
  { &yyActionTable[226],   1, 809 },
  { &yyActionTable[227],   1, 809 },
  { &yyActionTable[228],   1, 809 },
  { &yyActionTable[229],  17, 809 },
  { &yyActionTable[246],   1, 664 },
  { &yyActionTable[247],  16, 809 },
  { &yyActionTable[263],   2, 671 },
  { &yyActionTable[265],   3, 670 },
  { &yyActionTable[268],   0, 665 },
  { &yyActionTable[268],   2, 809 },
  { &yyActionTable[270],   0, 554 },
  { &yyActionTable[270],   0, 672 },
  { &yyActionTable[270],  28, 667 },
  { &yyActionTable[298],   0, 703 },
  { &yyActionTable[298],  15, 809 },
  { &yyActionTable[313],   0, 699 },
  { &yyActionTable[313],   1, 809 },
  { &yyActionTable[314],   4, 809 },
  { &yyActionTable[318],   0, 702 },
  { &yyActionTable[318],  26, 709 },
  { &yyActionTable[344],  15, 809 },
  { &yyActionTable[359],  27, 710 },
  { &yyActionTable[386],  15, 809 },
  { &yyActionTable[401],  12, 711 },
  { &yyActionTable[413],  15, 809 },
  { &yyActionTable[428],  12, 712 },
  { &yyActionTable[440],  15, 809 },
  { &yyActionTable[455],  12, 713 },
  { &yyActionTable[467],  15, 809 },
  { &yyActionTable[482],  12, 714 },
  { &yyActionTable[494],  15, 809 },
  { &yyActionTable[509],  16, 715 },
  { &yyActionTable[525],  15, 809 },
  { &yyActionTable[540],  16, 716 },
  { &yyActionTable[556],  15, 809 },
  { &yyActionTable[571],   8, 717 },
  { &yyActionTable[579],  15, 809 },
  { &yyActionTable[594],   8, 718 },
  { &yyActionTable[602],  15, 809 },
  { &yyActionTable[617],   8, 719 },
  { &yyActionTable[625],  15, 809 },
  { &yyActionTable[640],   8, 720 },
  { &yyActionTable[648],  15, 809 },
  { &yyActionTable[663],  16, 721 },
  { &yyActionTable[679],   6, 809 },
  { &yyActionTable[685],  15, 809 },
  { &yyActionTable[700],  16, 722 },
  { &yyActionTable[716],   0, 723 },
  { &yyActionTable[716],   0, 724 },
  { &yyActionTable[716],  15, 809 },
  { &yyActionTable[731],   6, 725 },
  { &yyActionTable[737],  15, 809 },
  { &yyActionTable[752],   6, 726 },
  { &yyActionTable[758],  15, 809 },
  { &yyActionTable[773],   3, 727 },
  { &yyActionTable[776],  15, 809 },
  { &yyActionTable[791],   3, 728 },
  { &yyActionTable[794],  15, 809 },
  { &yyActionTable[809],   3, 729 },
  { &yyActionTable[812],  15, 809 },
  { &yyActionTable[827],   2, 730 },
  { &yyActionTable[829],   0, 731 },
  { &yyActionTable[829],   2, 809 },
  { &yyActionTable[831],   0, 732 },
  { &yyActionTable[831],   1, 809 },
  { &yyActionTable[832],   0, 735 },
  { &yyActionTable[832],   0, 733 },
  { &yyActionTable[832],  15, 809 },
  { &yyActionTable[847],  28, 809 },
  { &yyActionTable[875],  15, 809 },
  { &yyActionTable[890],  16, 741 },
  { &yyActionTable[906],   1, 809 },
  { &yyActionTable[907],  20, 757 },
  { &yyActionTable[927],   5, 809 },
  { &yyActionTable[932],   2, 809 },
  { &yyActionTable[934],   1, 809 },
  { &yyActionTable[935],   1, 809 },
  { &yyActionTable[936],   1, 809 },
  { &yyActionTable[937],   0, 744 },
  { &yyActionTable[937],  28, 756 },
  { &yyActionTable[965],   0, 704 },
  { &yyActionTable[965],   0, 705 },
  { &yyActionTable[965],  15, 809 },
  { &yyActionTable[980],  26, 736 },
  { &yyActionTable[1006],  15, 809 },
  { &yyActionTable[1021],   2, 737 },
  { &yyActionTable[1023],  15, 809 },
  { &yyActionTable[1038],   2, 738 },
  { &yyActionTable[1040],  15, 809 },
  { &yyActionTable[1055],   2, 739 },
  { &yyActionTable[1057],  17, 809 },
  { &yyActionTable[1074],  29, 809 },
  { &yyActionTable[1103],   2, 809 },
  { &yyActionTable[1105],   4, 809 },
  { &yyActionTable[1109],   1, 809 },
  { &yyActionTable[1110],   0, 747 },
  { &yyActionTable[1110],  15, 809 },
  { &yyActionTable[1125],  29, 809 },
  { &yyActionTable[1154],  15, 809 },
  { &yyActionTable[1169],  28, 748 },
  { &yyActionTable[1197],   1, 809 },
  { &yyActionTable[1198],   4, 809 },
  { &yyActionTable[1202],   1, 809 },
  { &yyActionTable[1203],   0, 804 },
  { &yyActionTable[1203],   1, 809 },
  { &yyActionTable[1204],   4, 809 },
  { &yyActionTable[1208],   1, 809 },
  { &yyActionTable[1209],   0, 805 },
  { &yyActionTable[1209],   1, 809 },
  { &yyActionTable[1210],   4, 809 },
  { &yyActionTable[1214],   1, 809 },
  { &yyActionTable[1215],   0, 806 },
  { &yyActionTable[1215],   1, 809 },
  { &yyActionTable[1216],   4, 809 },
  { &yyActionTable[1220],   1, 809 },
  { &yyActionTable[1221],   0, 807 },
  { &yyActionTable[1221],  15, 809 },
  { &yyActionTable[1236],  29, 809 },
  { &yyActionTable[1265],  15, 809 },
  { &yyActionTable[1280],  29, 809 },
  { &yyActionTable[1309],  15, 809 },
  { &yyActionTable[1324],  28, 749 },
  { &yyActionTable[1352],   2, 809 },
  { &yyActionTable[1354],   0, 743 },
  { &yyActionTable[1354],  16, 757 },
  { &yyActionTable[1370],   0, 754 },
  { &yyActionTable[1370],   0, 755 },
  { &yyActionTable[1370],   0, 734 },
  { &yyActionTable[1370],  15, 809 },
  { &yyActionTable[1385],  28, 809 },
  { &yyActionTable[1413],  15, 809 },
  { &yyActionTable[1428],  26, 742 },
  { &yyActionTable[1454],   1, 809 },
  { &yyActionTable[1455],  20, 757 },
  { &yyActionTable[1475],   5, 809 },
  { &yyActionTable[1480],   0, 746 },
  { &yyActionTable[1480],   2, 809 },
  { &yyActionTable[1482],   0, 745 },
  { &yyActionTable[1482],   2, 671 },
  { &yyActionTable[1484],   3, 670 },
  { &yyActionTable[1487],   0, 666 },
  { &yyActionTable[1487],  15, 809 },
  { &yyActionTable[1502],  28, 676 },
  { &yyActionTable[1530],   1, 809 },
  { &yyActionTable[1531],  17, 757 },
  { &yyActionTable[1548],   1, 674 },
  { &yyActionTable[1549],  15, 809 },
  { &yyActionTable[1564],  28, 684 },
  { &yyActionTable[1592],   0, 640 },
  { &yyActionTable[1592],   2, 651 },
  { &yyActionTable[1594],   4, 649 },
  { &yyActionTable[1598],   0, 650 },
  { &yyActionTable[1598],   0, 654 },
  { &yyActionTable[1598],   0, 655 },
  { &yyActionTable[1598],   5, 809 },
  { &yyActionTable[1603],   0, 656 },
  { &yyActionTable[1603],   5, 809 },
  { &yyActionTable[1608],   0, 657 },
  { &yyActionTable[1608],   1, 809 },
  { &yyActionTable[1609],   0, 658 },
  { &yyActionTable[1609],   5, 809 },
  { &yyActionTable[1614],   5, 647 },
  { &yyActionTable[1619],   0, 555 },
  { &yyActionTable[1619],   0, 556 },
  { &yyActionTable[1619],   4, 809 },
  { &yyActionTable[1623],   0, 645 },
  { &yyActionTable[1623],   0, 646 },
  { &yyActionTable[1623],   2, 660 },
  { &yyActionTable[1625],   2, 662 },
  { &yyActionTable[1627],   0, 652 },
  { &yyActionTable[1627],   1, 809 },
  { &yyActionTable[1628],   6, 809 },
  { &yyActionTable[1634],   2, 809 },
  { &yyActionTable[1636],   0, 661 },
  { &yyActionTable[1636],   5, 809 },
  { &yyActionTable[1641],   0, 763 },
  { &yyActionTable[1641],   0, 765 },
  { &yyActionTable[1641],   0, 764 },
  { &yyActionTable[1641],  15, 809 },
  { &yyActionTable[1656],  28, 659 },
  { &yyActionTable[1684],   3, 809 },
  { &yyActionTable[1687],   5, 809 },
  { &yyActionTable[1692],   5, 647 },
  { &yyActionTable[1697],   2, 660 },
  { &yyActionTable[1699],   2, 662 },
  { &yyActionTable[1701],   0, 653 },
  { &yyActionTable[1701],  16, 809 },
  { &yyActionTable[1717],  33, 647 },
  { &yyActionTable[1750],   0, 642 },
  { &yyActionTable[1750],   0, 643 },
  { &yyActionTable[1750],   1, 809 },
  { &yyActionTable[1751],   5, 809 },
  { &yyActionTable[1756],   0, 644 },
  { &yyActionTable[1756],   0, 637 },
  { &yyActionTable[1756],   0, 638 },
  { &yyActionTable[1756],   0, 740 },
  { &yyActionTable[1756],  29, 809 },
  { &yyActionTable[1785],   0, 698 },
  { &yyActionTable[1785],   2, 809 },
  { &yyActionTable[1787],   0, 707 },
  { &yyActionTable[1787],   1, 809 },
  { &yyActionTable[1788],   0, 708 },
  { &yyActionTable[1788],  29, 809 },
  { &yyActionTable[1817],   2, 617 },
  { &yyActionTable[1819],   0, 586 },
  { &yyActionTable[1819],   4, 809 },
  { &yyActionTable[1823],   2, 761 },
  { &yyActionTable[1825],   1, 590 },
  { &yyActionTable[1826],   3, 587 },
  { &yyActionTable[1829],   0, 591 },
  { &yyActionTable[1829],   4, 809 },
  { &yyActionTable[1833],   0, 592 },
  { &yyActionTable[1833],   3, 809 },
  { &yyActionTable[1836],   4, 809 },
  { &yyActionTable[1840],   0, 593 },
  { &yyActionTable[1840],   2, 809 },
  { &yyActionTable[1842],   0, 596 },
  { &yyActionTable[1842],   0, 597 },
  { &yyActionTable[1842],   0, 598 },
  { &yyActionTable[1842],   0, 599 },
  { &yyActionTable[1842],   4, 809 },
  { &yyActionTable[1846],   0, 594 },
  { &yyActionTable[1846],   4, 809 },
  { &yyActionTable[1850],   0, 595 },
  { &yyActionTable[1850],   6, 809 },
  { &yyActionTable[1856],   2, 809 },
  { &yyActionTable[1858],   0, 762 },
  { &yyActionTable[1858],   0, 588 },
  { &yyActionTable[1858],   2, 809 },
  { &yyActionTable[1860],   0, 589 },
  { &yyActionTable[1860],   2, 602 },
  { &yyActionTable[1862],   0, 601 },
  { &yyActionTable[1862],   0, 572 },
  { &yyActionTable[1862],   7, 809 },
  { &yyActionTable[1869],   0, 573 },
  { &yyActionTable[1869],   0, 574 },
  { &yyActionTable[1869],   0, 575 },
  { &yyActionTable[1869],   2, 809 },
  { &yyActionTable[1871],   0, 576 },
  { &yyActionTable[1871],   0, 579 },
  { &yyActionTable[1871],   2, 809 },
  { &yyActionTable[1873],   0, 577 },
  { &yyActionTable[1873],   0, 580 },
  { &yyActionTable[1873],   0, 578 },
  { &yyActionTable[1873],   0, 581 },
  { &yyActionTable[1873],   4, 561 },
  { &yyActionTable[1877],   4, 809 },
  { &yyActionTable[1881],   2, 809 },
  { &yyActionTable[1883],   0, 562 },
  { &yyActionTable[1883],   4, 809 },
  { &yyActionTable[1887],   1, 809 },
  { &yyActionTable[1888],   0, 563 },
  { &yyActionTable[1888],   0, 566 },
  { &yyActionTable[1888],   1, 809 },
  { &yyActionTable[1889],   0, 567 },
  { &yyActionTable[1889],   1, 809 },
  { &yyActionTable[1890],   0, 568 },
  { &yyActionTable[1890],   0, 565 },
  { &yyActionTable[1890],   0, 564 },
  { &yyActionTable[1890],   0, 553 },
  { &yyActionTable[1890],   8, 809 },
  { &yyActionTable[1898],   6, 809 },
  { &yyActionTable[1904],   0, 607 },
  { &yyActionTable[1904],   4, 809 },
  { &yyActionTable[1908],   0, 610 },
  { &yyActionTable[1908],   1, 809 },
  { &yyActionTable[1909],   1, 809 },
  { &yyActionTable[1910],   6, 809 },
  { &yyActionTable[1916],   2, 809 },
  { &yyActionTable[1918],   2, 617 },
  { &yyActionTable[1920],   0, 611 },
  { &yyActionTable[1920],   1, 809 },
  { &yyActionTable[1921],   6, 809 },
  { &yyActionTable[1927],   2, 809 },
  { &yyActionTable[1929],   2, 617 },
  { &yyActionTable[1931],   0, 612 },
  { &yyActionTable[1931],  15, 809 },
  { &yyActionTable[1946],  30, 617 },
  { &yyActionTable[1976],   0, 613 },
  { &yyActionTable[1976],   1, 809 },
  { &yyActionTable[1977],   1, 809 },
  { &yyActionTable[1978],   6, 809 },
  { &yyActionTable[1984],   2, 809 },
  { &yyActionTable[1986],   1, 809 },
  { &yyActionTable[1987],   4, 809 },
  { &yyActionTable[1991],   2, 761 },
  { &yyActionTable[1993],   1, 590 },
  { &yyActionTable[1994],   7, 615 },
  { &yyActionTable[2001],   1, 809 },
  { &yyActionTable[2002],   0, 614 },
  { &yyActionTable[2002],   0, 616 },
  { &yyActionTable[2002],   0, 608 },
  { &yyActionTable[2002],   0, 609 },
  { &yyActionTable[2002],   0, 551 },
  { &yyActionTable[2002],   3, 809 },
  { &yyActionTable[2005],   5, 809 },
  { &yyActionTable[2010],   6, 547 },
  { &yyActionTable[2016],   2, 809 },
  { &yyActionTable[2018],   4, 809 },
  { &yyActionTable[2022],   0, 545 },
  { &yyActionTable[2022],   4, 809 },
  { &yyActionTable[2026],   1, 809 },
  { &yyActionTable[2027],   3, 809 },
  { &yyActionTable[2030],   5, 809 },
  { &yyActionTable[2035],   0, 546 },
  { &yyActionTable[2035],   1, 809 },
  { &yyActionTable[2036],   4, 809 },
  { &yyActionTable[2040],   1, 809 },
  { &yyActionTable[2041],   4, 809 },
  { &yyActionTable[2045],   1, 809 },
  { &yyActionTable[2046],   6, 809 },
  { &yyActionTable[2052],   2, 809 },
  { &yyActionTable[2054],   3, 809 },
  { &yyActionTable[2057],   1, 809 },
  { &yyActionTable[2058],   1, 809 },
  { &yyActionTable[2059],   4, 809 },
  { &yyActionTable[2063],   4, 787 },
  { &yyActionTable[2067],   4, 809 },
  { &yyActionTable[2071],   1, 809 },
  { &yyActionTable[2072],   4, 809 },
  { &yyActionTable[2076],   2, 792 },
  { &yyActionTable[2078],   3, 809 },
  { &yyActionTable[2081],   1, 809 },
  { &yyActionTable[2082],   9, 809 },
  { &yyActionTable[2091],   5, 809 },
  { &yyActionTable[2096],   1, 809 },
  { &yyActionTable[2097],   1, 809 },
  { &yyActionTable[2098],   1, 809 },
  { &yyActionTable[2099],   9, 809 },
  { &yyActionTable[2108],   1, 809 },
  { &yyActionTable[2109],   2, 619 },
  { &yyActionTable[2111],   6, 809 },
  { &yyActionTable[2117],   0, 620 },
  { &yyActionTable[2117],   4, 809 },
  { &yyActionTable[2121],   1, 809 },
  { &yyActionTable[2122],   5, 809 },
  { &yyActionTable[2127],   4, 809 },
  { &yyActionTable[2131],   4, 809 },
  { &yyActionTable[2135],   1, 809 },
  { &yyActionTable[2136],  15, 809 },
  { &yyActionTable[2151],  28, 686 },
  { &yyActionTable[2179],   1, 809 },
  { &yyActionTable[2180],   1, 809 },
  { &yyActionTable[2181],  15, 809 },
  { &yyActionTable[2196],  28, 687 },
  { &yyActionTable[2224],   3, 809 },
  { &yyActionTable[2227],   1, 809 },
  { &yyActionTable[2228],   4, 809 },
  { &yyActionTable[2232],   2, 694 },
  { &yyActionTable[2234],   5, 809 },
  { &yyActionTable[2239],   2, 809 },
  { &yyActionTable[2241],   0, 695 },
  { &yyActionTable[2241],   4, 809 },
  { &yyActionTable[2245],   0, 696 },
  { &yyActionTable[2245],   0, 697 },
  { &yyActionTable[2245],   4, 809 },
  { &yyActionTable[2249],   5, 809 },
  { &yyActionTable[2254],   1, 809 },
  { &yyActionTable[2255],  16, 809 },
  { &yyActionTable[2271],   2, 809 },
  { &yyActionTable[2273],  15, 809 },
  { &yyActionTable[2288],  28, 692 },
  { &yyActionTable[2316],   1, 809 },
  { &yyActionTable[2317],  28, 693 },
  { &yyActionTable[2345],   1, 809 },
  { &yyActionTable[2346],   4, 809 },
  { &yyActionTable[2350],   3, 809 },
  { &yyActionTable[2353],   1, 809 },
  { &yyActionTable[2354],  15, 809 },
  { &yyActionTable[2369],  29, 809 },
  { &yyActionTable[2398],   1, 809 },
  { &yyActionTable[2399],   2, 809 },
  { &yyActionTable[2401],   0, 793 },
  { &yyActionTable[2401],   0, 794 },
  { &yyActionTable[2401],   1, 809 },
  { &yyActionTable[2402],   1, 809 },
  { &yyActionTable[2403],   2, 809 },
  { &yyActionTable[2405],   5, 809 },
  { &yyActionTable[2410],   2, 809 },
  { &yyActionTable[2412],   0, 784 },
  { &yyActionTable[2412],   0, 785 },
  { &yyActionTable[2412],   1, 809 },
  { &yyActionTable[2413],   0, 786 },
  { &yyActionTable[2413],   4, 809 },
  { &yyActionTable[2417],   4, 809 },
  { &yyActionTable[2421],   1, 809 },
  { &yyActionTable[2422],   4, 809 },
  { &yyActionTable[2426],   1, 809 },
  { &yyActionTable[2427],   4, 809 },
  { &yyActionTable[2431],   1, 809 },
  { &yyActionTable[2432],   4, 809 },
  { &yyActionTable[2436],   1, 809 },
  { &yyActionTable[2437],   5, 809 },
  { &yyActionTable[2442],   1, 809 },
  { &yyActionTable[2443],   4, 809 },
  { &yyActionTable[2447],   3, 809 },
  { &yyActionTable[2450],   1, 809 },
  { &yyActionTable[2451],   2, 619 },
  { &yyActionTable[2453],   4, 809 },
  { &yyActionTable[2457],   1, 809 },
  { &yyActionTable[2458],   5, 809 },
  { &yyActionTable[2463],   4, 809 },
  { &yyActionTable[2467],   1, 809 },
  { &yyActionTable[2468],   1, 809 },
  { &yyActionTable[2469],   4, 809 },
  { &yyActionTable[2473],   2, 694 },
  { &yyActionTable[2475],   4, 809 },
  { &yyActionTable[2479],   5, 809 },
  { &yyActionTable[2484],   1, 809 },
  { &yyActionTable[2485],  16, 809 },
  { &yyActionTable[2501],   2, 809 },
  { &yyActionTable[2503],   1, 809 },
  { &yyActionTable[2504],   3, 809 },
  { &yyActionTable[2507],   1, 809 },
  { &yyActionTable[2508],   1, 809 },
  { &yyActionTable[2509],   2, 619 },
  { &yyActionTable[2511],   4, 809 },
  { &yyActionTable[2515],   1, 809 },
  { &yyActionTable[2516],   4, 809 },
  { &yyActionTable[2520],   2, 809 },
  { &yyActionTable[2522],   1, 809 },
  { &yyActionTable[2523],   1, 809 },
  { &yyActionTable[2524],   1, 809 },
  { &yyActionTable[2525],   5, 809 },
  { &yyActionTable[2530],   1, 809 },
  { &yyActionTable[2531],   3, 809 },
  { &yyActionTable[2534],   3, 809 },
  { &yyActionTable[2537],  10, 782 },
  { &yyActionTable[2547],   1, 809 },
  { &yyActionTable[2548],   1, 809 },
  { &yyActionTable[2549],   1, 809 },
  { &yyActionTable[2550],   1, 809 },
  { &yyActionTable[2551],   3, 809 },
  { &yyActionTable[2554],   1, 809 },
  { &yyActionTable[2555],   1, 809 },
  { &yyActionTable[2556],   1, 809 },
  { &yyActionTable[2557],   3, 809 },
  { &yyActionTable[2560],   1, 809 },
  { &yyActionTable[2561],   0, 781 },
  { &yyActionTable[2561],   4, 809 },
  { &yyActionTable[2565],   1, 809 },
  { &yyActionTable[2566],   1, 809 },
  { &yyActionTable[2567],   0, 534 },
  { &yyActionTable[2567],   0, 535 },
  { &yyActionTable[2567],   0, 531 },
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
    0,  /* ORACLE_OUTER_JOIN => nothing */
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
  "OR",            "ORACLE_OUTER_JOIN",  "ORDER",         "PLUS",        
  "PRAGMA",        "PRIMARY",       "RAISE",         "REFERENCES",  
  "REM",           "REPLACE",       "RESTRICT",      "ROLLBACK",    
  "ROW",           "RP",            "RSHIFT",        "SELECT",      
  "SEMI",          "SET",           "SLASH",         "SPACE",       
  "STAR",          "STATEMENT",     "STRING",        "TABLE",       
  "TEMP",          "THEN",          "TRANSACTION",   "TRIGGER",     
  "UMINUS",        "UNCLOSED_STRING",  "UNION",         "UNIQUE",      
  "UPDATE",        "UPLUS",         "USING",         "VACUUM",      
  "VALUES",        "VIEW",          "WHEN",          "WHERE",       
  "as",            "carg",          "carglist",      "case_else",   
  "case_exprlist",  "case_operand",  "ccons",         "cmd",         
  "cmdlist",       "collate",       "column",        "columnid",    
  "columnlist",    "conslist",      "conslist_opt",  "create_table",
  "create_table_args",  "defer_subclause",  "defer_subclause_opt",  "distinct",    
  "ecmd",          "error",         "explain",       "expr",        
  "expritem",      "exprlist",      "foreach_clause",  "from",        
  "groupby_opt",   "having_opt",    "id",            "ids",         
  "idxitem",       "idxlist",       "idxlist_opt",   "init_deferred_pred_opt",
  "input",         "inscollist",    "inscollist_opt",  "insert_cmd",  
  "itemlist",      "joinop",        "joinop2",       "likeop",      
  "limit_opt",     "limit_sep",     "minus_num",     "multiselect_op",
  "nm",            "number",        "on_opt",        "onconf",      
  "oneselect",     "orconf",        "orderby_opt",   "plus_num",    
  "plus_opt",      "refact",        "refarg",        "refargs",     
  "resolvetype",   "sclp",          "selcollist",    "select",      
  "seltablist",    "setlist",       "signed",        "sortitem",    
  "sortlist",      "sortorder",     "stl_prefix",    "tcons",       
  "temp",          "trans_opt",     "trigger_cmd",   "trigger_cmd_list",
  "trigger_event",  "trigger_time",  "type",          "typename",    
  "uniqueflag",    "using_opt",     "when_clause",   "where_opt",   
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
 /* 173 */ "expr ::= expr ORACLE_OUTER_JOIN",
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
 /* 231 */ "idxlist_opt ::=",
 /* 232 */ "idxlist_opt ::= LP idxlist RP",
 /* 233 */ "idxlist ::= idxlist COMMA idxitem",
 /* 234 */ "idxlist ::= idxitem",
 /* 235 */ "idxitem ::= nm",
 /* 236 */ "cmd ::= DROP INDEX nm",
 /* 237 */ "cmd ::= COPY orconf nm FROM nm USING DELIMITERS STRING",
 /* 238 */ "cmd ::= COPY orconf nm FROM nm",
 /* 239 */ "cmd ::= VACUUM",
 /* 240 */ "cmd ::= VACUUM nm",
 /* 241 */ "cmd ::= PRAGMA ids EQ nm",
 /* 242 */ "cmd ::= PRAGMA ids EQ ON",
 /* 243 */ "cmd ::= PRAGMA ids EQ plus_num",
 /* 244 */ "cmd ::= PRAGMA ids EQ minus_num",
 /* 245 */ "cmd ::= PRAGMA ids LP nm RP",
 /* 246 */ "cmd ::= PRAGMA ids",
 /* 247 */ "plus_num ::= plus_opt number",
 /* 248 */ "minus_num ::= MINUS number",
 /* 249 */ "number ::= INTEGER",
 /* 250 */ "number ::= FLOAT",
 /* 251 */ "plus_opt ::= PLUS",
 /* 252 */ "plus_opt ::=",
 /* 253 */ "cmd ::= CREATE TRIGGER nm trigger_time trigger_event ON nm foreach_clause when_clause BEGIN trigger_cmd_list END",
 /* 254 */ "trigger_time ::= BEFORE",
 /* 255 */ "trigger_time ::= AFTER",
 /* 256 */ "trigger_time ::= INSTEAD OF",
 /* 257 */ "trigger_time ::=",
 /* 258 */ "trigger_event ::= DELETE",
 /* 259 */ "trigger_event ::= INSERT",
 /* 260 */ "trigger_event ::= UPDATE",
 /* 261 */ "trigger_event ::= UPDATE OF inscollist",
 /* 262 */ "foreach_clause ::=",
 /* 263 */ "foreach_clause ::= FOR EACH ROW",
 /* 264 */ "foreach_clause ::= FOR EACH STATEMENT",
 /* 265 */ "when_clause ::=",
 /* 266 */ "when_clause ::= WHEN expr",
 /* 267 */ "trigger_cmd_list ::= trigger_cmd SEMI trigger_cmd_list",
 /* 268 */ "trigger_cmd_list ::=",
 /* 269 */ "trigger_cmd ::= UPDATE orconf nm SET setlist where_opt",
 /* 270 */ "trigger_cmd ::= INSERT orconf INTO nm inscollist_opt VALUES LP itemlist RP",
 /* 271 */ "trigger_cmd ::= INSERT orconf INTO nm inscollist_opt select",
 /* 272 */ "trigger_cmd ::= DELETE FROM nm where_opt",
 /* 273 */ "trigger_cmd ::= select",
 /* 274 */ "expr ::= RAISE LP IGNORE RP",
 /* 275 */ "expr ::= RAISE LP ROLLBACK COMMA nm RP",
 /* 276 */ "expr ::= RAISE LP ABORT COMMA nm RP",
 /* 277 */ "expr ::= RAISE LP FAIL COMMA nm RP",
 /* 278 */ "cmd ::= DROP TRIGGER nm",
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
    case 132:
#line 651 "parse.y"
{sqliteExprListDelete((yypminor->yy256));}
#line 4262 "parse.c"
      break;
    case 151:
#line 505 "parse.y"
{sqliteExprDelete((yypminor->yy202));}
#line 4267 "parse.c"
      break;
    case 152:
#line 670 "parse.y"
{sqliteExprDelete((yypminor->yy202));}
#line 4272 "parse.c"
      break;
    case 153:
#line 668 "parse.y"
{sqliteExprListDelete((yypminor->yy256));}
#line 4277 "parse.c"
      break;
    case 155:
#line 332 "parse.y"
{sqliteSrcListDelete((yypminor->yy395));}
#line 4282 "parse.c"
      break;
    case 156:
#line 422 "parse.y"
{sqliteExprListDelete((yypminor->yy256));}
#line 4287 "parse.c"
      break;
    case 157:
#line 427 "parse.y"
{sqliteExprDelete((yypminor->yy202));}
#line 4292 "parse.c"
      break;
    case 161:
#line 692 "parse.y"
{sqliteIdListDelete((yypminor->yy154));}
#line 4297 "parse.c"
      break;
    case 162:
#line 694 "parse.y"
{sqliteIdListDelete((yypminor->yy154));}
#line 4302 "parse.c"
      break;
    case 165:
#line 483 "parse.y"
{sqliteIdListDelete((yypminor->yy154));}
#line 4307 "parse.c"
      break;
    case 166:
#line 481 "parse.y"
{sqliteIdListDelete((yypminor->yy154));}
#line 4312 "parse.c"
      break;
    case 168:
#line 475 "parse.y"
{sqliteExprListDelete((yypminor->yy256));}
#line 4317 "parse.c"
      break;
    case 178:
#line 383 "parse.y"
{sqliteExprDelete((yypminor->yy202));}
#line 4322 "parse.c"
      break;
    case 180:
#line 267 "parse.y"
{sqliteSelectDelete((yypminor->yy91));}
#line 4327 "parse.c"
      break;
    case 182:
#line 394 "parse.y"
{sqliteExprListDelete((yypminor->yy256));}
#line 4332 "parse.c"
      break;
    case 189:
#line 303 "parse.y"
{sqliteExprListDelete((yypminor->yy256));}
#line 4337 "parse.c"
      break;
    case 190:
#line 301 "parse.y"
{sqliteExprListDelete((yypminor->yy256));}
#line 4342 "parse.c"
      break;
    case 191:
#line 265 "parse.y"
{sqliteSelectDelete((yypminor->yy91));}
#line 4347 "parse.c"
      break;
    case 192:
#line 328 "parse.y"
{sqliteSrcListDelete((yypminor->yy395));}
#line 4352 "parse.c"
      break;
    case 193:
#line 451 "parse.y"
{sqliteExprListDelete((yypminor->yy256));}
#line 4357 "parse.c"
      break;
    case 195:
#line 398 "parse.y"
{sqliteExprDelete((yypminor->yy202));}
#line 4362 "parse.c"
      break;
    case 196:
#line 396 "parse.y"
{sqliteExprListDelete((yypminor->yy256));}
#line 4367 "parse.c"
      break;
    case 198:
#line 330 "parse.y"
{sqliteSrcListDelete((yypminor->yy395));}
#line 4372 "parse.c"
      break;
    case 204:
#line 753 "parse.y"
{sqliteIdListDelete((yypminor->yy146).b);}
#line 4377 "parse.c"
      break;
    case 209:
#line 388 "parse.y"
{sqliteIdListDelete((yypminor->yy154));}
#line 4382 "parse.c"
      break;
    case 211:
#line 445 "parse.y"
{sqliteExprDelete((yypminor->yy202));}
#line 4387 "parse.c"
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
  { 164, 1 },
  { 136, 1 },
  { 136, 2 },
  { 148, 3 },
  { 148, 1 },
  { 150, 1 },
  { 150, 0 },
  { 135, 3 },
  { 201, 0 },
  { 201, 1 },
  { 201, 2 },
  { 135, 2 },
  { 135, 2 },
  { 135, 2 },
  { 135, 2 },
  { 143, 4 },
  { 200, 1 },
  { 200, 0 },
  { 144, 4 },
  { 144, 2 },
  { 140, 3 },
  { 140, 1 },
  { 138, 3 },
  { 139, 1 },
  { 158, 1 },
  { 159, 1 },
  { 159, 1 },
  { 176, 1 },
  { 176, 1 },
  { 176, 1 },
  { 206, 0 },
  { 206, 1 },
  { 206, 4 },
  { 206, 6 },
  { 207, 1 },
  { 207, 2 },
  { 194, 1 },
  { 194, 2 },
  { 194, 2 },
  { 130, 2 },
  { 130, 0 },
  { 129, 3 },
  { 129, 1 },
  { 129, 2 },
  { 129, 2 },
  { 129, 2 },
  { 129, 3 },
  { 129, 3 },
  { 129, 2 },
  { 129, 3 },
  { 129, 3 },
  { 129, 2 },
  { 134, 2 },
  { 134, 3 },
  { 134, 4 },
  { 134, 2 },
  { 134, 5 },
  { 134, 4 },
  { 134, 1 },
  { 134, 2 },
  { 187, 0 },
  { 187, 2 },
  { 186, 2 },
  { 186, 3 },
  { 186, 3 },
  { 186, 3 },
  { 185, 2 },
  { 185, 2 },
  { 185, 1 },
  { 185, 1 },
  { 145, 3 },
  { 145, 2 },
  { 163, 0 },
  { 163, 2 },
  { 163, 2 },
  { 142, 0 },
  { 142, 2 },
  { 141, 3 },
  { 141, 2 },
  { 141, 1 },
  { 199, 2 },
  { 199, 6 },
  { 199, 5 },
  { 199, 3 },
  { 199, 10 },
  { 146, 0 },
  { 146, 1 },
  { 179, 0 },
  { 179, 3 },
  { 181, 0 },
  { 181, 2 },
  { 188, 1 },
  { 188, 1 },
  { 188, 1 },
  { 188, 1 },
  { 188, 1 },
  { 135, 3 },
  { 135, 6 },
  { 135, 3 },
  { 135, 1 },
  { 191, 1 },
  { 191, 3 },
  { 175, 1 },
  { 175, 2 },
  { 175, 1 },
  { 175, 1 },
  { 180, 9 },
  { 147, 1 },
  { 147, 1 },
  { 147, 0 },
  { 189, 2 },
  { 189, 0 },
  { 190, 3 },
  { 190, 2 },
  { 190, 4 },
  { 128, 2 },
  { 128, 1 },
  { 128, 0 },
  { 155, 0 },
  { 155, 2 },
  { 198, 2 },
  { 198, 0 },
  { 192, 5 },
  { 192, 7 },
  { 169, 1 },
  { 169, 1 },
  { 169, 2 },
  { 169, 3 },
  { 169, 4 },
  { 178, 2 },
  { 178, 0 },
  { 209, 4 },
  { 209, 0 },
  { 182, 0 },
  { 182, 3 },
  { 196, 5 },
  { 196, 3 },
  { 195, 1 },
  { 197, 1 },
  { 197, 1 },
  { 197, 0 },
  { 137, 0 },
  { 137, 2 },
  { 156, 0 },
  { 156, 3 },
  { 157, 0 },
  { 157, 2 },
  { 172, 0 },
  { 172, 2 },
  { 172, 4 },
  { 173, 1 },
  { 173, 1 },
  { 135, 4 },
  { 211, 0 },
  { 211, 2 },
  { 135, 6 },
  { 193, 5 },
  { 193, 3 },
  { 135, 8 },
  { 135, 5 },
  { 167, 2 },
  { 167, 1 },
  { 168, 3 },
  { 168, 1 },
  { 166, 0 },
  { 166, 3 },
  { 165, 3 },
  { 165, 1 },
  { 151, 3 },
  { 151, 1 },
  { 151, 1 },
  { 151, 1 },
  { 151, 3 },
  { 151, 2 },
  { 151, 1 },
  { 151, 1 },
  { 151, 1 },
  { 151, 4 },
  { 151, 4 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 4 },
  { 171, 1 },
  { 171, 1 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 3 },
  { 151, 2 },
  { 151, 3 },
  { 151, 2 },
  { 151, 3 },
  { 151, 4 },
  { 151, 2 },
  { 151, 2 },
  { 151, 2 },
  { 151, 2 },
  { 151, 3 },
  { 151, 5 },
  { 151, 6 },
  { 151, 5 },
  { 151, 5 },
  { 151, 6 },
  { 151, 6 },
  { 151, 5 },
  { 132, 5 },
  { 132, 4 },
  { 131, 2 },
  { 131, 0 },
  { 133, 1 },
  { 133, 0 },
  { 153, 3 },
  { 153, 1 },
  { 152, 1 },
  { 152, 0 },
  { 135, 10 },
  { 208, 1 },
  { 208, 0 },
  { 162, 0 },
  { 162, 3 },
  { 161, 3 },
  { 161, 1 },
  { 160, 1 },
  { 135, 3 },
  { 135, 8 },
  { 135, 5 },
  { 135, 1 },
  { 135, 2 },
  { 135, 4 },
  { 135, 4 },
  { 135, 4 },
  { 135, 4 },
  { 135, 5 },
  { 135, 2 },
  { 183, 2 },
  { 174, 2 },
  { 177, 1 },
  { 177, 1 },
  { 184, 1 },
  { 184, 0 },
  { 135, 12 },
  { 205, 1 },
  { 205, 1 },
  { 205, 2 },
  { 205, 0 },
  { 204, 1 },
  { 204, 1 },
  { 204, 1 },
  { 204, 3 },
  { 154, 0 },
  { 154, 3 },
  { 154, 3 },
  { 210, 0 },
  { 210, 2 },
  { 203, 3 },
  { 203, 0 },
  { 202, 6 },
  { 202, 9 },
  { 202, 6 },
  { 202, 4 },
  { 202, 1 },
  { 151, 4 },
  { 151, 6 },
  { 151, 6 },
  { 151, 6 },
  { 135, 3 },
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
#line 4861 "parse.c"
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
#line 4872 "parse.c"
        /* No destructor defined for EXPLAIN */
        break;
      case 6:
#line 70 "parse.y"
{ sqliteBeginParse(pParse, 0); }
#line 4878 "parse.c"
        break;
      case 7:
#line 75 "parse.y"
{sqliteBeginTransaction(pParse,yymsp[0].minor.yy276);}
#line 4883 "parse.c"
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
#line 4899 "parse.c"
        /* No destructor defined for COMMIT */
        /* No destructor defined for trans_opt */
        break;
      case 12:
#line 80 "parse.y"
{sqliteCommitTransaction(pParse);}
#line 4906 "parse.c"
        /* No destructor defined for END */
        /* No destructor defined for trans_opt */
        break;
      case 13:
#line 81 "parse.y"
{sqliteRollbackTransaction(pParse);}
#line 4913 "parse.c"
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
   sqliteStartTable(pParse,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy58,yymsp[-2].minor.yy276);
}
#line 4926 "parse.c"
        /* No destructor defined for TABLE */
        break;
      case 16:
#line 90 "parse.y"
{yygotominor.yy276 = pParse->isTemp || !pParse->initFlag;}
#line 4932 "parse.c"
        /* No destructor defined for TEMP */
        break;
      case 17:
#line 91 "parse.y"
{yygotominor.yy276 = pParse->isTemp;}
#line 4938 "parse.c"
        break;
      case 18:
#line 92 "parse.y"
{
  sqliteEndTable(pParse,&yymsp[0].minor.yy0,0);
}
#line 4945 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for columnlist */
        /* No destructor defined for conslist_opt */
        break;
      case 19:
#line 95 "parse.y"
{
  sqliteEndTable(pParse,0,yymsp[0].minor.yy91);
  sqliteSelectDelete(yymsp[0].minor.yy91);
}
#line 4956 "parse.c"
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
{sqliteAddColumn(pParse,&yymsp[0].minor.yy58);}
#line 4975 "parse.c"
        break;
      case 24:
#line 113 "parse.y"
{yygotominor.yy58 = yymsp[0].minor.yy0;}
#line 4980 "parse.c"
        break;
      case 25:
#line 129 "parse.y"
{yygotominor.yy58 = yymsp[0].minor.yy0;}
#line 4985 "parse.c"
        break;
      case 26:
#line 130 "parse.y"
{yygotominor.yy58 = yymsp[0].minor.yy0;}
#line 4990 "parse.c"
        break;
      case 27:
#line 135 "parse.y"
{yygotominor.yy58 = yymsp[0].minor.yy0;}
#line 4995 "parse.c"
        break;
      case 28:
#line 136 "parse.y"
{yygotominor.yy58 = yymsp[0].minor.yy0;}
#line 5000 "parse.c"
        break;
      case 29:
#line 137 "parse.y"
{yygotominor.yy58 = yymsp[0].minor.yy0;}
#line 5005 "parse.c"
        break;
      case 30:
        break;
      case 31:
#line 140 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[0].minor.yy58,&yymsp[0].minor.yy58);}
#line 5012 "parse.c"
        break;
      case 32:
#line 141 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-3].minor.yy58,&yymsp[0].minor.yy0);}
#line 5017 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        break;
      case 33:
#line 143 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-5].minor.yy58,&yymsp[0].minor.yy0);}
#line 5024 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        /* No destructor defined for COMMA */
        /* No destructor defined for signed */
        break;
      case 34:
#line 145 "parse.y"
{yygotominor.yy58 = yymsp[0].minor.yy58;}
#line 5033 "parse.c"
        break;
      case 35:
#line 146 "parse.y"
{yygotominor.yy58 = yymsp[-1].minor.yy58;}
#line 5038 "parse.c"
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
#line 5069 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 44:
#line 155 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5075 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 45:
#line 156 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5081 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 46:
#line 157 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5087 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 47:
#line 158 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 5094 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 48:
#line 159 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5101 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 49:
#line 160 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5107 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 50:
#line 161 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 5114 "parse.c"
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
{sqliteAddNotNull(pParse, yymsp[0].minor.yy276);}
#line 5129 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for NULL */
        break;
      case 54:
#line 169 "parse.y"
{sqliteAddPrimaryKey(pParse,0,yymsp[0].minor.yy276);}
#line 5136 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for sortorder */
        break;
      case 55:
#line 170 "parse.y"
{sqliteCreateIndex(pParse,0,0,0,yymsp[0].minor.yy276,0,0);}
#line 5144 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 56:
        /* No destructor defined for CHECK */
        /* No destructor defined for LP */
  yy_destructor(151,&yymsp[-2].minor);
        /* No destructor defined for RP */
        /* No destructor defined for onconf */
        break;
      case 57:
#line 173 "parse.y"
{sqliteCreateForeignKey(pParse,0,&yymsp[-2].minor.yy58,yymsp[-1].minor.yy154,yymsp[0].minor.yy276);}
#line 5157 "parse.c"
        /* No destructor defined for REFERENCES */
        break;
      case 58:
#line 174 "parse.y"
{sqliteDeferForeignKey(pParse,yymsp[0].minor.yy276);}
#line 5163 "parse.c"
        break;
      case 59:
#line 175 "parse.y"
{
   sqliteAddCollateType(pParse, sqliteCollateType(pParse, &yymsp[0].minor.yy58));
}
#line 5170 "parse.c"
        /* No destructor defined for COLLATE */
        break;
      case 60:
#line 185 "parse.y"
{ yygotominor.yy276 = OE_Restrict * 0x010101; }
#line 5176 "parse.c"
        break;
      case 61:
#line 186 "parse.y"
{ yygotominor.yy276 = (yymsp[-1].minor.yy276 & yymsp[0].minor.yy99.mask) | yymsp[0].minor.yy99.value; }
#line 5181 "parse.c"
        break;
      case 62:
#line 188 "parse.y"
{ yygotominor.yy99.value = 0;     yygotominor.yy99.mask = 0x000000; }
#line 5186 "parse.c"
        /* No destructor defined for MATCH */
        /* No destructor defined for nm */
        break;
      case 63:
#line 189 "parse.y"
{ yygotominor.yy99.value = yymsp[0].minor.yy276;     yygotominor.yy99.mask = 0x0000ff; }
#line 5193 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for DELETE */
        break;
      case 64:
#line 190 "parse.y"
{ yygotominor.yy99.value = yymsp[0].minor.yy276<<8;  yygotominor.yy99.mask = 0x00ff00; }
#line 5200 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for UPDATE */
        break;
      case 65:
#line 191 "parse.y"
{ yygotominor.yy99.value = yymsp[0].minor.yy276<<16; yygotominor.yy99.mask = 0xff0000; }
#line 5207 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for INSERT */
        break;
      case 66:
#line 193 "parse.y"
{ yygotominor.yy276 = OE_SetNull; }
#line 5214 "parse.c"
        /* No destructor defined for SET */
        /* No destructor defined for NULL */
        break;
      case 67:
#line 194 "parse.y"
{ yygotominor.yy276 = OE_SetDflt; }
#line 5221 "parse.c"
        /* No destructor defined for SET */
        /* No destructor defined for DEFAULT */
        break;
      case 68:
#line 195 "parse.y"
{ yygotominor.yy276 = OE_Cascade; }
#line 5228 "parse.c"
        /* No destructor defined for CASCADE */
        break;
      case 69:
#line 196 "parse.y"
{ yygotominor.yy276 = OE_Restrict; }
#line 5234 "parse.c"
        /* No destructor defined for RESTRICT */
        break;
      case 70:
#line 198 "parse.y"
{yygotominor.yy276 = yymsp[0].minor.yy276;}
#line 5240 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for DEFERRABLE */
        break;
      case 71:
#line 199 "parse.y"
{yygotominor.yy276 = yymsp[0].minor.yy276;}
#line 5247 "parse.c"
        /* No destructor defined for DEFERRABLE */
        break;
      case 72:
#line 201 "parse.y"
{yygotominor.yy276 = 0;}
#line 5253 "parse.c"
        break;
      case 73:
#line 202 "parse.y"
{yygotominor.yy276 = 1;}
#line 5258 "parse.c"
        /* No destructor defined for INITIALLY */
        /* No destructor defined for DEFERRED */
        break;
      case 74:
#line 203 "parse.y"
{yygotominor.yy276 = 0;}
#line 5265 "parse.c"
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
{sqliteAddPrimaryKey(pParse,yymsp[-2].minor.yy154,yymsp[0].minor.yy276);}
#line 5294 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 82:
#line 217 "parse.y"
{sqliteCreateIndex(pParse,0,0,yymsp[-2].minor.yy154,yymsp[0].minor.yy276,0,0);}
#line 5303 "parse.c"
        /* No destructor defined for UNIQUE */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 83:
        /* No destructor defined for CHECK */
  yy_destructor(151,&yymsp[-1].minor);
        /* No destructor defined for onconf */
        break;
      case 84:
#line 220 "parse.y"
{
    sqliteCreateForeignKey(pParse, yymsp[-6].minor.yy154, &yymsp[-3].minor.yy58, yymsp[-2].minor.yy154, yymsp[-1].minor.yy276);
    sqliteDeferForeignKey(pParse, yymsp[0].minor.yy276);
}
#line 5319 "parse.c"
        /* No destructor defined for FOREIGN */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        /* No destructor defined for REFERENCES */
        break;
      case 85:
#line 225 "parse.y"
{yygotominor.yy276 = 0;}
#line 5329 "parse.c"
        break;
      case 86:
#line 226 "parse.y"
{yygotominor.yy276 = yymsp[0].minor.yy276;}
#line 5334 "parse.c"
        break;
      case 87:
#line 234 "parse.y"
{ yygotominor.yy276 = OE_Default; }
#line 5339 "parse.c"
        break;
      case 88:
#line 235 "parse.y"
{ yygotominor.yy276 = yymsp[0].minor.yy276; }
#line 5344 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for CONFLICT */
        break;
      case 89:
#line 236 "parse.y"
{ yygotominor.yy276 = OE_Default; }
#line 5351 "parse.c"
        break;
      case 90:
#line 237 "parse.y"
{ yygotominor.yy276 = yymsp[0].minor.yy276; }
#line 5356 "parse.c"
        /* No destructor defined for OR */
        break;
      case 91:
#line 238 "parse.y"
{ yygotominor.yy276 = OE_Rollback; }
#line 5362 "parse.c"
        /* No destructor defined for ROLLBACK */
        break;
      case 92:
#line 239 "parse.y"
{ yygotominor.yy276 = OE_Abort; }
#line 5368 "parse.c"
        /* No destructor defined for ABORT */
        break;
      case 93:
#line 240 "parse.y"
{ yygotominor.yy276 = OE_Fail; }
#line 5374 "parse.c"
        /* No destructor defined for FAIL */
        break;
      case 94:
#line 241 "parse.y"
{ yygotominor.yy276 = OE_Ignore; }
#line 5380 "parse.c"
        /* No destructor defined for IGNORE */
        break;
      case 95:
#line 242 "parse.y"
{ yygotominor.yy276 = OE_Replace; }
#line 5386 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 96:
#line 246 "parse.y"
{sqliteDropTable(pParse,&yymsp[0].minor.yy58,0);}
#line 5392 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for TABLE */
        break;
      case 97:
#line 250 "parse.y"
{
  sqliteCreateView(pParse, &yymsp[-5].minor.yy0, &yymsp[-2].minor.yy58, yymsp[0].minor.yy91, yymsp[-4].minor.yy276);
}
#line 5401 "parse.c"
        /* No destructor defined for VIEW */
        /* No destructor defined for AS */
        break;
      case 98:
#line 253 "parse.y"
{
  sqliteDropTable(pParse, &yymsp[0].minor.yy58, 1);
}
#line 5410 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for VIEW */
        break;
      case 99:
#line 259 "parse.y"
{
  sqliteSelect(pParse, yymsp[0].minor.yy91, SRT_Callback, 0, 0, 0, 0);
  sqliteSelectDelete(yymsp[0].minor.yy91);
}
#line 5420 "parse.c"
        break;
      case 100:
#line 269 "parse.y"
{yygotominor.yy91 = yymsp[0].minor.yy91;}
#line 5425 "parse.c"
        break;
      case 101:
#line 270 "parse.y"
{
  if( yymsp[0].minor.yy91 ){
    yymsp[0].minor.yy91->op = yymsp[-1].minor.yy276;
    yymsp[0].minor.yy91->pPrior = yymsp[-2].minor.yy91;
  }
  yygotominor.yy91 = yymsp[0].minor.yy91;
}
#line 5436 "parse.c"
        break;
      case 102:
#line 278 "parse.y"
{yygotominor.yy276 = TK_UNION;}
#line 5441 "parse.c"
        /* No destructor defined for UNION */
        break;
      case 103:
#line 279 "parse.y"
{yygotominor.yy276 = TK_ALL;}
#line 5447 "parse.c"
        /* No destructor defined for UNION */
        /* No destructor defined for ALL */
        break;
      case 104:
#line 280 "parse.y"
{yygotominor.yy276 = TK_INTERSECT;}
#line 5454 "parse.c"
        /* No destructor defined for INTERSECT */
        break;
      case 105:
#line 281 "parse.y"
{yygotominor.yy276 = TK_EXCEPT;}
#line 5460 "parse.c"
        /* No destructor defined for EXCEPT */
        break;
      case 106:
#line 283 "parse.y"
{
  yygotominor.yy91 = sqliteSelectNew(yymsp[-6].minor.yy256,yymsp[-5].minor.yy395,yymsp[-4].minor.yy202,yymsp[-3].minor.yy256,yymsp[-2].minor.yy202,yymsp[-1].minor.yy256,yymsp[-7].minor.yy276,yymsp[0].minor.yy406.limit,yymsp[0].minor.yy406.offset);
}
#line 5468 "parse.c"
        /* No destructor defined for SELECT */
        break;
      case 107:
#line 291 "parse.y"
{yygotominor.yy276 = 1;}
#line 5474 "parse.c"
        /* No destructor defined for DISTINCT */
        break;
      case 108:
#line 292 "parse.y"
{yygotominor.yy276 = 0;}
#line 5480 "parse.c"
        /* No destructor defined for ALL */
        break;
      case 109:
#line 293 "parse.y"
{yygotominor.yy276 = 0;}
#line 5486 "parse.c"
        break;
      case 110:
#line 304 "parse.y"
{yygotominor.yy256 = yymsp[-1].minor.yy256;}
#line 5491 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 111:
#line 305 "parse.y"
{yygotominor.yy256 = 0;}
#line 5497 "parse.c"
        break;
      case 112:
#line 306 "parse.y"
{
   yygotominor.yy256 = sqliteExprListAppend(yymsp[-2].minor.yy256,yymsp[-1].minor.yy202,yymsp[0].minor.yy58.n?&yymsp[0].minor.yy58:0);
}
#line 5504 "parse.c"
        break;
      case 113:
#line 309 "parse.y"
{
  yygotominor.yy256 = sqliteExprListAppend(yymsp[-1].minor.yy256, sqliteExpr(TK_ALL, 0, 0, 0), 0);
}
#line 5511 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 114:
#line 312 "parse.y"
{
  Expr *pRight = sqliteExpr(TK_ALL, 0, 0, 0);
  Expr *pLeft = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy58);
  yygotominor.yy256 = sqliteExprListAppend(yymsp[-3].minor.yy256, sqliteExpr(TK_DOT, pLeft, pRight, 0), 0);
}
#line 5521 "parse.c"
        /* No destructor defined for DOT */
        /* No destructor defined for STAR */
        break;
      case 115:
#line 322 "parse.y"
{ yygotominor.yy58 = yymsp[0].minor.yy58; }
#line 5528 "parse.c"
        /* No destructor defined for AS */
        break;
      case 116:
#line 323 "parse.y"
{ yygotominor.yy58 = yymsp[0].minor.yy58; }
#line 5534 "parse.c"
        break;
      case 117:
#line 324 "parse.y"
{ yygotominor.yy58.n = 0; }
#line 5539 "parse.c"
        break;
      case 118:
#line 336 "parse.y"
{yygotominor.yy395 = sqliteMalloc(sizeof(*yygotominor.yy395));}
#line 5544 "parse.c"
        break;
      case 119:
#line 337 "parse.y"
{yygotominor.yy395 = yymsp[0].minor.yy395;}
#line 5549 "parse.c"
        /* No destructor defined for FROM */
        break;
      case 120:
#line 342 "parse.y"
{
   yygotominor.yy395 = yymsp[-1].minor.yy395;
   if( yygotominor.yy395 && yygotominor.yy395->nSrc>0 ) yygotominor.yy395->a[yygotominor.yy395->nSrc-1].jointype = yymsp[0].minor.yy276;
}
#line 5558 "parse.c"
        break;
      case 121:
#line 346 "parse.y"
{yygotominor.yy395 = 0;}
#line 5563 "parse.c"
        break;
      case 122:
#line 347 "parse.y"
{
  yygotominor.yy395 = sqliteSrcListAppend(yymsp[-4].minor.yy395,&yymsp[-3].minor.yy58);
  if( yymsp[-2].minor.yy58.n ) sqliteSrcListAddAlias(yygotominor.yy395,&yymsp[-2].minor.yy58);
  if( yymsp[-1].minor.yy202 ){
    if( yygotominor.yy395 && yygotominor.yy395->nSrc>1 ){ yygotominor.yy395->a[yygotominor.yy395->nSrc-2].pOn = yymsp[-1].minor.yy202; }
    else { sqliteExprDelete(yymsp[-1].minor.yy202); }
  }
  if( yymsp[0].minor.yy154 ){
    if( yygotominor.yy395 && yygotominor.yy395->nSrc>1 ){ yygotominor.yy395->a[yygotominor.yy395->nSrc-2].pUsing = yymsp[0].minor.yy154; }
    else { sqliteIdListDelete(yymsp[0].minor.yy154); }
  }
}
#line 5579 "parse.c"
        break;
      case 123:
#line 359 "parse.y"
{
  yygotominor.yy395 = sqliteSrcListAppend(yymsp[-6].minor.yy395,0);
  yygotominor.yy395->a[yygotominor.yy395->nSrc-1].pSelect = yymsp[-4].minor.yy91;
  if( yymsp[-2].minor.yy58.n ) sqliteSrcListAddAlias(yygotominor.yy395,&yymsp[-2].minor.yy58);
  if( yymsp[-1].minor.yy202 ){
    if( yygotominor.yy395 && yygotominor.yy395->nSrc>1 ){ yygotominor.yy395->a[yygotominor.yy395->nSrc-2].pOn = yymsp[-1].minor.yy202; }
    else { sqliteExprDelete(yymsp[-1].minor.yy202); }
  }
  if( yymsp[0].minor.yy154 ){
    if( yygotominor.yy395 && yygotominor.yy395->nSrc>1 ){ yygotominor.yy395->a[yygotominor.yy395->nSrc-2].pUsing = yymsp[0].minor.yy154; }
    else { sqliteIdListDelete(yymsp[0].minor.yy154); }
  }
}
#line 5596 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 124:
#line 375 "parse.y"
{ yygotominor.yy276 = JT_INNER; }
#line 5603 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 125:
#line 376 "parse.y"
{ yygotominor.yy276 = JT_INNER; }
#line 5609 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 126:
#line 377 "parse.y"
{ yygotominor.yy276 = sqliteJoinType(pParse,&yymsp[-1].minor.yy0,0,0); }
#line 5615 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 127:
#line 378 "parse.y"
{ yygotominor.yy276 = sqliteJoinType(pParse,&yymsp[-2].minor.yy0,&yymsp[-1].minor.yy58,0); }
#line 5621 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 128:
#line 380 "parse.y"
{ yygotominor.yy276 = sqliteJoinType(pParse,&yymsp[-3].minor.yy0,&yymsp[-2].minor.yy58,&yymsp[-1].minor.yy58); }
#line 5627 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 129:
#line 384 "parse.y"
{yygotominor.yy202 = yymsp[0].minor.yy202;}
#line 5633 "parse.c"
        /* No destructor defined for ON */
        break;
      case 130:
#line 385 "parse.y"
{yygotominor.yy202 = 0;}
#line 5639 "parse.c"
        break;
      case 131:
#line 389 "parse.y"
{yygotominor.yy154 = yymsp[-1].minor.yy154;}
#line 5644 "parse.c"
        /* No destructor defined for USING */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 132:
#line 390 "parse.y"
{yygotominor.yy154 = 0;}
#line 5652 "parse.c"
        break;
      case 133:
#line 400 "parse.y"
{yygotominor.yy256 = 0;}
#line 5657 "parse.c"
        break;
      case 134:
#line 401 "parse.y"
{yygotominor.yy256 = yymsp[0].minor.yy256;}
#line 5662 "parse.c"
        /* No destructor defined for ORDER */
        /* No destructor defined for BY */
        break;
      case 135:
#line 402 "parse.y"
{
  yygotominor.yy256 = sqliteExprListAppend(yymsp[-4].minor.yy256,yymsp[-2].minor.yy202,0);
  if( yygotominor.yy256 ) yygotominor.yy256->a[yygotominor.yy256->nExpr-1].sortOrder = yymsp[-1].minor.yy276+yymsp[0].minor.yy276;
}
#line 5672 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 136:
#line 406 "parse.y"
{
  yygotominor.yy256 = sqliteExprListAppend(0,yymsp[-2].minor.yy202,0);
  if( yygotominor.yy256 ) yygotominor.yy256->a[0].sortOrder = yymsp[-1].minor.yy276+yymsp[0].minor.yy276;
}
#line 5681 "parse.c"
        break;
      case 137:
#line 410 "parse.y"
{yygotominor.yy202 = yymsp[0].minor.yy202;}
#line 5686 "parse.c"
        break;
      case 138:
#line 415 "parse.y"
{yygotominor.yy276 = SQLITE_SO_ASC;}
#line 5691 "parse.c"
        /* No destructor defined for ASC */
        break;
      case 139:
#line 416 "parse.y"
{yygotominor.yy276 = SQLITE_SO_DESC;}
#line 5697 "parse.c"
        /* No destructor defined for DESC */
        break;
      case 140:
#line 417 "parse.y"
{yygotominor.yy276 = SQLITE_SO_ASC;}
#line 5703 "parse.c"
        break;
      case 141:
#line 418 "parse.y"
{yygotominor.yy276 = SQLITE_SO_UNK;}
#line 5708 "parse.c"
        break;
      case 142:
#line 419 "parse.y"
{yygotominor.yy276 = sqliteCollateType(pParse, &yymsp[0].minor.yy58);}
#line 5713 "parse.c"
        /* No destructor defined for COLLATE */
        break;
      case 143:
#line 423 "parse.y"
{yygotominor.yy256 = 0;}
#line 5719 "parse.c"
        break;
      case 144:
#line 424 "parse.y"
{yygotominor.yy256 = yymsp[0].minor.yy256;}
#line 5724 "parse.c"
        /* No destructor defined for GROUP */
        /* No destructor defined for BY */
        break;
      case 145:
#line 428 "parse.y"
{yygotominor.yy202 = 0;}
#line 5731 "parse.c"
        break;
      case 146:
#line 429 "parse.y"
{yygotominor.yy202 = yymsp[0].minor.yy202;}
#line 5736 "parse.c"
        /* No destructor defined for HAVING */
        break;
      case 147:
#line 432 "parse.y"
{yygotominor.yy406.limit = -1; yygotominor.yy406.offset = 0;}
#line 5742 "parse.c"
        break;
      case 148:
#line 433 "parse.y"
{yygotominor.yy406.limit = atoi(yymsp[0].minor.yy0.z); yygotominor.yy406.offset = 0;}
#line 5747 "parse.c"
        /* No destructor defined for LIMIT */
        break;
      case 149:
#line 435 "parse.y"
{yygotominor.yy406.limit = atoi(yymsp[-2].minor.yy0.z); yygotominor.yy406.offset = atoi(yymsp[0].minor.yy0.z);}
#line 5753 "parse.c"
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
{sqliteDeleteFrom(pParse, &yymsp[-1].minor.yy58, yymsp[0].minor.yy202);}
#line 5766 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 153:
#line 447 "parse.y"
{yygotominor.yy202 = 0;}
#line 5773 "parse.c"
        break;
      case 154:
#line 448 "parse.y"
{yygotominor.yy202 = yymsp[0].minor.yy202;}
#line 5778 "parse.c"
        /* No destructor defined for WHERE */
        break;
      case 155:
#line 456 "parse.y"
{sqliteUpdate(pParse,&yymsp[-3].minor.yy58,yymsp[-1].minor.yy256,yymsp[0].minor.yy202,yymsp[-4].minor.yy276);}
#line 5784 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 156:
#line 459 "parse.y"
{yygotominor.yy256 = sqliteExprListAppend(yymsp[-4].minor.yy256,yymsp[0].minor.yy202,&yymsp[-2].minor.yy58);}
#line 5791 "parse.c"
        /* No destructor defined for COMMA */
        /* No destructor defined for EQ */
        break;
      case 157:
#line 460 "parse.y"
{yygotominor.yy256 = sqliteExprListAppend(0,yymsp[0].minor.yy202,&yymsp[-2].minor.yy58);}
#line 5798 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 158:
#line 465 "parse.y"
{sqliteInsert(pParse, &yymsp[-5].minor.yy58, yymsp[-1].minor.yy256, 0, yymsp[-4].minor.yy154, yymsp[-7].minor.yy276);}
#line 5804 "parse.c"
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 159:
#line 467 "parse.y"
{sqliteInsert(pParse, &yymsp[-2].minor.yy58, 0, yymsp[0].minor.yy91, yymsp[-1].minor.yy154, yymsp[-4].minor.yy276);}
#line 5813 "parse.c"
        /* No destructor defined for INTO */
        break;
      case 160:
#line 470 "parse.y"
{yygotominor.yy276 = yymsp[0].minor.yy276;}
#line 5819 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 161:
#line 471 "parse.y"
{yygotominor.yy276 = OE_Replace;}
#line 5825 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 162:
#line 477 "parse.y"
{yygotominor.yy256 = sqliteExprListAppend(yymsp[-2].minor.yy256,yymsp[0].minor.yy202,0);}
#line 5831 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 163:
#line 478 "parse.y"
{yygotominor.yy256 = sqliteExprListAppend(0,yymsp[0].minor.yy202,0);}
#line 5837 "parse.c"
        break;
      case 164:
#line 485 "parse.y"
{yygotominor.yy154 = 0;}
#line 5842 "parse.c"
        break;
      case 165:
#line 486 "parse.y"
{yygotominor.yy154 = yymsp[-1].minor.yy154;}
#line 5847 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 166:
#line 487 "parse.y"
{yygotominor.yy154 = sqliteIdListAppend(yymsp[-2].minor.yy154,&yymsp[0].minor.yy58);}
#line 5854 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 167:
#line 488 "parse.y"
{yygotominor.yy154 = sqliteIdListAppend(0,&yymsp[0].minor.yy58);}
#line 5860 "parse.c"
        break;
      case 168:
#line 507 "parse.y"
{yygotominor.yy202 = yymsp[-1].minor.yy202; sqliteExprSpan(yygotominor.yy202,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0); }
#line 5865 "parse.c"
        break;
      case 169:
#line 508 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_NULL, 0, 0, &yymsp[0].minor.yy0);}
#line 5870 "parse.c"
        break;
      case 170:
#line 509 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy0);}
#line 5875 "parse.c"
        break;
      case 171:
#line 510 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy0);}
#line 5880 "parse.c"
        break;
      case 172:
#line 511 "parse.y"
{
  Expr *temp1 = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy58);
  Expr *temp2 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy58);
  yygotominor.yy202 = sqliteExpr(TK_DOT, temp1, temp2, 0);
}
#line 5889 "parse.c"
        /* No destructor defined for DOT */
        break;
      case 173:
#line 517 "parse.y"
{yygotominor.yy202 = yymsp[-1].minor.yy202; ExprSetProperty(yygotominor.yy202,EP_Oracle8Join);}
#line 5895 "parse.c"
        /* No destructor defined for ORACLE_OUTER_JOIN */
        break;
      case 174:
#line 518 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_INTEGER, 0, 0, &yymsp[0].minor.yy0);}
#line 5901 "parse.c"
        break;
      case 175:
#line 519 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_FLOAT, 0, 0, &yymsp[0].minor.yy0);}
#line 5906 "parse.c"
        break;
      case 176:
#line 520 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_STRING, 0, 0, &yymsp[0].minor.yy0);}
#line 5911 "parse.c"
        break;
      case 177:
#line 521 "parse.y"
{
  yygotominor.yy202 = sqliteExprFunction(yymsp[-1].minor.yy256, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 5919 "parse.c"
        /* No destructor defined for LP */
        break;
      case 178:
#line 525 "parse.y"
{
  yygotominor.yy202 = sqliteExprFunction(0, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 5928 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for STAR */
        break;
      case 179:
#line 529 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_AND, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 5935 "parse.c"
        /* No destructor defined for AND */
        break;
      case 180:
#line 530 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_OR, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 5941 "parse.c"
        /* No destructor defined for OR */
        break;
      case 181:
#line 531 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_LT, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 5947 "parse.c"
        /* No destructor defined for LT */
        break;
      case 182:
#line 532 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_GT, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 5953 "parse.c"
        /* No destructor defined for GT */
        break;
      case 183:
#line 533 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_LE, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 5959 "parse.c"
        /* No destructor defined for LE */
        break;
      case 184:
#line 534 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_GE, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 5965 "parse.c"
        /* No destructor defined for GE */
        break;
      case 185:
#line 535 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_NE, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 5971 "parse.c"
        /* No destructor defined for NE */
        break;
      case 186:
#line 536 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_EQ, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 5977 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 187:
#line 537 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_BITAND, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 5983 "parse.c"
        /* No destructor defined for BITAND */
        break;
      case 188:
#line 538 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_BITOR, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 5989 "parse.c"
        /* No destructor defined for BITOR */
        break;
      case 189:
#line 539 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_LSHIFT, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 5995 "parse.c"
        /* No destructor defined for LSHIFT */
        break;
      case 190:
#line 540 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_RSHIFT, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 6001 "parse.c"
        /* No destructor defined for RSHIFT */
        break;
      case 191:
#line 541 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[0].minor.yy202, 0);
  pList = sqliteExprListAppend(pList, yymsp[-2].minor.yy202, 0);
  yygotominor.yy202 = sqliteExprFunction(pList, 0);
  if( yygotominor.yy202 ) yygotominor.yy202->op = yymsp[-1].minor.yy276;
  sqliteExprSpan(yygotominor.yy202, &yymsp[-2].minor.yy202->span, &yymsp[0].minor.yy202->span);
}
#line 6013 "parse.c"
        break;
      case 192:
#line 548 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[0].minor.yy202, 0);
  pList = sqliteExprListAppend(pList, yymsp[-3].minor.yy202, 0);
  yygotominor.yy202 = sqliteExprFunction(pList, 0);
  if( yygotominor.yy202 ) yygotominor.yy202->op = yymsp[-1].minor.yy276;
  yygotominor.yy202 = sqliteExpr(TK_NOT, yygotominor.yy202, 0, 0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-3].minor.yy202->span,&yymsp[0].minor.yy202->span);
}
#line 6025 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 193:
#line 557 "parse.y"
{yygotominor.yy276 = TK_LIKE;}
#line 6031 "parse.c"
        /* No destructor defined for LIKE */
        break;
      case 194:
#line 558 "parse.y"
{yygotominor.yy276 = TK_GLOB;}
#line 6037 "parse.c"
        /* No destructor defined for GLOB */
        break;
      case 195:
#line 559 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_PLUS, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 6043 "parse.c"
        /* No destructor defined for PLUS */
        break;
      case 196:
#line 560 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_MINUS, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 6049 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 197:
#line 561 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_STAR, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 6055 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 198:
#line 562 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_SLASH, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 6061 "parse.c"
        /* No destructor defined for SLASH */
        break;
      case 199:
#line 563 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_REM, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 6067 "parse.c"
        /* No destructor defined for REM */
        break;
      case 200:
#line 564 "parse.y"
{yygotominor.yy202 = sqliteExpr(TK_CONCAT, yymsp[-2].minor.yy202, yymsp[0].minor.yy202, 0);}
#line 6073 "parse.c"
        /* No destructor defined for CONCAT */
        break;
      case 201:
#line 565 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_ISNULL, yymsp[-1].minor.yy202, 0, 0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-1].minor.yy202->span,&yymsp[0].minor.yy0);
}
#line 6082 "parse.c"
        break;
      case 202:
#line 569 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_ISNULL, yymsp[-2].minor.yy202, 0, 0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-2].minor.yy202->span,&yymsp[0].minor.yy0);
}
#line 6090 "parse.c"
        /* No destructor defined for IS */
        break;
      case 203:
#line 573 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_NOTNULL, yymsp[-1].minor.yy202, 0, 0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-1].minor.yy202->span,&yymsp[0].minor.yy0);
}
#line 6099 "parse.c"
        break;
      case 204:
#line 577 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_NOTNULL, yymsp[-2].minor.yy202, 0, 0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-2].minor.yy202->span,&yymsp[0].minor.yy0);
}
#line 6107 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 205:
#line 581 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_NOTNULL, yymsp[-3].minor.yy202, 0, 0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-3].minor.yy202->span,&yymsp[0].minor.yy0);
}
#line 6116 "parse.c"
        /* No destructor defined for IS */
        /* No destructor defined for NOT */
        break;
      case 206:
#line 585 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_NOT, yymsp[0].minor.yy202, 0, 0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy202->span);
}
#line 6126 "parse.c"
        break;
      case 207:
#line 589 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_BITNOT, yymsp[0].minor.yy202, 0, 0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy202->span);
}
#line 6134 "parse.c"
        break;
      case 208:
#line 593 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_UMINUS, yymsp[0].minor.yy202, 0, 0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy202->span);
}
#line 6142 "parse.c"
        break;
      case 209:
#line 597 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_UPLUS, yymsp[0].minor.yy202, 0, 0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy202->span);
}
#line 6150 "parse.c"
        break;
      case 210:
#line 601 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_SELECT, 0, 0, 0);
  if( yygotominor.yy202 ) yygotominor.yy202->pSelect = yymsp[-1].minor.yy91;
  sqliteExprSpan(yygotominor.yy202,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);
}
#line 6159 "parse.c"
        break;
      case 211:
#line 606 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy202, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy202, 0);
  yygotominor.yy202 = sqliteExpr(TK_BETWEEN, yymsp[-4].minor.yy202, 0, 0);
  if( yygotominor.yy202 ) yygotominor.yy202->pList = pList;
  sqliteExprSpan(yygotominor.yy202,&yymsp[-4].minor.yy202->span,&yymsp[0].minor.yy202->span);
}
#line 6170 "parse.c"
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 212:
#line 613 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy202, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy202, 0);
  yygotominor.yy202 = sqliteExpr(TK_BETWEEN, yymsp[-5].minor.yy202, 0, 0);
  if( yygotominor.yy202 ) yygotominor.yy202->pList = pList;
  yygotominor.yy202 = sqliteExpr(TK_NOT, yygotominor.yy202, 0, 0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-5].minor.yy202->span,&yymsp[0].minor.yy202->span);
}
#line 6184 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 213:
#line 621 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_IN, yymsp[-4].minor.yy202, 0, 0);
  if( yygotominor.yy202 ) yygotominor.yy202->pList = yymsp[-1].minor.yy256;
  sqliteExprSpan(yygotominor.yy202,&yymsp[-4].minor.yy202->span,&yymsp[0].minor.yy0);
}
#line 6196 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 214:
#line 626 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_IN, yymsp[-4].minor.yy202, 0, 0);
  if( yygotominor.yy202 ) yygotominor.yy202->pSelect = yymsp[-1].minor.yy91;
  sqliteExprSpan(yygotominor.yy202,&yymsp[-4].minor.yy202->span,&yymsp[0].minor.yy0);
}
#line 6207 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 215:
#line 631 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_IN, yymsp[-5].minor.yy202, 0, 0);
  if( yygotominor.yy202 ) yygotominor.yy202->pList = yymsp[-1].minor.yy256;
  yygotominor.yy202 = sqliteExpr(TK_NOT, yygotominor.yy202, 0, 0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-5].minor.yy202->span,&yymsp[0].minor.yy0);
}
#line 6219 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 216:
#line 637 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_IN, yymsp[-5].minor.yy202, 0, 0);
  if( yygotominor.yy202 ) yygotominor.yy202->pSelect = yymsp[-1].minor.yy91;
  yygotominor.yy202 = sqliteExpr(TK_NOT, yygotominor.yy202, 0, 0);
  sqliteExprSpan(yygotominor.yy202,&yymsp[-5].minor.yy202->span,&yymsp[0].minor.yy0);
}
#line 6232 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 217:
#line 645 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_CASE, yymsp[-3].minor.yy202, yymsp[-1].minor.yy202, 0);
  if( yygotominor.yy202 ) yygotominor.yy202->pList = yymsp[-2].minor.yy256;
  sqliteExprSpan(yygotominor.yy202, &yymsp[-4].minor.yy0, &yymsp[0].minor.yy0);
}
#line 6244 "parse.c"
        break;
      case 218:
#line 652 "parse.y"
{
  yygotominor.yy256 = sqliteExprListAppend(yymsp[-4].minor.yy256, yymsp[-2].minor.yy202, 0);
  yygotominor.yy256 = sqliteExprListAppend(yygotominor.yy256, yymsp[0].minor.yy202, 0);
}
#line 6252 "parse.c"
        /* No destructor defined for WHEN */
        /* No destructor defined for THEN */
        break;
      case 219:
#line 656 "parse.y"
{
  yygotominor.yy256 = sqliteExprListAppend(0, yymsp[-2].minor.yy202, 0);
  yygotominor.yy256 = sqliteExprListAppend(yygotominor.yy256, yymsp[0].minor.yy202, 0);
}
#line 6262 "parse.c"
        /* No destructor defined for WHEN */
        /* No destructor defined for THEN */
        break;
      case 220:
#line 661 "parse.y"
{yygotominor.yy202 = yymsp[0].minor.yy202;}
#line 6269 "parse.c"
        /* No destructor defined for ELSE */
        break;
      case 221:
#line 662 "parse.y"
{yygotominor.yy202 = 0;}
#line 6275 "parse.c"
        break;
      case 222:
#line 664 "parse.y"
{yygotominor.yy202 = yymsp[0].minor.yy202;}
#line 6280 "parse.c"
        break;
      case 223:
#line 665 "parse.y"
{yygotominor.yy202 = 0;}
#line 6285 "parse.c"
        break;
      case 224:
#line 673 "parse.y"
{yygotominor.yy256 = sqliteExprListAppend(yymsp[-2].minor.yy256,yymsp[0].minor.yy202,0);}
#line 6290 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 225:
#line 674 "parse.y"
{yygotominor.yy256 = sqliteExprListAppend(0,yymsp[0].minor.yy202,0);}
#line 6296 "parse.c"
        break;
      case 226:
#line 675 "parse.y"
{yygotominor.yy202 = yymsp[0].minor.yy202;}
#line 6301 "parse.c"
        break;
      case 227:
#line 676 "parse.y"
{yygotominor.yy202 = 0;}
#line 6306 "parse.c"
        break;
      case 228:
#line 681 "parse.y"
{
  if( yymsp[-8].minor.yy276!=OE_None ) yymsp[-8].minor.yy276 = yymsp[0].minor.yy276;
  if( yymsp[-8].minor.yy276==OE_Default) yymsp[-8].minor.yy276 = OE_Abort;
  sqliteCreateIndex(pParse, &yymsp[-6].minor.yy58, &yymsp[-4].minor.yy58, yymsp[-2].minor.yy154, yymsp[-8].minor.yy276, &yymsp[-9].minor.yy0, &yymsp[-1].minor.yy0);
}
#line 6315 "parse.c"
        /* No destructor defined for INDEX */
        /* No destructor defined for ON */
        /* No destructor defined for LP */
        break;
      case 229:
#line 688 "parse.y"
{ yygotominor.yy276 = OE_Abort; }
#line 6323 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 230:
#line 689 "parse.y"
{ yygotominor.yy276 = OE_None; }
#line 6329 "parse.c"
        break;
      case 231:
#line 697 "parse.y"
{yygotominor.yy154 = 0;}
#line 6334 "parse.c"
        break;
      case 232:
#line 698 "parse.y"
{yygotominor.yy154 = yymsp[-1].minor.yy154;}
#line 6339 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 233:
#line 699 "parse.y"
{yygotominor.yy154 = sqliteIdListAppend(yymsp[-2].minor.yy154,&yymsp[0].minor.yy58);}
#line 6346 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 234:
#line 700 "parse.y"
{yygotominor.yy154 = sqliteIdListAppend(0,&yymsp[0].minor.yy58);}
#line 6352 "parse.c"
        break;
      case 235:
#line 701 "parse.y"
{yygotominor.yy58 = yymsp[0].minor.yy58;}
#line 6357 "parse.c"
        break;
      case 236:
#line 706 "parse.y"
{sqliteDropIndex(pParse, &yymsp[0].minor.yy58);}
#line 6362 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for INDEX */
        break;
      case 237:
#line 712 "parse.y"
{sqliteCopy(pParse,&yymsp[-5].minor.yy58,&yymsp[-3].minor.yy58,&yymsp[0].minor.yy0,yymsp[-6].minor.yy276);}
#line 6369 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        /* No destructor defined for USING */
        /* No destructor defined for DELIMITERS */
        break;
      case 238:
#line 714 "parse.y"
{sqliteCopy(pParse,&yymsp[-2].minor.yy58,&yymsp[0].minor.yy58,0,yymsp[-3].minor.yy276);}
#line 6378 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        break;
      case 239:
#line 718 "parse.y"
{sqliteVacuum(pParse,0);}
#line 6385 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 240:
#line 719 "parse.y"
{sqliteVacuum(pParse,&yymsp[0].minor.yy58);}
#line 6391 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 241:
#line 723 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy58,&yymsp[0].minor.yy58,0);}
#line 6397 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 242:
#line 724 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy58,&yymsp[0].minor.yy0,0);}
#line 6404 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 243:
#line 725 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy58,&yymsp[0].minor.yy58,0);}
#line 6411 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 244:
#line 726 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy58,&yymsp[0].minor.yy58,1);}
#line 6418 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 245:
#line 727 "parse.y"
{sqlitePragma(pParse,&yymsp[-3].minor.yy58,&yymsp[-1].minor.yy58,0);}
#line 6425 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 246:
#line 728 "parse.y"
{sqlitePragma(pParse,&yymsp[0].minor.yy58,&yymsp[0].minor.yy58,0);}
#line 6433 "parse.c"
        /* No destructor defined for PRAGMA */
        break;
      case 247:
#line 729 "parse.y"
{yygotominor.yy58 = yymsp[0].minor.yy58;}
#line 6439 "parse.c"
        /* No destructor defined for plus_opt */
        break;
      case 248:
#line 730 "parse.y"
{yygotominor.yy58 = yymsp[0].minor.yy58;}
#line 6445 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 249:
#line 731 "parse.y"
{yygotominor.yy58 = yymsp[0].minor.yy0;}
#line 6451 "parse.c"
        break;
      case 250:
#line 732 "parse.y"
{yygotominor.yy58 = yymsp[0].minor.yy0;}
#line 6456 "parse.c"
        break;
      case 251:
        /* No destructor defined for PLUS */
        break;
      case 252:
        break;
      case 253:
#line 739 "parse.y"
{
  Token all;
  all.z = yymsp[-11].minor.yy0.z;
  all.n = (yymsp[0].minor.yy0.z - yymsp[-11].minor.yy0.z) + yymsp[0].minor.yy0.n;
  sqliteCreateTrigger(pParse, &yymsp[-9].minor.yy58, yymsp[-8].minor.yy276, yymsp[-7].minor.yy146.a, yymsp[-7].minor.yy146.b, &yymsp[-5].minor.yy58, yymsp[-4].minor.yy276, yymsp[-3].minor.yy412, yymsp[-1].minor.yy111, &all);
}
#line 6471 "parse.c"
        /* No destructor defined for TRIGGER */
        /* No destructor defined for ON */
        /* No destructor defined for BEGIN */
        break;
      case 254:
#line 747 "parse.y"
{ yygotominor.yy276 = TK_BEFORE; }
#line 6479 "parse.c"
        /* No destructor defined for BEFORE */
        break;
      case 255:
#line 748 "parse.y"
{ yygotominor.yy276 = TK_AFTER;  }
#line 6485 "parse.c"
        /* No destructor defined for AFTER */
        break;
      case 256:
#line 749 "parse.y"
{ yygotominor.yy276 = TK_INSTEAD;}
#line 6491 "parse.c"
        /* No destructor defined for INSTEAD */
        /* No destructor defined for OF */
        break;
      case 257:
#line 750 "parse.y"
{ yygotominor.yy276 = TK_BEFORE; }
#line 6498 "parse.c"
        break;
      case 258:
#line 754 "parse.y"
{ yygotominor.yy146.a = TK_DELETE; yygotominor.yy146.b = 0; }
#line 6503 "parse.c"
        /* No destructor defined for DELETE */
        break;
      case 259:
#line 755 "parse.y"
{ yygotominor.yy146.a = TK_INSERT; yygotominor.yy146.b = 0; }
#line 6509 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 260:
#line 756 "parse.y"
{ yygotominor.yy146.a = TK_UPDATE; yygotominor.yy146.b = 0;}
#line 6515 "parse.c"
        /* No destructor defined for UPDATE */
        break;
      case 261:
#line 757 "parse.y"
{yygotominor.yy146.a = TK_UPDATE; yygotominor.yy146.b = yymsp[0].minor.yy154; }
#line 6521 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for OF */
        break;
      case 262:
#line 760 "parse.y"
{ yygotominor.yy276 = TK_ROW; }
#line 6528 "parse.c"
        break;
      case 263:
#line 761 "parse.y"
{ yygotominor.yy276 = TK_ROW; }
#line 6533 "parse.c"
        /* No destructor defined for FOR */
        /* No destructor defined for EACH */
        /* No destructor defined for ROW */
        break;
      case 264:
#line 762 "parse.y"
{ yygotominor.yy276 = TK_STATEMENT; }
#line 6541 "parse.c"
        /* No destructor defined for FOR */
        /* No destructor defined for EACH */
        /* No destructor defined for STATEMENT */
        break;
      case 265:
#line 765 "parse.y"
{ yygotominor.yy412 = 0; }
#line 6549 "parse.c"
        break;
      case 266:
#line 766 "parse.y"
{ yygotominor.yy412 = yymsp[0].minor.yy202; }
#line 6554 "parse.c"
        /* No destructor defined for WHEN */
        break;
      case 267:
#line 769 "parse.y"
{
  yymsp[-2].minor.yy111->pNext = yymsp[0].minor.yy111 ; yygotominor.yy111 = yymsp[-2].minor.yy111; }
#line 6561 "parse.c"
        /* No destructor defined for SEMI */
        break;
      case 268:
#line 771 "parse.y"
{ yygotominor.yy111 = 0; }
#line 6567 "parse.c"
        break;
      case 269:
#line 776 "parse.y"
{ yygotominor.yy111 = sqliteTriggerUpdateStep(&yymsp[-3].minor.yy58, yymsp[-1].minor.yy256, yymsp[0].minor.yy202, yymsp[-4].minor.yy276); }
#line 6572 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 270:
#line 781 "parse.y"
{yygotominor.yy111 = sqliteTriggerInsertStep(&yymsp[-5].minor.yy58, yymsp[-4].minor.yy154, yymsp[-1].minor.yy256, 0, yymsp[-7].minor.yy276);}
#line 6579 "parse.c"
        /* No destructor defined for INSERT */
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 271:
#line 784 "parse.y"
{yygotominor.yy111 = sqliteTriggerInsertStep(&yymsp[-2].minor.yy58, yymsp[-1].minor.yy154, 0, yymsp[0].minor.yy91, yymsp[-4].minor.yy276);}
#line 6589 "parse.c"
        /* No destructor defined for INSERT */
        /* No destructor defined for INTO */
        break;
      case 272:
#line 788 "parse.y"
{yygotominor.yy111 = sqliteTriggerDeleteStep(&yymsp[-1].minor.yy58, yymsp[0].minor.yy202);}
#line 6596 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 273:
#line 791 "parse.y"
{yygotominor.yy111 = sqliteTriggerSelectStep(yymsp[0].minor.yy91); }
#line 6603 "parse.c"
        break;
      case 274:
#line 794 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_RAISE, 0, 0, 0); 
  yygotominor.yy202->iColumn = OE_Ignore;
  sqliteExprSpan(yygotominor.yy202, &yymsp[-3].minor.yy0, &yymsp[0].minor.yy0);
}
#line 6612 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for IGNORE */
        break;
      case 275:
#line 799 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy58); 
  yygotominor.yy202->iColumn = OE_Rollback;
  sqliteExprSpan(yygotominor.yy202, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);
}
#line 6623 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for ROLLBACK */
        /* No destructor defined for COMMA */
        break;
      case 276:
#line 804 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy58); 
  yygotominor.yy202->iColumn = OE_Abort;
  sqliteExprSpan(yygotominor.yy202, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);
}
#line 6635 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for ABORT */
        /* No destructor defined for COMMA */
        break;
      case 277:
#line 809 "parse.y"
{
  yygotominor.yy202 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy58); 
  yygotominor.yy202->iColumn = OE_Fail;
  sqliteExprSpan(yygotominor.yy202, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);
}
#line 6647 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for FAIL */
        /* No destructor defined for COMMA */
        break;
      case 278:
#line 816 "parse.y"
{
    sqliteDropTrigger(pParse,&yymsp[0].minor.yy58,0);
}
#line 6657 "parse.c"
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

#line 6707 "parse.c"
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
