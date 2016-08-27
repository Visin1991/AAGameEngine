#pragma once
#include<D3D11.h>

//
//Driver
//
D3D_DRIVER_TYPE driverTypes[] =
{
	D3D_DRIVER_TYPE_HARDWARE, D3D_DRIVER_TYPE_WARP,
	D3D_DRIVER_TYPE_REFERENCE, D3D_DRIVER_TYPE_SOFTWARE
};
unsigned int totalDriverTypes = ARRAYSIZE(driverTypes);

//
//featureLevels
//
D3D_FEATURE_LEVEL featureLevels[] =
{
	D3D_FEATURE_LEVEL_11_0,
	D3D_FEATURE_LEVEL_10_1,
	D3D_FEATURE_LEVEL_10_0,
	D3D_FEATURE_LEVEL_9_3
};
unsigned int totalFeatureLevels = ARRAYSIZE(featureLevels);