//
//
//  LOCAL CHANGELOG:
//
//  09/02/2023:
//      Changed the help message
//
//
//

#include <stdio.h>
#include <string.h>
#include "terminal.h"
#include "../image/image.h"

const char *terminal_help_text = 
    "Usage: [filename] [options]\n"
    "where\n"
    "      filename := name of the image-file to manipulate (with extension),\n"
    "                  full path to file"
    "\n\n"
    "      options  := {\n"
    "           --copy : Copy image file\n"
    "                    [copy_name (with extension) | full/path/where/to/save]\n\n"
    "           --move : Move/rename image file\n"
    "                    [new_name (with extension) | full/path/where/to/save]\n\n"
    "           --info : Shows information about image file\n"
          "}\n";

void terminal(int argc, const char *argv[], void *(interpreter)(int size, const char **buffer)) {
    switch (argc) {
        case 1: {
            printf(
                "imager: missing filename\nUse «./imager --help» to see the help message\n"
            );
            break;
        }
        case 2: {
            if(!strcmp(argv[1], "--help")) {
                printf("%s", terminal_help_text);
            } else {
                // Если аргумент не --help, а аргументов всего 2
                // (запуск + 2ой аргумент(что угодно, кроме --help, даже название файла))
                printf("Use «./imager --help» to see the help message\n");
            }
            break;
        }
        default:
            interpreter(argc, argv);
            break;
    }
};