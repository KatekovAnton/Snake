//
//  SSnakeData.cpp
//  Snake
//
//  Created by  Developer on 09.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#include "SSnakeData.h"
#include "SSnakeEnviromentInterface.h"

SSnakeData::SSnakeData(int startLenght, const CCPoint &startPosition, const SnakeDirection startDirection, SSnakeEnviromentInterface   *enviroment)
:_enviroment_w(enviroment), _position(startPosition), _direction(startDirection)
{
    CCPoint point = startPosition;
    float dx = 0;
    float dy = 0;
    switch (startDirection) {
        case SnakeDirection_Up:
            dx = 0; dy = -1;
            break;
        case SnakeDirection_Down:
            dx = 0; dy = 1;
            break;
        case SnakeDirection_Left:
            dx = 1; dy = 0;
            break;
        case SnakeDirection_Right:
            dx = -1; dy = 0;
            break;
            
        default:
            break;
    }
    for (int i = 0; i < startLenght; i++) {
        _cells.push_back(point);
        point.x += dx;
        point.y += dy;
    }
}

SSnakeData::~SSnakeData()
{}

void SSnakeData::MakeAdvance()
{
    if (!CanMakeAdvance()) 
        return;
    
    
    _cells.erase(_cells.end() - 1);
    CCPoint newPoint = _cells[0];
    switch (_direction) {
        case SnakeDirection_Up:
            newPoint.y += 1;
            break;
        case SnakeDirection_Down:
            newPoint.y -= 1;
            break;
        case SnakeDirection_Right:
            newPoint.x += 1;
            break;
        case SnakeDirection_Left:
            newPoint.x -= 1;
            break;
            
        default:
            break;
    }
    
    _cells.insert(_cells.begin(), newPoint);
    
}

bool SSnakeData::CanMakeAdvance()
{
    CCPoint newPoint = _cells[0];
    switch (_direction) {
        case SnakeDirection_Up:
            newPoint.y += 1;
            break;
        case SnakeDirection_Down:
            newPoint.y -= 1;
            break;
        case SnakeDirection_Right:
            newPoint.x += 1;
            break;
        case SnakeDirection_Left:
            newPoint.x -= 1;
            break;
            
        default:
            break;
    }
    if (!_enviroment_w->IsCellValid(newPoint)) {
        return false;
    }
    for (int i = 0; i < _cells.size(); i++) {
        CCPoint p = _cells[i];
        if ((int)p.x == (int)newPoint.x && (int)p.y == (int)newPoint.y) 
            return false;
    }
    return true;
    
}

void SSnakeData::IncreaseLenght()
{
    
}

bool SSnakeData::CanIncreaseLenght()
{
    return true;
}

void SSnakeData::ChangeDirection(SnakeDirection newDirection)
{
    if (!CanChangeDirection(newDirection))
        return;
    
    _direction = newDirection;
    
}

bool SSnakeData::CanChangeDirection(SnakeDirection newDirection)
{
    switch (_direction)
    {
            
        case SnakeDirection_Up:
        case SnakeDirection_Down:
            return newDirection == SnakeDirection_Left||newDirection == SnakeDirection_Right;
            break;
        case SnakeDirection_Right:
        case SnakeDirection_Left:
            return newDirection == SnakeDirection_Up||newDirection == SnakeDirection_Down;
            break;
            
        default:
            break;
    }
    return false;
}
