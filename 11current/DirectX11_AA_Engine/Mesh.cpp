#include"Mesh.h"
#include"RenderEngine.h"

namespace AAEngine {
	Mesh::Mesh() {
		// create a triangle out of vertices
		VERTEX OurVertices[] =
		{
			{ 0.0f, 0.5f, 0.0f,    1.0f, 0.0f, 0.0f },
			{ 0.45f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f },
			{ -0.45f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f },
		};

		vertexCount = ARRAYSIZE(OurVertices);
		// create the vertex buffer
		D3D11_BUFFER_DESC bd = { 0 };
		bd.ByteWidth = sizeof(VERTEX) * vertexCount;
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA srd = { OurVertices, 0, 0 };

		RenderEngine::instance->m_pD3dDevice->CreateBuffer(&bd, &srd, &vertexBuffer);
	}

}