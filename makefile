CC = gcc
LLPATHS = main.c Lexer\widePointers.c Lexer\pagePointers.c
TARGET = a

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

build:
	${CC} ${LLPATHS}  -w

clean:
	@$(DEL) $(TARGET) 