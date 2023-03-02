typedef enum { typeCon, typeOpr,typeId,decl,prin} nodeEnum;
/* constants */
typedef struct {
int value;
} conNodeType;
/* identifiers */
/* identifiers */
typedef struct {
char *i;
} idNodeType;
/* operators */
typedef struct {
int oper;
int nops;
struct nodeTypeTag **op;
} oprNodeType;

typedef struct nodeTypeTag {
nodeEnum type;
union {
conNodeType con;
oprNodeType opr;
idNodeType  id;
struct vlist * vl;
};
} nodeType;

struct vlist
{
    nodeType  * val;
    struct vlist * next;
};


struct statementlist{
nodeType *ptr;
struct statementlist * next;
};

/* value of constant */
/* subscript to sym array */
/* operator */
/* number of operands */
/* operands */
/* type of node */
/* constants */
/* identifiers */
/* operators */
