#pragma once
#include "Scene.h"

class Texture;

class EndingScene : public Scene
{
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
public:
	Texture* m_pTex;
};

