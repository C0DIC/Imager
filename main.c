#include "functions/terminal.h"
#include "functions/interpreter.h"

int main(int argc, const char *argv[]) {
    terminal(argc, argv, interpreter);

    return 0;
}