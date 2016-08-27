#include <Windows.h>
#include <memory>
#include "constants.h"
#include "GameEngineManager.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow);
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);//Windows Callback Procedure
bool CreateMainWindow(HWND& hwnd, HINSTANCE hInstance, int cmdShow);
HWND hwnd = NULL; //handle window, it is a pointer

int WINAPI wWinMain(HINSTANCE hInstance,HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	UNREFERENCED_PARAMETER(prevInstance);//nothing special for this function
	UNREFERENCED_PARAMETER(cmdLine);//nothing special for this function
	
	if (!CreateMainWindow(hwnd, hInstance, cmdShow))
		return 0;
	/*/=====================================================================================
	//Demo initialze
	//=====================================================================================*/
	std::auto_ptr<GameEngineManager> gameEngineMananger(new GameEngineManager()); // need #include <memory>
	bool result = gameEngineMananger->Init(hInstance, hwnd);

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);  //decode and pass messages on to WinProc //If our application is going to accept character input from the user, it needs to call the TranslateMessage function inside the message loop
			DispatchMessage(&msg); /*to WinProc*/ //The messagesare sent to our WinProc function for processing by the Dispatch Message function.
		}
		else
		{
			gameEngineMananger->Update();
		}
	}
	// Demo Shutdown
	gameEngineMananger->ReleaseAll();

	return static_cast<int>(msg.wParam); //casting numerical data, like we are doing in Listing 2.3 by casting the wParam to an integer.
}

bool CreateMainWindow(HWND& hwnd,HINSTANCE hInstance,int cmdShow)
{
	//=====================================================================================
	//Set up the property for wndClass.
	//=====================================================================================
	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);				 //The size of the structure of wndClass in bytes.
	wndClass.style = CS_DBLCLKS | CS_OWNDC | 
					 CS_HREDRAW | CS_VREDRAW;			 //Style flags used to define the window’s look
	wndClass.lpfnWndProc = WndProc;						 //call back Function, we will create.
	wndClass.hInstance = hInstance;                      //The application instance that contains the windows procedure(callback) for this window class.
	//wndClass.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(ICON_GL));
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);   //A handle to the background brush that will be used for	painting the window’s background.
	wndClass.lpszMenuName = NULL;                          //A null-terminated string of the resource name for the	menu. //we dont wanna a windows meanu, so we set to null
	wndClass.lpszClassName = "DX11BookWindowClass";        //A null - terminated string for what you wish to name your window class.The maximum length is 256 characters.
	//wndClass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(ICON_GL));
	//=====================================================================================											  
	//register the window class.
	//=====================================================================================
	if (!RegisterClassEx(&wndClass))
		return -1;
	/*/=====================================================================================
	//to calculate the size required of the window based on our desired dimensions and style
	//=====================================================================================*/
	RECT rc = { 0, 0, GAME_WIDTH, GAME_HEIGHT };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);//false means no menu
	/*/=====================================================================================
	//Create the actual window
	//=====================================================================================*/
		hwnd = CreateWindowA(
		"DX11BookWindowClass", //lpClassName---window class name, Same to the name, we setuped.
		"Blank Win32 Window",  //lpWindowName--the window title bar text.
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,//dwStyle-------window's style flag.
		CW_USEDEFAULT,         //x-------------the Window's horizontal position
		CW_USEDEFAULT,		 //y-------------the Window's vertical position
		rc.right - rc.left,	 //width---------the window's width
		rc.bottom - rc.top,    //height--------the window's height
		NULL,					 //hWndParent----Handle to the parent window’s handle (optional if this new window is a pop - up or child window).
		NULL,					 //hMenu---------Resource handle to the window’s menu
		hInstance,
		NULL);
	/*/=====================================================================================
	//Show the window
	//=====================================================================================*/
	if (!hwnd)
		return -1;

	//if (!FULLSCREEN)
	//{
	//	// adjust window size so client area is GAME_WIDTH x GAME_HEIGHT
	//	RECT clientRect;//The RECT structure defines the coordinates of the upper-left and lower-right corners of a rectangle.
	//	GetClientRect(hwnd, &clientRect);
	//	MoveWindow(hwnd,
	//		0,	// left 
	//		0,  // Top
	//		GAME_WIDTH + (GAME_WIDTH - clientRect.right), // Right
	//		GAME_HEIGHT + (GAME_HEIGHT - clientRect.bottom), // bottom
	//		true);
	//}

	ShowWindow(hwnd, cmdShow);

	// Send a WM_PAINT message to the window procedure
	//UpdateWindow(hwnd);
	return true;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) //Windows Callback Procedure
{
	PAINTSTRUCT paintStruct;
	HDC hDC;

	switch (message)
	{
	case WM_CREATE:
	{
		// do initialization stuff here
		// return success
		return(0);
	} break;

	case WM_PAINT:
		hDC = BeginPaint(hwnd, &paintStruct); //Handle to Device Context //hDC=GetDC(hWnd)
		EndPaint(hwnd, &paintStruct);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}