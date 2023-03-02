%{
#include <stdlib.h>
#include "calc3.h"
#include "y.tab.h"
void yyerror(char *);
%}
%%
0 {
yylval.iValue = atoi(yytext);
return NUMBER;
}

[1-9][0-9]* {
yylval.iValue = atoi(yytext);
return NUMBER;
}
[+] { return ADD;}
[*] { return MUL;}
[-] { return yytext[0];;}
[/] { return DIV;}
[(] { return PAROPEN;}
[)] { return PARCLOSE;}
[ \t]+ {;}
[\n] {return yytext[0];}
%%
int yywrap(void) {
return 1;
}

