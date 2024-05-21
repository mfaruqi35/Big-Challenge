#include "header.h"

int hitungKata(char *str){
    int inWord = 0;
    int wordCount = 0;

    for(int i = 0; str[i]!= '\0'; i++){
        if(isspace((unsigned char)str[i])){
            inWord = 0;
        } else if (!inWord){
            inWord = 1;
            wordCount++;
        }

    }

    return wordCount;
}