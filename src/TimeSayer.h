#ifndef TIME_SAYER_H
#define TIME_SAYER_H
#include <Arduino.h>
#include "./Words.h"

class TimeSayer {
public:
	TimeSayer();
	const Word* words_on[6];
	void setWords(int8_t hour, int8_t minute);
};

#endif