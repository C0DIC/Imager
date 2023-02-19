#include "resize.h"

void resizeImage(image *imageFile, double percent)
{
    image *copy_image = imageFile;

    int new_width = copy_image->width * (percent/100);
    int new_height = copy_image->height * (percent/100);

    for (int i = 16; i < 20; i++)
        if (i != 19) copy_image->data[i] = (int)(ceil((copy_image->data[i] << 8) / 2)) >> 8;
        else copy_image->data[i] = new_width -  (copy_image->data[i - 1] << 8);

    for (int i = 20; i < 24; i++)
        if (i != 23) copy_image->data[i] = (int)(ceil((copy_image->data[i] << 8) / 2)) >> 8;
        else copy_image->data[i] = new_height - (copy_image->data[i - 1] << 8);

    copyImage(copy_image, "resized_test.png");
};