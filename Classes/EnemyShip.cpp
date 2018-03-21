#include "EnemyShip.h"

using namespace cocos2d;

EnemyShip::EnemyShip(float x, float y, float hspeed, float vspeed, const std::string & filenamePicture)
    : View(cocos2d::Sprite::create(filenamePicture))
    , X(x)
    , Y(y)
    , hSpeed(hspeed)
    , vSpeed(vspeed)
{
    View->setPosition(X, Y);
}

cocos2d::Sprite * EnemyShip::Sprite()
{
    if (View == nullptr)
        throw std::runtime_error("sprite was not been loaded");

    return View;
}

void EnemyShip::Update(float dx, float dy)
{
    cocos2d::Vec2 pos = Sprite()->getPosition();
    pos.x += dx;
    pos.y += dy;
    Sprite()->setPosition(pos);
}

void EnemyShip::Update(float delta)
{
    Update(hSpeed * delta, -vSpeed * delta);
}
