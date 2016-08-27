#pragma once
#include<array>
#include<vector>
#include"GameObject3D.h"

class ObjectManager
{
private:
	std::vector<GameObject3D*> objs;
public:
	void Update();
	bool Initial();
	ObjectManager();
	~ObjectManager();
};

