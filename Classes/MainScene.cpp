#include "MainScene.h"
#include "RollingText.h"
USING_NS_CC;

CCScene* Main::scene()
{
    CCScene *scene = CCScene::create();
    Main *layer = Main::create();
    scene->addChild(layer,1);

    return scene;

}

void Main::readFile()
{   
    std::string path =  CCFileUtils::sharedFileUtils()->getWritablePath();
    path=path+"data";
    const char* f = path.c_str();
    CCLog(f);
    CCLOG("/");
    std::string value;
    ifstream file(f); 
    for(int i = 0; i<10; ++i)
    {
        file >> this->numArray[i];
        std::getline(file, value);
    }
    CCLog(this->numArray[1].c_str());

}
void Main::showMessage()
{
   CCSprite* pSprite = CCSprite::create("fin.png");
   pSprite->setPosition(ccp(375,300));
   this->addChild(pSprite,201,1001);
   
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "close.png",
                                        "close.png",
                                        this,
                                     menu_selector(Main::hideMessage));
    pCloseItem->setPosition(ccp(220,160));
    this->pMenu = CCMenu::create(pCloseItem, NULL);

    this->addChild(this->pMenu, 202,1001);

}

void Main::hideMessage()
{
    CCLog("hide");
    this->removeChildByTag(1001);
    this->removeChildByTag(1001);
    this->removeChildByTag(1001);
}

// on "init" you need to initialize your instance
bool Main::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    this->touchCount = 0; 
    this->readFile(); 
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "touchme.png",
                                        "touchme_touched.png",
                                        this,
                                        menu_selector(Main::runNumbers));
    
	pCloseItem->setPosition(ccp(400,100));

    this->pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(this->pMenu, 1);
    CCSprite* pSprite = CCSprite::create("bg.jpg");
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);
   
    
    
    
    
    
    
    
    
    
    
    return true;
}


void Main::runNumbers()
{             float left = 0;
    float bottom = 0;
    if (this->touchCount>=5){
       left = (150+(100*this->touchCount))-500;
       bottom=250;
    }
    else{
       bottom = 300;
       left = (150+(100*this->touchCount));
    }


    RollingText *  runningnumbers = new RollingText();
    this->addChild(runningnumbers,101); 
    runningnumbers->setPosition(ccp(left,bottom)); 
    runningnumbers->startRolling(this->numArray[this->touchCount].c_str());
    this->touchCount++;
    if (this->touchCount>=10)
    {
        this->pMenu->setVisible(false);
        this->scheduleOnce(schedule_selector(Main::showMessage),5);

    }
}




void Main::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
