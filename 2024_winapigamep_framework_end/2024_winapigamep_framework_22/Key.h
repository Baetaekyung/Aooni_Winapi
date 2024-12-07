#pragma once
#include "Object.h"
class Texture;
class Key :
    public Object
{
public:
    Key();
    ~Key();
public:
    void Update() override;
    void Render(HDC hdc) override;
public:
    virtual void EnterCollision(Collider* other);
    virtual void StayCollision(Collider* other);
    virtual void ExitCollision(Collider* other);
public:
    void SetKeyType(KEY_TYPE newKeyType) { MyKeyType = newKeyType; }
    void UpTextBox();
    void SetTextType(TEXT_TYPE newKeyType) { MyTextType = newKeyType; }
private:
    BRUSH_TYPE currentBrushType;
    Texture* m_pTex;
    KEY_TYPE MyKeyType;
    TEXT_TYPE MyTextType;
};

