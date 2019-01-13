/*************************************************************************************************************************************
* Name : Plain Window with Message Box
* Discription : Pain Window with Generic Painter we use this in OpenGL and DirectX
**************************************************************************************************************************************/
//headers
#include<windows.h>

//global function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//winmain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declaration 
	WNDCLASSEX wndclass;
	TCHAR szAppName[] = TEXT("MyApp");
	HWND hwnd;
	MSG msg;
	

	//code
	//intialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//Register above created class
	RegisterClassEx(&wndclass);

	//create Window
	hwnd = CreateWindow(szAppName,
		TEXT("My Application"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//Message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return ((int)msg.wParam);

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	RECT rc;
	TCHAR str[] = TEXT("Hello World !!!");
	HDC hdc;
	//code
	switch (iMsg)
	{
	case WM_CREATE: MessageBox(hwnd, TEXT("This is WM_CREATE"), TEXT("My Message"), MB_OK);
		break;

		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:MessageBox(hwnd, TEXT("This isEscape"), TEXT("My Message"), MB_OK);
			DestroyWindow(hwnd);


		case 0x46:MessageBox(hwnd, TEXT("This is f key"), TEXT("My Message"), MB_OK);

		}
		break;

	case WM_LBUTTONDOWN:  MessageBox(hwnd, TEXT("This is LBUTTONDOWN"), TEXT("My Message"), MB_OK);
		GetClientRect(hwnd, &rc);
		hdc = GetDC(hwnd);
		SetBkColor(hdc, RGB(0, 0, 0));
		SetTextColor(hdc, RGB(0, 255, 0));
		DrawText(hdc, str, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;
		break;
	case WM_RBUTTONDOWN:MessageBox(hwnd, TEXT("This is RBUTTONDOWN"), TEXT("My Message"), MB_OK);
		break;
	case WM_DESTROY: PostQuitMessage(0);
		break;
	}
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}