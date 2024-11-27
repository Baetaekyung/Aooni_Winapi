#include "pch.h"
#include "Tile.h"
#include "ResourceManager.h"
#include "Texture.h"
#include <vector>
#include <map>

Tile::Tile()
	: FloorTex(nullptr)
	, WallTex(nullptr)
	, DoorTex(nullptr)
{
	//배열에 텍스처 욱여넣기
	/*
	* 0 : floor
	* 1 : wall
	* 2 : door
	*/

	m_TexArr.clear();

	std::map<std::wstring, std::wstring> textures = {
		{L"1F_MainHole", L"Texture\\aooniMap_1F_Hole.bmp"},
		{L"1F_MainHoleRightCorridor", L"Texture\\aooniMap_1F_HoleRightCorridor.bmp"},
	};

	for (const auto& [name, path] : textures) {
		Texture* texture = GET_SINGLE(ResourceManager)->TextureLoad(name, path);
		if (texture) {
			m_TexArr.push_back(texture);
		}
		else {
			std::cout << "희호희오 비상 *됨";
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

	int width = m_TexArr[(int)CurrentTileMap]->GetWidth();
	int height = m_TexArr[(int)CurrentTileMap]->GetHeight();

	::TransparentBlt(_hdc
		, (int)(vPos.x - width / 2)
		, (int)(vPos.y - height / 2),
		width, height,
		m_TexArr[(int)CurrentTileMap]->GetTexDC()
		, 0, 0, width, height, RGB(255, 0, 255));
}

void Tile::ChangeTile(TileMap NewTileMap)
{
	CurrentTileMap = NewTileMap;
}
