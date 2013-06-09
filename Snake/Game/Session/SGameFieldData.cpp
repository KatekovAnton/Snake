//
//  SGameFieldData.cpp
//  Snake
//
//  Created by  Developer on 09.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#include "SGameFieldData.h"


SGameFieldData::SGameFieldData(const int w, const int h)
:_w(w), _h(h)
{}

SGameFieldData::~SGameFieldData()
{}

bool SGameFieldData::IsCellValid(const int x, const int y) const
{
    return x >=0 && x < _w && y >= 0 && y < _h;
}
