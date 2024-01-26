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
    //register hook
    Config.ClientBase = (DWORD64)GetModuleHandleA("PalWorld-Win64-Shipping.exe");
    
    TickFunc = (Tick)(Config.ClientBase + Config.offset_Tick);

    MH_CreateHook(TickFunc, DetourTick, reinterpret_cast<void**>(&OldTickFunc));

    //init database
    ZeroMemory(&Config.db_filteredItems, sizeof(Config.db_filteredItems));
}
