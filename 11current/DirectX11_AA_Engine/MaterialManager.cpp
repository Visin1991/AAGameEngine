#include "MaterialManager.h"

MaterialManager* MaterialManager::instance = nullptr;;
std::map<std::string, Material*> MaterialManager::materialMap;

MaterialManager::MaterialManager()
{
}


MaterialManager::~MaterialManager()
{
}

void MaterialManager::SingleTn() {
	if (instance == nullptr)
		instance = new MaterialManager();
}

Material* MaterialManager::GetAMaterial(std::string name) {
	if (materialMap.find(name) != materialMap.end()) {
		return materialMap[name];
	}
	Material* tempMat = new Material();
	materialMap[name] = tempMat;
	return tempMat;
}
