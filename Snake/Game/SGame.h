//
//  SGame.h
//  Snake
//
//  Created by  Developer on 07.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#ifndef __Snake__SGame__
#define __Snake__SGame__

#include <iostream>
#include "DisplayInputDelegate.h"
#include "SGameSessionDelegate.h"

typedef enum {
    SGameState_Menu,
    SGameState_Game,
    SGameState_Pause
} SGameState;

class SGameSession;

class SGame : public DisplayInputDelegate, public SGameSessionDelegate {
    
public:
    
    SGameSession *_currentSession;
    
    SGame();
    ~SGame();
    
    void Init();

    void StartNewSession();
    
#pragma mark - DisplayInputDelegate
    
    virtual bool CanStartScreenInput(float x, float y);
    virtual void ProcessAction(int actionCode);
    
#pragma mark - SGameSessionDelegate 

    virtual void SessionDidFinishFail(int score);
    virtual void SessionDidFinishSuccess(int score);
    
};

extern SGame *  game;

#endif /* defined(__Snake__SGame__) */