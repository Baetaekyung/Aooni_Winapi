#include "pch.h"
#include "Door.h"
#include "Collider.h"

Door::~Door()
{
	SetName(L"Door");
	this->AddComponent<Collider>();
	GetComponent<Collider>()->SetSize({ 20, 50 });
}

void Door::Update()
{
}

void Door::Render(HDC hdc)
{
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