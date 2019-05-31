#ifndef GOLCONSOLE_H
#define GOLCONSOLE_H
#include "Langton.h"
#include <conio.h>
class LangtonConsole :
	public Langton
{
public:
	LangtonConsole();
	LangtonConsole(std::string filePath);
	~LangtonConsole();

private:
	void drawClear();
public:
	void Start();
	void View();
	void ProcessInput();

private:
	HANDLE hndl;
};

#endif