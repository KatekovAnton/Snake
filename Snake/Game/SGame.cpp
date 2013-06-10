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
#include "SInterface.h"

SGame globalGame;
SGame * game = &globalGame;

SGame::SGame()
{}

SGame::~SGame()
{}

void SGame::Init()
{
    Display::currentDisplay()->SetPinchDelegate(this);
 
    _gameInterface = new SInterface();
    _gameInterface->ToStartState();
    CCDirector::sharedDirector()->pushScene(_gameInterface);
    CCDirector::sharedDirector()->mainLoop();
    
}

void SGame::StartNewSession()
{
    if (_currentSession)
        delete _currentSession;
    _currentSession = new SGameSession();
    _currentSession->_delegate_w = this;
    _currentSession->Start();
}

void SGame::AbortCurrentSession()
{
    delete _currentSession;
    _currentSession = NULL;
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

void SGame::SessionScoreChanged(int score)
{
    _gameInterface->UpdateGameScore(score);
}

void SGame::SessionDidFinish(int score)
{
    AbortCurrentSession();
    _gameInterface->ToFinishState(score);
}

