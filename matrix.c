#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct entry {
	char input;
	char *output;
};

static struct entry newline = {'\n', "\n"}; 
static struct entry *entries; 
static int entries_size = 10;

static int HEIGHT = 2;
static int WIDTH = 2;

void set_dimensions(const int H, const int W) {
	HEIGHT = H;
	WIDTH = W;
}

void new_entry(char input, char *output) {
	static int entry_counter;

	if (entry_counter == 0) {
		entries = malloc(entries_size * sizeof(struct entry));
		entries[0] = newline;
		// One entry is already allocated. -8 brings us back 64 bits.
		memset(&entries[1], 0, entries_size * sizeof(struct entry) - 8);
		entry_counter++;
	} else if (entry_counter == entries_size) {
		entries = realloc(entries, entries_size * sizeof(struct entry) * 2);
		entries_size *= 2;
	}

	struct entry e = {input, output};
	entries[entry_counter] = e;
	entry_counter++;
};

void display(char lake[HEIGHT][WIDTH])
{
	int i, j, k;
	char c;
	for (i = 0, j = 0; i < HEIGHT;) {
		c = lake[i][j];

		if (c == '\n') {
		        j = 0;
		        i++;
		} else {
		        j++;

		}

		for (k = 0; k < entries_size; k++) {
		        if (entries[k].input == c) {
				printf("%s", entries[k].output);
		        }
		}
	}
}


int main(void) {

	set_dimensions(2, 2);
	char test[2][2] = {
			   {'1', '\n'},
			   {'.', '\n'}
				     };
	char *f = "test2\n";

	for (; *f != '\0'; f++)
		putchar(*f);

        new_entry('1', "██");
	new_entry('.', "  ");

	display(test);
}
