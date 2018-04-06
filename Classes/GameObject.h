#pragma once
#include <cocos2d.h>


class GameObject
{
public:
    GameObject(float x, float y, const std::string & filenamePicture);
    virtual ~GameObject() = default;

    virtual void Update(float) = 0;

    cocos2d::Sprite * Sprite();

    virtual void OnCollision(GameObject*);

    static bool Collision(GameObject*, GameObject*);

private:
    cocos2d::Sprite * View;
};

