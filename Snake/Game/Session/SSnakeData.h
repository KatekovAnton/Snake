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
    
    CCPoint         _position;
    SnakeDirection  _direction;
    
public:
    
    const vector<CCPoint> GetCells() const { return _cells; };
    
    SSnakeData(int startLenght, const CCPoint &startPosition, const SnakeDirection startDirection, SSnakeEnviromentInterface   *enviroment);
    ~SSnakeData();
    
    void MakeAdvance(bool increase);
    bool CanMakeAdvance();
    
    bool CellIsSnakeCell(const CCPoint &cell) const;
    CCPoint NextCell();
    
    void ChangeDirection(SnakeDirection newDirection);
    bool CanChangeDirection(SnakeDirection newDirection);
};

#endif /* defined(__Snake__SSnakeData__) */
