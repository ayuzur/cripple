#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "term.c"
#include "circle.c"
#include "sleep.c"
#include "ripple.c"


int main() {
	term_clear();
	term_goto(0, 0);
	srand(time(NULL));

	int radius = 10;
	int x = rand() % width;
	int y = rand() % height;

	while (true) {
		term_clear();
		bool alive = circle_draw(x, y, radius);
		
		if (!alive) {
			radius = 1;
			x = rand() % width;
			y = rand() % height;
		}

		sleep_frameSleep();
		radius++;
	}
	
	return 0;
}
