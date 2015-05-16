#! /bin/sh
flex --debug scanner.l
yacc -d parser.y
gcc y.tab.c lex.yy.c -o parser
