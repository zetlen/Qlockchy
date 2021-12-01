#include <Watchy.h>
#include <Arduino.h>
#include <Fonts/FreeMono9pt7b.h>

class Qlock : public Watchy{
	private:
		int16_t x1;
		int16_t y1;
		uint16_t w;
		uint16_t h;
	public:
			Qlock();
			void drawWatchFace();
			void drawTime();
};