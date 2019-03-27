#pragma once

#include <array>
#include "sdl_includes.h"
#include "Vector2D.h"
/*
 *
 */
class InputHandler {
public:

	enum MOUSE_BUTTONS { LEFT, MIDDLE, RIGHT };

	virtual ~InputHandler();

	void update();

	// keyboard
	bool isAnyKeyDown(); // if a key change state to down in the last update
	bool isAnyKeyUp(); // if a key change state to down in the last update
	bool isKeyDown(SDL_Scancode key);
	bool isKeyDown(SDL_Keycode key);

	// mouse
	const Vector2D& getMousePos();
	int getMouseButtonState(int b);

	// Joystick
	// see:
	//   Chapter 4 of 'SDL Game Development' book
	//   Available online via https://biblioteca.ucm.es/
	//

	static InputHandler* getInstance() {
		if ( instance_ == nullptr ) {
			instance_ = new InputHandler();
		}
		return instance_;
	}

private:
	InputHandler();

	// handle the events
	void onKeyDown(SDL_Event &event);
	void onKeyUp(SDL_Event &event);
	void onMouseMotion(SDL_Event &event);
	void onMouseButtonUp(SDL_Event &event);
	void onMouseButtonDown(SDL_Event &event);

	// reset the state
	void clearState();



	static InputHandler* instance_;

	// keyboard
	const Uint8 *kbState_;
	bool keyDown_;
	bool keyUp_;

	// mouse
	Vector2D mousePos_;
	std::array<bool,3> mbState_;

};

