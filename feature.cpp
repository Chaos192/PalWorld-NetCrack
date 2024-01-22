#include "pch.h"
#include "feature.h"

void ESP()
{
	if (Config.IsESP)
	{
		DrawPlayerList(ImColor(128,0,0));
	}
}

void DrawPlayerList(ImColor color)
{
	ImGui::GetBackgroundDrawList()->AddText(nullptr, 16, ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), color, "Drawing...");
	

	SDK::TArray<SDK::AActor*> actors = *(SDK::TArray<SDK::AActor*>*)(*((uint64_t*)(*(uint64_t*)(Config.GetUWorld()->PersistentLevel))+0x098));
	
	if (actors.IsValid())
	{
		for (int i = 0; i < actors.Num(); i++)
		{
			if (actors[i] != NULL)
			{
				ImGui::GetBackgroundDrawList()->AddText(nullptr, 16, ImVec2(10, 10 + (i * 30)), color, actors[i]->GetFullName().c_str());
			}
		}
	}

}