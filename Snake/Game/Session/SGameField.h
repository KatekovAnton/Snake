//
//  SGameField.h
//  Snake
//
//  Created by  Developer on 08.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#ifndef __Snake__SGameField__
#define __Snake__SGameField__

#include <iostream>
#include "SSnakeEnviromentInterface.h"
#include "miniPrefix.h"

class SGameFieldData;

class SGameField : public SSnakeEnviromentInterface {
    
    CCNode         *_node;
    SGameFieldData *_data;
    
    CCArray        *_sprites;
    
public:
    
    SGameFieldData *GetData() const {return _data;}
    
    SGameField(const int x, const int y, CCNode *node);
    ~SGameField();
    
    void ShowGameField();
    void HideGameField();
    
    CCPoint ScreenCoordinatesForCell(const CCPoint &cell);
    
#pragma mark - SSnakeEnviromentInterface
    
    virtual bool IsCellValid(const CCPoint &cell);
    
};

#endif /* defined(__Snake__SGameField__) */
