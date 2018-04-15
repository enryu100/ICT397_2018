#include "gameObject.h"

void GameObject::procCollision(GameObject &obj){
	if(bBox.checkCollision(pos, obj.bBox, obj.pos)){
		onColl(obj);
	}
}

GameObject::GameObject(){
	pos.x=0.0;
	pos.y=0.0;
	pos.z=0.0;
	sphSize=0.0;
	scale=1.0;
}

GameObject::GameObject(gameVector position, float sphereSize, float objScale){
	pos=position;
	sphSize=sphereSize;
	if(objScale>0.0)
		scale=objScale;
	else
		scale=1.0;
}

GameObject::GameObject(float x, float y, float z, float sphereSize, float objScale){
	pos.x=x;
	pos.y=y;
	pos.z=z;
	sphSize=sphereSize;
	if(objScale>0.0)
		scale=objScale;
	else
		scale=1.0;
}

void GameObject::setPos(gameVector position){
	pos=position;
}

void GameObject::setPos(float x, float y, float z){
	pos.x=x;
	pos.y=y;
	pos.z=z;
}

void GameObject::setSphSize(unsigned short sphereSize){
	if(size>0)
		sphSize=sphereSize;
}

void GameObject::setScale(float objScale){
	if(objScale>0.0)
		scale=objScale;
	else
		scale=1.0;
}

void GameObject::setPosInc(gameVector position){
	pos+=position;
}

void GameObject::setPosX(float x){
	pos.x=x;
}

void GameObject::setPosY(float y){
	pos.y=y;
}

void GameObject::setPosZ(float z){
	pos.z=z;
}