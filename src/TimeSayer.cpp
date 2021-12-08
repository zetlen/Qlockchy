#include "./TimeSayer.h"

TimeSayer::TimeSayer() {
	words_on[0] = &PREFIX_IT;
	words_on[1] = &PREFIX_IS;
}

void TimeSayer::setWords(int8_t hour, int8_t minute) {

	int8_t fiveMinutes = minute / 5;

	switch (fiveMinutes) {
	case 0:
		words_on[2] = &EMPTY;
		words_on[3] = &EMPTY;
		break;
	case 1:
		words_on[2] = &EMPTY;
		words_on[3] = &MINUTE_FIVE;
		break;
	case 2:
		words_on[2] = &EMPTY;
		words_on[3] = &MINUTE_TEN;
		break;
	case 3:
		words_on[2] = &EMPTY;
		words_on[3] = &MINUTE_QUARTER;
		break;
	case 4:
		words_on[2] = &EMPTY;
		words_on[3] = &MINUTE_TWENTY;
		break;
	case 5:
		words_on[2] = &MINUTE_TWENTY;
		words_on[3] = &MINUTE_FIVE;
		break;
	case 6:
		words_on[2] = &EMPTY;
		words_on[4] = &MINUTE_HALF;
		break;
	case 7:
		words_on[2] = &MINUTE_TWENTY;
		words_on[3] = &MINUTE_FIVE;
		break;
	case 8:
		words_on[2] = &EMPTY;
		words_on[3] = &MINUTE_TWENTY;
		break;
	case 9:
		words_on[2] = &INDEFINITE_ARTICLE;
		words_on[3] = &MINUTE_QUARTER;
		break;
	case 10:
		words_on[2] = &EMPTY;
		words_on[3] = &MINUTE_TEN;
		break;
	case 11:
		words_on[2] = &EMPTY;
		words_on[3] = &MINUTE_FIVE;
		break;
	}

	int hourIndex = hour += 11;
	if (fiveMinutes > 6) {
		hourIndex -= 11;
		words_on[4] = &INFIX_BEFORE;
		words_on[5] = &HOURS[hourIndex % 12];
	}
	else if (fiveMinutes > 0) {
		words_on[4] = &INFIX_AFTER;
		words_on[5] = &HOURS[hourIndex % 12];
	}
	else {
		words_on[4] = &HOURS[hourIndex % 12];
		words_on[5] = &SUFFIX_OCLOCK;
	}
}