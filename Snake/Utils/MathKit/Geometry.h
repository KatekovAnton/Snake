//
//  MathKit.h
//  Snake
//
//  Created by Katekov Anton on 10/30/12.
//
//

#ifndef Snake_MathKit_h
#define Snake_MathKit_h

#include "GlobalConstants.h"

#ifdef  TARGET_OS_IPHONE
    #define GLES2    <OpenGLES/ES2/gl.h>
    #define Glext    <OpenGLES/ES2/glext.h>
#include GLES2
#include Glext
#endif 
#ifdef TARGET_OS_WIN
#include <windows.h>
#include "glew.h"
#include "glext.h"
#include "wchar.h"
#include <GL/gl.h>
#include <GL/glu.h>
#endif

template <typename T> static __inline__
T __min(T a, T b)
{
    return a<b?a:b;
}

template <typename T> static __inline__
T __max(T a, T b)
{
    return a>b?a:b;
}

struct __GPoint2D {
    GLfloat x;
    GLfloat y;
};

struct __GSize2D {
    GLfloat height;
    GLfloat width;
};

struct __GRect2D {
    struct __GPoint2D   origin;
    struct __GSize2D    size;
};


typedef struct __GPoint2D GPoint2D;
typedef struct __GRect2D GRect2D;
typedef struct __GSize2D GSize2D;


static __inline__ GRect2D GRect2DMake(GLfloat x, GLfloat y, GLfloat width, GLfloat height) {
    GRect2D rect;
    rect.origin.x = x;
    rect.origin.y = y;
    rect.size.width = width;
    rect.size.height = height;
    return rect;
};


#include "MyMath.h"
#include "GLKMath.h"

struct __BoundingBox {
    GLKVector2 min;
    GLKVector2 max;
    
    GLKVector2 GetCenter() const {return GLKVector2Make((min.x + max.x)/2.0, (min.y + max.y)/2.0); }
    GLKVector2 GetSize() const {return GLKVector2Make(- (min.x - max.x), -(min.y - max.y)); }
    
    void AddBoundingBox(__BoundingBox bb)
    {
        min.x = __min(min.x, bb.min.x);
        min.y = __min(min.y, bb.min.y);
        max.x = __max(max.x, bb.max.x);
        max.y = __max(max.y, bb.max.y);
    }
    
};
typedef struct __BoundingBox BoundingBox;

static __inline__ BoundingBox BoundingBoxMake(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    BoundingBox rect;
    rect.min.x = x1;
    rect.min.y = y1;
    rect.max.x = x2;
    rect.max.y = y2;
    return rect;
};

static __inline__ BoundingBox BoundingBoxMake(GLKVector2 min, GLKVector2 max) {
    BoundingBox rect;
    rect.min = min;
    rect.max = max;
    return rect;
};

enum __ContainmentType
{
    ContainmentType_Disjoint,
    ContainmentType_Contains,
    ContainmentType_Intersects
};

typedef enum __ContainmentType ContainmentType;


static __inline__ ContainmentType GetContainmentType(BoundingBox first, BoundingBox second)
{
    if (first.max.x < second.min.x || first.max.y < second.min.y ||
        first.min.x > second.max.x || first.min.y > second.max.y) {
        return ContainmentType_Disjoint;
    }
    
    if (second.min.x > first.min.x && second.min.y > first.min.y &&
        second.max.x < first.max.x && second.max.y < first.max.y) {
        return ContainmentType_Contains;
    }
    
    return ContainmentType_Intersects;
}

//http://www.opengl.org/wiki/GluProject_and_gluUnProject_code

#endif