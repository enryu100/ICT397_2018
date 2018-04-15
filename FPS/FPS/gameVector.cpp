#include "gameVector.h"

gameVector::gameVector()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

gameVector::gameVector(float xpos, float ypos, float zpos)
{
	set(xpos, ypos, zpos);
}

gameVector::gameVector(const gameVector &vec)
{
	set(vec);
}

void gameVector::set(const gameVector &v2)
{
	x = v2.x;
	y = v2.y;
	z = v2.z;
}

void gameVector::set(float xpos, float ypos, float zpos)
{
	x = xpos;
	y = ypos;
	z = zpos;
}

void gameVector::operator+=(const gameVector &vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
}

void gameVector::operator=(const gameVector &vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

void gameVector::setX(float xpos)
{
	x = xpos;
}

void gameVector::setY(float ypos)
{
	y = ypos;
}

void gameVector::setZ(float zpos)
{
	z = zpos;
}

float gameVector::getX()
{
	return(x);
}

float gameVector::getY()
{
	return(y);
}

float gameVector::getZ()
{
	return(z);
}
