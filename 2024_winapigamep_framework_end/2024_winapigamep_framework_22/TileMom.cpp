#include "pch.h"
#include "TileMom.h"
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
	ResourceManager* RMptr
		= GET_SINGLE(ResourceManager);

	std::map<std::wstring, std::wstring> textures = {
		{L"Floor", L"AAoni_FloorTile.bmp"},
		{L"Wall", L"AAoni_WallTile"},
		{L"Door", L"AAoni_DoorTile.bmp"}
	};

	for (const auto& [name, path] : textures) {
		auto texture = RMptr->TextureLoad(name, path);
		if (texture) {
			m_pTex.push_back(texture);
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

	int width = m_pTex[(int)CurrentTileMap]->GetWidth();
	int height = m_pTex[(int)CurrentTileMap]->GetHeight();

	ComponentRender(_hdc);
}

void Tile::ChangeTile()
{
}
