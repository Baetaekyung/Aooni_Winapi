#include "pch.h"
#include "BGDScene.h"
#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"
#include "CollisionManager.h"

void BGDScene::Init()
{

	Object* pPlayer = new Player;
	pPlayer->SetPos({ SCREEN_WIDTH / 2.f,500.f });
	pPlayer->SetSize({ 100.f,500.f });
	AddObject(pPlayer, LAYER::PLAYER);

	Object* pObj = new Enemy;
	pObj->SetPos({ SCREEN_WIDTH / 2.f,150.f });
	pObj->SetSize({ 100.f,500.f });
	pObj->SetName(L"Enemy");
	AddObject(pObj, LAYER::ENEMY);

	Object* pObj2 = new Projectile;
	pObj2->SetPos({ SCREEN_WIDTH / 2.f,400.f });
	pObj2->SetSize({ 64.f,128.f });
	pObj2->SetName(L"BackGround1");
	AddObject(pObj2, LAYER::PROJECTILE);

	//Object* pObj3 = new Projectile;
	//pObj3->SetPos({ SCREEN_WIDTH / 2.f,550.f });
	//pObj3->SetSize({ 64.f,128.f });
	//pObj3->SetName(L"BackGround2");
	//AddObject(pObj3, LAYER::PROJECTILE);

	//GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);
	//GET_SINGLE(CollisionManager)->CheckLayer(LAYER::ENEMY, LAYER::PLAYER);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::ENEMY, LAYER::PROJECTILE);
	//GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);

}
