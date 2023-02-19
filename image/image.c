//
//  LOCAL CHANGELOG:
//
//  09/02/2023:
//      Removed implementations of the methods from image.h        
//      Added IMAGE_TYPE enumerator
//      Added setImageSize(), setImageData(), setImageExtension(), setImageResolution() methods
//      Added getPngRes(), getJpegRes() methods
//      Changed createImage() method
//
//  12/02/2023:
//      Fixed getJpegRes() method
//
//	15/02/2023:
//		Remove non-needed comments
//



#include "image.h"

// Image extension types
enum IMAGE_TYPE {
    JPEG = 1,
    JPG,
    PNG,
    GIF
};

// Sets the image-file size
void setImageSize(image *imageFile) {
    fseek(imageFile->source, 0, SEEK_END);
    imageFile->size = ftell(imageFile->source);
    fseek(imageFile->source, 0, SEEK_SET);
}

// Sets the data of the image from source
void setImageData(image *imageFile) {
    imageFile->data = (unsigned char*)malloc(imageFile->size);

    if (!imageFile->data) {
        fprintf(stderr, "Memory error!\n");
        imageFile->data = (void*)0;
    }

    fread(imageFile->data, imageFile->size, sizeof(unsigned char), imageFile->source);
}

// Sets (unsigned int)data of the image from source
void setImageUData(image *imageFile)
{
    imageFile->u_data = (unsigned char*)malloc(imageFile->size);

    if (!imageFile->data)
    {
        fprintf(stderr, "Read error!\n");
        imageFile->u_data = (void*)0;
    }

    for (int i = 0; i < imageFile->size; i++)
    {
        imageFile->u_data[i] = (unsigned int)imageFile->data[i];
    }
}

// Sets the image extension-type[number] and extenstion[text]
void setImageExtension(image *imageFile) {

    switch (is_imageFile(imageFile->filename)) {
        case JPEG: case JPG: { imageFile->extension_type = JPEG; imageFile->extension = ".jpeg"; break; }
        case PNG:  { imageFile->extension_type = PNG; imageFile->extension = ".png"; break; }
        case GIF:  { imageFile->extension_type = GIF; imageFile->extension = ".gif"; break; }

        default: { imageFile->extension_type = 0; break;}
    }
}

// Algorithm that gets the width and height of PNG-file 
void getPngRes(image *imageFile, unsigned int *imageWidth, unsigned int *imageHeight) {
    for (int i = 16; i < 20; i++) {
        if (i != 19) {
            *imageWidth += imageFile->u_data[i] << 8;
        } else *imageWidth += imageFile->u_data[i];
    }

    for (int i = 20; i < 24; i++) {
        if (i != 23) *imageHeight += imageFile->u_data[i] << 8;
        else *imageHeight += imageFile->u_data[i]; 
    }
}

void getJpegRes(image *imageFile, unsigned int *imageWidth, unsigned int *imageHeight) {
    for (int i = 135; i < 1000; i++) {
        if (imageFile->data[i] == '"') {
            *imageHeight = (imageFile->data[i-6] << 8) + imageFile->data[i-5];
            *imageWidth = (imageFile->data[i-4] << 8) + imageFile->data[i-3];
            break;
        }
    }
}   

void setImageResolution(image *imageFile) {
    switch (imageFile->extension_type) {
        case JPEG: { getJpegRes(imageFile, &imageFile->width, &imageFile->height); break; }
        case JPG:  { getJpegRes(imageFile, &imageFile->width, &imageFile->height); break; }
        case PNG:  { getPngRes(imageFile, &imageFile->width, &imageFile->height); break; }
    
        default: break;
    }
}

image createImage(const char *filename) {
    FILE *image_file = fopen(filename, "rb");

    if (!image_file) {
        fprintf(stderr, "There's no file named %s\n", filename);
        free(image_file);
        exit(1);
    }
    
    image new_image;

    new_image.filename = filename;
    new_image.source = image_file;
    new_image.width = 0;
    new_image.height = 0;
    setImageSize(&new_image);
    setImageData(&new_image);
    setImageUData(&new_image);
    setImageExtension(&new_image);
    setImageResolution(&new_image);

    return new_image;
}

void closeImage(image *imageFile) {
    free(imageFile->data);
    fclose(imageFile->source);
}
