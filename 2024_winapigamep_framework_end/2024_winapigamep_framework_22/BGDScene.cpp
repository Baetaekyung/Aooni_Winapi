#include "pch.h"
#include "BGDScene.h"
#include "Enemy.h"
#include "Player.h"

void BGDScene::Init()
{

	Object* pPlayer = new Player;
	pPlayer->SetPos({ SCREEN_WIDTH / 2.f,500.f });
	pPlayer->SetSize({ 100.f,500.f });
	AddObject(pPlayer, LAYER::PLAYER);

	Object* pObj = new Enemy;
	pObj->SetPos({ SCREEN_WIDTH / 2.f,150.f });
	pObj->SetSize({ 100.f,100.f });
	pObj->SetName(L"Enemy");
	AddObject(pObj, LAYER::ENEMY);

}
