#include "lexer.h"

pagePointer * constructPagePointer(size_t entries){
    pagePointer* ret = malloc(sizeof(pagePointer));
    ret->allocatedMemory = sizeof(pagePointer);
    ret->pointerPages = malloc(sizeof(widePointer*)*entries);
    for( int x =0; x < entries; x++){
        ret->pointerPages[x] = constructWidePointer();
    }
    return ret;
}
void freePagePointer(pagePointer * PagePointer){
    int32_t arrayLength = PagePointer->allocatedMemory / sizeof(pagePointer);
    for(int32_t index = 0; index < arrayLength; index++){
        free(PagePointer->pointerPages[index]);
    }
}