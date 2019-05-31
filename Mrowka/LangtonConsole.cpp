#include "LangtonConsole.h"
#include <iostream>


LangtonConsole::LangtonConsole() :Langton()
{
	hndl = GetStdHandle(STD_OUTPUT_HANDLE);
}

LangtonConsole::LangtonConsole(std::string filePath)
	:
	Langton(filePath)
{
	hndl = GetStdHandle(STD_OUTPUT_HANDLE);
}


LangtonConsole::~LangtonConsole()
{
}

void LangtonConsole::drawClear()
{
	//Rysowanie planszy z obwódk¹
	for (size_t i = 0; i < _m.getWidth() + 2; ++i) std::cout << "#";
	std::cout << "\n";
	for (size_t y = 0; y < _m.getHeight(); ++y)
	{
		std::cout << "#";
		for (size_t x = 0; x < _m.getWidth(); ++x)
		{
			if (_m.getCellColor(y*_m.getWidth() + x) == Komorka::WHITE) std::cout << "X";
			else std::cout << " ";
		}
		std::cout << "#\n";
	}
	for (size_t i = 0; i < _m.getWidth() + 2; ++i) std::cout << "#";
	std::cout << "\n";

	//Rysowanie Informacji po prawo
	SetConsoleCursorPosition(hndl, { (SHORT)_m.getWidth() + 5,(SHORT)1 });
	std::cout << "Aby wyjsc, kliknij Escape"<<'\n';
	SetConsoleCursorPosition(hndl, { (SHORT)_m.getWidth() + 5,(SHORT)3 });
	std::cout << "Przyspieszanie i zwalnianie gry";
	SetConsoleCursorPosition(hndl, { (SHORT)_m.getWidth() + 5,(SHORT)4 });
	std::cout << "Strzalkami gora/dol";
}

void LangtonConsole::Start()
{
	HWND h = GetConsoleWindow();
	RECT r;
	GetWindowRect(h, &r);
	MoveWindow(h, r.left, r.top, 1280, 720,TRUE);
	drawClear();
	while (true)
	{
		_m.Analize();
		View();
		ProcessInput();
		Sleep(dt);
	}
}

void LangtonConsole::View()
{
	SetConsoleCursorPosition(hndl,_m.getNew());
	std::cout << "&";
	SetConsoleCursorPosition(hndl, _m.getOld());
	std::cout << (_m.getCellColor((_m.getOld().Y-1)*_m.getWidth()+(_m.getOld().X-1)) == Komorka::WHITE ? "X" : " ");

	SetConsoleCursorPosition(hndl, { (SHORT)_m.getWidth() + 5,(SHORT)5 });
	std::cout << "Aktualna predkosc: "<<std::setprecision(3)<<1000.0/dt<<"ruchow/s   "<<(dt==5?"MAX":dt==150?"MIN":"   ");
}

void LangtonConsole::ProcessInput()
{
	char btn = '\0';
	if (_kbhit()) btn = _getch();

	switch (btn)
	{
	case 72:
	{
		SpeedUpBy(5);
		break;
	}
	case 80:
	{
		SlowBy(5);
		break;
	}
	case 27:
		exit(0);
	default:
		break;
	}
}
