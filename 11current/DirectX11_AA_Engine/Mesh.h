#pragma once
#include"Math\AAMath.h"
#include<D3D11.h>

using namespace AAEngine;

namespace AAEngine {
	struct Mesh
	{
		int vertexCount;
		ID3D11Buffer* vertexBuffer;
		Mesh();
	};
}

