#include "pch.h"
#include "Kitchen_1FScene.h"
#include "Tile.h"
void Kitchen_1FScene::Init()
{
	Tile* tile = new Tile;
	tile->SetTile(MAP_TYPE::Kitchen_1F);
	tile->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	tile->SetSize({ 286, 474 });
}

void Kitchen_1FScene::Update()
{
	Scene::Update();
}

void Kitchen_1FScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}
