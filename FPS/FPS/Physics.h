//Physics facade encapsulating RigidBody, Raycasting and Collision using ReactPhysics3D Engine
//Author: Ken Donohoe
//Date 12/04/2018

#include "react3d\reactphysics3d.h"

using namespace reactphysics3d;

class Physics
{
public:
	void initCollisionBody();
	void moveCollisionBody(CollisionBody* body); //Parameters can be placed here to make the function dynamic in regards to position/orientation
	void deleteCollisionBody(CollisionBody* body);
	void initDynamicsWorld();
	void disableSleepMode();
	void updateWorld();
	SYSTEMTIME getCurrentSystemTime();
private:
	rp3d::CollisionWorld world; //Create collision world
	rp3d::DynamicsWorld dworld;
	SYSTEMTIME systime;
};