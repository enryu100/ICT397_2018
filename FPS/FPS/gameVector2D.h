/**
* @class gameVector2D
* @brief A class that provides basic functions for 2D XY coordinates
*
* This class provides functions to set and get XY 2D coordinates
*
* Reference: ICT397 Collision Examples and ICT397 Topic06 Lecture Notes
*
* @author Kenneth Donohoe
*
*/

class gameVector2D
{
private:
	float x; ///x axis variable
	float y; ///y axis variable

public:
	/**
	*@brief gameVector2D default constructor
	*@param No param
	*@return No return
	*
	* Constructor which sets the X and Y values to zero.
	*/
	gameVector2D()
	{
		x = y = 0.0;
	}

	/**
	*@brief gameVector2D class constructor
	*@param int xpos - The position along the x axis
			int ypos - The position along the y axis
	*@return No return
	*
	* Constructor that uses parameter arguments to set the initial X and Y values and uses the setVector function with those arguments
	*/
	gameVector2D(int xpos, int ypos)
	{
		setVector(xpos, ypos);
	}

	/**
	*@brief Getter for the x variable
	*@param No param
	*@return float x
	*
	*/
	float getX()
	{
		return(x);
	}

	/**
	*@brief Getter for the y variable
	*@param No param
	*@return float y
	*
	*/
	float getY()
	{
		return(y);
	}

	/**
	*@brief Set Vector function which sets the X and Y variables from parameter arguments
	*@param int xpos - The position along the x axis
			int ypos - The position along the y axis
	*@return No return
	*
	*/
	void setVector(int xpos, int ypos)
	{
		x = (float)xpos;
		y = (float)ypos;
	}

	/**
	*@brief Set Vector function which sets the X and Y variables from the gameVector2D object
	*@param gameVector2D v2 - gameVector2D object
	*@return No return
	*
	*/
	void setVector(const gameVector2D &v2)
	{
		x = v2.x;
		y = v2.y;
	}
};