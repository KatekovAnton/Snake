//
//  SSnake.h
//  Snake
//
//  Created by  Developer on 08.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#ifndef __Snake__SSnake__
#define __Snake__SSnake__

#include <iostream>
#include "miniPrefix.h"

class SSnakeData;
class SSnakeEnviromentInterface;
class SGameField;
class SSnakeDelegate;

class SSnake {
    
    CCNode                      *_node;
    SSnakeData                  *_data;
    SGameField                  *_gameField_w;
    
    CCArray                     *_sprites;
    
public:
    
    SSnakeDelegate *_delegate_w;
    SSnakeData *GetData() const {return _data;};
    
    
    SSnake(SGameField* gameField, CCNode *node);
    ~SSnake();
    
    void Hide();
    
    bool Update(const CCPoint &targetCell);
    void UpdateView();
    void ProcessInputCommand(int command);
};

#endif /* defined(__Snake__SSnake__) */
