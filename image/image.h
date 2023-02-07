//
// image.h
//
// Created by C0DIC, 06/02/2023
//
//

#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>

// Basic image structure
typedef struct Image {
    FILE *source;
    const char *filename;
    unsigned char *data;
    unsigned long size;

    // Get the name of the image file
    const char    *(*getName)(struct Image *imageFile);

    // Get the size of the image file
    unsigned long (*getSize)(struct Image *imageFile);

    // Get the data of the image file
    unsigned char *(*getData)(struct Image *imageFile);
} image;

// Creates an Image-type variable
image createImage(const char *filename);

// Returns the name of the image file
const char *getImageName(image *imageFile);

// Returns the size of the image file
unsigned long getImageSize(image *imageFile);

// Returns the data of the image file
unsigned char *getImageData(image *imageFile);

// Close the image file and free memory
void closeImage(image *imageFile);

#endif /* image_h */