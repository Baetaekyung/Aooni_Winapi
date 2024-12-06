#pragma once
enum class LAYER
{
	DEFAULT,
	BACKGROUND,
	WALL,
	PLAYER,
	PROJECTILE,
	ENEMY,
	INTERACTABLE,
	// UI
	END = 30
};

enum class PEN_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, END
};

enum class BRUSH_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, END
};


enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,
	END,
};

enum class MAP_TYPE
{
	MainHole_1FScene,
	MainHoleRightCorridor_1F,
	Kitchen_1F,
	END
};