#include "pch.h"
#include "Player.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Projectile.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "CollisionManager.h"
#include "EventManager.h"

Player::Player()
	: m_pTex(nullptr)
	, _speed(1.5)
	, _playerDir(Direction::DOWN)
	, keyCount(0)
	, canGoUpward(true)
	, canGoDownward(true)
	, canGoLeftword(true)
	, canGoRightword(true)
	, canMove(true)
{
	SetName(L"Player");

	#pragma region Animation Init
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Hiroshi", L"Texture\\Hiroshi.bmp");
	this->AddComponent<Collider>();

	AddComponent<Animator>();
	GetComponent<Animator>()->CreateAnimation(L"HiroshiUpIdle", m_pTex, Vec2(0.f, 144.f),
		Vec2(32.f, 48.f), Vec2(32.f, 0.f), 1, 0.1f);
	GetComponent<Animator>()->CreateAnimation(L"HiroshiUp", m_pTex, Vec2(0.f, 144.f),
		Vec2(32.f, 48.f), Vec2(32.f, 0.f), 4, 0.1f);

	GetComponent<Animator>()->CreateAnimation(L"HiroshiDownIdle", m_pTex, Vec2(0.f, 0.f),
		Vec2(32.f, 48.f), Vec2(32.f, 0.f), 1, 0.1f);
	GetComponent<Animator>()->CreateAnimation(L"HiroshiDown", m_pTex, Vec2(0.f, 0.f),
		Vec2(32.f, 48.f), Vec2(32.f, 0.f), 4, 0.1f);

	GetComponent<Animator>()->CreateAnimation(L"HiroshiRightIdle", m_pTex, Vec2(0.f, 96.f),
		Vec2(32.f, 48.f), Vec2(32.f, 0.f), 1, 0.1f);
	GetComponent<Animator>()->CreateAnimation(L"HiroshiRight", m_pTex, Vec2(0.f, 96.f),
		Vec2(32.f, 48.f), Vec2(32.f, 0.f), 4, 0.1f);

	GetComponent<Animator>()->CreateAnimation(L"HiroshiLeftIdle", m_pTex, Vec2(0.f, 48.f),
		Vec2(32.f, 48.f), Vec2(32.f, 0.f), 1, 0.1f);
	GetComponent<Animator>()->CreateAnimation(L"HiroshiLeft", m_pTex, Vec2(0.f, 48.f),
		Vec2(32.f, 48.f), Vec2(32.f, 0.f), 4, 0.1f);

	GetComponent<Animator>()->PlayAnimation(L"HiroshiDownIdle", true);
#pragma endregion
	//Collision Check
	GET_SINGLE(CollisionManager)->GetInst()->CheckLayer(LAYER::PLAYER, LAYER::INTERACTABLE);
}

Player::~Player()
{

}
void Player::Update()
{
	PlayerMove();

	/*if (GET_KEYDOWN(KEY_TYPE::SPACE))
		CreateProjectile();*/
}

void Player::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	
	int width = m_pTex->GetWidth();
	int height = m_pTex->GetHeight();
	
	ComponentRender(_hdc);
}

void Player::StayCollision(Collider* _other)
{
	if (_other->GetOwner()->GetName() == L"Wall")
	{
		if (GetPlayerDirection() == Direction::LEFT)
		{
			canGoLeftword = false;
		}
		if (GetPlayerDirection() == Direction::RIGHT)
		{
			canGoRightword = false;
		}
		if (GetPlayerDirection() == Direction::UP)
		{
			canGoUpward = false;
		}
		if (GetPlayerDirection() == Direction::DOWN)
		{
			canGoDownward = false;
		}
	}
}

void Player::EnterCollision(Collider* other)
{
	Interact(other);
	if (other->GetOwner()->GetName() == L"Enemy")
	{
		SetDead();
		//GameOverScene Load
	}
	if (other->GetOwner()->GetName() == L"Wall")
	{
		if (GetPlayerDirection() == Direction::LEFT)
		{
			canGoLeftword = false;
		}
		if (GetPlayerDirection() == Direction::RIGHT)
		{
			canGoRightword = false;
		}
		if (GetPlayerDirection() == Direction::UP)
		{
			canGoUpward = false;
		}
		if (GetPlayerDirection() == Direction::DOWN)
		{
			canGoDownward = false;
		}
	}
}

