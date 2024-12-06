#include "pch.h"
#include "MainHoleRightCorridor_1F.h"
#include "Tile.h"
#include "Player.h"
#include "PlayerManager.h"

void MainHoleRightCorridor_1F::Init()
{
	Tile* tile = new Tile;
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetSize({ 384, 160 });
	AddObject(tile, LAYER::BACKGROUND);
	tile->SetTile(MAP_TYPE::MainHoleRightCorridor_1F);

	Object* pPlayer = new Player;
	pPlayer->SetSize({ 100, 100 });
	pPlayer->SetPos(GET_SINGLE(PlayerManager)->GetPlayerSpwanPos());
	AddObject(pPlayer, LAYER::PLAYER);
}

void MainHoleRightCorridor_1F::Update()
{
	Scene::Update();
}

void MainHoleRightCorridor_1F::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}