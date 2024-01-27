#include "pch.h"
#include "feature.h"

void ESP()
{
	if (Config.GetPalPlayerCharacter() != NULL)
	{
		if (Config.GetPalPlayerCharacter()->ShooterComponent != NULL)
		{
			if(Config.GetPalPlayerCharacter()->ShooterComponent->GetHasWeapon() != NULL)
			{
				DrawUActorComponent(Config.GetPalPlayerCharacter()->ShooterComponent->GetHasWeapon()->InstanceComponents, ImColor(128, 0, 0));
			}
		}
		if (Config.UCIM != NULL)
		{
			SDK::TArray<SDK::APalCharacter*> T = {};
			Config.UCIM->GetAllPalCharacter(&T);
			if (T.IsValid())
			{
				for (int i = 0; i < T.Num(); i++)
				{
					ImGui::GetBackgroundDrawList()->AddText(nullptr, 16, ImVec2(10, 10 + (i * 30)), ImColor(128,0,0), T[i]->GetFullName().c_str());
				}
			}
		}
	}
}
void DrawUActorComponent(SDK::TArray<SDK::UActorComponent*> Comps,ImColor color)
{
	ImGui::GetBackgroundDrawList()->AddText(nullptr, 16, ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), color, "Drawing...");
	if (Comps.IsValid())
	{
		for (int i = 0; i < Comps.Num(); i++)
		{
			
			if (Comps[i] != NULL)
			{
				
				ImGui::GetBackgroundDrawList()->AddText(nullptr, 16, ImVec2(10, 10 + (i * 30)), color, Comps[i]->GetFullName().c_str());
			}
		}
	}
}


void AddToInventoryContainer(__int32 mCount, __int32 mIndex)
{
	SDK::APalPlayerCharacter* p_appc = Config.GetPalPlayerCharacter();
	if (!p_appc != NULL)
		return;

	SDK::APalPlayerController* p_apc = static_cast<SDK::APalPlayerController*>(p_appc->Controller);
	if (!p_apc)
		return;

	SDK::APalPlayerState* p_apps = static_cast<SDK::APalPlayerState*>(p_apc->PlayerState);
	if (!p_apps)
		return;

	SDK::UPalPlayerInventoryData* InventoryData = p_apps->GetInventoryData();
	if (!InventoryData)
		return;

	SDK::UPalItemContainerMultiHelper* InventoryMultiHelper = InventoryData->InventoryMultiHelper;
	if (!InventoryMultiHelper)
		return;

	SDK::TArray<class SDK::UPalItemContainer*> Containers = InventoryMultiHelper->Containers;
	if (Containers.Num() <= 0)
		return;

	SDK::UPalItemSlot* pSelectedSlot = Containers[0]->Get(mIndex);

	if (!pSelectedSlot != NULL)
		return;

	SDK::FPalItemId FirstItemId = pSelectedSlot->GetItemId();
	int32 StackCount = pSelectedSlot->GetStackCount();
	__int32 mNewCount = StackCount += mCount;
	InventoryData->RequestAddItem(FirstItemId.StaticId, mNewCount, true);
}


void UnlockAllEffigies() {
	SDK::APalPlayerCharacter* pPalCharacter = Config.GetPalPlayerCharacter();
	if (!pPalCharacter)
		return;

	SDK::UWorld* world = Config.GetUWorld();
	if (!world)
		return;

	SDK::TUObjectArray* objects = world->GObjects;

	for (int i = 0; i < objects->NumElements; ++i) {
		SDK::UObject* object = objects->GetByIndex(i);

		if (!object) {
			continue;
		}

		if (!object->IsA(SDK::APalLevelObjectRelic::StaticClass())) {
			continue;
		}

		SDK::APalLevelObjectObtainable* relic = (SDK::APalLevelObjectObtainable*)object;
		if (!relic) {
			continue;
		}

		((SDK::APalPlayerState*)pPalCharacter->PlayerState)->RequestObtainLevelObject_ToServer(relic);
	}
}