void Player::ExitCollision(Collider* other)
{
	if (other->GetOwner()->GetName() == L"Wall")
	{
		canGoDownward = true;
		canGoLeftword = true;
		canGoRightword = true;
		canGoUpward = true;
	}
}

bool Player::DirectionChanged(Direction direction)
{
	if (_playerDir != direction)
	{
		_playerDir = direction;
		return true;
	}
}

Direction Player::GetPlayerDirection()
{
	return _playerDir;
}

void Player::Interact(Collider* other)
{
	if (other->GetOwner()->GetName() == L"Key")
	{
		GET_SINGLE(ResourceManager)->Play(L"GetKey");
		keyCount++;
		cout << keyCount << '\n';
	}
	if (other->GetOwner()->GetName() == L"Door")
	{
		//Scene Change
	}
}

#include <windows.h>

void Player::PlayerMove()
{
	Vec2 vPos = GetPos();

	if (!canMove) return;

	// HDC 가져오기 (현재 화면)
	HDC hdcScreen = GetDC(nullptr); // 전체 화면의 HDC

	if (GET_KEY(KEY_TYPE::A)) // 왼쪽 이동
	{
		int newX = static_cast<int>(vPos.x - 100.f * fDT * _speed);
		int newY = static_cast<int>(vPos.y);

		COLORREF color = GetPixel(hdcScreen, newX, newY); // 해당 좌표의 색상 가져오기
		if (IsBlockedByColor(color))
		{
			canGoLeftword = false;
		}
		else
		{
			canGoLeftword = true;
			vPos.x -= 100.f * fDT * _speed;
		}
	}
	else if (GET_KEY(KEY_TYPE::D)) // 오른쪽 이동
	{
		int newX = static_cast<int>(vPos.x + 100.f * fDT * _speed);
		int newY = static_cast<int>(vPos.y);

		COLORREF color = GetPixel(hdcScreen, newX, newY);
		if (IsBlockedByColor(color))
		{
			canGoRightword = false;
		}
		else
		{
			canGoRightword = true;
			vPos.x += 100.f * fDT * _speed;
		}
	}
	else if (GET_KEY(KEY_TYPE::W)) // 위쪽 이동
	{
		int newX = static_cast<int>(vPos.x);
		int newY = static_cast<int>(vPos.y - 100.f * fDT * _speed);

		COLORREF color = GetPixel(hdcScreen, newX, newY);
		if (IsBlockedByColor(color))
		{
			canGoUpward = false;
		}
		else
		{
			canGoUpward = true;
			vPos.y -= 100.f * fDT * _speed;
		}
	}
	else if (GET_KEY(KEY_TYPE::S)) // 아래쪽 이동
	{
		int newX = static_cast<int>(vPos.x);
		int newY = static_cast<int>(vPos.y + 100.f * fDT * _speed);

		COLORREF color = GetPixel(hdcScreen, newX, newY);
		if (IsBlockedByColor(color))
		{
			canGoDownward = false;
		}
		else
		{
			canGoDownward = true;
			vPos.y += 100.f * fDT * _speed;
		}
	}

	// HDC 해제
	ReleaseDC(nullptr, hdcScreen);

	SetPos(vPos);
}

bool Player::IsBlockedByColor(COLORREF color)
{
	// 검정색 여부 확인 (RGB 0, 0, 0)
	return (GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 0);
}



//void Player::CreateProjectile()
//{
//	Projectile* pProj = new Projectile;
//	Vec2 vPos = GetPos();
//	vPos.y -= GetSize().y / 2.f;
//	pProj->SetPos(vPos);
//	pProj->SetSize({30.f,30.f});
//	pProj->SetDir({0.f, -1.f});
//	pProj->SetName(L"PlayerBullet");
//
//	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(pProj, LAYER::PROJECTILE);
//}
