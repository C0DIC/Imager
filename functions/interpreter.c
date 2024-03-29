//
//
//  LOCAL CHANGELOG:
//
//  09/02/2023:
//      Removed non-needed includings
//      Added "info.h"
//      Added "../utils/correct_name.h"
//
//  12/02/2023:
//      Added alternatives for options --move, --info, --copy
//  19/02/2023:
//      Added resize.h | resizeImage() func
//

#include "../utils/correct_name.h"
#include "../utils/is_image.h"
#include "../image/image.h"
#include "interpreter.h"

#include <string.h>
#include <stdio.h>

#include "copy.h"
#include "move.h"
#include "info.h"
#include "crop.h"

const char *not_image_text = 
"Maybe, you forgot file extension or the file is argument is not correct\n";

void *interpreter(int size, const char **buffer) {
    int i = 2;

    image imageFile = createImage(buffer[1]);

    for (; i < size; i++) {
        if (!strcmp(buffer[i], "--copy") || !strcmp(buffer[i], "-cp")) {
            if ((i+1) >= size) {
                char new_copy_name[256] = "copy_";
                strcat(new_copy_name, imageFile.filename);
                correctName(new_copy_name);
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

        if (!strcmp(buffer[i], "--move") || !strcmp(buffer[i], "-mv")) {            
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

        if (!strcmp(buffer[i], "--info") || !strcmp(buffer[i], "-i")) {
            infoImage(&imageFile);
        }

        if (!strcmp(buffer[i], "--crop") || !strcmp(buffer[i], "-cr"))
        {
            if ((i+2) >= size) {
                fprintf(stderr, "Maybe you missed new size argument\n");
                break;
            }

            if (!atoi(buffer[i+1]))
            {
                if(!strcmp(buffer[i+1], "0")) 
                {
                    fprintf(stderr, "You can't use 0 as an argument!\n");
                    break;
                }    
                fprintf(stderr, "That's not a number!\n");
                break;
            }

            if (!atoi(buffer[i+2]))
            {
                if(!strcmp(buffer[i+1], "0")) 
                {
                    fprintf(stderr, "You can't use 0 as an argument!\n");
                    break;
                }    
                fprintf(stderr, "That's not a number!\n");
                break;
            }

            cropImage(&imageFile, atoi(buffer[i+1]), atoi(buffer[i+2]));
        }

        if (!strcmp(buffer[i], "--crop-percent") || !strcmp(buffer[i], "-crp"))
        {
            if ((i+1) >= size) {
                fprintf(stderr, "Maybe you missed new size argument\n");
                break;
            }

            if (!atoi(buffer[i+1]))
            {
                if(!strcmp(buffer[i+1], "0")) 
                {
                    fprintf(stderr, "You can't use 0 as an argument!\n");
                    break;
                }    
                fprintf(stderr, "That's not a number!\n");
                break;
            }

            cropPercentImage(&imageFile, atoi(buffer[i+1]));
        }
    }

    closeImage(&imageFile);
};