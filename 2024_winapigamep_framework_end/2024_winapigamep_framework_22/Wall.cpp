#include "pch.h"
#include "Wall.h"
#include "Collider.h"
#include "CollisionManager.h"
#include "GDISelector.h"

Wall::Wall()
{
	this->AddComponent<Collider>();
	GetComponent<Collider>()->SetSize(GetSize());
}

void Wall::Update()
{
}

void Wall::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	
	GDISelector* pBrush = new GDISelector(_hdc, BRUSH_TYPE::HOLLOW);
	GDISelector* pPen = new GDISelector(_hdc, PEN_TYPE::GREEN);
	RECT_RENDER(_hdc, vPos.x, vPos.y, vSize.x, vSize.y);
	pBrush->~GDISelector();
	pPen->~GDISelector();
	ComponentRender(_hdc);
}
