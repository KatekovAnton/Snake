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

class SGameSession {
    
    SGameField  *_gameField;
    SSnake      *_snake;
    
    CCNode      *_baseNode;
    CCNode      *_snakeNode;
    
public:
    
    SGameSessionDelegate *_delegate_w;
    
    SGameSession();
    ~SGameSession();
    
    void ProcessAction(int actionCode);
    void Update();
};

#endif /* defined(__Snake__SGameSession__) */
