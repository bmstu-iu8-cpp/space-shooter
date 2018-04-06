#include "EnemyShip.h"

using namespace cocos2d;

EnemyShip::EnemyShip(float x, float y, float hspeed, float vspeed, const std::string & filenamePicture)
    : MovableObject(x, y, hspeed, -vspeed, filenamePicture)
{
}
