#include "pch.h"
#include "GameScene.h"
#include "Enemy.h"
#include "Key.h"
#include "Tile.h"
#include "InputManager.h"
#include "Player.h"
#include "CollisionManager.h"
void GameScene::Init()
{
	tile = new Tile;
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetName(L"Map");
	AddObject(tile, LAYER::BACKGROUND);

	tile->ChangeTile(TileMap::_1F_MAINHOLE);

	pPlayer = new Player;
	pPlayer->SetPos({ SCREEN_WIDTH / 2.f,500.f });
	pPlayer->SetSize({ 100.f,100.f });
	AddObject(pPlayer, LAYER::PLAYER);

	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::ENEMY, LAYER::PLAYER);
}

void GameScene::Update()
{
	Scene::Update();

	
}

void GameScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}