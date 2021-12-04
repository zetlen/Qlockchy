#include <Watchy.h>
#include <Arduino.h>
#include <Fonts/FreeSans9pt7b.h>

// typedef struct {
// 	int x;
// 	int y;
// 	char letter;
// 	GFXfont font;
// }

class Qlock : public Watchy{
	private:
		// uint8_t row;
		// uint8_t column;
		int16_t x1;
		int16_t y1;
		uint16_t w;
		uint16_t h;
	public:
			Qlock();
			void drawWatchFace();
			void drawTime();
};