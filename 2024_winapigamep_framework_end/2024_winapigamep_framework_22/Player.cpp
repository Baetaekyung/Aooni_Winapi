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
Player::Player()
	: m_pTex(nullptr)
	, _speed(1.5)
	, _nextMoveTime(0.1f)
	, _lastMoveTime(0)
{
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Jiwoo", L"Texture\\jiwoo.bmp");
	this->AddComponent<Collider>();
	AddComponent<Animator>();
	GetComponent<Animator>()->CreateAnimation(L"JiwooFront", m_pTex, Vec2(0.f, 150.f),
		Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.1f);
	GetComponent<Animator>()->PlayAnimation(L"JiwooFront", true);
}
Player::~Player()
{
	
}
void Player::Update()
{
	Vec2 vPos = GetPos();
	
	//if(GET_KEY(KEY_TYPE::LEFT))
	if (GET_KEY(KEY_TYPE::A))
		vPos.x -= 100.f * fDT * _speed;
	else if (GET_KEY(KEY_TYPE::D))
		vPos.x += 100.f * fDT * _speed;
	else if (GET_KEY(KEY_TYPE::S))
		vPos.y += 100.f * fDT * _speed;
	else if (GET_KEY(KEY_TYPE::W))
		vPos.y -= 100.f * fDT * _speed;

	/*if (GET_KEYDOWN(KEY_TYPE::SPACE))
		CreateProjectile();*/
	SetPos(vPos);
}

void Player::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	
	int width = m_pTex->GetWidth();
	int height = m_pTex->GetHeight();
	
	ComponentRender(_hdc);
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
