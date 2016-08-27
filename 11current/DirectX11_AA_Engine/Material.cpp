#include "Material.h"



Material::Material()
{
	mainTexture = nullptr;
	mainTextureOffset = Vector2(0,0);
	mainTextureScale = Vector2(0, 0);
	shader = new Shader();
}


Material::~Material()
{
}
