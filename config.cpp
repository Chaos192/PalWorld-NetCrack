#include "pch.h"
#include "config.h"

config Config;

Tick TickFunc;
Tick OldTickFunc;

GetAllPlayer GetAllPlayerFunc;
GetAllPlayer OldGetAllPlayerFunc;

void DetourPlayers(SDK::UPalCharacterImportanceManager* i_this, SDK::TArray<SDK::APalCharacter*>* OutArray)
{
    if(i_this->PlayerList.IsValid())
    {
        Config.AllPlayers = i_this->PlayerList_ForOutsideGet;
    }
    return OldGetAllPlayerFunc(i_this, OutArray);
}
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
    }
    return (*(SDK::UWorld**)(gworld_ptr));
}

SDK::APalPlayerCharacter* config::GetPalPlayerCharacter()
{

    if (Config.localPlayer != NULL)
    {
        return Config.localPlayer;
    }
    return nullptr;
}

SDK::TArray<SDK::APalPlayerCharacter*> config::GetTAllPlayers()
{
    if (Config.AllPlayers.IsValid())
    {
        return Config.AllPlayers;
    }
    return NULL;
}

void config::Init()
{
    Config.ClientBase = (DWORD64)GetModuleHandleA("PalWorld-Win64-Shipping.exe");
    
    TickFunc = (Tick)(Config.ClientBase + Config.offset_Tick);
    GetAllPlayerFunc = (GetAllPlayer)(Config.ClientBase + Config.offset_GetAllPlayers);

    MH_CreateHook(TickFunc, DetourTick, reinterpret_cast<void**>(&OldTickFunc));
    MH_CreateHook(GetAllPlayerFunc, DetourPlayers, reinterpret_cast<void**>(&OldGetAllPlayerFunc));
}
