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
#define YYNSTATE 523
#define YYNRULE 276
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
  { 103,   0, 520}, /*  2:                   SEMI shift  520 */
  { 146,   1, 522}, /*  3:                   ecmd shift  522 */
  {  44,   0, 521}, /*  4:                EXPLAIN shift  521 */
  { 148,   0,   3}, /*  5:                explain shift  3 */
  { 161,   0, 800}, /*  6:                  input accept */
/* State 1 */
  {   0,   0, 523}, /*  1:                      $ reduce 0 */
  { 146,   0,   2}, /*  2:                   ecmd shift  2 */
  { 103,   0, 520}, /*  3:                   SEMI shift  520 */
  { 148,   3,   3}, /*  4:                explain shift  3 */
  {  44,   0, 521}, /*  5:                EXPLAIN shift  521 */
/* State 3 */
  { 133,   0,   4}, /*  1:                    cmd shift  4 */
  {  96,   0, 492}, /*  2:                REPLACE shift  492 */
  {  40,   0,  24}, /*  3:                    END shift  24 */
  {  98,   0,  26}, /*  4:               ROLLBACK shift  26 */
  {  23,   0,  22}, /*  5:                 COMMIT shift  22 */
  { 119,   0, 475}, /*  6:                 UPDATE shift  475 */
  { 177,  11,  66}, /*  7:              oneselect shift  66 */
  { 121,  12, 501}, /*  8:                 VACUUM shift  501 */
  { 141,  15,  28}, /*  9:           create_table shift  28 */
  {  28,  17, 374}, /* 10:                 CREATE shift  374 */
  {  63,   0, 490}, /* 11:                 INSERT shift  490 */
  { 102,   0,  70}, /* 12:                 SELECT shift  70 */
  { 164,   0, 481}, /* 13:             insert_cmd shift  481 */
  {  32,   0, 471}, /* 14:                 DELETE shift  471 */
  {  27,   0, 493}, /* 15:                   COPY shift  493 */
  {  91,   0, 503}, /* 16:                 PRAGMA shift  503 */
  {   9,   0,   6}, /* 17:                  BEGIN shift  6 */
  {  37,   0, 461}, /* 18:                   DROP shift  461 */
  { 189,  18, 470}, /* 19:                 select shift  470 */
/* State 4 */
  { 103,   0,   5}, /*  1:                   SEMI shift  5 */
/* State 6 */
  { 113,   0,  17}, /*  1:            TRANSACTION shift  17 */
  { 199,   1,   7}, /*  2:              trans_opt shift  7 */
/* State 7 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 103,   0, 610}, /*  2:                   SEMI reduce 87 */
  { 176,   0,   8}, /*  3:                 onconf shift  8 */
/* State 8 */
  { 103,   0, 530}, /*  1:                   SEMI reduce 7 */
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
  { 103,   0, 531}, /*  1:                   SEMI reduce 8 */
  { 199,   1,  23}, /*  2:              trans_opt shift  23 */
  { 113,   0,  17}, /*  3:            TRANSACTION shift  17 */
/* State 23 */
  { 103,   0, 534}, /*  1:                   SEMI reduce 11 */
/* State 24 */
  { 103,   0, 531}, /*  1:                   SEMI reduce 8 */
  { 199,   1,  25}, /*  2:              trans_opt shift  25 */
  { 113,   0,  17}, /*  3:            TRANSACTION shift  17 */
/* State 25 */
  { 103,   0, 535}, /*  1:                   SEMI reduce 12 */
/* State 26 */
  { 103,   0, 531}, /*  1:                   SEMI reduce 8 */
  { 199,   1,  27}, /*  2:              trans_opt shift  27 */
  { 113,   0,  17}, /*  3:            TRANSACTION shift  17 */
/* State 27 */
  { 103,   0, 536}, /*  1:                   SEMI reduce 13 */
/* State 28 */
  {   6,   0, 372}, /*  1:                     AS shift  372 */
  { 142,   3,  29}, /*  2:      create_table_args shift  29 */
  {  76,   0,  30}, /*  3:                     LP shift  30 */
/* State 29 */
  { 103,   0, 537}, /*  1:                   SEMI reduce 14 */
/* State 30 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  {  71,   0,  21}, /*  2:                JOIN_KW shift  21 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  { 136,   0, 371}, /*  4:                 column shift  371 */
  { 137,   3,  36}, /*  5:               columnid shift  36 */
  { 173,   7, 340}, /*  6:                     nm shift  340 */
  { 138,   0,  31}, /*  7:             columnlist shift  31 */
/* State 31 */
  {  21,   0,  34}, /*  1:                  COMMA shift  34 */
  { 100,   0, 598}, /*  2:                     RP reduce 75 */
  { 140,   0,  32}, /*  3:           conslist_opt shift  32 */
/* State 32 */
  { 100,   0,  33}, /*  1:                     RP shift  33 */
/* State 33 */
  { 103,   0, 541}, /*  1:                   SEMI reduce 18 */
/* State 34 */
  {  26,   0, 344}, /*  1:             CONSTRAINT shift  344 */
  { 118,   4, 352}, /*  2:                 UNIQUE shift  352 */
  { 197,   0, 370}, /*  3:                  tcons shift  370 */
  {  92,   0, 346}, /*  4:                PRIMARY shift  346 */
  { 173,   9, 340}, /*  5:                     nm shift  340 */
  { 109,   0,  20}, /*  6:                 STRING shift  20 */
  { 136,  11,  35}, /*  7:                 column shift  35 */
  { 137,   0,  36}, /*  8:               columnid shift  36 */
  {  56,  12,  19}, /*  9:                     ID shift  19 */
  { 139,  13, 341}, /* 10:               conslist shift  341 */
  {  71,   0,  21}, /* 11:                JOIN_KW shift  21 */
  {  17,   0, 357}, /* 12:                  CHECK shift  357 */
  {  48,   0, 360}, /* 13:                FOREIGN shift  360 */
/* State 36 */
  { 205,   0, 326}, /*  1:               typename shift  326 */
  {  56,   0, 244}, /*  2:                     ID shift  244 */
  { 157,   0, 339}, /*  3:                    ids shift  339 */
  { 109,   0, 245}, /*  4:                 STRING shift  245 */
  { 204,   4,  37}, /*  5:                   type shift  37 */
/* State 37 */
  { 128,   0,  38}, /*  1:               carglist shift  38 */
/* State 38 */
  { 143,   6, 288}, /*  1:        defer_subclause shift  288 */
  { 118,   8,  57}, /*  2:                 UNIQUE shift  57 */
  { 132,   0, 313}, /*  3:                  ccons shift  313 */
  { 185,   9, 287}, /*  4:             references shift  287 */
  {  82,  10,  43}, /*  5:                    NOT shift  43 */
  {  26,   0,  40}, /*  6:             CONSTRAINT shift  40 */
  {  19,   0, 289}, /*  7:                COLLATE shift  289 */
  {  92,   0,  51}, /*  8:                PRIMARY shift  51 */
  {  94,  12, 291}, /*  9:             REFERENCES shift  291 */
  {  30,  13, 311}, /* 10:             DEFERRABLE shift  311 */
  { 127,   0,  39}, /* 11:                   carg shift  39 */
  {  29,   0, 314}, /* 12:                DEFAULT shift  314 */
  {  17,   0,  59}, /* 13:                  CHECK shift  59 */
/* State 40 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3,  41}, /*  2:                     nm shift  41 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 41 */
  {  30,   0, 311}, /*  1:             DEFERRABLE shift  311 */
  {  92,   7,  51}, /*  2:                PRIMARY shift  51 */
  { 132,   2,  42}, /*  3:                  ccons shift  42 */
  { 143,   0, 288}, /*  4:        defer_subclause shift  288 */
  {  94,   0, 291}, /*  5:             REFERENCES shift  291 */
  { 185,   0, 287}, /*  6:             references shift  287 */
  {  82,   0,  43}, /*  7:                    NOT shift  43 */
  {  17,   0,  59}, /*  8:                  CHECK shift  59 */
  { 118,   0,  57}, /*  9:                 UNIQUE shift  57 */
  {  19,   0, 289}, /* 10:                COLLATE shift  289 */
/* State 43 */
  {  84,   2,  44}, /*  1:                   NULL shift  44 */
  {  30,   0,  46}, /*  2:             DEFERRABLE shift  46 */
/* State 44 */
  { 176,   0,  45}, /*  1:                 onconf shift  45 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 46 */
  { 160,   2,  47}, /*  1: init_deferred_pred_opt shift  47 */
  {  62,   0,  48}, /*  2:              INITIALLY shift  48 */
/* State 48 */
  {  31,   0,  49}, /*  1:               DEFERRED shift  49 */
  {  59,   1,  50}, /*  2:              IMMEDIATE shift  50 */
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
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 284}, /* 15:                   expr shift  284 */
/* State 61 */
  {  76,   2,  62}, /*  1:                     LP shift  62 */
  {  36,   0, 550}, /*  2:                    DOT reduce 27 */
/* State 62 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  { 109,   0,  63}, /*  2:                 STRING shift  63 */
  {  56,   0,  61}, /*  3:                     ID shift  61 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  {  76,   0,  65}, /*  5:                     LP shift  65 */
  { 149,   0, 163}, /*  6:                   expr shift  163 */
  { 150,   0, 208}, /*  7:               expritem shift  208 */
  { 151,   0, 280}, /*  8:               exprlist shift  280 */
  {  80,   0, 168}, /*  9:                  MINUS shift  168 */
  {  46,   0, 102}, /* 10:                  FLOAT shift  102 */
  {  82,  10, 164}, /* 11:                    NOT shift  164 */
  { 173,  14,  98}, /* 12:                     nm shift  98 */
  {  84,  15,  97}, /* 13:                   NULL shift  97 */
  {  65,   0, 101}, /* 14:                INTEGER shift  101 */
  {  12,   0, 166}, /* 15:                 BITNOT shift  166 */
  {  71,   0,  64}, /* 16:                JOIN_KW shift  64 */
  {  16,   0, 172}, /* 17:                   CASE shift  172 */
  { 107,  16, 282}, /* 18:                   STAR shift  282 */
/* State 63 */
  {  36,   0, 551}, /*  1:                    DOT reduce 28 */
/* State 64 */
  {  36,   0, 552}, /*  1:                    DOT reduce 29 */
/* State 65 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  { 109,   0,  63}, /*  2:                 STRING shift  63 */
  {  56,   0,  61}, /*  3:                     ID shift  61 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  {  76,   0,  65}, /*  5:                     LP shift  65 */
  { 149,   0, 278}, /*  6:                   expr shift  278 */
  {  46,   0, 102}, /*  7:                  FLOAT shift  102 */
  {  65,   0, 101}, /*  8:                INTEGER shift  101 */
  {  80,   0, 168}, /*  9:                  MINUS shift  168 */
  { 189,   0,  67}, /* 10:                 select shift  67 */
  {  82,   7, 164}, /* 11:                    NOT shift  164 */
  { 173,   8,  98}, /* 12:                     nm shift  98 */
  { 102,  14,  70}, /* 13:                 SELECT shift  70 */
  {  84,  15,  97}, /* 14:                   NULL shift  97 */
  {  12,   0, 166}, /* 15:                 BITNOT shift  166 */
  { 177,   0,  66}, /* 16:              oneselect shift  66 */
  {  16,   0, 172}, /* 17:                   CASE shift  172 */
  {  71,   0,  64}, /* 18:                JOIN_KW shift  64 */
/* State 67 */
  { 100,   0, 277}, /*  1:                     RP shift  277 */
  {  66,   0, 160}, /*  2:              INTERSECT shift  160 */
  { 172,   5,  68}, /*  3:         multiselect_op shift  68 */
  {  43,   0, 161}, /*  4:                 EXCEPT shift  161 */
  { 117,   0, 158}, /*  5:                  UNION shift  158 */
/* State 68 */
  { 102,   0,  70}, /*  1:                 SELECT shift  70 */
  { 177,   0,  69}, /*  2:              oneselect shift  69 */
/* State 70 */
  {   4,   0, 276}, /*  1:                    ALL shift  276 */
  { 145,   1,  71}, /*  2:               distinct shift  71 */
  {  35,   0, 275}, /*  3:               DISTINCT shift  275 */
/* State 71 */
  { 188,   0,  72}, /*  1:             selcollist shift  72 */
  { 187,   0, 268}, /*  2:                   sclp shift  268 */
/* State 72 */
  { 153,   3,  73}, /*  1:                   from shift  73 */
  {  49,   0, 231}, /*  2:                   FROM shift  231 */
  {  21,   0, 230}, /*  3:                  COMMA shift  230 */
/* State 73 */
  { 125,   0, 228}, /*  1:                  WHERE shift  228 */
  { 209,   1,  74}, /*  2:              where_opt shift  74 */
/* State 74 */
  { 154,   0,  75}, /*  1:            groupby_opt shift  75 */
  {  53,   0, 225}, /*  2:                  GROUP shift  225 */
/* State 75 */
  {  55,   0, 223}, /*  1:                 HAVING shift  223 */
  { 155,   1,  76}, /*  2:             having_opt shift  76 */
/* State 76 */
  {  89,   0,  85}, /*  1:                  ORDER shift  85 */
  { 179,   1,  77}, /*  2:            orderby_opt shift  77 */
/* State 77 */
  {  75,   0,  79}, /*  1:                  LIMIT shift  79 */
  { 169,   1,  78}, /*  2:              limit_opt shift  78 */
/* State 79 */
  {  65,   0,  80}, /*  1:                INTEGER shift  80 */
/* State 80 */
  {  21,   0,  84}, /*  1:                  COMMA shift  84 */
  {  86,   0,  83}, /*  2:                 OFFSET shift  83 */
  { 170,   2,  81}, /*  3:              limit_sep shift  81 */
/* State 81 */
  {  65,   0,  82}, /*  1:                INTEGER shift  82 */
/* State 83 */
  {  65,   0, 673}, /*  1:                INTEGER reduce 150 */
/* State 84 */
  {  65,   0, 674}, /*  1:                INTEGER reduce 151 */
/* State 85 */
  {  14,   0,  86}, /*  1:                     BY shift  86 */
/* State 86 */
  {  71,   0,  64}, /*  1:                JOIN_KW shift  64 */
  {  56,   0,  61}, /*  2:                     ID shift  61 */
  { 109,   0,  63}, /*  3:                 STRING shift  63 */
  { 173,   1,  98}, /*  4:                     nm shift  98 */
  {  76,   0,  65}, /*  5:                     LP shift  65 */
  {  90,   2, 170}, /*  6:                   PLUS shift  170 */
  { 193,   0, 220}, /*  7:               sortitem shift  220 */
  { 194,   3,  87}, /*  8:               sortlist shift  87 */
  {  93,   5, 182}, /*  9:                  RAISE shift  182 */
  {  46,  11, 102}, /* 10:                  FLOAT shift  102 */
  {  12,   0, 166}, /* 11:                 BITNOT shift  166 */
  {  65,   0, 101}, /* 12:                INTEGER shift  101 */
  {  80,  10, 168}, /* 13:                  MINUS shift  168 */
  { 149,   0,  95}, /* 14:                   expr shift  95 */
  {  82,  12, 164}, /* 15:                    NOT shift  164 */
  {  16,   0, 172}, /* 16:                   CASE shift  172 */
  {  84,  16,  97}, /* 17:                   NULL shift  97 */
/* State 87 */
  {  21,   0,  88}, /*  1:                  COMMA shift  88 */
/* State 88 */
  {  80,   4, 168}, /*  1:                  MINUS shift  168 */
  { 193,   7,  89}, /*  2:               sortitem shift  89 */
  {  82,   0, 164}, /*  3:                    NOT shift  164 */
  {  16,   0, 172}, /*  4:                   CASE shift  172 */
  {  84,   0,  97}, /*  5:                   NULL shift  97 */
  { 149,   0,  95}, /*  6:                   expr shift  95 */
  {  65,   0, 101}, /*  7:                INTEGER shift  101 */
  {  71,   0,  64}, /*  8:                JOIN_KW shift  64 */
  {  56,   0,  61}, /*  9:                     ID shift  61 */
  {  12,   0, 166}, /* 10:                 BITNOT shift  166 */
  {  90,   0, 170}, /* 11:                   PLUS shift  170 */
  { 109,  16,  63}, /* 12:                 STRING shift  63 */
  {  76,  10,  65}, /* 13:                     LP shift  65 */
  { 173,  12,  98}, /* 14:                     nm shift  98 */
  {  46,   0, 102}, /* 15:                  FLOAT shift  102 */
  {  93,   0, 182}, /* 16:                  RAISE shift  182 */
/* State 89 */
  {  19,   0,  92}, /*  1:                COLLATE shift  92 */
  { 135,   1,  90}, /*  2:                collate shift  90 */
/* State 90 */
  { 195,   0,  91}, /*  1:              sortorder shift  91 */
  {  34,   3,  56}, /*  2:                   DESC shift  56 */
  {   7,   0,  55}, /*  3:                    ASC shift  55 */
/* State 92 */
  { 156,   2,  94}, /*  1:                     id shift  94 */
  {  56,   0,  93}, /*  2:                     ID shift  93 */
/* State 95 */
  {  81,   4, 114}, /*  1:                     NE shift  114 */
  {  82,   0, 128}, /*  2:                    NOT shift  128 */
  {  83,   0, 150}, /*  3:                NOTNULL shift  150 */
  {  54,   0, 108}, /*  4:                     GT shift  108 */
  {  60,   0, 155}, /*  5:                     IN shift  155 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  { 168,   5, 126}, /*  7:                 likeop shift  126 */
  {  88,   0, 104}, /*  8:                     OR shift  104 */
  {  68,   0, 146}, /*  9:                     IS shift  146 */
  {  90,   0, 133}, /* 10:                   PLUS shift  133 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  42,   0, 116}, /* 13:                     EQ shift  116 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  95,   9, 141}, /* 15:                    REM shift  141 */
  {  69,  13, 145}, /* 16:                 ISNULL shift  145 */
  {  74,   0, 131}, /* 17:                   LIKE shift  131 */
  {  78,  19, 106}, /* 18:                     LT shift  106 */
  {  51,  22, 112}, /* 19:                     GE shift  112 */
  {  73,   0, 110}, /* 20:                     LE shift  110 */
  { 101,  17, 124}, /* 21:                 RSHIFT shift  124 */
  {  24,   0, 143}, /* 22:                 CONCAT shift  143 */
  {  80,   0, 135}, /* 23:                  MINUS shift  135 */
  {  77,   0, 122}, /* 24:                 LSHIFT shift  122 */
  { 105,  18, 139}, /* 25:                  SLASH shift  139 */
  {  52,   0, 132}, /* 26:                   GLOB shift  132 */
  { 107,  23, 137}, /* 27:                   STAR shift  137 */
/* State 96 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 103}, /* 15:                   expr shift  103 */
/* State 98 */
  {  36,   0,  99}, /*  1:                    DOT shift  99 */
/* State 99 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 100}, /*  2:                     nm shift  100 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 103 */
  {  51,   0, 112}, /*  1:                     GE shift  112 */
  { 101,   1, 124}, /*  2:                 RSHIFT shift  124 */
  {  77,  10, 122}, /*  3:                 LSHIFT shift  122 */
  {  78,   0, 106}, /*  4:                     LT shift  106 */
  {  54,   0, 108}, /*  5:                     GT shift  108 */
  { 105,  13, 139}, /*  6:                  SLASH shift  139 */
  {  81,   0, 114}, /*  7:                     NE shift  114 */
  { 107,  15, 137}, /*  8:                   STAR shift  137 */
  {  83,   0, 150}, /*  9:                NOTNULL shift  150 */
  {  52,   0, 132}, /* 10:                   GLOB shift  132 */
  {  60,  17, 155}, /* 11:                     IN shift  155 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  80,   0, 135}, /* 13:                  MINUS shift  135 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  82,   0, 128}, /* 15:                    NOT shift  128 */
  {  90,   0, 133}, /* 16:                   PLUS shift  133 */
  {  10,   0, 151}, /* 17:                BETWEEN shift  151 */
  {  42,   0, 116}, /* 18:                     EQ shift  116 */
  { 168,  22, 126}, /* 19:                 likeop shift  126 */
  {  69,   0, 145}, /* 20:                 ISNULL shift  145 */
  {  95,   0, 141}, /* 21:                    REM shift  141 */
  {  68,   0, 146}, /* 22:                     IS shift  146 */
  {  24,   0, 143}, /* 23:                 CONCAT shift  143 */
  {  73,   0, 110}, /* 24:                     LE shift  110 */
  {  74,  23, 131}, /* 25:                   LIKE shift  131 */
/* State 104 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 105}, /* 15:                   expr shift  105 */
/* State 105 */
  {  78,   7, 106}, /*  1:                     LT shift  106 */
  { 105,   0, 139}, /*  2:                  SLASH shift  139 */
  {  80,   8, 135}, /*  3:                  MINUS shift  135 */
  { 107,  10, 137}, /*  4:                   STAR shift  137 */
  {  82,   0, 128}, /*  5:                    NOT shift  128 */
  {  83,  15, 150}, /*  6:                NOTNULL shift  150 */
  {  52,   0, 132}, /*  7:                   GLOB shift  132 */
  {  54,   0, 108}, /*  8:                     GT shift  108 */
  {  60,   0, 155}, /*  9:                     IN shift  155 */
  {  81,   0, 114}, /* 10:                     NE shift  114 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  { 168,  16, 126}, /* 13:                 likeop shift  126 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {   5,   0,  96}, /* 15:                    AND shift  96 */
  {  90,   0, 133}, /* 16:                   PLUS shift  133 */
  {  68,  19, 146}, /* 17:                     IS shift  146 */
  {  95,  20, 141}, /* 18:                    REM shift  141 */
  {  42,   0, 116}, /* 19:                     EQ shift  116 */
  {  69,   0, 145}, /* 20:                 ISNULL shift  145 */
  {  51,   0, 112}, /* 21:                     GE shift  112 */
  {  73,   0, 110}, /* 22:                     LE shift  110 */
  {  74,   0, 131}, /* 23:                   LIKE shift  131 */
  { 101,   0, 124}, /* 24:                 RSHIFT shift  124 */
  {  24,   0, 143}, /* 25:                 CONCAT shift  143 */
  {  77,  21, 122}, /* 26:                 LSHIFT shift  122 */
/* State 106 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 107}, /* 15:                   expr shift  107 */
/* State 107 */
  {  77,   2, 122}, /*  1:                 LSHIFT shift  122 */
  {  11,   0, 118}, /*  2:                 BITAND shift  118 */
  { 101,   5, 124}, /*  3:                 RSHIFT shift  124 */
  { 168,   6, 126}, /*  4:                 likeop shift  126 */
  {  90,  10, 133}, /*  5:                   PLUS shift  133 */
  {  80,   0, 135}, /*  6:                  MINUS shift  135 */
  { 105,   0, 139}, /*  7:                  SLASH shift  139 */
  {  95,   0, 141}, /*  8:                    REM shift  141 */
  { 107,   0, 137}, /*  9:                   STAR shift  137 */
  {  24,  11, 143}, /* 10:                 CONCAT shift  143 */
  {  13,   0, 120}, /* 11:                  BITOR shift  120 */
/* State 108 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 109}, /* 15:                   expr shift  109 */
/* State 109 */
  {  77,   2, 122}, /*  1:                 LSHIFT shift  122 */
  {  11,   0, 118}, /*  2:                 BITAND shift  118 */
  { 101,   5, 124}, /*  3:                 RSHIFT shift  124 */
  { 168,   6, 126}, /*  4:                 likeop shift  126 */
  {  90,  10, 133}, /*  5:                   PLUS shift  133 */
  {  80,   0, 135}, /*  6:                  MINUS shift  135 */
  { 105,   0, 139}, /*  7:                  SLASH shift  139 */
  {  95,   0, 141}, /*  8:                    REM shift  141 */
  { 107,   0, 137}, /*  9:                   STAR shift  137 */
  {  24,  11, 143}, /* 10:                 CONCAT shift  143 */
  {  13,   0, 120}, /* 11:                  BITOR shift  120 */
/* State 110 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 111}, /* 15:                   expr shift  111 */
/* State 111 */
  {  77,   2, 122}, /*  1:                 LSHIFT shift  122 */
  {  11,   0, 118}, /*  2:                 BITAND shift  118 */
  { 101,   5, 124}, /*  3:                 RSHIFT shift  124 */
  { 168,   6, 126}, /*  4:                 likeop shift  126 */
  {  90,  10, 133}, /*  5:                   PLUS shift  133 */
  {  80,   0, 135}, /*  6:                  MINUS shift  135 */
  { 105,   0, 139}, /*  7:                  SLASH shift  139 */
  {  95,   0, 141}, /*  8:                    REM shift  141 */
  { 107,   0, 137}, /*  9:                   STAR shift  137 */
  {  24,  11, 143}, /* 10:                 CONCAT shift  143 */
  {  13,   0, 120}, /* 11:                  BITOR shift  120 */
/* State 112 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 113}, /* 15:                   expr shift  113 */
/* State 113 */
  {  77,   2, 122}, /*  1:                 LSHIFT shift  122 */
  {  11,   0, 118}, /*  2:                 BITAND shift  118 */
  { 101,   5, 124}, /*  3:                 RSHIFT shift  124 */
  { 168,   6, 126}, /*  4:                 likeop shift  126 */
  {  90,  10, 133}, /*  5:                   PLUS shift  133 */
  {  80,   0, 135}, /*  6:                  MINUS shift  135 */
  { 105,   0, 139}, /*  7:                  SLASH shift  139 */
  {  95,   0, 141}, /*  8:                    REM shift  141 */
  { 107,   0, 137}, /*  9:                   STAR shift  137 */
  {  24,  11, 143}, /* 10:                 CONCAT shift  143 */
  {  13,   0, 120}, /* 11:                  BITOR shift  120 */
