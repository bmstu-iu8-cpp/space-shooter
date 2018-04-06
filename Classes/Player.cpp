#include "Player.h"
#include "Bonus.h"
#include <Windows.h>

using namespace cocos2d;

Player::Player(float x, float y, const std::string & filenamePicture, std::set<cocos2d::EventKeyboard::KeyCode>* pressed)
    : MovableObject(x, y, 120, 240, filenamePicture)
    , PressedKeys(pressed)
{
}

bool Player::HasUserAction(cocos2d::EventKeyboard::KeyCode key)
{
    return PressedKeys->find(key) != PressedKeys->end();
}

void Player::Update(float delta)
{
    if (HasUserAction(EventKeyboard::KeyCode::KEY_Q)) {
        SetHSpeed(240);
        SetVSpeed(120);
    }

    if (HasUserAction(EventKeyboard::KeyCode::KEY_E)) {
        SetHSpeed(120);
        SetVSpeed(240);
    }

    if (HasUserAction(EventKeyboard::KeyCode::KEY_D)) {
        Move(delta, 0);
    }

    if (HasUserAction(EventKeyboard::KeyCode::KEY_A)) {
        Move(-delta, 0);
    }

    if (HasUserAction(EventKeyboard::KeyCode::KEY_W)) {
        Move(0, delta);
    }

    if (HasUserAction(EventKeyboard::KeyCode::KEY_S)) {
        Move(0, -delta);
    }
}

void Player::OnCollision(GameObject * object)
{
    Bonus* bonus = dynamic_cast<Bonus*>(object);

    if (bonus)
    {
        bonus->ApplyEffect(this);
    }
    else
    {
        cocos2d::log("object is not Bonus");
    }

    return;
}
