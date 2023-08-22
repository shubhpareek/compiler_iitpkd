/*
 *   This file is part of SIL Compiler.
 *
 *  SIL Compiler is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
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
#include <stdlib.h>
#include<string.h>
#include "../include/AbsSynTree.h"
#include "../build/y.tab.h"
//#include "calc3.h"
//#define YYSTYPE NODPTR
int 	Lineno;
int     wflag;
void yyerror(char *);
%}

%option noyywrap
digit	[0-9]
letter	[a-zA-Z]

%%
main	                 	{			/*ECHO;*/ return  MAIN;		}	
			
return  			{ /*ECHO;*/  return  RETURN;}
begin				{ /*ECHO;*/ return  BEG;
					}	
end			{ /*ECHO;*/ return  END;
				}	
write			{ /*ECHO;*/ return  WRITE;
					}	
integer			{ /*ECHO;*/ return  T_INT;
					}	
boolean				{
						/*ECHO;*/ return  T_BOOL;
					}	
decl				{
					/*ECHO;*/ return  DECL;
				}
enddecl				{
					/*ECHO;*/ return  ENDDECL;
				}
if				{
					/*ECHO;*/ return  IF;
				}
then				{
						/*ECHO;*/ return  THEN;
					}	
else				{
						/*ECHO;*/ return  ELSE;
					}	
endif				{
						/*ECHO;*/ return  ENDIF;
				}
do				{
						/*ECHO;*/ return  DO;
				}
while				{
						/*ECHO;*/ return  WHILE;
			}
endwhile			{
						/*ECHO;*/ return  ENDWHILE;
				}
"=="				{
						/*ECHO;*/ return  EQUALEQUAL;
					}	
"<="				{
						/*ECHO;*/ return  LESSTHANOREQUAL;
				}
">="				{
						/*ECHO;*/ return  GREATERTHANOREQUAL;
				}
"!="				{
						/*ECHO;*/ return  NOTEQUAL;
					}	
AND				{
						/*ECHO;*/ return  LOGICAL_AND;
					}	
OR				{
						/*ECHO;*/ return  LOGICAL_OR;
				}
NOT			{
						/*ECHO;*/ return  LOGICAL_NOT;
				}
true			{
						/*ECHO;*/ return  T;
					}	
false			      {
						/*ECHO;*/ return  F;
				}

{digit}+			{ 	
						//
						yylval.iValue = atoi(yytext);
						/*ECHO;*/ return  NUM;

				}

{letter}({letter}|{digit})*	{ 	
						//
						yylval.sindex = strdup(yytext);
						/*ECHO;*/ return  VAR;
				}
[-+*/=()><;,\{\}\[\]\%]         {
						/*ECHO;*/ return  yytext[0];
				}
			
["]                             {/*ECHO;*/ return  yytext[0] ;}
"\\n"                           {
									/*ECHO;*/ //return  yytext[0];
                                }

[ \t]				
.				{
					yyerror("what is this character?");
				}		

%%
//int yywrap(void) {
///*ECHO;*/ return  1;
//}

