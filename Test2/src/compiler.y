/*
 *   This file is part of SIL Compiler.
 *
 *  SIL Compiler is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Softwar    e Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  SIL Compiler is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with SIL Compiler.  If not, see <http://www.gnu.org/licenses/>.
 */

%{	
	#include <stdio.h>
	#include "../include/AbsSynTree.h"
	#include<string.h>
	//#define YYSTYPE double
	int yylex();
	void yyerror( char* );
        int i;	
        int cnt=0;
		 struct arrtype* cratfirst(char *s);//
		 struct arrtype* crat(struct arrtype * ar,int n);//
		 struct glis * arcrgli(struct arrtype *ar);//
		void joinglis(struct glis * hd,struct glis * nw);//
		void joingdec(struct glis * nw,int ty);//50
	
		struct varlis *crvhead(char *s);
		void joinv(struct varlis*head,char *s);
		struct nptlist * nphd;
		struct gdec * headgd;
		struct nptlist * crhnpt();

		struct nptstmt * sts(stmtp vale,struct nptstmt *f,struct nptlist* ff,struct nptlist *ss,int nu,struct varlis*vv,char *se);

		struct nptstmt * exprs(struct nptstmt* left,struct nptstmt* right,operat valu,stmtp vale);

		void joinnpt(struct nptlist *head,struct nptstmt *sm);
		struct nptstmt* ttt;
		struct symtab{
			char * nam;
		int tp;
		int *val;
		int size;//0 for variable

		}smt[50];
		int symcnt;
		int sfind(char *s);
		void sinsert(struct arrtype *temp,int typ);
		
		void executegd();

		void synprint(int type,struct nptlist *li,struct nptstmt * sta);
		void stupdate(char * s,int n,int v);
		int stval(char * s,int n);
		void prinvlis(struct varlis *v);
		
		void evprinvlis(struct varlis *v);
		int evaluate(int type,struct nptlist *li,struct nptstmt * sta);
		void stprint();
		int rtty;
%}
%union{
	int iValue;
	char * sindex;
	struct varlis*vl;
	struct arrtype*at;
	struct glis*gl;
	struct nptstmt * npt;
	struct nptlist * nptlis;
	struct gdec*gd;
}
%token BEG END
%token T_INT T_BOOL
%token WRITE
%token DECL ENDDECL
%token <iValue> NUM
%token <sindex> VAR 
%token IF THEN ELSE ENDIF
%token LOGICAL_AND LOGICAL_NOT LOGICAL_OR
%token EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%token WHILE DO ENDWHILE FOR 
%token T F 
%token MAIN RETURN


