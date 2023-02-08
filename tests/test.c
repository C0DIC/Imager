#include "../image/image.h"
#include "../functions/copy.h"
#include "../functions/terminal.h"
#include "../functions/interpreter.h"
#include <stdio.h>

int main(int argc, const char *argv[]) {
    terminal(argc, argv, interpreter);
    return 0;
}