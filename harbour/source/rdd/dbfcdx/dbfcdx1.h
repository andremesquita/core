
//#define LOCK_START                                            0x40000000L
//#define LOCK_APPEND                                           0x7FFFFFFEL
//#define LOCK_FILE                                             0x3FFFFFFFL
//#define MEMO_BLOCK                                                     64
//#define CDX_MAX_KEY                                                   240
//#define CDX_MAX_TAG_NAME_LEN                                           10
//#define CDX_BLOCK_SIZE                                                512
#define CDX_INTERNAL_SPACE                                            500
#define CDX_EXTERNAL_SPACE                                            488
#define CDX_MAX_REC_NUM                                       0x7FFFFFFFL
#define CDX_IGNORE_REC_NUM                                             -1
#define PAGE_ROOT                                                       1
#define PAGE_NODE                                                       2
#define PAGE_LEAF                                                       3
#define TOP_RECORD                                                      1
#define BTTM_RECORD                                                     2
#define PREV_RECORD                                                     3
#define NEXT_RECORD                                                     4
#define SORT_CHUNK_LIMIT                                            16384
#define SORT_ACTIVE_LIST                                                0
#define SORT_END_OF_KEY                                                 1
#define SORT_END_OF_WORD                                                2
#define SORT_STACK_OF_CHAR                                              3


#if (__BORLANDC__ > 1040) /* Use this only above Borland C++ 3.1 */
   #pragma option -a1 /* byte alignment */
#endif
#if defined(__GNUC__)
   #pragma pack(1)
#endif

typedef struct
{
   USHORT FreeSpace;
   LONG   RecNumMask;
   BYTE   DupCntMask;
   BYTE   TrlCntMask;
   BYTE   RecNumBits;
   BYTE   DupCntBits;
   BYTE   TrlCntBits;
   BYTE   ShortBytes;
   BYTE   ExtData[ CDX_EXTERNAL_SPACE ];
} CDXEXTERNAL;
typedef struct
{
   BYTE   IntData[ CDX_INTERNAL_SPACE ];
} CDXINTERNAL;
typedef struct _CDXDATA
{
   USHORT Node_Atr;
   USHORT Entry_Ct;
   LONG   Left_Ptr;
   LONG   Rght_Ptr;
   union
   {
      CDXEXTERNAL External;
      CDXINTERNAL Internal;
   } cdxu;
} CDXDATA;
#if (__BORLANDC__ > 1040) /* Use this only above Borland C++ 3.1 */
   #pragma option -a /* default alignment */
#endif
#if defined(__GNUC__)
   #pragma pack()
#endif
typedef CDXDATA * LPCDXDATA;

typedef struct _KEYINFO
{
   PHB_ITEM pItem;
   LONG     Tag;
   LONG     Xtra;
   struct  _KEYINFO * pNext;
} KEYINFO;
typedef KEYINFO * LPKEYINFO;

typedef struct HB_PAGEINFO_STRU
{
   LONG      Page;
   LONG      Left;
   LONG      Right;
   BOOL      Changed;
   BOOL      NewRoot;
   BOOL      LastEntry;
   BOOL      Reload;
   BOOL      ChkBOF;
   BOOL      ChkEOF;
   BYTE      PageType;
   LONG      RNMask;
   BYTE      ReqByte;
   BYTE      RNBits;
   BYTE      DCBits;
   BYTE      TCBits;
   BYTE      DCMask;
   BYTE      TCMask;
   USHORT    Space;
   LPKEYINFO pKeys;
   USHORT    uiKeys;
   SHORT     CurKey;
   struct HB_PAGEINFO_STRU * Owner;
   struct HB_PAGEINFO_STRU * Child;
   struct _CDXTAG * TagParent;
} HB_PAGEINFO;
typedef HB_PAGEINFO * LPPAGEINFO;


/*SORT stuff*/
typedef struct
{
   char   Character;
   BYTE   NUse;
   USHORT WordArray;
   USHORT Fill02;
   USHORT LevelLink;
} SORT_A;


typedef struct
{
   BYTE Fill03[ 4 ];
   char ChrStack[ 4 ];
} SORT_B;


typedef struct
{
   LONG Fill04;
   LONG ChrFill;
} SORT_C;


typedef struct
{
   union
   {
      SORT_A A;
      SORT_B B;
      SORT_C C;
   } sortu;
} SORTDATA;

typedef SORTDATA * LPSORTDATA;


typedef struct
{
   LONG       WordCount;
   LONG       RootLink;
   LONG       LevelPtr;
   LONG       PriorPtr;
   LONG       KeyTot;
   LONG       KeyCnt;
   LONG       LastTag;
   LONG *     ChunkList;
   BYTE *     SortBuffer;
   USHORT     SortChunk;
   USHORT     NodeLimit;
   USHORT     NodeMask;
   USHORT     NodeShift;
   USHORT     ChunkSize;
   USHORT     ChunkLimit;
   USHORT     ChunkCur;
   USHORT     NodeCur;
   USHORT     KeySize;
   USHORT     WCur;
   BOOL       Unique;
   BOOL       Ascend;
   BOOL       Closing;
   char       WPch[ 256 ];
   SORTDATA * WAdr;
   struct _CDXTAG * CurTag;
   LPCDXDATA  NodeList[ 32 ];
   LPKEYINFO  KeyWork;
   LPKEYINFO  LastKey;
} SORTINFO;

typedef SORTINFO * LPSORTINFO;