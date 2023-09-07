CC = gcc
LLPATHS = main.c Lexer\widePointers.c Lexer\pagePointers.c
TARGET = main

ifeq ($(shell echo "Windows"), "Windows")
#probably will also make CC = cl for windows compilation ...
	TARGET := $(TARGET).exe
	DEL = del
else
	TARGET := $(TARGET).out
	
	DEL = rm
endif
# else is for linux 

build:
	${CC} ${LLPATHS}  -w -o $(TARGET)

clean:
	@$(DEL) $(TARGET) 