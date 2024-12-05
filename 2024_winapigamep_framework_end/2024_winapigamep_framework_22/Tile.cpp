#include "pch.h"
#include "Tile.h"
#include "ResourceManager.h"
#include "Texture.h"
#include <vector>
#include <map>
#include <fstream>  // ���� �����
#include <sstream>  // ���ڿ� ��Ʈ��
#include <iostream> // �ܼ� ���

Tile::Tile()
{
    // �ؽ�ó �迭 �ʱ�ȭ
    m_TexArr.clear();

    int i = 0;

    // �ؽ�ó ��� ��
    std::map<std::wstring, std::wstring> textures = {
        {L"1F_MainHole", L"Texture\\aooniMap_1F_Hole.bmp"},
        {L"1F_MainHoleRightCorridor", L"Texture\\aooniMap_1F_HoleRightCorridor.bmp"},
    };

    // �ؽ�ó �ε�
    for (const auto& [name, path] : textures) {
        Texture* texture = GET_SINGLE(ResourceManager)->TextureLoad(name, path);
        if (texture) {
            m_TexArr.push_back(texture);
        }
        else {
            std::wcerr << L"Error: Failed to load texture: " << name << std::endl;
        }
    }
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

    int width = m_TexArr[static_cast<int>(CurrentTileMap)]->GetWidth();
    int height = m_TexArr[static_cast<int>(CurrentTileMap)]->GetHeight();

    ::TransparentBlt(_hdc,
        (int)(vPos.x - width / 2),
        (int)(vPos.y - height / 2),
        width, height,
        m_TexArr[static_cast<int>(CurrentTileMap)]->GetTexDC(),
        0, 0, width, height, RGB(255, 0, 255));
}

void Tile::SetTile(MAP_TYPE newMapType)
{
    CurrentTileMap = newMapType;
}
