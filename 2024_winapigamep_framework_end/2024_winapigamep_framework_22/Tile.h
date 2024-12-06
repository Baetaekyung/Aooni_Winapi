#pragma once

#include "Object.h"

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
    void SetTile(MAP_TYPE newMapType);

    void SetCustomTile(wstring newwstr);

private:
    MAP_TYPE CurrentTileMap
        = MAP_TYPE::MainHole_1FScene;
    std::map<std::wstring, std::wstring> textures;
    Texture* m_tTex;
};

