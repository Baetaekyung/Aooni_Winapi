#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "TitleScene.h"
#include "MainHole_1FScene.h"
#include "MainHoleRightCorridor_1F.h"
#include "Kitchen_1FScene.h"
#include "LeftCorridor_1FScene.h"
#include "IntroScene.h"
#include "IntroMoveScene.h"
#include "BGDScene.h"
void SceneManager::Init()
{
	m_pCurrentScene = nullptr;

	// ¾À µî·Ï
	RegisterScene(L"TitleScene", std::make_shared<TitleScene>());
	RegisterScene(L"MainHole_1FScene", std::make_shared<MainHole_1FScene>());
	RegisterScene(L"MainHoleRightCorridor_1F", std::make_shared<MainHoleRightCorridor_1F>());
	RegisterScene(L"Kitchen_1FScene", std::make_shared<Kitchen_1FScene>());
	RegisterScene(L"LeftCorridor_1FScene", std::make_shared<LeftCorridor_1FScene>());
	RegisterScene(L"IntroScene", std::make_shared<IntroScene>());
	RegisterScene(L"IntroMoveScene", std::make_shared<IntroMoveScene>());
	RegisterScene(L"B", std::make_shared<BGDScene>());

	// ¾À ·Îµå
	LoadScene(L"TitleScene");
}

void SceneManager::Update()
{
	if (m_pCurrentScene == nullptr)
		return;
	m_pCurrentScene->Update();
	m_pCurrentScene->LateUpdate();
}

void SceneManager::Render(HDC _hdc)
{
	if (m_pCurrentScene == nullptr)
		return;
	m_pCurrentScene->Render(_hdc);
}

void SceneManager::RegisterScene(const wstring& _sceneName, std::shared_ptr<Scene> _scene)
{
	if (_sceneName.empty() || _scene == nullptr)
		return;
	m_mapScenes.insert(m_mapScenes.end(), { _sceneName, _scene });
}

void SceneManager::LoadScene(const wstring _sceneName)
{
	// ¾ÀÀÌ ÀÖÀ¸¸é
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->Release();
		m_pCurrentScene = nullptr;
	}

	auto iter = m_mapScenes.find(_sceneName);
	if (iter != m_mapScenes.end())
	{
		m_pCurrentScene = iter->second;
		m_pCurrentScene->Init();
	}
}
