#pragma once

#include"ComponentBaseHeader.h"

using namespace AAEngine;

class RigidBodyManager;

class RigidBody : public MonoBehaviour
{
	friend RigidBodyManager;

	DECLEAR_DYNCRT_ACTION(RigidBody)
public:
	static std::string stype;
public:
	~RigidBody(void);

	virtual void Awake();
};

std::string RigidBody::stype = "RigidBody";
