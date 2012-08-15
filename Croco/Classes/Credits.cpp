#include "Credits.h"

Credits::Credits()
{
	CCMenuItemFont* itm_back = CCMenuItemFont::itemFromString("Back to Home", this, menu_selector(Credits::itm_backCallback));
	CCMenu* menu = CCMenu::menuWithItem(itm_back);
	addChild(menu);
	menu->setPosition(CCPointMake(700,100));
}
void Credits::itm_backCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
}