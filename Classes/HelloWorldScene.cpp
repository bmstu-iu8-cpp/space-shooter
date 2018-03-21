#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
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

    Ship.reset(
        new Player(
            visibleSize.width / 2 + origin.x,
            visibleSize.height / 3 + origin.y,
            "playerShip.png"
        )
    );

    for (int i = 0; i < 4; ++i)
    {
        Enemies.push_back(
            std::make_unique<EnemyShip>(
                visibleSize.width / 2 + origin.x + ((rand() - 150) % 300),
                visibleSize.height + origin.y,
                10,
                100 + (rand() % 150),
                "enemyShip.png"
            )
        );

        this->addChild(Enemies.back()->Sprite(), 0);
    }

    this->addChild(Ship->Sprite(), 0);

    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::OnKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(HelloWorld::OnKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    this->scheduleUpdate();

    return true;
}

void HelloWorld::OnKeyReleased(EventKeyboard::KeyCode key, Event* event)
{
    Ship->RemoveUserAction(key);
    return;
}

void HelloWorld::OnKeyPressed(EventKeyboard::KeyCode key, Event* event)
{
    Ship->AddUserAction(key);
    return;
}

void HelloWorld::update(float delta)
{
    Ship->Update(delta);

    for (auto& e : Enemies)
    {
        e->Update(delta);
    }
}
