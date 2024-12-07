#include "pch.h"
#include "LeftCorridor_1FScene.h"
#include "Tile.h"
#include "Player.h"
#include "Trigger.h"
#include "PlayerManager.h"


void LeftCorridor_1FScene::Init()
{
	Tile* tile = new Tile;
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetSize({ 449, 161 });
	tile->SetTile(MAP_TYPE::LeftCorridor_1FScene);
	AddObject(tile, LAYER::BACKGROUND);

	SpawnPlayer

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 문
	{
		Trigger* trigger = new Trigger;
		trigger->SetPos({865, 380});
		trigger->SetColliderSize({ 40, 150 });
		trigger->SetNextMap(MAP_TYPE::MainHole_1FScene);
		trigger->SetPlayerSpawnPoint({ 551, 442 });
		AddObject(trigger, LAYER::INTERACTABLE);
	}

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ오브젝트
	{
		Trigger * trigger = new Trigger;
		trigger->SetPos({ 625, 310 });
		trigger->SetColliderSize({500, 40});
		trigger->SetName(L"Wall");
		AddObject(trigger, LAYER::INTERACTABLE);
	}
}

void LeftCorridor_1FScene::Update()
{
	Scene::Update();
}

void LeftCorridor_1FScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}