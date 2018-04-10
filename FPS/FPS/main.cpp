// main.cpp

/**
* Currently, this project is an horrific merging of both SDL and GLUT code. These old files are being kept so as to not ruin the GLUT
* code, but to allow it to be deleted from the main project to test SDL.
*/

#include "MainGame.h"
#include <iostream>

int main(int argc, char** argv){
	MainGame mainGame; // In the future, make this a singleton. Maybe make a singleton class.

	mainGame.run("../resources/init/init.lua");

	return 0;
}