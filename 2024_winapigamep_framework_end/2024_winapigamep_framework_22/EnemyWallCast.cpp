#include "pch.h"
#include "EnemyWallCast.h"
#include "SceneManager.h"
#include "Collider.h"
#include "Scene.h"
#include "Enemy.h"
#include "Core.h"

EnemyWallCast::EnemyWallCast()
{
	this->AddComponent<Collider>();
	GetComponent<Collider>()->SetSize(Vec2(35.f, 40.f));
	GetComponent<Collider>()->SetOffSetPos(Vec2(0.f, 35.f));
	GetComponent<Collider>()->SetID(10);

	std::shared_ptr<Scene> pCurrentScene = GET_SINGLE(SceneManager)->GetCurrentScene();
	const vector<Object*>& enemyVec = pCurrentScene->GetLayerObjects(LAYER::ENEMY);
	if (enemyVec.size() > 0)
		_owner = dynamic_cast<Enemy*>(enemyVec[0]);

}

EnemyWallCast::~EnemyWallCast()
{
}

void EnemyWallCast::Update()
{
	Vec2 vPos = _owner->GetPos(); 
	/*if (_owner == nullptr)
		return;
	HDC _hdc = GET_SINGLE(Core)->GetMainDC();
	Direction dir;
	if(_isWallCast)
		dir = _owner->GetLastDirection();
	else
		dir = _owner->GetCurrentDirection();

	switch (dir)
	{
	case Direction::LEFT:
		color = GetPixel(_hdc, vPos.x - blockdistance.x, vPos.y + 40);
		break;
	case Direction::RIGHT:
		color = GetPixel(_hdc, vPos.x + blockdistance.x, vPos.y + 40 );
		break;
	case Direction::UP:
		color = GetPixel(_hdc, vPos.x , vPos.y + 40 - blockdistance.y);
		break;
	case Direction::DOWN:
		color = GetPixel(_hdc, vPos.x , vPos.y + 40 + blockdistance.y);
		break;
	}
	if (!_owner->IsBlockedByColor(color))
	{
		_isWallCast = false;
	}
	else if(!_isWallCast)
	{
		_isWallCast = true;
		_owner->WallDirection();

		cout << 2 << endl;
	}*/
	pos = vPos;
	SetPos(pos);

}

void EnemyWallCast::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
}

void EnemyWallCast::EnterCollision(Collider* _other)
{
	//cout << "CASTENTER" << endl;
	//_owner->WallDirection();
	//_isWallCast = true;
}

void EnemyWallCast::StayCollision(Collider* _other)
{
}

void EnemyWallCast::ExitCollision(Collider* _other)
{
	//Object* obj = _other->GetOwner();
	//_isWallCast = false;
	//cout << "CASTEXIT" << endl;
}



