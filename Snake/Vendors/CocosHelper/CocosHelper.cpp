//
//  CocosHelper.cpp
//  MAX
//
//  Created by  Developer on 24.02.13.
//  Copyright (c) 2013 AntonKatekov. All rights reserved.
//

#include "CocosHelper.h"
#include "miniPrefix.h"
#include "Display.h"
#include "cocos2d.h"

using namespace cocos2d;

void CocosHelper::ProceedCCNode(CCNode* node)
{
    node->setScale(Display::currentDisplay()->GetDisplayScale());
}

void CocosHelper::ProceedCCNodeBack(CCNode* node)
{
    node->setScale(1.0/Display::currentDisplay()->GetDisplayScale());
}

void CocosHelper::SetPosition(CCNode* node, const CCPoint& point)
{
    node->setPosition(ccp(point.x*node->getScale(), point.y*node->getScale()));
}

void CocosHelper::SetContentSize(CCNode* node, const CCSize& size)
{
    node->setContentSize(CCSize(size.width*node->getScale(), size.height*node->getScale()));
}

CCSize CocosHelper::GetContentSize(CCNode* node)
{
    return CCSize(node->getContentSize().width*node->getScale(), node->getContentSize().height*node->getScale());
}

void CocosHelper::MoveNode(CCNode* node, const CCPoint &vector)
{
    if (!node)
        return;
    
    CCPoint pos = node->getPosition();
    pos.x += vector.x;
    pos.y += vector.y;
    node->setPosition(pos);
}

void CocosHelper::PlaceNodeToTheCenterOfParent(CCNode* node)
{
    if (!node->getParent()) 
        return;
    
    CCSize sz = node->getParent()->getContentSize();
    node->setAnchorPoint(ccp(0.5, 0.5));
    node->setPosition(ccp(sz.width/2, sz.height/2));
}
