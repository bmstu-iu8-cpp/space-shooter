#include "GameObject.h"

cocos2d::Sprite * GameObject::Sprite()
{
    if (View == nullptr)
        throw std::runtime_error("sprite was not been loaded");

    return View;
}

bool GameObject::Collision(GameObject* a, GameObject* b)
{
    if (a == b)
        return false;

    float x1 = a->View->getPosition().x;
    float y1 = a->View->getPosition().y;
    float h1 = a->View->getContentSize().height;
    float w1 = a->View->getContentSize().width;

    float x2 = b->View->getPosition().x;
    float y2 = b->View->getPosition().y;
    float h2 = b->View->getContentSize().height;
    float w2 = b->View->getContentSize().width;

    return (std::abs(x1 - x2) < (w1 + w2) / 2)
        && (std::abs(y1 - y2) < (h1 + h2) / 2);
}

void GameObject::OnCollision(GameObject*)
{
}

GameObject::GameObject(float x, float y, const std::string & filenamePicture)
    : View(cocos2d::Sprite::create(filenamePicture))
{
    View->setPosition(x, y);
}