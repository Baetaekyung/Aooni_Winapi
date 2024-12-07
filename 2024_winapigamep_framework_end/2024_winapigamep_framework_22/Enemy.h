#pragma once
#include "Object.h"
#include "Player.h"
class Texture;
class EnemyWallCast;
class Enemy
	:public Object
{
public:
	Enemy();
	~Enemy();
public:
	void Update() override;
	void Move();
	void Render(HDC _hdc) override;
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
public:
	void WallDirection();
	Direction GetCurrentDirection()
	{
		return _enemeyCurrentDir;
	}
	Direction GetLastDirection()
	{
		return _wallEscapeDir;
	}
private:
	Texture* _m_pTex;
	Player* _player;
	EnemyWallCast* _wallcast;
	Direction _enemeyCurrentDir;
	Direction _wallEscapeDir;
	bool _isWallBumpInto;
	int _speed;
	//Direction _playerDir;
	wstring currentAnimation;
	std::unordered_map<Direction, wstring> animation;
	bool _isQuoinEscape;
	Vec2 blockdistance = { 20, 23 };
	float _time;
	COLORREF color;
};

