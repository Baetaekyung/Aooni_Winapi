#include "pch.h"
#include "IntroMoveScene.h"
#include "Player.h"
#include "Tile.h"
#include "Trigger.h"
#include "Animator.h"
#include "PlayerManager.h"
void IntroMoveScene::Init()
{
	Tile* tile = new Tile;
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetSize({ 639, 469 });
	tile->SetCustomTile(L"9");
	AddObject(tile, LAYER::BACKGROUND);

	SpawnPlayer
	pPlayer->SetIntro();

	//µ¿ÂÊ ¹®
	{
		Trigger* door = new Trigger;
		door->SetPos({ 850, 385 });
		door->SetColliderSize({ 30, 150 });
		door->SetPlayerSpawnPoint({ 470, 383 });
		door->SetNextMap(MAP_TYPE::MainHoleRightCorridor_1F);
		door->SetName(L"Door");
		AddObject(door, LAYER::INTERACTABLE);
	}
}

void IntroMoveScene::Update()
{
	Scene::Update();
}

void IntroMoveScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}
