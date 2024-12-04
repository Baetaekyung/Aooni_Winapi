#pragma once
#include "Object.h"
class Texture;

static int g_playerkeyCount = 0;

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
private:
	bool canMove;
	bool canGoUpward;
	bool canGoDownward;
	bool canGoRightword;
	bool canGoLeftword;
};

