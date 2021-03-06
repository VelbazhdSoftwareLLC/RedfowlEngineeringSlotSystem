#include <cstdlib>

#include "SlotDefinition.h"

namespace tropicalhot {

/**
 * Bonus scatter index in scatters distributions.
 */
const int BONUS_SCATTER_INDEX = 0;

/**
 * Free games scatter index in scatters distributions.
 */
const int FREE_GAMES_SCATTER_INDEX = 1;

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
const int MIN_SELECTED_LINES = 5;

/**
 * Maximum possible selected lines.
 */
const int MAX_SELECTED_LINES = 5;

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

/**
 * List of symbols names.
 */
string symbolsNames[SYMBOLS_LENGTH] = { "          ", "WILD      ",
										"          ", "SEVEN     ", "BAR       ", "PINEAPPLE ", "ORANGE    ",
										"LEMON     ", "WATERMELON", "PLUMS     ", "CHERRY    ", "BELL      ",
										"APPLE     ", "          ", "          ", "BONUS     ", "SCATTER   ",
									  };

/**
 * List of symbols types.
 */
string symbolsTypes[SYMBOLS_LENGTH] = { "", "WILD", "", "REGULAR",
										"REGULAR", "REGULAR", "REGULAR", "REGULAR", "REGULAR", "REGULAR",
										"REGULAR", "REGULAR", "", "", "", "BONUS", "SCATTER",
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
	}, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 }, {
		0,
		0, 0, 15, 10, 10, 8, 8, 5, 5, 4, 3, 0, 0, 0, 0, 0
	}, {
		0, 0, 0, 70, 40,
		25, 20, 18, 15, 12, 10, 10, 0, 0, 0, 0, 0
	}, {
		0, 0, 0, 750, 400, 300,
		200, 180, 150, 120, 100, 75, 0, 0, 0, 0, 0
	},
};

/**
 * Lines combinations.
 */
int lines[LINES_LENGTH][REELS_LENGTH] = { { 1, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 2, 2 }, { 0, 1, 2, 1, 0 }, { 2, 1, 0, 1, 2 },
};

/**
 * Scatter multipliers discret distribution. There are two scatters (one for free games
 * and another for bonus game).
 */
int scatterMultipliers[NUMBER_OF_SCATTERS][COMBINATION_LENGTH] = { {
		0, 0, 0, 1,
		2, 3
	}, { 0, 0, 0, 1, 2, 3 },
};

/**
 * Stips in base game for RTP from 90% to 99%.
 */
