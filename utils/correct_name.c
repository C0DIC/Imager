#include "correct_name.h"
#include <stdio.h>

void correctName(char filename[]) {
    unsigned int length = strlen(filename) - 1;
    
    int i = 0;
    for (; i < length; i++) {
        if (filename[i] == '/') filename[i] = '%';
    }
}