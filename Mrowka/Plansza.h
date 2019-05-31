#ifndef PLANSZA_H
#define PLANSZA_H
#include <vector>
#include "Komorka.h"
#include "Ant.h"
#include <fstream>
class Plansza
{
public:
	Plansza();
	Plansza(std::string filePath);
	~Plansza();

public:
	size_t size() { return _kom.size(); };
	size_t getWidth() { return _width; };
	size_t getHeight() { return _height; };
	Ant& getAnt() { return ant; };
	Komorka::Color getCellColor(size_t i) { return _kom[i].getColor(); };

	void setColor(size_t i, Komorka::Color c) { _kom[i].setColor(c); }
private:
	size_t _width;
	size_t _height;
	Ant ant;
	std::vector<Komorka> _kom;
private:
	void initmap();
	void initmap(std::string filePath);
};

#endif