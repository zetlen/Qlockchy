// STARRY HORIZON for Watchy by SQFMI
// Copyright 2021 Dan Delany dan.delany@gmail.com
// Released under free MIT License : https://github.com/dandelany/watchy-faces/blob/main/LICENSE

#ifndef QLOCK_INCLUDES	
#define QLOCK_INCLUDES
#include "Qlock.h"
#include "Words.h"
#endif

GFXcanvas1 canvas(200,200);

Qlock::Qlock(){
	display.setFont(&FreeMonoBold9pt7b);
	display.setTextSize(1);
	display.getTextBounds("W", 0, 0, &x1, &y1, &w, &h);
}; //constructor

void Qlock::drawWatchFace() {
  display.fillScreen(GxEPD_WHITE);
	drawTime();
};

void Qlock::drawTime() {
	Serial.printf("x1: %d, x2: %d, w: %d, h: %d\n", x1, y1, w, h);
	display.setFont(&FreeMono9pt7b);
	display.setTextColor(GxEPD_BLACK);
	display.setTextWrap(false);
	for (int i = 0; i < 10; i++) {
		display.setCursor(2 + ((i + 1) * h), 2);
		Serial.printf("row: %s\n", LETTERS[i]);
		Serial.printf("cursor: %d, %d\n", display.getCursorX(), display.getCursorY());
		display.println(*LETTERS[i]);
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