Library for mapping 2D array values to a formatted output.

# Usage
The dimensions of the display output must first be defined

		char array[80][40];
		set_dimensions(80, 40);

The dimensions of the display need not match that of the array. It is possible to only output a portion of the array by passing in the address of the starting element. 

A function to load the array from a file is provided

		load_array("test.mx", test);

Now mappings must defined for each of the possible array values

		new_entry('B', ANSI_COLOUR_BLUE "██" ANSI_COLOUR_RESET );

This entry declares that the character 'B' should be formatted as a blue Unicode block. The library provides ``ANSI_COLOUR_`` macros for the 8 ANSI colour escape codes. 

Once the array is loaded with its values and the mappings are set, the array can then be displayed
	
		display(array);

Characters that are read from the array with no entries will be ignored. 

# Example

See ``examples/main.c``


