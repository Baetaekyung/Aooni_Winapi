#include "pch.h"
#include "TitleScene.h"
#include "Object.h"
#include "Player.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "Key.h"
#include "Trigger.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "InitTexture.h"
#include "TitleImage.h"
void TitleScene::Init()
{
    Object* initTexture = new InitTexture;

    Object* title = new TitleImage;
    title->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
    title->SetSize({ 1000, 562 });
    AddObject(title, LAYER::BACKGROUND);
}

void TitleScene::Update() {
    Scene::Update();
    if (GET_KEYDOWN(KEY_TYPE::SPACE))
        GET_SINGLE(SceneManager)->LoadScene(L"IntroScene");
}

void TitleScene::Render(HDC _hdc)
{
    Scene::Render(_hdc);
    SetBkColor(_hdc, TRANSPARENT);
    SetTextColor(_hdc, RGB(255, 0, 0));
    TextOut(_hdc, (SCREEN_WIDTH / 2) - 50, 600, L"Space to start..", wcslen(L"Space to start.."));
}