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
	
		struct glis * fucrgli(struct fdecl *ar);
		struct varlis *crvhead(char *s);
		void joinv(struct varlis*head,char *s);
		struct nptlist * nphd;
		struct gdec * headgd;
		struct nptlist * crhnpt();
		struct funcclist * fhd; 
		struct nptstmt * sts(stmtp vale,struct nptstmt *f,struct nptlist* ff,struct nptlist *ss,int nu,struct varlis*vv,char *se);

		struct nptstmt * exprs(struct nptstmt* left,struct nptstmt* right,operat valu,stmtp vale);

		struct funcc* crfu(struct gdec *g,struct nptlist *n,struct nptstmt *e,int tp,struct arglis *a,char *s);
		void joinfuncc(struct funcclist * hd,struct funcc * node);
		void joinnpt(struct nptlist *head,struct nptstmt *sm);
		struct nptstmt* ttt;
		struct fdecl* crheadf(struct arglis * a,char *s);

		void joinar(struct arglis*head,struct arglis*p);
		struct gdec* mld;

		struct arglis*crahead(int typ,struct varlis*head);
		struct symtab{
			char * nam;
		int tp;
		
		int *val;
		int size;//0 for variable

		}smt[50];
		int symcnt;
		int sfind(char *s);
		void sinsert(struct arrtype *temp,int typ);
		
		void eprinvlis(struct varlis *v);
		void eprinf();
		void executegd();

		void esynprint(int type,struct nptlist *li,struct nptstmt * sta);
		void synprint(int type,struct nptlist *li,struct nptstmt * sta);
		struct nptstmt * fsts(struct nptstmt *a,struct nptlist * b,struct nptstmt * c,struct nptstmt *d);
		void stupdate(char * s,int n,int v);
		int stval(char * s,int n);
		void prinvlis(struct varlis *v);
		
		void evprinvlis(struct varlis *v);
		int evaluate(int type,struct nptlist *li,struct nptstmt * sta);
		void stprint();
		int rtty;
		void eexecutegd(struct gdec * haad);
		struct nptstmt * mainrt;
		void prinf();
