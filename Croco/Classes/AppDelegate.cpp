#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

#include "CrocoBoardGame.h"
#include "TextureCache.h"

using namespace cocos2d;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();
}

bool AppDelegate::initInstance()
{
    bool bRet = false;
    do 
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
        // Initialize OpenGLView instance, that release by CCDirector when application terminate.
        // The HelloWorld is designed as HVGA.
        CCEGLView * pMainWnd = new CCEGLView();
        CC_BREAK_IF(! pMainWnd
            || ! pMainWnd->Create(TEXT("Crocodile. Board game"), 768, 1024));
#endif  // CC_PLATFORM_WIN32

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

        // OpenGLView initialized in testsAppDelegate.mm on ios platform, nothing need to do here.

#endif  // CC_PLATFORM_IOS

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

        // Android doesn't need to do anything.

#endif  // CC_PLATFORM_ANDROID

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WOPHONE)
        // Initialize OpenGLView instance, that release by CCDirector when application terminate.
        // The HelloWorld is designed as HVGA.
        // Use GetScreenWidth() and GetScreenHeight() get screen width and height.
        CCEGLView * pMainWnd = new CCEGLView(this);
        CC_BREAK_IF(! pMainWnd
            || ! pMainWnd->Create(320, 480));

#if !defined(_TRANZDA_VM_)
        // set the resource zip file
        // on wophone emulator, we copy resources files to Work7/TG3/APP/ folder instead of zip file
        CCFileUtils::setResource("game1.zip");
#endif

#endif  // CC_PLATFORM_WOPHONE

        bRet = true;
    } while (0);
    
    return bRet;
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(&CCEGLView::sharedOpenGLView());

#ifndef __APPLE__
    // sets landscape mode
    pDirector->setDeviceOrientation(kCCDeviceOrientationLandscapeLeft);
#endif
    
    // turn on display FPS
    pDirector->setDisplayFPS(true);
    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

	//create config
	
	// create a scene. it's an autorelease object
	/*
    CCScene* pS_MainMenuScene = CCScene::node();
	CCLayer* pL_MainMenu = new MainMenuLayer(0);
	pS_MainMenuScene->addChild(pL_MainMenu,0);
	pL_MainMenu->release();
    */
    CCScene* pS_TextureCacheScene = CCScene::node();
	CCLayer* pL_TextureCacheLayer = new TextureCacheLayer();
	pS_TextureCacheScene->addChild(pL_TextureCacheLayer,0);
	pL_TextureCacheLayer->release();
    pDirector->runWithScene(pS_TextureCacheScene);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();

    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();

    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}