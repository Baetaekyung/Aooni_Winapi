#pragma once
#include "Object.h"
#include "TileMap.h"
class Wall :
    public Object
{
public:
    Wall();

    // Object��(��) ���� ��ӵ�
    void Update() override;

    void Render(HDC _hdc) override;

public:
    

private:
    TileMap Currenttilemap;
};

