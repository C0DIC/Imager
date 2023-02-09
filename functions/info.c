#include "info.h"

void infoImage(image *imageFile) {
    printf (
        "Image name:     %s\n"
        "Extension:      %s\n"
        "Size:           %ld\n"
        "Width x Height: %dx%d\n",

        imageFile->filename,
        imageFile->extension,
        imageFile->size,
        imageFile->width, imageFile->height
    );
}