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
#include "Texture.h"
#include "TitleImage.h"
#include "GDISelector.h"
void TitleScene::Init()
{
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Title", L"Texture\\Title.bmp");
	
	GET_SINGLE(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
	GET_SINGLE(ResourceManager)->LoadSound(L"TitleBGM", L"Sound\\TitleScene.wav", true);
	GET_SINGLE(ResourceManager)->Play(L"TitleBGM");
	GET_SINGLE(ResourceManager)->Volume(SOUND_CHANNEL::BGM, 0.2f);
	/*Object* pObj = new Enemy;
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
	pDoor->SetNextMap(TileMap::_1F_MAINHOLE);
	AddObject(pDoor, LAYER::INTERACTABLE);

	Object* pKey = new Key;
	pKey->SetPos({ 100, SCREEN_HEIGHT / 2 });
	pKey->SetSize({ 10.f, 10.f });
	AddObject(pKey, LAYER::INTERACTABLE);

	GET_SINGLE(ResourceManager)->LoadSound(L"Door", L"Sound\\doorOpen.wav", false);
	GET_SINGLE(ResourceManager)->LoadSound(L"GetKey", L"Sound\\GetKeySound.wav", false);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);*/
	//GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);
	//GET_SINGLE(ResourceManager)->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	//GET_SINGLE(ResourceManager)->Play(L"BGM");
}

void TitleScene::Update()
{
	Scene::Update();
	if (GET_KEYDOWN(KEY_TYPE::ENTER))
		GET_SINGLE(SceneManager)->LoadScene(L"EndingScene");
}

void TitleScene::Render(HDC _hdc)
{
	BitBlt(_hdc,
		200, 100,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		m_pTex->GetTexDC(), 0,
		0, SRCCOPY);

	SetTextColor(_hdc, RGB(255, 0, 0));
	SetBkColor(_hdc, TRANSPARENT);
	TextOut(_hdc, 600, 500 ,L"Enter to start!", 14);

	Scene::Render(_hdc);
}
