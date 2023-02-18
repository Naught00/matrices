#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct entry {
	char input;
	const char *output;
};

static struct entry newline = {'\n', "\n"}; 
static struct entry *entries; 
static int entries_size = 10;
static int entry_counter = 0;

int HEIGHT = 0;
int WIDTH = 0;

void set_dimensions(const int H, const int W) {
	HEIGHT = H;
	WIDTH = W;
}

void new_entry(char input, const char *output) {
	if (entry_counter == 0) {
		entries = malloc(entries_size * sizeof(struct entry));
		entries[0] = newline;
		/* One entry is already filled. 
		 * Take the size of one entry from the n bytes to fill.
		 */
		memset(&entries[1], 0, entries_size * sizeof(struct entry) - sizeof(struct entry));
		entry_counter++;
	} else if (entry_counter == entries_size) {
		entries = realloc(entries, entries_size * sizeof(struct entry) * 2);
		entries_size *= 2;
	}

	struct entry e = {input, output};
	entries[entry_counter] = e;
	entry_counter++;
};

void display(char array[HEIGHT][WIDTH]) {
	int i, j, k;
	char c;
	for (i = 0, j = 0; i < HEIGHT && j < WIDTH;) {
		c = array[i][j];

		if (c == '\n') {
		        j = 0;
		        i++;
		} else {
		        j++;

		}

		for (k = 0; k < entry_counter; k++) {
		        if (entries[k].input == c) {
				printf("%s", entries[k].output);
		        }
		}
	}
}

void load_array(const char *file_name, char array[HEIGHT][WIDTH]) {
	FILE *f;
	f = fopen(file_name, "r+");

	char c;
	int x, y;
	for (y = 0, x = 0; (c = getc(f)) != EOF;) {
		array[y][x] = c;

		if (c == '\n') {
			y++;
			x = 0;
		}
		x++;
	}
	rewind(f);
}

