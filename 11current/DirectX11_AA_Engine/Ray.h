#pragma once
#include"Math\AAMath.h"

namespace AAEngine {
	struct Ray {
		Vector3 origin;
		Vector3 direction;

		Ray(Vector3 _origin, Vector3 _direction) {
			origin = _origin;
			direction = _direction.normalze();
		}

		Vector3 GetPoint(float distance) {
			return distance * direction;
		}
	};
}