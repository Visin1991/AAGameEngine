#pragma once
#include<map>
#include"Mesh.h"

class MeshManager
{
public:
	MeshManager();
	~MeshManager();

	static void SingleTon();

	Mesh* GetAMesh(std::string name);

	static std::map<std::string, Mesh*> MeshsMap;

	static MeshManager* instance;
};

