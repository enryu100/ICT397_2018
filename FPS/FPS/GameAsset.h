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
		GameObject* CreateObject(string type);
		
};

#endif