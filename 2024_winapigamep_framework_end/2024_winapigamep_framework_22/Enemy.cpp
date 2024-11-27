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
	:_speed(1.2)
	, _enemeyCurrentDir(Direction::DOWN)
	, _enemeyLastDir(Direction::RIGHT)
{
	

	this->AddComponent<Collider>();
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

	//std::shared_ptr<Scene> pCurrentScene = GET_SINGLE(SceneManager)->GetCurrentScene();
	//const vector<Object*>& vecLeftLayer = pCurrentScene->GetLayerObjects(_left);
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	return;
	if (_isWallBumpInto)
		return;

	if (_isWallBumpInto)
	{
		Vec2 vPos = GetPos();
		Vec2 playerPos = _player->GetPos();
		/*switch (_enemeyLastDir)
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
		default:
			break;
		}*/

		switch (_enemeyCurrentDir)
		{
		case Direction::LEFT:
		case Direction::RIGHT:
			if (abs((vPos.y + 40) - playerPos.y) > 1.f)
			{
				//cout << vPos.y << endl;
				//cout << playerPos.y << endl;
				if (playerPos.y < (vPos.y + 40))
				{
					vPos.y -= 100 * _speed * fDT;
					_enemeyCurrentDir = Direction::UP;
				}
				if (playerPos.y > (vPos.y + 40))
				{
					vPos.y += 100 * _speed * fDT;
					_enemeyCurrentDir = Direction::DOWN;
				}
			}
			break;
		case Direction::UP:
		case Direction::DOWN:
			if (abs(playerPos.x - vPos.x) > 0.1f)
			{
				if (playerPos.x > vPos.x)
				{
					vPos.x += 100 * _speed * fDT;
					_enemeyCurrentDir = Direction::RIGHT;
				}
				else if (playerPos.x < vPos.x)
				{
					vPos.x -= 100 * _speed * fDT;
					_enemeyCurrentDir = Direction::LEFT;
				}
			}
			break;
		default:
			break;
		}

		if (currentAnimation != animation[_enemeyLastDir])
		{
			GetComponent<Animator>()->StopAnimation();

			GetComponent<Animator>()->PlayAnimation(animation[_enemeyLastDir], true);
			currentAnimation = animation[_enemeyLastDir];
		}

		//SetPos(vPos);
	}
	else
		Move();
}


void Enemy::Move()
{
	bool isPlayer = _player != nullptr;

	if (!isPlayer)
		return;

	Vec2 vPos = GetPos();
	Vec2 playerPos = _player->GetPos();
	_enemeyLastDir = _enemeyCurrentDir;

	//if (abs((vPos.y -20) - (playerPos.y -10)) > 0.1f)
	if (abs((vPos.y +40) - playerPos.y ) > 2.f)
	{
		//cout << vPos.y << endl;
		//cout << playerPos.y << endl;
		if (playerPos.y < (vPos.y + 40))
		{
			vPos.y -= 100 * _speed * fDT;
			_enemeyCurrentDir = Direction::UP;
		}
		if (playerPos.y > (vPos.y + 40))
		{
			vPos.y += 100 * _speed * fDT;
			_enemeyCurrentDir = Direction::DOWN;
		}
	}
	else if (abs(playerPos.x - vPos.x) > 2.f)
	{
		if (playerPos.x > vPos.x)
		{
			vPos.x += 100 * _speed * fDT;
			_enemeyCurrentDir = Direction::RIGHT;
		}
		else if (playerPos.x < vPos.x)
		{
			vPos.x -= 100 * _speed * fDT;
			_enemeyCurrentDir = Direction::LEFT;
		}
	}

	if (currentAnimation != animation[_enemeyCurrentDir])
	{
		GetComponent<Animator>()->StopAnimation();

		GetComponent<Animator>()->PlayAnimation(animation[_enemeyCurrentDir], true);
		currentAnimation = animation[_enemeyCurrentDir];
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
	cout << "Enemy Enter " << endl;
	Object* pOtherObj = _other->GetOwner();
	if (pOtherObj->GetName() == L"Player")	
	{
		//cout << "Enter" << endl;
		_isWallBumpInto = true;
		//GET_SINGLE(EventManager)->DeleteObject(pOtherObj);
	}
}


void Enemy::StayCollision(Collider* _other)
{
	cout << "Enemy Stay " << endl;
	//std::cout << "Stay" << std::endl;
}

void Enemy::ExitCollision(Collider* _other)
{
	//cout << "Enemy Exit " << endl;
	//cout << "Exit" << endl;
	//_isWallBumpInto = false;
	//std::cout << "Exit" << std::endl;
}
