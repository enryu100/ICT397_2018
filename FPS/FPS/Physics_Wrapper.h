#ifndef PHYSICS_WRAPPER_H
#define PHYSICS_WRAPPER_H

/**
* @class Physiscs_Wrapper.h
* @brief A class that deals with the bullet physics engine
*
* The physics class is responsible for managing and creating physics objects
*
* @author Ben Porter
* @version 01
* @date 19/4/2017 
* @bug Linker errors, removed from main project for now
* @todo add support for more types of triangle mesh and maybe heightfield
*/



//#include <string>
#include "Bullet\btBulletCollisionCommon.h"
#include "Bullet\btBulletDynamicsCommon.h"

class Physics_Wrapper
{
public:
		/**
         *@brief default constructer for physiscs, sets up the physics settings
         */
	Physics_Wrapper(void);
		/**
         *@brief Sets the gravity for the world
         *@return void
		 *@param ygravity - double
         */
	void SetGravity(double yGravity);
		/**
         *@brief Creates a RigidBodyRectangle and adds it to the physics world
         *@return void
		 *@param height -int, width -int, length -int, massi -int, xpos - int, ypos - int, zpos - int, xInertia -int, yInertia -int, zInertia -int
         */
	void CreateRigidBodyRectangle(int height, int width, int length, int massi, int xpos, int ypos, int zpos, int xInertia, int yInertia, int zInertia);
		/**
         *@brief Creates a RigidBodySphere and adds it to the physics world
         *@return void
		 *@param radius -int, massi -int, xpos - int, ypos - int, zpos - int, xInertia -int, yInertia -int, zInertia -int
         */
	void CreateRigidBodySphere(int radius, int massi, int xpos, int ypos, int zpos, int xInertia, int yIntertia, int zInertia);
		/**
         *@brief runs the physics and does collisions
         *@return void
         */
	void Run();
		/**
         *@brief Gets the xorigen of object i
         *@return float
		 *@param i -int
         */
	float GetXorigen(int i);
		/**
         *@brief Gets the yorigen of object i
         *@return float
		 *@param i -int
         */
	float GetYorigen(int i);
		/**
         *@brief Gets the zorigen of object i
         *@return float
		 *@param i -int
         */
	float GetZorigen(int i);
		/**
         *@brief Deconstructor for the physics, removes the objects
         */
	~Physics_Wrapper(void);
private:
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btBroadphaseInterface* overlappingPairCache;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* dynamicsWorld;
	//used to keep track of shapes
	btAlignedObjectArray<btCollisionShape*> collisionShapes;
};


#endif //PHYSICS_WRAPPER_H