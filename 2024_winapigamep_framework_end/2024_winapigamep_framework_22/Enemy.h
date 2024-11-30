#pragma once
#include "Object.h"
#include "Player.h"
class Texture;
class Enemy :
    public Object
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
private:

private:
	Texture* _m_pTex;
	Player* _player;
	Object* _listCollistionObj;
	Direction _enemeyCurrentDir;
	Direction _enemeyLastDir;
	bool _isWallBumpInto;
	bool _isEnter;
	int _speed;
	//Direction _playerDir;
	wstring currentAnimation;
	std::unordered_map<Direction, wstring> animation;
};

