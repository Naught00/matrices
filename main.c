#include <stdio.h>
#include "matrix.h"

int main(void) {
	set_dimensions(80, 40);
	char test[80][40];

	char *f = "test2\n";

	for (; *f != '\0'; f++)
		putchar(*f);

        new_entry('0',"██");
       // new_entry('X', ANSI_COLOUR_PINK "██" ANSI_COLOUR_RESET );
        new_entry('C', ANSI_COLOUR_CYAN "██" ANSI_COLOUR_RESET );
        new_entry('B', ANSI_COLOUR_BLUE "██" ANSI_COLOUR_RESET );
        new_entry('G', ANSI_COLOUR_GREEN "██" ANSI_COLOUR_RESET );
        new_entry('Y', ANSI_COLOUR_YELLOW "██" ANSI_COLOUR_RESET );
        new_entry('R', ANSI_COLOUR_BROWN "██" ANSI_COLOUR_RESET );
	new_entry('.', "  ");

	load_array("test.cell", test);

	display(test);
	for (;;);
}
