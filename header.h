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

void writeBinaryFile (Data datas[], int );
int Scoring(char c);
