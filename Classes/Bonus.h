#pragma once
#include <cocos2d.h>

#include "Player.h"
#include "MovableObject.h"

class Bonus
    : public MovableObject
{
public:
    Bonus(float x, float y, float hspeed, float vspeed, const std::string& filenamePicture);
    
    virtual void ApplyEffect(Player* ob) const;
};


class VBonus
    : public Bonus
{
public:
    VBonus(float x, float y, float hspeed, float vspeed, const std::string& filenamePicture);

    virtual void ApplyEffect(Player* ob) const override;
};

class HBonus
    : public Bonus
{
public:
    HBonus(float x, float y, float hspeed, float vspeed, const std::string& filenamePicture);

    virtual void ApplyEffect(Player* ob) const override;
};