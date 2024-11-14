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
	// ���̵� ���¸� ��Ÿ���� ������ Ÿ��
	enum class FadeState
	{
		None,
		FadeIn,
		FadeOut
	};

	// ������ map���� ����
	std::map<std::wstring, std::shared_ptr<Scene>> m_mapScenes;
	std::shared_ptr<Scene> m_pCurrentScene;

	// ���̵� ���� ����
	FadeState m_fadeState = FadeState::None;
	float m_fadeAlpha = 0.0f;
	float m_fadeDuration = 1.0f; // ���̵� ��/�ƿ��� �ɸ��� �ð� (�� ����)
	float m_fadeTimer = 0.0f;
	std::wstring m_nextScene; // ���̵� �� �ε��� �� �̸�
	bool m_isSceneChangePending = false; // �� ��ȯ ��� ���� �÷���
};