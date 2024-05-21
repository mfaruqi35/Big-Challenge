
#include "header.h"

int main() {

    int karakter = 0;
    int line = 0;
    int panjangstr = 0;
    int kata = 0;
    int Opsi_1 = 0;
    int Opsi_2 = 0;
    FILE *ifp;
    char filename[20];
    char *token;

    
    

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

                        line = hitungBaris(line, filename);
                        printf("%d\n",line);
                        panjangstr = hitungPanjang(panjangstr, filename);
                        printf("%d\n", panjangstr);

                        //Menghitung banyak karakter untuk dijadikan sebagai size array of char string 
                        karakter = hitungChar(karakter, filename);  

                        //Deklarasi array string
                        char string[karakter];

                        //Input string dari text file ke array
                        inputTextfile(filename, line, panjangstr, string);

                        kata = hitungKata(string);
                        printf("%d\n", kata);

                        Data awal[kata];
                        
                        processString(string);
                        strtokCharacter(token, string, awal);
                        bubbleSort(awal, kata);

                        for (int i = 0; i < kata; i++) {
                            printf("Kata: %s, Skor: %.2lf, Panjang: %d\n", awal[i].kata, awal[i].skor, awal[i].panjangKata);
                        }

         //------------------- Menu kedua ----------------------------------------------------
                    
                        do {
                            //Clear_System();
                            Header();
                            printf("      ------------( Menu / Option )------------\n\n");
                            printf("      [1] Masukkan Data Ke File Binary\n");
                            printf("      [2] Tampilkan Data Dari Binary\n");
                            printf("      [3] Kembali\n\n");
                            printf("    Pilihan Anda (1-3) : ");
                            scanf("%d", &Opsi_2);
                            ignoreInputBuffer();

                            switch(Opsi_2) {

                            case 1:
                                    Clear_System();
                                    printf("    \nOpsi pertama\n");
                                    Pause();
                                    
                                    break;

                            case 2:
                                    Clear_System();
                                    printf("    \nOpsi Kedua\n");
                                    Pause();
                                    
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

