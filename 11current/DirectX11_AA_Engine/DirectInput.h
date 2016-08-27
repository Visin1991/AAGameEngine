#pragma once

#include <dinput.h>

#define KEYDOWN( name, key ) ( name[key] & 0x80 )

class DirectInput
{
public:
	DirectInput();
	~DirectInput();
	bool Init(HINSTANCE &hinstance, HWND& hw);
	void Update();
	void ReleaseAll();
private:
	LPDIRECTINPUT8 directInput_;
	LPDIRECTINPUTDEVICE8A keyboardDevice_;
	char keyboardKeys_[256];
	char prevKeyboardKeys_[256];
};

