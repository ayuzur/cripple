#ifndef CIRCLE_C
#define CIRCLE_C
#include <math.h>
#include <stdbool.h>

int getSign(int num) {
	if (num > 0) {
		return 1;
	}
	else if (num < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

bool circle_draw(int x, int y, int r) {
	bool anyThingDrawn = false;

	int relx = -r;	
	int prevy = 0;
	for (int i = 0; i <= r * 2; i++) {	
		float rely = sqrtf((r * r) - (relx * relx));
		bool drawable = false;
		
		drawable = term_pixel(relx + x, rely + y);
		drawable = term_pixel(relx + x, -rely + y);
		
		if (drawable) {
			anyThingDrawn = true;
		}

		relx++;
	}	
	return anyThingDrawn;
}

#endif
