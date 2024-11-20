#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "TitleScene.h"
#include "GameScene.h"

void TitleScene::Init()
{
	
}

void TitleScene::Update()
{
	if (VK_RETURN) {
		GET_SINGLE(SceneManager)->LoadScene(L"MapScene");
	}
}
