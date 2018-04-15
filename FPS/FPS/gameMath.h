#define PI 3.14159265358979323846
#define piDiv180 PI/180

#include <math.h>

typedef struct point
{ 
	double x; 
	double y; 
}point2D;

//Converts degrees to radians
inline double degToRad(double radians);
//Convert from radians to degrees
inline double radToDeg(double radians);

//Converts from cartesian to polar coordinates
point cartToPolar(double x, double y);
point polarToCart(point2D polar);

void movePolar2D(double moveDistance, point2D& cartCoordinates, double& angle, int direction);
void changeSign(double &value);
