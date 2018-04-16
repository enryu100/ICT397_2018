/**
*	\class GameObject
*	A class that represents anything the engine can draw. 
*	All objects in the game are derived from this class.
*	@author Mitchell Holling
*/
#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "gameVector.h"
#include "gameCollision.h"
#include "AABB.h"
#include <iostream>

using namespace std;

class GameObject{
	public:
		/**
		*	\fn procCollision
		*	A function that processes a collision between this object and
		*	object taken in as a parameter.
		*	@param object the incoming object to test the collision with this object
		*/
		void procCollision(GameObject &object);
		
		/**
		*	\fn GameObject
		*	Overlaoded constructor for the object, which takes in no parameters
		*	Sets all values to defaults
		*/
		GameObject();
		/**
		*	\fn GameObject
		*	Overloaded constructor for the object, which takes in parameters of
		*	a Vector, the size, and the scale of the object
		*	@param position vector for the initial position of the object in 3D space
		*	@param sphereSize size of the object
		*	@param objScale scale of the object
		*/
		GameObject(gameVector position, float sphereSize, float objScale);
		/**
		*	\fn GameObject
		*	Overloaded constructor for the object, which takes in parameters of 
		*	the 3 coordinates of the object, the size, and the scale of the object
		*	@param x the X coordinate of the object
		*	@param y the Y coordinate of the object
		*	@param z the Z coordinate of the object
		*	@param sphereSize size of the object
		*	@param objScale scale of the object
		*/
		GameObject(float x, float y, float z, float sphereSize, float objScale);
		
		/**
		*	\fn setPos
		*	Sets the Position of the object by taking in a vector
		*	@param position the desired position of the object
		*/
		void setPos(gameVector position);
		/**
		*	\fn setPos
		*	Overloaded function that sets the desired position of the object by taking in three coordinate points
		*	@param x the X coordinate of the object
		*	@param y the Y coordinate of the object
		*	@param z the Z coordinate of the object
		*/
		void setPos(float x, float y, float z);
		/**
		*	\fn setSphSize
		*	Sets the size of the object
		*	@param sphereSize the desired size of the object
		*/
		void setSphSize(unsigned short sphereSize);
		/**
		*	\fn setScale
		*	Sets the scale of the object
		*	@param objScale the desired scale of the object
		*/
		void setScale(float objScale);
		/**
		*	\fn setPosInc
		*	Increments the position of the object by taking in another vector
		*	@param position the vector to increment the current position by 
		*/
		void setPosInc(gameVector position);
		/**
		*	\fn setPosX
		*	Sets the X coordinate of the object's position
		*	@param x the desired X coordinate of the object
		*/
		void setPosX(float x);
		/**
		*	\fn setPosY
		*	Sets the Y coordinate of the object's position
		*	@param y the desired Y coordinate of the object
		*/
		void setPosY(float y);
		/**
		*	\fn setPosZ
		*	Sets the Z coordinate of the object's position
		*	@param z the desired Z coordinate of the object
		*/
		void setPosZ(float z);

		/**
		*	\fn getPos
		*	Returns the position of the object as a vector
		*/
		gameVector getPos(){return pos;}
		/**
		*	\fn getPosX
		*	Returns the X coordinate of the object
		*/
		float getPosX(){return pos.getX();}
		/**
		*	\fn getPosY
		*	Returns the Y coordinate of the object
		*/
		float getPosY(){return pos.getY();}
		/**
		*	\fn getPosZ
		*	Returns the Z coordinate of the object
		*/
		float getPosZ(){return pos.getZ();}
		/**
		*	\fn getSphSize
		*	Returns the size of the object
		*/
		unsigned short getSphSize(){return (unsigned short)sphSize;}
		/**
		*	\fn getScale
		*	Returns the scale of the object
		*/
		float getScale(){return scale;}
	
	protected:
		/**
		*	\fn render
		*	Abstract render function allowing to be implemented within another class derived from this one
		*/
		virtual void render(){};
		/**
		*	\fn onColl
		*	Abstract function allowing implementing class to perform an action on a detected collision
		*/
		virtual void onColl(GameObject &collObj){};
		//Bounding Box variable
		AABB bBox;

	private:
		//Variables
		gameVector pos;
		float sphSize;
		float scale;

};

#endif
