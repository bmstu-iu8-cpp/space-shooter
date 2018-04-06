#include "Bonus.h"

using namespace cocos2d;

Bonus::Bonus(float x, float y, float hspeed, float vspeed, const std::string & filenamePicture)
    : MovableObject(x, y, hspeed, -vspeed, filenamePicture)
{
}

void Bonus::ApplyEffect(Player * ob) const
{
}

VBonus::VBonus(float x, float y, float hspeed, float vspeed, const std::string & filenamePicture)
    : Bonus(x, y, hspeed, vspeed, filenamePicture)
{
}

void VBonus::ApplyEffect(Player * ob) const
{
    ob->UpVSpeed(600.f);
}

HBonus::HBonus(float x, float y, float hspeed, float vspeed, const std::string & filenamePicture)
    : Bonus(x, y, hspeed, vspeed, filenamePicture)
{
}

void HBonus::ApplyEffect(Player * ob) const
{
    ob->UpHSpeed(600.f);
}