#include "crop.h"

void cropImage(image *imageFile, unsigned int width, unsigned int height)
{

    if (width <= 0 || width == imageFile->width) width = imageFile->width;
    if (height <= 0 || height == imageFile->height) height = imageFile->height;

    if (width > imageFile->width || height > imageFile->height)
    {
        fprintf(stderr, "New size can't be bigger than original\n");
        exit(1);
    } 

    /* Create name for new image file */
    char resized_name[256] = "resized_";
    strcat(resized_name, imageFile->filename);
    correctName(resized_name);

    copyImage(imageFile, resized_name);

    unsigned short read_count = 8;
    char imager_img_header[read_count];

    FILE *source_image = fopen(imageFile->filename, "rb");

    fread(imager_img_header, sizeof(unsigned char), read_count, source_image);

    if (png_sig_cmp(imager_img_header, 0, read_count))
    {
        fprintf(stderr, "%s is not a PNG file.\n", imageFile->filename);
        fclose(source_image);
        exit(1);
    }

    png_structp png_file_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!png_file_ptr)
    {
        fprintf(stderr, "[png_file_ptr] can not create readable png struct!\n");
        fclose(source_image);
        exit(1);
    }


    png_infop png_info_ptr = png_create_info_struct(png_file_ptr);

    if (!png_info_ptr)
    {
        fprintf(stderr, "[png_info_ptr] can not read png info!\n");
        fclose(source_image);
        exit(1);
    }

    if (setjmp(png_jmpbuf(png_file_ptr)))
    {
        fprintf(stderr, "[READ PNG FILE] can not read PNG header!\n");
        fclose(source_image);
        exit(1);
    }

    png_init_io(png_file_ptr, source_image);
    png_set_sig_bytes(png_file_ptr, read_count);

    png_read_info(png_file_ptr, png_info_ptr);

    png_byte color_type = png_get_color_type(png_file_ptr, png_info_ptr);
    png_byte bit_depth = png_get_bit_depth(png_file_ptr, png_info_ptr);

    int number_of_interlacing = png_set_interlace_handling(png_file_ptr);
    png_read_update_info(png_file_ptr, png_info_ptr);

    png_bytep *row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * imageFile->height);

    for (int i = 0; i < imageFile->height; i++)
        row_pointers[i] = (png_byte*) malloc(png_get_rowbytes(png_file_ptr, png_info_ptr));
    
    png_read_image(png_file_ptr, row_pointers);

    FILE *copy_image = fopen(resized_name, "wb");

    png_structp write_png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_infop write_info_ptr = png_create_info_struct(write_png_ptr);
    
    png_init_io(write_png_ptr, copy_image);

    unsigned paletteSize = PNG_MAX_PALETTE_LENGTH;
    png_color* palette = (png_color*)png_malloc(write_png_ptr, paletteSize*sizeof(png_color));

    png_set_PLTE(write_png_ptr, write_info_ptr, palette, paletteSize);


    png_set_IHDR(
        write_png_ptr,
        write_info_ptr,
        width,
        height,
        bit_depth,
        color_type,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_BASE,
        PNG_FILTER_TYPE_BASE
    );

    png_write_info(write_png_ptr, write_info_ptr);
    png_write_image(write_png_ptr, row_pointers);
    png_write_end(write_png_ptr, NULL);

    for (int i = 0; i<imageFile->height; i++)
        free(row_pointers[i]);

    free(row_pointers);
    fclose(source_image);
    fclose(copy_image);

    fprintf(stdout, "Image croped successfully.\n");
};

void cropPercentImage(image *imageFile, unsigned int percent)
{
    if (percent <= 0 || percent > 100){
        fprintf(stderr, "Input %% in range from 1 to 100\n");
        exit(1);
    }

    float width = (imageFile->width - (imageFile->width * (percent/100.0)));
    float height = (imageFile->height - (imageFile->height * (percent/100.0)));

    /* Create name for new image file */
    char resized_name[256] = "resized_";
    strcat(resized_name, imageFile->filename);
    correctName(resized_name);

    copyImage(imageFile, resized_name);

    unsigned short read_count = 8;
    char imager_img_header[read_count];

    FILE *source_image = fopen(imageFile->filename, "rb");

    fread(imager_img_header, sizeof(unsigned char), read_count, source_image);

    if (png_sig_cmp(imager_img_header, 0, read_count))
    {
        fprintf(stderr, "%s is not a PNG file.\n", imageFile->filename);
        fclose(source_image);
        exit(1);
    }

    png_structp png_file_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!png_file_ptr)
    {
        fprintf(stderr, "[png_file_ptr] can not create readable png struct!\n");
        fclose(source_image);
        exit(1);
    }


    png_infop png_info_ptr = png_create_info_struct(png_file_ptr);

    if (!png_info_ptr)
    {
        fprintf(stderr, "[png_info_ptr] can not read png info!\n");
        fclose(source_image);
        exit(1);
    }

    if (setjmp(png_jmpbuf(png_file_ptr)))
    {
        fprintf(stderr, "[READ PNG FILE] can not read PNG header!\n");
        fclose(source_image);
        exit(1);
    }

    png_init_io(png_file_ptr, source_image);
    png_set_sig_bytes(png_file_ptr, read_count);

    png_read_info(png_file_ptr, png_info_ptr);

    png_byte color_type = png_get_color_type(png_file_ptr, png_info_ptr);
    png_byte bit_depth = png_get_bit_depth(png_file_ptr, png_info_ptr);

    int number_of_interlacing = png_set_interlace_handling(png_file_ptr);
    png_read_update_info(png_file_ptr, png_info_ptr);

    png_bytep *row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * imageFile->height);

    for (int i = 0; i < imageFile->height; i++)
        row_pointers[i] = (png_byte*) malloc(png_get_rowbytes(png_file_ptr, png_info_ptr));
    
    png_read_image(png_file_ptr, row_pointers);

    FILE *copy_image = fopen(resized_name, "wb");

    png_structp write_png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_infop write_info_ptr = png_create_info_struct(write_png_ptr);
    
    png_init_io(write_png_ptr, copy_image);

    unsigned paletteSize = PNG_MAX_PALETTE_LENGTH;
    png_color* palette = (png_color*)png_malloc(write_png_ptr, paletteSize*sizeof(png_color));

    png_set_PLTE(write_png_ptr, write_info_ptr, palette, PNG_MAX_PALETTE_LENGTH);

    png_set_IHDR(
        write_png_ptr,
        write_info_ptr,
        width,
        height,
        bit_depth,
        color_type,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_BASE,
        PNG_FILTER_TYPE_BASE
    );

    png_write_info(write_png_ptr, write_info_ptr);
    png_write_image(write_png_ptr, row_pointers);
    png_write_end(write_png_ptr, NULL);

    for (int i = 0; i<imageFile->height; i++)
        free(row_pointers[i]);

    free(row_pointers);
    fclose(source_image);
    fclose(copy_image);

    fprintf(stdout, "Image croped successfully.\n");
};