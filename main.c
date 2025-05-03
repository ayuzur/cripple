#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "term.c"
#include "circle.c"
#include "sleep.c"
#include "ripple.c"

// the amount of ripples you want spawned
#define LEN 5
#define SPEED 1;

int main(int argc, char* argv[]) {
	term_clear();
	term_goto(0, 0);
	srand(time(NULL));

	if (argc == 3) {
		width = atoi(argv[1]) / 2;
		height = atoi(argv[2]);
	}

	//circle_draw(30, 30, 20);
	//term_goto(0, 0);
	//return 0;
	
	ripple_Ripple ripples[LEN];

	for (int i = 0; i < LEN; i++) {
		ripples[i].x = rand() % width;
		ripples[i].y = rand() % width;
		ripples[i].r = rand() % width;
	}

	while (true) {
		term_clear();

		for (int i = 0; i < LEN; i++) {
			
			ripples[i].x;
			ripples[i].y;
			ripples[i].r;

			bool alive = circle_draw(ripples[i].x, ripples[i].y, ripples[i].r);
			
			if (!alive) {
				ripples[i].r = 0;
				ripples[i].x = rand() % width;
				ripples[i].y = rand() % height;
			}

			ripples[i].r += SPEED;
		}
		fflush(stdout);
		sleep_frameSleep();
	}	
	
	return 0;
}
