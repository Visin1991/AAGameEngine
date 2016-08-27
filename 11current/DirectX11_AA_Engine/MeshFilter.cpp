#include "MeshFilter.h"

IMPLEMENT_DYNCRT_ACTION(MeshFilter)

MeshFilter::~MeshFilter()
{
	
}

void MeshFilter::Awake() {
	std::cout << "Down Load data for the MeshFilter" << std::endl;
}