#ifndef GOLAPI_H
#define GOLAPI_H
#include "Langton.h"
class LangtonApi :
	public Langton
{
public:
	LangtonApi();
	LangtonApi( std::string filePath);
	~LangtonApi();
public:
	void View();
private:
	size_t cell_width;
	size_t cell_height;
};
#endif
