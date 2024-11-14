#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "TitleScene.h"
#include "GameScene.h"

void SceneManager::Init()
{
	m_pCurrentScene = nullptr;

	// �� ���
	RegisterScene(L"TitleScene", std::make_shared<TitleScene>());
	RegisterScene(L"GameScene", std::make_shared<GameScene>());

	// ó�� �� �ε�
	LoadScene(L"TitleScene");
}

void SceneManager::Update()
{
	// ���̵� ��/�ƿ� ������ �� ���̵� ������Ʈ
	if (m_fadeState != FadeState::None)
	{
		m_fadeTimer += 0.016f; // assuming Update is called every frame (approx. 60 FPS)
		float progress = m_fadeTimer / m_fadeDuration;

		if (m_fadeState == FadeState::FadeOut)
		{
			m_fadeAlpha = progress; // 0���� 1�� ����
			if (progress >= 1.0f)
			{
				m_fadeAlpha = 1.0f;
				m_fadeState = FadeState::FadeIn;
				m_fadeTimer = 0.0f;

				// ���̵� �ƿ� �Ϸ� �Ŀ��� ���� �� �ε�
				auto iter = m_mapScenes.find(m_nextScene);
				if (iter != m_mapScenes.end())
				{
					// ���� ���� �����ϰ� �� ������ ��ȯ
					if (m_pCurrentScene != nullptr)
					{
						m_pCurrentScene->Release();
					}
					m_pCurrentScene = iter->second;
					m_pCurrentScene->Init();
				}
			}
		}
		else if (m_fadeState == FadeState::FadeIn)
		{
			m_fadeAlpha = 1.0f - progress; // 1���� 0���� ����
			if (progress >= 1.0f)
			{
				m_fadeAlpha = 0.0f;
				m_fadeState = FadeState::None; // ���̵� �Ϸ� ���·� ����
			}
		}
	}
	else if (m_pCurrentScene != nullptr)
	{
		// ���̵� �ִϸ��̼��� �ƴ� ���� �� ������Ʈ
		m_pCurrentScene->Update();
		m_pCurrentScene->LateUpdate();
	}
}

void SceneManager::Render(HDC _hdc)
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->Render(_hdc);
	}

	// ���̵� ��/�ƿ� �� ȭ�鿡 ������ �������� �׷��� ȿ�� ����
	if (m_fadeState != FadeState::None)
	{
		int alpha = static_cast<int>(m_fadeAlpha * 255);
		FillRectWithAlpha(_hdc, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), RGB(0, 0, 0), alpha);
	}
}

void SceneManager::RegisterScene(const std::wstring& _sceneName, std::shared_ptr<Scene> _scene)
{
	if (_sceneName.empty() || _scene == nullptr)
		return;
	m_mapScenes.insert(m_mapScenes.end(), { _sceneName, _scene });
}

void SceneManager::LoadScene(const std::wstring& _sceneName)
{
	// ���� ���̵� �ƿ� ���� �ƴ� ���� �� ��ȯ ��û�� ����
	if (m_fadeState == FadeState::None)  // ���̵� ���°� �ƹ��͵� ���� ���� ���ο� �� ��ȯ
	{
		m_fadeState = FadeState::FadeOut;
		m_fadeTimer = 0.0f;
		m_nextScene = _sceneName;
	}
}

void FillRectWithAlpha(HDC hdc, int x, int y, int width, int height, COLORREF color, int alpha)
{
	alpha = max(0, min(255, alpha));

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = -height;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	void* pvBits = nullptr;
	HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, &pvBits, NULL, 0);

	if (hBitmap == NULL) return;

	HDC hdcMem = CreateCompatibleDC(hdc);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hdcMem, hBitmap);

	DWORD colorWithAlpha = (alpha << 24) | (GetBValue(color) << 16) | (GetGValue(color) << 8) | GetRValue(color);
	DWORD* pPixels = (DWORD*)pvBits;
	for (int i = 0; i < width * height; ++i)
	{
		pPixels[i] = colorWithAlpha;
	}

	BLENDFUNCTION blendFunc = { 0 };
	blendFunc.BlendOp = AC_SRC_OVER;
	blendFunc.BlendFlags = 0;
	blendFunc.SourceConstantAlpha = 255;
	blendFunc.AlphaFormat = AC_SRC_ALPHA;

	AlphaBlend(hdc, x, y, width, height, hdcMem, 0, 0, width, height, blendFunc);

	SelectObject(hdcMem, hOldBitmap);
	DeleteObject(hBitmap);
	DeleteDC(hdcMem);
}
