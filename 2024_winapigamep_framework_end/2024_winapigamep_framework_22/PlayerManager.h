#pragma once
#define SpawnPlayer \
	Player* pPlayer = new Player; \
	pPlayer->SetSize({ 100, 100 }); \
	pPlayer->SetPos(GET_SINGLE(PlayerManager)->GetPlayerSpwanPos()); \
	AddObject(pPlayer, LAYER::PLAYER);
class PlayerManager
{
	DECLARE_SINGLE(PlayerManager);
public:
	Vec2 GetPlayerSpwanPos() { return pPlayerSpawnPos; }
	void SetPlayerSpawnPos(Vec2 newPlayerPos) { pPlayerSpawnPos = newPlayerPos; }
	bool GetPlayerKey(KEY_TYPE findKey);
	void AddPlayerKey(KEY_TYPE newKeyType);
public:
	bool MissingScene = true;
private:
	Vec2 pPlayerSpawnPos = { 470, 383 };
	vector<KEY_TYPE> Keylist = {KEY_TYPE::None};
};