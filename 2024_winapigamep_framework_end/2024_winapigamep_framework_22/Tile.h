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

    std::vector<std::vector<char>> m_WallArr[100];

private:
    Texture* FloorTex;
    Texture* WallTex;
    Texture* DoorTex;

    TileMap CurrentTileMap
        = TileMap::_1F_MAINHOLE;

    std::vector<Texture*> m_TexArr;

};

