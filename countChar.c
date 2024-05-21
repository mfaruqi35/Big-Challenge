#include "header.h"

int hitungChar(int character, char *filename){
    FILE *fh_input = fopen(filename, "r");
    char huruf;
    if(fh_input == NULL){
        printf("Tidak dapat membuka file");
        EXIT_FAILURE;
    }
    huruf=fgetc(fh_input);
    while(!feof(fh_input)){
        // if(isalpha(huruf)||isdigit(huruf)||huruf==' '||huruf=='\n'){
            character++;
        // }
        huruf=fgetc(fh_input);
    }
    fclose(fh_input);
    return character;
}