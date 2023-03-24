//gdecl_sec section 

//symbol table must be there , this can have variable , functions.

//local declarations will also be stored in symbol table ,but will be removed after block ends;


int frty,rrty,arty;



struct symbolTable{
    int what;
    int gl;
    union{
    //struct fdecl *f;
    //struct vdecl *v;
    //arr type
}

}symtb[70];


struct gltype{
    int what ;
union{
    struct fdecl *f;
    struct vdecl *v;
}
}
;



struct gdeclist{
    struct gltype * val;
    struct gdeclist *npt;
}
;
struct gdeclist *head,*root;

head = (struct gdeclist *)malloc(sizeof(struct gdeclist));
root = head;

//////////////////
%{
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdarg.h>
#include "calc3.h"
/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *con(int value);
void insert(nodeType *potr);
void runner(struct statementlist * st);
struct vlist * crhead(nodeType *ptr);
struct vlist * conn(struct vlist * root,nodeType * ptr);
nodeType * vlitonpt(struct vlist * root,int type);
nodeType *id(char *x);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);
void yyerror(char *s);
int count=0;
int poss;
int ab;
struct dataType {
	char * id_name;
	char * data_type;
	int value;
	int def;
} symbolTable[40];

int search(char *type);

void add(char * name);
struct statementlist *head,*root;
%}
%union {
int iValue;
char * sindex;
nodeType *nPtr;
struct vlist * valist;
};
%token	<iValue> NUMBER 
%token <sindex> var
%token  '+' '*' '/' '(' ')'  prt typp begindecl enddecl  ';' ',' '='
%left	'+' '-' /* left associative, same precedence */
%left	'*' '/'	  /* left assoc., higher precedence */
%nonassoc UMINUS
%type <valist> varlist vars
%type <nPtr> expr stmt declstmt assstmt prtstmt
%%
stmtlist:	/* Parser: Productions */
	|  stmtlist stmt   {/*puts("getting inserted");*/insert($2);}//connect to stmtlist//{ printf("%d\n",ex($2)); freeNode($2);}
	;
stmt : declstmt 	{/*puts("decl to stmt");*/$$ = $1; }
	| assstmt ';'   {$$ = $1;}
	| prtstmt ';'   {$$ = $1;}
	;
declstmt : begindecl vars enddecl {/*printf("declstmt\n");*/$$ = vlitonpt($2,1);} ;
	
vars : typp varlist ';' {/*printf("in vars\n");*/$$ = $2;};

varlist : varlist ',' var {/*printf("connecting\n");*/$$ = conn($1,id($3)); }
	|     var             {/*printf("creating head\n");*/$$ = crhead(id($1));}
	;
assstmt : var '=' expr {/*puts("assign");*/$$ = opr('=', 2, id($1), $3);} 
		//| var '=' var  {$$ = opr('=', 2, id($1), id($3));};
		;

prtstmt : prt '(' varlist ')' {$$ = vlitonpt($3,2);};
	
expr:	  NUMBER	{/*puts("found a number");*/ $$ = con($1); }
	| var {/*printf("in expr\n");*/$$ = id($1);}
	| '-' expr %prec UMINUS { $$ = opr(UMINUS, 1, $2); }
	//| '-' var %prec UMINUS { $$ = opr(UMINUS, 1, id($2)); } 
	| expr '+' expr	{  $$ = opr('+', 2, $1, $3); }
	| expr '-' expr	{  $$ = opr('-', 2, $1, $3); }
	| expr '*' expr	{  $$ = opr('*', 2, $1, $3); }
	| expr '/' expr	{  $$ = opr('/', 2, $1, $3); }
	//| expr '+' var  {  $$ = opr('+', 2, $1, id($3)); }
	//| expr '-' var  {  $$ = opr('-', 2, $1, id($3)); }
	// | var  '+' expr {  $$ = opr('+', 2, id($1), $3); }
	// | var  '-' expr {  $$ = opr('-', 2, id($1), $3); }
	//| expr '*' var  {  $$ = opr('*', 2, $1, id($3)); }
	//| expr '/' var  {  $$ = opr('/', 2, $1, id($3)); }
	//| var  '*' expr {  $$ = opr('*', 2, id($1), $3); }
	//| var  '/' expr {  $$ = opr('/', 2, id($1), $3); }
	//| '(' var ')' {$$ = id($2);}
	| '(' expr ')'	{ $$ = $2; }
	;
%%
	/* end of grammar */
int main(void) {
head = (struct statementlist *)malloc(sizeof(struct statementlist));
if(head==NULL)
{
	puts("outofmemory");
	return 0;
}
head->next=NULL;
root = head;

yyparse();
runner(head);exit(0);
return 0;
}

//#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)
nodeType *con(int value) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
	yyerror("out of memory");
	/* copy information */
	p->type = typeCon;
	/*printf("a number of value %d\n",value);*/
	p->con.value = value;
	return p;
}


