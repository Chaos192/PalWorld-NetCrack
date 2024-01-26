#pragma once
#include <Windows.h>
#include "libs/utils/memory.h"
#include "database.h"
#include "SDK.hpp"

typedef bool(*Tick)(SDK::APalPlayerCharacter* m_this,float DeltaSecond);
typedef void(*AddStatus)(SDK::UPalNetworkIndividualComponent* p_this, SDK::FPalInstanceID* ID, SDK::TArray<SDK::FPalGotStatusPoint>* AddStatusPointArray);

class config
{
public:
	//offsets
	DWORD64 ClientBase = 0;
	DWORD64 offset_Tick = 0x2A9E9D0;//APalPlayerCharacter::Tick
	DWORD64 offset_AddStatus = 0x2B0E960; //UPalNetworkIndividualComponent::AddPlayerCharacterStatusPoint_ToServer
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
	bool isEq = false;
	//def and value
	float SpeedModiflers = 1.0f;
	int DamageUp = 0;
	int DefuseUp = 0;
	int EXP = 0;
	int Item = 0;
	float Pos[3] = {0,0,0};
	char ItemName[255];
	char inputTextBuffer[255] = "";
	int EqModifiler = 1;
	SDK::UWorld* gWorld = nullptr;
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
	static SDK::UPalCharacterImportanceManager* GetCharacterImpManager();
	static SDK::APalPlayerCharacter* GetPalPlayerCharacter();
	static SDK::APalPlayerState* GetPalPlayerState();
	static SDK::TArray<SDK::APalPlayerCharacter*> GetTAllPlayers();
	static bool	GetTAllPlayers(SDK::TArray<class SDK::APalCharacter*>* outResult);
	static bool	GetTAllImpNPC(SDK::TArray<class SDK::APalCharacter*>* outResult);
	static bool	GetTAllNPC(SDK::TArray<class SDK::APalCharacter*>* outResult);
	static bool	GetTAllPals(SDK::TArray<class SDK::APalCharacter*>* outResult);
	static void Init();
	static void Update(const char* filterText);
	static const std::vector<std::string>& GetFilteredItems();
};
extern config Config;
