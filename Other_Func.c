#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

int Scoring(char c) {
    
    c = tolower(c);

    int score[] = {
        1, 70, 71, 72, 2, 73, 74, 75, 3, 76, // a-j
        77, 78, 4, 79, 5, 80, 81, 6, 82, 83, // k-t
        84, 85, 86, 87, 88, 89               // u-z
    };

    if (c >= 'a' && c <= 'z') {
        return score[c - 'a'];
    }
    return 0;
}