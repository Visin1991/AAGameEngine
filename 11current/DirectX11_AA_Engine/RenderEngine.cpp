#include"RenderEngine.h"
#include"constants.h"
#include<xnamath.h>
#include<fstream>
#include<array>
#include"RendererManager.h"
#include"Math\AAMath.h"
#include"MeshManager.h"

RenderEngine* RenderEngine::instance = nullptr;

namespace AAEngine {
	namespace {
		struct VertexPos
		{
			XMFLOAT3 pos;
			XMFLOAT2 tex0;
		};

		struct COLORMOD
		{
			float RedLevel, BlueLevel;
		};
	}

	RenderEngine::RenderEngine()
	{
		Time = 0.0f;
	}
	RenderEngine::~RenderEngine() {
	}
	bool RenderEngine::MakeSingleTon() {
		if (instance == nullptr) {
			instance = new RenderEngine();
		}
		return true;
	}
	bool RenderEngine::CreateVertexShader(char*  fileName, ID3D11VertexShader* vsShader, ID3D11InputLayout* inputLayout) {
		ID3DBlob* vsBuffer = 0;//This interface is used to return data of arbitrary length.
							   //More detail at P101
		bool compileResult = CompileD3DShader(fileName, "VS_Main", "vs_4_0", &vsBuffer);

		if (compileResult == false) {
			MessageBox(0, "Error loading vertex shader!", "Compile Error", MB_OK);
			return false;
		}
		//P103
		HRESULT d3dResult = m_pD3dDevice->CreateVertexShader(vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(), 0, &vsShader);

		if (FAILED(d3dResult)) {
			if (vsBuffer)
				vsBuffer->Release();

			return false;
		}
		//InputLayout
		//
		D3D11_INPUT_ELEMENT_DESC solidColorLayout[] = {
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "COLOR",    0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		};

		unsigned int totalLayoutElements = ARRAYSIZE(solidColorLayout);

		d3dResult = m_pD3dDevice->CreateInputLayout(solidColorLayout, totalLayoutElements, vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(), &inputLayout);
		vsBuffer->Release();

		m_pD3dContext->IASetInputLayout(inputLayout);
		m_pD3dContext->VSSetShader(vsShader, 0, 0);

		if (FAILED(d3dResult)) {
			return false;
		}
		return true;
	}
	bool RenderEngine::CreatePixelShader(char*  fileName, ID3D11PixelShader* psShader) {
		ID3DBlob* psBuffer = 0;

		bool compileResult = CompileD3DShader(fileName, "PS_Main", "ps_4_0", &psBuffer);

		if (compileResult == false) {
			MessageBox(0, "Error loading pixel shader!", "Compile Error", MB_OK);
			return false;
		}

		HRESULT d3dResult = m_pD3dDevice->CreatePixelShader(psBuffer->GetBufferPointer(), psBuffer->GetBufferSize(), 0, &psShader);
		psBuffer->Release();

		m_pD3dContext->PSSetShader(psShader, 0, 0);

		if (FAILED(d3dResult)) {
			return false;
		}
		return true;

		
	}
	bool RenderEngine::CreateConstantBuffer(ID3D11Buffer* _constantBuffer) {
		// this can be part of the InitPipeline() function
		D3D11_BUFFER_DESC bd = { 0 };

		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.ByteWidth = 16;
		bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

		m_pD3dDevice->CreateBuffer(&bd, nullptr, &_constantBuffer);

		m_pD3dContext->VSSetConstantBuffers(0,1,&_constantBuffer);
		return true;
	}
	bool RenderEngine::CreateTexture() {
		return false;
	}
	bool RenderEngine::CreateDynamicBufferForFront() {
		return false;
	}
	void RenderEngine::SetUpMatrixView() {
		//creates our orthographic-based view-projection matrix
		//XMMATRIX view = XMMatrixIdentity();
		//XMMATRIX projection = XMMatrixOrthographicOffCenterLH(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
		//vpMatrix_ = XMMatrixMultiply(view, projection);
	}
	void RenderEngine::SetUpBlendStaTe() {

	}
	bool RenderEngine::LoadContent() {
		return true;
	}
	void RenderEngine::UnloadContent() {

	}
	void RenderEngine::Update(float dt) {

	}

