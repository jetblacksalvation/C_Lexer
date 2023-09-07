CC = gcc
LLPATHS = main.c Lexer\widePointers.c Lexer\pagePointers.c

build:
	gcc ${LLPATHS}  -w