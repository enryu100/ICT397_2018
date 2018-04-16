#include "gameObject.h"

void GameObject::procCollision(GameObject &obj){
	if(bBox.checkCollision(pos, obj.bBox, obj.pos)){
		onColl(obj);
	}
}

GameObject::GameObject(){
	pos.setX(0.0);
	pos.setY(0.0);
	pos.setZ(0.0);
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
	pos.setX(x);
	pos.setY(y);
	pos.setZ(z);
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
	pos.setX(x);
	pos.setY(y);
	pos.setZ(z);
}

void GameObject::setSphSize(unsigned short sphereSize){
	if(sphereSize>0)
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
	pos.setX(x);
}

void GameObject::setPosY(float y){
	pos.setY(y);
}

void GameObject::setPosZ(float z){
	pos.setZ(z);
}
