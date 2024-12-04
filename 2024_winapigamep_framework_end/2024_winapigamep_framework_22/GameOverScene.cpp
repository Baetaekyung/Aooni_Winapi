#include "pch.h"
#include "GameOverScene.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Texture.h"

void GameOverScene::Init()
{
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"GameOver", L"Texture\\GameOver.bmp");
	
	GET_SINGLE(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
	GET_SINGLE(ResourceManager)->Volume(SOUND_CHANNEL::BGM, 0.2f);
	GET_SINGLE(ResourceManager)->LoadSound(L"AooniSound", L"Sound\\AooniSound.wav", true);
	GET_SINGLE(ResourceManager)->Play(L"AooniSound");
}

void GameOverScene::Update()
{
	Scene::Update();
	if (GET_KEYDOWN(KEY_TYPE::ENTER))
		GET_SINGLE(SceneManager)->LoadScene(L"TitleScene");
}

void GameOverScene::Render(HDC _hdc)
{
	BitBlt(_hdc,
		300, 100,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		m_pTex->GetTexDC(), 0,
		0, SRCCOPY);

	SetTextColor(_hdc, RGB(255, 0, 0));
	SetBkColor(_hdc, TRANSPARENT);
	TextOut(_hdc, 600, 500, L"당신은 죽었습니다..", 
		wcslen(L"당신은 죽었습니다.."));
	TextOut(_hdc, 600, 550, L"엔터를 눌러 타이틀로..",
		wcslen(L"엔터를 눌러 타이틀로.."));

	Scene::Render(_hdc);
}
