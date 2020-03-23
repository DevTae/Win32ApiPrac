#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Window Styles 검색
// https://docs.microsoft.com/en-us/windows/win32/winmsg/window-styles

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	// 구조체 정의
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance,
		MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "basic";
	wcex.hIconSm = LoadIcon(wcex.hInstance,
		MAKEINTRESOURCE(IDI_APPLICATION)); // hIcon Small

	// 구조체 등록
	RegisterClassEx(&wcex);

	// 윈도우 생성
	HWND hWnd = CreateWindow(wcex.lpszClassName, "HelloWorld",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, // 운영체제 기본 위치 값 설정
		CW_USEDEFAULT, // 운영체제 기본 위치 값 설정
		800, 600, NULL, NULL,
		hInstance, NULL);

	// 윈도우 출력
	ShowWindow(hWnd, nCmdShow);
	//ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	// 메세지 루프
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd,
	UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc; // 화면 관련 핸들

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: 화면 그리기 관련 코드
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		// TODO: 메모리 해제 관련 코드

		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message,
			wParam, lParam);
	}
	return 0;
}
