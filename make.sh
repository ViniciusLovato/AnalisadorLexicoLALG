#! /bin/sh
flex  scanner.l
yacc -d parser.y
gcc -c -g param.c
gcc -c -g symbolTable.c
gcc -g  param.o symbolTable.o y.tab.c lex.yy.c -o parser 
