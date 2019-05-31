#ifndef MAN_H
#define MAN_H
#include "Plansza.h"
#include <Windows.h>
class Manager
{
public:
	Manager();
	Manager(std::string filePath);
	~Manager();
public:
	void Analize();
	size_t getWidth();
	size_t getHeight();
	COORD& getOld() { return Antold; };
	COORD& getNew() { return Antnew; };
public:
	Komorka::Color getCellColor(size_t i) { return _p.getCellColor(i); };
private:
	void setCellColor(size_t i, Komorka::Color c) { _p.setColor(i,c); };
private:
	Plansza _p;
	COORD Antold;
	COORD Antnew;
};
#endif
