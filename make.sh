#! /bin/sh
lex scanner.l
gcc scanner.c lex.yy.c -o scanner
