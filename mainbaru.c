#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

int main() {
    FILE *ifp;
    char filename[20];
    char filebin[20];
    char **lines = NULL;
    WordData *data = NULL;
    WordFinal *final = NULL;
    int numlines = 0, numwords = 0;
    int numToShow;

    int Opsi_1 = 0;
    int Opsi_2 = 0;

    // Menu Utama
    do {
        Clear_System();
        Header();
        printf("    Sebelum Memulai, Silahkan input nama file ( File.txt )\n\n");
        printf("      [1] Input file text\n");
        printf("      [2] exit\n\n");
        printf("    Pilihan Anda (1/2) : ");
        scanf("%d", &Opsi_1);
        ignoreInputBuffer();

        if (Opsi_1 == 1) {

            int Berhasil = 0; 
            Clear_System();
            Header();
            printf("    Masukkan nama file input ( File.txt ) : ");
            scanf("%s", filename);
            ifp = fopen(filename, "r");
            if (ifp == NULL) {
                    printf("    File tidak ditemukan, Mohon tunggu ...\n");
                    Pause();
                    continue;;
                } else {
                    //Membaca textfile dan input ke array lines
                    lines = readTextFile(filename, &numlines); 

                    if(lines != NULL){
                    // Kapitalisasi dan penghilangan tanda baca dalam array
                    processText(lines, numlines);

                    //Proses scoring dan inisialisasi ke struct data
                    data = countScore(lines, numlines, &numwords);

                    //Sorting data menggunakan bubble sort
                    bubbleSort(data, numwords);
                    }
            Clear_System();
            Header();
        

         //------------------- Menu kedua ----------------------------------------------------
                    
                        do {

                            printf("\n      ------------( Menu / Option )------------\n\n");
                            printf("      [1] Masukkan Data Ke File Binary\n");
                            printf("      [2] Tampilkan Data Dari Binary\n");
                            printf("      [3] Kembali\n\n");
                            printf("    Pilihan Anda (1-3) : ");
                            scanf("%d", &Opsi_2);
                            ignoreInputBuffer();

                            switch(Opsi_2) {

                            case 1:
                                    
                                    Berhasil = 1;
                                    writeBinaryFile(data, numwords);
                                    Pause();
                                    
                                    break;

                            case 2:
                        
                                    if(Berhasil == 1){
                                        readBinary(data, numwords);
                                        Pause();
                                    }
                                    
                                    else {
                                        printf("\n    Mohon Pilih Opsi Satu Terlebih Dahulu");
                                        Pause();
                                        Clear_System();
                                        Header();
                                        break;
                                    }
                                    
                                    break;
                            case 3: 
                                    fclose(ifp);
                                     break;
                            default:
                                    printf("\n    Mohon Input Dengan Benar\n");
                                    Pause();
                                    fclose(ifp);
                                    break;
                            }

                        } while (Opsi_2 != 3); 
                }
            


        } else if (Opsi_1 == 2) {
            printf("\n    Terima Kasih :)\n");
        } else {
            printf("\nMohon Input Dengan Benar\n");
            Pause();
        }
    } while (Opsi_1 != 2);

    return 0;
}