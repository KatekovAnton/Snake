//
//  SSnakeTarget.cpp
//  Snake
//
//  Created by  Developer on 12.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#include "SSnakeTarget.h"
#include "SGameField.h"

SSnakeTarget::SSnakeTarget(CCPoint position, CCNode *node, SGameField *gameField)
:_position(position), _node_w(node)
{
    _sprite = CCSprite::create("snakeTarget.png");
    _sprite->setAnchorPoint(ccp(0, 0));
    _sprite->setPosition(gameField->ScreenCoordinatesForCell(position));
    _node_w->addChild(_sprite);
}

SSnakeTarget::~SSnakeTarget()
{
    _sprite->removeFromParentAndCleanup(true);
}