%}
%union{
	int iValue;
	char * sindex;
	struct varlis*vl;
	struct arrtype*at;
	struct glis*gl;
	struct nptstmt * npt;
		struct fdecl*fl;
	struct nptlist * nptlis;
	struct gdec*gd;
		struct arglis*al;
		struct funcclist * fnl;
		struct funcc * fn;
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
%type<iValue> ret_type func_ret_type arg_type type ffunc_ret_type
%type<sindex> func_name 
%type<at> Gid Lid
%type<gl> Glist Lid_list
%type<fl> func 
%type<gd> Gdecl Ldecl Ldecl_list Ldecl_sec
%type<npt> statement assign_stmt write_stmt cond_stmt var_expr expr ret_stmt func_call func_stmt
%type<nptlis> stmt_list para param_list param_list1
%type<vl> str_expr var_list
%type<al> arg arg_list arg_list1 FargList
%type<fn> Fdef
%%
	Prog	:	Gdecl_sec Fdef_sec MainBlock {/*final execution done from here*/}
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
		| func {$$=fucrgli($1);}
		|	Glist ',' Gid {joinglis($1,arcrgli($3));$$=$1;/*printf("%d ",cnt++);*/}	//
		|   Glist ',' func {joinglis($1,fucrgli($3));$$=$1;}
		;
			
	func 	:	VAR '(' arg_list ')' 	{ $$=crheadf($3,$1);/*create node and push to stack */}
		;
			
	arg_list:	{$$=NULL;}
		|	arg_list1  {$$=$1;}
		;
		
	arg_list1:	arg_list1 ';' arg	{joinar($1,$3);$$=$1;}//join
		|	arg			{$$=$1;}//first head
		;
		
	arg 	:	arg_type var_list	{$$=crahead($1,$2);}//create and pass
		;
		
	arg_type:	T_INT		 {$$=1;  }//push 1
		|	T_BOOL 		 { $$=0;}
		;

	var_list:	VAR 		 {$$=crvhead($1); }//first	
		|	VAR ',' var_list { joinv($3,$1);$$=$3;}
		;
	Fdef_sec:	
		|	Fdef_sec Fdef	{joinfuncc(fhd,$2);}
		;
		
	Fdef	:	func_ret_type func_name '(' FargList ')' '{' Ldecl_sec BEG stmt_list ret_stmt END '}'	{	 $$=crfu($7,$9,$10,$1,$4,$2);				}
		;
		
	func_ret_type:	T_INT		{$$=1; }
		|	T_BOOL		{ $$=0;}
		;
			
	func_name:	VAR		{ 		$$=$1;			}
		;
		
	FargList:	arg_list	{ 		$$=$1;			}
		;


	Gid	:	VAR		{ $$=cratfirst($1);/*keep counting the num if 0 then var else array .*/}
		|	Gid '[' NUM ']'	{         $$=crat($1,$3);                 }

		;
		
	ret_stmt:	RETURN expr ';'	{ $$=$2;}
		;
			
	MainBlock: 	ffunc_ret_type main '('')''{' Ldecl_sec BEG stmt_list ret_stmt END  '}'		{ 	mld=$6;nphd=$8;rtty=$1;	mainrt = $9;		  	  }
		;
	ffunc_ret_type:	T_INT		{ $$=1;/*make rrty gb var as 1 , so that we know this waas int */} //push 1
	|	T_BOOL 		{ $$=0;}
	;
		
		
	main	:	MAIN		{ 					}
		;
	
	Ldecl_sec:	DECL Ldecl_list ENDDECL	{$$=$2;}
		;

	Ldecl_list:	{$$=NULL;}	
		|	Ldecl Ldecl_list	{

			struct gdec * nw=$1;
			nw->next =$2;
			$$=$1;
		}
		;

	Ldecl	:	type Lid_list ';'		{
        struct gdec * nw=(struct gdec *)malloc(sizeof(struct gdec));
		nw->typ=$1;
		nw->val=$2;
		nw->next=NULL;
		$$=nw;
	}
		;

	type	:	T_INT			{ $$=1;}
		|	T_BOOL			{ $$=0;}
		;

	Lid_list:	Lid	{$$=arcrgli($1);}
		|	Lid_list ',' Lid {joinglis($1,arcrgli($3));$$=$1;}
		;
		
	Lid	:	VAR			{ $$=cratfirst($1);}
		;


				

	stmt_list:	/* NULL */		{$$=(struct nptlist *)malloc(sizeof(struct nptlist)); /*puts("first");*/ }
		|	stmt_list statement	{ joinnpt($1,$2);$$=$1;/*puts("lst")*/;						}
		;

	statement:	assign_stmt  ';'		{ 	$$=$1;/*puts("ass");*/						 }
		|	write_stmt ';'		{ $$=$1;/*puts("writte");*/}
		|	cond_stmt 		{ $$=$1;/*puts("condstmt");*/}
		|	func_stmt ';'		{ }
		;

		write_stmt:	WRITE '(' expr ')' 	{$$=sts(writeexp,$3,NULL,NULL,0,NULL,NULL);  }
		 | WRITE '(''"' str_expr '"'')'      { $$=sts(writestmt,NULL,NULL,NULL,0,$4,NULL);}

		;
	
	assign_stmt:	var_expr '=' expr 	{ 	$$=exprs($1,$3,eqt,assstmt);/*puts("assins");*/					}
		;

	cond_stmt:	IF expr THEN stmt_list ENDIF 	{$$=sts(iff,$2,$4,NULL,0,NULL,NULL); 	/*puts("condstmt");*/}
		|	IF expr THEN stmt_list ELSE stmt_list ENDIF 	{ $$=sts(ifelse,$2,$4,$6,0,NULL,NULL);		}
		|	WHILE expr DO stmt_list ENDWHILE ';'{ $$=sts(whle,$2,$4,NULL,0,NULL,NULL);	 	/*puts("condstmt");*/				}
		|    FOR '(' assign_stmt  ';'  expr ';'  assign_stmt ')' '{' stmt_list '}'  { $$=fsts($3,$10,$5,$7);                                                }
		;
	func_stmt:	func_call 		{ 	$$=$1;					}
		;
		
	func_call:	VAR '(' param_list ')'	{ $$=sts(func,NULL,$3,NULL,0,NULL,$1);						   }
		;
		
	param_list:				{$$=NULL;}
		|	param_list1	{$$=$1;}	
		;
		
	param_list1:	para		{$$=$1;}	
		|	para ',' param_list1	{			struct nptlist * temp =$1;temp->next=$3;$$=temp;}
		;

	para	:	expr			{ 		struct nptlist * temp = (struct nptlist *)malloc(sizeof(struct nptlist));temp->val=$1;temp->next=NULL;$$=temp;		}
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
		|	func_call		{ $$=$1; }
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
mld = (struct gdec*)malloc(sizeof(struct gdec));
headgd	=(struct gdec *)malloc(sizeof(struct gdec));
headgd->val =NULL;
headgd->next =NULL;
nphd = (struct nptlist *)malloc(sizeof(struct nptlist));
nphd->next=NULL;
fhd= (struct funcclist *)malloc(sizeof(struct funcclist));
mainrt=(struct nptstmt *)malloc(sizeof(struct nptstmt));
yyparse();
printf("/*\n");
eexecutegd(headgd);
eprinf();
if(rtty){printf("\nINT MAIN\n\n");}
else{puts("\nBOOL MAIN\n");}
eexecutegd(mld);
esynprint(1,nphd,NULL);
printf("RETURN ");
esynprint(2,NULL,mainrt);
printf("\n*/\n");
puts("#include<stdio.h>");
puts("#include<stdbool.h>");
// puts("printing the tree ");
executegd(headgd);
if(rtty){printf("\nint main(){\n\n");}
else{puts("\nbool main(){\n");}
executegd(mld);
synprint(1,nphd,NULL);
printf("return ");
synprint(2,NULL,mainrt);
printf(";");
printf("\n}\n");
prinf();
// puts("\n\nevaluating ");
// evaluate(1,nphd,NULL);
// puts("\n\nprinting symbol table");
// stprint();

}
void eprinf()
{
	struct funcclist * temp = fhd;
	
	while(1)
	{
		// puts("gaand");

		if(temp->val==NULL)
		{break;}
		struct funcc * tempp = temp->val;

		puts(" ");
		if(tempp->typ==1)
		{
			printf("FUNC INT VAR (");
		}
		else
		{

			printf("FUNC BOOL VAR (");
		}
		if(tempp->arg!=NULL)
		{
			struct arglis * temm = tempp->arg;
						while(1)
						{
							if(temm->typ==1)
							{
								struct varlis* temmm = temm->v;
								printf("INT ");
								while(1)
								{
									printf("VAR,");
									if(temmm->next==NULL)
									{
										break;
									}
									temmm= temmm->next;
								}
							}
							else
							{

								struct varlis* temmm = temm->v;
								printf("BOOL ");
								while(1)
								{
									printf("VAR,");
									if(temmm->next==NULL)
									{
										break;
									}
									temmm= temmm->next;
								}
							}
							if(temm->next==NULL)
							{
								break;
							}
							temm=temm->next;
						}
					
		}
					printf("){\n");

		if(tempp->ld!=NULL)	
		eexecutegd(tempp->ld);
		puts(" ");
		esynprint(1,tempp->nptl,NULL);
		puts(" ");
		printf("RETURN ");
		esynprint(2,NULL,tempp->ex);
		// printf(";\n");
		printf("}\n");

		// if(temp != NULL )
		// {puts("oohno");}
		if(temp->next == NULL)
		{
			// puts("reached here ");
			break;
		}
		temp=temp->next;
	}
}
void prinf()
{
	struct funcclist * temp = fhd;
	
	while(1)
	{
		// puts("gaand");

		if(temp->val==NULL)
		{break;}
		struct funcc * tempp = temp->val;

		puts(" ");
		if(tempp->typ==1)
		{
			printf("int %s(",tempp->nam);
		}
		else
		{

			printf("bool %s(",tempp->nam);
		}
		if(tempp->arg!=NULL)
		{
			struct arglis * temm = tempp->arg;
			while(1)
			{
				if(temm->typ==1)
				{
		 			struct varlis* temmm = temm->v;
					while(1)
					{
						printf("int %s",temmm->nam);
						if(temmm->next==NULL)
						{
							break;
						}
						printf(",");
						temmm= temmm->next;
					}
				}
				else
				{

					struct varlis* temmm = temm->v;
					while(1)
					{
						printf("bool %s",temmm->nam);
						if(temmm->next==NULL)
						{
							break;
						}
						printf(",");
						temmm= temmm->next;
					}
				}
				if(temm->next==NULL)
				{
					break;
				}
				printf(",");
				temm=temm->next;
			}
		}
					printf("){\n");


		if(tempp->ld!=NULL)	
		executegd(tempp->ld);
		puts(" ");
		synprint(1,tempp->nptl,NULL);
		puts(" ");
		printf("return ");
		synprint(2,NULL,tempp->ex);
		printf(";\n");
		printf("}\n");

		// if(temp != NULL )
		// {puts("oohno");}
		if(temp->next == NULL)
		{
			// puts("reached here ");
			break;
		}
		temp=temp->next;
	}
}
struct funcc* crfu(struct gdec *g,struct nptlist *n,struct nptstmt *e,int tp,struct arglis *a,char *s)
{
	struct funcc * temp = (struct funcc* )malloc(sizeof(struct funcc));
	temp->nam=s;
	temp->ld = g;
	temp->ex= e;
	temp->nptl=n;
	temp->typ=tp;
	temp->arg=a;
	return temp;
}
void joinfuncc(struct funcclist * hd,struct funcc * node)
{
	struct funcclist * temp = hd;
	struct funcclist * p = (struct funcclist *) malloc(sizeof(struct funcclist));
	while(1)
	{


		if(temp->next==NULL)
		{
			break;
		}
		temp=temp->next;
	}
	temp->val=node;
	temp->next=p;
	p->next=NULL;
	p->val=NULL;
}
struct arglis*crahead(int typ,struct varlis*head)
{
	struct arglis *temp = (struct arglis *)malloc(sizeof(struct arglis));
	temp->next=NULL;
	temp->typ=typ;
	temp->v=head;
	return temp;
}
void joinar(struct arglis*head,struct arglis*p)
{
	struct arglis *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=p;
}