/* State 114 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 115}, /* 15:                   expr shift  115 */
/* State 115 */
  { 105,   2, 139}, /*  1:                  SLASH shift  139 */
  {  90,   0, 133}, /*  2:                   PLUS shift  133 */
  { 107,   5, 137}, /*  3:                   STAR shift  137 */
  { 168,   8, 126}, /*  4:                 likeop shift  126 */
  {  77,   0, 122}, /*  5:                 LSHIFT shift  122 */
  {  95,   9, 141}, /*  6:                    REM shift  141 */
  {  51,   0, 112}, /*  7:                     GE shift  112 */
  {  78,   0, 106}, /*  8:                     LT shift  106 */
  {  80,   0, 135}, /*  9:                  MINUS shift  135 */
  {  54,  11, 108}, /* 10:                     GT shift  108 */
  {  24,   0, 143}, /* 11:                 CONCAT shift  143 */
  { 101,  13, 124}, /* 12:                 RSHIFT shift  124 */
  {  11,   0, 118}, /* 13:                 BITAND shift  118 */
  {  73,  15, 110}, /* 14:                     LE shift  110 */
  {  13,   0, 120}, /* 15:                  BITOR shift  120 */
/* State 116 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 117}, /* 15:                   expr shift  117 */
/* State 117 */
  { 105,   2, 139}, /*  1:                  SLASH shift  139 */
  {  90,   0, 133}, /*  2:                   PLUS shift  133 */
  { 107,   5, 137}, /*  3:                   STAR shift  137 */
  { 168,   8, 126}, /*  4:                 likeop shift  126 */
  {  77,   0, 122}, /*  5:                 LSHIFT shift  122 */
  {  95,   9, 141}, /*  6:                    REM shift  141 */
  {  51,   0, 112}, /*  7:                     GE shift  112 */
  {  78,   0, 106}, /*  8:                     LT shift  106 */
  {  80,   0, 135}, /*  9:                  MINUS shift  135 */
  {  54,  11, 108}, /* 10:                     GT shift  108 */
  {  24,   0, 143}, /* 11:                 CONCAT shift  143 */
  { 101,  13, 124}, /* 12:                 RSHIFT shift  124 */
  {  11,   0, 118}, /* 13:                 BITAND shift  118 */
  {  73,  15, 110}, /* 14:                     LE shift  110 */
  {  13,   0, 120}, /* 15:                  BITOR shift  120 */
/* State 118 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 119}, /* 15:                   expr shift  119 */
/* State 119 */
  { 168,   2, 126}, /*  1:                 likeop shift  126 */
  { 105,   0, 139}, /*  2:                  SLASH shift  139 */
  { 107,   0, 137}, /*  3:                   STAR shift  137 */
  {  80,   6, 135}, /*  4:                  MINUS shift  135 */
  {  95,   0, 141}, /*  5:                    REM shift  141 */
  {  24,   0, 143}, /*  6:                 CONCAT shift  143 */
  {  90,   0, 133}, /*  7:                   PLUS shift  133 */
/* State 120 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 121}, /* 15:                   expr shift  121 */
/* State 121 */
  { 168,   2, 126}, /*  1:                 likeop shift  126 */
  { 105,   0, 139}, /*  2:                  SLASH shift  139 */
  { 107,   0, 137}, /*  3:                   STAR shift  137 */
  {  80,   6, 135}, /*  4:                  MINUS shift  135 */
  {  95,   0, 141}, /*  5:                    REM shift  141 */
  {  24,   0, 143}, /*  6:                 CONCAT shift  143 */
  {  90,   0, 133}, /*  7:                   PLUS shift  133 */
/* State 122 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 123}, /* 15:                   expr shift  123 */
/* State 123 */
  { 168,   2, 126}, /*  1:                 likeop shift  126 */
  { 105,   0, 139}, /*  2:                  SLASH shift  139 */
  { 107,   0, 137}, /*  3:                   STAR shift  137 */
  {  80,   6, 135}, /*  4:                  MINUS shift  135 */
  {  95,   0, 141}, /*  5:                    REM shift  141 */
  {  24,   0, 143}, /*  6:                 CONCAT shift  143 */
  {  90,   0, 133}, /*  7:                   PLUS shift  133 */
/* State 124 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 125}, /* 15:                   expr shift  125 */
/* State 125 */
  { 168,   2, 126}, /*  1:                 likeop shift  126 */
  { 105,   0, 139}, /*  2:                  SLASH shift  139 */
  { 107,   0, 137}, /*  3:                   STAR shift  137 */
  {  80,   6, 135}, /*  4:                  MINUS shift  135 */
  {  95,   0, 141}, /*  5:                    REM shift  141 */
  {  24,   0, 143}, /*  6:                 CONCAT shift  143 */
  {  90,   0, 133}, /*  7:                   PLUS shift  133 */
/* State 126 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 127}, /* 15:                   expr shift  127 */
/* State 127 */
  { 105,   2, 139}, /*  1:                  SLASH shift  139 */
  {  90,   0, 133}, /*  2:                   PLUS shift  133 */
  { 107,   5, 137}, /*  3:                   STAR shift  137 */
  { 168,   8, 126}, /*  4:                 likeop shift  126 */
  {  77,   0, 122}, /*  5:                 LSHIFT shift  122 */
  {  95,   9, 141}, /*  6:                    REM shift  141 */
  {  51,   0, 112}, /*  7:                     GE shift  112 */
  {  78,   0, 106}, /*  8:                     LT shift  106 */
  {  80,   0, 135}, /*  9:                  MINUS shift  135 */
  {  54,  11, 108}, /* 10:                     GT shift  108 */
  {  24,   0, 143}, /* 11:                 CONCAT shift  143 */
  { 101,  13, 124}, /* 12:                 RSHIFT shift  124 */
  {  11,   0, 118}, /* 13:                 BITAND shift  118 */
  {  73,  15, 110}, /* 14:                     LE shift  110 */
  {  13,   0, 120}, /* 15:                  BITOR shift  120 */
/* State 128 */
  { 168,   2, 129}, /*  1:                 likeop shift  129 */
  {  84,   4, 209}, /*  2:                   NULL shift  209 */
  {  74,   0, 131}, /*  3:                   LIKE shift  131 */
  {  60,   0, 214}, /*  4:                     IN shift  214 */
  {  52,   6, 132}, /*  5:                   GLOB shift  132 */
  {  10,   0, 210}, /*  6:                BETWEEN shift  210 */
/* State 129 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 130}, /* 15:                   expr shift  130 */
/* State 130 */
  { 105,   2, 139}, /*  1:                  SLASH shift  139 */
  {  90,   0, 133}, /*  2:                   PLUS shift  133 */
  { 107,   5, 137}, /*  3:                   STAR shift  137 */
  { 168,   8, 126}, /*  4:                 likeop shift  126 */
  {  77,   0, 122}, /*  5:                 LSHIFT shift  122 */
  {  95,   9, 141}, /*  6:                    REM shift  141 */
  {  51,   0, 112}, /*  7:                     GE shift  112 */
  {  78,   0, 106}, /*  8:                     LT shift  106 */
  {  80,   0, 135}, /*  9:                  MINUS shift  135 */
  {  54,  11, 108}, /* 10:                     GT shift  108 */
  {  24,   0, 143}, /* 11:                 CONCAT shift  143 */
  { 101,  13, 124}, /* 12:                 RSHIFT shift  124 */
  {  11,   0, 118}, /* 13:                 BITAND shift  118 */
  {  73,  15, 110}, /* 14:                     LE shift  110 */
  {  13,   0, 120}, /* 15:                  BITOR shift  120 */
/* State 133 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 134}, /* 15:                   expr shift  134 */
/* State 134 */
  { 105,   2, 139}, /*  1:                  SLASH shift  139 */
  {  95,   0, 141}, /*  2:                    REM shift  141 */
  { 107,   0, 137}, /*  3:                   STAR shift  137 */
  { 168,   0, 126}, /*  4:                 likeop shift  126 */
  {  24,   0, 143}, /*  5:                 CONCAT shift  143 */
/* State 135 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 136}, /* 15:                   expr shift  136 */
/* State 136 */
  { 105,   2, 139}, /*  1:                  SLASH shift  139 */
  {  95,   0, 141}, /*  2:                    REM shift  141 */
  { 107,   0, 137}, /*  3:                   STAR shift  137 */
  { 168,   0, 126}, /*  4:                 likeop shift  126 */
  {  24,   0, 143}, /*  5:                 CONCAT shift  143 */
/* State 137 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 138}, /* 15:                   expr shift  138 */
/* State 138 */
  { 168,   2, 126}, /*  1:                 likeop shift  126 */
  {  24,   0, 143}, /*  2:                 CONCAT shift  143 */
/* State 139 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 140}, /* 15:                   expr shift  140 */
/* State 140 */
  { 168,   2, 126}, /*  1:                 likeop shift  126 */
  {  24,   0, 143}, /*  2:                 CONCAT shift  143 */
/* State 141 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 142}, /* 15:                   expr shift  142 */
/* State 142 */
  { 168,   2, 126}, /*  1:                 likeop shift  126 */
  {  24,   0, 143}, /*  2:                 CONCAT shift  143 */
/* State 143 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 144}, /* 15:                   expr shift  144 */
/* State 144 */
  { 168,   0, 126}, /*  1:                 likeop shift  126 */
/* State 146 */
  {  84,   2, 147}, /*  1:                   NULL shift  147 */
  {  82,   0, 148}, /*  2:                    NOT shift  148 */
/* State 148 */
  {  84,   0, 149}, /*  1:                   NULL shift  149 */
/* State 151 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 152}, /* 15:                   expr shift  152 */
/* State 152 */
  {  81,   4, 114}, /*  1:                     NE shift  114 */
  {  82,   0, 128}, /*  2:                    NOT shift  128 */
  {  83,   0, 150}, /*  3:                NOTNULL shift  150 */
  {  54,   0, 108}, /*  4:                     GT shift  108 */
  {  60,   0, 155}, /*  5:                     IN shift  155 */
  {   5,   0, 153}, /*  6:                    AND shift  153 */
  { 168,   5, 126}, /*  7:                 likeop shift  126 */
  {  88,   0, 104}, /*  8:                     OR shift  104 */
  {  68,   0, 146}, /*  9:                     IS shift  146 */
  {  90,   0, 133}, /* 10:                   PLUS shift  133 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  42,   0, 116}, /* 13:                     EQ shift  116 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  95,   9, 141}, /* 15:                    REM shift  141 */
  {  69,  13, 145}, /* 16:                 ISNULL shift  145 */
  {  74,   0, 131}, /* 17:                   LIKE shift  131 */
  {  78,  19, 106}, /* 18:                     LT shift  106 */
  {  51,  22, 112}, /* 19:                     GE shift  112 */
  {  73,   0, 110}, /* 20:                     LE shift  110 */
  { 101,  17, 124}, /* 21:                 RSHIFT shift  124 */
  {  24,   0, 143}, /* 22:                 CONCAT shift  143 */
  {  80,   0, 135}, /* 23:                  MINUS shift  135 */
  {  77,   0, 122}, /* 24:                 LSHIFT shift  122 */
  { 105,  18, 139}, /* 25:                  SLASH shift  139 */
  {  52,   0, 132}, /* 26:                   GLOB shift  132 */
  { 107,  23, 137}, /* 27:                   STAR shift  137 */
/* State 153 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 154}, /* 15:                   expr shift  154 */
/* State 154 */
  { 105,   2, 139}, /*  1:                  SLASH shift  139 */
  {  90,   0, 133}, /*  2:                   PLUS shift  133 */
  { 107,   5, 137}, /*  3:                   STAR shift  137 */
  { 168,   8, 126}, /*  4:                 likeop shift  126 */
  {  77,   0, 122}, /*  5:                 LSHIFT shift  122 */
  {  95,   9, 141}, /*  6:                    REM shift  141 */
  {  51,   0, 112}, /*  7:                     GE shift  112 */
  {  78,   0, 106}, /*  8:                     LT shift  106 */
  {  80,   0, 135}, /*  9:                  MINUS shift  135 */
  {  54,  11, 108}, /* 10:                     GT shift  108 */
  {  24,   0, 143}, /* 11:                 CONCAT shift  143 */
  { 101,  13, 124}, /* 12:                 RSHIFT shift  124 */
  {  11,   0, 118}, /* 13:                 BITAND shift  118 */
  {  73,  15, 110}, /* 14:                     LE shift  110 */
  {  13,   0, 120}, /* 15:                  BITOR shift  120 */
/* State 155 */
  {  76,   0, 156}, /*  1:                     LP shift  156 */
/* State 156 */
  {  80,   0, 168}, /*  1:                  MINUS shift  168 */
  {  82,   0, 164}, /*  2:                    NOT shift  164 */
  { 102,   2,  70}, /*  3:                 SELECT shift  70 */
  { 149,   8, 163}, /*  4:                   expr shift  163 */
  {  84,   0,  97}, /*  5:                   NULL shift  97 */
  {  65,   0, 101}, /*  6:                INTEGER shift  101 */
  {  46,   0, 102}, /*  7:                  FLOAT shift  102 */
  { 109,   0,  63}, /*  8:                 STRING shift  63 */
  {  90,   0, 170}, /*  9:                   PLUS shift  170 */
  { 189,   4, 157}, /* 10:                 select shift  157 */
  { 150,   9, 208}, /* 11:               expritem shift  208 */
  { 151,  15, 204}, /* 12:               exprlist shift  204 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  { 173,  16,  98}, /* 14:                     nm shift  98 */
  {  71,   0,  64}, /* 15:                JOIN_KW shift  64 */
  {  93,   0, 182}, /* 16:                  RAISE shift  182 */
  {  76,  19,  65}, /* 17:                     LP shift  65 */
  { 177,   0,  66}, /* 18:              oneselect shift  66 */
  {  56,  20,  61}, /* 19:                     ID shift  61 */
  {  16,   0, 172}, /* 20:                   CASE shift  172 */
/* State 157 */
  { 100,   0, 162}, /*  1:                     RP shift  162 */
  {  66,   0, 160}, /*  2:              INTERSECT shift  160 */
  { 172,   5,  68}, /*  3:         multiselect_op shift  68 */
  {  43,   0, 161}, /*  4:                 EXCEPT shift  161 */
  { 117,   0, 158}, /*  5:                  UNION shift  158 */
/* State 158 */
  { 102,   2, 625}, /*  1:                 SELECT reduce 102 */
  {   4,   0, 159}, /*  2:                    ALL shift  159 */
/* State 159 */
  { 102,   0, 626}, /*  1:                 SELECT reduce 103 */
/* State 160 */
  { 102,   0, 627}, /*  1:                 SELECT reduce 104 */
/* State 161 */
  { 102,   0, 628}, /*  1:                 SELECT reduce 105 */
/* State 163 */
  {  81,   4, 114}, /*  1:                     NE shift  114 */
  {  82,   0, 128}, /*  2:                    NOT shift  128 */
  {  83,   0, 150}, /*  3:                NOTNULL shift  150 */
  {  54,   0, 108}, /*  4:                     GT shift  108 */
  {  60,   0, 155}, /*  5:                     IN shift  155 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  { 168,   5, 126}, /*  7:                 likeop shift  126 */
  {  88,   0, 104}, /*  8:                     OR shift  104 */
  {  68,   0, 146}, /*  9:                     IS shift  146 */
  {  90,   0, 133}, /* 10:                   PLUS shift  133 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  42,   0, 116}, /* 13:                     EQ shift  116 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  95,   9, 141}, /* 15:                    REM shift  141 */
  {  69,  13, 145}, /* 16:                 ISNULL shift  145 */
  {  74,   0, 131}, /* 17:                   LIKE shift  131 */
  {  78,  19, 106}, /* 18:                     LT shift  106 */
  {  51,  22, 112}, /* 19:                     GE shift  112 */
  {  73,   0, 110}, /* 20:                     LE shift  110 */
  { 101,  17, 124}, /* 21:                 RSHIFT shift  124 */
  {  24,   0, 143}, /* 22:                 CONCAT shift  143 */
  {  80,   0, 135}, /* 23:                  MINUS shift  135 */
  {  77,   0, 122}, /* 24:                 LSHIFT shift  122 */
  { 105,  18, 139}, /* 25:                  SLASH shift  139 */
  {  52,   0, 132}, /* 26:                   GLOB shift  132 */
  { 107,  23, 137}, /* 27:                   STAR shift  137 */
/* State 164 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 165}, /* 15:                   expr shift  165 */
/* State 165 */
  {  51,   0, 112}, /*  1:                     GE shift  112 */
  { 101,   1, 124}, /*  2:                 RSHIFT shift  124 */
  {  77,  10, 122}, /*  3:                 LSHIFT shift  122 */
  {  78,   0, 106}, /*  4:                     LT shift  106 */
  {  54,   0, 108}, /*  5:                     GT shift  108 */
  { 105,  13, 139}, /*  6:                  SLASH shift  139 */
  {  81,   0, 114}, /*  7:                     NE shift  114 */
  { 107,  15, 137}, /*  8:                   STAR shift  137 */
  {  83,   0, 150}, /*  9:                NOTNULL shift  150 */
  {  52,   0, 132}, /* 10:                   GLOB shift  132 */
  {  60,  17, 155}, /* 11:                     IN shift  155 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  80,   0, 135}, /* 13:                  MINUS shift  135 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  82,   0, 128}, /* 15:                    NOT shift  128 */
  {  90,   0, 133}, /* 16:                   PLUS shift  133 */
  {  10,   0, 151}, /* 17:                BETWEEN shift  151 */
  {  42,   0, 116}, /* 18:                     EQ shift  116 */
  { 168,  22, 126}, /* 19:                 likeop shift  126 */
  {  69,   0, 145}, /* 20:                 ISNULL shift  145 */
  {  95,   0, 141}, /* 21:                    REM shift  141 */
  {  68,   0, 146}, /* 22:                     IS shift  146 */
  {  24,   0, 143}, /* 23:                 CONCAT shift  143 */
  {  73,   0, 110}, /* 24:                     LE shift  110 */
  {  74,  23, 131}, /* 25:                   LIKE shift  131 */
/* State 166 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 167}, /* 15:                   expr shift  167 */
/* State 167 */
  { 168,   0, 126}, /*  1:                 likeop shift  126 */
/* State 168 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 169}, /* 15:                   expr shift  169 */
/* State 169 */
  { 168,   0, 126}, /*  1:                 likeop shift  126 */
/* State 170 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 171}, /* 15:                   expr shift  171 */
/* State 171 */
  { 168,   0, 126}, /*  1:                 likeop shift  126 */
/* State 172 */
  {  71,   0,  64}, /*  1:                JOIN_KW shift  64 */
  {  90,   3, 170}, /*  2:                   PLUS shift  170 */
  {  56,   0,  61}, /*  3:                     ID shift  61 */
  { 173,   1,  98}, /*  4:                     nm shift  98 */
  {  76,   0,  65}, /*  5:                     LP shift  65 */
  { 124,   2, 745}, /*  6:                   WHEN reduce 222 */
  {  80,  10, 168}, /*  7:                  MINUS shift  168 */
  { 109,   0,  63}, /*  8:                 STRING shift  63 */
  {  93,   5, 182}, /*  9:                  RAISE shift  182 */
  {  46,  11, 102}, /* 10:                  FLOAT shift  102 */
  {  12,   0, 166}, /* 11:                 BITNOT shift  166 */
  {  65,   0, 101}, /* 12:                INTEGER shift  101 */
  { 131,   7, 174}, /* 13:           case_operand shift  174 */
  { 149,   0, 173}, /* 14:                   expr shift  173 */
  {  82,  12, 164}, /* 15:                    NOT shift  164 */
  {  16,   0, 172}, /* 16:                   CASE shift  172 */
  {  84,  16,  97}, /* 17:                   NULL shift  97 */
/* State 173 */
  { 168,   0, 126}, /*  1:                 likeop shift  126 */
  {  60,   0, 155}, /*  2:                     IN shift  155 */
  {  11,   0, 118}, /*  3:                 BITAND shift  118 */
  {  68,   0, 146}, /*  4:                     IS shift  146 */
  {  88,   2, 104}, /*  5:                     OR shift  104 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  {  90,   0, 133}, /*  7:                   PLUS shift  133 */
  {  13,   0, 120}, /*  8:                  BITOR shift  120 */
  {  73,   0, 110}, /*  9:                     LE shift  110 */
  {  77,   0, 122}, /* 10:                 LSHIFT shift  122 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  95,   3, 141}, /* 12:                    REM shift  141 */
  { 124,   4, 744}, /* 13:                   WHEN reduce 221 */
  {  69,   8, 145}, /* 14:                 ISNULL shift  145 */
  {  42,   0, 116}, /* 15:                     EQ shift  116 */
  {  51,   0, 112}, /* 16:                     GE shift  112 */
  {  52,  20, 132}, /* 17:                   GLOB shift  132 */
  { 101,   9, 124}, /* 18:                 RSHIFT shift  124 */
  {  74,   0, 131}, /* 19:                   LIKE shift  131 */
  {  24,   0, 143}, /* 20:                 CONCAT shift  143 */
  {  54,   0, 108}, /* 21:                     GT shift  108 */
  { 105,  10, 139}, /* 22:                  SLASH shift  139 */
  {  78,   0, 106}, /* 23:                     LT shift  106 */
  { 107,  16, 137}, /* 24:                   STAR shift  137 */
  {  80,  17, 135}, /* 25:                  MINUS shift  135 */
  {  81,   0, 114}, /* 26:                     NE shift  114 */
  {  82,  21, 128}, /* 27:                    NOT shift  128 */
  {  83,   0, 150}, /* 28:                NOTNULL shift  150 */
/* State 174 */
  { 130,   2, 175}, /*  1:          case_exprlist shift  175 */
  { 124,   0, 200}, /*  2:                   WHEN shift  200 */
/* State 175 */
  { 124,   3, 178}, /*  1:                   WHEN shift  178 */
  { 129,   0, 176}, /*  2:              case_else shift  176 */
  {  40,   0, 743}, /*  3:                    END reduce 220 */
  {  39,   0, 198}, /*  4:                   ELSE shift  198 */
/* State 176 */
  {  40,   0, 177}, /*  1:                    END shift  177 */
/* State 178 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 179}, /* 15:                   expr shift  179 */
/* State 179 */
  { 168,   2, 126}, /*  1:                 likeop shift  126 */
  { 112,   0, 180}, /*  2:                   THEN shift  180 */
  {  60,   0, 155}, /*  3:                     IN shift  155 */
  {  11,   0, 118}, /*  4:                 BITAND shift  118 */
  {  88,   3, 104}, /*  5:                     OR shift  104 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  {  90,   0, 133}, /*  7:                   PLUS shift  133 */
  {  13,   0, 120}, /*  8:                  BITOR shift  120 */
  {  73,   0, 110}, /*  9:                     LE shift  110 */
  {  77,   0, 122}, /* 10:                 LSHIFT shift  122 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  95,   4, 141}, /* 12:                    REM shift  141 */
  {  68,   0, 146}, /* 13:                     IS shift  146 */
  {  69,   8, 145}, /* 14:                 ISNULL shift  145 */
  {  42,   0, 116}, /* 15:                     EQ shift  116 */
  {  51,   0, 112}, /* 16:                     GE shift  112 */
  {  52,  20, 132}, /* 17:                   GLOB shift  132 */
  { 101,   9, 124}, /* 18:                 RSHIFT shift  124 */
  {  74,   0, 131}, /* 19:                   LIKE shift  131 */
  {  24,   0, 143}, /* 20:                 CONCAT shift  143 */
  {  54,   0, 108}, /* 21:                     GT shift  108 */
  { 105,  10, 139}, /* 22:                  SLASH shift  139 */
  {  78,   0, 106}, /* 23:                     LT shift  106 */
  { 107,  16, 137}, /* 24:                   STAR shift  137 */
  {  80,  17, 135}, /* 25:                  MINUS shift  135 */
  {  81,   0, 114}, /* 26:                     NE shift  114 */
  {  82,  21, 128}, /* 27:                    NOT shift  128 */
  {  83,   0, 150}, /* 28:                NOTNULL shift  150 */
/* State 180 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 181}, /* 15:                   expr shift  181 */
/* State 181 */
  {  81,   4, 114}, /*  1:                     NE shift  114 */
  {  82,   0, 128}, /*  2:                    NOT shift  128 */
  {  83,   0, 150}, /*  3:                NOTNULL shift  150 */
  {  54,   0, 108}, /*  4:                     GT shift  108 */
  {  60,   0, 155}, /*  5:                     IN shift  155 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  { 168,   5, 126}, /*  7:                 likeop shift  126 */
  {  88,   0, 104}, /*  8:                     OR shift  104 */
  {  68,   0, 146}, /*  9:                     IS shift  146 */
  {  90,   0, 133}, /* 10:                   PLUS shift  133 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  42,   0, 116}, /* 13:                     EQ shift  116 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  95,   9, 141}, /* 15:                    REM shift  141 */
  {  69,  13, 145}, /* 16:                 ISNULL shift  145 */
  {  74,   0, 131}, /* 17:                   LIKE shift  131 */
  {  78,  19, 106}, /* 18:                     LT shift  106 */
  {  51,  22, 112}, /* 19:                     GE shift  112 */
  {  73,   0, 110}, /* 20:                     LE shift  110 */
  { 101,  17, 124}, /* 21:                 RSHIFT shift  124 */
  {  24,   0, 143}, /* 22:                 CONCAT shift  143 */
  {  80,   0, 135}, /* 23:                  MINUS shift  135 */
  {  77,   0, 122}, /* 24:                 LSHIFT shift  122 */
  { 105,  18, 139}, /* 25:                  SLASH shift  139 */
  {  52,   0, 132}, /* 26:                   GLOB shift  132 */
  { 107,  23, 137}, /* 27:                   STAR shift  137 */
