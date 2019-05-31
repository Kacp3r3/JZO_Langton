#ifndef ANT_H
#define ANT_H
class Ant
{
public:
	enum Direction
	{
		UP = 0,
		RIGHT = 1,
		DOWN = 2,
		LEFT = 3
	};
public:
	Ant() : x(50), y(37), d(UP) {};
	~Ant();

public:
	long x;
	long y;
	Direction d;
};

#endif