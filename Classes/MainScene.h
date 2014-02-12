#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "RollingText.h"
#include <iostream>
#include <fstream>

#if (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
    #include <CCFileUtilsLinux.h>
#endif


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    #include <CCFileUtilsWin32.h>
#endif

class Main: public cocos2d::CCLayer
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(Main);
    void runNumbers();
    int touchCount;
    std::string numArray[10];
    void readFile();
    cocos2d::CCMenu* pMenu;
    void showMessage();
    void hideMessage();
};

#endif // __MAIN_SCENE_H__
