//
//  SInterface.cpp
//  Snake
//
//  Created by  Developer on 08.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#include "SInterface.h"
#include "SInterfaceDelegate.h"
#include "CocosHelper.h"
#include "StringUtils.h"

#define S_DEFAULT_FONT "HelveticaNeue-Bold"
#define S_COLOR_BLACK ccc3(0,0,0)
#define S_COLOR_WHITE ccc3(255,255,255)
#define S_DEFAULT_SIZE 20


SInterface::SInterface()
:_nodeStart(NULL),
_menuStart(NULL),
_buttonStart(NULL),
_nodeGame(NULL),
_labelScore(NULL),
_nodeFinish(NULL),
_labelText(NULL),
_labelFinalScore(NULL),
_buttonRestart(NULL),
_menuRestart(NULL),
_delegate_w(NULL)
{
    this->setPosition(ccp(0, 0));
    this->setAnchorPoint(ccp(0, 0));
    this->setContentSize(CCDirector::sharedDirector()->getVisibleSize());
    //start
    {
        _nodeStart = CCNode::create();
        _nodeStart->retain();
        _nodeStart->setContentSize(getContentSize());
        _nodeStart->retain();
        _nodeStart->setAnchorPoint(ccp(0, 0));
        _nodeStart->setPosition(ccp(0, 0));
    }
    
    {
        CCLabelTTF *buttonStartLabel = CCLabelTTF::create("START NEW GAME", S_DEFAULT_FONT, S_DEFAULT_SIZE);
        buttonStartLabel->setColor(S_COLOR_BLACK);
        CCMenuItemLabel* buttonStart = CCMenuItemLabel::create(buttonStartLabel, this, menu_selector(SInterface::OnStartNewSession));
        _buttonStart = buttonStart;
        _buttonStart->retain();
    }
    
    {
        _menuStart = CCMenu::create(_buttonStart, nullptr);
        _menuStart->setContentSize(getContentSize());
        _menuStart->setAnchorPoint(ccp(0, 0));
        _menuStart->setPosition(ccp(0, 0));
        _menuStart->retain();
        _nodeStart->addChild(_menuStart);
        CocosHelper::PlaceNodeToTheCenterOfParent(_buttonStart);
    }
    
    //game
    {
        _nodeGame = CCNode::create();
        _nodeGame->retain();
        _nodeGame->setContentSize(getContentSize());
        _nodeGame->retain();
        _nodeGame->setAnchorPoint(ccp(0, 0));
        _nodeGame->setPosition(ccp(0, 0));
    }
    
    {
        _labelScore = CCLabelTTF::create("", S_DEFAULT_FONT, S_DEFAULT_SIZE);
        _labelScore->setColor(S_COLOR_BLACK);
        _labelScore->retain();
        _labelScore->setAnchorPoint(ccp(0, 1));
        _labelScore->setPosition(ccp(5, getContentSize().height));
        _nodeGame->addChild(_labelScore);
    }
    
    
    //finish
    {
        _nodeFinish = CCNode::create();
        _nodeFinish->retain();
        _nodeFinish->setContentSize(getContentSize());
        _nodeFinish->retain();
        _nodeFinish->setAnchorPoint(ccp(0, 0));
        _nodeFinish->setPosition(ccp(0, 0));
    }
    
    {
        _labelText = CCLabelTTF::create("GAME OVER", S_DEFAULT_FONT, S_DEFAULT_SIZE);
        _labelText->setColor(S_COLOR_BLACK);
        _labelText->retain();
        _labelText->setAnchorPoint(ccp(0.5, 0));
        _labelText->setPosition(ccp(getContentSize().width/2, getContentSize().height/2 + 10));
        _nodeFinish->addChild(_labelText);
    }
    
    {
        _labelFinalScore = CCLabelTTF::create("0", S_DEFAULT_FONT, S_DEFAULT_SIZE);
        _labelFinalScore->setColor(S_COLOR_BLACK);
        _labelFinalScore->retain();
        _labelFinalScore->setAnchorPoint(ccp(0.5, 1));
        _labelFinalScore->setPosition(ccp(getContentSize().width/2, getContentSize().height/2 - 10));
        _nodeFinish->addChild(_labelFinalScore);
    }
    
    
    {
        CCLabelTTF *buttonRestartLabel = CCLabelTTF::create("START NEW GAME", S_DEFAULT_FONT, S_DEFAULT_SIZE);
        buttonRestartLabel->setColor(S_COLOR_BLACK);
        _buttonRestart = CCMenuItemLabel::create(buttonRestartLabel, this, menu_selector(SInterface::OnStartNewSession));
        _buttonRestart->retain();
    }
    
    {
        _menuRestart = CCMenu::create(_buttonRestart, nullptr);
        _menuRestart->setContentSize(getContentSize());
        _menuRestart->setAnchorPoint(ccp(0, 0));
        _menuRestart->setPosition(ccp(0, 0));
        _menuRestart->retain();
        _nodeFinish->addChild(_menuRestart);
        CocosHelper::PlaceNodeToTheCenterOfParent(_buttonRestart);
        CocosHelper::MoveNode(_buttonRestart, ccp(0, -70));
    }
    
    
}

SInterface::~SInterface()
{
    _nodeStart->release();
    _menuRestart->release();
    _buttonStart->release();
    _nodeGame->release();
    _labelScore->release();
    _nodeFinish->release();
    _labelText->release();
    _labelFinalScore->release();
    _menuRestart->release();
    _buttonRestart->release();
}

void SInterface::UpdateGameScore(int newScore)
{
    if (_labelScore)
        _labelScore->setString(intToString(newScore).c_str());
}

void SInterface::ToStartState()
{
    if (_nodeStart) {
        _nodeStart->removeFromParentAndCleanup(true);
        addChild(_nodeStart);
    }
    
    if (_nodeGame)
        _nodeGame->removeFromParentAndCleanup(true);
    
    if (_nodeFinish)
        _nodeFinish->removeFromParentAndCleanup(true);
}

void SInterface::ToGameState()
{
    if (_nodeStart) 
        _nodeStart->removeFromParentAndCleanup(true);
    
    if (_nodeGame) {
        _nodeGame->removeFromParentAndCleanup(true);
        addChild(_nodeGame);
    }
    
    if (_nodeFinish)
        _nodeFinish->removeFromParentAndCleanup(true);
}

void SInterface::ToFinishState(int score)
{
    if (_nodeStart)
        _nodeStart->removeFromParentAndCleanup(true);
    
    if (_nodeGame) 
        _nodeGame->removeFromParentAndCleanup(true);
    
    if (_nodeFinish) {
        _nodeFinish->removeFromParentAndCleanup(true);
        addChild(_nodeFinish);
    }
}

#pragma mark - button actions

void SInterface::OnStartNewSession(CCObject* sender)
{
    if (_delegate_w)
        _delegate_w->OnStartSession();
}
