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


	//���� ��
	{
		Trigger* door = new Trigger;
		door->SetPos({ 760, 450 });
		door->SetColliderSize({ 30, 150 });
		door->SetNextMap(MAP_TYPE::MainHoleRightCorridor_1F);
		door->SetName(L"Door");
		door->SetPlayerSpawnPoint({ 470, 383});
		AddObject(door, LAYER::INTERACTABLE);
	}
	//���� ��
	{
		Trigger* door = new Trigger;
		door->SetPos({ 520, 450 });
		door->SetColliderSize({ 30, 200 });
		door->SetNextMap(MAP_TYPE::LeftCorridor_1FScene);
		door->SetName(L"Door");
		door->SetPlayerSpawnPoint({ 825, 380 });
		AddObject(door, LAYER::INTERACTABLE);
	}


//�ѤѤѤѤѤѿ�����Ʈ��ѤѤѤѤѤѤѤѤѤ�
	{
		//���� �ⱸ�� �� ����
		Trigger* door = new Trigger;
		door->SetPos({ 540, 310 });
		door->SetColliderSize({ 50, 70 });
		door->SetNeedKey(true);
		door->SetName(L"Wall");
		AddObject(door, LAYER::INTERACTABLE);
	}
	{
		//���� ��� �� �� ����
		Trigger* door = new Trigger;
		door->SetPos({ 670, 275 });
		door->SetColliderSize({ 30, 70 });
		door->SetNeedKey(true);
		door->SetName(L"Wall");
		AddObject(door, LAYER::INTERACTABLE);
	}
	{
		//���� ���� ����
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