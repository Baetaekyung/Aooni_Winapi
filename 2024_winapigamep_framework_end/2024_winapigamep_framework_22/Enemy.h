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
	void Render(HDC _hdc) override;
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
private:
	Texture* _m_pTex;
	Player* _player;
	Direction _enemeyDir;
	wstring currentAnimation;
	std::unordered_map<Direction, wstring> animation;
};

