#include "pch.h"
#include "InitTexture.h"
#include "Texture.h"
#include "ResourceManager.h"

InitTexture::InitTexture()
{
    std::map<std::wstring, std::wstring> textures = {
        {L"MainHole_1FScene", L"Texture\\aooniMap_1F_Hole.bmp"},
        {L"MainHoleRightCorridor_1F", L"Texture\\aooniMap_1F_HoleRightCorridor.bmp"},
        {L"Kitchen_1F", L"Texture\\aooniMap_1F_kitchen.bmp"}
    };

    // 텍스처 로드
    for (const auto& [name, path] : textures) {
        if (GET_SINGLE(ResourceManager)->TextureLoad(name, path)) {
            std::cout << "Sucsess";
        }
        else {
            std::cout << "Boom";
        }
    }
}

void InitTexture::Update()
{
}

void InitTexture::Render(HDC _hdc)
{
}