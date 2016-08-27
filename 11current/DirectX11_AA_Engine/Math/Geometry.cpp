#include "Geometry.h"

namespace AAEngine
{
	//==================================================
	// Segment2D
	//==================================================
	Segment2D::Segment2D()
	{
		a.x = a.y= b.x = b.y =0.0f;
	}
	Segment2D::Segment2D(const Vector2 a_copy,const Vector2 b_copy)
	{
		a = a_copy; b = b_copy;
	}
	Segment2D::Segment2D(float x0,float y0,float x1, float y1)
	{
		a.x = x0; a.y = y0; b.x = x1; b.y = y1;
	}
	float Segment2D::magnitude()
	{
		return (a - b).magnitude();
	}
	float Segment2D::squareMagnitude()
	{
		return (a - b).squareMagnitude();
	}
	void Segment2D::DrawSegment2D()
	{
		
	}
	//==================================================
	// Rectangle
	//==================================================
	Rectangle::Rectangle()
	{
		x = y = w = h = 0.0f;
	}
	Rectangle::Rectangle(float x_copy, float y_copy,float w_copy,float h_copy)
	{
		x = x_copy; y = y_copy; w = w_copy; h = h_copy;
	}
	
	//==================================================
	// Face
	//==================================================
	Face::Face(Vector3 _p1, Vector3 _p2, Vector3 _p3) {
		p1 = _p1;
		p2 = _p2;
		p3 = _p3;
	}
	 bool Face::above(Vector3 vertex, Vector3 p, Vector3 n)
    {
       return Vector3::Dot(n, vertex - p) > 0;
    }
}