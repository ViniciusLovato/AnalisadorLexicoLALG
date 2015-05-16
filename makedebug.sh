#! /bin/sh
flex --debug scanner.l
yacc -d parser.y
gcc -g y.tab.c lex.yy.c -o parser
