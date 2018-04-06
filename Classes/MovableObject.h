#pragma once
#include "GameObject.h"


class MovableObject :
    public GameObject
{
public:
    MovableObject(float x, float y, float hspeed, float vspeed, const std::string& filenamePicture);

    void Move(float dx, float dy);
    
    void Update(float) override;

    inline void SetVSpeed(float s)
    {
        VerticalSpeed = s;
    }
    inline void SetHSpeed(float s)
    {
        HorizontalSpeed = s;
    }

    inline float GetVSpeed() const
    {
        return VerticalSpeed;
    }
    inline float GetHSpeed() const
    {
        return HorizontalSpeed;
    }
private:
    float VerticalSpeed;
    float HorizontalSpeed;
};