%left '<' '>'
%left EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%left '+' '-'
%left '*' '/'
%left '%'
%left LOGICAL_AND LOGICAL_OR
%left LOGICAL_NOT
%type<iValue> ret_type func_ret_type
%type<at> Gid
%type<gl> Glist 
%type<gd> Gdecl 
%type<npt> statement assign_stmt write_stmt cond_stmt var_expr expr
%type<nptlis> stmt_list
%type<vl> str_expr
%%
	Prog	:	Gdecl_sec MainBlock {/*final execution done from here*/}
		;
		
	Gdecl_sec:	DECL Gdecl_list ENDDECL{/*this will itself be a linked list */}
		;
		
	Gdecl_list: 
		| 	Gdecl Gdecl_list {/*start node will be attatched to linked list  here*/}
		;
		
	Gdecl 	:	ret_type Glist ';'  {joingdec($2,$1);/*create head for this linked list here .*/}
		;
		
	ret_type:	T_INT		{ $$=1;/*make rrty gb var as 1 , so that we know this waas int */} //push 1
		|	T_BOOL 		{ $$=0;}
		;
		
	Glist 	:	Gid	{$$=arcrgli($1);/*puts("end");*//*attach this to glist*/}//first
		|	Glist ',' Gid {joinglis($1,arcrgli($3));$$=$1;/*printf("%d ",cnt++);*/}	//
		;
	
	Gid	:	VAR		{ $$=cratfirst($1);/*keep counting the num if 0 then var else array .*/}
		|	Gid '[' NUM ']'	{         $$=crat($1,$3);                 }

		;
		
	ret_stmt:	RETURN expr ';'	{ 					}
		;
			
	MainBlock: 	func_ret_type main '('')''{' BEG stmt_list ret_stmt END  '}'		{ 	nphd=$7;rtty=$1;			  	  }
		;
	func_ret_type:	T_INT		{ $$=1;/*make rrty gb var as 1 , so that we know this waas int */} //push 1
	|	T_BOOL 		{ $$=0;}
	;
		
		
	main	:	MAIN		{ 					}
		;
		

				

	stmt_list:	/* NULL */		{$$=(struct nptlist *)malloc(sizeof(struct nptlist)); /*puts("first");*/ }
		|	stmt_list statement	{ joinnpt($1,$2);$$=$1;/*puts("lst")*/;						}
		;

	statement:	assign_stmt  ';'		{ 	$$=$1;/*puts("ass");*/						 }
		|	write_stmt ';'		{ $$=$1;/*puts("writte");*/}
		|	cond_stmt 		{ $$=$1;/*puts("condstmt");*/}
		;

		write_stmt:	WRITE '(' expr ')' 	{$$=sts(writeexp,$3,NULL,NULL,0,NULL,NULL);  }
		 | WRITE '(''"' str_expr '"'')'      { $$=sts(writestmt,NULL,NULL,NULL,0,$4,NULL);}

		;
	
	assign_stmt:	var_expr '=' expr 	{ 	$$=exprs($1,$3,eqt,assstmt);/*puts("assins");*/					}
		;

	cond_stmt:	IF expr THEN stmt_list ENDIF 	{$$=sts(iff,$2,$4,NULL,0,NULL,NULL); 	/*puts("condstmt");*/}
		|	IF expr THEN stmt_list ELSE stmt_list ENDIF 	{ $$=sts(ifelse,$2,$4,$6,0,NULL,NULL);		}
		|	WHILE expr DO stmt_list ENDWHILE ';'{ $$=sts(whle,$2,$4,NULL,0,NULL,NULL);	 	/*puts("condstmt");*/				}
		;
	
		expr	:	NUM 			{ $$=sts(exp,NULL,NULL,NULL,$1,NULL,NULL)	;	}
		|	'-' NUM			{  		$$=sts(exp,NULL,NULL,NULL,-$2,NULL,NULL)	;				   }
		|	var_expr		{ 	$$=$1;		}
		|	T			{ 		$$=sts(exp,NULL,NULL,NULL,1,NULL,NULL)	;				  	}
		|	F			{ 	$$=sts(exp,NULL,NULL,NULL,0,NULL,NULL)	;}
		|	'(' expr ')'		{  $$=$2;			}

		|	expr '+' expr 		{ $$=exprs($1,$3,plus,exp);	}
		|	expr '-' expr	 	{ 	$$=exprs($1,$3,minus,exp);					}
		|	expr '*' expr 		{ 			$$=exprs($1,$3,multiply,exp);}
		|	expr '/' expr 		{ 		$$=exprs($1,$3,divide,exp);			}
		|	expr '%' expr 		{ 	$$=exprs($1,$3,rem,exp);					}
		|	expr '<' expr		{ 			$$=exprs($1,$3,lt,exp);			}
		|	expr '>' expr		{ 			$$=exprs($1,$3,gt,exp);			}
		|	expr GREATERTHANOREQUAL expr				{ 				$$=exprs($1,$3,gte,exp);		}
		|	expr LESSTHANOREQUAL expr	{  		$$=exprs($1,$3,lte,exp);				}
		|	expr NOTEQUAL expr		{ 		$$=exprs($1,$3,nt,exp);				}
		|	expr EQUALEQUAL expr	{ 		$$=exprs($1,$3,ee,exp);				}
		;
	str_expr :  VAR                       {$$=crvhead($1);}
                  | str_expr VAR   {joinv($1,$2);$$=$1; }
                ;
	
	var_expr:	VAR	{ 	$$=sts(varexa,NULL,NULL,NULL,0,NULL,$1);			  }
		|	var_expr '[' expr ']'	{  ttt=$1;ttt->ifst=$3;$$=$1;                   }
		;
