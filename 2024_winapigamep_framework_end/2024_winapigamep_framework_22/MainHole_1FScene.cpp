#include "pch.h"
#include "MainHole_1FScene.h"
#include "Tile.h"
#include "Player.h"
#include "Trigger.h"
#include "PlayerManager.h"
void MainHole_1FScene::Init()
{
	Tile* tile = new Tile;
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetSize({ 224, 416 });
	tile->SetTile(MAP_TYPE::MainHole_1FScene);
	AddObject(tile, LAYER::BACKGROUND);

	SpawnPlayer


	//µ¿ÂÊ ¹®
	{
		Trigger* door = new Trigger;
		door->SetPos({ 760, 450 });
		door->SetColliderSize({ 30, 150 });
		door->SetNextMap(MAP_TYPE::MainHoleRightCorridor_1F);
		door->SetName(L"Door");
		door->SetPlayerSpawnPoint({ 477, 380});
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