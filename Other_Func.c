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

//Fungsi metode scoring
int Scoring(char *token) {
    int skor = 0;
    int panjangKata = strlen(token);
    //printf("Kata: %s, Panjang: %d\n", token, panjangKata);
    int score[] = {
        1, 70, 71, 72, 2, 73, 74, 75, 3, 76, // a-j
        77, 78, 4, 79, 5, 80, 81, 6, 82, 83, // k-t
        84, 85, 86, 87, 88, 89               // u-z
    };

    for (int i = 0; token[i] != '\0'; i++) {
        char c = tolower(token[i]);
        
        // Periksa apakah karakter adalah huruf kecil
        if (c >= 'a' && c <= 'z') {
            skor += score[c - 'a'];
        }
    }   
    return skor;
}

//Fungsi read textfile sekaligus memasukkan data ke array of char
char** readTextFile(char *filename, int *numlines){
    FILE *file;
    char **lines = NULL;
    char line[1000];
    int count = 0;

    file = fopen(filename, "r");
    if(file == NULL){
        printf("    gagal membuka file");
        return NULL;
    }

    while(fgets(line, sizeof(line), file) != NULL){
        count++;
    }

    lines = (char **)malloc(count * sizeof(char *));
    if(lines == NULL){
        printf("    gagal Mengalokasikan memori.");
        fclose(file);
        return NULL;
    }

    fseek(file, 0, SEEK_SET);

    for(int i = 0; i< count; i++){
        if(fgets(line, sizeof(line), file) != NULL){
            if(line[strlen(line) - 1 ] == '\n'){
                line[strlen(line) - 1] = '\0';
            }

            lines[i] = (char *)malloc(strlen(line) + 1);
            strcpy(lines[i], line);
        }
    }
    fclose(file);

    *numlines = count;
    return lines;

}

//Fungsi untuk kapitalisasi dan penghilangan tanda baca pada array
void processText(char **lines, int numlines){
    for(int i = 0; i< numlines; i++){
        char *line=lines[i];
        int j = 0;

        while(line[j] != '\0'){
            if(j == 0 || (j > 0 && line[j - 1] == ' ')){
                line[j] = toupper(line[j]);
            }

            if(!isalpha(line[j]) && !isspace(line[j])){
                memmove(&line[j], &line[j+1], strlen(line) - j);
                continue;
            }
            j++;
        }
    }
}

//Fungsi mengambil token dari kalimat dan scoring
WordData* countScore(char **lines, int numlines, int *numWords){
    int totalKata = 0;
    char word[64];
    for(int i = 0; i< numlines; i++){
        char lineCopy[1000];
        strcpy(lineCopy, lines[i]);
        char *token = strtok(lineCopy, " ");
        while(token != NULL){
            // printf("token1: %s\n", token);
            totalKata++;
            token = strtok(NULL, " ");
        }
    }
    // printf("NL : %d\n", numlines);
    // printf("TK : %d\n", totalKata);
    
    WordData *wordArray = (WordData*)malloc(totalKata * sizeof(WordData));
    if(wordArray == NULL){
        printf("    Gagal mengalokasikan memori.");
        exit(1);
    }

    int index = 0;
    for(int i = 0; i < numlines; i++){
        char lineCopy[1000];
        strcpy(lineCopy, lines[i]);
        char *token = strtok(lineCopy, " ");
        while(token != NULL){
            strcpy(wordArray[index].kata, token);
            wordArray[index].panjangKata = strlen(token);
            wordArray[index].skor = Scoring(token);
            //printf("Kata: %s, Panjang: %d, skor: %.2lf\n", token, wordArray[index].panjangKata, wordArray[index].skor);
            token = strtok(NULL, " ");
            index++;
        }
    }

    *numWords = totalKata;
    return wordArray;
}

//Fungsi menukar nilai struct
void swap(WordData *a, WordData *b){
    WordData temp = *a;
    *a = *b;
    *b = temp;
}

//Fungsi sorting dengan bubblesort
void bubbleSort(WordData *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Jika skor kata berbeda, urutkan berdasarkan skor dari yang terbesar ke terkecil
            if (array[j].skor != array[j + 1].skor) {
                if (array[j].skor < array[j + 1].skor) {
                    swap(&array[j], &array[j + 1]);
                }
            }
            // Jika skor kata sama, urutkan secara alfabetis berdasarkan kata
            else if (strcmp(array[j].kata, array[j + 1].kata) > 0) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

//Fungsi menulis ke binary file
void writeBinaryFile(WordData *data, int numWords) {
    char filebin[20];

    printf("\n    Ingin disimpan ke filebin yang mana? (File.bin): ");
    scanf("%s", filebin);

    //Buka file binary untuk ditulis
    FILE *file = fopen(filebin, "wb");
    if (file == NULL) {
        printf("    Gagal membuka file untuk ditulis.");
        exit(1);
    }

    // Tulis data ke file biner
    int currentskor = data[0].skor;
    int currentskorCount = 0;

    for (int i = 0; i < numWords; i++) {
        // Jika skor kata berubah, tulis skor baru dan jumlah kata dengan skor tersebut
        if (data[i].skor != currentskor) {
            fwrite(&currentskor, sizeof(int), 1, file);
            fwrite(&currentskorCount, sizeof(int), 1, file);
            currentskor = data[i].skor;
            currentskorCount = 0;
        }

        // Tulis panjang kata dan kata itu sendiri
        int panjangKata = data[i].panjangKata;
        fwrite(&panjangKata, sizeof(int), 1, file);
        fwrite(data[i].kata, sizeof(char), panjangKata, file);
        currentskorCount++;
    }

    // Tulis skor terakhir dan jumlah kata dengan skor tersebut
    fwrite(&currentskor, sizeof(int), 1, file);
    fwrite(&currentskorCount, sizeof(int), 1, file);

    // Tutup file
    fclose(file);
    printf("    Berhasil menulis ke file %s\n", filebin);
}

void readBinary (WordData *data, int numwords){
    int n;
    printf("    masukkan jumlah kata (0 - 50) : ");
    scanf("%d", &n);

    if(n <=0 || n>50){
        printf("    Jumlah kata invalid");
    }
    else{
        printf("\n");
        for(int i=0; i < n; i++){
            printf("    %.0lf {", data[i].skor);
            printf("%s (%d)", data[i].kata, data[i].panjangKata);
            for(int j = i+1; j<n; j++){
                if(data[j].skor == data[i].skor){
                    printf(", %s (%d)", data[j].kata, data[j].panjangKata);
                    i = j;
                }
            }
            printf("}\n");
        }
    }
    printf("\n\n");
    free(data);   
    
}


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