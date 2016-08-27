#include "RigidBody.h"

IMPLEMENT_DYNCRT_ACTION(RigidBody)

RigidBody::~RigidBody()
{

}
void RigidBody::Awake() {
	std::cout << "Down Load data for the RigidBody" << std::endl;
}

