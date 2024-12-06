#pragma once
#include "Object.h"
#include "PlayerManager.h"

#define SpawnPlayer \
	Object* pPlayer = new Player; \
	pPlayer->SetSize({ 100, 100 }); \
	pPlayer->SetPos(GET_SINGLE(PlayerManager)->GetPlayerSpwanPos()); \
	AddObject(pPlayer, LAYER::PLAYER);

class Texture;

enum class Direction
{
	NONE,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Player : public Object
{
public:
	Player();
	~Player();
public:
	void Update() override;
	void Render(HDC _hdc) override;
	void StayCollision(Collider* _other) override;
	void EnterCollision(Collider* other) override;
	void ExitCollision(Collider* other) override;
	bool DirectionChanged(Direction direction);
	Direction GetPlayerDirection();
public:
	void SetMove(bool isActive)
	{
		canMove = isActive;
	}
private:
	void Interact(Collider* other);
	void PlayerMove();
private:
	/*void CreateProjectile();*/
	Texture* m_pTex;
	float _speed;
	Direction _playerDir;
	Direction _wallEnterDirection;
	float checkblackLength = 10.f;
	float vSize = 30.f;
	Vec2 blockdistance = {15, 25};
public:
	int keyCount = 0;
private:
	bool canMove;
	bool canGoUpward;
	bool canGoDownward;
	bool canGoRightword;
	bool canGoLeftword;

//Debug
private:
	COLORREF color; // = RGB(10, 10, 10);
};

