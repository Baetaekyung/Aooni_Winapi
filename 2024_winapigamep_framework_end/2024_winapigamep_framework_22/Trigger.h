#pragma once
#include "Object.h"

class Trigger :
    public Object
{
public:
    Trigger();
    ~Trigger();
public:
    void Update() override;
    void Render(HDC hdc) override;
public:
    virtual void EnterCollision(Collider* other);
    virtual void StayCollision(Collider* other);
    virtual void ExitCollision(Collider* other);
public:
    void SetNextMap(MAP_TYPE nextTileMap);
    void SetPlayerSpawnPoint(Vec2 newVec) { pPlayerSpawnVec2 = newVec; }
    void SetColliderSize(Vec2 newVec);
private:
    bool _isEntering = false;
    void NeedKeyType(KEY_TYPE newKeyType);
    wstring nextSceneName;
    Vec2 pPlayerSpawnVec2;
};