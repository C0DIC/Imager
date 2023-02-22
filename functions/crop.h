#ifndef CROP_H
#define CROP_H

#include <stdio.h>

#include <png.h>
#include <zlib.h>

#include "../image/image.h"
#include "../functions/copy.h"
#include "../utils/correct_name.h"
#include "../utils/imager_errors.h"
#include <string.h>

void cropImage(image *imageFile, unsigned int width, unsigned int height);
void cropPercentImage(image *imageFile, unsigned int percent);

#endif