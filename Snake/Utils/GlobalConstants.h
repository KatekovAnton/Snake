//
//  GlobalConstants.h
//  Snake
//
//  Created by Katekov Anton on 10/20/12.
//
//

#ifndef Snake_GlobalConstants_h
#define Snake_GlobalConstants_h


#ifdef  TARGET_OS_IPHONE
    #define GLES2    <OpenGLES/ES2/gl.h>
    #define Glext    <OpenGLES/ES2/glext.h>
	#include GLES2
#endif
#ifdef TARGET_OS_WIN
	#include <windows.h>
	#include "wchar.h"
	#include "glew.h"
	#include <GL/gl.h>
	#include <GL/glu.h>

	#define __inline__ inline
#endif

#define GCCHECK_GL_ERROR_DEBUG() \
        GLenum __error = glGetError(); \
        if(__error)  \
            printf("OpenGL error 0x%04X in %s %s %d\n", __error, __FILE__, __FUNCTION__, __LINE__); 

#endif
