//
//  Display.h
//  Snake
//
//  Created by Katekov Anton on 10/18/12.
//
//

#ifndef __Snake__Display__
#define __Snake__Display__
#include "GlobalConstants.h"
#ifdef TARGET_OS_IPHONE
#include GLES2
#endif

#ifdef TARGET_OS_WIN
#include <windows.h>
#include "glew.h"
#include "glext.h"
#include "wchar.h"
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#include "DisplayInputDelegate.h"
#include <iostream>
#include "platform/CCEGLViewProtocol.h"

using namespace cocos2d;

class Display : public CCEGLViewProtocol {
    static Display * _current;
    
public:
    static Display * currentDisplay();
    
    virtual void  InitGLSurface(unsigned int depthFormat, unsigned int pixelFormat);
    
    virtual GLfloat GetDisplayHeight();
    virtual GLfloat GetDisplayWidth();
    
    virtual GLfloat GetDisplayScale();
    
    virtual void SwapBuffers();
    
    void SetViewPortInPoints(float x , float y , float w , float h);
    void SetScissorInPoints(float x , float y , float w , float h);

    virtual void SetPinchDelegate(DisplayInputDelegate* delegate);
};

#endif /* defined(__Snake__Display__) */