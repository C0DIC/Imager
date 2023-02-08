
#include "move.h"

void moveImage(image *imageFile, const char *new_filename) {
    if (rename(imageFile->filename, new_filename)) {
        imageFile->filename = new_filename;
        fprintf(stdout, "File moved successfully.\n");
    };
}