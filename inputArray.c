#include "header.h"
#include <stdio.h>

int hitungPanjang(int lenght, char *filename){
    int n=0;
    char huruf;
    FILE * input;
    input = fopen(filename,"r");

    if(input==NULL){
        printf("Tidak bisa membuka file...");
        exit(1);
    }
    huruf=fgetc(input);
    while(!feof(input)){
        if(huruf=='\n'){
            ++n;
            if(n>lenght){
            lenght=n;   
            }
            n=0;
            huruf=fgetc(input);
        }
        n++;
        huruf=fgetc(input);
        if(huruf==EOF){
            if(n>lenght){
                lenght=n;
            }
        }
    }

    fclose(input);
    return (lenght);
}

int hitungBaris(int line, char *filename){
    char huruf;
    FILE * finput;
    finput = fopen(filename, "r");

    if(finput == NULL){
        printf("Tidak dapat membuka file...");
        EXIT_FAILURE;
    }

    huruf = fgetc(finput);
    while(!feof(finput)){
        if(huruf == '\n'){
            line++;
        }
        huruf = fgetc(finput);
    }
    line++;
    fclose(finput);

    return line;
}   

void inputTextfile(char *filename, int line,int lenght,char * kalimat){
    char string[line][lenght];
    int i=0;
    int a=0;
    FILE * input;
    input = fopen(filename,"r");
    if(input==NULL){
        printf("Tidak dapat membuka file...");
        exit(1);
    }

    while(fgets(string[i],(lenght*sizeof(int)),input)!=NULL){
        i++;
    }
    for(int j=0;j < line;j++){
        for(int k=0;k < lenght;k++){
            if(string[j][k]=='\0'||string[j][k]==EOF){
                break;
            }
            if(isalpha(string[j][k])||isdigit(string[j][k])||string[j][k]==' '){
                kalimat[a]=string[j][k];
                kalimat[a]=tolower(kalimat[a]);
                a++;
            }
            else{
                kalimat[a]=' ';
                a++;
            }
            
        }
    }

    fclose(input);
}

void processString(char *str){
     int length = strlen(str);
    int newIndex = 0;
    int capitalizeNext = 1; // Flag to capitalize the next character

    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            if (capitalizeNext) {
                str[newIndex++] = toupper(str[i]);
                capitalizeNext = 0;
            } else {
                str[newIndex++] = str[i];
            }
        } else if (isspace(str[i])) {
            str[newIndex++] = str[i];
            capitalizeNext = 1; // Next character should be capitalized if it's a letter
        }
    }
    str[newIndex] = '\0'; 
}


