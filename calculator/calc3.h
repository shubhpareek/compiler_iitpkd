typedef enum { typeCon, typeOpr } nodeEnum;
/* constants */
typedef struct {
int value;
} conNodeType;
/* identifiers */

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
};
} nodeType;
/* value of constant */
/* subscript to sym array */
/* operator */
/* number of operands */
/* operands */
/* type of node */
/* constants */
/* identifiers */
/* operators */