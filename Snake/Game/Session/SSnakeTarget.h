//
//  SSnakeTarget.h
//  Snake
//
//  Created by  Developer on 12.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#ifndef __Snake__SSnakeTarget__
#define __Snake__SSnakeTarget__

#include <iostream>
#include "miniPrefix.h"

class SGameField;

class SSnakeTarget {
    
    CCPoint _position;
    CCSprite    *_sprite;
    CCNode      *_node_w;
    
public:
    
    CCPoint GetPosition() const {return _position;}
    
    SSnakeTarget(CCPoint position, CCNode *node, SGameField* gameField);
    ~SSnakeTarget();

};

#endif /* defined(__Snake__SSnakeTarget__) */
