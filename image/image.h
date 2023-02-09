//
// image.h
//
// Created by C0DIC, 06/02/2023
//
// LOCAL CHANGELOG:
//
// 09/02/2023:
//      Removed getImageSize(), getImageData(), getImageName() methods
//      Added extension_type, extension, width, height to Image structre
//      Changed including files
//
//

#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include "../utils/is_image.h"

// Basic image structure
typedef struct Image {
    FILE *source;
    const char *filename;
    unsigned short extension_type;
    const char *extension;
    unsigned char *data;
    unsigned long size;

    unsigned int width;
    unsigned int height;

    // Отключены за ненадобностью
    // Get the name of the image file
    // const char    *(*getName)(struct Image *imageFile);

    // Get the size of the image file
    // unsigned long (*getSize)(struct Image *imageFile);

    // Get the data of the image file
    //unsigned char *(*getData)(struct Image *imageFile);
} image;

// Creates an Image-type variable
image createImage(const char *filename);

// Close the image file and free memory
void closeImage(image *imageFile);

#endif /* image_h */