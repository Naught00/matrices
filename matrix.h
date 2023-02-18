#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>

#define ANSI_COLOUR_RED     "\x1b[31m"
#define ANSI_COLOUR_GREEN   "\x1b[32m"
#define ANSI_COLOUR_YELLOW  "\x1b[38;5;190m"
#define ANSI_COLOUR_PINK  "\x1b[38;5;254m"
#define ANSI_COLOUR_BLUE    "\x1b[34m"
#define ANSI_COLOUR_MAGENTA "\x1b[35m"
#define ANSI_COLOUR_CYAN    "\x1b[36m"
#define ANSI_COLOUR_BROWN "\x1b[38;5;58m"
#define ANSI_COLOUR_RESET   "\x1b[0m"

extern int HEIGHT;
extern int WIDTH;
void load_array(const char* file_name, char array[HEIGHT][WIDTH]);
void set_dimensions(const int H, const int W);
void new_entry(char input, const char *output);
void display(char lake[HEIGHT][WIDTH]);

#endif
