#include "Shader.h"
#include"RenderEngine.h"

namespace AAEngine {
	Shader::Shader()
	{
		vs_Shader = nullptr;
		ps_Shader = nullptr;
		fileName = "WorkingWithConstBuffer.txt";
		RenderEngine::instance->CreateVertexShader(fileName,vs_Shader, inputLayout);
		RenderEngine::instance->CreatePixelShader(fileName,ps_Shader);
		CreateConstantBuffer();
		
	}
	Shader::~Shader()
	{
	}
	void Shader::CreateConstantBuffer() { 
		// this can be part of the InitPipeline() function
		D3D11_BUFFER_DESC bd = { 0 };

		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.ByteWidth = 64;
		bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

		RenderEngine::instance->m_pD3dDevice->CreateBuffer(&bd, nullptr, &constantBuffer);

		RenderEngine::instance->m_pD3dContext->VSSetConstantBuffers(0, 1, &constantBuffer);
	}

}
