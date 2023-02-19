#include <stdio.h>
#include<stdbool.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<termios.h>
#include "../matrix.h"

void nonblock(int state);
int kbhit();
void move(int d);

struct pos {
	int x;
	int y;
};

static struct pos player = {15, 11};

char test[80][40];

int main(void) {
	set_dimensions(80, 40);

	char *f = "test2\n";

	for (; *f != '\0'; f++)
		putchar(*f);

        new_entry('0',"██");
        new_entry('C', ANSI_COLOUR_CYAN "██" ANSI_COLOUR_RESET );
        new_entry('B', ANSI_COLOUR_BLUE "██" ANSI_COLOUR_RESET );
        new_entry('G', ANSI_COLOUR_GREEN "██" ANSI_COLOUR_RESET );
        new_entry('Y', ANSI_COLOUR_YELLOW "██" ANSI_COLOUR_RESET );
        new_entry('R', ANSI_COLOUR_BROWN "██" ANSI_COLOUR_RESET );
	new_entry('.', "  ");

	load_array("test.mx", test);


	char c;
	int i = 0;
	nonblock(1);

	for (;;) {
		while (!i) {
			usleep(1);
			c = '0';
			i = kbhit();

			if (i != 0) {
				c = fgetc(stdin);
				if (c == 'q')
					i = 1;
				else 
					i = 0;
			}

			if (c == 'j') {
				move(10);
			}

			usleep(10 * 1000);
			system("clear");
			display(test);
		}
	}
}

void move(int d) {
	test[player.y][player.x] = 'B';
	test[player.y][player.x + 1] = 'Y';

	long i;
	int c;
	for (i = -1, c = 1; i < 2; i++, c++) {
	test[player.y + c][player.x + i] = 'B';
	test[player.y + c][player.x + 1] = 'C';
	}

	for (i = -1, c = 1; i < 2; i++, c++) {
	test[player.y + c - 1][player.x-  1 + i] = 'B';
	test[player.y + c][player.x + 1] = 'C';
	}

	player.x++;
};
	

int kbhit()
{
	struct timeval tv;
	fd_set fds;

	tv.tv_sec = 0;
	tv.tv_usec = 0;

	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);
	select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);

	return FD_ISSET(STDIN_FILENO, &fds);
}

void nonblock(int state)
{
	struct termios ttystate;
	tcgetattr(STDIN_FILENO, &ttystate);

	if (state == 1) {
		ttystate.c_lflag &= ~ICANON;
		ttystate.c_cc[VMIN] = 1;
	}
	else if (state == 0) {
		ttystate.c_lflag |= ICANON;
	}

	tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}
