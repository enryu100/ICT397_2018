#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "gameVector.h"
#include "gameCollision.h"
#include "AABB.h"
#include <iostream>

using namespace std;

class GameObject{
	public:
		void procCollision(GameObject &object);
		GameObject();
		GameObject(gameVector position, float sphereSize, float objScale);
		GameObject(float x, float y, float z, float sphereSize, float objScale);
		
		void setPos(gameVector position);
		void setPos(float x, float y, float z);
		void setSphSize(unsigned short sphereSize);
		void setScale(float objScale);
		void setPosInc(gameVector position);
		void setPosX(float x);
		void setPosY(float y);
		void setPosZ(float z);

		gameVector getPos(){return pos;}
		float getPosX(){return pos.getX();}
		float getPosY(){return pos.getY();}
		float getPosZ(){return pos.getZ();}
		unsigned short getSphSize(){return sphSize;}
		float getScale(){return scale;}
	
	protected:
		virtual void render(){};
		virtual void onColl(GameObject &collObj){};
		AABB bBox;

	private:
		gameVector pos;
		float sphSize;
		float scale;

};

#endif
