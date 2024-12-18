#include "pch.h"
#include "IntroObject.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "SceneManager.h"
#include <string>
#include "PlayerManager.h"

IntroObject::IntroObject() :
    cnt(0),
    bCanMoveScene(false)
{
    std::cout << "\nStart Intro\n";
    for (int i = 0; i <= 9; ++i) {
        std::wstring textureKey = std::to_wstring(i);
        std::wstring texturePath = L"Texture\\" + textureKey + L".bmp";

        GET_SINGLE(ResourceManager)
            ->TextureLoad(textureKey, texturePath);
    }

    GET_SINGLE(ResourceManager)->LoadSound(L"Glass"
        , L"Sound\\GlassBroken.wav", false);
    GET_SINGLE(ResourceManager)->LoadSound(L"Wind"
        , L"Sound\\WindBaseSFX.wav", true);


    std::wstring currentTextureKey = std::to_wstring(cnt);
    m_InTex = GET_SINGLE(ResourceManager)
        ->TextureFind(currentTextureKey);

    GET_SINGLE(ResourceManager)->Play(L"Wind");
}

void IntroObject::Update()
{
    if (GET_KEYDOWN(KEYBOARD_TYPE::SPACE)) {
        NextIntro();
    }
}

void IntroObject::Render(HDC _hdc)
{
    Vec2 vPos = GetPos();
    Vec2 vSize = GetSize();

    int width = m_InTex->GetWidth();
    int height = m_InTex->GetHeight();

    ::TransparentBlt(_hdc,
        static_cast<int>(vPos.x - vSize.x / 2),
        static_cast<int>(vPos.y - vSize.y / 2),
        static_cast<int>(vSize.x),
        static_cast<int>(vSize.y),
        m_InTex->GetTexDC(),
        0, 0, width, height,
        RGB(255, 0, 255));
}

void IntroObject::NextIntro()
{
    std::cout << "\nNext Intro\n";

    if (cnt >= 8) {
        bCanMoveScene = true;
        GET_SINGLE(SceneManager)->LoadScene(L"IntroMoveScene");
    }


    if (cnt == 5) {
        GET_SINGLE(ResourceManager)->Play(L"Glass");
    }

    cnt++;
    std::wstring nextTextureKey = std::to_wstring(cnt);
    m_InTex = GET_SINGLE(ResourceManager)
        ->TextureFind(nextTextureKey);
}
