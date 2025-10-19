#include <Geode/modify/MenuLayer.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/utils/ColorProvider.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        if (auto node = this->getChildByIDRecursive("profile-menu")) {
            auto spr = CCSprite::createWithSpriteFrameName("GJ_gpBtn_001.png"); // Google+ Icon

            auto btn = CCMenuItemSpriteExtra::create(
                spr,
                this,
                menu_selector(MyMenuLayer::onClick));

            node->addChild(btn);

            btn->m_baseScale = 1.000f;
            btn->setScale(btn->m_baseScale);
            btn->setPosition(82.500f, 25.000f);
        }

        return true;
    }

    void onClick(CCObject *) {
        FLAlertLayer::create(
            "Google+",
            "Google+ got deprecated in 2019 and is no longer avaible! (*bruh*)",
            "OK"
        )->show();

        web::openLinkInBrowser("https://plus.google.com/+geometrydash");
    }
};