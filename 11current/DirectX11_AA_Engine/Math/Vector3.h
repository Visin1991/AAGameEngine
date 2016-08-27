/*
AA Engine
Copy right: Zhu,Wei Visin
Date: 17_12_2015
*/
#ifndef _VECTOR3_H_17_12_2015_
#define _VECTOR3_H_17_12_2015_

#include<iostream>

namespace AAEngine
{
		struct Vector3
		{
			Vector3();
			//Vector3(const Vector3& copy);
			Vector3(float ax, float ay, float az);
			static float Dot(const Vector3& a, const Vector3& b);
			//unary operator
			//const meanse cannot change the private or protected variable
			Vector3 operator-() const;

			//binary operator
			Vector3 operator+(const Vector3& other)const;
			Vector3 operator-(const Vector3& other)const;
			Vector3 operator=(const Vector3& other);

			//scaler
			Vector3 operator*(float c) const;
			friend Vector3 operator*(float c, const Vector3& v);
			Vector3 operator/(float c)const;

			//utility
			float magnitude();
			float squareMagnitude();

			//normalize
			Vector3 normalze();

			float x, y, z;
		};
		//pass a const variable means cannot modify it, also can not implement any function on it, even the function didn't modify the variable
		float distance(const Vector3& a,const Vector3& b);
		Vector3 Cross(const Vector3& a, const Vector3& b);//get the Vector which perpendicular the plane which a and be stay on;
		
		float AngleBetween(Vector3& a, Vector3& b);
		bool IsPerpendicular(const Vector3& a,const Vector3& b);
		bool IsParalle(const Vector3& a, const Vector3& b);
}

#endif