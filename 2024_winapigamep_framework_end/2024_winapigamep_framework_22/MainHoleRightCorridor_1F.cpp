#include "pch.h"
#include "MainHoleRightCorridor_1F.h"
#include "Tile.h"
#include "Player.h"
#include "PlayerManager.h"
#include "Trigger.h"
#include "Key.h"
#include "ResourceManager.h"
void MainHoleRightCorridor_1F::Init()
{
	GET_SINGLE(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
	std::cout << "\nHelloWrold\n";
	Tile* tile = new Tile;
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetSize({ 384, 160 });
	AddObject(tile, LAYER::BACKGROUND);
	tile->SetTile(MAP_TYPE::MainHoleRightCorridor_1F);

	SpawnPlayer

	//동쪽 문
	{
		Trigger* door = new Trigger;
		door->SetPos({ 837, 380 });
		door->SetColliderSize({ 30, 100 });
		door->SetPlayerSpawnPoint({ 540, 414 });
		door->SetNextMap(MAP_TYPE::Kitchen_1F);
		AddObject(door, LAYER::INTERACTABLE);
	}

	//서쪽 문
	{
		Trigger* door = new Trigger;
		door->SetPos({ 445, 380 });
		door->SetColliderSize({ 20, 100 });
		door->SetPlayerSpawnPoint({ 732, 446 });
		door->SetNeedKeyType(KEY_TYPE::Glass);
		door->SetText(TEXT_TYPE::Guys);
		door->SetNextMap(MAP_TYPE::MainHole_1FScene);
		AddObject(door, LAYER::INTERACTABLE);
	}
	//ㅡㅡㅡㅡㅡㅡ오브젝트들ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	{
		Trigger* door = new Trigger;
		door->SetPos({ 650, 310 });
		door->SetColliderSize({ 420, 50 });
		door->SetName(L"Wall");
		AddObject(door, LAYER::INTERACTABLE);
	}
}

void MainHoleRightCorridor_1F::Update()
{
	Scene::Update();
}

void MainHoleRightCorridor_1F::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}