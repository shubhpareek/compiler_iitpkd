run : lexerr
	cat testinput3.txt | ./a.out

lexerr: lex.yy.c y.tab.c 
	gcc lex.yy.c y.tab.c 

lex.yy.c:
	lex calculator.l

y.tab.c:
	yacc -d calculator.y

clean:
	rm -f lex.yy.c y.tab.c a.out y.tab.h