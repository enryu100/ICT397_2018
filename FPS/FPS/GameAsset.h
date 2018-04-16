/**
*	\class GameAsset
*	A class that creates an asset with the type
*	specified by a string, then returning a pointer to the object
*	@author Mitchell Holling
*/

#ifndef _GAMEASSET_H
#define _GAMEASSET_H

#include <iostream>
#include "gameObject.h"
#include "Terrain.h"
#include "Camera.h"
/*#include "Obstacle.h"
#include "NPC.h"
#include "Enemy.h"*/

using namespace std;


class GameAsset{ 
	public:
		/*
		*	\fn CreateObject
		*	Taking in the type of asset to be created,
		*	Creates the object, then returns a pointer to it
		*	@param type the type of object that needs to be created
		*/
		GameObject* CreateObject(string type);
		
};

#endif
