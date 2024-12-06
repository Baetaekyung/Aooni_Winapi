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

private:
    void NextIntro();

    Texture* m_InTex;

    int cnt = 0;
};

