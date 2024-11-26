#include "pch.h"
#include "MapScene.h"
#include <vector>
#include <string>
#include <filesystem>
#include <Windows.h>
#include "Texture.h"
#include "Core.h"
#include "TileMom.h"


void MapScene::Init()
{
	Object* obj = new Tile;
	obj->SetPos({ rand() % SCREEN_WIDTH,
			rand() % SCREEN_HEIGHT });
	obj->SetSize({ 100, 100 });
	AddObject(obj, LAYER::BACKGROUND);

}
