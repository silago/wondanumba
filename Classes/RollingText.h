#ifndef __ROLLINGTEXT_H__
#define __ROLLINGTEXT_H__

#include "cocos2d.h"
#include <string>
using namespace std;

class RollingText: public cocos2d::CCNode
{
public:
    RollingText();
    void setNumbers(const char* num);
    void deleteUnused();
    void startRolling(const char * num);
    char* num;
    int count;
    //`virtual bool init();  
    
    //cocos2d::CCNode* text;
    //void menuCloseCallback(CCObject* phild(ttf1);ender);
    //CREATE_FUNC(Main);
    //void runNumbers();

    cocos2d::CCArray *numberArray;
};

#endif // __ROLLINGTEXT_H__
