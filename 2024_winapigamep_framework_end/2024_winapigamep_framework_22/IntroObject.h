#pragma once
#include "Object.h"
class Texture;
class IntroObject :
    public Object
{
public:
    IntroObject();
public:
    virtual void Update() override;

    virtual void Render(HDC _hdc) override;

public:
    bool GetMoveScene() { return bCanMoveScene; };
private:
    void NextIntro();
    Texture* m_InTex;
    bool bCanMoveScene;
    int cnt = 0;
};

