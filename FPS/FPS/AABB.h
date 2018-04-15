#include "gameVector.h"

class AABB
{
public:
	AABB();
	AABB(gameVector minValue, gameVector maxValue);
	void createAABB(gameVector vertices[], int numVerticies);
	bool checkCollisionWithPoint(gameVector &point, gameVector world);
	bool checkCollision(gameVector world, AABB &aabb, gameVector world_2);
	const AABB &operator=(const AABB &aabb_2);
private:
	gameVector min;
	gameVector max;
	AABB initWorld(AABB aabb, gameVector world);
	bool checkCollisionWithPoint(gameVector &point, AABB &aabb);
};