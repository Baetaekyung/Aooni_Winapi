#pragma once
#include "Scene.h"
class Kitchen_1FScene
	:Scene
{
public:
	virtual void Init() override;

	virtual void Update() override;

	virtual void Render(HDC _hdc) override;
};

