#include "pch.h"
#include "Door.h"
#include "Collider.h"

Door::Door()
{
	SetName(L"Door");
	this->AddComponent<Collider>();
	GetComponent<Collider>()->SetSize({ 20, 50 });
}

Door::~Door()
{
}

void Door::Update()
{
}

void Door::Render(HDC hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	RECT_RENDER(hdc, vPos.x, vPos.y, vSize)
}

void Door::EnterCollision(Collider* other)
{
}

void Door::StayCollision(Collider* other)
{
}

void Door::ExitCollision(Collider* other)
{
}
