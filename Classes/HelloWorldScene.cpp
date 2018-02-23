#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

HelloWorld::~HelloWorld()
{
    delete Ship;
    delete Ship2;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Ship = new Player(visibleSize.width / 2 + origin.x, visibleSize.height / 3 + origin.y, "playerShip.png");
    this->addChild(Ship->Sprite(), 0);

    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::OnKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(HelloWorld::OnKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    this->scheduleUpdate();

    return true;
}

void HelloWorld::OnKeyPressed(EventKeyboard::KeyCode key, Event* event)
{
    PressedKeys.insert(key);
    return;
}

void HelloWorld::update(float delta)
{
    if (PressedKeys.find(EventKeyboard::KeyCode::KEY_D) != PressedKeys.end()) {
        Vec2 pos = Ship->Sprite()->getPosition();
        pos.x += +120 * delta;
        Ship->Sprite()->setPosition(pos);
    }

    if (PressedKeys.find(EventKeyboard::KeyCode::KEY_A) != PressedKeys.end()) {
        Vec2 pos = Ship->Sprite()->getPosition();
        pos.x += -120 * delta;
        Ship->Sprite()->setPosition(pos);
    }

    if (PressedKeys.find(EventKeyboard::KeyCode::KEY_W) != PressedKeys.end()) {
        Vec2 pos = Ship->Sprite()->getPosition();
        pos.y += +120 * delta;
        Ship->Sprite()->setPosition(pos);
    }

    if (PressedKeys.find(EventKeyboard::KeyCode::KEY_S) != PressedKeys.end()) {
        Vec2 pos = Ship->Sprite()->getPosition();
        pos.y += -120 * delta;
        Ship->Sprite()->setPosition(pos);
    }
}

void HelloWorld::OnKeyReleased(EventKeyboard::KeyCode key, Event* event)
{
    if (PressedKeys.find(key) != PressedKeys.end())
        PressedKeys.erase(key);
    return;
}
