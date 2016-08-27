#pragma once
#include"Math\AAMath.h"
#include"Ray.h"

namespace AAEngine {

	struct Bounds {
		Vector3 center;    //The center of the bounding box.
		Vector3 extents;   //The extents of the box. This is always half of the size.
		Vector3 max;       //The maximal point of the box.This is always equal to center + extents.
		Vector3 min;       //The minimal point of the box. This is always equal to center-extents.
		Vector3 size;      //The total size of the box.This is always twice as large as the extents.

		Bounds(Vector3 _center, Vector3 _size) {
			center = _center;
			size = _size;
			extents = size / 2;
			max = center + extents;
			min = center - extents;
		}

		Vector3 ClosestPoint(Vector3 point) {

			//Vector3 The point on the bounding box or inside the bounding box.

			//If the point is inside the bounding box, unmodified point position will be returned.

			return Vector3(0, 0, 0);
		}

		bool Contains(Vector3 point) {
			return false;
		}

		void Encapsulate(Vector3 point) {
			//Grows the Bounds to include the point.
			//Grow the bounds to encapsulate the bounds.
		}

		void Expand(Vector3 amount) {
			extents = extents + amount;
			size = 2 * extents;
			max = center + extents;
			min = center - extents;
		}

		bool IntersectRay(Ray ray) {
			//check if the ray intersect with each face of the box;
			return false;
		}

		bool Intersects(Bounds other) {
			//Does another bounding box intersect with this bounding box?
			return false;
		}

		float SqrDistance() {
			//The smallest squared distance between the point and this bounding box.
			return 0.0f;
		}
	};
}