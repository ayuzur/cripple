#ifndef SLEEP_C
#define SLEEP_C
#define FPS 20

#ifdef _WIN32
	#include <windows.h>
	#define MILI_IN_SEC 1000
	#define MPF (float) MILI_IN_SEC / FPS 
	#define SPF MPF / MILI_IN_SEC
	void sleep_frameSleep() {
		Sleep(MPF);
	}
#else
	#include <time.h>
	#define NANO_IN_SEC 1000000000
	#define NPF (float) NANO_IN_SEC / FPS
	#define SPF NPF / NANO_IN_SEC

	struct timespec spf = {0, NPF};
	void sleep_frameSleep() {
		nanosleep(&spf, NULL);
	}
#endif

#endif
