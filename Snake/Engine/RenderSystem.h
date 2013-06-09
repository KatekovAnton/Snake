//
//  RenderSystem.h
//  Snake
//
//  Created by Katekov Anton on 10/18/12.
//
//

#ifndef __Snake__RenderSystem__
#define __Snake__RenderSystem__

#include "GlobalConstants.h"
#include <iostream>

class Display;

class RenderSystem {
    Display             *_deviceDisplay;
    
public:
    
    RenderSystem();
    
    Display * GetDisplay();
    
    void InitOpenGL();
    
    void EndFrame();
    
};

#endif /* defined(__Snake__RenderSystem__) */
