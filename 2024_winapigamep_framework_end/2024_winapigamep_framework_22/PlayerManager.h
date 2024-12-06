#pragma once
class PlayerManager
{
	DECLARE_SINGLE(PlayerManager);
public:
	Vec2 GetPlayerSpwanPos() { return pPlayerSpawnPos; }
	void SetPlayerSpawnPos(Vec2 newPlayerPos) { pPlayerSpawnPos = newPlayerPos; }

private:
	Vec2 pPlayerSpawnPos = { 1280 / 2, 500 };
};

