#pragma once
//#include "Enemy.h"
class Object;
class SpawnManger
{
	DECLARE_SINGLE(SpawnManger);
public:
	void Spawn(Vec2 spawnPos, int spawnCnt);
	void Update();
	void SpawnCntDown();
	void SpawnStop() { _isSpawnStop = true; }
private:
	bool _isSpawnStop;
	bool _isSpawn;
	int _spawnCnt;
	float _time;
	Vec2 _spawnPos;
	Object* _spawnEnemy;
};