nodeType *opr(int oper, int nops, ...) {
	va_list ap;
	nodeType *p;
	int i;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
	yyerror("out of memory");
	if ((p->opr.op = malloc(nops * sizeof(nodeType))) == NULL)
	yyerror("out of memory");
	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
	p->opr.op[i] = va_arg(ap, nodeType*);
	va_end(ap);
return p;
}
nodeType *id(char *x) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
	yyerror("out of memory");
	/* copy information */
	p->type = typeId;
	p->id.i = strdup(x);
	return p;
}
void freeNode(nodeType *p) {
	int i;
	if (!p) return;
	if (p->type == typeOpr) {
	for (i = 0; i < p->opr.nops; i++)
	freeNode(p->opr.op[i]);
	free(p->opr.op);
	}
free (p);
}
void yyerror(char *s) {
fprintf(stdout, "%s\n", s);
}

void insert(nodeType *potr)
{
	// puts("doing insertion");
	struct statementlist * temp;
	temp = (struct statementlist *)malloc(sizeof(struct statementlist));
	root->next = temp;
	temp->next = NULL;
	temp->ptr=potr;
	root = temp;
}

void runner(struct statementlist * st)
{
	int cnt =0;
	// puts("yo,iam");

	while(st->next!=NULL)
	{
		cnt++;
		st=st->next;
		// printf("on stmt no %d\n",cnt);
            
	
		ex(st->ptr);
		puts(" ");
            //freeNode(st->ptr);
	}
}

struct vlist * crhead(nodeType *ptr)
{
    struct vlist * ans;
    ans = (struct vlist *)malloc(sizeof(struct vlist));
    ans->val=ptr;
    ans->next= NULL;
	return ans;
}

struct vlist * conn(struct vlist * root,nodeType * ptr)
{
    struct vlist * ans;
    ans = (struct vlist *)malloc(sizeof(struct vlist));
    ans->val=ptr;
    ans->next= NULL;
    struct vlist * temp = root;
    while(temp->next!=NULL)
    {
    temp=temp->next;
    }
    temp->next=ans;
    return root;
}

nodeType * vlitonpt(struct vlist * root,int type)
{
    nodeType * ans;
    ans = (nodeType *)malloc(sizeof(nodeType));
    if(type==1)
    {
        ans->type=decl;
        ans->vl=root;
    }
    else
    {
        ans->type=prin;
        ans->vl=root;
    }
    return ans;
}
int ex(nodeType *p) {
// puts("in ex ");
if (!p) return 0;
switch(p->type) {
case decl:
printf("declaration ");
struct vlist * star = p->vl;
while(1)
{
	add((star->val)->id.i);
	printf("%s ,",(star->val)->id.i);
	if(star->next != NULL)
	{
		star=star->next;
	}
	else{
		break;
	}
}
return 0;
case prin:
printf("print ");
struct vlist * starr = p->vl;
while(1)
{
	int xx=search((starr->val)->id.i);
	int locposs = poss;
	if(xx==-1){
		if(symbolTable[locposs].def==0){printf("%s = %d ,",(starr->val)->id.i ,symbolTable[locposs].value);}
		else{printf("variable %s not assigned yet  ,",(starr->val)->id.i);}
	}
	else{
		puts("variable not in symbol table ");
		exit(0);
	}
	if(starr->next != NULL)
	{
		starr=starr->next;
	}
	else{
		break;
	}
}
return 0;
case typeId:
//how are you
ab = search(p->id.i);
if(ab==-1)
{
	int locposs=poss;
	if(symbolTable[locposs].def==0)
	{
		printf("%d ",symbolTable[locposs].value);
		return symbolTable[locposs].value;
	}
	else
	{
		puts("variable undefined");
		exit(0);
	}
}
else
{
	puts("variable doesn't exist");
	exit(0);
}
// printf(" (%d ) ",sym[p->id.i]);
// return sym[p->id.i];
case typeCon:
// puts("hello con");
printf("(%d ) ",p->con.value);
return (p->con.value);
case typeOpr:
switch(p->opr.oper) {
	case '=':
	printf("assign ");
	int aa= search(p->opr.op[0]->id.i);
	if(aa==-1)
	{		
			int locposs = poss;
			printf("%s = ",symbolTable[locposs].id_name);
			symbolTable[locposs].value = ex(p->opr.op[1]);
			symbolTable[locposs].def=0;
	}
	else
	{
		puts("variable doesn't exist");
		exit(0);
	}
	return 0;
	// printf("%d ",p->opr.op[0]->id.i);
	// sym[p->opr.op[0]->id.i] = ex(p->opr.op[1]);
	// return sym[p->opr.op[0]->id.i] ;
	case UMINUS:
	printf("uminus ");
	return -ex(p->opr.op[0] );
	case '+':
	printf("add ");
	return ex(p->opr.op[0] ) + ex(p->opr.op[1] );
	case '-':
	printf("subt ");
	return ex(p->opr.op[0] ) - ex(p->opr.op[1] );
	case '*':
	printf("multiply ");
	return ex(p->opr.op[0] ) * ex(p->opr.op[1] );
	case '/':
	printf("divide ");
	return ex(p->opr.op[0] ) / ex(p->opr.op[1] );
	}
}
return 0;
}

