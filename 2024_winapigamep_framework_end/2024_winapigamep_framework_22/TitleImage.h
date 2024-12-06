#pragma once
#include "Object.h"

class Texture;

class TitleImage :
    public Object
{
public:
    TitleImage();
    ~TitleImage();

public:
    virtual void Update() override;

    virtual void Render(HDC _hdc) override;
public:
    Texture* m_tTex;
};

