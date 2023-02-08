#include "../image/image.h"
#include "interpreter.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "copy.h"

void *interpreter(int size, const char **buffer) {
    int i = 2;

    for (; i < size; i++) {
        if (!strcmp(buffer[i], "--copy")) {
            image imageFile = createImage(buffer[1]);

            if ((i+1) >= size) {
                char new_copy_name[256] = "copy_";
                strcat(new_copy_name, imageFile.filename);
                copyImage(&imageFile, new_copy_name);
            } else {
                copyImage(&imageFile, buffer[i+1]);
            }

            closeImage(&imageFile);
        }
        
    }

    return (void*)0;
};