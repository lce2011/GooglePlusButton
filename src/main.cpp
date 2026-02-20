#include <Geode/modify/MenuLayer.hpp>
#include <Geode/loader/Mod.hpp>
#include <Geode/utils/web.hpp>

using namespace geode::prelude;

class $modify(GPBtnLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        auto gpSpr = CCSprite::createWithSpriteFrameName("GJ_gpBtn_001.png"); // Google+ Button
        auto gpgSpr = CCSprite::createWithSpriteFrameName("GJ_gpgBtn_001.png"); // Google+ Game Button
        auto gpSignInSpr = CCSprite::createWithSpriteFrameName("gplusSignIn_001.png"); // Google+ SignIn Button
        auto gpSignOutSpr = CCSprite::createWithSpriteFrameName("gplusSignOut_001.png"); // Google+ SignOut Button
        
        auto isGPGBtn = Mod::get()->getSettingValue<bool>("gpg-setting"); // Checks Google+ Games Button setting
        auto isGPSignOutBtn = Mod::get()->getSettingValue<bool>("gp-signOut-setting"); // Checks Google+ Sign Out Button setting
    

        // "bottom-menu" => Google+ | Google+ Games
        auto bottomMenu = this->getChildByIDRecursive("bottom-menu");
        
        if (isGPGBtn) {
            auto gpBtn = CCMenuItemSpriteExtra::create(
                gpgSpr,
                this,
                menu_selector(GPBtnLayer::onGPClick));
                
            gpBtn->setID("gp-btn"_spr);
            gpBtn->m_baseScale = 1.0f;
            gpBtn->setScale(gpBtn->m_baseScale);
            
            bottomMenu->addChild(gpBtn);
            bottomMenu->updateLayout();
        } else {
            auto gpBtn = CCMenuItemSpriteExtra::create(
                gpSpr,
                this,
                menu_selector(GPBtnLayer::onGPClick));
                    
            gpBtn->setID("gp-btn"_spr);
            gpBtn->m_baseScale = 1.0f;
            gpBtn->setScale(gpBtn->m_baseScale);
            
            bottomMenu->addChild(gpBtn);
            bottomMenu->updateLayout();
        }
        
        // "profile-menu" => Google+ SignIn | Google+ SignOut
        auto profileMenu = this->getChildByIDRecursive("profile-menu");
        
        if (isGPSignOutBtn) {
            auto gpSignBtn = CCMenuItemSpriteExtra::create(
                gpSignOutSpr,
                this,
                menu_selector(GPBtnLayer::onGPSignClick));
                    
            gpSignBtn->setID("gp-sign-btn"_spr);
            gpSignBtn->m_baseScale = 1.0f;
            gpSignBtn->setScale(gpSignBtn->m_baseScale);
            
            profileMenu->addChild(gpSignBtn);
            profileMenu->updateLayout();
        } else {
            auto gpSignBtn = CCMenuItemSpriteExtra::create(
                gpSignInSpr,
                this,
                menu_selector(GPBtnLayer::onGPSignClick));
                    
            gpSignBtn->setID("gp-sign-btn"_spr);
            gpSignBtn->m_baseScale = 1.0f;
            gpSignBtn->setScale(gpSignBtn->m_baseScale);
            
            profileMenu->addChild(gpSignBtn);
            profileMenu->updateLayout();
        }

        return true;
    }

    void onGPClick(CCObject*) {
        auto gpAlert = FLAlertLayer::create(
            "Google+",
            "<cy>Google+</c> got <cr>deprecated</c> in 2019 and is <cr>no longer avaible!</c>",
            "OK");
        
        gpAlert->m_scene = this;
        gpAlert->show();
        
        web::openLinkInBrowser("https://plus.google.com/+geometrydash");
    }
    
    void onGPSignClick(CCObject*) {
        auto isGPSignOutBtn = Mod::get()->getSettingValue<bool>("gp-signOut-setting");
        auto gpSignAlert = FLAlertLayer::create(
            "Google+ SignIn/SignOut",
            "<cy>Google+</c> got <cr>deprecated</c> in 2019 and is <cr>no longer avaible!</c>",
            "OK");
            
        gpSignAlert->m_scene = this;
        gpSignAlert->show();
        
        if (isGPSignOutBtn) {
            web::openLinkInBrowser("https://accounts.google.com/Logout");
        } else {
            web::openLinkInBrowser("https://accounts.google.com/Login");
        }
    }
};