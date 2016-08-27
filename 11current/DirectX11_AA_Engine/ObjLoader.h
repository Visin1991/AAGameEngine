#pragma once
#include<vector>

class RowModel;


class ObjLoader
{
public:
	ObjLoader();
	~ObjLoader();
	void OpenGL_LoadOBJ(char *fileName);
	void DirectX_LoadOBJ(char *fileName);
	void BindToRenderPipleLine();
	static ObjLoader* Instance();


private:
	static ObjLoader* instance_;
	//load those data in to heap----provent stack overflow.
	//std::vector<float> vertices;
	//std::vector<float> texturesUV;
	//std::vector<float> normals;
	//std::vector<unsigned int> faces;
};

