#define PI 3.14159265358979323846
#define piDiv180 PI/180

#include <math.h>


//Structure which represents a point of X and Y coordinates
typedef struct point
{ 
	double x; 
	double y; 
}point2D;

/**
* @class gameMath
* @brief A class that provides basic math functions and conversion
*
* This class converts different units back and forth for use in collision detection.
*
* Reference: ICT397 Collision Examples and ICT397 Topic06 Lecture Notes
*
* @author Kenneth Donohoe
*
*/

/**
*@brief Converts degrees to radians
*@param double radians
*@return double radians
*
* Multiplies piDiv180 with radians and returns the result
*/
inline double degToRad(double radians);

/**
*@brief Converts radians to degrees
*@param double radians
*@return double radians
*
* Multiplies radians with 180 divided by PI and returns the result
*/
inline double radToDeg(double radians);

/**
*@brief Converts cartesian coordinates to polar coordinates
*@param double x
		double y
*@return point polar
*
*/
point cartToPolar(double x, double y);

/**
*@brief Converts polar coordinates to cartesian coordinates
*@param point2D polar
*@return point cart
*
*/
point polarToCart(point2D polar);

/**
*@brief Moves to polar 2D co-ordinates to a specified angle and direction
*@param double moveDistance
		point2D cartCoordinates
		double angle
		int direction
*@return No return
*
*/
void movePolar2D(double moveDistance, point2D& cartCoordinates, double& angle, int direction);
