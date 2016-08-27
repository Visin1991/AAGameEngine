#pragma once

#include"ComponentBaseHeader.h"
#include "Mesh.h"

using namespace AAEngine;

class MeshFilter : public MonoBehaviour
{
	DECLEAR_DYNCRT_ACTION(MeshFilter)
public:
	~MeshFilter();

	virtual void Awake();
};

