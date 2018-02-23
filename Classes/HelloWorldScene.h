#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Player.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    ~HelloWorld();

    bool init() override;
    void update(float delta) override;

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
    Player * Ship;
    Player * Ship2;

    std::set<cocos2d::EventKeyboard::KeyCode> PressedKeys;


    void OnKeyPressed(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
    void OnKeyReleased(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
};

#endif // __HELLOWORLD_SCENE_H__