%%
int main()
{
	symcnt=0;
headgd	=(struct gdec *)malloc(sizeof(struct gdec));
headgd->val =NULL;
headgd->next =NULL;
nphd = (struct nptlist *)malloc(sizeof(struct nptlist));
nphd->next=NULL;
yyparse();
puts("printing the tree ");
executegd();
if(rtty){printf("INT MAIN\n\n");}
else{puts("BOOL MAIN\n");}
synprint(1,nphd,NULL);
puts("\n\nevaluating ");
evaluate(1,nphd,NULL);
puts("\n\nprinting symbol table");
stprint();

}
void yyerror(char *s) {
fprintf(stdout, "%s\n", s);
}
struct varlis *crvhead(char *s)
{
	struct varlis *temp = (struct varlis *)malloc(sizeof(struct varlis));
	temp->nam = strdup(s);
	temp->next=NULL;
	return temp;
}
void joinv(struct varlis*head,char *s)
{
	struct varlis *p = (struct varlis *)malloc(sizeof(struct varlis));
	struct varlis*temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=p;
	p->next=NULL;
	p->nam=strdup(s);
}



struct arrtype* cratfirst(char *s)
{
	struct arrtype* temp=(struct arrtype*)malloc(sizeof(struct arrtype));
	temp->nam=strdup(s);
	temp->siz=0;
	return temp;
}


struct arrtype* crat(struct arrtype * ar,int n)
{
	ar->siz=n;
	return ar;
}

struct glis * arcrgli(struct arrtype *ar)
{
	struct glis* temp= (struct glis*)malloc(sizeof(struct glis));
	temp->wh=1;
	temp->nex=NULL;
	temp->at=ar;
	return temp;
}
// struct glis * fucrgli(struct fdecl *ar)
// {
// 	struct glis* temp= (struct glis*)malloc(sizeof(struct glis));
// 	temp->wh=2;
// 	temp->nex=NULL;
// 	temp->fu=ar;
// 	return temp;
// }
void joinglis(struct glis * hd,struct glis * nw)
{
	struct glis * temp=hd;
	while(temp->nex!=NULL)
	{
		temp=temp->nex;
	}
	temp->nex=nw;
	
}

void joingdec(struct glis * nw,int ty)
{
	struct gdec* ins =(struct gdec*)malloc(sizeof(struct gdec));
	struct gdec* temp=headgd;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	ins->val=nw;
	ins->typ=ty;
	ins->next=NULL;
	temp->next=ins;
	
}	


struct nptlist * crhnpt()
{
struct nptlist * temp =( struct nptlist *)malloc(sizeof(struct nptlist ));
temp->next=NULL;
}

struct nptstmt * sts(stmtp vale,struct nptstmt *f,struct nptlist* ff,struct nptlist *ss,int nu,struct varlis*vv,char *se)
{
	struct nptstmt * temp= (struct nptstmt *)malloc(sizeof(struct nptstmt));
	temp->wt=vale;
	switch (vale)
	{
	case ifelse/* constant-expression */:
		/* code */
		temp->wt=vale;
		temp->ifst=f;
		temp->ifl=ff;
		temp->elst=ss;
		break;
	case iff:
		temp->wt=vale;
		temp->ifst=f;
		temp->ifl=ff;
		break;
	case whle:
		temp->ifst=f;
		temp->ifl=ff;
		break;
	case writestmt:
		temp->vl=vv;
		break;
	case varexa:
		temp->s=se;
		temp->num=nu;
		break;
	case exp:
		// printf("num was %d\n",nu);
		temp->num=nu;
		// printf("num was %d\n",temp->num);
		temp->op=num;
		break;
	case writeexp:
		temp->ifst=f;
		break;
	default:
		break;
	}
	return temp;
}


struct nptstmt * exprs(struct nptstmt* left,struct nptstmt* right,operat valu,stmtp vale)
{
		struct nptstmt * temp = (struct nptstmt *)malloc(sizeof(struct nptstmt));
		temp->op=valu;
		temp->wt=vale;
		temp->exl=left;
		temp->exr=right;
		return temp;
}


