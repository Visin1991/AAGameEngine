/*
AA Engine
Copy right: Zhu,Wei Visin
Date: 17_12_2015
*/
#ifndef _VECTOR2_H_17_12_2015
#define _VECTOR2_H_17_12_2015

#include <iostream>

namespace AAEngine
{
		struct Vector2
		{
			Vector2();
			//Vector2(const Vector2& copy);
			Vector2(float ax, float ay);

			//unary operator
			Vector2	operator+() const;
			Vector2 operator-() const;

			//binary operator
			Vector2 operator+(const Vector2& other) const;
			Vector2 operator-(const Vector2& other) const;
			Vector2 operator=(const Vector2& other);

			//scaler
			Vector2 operator*(float c) const;
			friend Vector2 operator*(float c, const Vector2& v);
			Vector2 operator/(float c) const;

			//utility function
			float magnitude();
			float squareMagnitude();

			//normalize
			Vector2 normalze();

			float x, y;
		};
		float distance(const Vector2& a, const Vector2& b);
		float Dot(const Vector2& a, const Vector2& b);
		float AngleBetween(Vector2& a, Vector2& b);
		bool IsPerpendicular(const Vector2& a, const Vector2& b);
		bool IsParalle(const Vector2& a, const Vector2& b);
		Vector2 ProjectionA_On_B(Vector2& a, Vector2& b);
}
#endif