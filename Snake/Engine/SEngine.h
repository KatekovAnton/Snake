//
//  MAXEngine.h
//  MAX
//
//  Created by Anton Katekov on 25.12.12.
//  Copyright (c) 2012 AntonKatekov. All rights reserved.
//

#ifndef __MAX__MAXEngine__
#define __MAX__MAXEngine__

#include <iostream>
#include "miniPrefix.h"

using namespace cocos2d;
using namespace std;

class RenderSystem;

class SEngineDelegate {
public:
    virtual void onFrame() = 0;
};

class SEngine {
    
    
    RenderSystem        *_renderSystem;
    float displayw,displayh;
    
    double                _elapsedTime;
    double                _fullTime;
    
    
public:
    
    CCDirector              *_director;
    
    SEngine();
    ~SEngine();
    
    void Init();
    void EngineMain();
    
    void RunLoop(double delta);
    
    double ElapsedTime() const {return _elapsedTime;};
    double FullTime() const {return _fullTime;};
    
    void Update();
    void Draw();
    void DrawInterface();
    void EndFrame();

};


extern SEngine *  engine;

#endif /* defined(__MAX__MAXEngine__) */
