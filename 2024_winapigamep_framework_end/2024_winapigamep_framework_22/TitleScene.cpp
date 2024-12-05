#include "pch.h"
#include "TitleScene.h"
#include "Object.h"
#include "Player.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "Key.h"
#include "Door.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "TileMap.h"
void TitleScene::Init()
{
	Object* pObj = new Enemy;
	pObj->SetPos({ SCREEN_WIDTH / 2.f,150.f });
	pObj->SetSize({ 100.f,100.f });
	pObj->SetName(L"Enemy");
	AddObject(pObj, LAYER::ENEMY);

	Object* pPlayer = new Player;
	pPlayer->SetPos({ SCREEN_WIDTH / 2.f,500.f });
	pPlayer->SetSize({ 100.f,100.f });
	AddObject(pPlayer, LAYER::PLAYER);

	Door* pDoor = new Door;
	pDoor->SetPos({ SCREEN_WIDTH - 100, SCREEN_HEIGHT / 2 });
	pDoor->SetSize({ 30.f, 50.f });
	pDoor->SetNextMap(MAP_TYPE::MainHole_1FScene);
	AddObject(pDoor, LAYER::INTERACTABLE);

	Object* pKey = new Key;
	pKey->SetPos({ 100, SCREEN_HEIGHT / 2 });
	pKey->SetSize({ 10.f, 10.f });
	AddObject(pKey, LAYER::INTERACTABLE);

	GET_SINGLE(ResourceManager)->LoadSound(L"Door", L"Sound\\doorOpen.wav", false);
	GET_SINGLE(ResourceManager)->LoadSound(L"GetKey", L"Sound\\GetKeySound.wav", false);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);
	//GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);
	//GET_SINGLE(ResourceManager)->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	//GET_SINGLE(ResourceManager)->Play(L"BGM");
}

void TitleScene::Update()
{
	Scene::Update();
	if (GET_KEYDOWN(KEY_TYPE::ENTER))
		GET_SINGLE(SceneManager)->LoadScene(L"MainHole_1FScene");
}

void TitleScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}
