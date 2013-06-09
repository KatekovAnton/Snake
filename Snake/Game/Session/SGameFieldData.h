//
//  SGameFieldData.h
//  Snake
//
//  Created by  Developer on 09.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#ifndef __Snake__SGameFieldData__
#define __Snake__SGameFieldData__

#include <iostream>

class SGameFieldData {
    
    int _w;
    int _h;
    
public:
    
    int GetWidth() const {return _w;}
    int GetHeight() const {return _h;}
    
    SGameFieldData(const int x, const int y);
    ~SGameFieldData();
    
    bool IsCellValid(const int x, const int y) const;

};

#endif /* defined(__Snake__SGameFieldData__) */
