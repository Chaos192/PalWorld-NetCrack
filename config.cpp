#include "pch.h"
#include "config.h"
#include <algorithm>

config Config;

Tick TickFunc;
Tick OldTickFunc;

void config::Update(const char* filterText)
{
    Config.db_filteredItems.clear();

    const auto& itemsToSearch = database::db_items;

    for (const auto& itemName : itemsToSearch) {
        if (strstr(itemName.c_str(), filterText) != nullptr) {
            Config.db_filteredItems.push_back(itemName);
        }
    }
    std::sort(Config.db_filteredItems.begin(), Config.db_filteredItems.end());
}
const std::vector<std::string>& config::GetFilteredItems(){ return Config.db_filteredItems; }

bool DetourTick(SDK::APalPlayerCharacter* m_this,float DeltaSecond)
{
    if (m_this->GetPalPlayerController() != NULL)
    {
        if (m_this->GetPalPlayerController()->IsLocalPlayerController())
        {
            Config.localPlayer = m_this;
        }
    }
        return OldTickFunc(m_this, DeltaSecond);
}
SDK::UWorld* config::GetUWorld()
{
    static uint64_t gworld_ptr = 0;
    if (!gworld_ptr)
    {
        auto gworld = signature("48 8B 05 ? ? ? ? EB 05").instruction(3).add(7);
        gworld_ptr = gworld.GetPointer();
        if (gworld_ptr)
            gWorld = *(SDK::UWorld**)gworld_ptr;
    }
    return (*(SDK::UWorld**)(gworld_ptr));
}

SDK::UPalCharacterImportanceManager* GetCharacterImpManager()
{
    SDK::UWorld* pWorld = config::gWorld;
    if (!pWorld)
        return;

    SDK::UGameInstance* pGameInstance = pWorld->OwningGameInstance; 
    if (!pGameInstance) 
        return nullptr;

    return static_cast<SDK::UPalGameInstance*>(pGameInstance)->CharacterImportanceManager;
}

SDK::APalPlayerCharacter* config::GetPalPlayerCharacter()
{

    if (Config.localPlayer != NULL)
    {
        return Config.localPlayer;
    }
    return nullptr;
}

SDK::APalPlayerState* config::GetPalPlayerState()
{
    SDK::APalPlayerCharacter* pPlayer = GetPalPlayerCharacter();
    if (!pPlayer)
        return nullptr;

    return static_cast<SDK::APalPlayerState*>(pPlayer->PlayerState);
}

bool GetTAllPlayers(SDK::TArray<class SDK::APalCharacter*>* outResult)
{
    SDK::UPalCharacterImportanceManager* mPal = GetCharacterImpManager();
    if (!mPal)
        return false;

    mPal->GetAllPlayer(outResult);
    return true;
}

bool GetTAllImpNPC(SDK::TArray<class SDK::APalCharacter*>* outResult)
{
    SDK::UPalCharacterImportanceManager* mPal = GetCharacterImpManager();
    if (!mPal)
        return false;

    mPal->GetImportantNPC(outResult);
    return true;
}

bool GetTAllNPC(SDK::TArray<class SDK::APalCharacter*>* outResult)
{
    SDK::UPalCharacterImportanceManager* mPal = GetCharacterImpManager();
    if (!mPal)
        return false;

    mPal->GetAllNPC(outResult);
    return true;
}

bool GetTAllPals(SDK::TArray<class SDK::APalCharacter*>* outResult)
{
    SDK::UPalCharacterImportanceManager* mPal = GetCharacterImpManager();
    if (!mPal)
        return false;

    mPal->GetAllPalCharacter(outResult);
    return true;
}


void config::Init()
{
    //register hook
    Config.ClientBase = (DWORD64)GetModuleHandleA("PalWorld-Win64-Shipping.exe");
    
    TickFunc = (Tick)(Config.ClientBase + Config.offset_Tick);

    MH_CreateHook(TickFunc, DetourTick, reinterpret_cast<void**>(&OldTickFunc));

    //init database
    ZeroMemory(&Config.db_filteredItems, sizeof(Config.db_filteredItems));
}
