/*
AA Engine
Copy right: Zhu,Wei Visin
Date: 17_12_2015
*/

#include "Vector3.h"

#define PI 3.141592654

namespace AAEngine{

	Vector3::Vector3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vector3::Vector3(float ax, float ay, float az)
	{
		x = ax;
		y = ay;
		z = az;
	}

	Vector3 Vector3::operator-()const
	{
		Vector3 result;
		result.x = -x;
		result.y = -y;
		result.z = -z;
		return result;
	}

	Vector3 Vector3::operator+(const Vector3& other) const
	{
		Vector3 result;
		result.x = x + other.x;
		result.y = y + other.y;
		result.z = z + other.z;
		return result;
	}
	Vector3 Vector3::operator-(const Vector3& other)const
	{
		Vector3 result;
		result.x = x + other.x;
		result.y = y + other.y;
		result.z = z + other.z;
		return result;
	}
	Vector3 Vector3::operator=(const Vector3& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		return other;
	}
	Vector3 Vector3::operator*(float c)const
	{
		Vector3 result;
		result.x = x*c;
		result.y = y*c;
		result.z = z*c;
		return result;
	}
	Vector3 operator*(float c, const Vector3& v)
	{
		return v*c;
	}
	Vector3 Vector3::operator/(float c) const
	{
		Vector3 result;
		result.x = x / c;
		result.y = y / c;
		result.z = z / c;
		return result;
	}
	float Vector3::squareMagnitude()
	{
		return x*x + y*y + z*z;
	}

	float Vector3::magnitude()
	{
		return sqrt(squareMagnitude());
	}
	Vector3 Vector3::normalze()
	{
		return Vector3(x / magnitude(), y / magnitude(), z / magnitude());
	}
	//=================================================================
	float distance(const Vector3& a, const Vector3& b)
	{
		return (a - b).magnitude();
	}
	Vector3 Cross(const Vector3& a, const Vector3& b)
	{
		return Vector3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
	}
	float Vector3::Dot(const Vector3& a, const Vector3& b)
	{
		return (a.x*b.x + a.y*b.y + a.z*b.z);
	}

	float AngleBetween(Vector3& a, Vector3& b)
	{
		float dot = Vector3::Dot(a, b);
		return acos(dot / (a.magnitude() * b.magnitude())) * 180.0f / PI;
	}
	bool IsPerpendicular(const Vector3& a, const Vector3& b)
	{
		//return (AngleBetween(a,b) == 90);// Is there any effecient way?
		return ((a.x * a.y * a.z) + (b.x *b.y *b.z) == 0);
	}
	bool IsParalle(const Vector3& a, const Vector3& b)
	{
		return ((a.x * b.y - b.x *a.y == 0) && (a.x*b.z - b.x *a.z) == 0);
	}
}