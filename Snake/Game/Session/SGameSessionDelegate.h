//
//  SGameSessionDelegate.h
//  Snake
//
//  Created by  Developer on 10.06.13.
//  Copyright (c) 2013 HappyEnergy. All rights reserved.
//

#ifndef Snake_SGameSessionDelegate_h
#define Snake_SGameSessionDelegate_h

class SGameSessionDelegate {
    
public:
    
    virtual void SessionDidFinishFail(int score) = 0;
    virtual void SessionDidFinishSuccess(int score) = 0;
    
};

#endif
