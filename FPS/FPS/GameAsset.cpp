#include "GameAsset.h"

GameObject* GameAsset::CreateObject(string type){

	if(type.compare("Terrain") == 0){
		return new terrain::Terrain();
	}
	if(type.compare("PLAYER") == 0){
		return new Camera();
	}
	/*if(type.c_str=="OBSTACLE")
		return new Obstacle();
	if(type.c_str=="NPC")
		return new NPC();
	if(type.c_str=="ENEMY");
		return new Enemy();*/

	return nullptr;
}