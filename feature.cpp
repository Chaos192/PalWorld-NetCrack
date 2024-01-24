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
