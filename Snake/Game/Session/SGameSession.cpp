//
//  SGameSession.cpp
//  Snake
//
//  Created by  Developer on 08.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#include "SGameSession.h"
#include "SGameSessionDelegate.h"
#include "SGameField.h"
#include "SGameFieldData.h"
#include "SSnake.h"
#include "SSnakeData.h"
#include "SSnakeTarget.h"

#include "MyRandom.h"
#include "miniPrefix.h"

SGameSession::SGameSession()
:_delegate_w(NULL), _started(false), _score(0), _target(NULL), _deltaTime(0.5)
{
    _baseNode = CCNode::create();
    _baseNode->setContentSize(CCDirector::sharedDirector()->getRunningScene()->getContentSize());
    CCDirector::sharedDirector()->getRunningScene()->addChild(_baseNode);
    
    _snakeNode = CCNode::create();
    _snakeNode->setContentSize(CCDirector::sharedDirector()->getRunningScene()->getContentSize());
    CCDirector::sharedDirector()->getRunningScene()->addChild(_snakeNode);

    
    _gameField = new SGameField(32, 44, _baseNode);
    _snake = new SSnake(_gameField, _snakeNode);
    _snake->_delegate_w = this;
    GenerateNewTarget();
}

SGameSession::~SGameSession()
{
    StopTimer();
    RemoveTarget();
    delete _gameField;
    delete _snake;
}

void SGameSession::StartTimer()
{
    StopTimer();
    CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(SGameSession::OnTimer), this, _deltaTime, false);
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

void SGameSession::RemoveTarget()
{
    if (_target)
    {
        delete _target;
        _target = NULL;
    }
}

void SGameSession::GenerateNewTarget()
{
    RemoveTarget();
    
    int cellIndex = nextIntMax(_gameField->GetData()->GetWidth() * _gameField->GetData()->GetHeight());
    int startCellIndex = cellIndex;
    CCPoint cell = ccp(cellIndex % _gameField->GetData()->GetWidth(), cellIndex / _gameField->GetData()->GetWidth());
    bool notValaid = _snake->GetData()->CellIsSnakeCell(cell);
    
    if (notValaid)
    {
        int delta = (nextInt() % 2 == 0) ? -1 : 1;
        int times = 0;
        while (notValaid)
        {
            if (times == cellIndex == _gameField->GetData()->GetWidth() * _gameField->GetData()->GetHeight())
            {
                _delegate_w->SessionDidFinish(_score);
                return;
            }
            cellIndex += delta;
            cell = ccp(cellIndex % _gameField->GetData()->GetWidth(), cellIndex / _gameField->GetData()->GetWidth());
            notValaid = _snake->GetData()->CellIsSnakeCell(cell);
            
            if (notValaid)
            {
                if (cellIndex == 0)
                {
                    delta = 1;
                    cellIndex = startCellIndex;
                }
                else if (cellIndex == _gameField->GetData()->GetWidth() * _gameField->GetData()->GetHeight() - 1)
                {
                    delta = -1;
                    cellIndex = startCellIndex;
                }
            }
            
            times ++;
        }
    }
    
    if (!notValaid)
        _target = new SSnakeTarget(cell, _snakeNode, _gameField);
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
    if (_snake->Update(_target->GetPosition()))
        _snake->UpdateView();
    else
	{
		StopTimer();
        _delegate_w->SessionDidFinish(_score);
	}
}

#pragma mark - SSnakeDelegate

void SGameSession::SnakeDidIncreaseLength()
{
    GenerateNewTarget();
    _score += 1;
    _delegate_w->SessionScoreChanged(_score);
    _deltaTime *= 0.9;
    if (_deltaTime < 0.1)
        _deltaTime = 0.1;
    
    StopTimer();
    StartTimer();
}

