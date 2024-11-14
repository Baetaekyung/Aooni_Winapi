#pragma once

#include <memory>
#include <map>
#include <string>

class Scene;
class SceneManager
{
	DECLARE_SINGLE(SceneManager);
public:
	void Init(); // start
	void Update();
	void Render(HDC _hdc);
	void RegisterScene(const std::wstring& _sceneName, std::shared_ptr<Scene> _scene);
	void LoadScene(const std::wstring& _sceneName);

	const std::shared_ptr<Scene>& GetCurrentScene() const { return m_pCurrentScene; }

private:
	// 페이드 상태를 나타내는 열거형 타입
	enum class FadeState
	{
		None,
		FadeIn,
		FadeOut
	};

	// 씬들을 map으로 관리
	std::map<std::wstring, std::shared_ptr<Scene>> m_mapScenes;
	std::shared_ptr<Scene> m_pCurrentScene;

	// 페이드 관련 변수
	FadeState m_fadeState = FadeState::None;
	float m_fadeAlpha = 0.0f;
	float m_fadeDuration = 1.0f; // 페이드 인/아웃에 걸리는 시간 (초 단위)
	float m_fadeTimer = 0.0f;
	std::wstring m_nextScene; // 페이드 후 로드할 씬 이름
	bool m_isSceneChangePending = false; // 씬 전환 대기 상태 플래그
};