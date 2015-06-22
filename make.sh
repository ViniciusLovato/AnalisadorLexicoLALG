#! /bin/sh
flex  scanner.l
yacc -d parser.y
gcc param.c symbolTable.h y.tab.c lex.yy.c -o parser
