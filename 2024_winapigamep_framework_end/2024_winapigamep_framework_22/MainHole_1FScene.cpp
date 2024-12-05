#include "pch.h"
#include "MainHole_1FScene.h"
#include "Tile.h"
#include "Player.h"
#include "Door.h"

void MainHole_1FScene::Init()
{
	std::cout << "\nIn";

	Tile* tile = new Tile;
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetSize({ 224, 416 });
	tile->SetTile(MAP_TYPE::MainHole_1FScene);
	AddObject(tile, LAYER::BACKGROUND);

	Object* pPlayer = new Player;
	pPlayer->SetPos({ SCREEN_WIDTH / 2.f,500.f });
	pPlayer->SetSize({ 100.f,100.f });
	AddObject(pPlayer, LAYER::PLAYER);

	Door* door1 =new Door;
	door1->SetPos({ 750, 400 });
	door1->SetName(L"Door");
	door1->SetNoNeedKey(true);
	door1->SetNextMap(MAP_TYPE::MainHoleRightCorridor_1F);
	AddObject(door1, LAYER::INTERACTABLE);
}

void MainHole_1FScene::Update()
{
	Scene::Update();
}

void MainHole_1FScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}