#pragma once
//#include "Enemy.h"
class Object;
class SpawnManger
{
	DECLARE_SINGLE(SpawnManger);
public:
	void Spawn(Vec2 spawnPos, float spawnTime);
	void Update();
private:
	bool _isSpawn;
	float spawnTime;
	Object* _spawnEnemy;
};

