#pragma once
#include "Object.h"
class Texture;
class Aooni : Object
{
public:
	Aooni();
	~Aooni();
public:
	void Update() override;
	void Render(HDC _hdc) override;
private:
	void CreateProjectile();
	Texture* m_pTex;
};

