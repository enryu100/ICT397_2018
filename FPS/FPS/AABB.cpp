#include "AABB.h"
#include <iostream>

using namespace std;

AABB::AABB()
{
	min.set(0, 0, 0);
	max.set(0, 0, 0);
}

AABB::AABB(gameVector minValues, gameVector maxValues)
{
	min = minValues;
	max = maxValues;
}

//Creates the axis aligned bounding box vertices along XYZ planes
void AABB::createAABB(gameVector vertices[], int numVertices)
{
	for (int i = 0; i < numVertices; i++)
	{
		//Checks are done to see if XYZ is between min/max values
		//If they aren't then the minimum XYZ value is set by that vertice which is being checked
		if (vertices[i].getX() < min.getX())
		{
			min.setX(vertices[i].getX());
		}
		if (vertices[i].getX()>max.getX())
		{
			max.setX(vertices[i].getX());
		}
		if (vertices[i].getY()<min.getY())
		{
			min.setY(vertices[i].getY());
		}
		if (vertices[i].getY()>max.getY())
		{
			max.setY(vertices[i].getY());
		}
		if (vertices[i].getZ()<min.getZ())
		{
			min.setZ(vertices[i].getZ());
		}
		if (vertices[i].getZ()>max.getZ())
		{
			max.setZ(vertices[i].getZ());
		}
	}
}

//Initialises the world - assigns the min/max XYZ values to AABB world
AABB AABB::initWorld(AABB aabb, gameVector world)
{
	AABB worldAABB;
	float t; //Temporary value

	t = (float)(aabb.max.getX() - aabb.min.getX()) / 2.0;
	worldAABB.min.setX(world.getX() - t);
	worldAABB.max.setX(world.getX() + t);

	t = (float)(aabb.max.getY() - aabb.min.getY()) / 2.0;
	worldAABB.min.setY(world.getY() - t);
	worldAABB.max.setY(world.getY() + t);

	t = (float)(aabb.max.getZ() - aabb.min.getZ()) / 2.0;
	worldAABB.min.setZ(world.getZ() - t);
	worldAABB.max.setZ(world.getZ() + t);

	return(worldAABB);
}

bool AABB::checkCollisionWithPoint(gameVector &point, AABB &aabb)
{
	return((point.getX() >= aabb.min.getX()) && (point.getX() <= aabb.max.getX()) && (point.getY() >= aabb.min.getY()) && (point.getY() <= aabb.max.getY()) && (point.getZ() >= aabb.min.getZ()) && (point.getZ() <= aabb.max.getZ()));
}

bool AABB::checkCollisionWithPoint(gameVector &point, gameVector world)
{
	AABB worldAABB = initWorld(*this, world);

	return((point.getX() >= worldAABB.min.getX()) && (point.getX() <= worldAABB.max.getX()) && (point.getY() >= worldAABB.min.getY()) && (point.getY() <= worldAABB.max.getY()) && (point.getZ() >= worldAABB.min.getZ()) && (point.getZ() <= worldAABB.max.getZ()));
}

bool AABB::checkCollision(gameVector world, AABB &aabb_2, gameVector world_2)
{
	AABB gameObj1 = initWorld(*this, world);
	AABB gameObj2 = initWorld(aabb_2, world_2);
	gameVector v[8];

	v[0].set(gameObj1.min.getX(), gameObj1.min.getY(), gameObj1.min.getZ());
	v[1].set(gameObj1.max.getX(), gameObj1.min.getY(), gameObj1.min.getZ());
	v[2].set(gameObj1.max.getX(), gameObj1.max.getY(), gameObj1.min.getZ());
	v[3].set(gameObj1.min.getX(), gameObj1.max.getY(), gameObj1.min.getZ());
	v[4].set(gameObj1.min.getX(), gameObj1.min.getY(), gameObj1.max.getZ());
	v[5].set(gameObj1.max.getX(), gameObj1.min.getY(), gameObj1.max.getZ());
	v[6].set(gameObj1.max.getX(), gameObj1.max.getY(), gameObj1.max.getZ());
	v[7].set(gameObj1.min.getX(), gameObj1.max.getY(), gameObj1.max.getZ());

	for (int i = 0; i < 8; i++)
	{
		if (checkCollisionWithPoint(v[i], gameObj2))
		{
			return(true);
		}
	}
	return(false);
}

const AABB &AABB::operator=(const AABB &aabb_2)
{
	min = aabb_2.min;
	max = aabb_2.max;

	return *this;
}