#pragma once

#include "Scene.h"

class TitleImage;

class TitleScene : public Scene
{
public:
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;

	virtual void Render(HDC _hdc) override;

private:
	
};

