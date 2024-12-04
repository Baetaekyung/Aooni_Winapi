#include "pch.h"
#include "Key.h"
#include "Collider.h"
#include "EventManager.h"
#include "GDISelector.h"
#include "ResourceManager.h"

Key::Key()
	:currentBrushType(BRUSH_TYPE::YELLOW)
{
	SetName(L"Key");
	this->AddComponent<Collider>();
	GetComponent<Collider>()->SetSize({ 10, 10 });
}

Key::~Key()
{
}

void Key::Update()
{
}

void Key::Render(HDC hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();

	GDISelector* pBrush = new GDISelector(hdc, currentBrushType);
	RECT_RENDER(hdc, vPos.x, vPos.y,
		vSize.x, vSize.y);
	pBrush->~GDISelector();

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
