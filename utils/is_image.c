//
//
//  LOCAL CHANGELOG:
//
//  09/02/2023:
//      Changed the return value to the image-type value
//      Removed non-needed includings
//
//
//
//

#include "is_image.h"
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
            return i + 1;
        }
    }

    return 0;
};