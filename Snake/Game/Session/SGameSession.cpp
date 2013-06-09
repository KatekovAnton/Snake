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

#include "miniPrefix.h"

SGameSession::SGameSession()
:_delegate_w(NULL)
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
{}

void SGameSession::ProcessAction(int actionCode)
{
    _snake->ProcessInputCommand(actionCode);
}

void SGameSession::Update()
{
}


