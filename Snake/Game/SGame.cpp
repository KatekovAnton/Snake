//
//  SGame.cpp
//  Snake
//
//  Created by  Developer on 07.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#include "SGame.h"
#include "Display.h"
#include "cocos2d.h"
#include "SGameSession.h"

SGame globalGame;
SGame * game = &globalGame;

SGame::SGame()
{}

SGame::~SGame()
{}

void SGame::Init()
{
    Display::currentDisplay()->SetPinchDelegate(this);
    CCScene* scene = CCScene::create();
    scene->setPosition(ccp(0, 0));
    scene->setAnchorPoint(ccp(0, 0));
    scene->setContentSize(Display::currentDisplay()->getFrameSize());
    CCDirector::sharedDirector()->pushScene(scene);
    CCDirector::sharedDirector()->mainLoop();
    StartNewSession();
}

void SGame::StartNewSession()
{
    if (_currentSession)
        delete _currentSession;
    _currentSession = new SGameSession();
    _currentSession->_delegate_w = this;
}

#pragma mark - DisplayInputDelegate

bool SGame::CanStartScreenInput(float x, float y)
{
    return true;
}

void SGame::ProcessAction(int actionCode)
{
    _currentSession->ProcessAction(actionCode);
}

#pragma mark - SGameSessionDelegate

void SGame::SessionDidFinishFail(int score)
{}

void SGame::SessionDidFinishSuccess(int score)
{}

