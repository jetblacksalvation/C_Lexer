#include "lexer.h"


widePointer* constructWidePointer(){
    widePointer* this = malloc(sizeof(widePointer));
    
    this->string  = malloc(DEFAULT_ALLOC_LEN*sizeof(char));
    this->allocatedMemory = DEFAULT_ALLOC_LEN;
    this->pascalInt = 0;
    //EMPTY STRING...
    return  this;
};
//COPY FROM BUFFER USING C-sytle strings ...
void setFromInputStream(widePointer * inputPointer , char * Stream){
    inputPointer->pascalInt = 0;
    char * inputStream = Stream;

    while (*inputStream != 0) {

        inputPointer->pascalInt ++;
        inputStream++;
    }
    if(inputPointer->allocatedMemory < inputPointer->pascalInt){
        ALLOC_MORE_MEM(inputPointer, inputPointer->pascalInt *2);
    }
    memccpy(inputPointer->string, Stream, sizeof(char), inputPointer->pascalInt );
    
    return;
}
void setFromWidePointer(widePointer * inputPointer , widePointer* setFromPointer){
    inputPointer->pascalInt = setFromPointer->pascalInt;

    if (inputPointer->allocatedMemory < setFromPointer->allocatedMemory && inputPointer->pascalInt < setFromPointer->pascalInt){
        ALLOC_MORE_MEM(inputPointer, setFromPointer->allocatedMemory);
    }
    else if (inputPointer->allocatedMemory > setFromPointer->allocatedMemory && inputPointer->pascalInt > setFromPointer->pascalInt) {
        ALLOC_MORE_MEM(setFromPointer, inputPointer->allocatedMemory);
    }

    memccpy(inputPointer->string, setFromPointer, sizeof(char), inputPointer->pascalInt );
    //copies string data...
    return;
}
void addCharacter(widePointer * this, char c){
    if(this->pascalInt + sizeof(char) > this->allocatedMemory){
        ALLOC_MORE_MEM(this, this->pascalInt);
    }
    this->string[this->pascalInt] = c;
    this->pascalInt++;

}

