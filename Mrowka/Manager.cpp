#include "Manager.h"



Manager::Manager():_p()
{
}

Manager::Manager(std::string filePath)
	:
	_p(filePath)
{
}


Manager::~Manager()
{
}

void Manager::Analize()
{
	Ant& a = _p.getAnt();
	Antold = { (SHORT)a.x+1, (SHORT)a.y+1 };
	//Wytycz nowy kierunek
	switch (getCellColor(a.y*getWidth() + a.x))
	{
		case Komorka::WHITE:
		{
			a.d = static_cast<Ant::Direction>(a.d - 1 >=0 ? a.d-1:3);

			// Ustaw star¹ pozycje na przeciwny kolor
			setCellColor(a.y*getWidth() + a.x, Komorka::BLACK);
			break;
		}
		case Komorka::BLACK:
		{
			a.d = static_cast<Ant::Direction>(a.d + 1 <= 3? a.d+1:0);

			// Ustaw star¹ pozycje na przeciwny kolor
			setCellColor(a.y*getWidth() + a.x, Komorka::WHITE);
			break;
		}
	}
	
	switch (a.d)
	{
		case Ant::UP:
		{
			a.y = a.y-1>=0? a.y-1 : getHeight()-1;
			break;
		}
		case Ant::DOWN:
		{
			a.y = a.y + 1 < (long)getHeight() ? a.y + 1 : 0;
			break;
		}
		case Ant::LEFT:
		{
			a.x = a.x - 1 >= 0 ? a.x - 1 : getWidth() - 1;
			break;
		}
		case Ant::RIGHT:
		{
			a.x = a.x + 1 < (long)getWidth() ? a.x + 1 :  0;
			break;
		}
	}	
	Antnew = { (SHORT)(a.x + 1 < getWidth() ? a.x + 1 : 0), (SHORT)(a.y + 1 < getHeight() ? a.y + 1 : 0) };
}

size_t Manager::getWidth()
{
	return _p.getWidth();
}

size_t Manager::getHeight()
{
	return _p.getHeight();
}
