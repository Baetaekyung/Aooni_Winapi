#pragma once
#include "Scene.h"

class MapScene : public Scene
{
public:
	virtual void Init() override;

public:
	void NextMap(MAP_TYPE nextMap);
};

