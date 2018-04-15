#include "gameMath.h"

inline double degToRad(double radians)
{
	return(piDiv180 * radians);
}

inline double radToDeg(double radians)
{
	radians = radians * (180.0 / PI);
	return(radians);
}

point cartToPolar(double x, double y)
{
	point2D polar;

	polar.x = sqrt((x * x) + (y * y));
	polar.y = radToDeg((double)atan(y / x));

	return(polar);
}

point polarToCart(point2D polar)
{
	point2D cart;
	cart.x = polar.x * cos(polar.y);
	cart.y = polar.x * sin(polar.y);

	return(cart);
}

void movePolar2D(double moveDist, point2D& cartCoordinates, double& angle, int direction)
{
	if (moveDist > 0)
	{
		double a = cos(degToRad(angle));
		double b = sin(degToRad(angle));
		cartCoordinates.x += moveDist * cos(degToRad(angle)) * direction;
		cartCoordinates.y += moveDist * sin(degToRad(angle)) * direction;
	}
}