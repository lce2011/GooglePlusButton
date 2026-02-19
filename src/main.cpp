#include <Geode/modify/MenuLayer.hpp>
#include <Geode/utils/web.hpp>

using namespace geode::prelude;

class $modify(GPBtnLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        if (auto node = this->getChildByIDRecursive("bottom-menu")) {
            auto spr = CCSprite::createWithSpriteFrameName("GJ_gpBtn_001.png"); // Google+ Icon

            auto btn = CCMenuItemSpriteExtra::create(
                spr,
                this,
                menu_selector(GPBtnLayer::onClick));
            
            btn->setID("gp-btn"_spr);
            btn->m_baseScale = 1.000f;
            btn->setScale(btn->m_baseScale);
            
            node->addChild(btn);
            node->updateLayout();
        }

        return true;
    }

    void onClick(CCObject *) {
        FLAlertLayer::create(
            "Google+",
            "<cy>Google+</c> got <cr>deprecated</c> in 2019 and is <cr>no longer avaible!</c>",
            "OK"
        )->show();
        
        web::openLinkInBrowser("https://plus.google.com/+geometrydash");
    }
};