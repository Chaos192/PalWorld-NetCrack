#pragma once
#include "include/Menu.hpp"
#include "config.h"
#include <Windows.h>

void ESP();

void ESP_DEBUG(float mDist, ImVec4 color, SDK::UClass* mEntType = SDK::AActor::StaticClass());

void DrawUActorComponent(SDK::TArray<SDK::UActorComponent*> Comps, ImColor color);

void UnlockAllEffigies();

void AddToInventoryContainer(__int32 mCount, __int32 mIndex = 0);

void ResetStamina();

void SetInfiniteAmmo(bool bInfAmmo);

void SetCraftingSpeed(float mNewSpeed, bool bRestoreDefault = false);

void AddTechPoints(__int32 mPoints);

void AddAncientTechPoints(__int32 mPoints);

void RemoveTechPoints(__int32 mPoints);

void RemoveAncientTechPoint(__int32 mPoints);