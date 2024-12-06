#pragma once
#include "Scene.h"
class IntroMoveScene :
    public Scene
{
    virtual void Init() override;

    virtual void Update() override;

    virtual void Render(HDC _hdc) override;
};

