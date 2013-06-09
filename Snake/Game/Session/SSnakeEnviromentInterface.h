//
//  SSnakeEnviromentInterface.h
//  Snake
//
//  Created by  Developer on 10.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#ifndef Snake_SSnakeEnviromentInterface_h
#define Snake_SSnakeEnviromentInterface_h

#include "miniPrefix.h"

class SSnakeEnviromentInterface {
    
public:
    
    virtual bool IsCellValid(const CCPoint &cell) = 0;
    
};

#endif