int baseGameReels[REELS_SET_LENGTH][REELS_LENGTH][REEL_LENGTH] = {
	/*Base game 	Target percent: 90%	Fitness value: 0.0144696%*/{ {
			9, 15, 9, 11, 9,
			8, 4, 8, 9, 10, 7, 11, 3, 1, 5, 15, 4, 6, 10, 11, 8, 7, 9, 10, 7, 4, 16,
			1, 6, 8, 10, 7, 9, 10, 1, 8, 6, 11, 16, 7, 11, 9, 5, 3, 11, 10, 5, 4,
			11, 5, 8, 1, 6, 3, 4, 11, 6, 10, 11, 9, 3, 5, 10,
		}, {
			8, 11, 9, 7, 1,
			3, 9, 8, 4, 8, 7, 9, 1, 5, 10, 3, 6, 11, 4, 9, 7, 10, 11, 8, 6, 15, 9,
			6, 10, 16, 11, 7, 9, 6, 5, 3, 10, 8, 4, 5, 10, 6, 11, 15, 3, 10, 16, 8,
			5, 7, 11, 1, 10, 6, 5, 4, 1, 7, 11, 8, 9, 10, 11,
		}, {
			8, 10, 4, 5, 10,
			7, 6, 8, 9, 5, 3, 11, 6, 4, 7, 1, 10, 11, 6, 3, 8, 9, 11, 7, 4, 16, 5,
			15, 4, 7, 10, 5, 8, 15, 3, 9, 10, 8, 7, 16, 9, 6, 11, 3, 10, 7, 9, 6,
			10, 5, 7, 16, 3, 9, 11, 8, 1, 10, 4, 8, 11, 9, 1,
		}, {
			11, 1, 8, 10, 11,
			5, 7, 4, 5, 3, 7, 6, 9, 11, 7, 10, 6, 16, 10, 5, 1, 15, 9, 3, 8, 4, 8,
			1, 9, 8, 16, 7, 11, 8, 9, 10, 3, 8, 9, 4, 11, 8, 10, 7, 16, 4, 15, 11,
			4, 6, 11, 5, 10, 9, 6, 3, 5, 9, 6, 7, 3, 10, 11,
		}, {
			6, 3, 8, 7, 10,
			11, 8, 3, 9, 10, 8, 4, 5, 7, 9, 16, 5, 6, 8, 10, 9, 11, 6, 1, 8, 9, 6,
			11, 15, 4, 10, 1, 7, 10, 9, 15, 10, 7, 11, 10, 6, 16, 5, 9, 6, 7, 3, 11,
			10, 8, 5, 4, 16, 6, 9, 5, 3, 4, 11, 8, 3, 1, 7,
		},
	},
	/*Base game 	Target percent: 91%	Fitness value: 0.000688%*/{ {
			9, 7, 11, 9, 4,
			5, 8, 3, 15, 8, 9, 10, 3, 1, 5, 15, 10, 6, 4, 11, 8, 7, 9, 3, 7, 4, 16,
			1, 4, 8, 3, 7, 9, 10, 1, 8, 6, 16, 7, 10, 6, 9, 5, 3, 4, 10, 9, 4, 3, 5,
			8, 1, 6, 5, 4, 11, 6, 10, 11, 9, 3, 5, 10,
		}, {
			8, 11, 9, 7, 1, 3, 9, 8,
			4, 8, 7, 9, 1, 5, 10, 3, 6, 11, 4, 9, 7, 10, 11, 8, 6, 15, 9, 6, 10, 16,
			11, 7, 9, 6, 5, 3, 10, 8, 4, 5, 10, 6, 11, 15, 3, 10, 16, 8, 5, 7, 11,
			1, 10, 6, 5, 4, 1, 7, 11, 8, 9, 10, 11,
		}, {
			8, 10, 4, 5, 10, 7, 6, 8,
			9, 5, 3, 11, 6, 8, 7, 1, 10, 11, 6, 3, 8, 9, 11, 6, 4, 16, 5, 15, 4, 7,
			10, 5, 8, 15, 3, 9, 10, 8, 7, 16, 9, 6, 11, 4, 10, 7, 9, 6, 10, 5, 7,
			16, 3, 9, 11, 8, 1, 10, 4, 3, 11, 9, 1,
		}, {
			11, 1, 8, 10, 11, 5, 7, 10,
			5, 3, 7, 6, 9, 11, 7, 10, 6, 16, 10, 5, 8, 15, 9, 3, 1, 4, 8, 3, 9, 8,
			16, 7, 11, 4, 9, 10, 3, 8, 9, 4, 11, 8, 10, 7, 16, 4, 15, 11, 4, 6, 11,
			5, 10, 9, 6, 8, 5, 9, 6, 7, 3, 10, 11,
		}, {
			6, 3, 8, 7, 10, 11, 8, 3, 9,
			1, 8, 4, 5, 11, 9, 16, 5, 6, 8, 10, 1, 11, 6, 1, 8, 9, 10, 11, 15, 4,
			10, 1, 7, 10, 9, 15, 1, 7, 11, 10, 6, 16, 5, 9, 6, 7, 3, 11, 10, 8, 5,
			4, 16, 6, 9, 5, 7, 4, 11, 8, 3, 1, 7,
		},
	},
	/*Base game 	Target percent: 92%	Fitness value: 0.000832%*/{ {
			6, 1, 7, 11, 5,
			7, 10, 4, 7, 3, 9, 8, 11, 1, 9, 5, 1, 6, 8, 7, 1, 9, 5, 4, 5, 1, 7, 9,
			10, 15, 8, 5, 1, 5, 9, 4, 8, 1, 9, 3, 7, 11, 9, 3, 4, 10, 6, 5, 10, 1,
			9, 4, 8, 9, 1, 10, 4, 1, 8, 7, 3, 5, 8,
		}, {
			16, 6, 7, 8, 4, 5, 10, 9,
			6, 10, 7, 16, 6, 10, 8, 4, 11, 7, 9, 4, 11, 9, 5, 9, 8, 6, 7, 10, 1, 7,
			10, 9, 16, 11, 10, 6, 10, 5, 10, 8, 5, 11, 3, 8, 10, 7, 1, 8, 4, 8, 10,
			4, 3, 7, 1, 9, 6, 7, 16, 8, 6, 11, 9,
		}, {
			1, 10, 15, 9, 1, 9, 5, 10, 4,
			6, 3, 11, 9, 8, 3, 9, 11, 3, 10, 8, 16, 8, 9, 5, 6, 4, 3, 8, 10, 1, 3,
			10, 4, 9, 10, 6, 10, 4, 3, 15, 10, 3, 6, 10, 11, 1, 11, 16, 7, 10, 8, 7,
			1, 9, 8, 4, 10, 5, 16, 6, 15, 10, 9,
		}, {
			9, 4, 8, 10, 11, 3, 7, 6, 11,
			7, 8, 6, 5, 11, 9, 8, 15, 1, 9, 7, 10, 1, 4, 7, 10, 6, 11, 1, 8, 16, 11,
			5, 11, 3, 7, 3, 6, 11, 4, 3, 5, 9, 4, 11, 6, 10, 11, 6, 9, 4, 7, 11, 4,
			8, 7, 5, 10, 11, 8, 5, 8, 7, 5,
		}, {
			1, 10, 9, 1, 5, 3, 9, 16, 3, 9, 10,
			15, 9, 11, 10, 9, 7, 4, 5, 10, 6, 9, 10, 7, 3, 10, 15, 4, 3, 5, 3, 15,
			3, 16, 5, 11, 6, 7, 16, 9, 8, 15, 1, 6, 8, 10, 15, 4, 3, 11, 5, 8, 11,
			4, 8, 15, 8, 3, 16, 7, 10, 6, 9,
		},
	},
	/*Target percent: 93% Fitness value: 93.0%*/{ {
			9, 11, 3, 9, 1, 4, 8, 10, 15, 8,
			9, 4, 7, 1, 5, 15, 4, 6, 7, 11, 8, 7, 9, 10, 11, 4, 16, 1, 6, 8, 10, 7,
			9, 4, 1, 8, 10, 16, 7, 11, 6, 9, 5, 3, 11, 10, 5, 4, 11, 9, 8, 1, 6, 3,
			4, 11, 6, 10, 11, 9, 3, 5, 10,
		}, {
			8, 11, 9, 7, 1, 3, 9, 8, 4, 8, 7, 9,
			1, 5, 10, 3, 6, 11, 4, 9, 7, 10, 11, 8, 6, 15, 9, 6, 10, 16, 11, 7, 9,
			6, 5, 3, 10, 8, 4, 5, 10, 6, 11, 15, 3, 10, 16, 8, 5, 7, 11, 1, 10, 6,
			5, 4, 1, 7, 11, 8, 9, 10, 11,
		}, {
			8, 10, 4, 5, 10, 7, 6, 8, 9, 5, 3,
			11, 6, 8, 7, 1, 10, 11, 6, 3, 8, 9, 11, 6, 4, 16, 5, 15, 4, 7, 10, 5, 8,
			15, 3, 9, 10, 8, 7, 16, 9, 6, 11, 3, 10, 7, 9, 6, 10, 5, 7, 16, 3, 9,
			11, 8, 1, 10, 4, 8, 11, 9, 1,
		}, {
			11, 1, 8, 10, 11, 5, 7, 4, 5, 3, 7,
			6, 5, 11, 7, 4, 6, 16, 10, 5, 1, 15, 9, 5, 3, 4, 8, 1, 9, 3, 16, 7, 11,
			4, 9, 10, 3, 8, 5, 4, 11, 8, 10, 7, 16, 4, 15, 11, 4, 6, 11, 5, 10, 9,
			6, 3, 5, 4, 6, 7, 3, 10, 4,
		}, {
			6, 3, 8, 7, 3, 11, 8, 3, 9, 1, 8, 4, 5,
			7, 9, 16, 5, 6, 8, 10, 9, 11, 6, 4, 8, 9, 6, 11, 15, 4, 10, 1, 7, 10, 9,
			15, 10, 7, 11, 10, 6, 16, 5, 9, 6, 7, 3, 11, 10, 8, 5, 4, 16, 6, 9, 5,
			3, 4, 11, 8, 3, 4, 7,
		},
	},
	/*Target percent: 94% Fitness value: 94.0%*/{ {
			9, 11, 9, 4, 10, 15, 8, 9, 5, 7,
			6, 3, 1, 5, 15, 4, 6, 7, 1, 8, 7, 9, 10, 8, 4, 16, 1, 5, 8, 10, 7, 9,
			10, 1, 8, 6, 16, 7, 4, 6, 9, 10, 4, 11, 5, 4, 10, 5, 8, 1, 4, 6, 3, 4,
			8, 6, 10, 6, 9, 3, 5, 1, 8,
		}, {
			11, 9, 7, 1, 3, 9, 8, 4, 8, 7, 9, 1, 5,
			10, 3, 6, 11, 4, 9, 7, 10, 11, 8, 6, 15, 9, 6, 10, 16, 11, 7, 9, 6, 5,
			3, 10, 8, 4, 5, 10, 6, 11, 15, 3, 10, 16, 8, 5, 7, 11, 1, 10, 6, 5, 4,
			1, 7, 11, 8, 9, 10, 11, 8,
		}, {
			10, 4, 5, 10, 7, 11, 8, 9, 5, 3, 11, 6,
			8, 7, 1, 10, 11, 6, 3, 8, 9, 11, 6, 4, 16, 5, 15, 4, 7, 10, 5, 8, 15, 3,
			9, 10, 8, 7, 16, 9, 6, 11, 3, 10, 7, 9, 6, 10, 5, 7, 16, 3, 9, 11, 8, 1,
			10, 4, 8, 11, 9, 1, 11,
		}, {
			1, 8, 10, 4, 5, 7, 10, 5, 3, 7, 6, 9, 11,
			7, 10, 6, 16, 11, 5, 1, 15, 9, 3, 11, 4, 8, 1, 9, 5, 16, 7, 5, 3, 9, 10,
			3, 8, 9, 4, 11, 8, 10, 7, 16, 4, 15, 11, 4, 6, 11, 5, 10, 9, 6, 3, 5, 9,
			6, 7, 3, 4, 11, 6,
		}, {
			3, 8, 7, 10, 11, 8, 1, 9, 10, 11, 4, 5, 3, 9,
			16, 5, 6, 7, 10, 4, 11, 7, 3, 5, 9, 6, 11, 15, 4, 10, 1, 7, 11, 9, 15,
			10, 7, 11, 4, 6, 16, 5, 9, 6, 7, 4, 11, 10, 8, 5, 4, 16, 6, 9, 5, 7, 4,
			11, 8, 3, 1, 7, 11,
		},
	},
	/*Base game 	Target percent: 95%	Fitness value: 0.000482%*/{ {
			9, 8, 10, 1, 3,
			10, 15, 9, 10, 7, 6, 9, 3, 5, 10, 15, 4, 8, 11, 7, 1, 7, 9, 10, 8, 4,
			16, 1, 5, 8, 11, 7, 9, 10, 3, 8, 6, 16, 7, 4, 8, 9, 5, 4, 11, 10, 5, 6,
			11, 5, 9, 1, 6, 3, 4, 8, 6, 10, 8, 9, 11, 5, 1,
		}, {
			8, 11, 9, 7, 1, 3,
			9, 8, 4, 8, 7, 9, 1, 5, 10, 3, 6, 11, 4, 9, 7, 10, 11, 4, 6, 15, 9, 6,
			10, 16, 11, 7, 9, 6, 5, 3, 10, 8, 4, 5, 10, 6, 11, 15, 3, 10, 16, 8, 5,
			7, 11, 1, 10, 6, 5, 4, 1, 7, 11, 8, 9, 10, 11,
		}, {
			8, 10, 4, 5, 10, 7,
			11, 4, 9, 5, 10, 11, 6, 8, 7, 1, 10, 11, 6, 3, 8, 9, 1, 6, 4, 16, 5, 15,
			4, 7, 10, 11, 8, 15, 3, 9, 10, 11, 3, 16, 9, 6, 11, 3, 10, 7, 9, 11, 10,
			5, 7, 16, 3, 9, 6, 8, 1, 11, 4, 8, 11, 9, 1,
		}, {
			11, 1, 8, 10, 11, 5,
			7, 10, 5, 3, 7, 6, 4, 8, 7, 10, 6, 16, 10, 5, 1, 15, 9, 3, 11, 4, 8, 1,
			9, 8, 16, 7, 11, 8, 9, 10, 3, 11, 9, 4, 11, 8, 6, 7, 16, 4, 15, 11, 4,
			6, 11, 5, 10, 9, 6, 3, 5, 9, 6, 7, 3, 10, 11,
		}, {
			6, 4, 8, 7, 4, 10, 3,
			1, 9, 10, 8, 4, 5, 7, 11, 16, 5, 6, 8, 3, 5, 11, 10, 1, 4, 9, 6, 3, 15,
			8, 10, 11, 7, 6, 9, 15, 5, 7, 11, 4, 9, 16, 5, 10, 6, 7, 3, 9, 10, 8, 5,
			4, 16, 6, 9, 5, 3, 4, 11, 8, 3, 1, 7,
		},
	},
	/*Target percent: 96% Fitness value: 96.0%*/{ {
			9, 11, 9, 8, 10, 15, 8, 9, 10,
			7, 11, 3, 1, 5, 15, 4, 6, 7, 1, 8, 11, 9, 10, 7, 4, 16, 1, 6, 8, 10, 7,
			9, 10, 1, 8, 6, 16, 7, 11, 6, 9, 5, 3, 11, 10, 5, 4, 11, 5, 8, 1, 6, 3,
			4, 6, 10, 11, 9, 3, 4, 10, 1, 8,
		}, {
			11, 9, 7, 1, 3, 9, 8, 4, 8, 7, 9,
			1, 5, 10, 3, 6, 11, 4, 9, 7, 10, 11, 8, 6, 15, 9, 6, 10, 16, 11, 7, 9,
			6, 5, 3, 10, 8, 4, 5, 10, 6, 11, 15, 3, 10, 16, 8, 5, 7, 11, 1, 10, 6,
			5, 4, 1, 7, 11, 8, 9, 10, 11, 8,
		}, {
			10, 4, 5, 10, 7, 6, 8, 10, 5, 8,
			11, 6, 8, 7, 1, 10, 11, 6, 3, 8, 9, 11, 6, 4, 16, 5, 15, 4, 7, 10, 5, 8,
			15, 3, 9, 10, 8, 7, 16, 9, 6, 11, 3, 10, 7, 9, 6, 10, 5, 7, 16, 3, 9,
			11, 8, 1, 10, 4, 8, 11, 9, 1, 11,
		}, {
			1, 8, 10, 11, 5, 7, 4, 5, 3, 7,
			6, 9, 11, 7, 10, 6, 16, 10, 5, 1, 15, 9, 3, 8, 4, 8, 1, 9, 8, 16, 7, 11,
			8, 9, 10, 3, 8, 9, 4, 11, 8, 10, 7, 16, 4, 15, 11, 4, 6, 11, 5, 10, 9,
			6, 3, 5, 9, 6, 7, 3, 10, 11, 6,
		}, {
			3, 8, 7, 10, 11, 5, 4, 9, 3, 8, 4,
			5, 3, 6, 16, 5, 6, 8, 10, 9, 11, 6, 1, 8, 9, 6, 7, 15, 4, 10, 1, 7, 5,
			9, 15, 10, 7, 11, 10, 6, 16, 5, 9, 6, 7, 3, 11, 10, 8, 5, 4, 16, 6, 9,
			5, 3, 4, 11, 8, 3, 1, 7, 11,
		},
	},
	/*Base game 	Target percent: 97%	Fitness value: 0.00084%*/{ {
			9, 11, 10, 9, 8,
			10, 9, 15, 9, 10, 1, 9, 11, 3, 9, 1, 5, 10, 15, 4, 9, 6, 7, 11, 9, 8, 7,
			10, 7, 4, 16, 1, 6, 8, 10, 7, 9, 10, 1, 8, 9, 6, 16, 9, 7, 11, 6, 9, 5,
			3, 9, 11, 10, 5, 9, 4, 3, 9, 5, 8, 9, 1, 6,
		}, {
			3, 4, 11, 6, 10, 11, 9,
			3, 5, 10, 8, 11, 9, 7, 1, 3, 9, 8, 4, 8, 7, 9, 1, 5, 10, 3, 6, 11, 4, 9,
			7, 10, 11, 8, 6, 15, 9, 6, 10, 16, 11, 7, 9, 10, 5, 3, 10, 8, 4, 5, 10,
			1, 6, 11, 15, 3, 10, 16, 8, 5, 7, 1, 8,
		}, {
			6, 5, 4, 1, 9, 11, 8, 9,
			10, 11, 8, 10, 4, 5, 10, 7, 6, 8, 9, 5, 3, 11, 6, 8, 7, 1, 10, 11, 6, 3,
			8, 11, 6, 8, 4, 16, 5, 15, 4, 7, 10, 5, 8, 15, 3, 9, 10, 8, 7, 16, 9, 6,
			11, 3, 10, 7, 9, 6, 10, 5, 7, 16, 3,
		}, {
			9, 11, 8, 1, 6, 10, 4, 3, 11,
			1, 8, 10, 11, 5, 7, 1, 5, 3, 11, 1, 7, 6, 9, 8, 7, 4, 6, 16, 10, 5, 1,
			15, 9, 3, 8, 4, 6, 1, 9, 4, 16, 7, 11, 8, 9, 10, 3, 5, 9, 4, 11, 8, 10,
			7, 16, 3, 15, 11, 4, 6, 3, 5, 10,
		}, {
			9, 6, 3, 5, 9, 6, 7, 3, 10, 11,
			6, 3, 8, 7, 4, 11, 8, 3, 9, 10, 8, 4, 5, 7, 11, 16, 5, 6, 8, 4, 9, 11,
			6, 3, 8, 11, 6, 8, 15, 4, 10, 1, 7, 10, 16, 15, 10, 7, 5, 4, 6, 16, 5,
			9, 6, 7, 3, 11, 10, 8, 5, 4, 16,
		},
	},
	/*Base game 	Target percent: 98%	Fitness value: 0.000188%*/{ {
			9, 7, 15, 9, 5,
			3, 9, 8, 4, 9, 16, 11, 9, 10, 11, 9, 5, 10, 16, 7, 11, 9, 6, 10, 9, 6,
			10, 7, 9, 3, 5, 1, 9, 10, 6, 9, 11, 1, 9, 7, 9, 10, 9, 8, 7, 9, 4, 1, 9,
			6, 10, 11, 5, 7, 8, 15, 9, 1, 8, 10, 9, 8, 1,
		}, {
			3, 4, 11, 6, 10, 11,
			9, 3, 5, 10, 8, 11, 9, 7, 1, 3, 9, 8, 4, 8, 7, 9, 1, 11, 10, 3, 6, 11,
			4, 9, 7, 10, 11, 8, 6, 15, 9, 6, 10, 16, 11, 7, 9, 6, 5, 3, 10, 8, 4, 6,
			10, 6, 11, 15, 3, 10, 16, 8, 5, 7, 10, 1, 10,
		}, {
			6, 5, 4, 1, 7, 11, 8,
			9, 10, 11, 8, 10, 4, 5, 10, 7, 6, 8, 9, 5, 3, 11, 6, 8, 7, 1, 10, 11, 6,
			3, 8, 9, 11, 6, 4, 16, 5, 15, 4, 7, 10, 5, 8, 15, 3, 9, 10, 8, 7, 16, 9,
			6, 11, 3, 10, 7, 9, 6, 10, 5, 7, 16, 3,
		}, {
			9, 11, 8, 1, 10, 4, 8, 11,
			9, 1, 11, 1, 8, 10, 11, 5, 7, 10, 5, 3, 11, 6, 9, 11, 7, 10, 6, 16, 10,
			5, 1, 15, 9, 3, 8, 4, 8, 1, 9, 8, 16, 7, 11, 8, 9, 10, 3, 8, 9, 4, 11,
			8, 10, 7, 16, 4, 15, 11, 4, 6, 11, 11, 10,
		}, {
			9, 6, 3, 5, 9, 6, 7, 3,
			10, 11, 6, 10, 7, 4, 11, 7, 8, 3, 10, 8, 3, 5, 8, 7, 9, 16, 5, 6, 8, 6,
			9, 11, 6, 1, 8, 9, 6, 11, 15, 16, 10, 1, 7, 10, 9, 15, 10, 7, 11, 10, 6,
			16, 5, 9, 6, 7, 3, 11, 10, 8, 5, 4, 16,
		},
	},
	/*Base game 	Target percent: 99%	Fitness value: 0.001084%*/{ {
			9, 11, 8, 4, 10,
			15, 9, 10, 7, 4, 11, 1, 9, 1, 5, 15, 3, 8, 4, 7, 11, 8, 7, 9, 10, 7, 9,
			4, 16, 1, 6, 8, 10, 7, 6, 10, 9, 1, 8, 6, 9, 16, 7, 9, 11, 8, 9, 5, 3,
			11, 9, 10, 5, 9, 11, 5, 8, 9, 1, 6, 9, 6, 4,
		}, {
			11, 6, 10, 11, 9, 3,
			5, 10, 8, 11, 9, 7, 1, 3, 9, 8, 4, 8, 7, 9, 1, 11, 10, 3, 6, 11, 4, 9,
			7, 10, 11, 8, 6, 15, 9, 6, 10, 16, 11, 7, 9, 6, 5, 3, 10, 8, 4, 6, 10,
			6, 11, 15, 3, 10, 16, 8, 5, 7, 11, 1, 10, 6, 5,
		}, {
			4, 1, 7, 11, 8, 9,
			10, 11, 8, 10, 4, 5, 10, 7, 6, 8, 9, 5, 3, 11, 6, 8, 7, 1, 10, 11, 6, 3,
			8, 9, 11, 6, 4, 16, 5, 15, 4, 7, 10, 5, 8, 15, 3, 9, 10, 8, 7, 16, 9, 6,
			11, 3, 10, 7, 9, 6, 10, 5, 7, 16, 3, 9, 11,
		}, {
			8, 1, 10, 4, 8, 11, 9,
			1, 11, 7, 1, 8, 10, 11, 5, 10, 5, 3, 11, 6, 9, 11, 7, 10, 6, 16, 10, 5,
			1, 15, 9, 3, 8, 4, 8, 1, 9, 8, 16, 7, 3, 8, 9, 10, 3, 8, 9, 4, 11, 8,
			10, 7, 16, 11, 4, 15, 11, 4, 6, 11, 10, 9, 6,
		}, {
			3, 5, 9, 6, 7, 3, 10,
			11, 6, 3, 7, 10, 11, 7, 8, 3, 4, 8, 3, 5, 8, 7, 9, 16, 5, 6, 8, 6, 4,
			11, 6, 1, 8, 9, 6, 11, 15, 16, 10, 1, 7, 10, 9, 15, 10, 7, 11, 10, 6,
			16, 5, 9, 6, 7, 3, 11, 10, 8, 5, 4, 16, 6, 9,
		},
	},
};

