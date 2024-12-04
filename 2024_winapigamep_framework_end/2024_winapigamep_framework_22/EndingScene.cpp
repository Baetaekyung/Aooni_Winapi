#include "pch.h"
#include "EndingScene.h"
#include "Texture.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "ResourceManager.h"

void EndingScene::Init()
{
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Ending", L"Texture\\GameEndingScene.bmp");

	GET_SINGLE(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
	GET_SINGLE(ResourceManager)->Volume(SOUND_CHANNEL::BGM, 0.2f);
	GET_SINGLE(ResourceManager)->LoadSound(L"EndingSound", L"Sound\\EndingSound.wav", true);
	GET_SINGLE(ResourceManager)->Play(L"EndingSound");
}

void EndingScene::Update()
{
	Scene::Update();
	if (GET_KEYDOWN(KEY_TYPE::ENTER))
		GET_SINGLE(SceneManager)->LoadScene(L"TitleScene");
}

void EndingScene::Render(HDC hdc)
{
	BitBlt(hdc,
		150, 100,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		m_pTex->GetTexDC(), 0,
		0, SRCCOPY);

	SetTextColor(hdc, RGB(255, 255, 255));
	SetBkColor(hdc, TRANSPARENT);

	TextOut(hdc, 550, 500, L"����� �ƿ����Ͽ��Լ� ��Ƴ��ҽ��ϴ�..", 
		wcslen(L"����� �ƿ����Ͽ��Լ� ��Ƴ��ҽ��ϴ�.."));
	TextOut(hdc, 550, 550, L"Enter�� ���� Ÿ��Ʋ��..", 
		wcslen(L"Enter�� ���� Ÿ��Ʋ��.."));

	Scene::Render(hdc);
}
