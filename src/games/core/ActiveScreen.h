#ifndef GAME_CORE_ACTIVESCREEN_H_
#define GAME_CORE_ACTIVESCREEN_H_

namespace core {

enum ActiveScreen {
	SPLASH_SCREEN = 1, MAIN_GAME_SCREEN = 2, FREE_GAME_SCREEN = 4, BONUS_GAME_SCREEN = 8, PAYTABLE_SCREEN = 16, HELP_SCREEN = 32,
};

}

#endif
