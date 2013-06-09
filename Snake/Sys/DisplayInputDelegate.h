//
//  DisplayInputDelegate.h
//  Snake
//
//  Created by  Developer on 25.12.12.
//  Copyright (c) 2012 AntonKatekov. All rights reserved.
//

#ifndef __Snake__DisplayInputDelegate__
#define __Snake__DisplayInputDelegate__

#include <iostream>

class DisplayInputDelegate {
    
public:
    
    virtual bool CanStartScreenInput(float x, float y) = 0;
    virtual void ProcessAction(int actionCode) = 0;

};

#endif /* defined(__Snake__DisplayInputDelegate__) */
