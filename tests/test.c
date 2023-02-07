#include "../image/image.h"
#include "../functions/copy.h"
#include <string.h>

int main(int argc, const char *argv[]) {
    image image_file = createImage(argv[1]);

    if (!argv[2]) {
        // Сейчас --help нет, запись на будущее
        fprintf(stdout, "Use --help for using guide\n");
    } else {
        if (!strcmp(argv[2], "--copy")) {
            if (argv[3])
                copyImage(&image_file, argv[3]);
            else
                fprintf(stdout, "Write the name of the copy (with extension) after --copy key\n");
        }
    }

    closeImage(&image_file);
    return 0;
}