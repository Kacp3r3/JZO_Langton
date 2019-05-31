#ifndef GOL_H
#define GOL_H
#include "Manager.h"
#include <Windows.h>
#include <iomanip>
class Langton
{

public:
	Langton();
	Langton(std::string filePath);
	~Langton();

public:
	virtual void View()=0;
	void Start();
	void SlowBy(size_t i);
	void SpeedUpBy(size_t i);
protected:
	Manager _m;
	size_t dt;
};
#endif