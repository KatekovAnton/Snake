//
//  SInterface.cpp
//  Snake
//
//  Created by  Developer on 08.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#include "SInterface.h"


SInterface::SInterface()
:_nodeStart(NULL),
_startButton(NULL),
_nodeGame(NULL),
_labelScore(NULL),
_nodeFinish(NULL),
_labelText(NULL),
_labelFinalScore(NULL),
_restartButton(NULL),
_delegate_w(NULL)
{
    this->setPosition(ccp(0, 0));
    this->setAnchorPoint(ccp(0, 0));
    this->setContentSize(CCDirector::sharedDirector()->getVisibleSize());
}

SInterface::~SInterface()
{
    _nodeStart->release();
    _startButton->release();
    _nodeGame->release();
    _labelScore->release();
    _nodeFinish->release();
    _labelText->release();
    _labelFinalScore->release();
    _restartButton->release();
}

void SInterface::UpdateGameScore(int newScore)
{}

void SInterface::ToStartState()
{}

void SInterface::ToGameState()
{}

void SInterface::ToFinishState(int score)
{}

