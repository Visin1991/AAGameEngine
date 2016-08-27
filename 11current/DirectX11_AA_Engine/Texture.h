#pragma once

namespace AAEngine {

	enum TextureWrapMode {
		Repeat,Clamp
	};

	class Texture
	{
	public:
		Texture();
		~Texture();
		//variable
		int anisoLevel;
		int width;  //Width of the texture in pixels. (Read Only)
		TextureWrapMode wrapMode;
	};
}

