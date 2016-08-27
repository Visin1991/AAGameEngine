#include "MeshManager.h"

std::map<std::string, Mesh*> MeshManager::MeshsMap;

MeshManager* MeshManager::instance = nullptr;

MeshManager::MeshManager()
{
}

MeshManager::~MeshManager()
{
}

void MeshManager::SingleTon() {
	if (instance == nullptr)
		instance = new MeshManager();
}

Mesh* MeshManager::GetAMesh(std::string name) {
	if (MeshsMap.find(name) != MeshsMap.end())
		return MeshsMap[name];
	Mesh* temp = new Mesh();
	MeshsMap[name] = temp;
	return temp;
}
