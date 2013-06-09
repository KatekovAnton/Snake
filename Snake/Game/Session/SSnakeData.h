//
//  SSnakeData.h
//  Snake
//
//  Created by  Developer on 09.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#ifndef __Snake__SSnakeData__
#define __Snake__SSnakeData__

#include <iostream>
#include "miniPrefix.h"

class SSnakeEnviromentInterface;

class SSnakeData {
    
    SSnakeEnviromentInterface   *_enviroment_w;
    
    vector<CCPoint> _cells;
    vector<CCPoint> _trace;
    
    CCPoint         _position;
    SnakeDirection  _direction;
    
    int             _increaseLengthStep;
    
public:
    
    const vector<CCPoint> GetCells() const { return _cells; };
    
    SSnakeData(int startLenght, int increaseLenghtStep, const CCPoint &startPosition, const SnakeDirection startDirection, SSnakeEnviromentInterface   *enviroment);
    ~SSnakeData();
    
    void MakeAdvance();
    bool CanMakeAdvance();
    
    void IncreaseLenght();
    bool CanIncreaseLenght();
    
    void ChangeDirection(SnakeDirection newDirection);
    bool CanChangeDirection(SnakeDirection newDirection);
};

#endif /* defined(__Snake__SSnakeData__) */
