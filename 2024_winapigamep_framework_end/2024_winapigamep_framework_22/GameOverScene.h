#pragma once
#include "Scene.h"

class Texture;

class GameOverScene : public Scene
{
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC _hdc) override;
public:
	Texture *m_pTex;
};

