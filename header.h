#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    double skor;
    char kata[64];
    int panjangKata;
} Data;

typedef struct {
    double skor;
    char kata[64];
    int panjangKata;
} Final;

int hitungKata (char *str);
int hitungBaris(int line, char *filename);
int hitungPanjang(int lenght, char *filename);
void processString(char *str);
void inputTextfile (char *filename, int line, int lenght, char *kalimat);
void writeBinaryFile (Data datas[], int );
int Scoring(char *token);
void strtokCharacter(char *token, char *kalimat,Data datas[]);
void Header();
void Clear_System();
void Pause();
void ignoreInputBuffer();
void getEnterKey();
int hitungChar(int karakter, char *filename);
void bubbleSort(Data datas[],int word);

