#include "pch.h"
#include "Enemy.h"
#include "Collider.h"
#include "TextUI.h"
#include "EventManager.h"
#include "ResourceManager.h"
#include "TimeManager.h"
#include "Texture.h"
#include "Animator.h"
#include "SceneManager.h"
#include "EnemyWallCast.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "Scene.h"
#include "Core.h"

Enemy::Enemy()
	:_speed(1.5)
	, _enemeyCurrentDir(Direction::DOWN)
	, _wallEscapeDir(Direction::RIGHT)
{
	

	this->AddComponent<Collider>();
	this->AddComponent<TextUI>();
	GetComponent<Collider>()->SetSize(Vec2(35.f, 40.f));
	GetComponent<Collider>()->SetOffSetPos(Vec2(0.f, 35.f));

	_m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"aooni", L"Texture\\Aooni.bmp");
	AddComponent<Animator>();
	GetComponent<Animator>()->CreateAnimation(L"AooniFront", _m_pTex, Vec2(0.f, 0.f),
		Vec2(64.f, 128.f), Vec2(64.f, 0.f), 4, 0.1f);
	GetComponent<Animator>()->CreateAnimation(L"AooniLeft", _m_pTex, Vec2(0.f, 128.f),
		Vec2(64.f, 128.f), Vec2(64.f, 0.f), 4, 0.1f);
	GetComponent<Animator>()->CreateAnimation(L"AooniRight", _m_pTex, Vec2(0.f, 256.f),
		Vec2(64.f, 128.f), Vec2(64.f, 0.f), 4, 0.1f);
	GetComponent<Animator>()->CreateAnimation(L"AooniBack", _m_pTex, Vec2(0.f, 384.f),
		Vec2(64.f, 128.f), Vec2(64.f, 0.f), 4, 0.1f);

	animation[Direction::DOWN] = L"AooniFront";
	animation[Direction::UP] = L"AooniBack";
	animation[Direction::RIGHT] = L"AooniRight";
	animation[Direction::LEFT] = L"AooniLeft";

	GetComponent<Animator>()->PlayAnimation(L"AooniFront", true);
	currentAnimation = L"AooniFront";
	std::shared_ptr<Scene> pCurrentScene = GET_SINGLE(SceneManager)->GetCurrentScene();
	const vector<Object*>& playerVec = pCurrentScene->GetLayerObjects(LAYER::PLAYER);
	if (playerVec.size() > 0)
		_player = dynamic_cast<Player*>(playerVec[0]);
	GET_SINGLE(CollisionManager)->GetInst()->CheckLayer(LAYER::ENEMYCAST, LAYER::INTERACTABLE);
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	if (_wallcast == nullptr)
	{
		std::shared_ptr<Scene> pCurrentScene = GET_SINGLE(SceneManager)->GetCurrentScene();
		const vector<Object*>& castVec = pCurrentScene->GetLayerObjects(LAYER::ENEMYCAST);
		if (castVec.size() > 0)
			_wallcast = dynamic_cast<EnemyWallCast*>(castVec[0]);
		else
			return;
	}

	if (_wallcast->GetWallCast())
	{
		Vec2 vPos = GetPos();
		switch (_wallEscapeDir)
		{
		case Direction::LEFT:
			vPos.x -= 100 * _speed * fDT;
			break;
		case Direction::RIGHT:
			vPos.x += 100 * _speed * fDT;
			break;
		case Direction::UP:
			vPos.y -= 100 * _speed * fDT;
			break;
		case Direction::DOWN:
			vPos.y += 100 * _speed * fDT;
			break;
		}


		if (currentAnimation != animation[_wallEscapeDir])
		{
			GetComponent<Animator>()->StopAnimation();
			GetComponent<Animator>()->PlayAnimation(animation[_wallEscapeDir], true);
			currentAnimation = animation[_wallEscapeDir];
		}
			SetPos(vPos);

	}
	else if (_isQuoinEscape)
	{
		HDC hdc = GET_SINGLE(Core)->GetMainDC();
		Vec2 vPos = GetPos();
		Vec2 playerPos = _player->GetPos();

		if (_time >= 1.5f)
		{
			_isQuoinEscape = false;
			_time = 0;
		}
		else
			_time += fDT;

		switch (_wallEscapeDir)
		{
		case Direction::LEFT:
			color = GetPixel(hdc, vPos.x - blockdistance.x, vPos.y + 40);
			vPos.x -= 100 * _speed * fDT;
			break;
		case Direction::RIGHT:
			color = GetPixel(hdc, vPos.x + blockdistance.x, vPos.y + 40);
			vPos.x += 100 * _speed * fDT;
			break;
		case Direction::UP:
			color = GetPixel(hdc, vPos.x, vPos.y + 40 - blockdistance.y);
			vPos.y -= 100 * _speed * fDT;
			break;
		case Direction::DOWN:
			color = GetPixel(hdc, vPos.x, vPos.y + 40 + blockdistance.y);
			vPos.y += 100 * _speed * fDT;
			break;
		}


		if (currentAnimation != animation[_wallEscapeDir])
		{
			GetComponent<Animator>()->StopAnimation();
			GetComponent<Animator>()->PlayAnimation(animation[_wallEscapeDir], true);
			currentAnimation = animation[_wallEscapeDir];
		}

		if (!IsBlockedByColor(color))
		{
			SetPos(vPos);
		}
		else
		{
			WallDirection();
			cout << 1 << endl;
		}
	}
	else
		Move();
}


