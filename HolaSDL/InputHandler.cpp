#include "InputHandler.h"

InputHandler* InputHandler::instance_ = nullptr;


void InputHandler::clearState() {
	keyDown_ = false;
	keyUp_ = false;
	kbState_ = nullptr;
	for(int i=0; i<3; i++) {
		mbState_[i] = false;
	}
}

void InputHandler::update() {

	SDL_Event event;

	clearState();

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			onKeyDown(event);
			break;
		case SDL_KEYUP:
			onKeyUp(event);
			break;
		case SDL_MOUSEMOTION:
			onMouseMotion(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;
		}
	}

}



bool InputHandler::isAnyKeyDown() {
	return keyDown_;
}

bool InputHandler::isAnyKeyUp() {
	return keyUp_;
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
	return kbState_ != nullptr && kbState_[key] == 1;
}

bool InputHandler::isKeyDown(SDL_Keycode key) {
	return isKeyDown(SDL_GetScancodeFromKey(key));
}

const Vector2D& InputHandler::getMousePos() {
	return mousePos_;
}

int InputHandler::getMouseButtonState(int b) {
	return mbState_[b];
}

InputHandler::InputHandler() {
	clearState();
}

InputHandler::~InputHandler() {
}

void InputHandler::onKeyDown(SDL_Event& event) {
	keyDown_ = true;
	kbState_ = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp(SDL_Event& event) {
	keyUp_ = true;
	kbState_ = SDL_GetKeyboardState(0);
}

void InputHandler::onMouseMotion(SDL_Event& event) {
	mousePos_.set(event.motion.x,event.motion.y);
}

void InputHandler::onMouseButtonUp(SDL_Event& event) {
	if ( event.button.button == SDL_BUTTON_LEFT ) {
		mbState_[LEFT] = false;
	} else if ( event.button.button == SDL_BUTTON_MIDDLE ) {
		mbState_[MIDDLE] = false;
	} else if ( event.button.button == SDL_BUTTON_RIGHT ) {
		mbState_[RIGHT] = false;
	}
}

void InputHandler::onMouseButtonDown(SDL_Event& event) {
	if ( event.button.button == SDL_BUTTON_LEFT ) {
		mbState_[LEFT] = true;
	} else if ( event.button.button == SDL_BUTTON_MIDDLE ) {
		mbState_[MIDDLE] = true;
	} else if ( event.button.button == SDL_BUTTON_RIGHT ) {
		mbState_[RIGHT] = true;
	}
}

