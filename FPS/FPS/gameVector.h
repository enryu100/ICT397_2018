#ifndef __GAMEVECTOR_H
#define __GAMEVECTOR_H
#include <math.h>
#include "gameMath.h"

/**
* @class gameVector
* @brief A class that sets and retrieves the XYZ values for the vectors in game
*
* This class provides functions to test for setting and getting XYZ values for the vectors
* along with operator overloading functions.
*
* Reference: ICT397 Collision Examples and ICT397 Topic06 Lecture Notes
*
* @author Kenneth Donohoe
*
*/

class gameVector
{
public:
	/**
	*@brief gameVector default constructor
	*@param No param
	*@return No return
	*
	* Constructor which sets the XYZ values all to zero
	*/
	gameVector();

	/**
	*@brief gameVector class constructor
	*@param float xpos - The position along the x axis
			float ypos - The position along the y axis
			float zpos - The position along the z axis
	*@return No return
	*
	* Constructor that uses parameter arguments to set the initial XYZ values and uses the set function with those arguments
	*/
	gameVector(float xpos, float ypos, float zpos);

	/**
	*@brief gameVector class constructor
	*@param gameVector vec - gameVector object
	*@return No return
	*
	* Constructor that uses parameter gameVector object to pass through to the set function
	*/
	gameVector(const gameVector &vec);

	/**
	*@brief Set function which sets the XYZ values to the v2 object
	*@param gameVector v2 - gameVector object
	*@return No return
	*
	*/
	void set(const gameVector &v2);

	/**
	*@brief Set function which sets the XYZ values according to parameter arguments
	*@param float xpos
			float ypos
			float zpos
	*@return No return
	*
	*/
	void set(float xpos, float ypos, float zpos);

	/**
	*@brief Equals operator overloading fucntion
	*@param gameVector vec
	*@return No return
	*
	*/
	void operator=(const gameVector &vec);

	/**
	*@brief Addition operator overloading fucntion
	*@param gameVector vec
	*@return No return
	*
	*/
	void operator+=(const gameVector& vec);

	/**
	*@brief Setter for the x variable
	*@param float xpos
	*@return No return
	*
	*/
	void setX(float xpos);

	/**
	*@brief Setter for the y variable
	*@param float ypos
	*@return No return
	*
	*/
	void setY(float ypos);

	/**
	*@brief Setter for the z variable
	*@param float zpos
	*@return No return
	*
	*/
	void setZ(float zpos);

	/**
	*@brief Getter for the x variable
	*@param No param
	*@return float x
	*
	*/
	float getX();

	/**
	*@brief Getter for the y variable
	*@param No param
	*@return float y
	*
	*/
	float getY();

	/**
	*@brief Getter for the z variable
	*@param No param
	*@return float z
	*
	*/
	float getZ();
private:
	float x; ///variable for the x axis
	float y; ///variable for the y axis
	float z; ///variable for the z axis
};

#endif