/* State 182 */
  {  76,   0, 183}, /*  1:                     LP shift  183 */
/* State 183 */
  {  45,   4, 194}, /*  1:                   FAIL shift  194 */
  {  57,   1, 184}, /*  2:                 IGNORE shift  184 */
  {  98,   0, 186}, /*  3:               ROLLBACK shift  186 */
  {   1,   0, 190}, /*  4:                  ABORT shift  190 */
/* State 184 */
  { 100,   0, 185}, /*  1:                     RP shift  185 */
/* State 186 */
  {  21,   0, 187}, /*  1:                  COMMA shift  187 */
/* State 187 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 188}, /*  2:                     nm shift  188 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 188 */
  { 100,   0, 189}, /*  1:                     RP shift  189 */
/* State 190 */
  {  21,   0, 191}, /*  1:                  COMMA shift  191 */
/* State 191 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 192}, /*  2:                     nm shift  192 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 192 */
  { 100,   0, 193}, /*  1:                     RP shift  193 */
/* State 194 */
  {  21,   0, 195}, /*  1:                  COMMA shift  195 */
/* State 195 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 196}, /*  2:                     nm shift  196 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 196 */
  { 100,   0, 197}, /*  1:                     RP shift  197 */
/* State 198 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 199}, /* 15:                   expr shift  199 */
/* State 199 */
  { 168,   0, 126}, /*  1:                 likeop shift  126 */
  {  60,   0, 155}, /*  2:                     IN shift  155 */
  {  11,   0, 118}, /*  3:                 BITAND shift  118 */
  {  40,   0, 742}, /*  4:                    END reduce 219 */
  {  88,   2, 104}, /*  5:                     OR shift  104 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  {  90,   0, 133}, /*  7:                   PLUS shift  133 */
  {  13,   0, 120}, /*  8:                  BITOR shift  120 */
  {  73,   0, 110}, /*  9:                     LE shift  110 */
  {  77,   0, 122}, /* 10:                 LSHIFT shift  122 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  95,   3, 141}, /* 12:                    REM shift  141 */
  {  68,   4, 146}, /* 13:                     IS shift  146 */
  {  69,   8, 145}, /* 14:                 ISNULL shift  145 */
  {  42,   0, 116}, /* 15:                     EQ shift  116 */
  {  51,   0, 112}, /* 16:                     GE shift  112 */
  {  52,  20, 132}, /* 17:                   GLOB shift  132 */
  { 101,   9, 124}, /* 18:                 RSHIFT shift  124 */
  {  74,   0, 131}, /* 19:                   LIKE shift  131 */
  {  24,   0, 143}, /* 20:                 CONCAT shift  143 */
  {  54,   0, 108}, /* 21:                     GT shift  108 */
  { 105,  10, 139}, /* 22:                  SLASH shift  139 */
  {  78,   0, 106}, /* 23:                     LT shift  106 */
  { 107,  16, 137}, /* 24:                   STAR shift  137 */
  {  80,  17, 135}, /* 25:                  MINUS shift  135 */
  {  81,   0, 114}, /* 26:                     NE shift  114 */
  {  82,  21, 128}, /* 27:                    NOT shift  128 */
  {  83,   0, 150}, /* 28:                NOTNULL shift  150 */
/* State 200 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 201}, /* 15:                   expr shift  201 */
/* State 201 */
  { 168,   2, 126}, /*  1:                 likeop shift  126 */
  { 112,   0, 202}, /*  2:                   THEN shift  202 */
  {  60,   0, 155}, /*  3:                     IN shift  155 */
  {  11,   0, 118}, /*  4:                 BITAND shift  118 */
  {  88,   3, 104}, /*  5:                     OR shift  104 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  {  90,   0, 133}, /*  7:                   PLUS shift  133 */
  {  13,   0, 120}, /*  8:                  BITOR shift  120 */
  {  73,   0, 110}, /*  9:                     LE shift  110 */
  {  77,   0, 122}, /* 10:                 LSHIFT shift  122 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  95,   4, 141}, /* 12:                    REM shift  141 */
  {  68,   0, 146}, /* 13:                     IS shift  146 */
  {  69,   8, 145}, /* 14:                 ISNULL shift  145 */
  {  42,   0, 116}, /* 15:                     EQ shift  116 */
  {  51,   0, 112}, /* 16:                     GE shift  112 */
  {  52,  20, 132}, /* 17:                   GLOB shift  132 */
  { 101,   9, 124}, /* 18:                 RSHIFT shift  124 */
  {  74,   0, 131}, /* 19:                   LIKE shift  131 */
  {  24,   0, 143}, /* 20:                 CONCAT shift  143 */
  {  54,   0, 108}, /* 21:                     GT shift  108 */
  { 105,  10, 139}, /* 22:                  SLASH shift  139 */
  {  78,   0, 106}, /* 23:                     LT shift  106 */
  { 107,  16, 137}, /* 24:                   STAR shift  137 */
  {  80,  17, 135}, /* 25:                  MINUS shift  135 */
  {  81,   0, 114}, /* 26:                     NE shift  114 */
  {  82,  21, 128}, /* 27:                    NOT shift  128 */
  {  83,   0, 150}, /* 28:                NOTNULL shift  150 */
/* State 202 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 203}, /* 15:                   expr shift  203 */
/* State 203 */
  {  81,   4, 114}, /*  1:                     NE shift  114 */
  {  82,   0, 128}, /*  2:                    NOT shift  128 */
  {  83,   0, 150}, /*  3:                NOTNULL shift  150 */
  {  54,   0, 108}, /*  4:                     GT shift  108 */
  {  60,   0, 155}, /*  5:                     IN shift  155 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  { 168,   5, 126}, /*  7:                 likeop shift  126 */
  {  88,   0, 104}, /*  8:                     OR shift  104 */
  {  68,   0, 146}, /*  9:                     IS shift  146 */
  {  90,   0, 133}, /* 10:                   PLUS shift  133 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  42,   0, 116}, /* 13:                     EQ shift  116 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  95,   9, 141}, /* 15:                    REM shift  141 */
  {  69,  13, 145}, /* 16:                 ISNULL shift  145 */
  {  74,   0, 131}, /* 17:                   LIKE shift  131 */
  {  78,  19, 106}, /* 18:                     LT shift  106 */
  {  51,  22, 112}, /* 19:                     GE shift  112 */
  {  73,   0, 110}, /* 20:                     LE shift  110 */
  { 101,  17, 124}, /* 21:                 RSHIFT shift  124 */
  {  24,   0, 143}, /* 22:                 CONCAT shift  143 */
  {  80,   0, 135}, /* 23:                  MINUS shift  135 */
  {  77,   0, 122}, /* 24:                 LSHIFT shift  122 */
  { 105,  18, 139}, /* 25:                  SLASH shift  139 */
  {  52,   0, 132}, /* 26:                   GLOB shift  132 */
  { 107,  23, 137}, /* 27:                   STAR shift  137 */
/* State 204 */
  { 100,   0, 205}, /*  1:                     RP shift  205 */
  {  21,   0, 206}, /*  2:                  COMMA shift  206 */
/* State 206 */
  {  80,   4, 168}, /*  1:                  MINUS shift  168 */
  {  65,   0, 101}, /*  2:                INTEGER shift  101 */
  {  82,   0, 164}, /*  3:                    NOT shift  164 */
  {  16,   0, 172}, /*  4:                   CASE shift  172 */
  {  84,   0,  97}, /*  5:                   NULL shift  97 */
  { 149,   0, 163}, /*  6:                   expr shift  163 */
  { 150,   0, 207}, /*  7:               expritem shift  207 */
  {  71,   0,  64}, /*  8:                JOIN_KW shift  64 */
  {  56,   0,  61}, /*  9:                     ID shift  61 */
  {  12,   0, 166}, /* 10:                 BITNOT shift  166 */
  {  90,   0, 170}, /* 11:                   PLUS shift  170 */
  { 109,  16,  63}, /* 12:                 STRING shift  63 */
  {  76,  10,  65}, /* 13:                     LP shift  65 */
  { 173,  12,  98}, /* 14:                     nm shift  98 */
  {  46,   0, 102}, /* 15:                  FLOAT shift  102 */
  {  93,   0, 182}, /* 16:                  RAISE shift  182 */
/* State 210 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 211}, /* 15:                   expr shift  211 */
/* State 211 */
  {  81,   4, 114}, /*  1:                     NE shift  114 */
  {  82,   0, 128}, /*  2:                    NOT shift  128 */
  {  83,   0, 150}, /*  3:                NOTNULL shift  150 */
  {  54,   0, 108}, /*  4:                     GT shift  108 */
  {  60,   0, 155}, /*  5:                     IN shift  155 */
  {   5,   0, 212}, /*  6:                    AND shift  212 */
  { 168,   5, 126}, /*  7:                 likeop shift  126 */
  {  88,   0, 104}, /*  8:                     OR shift  104 */
  {  68,   0, 146}, /*  9:                     IS shift  146 */
  {  90,   0, 133}, /* 10:                   PLUS shift  133 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  42,   0, 116}, /* 13:                     EQ shift  116 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  95,   9, 141}, /* 15:                    REM shift  141 */
  {  69,  13, 145}, /* 16:                 ISNULL shift  145 */
  {  74,   0, 131}, /* 17:                   LIKE shift  131 */
  {  78,  19, 106}, /* 18:                     LT shift  106 */
  {  51,  22, 112}, /* 19:                     GE shift  112 */
  {  73,   0, 110}, /* 20:                     LE shift  110 */
  { 101,  17, 124}, /* 21:                 RSHIFT shift  124 */
  {  24,   0, 143}, /* 22:                 CONCAT shift  143 */
  {  80,   0, 135}, /* 23:                  MINUS shift  135 */
  {  77,   0, 122}, /* 24:                 LSHIFT shift  122 */
  { 105,  18, 139}, /* 25:                  SLASH shift  139 */
  {  52,   0, 132}, /* 26:                   GLOB shift  132 */
  { 107,  23, 137}, /* 27:                   STAR shift  137 */
/* State 212 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 213}, /* 15:                   expr shift  213 */
/* State 213 */
  {  51,   0, 112}, /*  1:                     GE shift  112 */
  { 101,   1, 124}, /*  2:                 RSHIFT shift  124 */
  {  77,  10, 122}, /*  3:                 LSHIFT shift  122 */
  {  78,   0, 106}, /*  4:                     LT shift  106 */
  {  54,   0, 108}, /*  5:                     GT shift  108 */
  { 105,  13, 139}, /*  6:                  SLASH shift  139 */
  {  81,   0, 114}, /*  7:                     NE shift  114 */
  { 107,  15, 137}, /*  8:                   STAR shift  137 */
  {  83,   0, 150}, /*  9:                NOTNULL shift  150 */
  {  52,   0, 132}, /* 10:                   GLOB shift  132 */
  {  60,  17, 155}, /* 11:                     IN shift  155 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  80,   0, 135}, /* 13:                  MINUS shift  135 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  82,   0, 128}, /* 15:                    NOT shift  128 */
  {  90,   0, 133}, /* 16:                   PLUS shift  133 */
  {  10,   0, 151}, /* 17:                BETWEEN shift  151 */
  {  42,   0, 116}, /* 18:                     EQ shift  116 */
  { 168,  22, 126}, /* 19:                 likeop shift  126 */
  {  69,   0, 145}, /* 20:                 ISNULL shift  145 */
  {  95,   0, 141}, /* 21:                    REM shift  141 */
  {  68,   0, 146}, /* 22:                     IS shift  146 */
  {  24,   0, 143}, /* 23:                 CONCAT shift  143 */
  {  73,   0, 110}, /* 24:                     LE shift  110 */
  {  74,  23, 131}, /* 25:                   LIKE shift  131 */
/* State 214 */
  {  76,   0, 215}, /*  1:                     LP shift  215 */
/* State 215 */
  {  80,   0, 168}, /*  1:                  MINUS shift  168 */
  {  82,   0, 164}, /*  2:                    NOT shift  164 */
  { 102,   2,  70}, /*  3:                 SELECT shift  70 */
  { 149,   8, 163}, /*  4:                   expr shift  163 */
  {  84,   0,  97}, /*  5:                   NULL shift  97 */
  {  65,   0, 101}, /*  6:                INTEGER shift  101 */
  {  46,   0, 102}, /*  7:                  FLOAT shift  102 */
  { 109,   0,  63}, /*  8:                 STRING shift  63 */
  {  90,   0, 170}, /*  9:                   PLUS shift  170 */
  { 189,   4, 216}, /* 10:                 select shift  216 */
  { 150,   9, 208}, /* 11:               expritem shift  208 */
  { 151,  15, 218}, /* 12:               exprlist shift  218 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  { 173,  16,  98}, /* 14:                     nm shift  98 */
  {  71,   0,  64}, /* 15:                JOIN_KW shift  64 */
  {  93,   0, 182}, /* 16:                  RAISE shift  182 */
  {  76,  19,  65}, /* 17:                     LP shift  65 */
  { 177,   0,  66}, /* 18:              oneselect shift  66 */
  {  56,  20,  61}, /* 19:                     ID shift  61 */
  {  16,   0, 172}, /* 20:                   CASE shift  172 */
/* State 216 */
  { 100,   0, 217}, /*  1:                     RP shift  217 */
  {  66,   0, 160}, /*  2:              INTERSECT shift  160 */
  { 172,   5,  68}, /*  3:         multiselect_op shift  68 */
  {  43,   0, 161}, /*  4:                 EXCEPT shift  161 */
  { 117,   0, 158}, /*  5:                  UNION shift  158 */
/* State 218 */
  { 100,   0, 219}, /*  1:                     RP shift  219 */
  {  21,   0, 206}, /*  2:                  COMMA shift  206 */
/* State 220 */
  {  19,   0,  92}, /*  1:                COLLATE shift  92 */
  { 135,   1, 221}, /*  2:                collate shift  221 */
/* State 221 */
  { 195,   0, 222}, /*  1:              sortorder shift  222 */
  {  34,   3,  56}, /*  2:                   DESC shift  56 */
  {   7,   0,  55}, /*  3:                    ASC shift  55 */
/* State 223 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 224}, /* 15:                   expr shift  224 */
/* State 224 */
  {  81,   4, 114}, /*  1:                     NE shift  114 */
  {  82,   0, 128}, /*  2:                    NOT shift  128 */
  {  83,   0, 150}, /*  3:                NOTNULL shift  150 */
  {  54,   0, 108}, /*  4:                     GT shift  108 */
  {  60,   0, 155}, /*  5:                     IN shift  155 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  { 168,   5, 126}, /*  7:                 likeop shift  126 */
  {  88,   0, 104}, /*  8:                     OR shift  104 */
  {  68,   0, 146}, /*  9:                     IS shift  146 */
  {  90,   0, 133}, /* 10:                   PLUS shift  133 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  42,   0, 116}, /* 13:                     EQ shift  116 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  95,   9, 141}, /* 15:                    REM shift  141 */
  {  69,  13, 145}, /* 16:                 ISNULL shift  145 */
  {  74,   0, 131}, /* 17:                   LIKE shift  131 */
  {  78,  19, 106}, /* 18:                     LT shift  106 */
  {  51,  22, 112}, /* 19:                     GE shift  112 */
  {  73,   0, 110}, /* 20:                     LE shift  110 */
  { 101,  17, 124}, /* 21:                 RSHIFT shift  124 */
  {  24,   0, 143}, /* 22:                 CONCAT shift  143 */
  {  80,   0, 135}, /* 23:                  MINUS shift  135 */
  {  77,   0, 122}, /* 24:                 LSHIFT shift  122 */
  { 105,  18, 139}, /* 25:                  SLASH shift  139 */
  {  52,   0, 132}, /* 26:                   GLOB shift  132 */
  { 107,  23, 137}, /* 27:                   STAR shift  137 */
/* State 225 */
  {  14,   0, 226}, /*  1:                     BY shift  226 */
/* State 226 */
  {  71,   0,  64}, /*  1:                JOIN_KW shift  64 */
  {  56,   0,  61}, /*  2:                     ID shift  61 */
  {  76,   0,  65}, /*  3:                     LP shift  65 */
  { 173,   1,  98}, /*  4:                     nm shift  98 */
  {  46,   7, 102}, /*  5:                  FLOAT shift  102 */
  {  90,   2, 170}, /*  6:                   PLUS shift  170 */
  {  12,   0, 166}, /*  7:                 BITNOT shift  166 */
  { 109,   0,  63}, /*  8:                 STRING shift  63 */
  {  93,   3, 182}, /*  9:                  RAISE shift  182 */
  {  82,  11, 164}, /* 10:                    NOT shift  164 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  16,   0, 172}, /* 12:                   CASE shift  172 */
  {  80,   5, 168}, /* 13:                  MINUS shift  168 */
  { 149,   0, 163}, /* 14:                   expr shift  163 */
  { 150,  10, 208}, /* 15:               expritem shift  208 */
  { 151,   0, 227}, /* 16:               exprlist shift  227 */
  {  84,  12,  97}, /* 17:                   NULL shift  97 */
/* State 227 */
  {  21,   0, 206}, /*  1:                  COMMA shift  206 */
/* State 228 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 229}, /* 15:                   expr shift  229 */
/* State 229 */
  {  81,   4, 114}, /*  1:                     NE shift  114 */
  {  82,   0, 128}, /*  2:                    NOT shift  128 */
  {  83,   0, 150}, /*  3:                NOTNULL shift  150 */
  {  54,   0, 108}, /*  4:                     GT shift  108 */
  {  60,   0, 155}, /*  5:                     IN shift  155 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  { 168,   5, 126}, /*  7:                 likeop shift  126 */
  {  88,   0, 104}, /*  8:                     OR shift  104 */
  {  68,   0, 146}, /*  9:                     IS shift  146 */
  {  90,   0, 133}, /* 10:                   PLUS shift  133 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  42,   0, 116}, /* 13:                     EQ shift  116 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  95,   9, 141}, /* 15:                    REM shift  141 */
  {  69,  13, 145}, /* 16:                 ISNULL shift  145 */
  {  74,   0, 131}, /* 17:                   LIKE shift  131 */
  {  78,  19, 106}, /* 18:                     LT shift  106 */
  {  51,  22, 112}, /* 19:                     GE shift  112 */
  {  73,   0, 110}, /* 20:                     LE shift  110 */
  { 101,  17, 124}, /* 21:                 RSHIFT shift  124 */
  {  24,   0, 143}, /* 22:                 CONCAT shift  143 */
  {  80,   0, 135}, /* 23:                  MINUS shift  135 */
  {  77,   0, 122}, /* 24:                 LSHIFT shift  122 */
  { 105,  18, 139}, /* 25:                  SLASH shift  139 */
  {  52,   0, 132}, /* 26:                   GLOB shift  132 */
  { 107,  23, 137}, /* 27:                   STAR shift  137 */
/* State 231 */
  { 196,   2, 242}, /*  1:             stl_prefix shift  242 */
  { 190,   0, 232}, /*  2:             seltablist shift  232 */
/* State 232 */
  {  70,   0, 235}, /*  1:                   JOIN shift  235 */
  {  21,   0, 234}, /*  2:                  COMMA shift  234 */
  { 166,   1, 233}, /*  3:                 joinop shift  233 */
  {  71,   0, 236}, /*  4:                JOIN_KW shift  236 */
/* State 236 */
  {  70,   0, 237}, /*  1:                   JOIN shift  237 */
  {  71,   3,  21}, /*  2:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 173,   0, 238}, /*  4:                     nm shift  238 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 238 */
  {  70,   0, 239}, /*  1:                   JOIN shift  239 */
  {  71,   3,  21}, /*  2:                JOIN_KW shift  21 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 173,   0, 240}, /*  4:                     nm shift  240 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 240 */
  {  70,   0, 241}, /*  1:                   JOIN shift  241 */
/* State 242 */
  {  71,   3,  21}, /*  1:                JOIN_KW shift  21 */
  {  76,   1, 262}, /*  2:                     LP shift  262 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 173,   0, 243}, /*  4:                     nm shift  243 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 243 */
  {  56,   4, 244}, /*  1:                     ID shift  244 */
  { 126,   1, 249}, /*  2:                     as shift  249 */
  { 157,   0, 248}, /*  3:                    ids shift  248 */
  {   6,   0, 246}, /*  4:                     AS shift  246 */
  { 109,   0, 245}, /*  5:                 STRING shift  245 */
/* State 246 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 247}, /*  2:                     nm shift  247 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 249 */
  {  87,   0, 260}, /*  1:                     ON shift  260 */
  { 175,   1, 250}, /*  2:                 on_opt shift  250 */
/* State 250 */
  { 120,   0, 252}, /*  1:                  USING shift  252 */
  { 207,   0, 251}, /*  2:              using_opt shift  251 */
/* State 252 */
  {  76,   0, 253}, /*  1:                     LP shift  253 */
/* State 253 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  { 158,   1, 259}, /*  3:                idxitem shift  259 */
  { 159,   0, 254}, /*  4:                idxlist shift  254 */
  {  71,   0,  21}, /*  5:                JOIN_KW shift  21 */
  { 173,   5, 258}, /*  6:                     nm shift  258 */
/* State 254 */
  { 100,   0, 255}, /*  1:                     RP shift  255 */
  {  21,   0, 256}, /*  2:                  COMMA shift  256 */
/* State 256 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  {  71,   1,  21}, /*  2:                JOIN_KW shift  21 */
  { 158,   0, 257}, /*  3:                idxitem shift  257 */
  { 173,   3, 258}, /*  4:                     nm shift  258 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 260 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 261}, /* 15:                   expr shift  261 */
/* State 261 */
  {  81,   4, 114}, /*  1:                     NE shift  114 */
  {  82,   0, 128}, /*  2:                    NOT shift  128 */
  {  83,   0, 150}, /*  3:                NOTNULL shift  150 */
  {  54,   0, 108}, /*  4:                     GT shift  108 */
  {  60,   0, 155}, /*  5:                     IN shift  155 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  { 168,   5, 126}, /*  7:                 likeop shift  126 */
  {  88,   0, 104}, /*  8:                     OR shift  104 */
  {  68,   0, 146}, /*  9:                     IS shift  146 */
  {  90,   0, 133}, /* 10:                   PLUS shift  133 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  42,   0, 116}, /* 13:                     EQ shift  116 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  95,   9, 141}, /* 15:                    REM shift  141 */
  {  69,  13, 145}, /* 16:                 ISNULL shift  145 */
  {  74,   0, 131}, /* 17:                   LIKE shift  131 */
  {  78,  19, 106}, /* 18:                     LT shift  106 */
  {  51,  22, 112}, /* 19:                     GE shift  112 */
  {  73,   0, 110}, /* 20:                     LE shift  110 */
  { 101,  17, 124}, /* 21:                 RSHIFT shift  124 */
  {  24,   0, 143}, /* 22:                 CONCAT shift  143 */
  {  80,   0, 135}, /* 23:                  MINUS shift  135 */
  {  77,   0, 122}, /* 24:                 LSHIFT shift  122 */
  { 105,  18, 139}, /* 25:                  SLASH shift  139 */
  {  52,   0, 132}, /* 26:                   GLOB shift  132 */
  { 107,  23, 137}, /* 27:                   STAR shift  137 */
/* State 262 */
  { 189,   2, 263}, /*  1:                 select shift  263 */
  { 177,   3,  66}, /*  2:              oneselect shift  66 */
  { 102,   0,  70}, /*  3:                 SELECT shift  70 */
/* State 263 */
  { 100,   0, 264}, /*  1:                     RP shift  264 */
  {  66,   0, 160}, /*  2:              INTERSECT shift  160 */
  { 172,   5,  68}, /*  3:         multiselect_op shift  68 */
  {  43,   0, 161}, /*  4:                 EXCEPT shift  161 */
  { 117,   0, 158}, /*  5:                  UNION shift  158 */
/* State 264 */
  {  56,   4, 244}, /*  1:                     ID shift  244 */
  { 126,   1, 265}, /*  2:                     as shift  265 */
  { 157,   0, 248}, /*  3:                    ids shift  248 */
  {   6,   0, 246}, /*  4:                     AS shift  246 */
  { 109,   0, 245}, /*  5:                 STRING shift  245 */
/* State 265 */
  {  87,   0, 260}, /*  1:                     ON shift  260 */
  { 175,   1, 266}, /*  2:                 on_opt shift  266 */
/* State 266 */
  { 120,   0, 252}, /*  1:                  USING shift  252 */
  { 207,   0, 267}, /*  2:              using_opt shift  267 */
