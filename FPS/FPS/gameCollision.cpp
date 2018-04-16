#include "gameCollision.h"
#include <iostream>

using namespace std;

bool sphereColTest(gameVector2D gameObj1Centre, gameVector2D gameObj2Centre, float gameObj1Radius, float gameObj2Radius)
{
	float distance;

	distance = (abs(gameObj1Centre.getX() - gameObj2Centre.getX()) * abs(gameObj1Centre.getX() - gameObj2Centre.getX())) + (abs(gameObj1Centre.getY() - gameObj2Centre.getY()) * abs(gameObj1Centre.getY() - gameObj2Centre.getY()));

	if (((gameObj1Radius + gameObj2Radius) * (gameObj1Radius + gameObj2Radius)) >= distance)
	{
		return(true);
	}

	return(false);
}

void getObjectCentre(gameVector2D vertices[], int numVertices, gameVector2D &objCentre)
{
	float largestX = 0;
	float largestY = 0;
	float smallestX = 1000000;
	float smallestY = 1000000;

	if (vertices == NULL)
	{
		return;

		for (int counter = 0; counter < numVertices; counter++)
		{
			if (vertices[counter].getX()>largestX)
			{
				largestX = vertices[counter].getX();
			}
			if (vertices[counter].getX()<smallestX)
			{
				smallestX = vertices[counter].getX();
			}
			if (vertices[counter].getY()>largestY)
			{
				largestY = vertices[counter].getY();
			}
			if (vertices[counter].getY()<smallestY)
			{
				smallestY = vertices[counter].getY();
			}
		}

		float xsize = largestX - smallestX;
		float ysize = largestY - smallestY;

		objCentre.setVector((int)(smallestX + (xsize / 2)), (int)(smallestY + (ysize / 2)));
	}
}

float getBoundingSphereRadius(gameVector2D vertices[], int numVertices, gameVector2D objCentre)
{
	float distance;
	float maxDistance = 0;

	for (int counter = 0; counter < numVertices; counter++)
	{
		distance = ((vertices[counter].getX() - objCentre.getX()) * (vertices[counter].getX() - objCentre.getX())) + ((vertices[counter].getY() - objCentre.getY()) * (vertices[counter].getY() - objCentre.getY()));

		//Checking max distance
		if (distance > maxDistance)
		{
			maxDistance = distance;
		}
	}

	return(sqrt(maxDistance));
}