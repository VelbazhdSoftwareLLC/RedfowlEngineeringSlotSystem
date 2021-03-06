#include "BingoSteamHot.h"

#include <cstdlib>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "../core/CommonState.h"
#include "../core/Persistence.h"
#include "../core/Visualization.h"
#include "../core/FiniteStateMachine.h"

#include "EventLoop.h"
#include "SlotState.h"
#include "SlotDefinition.h"

namespace bingosteamhot {

int main12(int argc, char *argv[], unsigned long &session) {
	/*
	 * Seed internal PRNG.
	 */
	srand(time(NULL));

	/*
	 * Obtain game title.
	 */
	core::CommonState::title = TITLE;
	core::Persistence::connectDb(argc, argv);

	/*
	 * Register into the database.
	 */
	core::Persistence::registerGame(core::CommonState::title, core::CommonState::rtp);
	core::Persistence::registerSession(session, core::CommonState::credit);
	core::CommonState::sessionId = session;
	core::Persistence::adjustDenomination(core::CommonState::denomination);

	/*
	 * Open graphic mode.
	 */
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		return ( EXIT_SUCCESS);
	}

	/*
	 * Open TTF mode.
	 */
	if (TTF_Init() != 0) {
		return ( EXIT_SUCCESS);
	}

	/*
	 * Create canvas.
	 */
	if (!(core::window = SDL_CreateWindow("Slot Reels Animation", 0, 0,
										  CANVAS_WIDTH, CANVAS_HEIGHT, 0))) {
		SDL_Quit();
	}
	core::canvas = SDL_GetWindowSurface(core::window);

	/*
	 * Reset finite state machine.
	 */
	core::FiniteStateMachine::reset();

	/*
	 * Game loop.
	 */
	loop();

	/*
	 * Close TTF mode.
	 */
	TTF_Quit();

	/*
	 * Close graphic mode.
	 */
	SDL_Quit();

	/*
	 * Disconnect database connection.
	 */
	core::Persistence::disconnectDb();

	/*
	 * Return error code to the operating system.
	 */
	return ( EXIT_SUCCESS);
}

}
