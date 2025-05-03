#ifndef CIRCLE_C
#define CIRCLE_C
#include <math.h>

void circle_draw(int x, int y, int r) {	
	int ox = -r;	
	for (int i = 0; i <= 2 * r; i++) {	
		// out y
		float oy = sqrtf(abs((r * r) - (ox * ox)));
		term_pixel(ox + x, oy + y);
		ox++;
	}
}

#endif
