//
//  TextureCache.h
//  Croco
//
//  Created by admin on 18.07.12.
//
//
#define ADDIMAGE(IMG) CCTextureCache::sharedTextureCache()->addImageAsync(IMG, this, callfuncO_selector(TextureCacheLayer::loadingCallBack));

//MainMenu 1
#define MainMenu_background                 "MainMenu/background.png"
//GroupCustomization 10
#define GroupCustomization_start            "GroupCustomization/start.png"
#define GroupCustomization_start_selected   "GroupCustomization/start_selected.png"
#define GroupCustomization_back             "GroupCustomization/back.png"
#define GroupCustomization_back_selected    "GroupCustomization/back_selected.png"
#define GroupCustomization_blue             "GroupCustomization/blue.png"
#define GroupCustomization_green            "GroupCustomization/green.png"
#define GroupCustomization_red              "GroupCustomization/red.png"
#define GroupCustomization_yellow           "GroupCustomization/yellow.png"
#define GroupCustomization_stripe           "GroupCustomization/stripe.png"
#define GroupCustomization_dot              "GroupCustomization/dot.png"
#define GroupCustomization_lead_choise_colors              "GroupCustomization/lead_choise_colors.png"
//Timer
#define Timer_itm_timer_norm                "Timer/itm_timer_norm.png"
#define Timer_itm_timer_norm_light          "Timer/itm_timer_norm_light.png"
#define Timer_itm_timer_run_norm            "Timer/itm_timer_run_norm.png"
#define Timer_itm_timer_run_sel             "Timer/itm_timer_run_sel.png"
#define Timer_itm_timer_sel                 "Timer/itm_timer_sel.png"
#define Timer_itm_timer_stop_norm           "Timer/itm_timer_stop_norm.png"
#define Timer_itm_timer_stop_sel            "Timer/itm_timer_stop_sel.png"
#define Timer_timer_digits_active           "Timer/timer_digits_active.png"
#define Timer_timer_digits_light            "Timer/timer_digits_light.png"
#define Timer_timer_digits_passive          "Timer/timer_digits_passive.png"
#define Timer_timer_forest                  "Timer/timer_forest.png"
//Desk
#define _desk                               "desk.png"
#define _c_big                              "c_big.png"
//GameMenu 10
#define GameMenu_gamemenu                   "GameMenu/gamemenu.png"
#define GameMenu_help                       "GameMenu/help.png"
#define GameMenu_menu_button_a              "GameMenu/menu_button_a.png"
#define GameMenu_menu_button                "GameMenu/menu_button.png"
#define GameMenu_menu_forward_a             "GameMenu/menu_forward_a.png"
#define GameMenu_menu_forward               "GameMenu/menu_forward.png"
#define GameMenu_menu_button                "GameMenu/menu_button.png"
#define GameMenu_menu_rewind_a              "GameMenu/menu_rewind_a.png"
#define GameMenu_menu_rewind                "GameMenu/menu_rewind.png"
#define GameMenu_sound                      "GameMenu/sound.png"
#define GameMenu_swipe                      "GameMenu/swipe.png"
//RightControl 11
#define RightControl_c3_hybrid              "RightControl/c3_hybrid.png"
#define RightControl_c3                     "RightControl/c3.png"
#define RightControl_c3bottom               "RightControl/c3bottom.png"
#define RightControl_c3div                  "RightControl/c3div.png"
#define RightControl_c4_hybrid              "RightControl/c4_hybrid.png"
#define RightControl_c4                     "RightControl/c4.png"
#define RightControl_c4div                  "RightControl/c4div.png"
#define RightControl_c4bottom               "RightControl/c4bottom.png"
#define RightControl_c5_hybrid              "RightControl/c5_hybrid.png"
#define RightControl_c5                     "RightControl/c5.png"
#define RightControl_c5bottom               "RightControl/c5bottom.png"
#define RightControl_c5div                  "RightControl/c5div.png"
#define RightControl_itm_no_norm            "RightControl/itm_no_norm.png"
#define RightControl_itm_other_norm         "RightControl/itm_other_norm.png"
#define RightControl_itm_yes_norm           "RightControl/itm_yes_norm.png"
#define RightControl_c_blank0               "RightControl/c_blank0.png"
#define RightControl_c_blank1               "RightControl/c_blank1.png"
#define RightControl_c_blank2               "RightControl/c_blank2.png"
#define RightControl_c_blank3               "RightControl/c_blank3.png"
//RewindAnimation 2
#define RewindAnimation_rewind2             "RewindAnimation/rewind2.png"
#define RewindAnimation_rewind              "RewindAnimation/rewind.png"
//Tokens 5
#define tokens_token_blue                   "tokens/token_blue.png"
#define tokens_token_green                  "tokens/token_green.png"
#define tokens_token_red                    "tokens/token_red.png"
#define tokens_token_yellow                 "tokens/token_yellow.png"
#define tokens_token_shadow                 "tokens/token_shadow.png"
//SubMenu 6
#define SubMenu_2groups                     "SubMenu/2groups.png"
#define SubMenu_3gamers                     "SubMenu/3gamers.png"
#define SubMenu_3groups                     "SubMenu/3groups.png"
#define SubMenu_4groups               	    "SubMenu/4groups.png"
#define SubMenu_hint_bottom                 "SubMenu/hint_bottom.png"
#define SubMenu_lead_choise_groups          "SubMenu/lead_choise_groups.png"
//SN_icons 3
#define SN_icons_facebook_icon              "SN_icons/facebook_icon_60.png"
#define SN_icons_twitter_icon               "SN_icons/twitter_icon_60.png"
#define SN_icons_vkontakte_icon             "SN_icons/vkontakte_icon_60.png"

#ifndef __Croco__TextureCache__
#define __Croco__TextureCache__

#include "CrocoBoardGame.h"

class TextureCacheLayer : public CCLayer
{
public:
	TextureCacheLayer();
	void loadMainMenu();
	void loadingCallBack(cocos2d::CCObject *obj);
    
private:
	cocos2d::CCLabelTTF *m_pLabelLoading;
	cocos2d::CCLabelTTF *m_pLabelPercent;
	int m_nNumberOfSprites;
	int m_nNumberOfLoadedSprites;
};

#endif /* defined(__Croco__TextureCache__) */
