#pragma once
#include "Object.h"
class Texture;
class Player : public Object
{
public:
	Player();
	~Player();
public:
	void Update() override;
	void Render(HDC _hdc) override;
private:
	/*void CreateProjectile();*/
	Texture* m_pTex;
	float _speed;
	float _nextMoveTime;
	float _lastMoveTime;
};

