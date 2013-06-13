#include "windows_display.h"
#include <GL/GL.h>
#include <GL/GLU.h>
#include <windows.h>		// Header File For Windows

static windows_display* shared_display_instance = NULL;
void GetWindowPos(HWND hWnd, int *x, int *y)
{
    HWND hWndParent = GetParent(hWnd);

    RECT parentScreenRect;
    RECT itemScreenRect;
    GetWindowRect(hWndParent, &parentScreenRect);
    GetWindowRect(hWnd, &itemScreenRect);

    (*x) = itemScreenRect.left - parentScreenRect.left;
    (*y) = itemScreenRect.top - parentScreenRect.top;
}

windows_display::windows_display(float _w, float _h, HDC _hDC, HWND _hWND, DisplayInputDelegate **_actionDelegate)
	:_mouseDown(false), _mouseDownToCocos(false)
{
    w = _w;
	h = _h;

	hDC = _hDC;
	hWND= _hWND;
	this->_delegate = _actionDelegate;
}

windows_display::~windows_display(void)
{
}

void windows_display::SetSharedDisplay(windows_display* _display)
{
	shared_display_instance = _display;
}

windows_display* windows_display::GetSharedDisplay()
{
	return shared_display_instance;
}

windows_display::windows_display()
{
}

void windows_display::setDesignResolutionSize(float width, float height, ResolutionPolicy resolutionPolicy)
{
	this->setFrameSize(width, height);
	Display::setDesignResolutionSize(width, height, resolutionPolicy);
}

void windows_display::InitGLSurface(unsigned int depthFormat, unsigned int pixelFormat) {
    
   
}

GLfloat windows_display::GetDisplayHeight() {
    float result = h;
    return result;
}

GLfloat windows_display::GetDisplayWidth() {
    float result = w;
    return result;
}

GLfloat windows_display::GetDisplayScale()
{
    return 1.0;
}

void swapOglBuffers(HDC _p)
{
	SwapBuffers(_p);
}

void windows_display::SwapBuffers() {
	swapOglBuffers(hDC);
}

void windows_display::swapBuffers() {
    //SwapBuffers();
}

bool windows_display::isOpenGLReady() {
    return true;
}

bool windows_display::setContentScaleFactor(float contentScaleFactor) {
    return true;
}

void windows_display::end() {
    // do nothing;
}

void windows_display::setIMEKeyboardState(bool bOpen) {
    
}

void windows_display::SetPinchDelegate(DisplayInputDelegate* _newDelegate) {
	*this->_delegate = _newDelegate;
}

void windows_display::ProceedMessage(MSG msg)
{
	POINT position;
	
	GetCursorPos(&position);
	ScreenToClient(hWND, &position);

	DisplayInputDelegate* _delegateC = *_delegate;
	bool lastMouseFlag = _mouseDown;
	
	if (msg.message == WM_LBUTTONDOWN && !_mouseDown)
	{
		SetCapture(hWND);
		if (_delegateC->CanStartScreenInput(position.x,position.y))
		{
			_mouseDown = true;
			_mouseDownPoint = position;
		}
		else
		{
			_mouseDownToCocos = true;
			//to cocos
			int ids[1] = {0};
			float xs[1] = {position.x};
			float ys[1] = {position.y};
			this->handleTouchesBegin(1, ids, xs, ys); 
		}
	}
	if (msg.message == WM_LBUTTONUP)
	{
		if (_mouseDown)
		{
			_mouseDown = false;
			
		}
		else if (_mouseDownToCocos)
		{
			_mouseDownToCocos = false;
			//to cocos
			int ids[1] = {0};
			float xs[1] = {position.x};
			float ys[1] = {position.y};
			this->handleTouchesEnd(1, ids, xs, ys); 
		}
		ReleaseCapture();
	}


	_mousePointLast = position;
}