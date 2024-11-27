#include "pch.h"
#include "GameScene.h"
#include "Enemy.h"
#include "Key.h"
#include "Tile.h"
#include "InputManager.h"
void GameScene::Init()
{
	tile = new Tile;
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetName(L"Map");
	AddObject(tile, LAYER::BACKGROUND);

	tile->ChangeTile(TileMap::_1F_MAINHOLE);
}

void GameScene::Update()
{
	Scene::Update();

	
}

void GameScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}
