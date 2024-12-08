#include "pch.h"
#include "Trigger.h"
#include "Collider.h"
#include "Player.h"
#include "GDISelector.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include <string>
#include "PlayerManager.h"
#include "Collider.h"
#include "TextBoxObject.h"
#include "SceneManager.h"
#include "Scene.h"
Trigger::Trigger()
	: _isEntering(false)
	, nextSceneName(L"")
	, needKeyType(KEY_TYPE::None)
	, MyTextType(TEXT_TYPE::Scare)
{
	SetName(L"Door");
	this->AddComponent<Collider>();
	GetComponent<Collider>()->SetSize({ 30, 50 });
}

Trigger::~Trigger()
{
}

void Trigger::Update()
{
}

void Trigger::Render(HDC hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	//PEN_TYPE ePen = PEN_TYPE::BLUE;
	//PEN_TYPE eBrush = PEN_TYPE::BLUE;
	//GDISelector* pPen = new GDISelector(hdc, ePen);
	//GDISelector* pBrush = new GDISelector(hdc, eBrush);
	RECT_RENDER(hdc, vPos.x, vPos.y, vSize.x, vSize.y);
	//pBrush->~GDISelector();
	//pPen->~GDISelector();

	//DeleteObject(pPen);
	//DeleteObject(pBrush);

	ComponentRender(hdc);
}

void Trigger::EnterCollision(Collider* other)
{
	if (other->GetOwner()->GetName() == L"Player" && _isEntering == false)
	{
		_isEntering = true;

		Player* pPlayer = 
			dynamic_cast<Player*>(other->GetOwner());
		GET_SINGLE(ResourceManager)->Play(L"Door");
		if (GetName() != L"Wall"
			&& GET_SINGLE(PlayerManager)->GetPlayerKey(needKeyType)) {
			//MessageBox(NULL, L"abc", nextSceneName.c_str(), MB_OK);
			if (GET_SINGLE(PlayerManager)->MissingScene && MyTextType == TEXT_TYPE::Guys) {
				GET_SINGLE(PlayerManager)->SetPlayerSpawnPos(pPlayerSpawnVec2);
				UpText();
				GET_SINGLE(PlayerManager)->MissingScene = false;
			}
			GET_SINGLE(SceneManager)->LoadScene(nextSceneName);
		}
		else
		{
			pPlayer->keyCount--;
			cout << "You need key!!";
		}
	}
}

void Trigger::StayCollision(Collider* other)
{
}

void Trigger::ExitCollision(Collider* other)
{
	if (other->GetOwner()->GetName() == L"Player" && _isEntering == true)
	{
		_isEntering = false;
	}
}

void Trigger::SetNextMap(MAP_TYPE nextTileMap)
{
	switch (nextTileMap)
	{
	case MAP_TYPE::MainHole_1FScene:
		nextSceneName = L"MainHole_1FScene";
		break;
	case MAP_TYPE::MainHoleRightCorridor_1F: {
		nextSceneName = L"MainHoleRightCorridor_1F";
		break;
	}
	case MAP_TYPE::Kitchen_1F:
		nextSceneName = L"Kitchen_1FScene";
		break;
	case MAP_TYPE::LeftCorridor_1FScene:
		nextSceneName = L"LeftCorridor_1FScene";
		break;
	default:
		break;
	}
}

void Trigger::SetColliderSize(Vec2 newVec) {
	GetComponent<Collider>()->SetSize(newVec);
}

void Trigger::UpText()
{
	SpawnTextBox(MyTextType);
}
