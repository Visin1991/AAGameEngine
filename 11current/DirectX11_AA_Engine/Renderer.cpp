#include "Renderer.h"
#include"RenderEngine.h"

IMPLEMENT_DYNCRT_ACTION(Renderer)

Renderer::Renderer() {
	
}

Renderer::~Renderer()
{
}

void Renderer::Awake() {
	std::cout << "Down Load data for the Renderer" << std::endl;
}