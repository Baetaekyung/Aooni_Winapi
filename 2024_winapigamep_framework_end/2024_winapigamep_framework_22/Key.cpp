#include "pch.h"
#include "Key.h"
#include "SceneManager.h"
#include "Collider.h"
#include "CollisionManager.h"
#include "EventManager.h"

Key::Key()
{
	SetName(L"Key");
	this->AddComponent<Collider>();
	GetComponent<Collider>()->SetSize({ 20, 20 });
}

Key::~Key()
{
	GET_SINGLE(CollisionManager)->GetInst()->CheckReset();
}

void Key::Update()
{
}

void Key::Render(HDC hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	RECT_RENDER(hdc, vPos.x, vPos.y,
		vSize.x, vSize.y);
	ComponentRender(hdc);
}

void Key::EnterCollision(Collider* other)
{
	if (other->GetOwner()->GetName() == L"Player")
	{
		GET_SINGLE(EventManager)->DeleteObject(this);
	}
}

void Key::StayCollision(Collider* other)
{
}

void Key::ExitCollision(Collider* other)
{
}