struct fdecl* crheadf(struct arglis * a,char *s)
{
	struct fdecl* temp =(struct fdecl*)malloc(sizeof(struct fdecl));
	temp->nam=strdup(s);
	temp->arglit=a;
	return temp;
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
struct glis * fucrgli(struct fdecl *ar)
{
	struct glis* temp= (struct glis*)malloc(sizeof(struct glis));
	temp->wh=2;
	temp->nex=NULL;
	temp->fu=ar;
	return temp;
}
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
	temp->typ=ty;
	ins->next=NULL;
	temp->val=nw;
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
	case func:
		temp->ifl=ff;
		temp->s=se;
		break;
	default:
		break;
	}
	return temp;
}

struct nptstmt * fsts(struct nptstmt *a,struct nptlist * b,struct nptstmt * c,struct nptstmt *d)
{
	struct nptstmt * temp = (struct nptstmt * )malloc(sizeof(struct nptstmt));
	temp->wt=forr;
	temp->ifst=a;
	temp->ifl=b;
	temp->exl=c;
	temp->exr=d;
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
void eprinvlis(struct varlis *v)
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

void prinvlis(struct varlis *v)
{
	struct varlis * temp = v;
	while(1)
	{
		printf("%s ",temp->nam);
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
void eexecutegd(struct gdec * haad)
{
	// puts("hello!");
	struct gdec*temp =haad;
	// temp=temp->next;
	while(temp->val!=NULL)
	{
		
		struct glis * temp2=temp->val;
		// printf("DECL ");
		printf("\nDECL ");
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
			if(temp2->wh==1)
			{
						
			// sinsert(temp2->at,temp->typ);
			if(temp2->at->siz)
			printf("ARR VAR %d,",temp2->at->siz);
			else
			printf("VAR ,");
			}
			else if (temp2->wh==2)
			{
					printf("FUNC VAR(");
					if(temp2->fu->arglit!=NULL)
					{
						struct arglis * temm = temp2->fu->arglit;
						while(1)
						{
							if(temm->typ==1)
							{
								struct varlis* temmm = temm->v;
								printf("INT ");
								while(1)
								{
									printf("VAR,");
									if(temmm->next==NULL)
									{
										break;
									}
									temmm= temmm->next;
								}
							}
							else
							{

								struct varlis* temmm = temm->v;
								printf("BOOL ");
								while(1)
								{
									printf("VAR,");
									if(temmm->next==NULL)
									{
										break;
									}
									temmm= temmm->next;
								}
							}
							if(temm->next==NULL)
							{
								break;
							}
							temm=temm->next;
						}
					}
					printf("),");

			}

			if(temp2->nex==NULL)
			{

				break;
			}
			temp2=temp2->nex;
		}
		if(temp->next==NULL)
		{
			//puts("reached here");
			break;
		}
		temp=temp->next;
	}
}
void executegd(struct gdec * haad)
{
	// puts("hello!");
	struct gdec*temp =haad;
	// temp=temp->next;
	while(temp->val!=NULL)
	{
		
		struct glis * temp2=temp->val;
		// printf("DECL ");
		while(1)
		{
			if(temp2->wh==1)
			{
						
			if(temp->typ)
			{
			printf("int ");
			}
			else
			{
			printf("bool ");
			}
			// sinsert(temp2->at,temp->typ);
			if(temp2->at->siz)
			printf("%s [%d]",temp2->at->nam,temp2->at->siz);
			else
			printf("%s",temp2->at->nam);
			printf(";\n");
			}
			else if (temp2->wh==2)
			{
			if(temp->typ)
			{
				printf("int ");
			}
			else
			{
				printf("bool ");
			}
					printf("%s(",temp2->fu->nam);
					if(temp2->fu->arglit!=NULL)
					{
						struct arglis * temm = temp2->fu->arglit;
						while(1)
						{
							if(temm->typ==1)
							{
								struct varlis* temmm = temm->v;
								while(1)
								{
									printf("int %s",temmm->nam);
									if(temmm->next==NULL)
									{
										break;
									}
									printf(",");
									temmm= temmm->next;
								}
							}
							else
							{

								struct varlis* temmm = temm->v;
								while(1)
								{
									printf("bool %s",temmm->nam);
									if(temmm->next==NULL)
									{
										break;
									}
									printf(",");
									temmm= temmm->next;
								}
							}
							if(temm->next==NULL)
							{
								break;
							}
							printf(",");
							temm=temm->next;
						}
					}
					printf(");\n");

			}

			if(temp2->nex==NULL)
			{

				break;
			}
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
void esynprint(int type,struct nptlist *li,struct nptstmt * sta)
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
				printf("IF")				;
				esynprint(2,NULL,temps->ifst);
				puts(" ")	;
				esynprint(1,temps->ifl,NULL);

				printf("ELSE ");
				esynprint(1,temps->elst,NULL);
				// puts("ENDIF ");
				break;
				case iff:
				printf("IF")				;
				esynprint(2,NULL,temps->ifst);
				puts(" ")	;
				esynprint(1,temps->ifl,NULL);

				break;
				case whle:
				printf("WHILE ");
				esynprint(2,NULL,temps->ifst);
				puts(" ");
				esynprint(1,temps->ifl,NULL);
				puts("ENDWHILE ");
				break;
				case assstmt:
				printf("ASSIGN ");
				esynprint(2,NULL,temps->exl);
				printf(" = ");
				esynprint(2,NULL,temps->exr);
				// puts(" ");
				break;
				case writestmt:
				printf("FUNCALL  ");
				eprinvlis(temps->vl);
				// printf(" \")\n");
				puts("");
				break;
				case writeexp:
				printf("FUNCALL (\"");putchar('%');printf("d\", ");
				esynprint(2,NULL,temps->ifst);
				printf(") \n");
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
					case func:
					printf("FUNCALL (");
					struct nptlist * tnp = temps->ifl;

					while(tnp!=NULL)
					{
						esynprint(2,NULL,tnp->val);
						tnp=tnp->next;
						if(tnp!=NULL){printf(",");}
					}
					printf(")");
					break;
					case forr:
					printf("FOR (");
					if(temps->ifst)
					esynprint(2,NULL,temps->ifst);
					printf(";");
					if(temps->exl)
					esynprint(2,NULL,temps->exl);
					printf(";");
					if(temps->exr)
					esynprint(2,NULL,temps->exr);
					printf("){\n");
					if(temps->ifl)
					esynprint(1,temps->ifl,NULL);
					printf("\n}");

					break;
			}
			// printf(";\n");
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
				printf("IF")				;
				esynprint(2,NULL,temps->ifst);
				puts(" ")	;
				esynprint(1,temps->ifl,NULL);

				printf("ELSE ");
				esynprint(1,temps->elst,NULL);
				// puts("ENDIF ");
				break;
				case iff:
				printf("IF")				;
				esynprint(2,NULL,temps->ifst);
				puts(" ")	;
				esynprint(1,temps->ifl,NULL);

				break;
				case whle:
				printf("WHILE ");
				esynprint(2,NULL,temps->ifst);
				puts(" ");
				esynprint(1,temps->ifl,NULL);
				puts("ENDWHILE ");
				break;
				case assstmt:
				printf("ASSIGN ");
				esynprint(2,NULL,temps->exl);
				printf(" = ");
				esynprint(2,NULL,temps->exr);
				// puts(" ");
				break;
				case writestmt:
				printf("FUNCALL  ");
				eprinvlis(temps->vl);
				// printf(" \")\n");
				puts("");
				break;
				case writeexp:
				printf("FUNCALL (\"");putchar('%');printf("d\", ");
				esynprint(2,NULL,temps->ifst);
				printf(") \n");
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
					case func:
					printf("FUNCALL (");
					struct nptlist * tnp = temps->ifl;

					while(tnp!=NULL)
					{
						esynprint(2,NULL,tnp->val);
						tnp=tnp->next;
						if(tnp!=NULL){printf(",");}
					}
					printf(")");
					break;
					case forr:
					printf("FOR (");
					if(temps->ifst)
					esynprint(2,NULL,temps->ifst);
					printf(";");
					if(temps->exl)
					esynprint(2,NULL,temps->exl);
					printf(";");
					if(temps->exr)
					esynprint(2,NULL,temps->exr);
					printf("){\n");
					if(temps->ifl)
					esynprint(1,temps->ifl,NULL);
					printf("\n}");

					break;
			}
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
				printf("if(")				;
				synprint(2,NULL,temps->ifst);
				
				puts("){ ");
				synprint(1,temps->ifl,NULL);

				puts(";}");
				printf("else{ ");
				synprint(1,temps->elst,NULL);
				puts(";} ");
				// puts("ENDIF ");
				break;
				case iff:
				printf("if(")				;
				synprint(2,NULL,temps->ifst);
				
				puts("){ ");
				synprint(1,temps->ifl,NULL);

				puts(";}");
				break;
				case whle:
				printf("while( ");
				synprint(2,NULL,temps->ifst);
				puts("){ ");
				synprint(1,temps->ifl,NULL);
				puts(";} ");
				break;
				case assstmt:
				// printf("ASSIGN ");
				synprint(2,NULL,temps->exl);
				printf(" = ");
				synprint(2,NULL,temps->exr);
				// puts(" ");
				break;
				case writestmt:
				printf("printf(\" ");
				prinvlis(temps->vl);
				printf(" \")\n");
				break;
				case writeexp:
				printf("printf(\"");putchar('%');printf("d\", ");
				synprint(2,NULL,temps->ifst);
				printf(") ");
				break;
				case exp:
					if(temps->op!=num)
					{
						synprint(2,NULL,temps->exl);
						switch(temps->op)
						{
							case plus:
							printf("+ ");
							break;
							case minus:
							printf("- ");
							break;
							case multiply:
							printf("* ");
							break;
							case divide:
							printf("/ ");
							break;
							case rem:
							putchar('%');putchar(' ');
							break;
							case gt:
							printf("> ");
							break;
							case lt:
							printf("< ");
							break;
							case gte:
							printf(">= ");
							break;
							case lte:
							printf("<= ");
							break;
							case ee:
							printf("== ");
							break;
							case nt:
							printf("!= ");
							break;
							case num:
							printf("NUM ");
							break;
						}
						synprint(2,NULL,temps->exr);
					}
					else{
						printf("%d ",temps->num);
					}
					puts(" ");
					break;
					case varexa:
					if(temps->ifst==NULL)
					{printf("%s ",temps->s);}
					else
					{
						printf("%s[",temps->s);
						synprint(2,NULL,temps->ifst);
						printf("]");
					}
					break;
					case func:
					printf("%s(",temps->s);
					struct nptlist * tnp = temps->ifl;

					while(tnp!=NULL)
					{
						synprint(2,NULL,tnp->val);
						tnp=tnp->next;
						if(tnp!=NULL){printf(",");}
					}
					printf(")");
					break;
					case forr:
					printf("for(");
					if(temps->ifst)
					synprint(2,NULL,temps->ifst);
					printf(";");
					if(temps->exl)
					synprint(2,NULL,temps->exl);
					printf(";");
					if(temps->exr)
					synprint(2,NULL,temps->exr);
					printf("){\n");
					if(temps->ifl)
					synprint(1,temps->ifl,NULL);
					printf("\n}");

					break;
			}
			printf(";\n");
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
				printf("if(")				;
				synprint(2,NULL,temps->ifst);
				
				puts("){ ");
				synprint(1,temps->ifl,NULL);

				puts(";}");
				printf("else{ ");
				synprint(1,temps->elst,NULL);
				puts(";} ");
				// puts("ENDIF ");
				break;
				case iff:
				printf("if(")				;
				synprint(2,NULL,temps->ifst);
				
				puts("){ ");
				synprint(1,temps->ifl,NULL);

				puts(";}");
				break;
				case whle:
				printf("while( ");
				synprint(2,NULL,temps->ifst);
				puts("){ ");
				synprint(1,temps->ifl,NULL);
				puts(";} ");
				break;
				case assstmt:
				// printf("ASSIGN ");
				synprint(2,NULL,temps->exl);
				printf(" = ");
				synprint(2,NULL,temps->exr);
				puts(" ");
				break;
				case writestmt:
				printf("printf(\" ");
				prinvlis(temps->vl);
				printf(" \")\n");
				break;
				case writeexp:
				printf("printf(\"");putchar('%');printf("d\", ");
				synprint(2,NULL,temps->ifst);
				puts(") ");
				break;
				case exp:
					if(temps->op!=num)
					{
						synprint(2,NULL,temps->exl);
						switch(temps->op)
						{
							case plus:
							printf("+ ");
							break;
							case minus:
							printf("- ");
							break;
							case multiply:
							printf("* ");
							break;
							case divide:
							printf("/ ");
							break;
							case rem:
							putchar('%');putchar(' ');
							break;
							case gt:
							printf("> ");
							break;
							case lt:
							printf("< ");
							break;
							case gte:
							printf(">= ");
							break;
							case lte:
							printf("<= ");
							break;
							case ee:
							printf("== ");
							break;
							case nt:
							printf("!= ");
							break;
							case num:
							printf("NUM ");
							break;
						}
						synprint(2,NULL,temps->exr);
					}
					else{
						printf("%d ",temps->num);
					}
					puts(" ");
					break;
					case varexa:
					if(temps->ifst==NULL)
					{printf("%s ",temps->s);}
					else
					{
						printf("%s[",temps->s);
						synprint(2,NULL,temps->ifst);
						printf("]");
					}
					break;
					case func:
					printf("%s(",temps->s);
					struct nptlist * tnp = temps->ifl;

					while(tnp!=NULL)
					{
						synprint(2,NULL,tnp->val);
						tnp=tnp->next;
						if(tnp!=NULL){printf(",");}
					}
					printf(")");
					break;
					case forr:
					printf("for(");
					if(temps->ifst)
					synprint(2,NULL,temps->ifst);
					printf(";");
					if(temps->exl)
					synprint(2,NULL,temps->exl);
					printf(";");
					if(temps->exr)
					synprint(2,NULL,temps->exr);
					printf("){\n");
					if(temps->ifl)
					synprint(1,temps->ifl,NULL);
					printf("\n}");

					break;
			}
	}
}
