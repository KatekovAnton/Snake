#pragma once
#include "display.h"
#include <windows.h>

class DisplayInputDelegate;

class windows_display :
	public Display
{

	float w;
	float h;
	HDC			hDC;
	HWND		hWND;
	bool		_mouseDown;
	bool		_mouseDownToCocos;
	POINT		_mouseDownPoint;
	POINT		_mousePointLast;
	DisplayInputDelegate** _delegate;
public:
	
	windows_display(float _w, float _h, HDC _hDC, HWND _hWND, DisplayInputDelegate **_actionDelegate);
	windows_display(void);
	~windows_display(void);

	static void SetSharedDisplay(windows_display* display);
	static windows_display* GetSharedDisplay();

	virtual void InitGLSurface(unsigned int depthFormat, unsigned int pixelFormat);
    
    virtual GLfloat GetDisplayHeight();
    virtual GLfloat GetDisplayWidth();
    virtual GLfloat GetDisplayScale();
    
    virtual void    SwapBuffers();
    
    virtual bool    isOpenGLReady();
    virtual bool    setContentScaleFactor(float contentScaleFactor);
    
    // keep compatible
    virtual void    end();
    virtual void    swapBuffers();
    
    virtual void setIMEKeyboardState(bool bOpen);
    virtual void SetPinchDelegate(DisplayInputDelegate* _newDelegate);

	virtual void setDesignResolutionSize(float width, float height, ResolutionPolicy resolutionPolicy);
	void ProceedMessage(MSG msg);
};

