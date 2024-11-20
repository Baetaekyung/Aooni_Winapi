#include "pch.h"
#include "Enemy.h"
#include "Collider.h"
#include "EventManager.h"
#include "ResourceManager.h"
#include "TimeManager.h"
#include "Texture.h"
#include "Animator.h"
#include "SceneManager.h"
#include "Scene.h"

Enemy::Enemy()
{
	this->AddComponent<Collider>();
	_m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"aooni", L"Texture\\Aooni.bmp");
	AddComponent<Animator>();
	GetComponent<Animator>()->CreateAnimation(L"JiwooFront", _m_pTex, Vec2(0.f, 0.f),
		Vec2(64.f, 128.f), Vec2(64.f, 0.f), 4, 0.1f);
	GetComponent<Animator>()->CreateAnimation(L"JiwooLeft", _m_pTex, Vec2(0.f, 128.f),
		Vec2(64.f, 128.f), Vec2(64.f, 0.f), 4, 0.1f);
	GetComponent<Animator>()->CreateAnimation(L"JiwooRight", _m_pTex, Vec2(0.f, 256.f),
		Vec2(64.f, 128.f), Vec2(64.f, 0.f), 4, 0.1f);
	GetComponent<Animator>()->CreateAnimation(L"JiwooBack", _m_pTex, Vec2(0.f, 384.f),
		Vec2(64.f, 128.f), Vec2(64.f, 0.f), 4, 0.1f);

	animation[Direction::DOWN] = L"JiwooFront";
	animation[Direction::UP] = L"JiwooBack";
	animation[Direction::RIGHT] = L"JiwooRight";
	animation[Direction::LEFT] = L"JiwooLeft";

	GetComponent<Animator>()->PlayAnimation(L"JiwooFront", true);
	currentAnimation = L"JiwooFront";

	//std::shared_ptr<Scene> pCurrentScene = GET_SINGLE(SceneManager)->GetCurrentScene();
	//const vector<Object*>& vecLeftLayer = pCurrentScene->GetLayerObjects(_left);
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	std::shared_ptr<Scene> pCurrentScene = GET_SINGLE(SceneManager)->GetCurrentScene();
	const vector<Object*>& playerVec = pCurrentScene->GetLayerObjects(LAYER::PLAYER);
	_player = dynamic_cast<Player*>(playerVec[0]);

	Vec2 vPos = GetPos();
	Vec2 playerPos = _player->GetPos();
	int speed = 120;
	
	if (abs(playerPos.y - vPos.y) < 4)
	{
		if (playerPos.x > vPos.x)
		{
			vPos.x += speed * fDT;
			_enemeyDir = Direction::RIGHT;
		}
		else if (playerPos.x < vPos.x)
		{
			vPos.x -= speed * fDT;
			_enemeyDir = Direction::LEFT;
		}
	}
	else
	{
		if (playerPos.y < vPos.y)
		{
			vPos.y -= speed * fDT;
			_enemeyDir = Direction::UP;

		}
		else if (playerPos.y > vPos.y)
		{
			vPos.y += speed * fDT;
			_enemeyDir = Direction::DOWN;
		}
	}

	
	//cout << _player->GetPos().x << endl;
	

	if (currentAnimation != animation[_enemeyDir])
	{
		GetComponent<Animator>()->StopAnimation();

		GetComponent<Animator>()->PlayAnimation(animation[_enemeyDir], true);
		currentAnimation = animation[_enemeyDir];
	}

	SetPos(vPos);

}

void Enemy::Render(HDC _hdc)
{	
	//HBRUSH brush = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
	//HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();

	int width = _m_pTex->GetWidth();
	int height = _m_pTex->GetHeight();

	/*RECT_RENDER(_hdc, vPos.x, vPos.y
		, vSize.x, vSize.y);*/
	ComponentRender(_hdc);
	//SelectObject(_hdc, oldbrush); 
	//DeleteObject(brush);
}

void Enemy::EnterCollision(Collider* _other)
{
	std::cout << "Enter" << std::endl;
	Object* pOtherObj = _other->GetOwner();
	if (pOtherObj->GetName() == L"Player")
	{
			GET_SINGLE(EventManager)->DeleteObject(pOtherObj);
	}
}

void Enemy::StayCollision(Collider* _other)
{
	//std::cout << "Stay" << std::endl;
}

void Enemy::ExitCollision(Collider* _other)
{
	std::cout << "Exit" << std::endl;
}
