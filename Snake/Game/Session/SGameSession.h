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

class SGameField;
class SSnake;
class SGameSessionDelegate;

class SGameSession : public CCObject {
    
    SGameField  *_gameField;
    SSnake      *_snake;
    
    CCNode      *_baseNode;
    CCNode      *_snakeNode;
    
    bool _started;
    
    void StartTimer();
    void StopTimer();
    void OnTimer(float delta);
    
    int _score;
    
public:
    
    SGameSessionDelegate *_delegate_w;
    
    SGameSession();
    ~SGameSession();
    
    void Start();
    
    void ProcessAction(int actionCode);
    void Update();
};

#endif /* defined(__Snake__SGameSession__) */