/* State 268 */
  {  80,   4, 168}, /*  1:                  MINUS shift  168 */
  {  65,   0, 101}, /*  2:                INTEGER shift  101 */
  {  82,   0, 164}, /*  3:                    NOT shift  164 */
  {  16,   0, 172}, /*  4:                   CASE shift  172 */
  {  84,   0,  97}, /*  5:                   NULL shift  97 */
  { 149,   0, 269}, /*  6:                   expr shift  269 */
  {  12,   0, 166}, /*  7:                 BITNOT shift  166 */
  {  71,   0,  64}, /*  8:                JOIN_KW shift  64 */
  {  56,   0,  61}, /*  9:                     ID shift  61 */
  { 109,  16,  63}, /* 10:                 STRING shift  63 */
  {  90,   0, 170}, /* 11:                   PLUS shift  170 */
  { 107,   0, 271}, /* 12:                   STAR shift  271 */
  {  76,   7,  65}, /* 13:                     LP shift  65 */
  { 173,  10, 272}, /* 14:                     nm shift  272 */
  {  46,   0, 102}, /* 15:                  FLOAT shift  102 */
  {  93,   0, 182}, /* 16:                  RAISE shift  182 */
/* State 269 */
  {  69,   2, 145}, /*  1:                 ISNULL shift  145 */
  {   5,   0,  96}, /*  2:                    AND shift  96 */
  {  73,   0, 110}, /*  3:                     LE shift  110 */
  {  42,   8, 116}, /*  4:                     EQ shift  116 */
  {  68,   0, 146}, /*  5:                     IS shift  146 */
  { 101,   1, 124}, /*  6:                 RSHIFT shift  124 */
  {   6,   0, 246}, /*  7:                     AS shift  246 */
  {  10,   0, 151}, /*  8:                BETWEEN shift  151 */
  { 168,   0, 126}, /*  9:                 likeop shift  126 */
  { 105,   3, 139}, /* 10:                  SLASH shift  139 */
  {  74,   4, 131}, /* 11:                   LIKE shift  131 */
  { 107,  13, 137}, /* 12:                   STAR shift  137 */
  {  11,   0, 118}, /* 13:                 BITAND shift  118 */
  { 109,  16, 245}, /* 14:                 STRING shift  245 */
  {  78,   0, 106}, /* 15:                     LT shift  106 */
  {  77,  22, 122}, /* 16:                 LSHIFT shift  122 */
  {  80,   0, 135}, /* 17:                  MINUS shift  135 */
  {  81,   0, 114}, /* 18:                     NE shift  114 */
  {  82,   0, 128}, /* 19:                    NOT shift  128 */
  {  83,  24, 150}, /* 20:                NOTNULL shift  150 */
  {  52,   0, 132}, /* 21:                   GLOB shift  132 */
  {  13,   0, 120}, /* 22:                  BITOR shift  120 */
  {  54,   0, 108}, /* 23:                     GT shift  108 */
  {  51,   0, 112}, /* 24:                     GE shift  112 */
  {  88,  26, 104}, /* 25:                     OR shift  104 */
  {  56,  28, 244}, /* 26:                     ID shift  244 */
  {  90,   0, 133}, /* 27:                   PLUS shift  133 */
  {  24,   0, 143}, /* 28:                 CONCAT shift  143 */
  {  60,   0, 155}, /* 29:                     IN shift  155 */
  { 157,   0, 248}, /* 30:                    ids shift  248 */
  { 126,   0, 270}, /* 31:                     as shift  270 */
  {  95,   0, 141}, /* 32:                    REM shift  141 */
/* State 272 */
  {  36,   0, 273}, /*  1:                    DOT shift  273 */
/* State 273 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  {  71,   1,  21}, /*  2:                JOIN_KW shift  21 */
  { 107,   0, 274}, /*  3:                   STAR shift  274 */
  { 173,   0, 100}, /*  4:                     nm shift  100 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 278 */
  { 168,   0, 126}, /*  1:                 likeop shift  126 */
  {  60,   0, 155}, /*  2:                     IN shift  155 */
  {  11,   0, 118}, /*  3:                 BITAND shift  118 */
  {  13,   0, 120}, /*  4:                  BITOR shift  120 */
  {  88,   2, 104}, /*  5:                     OR shift  104 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  {  90,   0, 133}, /*  7:                   PLUS shift  133 */
  {  73,   0, 110}, /*  8:                     LE shift  110 */
  {  77,   0, 122}, /*  9:                 LSHIFT shift  122 */
  {  51,   0, 112}, /* 10:                     GE shift  112 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  95,   3, 141}, /* 12:                    REM shift  141 */
  {  68,   0, 146}, /* 13:                     IS shift  146 */
  {  69,   4, 145}, /* 14:                 ISNULL shift  145 */
  {  42,   0, 116}, /* 15:                     EQ shift  116 */
  {  52,  20, 132}, /* 16:                   GLOB shift  132 */
  { 100,   0, 279}, /* 17:                     RP shift  279 */
  { 101,   8, 124}, /* 18:                 RSHIFT shift  124 */
  {  74,   0, 131}, /* 19:                   LIKE shift  131 */
  {  24,   0, 143}, /* 20:                 CONCAT shift  143 */
  {  54,   0, 108}, /* 21:                     GT shift  108 */
  { 105,   9, 139}, /* 22:                  SLASH shift  139 */
  {  78,   0, 106}, /* 23:                     LT shift  106 */
  { 107,  10, 137}, /* 24:                   STAR shift  137 */
  {  80,  16, 135}, /* 25:                  MINUS shift  135 */
  {  81,   0, 114}, /* 26:                     NE shift  114 */
  {  82,  21, 128}, /* 27:                    NOT shift  128 */
  {  83,   0, 150}, /* 28:                NOTNULL shift  150 */
/* State 280 */
  { 100,   0, 281}, /*  1:                     RP shift  281 */
  {  21,   0, 206}, /*  2:                  COMMA shift  206 */
/* State 282 */
  { 100,   0, 283}, /*  1:                     RP shift  283 */
/* State 284 */
  { 168,   0, 126}, /*  1:                 likeop shift  126 */
  {  60,   0, 155}, /*  2:                     IN shift  155 */
  {  11,   0, 118}, /*  3:                 BITAND shift  118 */
  {  13,   0, 120}, /*  4:                  BITOR shift  120 */
  {  88,   2, 104}, /*  5:                     OR shift  104 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  {  90,   0, 133}, /*  7:                   PLUS shift  133 */
  {  73,   0, 110}, /*  8:                     LE shift  110 */
  {  77,   0, 122}, /*  9:                 LSHIFT shift  122 */
  {  51,   0, 112}, /* 10:                     GE shift  112 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  95,   3, 141}, /* 12:                    REM shift  141 */
  {  68,   0, 146}, /* 13:                     IS shift  146 */
  {  69,   4, 145}, /* 14:                 ISNULL shift  145 */
  {  42,   0, 116}, /* 15:                     EQ shift  116 */
  {  52,  20, 132}, /* 16:                   GLOB shift  132 */
  { 100,   0, 285}, /* 17:                     RP shift  285 */
  { 101,   8, 124}, /* 18:                 RSHIFT shift  124 */
  {  74,   0, 131}, /* 19:                   LIKE shift  131 */
  {  24,   0, 143}, /* 20:                 CONCAT shift  143 */
  {  54,   0, 108}, /* 21:                     GT shift  108 */
  { 105,   9, 139}, /* 22:                  SLASH shift  139 */
  {  78,   0, 106}, /* 23:                     LT shift  106 */
  { 107,  10, 137}, /* 24:                   STAR shift  137 */
  {  80,  16, 135}, /* 25:                  MINUS shift  135 */
  {  81,   0, 114}, /* 26:                     NE shift  114 */
  {  82,  21, 128}, /* 27:                    NOT shift  128 */
  {  83,   0, 150}, /* 28:                NOTNULL shift  150 */
/* State 285 */
  { 176,   0, 286}, /*  1:                 onconf shift  286 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 289 */
  { 156,   2, 290}, /*  1:                     id shift  290 */
  {  56,   0,  93}, /*  2:                     ID shift  93 */
/* State 291 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 292}, /*  2:                     nm shift  292 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 292 */
  { 184,   2, 310}, /*  1:                refargs shift  310 */
  {  76,   0, 293}, /*  2:                     LP shift  293 */
/* State 293 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  { 158,   1, 259}, /*  3:                idxitem shift  259 */
  { 159,   0, 294}, /*  4:                idxlist shift  294 */
  {  71,   0,  21}, /*  5:                JOIN_KW shift  21 */
  { 173,   5, 258}, /*  6:                     nm shift  258 */
/* State 294 */
  { 100,   0, 295}, /*  1:                     RP shift  295 */
  {  21,   0, 256}, /*  2:                  COMMA shift  256 */
/* State 295 */
  { 184,   0, 296}, /*  1:                refargs shift  296 */
/* State 296 */
  { 183,   3, 297}, /*  1:                 refarg shift  297 */
  {  79,   0, 298}, /*  2:                  MATCH shift  298 */
  {  87,   0, 300}, /*  3:                     ON shift  300 */
/* State 298 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 299}, /*  2:                     nm shift  299 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 300 */
  {  32,   0, 301}, /*  1:                 DELETE shift  301 */
  { 119,   0, 308}, /*  2:                 UPDATE shift  308 */
/* State 301 */
  { 104,   0, 303}, /*  1:                    SET shift  303 */
  {  97,   0, 307}, /*  2:               RESTRICT shift  307 */
  { 182,   0, 302}, /*  3:                 refact shift  302 */
  {  15,   0, 306}, /*  4:                CASCADE shift  306 */
/* State 303 */
  {  84,   0, 304}, /*  1:                   NULL shift  304 */
  {  29,   0, 305}, /*  2:                DEFAULT shift  305 */
/* State 308 */
  { 104,   0, 303}, /*  1:                    SET shift  303 */
  {  97,   0, 307}, /*  2:               RESTRICT shift  307 */
  { 182,   0, 309}, /*  3:                 refact shift  309 */
  {  15,   0, 306}, /*  4:                CASCADE shift  306 */
/* State 310 */
  { 183,   3, 297}, /*  1:                 refarg shift  297 */
  {  79,   0, 298}, /*  2:                  MATCH shift  298 */
  {  87,   0, 300}, /*  3:                     ON shift  300 */
/* State 311 */
  { 160,   2, 312}, /*  1: init_deferred_pred_opt shift  312 */
  {  62,   0,  48}, /*  2:              INITIALLY shift  48 */
/* State 314 */
  {  84,   2, 325}, /*  1:                   NULL shift  325 */
  {  56,   0, 316}, /*  2:                     ID shift  316 */
  {  65,   0, 317}, /*  3:                INTEGER shift  317 */
  {  80,   0, 321}, /*  4:                  MINUS shift  321 */
  { 109,   6, 315}, /*  5:                 STRING shift  315 */
  {  46,   0, 324}, /*  6:                  FLOAT shift  324 */
  {  90,   0, 318}, /*  7:                   PLUS shift  318 */
/* State 318 */
  {  46,   0, 320}, /*  1:                  FLOAT shift  320 */
  {  65,   0, 319}, /*  2:                INTEGER shift  319 */
/* State 321 */
  {  46,   0, 323}, /*  1:                  FLOAT shift  323 */
  {  65,   0, 322}, /*  2:                INTEGER shift  322 */
/* State 326 */
  {  76,   3, 327}, /*  1:                     LP shift  327 */
  { 157,   4, 338}, /*  2:                    ids shift  338 */
  {  56,   0, 244}, /*  3:                     ID shift  244 */
  { 109,   0, 245}, /*  4:                 STRING shift  245 */
/* State 327 */
  { 192,   4, 328}, /*  1:                 signed shift  328 */
  {  65,   0, 333}, /*  2:                INTEGER shift  333 */
  {  90,   0, 334}, /*  3:                   PLUS shift  334 */
  {  80,   0, 336}, /*  4:                  MINUS shift  336 */
/* State 328 */
  { 100,   0, 329}, /*  1:                     RP shift  329 */
  {  21,   0, 330}, /*  2:                  COMMA shift  330 */
/* State 330 */
  { 192,   4, 331}, /*  1:                 signed shift  331 */
  {  65,   0, 333}, /*  2:                INTEGER shift  333 */
  {  90,   0, 334}, /*  3:                   PLUS shift  334 */
  {  80,   0, 336}, /*  4:                  MINUS shift  336 */
/* State 331 */
  { 100,   0, 332}, /*  1:                     RP shift  332 */
/* State 334 */
  {  65,   0, 335}, /*  1:                INTEGER shift  335 */
/* State 336 */
  {  65,   0, 337}, /*  1:                INTEGER shift  337 */
/* State 341 */
  {  48,   0, 360}, /*  1:                FOREIGN shift  360 */
  {  17,   0, 357}, /*  2:                  CHECK shift  357 */
  {  26,   0, 344}, /*  3:             CONSTRAINT shift  344 */
  {  92,   0, 346}, /*  4:                PRIMARY shift  346 */
  { 100,   4, 599}, /*  5:                     RP reduce 76 */
  { 197,   8, 369}, /*  6:                  tcons shift  369 */
  { 118,   0, 352}, /*  7:                 UNIQUE shift  352 */
  {  21,   0, 342}, /*  8:                  COMMA shift  342 */
/* State 342 */
  {  48,   0, 360}, /*  1:                FOREIGN shift  360 */
  {  26,   0, 344}, /*  2:             CONSTRAINT shift  344 */
  {  92,   2, 346}, /*  3:                PRIMARY shift  346 */
  {  17,   0, 357}, /*  4:                  CHECK shift  357 */
  { 118,   0, 352}, /*  5:                 UNIQUE shift  352 */
  { 197,   4, 343}, /*  6:                  tcons shift  343 */
/* State 344 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 345}, /*  2:                     nm shift  345 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 346 */
  {  72,   0, 347}, /*  1:                    KEY shift  347 */
/* State 347 */
  {  76,   0, 348}, /*  1:                     LP shift  348 */
/* State 348 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  { 158,   1, 259}, /*  3:                idxitem shift  259 */
  { 159,   0, 349}, /*  4:                idxlist shift  349 */
  {  71,   0,  21}, /*  5:                JOIN_KW shift  21 */
  { 173,   5, 258}, /*  6:                     nm shift  258 */
/* State 349 */
  { 100,   0, 350}, /*  1:                     RP shift  350 */
  {  21,   0, 256}, /*  2:                  COMMA shift  256 */
/* State 350 */
  { 176,   0, 351}, /*  1:                 onconf shift  351 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 352 */
  {  76,   0, 353}, /*  1:                     LP shift  353 */
/* State 353 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  { 158,   1, 259}, /*  3:                idxitem shift  259 */
  { 159,   0, 354}, /*  4:                idxlist shift  354 */
  {  71,   0,  21}, /*  5:                JOIN_KW shift  21 */
  { 173,   5, 258}, /*  6:                     nm shift  258 */
/* State 354 */
  { 100,   0, 355}, /*  1:                     RP shift  355 */
  {  21,   0, 256}, /*  2:                  COMMA shift  256 */
/* State 355 */
  { 176,   0, 356}, /*  1:                 onconf shift  356 */
  {  87,   0,   9}, /*  2:                     ON shift  9 */
/* State 357 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 358}, /* 15:                   expr shift  358 */
/* State 358 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  {  88,   0, 104}, /*  2:                     OR shift  104 */
  { 176,   5, 359}, /*  3:                 onconf shift  359 */
  {  90,   0, 133}, /*  4:                   PLUS shift  133 */
  {  60,   0, 155}, /*  5:                     IN shift  155 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  {  10,   0, 151}, /*  7:                BETWEEN shift  151 */
  {  11,   0, 118}, /*  8:                 BITAND shift  118 */
  {  95,   0, 141}, /*  9:                    REM shift  141 */
  {  13,   0, 120}, /* 10:                  BITOR shift  120 */
  {  68,   7, 146}, /* 11:                     IS shift  146 */
  {  69,   8, 145}, /* 12:                 ISNULL shift  145 */
  {  78,   0, 106}, /* 13:                     LT shift  106 */
  {  42,  10, 116}, /* 14:                     EQ shift  116 */
  { 101,   0, 124}, /* 15:                 RSHIFT shift  124 */
  {  73,   0, 110}, /* 16:                     LE shift  110 */
  {  74,   0, 131}, /* 17:                   LIKE shift  131 */
  {  51,   0, 112}, /* 18:                     GE shift  112 */
  { 105,   0, 139}, /* 19:                  SLASH shift  139 */
  {  77,   0, 122}, /* 20:                 LSHIFT shift  122 */
  { 107,  13, 137}, /* 21:                   STAR shift  137 */
  {  81,  27, 114}, /* 22:                     NE shift  114 */
  {  80,  18, 135}, /* 23:                  MINUS shift  135 */
  { 168,  22, 126}, /* 24:                 likeop shift  126 */
  {  82,  28, 128}, /* 25:                    NOT shift  128 */
  {  83,  29, 150}, /* 26:                NOTNULL shift  150 */
  {  52,   0, 132}, /* 27:                   GLOB shift  132 */
  {  24,   0, 143}, /* 28:                 CONCAT shift  143 */
  {  54,   0, 108}, /* 29:                     GT shift  108 */
/* State 360 */
  {  72,   0, 361}, /*  1:                    KEY shift  361 */
/* State 361 */
  {  76,   0, 362}, /*  1:                     LP shift  362 */
/* State 362 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  { 158,   1, 259}, /*  3:                idxitem shift  259 */
  { 159,   0, 363}, /*  4:                idxlist shift  363 */
  {  71,   0,  21}, /*  5:                JOIN_KW shift  21 */
  { 173,   5, 258}, /*  6:                     nm shift  258 */
/* State 363 */
  { 100,   0, 364}, /*  1:                     RP shift  364 */
  {  21,   0, 256}, /*  2:                  COMMA shift  256 */
/* State 364 */
  {  94,   0, 291}, /*  1:             REFERENCES shift  291 */
  { 185,   0, 365}, /*  2:             references shift  365 */
/* State 365 */
  { 144,   0, 367}, /*  1:    defer_subclause_opt shift  367 */
  {  30,   0, 311}, /*  2:             DEFERRABLE shift  311 */
  {  82,   2, 366}, /*  3:                    NOT shift  366 */
  { 143,   0, 368}, /*  4:        defer_subclause shift  368 */
/* State 366 */
  {  30,   0,  46}, /*  1:             DEFERRABLE shift  46 */
/* State 372 */
  { 189,   2, 373}, /*  1:                 select shift  373 */
  { 177,   3,  66}, /*  2:              oneselect shift  66 */
  { 102,   0,  70}, /*  3:                 SELECT shift  70 */
/* State 373 */
  { 117,   0, 158}, /*  1:                  UNION shift  158 */
  {  66,   0, 160}, /*  2:              INTERSECT shift  160 */
  { 172,   1,  68}, /*  3:         multiselect_op shift  68 */
  { 103,   5, 542}, /*  4:                   SEMI reduce 19 */
  {  43,   0, 161}, /*  5:                 EXCEPT shift  161 */
/* State 374 */
  { 198,   2, 375}, /*  1:                   temp shift  375 */
  { 118,   5, 392}, /*  2:                 UNIQUE shift  392 */
  { 114,   0, 393}, /*  3:                TRIGGER shift  393 */
  { 123,   0, 379}, /*  4:                   VIEW shift  379 */
  { 110,   0, 540}, /*  5:                  TABLE reduce 17 */
  {  61,   0, 752}, /*  6:                  INDEX reduce 229 */
  { 206,   1, 383}, /*  7:             uniqueflag shift  383 */
  { 111,   0, 378}, /*  8:                   TEMP shift  378 */
/* State 375 */
  { 110,   0, 376}, /*  1:                  TABLE shift  376 */
/* State 376 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 377}, /*  2:                     nm shift  377 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 378 */
  { 110,   0, 539}, /*  1:                  TABLE reduce 16 */
/* State 379 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 380}, /*  2:                     nm shift  380 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 380 */
  {   6,   0, 381}, /*  1:                     AS shift  381 */
/* State 381 */
  { 189,   2, 382}, /*  1:                 select shift  382 */
  { 177,   3,  66}, /*  2:              oneselect shift  66 */
  { 102,   0,  70}, /*  3:                 SELECT shift  70 */
/* State 382 */
  { 117,   0, 158}, /*  1:                  UNION shift  158 */
  {  66,   0, 160}, /*  2:              INTERSECT shift  160 */
  { 172,   1,  68}, /*  3:         multiselect_op shift  68 */
  { 103,   5, 620}, /*  4:                   SEMI reduce 97 */
  {  43,   0, 161}, /*  5:                 EXCEPT shift  161 */
/* State 383 */
  {  61,   0, 384}, /*  1:                  INDEX shift  384 */
/* State 384 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 385}, /*  2:                     nm shift  385 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 385 */
  {  87,   0, 386}, /*  1:                     ON shift  386 */
/* State 386 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 387}, /*  2:                     nm shift  387 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 387 */
  {  76,   0, 388}, /*  1:                     LP shift  388 */
/* State 388 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 109,   0,  20}, /*  2:                 STRING shift  20 */
  { 158,   1, 259}, /*  3:                idxitem shift  259 */
  { 159,   0, 389}, /*  4:                idxlist shift  389 */
  {  71,   0,  21}, /*  5:                JOIN_KW shift  21 */
  { 173,   5, 258}, /*  6:                     nm shift  258 */
/* State 389 */
  { 100,   0, 390}, /*  1:                     RP shift  390 */
  {  21,   0, 256}, /*  2:                  COMMA shift  256 */
/* State 390 */
  {  87,   0,   9}, /*  1:                     ON shift  9 */
  { 103,   0, 610}, /*  2:                   SEMI reduce 87 */
  { 176,   0, 391}, /*  3:                 onconf shift  391 */
/* State 391 */
  { 103,   0, 750}, /*  1:                   SEMI reduce 227 */
/* State 392 */
  {  61,   0, 751}, /*  1:                  INDEX reduce 228 */
/* State 393 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 394}, /*  2:                     nm shift  394 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 394 */
  {  64,   2, 459}, /*  1:                INSTEAD shift  459 */
  {   8,   0, 457}, /*  2:                 BEFORE shift  457 */
  {   2,   0, 458}, /*  3:                  AFTER shift  458 */
  { 203,   0, 395}, /*  4:           trigger_time shift  395 */
/* State 395 */
  {  32,   0, 452}, /*  1:                 DELETE shift  452 */
  {  63,   0, 453}, /*  2:                 INSERT shift  453 */
  { 202,   0, 396}, /*  3:          trigger_event shift  396 */
  { 119,   2, 454}, /*  4:                 UPDATE shift  454 */
/* State 396 */
  {  87,   0, 397}, /*  1:                     ON shift  397 */
/* State 397 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 398}, /*  2:                     nm shift  398 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 398 */
  { 152,   0, 399}, /*  1:         foreach_clause shift  399 */
  {  47,   0, 448}, /*  2:                    FOR shift  448 */
/* State 399 */
  {   9,   0, 785}, /*  1:                  BEGIN reduce 262 */
  { 208,   3, 400}, /*  2:            when_clause shift  400 */
  { 124,   0, 446}, /*  3:                   WHEN shift  446 */
/* State 400 */
  {   9,   0, 401}, /*  1:                  BEGIN shift  401 */
/* State 401 */
  { 189,   2, 402}, /*  1:                 select shift  402 */
  {  63,   0, 423}, /*  2:                 INSERT shift  423 */
  { 200,   8, 405}, /*  3:            trigger_cmd shift  405 */
  { 201,   9, 403}, /*  4:       trigger_cmd_list shift  403 */
  {  40,   0, 788}, /*  5:                    END reduce 265 */
  {  32,   0, 442}, /*  6:                 DELETE shift  442 */
  { 177,   0,  66}, /*  7:              oneselect shift  66 */
  { 119,   0, 408}, /*  8:                 UPDATE shift  408 */
  { 102,   0,  70}, /*  9:                 SELECT shift  70 */
/* State 402 */
  { 117,   0, 158}, /*  1:                  UNION shift  158 */
  {  66,   0, 160}, /*  2:              INTERSECT shift  160 */
  { 172,   1,  68}, /*  3:         multiselect_op shift  68 */
  { 103,   5, 793}, /*  4:                   SEMI reduce 270 */
  {  43,   0, 161}, /*  5:                 EXCEPT shift  161 */
/* State 403 */
  {  40,   0, 404}, /*  1:                    END shift  404 */
/* State 404 */
  { 103,   0, 773}, /*  1:                   SEMI reduce 250 */
/* State 405 */
  { 103,   0, 406}, /*  1:                   SEMI shift  406 */
/* State 406 */
  { 189,   2, 402}, /*  1:                 select shift  402 */
  {  63,   0, 423}, /*  2:                 INSERT shift  423 */
  { 200,   8, 405}, /*  3:            trigger_cmd shift  405 */
  { 201,   9, 407}, /*  4:       trigger_cmd_list shift  407 */
  {  40,   0, 788}, /*  5:                    END reduce 265 */
  {  32,   0, 442}, /*  6:                 DELETE shift  442 */
  { 177,   0,  66}, /*  7:              oneselect shift  66 */
  { 119,   0, 408}, /*  8:                 UPDATE shift  408 */
  { 102,   0,  70}, /*  9:                 SELECT shift  70 */
/* State 407 */
  {  40,   0, 787}, /*  1:                    END reduce 264 */
/* State 408 */
  { 178,   2, 411}, /*  1:                 orconf shift  411 */
  {  88,   0, 409}, /*  2:                     OR shift  409 */
