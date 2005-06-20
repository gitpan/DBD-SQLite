/* Automatically generated.  Do not edit */
/* See the mkopcodeh.awk script for details */
#define OP_ReadCookie                           1
#define OP_AutoCommit                           2
#define OP_Found                                3
#define OP_NullRow                              4
#define OP_Lt                                  74   /* same as TK_LT       */
#define OP_MoveLe                               5
#define OP_Variable                             6
#define OP_Pull                                 7
#define OP_Sort                                 8
#define OP_SortNext                             9
#define OP_IfNot                               10
#define OP_Gosub                               11
#define OP_Add                                 81   /* same as TK_PLUS     */
#define OP_NotFound                            12
#define OP_IsNull                              68   /* same as TK_ISNULL   */
#define OP_MoveLt                              13
#define OP_Rowid                               14
#define OP_Push                                15
#define OP_CreateIndex                         16
#define OP_Statement                           17
#define OP_Callback                            18
#define OP_MemLoad                             19
#define OP_Null                                20
#define OP_DropIndex                           21
#define OP_IdxInsert                           22
#define OP_Next                                23
#define OP_SetNumColumns                       24
#define OP_Ge                                  75   /* same as TK_GE       */
#define OP_BitNot                              89   /* same as TK_BITNOT   */
#define OP_Dup                                 25
#define OP_Rewind                              26
#define OP_Multiply                            83   /* same as TK_STAR     */
#define OP_AggFunc                             27
#define OP_Gt                                  72   /* same as TK_GT       */
#define OP_Last                                28
#define OP_MustBeInt                           29
#define OP_Ne                                  70   /* same as TK_NE       */
#define OP_MoveGe                              30
#define OP_AggSet                              31
#define OP_ListRewind                          32
#define OP_String                              33
#define OP_ForceInt                            34
#define OP_Close                               35
#define OP_AggFocus                            36
#define OP_AbsValue                            37
#define OP_RowData                             38
#define OP_IdxRowid                            39
#define OP_BitOr                               78   /* same as TK_BITOR    */
#define OP_NotNull                             69   /* same as TK_NOTNULL  */
#define OP_MoveGt                              40
#define OP_Not                                 64   /* same as TK_NOT      */
#define OP_OpenPseudo                          41
#define OP_Halt                                42
#define OP_NewRowid                            43
#define OP_Real                               128   /* same as TK_FLOAT    */
#define OP_IdxLT                               44
#define OP_Distinct                            45
#define OP_SortReset                           46
#define OP_AggReset                            47
#define OP_MemMax                              48
#define OP_Function                            49
#define OP_Remainder                           85   /* same as TK_REM      */
#define OP_IntegrityCk                         50
#define OP_HexBlob                            129   /* same as TK_BLOB     */
#define OP_ShiftLeft                           79   /* same as TK_LSHIFT   */
#define OP_AggContextPop                       51
#define OP_BitAnd                              77   /* same as TK_BITAND   */
#define OP_Or                                  62   /* same as TK_OR       */
#define OP_NotExists                           52
#define OP_MemStore                            53
#define OP_IdxDelete                           54
#define OP_Vacuum                              55
#define OP_If                                  56
#define OP_Destroy                             57
#define OP_Insert                              58
#define OP_Clear                               59
#define OP_IdxGE                               60
#define OP_Divide                              84   /* same as TK_SLASH    */
#define OP_String8                             90   /* same as TK_STRING   */
#define OP_Concat                              86   /* same as TK_CONCAT   */
#define OP_MakeRecord                          61
#define OP_AggContextPush                      65
#define OP_SetCookie                           66
#define OP_Prev                                67
#define OP_AggGet                              76
#define OP_ContextPush                         88
#define OP_ListWrite                           91
#define OP_DropTrigger                         92
#define OP_IdxGT                               93
#define OP_AggNext                             94
#define OP_And                                 63   /* same as TK_AND      */
#define OP_Return                              95
#define OP_OpenWrite                           96
#define OP_Integer                             97
#define OP_Transaction                         98
#define OP_CollSeq                             99
#define OP_ContextPop                         100
#define OP_ShiftRight                          80   /* same as TK_RSHIFT   */
#define OP_CreateTable                        101
#define OP_AddImm                             102
#define OP_IdxIsNull                          103
#define OP_IsUnique                           104
#define OP_DropTable                          105
#define OP_ListRead                           106
#define OP_AggInit                            107
#define OP_SortInsert                         108
#define OP_Noop                               109
#define OP_RowKey                             110
#define OP_OpenTemp                           111
#define OP_Expire                             112
#define OP_Delete                             113
#define OP_IfMemPos                           114
#define OP_Subtract                            82   /* same as TK_MINUS    */
#define OP_MemIncr                            115
#define OP_Blob                               116
#define OP_Goto                               117
#define OP_Negative                            87   /* same as TK_UMINUS   */
#define OP_ParseSchema                        118
#define OP_Eq                                  71   /* same as TK_EQ       */
#define OP_Pop                                119
#define OP_Le                                  73   /* same as TK_LE       */
#define OP_ListReset                          120
#define OP_VerifyCookie                       121
#define OP_Column                             122
#define OP_OpenRead                           123
#define OP_ResetCount                         124

/* The following opcode values are never used */
#define OP_NotUsed_125                        125
#define OP_NotUsed_126                        126
#define OP_NotUsed_127                        127

#define NOPUSH_MASK_0 48572
#define NOPUSH_MASK_1 64998
#define NOPUSH_MASK_2 63261
#define NOPUSH_MASK_3 56825
#define NOPUSH_MASK_4 61439
#define NOPUSH_MASK_5 64447
#define NOPUSH_MASK_6 48093
#define NOPUSH_MASK_7 7151
#define NOPUSH_MASK_8 0
#define NOPUSH_MASK_9 0
