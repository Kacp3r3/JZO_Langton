#include "LangtonApi.h"




LangtonApi::LangtonApi() : Langton()
{
}

LangtonApi::LangtonApi(std::string filePath)
	:
	 Langton(filePath)
{
}

LangtonApi::~LangtonApi()
{
}

void LangtonApi::View()
{
	//size_t TilesBorder = 1;
	//size_t TilesWidth = Graphics::ScreenWidth / (_m.getWidth());// +_m.getWidth() * 2 * TilesBorder);
	//size_t TilesHeight = Graphics::ScreenHeight / (_m.getHeight());// +_m.getHeight() * 2 * TilesBorder);
	//for(size_t y=0;y<_m.getHeight();++y)
	//	for (size_t x = 0; x < _m.getWidth(); ++x)
	//	{
	//		for (size_t yt = y * TilesHeight; yt < y*TilesHeight + TilesHeight; ++yt)
	//		{
	//			for (size_t xt = x * TilesWidth; xt < x*TilesWidth + TilesWidth; ++xt)
	//			{
	//				if (_m.getCell(static_cast<int>(y*_m.getWidth() + x)))
	//					gfx.PutPixel(static_cast<int>(xt), static_cast<int>(yt), Colors::Black);
	//				else gfx.PutPixel(static_cast<int>(xt), static_cast<int>(yt), Colors::White);
	//			}
	//		}
	//	}
}
