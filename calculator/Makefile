all : calculator.out

calculator.out : y.tab.c lex.yy.c  interpreter.c 
	gcc lex.yy.c y.tab.c interpreter.c -o calculator.out

y.tab.c : calculator.y
	yacc -d calculator.y

lex.yy.c : calculator.l y.tab.h
	lex calculator.l
	
y.tab.h : calculator.y
	yacc -d calculator.y

clean : 
	rm -f lex.yy.c y.tab.c calculator.out y.tab.h

.PHONY: clean
