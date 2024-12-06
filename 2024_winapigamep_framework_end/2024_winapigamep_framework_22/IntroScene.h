#pragma once
#include "Scene.h"
class IntroObject;
class IntroScene :
    public Scene
{
public:
    virtual void Init() override;

    virtual void Update() override;

    virtual void Render(HDC _hdc) override;

private:
    IntroObject* intro;
    bool spawnplayer = true;
};