#pragma once
#include "Object.h"
class Texture;

enum class Direction
{
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
private:
	void Interact();
private:
	/*void CreateProjectile();*/
	Texture* m_pTex;
	float _speed;
	Direction _playerDir;

};

