//
//  SInterface.h
//  Snake
//
//  Created by  Developer on 08.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#ifndef __Snake__SInterface__
#define __Snake__SInterface__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

class SInterfaceDelegate;

class SInterface : public CCScene {
    
    CCNode      *_nodeStart;
    CCMenu      *_menuStart;
    CCMenuItem  *_buttonStart;
    
    CCNode      *_nodeGame;
    CCLabelTTF  *_labelScore;
    
    CCNode      *_nodeFinish;
    CCLabelTTF  *_labelText;
    CCLabelTTF  *_labelFinalScore;
    CCMenu      *_menuRestart;
    CCMenuItem  *_buttonRestart;
    
public:
    
    SInterfaceDelegate *_delegate_w;
    
    SInterface();
    ~SInterface();
    
    void UpdateGameScore(int newScore);
    
    void ToStartState();
    void ToGameState();
    void ToFinishState(int score);
    
#pragma mark - button actions
    void OnStartNewSession(CCObject* sender);
    
};

#endif /* defined(__Snake__SInterface__) */
