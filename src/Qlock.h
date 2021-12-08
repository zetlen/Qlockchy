#include <Watchy.h>
#include <Arduino.h>
#include "./TimeSayer.h"
#include "./Jost_Light10pt7b.h"
#include "./Jost_SemiBold10pt7b.h"

class Qlock : public Watchy{
	private:
		// uint8_t row;
		// uint8_t column;
		int16_t x1;
		int16_t y1;
		uint16_t w;
		uint16_t h;
		int8_t wordIndex = -1;
		const Word* currentWord;
		TimeSayer timeSayer;
		void nextWord();
	public:
			Qlock();
			void drawWatchFace();
};