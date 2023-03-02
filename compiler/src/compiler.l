%{
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "../include/calc3.h"
#include "../build/y.tab.h"
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
[-()=+*/;] {return yytext[0];}
[,] {return yytext[0];}
[a-z]+[a-z0-9]* {
    if(!strcmp(yytext,"print")){return prt;}
    else if(!strcmp(yytext,"int")){return typp;}
    else if(!strcmp(yytext,"begindecl")){/*ECHO;*/return begindecl;}
    else if(!strcmp(yytext,"enddecl")){return enddecl;}
    else{
        // /*yylval.idname=strdup(yytext);*/
        // ECHO;
        yylval.sindex = strdup(yytext);
        return var;}
        }
[ \t\n]+ { ;}
%%
int yywrap(void) {
return 1;
}

