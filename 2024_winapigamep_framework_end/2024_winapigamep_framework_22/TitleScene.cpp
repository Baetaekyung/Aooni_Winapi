#include "pch.h"
#include "TitleScene.h"
#include "Object.h"
#include "Player.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "Key.h"
#include "Door.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "TileMap.h"
#include "InitTexture.h"
void TitleScene::Init()
{
    Object* initTexture = new InitTexture;
}

void TitleScene::Update()
{
    Scene::Update();
    if (GET_KEYDOWN(KEY_TYPE::ENTER))
        GET_SINGLE(SceneManager)->LoadScene(L"MainHole_1FScene");
}

void TitleScene::Render(HDC _hdc)
{
    Scene::Render(_hdc);
    SetBkColor(_hdc, TRANSPARENT);
    SetTextColor(_hdc, RGB(255, 0, 0));
    TextOut(_hdc, 550, 400, L"Enter to start..", wcslen(L"Enter to start.."));
}