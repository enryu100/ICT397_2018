#ifndef __GAMEVECTOR_H
#define __GAMEVECTOR_H
#include <math.h>
#include "gameMath.h"

class gameVector
{
public:
	gameVector();
	gameVector(float xpos, float ypos, float zpos);
	gameVector(const gameVector &vec);
	void set(const gameVector &v2);
	void set(float xpos, float ypos, float zpos);
	void operator=(const gameVector &vec);
	void operator+=(const gameVector& vec);
	void setX(float xpos);
	void setY(float ypos);
	void setZ(float zpos);
	float getX();
	float getY();
	float getZ();
private:
	float x;
	float y;
	float z;
};

#endif