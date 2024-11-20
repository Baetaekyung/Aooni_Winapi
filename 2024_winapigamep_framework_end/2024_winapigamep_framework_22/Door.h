#pragma once
#include "Object.h"
class Door :
    public Object
{
public:
    Door();
    ~Door();
public:
    void Update() override;
    void Render(HDC hdc) override;
public:
    void EnterCollision(Collider* other) override;
    void StayCollision(Collider* other) override;
    void ExitCollision(Collider* other) override;
};

