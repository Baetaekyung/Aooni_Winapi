#include "pch.h"
#include "TitleImage.h"
#include "Texture.h"
#include "ResourceManager.h"

TitleImage::TitleImage()
{
	m_tTex = GET_SINGLE(ResourceManager)
		->TextureLoad(L"TitleTexture", L"Title.bmp");

	std::cout << "Start";
}

TitleImage::~TitleImage()
{
}

void TitleImage::Update()
{
}

void TitleImage::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();

	int width = m_tTex->GetWidth();
	int height = m_tTex->GetHeight();

	::TransparentBlt(_hdc,
		static_cast<int>(vPos.x - vSize.x / 2),
		static_cast<int>(vPos.y - vSize.y / 2),
		static_cast<int>(vSize.x),
		static_cast<int>(vSize.y),
		m_tTex->GetTexDC(),
		0, 0, width, height,
		RGB(255, 0, 255));

	ComponentRender(_hdc);
}
