#include "header.h"

// Fungsi untuk mendapatkan skor dari karakter tertentu
int Scoring(char *token) {
    int skor = 0;
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

// Fungsi untuk menghitung total skor dari suatu kata
// int calculate_word_score(const char *word) {
//     int total_score = 0;
//     for (int i = 0; i < strlen(word); i++) {
//         total_score += get_char_score(word[i]);
//     }
//     return total_score;
// }

// // Struktur untuk menyimpan kata dan skornya
// typedef struct {
//     char word[100];
//     int score;
// } WordScore;

// // Fungsi untuk membandingkan dua WordScore berdasarkan skor (untuk qsort)
// int compare_scores(const void *a, const void *b) {
//     WordScore *wordA = (WordScore *)a;
//     WordScore *wordB = (WordScore *)b;
//     return wordB->score - wordA->score;
// }

// // Fungsi untuk membandingkan dua WordScore berdasarkan kata (untuk qsort)
// int compare_words(const void *a, const void *b) {
//     WordScore *wordA = (WordScore *)a;
//     WordScore *wordB = (WordScore *)b;
//     return strcmp(wordA->word, wordB->word);
// }

// int main() {
//     char input[1000];
//     printf("Masukkan kata-kata (dipisahkan oleh spasi): ");
//     fgets(input, sizeof(input), stdin);

//     // Hapus newline di akhir input jika ada
//     input[strcspn(input, "\n")] = 0;

//     // Array untuk menyimpan kata-kata dan skornya
//     WordScore words[100];
//     int word_count = 0;

//     // Memisahkan kata menggunakan strtok
//     char *token = strtok(input, " ");
//     while (token != NULL) {
//         strcpy(words[word_count].word, token);
//         words[word_count].score = calculate_word_score(token);
//         word_count++;
//         token = strtok(NULL, " ");
//     }

//     // Mengurutkan kata-kata berdasarkan skor menggunakan qsort
//     qsort(words, word_count, sizeof(WordScore), compare_scores);

//     // Mencetak hasil dengan pengelompokan skor
//     int i = 0;
//     while (i < word_count) {
//         int current_score = words[i].score;
//         int start_index = i;
        
//         // Kelompokkan kata-kata dengan skor yang sama
//         while (i < word_count && words[i].score == current_score) {
//             i++;
//         }
        
//         int end_index = i;
        
//         // Urutkan kata-kata dalam kelompok ini secara alfabetis
//         qsort(&words[start_index], end_index - start_index, sizeof(WordScore), compare_words);
        
//         // Cetak skor, jumlah kata, dan kata-katanya
//         printf("(%d){%d}", current_score, end_index - start_index);
//         for (int j = start_index; j < end_index; j++) {
//             printf("(%s)(%lu)", words[j].word, strlen(words[j].word));
//         }
//         printf("\n");
//     }

//     return 0;
// }
