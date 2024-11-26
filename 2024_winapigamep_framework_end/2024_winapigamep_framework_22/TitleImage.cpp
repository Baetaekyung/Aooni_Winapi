#include "pch.h"
#include "TitleImage.h"
#include "Texture.h"
#include "ResourceManager.h"

TitleImage::TitleImage()
{
	m_TTex = GET_SINGLE(ResourceManager)
		->TextureLoad(L"TitleImage", L"aooni.bmp");

	std::cout << "Start";
}

TitleImage::~TitleImage()
{
}

void TitleImage::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();

	int width = m_TTex->GetWidth();
	int height = m_TTex->GetHeight();

	ComponentRender(_hdc);
}
