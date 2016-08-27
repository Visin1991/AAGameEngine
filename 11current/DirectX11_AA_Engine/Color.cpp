#include"Color.h"

namespace AAEngine {
	Vector4 Color::black = Vector4(0, 0, 0, 1);
	Vector4 Color::blue = Vector4(0, 0, 1, 1);
	Vector4 Color::clear = Vector4(0, 0, 0, 0);
	Vector4 Color::cyan = Vector4(0, 1, 1, 1);
	Vector4 Color::gray = Vector4(0.5, 0.5, 0.5, 1);
	Vector4 Color::green = Vector4(0, 1, 0, 1);
	Vector4 Color::magenta = Vector4(1, 0, 1, 1);
	Vector4 Color::red = Vector4(1, 0, 1, 1);
	Vector4 Color::white = Vector4(1, 1, 1, 1);
	Vector4 Color::yellow = Vector4(1, 0.92, 0.016, 1);

	Color::Color() {
		r = 1;
		g = 1;
		b = 1;
		a = 1;
	}
	Color::~Color() {

	}
	Color::Color(float _r, float _g, float _b,float _a) {
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	
	}
	float Color::MaxColorComponent(){ 
		return  (r > g ? r : g) > b ? (r > g ? r : g) : b;
	}
}