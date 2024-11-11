#include "pch.h"
#include "Enemy.h"
#include "Collider.h"
#include "EventManager.h"

Enemy::Enemy()
{
	this->AddComponent<Collider>();
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
}

void Enemy::Render(HDC _hdc)
{	
	//HBRUSH brush = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
	//HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	RECT_RENDER(_hdc, vPos.x, vPos.y
		, vSize.x, vSize.y);
	ComponentRender(_hdc);
	//SelectObject(_hdc, oldbrush); 
	//DeleteObject(brush);
}

void Enemy::EnterCollision(Collider* _other)
{
	std::cout << "Enter" << std::endl;
	Object* pOtherObj = _other->GetOwner();
	if (pOtherObj->GetName() == L"Player")
	{
			GET_SINGLE(EventManager)->DeleteObject(pOtherObj);
	}
}

void Enemy::StayCollision(Collider* _other)
{
	//std::cout << "Stay" << std::endl;
}

void Enemy::ExitCollision(Collider* _other)
{
	std::cout << "Exit" << std::endl;
}
