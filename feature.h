#pragma once
#include "include/Menu.hpp"
#include "config.h"
#include <Windows.h>

void ESP();

void DrawUActorComponent(SDK::TArray<SDK::UActorComponent*> Comps,ImColor color);

void UnlockAllEffigies();

void AddToInventoryContainer(__int32 mCount, __int32 mIndex = 0);

