#include "Plansza.h"
#include <ctime>


Plansza::Plansza():_width(100), _height(65),_kom(_width*_height)
{
	initmap();
}

Plansza::Plansza(std::string filePath): _kom()
{
	initmap(filePath);
}


Plansza::~Plansza()
{
}

void Plansza::initmap()
{
	if (_kom.size() == 0)
	{
		for (size_t i = 0, e = _width * _height; i < e; ++i) _kom.emplace_back();
	}
	srand(static_cast<unsigned int>(time(NULL)));
	for (size_t y = 0; y < _height; ++y)
		for (size_t x = 0; x < _width; ++x)
		{
			_kom[y*_width + x] = Komorka(x, y, Komorka::Color::BLACK);
		}
}

void Plansza::initmap(std::string filePath)
{
	std::fstream plik;
	plik.open(filePath, std::ios::in);
	if (!plik.good()) exit(0);

	plik >> _width;
	plik >> _height;
	plik >> ant.x;
	plik >> ant.y;
	initmap();
}
