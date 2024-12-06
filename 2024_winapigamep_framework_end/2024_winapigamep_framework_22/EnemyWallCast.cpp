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
	if (_owner == nullptr)
		return;
	if (enterCnt > 0)
		_isWallCast = true;
	else
		_isWallCast = false;
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
	enterCnt++;
	_owner->WallDirection();
	_isWallCast = true;
}

void EnemyWallCast::StayCollision(Collider* _other)
{
}

void EnemyWallCast::ExitCollision(Collider* _other)
{
	enterCnt--;
	//Object* obj = _other->GetOwner();
	_isWallCast = false;
	//cout << "CASTEXIT" << endl;
}



