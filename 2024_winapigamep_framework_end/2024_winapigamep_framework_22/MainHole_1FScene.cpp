#include "pch.h"
#include "MainHole_1FScene.h"
#include "Tile.h"
#include "Player.h"
#include "Trigger.h"

void MainHole_1FScene::Init()
{
	Tile* tile = new Tile;
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetSize({ 224, 416 });
	tile->SetTile(MAP_TYPE::MainHole_1FScene);
	AddObject(tile, LAYER::BACKGROUND);

	SpawnPlayer


	//동쪽 문
	{
		Trigger* door = new Trigger;
		door->SetPos({ 760, 450 });
		door->SetColliderSize({ 30, 150 });
		door->SetNextMap(MAP_TYPE::MainHoleRightCorridor_1F);
		door->SetName(L"Door");
		door->SetPlayerSpawnPoint({ 470, 383});
		AddObject(door, LAYER::INTERACTABLE);
	}
	//서쪽 문
	{
		Trigger* door = new Trigger;
		door->SetPos({ 520, 450 });
		door->SetColliderSize({ 30, 200 });
		door->SetNextMap(MAP_TYPE::LeftCorridor_1FScene);
		door->SetName(L"Door");
		door->SetPlayerSpawnPoint({ 825, 380 });
		AddObject(door, LAYER::INTERACTABLE);
	}


//ㅡㅡㅡㅡㅡㅡ오브젝트들ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	{
		//왼쪽 출구쪽 벽 막기
		Trigger* door = new Trigger;
		door->SetPos({ 540, 310 });
		door->SetColliderSize({ 50, 70 });
		door->SetNeedKey(true);
		door->SetName(L"Wall");
		AddObject(door, LAYER::INTERACTABLE);
	}
	{
		//북쪽 계단 옆 벽 막기
		Trigger* door = new Trigger;
		door->SetPos({ 670, 275 });
		door->SetColliderSize({ 30, 70 });
		door->SetNeedKey(true);
		door->SetName(L"Wall");
		AddObject(door, LAYER::INTERACTABLE);
	}
	{
		//북쪽 문쪽 막기
		Trigger* door = new Trigger;
		door->SetPos({ 600, 175 });
		door->SetColliderSize({ 150, 70 });
		door->SetNeedKey(true);
		door->SetName(L"Wall");
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