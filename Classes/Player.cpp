#include "Player.h"

Player::Player(float x, float y, const std::string & filenamePicture)
    : View(cocos2d::Sprite::create(filenamePicture))
    , X(x)
    , Y(y)
{
    if (View == nullptr)
        throw std::runtime_error("can't create a sprite");

    View->setPosition(X, Y);
}

cocos2d::Sprite * Player::Sprite()
{
    return View;
}
