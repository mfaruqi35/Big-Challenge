#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "header.h"



int main(){

    // ---- Affan var
    int Opsi_1 = 0;
    int Opsi_2 = 0;
    // ----
    int option;
    int is_continue = 1;
    int option1_selected = 0;
    int line = 0;
    int length = 0;
    int kata = 0;
    FILE *ifp;
    char filename[20];
    //Data contoh[kata];
  
    label_input:
    do{
        int Berhasi_1 = 1;
        Clear_System();
        Header();
        printf("    Sebelum Memulai, Silahkan input nama file (txt)\n\n");
        printf("      [1] Input file text\n");
        printf("      [2] exit\n\n");
        printf("    Pilihan Anda (1/2) : ");
        scanf("%d",&Opsi_1);
        ignoreInputBuffer();

        do{
            if (Opsi_1 == 1){
                Opsi_1 = 0; //Reset
                Clear_System();
                Header();
                printf("    Masukkan nama file input (txt): ");
                scanf("%s", filename);
                ifp = fopen(filename, "r");
                if(ifp == NULL){
                    printf("    Error, tidak dapat menemukan file...\n");
                    Pause();
                    Berhasi_1 = 0;
                }  
            } 
            fclose(ifp);
        }while(Berhasi_1 != 0); 

    /*
        int Berhasil = 1;
        Clear_System();
        Header();
        printf("Masukkan nama file input (txt): ");
        scanf("%s", filename);
        ifp = fopen(filename, "r");

            if(ifp == NULL){
                printf("Error, tidak dapat membuka file...\n");
                Berhasil = 0;
                exit(1);
            }   
        fclose(ifp);


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

        */
    }while(Opsi_1 !=2);
    return 0;
}