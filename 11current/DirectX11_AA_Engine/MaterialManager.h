#pragma once
#include <map>
#include "Material.h"

class MaterialManager
{
public:
	MaterialManager();
	~MaterialManager();

	static void SingleTn();

	Material* GetAMaterial(std::string name);

	static MaterialManager* instance;
	static std::map<std::string, Material*> materialMap;
};

