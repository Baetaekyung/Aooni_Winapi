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
	pos = _owner->GetPos();
	SetPos(pos);


}

void EnemyWallCast::Render(HDC _hdc)
{
	//Vec2 vPos = GetPos();
	//Vec2 vSize = GetSize();

	////int width = _m_pTex->GetWidth();
	////int height = _m_pTex->GetHeight();
	//ComponentRender(_hdc);
}

void EnemyWallCast::EnterCollision(Collider* _other)
{
	cout << "CASTENTER" << endl;
	_owner->WallDirection();
	_isWallCast = true;
}

void EnemyWallCast::StayCollision(Collider* _other)
{
}

void EnemyWallCast::ExitCollision(Collider* _other)
{
	Object* obj = _other->GetOwner();
	_isWallCast = false;
	cout << "CASTEXIT" << endl;
}



