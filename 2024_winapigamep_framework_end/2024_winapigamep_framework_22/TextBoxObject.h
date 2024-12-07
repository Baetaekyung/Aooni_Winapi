#pragma once
#include "Object.h"

#define SpawnTextBox(type) \
    TextBoxObject* text = new TextBoxObject; \
    text->SetUpTextBox(type); \
    text->SetPos({ 650, 500 }); \
    text->SetSize({ 600, 200 }); \
    GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(text, LAYER::TEXTBOX);

class Texture;
class TextBoxObject :
    public Object
{
public:
    TextBoxObject();
public:
    virtual void Render(HDC _hdc) override;
    virtual void Update() override;
public:
    void SetUpTextBox(TEXT_TYPE textType);
    void UPTextBox();

private:
    Texture* m_tTex;
    bool bIsSpawn;
    float cnt;
};

