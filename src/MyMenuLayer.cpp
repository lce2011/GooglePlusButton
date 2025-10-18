#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        auto label = CCLabelBMFont::create("2.2", "goldFont.fnt");
        label->setPosition(520.0f, 300.0f);
        label->setScale(1.500f);
        label->setRotation(20.0f);
        this->addChild(label);

        if (auto node = this->getChildByIDRecursive("social-media-menu")) {
            auto spr = CCSprite::createWithSpriteFrameName("GJ_gpBtn_001.png"); // Google+ Icon

            auto btn = CCMenuItemSpriteExtra::create(
                spr,
                this,
                menu_selector(MyMenuLayer::onClick));

            node->addChild(btn);

            btn->m_baseScale = 0.700f;
            btn->setScale(btn->m_baseScale);
            btn->setPosition(85, 80);
        }

        return true;
    }

    void onClick(CCObject *) {
        FLAlertLayer::create(
            "Google+",
            "Google+ was brutally murdered and is no longer available!",
            "OK"
        )->show();
    }
};