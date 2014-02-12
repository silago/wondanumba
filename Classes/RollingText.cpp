#include "RollingText.h"
#include <stdio.h>
#include <stdlib.h> 
USING_NS_CC;


RollingText::RollingText()
{
    this->num = NULL;
}


void RollingText::setNumbers(const char* num = NULL)
{   

    CCObject* n = NULL; 
    CCARRAY_FOREACH(this->getChildren(), n)
    {   float time = rand() % 1;
       // ((cocos2d::CCNode*)n)->runAction(CCScaleTo::create(time,2));
        ((cocos2d::CCNode*)n)->runAction(CCFadeOut::create(time));
        ((cocos2d::CCNode*)n)->setTag(10);
    }
    this->removeChildByTag(10);
    
    int numberOfElements = 4;
    
    this->numberArray = CCArray::create();
    char f;
    for(int i=0; i<=(numberOfElements-1); i++){
                int r = rand() % 9;
                sprintf(&f,"%d",r);
                CCLog(&f);
                if (this->count==0){
                    f = (char)this->num[i];
                }
                CCLabelTTF* ttf1 = CCLabelTTF::create(&f, "Helvetica", 32, CCSizeMake(245, 32), kCCTextAlignmentCenter);
            this->numberArray->insertObject(ttf1,i);
            this->addChild(ttf1,101,i);
            ttf1->setPosition(ccp(i*20,0));
    }

    this->count--;
}


void RollingText::deleteUnused(){
this->removeChildByTag(10);
}

void RollingText::startRolling(const char* num)
    {
    this->count = 16;
    this->schedule(schedule_selector(RollingText::setNumbers),0.1,16,0);
    this->schedule(schedule_selector(RollingText::deleteUnused),0.5,6,1);
    this->num = (char*)num;
}
