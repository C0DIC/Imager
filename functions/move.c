//
//  LOCAL CHANGELOG:
//
//  12/02/2023:
//      Bugfix (if block never entered, cuz of missed ! before rename())
//
//
//
//


#include "move.h"

void moveImage(image *imageFile, const char *new_filename) {
    if (!rename(imageFile->filename, new_filename)) {
        imageFile->filename = new_filename;
        printf("File moved successfully.\n");
    };
}