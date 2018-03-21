#pragma once
#include <cocos2d.h>

class EnemyShip
{
public:
    EnemyShip(float x, float y, float hspeed, float vspeed, const std::string& filenamePicture);

    cocos2d::Sprite * Sprite();
    void Update(float delta);

private:

    void Update(float dx, float dy);

    cocos2d::Sprite * View;
    float X;
    float Y;

    float hSpeed;
    float vSpeed;
};

