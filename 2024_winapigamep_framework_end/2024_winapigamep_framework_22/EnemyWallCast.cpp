#include "pch.h"
#include "EnemyWallCast.h"
#include "SceneManager.h"
#include "Collider.h"
#include "Scene.h"
#include "Enemy.h"

EnemyWallCast::EnemyWallCast()
{
	this->AddComponent<Collider>();
	GetComponent<Collider>()->SetSize(Vec2(35.f, 40.f));
	GetComponent<Collider>()->SetOffSetPos(Vec2(0.f, 35.f));

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
	pos = _owner->GetPos();
	SetPos(pos);
}

void EnemyWallCast::Render(HDC _hdc)
{

}

void EnemyWallCast::EnterCollision(Collider* _other)
{
	cout << "CASTENTER" << endl;
	if (_other->GetOwner()->GetName() == L"Player")
		return;
	_owner->WallDirection();
	_isWallCast = true;
}

void EnemyWallCast::StayCollision(Collider* _other)
{
}

void EnemyWallCast::ExitCollision(Collider* _other)
{
	if (_other->GetOwner()->GetName() == L"Player")
		return;
	_isWallCast = false;
	cout << "CASTEXIT" << endl;
}



