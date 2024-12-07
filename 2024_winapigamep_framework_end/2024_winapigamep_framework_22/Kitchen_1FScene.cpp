#include "pch.h"
#include "Kitchen_1FScene.h"
#include "Tile.h"
#include "Player.h"
#include "Trigger.h"
#include "Key.h"
#include "PlayerManager.h"
void Kitchen_1FScene::Init()
{
	std::cout << "\nHelloWrold\n";

	Tile* tile = new Tile;
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetSize({ 286, 474 });
	tile->SetTile(MAP_TYPE::Kitchen_1F);
	AddObject(tile, LAYER::BACKGROUND);

	SpawnPlayer

	//����
	{
		Key * key = new Key;
		key->SetPos({ 635, 225 });
		key->SetSize({ 20, 20 });
		key->SetKeyType(KEY_TYPE::Glass);
		key->SetTextType(TEXT_TYPE::GetGlass);
		AddObject(key, LAYER::INTERACTABLE);
	}

	//���� ��
	{
		Trigger* door = new Trigger;
		door->SetPos({ 504, 412 });
		door->SetColliderSize({ 50, 50 });
		door->SetPlayerSpawnPoint({ 806, 386 });
		door->SetNextMap(MAP_TYPE::MainHoleRightCorridor_1F);
		AddObject(door, LAYER::INTERACTABLE);
	}

	//�ѤѤѤѤѤѿ�����Ʈ��ѤѤѤѤѤѤѤѤѤ�
	{
		//��Ź ����
		Trigger* door = new Trigger;
		door->SetPos({ 670, 330 });
		door->SetColliderSize({ 100, 150 });
		door->SetName(L"Wall");
		AddObject(door, LAYER::INTERACTABLE);
	}
	{
		//����� ¼��¼�� ����
		Trigger* door = new Trigger;
		door->SetPos({ 650, 140 });
		door->SetColliderSize({ 240, 80 });
		door->SetName(L"Wall");
		AddObject(door, LAYER::INTERACTABLE);
	}
	{
		//��ũ�� ����
		Trigger* door = new Trigger;
		door->SetPos({ 720, 240 });
		door->SetColliderSize({ 120, 30 });
		door->SetName(L"Wall");
		AddObject(door, LAYER::INTERACTABLE);
	}

	{
		//������ �Ʒ� ���� ����
		Trigger* door = new Trigger;
		door->SetPos({ 710, 520 });
		door->SetColliderSize({ 30, 60 });
		door->SetName(L"Wall");
		AddObject(door, LAYER::INTERACTABLE);
	}
	{
		//�Ʒ� ���� ����
		Trigger* door = new Trigger;
		door->SetPos({ 620, 590 });
		door->SetColliderSize({ 60, 30 });
		door->SetName(L"Wall");
		AddObject(door, LAYER::INTERACTABLE);
	}
	{
		//��, �ⱸ�� �� ����
		Trigger* door = new Trigger;
		door->SetPos({ 510, 360 });
		door->SetColliderSize({ 30, 30 });
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
