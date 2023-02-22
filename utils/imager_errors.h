#ifndef IMAGER_ERRORS_H
#define IMAGER_ERRORS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void raiseError(const char *text, ...);

#endif