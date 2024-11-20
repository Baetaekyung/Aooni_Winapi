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
	GET_SINGLE(CollisionManager)->GetInst()->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);
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
	
}

void Player::EnterCollision(Collider* other)
{
	Interact(other);
	if (other->GetOwner()->GetName() == L"Enemy")
	{
		SetDead();
		//GameOverScene Load
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
		//Getkey
		keyCount++;
		cout << keyCount << '\n';
	}
	if (other->GetOwner()->GetName() == L"Door")
	{
		//Scene Change
	}
}

void Player::PlayerMove()
{
	Vec2 vPos = GetPos();
	Vec2 colliderSize = GetComponent<Collider>()->GetSize();

	if (GET_KEY(KEY_TYPE::A))
	{
		vPos.x -= 100.f * fDT * _speed;
		if (_playerDir != Direction::LEFT)
		{
			GetComponent<Animator>()->StopAnimation();
			GetComponent<Animator>()->PlayAnimation(L"HiroshiLeft", true);
			DirectionChanged(Direction::LEFT);
		}
	}
	else if (GET_KEY(KEY_TYPE::D))
	{
		vPos.x += 100.f * fDT * _speed;
		if (_playerDir != Direction::RIGHT)
		{
			GetComponent<Animator>()->StopAnimation();
			GetComponent<Animator>()->PlayAnimation(L"HiroshiRight", true);
			DirectionChanged(Direction::RIGHT);
		}
	}
	else if (GET_KEY(KEY_TYPE::S))
	{
		vPos.y += 100.f * fDT * _speed;
		if (_playerDir != Direction::DOWN)
		{
			GetComponent<Animator>()->StopAnimation();
			GetComponent<Animator>()->PlayAnimation(L"HiroshiDown", true);
			DirectionChanged(Direction::DOWN);
		}
	}
	else if (GET_KEY(KEY_TYPE::W))
	{
		vPos.y -= 100.f * fDT * _speed;
		if (_playerDir != Direction::UP)
		{
			GetComponent<Animator>()->StopAnimation();
			GetComponent<Animator>()->PlayAnimation(L"HiroshiUp", true);
			DirectionChanged(Direction::UP);
		}
	}
	else
	{
		switch (_playerDir)
		{
		case Direction::NONE:
			break;
		case Direction::LEFT:
			GetComponent<Animator>()->StopAnimation();
			GetComponent<Animator>()->PlayAnimation(L"HiroshiLeftIdle", true);
			_playerDir = Direction::NONE;
			break;
		case Direction::RIGHT:
			GetComponent<Animator>()->StopAnimation();
			GetComponent<Animator>()->PlayAnimation(L"HiroshiRightIdle", true);
			_playerDir = Direction::NONE;
			break;
		case Direction::UP:
			GetComponent<Animator>()->StopAnimation();
			GetComponent<Animator>()->PlayAnimation(L"HiroshiUpIdle", true);
			_playerDir = Direction::NONE;
			break;
		case Direction::DOWN:
			GetComponent<Animator>()->StopAnimation();
			GetComponent<Animator>()->PlayAnimation(L"HiroshiDownIdle", true);
			_playerDir = Direction::NONE;
			break;
		default:
			break;
		}
	}
	SetPos(vPos);
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
