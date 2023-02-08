//
// terminal.h
//
// Created by C0DIC, 08/02/2023
//
//

#ifndef TERMINAL_H
#define TERMINAL_H

// Function to process command-line arguments
void terminal(int argc, const char *argv[], void *(interpreter)(int size, const char **buffer));

#endif /* terminal_h */