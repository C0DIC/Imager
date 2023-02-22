#include "imager_errors.h"

void raiseError(const char *restrict text, ...)
{
    va_list args;
    va_start(args, text);

    const char *arg = va_arg(args, const char *);

    while (arg != NULL) {fprintf(stderr, text, arg); arg = va_arg(args, const char *); }
    va_end(args);

    exit(1); 
}