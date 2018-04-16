#include "gameVector.h"
#include "gameVector2D.h"
#include <math.h>

/**
* @class gameCollision
* @brief A class that calculates and tests for Bounding Sphere Collisions
*
* This class provides functions to test for sphere collisions, calculate an objects
* centre and gets the bounding sphere radius for the user.
*
* Reference: ICT397 Collision Examples and ICT397 Topic06 Lecture Notes
*
* @author Kenneth Donohoe
*
* @todo Ensure that the collision works
*/

/**
*@brief Sphere Collision Test
*@param gameVector2D gameObj1Centre - The centre of the first game object sphere
		gameVector2D gameObj2Centre - The centre of the second game object sphere
		float gameObj1Radius - The radius of the first game object sphere
		float gameObj2Radius - The radius of the second game object sphere
*@return Boolean
*
* Tests for sphere collisions between two objects centres and then their radius' and returns true or false depending
* on whether or not the two spheres collide.
*/
bool sphereColTest(gameVector2D gameObj1Centre, gameVector2D gameObj2Centre, float gameObj1Radius, float gameObj2Radius);

/**
*@brief Gets the object centre
*@param gameVector2D vertices[] - An array of 2D gameVector vertices
		int numVertices - Number of vertices
		gameVector2D objCentre - The centre of the gameVector2D object
*@return No return
*
* Gets the object centre and if the vertices are null it sets the largest X and Y to the vertices
*/
void getObjectCentre(gameVector2D vertices[], int numVertices, gameVector2D &objCentre);

/**
*@brief Gets the bounding sphere radius
*@param gameVector2D vertices[] - An array of 2D gameVector vertices
		int numVertices - Number of vertices
		gameVector2D objCentre - The centre of the gameVector2D object
*@return Float maxDistance
*
* Gets the bounding sphere radius by performing calculates of the object radius and the vertices and
* returns the square root of the maxDistance
*/
float getBoundingSphereRadius(gameVector2D vertices[], int numVertices, gameVector2D objCentre);
