#ifndef _GEOMETRY_H_2015_12_21
#define _GEOMETRY_H_2015_12_21
 
#include "Algorithm.h"

namespace AAEngine
{
		//==================================================
		// Segment2D
		//==================================================
		//This is a line, not a vector2( vector2 doesn't consider start and end point in Cardiers coordinates)
		struct Segment2D
		{
			Segment2D();
			//over here Vector2 is not consider to a vector, it is actrually a point in 2D space.
			//the segment is means from point a to point b;
			Segment2D(const Vector2 a_copy,const Vector2 b_copy);
			Segment2D(float x_copy,float y_copy,float w_copy,float h_copy);
			float magnitude();
			float squareMagnitude(); 
			Vector2 a, b;
			void DrawSegment2D();
		};
		//==================================================
		//Rectangle
		//==================================================
		// Rectangle
		struct Rectangle
		{
			Rectangle();
			Rectangle(float x, float y, float w, float h);
			
			float x, y, w, h;
		};

		struct Face {
			Vector3 p1;
			Vector3 p2;
			Vector3 p3;
			Face(Vector3 _p1, Vector3 _p2, Vector3 _p3);
			bool above(Vector3 vertex, Vector3 p, Vector3 normal);
		};
}
#endif
