all: bin/compiler

test: bin/compiler 
	cat testcase.txt | ./bin/compiler	

bin/compiler : build/y.tab.c build/lex.yy.c   | build bin
	gcc build/lex.yy.c build/y.tab.c  -o bin/compiler

build/lex.yy.c : src/compiler.l build/y.tab.h | build
	lex -o build/lex.yy.c src/compiler.l

build/y.tab.c : src/compiler.y | build
	yacc -d src/compiler.y -o build/y.tab.c

build/y.tab.h : src/compiler.y | build
	yacc -d src/compiler.y -o src/y.tab.c

build:
	mkdir -p build

bin:
	mkdir -p bin

clean :
	rm -rf build bin