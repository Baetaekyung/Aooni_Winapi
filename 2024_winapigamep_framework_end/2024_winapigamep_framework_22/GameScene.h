#pragma once
#include "Scene.h"
class Tile;
class Wall;
class GameScene :
    public Scene
{
public:
    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;

    virtual void Update() override;

    virtual void Render(HDC _hdc) override;

public:
    Tile* tile;
    Wall* wall;
};