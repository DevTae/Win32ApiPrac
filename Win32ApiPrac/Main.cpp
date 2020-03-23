#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Window Styles �˻�
// https://docs.microsoft.com/en-us/windows/win32/winmsg/window-styles

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	// ����ü ����
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

	// ����ü ���
	RegisterClassEx(&wcex);

	// ������ ����
	HWND hWnd = CreateWindow(wcex.lpszClassName, "HelloWorld",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, // �ü�� �⺻ ��ġ �� ����
		CW_USEDEFAULT, // �ü�� �⺻ ��ġ �� ����
		800, 600, NULL, NULL,
		hInstance, NULL);

	// ������ ���
	ShowWindow(hWnd, nCmdShow);
	//ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	// �޼��� ����
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
	HDC hdc; // ȭ�� ���� �ڵ�

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: ȭ�� �׸��� ���� �ڵ�
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		// TODO: �޸� ���� ���� �ڵ�

		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message,
			wParam, lParam);
	}
	return 0;
}
