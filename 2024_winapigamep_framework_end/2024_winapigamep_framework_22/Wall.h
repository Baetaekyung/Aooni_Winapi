#pragma once
#include "Object.h"
#include "TileMap.h"
class Wall :
    public Object
{
public:
    Wall();

    // Object을(를) 통해 상속됨
    void Update() override;

    void Render(HDC _hdc) override;

public:
    

private:
    TileMap Currenttilemap;
};