	void RenderEngine::Render(float dt)
	{
		CleanScreen();

		    std::map<std::string, std::vector<Renderer*> >::iterator it = RendererManager::instance->RendererTypeByMeshType.begin();
		

			ID3D11Buffer* vertexBuffer = MeshManager::instance->GetAMesh(it->first)->vertexBuffer; //get instance buffer
			ID3D11Buffer* constantBuffer = it->second[0]->material->shader->constantBuffer;
			

			UINT stride = sizeof(VERTEX);
			UINT offset = 0;

			m_pD3dContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
			m_pD3dContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		
			Time += 0.05;
			// change the world transformation of the object
			XMMATRIX matWorld = XMMatrixRotationY(3.14);
			//XMMATRIX matWorld = XMMatrixIdentity();
			float moveCam = Time * 0.1;

			XMVECTOR vecCamPosition = XMVectorSet(1.5f, 0.5f , 1.5f + moveCam, 0);
			XMVECTOR vecCamLookAt = XMVectorSet(0, 0, 0, 0);
			XMVECTOR vecCamUp = XMVectorSet(0, 1, 0, 0);

			XMMATRIX matView = XMMatrixLookAtLH(vecCamPosition, vecCamLookAt, vecCamUp);
			

			XMMATRIX matProjection = XMMatrixPerspectiveFovLH(
				XMConvertToRadians(45),                                      // the field of view
				(FLOAT)GAME_WIDTH / (FLOAT)GAME_HEIGHT,                      // aspect ratio
				1,                                                           // the near view-plane
				100);                                                        // the far view-plane
																			 // calculate the final matrix
			XMMATRIX matFinal = matWorld * matView * matProjection;

			m_pD3dContext->UpdateSubresource(constantBuffer, 0, 0, &matFinal, 0, 0);

			m_pD3dContext->Draw(3, 0);

			m_pSwapChain->Present(1, 0);
	}


	void RenderEngine::CleanScreen() {
		/*Bind one or more render targets atomically and the depth-stencil buffer to the output-merger stage.*/
		// If we use multiple swapChain, then we need to Set the RenderTargets ever frame...
		
		float clearColor[4] = { 0.0f, 0.25f, 0.5f, 1.0f };
		m_pD3dContext->ClearRenderTargetView(m_pBackBufferTarget, clearColor);

		m_pD3dContext->OMSetRenderTargets(1, &m_pBackBufferTarget, nullptr);

	}

	bool RenderEngine::DrawString(char* _message, float _startX, float _startY) {
		const int maxLetters = 24;
		int length = strlen(_message);

		if (length > maxLetters) {
			length = maxLetters;
		}

		float charWidth = 32.0f / 800.0f;//Char's width on screem.
		float charHeight = 32.0f / 640.0f;
		float texelWidth = 32.0f / 864.0f; //32 * 24 = 864
		const int verticesPerLetter = 6;
		D3D11_MAPPED_SUBRESOURCE mapResource;
		//Detail at p167
		HRESULT d3dResult = m_pD3dContext->Map(vertexBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapResource);

		if (FAILED(d3dResult)) {
			DXTRACE_MSG("Faild to map resource!");
			return false;
		}
		VertexPos* spritePtr = (VertexPos*)mapResource.pData;
		const int indexA = static_cast<char>('A');
		const int indexZ = static_cast<char>('Z');

		for (int i = 0; i < length; ++i) {
			float thisStartX = _startX + (charWidth * static_cast<float>(i));
			float thisEndX = thisStartX + charWidth;
			float thisEndY = _startY + charHeight;

			spritePtr[0].pos = XMFLOAT3(thisEndX, thisEndY, 1.0f);
			spritePtr[1].pos = XMFLOAT3(thisEndX, _startY, 1.0f);
			spritePtr[2].pos = XMFLOAT3(thisStartX, _startY, 1.0f);
			spritePtr[3].pos = XMFLOAT3(thisStartX, _startY, 1.0f);
			spritePtr[4].pos = XMFLOAT3(thisStartX, thisEndY, 1.0f);
			spritePtr[5].pos = XMFLOAT3(thisEndX, thisEndY, 1.0f);

			int texLookup = 0;
			int letter = static_cast<char>(_message[i]);

			if (letter < indexA || letter > indexZ) {
				texLookup = (indexZ - indexA) + 1;// Grab one index past Z, which is a blank space in the texture.
			}
			else {
				// A = 0, B = 1, Z = 25, etc.
				texLookup = (letter - indexA);
			}

			float tuStart = 0.0f + (texelWidth * static_cast<float>(texLookup));
			float tuEnd = tuStart + texelWidth;

			spritePtr[0].tex0 = XMFLOAT2(tuEnd, 0.0f);
			spritePtr[1].tex0 = XMFLOAT2(tuEnd, 1.0f);
			spritePtr[2].tex0 = XMFLOAT2(tuStart, 1.0f);
			spritePtr[3].tex0 = XMFLOAT2(tuStart, 1.0f);
			spritePtr[4].tex0 = XMFLOAT2(tuStart, 0.0f);
			spritePtr[5].tex0 = XMFLOAT2(tuEnd, 0.0f);

			spritePtr += 6;
		}

		m_pD3dContext->Unmap(vertexBuffer_, 0);
		m_pD3dContext->Draw(6 * length, 0);

		return true;
	}
}