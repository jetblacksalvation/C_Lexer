CC = gcc
LLPATHS = main.c Lexer\widePointers.c Lexer\pagePointers.c

build:
	${CC} ${LLPATHS}  -w