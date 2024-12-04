#include "pch.h"
#include "BGDScene.h"
#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"
#include "EnemyWallCast.h"
#include "CollisionManager.h"
#include "Tile.h"
#include "Wall.h"

void BGDScene::Init()
{

	Object* pPlayer = new Player;
	pPlayer->SetPos({ SCREEN_WIDTH / 2.f,500.f });
	pPlayer->SetSize({ 100.f,500.f });
	AddObject(pPlayer, LAYER::PLAYER);

	//Object* pEnemy = new Enemy;
	//pEnemy->SetPos({ SCREEN_WIDTH / 2.f,150.f });
	//pEnemy->SetSize({ 100.f,500.f });
	//pEnemy->SetName(L"Enemy");
	//AddObject(pEnemy, LAYER::ENEMY);

	//Object* pEnemyCast = new EnemyWallCast;
	//pEnemyCast->SetPos({ SCREEN_WIDTH / 2.f,150.f });
	//pEnemyCast->SetSize({ 100.f,500.f });
	//pEnemyCast->SetName(L"EnemyCast");
	//AddObject(pEnemyCast, LAYER::ENEMYCAST);

	//Object* pObj2 = new Projectile;
	//pObj2->SetPos({ SCREEN_WIDTH / 2.f,400.f });
	//pObj2->SetSize({ 64.f,128.f });
	//pObj2->SetName(L"BackGround1");
	//AddObject(pObj2, LAYER::PROJECTILE);

	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::ENEMYCAST, LAYER::PROJECTILE);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::ENEMY, LAYER::PLAYER);
	//GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);

}
