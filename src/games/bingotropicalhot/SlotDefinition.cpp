#include <cstdlib>

#include "SlotDefinition.h"

namespace bingotropicalhot {

/**
 * Minimum possible credit.
 */
const int MIN_CREDIT = 0;

/**
 * Maximum possible credit.
 */
const int MAX_CREDIT = 10000;

/**
 * Credit increment.
 */
const int CREDIT_INCREMENT = 1000;

/**
 * Minimum possible selected lines.
 */
const int MIN_SELECTED_LINES = 9;

/**
 * Maximum possible selected lines.
 */
const int MAX_SELECTED_LINES = 9;

/**
 * Minimum possible line bet.
 */
const int MIN_SINGLE_LINE_BET = 1;

/**
 * Maximum possible line bet.
 */
const int MAX_SINGLE_LINE_BET = 10;

/**
 * List of symbols names.
 */
std::string symbolsNames[SYMBOLS_LENGTH] = { "          ", "          ", "          ",
											 "BAR       ", "SEVEN     ", "PINEAPPLE ", "LEMON     ", "ORANGE    ", "CHERRY    ",
											 "PLUMS     ", "APPLE     ", "WATERMELON", "BELL      ", "          ", "          ",
											 "          ", "          ",
										   };

/**
 * List of symbols types.
 */
std::string symbolsTypes[SYMBOLS_LENGTH] = { "", "", "", "REGULAR", "REGULAR",
											 "REGULAR", "REGULAR", "REGULAR", "REGULAR", "REGULAR", "REGULAR",
											 "REGULAR", "REGULAR", "", "", "", "",
										   };

/**
 * Slot game paytable.
 */
int paytable[COMBINATION_LENGTH][SYMBOLS_LENGTH] = { {
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0
	}, {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0
	}, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, {
		0,
		0, 0, 75, 50, 20, 15, 9, 7, 5, 3, 2, 1, 0, 0, 0, 0
	}, {
		0, 0, 0, 150,
		100, 75, 50, 35, 20, 15, 9, 7, 3, 0, 0, 0, 0
	}, {
		0, 0, 0, 300, 250,
		200, 150, 100, 75, 50, 30, 20, 10, 0, 0, 0, 0
	},
};

/**
 * Lines combinations.
 */
int lines[LINES_LENGTH][REELS_LENGTH] = { { 1, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 2, 2 }, { 0, 1, 2, 1, 0 }, { 2, 1, 0, 1, 2 },
	{ 0, 0, 1, 2, 2 }, { 2, 2, 1, 0, 0 }, { 1, 0, 1, 2, 1 },
	{ 1, 2, 1, 0, 1 },
};

/**
 * Stips in base game for RTP from 90% to 99%.
 */
int baseGameReels[REELS_SET_LENGTH][REELS_LENGTH][REEL_LENGTH] = {
	/*Base game 	Target percent: 90%	Fitness value: 0.00378%*/{ {
			3, 9, 10,
			4, 9, 7, 5, 9, 3, 9, 4, 4, 8, 6, 5, 11, 3, 4, 3, 6, 5, 3, 4, 5,
			9, 5, 3, 4, 3, 8, 7, 4, 10, 6, 4, 6, 9, 5, 7, 7, 12, 3, 11, 6,
			6, 9, 3, 7, 12, 9, 12, 12, 4, 4, 12, 3, 7, 6, 3, 7, 9, 4, 5,
		},
		{
			10, 7, 12, 9, 4, 12, 5, 9, 9, 10, 7, 7, 5, 4, 3, 9, 3, 4, 5,
			3, 6, 11, 3, 7, 3, 3, 3, 5, 3, 7, 9, 4, 6, 10, 6, 3, 12,
			6, 3, 12, 4, 5, 7, 3, 4, 7, 3, 4, 4, 12, 9, 5, 6, 5, 4,
			4, 4, 8, 7, 11, 7, 9, 6,
		}, {
			3, 4, 11, 12, 7, 3, 5, 11,
			4, 6, 5, 5, 4, 9, 10, 5, 5, 9, 9, 7, 6, 9, 4, 5, 3, 7,
			9, 6, 6, 3, 9, 5, 4, 8, 4, 6, 3, 9, 12, 7, 5, 9, 5, 3,
			5, 12, 7, 7, 5, 8, 9, 11, 6, 3, 8, 5, 12, 9, 9, 4, 5, 6,
			3,
		}, {
			4, 3, 3, 3, 3, 3, 9, 6, 8, 3, 7, 9, 5, 4, 3, 3,
			12, 4, 7, 7, 7, 9, 5, 11, 5, 9, 12, 11, 12, 9, 8, 10, 9,
			3, 4, 4, 7, 9, 7, 4, 4, 7, 7, 4, 9, 3, 12, 5, 6, 4, 11,
			11, 6, 4, 4, 4, 9, 3, 8, 6, 9, 4, 12,
		}, {
			3, 9, 4, 11,
			9, 3, 8, 6, 4, 5, 12, 3, 3, 4, 3, 5, 8, 5, 6, 4, 7, 7,
			9, 3, 3, 4, 9, 6, 9, 5, 9, 7, 5, 8, 7, 6, 9, 5, 10, 11,
			12, 12, 7, 12, 6, 3, 4, 3, 6, 4, 4, 7, 6, 3, 7, 6, 10,
			12, 6, 4, 10, 9, 4,
		},
	},
	/*Base game 	Target percent: 91%	Fitness value: 0.00568444%*/{ {
			11, 9,
			7, 9, 5, 3, 7, 4, 4, 4, 9, 6, 5, 4, 7, 4, 12, 3, 5, 3, 7, 4, 10,
			3, 3, 7, 6, 4, 9, 4, 5, 6, 6, 8, 7, 10, 3, 5, 8, 6, 8, 3, 3, 12,
			3, 9, 7, 5, 8, 12, 5, 4, 5, 4, 11, 5, 10, 3, 5, 6, 8, 7, 7,
		}, {
			9, 5, 4, 9, 6, 5, 7, 7, 6, 3, 7, 9, 10, 10, 6, 3, 11, 5, 4, 5,
			3, 4, 6, 8, 8, 7, 5, 4, 7, 4, 6, 7, 11, 3, 5, 7, 3, 7, 8, 3, 5,
			9, 9, 6, 10, 3, 8, 7, 3, 4, 5, 9, 5, 8, 5, 6, 5, 9, 3, 3, 12, 6,
			4,
		}, {
			5, 7, 5, 10, 8, 6, 5, 6, 3, 3, 10, 4, 4, 9, 3, 11, 5, 7,
			5, 4, 5, 4, 12, 7, 5, 4, 9, 6, 5, 3, 4, 7, 3, 8, 7, 6, 5, 9, 6,
			4, 7, 6, 5, 11, 6, 3, 10, 3, 10, 7, 3, 12, 4, 4, 3, 5, 8, 3, 3,
			11, 12, 12, 5,
		}, {
			4, 7, 7, 6, 3, 3, 3, 7, 8, 4, 5, 5, 4, 8, 3,
			12, 4, 5, 6, 5, 8, 9, 3, 10, 6, 8, 8, 7, 4, 4, 9, 9, 9, 6, 5, 6,
			8, 6, 6, 9, 6, 3, 6, 9, 7, 4, 4, 4, 7, 7, 4, 8, 8, 8, 12, 6, 4,
			9, 12, 3, 4, 6, 7,
		}, {
			4, 7, 4, 10, 6, 3, 7, 5, 3, 3, 7, 6, 3,
			7, 5, 4, 8, 4, 6, 4, 12, 4, 7, 4, 7, 7, 7, 3, 3, 4, 7, 8, 8, 8,
			8, 10, 8, 5, 3, 4, 7, 5, 5, 9, 6, 4, 3, 7, 4, 6, 5, 5, 6, 3, 12,
			12, 5, 3, 8, 9, 11, 12, 4,
		},
	},
	/*Base game 	Target percent: 92%	Fitness value: 0.00421%*/{ {
			3, 12, 3,
			3, 4, 7, 7, 8, 10, 5, 12, 7, 3, 6, 3, 11, 4, 4, 9, 6, 4, 9, 9,
			4, 5, 6, 12, 3, 4, 7, 3, 8, 9, 9, 3, 9, 11, 4, 5, 9, 4, 6, 10,
			6, 4, 3, 5, 4, 5, 7, 6, 9, 5, 4, 6, 9, 3, 12, 5, 12, 7, 7, 3,
		},
		{
			10, 12, 9, 4, 5, 9, 3, 5, 9, 3, 5, 6, 10, 5, 3, 5, 7, 10, 6,
			4, 5, 7, 9, 12, 6, 4, 5, 4, 9, 4, 3, 11, 12, 4, 4, 7, 5,
			7, 8, 3, 3, 7, 3, 9, 9, 3, 9, 4, 7, 8, 9, 7, 6, 3, 4, 4,
			9, 3, 9, 7, 7, 7, 5,
		}, {
			5, 9, 12, 3, 9, 3, 4, 10, 5,
			5, 7, 9, 4, 9, 5, 3, 11, 10, 12, 12, 11, 11, 12, 3, 5,
			5, 4, 9, 3, 6, 6, 3, 9, 7, 6, 5, 8, 12, 4, 5, 3, 9, 7,
			9, 7, 6, 4, 4, 3, 3, 7, 8, 5, 7, 6, 7, 3, 7, 9, 6, 4,
			10, 4,
		}, {
			6, 6, 6, 3, 9, 5, 3, 3, 9, 7, 10, 3, 9, 5,
			7, 8, 12, 12, 4, 10, 7, 12, 4, 8, 4, 5, 9, 3, 12, 5, 3,
			4, 4, 6, 9, 3, 6, 6, 6, 5, 7, 3, 4, 4, 4, 3, 5, 9, 3, 7,
			12, 7, 9, 11, 11, 7, 9, 3, 4, 7, 7, 4, 9,
		}, {
			10, 9, 7,
			3, 5, 11, 7, 9, 11, 7, 3, 5, 9, 7, 7, 6, 3, 7, 9, 4, 7,
			3, 9, 4, 5, 11, 3, 5, 9, 8, 7, 3, 11, 3, 5, 3, 12, 4, 6,
			12, 7, 3, 3, 7, 7, 3, 5, 5, 6, 3, 3, 5, 6, 4, 4, 7, 12,
			4, 12, 5, 6, 6, 9,
		},
	},
	/*Base game 	Target percent: 93%	Fitness value: 0.00119444%*/{
		{
			9, 6, 8, 3, 4, 10, 7, 6, 3, 4, 9, 3, 8, 9, 12, 7, 8, 5, 4, 7,
			5, 3, 12, 6, 8, 9, 5, 7, 10, 5, 6, 4, 7, 6, 3, 11, 9, 4,
			7, 5, 3, 10, 5, 3, 4, 12, 6, 5, 3, 11, 4, 5, 7, 6, 8, 4,
			7, 5, 3, 4, 9, 3, 5,
		}, {
			3, 5, 12, 4, 9, 6, 5, 9, 7, 6,
			4, 3, 5, 4, 3, 7, 5, 9, 11, 3, 5, 12, 10, 11, 3, 9, 4,
			10, 6, 3, 4, 7, 6, 3, 10, 5, 6, 7, 3, 5, 9, 7, 4, 6, 7,
			8, 5, 9, 3, 5, 7, 3, 5, 4, 7, 3, 9, 5, 3, 4, 8, 9, 6,
		},
		{
			10, 8, 4, 3, 5, 10, 7, 3, 4, 8, 7, 5, 6, 3, 12, 7, 4, 6, 5, 3,
			11, 6, 9, 7, 11, 5, 4, 10, 5, 4, 3, 6, 4, 9, 5, 7, 9, 8,
			4, 5, 3, 9, 8, 3, 5, 12, 10, 3, 5, 12, 4, 3, 6, 5, 7, 4,
			9, 8, 7, 5, 6, 9, 7,
		}, {
			9, 3, 4, 6, 5, 3, 6, 4, 12, 3,
			11, 4, 10, 3, 8, 4, 5, 3, 6, 8, 7, 9, 3, 4, 9, 12, 3, 8,
			5, 9, 4, 5, 9, 7, 8, 4, 9, 3, 7, 5, 6, 10, 4, 9, 10, 5,
			4, 12, 6, 5, 7, 3, 6, 5, 7, 3, 4, 5, 9, 7, 8, 5, 6,
		}, {
			9, 3, 7, 4, 3, 7, 9, 4, 7, 12, 3, 9, 6, 10, 3, 5, 4, 7,
			3, 5, 7, 3, 5, 4, 9, 11, 3, 12, 9, 11, 8, 6, 3, 8, 6, 5,
			12, 3, 9, 10, 3, 9, 5, 3, 11, 4, 7, 3, 5, 7, 8, 9, 12,
			5, 6, 7, 3, 5, 9, 3, 7, 4, 5,
		},
	},
	/*Base game 	Target percent: 94%	Fitness value: 0.00410222%*/{ {
			7, 3,
			5, 4, 12, 5, 9, 3, 5, 8, 6, 4, 11, 9, 4, 6, 3, 7, 4, 6, 8, 3, 4,
			9, 3, 6, 4, 3, 5, 6, 11, 10, 5, 4, 6, 7, 3, 4, 9, 7, 10, 5, 3,
			6, 10, 5, 8, 7, 5, 4, 7, 5, 4, 3, 8, 4, 6, 5, 7, 4, 5, 6, 8,
		},
		{
			10, 6, 7, 5, 10, 4, 3, 7, 6, 5, 9, 4, 3, 10, 6, 4, 8, 11, 10,
			4, 8, 9, 3, 6, 7, 5, 8, 10, 11, 6, 3, 8, 6, 3, 7, 9, 5,
			6, 4, 12, 9, 8, 3, 6, 5, 3, 7, 4, 3, 5, 6, 7, 9, 6, 4,
			8, 3, 5, 7, 10, 3, 7, 9,
		}, {
			6, 8, 4, 7, 5, 4, 6, 8,
			11, 7, 4, 5, 3, 10, 5, 3, 7, 9, 8, 4, 5, 3, 6, 8, 3, 7,
			4, 6, 9, 3, 6, 4, 3, 5, 6, 7, 9, 3, 4, 5, 8, 7, 4, 5, 9,
			3, 6, 9, 4, 5, 6, 3, 8, 4, 3, 5, 7, 8, 6, 4, 3, 7, 4,
		},
		{
			7, 11, 5, 8, 10, 6, 5, 10, 4, 5, 12, 10, 7, 3, 9, 8, 3, 4, 10,
			3, 6, 9, 11, 10, 9, 8, 3, 5, 6, 4, 5, 8, 9, 3, 4, 5, 3,
			4, 6, 3, 9, 7, 4, 6, 9, 7, 8, 3, 5, 6, 7, 10, 5, 4, 7,
			6, 9, 8, 6, 11, 10, 5, 3,
		}, {
			4, 6, 7, 4, 3, 7, 9, 5,
			7, 12, 4, 3, 5, 6, 11, 3, 9, 6, 5, 3, 4, 5, 6, 3, 7, 6,
			5, 4, 10, 7, 6, 5, 8, 7, 3, 6, 9, 7, 3, 4, 5, 7, 12, 5,
			4, 7, 5, 3, 4, 8, 9, 7, 4, 5, 6, 3, 5, 6, 3, 5, 4, 10,
			11,
		},
	},
	/*Base game 	Target percent: 95%	Fitness value: 0.00674333%*/{ {
			5, 4, 3, 8, 5, 4, 4, 7, 5, 5, 4, 5, 8, 12, 5, 6, 6, 7, 5, 4, 10, 4, 4,
			3, 8, 5, 9, 7, 7, 6, 11, 8, 4, 4, 6, 3, 5, 3, 10, 6, 8, 3, 9, 3,
			4, 6, 8, 3, 9, 10, 4, 7, 7, 8, 5, 6, 3, 6, 7, 4, 5, 7, 3,
		}, {
			4, 9, 5, 7, 4, 8, 5, 7, 4, 8, 6, 10, 5, 3, 7, 4, 7, 5, 10, 5,
			10, 8, 4, 9, 4, 6, 6, 4, 8, 3, 5, 8, 7, 3, 3, 8, 4, 9, 6, 6, 4,
			4, 6, 7, 5, 8, 4, 3, 9, 5, 6, 6, 6, 7, 8, 3, 5, 4, 4, 7, 4, 8,
			11,
		}, {
			5, 7, 8, 4, 8, 3, 5, 7, 6, 8, 3, 5, 4, 10, 10, 7, 4, 3,
			7, 9, 4, 7, 5, 11, 3, 3, 4, 3, 6, 7, 6, 5, 8, 5, 6, 5, 5, 3, 8,
			4, 4, 9, 4, 6, 9, 5, 5, 6, 5, 8, 3, 6, 6, 7, 10, 10, 7, 7, 4, 8,
			7, 10, 9,
		}, {
			6, 3, 5, 4, 6, 5, 3, 7, 7, 6, 5, 5, 11, 8, 3, 7,
			9, 8, 9, 5, 5, 9, 8, 10, 5, 3, 11, 3, 4, 3, 9, 10, 3, 5, 7, 4,
			8, 6, 3, 6, 4, 10, 6, 4, 8, 6, 4, 4, 4, 3, 6, 7, 4, 12, 6, 5, 4,
			7, 5, 7, 3, 5, 8,
		}, {
			4, 8, 5, 6, 3, 3, 6, 7, 7, 4, 5, 7, 3, 5,
			3, 8, 5, 4, 5, 4, 4, 4, 4, 8, 7, 7, 4, 6, 5, 5, 8, 6, 7, 6, 10,
			3, 6, 8, 3, 4, 5, 7, 5, 3, 9, 7, 6, 5, 7, 9, 10, 7, 4, 6, 5, 9,
			4, 4, 8, 5, 4, 10, 4,
		},
	},
	/*Base game 	Target percent: 96%	Fitness value: 0.00108889%*/{ {
			9, 3, 10, 11, 4, 10, 6, 3, 4, 5, 8, 7, 3, 8, 6, 5, 8, 7,
			5, 6, 3, 7, 4, 9, 5, 3, 7, 9, 8, 6, 10, 5, 6, 4, 11, 3,
			8, 4, 5, 6, 12, 3, 5, 6, 3, 5, 9, 3, 10, 11, 4, 10, 6,
			3, 4, 5, 8, 7, 3, 8, 6, 5, 8,
		}, {
			7, 5, 6, 3, 7, 4, 9,
			5, 3, 7, 9, 8, 6, 10, 5, 6, 4, 11, 3, 8, 4, 5, 6, 12, 3,
			5, 6, 3, 5, 4, 3, 8, 6, 7, 9, 3, 4, 5, 9, 3, 10, 11, 4,
			10, 6, 3, 4, 5, 8, 7, 5, 8, 6, 5, 8, 7, 5, 6, 3, 7, 4,
			9, 3,
		}, {
			8, 3, 9, 8, 6, 10, 5, 6, 4, 11, 9, 3, 10, 11,
			9, 3, 10, 11, 4, 10, 6, 3, 4, 5, 8, 7, 3, 8, 6, 5, 8, 7,
			5, 6, 3, 7, 4, 9, 5, 3, 11, 9, 3, 6, 10, 5, 6, 4, 11, 3,
			8, 4, 5, 6, 12, 3, 5, 8, 3, 5, 4, 7, 6,
		}, {
			5, 7, 6, 3,
			4, 6, 7, 3, 5, 8, 7, 4, 6, 12, 4, 5, 11, 10, 7, 9, 3, 6,
			8, 5, 9, 8, 10, 6, 9, 5, 11, 6, 8, 3, 5, 4, 6, 5, 4, 3,
			7, 6, 3, 4, 5, 6, 4, 8, 3, 5, 6, 4, 3, 8, 7, 5, 6, 3,
			10, 6, 8, 3, 9,
		}, {
			4, 7, 9, 3, 10, 11, 5, 4, 8, 3, 6,
			5, 4, 7, 10, 3, 6, 5, 9, 7, 5, 4, 3, 7, 4, 9, 5, 3, 7,
			9, 8, 6, 3, 8, 5, 4, 11, 8, 3, 6, 5, 4, 12, 3, 8, 6, 3,
			4, 6, 3, 8, 6, 9, 3, 10, 11, 4, 10, 6, 3, 4, 5, 8,
		},
	},
	/*Base game 	Target percent: 97%	Fitness value: 0.0113644%*/{ {
			4, 3, 8, 5, 3, 6, 9, 3, 5, 7, 4, 9, 10, 4, 6, 8, 5, 7,
			4, 3, 6, 8, 7, 12, 5, 3, 9, 7, 11, 10, 3, 4, 10, 7, 5,
			4, 6, 9, 3, 6, 8, 3, 5, 6, 10, 3, 6, 7, 11, 4, 5, 3, 8,
			4, 5, 8, 4, 9, 6, 3, 4, 5, 7,
		}, {
			4, 8, 9, 3, 8, 5, 3,
			10, 4, 3, 5, 7, 3, 10, 11, 5, 10, 8, 6, 4, 5, 10, 9, 6,
			4, 5, 3, 7, 6, 8, 4, 6, 12, 5, 4, 3, 6, 9, 8, 7, 5, 3,
			4, 7, 3, 10, 4, 8, 7, 5, 11, 10, 6, 5, 3, 11, 8, 9, 7,
			8, 3, 5, 7,
		}, {
			8, 4, 5, 6, 3, 8, 5, 4, 3, 5, 11, 4, 6,
			3, 7, 8, 10, 3, 6, 7, 9, 11, 5, 4, 10, 6, 5, 3, 9, 5, 7,
			4, 5, 7, 9, 12, 8, 4, 3, 6, 4, 10, 7, 9, 3, 6, 7, 4, 3,
			5, 6, 8, 10, 3, 6, 7, 4, 3, 5, 8, 4, 3, 9,
		}, {
			9, 7, 8,
			6, 3, 7, 8, 5, 7, 3, 6, 4, 5, 9, 3, 6, 8, 4, 3, 8, 5, 3,
			6, 9, 3, 5, 7, 4, 9, 10, 4, 6, 8, 5, 7, 4, 3, 6, 8, 7,
			4, 5, 3, 9, 7, 12, 5, 3, 8, 5, 3, 6, 9, 3, 5, 7, 4, 9,
			10, 4, 6, 8, 5,
		}, {
			7, 5, 6, 3, 8, 6, 7, 4, 3, 5, 12,
			7, 10, 4, 3, 8, 5, 3, 6, 9, 3, 5, 7, 4, 9, 10, 4, 6, 8,
			5, 7, 4, 3, 6, 8, 4, 12, 5, 3, 9, 7, 11, 10, 3, 4, 10,
			7, 5, 4, 6, 9, 3, 6, 8, 3, 5, 6, 10, 3, 6, 7, 11, 4,
		},
	},
	/*Base game 	Target percent: 98%	Fitness value: 0.000278889%*/{
		{
			4, 3, 5, 6, 7, 3, 5, 4, 3, 8, 4, 11, 6, 3, 8, 5, 3, 4,
			7, 10, 8, 6, 5, 4, 7, 5, 10, 4, 6, 12, 9, 6, 4,
			10, 8, 4, 3, 5, 6, 7, 3, 5, 4, 3, 8, 5, 11, 6,
			3, 8, 5, 3, 4, 7, 10, 8, 6, 5, 7, 3, 6, 8, 5,
		},
		{
			9, 3, 7, 5, 6, 7, 10, 3, 6, 4, 8, 3, 7, 5, 4, 8, 3,
			10, 4, 5, 3, 9, 4, 5, 8, 6, 7, 12, 3, 8, 6, 4,
			9, 3, 5, 9, 10, 4, 11, 5, 6, 7, 3, 9, 5, 4, 11,
			5, 6, 8, 3, 4, 6, 7, 5, 10, 4, 5, 3, 7, 6, 5, 8,
		},
		{
			6, 7, 5, 4, 3, 5, 11, 3, 4, 9, 6, 5, 8, 4, 7, 10, 3,
			4, 10, 3, 7, 4, 10, 9, 5, 4, 8, 3, 4, 5, 9, 6,
			8, 12, 6, 3, 5, 11, 8, 6, 3, 4, 5, 9, 6, 5, 10,
			8, 4, 10, 5, 4, 8, 7, 6, 8, 12, 4, 3, 5, 4, 10,
			5,
		}, {
			6, 9, 11, 8, 3, 5, 6, 8, 3, 5, 10, 8, 9,
			6, 5, 4, 3, 7, 6, 3, 8, 4, 5, 6, 4, 7, 6, 3, 8,
			6, 5, 4, 3, 9, 7, 6, 3, 4, 9, 8, 7, 3, 6, 8, 3,
			7, 5, 3, 4, 9, 5, 6, 10, 3, 5, 6, 3, 12, 6, 10,
			8, 4, 5,
		}, {
			4, 10, 9, 5, 8, 4, 3, 5, 6, 7, 3,
			5, 4, 3, 8, 5, 11, 4, 3, 8, 5, 3, 4, 7, 10, 8,
			6, 5, 4, 7, 5, 10, 6, 4, 12, 9, 6, 4, 10, 8, 7,
			6, 9, 3, 8, 9, 4, 3, 6, 10, 9, 3, 8, 7, 4, 3, 9,
			5, 3, 4, 9, 7, 5,
		},
	},
	/*Base game 	Target percent: 99%	Fitness value: 0.00955222%*/{ {
			5, 3, 7, 6, 4, 9, 5, 3, 7, 8, 5, 4, 3, 11, 4, 3, 9, 6,
			5, 3, 7, 8, 4, 6, 8, 3, 6, 11, 9, 3, 6, 4, 9, 7, 5, 4,
			8, 6, 12, 3, 4, 9, 10, 7, 5, 10, 6, 4, 5, 3, 7, 6, 4, 9,
			5, 3, 7, 8, 5, 4, 3, 11, 4,
		}, {
			3, 9, 6, 5, 8, 7, 3, 4,
			6, 8, 3, 6, 11, 9, 3, 6, 4, 9, 7, 5, 4, 8, 6, 12, 3, 4,
			9, 10, 7, 5, 10, 6, 4, 7, 3, 5, 6, 3, 5, 4, 10, 5, 8, 3,
			7, 4, 3, 10, 11, 3, 8, 7, 6, 3, 5, 4, 8, 7, 11, 9, 6,
			12, 5,
		}, {
			5, 9, 3, 7, 5, 10, 8, 6, 10, 5, 4, 6, 5, 8,
			4, 3, 7, 11, 4, 5, 3, 11, 9, 4, 3, 7, 4, 3, 6, 5, 4, 3,
			7, 4, 5, 3, 7, 5, 3, 12, 5, 7, 9, 3, 8, 10, 3, 7, 10, 4,
			5, 8, 7, 5, 9, 4, 10, 8, 11, 4, 10, 8, 6,
		}, {
			9, 3, 5,
			6, 4, 3, 5, 6, 3, 7, 10, 9, 7, 3, 4, 6, 8, 4, 9, 3, 5,
			8, 7, 3, 4, 9, 5, 7, 4, 6, 5, 8, 3, 11, 4, 3, 9, 6, 5,
			4, 6, 8, 4, 5, 6, 3, 5, 11, 9, 8, 6, 3, 7, 9, 6, 3, 4,
			6, 5, 3, 9, 6, 4,
		}, {
			9, 5, 3, 7, 9, 5, 4, 3, 11, 4, 3,
			9, 6, 5, 3, 7, 8, 4, 6, 3, 9, 8, 7, 6, 8, 11, 3, 6, 8,
			3, 4, 8, 5, 12, 7, 3, 9, 10, 4, 5, 3, 6, 4, 5, 9, 3, 4,
			6, 7, 9, 4, 7, 8, 5, 4, 9, 11, 8, 4, 6, 3, 5, 6,
		},
	},
};

/**
 * Minimal reels offsets during spin procedure.
 */
int reelsMinOffset[REELS_LENGTH] = {5, 8, 11, 14, 17};

/**
 * Maximal reels offsets during spin procedure.
 */
int reelsMaxOffset[REELS_LENGTH] = {7, 10, 13, 16, 19};

/**
 * Do symbol balance in order to destroy groups of equal symbols.
 *
 * @param array Reels.
 */
void symbolsBalance(int array[REELS_LENGTH][REEL_LENGTH]) {
	/*
	 * Problems are possible for example if there is only one symbol in the reel.
	 */
	static const int TRYS_LIMIT = REEL_LENGTH * REEL_LENGTH;

	int swap;
	for (int i = 0, a, b, c, t; i < REELS_LENGTH; i++) {
		bool done = true;

		for (int j = 0, k = 1, l = 2; j < REEL_LENGTH;
				j++, k = (k + 1) % REEL_LENGTH, l = (l + 1) % REEL_LENGTH) {
			if ((array[i][j] == array[i][k] || array[i][j] == array[i][l])) {
				t = 0;
				done = false;
				do {
					if (t >= TRYS_LIMIT) {
						break;
					}

					a = rand() % REEL_LENGTH;
					b = (a + 1) % REEL_LENGTH;
					c = (a + 2) % REEL_LENGTH;
					t++;
				} while (array[i][j] == array[i][a]
						 || array[i][j] == array[i][b]
						 || array[i][j] == array[i][c]);

				swap = array[i][j];
				array[i][j] = array[i][a];
				array[i][a] = swap;
			}
		}

		if (done == false) {
			i--;
		}
	}
}

}
