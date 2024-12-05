#pragma once
#include "Object.h"
class Enemy;
class EnemyWallCast
	:public Object
{
public:
	EnemyWallCast();
	~EnemyWallCast();
public:
	void Update() override;
	void Render(HDC _hdc) override;
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
	const bool& GetWallCast() const { return _isWallCast; }
private:
	bool _isWallCast;
	Enemy* _owner;
	Vec2 blockdistance = { 5, 10 };
	COLORREF color; // = RGB(10, 10, 10);
	Vec2 pos;
};

