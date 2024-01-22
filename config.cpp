#include "pch.h"
#include "config.h"

config Config;

Tick TickFunc;
Tick OldTickFunc;


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

void config::Init()
{
    //����IsAdjustLocation��������
    Config.ClientBase = (DWORD64)GetModuleHandleA("PalWorld-Win64-Shipping.exe");
    TickFunc = (Tick)(Config.ClientBase + Config.offset_Tick);

    MH_CreateHook(TickFunc, DetourTick, reinterpret_cast<void**>(&OldTickFunc));

}
