#include "pch.h"
#include "Door.h"
#include "Collider.h"
#include "Player.h"
#include "GDISelector.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include <string>
#include "PlayerManager.h"
#include "Collider.h"
Door::Door()
	: _isEntering(false)
	, nextSceneName(L"")
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
	GDISelector* pPen = new GDISelector(hdc, PEN_TYPE::BLUE);
	GDISelector* pBrush = new GDISelector(hdc, BRUSH_TYPE::BLUE);
	RECT_RENDER(hdc, vPos.x, vPos.y, vSize.x, vSize.y);
	pBrush->~GDISelector();
	pPen->~GDISelector();

	ComponentRender(hdc);
}

void Door::EnterCollision(Collider* other)
{
	if (other->GetOwner()->GetName() == L"Player" && _isEntering == false)
	{
		_isEntering = true;

		Player* pPlayer = 
			dynamic_cast<Player*>(other->GetOwner());
		GET_SINGLE(ResourceManager)->Play(L"Door");
		if (NoNeedKey || pPlayer->keyCount > 0)
		{
			//MessageBox(NULL, L"abc", nextSceneName.c_str(), MB_OK);
			GET_SINGLE(PlayerManager)->SetPlayerSpawnPos(pPlayerSpawnVec2);
			GET_SINGLE(SceneManager)->LoadScene(nextSceneName);
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
	if (other->GetOwner()->GetName() == L"Player" && _isEntering == true)
	{
		_isEntering = false;
	}
}

void Door::SetNextMap(MAP_TYPE nextTileMap)
{
	switch (nextTileMap)
	{
	case MAP_TYPE::MainHole_1FScene:
		nextSceneName = L"MainHole_1FScene";
		break;
	case MAP_TYPE::MainHoleRightCorridor_1F:
		nextSceneName = L"MainHoleRightCorridor_1F";
		break;
	default:
		break;
	}
}

void Door::SetColliderSize(Vec2 newVec)
{
	GetComponent<Collider>()->SetSize(newVec);
}