#pragma once
#include <cocos2d.h>

class Player
{
public:
    Player(float x, float y, const std::string& filenamePicture);
    ~Player() = default;

    cocos2d::Sprite * Sprite();

private:
    cocos2d::Sprite * View;
    float X;
    float Y;
};

