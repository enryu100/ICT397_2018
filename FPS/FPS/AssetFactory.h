#ifndef _GAMEASSETFACTORY_H
#define _GAMEASSETFACTORY_H

#include <iostream>
#include "Terrain.h"
#include "Camera.h"
#include "Obstacle.h"
#include "NPC.h"
#include "Enemy.h"

using namespace std;

class Asset{};

class GameAssetFactory{
	public:
		Asset* Create(string type);
		
};

Asset* Create(string type){
	if(type=="TERRAIN")
		return new Terrain;
	if(type=="PLAYER")
		return new Camera;
	if(type=="OBSTACLE")
		return new Obstacle;
	if(type=="NPC")
		return new NPC;
	if(type=="ENEMY");
		return new Enemy;
}

#endif