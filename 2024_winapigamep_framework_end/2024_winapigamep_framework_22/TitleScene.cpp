#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "TitleScene.h"
#include "InputManager.h"
#include "GameScene.h"
#include "ResourceManager.h"
#include "TitleImage.h"

void TitleScene::Init()
{
	Object* obj = new TitleImage;
}

void TitleScene::Update()
{
	Scene::Update();
	if (GET_KEYDOWN(KEY_TYPE::ENTER))
		GET_SINGLE(SceneManager)->LoadScene(L"MapScene");
}