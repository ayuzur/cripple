#ifndef TERM_C
#define TERM_C
#include <stdio.h>
#include <stdbool.h>

term_clear() {
	printf("\033[2J");
}

term_goto(int x, int y) {
	printf("\033[%d;%dH", y, x);
}

term_cursv(bool toggle) {
	if (toggle) {
		printf("\033[?25h");
	}
	else {
		printf("\033[?25l");
	}
}

#endif

