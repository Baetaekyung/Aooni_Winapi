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
    void SetNeedKeyType(KEY_TYPE newKeyType) { needKeyType = newKeyType; }
    void SetText(TEXT_TYPE newTextType) { MyTextType = newTextType; }
private:
    void UpText();
private:
    KEY_TYPE needKeyType;
    bool _isEntering = false;
    wstring nextSceneName;
    Vec2 pPlayerSpawnVec2;
    TEXT_TYPE MyTextType;
};