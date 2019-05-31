#ifndef KOMORKA_H
#define KOMORKA_H
class Komorka
{
public:
	enum Color
	{
		BLACK = 0,
		WHITE = 1,
	};
public:
	Komorka();
	Komorka(size_t x,size_t y, Color cl);
	~Komorka();
public:
	size_t getX() { return _x; };
	size_t getY() { return _y; };
	Color getColor() { return c; };
	void MakeBlack() { c = BLACK; };
	void MakeWhite() { c = WHITE; };
	void setColor(Color cl) { c = cl; };
private:
	size_t _x;
	size_t _y;
	Color c;
};
#endif
