#include "Physics.h"
#include <iostream>

using namespace std;

void Physics::initCollisionBody()
{
	//The initial position and orientation of the collision body
	rp3d::Vector3 initPosition(0.0, 3.0, 0.0);
	rp3d::Quaternion initOrientation = rp3d::Quaternion::identity();
	rp3d::Transform transform(initPosition, initOrientation);

	//Creates a collision body in the world
	rp3d::CollisionBody* body;
	body = world.createCollisionBody(transform);
}

void Physics::moveCollisionBody(CollisionBody* body)
{
	//New  position  and  orientation  of the  collision  body
	rp3d::Vector3 position(10.0, 3.0, 0.0);
	rp3d::Quaternion orientation = rp3d::Quaternion::identity();
	rp3d::Transform newTransform(position, orientation);
	//Move the collision body
	body->setTransform(newTransform);
}

void Physics::deleteCollisionBody(CollisionBody* body)
{
	//Destroy collision body and remove it from the world
	world.destroyCollisionBody(body);
}

void Physics::initDynamicsWorld()
{
	//Gravity vector (setting gravity)
	rp3d::Vector3 gravity(0.0, -9.81, 0.0);

	//Create dynamic world
	rp3d::DynamicsWorld dworld(gravity);
}

void Physics::disableSleepMode()
{
	//Disable the sleeping technique (this means more computation power will be used)
	dworld.enableSleeping(false);
}