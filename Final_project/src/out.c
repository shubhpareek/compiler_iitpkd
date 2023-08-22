/*

DECL INT FUNC VAR(INT VAR,INT VAR,VAR,),
DECL INT ARR VAR 5,ARR VAR 5,ARR VAR 5,VAR ,
DECL INT FUNC VAR(INT VAR,INT VAR,VAR,BOOL VAR,),
DECL INT FUNC VAR(INT VAR,INT VAR,VAR,BOOL VAR,),
DECL BOOL VAR ,VAR ,
DECL INT VAR , 
FUNC INT VAR (INT VAR,INT VAR,VAR,){
 
 
RETURN VAR }
 
FUNC INT VAR (INT VAR,INT VAR,VAR,BOOL VAR,){

DECL INT VAR , 
ASSIGN VAR  = PLUS 2  
3  
 
 
RETURN VAR }
 
FUNC INT VAR (INT VAR,INT VAR,VAR,BOOL VAR,){

DECL INT VAR , 
ASSIGN VAR  = PLUS 2  
3  
 
 
RETURN VAR }

INT MAIN


DECL INT VAR ,VAR ,ASSIGN VAR  = NUM  
ASSIGN VAR  = NUM  
ASSIGN VAR  = NUM  
ASSIGN VAR  = NUM  
ASSIGN VAR  = NUM  
WHILE LESSTHAN temp 5  
 
 
ASSIGN ARREF VAR NUM = PLUS temp 2  
 
ASSIGN ARREF VAR NUM = PLUS temp + 5  
 
n  
ASSIGN ARREF VAR NUM = PLUS a[temp ]b[temp ] 
ASSIGN VAR  = PLUS temp 1  
 
ENDWHILE 
ASSIGN VAR  = NUM  
IFLESSTHAN temp 3  
 
 
FUNCALL ("%d", ARREF VAR NUM) 
ELSE FUNCALL ("%d", ARREF VAR NUM) 
FUNCALL  VAR VAR VAR VAR VAR 
FOR (ASSIGN VAR  = NUM  
;LESSTHAN xx 1  
 
;ASSIGN VAR  = PLUS xx 1  
 
){
ASSIGN VAR  = PLUS xx 2  
 

}ASSIGN VAR  = FUNCALL (PLUS 2  
3  
 
,NUM  
,VAR )RETURN NUM  

*/
#include<stdio.h>
#include<stdbool.h>
int bbs(int a,int c,int b);
 
int a [5];
int b [5];
int c [5];
int temp;
 
int lol(int a,int c,int b,bool x);
 
int tol(int a,int c,int b,bool x);
 
bool n;
bool z;
 
int x;
 

int main(){

int xx;
int yy;
 
temp  = 0  
;
x  = 1  
;
xx  = 0  
;
z  = 1  
;
n  = 0  
;
while( temp < 5  
 
){ 
a[temp ] = temp + 2  
 
;
b[temp ] = temp + 5  
 
+ n  
;
c[temp ] = a[temp ]+ b[temp ] 
;
temp  = temp + 1  
 
;
;} 
;
temp  = 3  
;
if(temp < 3  
 
){ 
printf("%d", c[1  
]) ;
;}
else{ printf("%d", c[4  
]) ;
;} 
;
printf(" I am a string \n  ")
;
for(xx  = 0  
 
;xx < 1  
 
;xx  = xx + 1  
 
 
){
xx  = xx + 2  
 
;

};
x  = bbs(2  
+ 3  
 
,5  
,xx );
return 0  
;
}
 
int bbs(int a,int c,int b){
 
 
return a ;
}
 
int lol(int a,int c,int b,bool x){
int d;
 
 
a  = 2  
+ 3  
 
;
 
return b ;
}
 
int tol(int a,int c,int b,bool x){
int d;
 
 
a  = 2  
+ 3  
 
;
 
return b ;
}
