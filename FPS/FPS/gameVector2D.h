//gameVector2D.h

class gameVector2D
{
private:
	float x;
	float y;

public:
	gameVector2D()
	{
		x = y = 0.0;
	}

	gameVector2D(int xpos, int ypos)
	{
		setVector(xpos, ypos);
	}

	float getX()
	{
		return(x);
	}

	float getY()
	{
		return(y);
	}

	void setVector(int xpos, int ypos)
	{
		x = xpos;
		y = ypos;
	}

	void setVector(const gameVector2D &v2)
	{
		x = v2.x;
		y = v2.y;
	}
};