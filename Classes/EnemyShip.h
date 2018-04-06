#pragma once
#include <cocos2d.h>

#include "MovableObject.h"

class EnemyShip
    : public MovableObject
{
public:
    EnemyShip(float x, float y, float hspeed, float vspeed, const std::string& filenamePicture);
};
