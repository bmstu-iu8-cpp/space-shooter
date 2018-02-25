#include "Player.h"

Player::Player(float x, float y, const std::string & filenamePicture)
    : View(cocos2d::Sprite::create(filenamePicture))
    , X(x)
    , Y(y)
{
    View->setPosition(X, Y);
}

cocos2d::Sprite * Player::Sprite()
{
    if (View == nullptr)
        throw std::runtime_error("sprite was not been loaded");

    return View;
}
