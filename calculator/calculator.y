%{
#define	YYSTYPE	double 	/* data type of yacc stack */
%}
%token	NUMBER ADD SUB MUL DIV PAROPEN PARCLOSE 
%left	ADD SUB	  /* left associative, same precedence */
%left	MUL DIV	  /* left assoc., higher precedence */
%left	PAROPEN PARCLOSE
%%
list:	/* Parser: Productions */
	| list '\n'
	| list expr '\n'    { printf("\t%.8g\n", $2); }
	;
expr:	  NUMBER	{ $$ = $1; }
	| expr ADD expr	{ $$ = $1 + $3; }
	| expr SUB expr	{ $$ = $1 - $3; }
	| expr MUL expr	{ $$ = $1 * $3; }
	| expr DIV expr	{ $$ = $1 / $3; }
	| PAROPEN expr PARCLOSE	{ $$ = $2; }
	;
%%
	/* end of grammar */

#include <stdio.h>
#include <ctype.h>
char	*progname;	/* for error messages */
int	lineno = 1;

int yywrap()
{
    return 1;
}


main(argc, argv)	
	char *argv[];
{
	progname = argv[0];
	yyparse();
}

/*
yylex()		// lexical analyzer 
{
	int c;

	while ((c=getchar()) == ' ' || c == '\t')
		;
	if (c == EOF)
		return 0;
	if (c == '.' || isdigit(c)) {	// number 
		ungetc(c, stdin);
		scanf("%lf", &yylval);
		return NUMBER;
	}
	if (c == '\n')
		lineno++;
	return c;
}
*/
yyerror(s)	/* called for yacc syntax error */
	char *s;
{
	warning(s, (char *) 0);
}

warning(s, t)	/* print warning message */
	char *s, *t;
{
	fprintf(stderr, "%s: %s", progname, s);
	if (t)
		fprintf(stderr, " %s", t);
	fprintf(stderr, " near line %d\n", lineno);
}
