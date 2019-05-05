CC = clang
FLAGS = -g 
LEX = lex
YACC = yacc

taft: y.tab.o lex.yy.o base_tree.o scope.o node.o base_semantic.o core_semantic.o codegen.o
	$(CC) $(FLAGS) -o taft y.tab.o lex.yy.o base_tree.o scope.o node.o base_semantic.o core_semantic.o codegen.o -ll -ly

y.tab.o: y.tab.c
	$(CC) $(FLAGS) -c y.tab.c

base_tree.o: base_tree.c
	$(CC) $(FLAGS) -c base_tree.c

scope.o: scope.c
	$(CC) $(FLAGS) -c scope.c

node.o: node.c
	$(CC) $(FLAGS) -c node.c

base_semantic.o: base_semantic.c
	$(CC) $(FLAGS) -c base_semantic.c

core_semantic.o: core_semantic.c
	$(CC) $(FLAGS) -c core_semantic.c

codegen.o: codegen.c
	$(CC) $(FLAGS) -c codegen.c

lex.yy.o: lex.yy.c
	$(CC) $(FLAGS) -c lex.yy.c

y.tab.c: pc.y
	$(YACC) -y -dv pc.y

lex.yy.c: pc.l
	$(LEX) -l pc.l

clean:
	rm -f taft *.o y.tab.* lex.yy.* y.output
