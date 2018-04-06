#include "MovableObject.h"

MovableObject::MovableObject(float x, float y, float hspeed, float vspeed, const std::string& filenamePicture)
    : GameObject(x, y, filenamePicture)
    , HorizontalSpeed(hspeed)
    , VerticalSpeed(vspeed)
{ }

void MovableObject::Move(float dx, float dy)
{
    cocos2d::Vec2 pos = Sprite()->getPosition();
    pos.add({dx * HorizontalSpeed, dy * VerticalSpeed});
    Sprite()->setPosition(pos);
}

void MovableObject::Update(float delta)
{
    Move(delta, delta);
}