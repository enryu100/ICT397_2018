/**
* Events.h
*
* Author: Brandon Lim
*
* Defines an event class for handling input events in the game.
*/
#pragma once

#include <vector>

namespace events{
	/**
	* @struct gameEvent
	* @brief Provides a structure for holding data from input events in a game.
	*
	* This struct is to be used for getting any changes from input events that may have
	* occurred during a game's execution.
	*
	* @author Brandon Lim
	*/
	struct gameEvent{
		/// Determines if any events have occurred.
		bool hasEvents;
		/// Determines if the game has been quit.
		bool hasQuit;
		/// Which keys on the keyboard were pressed, if any.
		std::vector<char> keysPressed;
		/// Determines if any key is down. May not be needed presently.
		bool keyDown;
		/// Determines if any key has been released. May not be needed presently.
		bool keyReleased;
		/// The x position of the cursor on the screen.
		int mouseX;
		/// The y position of the cursor on the screen.
		int mouseY;
		/// The ID of the mouse button that was pressed, if any.
		int button;
		/// Determines if the button is down. May not be needed presently.
		bool buttonDown;
		/// Determines if the pressed button has been released. May not be needed presently.
		bool buttonReleased;

		/**
		* The constructor for a gameEvent variable.
		* Initialises the member variables.
		*/
		gameEvent(){
			hasEvents = false;
			hasQuit = false;
			keyDown = false;
			keyReleased = false;
			mouseX = 0;
			mouseY = 0;
			button = 0;
			buttonDown = false;
			buttonReleased = false;
		};

		/**
		* @brief Copies the contents of another gameEvent to this one.
		* @param otherEvent - The event being copied from
		* @return gameEvent& - The current event
		*
		* This is merely an overloaded assignment operator, adjusted so that it only copies
		* the contents from one gameEvent variable to another.
		*/
		gameEvent& operator=(const gameEvent& otherEvent){
			this->hasEvents = otherEvent.hasEvents;
			this->hasQuit = otherEvent.hasQuit;
			this->keysPressed = otherEvent.keysPressed;
			this->keyDown = otherEvent.keyDown;
			this->keyReleased = otherEvent.keyReleased;
			this->mouseX = otherEvent.mouseX;
			this->mouseY = otherEvent.mouseY;
			this->button = otherEvent.button;
			this->buttonDown = otherEvent.buttonDown;
			this->buttonReleased = otherEvent.buttonReleased;

			return *this;
		};
	};
}
