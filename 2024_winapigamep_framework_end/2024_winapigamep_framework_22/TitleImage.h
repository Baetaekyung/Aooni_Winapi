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
    virtual void Render(HDC _hdc) override;
private:
    Texture* m_TTex;
};

