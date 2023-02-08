#include "../utils/is_image.h"
#include "../image/image.h"
#include "interpreter.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "copy.h"
#include "move.h"

const char *not_image_text = 
"Maybe, you forgot file extension or the file is argument is not correct\n";

void *interpreter(int size, const char **buffer) {
    int i = 2;
    image imageFile = createImage(buffer[1]);

    for (; i < size; i++) {
        if (!strcmp(buffer[i], "--copy")) {
            if ((i+1) >= size) {
                char new_copy_name[256] = "copy_";
                strcat(new_copy_name, imageFile.filename);
                copyImage(&imageFile, new_copy_name);
            } else {
                if (is_imageFile(buffer[i+1])) {
                    copyImage(&imageFile, buffer[i+1]);
                } else {
                    fprintf(stderr, "%s", not_image_text);
                    break;
                }
            }
        }

        if (!strcmp(buffer[i], "--move")) {            
            if ((i+1) >= size) {
                fprintf(stderr, "Maybe you missed an argument\n");
                break;
            }

            if (is_imageFile(buffer[i+1])) {
                moveImage(&imageFile, buffer[i+1]);
            } else {
                fprintf(stderr, "%s", not_image_text);
                break;
            }
        }
    }

    closeImage(&imageFile);
};