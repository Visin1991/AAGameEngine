#pragma once
#include"Math\AAMath.h"

namespace AAEngine {

	struct Color
	{
		//static Variable
		static Vector4 black;
		static Vector4 blue;
		static Vector4 clear;
		static Vector4 cyan;
		static Vector4 gray;
		static Vector4 green;
		static Vector4 magenta;
		static Vector4 red;
		static Vector4 white;
		static Vector4 yellow;

		//variable;
		float r;
		float g;
		float b;
		float a;
		
		float grayscale;    //Y = 0.299R' + 0.578G' + 0.114B'
		float grayscaleHD;  //Y = 0.2126R' 0.7152G' + 0.0722B'
		
		
		
		//Construcor
		Color();
		Color(float r, float g, float b,float a);
		~Color();

		//Function
		float MaxColorComponent();
		//Color* GetGamma;       //A version of the color that has had the gamma curve applied.
		//Color* GetLinear;      //with inverse of sRGB gamma curve applied.

		//Color* Lerp();
	};	
}