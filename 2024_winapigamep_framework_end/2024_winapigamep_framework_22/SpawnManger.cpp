#include "pch.h"
#include "SpawnManger.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Enemy.h"
#include "EnemyWallCast.h"

void SpawnManger::Spawn(Vec2 spawnPos, int spawnCnt)
{
	//cout << 1 << endl;
	Object* pEnemy = new Enemy;
	pEnemy->SetPos({ SCREEN_WIDTH / spawnPos.x,spawnPos.y });
	pEnemy->SetSize({ 100.f,500.f });
	pEnemy->SetName(L"Enemy");
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pEnemy, LAYER::ENEMY);

	Object* pEnemyCast = new EnemyWallCast;
	pEnemyCast->SetPos({ SCREEN_WIDTH / spawnPos.x,spawnPos.y });
	pEnemyCast->SetSize({ 100.f,500.f });
	pEnemyCast->SetName(L"EnemyCast");
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pEnemyCast, LAYER::ENEMYCAST);
	_spawnCnt = spawnCnt;
}

void SpawnManger::Update()
{
	if (_spawnCnt > 0
		&& GET_SINGLE(SceneManager)->GetCurrentScene()->GetLayerObjects(LAYER::ENEMY).size() < 0
		&& !_isSpawn)
	{
		_isSpawn = true;
		_spawnPos = GET_SINGLE(SceneManager)->GetCurrentScene()->GetLayerObjects(LAYER::PLAYER)[0]->GetPos();
	}

	if (_isSpawn)
	{
		_time += fDT;
		if (_time > 1)
		{
			cout << GET_SINGLE(SceneManager)->GetCurrentScene()->GetLayerObjects(LAYER::ENEMY).size() << endl;

			_time = 0;
			_isSpawn = false;
			Spawn(_spawnPos,_spawnCnt);
		}
	}
}

void SpawnManger::SpawnCntDown()
{
	_spawnCnt--;
}
