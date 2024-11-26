#pragma once

#include "Object.h"

enum class TileMap {
    FLOOR,
    WALL,
    DOOR,
};

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
    void ChangeTile();

private:
    Texture* FloorTex;
    Texture* WallTex;
    Texture* DoorTex;

    TileMap CurrentTileMap;

    std::vector<Texture*> m_pTex;
};

