// main.cpp

/**
* Currently, this project is an horrific merging of both SDL and GLUT code. These old files are being kept so as to not ruin the GLUT
* code, but to allow it to be deleted from the main project to test SDL.
*/

#include "MainGame.h"
#include <iostream>

void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// Play Option
	const unsigned char* play_text = reinterpret_cast<const unsigned char *>("Play"); //Converts text to unsigned char
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, play_text);

	// Exit Option
	const unsigned char* exit_text = reinterpret_cast<const unsigned char *>("Exit"); //Converts text to unsigned char
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, exit_text);
	glFlush();
}

void Play()
{
	MainGame mainGame; // In the future, make this a singleton. Maybe make a singleton class.

	mainGame.run("../resources/init/init.lua");

	return;
}


void main_men(int val)
{
	switch (val)
	{
	case 1:
	{
		Play();
		break;
	}
	case 2:
	{
		exit(0);
		break;
	}
	}

	glutPostRedisplay();
}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(250, 250);
	glutInitWindowSize(250, 250);
	glutCreateWindow("Menu");

	int submen1 = glutCreateMenu(main_men);

	glutAddMenuEntry("Play", 1);
	glutAddMenuEntry("Exit", 2);

	glutDisplayFunc(display);
	glutMainLoop();



	return 0;
}


