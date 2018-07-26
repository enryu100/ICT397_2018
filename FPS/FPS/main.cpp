// main.cpp

/**
* Currently, this project is an horrific merging of both SDL and GLUT code. These old files are being kept so as to not ruin the GLUT
* code, but to allow it to be deleted from the main project to test SDL.
*/

#include "MainGame.h"
#include <iostream>

#define SIZE 300 //Defines window size

void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glLineWidth(2.0);
	

	// Game Title
	const unsigned char* bite_text = reinterpret_cast<const unsigned char *>("Bite Club: A Game by BMK Software"); //Converts text to unsigned char
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, bite_text);
	gluOrtho2D(0.0, 0.0, 1.0, 0.0);

	// Instruction
	const unsigned char* ins_text = reinterpret_cast<const unsigned char *>("Click Left Mouse Button to select option."); //Converts text to unsigned char
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, ins_text);
	gluOrtho2D(0.0, 0.0, 2.0, 0.0);

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


int main(int argc, char** argv)
{
	/*
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(250, 250);
	glutInitWindowSize(SIZE, SIZE);
	glutCreateWindow("Menu");

	int submen1 = glutCreateMenu(main_men);

	glutAddMenuEntry("Play", 1);
	glutAddMenuEntry("Exit", 2);
	glutAttachMenu(GLUT_LEFT_BUTTON);

	glutDisplayFunc(display);
	glutMainLoop();
	*/

	Play();
	return 0;
}