void joinnpt(struct nptlist *head,struct nptstmt *sm)
{

	struct nptlist *p = (struct nptlist *)malloc(sizeof(struct nptlist));
	struct nptlist *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=p;
	temp->val=sm;
	p->next=NULL;
	// p->val=sm;
}
int sfind(char *s)
{
	// puts(s);
	for(int i=0;i<symcnt;i++)
	{
		if(strcmp(smt[i].nam,s)==0)
		{return 0;}
	}
	return 1;
}
void sinsert(struct arrtype *temp,int typ)
{
	// puts(temp->nam);
	if(sfind(temp->nam))
	{
			smt[symcnt].nam=temp->nam;
			if(temp->siz!=0)
			{
				printf("ARR VAR %d",temp->siz);
				smt[symcnt].tp=typ;
				smt[symcnt].size=temp->siz;
				smt[symcnt].val=(int *)malloc((temp->siz)*sizeof(int));
			}
			else
			{
				printf("VAR ");
				smt[symcnt].tp=typ;

				smt[symcnt].size=0;

				smt[symcnt].val=(int *)malloc((1)*sizeof(int));
			}
			symcnt++;
	}
	else
	{
		printf("error: name already exists");
	}
}
void stupdate(char * s,int n,int v)
{int *x;
// puts(s);
int aa=0;
	for(int i=0;i<symcnt;i++)
	{
		if(strcmp(smt[i].nam,s)==0)
		{
			aa=1;
			// printf("%dth,elemnet\n",i);
			if(smt[i].size==0)
			{
				x=smt[i].val;
				*x=v;
				if(!smt[i].tp&&!(v==0||v==1))
				{
					puts("warning : assigning integer value to bool variable");
				}
			}
			else
			{
				x=smt[i].val;
				*(x+n)=v;
				if(!smt[i].tp&&!(v==0||v==1))
				{
					puts("warning : assigning integer value to bool variable");
				}
			}
			return ;
		}
	}
	if(!aa)
	{
		puts("cant update a name that doesnot exist");
	}
}

void stprint()
{
	for(int i=0;i<symcnt;i++)
	{
		if(smt[i].size==0)
		{
				printf("%s = %d\n",smt[i].nam,*(smt[i].val));
		}
		else
		{
				for(int k=0;k<smt[i].size;k++)
				printf("%s [%d] = %d\n",smt[i].nam,k,*(smt[i].val+k));
		}
	}
}
int stval(char * s,int n)
{int *x;
// puts(s);
	for(int i=0;i<symcnt;i++)
	{
		if(strcmp(smt[i].nam,s)==0)
		{
			if(smt[i].size==0)
			{
				x=smt[i].val;
				return *x;
			}
			else
			{
				x=smt[i].val;
				return *(x+n);
			}
		}
	}
	printf("%s this variable doesnot exist1",s);
	return 0;
}
void prinvlis(struct varlis *v)
{
	struct varlis * temp = v;
	while(1)
	{
		printf("VAR ");
		if(temp->next==NULL)
		{
			break;
		}
		temp=temp->next;
	}
}

