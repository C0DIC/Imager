#include "is_image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_imageFile(const char* filename) {
    unsigned int length = strlen(filename) - 1;
    int size = length - (strlen(filename) - 6);
    char temp_array[256];
    char reversed_array[256];

    for (int i = 0; length > strlen(filename) - 6; length--, i++) {
        temp_array[i] = filename[length];
    }

    for (int i = 0, j = size - 1; i < size; i++, j--) {
        reversed_array[i] = temp_array[j];
    }

    int i = 0;
    for (;;) {
        if(reversed_array[i] != '.') { i++; continue; } else break;
    }

    char extension[256] = {};

    for (int j = 0; i < size; i++, j++) {
        extension[j] = reversed_array[i];
    }
    
    char *extensions[] = {".jpeg", ".jpg", ".png", ".gif"};

    i = 0;
    for (; i < 4; i++) {
        if (!strcmp(extension, extensions[i])) {
            return 1;
        }
    }

    return 0;
};

/*
int is_imageFile(const char* filename) {
    printf("[DEBUG]: %s\n", filename);

    int length = strlen(filename);
    char temp_array[256];
    char reversed_array[256];

    for (int i = 0; ; length--, i++) {
        if (filename[length] != '.')
            temp_array[i] = filename[length];
        else {
            temp_array[i] = filename[length];
            break;
        };
    }

    for (int i = 0; i < 7; i++) {
        printf("[TEMP]: %c\n", temp_array[i]);
        if((int)temp_array[i] == 0) {
            temp_array[i] = '1';
        }
    }

    printf("[DEBUG]: %s\n", temp_array);

    for (int i = 0, j = strlen(temp_array) - 1; i < 6; i++, j--) {
        reversed_array[i] = temp_array[j];
    }

    printf("[DEBUG]: %s\n", reversed_array);

    char extension[256] = {};

    for (int i = 0, j = 0; i < strlen(reversed_array) + 1; i++) {
        if (reversed_array[i] != '.') {
            i++;
        }
        else {
            for (int k = i; k < strlen(reversed_array) + 1; k++) {
                extension[j] = reversed_array[k];
                j +=1 ;
            }
        }
    }

    printf("[DEBUG]: %s\n", extension);

    int result = 0;
    const char *extensions[] = {".jpeg", ".jpg", ".png", ".gif"};

    for (int i = 0; i < 4; i++) {
        if(!strcmp(extension, extensions[i])) {
            printf("Found: %s\n", extensions[i]);
            result = 1;
            return result;
        }
    }

    return result;
}*/