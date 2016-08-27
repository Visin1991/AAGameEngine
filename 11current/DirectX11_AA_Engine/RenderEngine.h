#pragma once

#include"DXbase.h"
#include"GameObject2D.h"
#include<vector>
#include"Renderer.h"

namespace AAEngine {
	class RenderEngine : public DXbase
	{
	public:
		RenderEngine();
		virtual ~RenderEngine();

		bool LoadContent();
		void SetUpMatrixView();
		void SetUpBlendStaTe();
		void UnloadContent();

		void Update(float dt)override;
		void Render(float dt)override;
		void CleanScreen();
		bool DrawString(char* message, float startX, float startY);

		bool CreateVertexShader(char* fileName, ID3D11VertexShader* vsShader, ID3D11InputLayout* inputLayout);
		bool CreatePixelShader(char*  fileName, ID3D11PixelShader* psShader);
		bool CreateConstantBuffer(ID3D11Buffer* constBuffer);
		bool CreateTexture();
		bool CreateDynamicBufferForFront();

		static bool MakeSingleTon();


		static RenderEngine* instance;

		std::vector<Renderer*> m_renders;

		float Time;
	private:

		ID3D11Buffer* vertexBuffer_;
	};
}