#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

void ignoreInputBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {   // membersihkan buffer input
        continue;
    }
}

void getEnterKey(){
    printf("\n<Tekan enter untuk lanjut>\n");
    ignoreInputBuffer();
}

int main(){
    system("cls");

    int option;
    int is_continue = 1;
    int option1_selected = 0;

    int line = 0;
    int length = 0;
    int kata = 0;

    Data contoh[kata];

    FILE *ifp;
    char filename[20];
    printf("Masukkan nama file input (txt): ");
    scanf("%s", filename);
    ifp = fopen(filename, "r");
    if(ifp == NULL){
        printf("Error, tidak dapat membuka file...\n");
        exit(1);
    }   

    //Program pemrosesan data
    
    fclose(ifp);
    
    label_input:
    system("cls");
    printf("Selamat Datang di Big challenge\n\n");
    printf("(1) Masukan ke binary file\n");
    printf("(2) Baca dari binary file\n");
    printf("(3) Keluar\n");
    printf("Masukkan pilihan anda: ");
    scanf("%d", &option);
    ignoreInputBuffer();
    
    if(option == 1){
        printf("program write to file binary\n");
        writeBinaryFile(contoh, kata);
        getEnterKey();
        goto label_input;
    }
    else if(option == 2){
            if(option1_selected){
                printf("program read file binary\n");
                //read binary and print to terminal
                getEnterKey();
                goto label_input;
            }
            else {
                printf("Pilih opsi satu terlebih dahulu");
                getEnterKey();
                goto label_input; 
            }
    //     
    }
    else if(option == 3){
        printf("Program selesai, Sampai jumpa");
    }
    else {
        printf("input tidak valid, silahkan masukkan input ulang\n");
        getEnterKey();
        goto label_input;
    }



    return 0;
}