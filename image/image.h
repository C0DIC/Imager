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
// 15/02/2023:
//		Removed non-nedeed code lines
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
    unsigned char *u_data;
    unsigned long size;

    unsigned int width;
    unsigned int height;
} image;

// Creates an Image-type variable
image createImage(const char *filename);

// Close the image file and free memory
void closeImage(image *imageFile);

#endif /* image_h */