/* State 409 */
  { 186,   5, 410}, /*  1:            resolvetype shift  410 */
  {   1,   0,  13}, /*  2:                  ABORT shift  13 */
  {  98,   0,  12}, /*  3:               ROLLBACK shift  12 */
  {  57,   6,  15}, /*  4:                 IGNORE shift  15 */
  {  96,   0,  16}, /*  5:                REPLACE shift  16 */
  {  45,   0,  14}, /*  6:                   FAIL shift  14 */
/* State 411 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 412}, /*  2:                     nm shift  412 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 412 */
  { 104,   0, 413}, /*  1:                    SET shift  413 */
/* State 413 */
  {  71,   3,  21}, /*  1:                JOIN_KW shift  21 */
  { 191,   1, 414}, /*  2:                setlist shift  414 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 173,   0, 420}, /*  4:                     nm shift  420 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 414 */
  { 125,   3, 228}, /*  1:                  WHERE shift  228 */
  { 209,   1, 419}, /*  2:              where_opt shift  419 */
  {  21,   0, 415}, /*  3:                  COMMA shift  415 */
  { 103,   0, 676}, /*  4:                   SEMI reduce 153 */
/* State 415 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 416}, /*  2:                     nm shift  416 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 416 */
  {  42,   0, 417}, /*  1:                     EQ shift  417 */
/* State 417 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 418}, /* 15:                   expr shift  418 */
/* State 418 */
  {  81,   4, 114}, /*  1:                     NE shift  114 */
  {  82,   0, 128}, /*  2:                    NOT shift  128 */
  {  83,   0, 150}, /*  3:                NOTNULL shift  150 */
  {  54,   0, 108}, /*  4:                     GT shift  108 */
  {  60,   0, 155}, /*  5:                     IN shift  155 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  { 168,   5, 126}, /*  7:                 likeop shift  126 */
  {  88,   0, 104}, /*  8:                     OR shift  104 */
  {  68,   0, 146}, /*  9:                     IS shift  146 */
  {  90,   0, 133}, /* 10:                   PLUS shift  133 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  42,   0, 116}, /* 13:                     EQ shift  116 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  95,   9, 141}, /* 15:                    REM shift  141 */
  {  69,  13, 145}, /* 16:                 ISNULL shift  145 */
  {  74,   0, 131}, /* 17:                   LIKE shift  131 */
  {  78,  19, 106}, /* 18:                     LT shift  106 */
  {  51,  22, 112}, /* 19:                     GE shift  112 */
  {  73,   0, 110}, /* 20:                     LE shift  110 */
  { 101,  17, 124}, /* 21:                 RSHIFT shift  124 */
  {  24,   0, 143}, /* 22:                 CONCAT shift  143 */
  {  80,   0, 135}, /* 23:                  MINUS shift  135 */
  {  77,   0, 122}, /* 24:                 LSHIFT shift  122 */
  { 105,  18, 139}, /* 25:                  SLASH shift  139 */
  {  52,   0, 132}, /* 26:                   GLOB shift  132 */
  { 107,  23, 137}, /* 27:                   STAR shift  137 */
/* State 419 */
  { 103,   0, 789}, /*  1:                   SEMI reduce 266 */
/* State 420 */
  {  42,   0, 421}, /*  1:                     EQ shift  421 */
/* State 421 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 422}, /* 15:                   expr shift  422 */
/* State 422 */
  {  81,   4, 114}, /*  1:                     NE shift  114 */
  {  82,   0, 128}, /*  2:                    NOT shift  128 */
  {  83,   0, 150}, /*  3:                NOTNULL shift  150 */
  {  54,   0, 108}, /*  4:                     GT shift  108 */
  {  60,   0, 155}, /*  5:                     IN shift  155 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  { 168,   5, 126}, /*  7:                 likeop shift  126 */
  {  88,   0, 104}, /*  8:                     OR shift  104 */
  {  68,   0, 146}, /*  9:                     IS shift  146 */
  {  90,   0, 133}, /* 10:                   PLUS shift  133 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  42,   0, 116}, /* 13:                     EQ shift  116 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  95,   9, 141}, /* 15:                    REM shift  141 */
  {  69,  13, 145}, /* 16:                 ISNULL shift  145 */
  {  74,   0, 131}, /* 17:                   LIKE shift  131 */
  {  78,  19, 106}, /* 18:                     LT shift  106 */
  {  51,  22, 112}, /* 19:                     GE shift  112 */
  {  73,   0, 110}, /* 20:                     LE shift  110 */
  { 101,  17, 124}, /* 21:                 RSHIFT shift  124 */
  {  24,   0, 143}, /* 22:                 CONCAT shift  143 */
  {  80,   0, 135}, /* 23:                  MINUS shift  135 */
  {  77,   0, 122}, /* 24:                 LSHIFT shift  122 */
  { 105,  18, 139}, /* 25:                  SLASH shift  139 */
  {  52,   0, 132}, /* 26:                   GLOB shift  132 */
  { 107,  23, 137}, /* 27:                   STAR shift  137 */
/* State 423 */
  {  88,   3, 409}, /*  1:                     OR shift  409 */
  { 178,   1, 424}, /*  2:                 orconf shift  424 */
  {  67,   0, 612}, /*  3:                   INTO reduce 89 */
/* State 424 */
  {  67,   0, 425}, /*  1:                   INTO shift  425 */
/* State 425 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 426}, /*  2:                     nm shift  426 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 426 */
  {  76,   0, 427}, /*  1:                     LP shift  427 */
  { 163,   0, 433}, /*  2:         inscollist_opt shift  433 */
/* State 427 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  {  71,   1,  21}, /*  2:                JOIN_KW shift  21 */
  { 162,   0, 428}, /*  3:             inscollist shift  428 */
  { 173,   0, 432}, /*  4:                     nm shift  432 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 428 */
  { 100,   0, 429}, /*  1:                     RP shift  429 */
  {  21,   0, 430}, /*  2:                  COMMA shift  430 */
/* State 430 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 431}, /*  2:                     nm shift  431 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 433 */
  { 177,   0,  66}, /*  1:              oneselect shift  66 */
  { 189,   1, 434}, /*  2:                 select shift  434 */
  { 122,   4, 435}, /*  3:                 VALUES shift  435 */
  { 102,   0,  70}, /*  4:                 SELECT shift  70 */
/* State 434 */
  { 117,   0, 158}, /*  1:                  UNION shift  158 */
  {  66,   0, 160}, /*  2:              INTERSECT shift  160 */
  { 172,   1,  68}, /*  3:         multiselect_op shift  68 */
  { 103,   5, 791}, /*  4:                   SEMI reduce 268 */
  {  43,   0, 161}, /*  5:                 EXCEPT shift  161 */
/* State 435 */
  {  76,   0, 436}, /*  1:                     LP shift  436 */
/* State 436 */
  {  80,   4, 168}, /*  1:                  MINUS shift  168 */
  {  65,   0, 101}, /*  2:                INTEGER shift  101 */
  {  82,   0, 164}, /*  3:                    NOT shift  164 */
  {  16,   0, 172}, /*  4:                   CASE shift  172 */
  {  84,   0,  97}, /*  5:                   NULL shift  97 */
  { 165,   7, 437}, /*  6:               itemlist shift  437 */
  { 149,   0, 441}, /*  7:                   expr shift  441 */
  {  71,   0,  64}, /*  8:                JOIN_KW shift  64 */
  {  56,   0,  61}, /*  9:                     ID shift  61 */
  {  12,   0, 166}, /* 10:                 BITNOT shift  166 */
  {  90,   0, 170}, /* 11:                   PLUS shift  170 */
  { 109,  16,  63}, /* 12:                 STRING shift  63 */
  {  76,  10,  65}, /* 13:                     LP shift  65 */
  { 173,  12,  98}, /* 14:                     nm shift  98 */
  {  46,   0, 102}, /* 15:                  FLOAT shift  102 */
  {  93,   0, 182}, /* 16:                  RAISE shift  182 */
/* State 437 */
  { 100,   0, 440}, /*  1:                     RP shift  440 */
  {  21,   0, 438}, /*  2:                  COMMA shift  438 */
/* State 438 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 439}, /* 15:                   expr shift  439 */
/* State 439 */
  {  81,   4, 114}, /*  1:                     NE shift  114 */
  {  82,   0, 128}, /*  2:                    NOT shift  128 */
  {  83,   0, 150}, /*  3:                NOTNULL shift  150 */
  {  54,   0, 108}, /*  4:                     GT shift  108 */
  {  60,   0, 155}, /*  5:                     IN shift  155 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  { 168,   5, 126}, /*  7:                 likeop shift  126 */
  {  88,   0, 104}, /*  8:                     OR shift  104 */
  {  68,   0, 146}, /*  9:                     IS shift  146 */
  {  90,   0, 133}, /* 10:                   PLUS shift  133 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  42,   0, 116}, /* 13:                     EQ shift  116 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  95,   9, 141}, /* 15:                    REM shift  141 */
  {  69,  13, 145}, /* 16:                 ISNULL shift  145 */
  {  74,   0, 131}, /* 17:                   LIKE shift  131 */
  {  78,  19, 106}, /* 18:                     LT shift  106 */
  {  51,  22, 112}, /* 19:                     GE shift  112 */
  {  73,   0, 110}, /* 20:                     LE shift  110 */
  { 101,  17, 124}, /* 21:                 RSHIFT shift  124 */
  {  24,   0, 143}, /* 22:                 CONCAT shift  143 */
  {  80,   0, 135}, /* 23:                  MINUS shift  135 */
  {  77,   0, 122}, /* 24:                 LSHIFT shift  122 */
  { 105,  18, 139}, /* 25:                  SLASH shift  139 */
  {  52,   0, 132}, /* 26:                   GLOB shift  132 */
  { 107,  23, 137}, /* 27:                   STAR shift  137 */
/* State 440 */
  { 103,   0, 790}, /*  1:                   SEMI reduce 267 */
/* State 441 */
  {  81,   4, 114}, /*  1:                     NE shift  114 */
  {  82,   0, 128}, /*  2:                    NOT shift  128 */
  {  83,   0, 150}, /*  3:                NOTNULL shift  150 */
  {  54,   0, 108}, /*  4:                     GT shift  108 */
  {  60,   0, 155}, /*  5:                     IN shift  155 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  { 168,   5, 126}, /*  7:                 likeop shift  126 */
  {  88,   0, 104}, /*  8:                     OR shift  104 */
  {  68,   0, 146}, /*  9:                     IS shift  146 */
  {  90,   0, 133}, /* 10:                   PLUS shift  133 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  11,   0, 118}, /* 12:                 BITAND shift  118 */
  {  42,   0, 116}, /* 13:                     EQ shift  116 */
  {  13,   0, 120}, /* 14:                  BITOR shift  120 */
  {  95,   9, 141}, /* 15:                    REM shift  141 */
  {  69,  13, 145}, /* 16:                 ISNULL shift  145 */
  {  74,   0, 131}, /* 17:                   LIKE shift  131 */
  {  78,  19, 106}, /* 18:                     LT shift  106 */
  {  51,  22, 112}, /* 19:                     GE shift  112 */
  {  73,   0, 110}, /* 20:                     LE shift  110 */
  { 101,  17, 124}, /* 21:                 RSHIFT shift  124 */
  {  24,   0, 143}, /* 22:                 CONCAT shift  143 */
  {  80,   0, 135}, /* 23:                  MINUS shift  135 */
  {  77,   0, 122}, /* 24:                 LSHIFT shift  122 */
  { 105,  18, 139}, /* 25:                  SLASH shift  139 */
  {  52,   0, 132}, /* 26:                   GLOB shift  132 */
  { 107,  23, 137}, /* 27:                   STAR shift  137 */
/* State 442 */
  {  49,   0, 443}, /*  1:                   FROM shift  443 */
/* State 443 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 444}, /*  2:                     nm shift  444 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 444 */
  { 125,   0, 228}, /*  1:                  WHERE shift  228 */
  { 103,   0, 676}, /*  2:                   SEMI reduce 153 */
  { 209,   1, 445}, /*  3:              where_opt shift  445 */
/* State 445 */
  { 103,   0, 792}, /*  1:                   SEMI reduce 269 */
/* State 446 */
  {  90,   0, 170}, /*  1:                   PLUS shift  170 */
  {  76,   3,  65}, /*  2:                     LP shift  65 */
  {  46,   7, 102}, /*  3:                  FLOAT shift  102 */
  {  93,   0, 182}, /*  4:                  RAISE shift  182 */
  { 109,   0,  63}, /*  5:                 STRING shift  63 */
  {  80,  11, 168}, /*  6:                  MINUS shift  168 */
  {  16,   0, 172}, /*  7:                   CASE shift  172 */
  {  82,   0, 164}, /*  8:                    NOT shift  164 */
  { 173,   0,  98}, /*  9:                     nm shift  98 */
  {  84,   0,  97}, /* 10:                   NULL shift  97 */
  {  65,   0, 101}, /* 11:                INTEGER shift  101 */
  {  71,  14,  64}, /* 12:                JOIN_KW shift  64 */
  {  12,   0, 166}, /* 13:                 BITNOT shift  166 */
  {  56,   0,  61}, /* 14:                     ID shift  61 */
  { 149,   0, 447}, /* 15:                   expr shift  447 */
/* State 447 */
  { 168,   0, 126}, /*  1:                 likeop shift  126 */
  {  60,   0, 155}, /*  2:                     IN shift  155 */
  {  11,   0, 118}, /*  3:                 BITAND shift  118 */
  {  13,   0, 120}, /*  4:                  BITOR shift  120 */
  {  88,   2, 104}, /*  5:                     OR shift  104 */
  {   5,   0,  96}, /*  6:                    AND shift  96 */
  {  90,   0, 133}, /*  7:                   PLUS shift  133 */
  {  73,   0, 110}, /*  8:                     LE shift  110 */
  {  77,   0, 122}, /*  9:                 LSHIFT shift  122 */
  {   9,   0, 786}, /* 10:                  BEGIN reduce 263 */
  {  10,   0, 151}, /* 11:                BETWEEN shift  151 */
  {  95,   3, 141}, /* 12:                    REM shift  141 */
  {  68,   0, 146}, /* 13:                     IS shift  146 */
  {  69,   4, 145}, /* 14:                 ISNULL shift  145 */
  {  42,   0, 116}, /* 15:                     EQ shift  116 */
  {  51,   0, 112}, /* 16:                     GE shift  112 */
  {  52,  20, 132}, /* 17:                   GLOB shift  132 */
  { 101,   8, 124}, /* 18:                 RSHIFT shift  124 */
  {  74,   0, 131}, /* 19:                   LIKE shift  131 */
  {  24,   0, 143}, /* 20:                 CONCAT shift  143 */
  {  54,   0, 108}, /* 21:                     GT shift  108 */
  { 105,   9, 139}, /* 22:                  SLASH shift  139 */
  {  78,   0, 106}, /* 23:                     LT shift  106 */
  { 107,  16, 137}, /* 24:                   STAR shift  137 */
  {  80,  17, 135}, /* 25:                  MINUS shift  135 */
  {  81,   0, 114}, /* 26:                     NE shift  114 */
  {  82,  21, 128}, /* 27:                    NOT shift  128 */
  {  83,   0, 150}, /* 28:                NOTNULL shift  150 */
/* State 448 */
  {  38,   0, 449}, /*  1:                   EACH shift  449 */
/* State 449 */
  { 108,   0, 451}, /*  1:              STATEMENT shift  451 */
  {  99,   0, 450}, /*  2:                    ROW shift  450 */
/* State 452 */
  {  87,   0, 778}, /*  1:                     ON reduce 255 */
/* State 453 */
  {  87,   0, 779}, /*  1:                     ON reduce 256 */
/* State 454 */
  {  85,   0, 455}, /*  1:                     OF shift  455 */
  {  87,   1, 780}, /*  2:                     ON reduce 257 */
/* State 455 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  {  71,   1,  21}, /*  2:                JOIN_KW shift  21 */
  { 162,   0, 456}, /*  3:             inscollist shift  456 */
  { 173,   0, 432}, /*  4:                     nm shift  432 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 456 */
  {  21,   0, 430}, /*  1:                  COMMA shift  430 */
  {  87,   1, 781}, /*  2:                     ON reduce 258 */
/* State 459 */
  {  85,   0, 460}, /*  1:                     OF shift  460 */
/* State 461 */
  { 110,   0, 462}, /*  1:                  TABLE shift  462 */
  {  61,   0, 466}, /*  2:                  INDEX shift  466 */
  { 114,   1, 468}, /*  3:                TRIGGER shift  468 */
  { 123,   0, 464}, /*  4:                   VIEW shift  464 */
/* State 462 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 463}, /*  2:                     nm shift  463 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 463 */
  { 103,   0, 619}, /*  1:                   SEMI reduce 96 */
/* State 464 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 465}, /*  2:                     nm shift  465 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 465 */
  { 103,   0, 621}, /*  1:                   SEMI reduce 98 */
/* State 466 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 467}, /*  2:                     nm shift  467 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 467 */
  { 103,   0, 756}, /*  1:                   SEMI reduce 233 */
/* State 468 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 469}, /*  2:                     nm shift  469 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 469 */
  { 103,   0, 798}, /*  1:                   SEMI reduce 275 */
/* State 470 */
  { 117,   0, 158}, /*  1:                  UNION shift  158 */
  {  66,   0, 160}, /*  2:              INTERSECT shift  160 */
  { 172,   1,  68}, /*  3:         multiselect_op shift  68 */
  { 103,   5, 622}, /*  4:                   SEMI reduce 99 */
  {  43,   0, 161}, /*  5:                 EXCEPT shift  161 */
/* State 471 */
  {  49,   0, 472}, /*  1:                   FROM shift  472 */
/* State 472 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 473}, /*  2:                     nm shift  473 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 473 */
  { 125,   0, 228}, /*  1:                  WHERE shift  228 */
  { 103,   0, 676}, /*  2:                   SEMI reduce 153 */
  { 209,   1, 474}, /*  3:              where_opt shift  474 */
/* State 474 */
  { 103,   0, 675}, /*  1:                   SEMI reduce 152 */
/* State 475 */
  { 178,   2, 476}, /*  1:                 orconf shift  476 */
  {  88,   0, 409}, /*  2:                     OR shift  409 */
/* State 476 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 477}, /*  2:                     nm shift  477 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 477 */
  { 104,   0, 478}, /*  1:                    SET shift  478 */
/* State 478 */
  {  71,   3,  21}, /*  1:                JOIN_KW shift  21 */
  { 191,   1, 479}, /*  2:                setlist shift  479 */
  {  56,   0,  19}, /*  3:                     ID shift  19 */
  { 173,   0, 420}, /*  4:                     nm shift  420 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 479 */
  { 125,   3, 228}, /*  1:                  WHERE shift  228 */
  { 209,   1, 480}, /*  2:              where_opt shift  480 */
  {  21,   0, 415}, /*  3:                  COMMA shift  415 */
  { 103,   0, 676}, /*  4:                   SEMI reduce 153 */
/* State 480 */
  { 103,   0, 678}, /*  1:                   SEMI reduce 155 */
/* State 481 */
  {  67,   0, 482}, /*  1:                   INTO shift  482 */
/* State 482 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 483}, /*  2:                     nm shift  483 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 483 */
  {  76,   0, 427}, /*  1:                     LP shift  427 */
  { 163,   0, 484}, /*  2:         inscollist_opt shift  484 */
/* State 484 */
  { 177,   0,  66}, /*  1:              oneselect shift  66 */
  { 189,   1, 485}, /*  2:                 select shift  485 */
  { 122,   4, 486}, /*  3:                 VALUES shift  486 */
  { 102,   0,  70}, /*  4:                 SELECT shift  70 */
/* State 485 */
  { 117,   0, 158}, /*  1:                  UNION shift  158 */
  {  66,   0, 160}, /*  2:              INTERSECT shift  160 */
  { 172,   1,  68}, /*  3:         multiselect_op shift  68 */
  { 103,   5, 682}, /*  4:                   SEMI reduce 159 */
  {  43,   0, 161}, /*  5:                 EXCEPT shift  161 */
/* State 486 */
  {  76,   0, 487}, /*  1:                     LP shift  487 */
/* State 487 */
  {  80,   4, 168}, /*  1:                  MINUS shift  168 */
  {  65,   0, 101}, /*  2:                INTEGER shift  101 */
  {  82,   0, 164}, /*  3:                    NOT shift  164 */
  {  16,   0, 172}, /*  4:                   CASE shift  172 */
  {  84,   0,  97}, /*  5:                   NULL shift  97 */
  { 165,   7, 488}, /*  6:               itemlist shift  488 */
  { 149,   0, 441}, /*  7:                   expr shift  441 */
  {  71,   0,  64}, /*  8:                JOIN_KW shift  64 */
  {  56,   0,  61}, /*  9:                     ID shift  61 */
  {  12,   0, 166}, /* 10:                 BITNOT shift  166 */
  {  90,   0, 170}, /* 11:                   PLUS shift  170 */
  { 109,  16,  63}, /* 12:                 STRING shift  63 */
  {  76,  10,  65}, /* 13:                     LP shift  65 */
  { 173,  12,  98}, /* 14:                     nm shift  98 */
  {  46,   0, 102}, /* 15:                  FLOAT shift  102 */
  {  93,   0, 182}, /* 16:                  RAISE shift  182 */
/* State 488 */
  { 100,   0, 489}, /*  1:                     RP shift  489 */
  {  21,   0, 438}, /*  2:                  COMMA shift  438 */
/* State 489 */
  { 103,   0, 681}, /*  1:                   SEMI reduce 158 */
/* State 490 */
  {  88,   3, 409}, /*  1:                     OR shift  409 */
  { 178,   1, 491}, /*  2:                 orconf shift  491 */
  {  67,   0, 612}, /*  3:                   INTO reduce 89 */
/* State 491 */
  {  67,   0, 683}, /*  1:                   INTO reduce 160 */
/* State 492 */
  {  67,   0, 684}, /*  1:                   INTO reduce 161 */
/* State 493 */
  { 178,   2, 494}, /*  1:                 orconf shift  494 */
  {  88,   0, 409}, /*  2:                     OR shift  409 */
/* State 494 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 495}, /*  2:                     nm shift  495 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 495 */
  {  49,   0, 496}, /*  1:                   FROM shift  496 */
/* State 496 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 497}, /*  2:                     nm shift  497 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 497 */
  { 120,   0, 498}, /*  1:                  USING shift  498 */
  { 103,   0, 758}, /*  2:                   SEMI reduce 235 */
/* State 498 */
  {  33,   0, 499}, /*  1:             DELIMITERS shift  499 */
/* State 499 */
  { 109,   0, 500}, /*  1:                 STRING shift  500 */
/* State 500 */
  { 103,   0, 757}, /*  1:                   SEMI reduce 234 */
/* State 501 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  {  71,   1,  21}, /*  2:                JOIN_KW shift  21 */
  { 103,   0, 759}, /*  3:                   SEMI reduce 236 */
  { 173,   3, 502}, /*  4:                     nm shift  502 */
  { 109,   0,  20}, /*  5:                 STRING shift  20 */
/* State 502 */
  { 103,   0, 760}, /*  1:                   SEMI reduce 237 */
/* State 503 */
  { 109,   0, 245}, /*  1:                 STRING shift  245 */
  { 157,   1, 504}, /*  2:                    ids shift  504 */
  {  56,   0, 244}, /*  3:                     ID shift  244 */
/* State 504 */
  {  42,   0, 505}, /*  1:                     EQ shift  505 */
  { 103,   3, 766}, /*  2:                   SEMI reduce 243 */
  {  76,   0, 517}, /*  3:                     LP shift  517 */
/* State 505 */
  { 180,   3, 508}, /*  1:               plus_num shift  508 */
  { 181,   5, 510}, /*  2:               plus_opt shift  510 */
  {  90,   6, 516}, /*  3:                   PLUS shift  516 */
  { 173,   0, 506}, /*  4:                     nm shift  506 */
  { 171,   9, 509}, /*  5:              minus_num shift  509 */
  {  80,   0, 514}, /*  6:                  MINUS shift  514 */
  {  56,   0,  19}, /*  7:                     ID shift  19 */
  {  87,   0, 507}, /*  8:                     ON shift  507 */
  {  71,   0,  21}, /*  9:                JOIN_KW shift  21 */
  { 109,   0,  20}, /* 10:                 STRING shift  20 */
/* State 506 */
  { 103,   0, 761}, /*  1:                   SEMI reduce 238 */
/* State 507 */
  { 103,   0, 762}, /*  1:                   SEMI reduce 239 */
/* State 508 */
  { 103,   0, 763}, /*  1:                   SEMI reduce 240 */
/* State 509 */
  { 103,   0, 764}, /*  1:                   SEMI reduce 241 */
/* State 510 */
  { 174,   0, 511}, /*  1:                 number shift  511 */
  {  46,   0, 513}, /*  2:                  FLOAT shift  513 */
  {  65,   0, 512}, /*  3:                INTEGER shift  512 */
/* State 511 */
  { 103,   0, 767}, /*  1:                   SEMI reduce 244 */
/* State 512 */
  { 103,   0, 769}, /*  1:                   SEMI reduce 246 */
/* State 513 */
  { 103,   0, 770}, /*  1:                   SEMI reduce 247 */
/* State 514 */
  { 174,   0, 515}, /*  1:                 number shift  515 */
  {  46,   0, 513}, /*  2:                  FLOAT shift  513 */
  {  65,   0, 512}, /*  3:                INTEGER shift  512 */
/* State 515 */
  { 103,   0, 768}, /*  1:                   SEMI reduce 245 */
