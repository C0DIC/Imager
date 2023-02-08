#include "copy.h"
#include <stdlib.h>

void copyImage(image *imageFile, const char *copy_name) {
    FILE *copy_file = malloc(sizeof(imageFile->size));
    copy_file = fopen(copy_name, "w+");

    if (!copy_file) {
        // Оставлен изначальных вариант, так как
        // была добавлена возможность автоматического создания 
        // названия для копии фото

        // Всегда ли ошибка в том, что пользователь не ввел название для копии?
        //fprintf(stderr, "Input the name of the copy file\n");
        fprintf(stderr, "Unable to create copy of the %s\n", imageFile->filename);

        // Решение, объединяющее первый и второй вариант (??)
        // fprintf(stderr, "Unable to create copy of the %s. Maybe you missed the name of the copy file?\n", imageFile->filename);
        free(copy_file);
        exit(1);
    }

    fwrite(imageFile->data, sizeof(unsigned char), imageFile->size, copy_file);
    fclose(copy_file);

    fprintf(stdout, "Image copied successfully.\n");
}