//
//  SGameField.cpp
//  Snake
//
//  Created by  Developer on 08.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#include "SGameField.h"
#include "SGameFieldData.h"

const float cellSize = 12;

SGameField::SGameField(const int x, const int y, CCNode *node)
:_node(node), _sprites(NULL)
{
    _data = new SGameFieldData(x, y);
    ShowGameField();
}

void SGameField::ShowGameField()
{
    HideGameField();
    _sprites = CCArray::create();
    _sprites->retain();
    for (int i = 0; i < _data->GetHeight(); i++) {
        for (int j = 0; j < _data->GetWidth(); j++) {
            CCSprite *spr = CCSprite::create("snake.png");
            spr->setOpacity(67);
            spr->setAnchorPoint(ccp(0, 0));
            spr->setPosition(ScreenCoordinatesForCell(ccp(j, i)));
            _node->addChild(spr);
            _sprites->addObject(spr);
        }
    }
}

void SGameField::HideGameField()
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

SGameField::~SGameField()
{
    HideGameField();
    delete _data;
}

CCPoint SGameField::ScreenCoordinatesForCell(const CCPoint &cell)
{
    CCPoint center = ccp(0, 0);
    CCSize sz = CCDirector::sharedDirector()->getRunningScene()->getContentSize();
    center.x = sz.width / 2;
    center.y = sz.height / 2;
    
//    
//  ^y
//  |
//  | o~~~
//  |     x
//  O----->
//
    
    CCPoint fieldZero = ccp(center.x - _data->GetWidth() * cellSize / 2.0, center.y - _data->GetHeight() * cellSize / 2.0);
    
    CCPoint result = ccp(fieldZero.x + cell.x * cellSize, fieldZero.y + cell.y * cellSize);
    return result;
}

#pragma mark - SSnakeEnviromentInterface

bool SGameField::IsCellValid(const CCPoint &cell)
{
    return _data->IsCellValid(cell.x, cell.y);
}
