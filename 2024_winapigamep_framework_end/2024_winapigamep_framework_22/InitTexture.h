#pragma once
#include "Object.h"
class InitTexture :
    public Object
{
public:
    InitTexture();

    virtual void Update() override;

    virtual void Render(HDC _hdc) override;
};

