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
bool circle_draw_ch(int x, int y, int r, char ch) {
	bool anyThingDrawn = false;

	int relx = -r;	
	int prevy = 0;
	for (int i = 0; i <= r * 2; i++) {	
		float rely = sqrtf((r * r) - (relx * relx));
		bool drawable = false;

		rely = round(rely);

		//term_color(RED);

		drawable = term_pixel_ch(relx + x, rely + y, ch);
		drawable = term_pixel_ch(relx + x, -rely + y, ch);

		if (drawable) {
			anyThingDrawn = true;
		}


		if (i == 0) {
			relx++;
			continue;
		}

		// fill gaps
		int prevx = relx - 1;
		int prevy = round(sqrtf((r * r) - (prevx * prevx)));
		int y1;
		int y2;
		int xToUse;
		
		if (prevy < rely) {
			y1 = prevy;
			y2 = rely;
			xToUse = prevx;
		}
		else {
			y1 = rely;
			y2 = prevy;
			xToUse = relx;
		}

		//int ydiff = prevy - rely;
		int ydiff = y1 - y2;
		int sign = getSign(ydiff);
		for (int a = 1; a < abs(ydiff); a++) {

			// DEBUG stuff
			/*
			   if (a == 1) {
			   term_color(BLUE);
			   }
			   else {
			   term_color(GREEN);
			   }
			   */

			term_pixel_ch(xToUse + x, y2 + (a * sign) + y, ch);
			term_pixel_ch(xToUse + x, -y2 + (a * -sign) + y, ch);
			//term_pixel(relx + x, rely + (a * sign) + y);
			//term_pixel(relx + x, -rely + (a * -sign) + y);
		}

		relx++;
	}	

	//term_color(RESET);

	return anyThingDrawn;
}
bool circle_draw(int x, int y, int r) {
	return circle_draw_ch(x, y, r, '#');
}

#endif
