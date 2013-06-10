//
//  SGameSession.cpp
//  Snake
//
//  Created by  Developer on 08.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#include "SGameSession.h"
#include "SGameField.h"
#include "SSnake.h"
#include "SGameSessionDelegate.h"

#include "miniPrefix.h"

SGameSession::SGameSession()
:_delegate_w(NULL), _started(false), _score(0)
{
    _baseNode = CCNode::create();
    _baseNode->setContentSize(CCDirector::sharedDirector()->getRunningScene()->getContentSize());
    CCDirector::sharedDirector()->getRunningScene()->addChild(_baseNode);
    
    _snakeNode = CCNode::create();
    _snakeNode->setContentSize(CCDirector::sharedDirector()->getRunningScene()->getContentSize());
    CCDirector::sharedDirector()->getRunningScene()->addChild(_snakeNode);

    
    _gameField = new SGameField(20, 30, _baseNode);
    _snake = new SSnake(_gameField, _snakeNode);

}

SGameSession::~SGameSession()
{
    StopTimer();
    delete _gameField;
    delete _snake;
}

void SGameSession::StartTimer()
{
    StopTimer();
    CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(SGameSession::OnTimer), this, 0.5, false);
    _started = true;
}

void SGameSession::StopTimer()
{
    CCDirector::sharedDirector()->getScheduler()->unscheduleAllSelectorsForTarget(this);
    _started = false;
}

void SGameSession::OnTimer(float delta)
{
    Update();
}

void SGameSession::Start()
{
    StartTimer();
    _delegate_w->SessionScoreChanged(_score);
}

void SGameSession::ProcessAction(int actionCode)
{
    _snake->ProcessInputCommand(actionCode);
}

void SGameSession::Update()
{
    if (_snake->Update())
        _snake->UpdateView();
    else
        _delegate_w->SessionDidFinish(_score);
}


