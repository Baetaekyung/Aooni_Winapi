#pragma once

#include "Scene.h"
class Tile;
class Wall;
class MainHole_1F :
    public Scene
{
public:
    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;

    virtual void Update() override;

    virtual void Render(HDC _hdc) override;

public:
    Tile* tile;
};