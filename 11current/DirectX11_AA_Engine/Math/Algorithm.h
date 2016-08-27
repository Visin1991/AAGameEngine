#ifndef _ALGORITHM_H_12_24_2015_
#define _ALGORITHM_H_12_24_2015_

#include <cstdlib>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <math.h>
#include <time.h>

#define PI 3.141592654

namespace AAEngine
{
	//-------------------------------
	//Linear Function
	static int pow(int b, int e)
	{
		if (e == 0)
			return 0;
		if (e == 1)
			return 1;
		if (e % 2 == 0)
			return pow(b*b, e / 2);
		else
			return b*pow(b, e - 1);
	}
	//-----------------------------
	// Random function
	static int random(int low, int high)
	{
		srand(time(nullptr));
		return rand() % (high - low + 1) + low;
	}
	static float random(float low, float high)
	{
		srand(time(nullptr));
		float range = high - low;
		int i_range = int(range * 1000);
		float random_num = rand() % i_range;
		return random_num / 1000 + low;
	}
	struct Random
	{
		//Spherical coordinates (p, θ, φ) 
		//polar angle θ (theta)     0 <= θ <=180;
		//azimuthal angle φ (phi).  0 <= φ <=360;
		//theta = random(0, 180);
		float theta = random(0, 180);
		float phi = random(0, 180);
		float x = sin(theta*PI / 180)*cos(phi*PI / 180);
		float y = sin(theta*PI / 180)*sin(phi*PI / 180);
		float z = cos(theta*PI / 180);
		Vector3 onUnitSphere = Vector3(x, y, z);

		float x2 = random(0.0f, 1.0f) * x;
		float y2 = random(0.0f, 1.0f) * y;
		float z2 = random(0.0f, 1.0f) * z;
		Vector3 insideUnitSphere = Vector3(x2, y2, z2);

		float angle = random(0, 360);
		Vector2 onUnitCircle = Vector2(cos(angle), sin(angle));
		Vector2 insideUnitCircle = Vector2(random(0.0f, 1.0f)*cos(angle), random(0.0f, 1.0f)*sin(angle));
	};

	//-----------------------------------------------
	// basc comparetion
	template<typename T>
	inline T Min(T x, T y) { return x > y ? x : y; }
	template<typename T>
	inline T Max(T x, T y) { return x < y ? x : y; }

	template<typename T>
	inline T Lerp(T a, T b, T c){ return a + c*(b - a); }
	// return a when c=0, return b when c=1;
	// when c = 0.5, return a + half of the distance between a and b;
}
#endif