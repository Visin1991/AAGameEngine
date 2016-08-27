#ifndef _GRAPHIC_DEFINE_H_2015_11_13
#define _GRAPHIC_DEFINE_H_2015_11_13


#include <string>


namespace Graphic{
	//================================================================================
	//graphic images
	//================================================================================
	struct Animation
	{
		std::string name;
		int numFrames;
		int x, y, w, h;
		float fps;
	};
}
#endif // _GRAPHIC_DEFINE_H_2015_11_13