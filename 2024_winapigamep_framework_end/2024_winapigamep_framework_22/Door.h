#pragma once
#include "Object.h"
#include "TileMap.h"
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
    void SetNextMap(TileMap nextTileMap);
private:
    bool _isEntering = false;
    wstring nextSceneName;
};

