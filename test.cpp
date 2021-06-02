#include <WinGDI.h>
#pragma comment(lib, "Msimg32.lib")

//bool PaintBmp(HWND hWnd)
//{
//    // Gets a handle to the display device context environment for the client area of the window
//    HDC hDC = ::GetDC(hWnd);
//    // Create an hDC Compatible memory device context environment
//    HDC hBuf = ::CreateCompatibleDC(hDC);
//    // Load bitmap, Get bitmap handle
//    HBITMAP hBmp = (HBITMAP)::LoadImage(NULL, "image\\bg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
//    // Select bitmap handle to hBuf in, And get the returned original bitmap handle
//    HBITMAP hOldBmp = (HBITMAP)::SelectObject(hBuf, hBmp);
//    // mapping
//    ::BitBlt(hDC, 0, 0, 764, 397, hBuf, 0, 0, SRCCOPY);
//    // Restore bitmap objects
//    ::SelectObject(hBuf, hOldBmp);
//    // Release bitmap
//    ::DeleteObject(hBmp);
//    // Release compatible memory device context environment
//    ::DeleteDC(hBuf);
//    // Release device context
//    ::ReleaseDC(hWnd, hDC);
//    return TRUE;
//}

//bool PaintTransparentBmp(HWND hWnd)
//{
//    // Gets a handle to the display device context environment for the client area of the window
//    HDC hDC = ::GetDC(hWnd);
//    // Create an hDC Compatible memory device context environment
//    HDC hBuf = ::CreateCompatibleDC(hDC);
//    // Load bitmap, Get bitmap handle
//    HBITMAP hBmp = (HBITMAP)::LoadImage(NULL, "image\\1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
//    // Select bitmap handle to hBuf in, And get the returned original bitmap handle
//    HBITMAP hOldBmp = (HBITMAP)::SelectObject(hBuf, hBmp);
//    // The transparent color is drawn in blue
//    ::TransparentBlt(hDC, 280, 210, 200, 200, hBuf, 0, 0, 101, 121, RGB(0, 0, 255));
//    // Restore bitmap objects
//    ::SelectObject(hBuf, hOldBmp);
//    // Release bitmap
//    ::DeleteObject(hBmp);
//    // Release compatible memory device context environment
//    ::DeleteDC(hBuf);
//    // Release device context
//    ::ReleaseDC(hWnd, hDC);
//    return TRUE;
//}