void evprinvlis(struct varlis *v)
{
	struct varlis * temp = v;
	printf("writing ");
	while(1)
	{
		printf("%d ",stval(temp->nam,0));
		if(temp->next==NULL)
		{
			break;
		}
		temp=temp->next;
	}
}
void executegd()
{
	// puts("hello!");
	struct gdec*temp =headgd;
	temp=temp->next;
	while(temp->val!=NULL)
	{
		
		struct glis * temp2=temp->val;
		printf("DECL ");
		if(temp->typ)
		{
			printf("INT ");
		}
		else
		{
			printf("BOOL ");
		}
		while(1)
		{

			sinsert(temp2->at,temp->typ);
			if(temp2->nex==NULL)
			{

				break;
			}
			printf(",");
			temp2=temp2->nex;
		}
		puts(" ");
		if(temp->next==NULL)
		{
			//puts("reached here");
			break;
		}
		temp=temp->next;
	}
}
void synprint(int type,struct nptlist *li,struct nptstmt * sta)
{
	
	if(type==1)
	{
		// puts("hello");
		// if(li==NULL)
		// {
		// 	puts("NULL");
		// }
		struct nptlist *temp=li;
		while(temp->val!=NULL)
		{
			struct nptstmt *temps=temp->val;
			switch(temps->wt)
			{
				case ifelse:
				printf("IF ")				;
				synprint(2,NULL,temps->ifst);
				puts(" ");
				synprint(1,temps->ifl,NULL);
				printf("ELSE ");
				synprint(1,temps->elst,NULL);
				puts(" ");
				puts("ENDIF ");
				break;
				case iff:
				printf("IF ")				;
				synprint(2,NULL,temps->ifst);
				puts(" ");
				synprint(1,temps->ifl,NULL);
				puts(" ");
				puts("ENDIF ");
				break;
				case whle:
				printf("WHILE ");
				synprint(2,NULL,temps->ifst);
				puts(" ");
				synprint(1,temps->ifl,NULL);
				puts("ENDWHILE ");
				break;
				case assstmt:
				printf("ASSIGN ");
				synprint(2,NULL,temps->exl);
				synprint(2,NULL,temps->exr);
				puts(" ");
				break;
				case writestmt:
				printf("FUNCALL ");
				prinvlis(temps->vl);
				break;
				case writeexp:
				printf("FUNCALL ");
				synprint(2,NULL,temps->ifst);
				puts(" ");
				break;
				case exp:
					switch(temps->op)
					{
						case plus:
						printf("PLUS ");
						break;
						case minus:
						printf("MINUS ");
						break;
						case multiply:
						printf("MULTIPLY ");
						break;
						case divide:
						printf("DIVIDE ");
						break;
						case rem:
						printf("REMAINDER ");
						break;
						case gt:
						printf("GREATERTHAN ");
						break;
						case lt:
						printf("LESSTHAN ");
						break;
						case gte:
						printf("GREATERTHANEQUAL ");
						break;
						case lte:
						printf("LESSTHANEQUAL ");
						break;
						case ee:
						printf("EQUALEQUAL ");
						break;
						case nt:
						printf("NOTEQUALTO ");
						break;
						case num:
						printf("NUM ");
						break;
					}
					if(temps->op!=num)
					{
						synprint(2,NULL,temps->exl);
						synprint(2,NULL,temps->exr);
					}
					puts(" ");
					break;
					case varexa:
					if(temps->ifst==NULL)
					{printf("VAR ");}
					else
					{
						printf("ARREF VAR NUM");
					}
					break;
			}
			if(temp->next!=NULL) {
				temp=temp->next;
			}
			else
			{break;}
		}
	}
	else
	{
		struct nptstmt *temps=sta;
			switch(temps->wt)
			{
				case ifelse:
				printf("IF ")				;
				synprint(2,NULL,temps->ifst);
				puts(" ");
				synprint(1,temps->ifl,NULL);
				printf("ELSE ");
				synprint(1,temps->elst,NULL);
				puts(" ");
				break;
				case iff:
				printf("IF ")				;
				synprint(2,NULL,temps->ifst);
				puts(" ");
				synprint(1,temps->ifl,NULL);
				puts(" ");
				break;
				case whle:
				printf("WHILE ");
				synprint(2,NULL,temps->ifst);
				puts(" ");
				synprint(1,temps->ifl,NULL);
				break;
				case assstmt:
				printf("ASSIGN ");
				synprint(2,NULL,temps->exl);
				synprint(2,NULL,temps->exr);
				puts(" ");
				break;
				case writestmt:
				printf("FUNCALL ");
				prinvlis(temps->vl);
				break;
				case writeexp:
				printf("FUNCALL ");
				synprint(2,NULL,temps->ifst);
				puts(" ");
				break;
				case exp:
					switch(temps->op)
					{
						case plus:
						printf("PLUS ");
						break;
						case minus:
						printf("MINUS ");
						break;
						case multiply:
						printf("MULTIPLY ");
						break;
						case divide:
						printf("DIVIDE ");
						break;
						case rem:
						printf("REMAINDER ");
						break;
						case gt:
						printf("GREATERTHAN ");
						break;
						case lt:
						printf("LESSTHAN ");
						break;
						case gte:
						printf("GREATERTHANEQUAL ");
						break;
						case lte:
						printf("LESSTHANEQUAL ");
						break;
						case ee:
						printf("EQUALEQUAL ");
						break;
						case nt:
						printf("NOTEQUALTO ");
						break;
						case num:
						printf("NUM ");
						break;
					}
					if(temps->op!=num)
					{
						synprint(2,NULL,temps->exl);
						synprint(2,NULL,temps->exr);
					}
					puts(" ");
					break;
					case varexa:
					if(temps->ifst==NULL)
					{printf("VAR ");}
					else
					{
						printf("ARREF VAR ");
						synprint(2,NULL,temps->ifst);
					}
					break;
			}
	}
}

