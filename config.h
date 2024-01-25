#pragma once
#include <Windows.h>
#include "libs/utils/memory.h"
#include "database.h"
#include "SDK.hpp"

typedef bool(*Tick)(SDK::APalPlayerCharacter* m_this,float DeltaSecond);
typedef void(*GetAllPlayer)(SDK::UPalCharacterImportanceManager* i_this, SDK::TArray<SDK::APalCharacter*>* OutArray);

class config
{
public:
	//offsets
	DWORD64 ClientBase = 0;
	DWORD64 offset_Tick = 0x2AB44D0;//APalPlayerCharacter::Tick
	DWORD64 offset_GetAllPlayers = 0x2962330;// UPalCharacterImportanceManager::GetAllPlayer
	//check
	bool IsESP = false;
	bool IsAimbot = false;
	bool IsSpeedHack = false;
	bool IsAttackModiler = false;
	bool IsDefuseModiler = false;
	bool IsInfStamina = false;
	bool IsSafe = true;
	bool IsInfinAmmo = false;
	bool IsToggledFly = false;
	bool IsMuteki = false;
	bool IsMonster = false;
	bool IsQuick = false;
	bool matchDbItems = true;
	//def and value
	float SpeedModiflers = 1.0f;
	int DamageUp = 0;
	int DefuseUp = 0;
	int EXP = 0;
	int Item = 0;
	int PalRank = 0;
	float Pos[3] = {0,0,0};
	char ItemName[255];
	char PalName[255];
	int PalLvL = 1;
	int PalNum = 1;
	char inputTextBuffer[255] = "";
	SDK::APalPlayerCharacter* localPlayer = NULL;
	SDK::TArray<SDK::APalPlayerCharacter*> AllPlayers = {};
	SDK::UPalCharacterImportanceManager* UCIM = NULL;
	SDK::UObject* WorldContextObject = NULL;

	enum QuickItemSet
	{
		basic_items_stackable,
	    basic_items_single,
		pal_unlock_skills,
		spheres,
		tools

	};
	//Filtered Items
	std::vector<std::string> db_filteredItems;

	//static function
	static SDK::UWorld* GetUWorld();
	static SDK::APalPlayerCharacter* GetPalPlayerCharacter();
	static SDK::TArray<SDK::APalPlayerCharacter*> GetTAllPlayers();
	static void Init();
	static void Update(const char* filterText);
	static const std::vector<std::string>& GetFilteredItems();
};
extern config Config;
