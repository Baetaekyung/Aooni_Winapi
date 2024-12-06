#pragma once
#include "Scene.h"
class LeftCorridor_1FScene :
    public Scene
{
public:
    virtual void Init() override;

    virtual void Update() override;

    virtual void Render(HDC _hdc) override;
};

