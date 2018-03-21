#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Player.h"
#include "EnemyShip.h"

#include <memory>

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    bool init() override;
    void update(float delta) override;

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
    
    std::vector<std::unique_ptr<EnemyShip>> Enemies;
    std::unique_ptr<EnemyShip> E;
    std::unique_ptr<Player> Ship;
   
    void OnKeyPressed(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
    void OnKeyReleased(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
};

#endif // __HELLOWORLD_SCENE_H__
