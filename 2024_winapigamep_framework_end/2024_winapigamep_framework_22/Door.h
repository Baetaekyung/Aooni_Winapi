#pragma once
#include "Object.h"

class Door :
    public Object
{
public:
    Door();
    ~Door();
public:
    void Update() override;
    void Render(HDC hdc) override;
public:
    virtual void EnterCollision(Collider* other);
    virtual void StayCollision(Collider* other);
    virtual void ExitCollision(Collider* other);
public:
    void SetNextMap(MAP_TYPE nextTileMap);
    void SetNoNeedKey(bool newbool) { NoNeedKey = newbool; };
    void SetPlayerSpawnPoint(Vec2 newVec) { pPlayerSpawnVec2 = newVec; }
    void SetColliderSize(Vec2 newVec);
private:
    bool _isEntering = false;
    bool NoNeedKey = false;
    wstring nextSceneName;
    Vec2 pPlayerSpawnVec2;
};