void Enemy::Move()
{
	bool isPlayer = _player != nullptr;
	HDC hdc = GET_SINGLE(Core)->GetMainDC();
	if (!isPlayer)
		return;

	Vec2 vPos = GetPos();
	Vec2 playerPos = _player->GetPos();
	if (abs(playerPos.x - vPos.x) > 10.f)
	{
		if (playerPos.x > vPos.x)
		{
			color = GetPixel(hdc, vPos.x + blockdistance.x, vPos.y + 40);
			vPos.x += 100 * _speed * fDT;
			_enemeyCurrentDir = Direction::RIGHT;
		}
		else if (playerPos.x < vPos.x)
		{
			color = GetPixel(hdc, vPos.x - blockdistance.x, vPos.y + 40);
			vPos.x -= 100 * _speed * fDT;
			_enemeyCurrentDir = Direction::LEFT;
		}
	}
	else if (abs((vPos.y + 40) - playerPos.y) > 40.f)
	{
		if (playerPos.y < (vPos.y + 40))
		{
			color = GetPixel(hdc, vPos.x , vPos.y + 40 - blockdistance.y);

			vPos.y -= 100 * _speed * fDT;
			_enemeyCurrentDir = Direction::UP;
		}
		if (playerPos.y > (vPos.y + 40))
		{
			color = GetPixel(hdc, vPos.x , vPos.y + 40 + blockdistance.y);
			vPos.y += 100 * _speed * fDT;
			_enemeyCurrentDir = Direction::DOWN;
		}
	}

	if (currentAnimation != animation[_enemeyCurrentDir])
	{
		GetComponent<Animator>()->StopAnimation();
		GetComponent<Animator>()->PlayAnimation(animation[_enemeyCurrentDir], true);
		currentAnimation = animation[_enemeyCurrentDir];
	}

	if (!IsBlockedByColor(color))
	{
		SetPos(vPos);
	}
	else
	{
		WallDirection();
		_isQuoinEscape = true;
	}

	//DeleteDC(_hdc);
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
	//cout << "EenmyEnter" << endl;

}


void Enemy::StayCollision(Collider* _other)
{

}

void Enemy::ExitCollision(Collider* _other)
{
	//cout << "EenmyExit" << endl;
}

void Enemy::WallDirection()
{

	Vec2 vPos = GetPos();
	Vec2 playerPos = _player->GetPos();

	if (_wallcast->GetWallCast())
	{
		switch (_wallEscapeDir)
		{
		case Direction::LEFT:
		case Direction::RIGHT:
			if (_player->GetPos().y <= (vPos.y + 40))
			{
				_wallEscapeDir = Direction::UP;

			}
			else
			{
				_wallEscapeDir = Direction::DOWN;

			}
			break;
		case Direction::UP:
		case Direction::DOWN:
			if (_player->GetPos().x >= vPos.x)
			{
				_wallEscapeDir = Direction::RIGHT;
			}
			else
			{
				_wallEscapeDir = Direction::LEFT;
			}
			break;
		}
	}
	else
	{
		switch (_enemeyCurrentDir)
		{
		case Direction::LEFT:
		case Direction::RIGHT:
			if (_player->GetPos().y <= (vPos.y + 40))
			{
				_wallEscapeDir = Direction::UP;

			}
			else
			{
				_wallEscapeDir = Direction::DOWN;

			}
			break;
		case Direction::UP:
		case Direction::DOWN:
			if (_player->GetPos().x >= vPos.x)
			{
				_wallEscapeDir = Direction::RIGHT;
			}
			else
			{
				_wallEscapeDir = Direction::LEFT;
			}
			break;
		}
		//_wallListDir = _enemeyLastDir;
	}

	

}
