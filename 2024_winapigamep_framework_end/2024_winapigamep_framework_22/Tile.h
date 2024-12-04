#pragma once

#include "Object.h"
#include "TileMap.h"

class Texture;

class Tile :
    public Object
{
public:
    Tile();
    ~Tile();

public:
    void Update() override;
    void Render(HDC _hdc) override;


public:
    void ChangeTile(TileMap NewTileMap);

private:
    TileMap CurrentTileMap
        = TileMap::_1F_MAINHOLE;

    std::vector<Texture*> m_TexArr;

};

