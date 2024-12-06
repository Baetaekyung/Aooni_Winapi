#include "pch.h"
#include "Kitchen_1FScene.h"
#include "Tile.h"
#include "Player.h"
#include "PlayerManager.h"
#include "Trigger.h"
void Kitchen_1FScene::Init()
{
	std::cout << "\nHelloWrold\n";

	Tile* tile = new Tile;
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetSize({ 286, 474 });
	tile->SetTile(MAP_TYPE::Kitchen_1F);
	AddObject(tile, LAYER::BACKGROUND);

	SpawnPlayer

	//서쪽 문
	{
		Trigger* door = new Trigger;
		door->SetPos({ 504, 412 });
		door->SetColliderSize({ 50, 50 });
		door->SetPlayerSpawnPoint({ 806, 386 });
		door->SetNextMap(MAP_TYPE::MainHoleRightCorridor_1F);
		AddObject(door, LAYER::INTERACTABLE);
	}

	//ㅡㅡㅡㅡㅡㅡ오브젝트들ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	{
		Trigger* door = new Trigger;
		door->SetPos({ 670, 330 });
		door->SetColliderSize({ 100, 150 });
		door->SetNeedKey(true);
		door->SetName(L"Wall");
		AddObject(door, LAYER::INTERACTABLE);
	}
	{
		Trigger* door = new Trigger;
		door->SetPos({ 650, 140 });
		door->SetColliderSize({ 240, 80 });
		door->SetNeedKey(true);
		door->SetName(L"Wall");
		AddObject(door, LAYER::INTERACTABLE);
	}
	{
		Trigger* door = new Trigger;
		door->SetPos({ 720, 240 });
		door->SetColliderSize({ 120, 30 });
		door->SetNeedKey(true);
		door->SetName(L"Wall");
		AddObject(door, LAYER::INTERACTABLE);
	}
}

void Kitchen_1FScene::Update()
{
	Scene::Update();
}

void Kitchen_1FScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}