/* State 517 */
  {  56,   0,  19}, /*  1:                     ID shift  19 */
  { 173,   3, 518}, /*  2:                     nm shift  518 */
  { 109,   0,  20}, /*  3:                 STRING shift  20 */
  {  71,   0,  21}, /*  4:                JOIN_KW shift  21 */
/* State 518 */
  { 100,   0, 519}, /*  1:                     RP shift  519 */
/* State 519 */
  { 103,   0, 765}, /*  1:                   SEMI reduce 242 */
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
  { &yyActionTable[0],   6, 529 },
  { &yyActionTable[6],   5, 529 },
  { &yyActionTable[11],   0, 525 },
  { &yyActionTable[11],  19, 799 },
  { &yyActionTable[30],   1, 799 },
  { &yyActionTable[31],   0, 526 },
  { &yyActionTable[31],   2, 531 },
  { &yyActionTable[33],   3, 799 },
  { &yyActionTable[36],   1, 799 },
  { &yyActionTable[37],   1, 799 },
  { &yyActionTable[38],   6, 799 },
  { &yyActionTable[44],   0, 611 },
  { &yyActionTable[44],   0, 614 },
  { &yyActionTable[44],   0, 615 },
  { &yyActionTable[44],   0, 616 },
  { &yyActionTable[44],   0, 617 },
  { &yyActionTable[44],   0, 618 },
  { &yyActionTable[44],   4, 532 },
  { &yyActionTable[48],   0, 533 },
  { &yyActionTable[48],   0, 550 },
  { &yyActionTable[48],   0, 551 },
  { &yyActionTable[48],   0, 552 },
  { &yyActionTable[48],   3, 799 },
  { &yyActionTable[51],   1, 799 },
  { &yyActionTable[52],   3, 799 },
  { &yyActionTable[55],   1, 799 },
  { &yyActionTable[56],   3, 799 },
  { &yyActionTable[59],   1, 799 },
  { &yyActionTable[60],   3, 799 },
  { &yyActionTable[63],   1, 799 },
  { &yyActionTable[64],   7, 799 },
  { &yyActionTable[71],   3, 799 },
  { &yyActionTable[74],   1, 799 },
  { &yyActionTable[75],   1, 799 },
  { &yyActionTable[76],  13, 799 },
  { &yyActionTable[89],   0, 543 },
  { &yyActionTable[89],   5, 553 },
  { &yyActionTable[94],   1, 563 },
  { &yyActionTable[95],  13, 545 },
  { &yyActionTable[108],   0, 562 },
  { &yyActionTable[108],   4, 799 },
  { &yyActionTable[112],  10, 799 },
  { &yyActionTable[122],   0, 564 },
  { &yyActionTable[122],   2, 799 },
  { &yyActionTable[124],   2, 610 },
  { &yyActionTable[126],   0, 575 },
  { &yyActionTable[126],   2, 595 },
  { &yyActionTable[128],   0, 593 },
  { &yyActionTable[128],   2, 799 },
  { &yyActionTable[130],   0, 596 },
  { &yyActionTable[130],   0, 597 },
  { &yyActionTable[130],   1, 799 },
  { &yyActionTable[131],   3, 663 },
  { &yyActionTable[134],   2, 610 },
  { &yyActionTable[136],   0, 576 },
  { &yyActionTable[136],   0, 661 },
  { &yyActionTable[136],   0, 662 },
  { &yyActionTable[136],   2, 610 },
  { &yyActionTable[138],   0, 577 },
  { &yyActionTable[138],   1, 799 },
  { &yyActionTable[139],  15, 799 },
  { &yyActionTable[154],   2, 693 },
  { &yyActionTable[156],  18, 749 },
  { &yyActionTable[174],   1, 698 },
  { &yyActionTable[175],   1, 694 },
  { &yyActionTable[176],  18, 799 },
  { &yyActionTable[194],   0, 623 },
  { &yyActionTable[194],   5, 799 },
  { &yyActionTable[199],   2, 799 },
  { &yyActionTable[201],   0, 624 },
  { &yyActionTable[201],   3, 632 },
  { &yyActionTable[204],   2, 634 },
  { &yyActionTable[206],   3, 641 },
  { &yyActionTable[209],   2, 676 },
  { &yyActionTable[211],   2, 666 },
  { &yyActionTable[213],   2, 668 },
  { &yyActionTable[215],   2, 656 },
  { &yyActionTable[217],   2, 670 },
  { &yyActionTable[219],   0, 629 },
  { &yyActionTable[219],   1, 799 },
  { &yyActionTable[220],   3, 671 },
  { &yyActionTable[223],   1, 799 },
  { &yyActionTable[224],   0, 672 },
  { &yyActionTable[224],   1, 799 },
  { &yyActionTable[225],   1, 799 },
  { &yyActionTable[226],   1, 799 },
  { &yyActionTable[227],  17, 799 },
  { &yyActionTable[244],   1, 657 },
  { &yyActionTable[245],  16, 799 },
  { &yyActionTable[261],   2, 664 },
  { &yyActionTable[263],   3, 663 },
  { &yyActionTable[266],   0, 658 },
  { &yyActionTable[266],   2, 799 },
  { &yyActionTable[268],   0, 547 },
  { &yyActionTable[268],   0, 665 },
  { &yyActionTable[268],  27, 660 },
  { &yyActionTable[295],  15, 799 },
  { &yyActionTable[310],   0, 692 },
  { &yyActionTable[310],   1, 799 },
  { &yyActionTable[311],   4, 799 },
  { &yyActionTable[315],   0, 695 },
  { &yyActionTable[315],   0, 696 },
  { &yyActionTable[315],   0, 697 },
  { &yyActionTable[315],  25, 701 },
  { &yyActionTable[340],  15, 799 },
  { &yyActionTable[355],  26, 702 },
  { &yyActionTable[381],  15, 799 },
  { &yyActionTable[396],  11, 703 },
  { &yyActionTable[407],  15, 799 },
  { &yyActionTable[422],  11, 704 },
  { &yyActionTable[433],  15, 799 },
  { &yyActionTable[448],  11, 705 },
  { &yyActionTable[459],  15, 799 },
  { &yyActionTable[474],  11, 706 },
  { &yyActionTable[485],  15, 799 },
  { &yyActionTable[500],  15, 707 },
  { &yyActionTable[515],  15, 799 },
  { &yyActionTable[530],  15, 708 },
  { &yyActionTable[545],  15, 799 },
  { &yyActionTable[560],   7, 709 },
  { &yyActionTable[567],  15, 799 },
  { &yyActionTable[582],   7, 710 },
  { &yyActionTable[589],  15, 799 },
  { &yyActionTable[604],   7, 711 },
  { &yyActionTable[611],  15, 799 },
  { &yyActionTable[626],   7, 712 },
  { &yyActionTable[633],  15, 799 },
  { &yyActionTable[648],  15, 713 },
  { &yyActionTable[663],   6, 799 },
  { &yyActionTable[669],  15, 799 },
  { &yyActionTable[684],  15, 714 },
  { &yyActionTable[699],   0, 715 },
  { &yyActionTable[699],   0, 716 },
  { &yyActionTable[699],  15, 799 },
  { &yyActionTable[714],   5, 717 },
  { &yyActionTable[719],  15, 799 },
  { &yyActionTable[734],   5, 718 },
  { &yyActionTable[739],  15, 799 },
  { &yyActionTable[754],   2, 719 },
  { &yyActionTable[756],  15, 799 },
  { &yyActionTable[771],   2, 720 },
  { &yyActionTable[773],  15, 799 },
  { &yyActionTable[788],   2, 721 },
  { &yyActionTable[790],  15, 799 },
  { &yyActionTable[805],   1, 722 },
  { &yyActionTable[806],   0, 723 },
  { &yyActionTable[806],   2, 799 },
  { &yyActionTable[808],   0, 724 },
  { &yyActionTable[808],   1, 799 },
  { &yyActionTable[809],   0, 727 },
  { &yyActionTable[809],   0, 725 },
  { &yyActionTable[809],  15, 799 },
  { &yyActionTable[824],  27, 799 },
  { &yyActionTable[851],  15, 799 },
  { &yyActionTable[866],  15, 733 },
  { &yyActionTable[881],   1, 799 },
  { &yyActionTable[882],  20, 749 },
  { &yyActionTable[902],   5, 799 },
  { &yyActionTable[907],   2, 799 },
  { &yyActionTable[909],   1, 799 },
  { &yyActionTable[910],   1, 799 },
  { &yyActionTable[911],   1, 799 },
  { &yyActionTable[912],   0, 736 },
  { &yyActionTable[912],  27, 748 },
  { &yyActionTable[939],  15, 799 },
  { &yyActionTable[954],  25, 728 },
  { &yyActionTable[979],  15, 799 },
  { &yyActionTable[994],   1, 729 },
  { &yyActionTable[995],  15, 799 },
  { &yyActionTable[1010],   1, 730 },
  { &yyActionTable[1011],  15, 799 },
  { &yyActionTable[1026],   1, 731 },
  { &yyActionTable[1027],  17, 799 },
  { &yyActionTable[1044],  28, 799 },
  { &yyActionTable[1072],   2, 799 },
  { &yyActionTable[1074],   4, 799 },
  { &yyActionTable[1078],   1, 799 },
  { &yyActionTable[1079],   0, 739 },
  { &yyActionTable[1079],  15, 799 },
  { &yyActionTable[1094],  28, 799 },
  { &yyActionTable[1122],  15, 799 },
  { &yyActionTable[1137],  27, 740 },
  { &yyActionTable[1164],   1, 799 },
  { &yyActionTable[1165],   4, 799 },
  { &yyActionTable[1169],   1, 799 },
  { &yyActionTable[1170],   0, 794 },
  { &yyActionTable[1170],   1, 799 },
  { &yyActionTable[1171],   4, 799 },
  { &yyActionTable[1175],   1, 799 },
  { &yyActionTable[1176],   0, 795 },
  { &yyActionTable[1176],   1, 799 },
  { &yyActionTable[1177],   4, 799 },
  { &yyActionTable[1181],   1, 799 },
  { &yyActionTable[1182],   0, 796 },
  { &yyActionTable[1182],   1, 799 },
  { &yyActionTable[1183],   4, 799 },
  { &yyActionTable[1187],   1, 799 },
  { &yyActionTable[1188],   0, 797 },
  { &yyActionTable[1188],  15, 799 },
  { &yyActionTable[1203],  28, 799 },
  { &yyActionTable[1231],  15, 799 },
  { &yyActionTable[1246],  28, 799 },
  { &yyActionTable[1274],  15, 799 },
  { &yyActionTable[1289],  27, 741 },
  { &yyActionTable[1316],   2, 799 },
  { &yyActionTable[1318],   0, 735 },
  { &yyActionTable[1318],  16, 749 },
  { &yyActionTable[1334],   0, 746 },
  { &yyActionTable[1334],   0, 747 },
  { &yyActionTable[1334],   0, 726 },
  { &yyActionTable[1334],  15, 799 },
  { &yyActionTable[1349],  27, 799 },
  { &yyActionTable[1376],  15, 799 },
  { &yyActionTable[1391],  25, 734 },
  { &yyActionTable[1416],   1, 799 },
  { &yyActionTable[1417],  20, 749 },
  { &yyActionTable[1437],   5, 799 },
  { &yyActionTable[1442],   0, 738 },
  { &yyActionTable[1442],   2, 799 },
  { &yyActionTable[1444],   0, 737 },
  { &yyActionTable[1444],   2, 664 },
  { &yyActionTable[1446],   3, 663 },
  { &yyActionTable[1449],   0, 659 },
  { &yyActionTable[1449],  15, 799 },
  { &yyActionTable[1464],  27, 669 },
  { &yyActionTable[1491],   1, 799 },
  { &yyActionTable[1492],  17, 749 },
  { &yyActionTable[1509],   1, 667 },
  { &yyActionTable[1510],  15, 799 },
  { &yyActionTable[1525],  27, 677 },
  { &yyActionTable[1552],   0, 633 },
  { &yyActionTable[1552],   2, 644 },
  { &yyActionTable[1554],   4, 642 },
  { &yyActionTable[1558],   0, 643 },
  { &yyActionTable[1558],   0, 647 },
  { &yyActionTable[1558],   0, 648 },
  { &yyActionTable[1558],   5, 799 },
  { &yyActionTable[1563],   0, 649 },
  { &yyActionTable[1563],   5, 799 },
  { &yyActionTable[1568],   0, 650 },
  { &yyActionTable[1568],   1, 799 },
  { &yyActionTable[1569],   0, 651 },
  { &yyActionTable[1569],   5, 799 },
  { &yyActionTable[1574],   5, 640 },
  { &yyActionTable[1579],   0, 548 },
  { &yyActionTable[1579],   0, 549 },
  { &yyActionTable[1579],   4, 799 },
  { &yyActionTable[1583],   0, 638 },
  { &yyActionTable[1583],   0, 639 },
  { &yyActionTable[1583],   2, 653 },
  { &yyActionTable[1585],   2, 655 },
  { &yyActionTable[1587],   0, 645 },
  { &yyActionTable[1587],   1, 799 },
  { &yyActionTable[1588],   6, 799 },
  { &yyActionTable[1594],   2, 799 },
  { &yyActionTable[1596],   0, 654 },
  { &yyActionTable[1596],   5, 799 },
  { &yyActionTable[1601],   0, 753 },
  { &yyActionTable[1601],   0, 755 },
  { &yyActionTable[1601],   0, 754 },
  { &yyActionTable[1601],  15, 799 },
  { &yyActionTable[1616],  27, 652 },
  { &yyActionTable[1643],   3, 799 },
  { &yyActionTable[1646],   5, 799 },
  { &yyActionTable[1651],   5, 640 },
  { &yyActionTable[1656],   2, 653 },
  { &yyActionTable[1658],   2, 655 },
  { &yyActionTable[1660],   0, 646 },
  { &yyActionTable[1660],  16, 799 },
  { &yyActionTable[1676],  32, 640 },
  { &yyActionTable[1708],   0, 635 },
  { &yyActionTable[1708],   0, 636 },
  { &yyActionTable[1708],   1, 799 },
  { &yyActionTable[1709],   5, 799 },
  { &yyActionTable[1714],   0, 637 },
  { &yyActionTable[1714],   0, 630 },
  { &yyActionTable[1714],   0, 631 },
  { &yyActionTable[1714],   0, 732 },
  { &yyActionTable[1714],  28, 799 },
  { &yyActionTable[1742],   0, 691 },
  { &yyActionTable[1742],   2, 799 },
  { &yyActionTable[1744],   0, 699 },
  { &yyActionTable[1744],   1, 799 },
  { &yyActionTable[1745],   0, 700 },
  { &yyActionTable[1745],  28, 799 },
  { &yyActionTable[1773],   2, 610 },
  { &yyActionTable[1775],   0, 578 },
  { &yyActionTable[1775],   0, 579 },
  { &yyActionTable[1775],   0, 580 },
  { &yyActionTable[1775],   2, 799 },
  { &yyActionTable[1777],   0, 581 },
  { &yyActionTable[1777],   4, 799 },
  { &yyActionTable[1781],   2, 584 },
  { &yyActionTable[1783],   6, 799 },
  { &yyActionTable[1789],   2, 799 },
  { &yyActionTable[1791],   1, 584 },
  { &yyActionTable[1792],   3, 582 },
  { &yyActionTable[1795],   0, 585 },
  { &yyActionTable[1795],   4, 799 },
  { &yyActionTable[1799],   0, 586 },
  { &yyActionTable[1799],   2, 799 },
  { &yyActionTable[1801],   4, 799 },
  { &yyActionTable[1805],   0, 587 },
  { &yyActionTable[1805],   2, 799 },
  { &yyActionTable[1807],   0, 589 },
  { &yyActionTable[1807],   0, 590 },
  { &yyActionTable[1807],   0, 591 },
  { &yyActionTable[1807],   0, 592 },
  { &yyActionTable[1807],   4, 799 },
  { &yyActionTable[1811],   0, 588 },
  { &yyActionTable[1811],   3, 583 },
  { &yyActionTable[1814],   2, 595 },
  { &yyActionTable[1816],   0, 594 },
  { &yyActionTable[1816],   0, 565 },
  { &yyActionTable[1816],   7, 799 },
  { &yyActionTable[1823],   0, 566 },
  { &yyActionTable[1823],   0, 567 },
  { &yyActionTable[1823],   0, 568 },
  { &yyActionTable[1823],   2, 799 },
  { &yyActionTable[1825],   0, 569 },
  { &yyActionTable[1825],   0, 572 },
  { &yyActionTable[1825],   2, 799 },
  { &yyActionTable[1827],   0, 570 },
  { &yyActionTable[1827],   0, 573 },
  { &yyActionTable[1827],   0, 571 },
  { &yyActionTable[1827],   0, 574 },
  { &yyActionTable[1827],   4, 554 },
  { &yyActionTable[1831],   4, 799 },
  { &yyActionTable[1835],   2, 799 },
  { &yyActionTable[1837],   0, 555 },
  { &yyActionTable[1837],   4, 799 },
  { &yyActionTable[1841],   1, 799 },
  { &yyActionTable[1842],   0, 556 },
  { &yyActionTable[1842],   0, 559 },
  { &yyActionTable[1842],   1, 799 },
  { &yyActionTable[1843],   0, 560 },
  { &yyActionTable[1843],   1, 799 },
  { &yyActionTable[1844],   0, 561 },
  { &yyActionTable[1844],   0, 558 },
  { &yyActionTable[1844],   0, 557 },
  { &yyActionTable[1844],   0, 546 },
  { &yyActionTable[1844],   8, 799 },
  { &yyActionTable[1852],   6, 799 },
  { &yyActionTable[1858],   0, 600 },
  { &yyActionTable[1858],   4, 799 },
  { &yyActionTable[1862],   0, 603 },
  { &yyActionTable[1862],   1, 799 },
  { &yyActionTable[1863],   1, 799 },
  { &yyActionTable[1864],   6, 799 },
  { &yyActionTable[1870],   2, 799 },
  { &yyActionTable[1872],   2, 610 },
  { &yyActionTable[1874],   0, 604 },
  { &yyActionTable[1874],   1, 799 },
  { &yyActionTable[1875],   6, 799 },
  { &yyActionTable[1881],   2, 799 },
  { &yyActionTable[1883],   2, 610 },
  { &yyActionTable[1885],   0, 605 },
  { &yyActionTable[1885],  15, 799 },
  { &yyActionTable[1900],  29, 610 },
  { &yyActionTable[1929],   0, 606 },
  { &yyActionTable[1929],   1, 799 },
  { &yyActionTable[1930],   1, 799 },
  { &yyActionTable[1931],   6, 799 },
  { &yyActionTable[1937],   2, 799 },
  { &yyActionTable[1939],   2, 799 },
  { &yyActionTable[1941],   4, 608 },
  { &yyActionTable[1945],   1, 799 },
  { &yyActionTable[1946],   0, 607 },
  { &yyActionTable[1946],   0, 609 },
  { &yyActionTable[1946],   0, 601 },
  { &yyActionTable[1946],   0, 602 },
  { &yyActionTable[1946],   0, 544 },
  { &yyActionTable[1946],   3, 799 },
  { &yyActionTable[1949],   5, 799 },
  { &yyActionTable[1954],   8, 799 },
  { &yyActionTable[1962],   1, 799 },
  { &yyActionTable[1963],   4, 799 },
  { &yyActionTable[1967],   0, 538 },
  { &yyActionTable[1967],   1, 799 },
  { &yyActionTable[1968],   4, 799 },
  { &yyActionTable[1972],   1, 799 },
  { &yyActionTable[1973],   3, 799 },
  { &yyActionTable[1976],   5, 799 },
  { &yyActionTable[1981],   1, 799 },
  { &yyActionTable[1982],   4, 799 },
  { &yyActionTable[1986],   1, 799 },
  { &yyActionTable[1987],   4, 799 },
  { &yyActionTable[1991],   1, 799 },
  { &yyActionTable[1992],   6, 799 },
  { &yyActionTable[1998],   2, 799 },
  { &yyActionTable[2000],   3, 799 },
  { &yyActionTable[2003],   1, 799 },
  { &yyActionTable[2004],   1, 799 },
  { &yyActionTable[2005],   4, 799 },
  { &yyActionTable[2009],   4, 777 },
  { &yyActionTable[2013],   4, 799 },
  { &yyActionTable[2017],   1, 799 },
  { &yyActionTable[2018],   4, 799 },
  { &yyActionTable[2022],   2, 782 },
  { &yyActionTable[2024],   3, 799 },
  { &yyActionTable[2027],   1, 799 },
  { &yyActionTable[2028],   9, 799 },
  { &yyActionTable[2037],   5, 799 },
  { &yyActionTable[2042],   1, 799 },
  { &yyActionTable[2043],   1, 799 },
  { &yyActionTable[2044],   1, 799 },
  { &yyActionTable[2045],   9, 799 },
  { &yyActionTable[2054],   1, 799 },
  { &yyActionTable[2055],   2, 612 },
  { &yyActionTable[2057],   6, 799 },
  { &yyActionTable[2063],   0, 613 },
  { &yyActionTable[2063],   4, 799 },
  { &yyActionTable[2067],   1, 799 },
  { &yyActionTable[2068],   5, 799 },
  { &yyActionTable[2073],   4, 799 },
  { &yyActionTable[2077],   4, 799 },
  { &yyActionTable[2081],   1, 799 },
  { &yyActionTable[2082],  15, 799 },
  { &yyActionTable[2097],  27, 679 },
  { &yyActionTable[2124],   1, 799 },
  { &yyActionTable[2125],   1, 799 },
  { &yyActionTable[2126],  15, 799 },
  { &yyActionTable[2141],  27, 680 },
  { &yyActionTable[2168],   3, 799 },
  { &yyActionTable[2171],   1, 799 },
  { &yyActionTable[2172],   4, 799 },
  { &yyActionTable[2176],   2, 687 },
  { &yyActionTable[2178],   5, 799 },
  { &yyActionTable[2183],   2, 799 },
  { &yyActionTable[2185],   0, 688 },
  { &yyActionTable[2185],   4, 799 },
  { &yyActionTable[2189],   0, 689 },
  { &yyActionTable[2189],   0, 690 },
  { &yyActionTable[2189],   4, 799 },
  { &yyActionTable[2193],   5, 799 },
  { &yyActionTable[2198],   1, 799 },
  { &yyActionTable[2199],  16, 799 },
  { &yyActionTable[2215],   2, 799 },
  { &yyActionTable[2217],  15, 799 },
  { &yyActionTable[2232],  27, 685 },
  { &yyActionTable[2259],   1, 799 },
  { &yyActionTable[2260],  27, 686 },
  { &yyActionTable[2287],   1, 799 },
  { &yyActionTable[2288],   4, 799 },
  { &yyActionTable[2292],   3, 799 },
  { &yyActionTable[2295],   1, 799 },
  { &yyActionTable[2296],  15, 799 },
  { &yyActionTable[2311],  28, 799 },
  { &yyActionTable[2339],   1, 799 },
  { &yyActionTable[2340],   2, 799 },
  { &yyActionTable[2342],   0, 783 },
  { &yyActionTable[2342],   0, 784 },
  { &yyActionTable[2342],   1, 799 },
  { &yyActionTable[2343],   1, 799 },
  { &yyActionTable[2344],   2, 799 },
  { &yyActionTable[2346],   5, 799 },
  { &yyActionTable[2351],   2, 799 },
  { &yyActionTable[2353],   0, 774 },
  { &yyActionTable[2353],   0, 775 },
  { &yyActionTable[2353],   1, 799 },
  { &yyActionTable[2354],   0, 776 },
  { &yyActionTable[2354],   4, 799 },
  { &yyActionTable[2358],   4, 799 },
  { &yyActionTable[2362],   1, 799 },
  { &yyActionTable[2363],   4, 799 },
  { &yyActionTable[2367],   1, 799 },
  { &yyActionTable[2368],   4, 799 },
  { &yyActionTable[2372],   1, 799 },
  { &yyActionTable[2373],   4, 799 },
  { &yyActionTable[2377],   1, 799 },
  { &yyActionTable[2378],   5, 799 },
  { &yyActionTable[2383],   1, 799 },
  { &yyActionTable[2384],   4, 799 },
  { &yyActionTable[2388],   3, 799 },
  { &yyActionTable[2391],   1, 799 },
  { &yyActionTable[2392],   2, 612 },
  { &yyActionTable[2394],   4, 799 },
  { &yyActionTable[2398],   1, 799 },
  { &yyActionTable[2399],   5, 799 },
  { &yyActionTable[2404],   4, 799 },
  { &yyActionTable[2408],   1, 799 },
  { &yyActionTable[2409],   1, 799 },
  { &yyActionTable[2410],   4, 799 },
  { &yyActionTable[2414],   2, 687 },
  { &yyActionTable[2416],   4, 799 },
  { &yyActionTable[2420],   5, 799 },
  { &yyActionTable[2425],   1, 799 },
  { &yyActionTable[2426],  16, 799 },
  { &yyActionTable[2442],   2, 799 },
  { &yyActionTable[2444],   1, 799 },
  { &yyActionTable[2445],   3, 799 },
  { &yyActionTable[2448],   1, 799 },
  { &yyActionTable[2449],   1, 799 },
  { &yyActionTable[2450],   2, 612 },
  { &yyActionTable[2452],   4, 799 },
  { &yyActionTable[2456],   1, 799 },
  { &yyActionTable[2457],   4, 799 },
  { &yyActionTable[2461],   2, 799 },
  { &yyActionTable[2463],   1, 799 },
  { &yyActionTable[2464],   1, 799 },
  { &yyActionTable[2465],   1, 799 },
  { &yyActionTable[2466],   5, 799 },
  { &yyActionTable[2471],   1, 799 },
  { &yyActionTable[2472],   3, 799 },
  { &yyActionTable[2475],   3, 799 },
  { &yyActionTable[2478],  10, 772 },
  { &yyActionTable[2488],   1, 799 },
  { &yyActionTable[2489],   1, 799 },
  { &yyActionTable[2490],   1, 799 },
  { &yyActionTable[2491],   1, 799 },
  { &yyActionTable[2492],   3, 799 },
  { &yyActionTable[2495],   1, 799 },
  { &yyActionTable[2496],   1, 799 },
  { &yyActionTable[2497],   1, 799 },
  { &yyActionTable[2498],   3, 799 },
  { &yyActionTable[2501],   1, 799 },
  { &yyActionTable[2502],   0, 771 },
  { &yyActionTable[2502],   4, 799 },
  { &yyActionTable[2506],   1, 799 },
  { &yyActionTable[2507],   1, 799 },
  { &yyActionTable[2508],   0, 527 },
  { &yyActionTable[2508],   0, 528 },
  { &yyActionTable[2508],   0, 524 },
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
 /*  52 */ "ccons ::= NOT NULL onconf",
 /*  53 */ "ccons ::= PRIMARY KEY sortorder onconf",
 /*  54 */ "ccons ::= UNIQUE onconf",
 /*  55 */ "ccons ::= CHECK LP expr RP onconf",
 /*  56 */ "ccons ::= references",
 /*  57 */ "ccons ::= defer_subclause",
 /*  58 */ "ccons ::= COLLATE id",
 /*  59 */ "references ::= REFERENCES nm LP idxlist RP refargs",
 /*  60 */ "references ::= REFERENCES nm refargs",
 /*  61 */ "refargs ::=",
 /*  62 */ "refargs ::= refargs refarg",
 /*  63 */ "refarg ::= MATCH nm",
 /*  64 */ "refarg ::= ON DELETE refact",
 /*  65 */ "refarg ::= ON UPDATE refact",
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
 /*  84 */ "tcons ::= FOREIGN KEY LP idxlist RP references defer_subclause_opt",
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
 /*  97 */ "cmd ::= CREATE VIEW nm AS select",
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
 /* 230 */ "idxlist ::= idxlist COMMA idxitem",
 /* 231 */ "idxlist ::= idxitem",
 /* 232 */ "idxitem ::= nm",
 /* 233 */ "cmd ::= DROP INDEX nm",
 /* 234 */ "cmd ::= COPY orconf nm FROM nm USING DELIMITERS STRING",
 /* 235 */ "cmd ::= COPY orconf nm FROM nm",
 /* 236 */ "cmd ::= VACUUM",
 /* 237 */ "cmd ::= VACUUM nm",
 /* 238 */ "cmd ::= PRAGMA ids EQ nm",
 /* 239 */ "cmd ::= PRAGMA ids EQ ON",
 /* 240 */ "cmd ::= PRAGMA ids EQ plus_num",
 /* 241 */ "cmd ::= PRAGMA ids EQ minus_num",
 /* 242 */ "cmd ::= PRAGMA ids LP nm RP",
 /* 243 */ "cmd ::= PRAGMA ids",
 /* 244 */ "plus_num ::= plus_opt number",
 /* 245 */ "minus_num ::= MINUS number",
 /* 246 */ "number ::= INTEGER",
 /* 247 */ "number ::= FLOAT",
 /* 248 */ "plus_opt ::= PLUS",
 /* 249 */ "plus_opt ::=",
 /* 250 */ "cmd ::= CREATE TRIGGER nm trigger_time trigger_event ON nm foreach_clause when_clause BEGIN trigger_cmd_list END",
 /* 251 */ "trigger_time ::= BEFORE",
 /* 252 */ "trigger_time ::= AFTER",
 /* 253 */ "trigger_time ::= INSTEAD OF",
 /* 254 */ "trigger_time ::=",
 /* 255 */ "trigger_event ::= DELETE",
 /* 256 */ "trigger_event ::= INSERT",
 /* 257 */ "trigger_event ::= UPDATE",
 /* 258 */ "trigger_event ::= UPDATE OF inscollist",
 /* 259 */ "foreach_clause ::=",
 /* 260 */ "foreach_clause ::= FOR EACH ROW",
 /* 261 */ "foreach_clause ::= FOR EACH STATEMENT",
 /* 262 */ "when_clause ::=",
 /* 263 */ "when_clause ::= WHEN expr",
 /* 264 */ "trigger_cmd_list ::= trigger_cmd SEMI trigger_cmd_list",
 /* 265 */ "trigger_cmd_list ::=",
 /* 266 */ "trigger_cmd ::= UPDATE orconf nm SET setlist where_opt",
 /* 267 */ "trigger_cmd ::= INSERT orconf INTO nm inscollist_opt VALUES LP itemlist RP",
 /* 268 */ "trigger_cmd ::= INSERT orconf INTO nm inscollist_opt select",
 /* 269 */ "trigger_cmd ::= DELETE FROM nm where_opt",
 /* 270 */ "trigger_cmd ::= select",
 /* 271 */ "expr ::= RAISE LP IGNORE RP",
 /* 272 */ "expr ::= RAISE LP ROLLBACK COMMA nm RP",
 /* 273 */ "expr ::= RAISE LP ABORT COMMA nm RP",
 /* 274 */ "expr ::= RAISE LP FAIL COMMA nm RP",
 /* 275 */ "cmd ::= DROP TRIGGER nm",
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
#line 636 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4187 "parse.c"
      break;
    case 149:
