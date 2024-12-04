#pragma once
#include "Component.h"
class TextUI
	:public Component
{
public:
	TextUI();
	~TextUI();
public:
	// Component을(를) 통해 상속됨
	void LateUpdate() override;
	void Render(HDC _hdc) override;
public:
	void TextBoxOpen(LPCWSTR text);
	void TextBoxClose();
	LPCWSTR str;
	RECT rt;

};

