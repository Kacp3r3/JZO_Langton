#include "Langton.h"



Langton::Langton():_m(), dt(150)
{
}

Langton::Langton(std::string filePath)
	:
	_m(filePath)
	,dt(150)
{
}


Langton::~Langton()
{
}

void Langton::Start()
{
	
}

void Langton::SlowBy(size_t i)
{
	dt += i;
	if (dt > 150) dt = 150;
}

void Langton::SpeedUpBy(size_t i)
{
	dt -= i;
	if (dt < 5) dt = 5;
}
