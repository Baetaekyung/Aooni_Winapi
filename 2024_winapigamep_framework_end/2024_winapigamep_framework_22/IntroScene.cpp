#include "pch.h"
#include "IntroScene.h"
#include "IntroObject.h"
#include "Player.h"
#include "PlayerManager.h"
void IntroScene::Init()
{
	IntroObject* intro = new IntroObject;
	intro->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	intro->SetSize({ 637, 464 });
	AddObject(intro, LAYER::BACKGROUND);
	GET_SINGLE(PlayerManager)->SetPlayerSpawnPos({680, 380});
}

void IntroScene::Update()
{
	Scene::Update();
}

void IntroScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}