#include "Lexer\lexer.h"

int main(){
    pagePointer * vectorString;
    vectorString = constructPagePointer(1);
    
    widePointer* lexerString= vectorString->pointerPages[0];

    setFromInputStream(lexerString, "acbdef");

    addCharacter(lexerString, 'g');
    for(int x =0; x< lexerString->pascalInt; x++){
        printf("%c",lexerString->string[x]);

    }
    // printf("%s", lexerString->string);
}