#include "image.h"
#include <stdlib.h>

image createImage(const char *filename) {
    FILE *image_file = fopen(filename, "rb");

    if (!image_file) {
        // Всегда ли он должен писать, что такого файла нет?
        // Или могут быть другие ошибки, в случае чего нужно выводить
        // закомментированную фразу
        
        // fprintf(stderr, "Unable to open file %s\n", filename);
        fprintf(stderr, "There's no file named %s\n", filename);
        free(image_file);
        exit(1);
    }
    image new_image;

    new_image.filename = filename;
    new_image.source = image_file;
    new_image.size = getImageSize(&new_image);
    new_image.data = getImageData(&new_image);

    new_image.getName = getImageName;
    new_image.getSize = getImageSize;
    new_image.getData = getImageData;

    return new_image;
}

const char *getImageName(image *imageFile) {
    return imageFile->filename;
}

unsigned long getImageSize(image *imageFile) {
    fseek(imageFile->source, 0, SEEK_END);
    imageFile->size = ftell(imageFile->source);
    fseek(imageFile->source, 0, SEEK_SET);

    return imageFile->size;
}

unsigned char *getImageData(image *imageFile) {
    imageFile->data = (char*)malloc(imageFile->size);

    if (!imageFile->data) {
        fprintf(stderr, "Memory error!\n");
        imageFile->data = (void*)0;
        return imageFile->data;
    }

    fread(imageFile->data, imageFile->size, sizeof(unsigned char), imageFile->source);
    
    return imageFile->data;
}

void closeImage(image *imageFile) {
    free(imageFile->data);
    fclose(imageFile->source);
}