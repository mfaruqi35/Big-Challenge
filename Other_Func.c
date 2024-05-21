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

//Fungsi menghitung karakter pada teksfile
int hitungChar(int character, char *filename){
    FILE *fh_input = fopen(filename, "r");
    char huruf;
    if(fh_input == NULL){
        printf("Tidak dapat membuka file");
        EXIT_FAILURE;
    }
    huruf=fgetc(fh_input);
    while(!feof(fh_input)){
        // if(isalpha(huruf)||isdigit(huruf)||huruf==' '||huruf=='\n'){
            character++;
        // }
        huruf=fgetc(fh_input);
    }
    fclose(fh_input);
    return character;
}


//Fungsi menghitung panjang string di teksfile
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


//Fungsi menghitung baris di teksfile
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


//Fungsi menghitung kata pada array
int hitungKata(char *str){
    int inWord = 0;
    int wordCount = 0;

    for(int i = 0; str[i]!= '\0'; i++){
        if(isspace((unsigned char)str[i])){
            inWord = 0;
        } else if (!inWord){
            inWord = 1;
            wordCount++;
        }

    }

    return wordCount;
}


//Fungsi menginput data dari teksfile ke array
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


//Fungsi kapitalisasi huruf awal tiap kata dan menghilangkan tanda baca
void processString(char *str){
    int length = strlen(str);
    int newIndex = 0;
    int capitalizeNext = 1; // Sebagai tanda untuk mengkapitalkan karakter setelahnya

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
            capitalizeNext = 1; 
        }
    }
    str[newIndex] = '\0'; 
}


//Fungsi mencari token untuk menghitung skor tiap kata
void strtokCharacter(char *token, char *kalimat, Data awal[]){
    int i = 0;
    token = strtok(kalimat," ");
    while (token != NULL){
        // printf("%s\n",token);
        strcpy(awal[i].kata,token);
        awal[i].skor=Scoring(token);
        awal[i].panjangKata=strlen(token);
        token = strtok(NULL, " ");
        i++;
    }
}

    
//Fungsi untuk menghitung total skor dari sebuah string
int Scoring(char *token){
    int skor = 0;
    int score[] = {
        1, 70, 71, 72, 2, 73, 74, 75, 3, 76, // a-j
        77, 78, 4, 79, 5, 80, 81, 6, 82, 83, // k-t
        84, 85, 86, 87, 88, 89               // u-z
    };

    for(int i = 0; token[i] != '\0'; i++) {
        char c = tolower(token[i]);
        
        // Periksa apakah karakter adalah huruf kecil
        if (c >= 'a' && c <= 'z') {
            skor += score[c -'a'];
        }
    }   
    return skor;
}


//Fungsi untuk mengurutkan skor dan kata dengan bubble sort
void bubbleSort(Data awal[],int kata){
    //mengurutkan skor(desc)
    for(int i=0;i < kata; i++){
        for(int j=0;j < kata-i-1;j++){
            if(awal[j].skor<awal[j+1].skor){
                Data temp = awal[j];
                awal[j] = awal[j+1];
                awal[j+1] = temp;
            }
        }
    }

    //mengurutkan kata sesuai abjad
    for(int i=0;i < kata; i++){
        for(int j=0;j < kata-i-1;j++){
            if((awal[j].skor==awal[j+1].skor)&&(strcmp(awal[j].kata, awal[j+1].kata) > 0)){
                Data temp = awal[j];
                awal[j] = awal[j+1];
                awal[j+1] = temp;
            }
        }
    }
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