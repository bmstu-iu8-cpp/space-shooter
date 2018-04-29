#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Bonus.h"
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

    // TODO refactoring
    Objects.push_back(
        std::make_unique<Player>(
            visibleSize.width / 2 + origin.x,
            visibleSize.height / 3 + origin.y,
            "playerShip.png",
            &PressedKeys
        )
    );
    this->addChild(Objects.back()->Sprite(), 0);

    for (int i = 0; i < 4; ++i)
    {
        // TODO refactoring
        Objects.push_back(
            std::make_unique<EnemyShip>(
                visibleSize.width / 2 + origin.x + (rand() % 600) - 300,
                visibleSize.height + origin.y,
                10,
                100 + (rand() % 150),
                "enemyShip.png"
            )
        );

        this->addChild(Objects.back()->Sprite(), 0);
    }

    for (int i = 0; i < 1; ++i)
    {
        // TODO refactoring
        Objects.push_back(
            std::make_unique<HBonus>(
                visibleSize.width / 2 + origin.x + (rand() % 600) - 300,
                visibleSize.height + origin.y,
                10,
                100 + (rand() % 150),
                "mushroom_life.png"
                )
        );
        this->addChild(Objects.back()->Sprite(), 0);

        // TODO refactoring
        Objects.push_back(
            std::make_unique<VBonus>(
                visibleSize.width / 2 + origin.x + (rand() % 600) - 300,
                visibleSize.height + origin.y,
                10,
                100 + (rand() % 150),
                "mushroom_life.png"
                )
        );
        this->addChild(Objects.back()->Sprite(), 0);
    }

    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::OnKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(HelloWorld::OnKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    this->scheduleUpdate();

    return true;
}

void HelloWorld::OnKeyReleased(EventKeyboard::KeyCode key, Event* event)
{
    if (PressedKeys.find(key) != PressedKeys.end())
        PressedKeys.erase(key);
}

void HelloWorld::OnKeyPressed(EventKeyboard::KeyCode key, Event* event)
{
    PressedKeys.insert(key);
}

void HelloWorld::update(float delta)
{
    for (auto& e : Objects)
    {
        e->Update(delta);
    }

    std::set<
        std::vector<std::unique_ptr<GameObject>>::iterator
    > toDelete;

    GameObject* player = Objects.begin()->get();
    {
        for (auto it = Objects.rbegin() + 1; it != Objects.rend(); ++it)
        {
            GameObject* obj = it->get();
            bool yes = GameObject::Collision(player, obj);
            if (yes)
            {
                toDelete.insert(it);
                player->OnCollision(obj);
            }
        }
    }

    for (auto it : toDelete)
    {
        // TODO refactoring
        std::unique_ptr<GameObject>& ptr = *it;
        CCParticleSystemQuad* explosion = CCParticleSystemQuad::create("explosion.plist");
        explosion->setAutoRemoveOnFinish(true);
        explosion->setPosition(ptr->Sprite()->getPosition());
        this->addChild(explosion);

        this->removeChild(ptr->Sprite());
        Objects.erase(it);
    }
}