/**
 * Stips in free games for RTP from 90% to 99%.
 * There should not be bonus game during free games.
 */
int freeGamesReels[REELS_SET_LENGTH][REELS_LENGTH][REEL_LENGTH] = {
	/*Free games 	Target percent: 90%	Fitness value: 0.0144696%*/{ {
			11, 6, 8, 7,
			11, 5, 9, 8, 11, 1, 9, 8, 7, 6, 10, 7, 1, 11, 6, 7, 9, 6, 7, 8, 4, 11,
			1, 9, 5, 8, 3, 4, 1, 5, 10, 6, 16, 4, 1, 9, 10, 3, 10, 8, 3, 11, 1, 5,
			7, 1, 8, 10, 6, 4, 9, 11, 10, 3, 11, 10, 5, 9, 11,
		}, {
			10, 8, 9, 10, 6,
			5, 4, 6, 11, 10, 8, 6, 7, 5, 6, 1, 3, 10, 1, 8, 1, 5, 11, 9, 10, 8, 7,
			1, 10, 11, 9, 8, 6, 10, 11, 1, 9, 3, 7, 3, 10, 16, 3, 8, 7, 4, 11, 5,
			11, 9, 7, 5, 11, 4, 10, 1, 4, 7, 9, 11, 1, 6, 3,
		}, {
			8, 11, 8, 4, 1, 4,
			6, 5, 7, 10, 1, 9, 5, 11, 9, 11, 16, 7, 8, 11, 9, 8, 10, 6, 9, 3, 6, 11,
			7, 1, 16, 8, 9, 3, 1, 16, 4, 6, 1, 5, 8, 11, 8, 10, 6, 1, 7, 9, 1, 7,
			10, 9, 1, 5, 4, 8, 3, 6, 10, 3, 11, 5, 10,
		}, {
			7, 9, 7, 11, 4, 10, 8,
			11, 7, 5, 1, 6, 3, 5, 1, 8, 7, 10, 9, 8, 5, 3, 16, 8, 4, 1, 9, 6, 8, 9,
			11, 6, 3, 9, 7, 11, 5, 9, 1, 10, 7, 11, 16, 8, 1, 11, 1, 3, 10, 11, 4,
			1, 9, 5, 6, 10, 1, 7, 8, 1, 6, 4, 10,
		}, {
			6, 7, 5, 10, 1, 6, 9, 8, 10,
			5, 11, 7, 1, 5, 4, 9, 7, 10, 6, 1, 9, 16, 5, 9, 5, 3, 11, 1, 8, 6, 11,
			9, 8, 3, 8, 11, 10, 1, 4, 6, 11, 1, 4, 3, 6, 11, 7, 3, 6, 10, 8, 11, 7,
			1, 9, 16, 8, 4, 1, 8, 10, 9, 1,
		},
	},
	/*Free games 	Target percent: 91%	Fitness value: 0.000688%*/{ {
			11, 6, 8, 7, 11,
			5, 9, 8, 11, 1, 9, 4, 7, 6, 10, 7, 1, 11, 6, 7, 9, 6, 7, 8, 4, 11, 1, 9,
			5, 8, 3, 4, 1, 5, 10, 6, 16, 4, 1, 9, 10, 3, 10, 8, 3, 11, 1, 5, 7, 1,
			8, 10, 6, 4, 9, 11, 10, 3, 11, 10, 5, 9, 11,
		}, {
			10, 8, 9, 10, 5, 4, 6,
			11, 10, 8, 6, 7, 5, 6, 1, 3, 6, 10, 1, 8, 1, 5, 11, 9, 1, 10, 11, 10,
			16, 9, 8, 6, 11, 1, 9, 3, 10, 7, 3, 10, 8, 7, 3, 8, 7, 4, 11, 5, 11, 9,
			7, 5, 11, 4, 10, 1, 4, 7, 9, 11, 1, 6, 3,
		}, {
			8, 11, 8, 4, 1, 4, 6, 5,
			7, 8, 1, 9, 5, 11, 9, 11, 16, 7, 8, 11, 9, 8, 10, 6, 9, 1, 3, 6, 11, 7,
			1, 16, 8, 9, 3, 1, 16, 4, 9, 1, 5, 8, 11, 8, 1, 10, 6, 7, 1, 7, 10, 9,
			1, 5, 4, 8, 3, 6, 10, 3, 11, 5, 10,
		}, {
			7, 9, 7, 11, 4, 10, 8, 11, 7,
			5, 1, 6, 3, 5, 1, 8, 7, 10, 9, 8, 5, 3, 16, 8, 4, 1, 9, 6, 8, 9, 11, 6,
			3, 9, 7, 11, 5, 9, 1, 10, 7, 11, 16, 8, 1, 11, 1, 3, 10, 11, 4, 1, 9, 5,
			6, 10, 1, 7, 8, 1, 6, 4, 10,
		}, {
			6, 7, 5, 10, 1, 6, 9, 8, 10, 5, 11, 7,
			1, 5, 4, 9, 7, 10, 6, 1, 9, 16, 5, 10, 5, 3, 11, 1, 8, 6, 11, 9, 8, 3,
			8, 11, 10, 1, 4, 6, 11, 1, 4, 3, 6, 11, 7, 3, 6, 8, 9, 11, 7, 9, 1, 16,
			9, 7, 11, 9, 10, 3, 9,
		},
	},
	/*Free games 	Target percent: 92%	Fitness value: 0.000832%*/{ {
			7, 8, 10, 1, 3,
			10, 9, 6, 1, 6, 4, 10, 3, 11, 3, 10, 11, 8, 4, 10, 11, 6, 7, 1, 11, 5,
			7, 6, 10, 3, 9, 8, 11, 5, 8, 11, 16, 9, 11, 10, 7, 11, 1, 9, 7, 8, 10,
			6, 8, 10, 7, 8, 16, 7, 9, 10, 7, 9, 11, 7, 3, 10, 1,
		}, {
			1, 8, 4, 1, 6,
			9, 3, 11, 9, 1, 8, 9, 1, 9, 6, 11, 5, 4, 1, 6, 11, 8, 6, 11, 4, 8, 11,
			3, 6, 11, 5, 3, 10, 11, 6, 10, 8, 10, 11, 4, 6, 7, 10, 11, 7, 10, 1, 11,
			3, 1, 8, 9, 11, 5, 10, 4, 5, 6, 7, 5, 6, 3, 9,
		}, {
			8, 11, 6, 8, 11, 4,
			9, 11, 8, 3, 1, 7, 1, 11, 5, 9, 3, 6, 1, 8, 6, 10, 1, 11, 8, 5, 3, 4,
			11, 10, 1, 5, 6, 11, 6, 10, 7, 16, 10, 8, 4, 8, 11, 9, 7, 6, 1, 8, 9, 1,
			8, 3, 5, 10, 11, 9, 6, 16, 9, 8, 9, 16, 7,
		}, {
			3, 6, 1, 7, 5, 9, 3, 7,
			1, 5, 8, 1, 7, 10, 1, 7, 8, 1, 9, 6, 1, 6, 10, 4, 1, 9, 5, 1, 10, 9, 6,
			5, 11, 1, 9, 8, 11, 4, 3, 6, 5, 3, 5, 6, 4, 8, 10, 4, 1, 8, 5, 1, 10, 8,
			16, 1, 11, 16, 7, 1, 10, 7, 9,
		}, {
			3, 8, 4, 8, 6, 9, 1, 7, 5, 10, 9, 5,
			10, 4, 5, 10, 9, 1, 5, 9, 1, 8, 9, 6, 9, 11, 1, 6, 1, 10, 4, 1, 5, 1, 7,
			10, 9, 10, 4, 9, 10, 9, 11, 5, 3, 9, 7, 5, 1, 9, 5, 1, 10, 9, 1, 9, 3,
			9, 4, 6, 9, 4, 7,
		},
	},
	/*Target percent: 93% Fitness value: 93.0%*/{ {
			11, 6, 8, 7, 11, 5, 9, 8, 11, 1,
			9, 8, 7, 6, 10, 7, 1, 11, 6, 7, 9, 6, 7, 8, 4, 11, 1, 9, 5, 8, 3, 4, 1,
			5, 10, 6, 16, 4, 1, 9, 10, 3, 10, 8, 3, 11, 1, 5, 7, 1, 8, 10, 6, 4, 9,
			11, 10, 3, 11, 10, 5, 9, 11,
		}, {
			10, 8, 6, 9, 10, 6, 5, 4, 11, 10, 8,
			6, 7, 5, 6, 1, 3, 10, 1, 8, 1, 5, 11, 9, 10, 8, 7, 1, 10, 11, 8, 6, 10,
			11, 1, 9, 3, 7, 3, 10, 16, 9, 3, 8, 7, 4, 11, 5, 11, 9, 7, 5, 11, 4, 10,
			1, 4, 7, 9, 11, 1, 6, 3,
		}, {
			8, 11, 8, 4, 1, 4, 6, 5, 7, 10, 1, 9, 5,
			11, 9, 11, 16, 7, 8, 11, 9, 8, 10, 6, 9, 3, 6, 11, 7, 1, 16, 8, 9, 3, 1,
			16, 4, 6, 1, 5, 8, 11, 8, 10, 6, 1, 7, 9, 1, 7, 10, 9, 1, 5, 4, 8, 3, 6,
			10, 3, 11, 5, 10,
		}, {
			7, 9, 7, 11, 4, 10, 8, 11, 7, 5, 1, 6, 3, 5, 1,
			8, 7, 10, 9, 8, 5, 3, 16, 8, 4, 1, 9, 6, 8, 9, 11, 6, 3, 9, 7, 11, 5, 9,
			1, 10, 7, 11, 16, 8, 1, 11, 1, 3, 10, 11, 4, 1, 9, 5, 6, 10, 1, 7, 8, 1,
			6, 4, 10,
		}, {
			6, 7, 5, 10, 1, 6, 9, 8, 10, 5, 11, 7, 1, 5, 4, 9, 7, 10,
			6, 1, 9, 16, 5, 9, 5, 3, 11, 1, 8, 6, 11, 9, 8, 3, 8, 11, 10, 1, 4, 6,
			11, 1, 4, 3, 6, 11, 7, 3, 6, 10, 8, 11, 7, 1, 9, 16, 8, 4, 1, 8, 10, 9,
			1,
		},
	},
	/*Target percent: 94% Fitness value: 94.0%*/{ {
			6, 8, 7, 11, 5, 9, 8, 11, 1, 9,
			8, 7, 6, 10, 7, 1, 11, 6, 7, 9, 6, 7, 8, 4, 11, 1, 9, 5, 8, 3, 4, 1, 5,
			10, 6, 16, 4, 1, 9, 10, 3, 10, 8, 3, 11, 1, 5, 7, 1, 8, 10, 6, 4, 9, 11,
			10, 3, 11, 10, 5, 9, 11, 10,
		}, {
			8, 9, 6, 10, 5, 4, 11, 6, 10, 8, 6, 7,
			5, 6, 1, 3, 10, 1, 8, 1, 5, 11, 9, 10, 8, 7, 1, 10, 11, 10, 16, 9, 8, 6,
			10, 11, 1, 9, 3, 7, 9, 3, 8, 7, 4, 11, 5, 11, 9, 7, 5, 11, 4, 10, 1, 4,
			7, 9, 11, 1, 6, 3, 8,
		}, {
			11, 8, 4, 1, 4, 6, 5, 7, 10, 1, 9, 5, 11, 9,
			11, 16, 7, 8, 11, 9, 8, 10, 6, 9, 3, 6, 11, 7, 1, 16, 8, 9, 3, 1, 16, 4,
			6, 1, 5, 8, 11, 8, 10, 6, 1, 7, 9, 1, 7, 10, 9, 1, 5, 4, 8, 3, 6, 10, 3,
			11, 5, 10, 7,
		}, {
			9, 7, 11, 4, 10, 8, 11, 7, 5, 1, 6, 3, 5, 1, 8, 7,
			10, 9, 8, 5, 3, 16, 8, 4, 1, 9, 6, 8, 9, 11, 6, 3, 9, 7, 11, 5, 9, 1,
			10, 7, 11, 16, 8, 1, 11, 1, 3, 10, 11, 4, 1, 9, 5, 6, 10, 1, 7, 8, 1, 6,
			4, 10, 6,
		},
		{
			7, 5, 10, 1, 6, 9, 8, 10, 5, 11, 7, 1, 5, 4, 9, 7, 10, 6, 1, 9, 16, 5,
			9, 5, 3, 11, 1, 8, 6, 11, 9, 8, 3, 8, 11, 10, 1, 4, 6, 11, 1, 4,
			3, 6, 11, 7, 3, 6, 10, 8, 11, 7, 1, 9, 16, 8, 4, 1, 8, 10, 9, 1,
			7,
		},
	},
	/*Free games 	Target percent: 95%	Fitness value: 0.000482%*/{ {
			11, 6, 8, 7, 11,
			5, 9, 8, 11, 1, 9, 8, 7, 6, 10, 7, 1, 11, 6, 7, 9, 6, 7, 8, 4, 11, 1, 9,
			5, 8, 3, 4, 1, 5, 10, 6, 16, 4, 1, 9, 10, 3, 10, 8, 3, 11, 1, 5, 7, 1,
			8, 10, 6, 4, 9, 11, 10, 3, 11, 10, 5, 9, 11,
		}, {
			10, 8, 6, 9, 10, 6, 5,
			4, 6, 11, 10, 8, 6, 7, 5, 1, 3, 10, 1, 8, 1, 5, 11, 9, 10, 8, 7, 1, 10,
			11, 10, 16, 9, 8, 6, 10, 11, 1, 9, 3, 7, 9, 3, 8, 7, 4, 11, 5, 11, 9, 7,
			5, 11, 4, 10, 1, 4, 7, 9, 11, 1, 6, 3,
		}, {
			8, 11, 8, 4, 1, 4, 6, 5, 7,
			10, 1, 9, 5, 11, 9, 11, 16, 7, 8, 11, 9, 8, 10, 6, 9, 3, 6, 11, 7, 1,
			16, 8, 9, 3, 1, 16, 4, 6, 1, 5, 8, 11, 8, 10, 6, 1, 7, 9, 1, 7, 10, 9,
			1, 5, 4, 8, 3, 6, 10, 3, 11, 5, 10,
		}, {
			7, 9, 7, 11, 4, 10, 8, 11, 7,
			5, 1, 6, 3, 5, 1, 8, 7, 10, 9, 8, 5, 3, 16, 8, 4, 1, 9, 6, 8, 9, 11, 6,
			3, 9, 7, 11, 5, 9, 1, 10, 7, 11, 16, 8, 1, 11, 1, 3, 10, 11, 4, 1, 9, 5,
			6, 10, 1, 7, 8, 1, 6, 4, 10,
		}, {
			6, 7, 9, 5, 10, 9, 1, 6, 9, 8, 10, 9,
			1, 5, 11, 7, 1, 5, 4, 9, 7, 10, 9, 6, 1, 9, 16, 5, 9, 5, 3, 1, 9, 11, 1,
			8, 6, 11, 9, 8, 3, 9, 8, 11, 10, 1, 4, 6, 11, 1, 4, 3, 6, 11, 7, 3, 6,
			10, 8, 11, 7, 1, 9,
		},
	},
	/*Target percent: 96% Fitness value: 96.0%*/{ {
			6, 8, 7, 11, 5, 9, 8, 11, 1, 9,
			8, 7, 6, 10, 7, 1, 11, 6, 7, 9, 6, 7, 8, 4, 11, 1, 9, 5, 8, 3, 4, 1, 5,
			10, 6, 16, 4, 1, 9, 10, 3, 10, 8, 3, 11, 1, 5, 7, 1, 8, 10, 6, 4, 9, 11,
			10, 3, 11, 10, 5, 9, 11, 10,
		}, {
			8, 9, 6, 10, 5, 6, 4, 11, 10, 8, 6, 7,
			5, 6, 1, 3, 10, 1, 8, 1, 5, 11, 9, 10, 8, 7, 1, 10, 11, 10, 16, 9, 8, 6,
			10, 11, 1, 9, 3, 7, 9, 3, 8, 7, 4, 11, 5, 11, 9, 7, 5, 11, 4, 10, 1, 4,
			7, 9, 11, 1, 6, 3, 8,
		}, {
			11, 8, 4, 1, 4, 6, 5, 7, 10, 1, 9, 5, 11, 9,
			11, 16, 7, 8, 11, 9, 8, 10, 6, 9, 3, 6, 11, 7, 1, 16, 8, 9, 3, 1, 16, 4,
			6, 1, 5, 8, 11, 8, 10, 6, 1, 7, 9, 1, 7, 10, 9, 1, 5, 4, 8, 3, 6, 10, 3,
			11, 5, 10, 7,
		}, {
			9, 7, 11, 4, 10, 8, 11, 7, 5, 1, 6, 3, 5, 1, 8, 7,
			10, 9, 8, 5, 3, 16, 8, 4, 1, 9, 6, 8, 9, 11, 6, 3, 9, 7, 11, 5, 9, 1,
			10, 7, 11, 16, 8, 1, 11, 1, 3, 10, 11, 4, 1, 9, 5, 6, 10, 1, 7, 8, 1, 6,
			4, 10, 6,
		},
		{
			7, 5, 10, 1, 6, 9, 8, 10, 5, 11, 7, 1, 5, 4, 9, 7, 10, 6, 1, 9, 16, 5,
			9, 5, 3, 11, 1, 8, 6, 11, 9, 8, 3, 8, 11, 10, 1, 4, 6, 11, 1, 4,
			3, 6, 11, 7, 3, 6, 10, 8, 11, 7, 1, 9, 16, 8, 4, 1, 8, 10, 9, 1,
			7,
		},
	},
	/*Free games 	Target percent: 97%	Fitness value: 0.00084%*/{ {
			6, 9, 5, 3, 4,
			11, 8, 3, 1, 7, 1, 6, 8, 7, 11, 5, 9, 8, 11, 1, 9, 8, 7, 6, 10, 7, 1,
			11, 6, 7, 9, 6, 7, 8, 4, 11, 1, 9, 5, 8, 3, 4, 1, 5, 10, 6, 16, 4, 1, 9,
			10, 3, 10, 8, 3, 11, 1, 5, 7, 1, 8, 10, 6,
		}, {
			4, 9, 6, 11, 10, 3, 11,
			10, 5, 11, 10, 5, 8, 9, 10, 5, 4, 11, 6, 10, 8, 6, 7, 5, 6, 1, 3, 10, 1,
			8, 1, 5, 11, 9, 10, 8, 7, 1, 10, 11, 10, 16, 9, 8, 6, 10, 11, 1, 9, 1,
			7, 9, 3, 8, 7, 4, 11, 5, 11, 9, 7, 5, 7,
		}, {
			4, 10, 1, 4, 7, 9, 11, 1,
			6, 3, 8, 11, 8, 4, 1, 4, 6, 5, 7, 10, 1, 9, 5, 11, 9, 11, 16, 7, 8, 11,
			9, 8, 10, 6, 9, 3, 6, 11, 7, 1, 16, 8, 9, 3, 1, 16, 4, 6, 1, 5, 8, 11,
			8, 10, 6, 1, 7, 9, 1, 7, 10, 9, 1,
		}, {
			5, 4, 8, 3, 6, 10, 3, 11, 5, 10,
			7, 9, 7, 11, 4, 10, 8, 11, 7, 5, 1, 3, 8, 5, 3, 16, 8, 3, 5, 1, 8, 7,
			10, 8, 3, 9, 8, 1, 9, 6, 8, 9, 11, 6, 7, 11, 5, 9, 1, 16, 8, 1, 11, 1,
			3, 7, 11, 3, 10, 11, 4, 1, 9,
		}, {
			5, 6, 9, 10, 1, 9, 7, 6, 1, 9, 6, 4,
			9, 10, 6, 9, 7, 5, 9, 10, 1, 6, 9, 8, 9, 5, 3, 9, 11, 9, 10, 9, 7, 6, 9,
			11, 1, 8, 9, 7, 9, 1, 9, 5, 4, 9, 10, 9, 6, 1, 9, 16, 5, 9, 7, 11, 9, 8,
			3, 9, 8, 11, 9,
		},
	},
	/*Free games 	Target percent: 98%	Fitness value: 0.000188%*/{ {
			6, 9, 5, 3, 4,
			11, 8, 3, 1, 7, 11, 6, 8, 7, 11, 5, 9, 8, 11, 1, 9, 8, 7, 6, 10, 7, 1,
			11, 6, 7, 9, 4, 7, 8, 4, 11, 1, 9, 5, 8, 3, 4, 1, 5, 10, 6, 16, 4, 1, 9,
			10, 3, 10, 8, 3, 11, 1, 5, 7, 1, 6, 10, 6,
		}, {
			4, 9, 11, 10, 3, 11, 10,
			5, 9, 11, 10, 8, 9, 6, 10, 5, 6, 4, 11, 10, 8, 6, 7, 5, 1, 6, 3, 10, 1,
			8, 1, 5, 11, 1, 5, 8, 7, 1, 10, 11, 10, 16, 9, 8, 6, 10, 11, 1, 9, 3, 7,
			9, 3, 8, 7, 4, 11, 5, 11, 9, 7, 5, 11,
		}, {
			4, 10, 1, 4, 7, 9, 11, 1,
			10, 4, 1, 3, 8, 11, 8, 4, 1, 6, 5, 7, 1, 9, 5, 11, 9, 11, 1, 7, 8, 11,
			9, 8, 10, 6, 11, 9, 3, 11, 7, 1, 16, 8, 9, 3, 1, 16, 4, 6, 1, 5, 8, 11,
			8, 10, 6, 1, 7, 9, 1, 7, 10, 9, 1,
		}, {
			5, 4, 8, 3, 6, 10, 3, 11, 5, 10,
			7, 9, 7, 11, 4, 10, 8, 11, 7, 5, 1, 6, 3, 5, 1, 8, 7, 10, 9, 8, 5, 3,
			16, 8, 4, 1, 9, 6, 8, 3, 9, 7, 11, 5, 9, 1, 10, 7, 11, 16, 1, 8, 11, 1,
			3, 10, 4, 9, 11, 6, 4, 1, 9,
		}, {
			5, 6, 9, 10, 1, 9, 7, 8, 9, 1, 6, 4,
			10, 6, 7, 5, 1, 6, 5, 9, 8, 10, 5, 11, 7, 1, 5, 4, 9, 7, 10, 6, 1, 9,
			16, 5, 9, 5, 3, 11, 1, 8, 6, 11, 9, 8, 3, 9, 8, 11, 9, 10, 1, 9, 4, 6,
			9, 11, 1, 9, 4, 3, 9,
		},
	},
	/*Free games 	Target percent: 99%	Fitness value: 0.001084%*/{ {
			5, 3, 4, 11, 8,
			3, 1, 7, 11, 6, 8, 7, 11, 5, 9, 8, 11, 1, 9, 8, 7, 6, 10, 7, 1, 11, 6,
			7, 9, 4, 7, 8, 4, 11, 1, 9, 5, 8, 3, 4, 1, 5, 10, 6, 16, 4, 1, 9, 10, 3,
			10, 8, 3, 11, 1, 5, 7, 1, 8, 10, 6, 4, 9,
		}, {
			11, 10, 6, 3, 11, 6, 10,
			5, 9, 11, 10, 8, 9, 10, 5, 4, 11, 10, 8, 6, 7, 5, 6, 1, 3, 10, 1, 8, 1,
			5, 11, 1, 5, 8, 7, 1, 10, 11, 10, 16, 9, 8, 6, 10, 11, 1, 9, 3, 7, 9, 3,
			8, 7, 4, 11, 5, 11, 9, 7, 5, 11, 4, 10,
		}, {
			1, 4, 7, 9, 11, 1, 4, 6, 1,
			3, 8, 11, 8, 4, 1, 6, 5, 7, 10, 1, 9, 5, 11, 9, 11, 1, 7, 8, 11, 9, 8,
			10, 9, 3, 11, 7, 1, 11, 16, 8, 9, 3, 1, 16, 4, 6, 1, 5, 8, 11, 8, 10, 6,
			1, 7, 9, 1, 7, 10, 9, 1, 5, 4,
		}, {
			8, 3, 6, 10, 3, 11, 5, 10, 7, 9, 7,
			11, 4, 10, 8, 11, 7, 5, 1, 6, 3, 5, 1, 8, 7, 10, 9, 8, 5, 3, 16, 8, 4,
			1, 9, 6, 8, 3, 9, 7, 11, 5, 9, 1, 10, 7, 11, 16, 8, 1, 11, 1, 3, 10, 4,
			9, 11, 6, 4, 1, 9, 5, 6,
		}, {
			10, 1, 9, 7, 8, 9, 1, 6, 4, 10, 6, 7, 5,
			1, 6, 5, 9, 8, 10, 5, 11, 7, 1, 5, 4, 9, 7, 10, 9, 6, 1, 9, 16, 5, 9, 5,
			3, 11, 9, 1, 8, 9, 6, 11, 9, 8, 3, 9, 8, 11, 9, 10, 1, 9, 4, 6, 9, 11,
			1, 9, 4, 3, 9,
		},
	},
};

