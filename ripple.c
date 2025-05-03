#include <stdio.h>

#include "term.c"
#include "circle.c"


int main() {
	term_clear();
	term_goto(0, 0);

	circle_draw(20, 20, 10);
	
	return 0;
}
