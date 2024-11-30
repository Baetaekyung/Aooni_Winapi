#include "pch.h"
#include "GameScene.h"
#include "Enemy.h"
#include "Key.h"
#include "Tile.h"
#include "InputManager.h"
#include "Player.h"
#include "Door.h"
#include "QuestionPuzzle.h"
#include "Object.h"

void GameScene::Init()
{
	tile = new Tile;
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetName(L"Map");
	AddObject(tile, LAYER::BACKGROUND);

	tile->ChangeTile(TileMap::_1F_MAINHOLE);

	Player* player = new Player;
	player->SetPos({ 640, 550 });
	player->SetSize({ 100.f, 100.f });
	player->SetName(L"Player");
	AddObject(player, LAYER::PLAYER);

	Door* door = new Door;
	door->SetNextMap(TileMap::_1F_MAINHOLE);
	door->SetSize({ 30, 60 });
	door->SetPos({ 610, 190 });
	door->SetName(L"Door");
	AddObject(door, LAYER::INTERACTABLE);

	QuestionPuzzle* pObj = new QuestionPuzzle;
	pObj->SetPuzzleQuestion(L"Who is GGM's GAMP TEACHER?");
	pObj->SetPuzzleAnswer(L"joonyongteacher");
	pObj->SetErrorMessage(L"반말하지 마세요~");
	pObj->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	pObj->SetName(L"Question");
	AddObject(pObj, LAYER::INTERACTABLE);
}

void GameScene::Update()
{
	Scene::Update();
}

void GameScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}
