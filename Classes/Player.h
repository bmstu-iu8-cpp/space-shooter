#pragma once
#include <cocos2d.h>
#include "MovableObject.h"

class Player
    : public MovableObject
{
public:
    Player(float x, float y, const std::string& filenamePicture, std::set<cocos2d::EventKeyboard::KeyCode>* pressed);

    void Update(float delta) override;

    void OnCollision(GameObject*) override;

    void UpVSpeed(float dx)
    {
        SetVSpeed(GetVSpeed() + dx);
    }

    void UpHSpeed(float dx)
    {
        SetHSpeed(GetHSpeed() + dx);
    }
private:

    bool HasUserAction(cocos2d::EventKeyboard::KeyCode);
    
    std::set<cocos2d::EventKeyboard::KeyCode>* PressedKeys;
};

