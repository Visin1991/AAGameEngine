#pragma once
 
namespace AAEngine {

	struct Vector4 {
		float x;
		float y;
		float z;
		float w;

		Vector4() {
			x = 0.0f;
			y = 0.0f;
			z= 0.0f;
			w = 0.0f;
		}

		Vector4(float _x,float _y,float _z,float _w) {
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}

	};
}