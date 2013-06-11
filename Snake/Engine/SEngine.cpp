//
//  SEngine.cpp
//  MAX
//
//  Created by Anton Katekov on 25.12.12.
//  Copyright (c) 2012 AntonKatekov. All rights reserved.
//

#include "SEngine.h"
#include <time.h>
#include <math.h>


#include "cocos2d.h"
#include "RenderSystem.h"
#include "Display.h"

using namespace cocos2d;

SEngine globalEngine;
SEngine *engine = &globalEngine;

SEngine::SEngine()
{
    _renderSystem = new RenderSystem();
}

SEngine::~SEngine()
{
    delete _renderSystem;
}

void SEngine::Init() {
    
    _renderSystem->InitOpenGL();
   
    GCCHECK_GL_ERROR_DEBUG(); 

        
    _director = CCDirector::sharedDirector();
    _director->setContentScaleFactor(_renderSystem->GetDisplay()->GetDisplayScale());
    _director->setOpenGLView((CCEGLView *)(_renderSystem->GetDisplay()));
      
    float scale = _renderSystem->GetDisplay()->GetDisplayScale();
    _renderSystem->GetDisplay()->setDesignResolutionSize(_renderSystem->GetDisplay()->GetDisplayWidth()/scale, _renderSystem->GetDisplay()->GetDisplayHeight()/scale, kResolutionNoBorder);
    
    if (scale == 1.0) 
        CCFileUtils::sharedFileUtils()->setResourceDirectory("simple");
    
    if (scale == 2.0) 
        CCFileUtils::sharedFileUtils()->setResourceDirectory("retina");
    
    
    _director->setDisplayStats(true);
}

void SEngine::RunLoop(double delta)
{
    
    displayw = Display::currentDisplay()->GetDisplayWidth()/Display::currentDisplay()->GetDisplayScale();
    displayh = Display::currentDisplay()->GetDisplayHeight()/Display::currentDisplay()->GetDisplayScale();
    
    _elapsedTime = delta;
    _fullTime += _elapsedTime;
    
    glClearColor(0.8, 0.8, 0.8, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    this->Update();
    this->Draw();
    this->EndFrame();
}

void SEngine::Update()
{
   
}

void SEngine::Draw()
{
    DrawInterface();
}

void SEngine::DrawInterface()
{
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    _director->mainLoop();
}

void SEngine::EndFrame()
{
    _renderSystem->EndFrame();
}

