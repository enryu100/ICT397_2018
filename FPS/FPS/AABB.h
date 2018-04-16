#include "gameVector.h"

/**
* @class AABB
* @brief A class that creates the AABB world and checks collisions
*
* This class provides functions to test for collisions on Axis Aligned Bounding Boxes.
* Two gameVectors are kept called min and max and are used to calculate collisions.
* 
*
* @author Kenneth Donohoe
*
* @todo Ensure that the collision works
*/
class AABB
{
public:
	/** 
	*@brief AABB default constructor
	*@param No param
	*@return No return
	* 
	* Constructor which sets the min and max values all to zero
	*/
	AABB();

	/** 
	*@brief AABB class constructor
	*@param gameVector minValue - The minimum value for the XYZ vertices
	*		gameVector maxValue - The maximum value for the XYZ vertices
	*@return No return
	*
	* Constructor that uses parameter arguments to set the initial min and max values
	*/
	AABB(gameVector minValue, gameVector maxValue);

	/** 
	*@brief Create AABB world
	*@param gameVector vertices[] - Array of gameVector vertices
	*		int numVertices - Number of vertices
	*@return No return
	*
	* Min and max values are calculated in here and checked if they are within min/max bounds
	*/
	void createAABB(gameVector vertices[], int numVertices);

	/**
	*@brief Checks collision with a point
	*@param gameVector point - A point in the gameVector
	*		gameVector world - The local gameVector world
	*@return Boolean 
	*
	* Checks for collision between an AABB and a point within the local co-ordinate system
	*/
	bool checkCollisionWithPoint(gameVector &point, gameVector world);

	/**
	*@brief Checks collision between two AABBs 
	*@param gameVector world - The local gameVector world
			AABB aabb - Axis Aligned Bounding Box object
			gameVector world_2 - A second local gameVector world
	*@return Boolean
	*
	* Checks for collision between an AABB and another AABB and returns true or false depending on if the XYZ co-ordinates 
	* collide with gameObj2
	*/
	bool checkCollision(gameVector world, AABB &aabb, gameVector world_2);

	/**
	*@brief Equals operator overload
	*@param const AABB aabb_2
	*@return *this pointer
	*
	* 
	*/
	const AABB &operator=(const AABB &aabb_2);
private:
	gameVector min; /// Minimum gameVector value
	gameVector max; /// Maximum gameVector value

	/**
	*@brief Converts the AABB to the world
	*@param AABB aabb - Axis Aligned Bounding Box object
	*		gameVector world - Local game world
	*@return AABB worldAABB - The converted AABB
	*
	* Initialises the worldAAB and sets all the min/man XYZ vertices
	*/
	AABB initWorld(AABB aabb, gameVector world);

	/**
	*@brief Checks collision with a point
	*@param gameVector point - A point in the gameVector
	*		AABB aabb - Axis Aligned Boundary Box object
	*@return Boolean
	*
	* Checks for collision between an AABB and a point within the world aligned system
	*/
	bool checkCollisionWithPoint(gameVector &point, AABB &aabb);
};