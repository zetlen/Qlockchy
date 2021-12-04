// STARRY HORIZON for Watchy by SQFMI
// Copyright 2021 Dan Delany dan.delany@gmail.com
// Released under free MIT License : https://github.com/dandelany/watchy-faces/blob/main/LICENSE

#ifndef QLOCK_INCLUDES	
#define QLOCK_INCLUDES
#include "Qlock.h"
#include "Words.h"
#endif

const short COLWIDTH = 18;
const short ROWHEIGHT = 20;

Qlock::Qlock(){
	// // start unlit
	// for (short i = 0; i < 110; i++) {
	// 	currentLit[i] = false;
	// }
} //constructor

void Qlock::drawWatchFace() {
  display.fillScreen(GxEPD_WHITE);
	display.setTextColor(GxEPD_BLACK);
	display.setTextWrap(false);
	drawTime();
};

void Qlock::drawTime() {
	Serial.printf("x1: %d, x2: %d, w: %d, h: %d\n", x1, y1, w, h);
	display.setFont(&FreeSans9pt7b);
	display.setTextSize(1);
	display.setTextColor(GxEPD_BLACK);
	display.setTextWrap(false);
	for (int col = 0; col < 11; col++) {
		for (int row = 0; row < 10; row++) {
			char letter = LETTERS[row][col];
			short x = col * COLWIDTH;
			short y = row * ROWHEIGHT + 17;
			display.getTextBounds(String(letter), x, y, &x1, &y1, &w, &h);
			// asprintf(&logStr, "Letter %s getTextBounds output: &x1 = %d, &y1 = %d, &w = %d, &h = %d", letter, x1, y1, w, h);
			// Serial.println(logStr);
			short startCursor = x + (COLWIDTH - w) / 2;
			display.setCursor(startCursor, y);
			if (letter == 'O' || letter == 'F' || letter == 'I') {
				Serial.printf("printing letter %c", letter);
				Serial.printf(" row %d, col %d", row, col);
				Serial.println("");
				Serial.printf("x = %d (col * %d), y = %d (row * %d + 17)", x, COLWIDTH, y, ROWHEIGHT);
				Serial.println("");
				Serial.printf("textBounds: x1 = %d, y1 = %d, w = %d, h = %d", x1, y1, w, h);
				Serial.println("");
				Serial.printf("display.setCursor(%d (%d + (%d - %d) / 2, or (x + (COLWIDTH - w) - 2, %d (y))", startCursor, x, COLWIDTH, w, y);
				Serial.println("");
				Serial.println("");
			}
			display.print(letter);
		}
	}
};

// 	void drawDate() {
// 		String monthStr = monthShortStr(currentTime.Month);
// 		String dayOfWeek = dayShortStr(currentTime.Wday);
// 		display.setFont(&FreeMono9pt7b);
// 		display.setTextColor(GxEPD_WHITE);
// 		display.setTextWrap(false);
// 		char* dateStr;
// 		asprintf(&dateStr, "%s %s %d", dayOfWeek.c_str(), monthStr.c_str(), currentTime.Day);
// 		drawCenteredString(dateStr, 100, 140, true);
// 		free(dateStr);
// 	}

// 	void drawCenteredString(const String& str, int x, int y, bool drawBg) {
// 		int16_t x1, y1;
// 		uint16_t w, h;

// 		display.getTextBounds(str, x, y, &x1, &y1, &w, &h);
// 		//          printf("bounds: %d x %d y, %d x1 %d y1, %d w, %d h\n", 0, 100, x1, y1, w, h);
// 		display.setCursor(x - w / 2, y);
// 		if (drawBg) {
// 			int padY = 3;
// 			int padX = 10;
// 			display.fillRect(x - (w / 2 + padX), y - (h + padY), w + padX * 2, h + padY * 2, GxEPD_BLACK);
// 		}
// 		// uncomment to draw bounding box
// //          display.drawRect(x - w / 2, y - h, w, h, GxEPD_WHITE);
// 		display.print(str);
// 	}