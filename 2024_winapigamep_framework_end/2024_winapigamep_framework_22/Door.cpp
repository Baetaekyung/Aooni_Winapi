#include "pch.h"
#include "Door.h"
#include "Collider.h"
#include "Player.h"
#include "GDISelector.h"

Door::Door()
{
	SetName(L"Door");
	this->AddComponent<Collider>();
	GetComponent<Collider>()->SetSize({ 30, 50 });
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
	GDISelector* pBrush = new GDISelector(hdc, BRUSH_TYPE::BLUE);
	RECT_RENDER(hdc, vPos.x, vPos.y, vSize.x, vSize.y);
	pBrush->~GDISelector();

	ComponentRender(hdc);
}

void Door::EnterCollision(Collider* other)
{
	if (other->GetOwner()->GetName() == L"Player")
	{
		Player* pPlayer = 
			dynamic_cast<Player*>(other->GetOwner());
		if (pPlayer->keyCount > 0)
		{
			cout << "Scene Changed";
		}
		else
		{
			cout << "You need key!!";
		}
	}
}

void Door::StayCollision(Collider* other)
{
}

void Door::ExitCollision(Collider* other)
{
}
