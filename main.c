#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <signal.h>

#include "term.c"
#include "circle.c"
#include "sleep.c"
#include "ripple.c"

// the amount of ripples you want spawned
#define AMOUNT 5
#define SPEED 1
#define FADE 2

void sigint_exit_handler(int sig) {
	term_cursv(true);
	term_clear();
	term_goto(0, 0);
	printf("exiting...\n");
	term_color(RESET);
	exit(0);
}

int main(int argc, char* argv[]) {
	signal(SIGINT, sigint_exit_handler);

	term_clear();
	term_cursv(false);
	term_goto(0, 0);
	srand(time(NULL));

	if (argc == 3) {
		width = atoi(argv[1]) / 2;
		height = atoi(argv[2]);
	}

	//circle_draw(30, 30, 20);
	//term_goto(0, 0);
	//return 0;
	
	ripple_Ripple ripples[AMOUNT];

	for (int i = 0; i < AMOUNT; i++) {
		ripples[i].x = rand() % width;
		ripples[i].y = rand() % width;
		ripples[i].r = rand() % (strlen(bScale) / FADE);
	}

	while (true) {
		term_clear();

		for (int i = 0; i < AMOUNT; i++) {
			
			int x = ripples[i].x;
			int y = ripples[i].y;
			int r = ripples[i].r;

			char ch;
			bool alive;

			if (r * FADE < strlen(bScale)) {
				ch = bScale[r * FADE];
				alive = true;
			}
			else {
				alive = false;
			}
			
			if (!alive) {
				ripples[i].r = 1;
				ripples[i].x = rand() % width;
				ripples[i].y = rand() % height;
				continue;
			}
			circle_draw_ch(x, y, r, ch);

			ripples[i].r += SPEED;
		}
		fflush(stdout);
		sleep_frameSleep();
	}	
	
	return 0;
}
