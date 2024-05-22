#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    double skor;
    char kata[64];
    int panjangKata;
} WordData;

typedef struct {
    double skor;
    char kata[64];
    int panjangKata;
} WordFinal;

//Operating Function
void readBinary (WordData *data, int numwords);
void writeBinaryFile(WordData *data, int numWords);
void bubbleSort(WordData *array, int size); 
void swap(WordData *a, WordData *b);
void processText(char **lines, int numlines);
char** readTextFile(char *filename, int *numlines);
WordData* countScore(char **lines, int numlines, int *numWords);

//UI
void Header();
void Clear_System();
void Pause();
void ignoreInputBuffer();
void getEnterKey();
