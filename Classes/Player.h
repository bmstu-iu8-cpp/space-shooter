#pragma once
#include <cocos2d.h>

class Player
{
public:
    Player(float x, float y, const std::string& filenamePicture);
    ~Player() = default;

    cocos2d::Sprite * Sprite();
    void Update(float delta);

    void AddUserAction(cocos2d::EventKeyboard::KeyCode);
    void RemoveUserAction(cocos2d::EventKeyboard::KeyCode);
private:

    bool HasUserAction(cocos2d::EventKeyboard::KeyCode);

    void Update(float dx, float dy);

    cocos2d::Sprite * View;
    float X;
    float Y;

    float hSpeed;
    float vSpeed;


    std::set<cocos2d::EventKeyboard::KeyCode> PressedKeys;
};

