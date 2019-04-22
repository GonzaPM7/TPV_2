#include "AsteroidsGame.h"
#include "InputHandler.h"
#include "Logger.h"

using namespace std;

AsteroidsGame::AsteroidsGame() :
	SDLGame("Asteroids", _WINDOW_WIDTH_, _WINDOW_HEIGHT_),
	fighter_(this),
	asteroids_(this),
	bullets_(this),
	gameManager_(this),
	blackHoles_(this)
{
	initGame();
}

AsteroidsGame::~AsteroidsGame() {
	closeGame();
}

void AsteroidsGame::initGame() {
	actors_.push_back(&fighter_);
	actors_.push_back(&asteroids_);
	actors_.push_back(&bullets_);
	actors_.push_back(&gameManager_);
	actors_.push_back(&blackHoles_);

	addObserver(&fighter_);
	addObserver(&asteroids_);
	addObserver(&bullets_);
	addObserver(&gameManager_);
	addObserver(&blackHoles_);

	Logger::instance()->initInstance("log.txt");
}

void AsteroidsGame::closeGame() {
}

void AsteroidsGame::start() {
	exit_ = false;

	while (!exit_) {
		Uint32 startTime = SDL_GetTicks();
		handleInput(startTime);
		update(startTime);
		render(startTime);

		Uint32 frameTime = SDL_GetTicks() - startTime;
		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
	}
}

void AsteroidsGame::stop() {
	exit_ = true;
}

void AsteroidsGame::handleInput(Uint32 time) {
	InputHandler::getInstance()->update();
		for (GameObject* o : actors_) {
			o->handleInput(time);
		}
	}


void AsteroidsGame::update(Uint32 time) {
	for (GameObject* o : actors_) {
		o->update(time);
	}
}

void AsteroidsGame::render(Uint32 time) {
	SDL_SetRenderDrawColor(getRenderer(), COLOR(0x00AAAAFF));
	SDL_RenderClear(getRenderer());

	for (GameObject* o : actors_) {
		o->render(time);
	}

	SDL_RenderPresent(getRenderer());
}

