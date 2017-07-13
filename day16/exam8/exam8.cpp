// exam8.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "exam8.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.
	plusEngine::startUpGdiPlus();
    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EXAM8, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXAM8));

    MSG msg;

    // �⺻ �޽��� �����Դϴ�.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
	plusEngine::CloseGdiPlus();
    return (int) msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EXAM8));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EXAM8);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
REAL g_fAngle;
REAL g_fTopAngle;

irr::core::vector2df g_vPosition;
irr::core::vector2df g_vTopPosition;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
		g_fAngle = 0.0;
		g_vPosition.set(0, 0);
		
		break;
	case WM_KEYDOWN:
	{
		irr::core::vector2df vDir(0, 1);
		vDir.rotateBy(g_fAngle);
		switch (wParam)
		{
		case VK_UP:
		{
			//g_vPosition -= (irr::core::vector2df(0,1) * 10.);
			g_vPosition -= vDir *10.;
			//g_vPosition -= (irr::core::vector2df(-sin(3.14*(g_fAngle / 180.)), cos(3.14*(g_fAngle / 180.))) * 10.); // vDir������
			//g_vPosition.Y -= 10 * cos(3.14*(g_fAngle / 180.));
			//g_vPosition.X += 10 * sin(3.14*(g_fAngle / 180.));
		}
		break;
		case VK_DOWN:
		{
			//g_vPosition += (irr::core::vector2df(0, 1) * 10.);
			g_vPosition += vDir *10.;
			//g_vPosition += (irr::core::vector2df(-sin(3.14*(g_fAngle / 180.)), cos(3.14*(g_fAngle / 180.))) * 10.);
			//g_vPosition.Y += 10 * cos(3.14*(g_fAngle / 180.));
			//g_vPosition.X -= 10 * sin(3.14*(g_fAngle / 180.));
		}
		break;
		case VK_RIGHT:
		{
		
			g_fAngle += 8.;
			//g_fTopAngle += 8;
		}
		break;
		case VK_LEFT:
		{
			g_fAngle -= 8.;
			//g_fTopAngle -= 8;
		}

		break;
		case 0x41:
		{
			g_fTopAngle -= 8.;
		}

		break;
		case 0x44:
		{
			g_fTopAngle += 8.;
		}

		break;
		default:
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
	}
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �޴� ������ ���� �м��մϴ�.
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.
			Graphics grp(hdc);
			Pen pen(Color(0, 0, 0));
			grp.DrawRectangle(&pen, 0, 0, 320, 240);
			grp.DrawLine(&pen, 0, 120, 320, 120);
			grp.DrawLine(&pen, 160, 0, 160, 240);

			grp.SetTransform(&Matrix(1,0,0,1,160,120));

			//��ũ �׸���
			{
				Matrix oldMat;
				grp.GetTransform(&oldMat);
				
				grp.TranslateTransform(g_vPosition.X, g_vPosition.Y);
				grp.RotateTransform(g_fAngle);
				//body
				grp.DrawRectangle(&pen,-20,-30,40,60);
				//top
				grp.RotateTransform(g_fTopAngle);
				grp.DrawRectangle(&pen, -5, -15, 10, 20);
				grp.DrawRectangle(&pen, -10, -10, 20, 20);
				grp.ResetTransform();
				grp.SetTransform(&oldMat);
			}

			grp.ResetTransform();
			EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}