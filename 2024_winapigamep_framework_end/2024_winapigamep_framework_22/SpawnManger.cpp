#include "pch.h"
#include "SpawnManger.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Enemy.h"

void SpawnManger::Spawn(Vec2 spawnPos, float spawnTime)
{
	Object* pEnemy = new Enemy;
	pEnemy->SetPos({ SCREEN_WIDTH / spawnPos.x,spawnPos.y });
	pEnemy->SetSize({ 100.f,500.f });
	pEnemy->SetName(L"Enemy");
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pEnemy, LAYER::ENEMY);
	_spawnTime = spawnTime;
	_isSpawn = true;
}

void SpawnManger::Update()
{
	if (_isSpawn)
	{
		_spawnTime -= fDT;
		if (_spawnTime <= 0)
		{
			_isSpawn = false;
			_spawnEnemy = GET_SINGLE(SceneManager)->GetCurrentScene()->GetLayerObjects(LAYER::ENEMY)[0];
			delete _spawnEnemy;
		}
	}

	//if (_isSpawn)
	//{
	//	//const vector<Object*>& vecLeftLayer = GET_SINGLE(SceneManager)->GetCurrentScene()->GetLayerObjects(LAYER::ENEMY);
	//	_spawnEnemy = GET_SINGLE(SceneManager)->GetCurrentScene()->GetLayerObjects(LAYER::ENEMY)[0];

	//}
}
