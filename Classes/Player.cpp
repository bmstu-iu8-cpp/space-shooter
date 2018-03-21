#include "Player.h"

using namespace cocos2d;

Player::Player(float x, float y, const std::string & filenamePicture)
    : View(cocos2d::Sprite::create(filenamePicture))
    , X(x)
    , Y(y)
    , hSpeed(120)
    , vSpeed(240)
{
    View->setPosition(X, Y);
}

cocos2d::Sprite * Player::Sprite()
{
    if (View == nullptr)
        throw std::runtime_error("sprite was not been loaded");

    return View;
}

bool Player::HasUserAction(cocos2d::EventKeyboard::KeyCode key)
{
    return PressedKeys.find(key) != PressedKeys.end();
}

void Player::Update(float dx, float dy)
{
    cocos2d::Vec2 pos = Sprite()->getPosition();
    pos.x += dx;
    pos.y += dy;
    Sprite()->setPosition(pos);
}

void Player::Update(float delta)
{
    if (HasUserAction(EventKeyboard::KeyCode::KEY_Q)) {
        hSpeed = 240;
        vSpeed = 120;
    }

    if (HasUserAction(EventKeyboard::KeyCode::KEY_E)) {
        hSpeed = 120;
        vSpeed = 240;
    }

    if (HasUserAction(EventKeyboard::KeyCode::KEY_D)) {
        Update(hSpeed * delta, 0);
    }

    if (HasUserAction(EventKeyboard::KeyCode::KEY_A)) {
        Update(-hSpeed * delta, 0);
    }

    if (HasUserAction(EventKeyboard::KeyCode::KEY_W)) {
        Update(0, +vSpeed * delta);
    }

    if (HasUserAction(EventKeyboard::KeyCode::KEY_S)) {
        Update(0, -vSpeed * delta);
    }
}

void Player::AddUserAction(cocos2d::EventKeyboard::KeyCode key)
{
    PressedKeys.insert(key);
}

void Player::RemoveUserAction(cocos2d::EventKeyboard::KeyCode key)
{
    if (PressedKeys.find(key) != PressedKeys.end())
        PressedKeys.erase(key);
}
