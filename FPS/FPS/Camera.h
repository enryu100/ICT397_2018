/**
* \class Camera
* A class that manages the camera/view parts of the program.
* Initially was based off the Camera class in Shay's World, but was later changed
* due to plans to use matrix transformations. Later was changed yet again, due to
* issues.
* @author Brandon Lim
*/
#pragma once

#define PI 3.1415962654

#include "Types.h"
#include "gameObject.h"

class Camera : public GameObject{
	public:
		/**
		* \fn Camera()
		* A constructor for a camera.
		* A basic constructor for a camera. Should be a singleton.
		*/
		Camera();

		//Set Methods
		/**
		* \fn setRotateSpeed
		* A function that sets the camera rotate speed.
		* A simple function to set the camera rotate speed at runtime.
		* @param tmpSpeed the desired rotate speed
		*/
		void setRotateSpeed(const double &tmpSpeed){m_rotateSpeed = tmpSpeed;}
		/**
		* \fn setMoveSpeed
		* A function that sets the camera Move speed.
		* A simple function to set the camera move speed at runtime.
		* @param tmpSpeed the desired move speed
		*/
		void setMoveSpeed(const double &tmpSpeed){m_moveSpeed = tmpSpeed;}
		/**
		* \fn transformView
		* Changes the view matrix to move the camera.
		* A function that receives a number of variables and transforms the
		* matrix storing camera details to move the camera
		* @param deltaX the distance to move along the X-axis
		* @param deltaY the distance to move along the Y-axis
		* @param deltaZ the distance to move along the Z-axis
		* @param deltaXAngle Horizontal angle, Used to set LookAt
		* @param deltaYAngle Vertical angle, used to set LookAt
		* @param deltaZAngle the amount to rotate around the Z-axis
		*/
		void transformView(float deltaX, float deltaY, float deltaZ, float deltaXAngle, float deltaYAngle, float deltaZAngle);

		//Get Methods
		/**
		* \fn getViewMatrix
		* A get method that returns the view Matrix.
		*/
		types::Matrix4x4 getViewMatrix(){return viewMatrix;};

	private:
		//variables
		//Speed variables
		double m_rotateSpeed;
		double m_moveSpeed;
		float horizontalAngle;
		float verticalAngle;
		//Vector variables
		types::Vector3D position, forward, right, up;

		// Matrix variables - added by Alfie
		types::Matrix4x4 viewMatrix;

		/**
		* \fn moveForwardBack
		* Forwards and Backwards movement.
		* A function that sets the amount to move when moving
		* forwards or backwards.
		* @param amount amount to move
		*/
		void moveForwardBack(float amountx, float amounty);
		/**
		* \fn moveLeftRight
		* Left and Right movement.
		* A function that sets the amount to move when moving
		* left or right.
		* @param amount amount to move
		*/
		void moveLeftRight(float amountx, float amountz);
		/**
		* \fn moveUpDown
		* Upwards and Downwards movement.
		* A function that sets the amount to move when moving
		* upwards or downwards.
		* @param amount amount to move
		*/
		void moveUpDown(float amount);
		/**
		* \fn rotateX
		* rotation around the x-axis.
		* A function for rotating the camera around the x-Axis, not used
		* @param angle the angle of rotation
		*/
		void rotateX(float angle);
		/**
		* \fn rotateY
		* rotation around the Y-axis.
		* A function for rotating the camera around the Y-Axis, not used
		* @param angle the angle of rotation
		*/
		void rotateY(float angle);
		/**
		* \fn rotateZ
		* rotation around the z-axis.
		* A function for rotating the camera around the Z-Axis
		* @param angle the angle of rotation
		*/
		void rotateZ(float angle);
};
