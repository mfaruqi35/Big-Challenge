#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Fungsi untuk menghitung total skor dari sebuah string
// int Scoring(char *token ) {
//     int skor = 0;
//     int score[] = {
//         1, 70, 71, 72, 2, 73, 74, 75, 3, 76, // a-j
//         77, 78, 4, 79, 5, 80, 81, 6, 82, 83, // k-t
//         84, 85, 86, 87, 88, 89               // u-z
//     };

//     for (int i = 0; token[i] != '\0'; i++) {
//         char c = tolower(token[i]);
        
//         // Periksa apakah karakter adalah huruf kecil
//         if (c >= 'a' && c <= 'z') {
//             skor += score[c - 'a'];
//         }
//     }   
//     return skor;
// }


// Fungsi Tambahan Untuk support system
void Header(){
    printf("\n");
    printf("    +----------------------------------------------------+\n");
    printf("    |             Selamat Datang Di Program              |\n");
    printf("    |                   BIG CHALLENGE                    |\n");
    printf("    +----------------------------------------------------+\n\n");
}

void ignoreInputBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {   // membersihkan buffer input
        continue;
    }
}

void getEnterKey(){
#ifdef _WIN32
    system("pause");
#else
    printf("\n<Tekan enter untuk lanjut>\n");
    ignoreInputBuffer();
#endif
}

void Clear_System() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Pause() {
#ifdef _WIN32
    Sleep(2000); // Windows
#else
    sleep(2); // Unix
#endif
}