#pragma once
#include "Object.h"
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
	bool DirectionChanged(Direction direction);
	Direction GetPlayerDirection();
private:
	void Interact(Collider* other);
	void PlayerMove();
private:
	/*void CreateProjectile();*/
	Texture* m_pTex;
	float _speed;
	Direction _playerDir;
public:
	int keyCount = 0;
};

