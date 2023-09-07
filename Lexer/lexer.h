#pragma once 
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
/*

*/
struct widePointer{
    char * string;
    int64_t pascalInt;
    int64_t allocatedMemory;
};
typedef struct widePointer widePointer;

struct pagePointer{
    widePointer ** pointerPages;
    int64_t allocatedMemory;
};
typedef struct pagePointer pagePointer;

/*
expects widePointer type ...
*/
#define ALLOC_MORE_MEM(arg, memToAdd)          \
realloc(arg->string, sizeof(char)*arg->pascalInt+ arg->allocatedMemory+memToAdd );                            \
arg->allocatedMemory = sizeof(char)*arg->pascalInt+ arg->allocatedMemory +memToAdd;                           \
/*
only used by functions where the size is set unconditionally 
*/

#define DEFAULT_ALLOC_LEN 20
widePointer* constructWidePointer();
void setFromInputStream(widePointer * inputPointer , char * inputStream);
void setFromWidePointer(widePointer * inputPointer , widePointer* setFromPointer);
void addCharacter(widePointer * this, char c);
pagePointer * constructPagePointer(size_t entires);