#line 495 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4192 "parse.c"
      break;
    case 150:
#line 655 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4197 "parse.c"
      break;
    case 151:
#line 653 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4202 "parse.c"
      break;
    case 153:
#line 319 "parse.y"
{sqliteSrcListDelete((yypminor->yy7));}
#line 4207 "parse.c"
      break;
    case 154:
#line 413 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4212 "parse.c"
      break;
    case 155:
#line 418 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4217 "parse.c"
      break;
    case 159:
#line 677 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4222 "parse.c"
      break;
    case 162:
#line 474 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4227 "parse.c"
      break;
    case 163:
#line 472 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4232 "parse.c"
      break;
    case 165:
#line 466 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4237 "parse.c"
      break;
    case 175:
#line 374 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4242 "parse.c"
      break;
    case 177:
#line 254 "parse.y"
{sqliteSelectDelete((yypminor->yy219));}
#line 4247 "parse.c"
      break;
    case 179:
#line 385 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4252 "parse.c"
      break;
    case 187:
#line 290 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4257 "parse.c"
      break;
    case 188:
#line 288 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4262 "parse.c"
      break;
    case 189:
#line 252 "parse.y"
{sqliteSelectDelete((yypminor->yy219));}
#line 4267 "parse.c"
      break;
    case 190:
#line 315 "parse.y"
{sqliteSrcListDelete((yypminor->yy7));}
#line 4272 "parse.c"
      break;
    case 191:
#line 442 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4277 "parse.c"
      break;
    case 193:
#line 389 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4282 "parse.c"
      break;
    case 194:
#line 387 "parse.y"
{sqliteExprListDelete((yypminor->yy228));}
#line 4287 "parse.c"
      break;
    case 196:
#line 317 "parse.y"
{sqliteSrcListDelete((yypminor->yy7));}
#line 4292 "parse.c"
      break;
    case 202:
#line 734 "parse.y"
{sqliteIdListDelete((yypminor->yy90).b);}
#line 4297 "parse.c"
      break;
    case 207:
#line 379 "parse.y"
{sqliteIdListDelete((yypminor->yy250));}
#line 4302 "parse.c"
      break;
    case 209:
#line 436 "parse.y"
{sqliteExprDelete((yypminor->yy62));}
#line 4307 "parse.c"
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
  { 133, 5 },
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
#line 4778 "parse.c"
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
#line 4789 "parse.c"
        /* No destructor defined for EXPLAIN */
        break;
      case 6:
#line 70 "parse.y"
{ sqliteBeginParse(pParse, 0); }
#line 4795 "parse.c"
        break;
      case 7:
#line 75 "parse.y"
{sqliteBeginTransaction(pParse,yymsp[0].minor.yy172);}
#line 4800 "parse.c"
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
#line 4816 "parse.c"
        /* No destructor defined for COMMIT */
        /* No destructor defined for trans_opt */
        break;
      case 12:
#line 80 "parse.y"
{sqliteCommitTransaction(pParse);}
#line 4823 "parse.c"
        /* No destructor defined for END */
        /* No destructor defined for trans_opt */
        break;
      case 13:
#line 81 "parse.y"
{sqliteRollbackTransaction(pParse);}
#line 4830 "parse.c"
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
#line 4843 "parse.c"
        /* No destructor defined for TABLE */
        break;
      case 16:
#line 90 "parse.y"
{yygotominor.yy172 = pParse->isTemp || !pParse->initFlag;}
#line 4849 "parse.c"
        /* No destructor defined for TEMP */
        break;
      case 17:
#line 91 "parse.y"
{yygotominor.yy172 = pParse->isTemp;}
#line 4855 "parse.c"
        break;
      case 18:
#line 92 "parse.y"
{
  sqliteEndTable(pParse,&yymsp[0].minor.yy0,0);
}
#line 4862 "parse.c"
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
#line 4873 "parse.c"
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
#line 4892 "parse.c"
        break;
      case 24:
#line 113 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4897 "parse.c"
        break;
      case 25:
#line 129 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4902 "parse.c"
        break;
      case 26:
#line 130 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4907 "parse.c"
        break;
      case 27:
#line 135 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4912 "parse.c"
        break;
      case 28:
#line 136 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4917 "parse.c"
        break;
      case 29:
#line 137 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 4922 "parse.c"
        break;
      case 30:
        break;
      case 31:
#line 140 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[0].minor.yy378,&yymsp[0].minor.yy378);}
#line 4929 "parse.c"
        break;
      case 32:
#line 141 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-3].minor.yy378,&yymsp[0].minor.yy0);}
#line 4934 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        break;
      case 33:
#line 143 "parse.y"
{sqliteAddColumnType(pParse,&yymsp[-5].minor.yy378,&yymsp[0].minor.yy0);}
#line 4941 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for signed */
        /* No destructor defined for COMMA */
        /* No destructor defined for signed */
        break;
      case 34:
#line 145 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 4950 "parse.c"
        break;
      case 35:
#line 146 "parse.y"
{yygotominor.yy378 = yymsp[-1].minor.yy378;}
#line 4955 "parse.c"
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
#line 4986 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 44:
#line 155 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 4992 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 45:
#line 156 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 4998 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 46:
#line 157 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5004 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 47:
#line 158 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 5011 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 48:
#line 159 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5018 "parse.c"
        /* No destructor defined for DEFAULT */
        break;
      case 49:
#line 160 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,0);}
#line 5024 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for PLUS */
        break;
      case 50:
#line 161 "parse.y"
{sqliteAddDefaultValue(pParse,&yymsp[0].minor.yy0,1);}
#line 5031 "parse.c"
        /* No destructor defined for DEFAULT */
        /* No destructor defined for MINUS */
        break;
      case 51:
        /* No destructor defined for DEFAULT */
        /* No destructor defined for NULL */
        break;
      case 52:
#line 167 "parse.y"
{sqliteAddNotNull(pParse, yymsp[0].minor.yy172);}
#line 5042 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for NULL */
        break;
      case 53:
#line 168 "parse.y"
{sqliteAddPrimaryKey(pParse,0,yymsp[0].minor.yy172);}
#line 5049 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for sortorder */
        break;
      case 54:
#line 169 "parse.y"
{sqliteCreateIndex(pParse,0,0,0,yymsp[0].minor.yy172,0,0);}
#line 5057 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 55:
        /* No destructor defined for CHECK */
        /* No destructor defined for LP */
  yy_destructor(149,&yymsp[-2].minor);
        /* No destructor defined for RP */
        /* No destructor defined for onconf */
        break;
      case 56:
        /* No destructor defined for references */
        break;
      case 57:
        /* No destructor defined for defer_subclause */
        break;
      case 58:
#line 173 "parse.y"
{
   sqliteAddCollateType(pParse, sqliteCollateType(pParse, &yymsp[0].minor.yy378));
}
#line 5078 "parse.c"
        /* No destructor defined for COLLATE */
        break;
      case 59:
        /* No destructor defined for REFERENCES */
        /* No destructor defined for nm */
        /* No destructor defined for LP */
  yy_destructor(159,&yymsp[-2].minor);
        /* No destructor defined for RP */
        /* No destructor defined for refargs */
        break;
      case 60:
        /* No destructor defined for REFERENCES */
        /* No destructor defined for nm */
        /* No destructor defined for refargs */
        break;
      case 61:
        break;
      case 62:
        /* No destructor defined for refargs */
        /* No destructor defined for refarg */
        break;
      case 63:
        /* No destructor defined for MATCH */
        /* No destructor defined for nm */
        break;
      case 64:
        /* No destructor defined for ON */
        /* No destructor defined for DELETE */
        /* No destructor defined for refact */
        break;
      case 65:
        /* No destructor defined for ON */
        /* No destructor defined for UPDATE */
        /* No destructor defined for refact */
        break;
      case 66:
        /* No destructor defined for SET */
        /* No destructor defined for NULL */
        break;
      case 67:
        /* No destructor defined for SET */
        /* No destructor defined for DEFAULT */
        break;
      case 68:
        /* No destructor defined for CASCADE */
        break;
      case 69:
        /* No destructor defined for RESTRICT */
        break;
      case 70:
        /* No destructor defined for NOT */
        /* No destructor defined for DEFERRABLE */
        /* No destructor defined for init_deferred_pred_opt */
        break;
      case 71:
        /* No destructor defined for DEFERRABLE */
        /* No destructor defined for init_deferred_pred_opt */
        break;
      case 72:
        break;
      case 73:
        /* No destructor defined for INITIALLY */
        /* No destructor defined for DEFERRED */
        break;
      case 74:
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
#line 207 "parse.y"
{sqliteAddPrimaryKey(pParse,yymsp[-2].minor.yy250,yymsp[0].minor.yy172);}
#line 5172 "parse.c"
        /* No destructor defined for PRIMARY */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 82:
#line 209 "parse.y"
{sqliteCreateIndex(pParse,0,0,yymsp[-2].minor.yy250,yymsp[0].minor.yy172,0,0);}
#line 5181 "parse.c"
        /* No destructor defined for UNIQUE */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 83:
        /* No destructor defined for CHECK */
  yy_destructor(149,&yymsp[-1].minor);
        /* No destructor defined for onconf */
        break;
      case 84:
        /* No destructor defined for FOREIGN */
        /* No destructor defined for KEY */
        /* No destructor defined for LP */
  yy_destructor(159,&yymsp[-3].minor);
        /* No destructor defined for RP */
        /* No destructor defined for references */
        /* No destructor defined for defer_subclause_opt */
        break;
      case 85:
        break;
      case 86:
        /* No destructor defined for defer_subclause */
        break;
      case 87:
#line 221 "parse.y"
{ yygotominor.yy172 = OE_Default; }
#line 5208 "parse.c"
        break;
      case 88:
#line 222 "parse.y"
{ yygotominor.yy172 = yymsp[0].minor.yy172; }
#line 5213 "parse.c"
        /* No destructor defined for ON */
        /* No destructor defined for CONFLICT */
        break;
      case 89:
#line 223 "parse.y"
{ yygotominor.yy172 = OE_Default; }
#line 5220 "parse.c"
        break;
      case 90:
#line 224 "parse.y"
{ yygotominor.yy172 = yymsp[0].minor.yy172; }
#line 5225 "parse.c"
        /* No destructor defined for OR */
        break;
      case 91:
#line 225 "parse.y"
{ yygotominor.yy172 = OE_Rollback; }
#line 5231 "parse.c"
        /* No destructor defined for ROLLBACK */
        break;
      case 92:
#line 226 "parse.y"
{ yygotominor.yy172 = OE_Abort; }
#line 5237 "parse.c"
        /* No destructor defined for ABORT */
        break;
      case 93:
#line 227 "parse.y"
{ yygotominor.yy172 = OE_Fail; }
#line 5243 "parse.c"
        /* No destructor defined for FAIL */
        break;
      case 94:
#line 228 "parse.y"
{ yygotominor.yy172 = OE_Ignore; }
#line 5249 "parse.c"
        /* No destructor defined for IGNORE */
        break;
      case 95:
#line 229 "parse.y"
{ yygotominor.yy172 = OE_Replace; }
#line 5255 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 96:
#line 233 "parse.y"
{sqliteDropTable(pParse,&yymsp[0].minor.yy378,0);}
#line 5261 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for TABLE */
        break;
      case 97:
#line 237 "parse.y"
{
  sqliteCreateView(pParse, &yymsp[-4].minor.yy0, &yymsp[-2].minor.yy378, yymsp[0].minor.yy219);
}
#line 5270 "parse.c"
        /* No destructor defined for VIEW */
        /* No destructor defined for AS */
        break;
      case 98:
#line 240 "parse.y"
{
  sqliteDropTable(pParse, &yymsp[0].minor.yy378, 1);
}
#line 5279 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for VIEW */
        break;
      case 99:
#line 246 "parse.y"
{
  sqliteSelect(pParse, yymsp[0].minor.yy219, SRT_Callback, 0, 0, 0, 0);
  sqliteSelectDelete(yymsp[0].minor.yy219);
}
#line 5289 "parse.c"
        break;
      case 100:
#line 256 "parse.y"
{yygotominor.yy219 = yymsp[0].minor.yy219;}
#line 5294 "parse.c"
        break;
      case 101:
#line 257 "parse.y"
{
  if( yymsp[0].minor.yy219 ){
    yymsp[0].minor.yy219->op = yymsp[-1].minor.yy172;
    yymsp[0].minor.yy219->pPrior = yymsp[-2].minor.yy219;
  }
  yygotominor.yy219 = yymsp[0].minor.yy219;
}
#line 5305 "parse.c"
        break;
      case 102:
#line 265 "parse.y"
{yygotominor.yy172 = TK_UNION;}
#line 5310 "parse.c"
        /* No destructor defined for UNION */
        break;
      case 103:
#line 266 "parse.y"
{yygotominor.yy172 = TK_ALL;}
#line 5316 "parse.c"
        /* No destructor defined for UNION */
        /* No destructor defined for ALL */
        break;
      case 104:
#line 267 "parse.y"
{yygotominor.yy172 = TK_INTERSECT;}
#line 5323 "parse.c"
        /* No destructor defined for INTERSECT */
        break;
      case 105:
#line 268 "parse.y"
{yygotominor.yy172 = TK_EXCEPT;}
#line 5329 "parse.c"
        /* No destructor defined for EXCEPT */
        break;
      case 106:
#line 270 "parse.y"
{
  yygotominor.yy219 = sqliteSelectNew(yymsp[-6].minor.yy228,yymsp[-5].minor.yy7,yymsp[-4].minor.yy62,yymsp[-3].minor.yy228,yymsp[-2].minor.yy62,yymsp[-1].minor.yy228,yymsp[-7].minor.yy172,yymsp[0].minor.yy6.limit,yymsp[0].minor.yy6.offset);
}
#line 5337 "parse.c"
        /* No destructor defined for SELECT */
        break;
      case 107:
#line 278 "parse.y"
{yygotominor.yy172 = 1;}
#line 5343 "parse.c"
        /* No destructor defined for DISTINCT */
        break;
      case 108:
#line 279 "parse.y"
{yygotominor.yy172 = 0;}
#line 5349 "parse.c"
        /* No destructor defined for ALL */
        break;
      case 109:
#line 280 "parse.y"
{yygotominor.yy172 = 0;}
#line 5355 "parse.c"
        break;
      case 110:
#line 291 "parse.y"
{yygotominor.yy228 = yymsp[-1].minor.yy228;}
#line 5360 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 111:
#line 292 "parse.y"
{yygotominor.yy228 = 0;}
#line 5366 "parse.c"
        break;
      case 112:
#line 293 "parse.y"
{
   yygotominor.yy228 = sqliteExprListAppend(yymsp[-2].minor.yy228,yymsp[-1].minor.yy62,yymsp[0].minor.yy378.n?&yymsp[0].minor.yy378:0);
}
#line 5373 "parse.c"
        break;
      case 113:
#line 296 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-1].minor.yy228, sqliteExpr(TK_ALL, 0, 0, 0), 0);
}
#line 5380 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 114:
#line 299 "parse.y"
{
  Expr *pRight = sqliteExpr(TK_ALL, 0, 0, 0);
  Expr *pLeft = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy378);
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-3].minor.yy228, sqliteExpr(TK_DOT, pLeft, pRight, 0), 0);
}
#line 5390 "parse.c"
        /* No destructor defined for DOT */
        /* No destructor defined for STAR */
        break;
      case 115:
#line 309 "parse.y"
{ yygotominor.yy378 = yymsp[0].minor.yy378; }
#line 5397 "parse.c"
        /* No destructor defined for AS */
        break;
      case 116:
#line 310 "parse.y"
{ yygotominor.yy378 = yymsp[0].minor.yy378; }
#line 5403 "parse.c"
        break;
      case 117:
#line 311 "parse.y"
{ yygotominor.yy378.n = 0; }
#line 5408 "parse.c"
        break;
      case 118:
#line 323 "parse.y"
{yygotominor.yy7 = sqliteMalloc(sizeof(*yygotominor.yy7));}
#line 5413 "parse.c"
        break;
      case 119:
#line 324 "parse.y"
{yygotominor.yy7 = yymsp[0].minor.yy7;}
#line 5418 "parse.c"
        /* No destructor defined for FROM */
        break;
      case 120:
#line 329 "parse.y"
{
   yygotominor.yy7 = yymsp[-1].minor.yy7;
   if( yygotominor.yy7 && yygotominor.yy7->nSrc>0 ) yygotominor.yy7->a[yygotominor.yy7->nSrc-1].jointype = yymsp[0].minor.yy172;
}
#line 5427 "parse.c"
        break;
      case 121:
#line 333 "parse.y"
{yygotominor.yy7 = 0;}
#line 5432 "parse.c"
        break;
      case 122:
#line 334 "parse.y"
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
#line 5448 "parse.c"
        break;
      case 123:
#line 346 "parse.y"
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
#line 5469 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 124:
#line 366 "parse.y"
{ yygotominor.yy172 = JT_INNER; }
#line 5476 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 125:
#line 367 "parse.y"
{ yygotominor.yy172 = JT_INNER; }
#line 5482 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 126:
#line 368 "parse.y"
{ yygotominor.yy172 = sqliteJoinType(pParse,&yymsp[-1].minor.yy0,0,0); }
#line 5488 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 127:
#line 369 "parse.y"
{ yygotominor.yy172 = sqliteJoinType(pParse,&yymsp[-2].minor.yy0,&yymsp[-1].minor.yy378,0); }
#line 5494 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 128:
#line 371 "parse.y"
{ yygotominor.yy172 = sqliteJoinType(pParse,&yymsp[-3].minor.yy0,&yymsp[-2].minor.yy378,&yymsp[-1].minor.yy378); }
#line 5500 "parse.c"
        /* No destructor defined for JOIN */
        break;
      case 129:
#line 375 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5506 "parse.c"
        /* No destructor defined for ON */
        break;
      case 130:
#line 376 "parse.y"
{yygotominor.yy62 = 0;}
#line 5512 "parse.c"
        break;
      case 131:
#line 380 "parse.y"
{yygotominor.yy250 = yymsp[-1].minor.yy250;}
#line 5517 "parse.c"
        /* No destructor defined for USING */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 132:
#line 381 "parse.y"
{yygotominor.yy250 = 0;}
#line 5525 "parse.c"
        break;
      case 133:
#line 391 "parse.y"
{yygotominor.yy228 = 0;}
#line 5530 "parse.c"
        break;
      case 134:
#line 392 "parse.y"
{yygotominor.yy228 = yymsp[0].minor.yy228;}
#line 5535 "parse.c"
        /* No destructor defined for ORDER */
        /* No destructor defined for BY */
        break;
      case 135:
#line 393 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-4].minor.yy228,yymsp[-2].minor.yy62,0);
  if( yygotominor.yy228 ) yygotominor.yy228->a[yygotominor.yy228->nExpr-1].sortOrder = yymsp[-1].minor.yy172+yymsp[0].minor.yy172;
}
#line 5545 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 136:
#line 397 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(0,yymsp[-2].minor.yy62,0);
  if( yygotominor.yy228 ) yygotominor.yy228->a[0].sortOrder = yymsp[-1].minor.yy172+yymsp[0].minor.yy172;
}
#line 5554 "parse.c"
        break;
      case 137:
#line 401 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5559 "parse.c"
        break;
      case 138:
#line 406 "parse.y"
{yygotominor.yy172 = SQLITE_SO_ASC;}
#line 5564 "parse.c"
        /* No destructor defined for ASC */
        break;
      case 139:
#line 407 "parse.y"
{yygotominor.yy172 = SQLITE_SO_DESC;}
#line 5570 "parse.c"
        /* No destructor defined for DESC */
        break;
      case 140:
#line 408 "parse.y"
{yygotominor.yy172 = SQLITE_SO_ASC;}
#line 5576 "parse.c"
        break;
      case 141:
#line 409 "parse.y"
{yygotominor.yy172 = SQLITE_SO_UNK;}
#line 5581 "parse.c"
        break;
      case 142:
