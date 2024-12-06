#include "pch.h"
#include "Tile.h"
#include "ResourceManager.h"
#include "Texture.h"
#include <vector>
#include <map>

Tile::Tile()
{
    m_tTex = GET_SINGLE(ResourceManager)->TextureFind(L"Kitchen_1F");
}

Tile::~Tile()
{
}

void Tile::Update()
{
}

void Tile::Render(HDC _hdc)
{
    Vec2 vPos = GetPos();
    Vec2 vSize = GetSize();

    int width = m_tTex->GetWidth();
    int height = m_tTex->GetHeight();

    ::TransparentBlt(_hdc,
        static_cast<int>(vPos.x - vSize.x / 2),
        static_cast<int>(vPos.y - vSize.y / 2),
        static_cast<int>(vSize.x),
        static_cast<int>(vSize.y),
        m_tTex->GetTexDC(),
        0, 0, width, height,
        RGB(255, 0, 255));

    ComponentRender(_hdc);
}


void Tile::SetTile(MAP_TYPE newMapType)
{
    wstring path;

    switch (newMapType)
    {
    case MAP_TYPE::MainHole_1FScene:
        path = L"MainHole_1FScene";
        break;
    case MAP_TYPE::MainHoleRightCorridor_1F:
        path = L"MainHoleRightCorridor_1F";
        break;
    case MAP_TYPE::Kitchen_1F:
        path = L"Kitchen_1F";
        break;
    case MAP_TYPE::LeftCorridor_1FScene:
        path = L"LeftCorridor_1FScene";
        break;
    case MAP_TYPE::END:
        break;
    default:
        break;
    }
    m_tTex = GET_SINGLE(ResourceManager)->TextureFind(path);
}
