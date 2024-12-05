#include "pch.h"
#include "MainHoleRightCorridor_1F.h"
#include "Tile.h"

void MainHoleRightCorridor_1F::Init()
{
	Tile* tile = new Tile;
	tile->SetTile(MAP_TYPE::MainHoleRightCorridor_1F);
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetSize({ 1000, 1000 });
	tile->SetName(L"Map");
	AddObject(tile, LAYER::BACKGROUND);
}

void MainHoleRightCorridor_1F::Update()
{
	Scene::Update();
}

void MainHoleRightCorridor_1F::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}
