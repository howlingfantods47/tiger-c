a.out: parsetest.o prabsyn.o absyn.o symbol.o table.o y.tab.o lex.yy.o errormsg.o util.o
	cc -g parsetest.o prabsyn.o absyn.o symbol.o table.o y.tab.o lex.yy.o errormsg.o util.o

env.o: env.c env.h
	cc -g -c env.c

parsetest.o: parsetest.c parsetest.h
	cc -g -c parsetest.c

prabsyn.o: prabsyn.c prabsyn.h
	cc -g -c prabsyn.c

absyn.o: absyn.c absyn.h
	cc -g -c absyn.c

symbol.o: symbol.c symbol.h
	cc -g -c symbol.c

table.o: table.c table.h
	cc -g -c table.c

y.tab.o: y.tab.c
	cc -g -c y.tab.c

y.tab.c: tiger.grm
	yacc -x -dv tiger.grm

y.tab.h: y.tab.c
	echo "y.tab.h was created at the same time as y.tab.c"

errormsg.o: errormsg.c errormsg.h
	cc -g -c errormsg.c

lex.yy.o: lex.yy.c
	cc -g -c lex.yy.c

lex.yy.c: tiger.lex
	lex tiger.lex

util.o: util.c util.h
	cc -g -c util.c

clean:
	rm -f a.out table.o env.o symbol.o absyn.o \
		util.o parsetest.o lex.yy.c lex.yy.o errormsg.o \
	  	y.tab.c y.tab.h y.tab.o y.output
