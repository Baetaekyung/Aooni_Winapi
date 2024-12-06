#include "pch.h"
#include "MainHole_1FScene.h"
#include "Tile.h"
#include "Player.h"
#include "Door.h"
#include "PlayerManager.h"
void MainHole_1FScene::Init()
{
	Tile* tile = new Tile;
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetSize({ 224, 416 });
	tile->SetTile(MAP_TYPE::MainHole_1FScene);
	AddObject(tile, LAYER::BACKGROUND);

	Object* pPlayer = new Player;
	pPlayer->SetPos(GET_SINGLE(PlayerManager)->GetPlayerSpwanPos());
	pPlayer->SetSize({ 100.f,100.f });
	AddObject(pPlayer, LAYER::PLAYER);


	//µ¿ÂÊ ¹®
	{
		Door* door = new Door;
		door->SetPos({ 750, 420 });
		door->SetColliderSize({ 30, 150 });
		door->SetNextMap(MAP_TYPE::MainHoleRightCorridor_1F);
		door->SetName(L"Door");
		door->SetNoNeedKey(true);
		door->SetPlayerSpawnPoint({459, 380});
		AddObject(door, LAYER::INTERACTABLE);
	}
}

void MainHole_1FScene::Update()
{
	Scene::Update();
}

void MainHole_1FScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}