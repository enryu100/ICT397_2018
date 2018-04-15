#include "gameVector.h"
#include "gameVector2D.h"
#include <math.h>

bool sphereColTest(gameVector2D gameObj1Centre, gameVector2D gameObj2Centre, float gameObj1Radius, float gameObj2Radius);
void getObjectCentre(gameVector2D vertices[], int numVertices, gameVector2D &objCentre);
float getBoundingSphereRadius(gameVector2D vertices[], int numVertices, gameVector2D objCentre);