int evaluate(int type,struct nptlist *li,struct nptstmt * sta)
{
	// puts("HELLO EVALUATING")	;
	if(type==1)
	{
		// puts("hello");
		// if(li==NULL)
		// {
		// 	puts("NULL");
		// }
		struct nptlist *temp=li;
		while(temp->val!=NULL)
		{
			struct nptstmt *temps=temp->val;
			switch(temps->wt)
			{
				case ifelse:
				// printf("IF ")				;
				if(evaluate(2,NULL,temps->ifst))
				{
				evaluate(1,temps->ifl,NULL);
				}
				else{evaluate(1,temps->elst,NULL);}
				// return 0;
				break;
				case iff:
				if(evaluate(2,NULL,temps->ifst))
				{
				evaluate(1,temps->ifl,NULL);
				}
				// return 0;
				break;
				case whle:
				
				// printf("WHILE ");
				while(evaluate(2,NULL,temps->ifst))
				{
					// puts("inwhile");

				evaluate(1,temps->ifl,NULL);
				}	
				// return 0;
				break;
				case assstmt:
				// printf("ASSIGN ");
				// synprint(2,NULL,temps->exl);
					if(temps->exl->ifst==NULL)
					{  
						// puts("assigning var");
						  stupdate(temps->exl->s,0,evaluate(2,NULL,temps->exr));
						// return 0;
						}
					else
					{
						stupdate(temps->exl->s,evaluate(2,NULL,temps->exl->ifst),evaluate(2,NULL,temps->exr));
						// return 0;
						}
				// synprint(2,NULL,temps->exr);
				break;
				case writestmt:
				// printf("FUNCALL ");
				evprinvlis(temps->vl);
				// return 0;
				// prinvlis(temps->vl);
				break;
				case writeexp:
				// printf("FUNCALL ");
				printf("writing %d\n",evaluate(2,NULL,temps->ifst));
				// return 0;
				break;
				case exp:
					switch(temps->op)
					{
						case plus:
						// printf("PLUS ");
						return (evaluate(2,NULL,temps->exl)+evaluate(2,NULL,temps->exr));
						break;
						case minus:
						// npnrintf("MINUS ");
						return (evaluate(2,NULL,temps->exl)-evaluate(2,NULL,temps->exr));
						break;
						case multiply:
						
						// printf("MULTIPLY ");
						return (evaluate(2,NULL,temps->exl)*evaluate(2,NULL,temps->exr));
						break;
						case divide:
						// printf("DIVIDE ");
						return (evaluate(2,NULL,temps->exl)/evaluate(2,NULL,temps->exr));
						break;
						case rem:
                        return (evaluate(2,NULL,temps->exl)%evaluate(2,NULL,temps->exr));
						// printf("REMAINDER ");
						break;
						case gt:
						// printf("GREATERTHAN ");
						return (evaluate(2,NULL,temps->exl)>evaluate(2,NULL,temps->exr))?1:0;
						break;
						case lt:
                        return (evaluate(2,NULL,temps->exl)<evaluate(2,NULL,temps->exr))?1:0;
						// printf("LESSTHAN ");
						break;
						case gte:
						// printf("GREATERTHANEQUAL ");
						return (evaluate(2,NULL,temps->exl)<=evaluate(2,NULL,temps->exr))?1:0;
						break;
						case lte:
						// printf("LESSTHANEQUAL ");
						return (evaluate(2,NULL,temps->exl)>=evaluate(2,NULL,temps->exr))?1:0;
						break;
						case ee:
						// printf("EQUALEQUAL ");
						return (evaluate(2,NULL,temps->exl)==evaluate(2,NULL,temps->exr))?1:0;
						break;
						case nt:
						// printf("NOTEQUALTO ");
						return (evaluate(2,NULL,temps->exl)!=evaluate(2,NULL,temps->exr))?1:0;
						break;
						case num:
						// printf("NUM ");
						return temps->num;
						break;
					}
					// if(temps->op!=num)
					// {
					// 	synprint(2,NULL,temps->exl);
					// 	synprint(2,NULL,temps->exr);
					// }
					break;
					case varexa:
					if(temps->ifst==NULL)
					{return stval(temps->s,0);}
					else
					{
						// synprint(2,NULL,temps->ifst);
						return stval(temps->s,evaluate(2,NULL,temps->ifst));
					}
					break;
			}

			if(temp->next!=NULL) {
				// puts("next temp");
				temp=temp->next;
			}
			else
			{break;}
		}
		return 0;
	}
	else
	{
		struct nptstmt *temps=sta;
			switch(temps->wt)
			{
				case ifelse:
				// printf("IF ")				;
				if(evaluate(2,NULL,temps->ifst))
				{
				evaluate(1,temps->ifl,NULL);
				}
				else{evaluate(1,temps->elst,NULL);}
				return 0;
				break;
				case iff:
				if(evaluate(2,NULL,temps->ifst))
				{
				evaluate(1,temps->ifl,NULL);
				}
				return 0;
				break;
				case whle:
				// printf("WHILE ");
				while(evaluate(2,NULL,temps->ifst))
				{
					// puts("inwhile");

				evaluate(1,temps->ifl,NULL);
				}	
				return 0;
				break;
				case assstmt:
				// printf("ASSIGN ");
				// synprint(2,NULL,temps->exl);
					if(temps->exl->ifst==NULL)
					{  
						// puts("assigning var");
						  stupdate(temps->exl->s,0,evaluate(2,NULL,temps->exr));
						return 0;}
					else
					{
						stupdate(temps->exl->s,evaluate(2,NULL,temps->exl->ifst),evaluate(2,NULL,temps->exr));
						return 0;}
				// synprint(2,NULL,temps->exr);
				break;
				case writestmt:
				// printf("FUNCALL ");
				evprinvlis(temps->vl);
				return 0;
				// prinvlis(temps->vl);
				break;
				case writeexp:
				// printf("FUNCALL ");
				printf("writing %d\n",evaluate(2,NULL,temps->ifst));
				return 0;
				break;
				case exp:
					switch(temps->op)
					{
						case plus:
						// printf("PLUS ");
						return (evaluate(2,NULL,temps->exl)+evaluate(2,NULL,temps->exr));
						break;
						case minus:
						// npnrintf("MINUS ");
						return (evaluate(2,NULL,temps->exl)-evaluate(2,NULL,temps->exr));
						break;
						case multiply:
						
						// printf("MULTIPLY ");
						return (evaluate(2,NULL,temps->exl)*evaluate(2,NULL,temps->exr));
						break;
						case divide:
						// printf("DIVIDE ");
						return (evaluate(2,NULL,temps->exl)/evaluate(2,NULL,temps->exr));
						break;
						case rem:
                        return (evaluate(2,NULL,temps->exl)%evaluate(2,NULL,temps->exr));
						// printf("REMAINDER ");
						break;
						case gt:
						// printf("GREATERTHAN ");
						return (evaluate(2,NULL,temps->exl)>evaluate(2,NULL,temps->exr))?1:0;
						break;
						case lt:
                        return (evaluate(2,NULL,temps->exl)<evaluate(2,NULL,temps->exr))?1:0;
						// printf("LESSTHAN ");
						break;
						case gte:
						// printf("GREATERTHANEQUAL ");
						return (evaluate(2,NULL,temps->exl)<=evaluate(2,NULL,temps->exr))?1:0;
						break;
						case lte:
						// printf("LESSTHANEQUAL ");
						return (evaluate(2,NULL,temps->exl)>=evaluate(2,NULL,temps->exr))?1:0;
						break;
						case ee:
						// printf("EQUALEQUAL ");
						return (evaluate(2,NULL,temps->exl)==evaluate(2,NULL,temps->exr))?1:0;
						break;
						case nt:
						// printf("NOTEQUALTO ");
						return (evaluate(2,NULL,temps->exl)!=evaluate(2,NULL,temps->exr))?1:0;
						break;
						case num:
						// printf("NUM ");
						// puts("returning num ");
						// if(temps->num==NULL)puts("suddenly NULL");
						// printf("of value %d",temps->num);
						return (temps->num);
						break;
					}
					// if(temps->op!=num)
					// {
					// 	synprint(2,NULL,temps->exl);
					// 	synprint(2,NULL,temps->exr);
					// }
					break;
					case varexa:
					if(temps->ifst==NULL)
					{return stval(temps->s,0);}
					else
					{
						// synprint(2,NULL,temps->ifst);
						return stval(temps->s,evaluate(2,NULL,temps->ifst));
					}
					break;
			}
	}
}
