#ifndef Words_H
#define Words_H

typedef struct {
	int row;
	int column;
	int length;
}
Word;

const char LETTERS[10][11] = {
 {'I', 'T', 'L', 'I', 'S', 'S', 'A', 'T', 'I', 'M', 'E' }, // 0
 {'A', 'C', 'Q', 'U', 'A', 'R', 'T', 'E', 'R', 'D', 'C' }, // 1
 {'T', 'W', 'E', 'N', 'T', 'Y', 'F', 'I', 'V', 'E', 'X' }, // 2
 {'H', 'A', 'L', 'F', 'B', 'T', 'E', 'N', 'F', 'T', 'O' }, // 3
 {'P', 'A', 'S', 'T', 'E', 'R', 'U', 'N', 'I', 'N', 'E' }, // 4
 {'O', 'N', 'E', 'S', 'I', 'X', 'T', 'H', 'R', 'E', 'E' }, // 5
 {'F', 'O', 'U', 'R', 'F', 'I', 'V', 'E', 'T', 'W', 'O' }, // 6
 {'E', 'I', 'G', 'H', 'T', 'E', 'L', 'E', 'V', 'E', 'N' }, // 7
 {'S', 'E', 'V', 'E', 'N', 'T', 'W', 'E', 'L', 'V', 'E' }, // 8
 {'T', 'E', 'N', 'S', 'E', 'O', 'C', 'L', 'O', 'C', 'K' }, // 9
};

// const char* LETTERS = "ITLISASTIMEACQUARTERDCTWENTYFIVEXHALFBTENFTOPASTERUNINEONESIXTHREEFOURFIVETWOEIGHTELEVENSEVENTWELVETENSEOCLOCK";

const Word PREFIX_IT = {0, 0, 2}; // IT
const Word PREFIX_IS = {0, 3, 2}; // IS

const Word INFIX_BEFORE = {3, 9, 2}; // TO
const Word INFIX_AFTER = {4, 0, 4}; // PAST

const Word SUFFIX_OCLOCK = {9, 5, 6}; // OCLOCK

const Word MINUTE_FIVE = {2, 6, 4}; // FIVE
const Word MINUTE_TEN = { 3, 5, 3 }; // TEN
const Word MINUTE_QUARTER = {1, 2, 7}; // QUARTER
const Word MINUTE_TWENTY = {2, 0, 6}; // TWENTY
const Word MINUTE_HALF = {3, 0, 4}; // HALF

const Word HOURS[12] = {  
	{5, 0, 3}, // ONE
	{6, 8, 3}, // TWO
	{5, 6, 5}, // THREE
	{6, 0, 4}, // FOUR
	{6, 4, 4}, // FIVE
	{5, 3, 3}, // SIX
	{8, 0, 5}, // SEVEN
	{7, 0, 5}, // EIGHT
	{4, 7, 4}, // NINE
	{9, 0, 3}, // TEN
	{7, 5, 6}, // ELEVEN
	{8, 5, 6}, // TWELVE
};
#endif