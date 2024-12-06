#include "pch.h"
#include "IntroScene.h"
#include "IntroObject.h"
#include "Player.h"

void IntroScene::Init()
{
	intro = new IntroObject;
	intro->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	intro->SetSize({ 637, 464 });
	AddObject(intro, LAYER::BACKGROUND);
	spawnplayer = true;
	GET_SINGLE(PlayerManager)->SetPlayerSpawnPos({690, 383});
}

void IntroScene::Update()
{
	Scene::Update();
 	if (spawnplayer && intro->GetMoveScene()) {
		spawnplayer = false;
		SpawnPlayer;
	}
}

void IntroScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}