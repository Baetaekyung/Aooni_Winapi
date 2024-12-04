#pragma once
#include "Component.h"
class TextUI
	:public Component
{
public:
	TextUI();
	~TextUI();
public:
	// Component��(��) ���� ��ӵ�
	void LateUpdate() override;
	void Render(HDC _hdc) override;
public:
	void TextBoxOpen(LPCWSTR text);
	void TextBoxClose();
	LPCWSTR str;
	RECT rt;

};

