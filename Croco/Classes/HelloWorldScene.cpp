#include "HelloWorldScene.h"

#define TRANSITION_DURATION (1.2f)

using namespace cocos2d;

StartLayer::StartLayer(void)
{
	float x,y;

    CCSize size = CCDirector::sharedDirector()->getWinSize();
    x = size.width/2;
    y = size.height/2;

	CCLabelTTF* title = CCLabelTTF::labelWithString("Hello world", "Thonburi", 32 );
	title->setColor(ccWHITE);
	addChild(title,1);
	title->setPosition(CCPointMake(x,y));

}

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::node();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::node();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

        //////////////////////////////////////////////////////////////////////////
        // add your codes below...
        //////////////////////////////////////////////////////////////////////////

        // 1. Add a menu item with "X" image, which is clicked to quit the program.

        // Create a "close" menu item with close icon, it's an auto release object.
        CCMenuItemImage *pCloseItem = CCMenuItemImage::itemFromNormalImage(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
			menu_selector(HelloWorld::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

		 CCMenuItemImage *pStartItem = CCMenuItemImage::itemFromNormalImage(
            "Nextscene.png",
            "Nextscene.png",
            this,
            menu_selector(HelloWorld::menuStartCallback));
        CC_BREAK_IF(! pStartItem);

        // Place the menu item bottom-right conner.
        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

		pStartItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 80));

        // Create a menu with the "close" menu item, it's an auto release object.
		CCMenu* pMenu = CCMenu::menuWithItems(pCloseItem, pStartItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // Add the menu to HelloWorld layer as a child layer.
        this->addChild(pMenu, 1);

        // 2. Add a label shows "Hello World".

        // Create a label and initialize with string "Hello World".
        CCLabelTTF* pLabel = CCLabelTTF::labelWithString("Hello World", "Thonburi", 64);
        CC_BREAK_IF(! pLabel);

        // Get window size and place the label upper. 
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        pLabel->setPosition(ccp(size.width / 2, size.height - 20));

        // Add the label to HelloWorld layer as a child layer.
        this->addChild(pLabel, 1);

        // 3. Add add a splash screen, show the cocos2d splash image.
        CCSprite* pSprite = CCSprite::spriteWithFile("HelloWorld.png");
        CC_BREAK_IF(! pSprite);

        // Place the sprite on the center of the screen
        pSprite->setPosition(ccp(size.width/2, size.height/2));

        // Add the sprite to HelloWorld layer as a child layer.
        this->addChild(pSprite, 0);

        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::menuStartCallback(CCObject* pSender)
{
	CCScene* pScene = new CCScene();
		
	CCLayer* pLayer = new StartLayer();
	
	pScene->addChild(pLayer);
	
	CCScene* s = CCTransitionFade::transitionWithDuration((1.2f), pScene);

	pScene->release();
	pLayer->release();

	CCDirector::sharedDirector()->replaceScene(s);
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}