int search(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbolTable[i].id_name, type)==0) {
            poss=i;
			return -1;
			break;
		}
	}
	return 0;
}

void add(char * name)
{
    int x = search(name);
    if(x==0){
    if(count<40)
    {
            symbolTable[count].id_name=strdup(name);
			symbolTable[count].data_type=strdup("int");
            symbolTable[count].value=-1;
            symbolTable[count].def=-1;
            count++;
    }
    else{
        puts("memory space overflowed because of variable");
    }
    }
    else
    {
        puts("error : variable already declared ");
        exit(0);
    }
}
/////////////////////////////////

void displayinorder(struct tree *root)
{
	if (root!=NULL)
	{
		displayinorder(root->left);
		if (root->nval !=-1)
			printf("%d ",root->nval);
		else if (root->nop !='\0')
			printf("%c ",root->nop);
		else if(!strcmp(root->type,"dummy"))
			printf("dummy ");
		else if(!strcmp(root->type,"if"))
			{printf("if ");displayinorder(root->middle);}
		else if(!strcmp(root->type,"=="))
			printf("== ");
		else if(!strcmp(root->type,"<="))
			printf("<= ");
		else if(!strcmp(root->type,">="))
			printf(">= ");
		else if(!strcmp(root->type,"<"))
			printf("< ");
		else if(!strcmp(root->type,">"))
			printf("> ");
		else if(!strcmp(root->type,"variable"))
			printf("%c",root->name);
		else if(!strcmp(root->type,"read"))
			printf("read ");
		else if(!strcmp(root->type,"write"))
			printf("write ");
		else if(!strcmp(root->type,"while"))
			{printf("while ");}	
		displayinorder(root->right);
	}
}
int evaluation(struct tree *root)
{
	
	if(root->nop=='=')
	{
		char k=(root->left)->name;
		sym[k-'a']=evaluation(root->right);
		//printf("%c=",k);
		return sym[k-'a'];
	}
	else if(root->name!='\0')
	{
	  	return sym[root->name - 'a'];	
	}	
	else
	{
	if(root->nval!=-1)
		return root->nval;
	else if(root->nop=='+')
		return ( evaluation(root->left) + evaluation(root->right) );
	else if (root->nop=='*')
		return ( evaluation(root->left) * evaluation(root->right) );
	else if(strcmp(root->type,"==")==0)
		return ( evaluation(root->left) == evaluation(root->right) );
	else if(strcmp(root->type,">=")==0)
		return ( evaluation(root->left) >= evaluation(root->right) );
	else if(strcmp(root->type,"<=")==0)
		return ( evaluation(root->left) <= evaluation(root->right) );
	else if(strcmp(root->type,">")==0)
		return ( evaluation(root->left) > evaluation(root->right) );
	else if(strcmp(root->type,"<")==0)
		return ( evaluation(root->left) < evaluation(root->right) );
	}

}
int is_left(struct tree* node)
{
	if (node->left!=NULL)
		return 1;
	else
		return 0;
}
int is_right(struct tree* node)
{
	if (node->right!=NULL)
		return 1;
	else
		return 0;
}
int is_dummy(struct tree* node)
{
	if(strcmp(node->type,"dummy")==0)
		return 1;
	else
		return 0;
}
struct tree* dummyalloc()
{
	struct tree *hi=(struct tree*) malloc(sizeof(struct tree));
	strcpy(hi->type,"dummy");
	hi->name='\0';
	hi->nval=-1;
	hi->nop='\0';
	hi->left=NULL;
	hi->right=NULL;
	hi->middle=NULL;
	return hi;
}
void neweval(struct tree *node)
{
	if(node!=NULL)
	{
	if(is_dummy(node))
	{
		neweval(node->left);
		neweval(node->right);
	}
	
	else if(node->nop=='=')
	{
		int k=evaluation(node);//printf("%d\n",evaluation(node));
	}
	else if(strcmp(node->type,"read")==0)
	{
	   printf("Enter value of %c",node->name);
	   scanf("%d",&sym[node->name-'a']);
	 }
	else if(strcmp(node->type,"write")==0)
	{
		printf("%d\n",evaluation(node->left));
	}
	else if(strcmp(node->type,"if")==0)
	{
		int k=evaluation(node->left);
		if(k!=0)
			 neweval(node->middle);
		else if(node->right != NULL)
			 neweval(node->right);
	}
	else if(strcmp(node->type,"while")==0)
	{
		int k=evaluation(node->left);
		while(k)
		{
		neweval(node->right);
		k=evaluation(node->left);
		}
		
	}
	}
}
