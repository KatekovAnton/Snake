//
//  SGameSession.h
//  Snake
//
//  Created by  Developer on 08.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#ifndef __Snake__SGameSession__
#define __Snake__SGameSession__

#include <iostream>
#include "miniPrefix.h"
#include "SSnakeDelegate.h"

class SGameField;
class SSnake;
class SSnakeTarget;
class SGameSessionDelegate;

class SGameSession : public CCObject, public SSnakeDelegate{
    
    SGameField  *_gameField;
    SSnake      *_snake;
    
    CCNode      *_baseNode;
    CCNode      *_snakeNode;
    
    SSnakeTarget *_target;
    
    bool _started;
    
    void StartTimer();
    void StopTimer();
    void OnTimer(float delta);
    
    int     _score;
    float   _deltaTime;
    
public:
    
    SGameSessionDelegate *_delegate_w;
    
    SGameSession();
    ~SGameSession();
    
    void Start();
    void RemoveTarget();
    void GenerateNewTarget();
    
    void ProcessAction(int actionCode);
    void Update();
    
#pragma mark - SSnakeDelegate

    virtual void SnakeDidIncreaseLength();
};

#endif /* defined(__Snake__SGameSession__) */
