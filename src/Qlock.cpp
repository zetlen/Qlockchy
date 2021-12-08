#ifndef QLOCK_INCLUDES	
#define QLOCK_INCLUDES
#include "./Qlock.h"
#include "./TimeSayer.h"
#endif

const short COLWIDTH = 18;
const short ROWHEIGHT = 20;

Qlock::Qlock() {}; //constructor

void Qlock::drawWatchFace() {
	display.fillScreen(GxEPD_WHITE);
	display.setTextColor(GxEPD_BLACK);
	display.setTextWrap(false);
	Serial.printf("hour %d minute %d", currentTime.Hour, currentTime.Minute);
	Serial.println(" ");
	timeSayer.setWords(currentTime.Hour, currentTime.Minute);
	nextWord();
	display.setFont(&Jost_Light10pt7b);
	display.setTextSize(1);
	display.setTextColor(GxEPD_BLACK);
	display.setTextWrap(false);
	for (int row = 0; row < 10; row++) {
		if (row - currentWord->row == 1) {
			Serial.printf("Switching bold OFF due to current word row %d and current row %d", currentWord->row, row);
			Serial.println(" ");
			display.setFont(&Jost_Light10pt7b);
			nextWord();
		}
		for (int col = 0; col < 11; col++) {
			char letter = LETTERS[row][col];
			short x = col * COLWIDTH;
			short y = row * ROWHEIGHT + 17;
			if (currentWord->row == row) {
				if (currentWord->column == col) {
					Serial.printf("Switching bold on at letter %c", letter);
					Serial.printf(" row %d col %d", row, col);
					Serial.println(" ");
					display.setFont(&Jost_SemiBold10pt7b);
				}
				else if (currentWord->column + currentWord->length == col) {
					Serial.printf("Switching bold OFF at letter %c", letter);
					Serial.printf(" row %d col %d", row, col);
					Serial.println(" ");
					display.setFont(&Jost_Light10pt7b);
					nextWord();
				}
			}
			display.getTextBounds(String(letter), x, y, &x1, &y1, &w, &h);
			short startCursor = x + (COLWIDTH - w) / 2;
			display.setCursor(startCursor, y);
			display.fillRect(x, y, w, h, GxEPD_WHITE);
			display.print(letter);
		}
	}
};

void Qlock::nextWord() {
	if (wordIndex < 5) {
		wordIndex++;
		currentWord = timeSayer.words_on[wordIndex];
		Serial.printf("going to next word: row %d col %d len %d", currentWord->row, currentWord->column, currentWord->length);
		Serial.println(" ");
		if (currentWord->length == 0) {
			nextWord();
			Serial.println("next word is EMPTY, continuing...");
		}
	}
	else {
		Serial.println("Word index overflow");
	}
};