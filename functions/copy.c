#include "copy.h"
#include <stdlib.h>

void copyImage(image *imageFile, const char *copy_name) {
    FILE *copy_file = malloc(sizeof(imageFile->size));
    copy_file = fopen(copy_name, "w+");

    if (!copy_file) {
        fprintf(stderr, "Unable to create copy of the %s\n", imageFile->filename);
        free(copy_file);
        exit(1);
    }

    fwrite(imageFile->data, sizeof(unsigned char), imageFile->size, copy_file);
    fclose(copy_file);

    fprintf(stdout, "Image copied successfully.\n");
}