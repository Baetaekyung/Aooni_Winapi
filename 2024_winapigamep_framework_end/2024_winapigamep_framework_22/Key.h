#pragma once
#include "Object.h"
class Key :
    public Object
{
public:
    Key();
    ~Key();
public:
    void Update() override;
    void Render(HDC hdc) override;
public:
    virtual void EnterCollision(Collider* other);
    virtual void StayCollision(Collider* other);
    virtual void ExitCollision(Collider* other);
private:
    BRUSH_TYPE currentBrushType;
};

