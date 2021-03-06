//
//  SSnake.cpp
//  Snake
//
//  Created by  Developer on 08.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#include "SSnake.h"
#include "SSnakeData.h"
#include "SGameField.h"
#include "SSnakeDelegate.h"

const int startLength = 4;

SSnake::SSnake(SGameField *gameField, CCNode *node)
:_node(node), _gameField_w(gameField), _delegate_w(NULL)
{
    _data = new SSnakeData(startLength, ccp(10, 10), SnakeDirection_Up, gameField);
    _sprites = CCArray::create();
    _sprites->retain();
    UpdateView();
}

SSnake::~SSnake()
{
    Hide();
}

void SSnake::Hide()
{
    if (!_sprites) 
        return;
    
    for (int i = 0; i < _sprites->count(); i++) {
        CCSprite *spr = reinterpret_cast<CCSprite*>(_sprites->objectAtIndex(i));
        spr->removeFromParentAndCleanup(true);
    }
    _sprites->release();
    _sprites = NULL;
}

bool SSnake::Update(const CCPoint &targetCell)
{
    if (_data->CanMakeAdvance())
    {
        CCPoint newxtCell = _data->NextCell();
        bool increase = newxtCell.equals(targetCell);
        _data->MakeAdvance(increase);
        if (increase && _delegate_w)
            _delegate_w->SnakeDidIncreaseLength();
        
        return true;
    }
    else
        return false;
}

void SSnake::UpdateView()
{
    for (int i = 0; i < _sprites->count(); i++)
    {
        CCSprite* spr = reinterpret_cast<CCSprite*>(_sprites->objectAtIndex(i));
        spr->removeFromParentAndCleanup(true);
    }
    
    const vector<CCPoint> cells = _data->GetCells();
    for (int i = 0; i < cells.size(); i++)
    {
        CCSprite* spr = CCSprite::create("snake.png");
        spr->setAnchorPoint(ccp(0, 0));
        _node->addChild(spr);
        _sprites->addObject(spr);
        spr->setPosition(_gameField_w->ScreenCoordinatesForCell(cells[i]));
    }

}

void SSnake::ProcessInputCommand(int command)
{
    SnakeDirection direction = SnakeDirection_Up;
    if (command == 0)
        direction = SnakeDirection_Up;
    if (command == 1)
        direction = SnakeDirection_Right;
    if (command == 2)
        direction = SnakeDirection_Down;
    if (command == 3)
        direction = SnakeDirection_Left;
    
    
    if (_data->CanChangeDirection(direction)) 
        _data->ChangeDirection(direction);
    
}

