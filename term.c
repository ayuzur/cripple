#ifndef TERM_C
#define TERM_C
#include <stdio.h>
#include <stdbool.h>

int width = 200;
int height = 100;

void term_clear() {
	printf("\033[2J");
}

void term_goto(int x, int y) {
	printf("\033[%d;%dH", y, x);
}

void term_cursv(bool toggle) {
	if (toggle) {
		printf("\033[?25h");
	}
	else {
		printf("\033[?25l");
	}
}

bool term_pixel(int x, int y) {

	if (x < 0 || x > width) {
		return false;
	}
	else if (y < 0 || y > height) {
		return false;
	}

	term_goto(x * 2, y);
	printf("##");
	return true;
}


enum Color {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, RESET};

void term_color(enum Color color) {
	switch(color) {
		case RED:
			printf("\033[31m");
			break;
		case GREEN:
			printf("\033[32m");
			break;
		case YELLOW:
			printf("\033[33m");
			break;
		case BLUE:
			printf("\033[34m");
			break;
		case MAGENTA:
			printf("\033[35m");
			break;
		case CYAN:
			printf("\033[36m");
			break;
		case WHITE:
			printf("\033[37m");
			break;
		case RESET:
			printf("\033[0m");
			break;
	}
}
#endif