#line 410 "parse.y"
{yygotominor.yy172 = sqliteCollateType(pParse, &yymsp[0].minor.yy378);}
#line 5586 "parse.c"
        /* No destructor defined for COLLATE */
        break;
      case 143:
#line 414 "parse.y"
{yygotominor.yy228 = 0;}
#line 5592 "parse.c"
        break;
      case 144:
#line 415 "parse.y"
{yygotominor.yy228 = yymsp[0].minor.yy228;}
#line 5597 "parse.c"
        /* No destructor defined for GROUP */
        /* No destructor defined for BY */
        break;
      case 145:
#line 419 "parse.y"
{yygotominor.yy62 = 0;}
#line 5604 "parse.c"
        break;
      case 146:
#line 420 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5609 "parse.c"
        /* No destructor defined for HAVING */
        break;
      case 147:
#line 423 "parse.y"
{yygotominor.yy6.limit = -1; yygotominor.yy6.offset = 0;}
#line 5615 "parse.c"
        break;
      case 148:
#line 424 "parse.y"
{yygotominor.yy6.limit = atoi(yymsp[0].minor.yy0.z); yygotominor.yy6.offset = 0;}
#line 5620 "parse.c"
        /* No destructor defined for LIMIT */
        break;
      case 149:
#line 426 "parse.y"
{yygotominor.yy6.limit = atoi(yymsp[-2].minor.yy0.z); yygotominor.yy6.offset = atoi(yymsp[0].minor.yy0.z);}
#line 5626 "parse.c"
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
#line 433 "parse.y"
{sqliteDeleteFrom(pParse, &yymsp[-1].minor.yy378, yymsp[0].minor.yy62);}
#line 5639 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 153:
#line 438 "parse.y"
{yygotominor.yy62 = 0;}
#line 5646 "parse.c"
        break;
      case 154:
#line 439 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 5651 "parse.c"
        /* No destructor defined for WHERE */
        break;
      case 155:
#line 447 "parse.y"
{sqliteUpdate(pParse,&yymsp[-3].minor.yy378,yymsp[-1].minor.yy228,yymsp[0].minor.yy62,yymsp[-4].minor.yy172);}
#line 5657 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 156:
#line 450 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(yymsp[-4].minor.yy228,yymsp[0].minor.yy62,&yymsp[-2].minor.yy378);}
#line 5664 "parse.c"
        /* No destructor defined for COMMA */
        /* No destructor defined for EQ */
        break;
      case 157:
#line 451 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(0,yymsp[0].minor.yy62,&yymsp[-2].minor.yy378);}
#line 5671 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 158:
#line 456 "parse.y"
{sqliteInsert(pParse, &yymsp[-5].minor.yy378, yymsp[-1].minor.yy228, 0, yymsp[-4].minor.yy250, yymsp[-7].minor.yy172);}
#line 5677 "parse.c"
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 159:
#line 458 "parse.y"
{sqliteInsert(pParse, &yymsp[-2].minor.yy378, 0, yymsp[0].minor.yy219, yymsp[-1].minor.yy250, yymsp[-4].minor.yy172);}
#line 5686 "parse.c"
        /* No destructor defined for INTO */
        break;
      case 160:
#line 461 "parse.y"
{yygotominor.yy172 = yymsp[0].minor.yy172;}
#line 5692 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 161:
#line 462 "parse.y"
{yygotominor.yy172 = OE_Replace;}
#line 5698 "parse.c"
        /* No destructor defined for REPLACE */
        break;
      case 162:
#line 468 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(yymsp[-2].minor.yy228,yymsp[0].minor.yy62,0);}
#line 5704 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 163:
#line 469 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(0,yymsp[0].minor.yy62,0);}
#line 5710 "parse.c"
        break;
      case 164:
#line 476 "parse.y"
{yygotominor.yy250 = 0;}
#line 5715 "parse.c"
        break;
      case 165:
#line 477 "parse.y"
{yygotominor.yy250 = yymsp[-1].minor.yy250;}
#line 5720 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 166:
#line 478 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(yymsp[-2].minor.yy250,&yymsp[0].minor.yy378);}
#line 5727 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 167:
#line 479 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(0,&yymsp[0].minor.yy378);}
#line 5733 "parse.c"
        break;
      case 168:
#line 497 "parse.y"
{yygotominor.yy62 = yymsp[-1].minor.yy62; sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);}
#line 5738 "parse.c"
        break;
      case 169:
#line 498 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_NULL, 0, 0, &yymsp[0].minor.yy0);}
#line 5743 "parse.c"
        break;
      case 170:
#line 499 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy0);}
#line 5748 "parse.c"
        break;
      case 171:
#line 500 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy0);}
#line 5753 "parse.c"
        break;
      case 172:
#line 501 "parse.y"
{
  Expr *temp1 = sqliteExpr(TK_ID, 0, 0, &yymsp[-2].minor.yy378);
  Expr *temp2 = sqliteExpr(TK_ID, 0, 0, &yymsp[0].minor.yy378);
  yygotominor.yy62 = sqliteExpr(TK_DOT, temp1, temp2, 0);
}
#line 5762 "parse.c"
        /* No destructor defined for DOT */
        break;
      case 173:
#line 506 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_INTEGER, 0, 0, &yymsp[0].minor.yy0);}
#line 5768 "parse.c"
        break;
      case 174:
#line 507 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_FLOAT, 0, 0, &yymsp[0].minor.yy0);}
#line 5773 "parse.c"
        break;
      case 175:
#line 508 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_STRING, 0, 0, &yymsp[0].minor.yy0);}
#line 5778 "parse.c"
        break;
      case 176:
#line 509 "parse.y"
{
  yygotominor.yy62 = sqliteExprFunction(yymsp[-1].minor.yy228, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 5786 "parse.c"
        /* No destructor defined for LP */
        break;
      case 177:
#line 513 "parse.y"
{
  yygotominor.yy62 = sqliteExprFunction(0, &yymsp[-3].minor.yy0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
}
#line 5795 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for STAR */
        break;
      case 178:
#line 517 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_AND, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5802 "parse.c"
        /* No destructor defined for AND */
        break;
      case 179:
#line 518 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_OR, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5808 "parse.c"
        /* No destructor defined for OR */
        break;
      case 180:
#line 519 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_LT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5814 "parse.c"
        /* No destructor defined for LT */
        break;
      case 181:
#line 520 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_GT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5820 "parse.c"
        /* No destructor defined for GT */
        break;
      case 182:
#line 521 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_LE, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5826 "parse.c"
        /* No destructor defined for LE */
        break;
      case 183:
#line 522 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_GE, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5832 "parse.c"
        /* No destructor defined for GE */
        break;
      case 184:
#line 523 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_NE, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5838 "parse.c"
        /* No destructor defined for NE */
        break;
      case 185:
#line 524 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_EQ, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5844 "parse.c"
        /* No destructor defined for EQ */
        break;
      case 186:
#line 525 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_BITAND, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5850 "parse.c"
        /* No destructor defined for BITAND */
        break;
      case 187:
#line 526 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_BITOR, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5856 "parse.c"
        /* No destructor defined for BITOR */
        break;
      case 188:
#line 527 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_LSHIFT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5862 "parse.c"
        /* No destructor defined for LSHIFT */
        break;
      case 189:
#line 528 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_RSHIFT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5868 "parse.c"
        /* No destructor defined for RSHIFT */
        break;
      case 190:
#line 529 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[0].minor.yy62, 0);
  pList = sqliteExprListAppend(pList, yymsp[-2].minor.yy62, 0);
  yygotominor.yy62 = sqliteExprFunction(pList, &yymsp[-1].minor.yy378);
  sqliteExprSpan(yygotominor.yy62, &yymsp[-2].minor.yy62->span, &yymsp[0].minor.yy62->span);
}
#line 5879 "parse.c"
        break;
      case 191:
#line 535 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[0].minor.yy62, 0);
  pList = sqliteExprListAppend(pList, yymsp[-3].minor.yy62, 0);
  yygotominor.yy62 = sqliteExprFunction(pList, &yymsp[-1].minor.yy378);
  yygotominor.yy62 = sqliteExpr(TK_NOT, yygotominor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy62->span,&yymsp[0].minor.yy62->span);
}
#line 5890 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 192:
#line 542 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 5896 "parse.c"
        break;
      case 193:
#line 543 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 5901 "parse.c"
        break;
      case 194:
#line 544 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_PLUS, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5906 "parse.c"
        /* No destructor defined for PLUS */
        break;
      case 195:
#line 545 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_MINUS, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5912 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 196:
#line 546 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_STAR, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5918 "parse.c"
        /* No destructor defined for STAR */
        break;
      case 197:
#line 547 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_SLASH, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5924 "parse.c"
        /* No destructor defined for SLASH */
        break;
      case 198:
#line 548 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_REM, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5930 "parse.c"
        /* No destructor defined for REM */
        break;
      case 199:
#line 549 "parse.y"
{yygotominor.yy62 = sqliteExpr(TK_CONCAT, yymsp[-2].minor.yy62, yymsp[0].minor.yy62, 0);}
#line 5936 "parse.c"
        /* No destructor defined for CONCAT */
        break;
      case 200:
#line 550 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_ISNULL, yymsp[-1].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5945 "parse.c"
        break;
      case 201:
#line 554 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_ISNULL, yymsp[-2].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5953 "parse.c"
        /* No destructor defined for IS */
        break;
      case 202:
#line 558 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOTNULL, yymsp[-1].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5962 "parse.c"
        break;
      case 203:
#line 562 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOTNULL, yymsp[-2].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5970 "parse.c"
        /* No destructor defined for NOT */
        break;
      case 204:
#line 566 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOTNULL, yymsp[-3].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-3].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 5979 "parse.c"
        /* No destructor defined for IS */
        /* No destructor defined for NOT */
        break;
      case 205:
#line 570 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_NOT, yymsp[0].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 5989 "parse.c"
        break;
      case 206:
#line 574 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_BITNOT, yymsp[0].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 5997 "parse.c"
        break;
      case 207:
#line 578 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_UMINUS, yymsp[0].minor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 6005 "parse.c"
        break;
      case 208:
#line 582 "parse.y"
{
  yygotominor.yy62 = yymsp[0].minor.yy62;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy62->span);
}
#line 6013 "parse.c"
        break;
      case 209:
#line 586 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_SELECT, 0, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pSelect = yymsp[-1].minor.yy219;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);
}
#line 6022 "parse.c"
        break;
      case 210:
#line 591 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy62, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy62, 0);
  yygotominor.yy62 = sqliteExpr(TK_BETWEEN, yymsp[-4].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = pList;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-4].minor.yy62->span,&yymsp[0].minor.yy62->span);
}
#line 6033 "parse.c"
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 211:
#line 598 "parse.y"
{
  ExprList *pList = sqliteExprListAppend(0, yymsp[-2].minor.yy62, 0);
  pList = sqliteExprListAppend(pList, yymsp[0].minor.yy62, 0);
  yygotominor.yy62 = sqliteExpr(TK_BETWEEN, yymsp[-5].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = pList;
  yygotominor.yy62 = sqliteExpr(TK_NOT, yygotominor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-5].minor.yy62->span,&yymsp[0].minor.yy62->span);
}
#line 6047 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for BETWEEN */
        /* No destructor defined for AND */
        break;
      case 212:
#line 606 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_IN, yymsp[-4].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = yymsp[-1].minor.yy228;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-4].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 6059 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 213:
#line 611 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_IN, yymsp[-4].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pSelect = yymsp[-1].minor.yy219;
  sqliteExprSpan(yygotominor.yy62,&yymsp[-4].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 6070 "parse.c"
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 214:
#line 616 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_IN, yymsp[-5].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = yymsp[-1].minor.yy228;
  yygotominor.yy62 = sqliteExpr(TK_NOT, yygotominor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-5].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 6082 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 215:
#line 622 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_IN, yymsp[-5].minor.yy62, 0, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pSelect = yymsp[-1].minor.yy219;
  yygotominor.yy62 = sqliteExpr(TK_NOT, yygotominor.yy62, 0, 0);
  sqliteExprSpan(yygotominor.yy62,&yymsp[-5].minor.yy62->span,&yymsp[0].minor.yy0);
}
#line 6095 "parse.c"
        /* No destructor defined for NOT */
        /* No destructor defined for IN */
        /* No destructor defined for LP */
        break;
      case 216:
#line 630 "parse.y"
{
  yygotominor.yy62 = sqliteExpr(TK_CASE, yymsp[-3].minor.yy62, yymsp[-1].minor.yy62, 0);
  if( yygotominor.yy62 ) yygotominor.yy62->pList = yymsp[-2].minor.yy228;
  sqliteExprSpan(yygotominor.yy62, &yymsp[-4].minor.yy0, &yymsp[0].minor.yy0);
}
#line 6107 "parse.c"
        break;
      case 217:
#line 637 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(yymsp[-4].minor.yy228, yymsp[-2].minor.yy62, 0);
  yygotominor.yy228 = sqliteExprListAppend(yygotominor.yy228, yymsp[0].minor.yy62, 0);
}
#line 6115 "parse.c"
        /* No destructor defined for WHEN */
        /* No destructor defined for THEN */
        break;
      case 218:
#line 641 "parse.y"
{
  yygotominor.yy228 = sqliteExprListAppend(0, yymsp[-2].minor.yy62, 0);
  yygotominor.yy228 = sqliteExprListAppend(yygotominor.yy228, yymsp[0].minor.yy62, 0);
}
#line 6125 "parse.c"
        /* No destructor defined for WHEN */
        /* No destructor defined for THEN */
        break;
      case 219:
#line 646 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 6132 "parse.c"
        /* No destructor defined for ELSE */
        break;
      case 220:
#line 647 "parse.y"
{yygotominor.yy62 = 0;}
#line 6138 "parse.c"
        break;
      case 221:
#line 649 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 6143 "parse.c"
        break;
      case 222:
#line 650 "parse.y"
{yygotominor.yy62 = 0;}
#line 6148 "parse.c"
        break;
      case 223:
#line 658 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(yymsp[-2].minor.yy228,yymsp[0].minor.yy62,0);}
#line 6153 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 224:
#line 659 "parse.y"
{yygotominor.yy228 = sqliteExprListAppend(0,yymsp[0].minor.yy62,0);}
#line 6159 "parse.c"
        break;
      case 225:
#line 660 "parse.y"
{yygotominor.yy62 = yymsp[0].minor.yy62;}
#line 6164 "parse.c"
        break;
      case 226:
#line 661 "parse.y"
{yygotominor.yy62 = 0;}
#line 6169 "parse.c"
        break;
      case 227:
#line 666 "parse.y"
{
  if( yymsp[-8].minor.yy172!=OE_None ) yymsp[-8].minor.yy172 = yymsp[0].minor.yy172;
  if( yymsp[-8].minor.yy172==OE_Default) yymsp[-8].minor.yy172 = OE_Abort;
  sqliteCreateIndex(pParse, &yymsp[-6].minor.yy378, &yymsp[-4].minor.yy378, yymsp[-2].minor.yy250, yymsp[-8].minor.yy172, &yymsp[-9].minor.yy0, &yymsp[-1].minor.yy0);
}
#line 6178 "parse.c"
        /* No destructor defined for INDEX */
        /* No destructor defined for ON */
        /* No destructor defined for LP */
        break;
      case 228:
#line 673 "parse.y"
{ yygotominor.yy172 = OE_Abort; }
#line 6186 "parse.c"
        /* No destructor defined for UNIQUE */
        break;
      case 229:
#line 674 "parse.y"
{ yygotominor.yy172 = OE_None; }
#line 6192 "parse.c"
        break;
      case 230:
#line 681 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(yymsp[-2].minor.yy250,&yymsp[0].minor.yy378);}
#line 6197 "parse.c"
        /* No destructor defined for COMMA */
        break;
      case 231:
#line 683 "parse.y"
{yygotominor.yy250 = sqliteIdListAppend(0,&yymsp[0].minor.yy378);}
#line 6203 "parse.c"
        break;
      case 232:
#line 684 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 6208 "parse.c"
        break;
      case 233:
#line 689 "parse.y"
{sqliteDropIndex(pParse, &yymsp[0].minor.yy378);}
#line 6213 "parse.c"
        /* No destructor defined for DROP */
        /* No destructor defined for INDEX */
        break;
      case 234:
#line 695 "parse.y"
{sqliteCopy(pParse,&yymsp[-5].minor.yy378,&yymsp[-3].minor.yy378,&yymsp[0].minor.yy0,yymsp[-6].minor.yy172);}
#line 6220 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        /* No destructor defined for USING */
        /* No destructor defined for DELIMITERS */
        break;
      case 235:
#line 697 "parse.y"
{sqliteCopy(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,0,yymsp[-3].minor.yy172);}
#line 6229 "parse.c"
        /* No destructor defined for COPY */
        /* No destructor defined for FROM */
        break;
      case 236:
#line 701 "parse.y"
{sqliteVacuum(pParse,0);}
#line 6236 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 237:
#line 702 "parse.y"
{sqliteVacuum(pParse,&yymsp[0].minor.yy378);}
#line 6242 "parse.c"
        /* No destructor defined for VACUUM */
        break;
      case 238:
#line 706 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,0);}
#line 6248 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 239:
#line 707 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy0,0);}
#line 6255 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 240:
#line 708 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,0);}
#line 6262 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 241:
#line 709 "parse.y"
{sqlitePragma(pParse,&yymsp[-2].minor.yy378,&yymsp[0].minor.yy378,1);}
#line 6269 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for EQ */
        break;
      case 242:
#line 710 "parse.y"
{sqlitePragma(pParse,&yymsp[-3].minor.yy378,&yymsp[-1].minor.yy378,0);}
#line 6276 "parse.c"
        /* No destructor defined for PRAGMA */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 243:
#line 711 "parse.y"
{sqlitePragma(pParse,&yymsp[0].minor.yy378,&yymsp[0].minor.yy378,0);}
#line 6284 "parse.c"
        /* No destructor defined for PRAGMA */
        break;
      case 244:
#line 712 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 6290 "parse.c"
        /* No destructor defined for plus_opt */
        break;
      case 245:
#line 713 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy378;}
#line 6296 "parse.c"
        /* No destructor defined for MINUS */
        break;
      case 246:
#line 714 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 6302 "parse.c"
        break;
      case 247:
#line 715 "parse.y"
{yygotominor.yy378 = yymsp[0].minor.yy0;}
#line 6307 "parse.c"
        break;
      case 248:
        /* No destructor defined for PLUS */
        break;
      case 249:
        break;
      case 250:
#line 722 "parse.y"
{
  sqliteCreateTrigger(pParse, &yymsp[-9].minor.yy378, yymsp[-8].minor.yy172, yymsp[-7].minor.yy90.a, yymsp[-7].minor.yy90.b, &yymsp[-5].minor.yy378, yymsp[-4].minor.yy172, yymsp[-3].minor.yy308, yymsp[-1].minor.yy311, 
      yymsp[-11].minor.yy0.z, (int)(yymsp[0].minor.yy0.z - yymsp[-11].minor.yy0.z) + yymsp[0].minor.yy0.n );
}
#line 6320 "parse.c"
        /* No destructor defined for TRIGGER */
        /* No destructor defined for ON */
        /* No destructor defined for BEGIN */
        break;
      case 251:
#line 728 "parse.y"
{ yygotominor.yy172 = TK_BEFORE; }
#line 6328 "parse.c"
        /* No destructor defined for BEFORE */
        break;
      case 252:
#line 729 "parse.y"
{ yygotominor.yy172 = TK_AFTER;  }
#line 6334 "parse.c"
        /* No destructor defined for AFTER */
        break;
      case 253:
#line 730 "parse.y"
{ yygotominor.yy172 = TK_INSTEAD;}
#line 6340 "parse.c"
        /* No destructor defined for INSTEAD */
        /* No destructor defined for OF */
        break;
      case 254:
#line 731 "parse.y"
{ yygotominor.yy172 = TK_BEFORE; }
#line 6347 "parse.c"
        break;
      case 255:
#line 735 "parse.y"
{ yygotominor.yy90.a = TK_DELETE; yygotominor.yy90.b = 0; }
#line 6352 "parse.c"
        /* No destructor defined for DELETE */
        break;
      case 256:
#line 736 "parse.y"
{ yygotominor.yy90.a = TK_INSERT; yygotominor.yy90.b = 0; }
#line 6358 "parse.c"
        /* No destructor defined for INSERT */
        break;
      case 257:
#line 737 "parse.y"
{ yygotominor.yy90.a = TK_UPDATE; yygotominor.yy90.b = 0;}
#line 6364 "parse.c"
        /* No destructor defined for UPDATE */
        break;
      case 258:
#line 738 "parse.y"
{yygotominor.yy90.a = TK_UPDATE; yygotominor.yy90.b = yymsp[0].minor.yy250; }
#line 6370 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for OF */
        break;
      case 259:
#line 741 "parse.y"
{ yygotominor.yy172 = TK_ROW; }
#line 6377 "parse.c"
        break;
      case 260:
#line 742 "parse.y"
{ yygotominor.yy172 = TK_ROW; }
#line 6382 "parse.c"
        /* No destructor defined for FOR */
        /* No destructor defined for EACH */
        /* No destructor defined for ROW */
        break;
      case 261:
#line 743 "parse.y"
{ yygotominor.yy172 = TK_STATEMENT; }
#line 6390 "parse.c"
        /* No destructor defined for FOR */
        /* No destructor defined for EACH */
        /* No destructor defined for STATEMENT */
        break;
      case 262:
#line 746 "parse.y"
{ yygotominor.yy308 = 0; }
#line 6398 "parse.c"
        break;
      case 263:
#line 747 "parse.y"
{ yygotominor.yy308 = yymsp[0].minor.yy62; }
#line 6403 "parse.c"
        /* No destructor defined for WHEN */
        break;
      case 264:
#line 750 "parse.y"
{
  yymsp[-2].minor.yy311->pNext = yymsp[0].minor.yy311 ; yygotominor.yy311 = yymsp[-2].minor.yy311; }
#line 6410 "parse.c"
        /* No destructor defined for SEMI */
        break;
      case 265:
#line 752 "parse.y"
{ yygotominor.yy311 = 0; }
#line 6416 "parse.c"
        break;
      case 266:
#line 757 "parse.y"
{ yygotominor.yy311 = sqliteTriggerUpdateStep(&yymsp[-3].minor.yy378, yymsp[-1].minor.yy228, yymsp[0].minor.yy62, yymsp[-4].minor.yy172); }
#line 6421 "parse.c"
        /* No destructor defined for UPDATE */
        /* No destructor defined for SET */
        break;
      case 267:
#line 762 "parse.y"
{yygotominor.yy311 = sqliteTriggerInsertStep(&yymsp[-5].minor.yy378, yymsp[-4].minor.yy250, yymsp[-1].minor.yy228, 0, yymsp[-7].minor.yy172);}
#line 6428 "parse.c"
        /* No destructor defined for INSERT */
        /* No destructor defined for INTO */
        /* No destructor defined for VALUES */
        /* No destructor defined for LP */
        /* No destructor defined for RP */
        break;
      case 268:
#line 765 "parse.y"
{yygotominor.yy311 = sqliteTriggerInsertStep(&yymsp[-2].minor.yy378, yymsp[-1].minor.yy250, 0, yymsp[0].minor.yy219, yymsp[-4].minor.yy172);}
#line 6438 "parse.c"
        /* No destructor defined for INSERT */
        /* No destructor defined for INTO */
        break;
      case 269:
#line 769 "parse.y"
{yygotominor.yy311 = sqliteTriggerDeleteStep(&yymsp[-1].minor.yy378, yymsp[0].minor.yy62);}
#line 6445 "parse.c"
        /* No destructor defined for DELETE */
        /* No destructor defined for FROM */
        break;
      case 270:
#line 772 "parse.y"
{yygotominor.yy311 = sqliteTriggerSelectStep(yymsp[0].minor.yy219); }
#line 6452 "parse.c"
        break;
      case 271:
#line 775 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, 0); 
    yygotominor.yy62->iColumn = OE_Ignore; sqliteExprSpan(yygotominor.yy62, &yymsp[-3].minor.yy0, &yymsp[0].minor.yy0);}
#line 6458 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for IGNORE */
        break;
      case 272:
#line 778 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy378); 
    yygotominor.yy62->iColumn = OE_Rollback; sqliteExprSpan(yygotominor.yy62, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);}
#line 6466 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for ROLLBACK */
        /* No destructor defined for COMMA */
        break;
      case 273:
#line 781 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy378); 
    yygotominor.yy62->iColumn = OE_Abort; sqliteExprSpan(yygotominor.yy62, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);}
#line 6475 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for ABORT */
        /* No destructor defined for COMMA */
        break;
      case 274:
#line 784 "parse.y"
{ yygotominor.yy62 = sqliteExpr(TK_RAISE, 0, 0, &yymsp[-1].minor.yy378); 
    yygotominor.yy62->iColumn = OE_Fail; sqliteExprSpan(yygotominor.yy62, &yymsp[-5].minor.yy0, &yymsp[0].minor.yy0);}
#line 6484 "parse.c"
        /* No destructor defined for LP */
        /* No destructor defined for FAIL */
        /* No destructor defined for COMMA */
        break;
      case 275:
#line 788 "parse.y"
{
    sqliteDropTrigger(pParse,&yymsp[0].minor.yy378,0);
}
#line 6494 "parse.c"
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

#line 6544 "parse.c"
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
