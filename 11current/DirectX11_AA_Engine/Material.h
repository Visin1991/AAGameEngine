 #pragma once
#include "Color.h"
#include "Texture.h"
#include "Shader.h"

namespace AAEngine {
	class Material
	{
	public:
		Material();
		~Material();

		Color* color;

		//MaterialGlobalIlluminationFlags globalIlluminationFlags;

		Texture* mainTexture;

		Vector2 mainTextureOffset;

		Vector2 mainTextureScale;

		unsigned int renderQueue;

		Shader* shader;

		//.............
	};
}

