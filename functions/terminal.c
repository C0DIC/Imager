//
//
//  LOCAL CHANGELOG:
//
//  09/02/2023:
//      Changed the help message
//
//  12/02/2023:
//      Added alternatives for --help command
//      Changed wrong usage message
//      Changed help message
//
//

#include <stdio.h>
#include <string.h>
#include "terminal.h"
#include "../image/image.h"

const char *terminal_help_text = 
    "Usage: FILEname [options...]\n"
    "Manipulate with image files\n\n"
    "Options:\n"
    "   -cp, --copy                     Copy image file\n"
    "                                   [copy_name (with extension) | full/path/where/to/save]\n\n"
    "   -mv, --move                     Move/rename image file\n"
    "                                   [new_name (with extension) | full/path/where/to/save]\n\n"
    "   -cr, --crop                     Crop image\n"
    "                                   new_width, new_height\n"
    "   -crp, --crop-percent            Crop image by percent\n"
    "   -i, --info                      Shows information about image file\n";

void terminal(int argc, const char *argv[], void *(interpreter)(int size, const char **buffer)) {
    switch (argc) {
        case 1: {
            printf(
                "imager: missing filename\nUse -? (-h, --help)  to see the help message\n"
            );
            break;
        }
        case 2: {
            if(!strcmp(argv[1], "--help") || !strcmp(argv[1], "-?") || !strcmp(argv[1], "-h")) {
                printf("%s", terminal_help_text);
            } else {
                printf("Use «./imager --help» to see the help message\n");
            }
            break;
        }
        default:
            interpreter(argc, argv);
            break;
    }
};