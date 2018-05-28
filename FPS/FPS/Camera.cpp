#include "Camera.h"
#include <math.h>
#include <iostream>

using namespace types;

Camera::Camera(){
	m_rotateSpeed = 0.0f;
	m_moveSpeed = 0.0f;
	position = Vector3D(1000.0f, 0.0f, 1000.0f);
	right = Vector3D(1.0f, 0.0f, 0.0f);
	up = Vector3D(0.0f, 1.0f, 0.0f);
	forward = Vector3D(0.0f, 0.0f, 1.0f);
	viewMatrix = Matrix4x4(Vector4D(1.0f, 0.0f, 0.0f, 0.0f),
	                       Vector4D(0.0f, 1.0f, 0.0f, 0.0f),
	                       Vector4D(0.0f, 0.0f, 1.0f, 0.0f),
	                       Vector4D(0.0f, 0.0f, 0.0f, 1.0f));
	float horizontalAngle=0;
	float verticalAngle=0;
}

void Camera::transformView(float deltaX, float deltaY, float deltaZ, float MouseX, float MouseY, float LRMove){
	//2 and 3 are your x and z change
	moveLeftRight(deltaX, deltaZ);
	moveUpDown(deltaY);
	moveForwardBack(deltaX, deltaZ);
	horizontalAngle = MouseX;
	verticalAngle = MouseY;
	float movex=LRMove;//, movez=LRMove;
	moveLeftRight(movex, 0);
	viewMatrix.columns[0] = Vector4D(right.x, right.y, right.z, 0);
	//viewMatrix.columns[1] = Vector4D(up.x, up.y, up.z, 0);
	//viewMatrix.columns[2] = Vector4D(forward.x, forward.y, forward.z, 0);
	viewMatrix.columns[2] = Vector4D (
    cos(verticalAngle) * sin(horizontalAngle),
    sin(verticalAngle),
    cos(verticalAngle) * cos(horizontalAngle), 0.0f
);
	viewMatrix.columns[3] = Vector4D(position.x, position.y, position.z, 1);
	//std::cout << m_moveSpeed << std::endl;
}

//walking should be dependant on where the camera is looking, currently is just a generic back and forth 
//something weird af need both for actual proper movement
void Camera::moveForwardBack(float amountx, float amountz){
	// This makes the movement occur only on the x and z axes, mimicking walking.
	
	position.x += (float)(right.x * amountx * m_moveSpeed*viewMatrix.columns[2].x);
	position.z += (float)(right.z * amountz * m_moveSpeed*viewMatrix.columns[2].z);
	
	position.x += (float)(forward.x * amountx * m_moveSpeed *viewMatrix.columns[2].x);
	position.z += (float)(forward.z * amountz * m_moveSpeed*viewMatrix.columns[2].z);
		

}

void Camera::moveLeftRight(float amountx, float amountz){
	// This makes the movement occur only on the x and z axes, mimicking walking.
	/*position.x += amountz*m_moveSpeed;
	position.z += amountx*m_moveSpeed;*/

	
	
}

void Camera::moveUpDown(float amount){
	// This makes the movement occur only on the global y-axis, mimicking jumping.
	position.y = amount;
}

