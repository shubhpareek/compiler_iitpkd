%{
#define YYSTYPE double
#include <stdio.h>
#include "y.tab.h"
//extern YYSTYPE yylval;
extern int lineno;
%}
%%
[0-9]+ { yylval = atoi(yytext); return NUMBER;}
[\+] { return ADD;}
[\*] { return MUL;}
[\-] { return SUB;}
[\/] { return DIV;}
[\(] { return PAROPEN;}
[\)] { return PARCLOSE;}
[ \t]+ { };
[\n] {lineno++;return yytext[0];}
%%