/**
 * Free spins multipliers discrete distribution. Each win in free games mode should be multiplied by single selected random number from this distribution.
 */
int freeMultiplierDistribution[FREE_MULTIPLIER_DISTRIBUTION_LENGTH] = { 1, 2, 3,
																		1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
																		1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
																		1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2
																	  };

/**
 * Base game scatter discrete distribution. First scatter determines the win of the bonus game. Second scatter determines the number of free games to be played.
 */
int baseScatterDistritution[NUMBER_OF_SCATTERS][BASE_SCATTER_DISTRIBUTION_LENGTH] = {
	{
		10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20,
		30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30,
		10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10,
		20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20,
		30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30,
		10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10,
		20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20,
		30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30,
		10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10,
		20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20,
		30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30,
		10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10,
		20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30, 10, 20, 30
	}, {
		3,
		5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3,
		5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3,
		5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3,
		5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3,
		5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3,
		5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3,
		5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3,
		5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3,
		5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3,
		5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3,
		5, 9, 15, 3, 5, 9
	},
};

/**
 * Free spins scatter discrete distribution. First scatter determines the win of the bonus game and in free games mode there should no be bonus game. Second scatter determines the number of free games to be played.
 */
int freeScatterDistritution[NUMBER_OF_SCATTERS][FREE_SCATTER_DISTRIBUTION_LENGTH] = {
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	}, {
		3, 5, 9, 15,
		3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15,
		3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15,
		3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15,
		3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15,
		3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15,
		3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15,
		3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15,
		3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15,
		3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15,
		3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15, 3, 5, 9, 15,
		3, 5, 9
	},
};

/**
 * Minimal reels offsets during spin procedure.
 */
int reelsMinOffset[REELS_LENGTH] = { 5, 8, 11, 14, 17 };

/**
 * Maximal reels offsets during spin procedure.
 */
int reelsMaxOffset[REELS_LENGTH] = { 7, 10, 13, 16, 19 };

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
