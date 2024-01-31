#include "pch.h"
#include "feature.h"
using namespace SDK;

//	should only be called from a GUI thread with ImGui context
void ESP()
{
	APalPlayerCharacter* pPalCharacter = Config.GetPalPlayerCharacter();
	if (!pPalCharacter)
		return;

	UPalShooterComponent* pShootComponent = pPalCharacter->ShooterComponent;
	if (!pShootComponent)
		return;

	APalWeaponBase* pWeapon = pShootComponent->HasWeapon;
	if (pWeapon)
		DrawUActorComponent(pWeapon->InstanceComponents, ImColor(128, 0, 0));

	if (!Config.UCIM)
		return;

	TArray<SDK::APalCharacter*> T = {};
	Config.UCIM->GetAllPalCharacter(&T);
	if (!T.IsValid())
		return;

	for (int i = 0; i < T.Count(); i++)
		ImGui::GetBackgroundDrawList()->AddText(nullptr, 16, ImVec2(10, 10 + (i * 30)), ImColor(128,0,0), T[i]->GetFullName().c_str());
}

// credit: xCENTx
//	draws debug information for the input actor array
//	should only be called from a GUI thread with ImGui context
void ESP_DEBUG(float mDist, ImVec4 color, UClass* mEntType)
{
	APalPlayerCharacter* pLocalPlayer = Config.GetPalPlayerCharacter();
	if (!pLocalPlayer)
		return;

	APalPlayerController* pPlayerController = static_cast<APalPlayerController*>(pLocalPlayer->Controller);
	if (!pPlayerController)
		return;

	std::vector<AActor*> actors;
	if (!config::GetAllActorsofType(mEntType, &actors, true))
		return;
	
	auto draw = ImGui::GetBackgroundDrawList();

	__int32 actorsCount = actors.size();
	for (AActor* actor : actors)
	{
		FVector actorLocation = actor->K2_GetActorLocation();
		FVector localPlayerLocation = pLocalPlayer->K2_GetActorLocation();
		float distanceTo = GetDistanceToActor(pLocalPlayer, actor);
		if (distanceTo > mDist)
			continue;

		FVector2D outScreen;
		if (!pPlayerController->ProjectWorldLocationToScreen(actorLocation, &outScreen, true))
			continue;

		char data[0x256];
		const char* StringData = "OBJECT: [%s]\nCLASS: [%s]\nPOSITION: { %0.0f, %0.0f, %0.0f }\nDISTANCE: [%.0fm]";
		if (distanceTo >= 1000.f)
		{
			distanceTo /= 1000.f;
			StringData = "OBJECT: [%s]\nCLASS: [%s]\nPOSITION: { %0.0f, %0.0f, %0.0f }\nDISTANCE: [%.0fkm]";
		}
		sprintf_s(data, StringData, actor->GetName().c_str(), actor->Class->GetFullName().c_str(), actorLocation.X, actorLocation.Y, actorLocation.Z, distanceTo);

		ImVec2 screen = ImVec2(static_cast<float>(outScreen.X), static_cast<float>(outScreen.Y));
		draw->AddText(screen, ImColor(color), data);
	}
}

//	should only be called from a GUI thread with ImGui context
void DrawUActorComponent(TArray<UActorComponent*> Comps,ImColor color)
{
	ImGui::GetBackgroundDrawList()->AddText(nullptr, 16, ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), color, "Drawing...");
	if (!Comps.IsValid())
		return; 
	for (int i = 0; i < Comps.Count(); i++)
	{
		
		if (!Comps[i])
			continue;

		ImGui::GetBackgroundDrawList()->AddText(nullptr, 16, ImVec2(10, 10 + (i * 30)), color, Comps[i]->GetFullName().c_str());
	}
}

//	credit: 
void UnlockAllEffigies() 
{
	APalPlayerCharacter* pPalCharacter = Config.GetPalPlayerCharacter();
	APalPlayerState* pPalPlayerState = Config.GetPalPlayerState();
	if (!pPalCharacter || !pPalPlayerState)
		return;

	UWorld* world = Config.GetUWorld();
	if (!world)
		return;

	TUObjectArray* objects = world->GObjects;

	for (int i = 0; i < objects->NumElements; ++i) 
	{
		UObject* object = objects->GetByIndex(i);

		if (!object)
			continue;

		if (!object->IsA(APalLevelObjectRelic::StaticClass()))
			continue;

		APalLevelObjectObtainable* relic = (APalLevelObjectObtainable*)object;
		if (!relic) {
			continue;
		}

		pPalPlayerState->RequestObtainLevelObject_ToServer(relic);
	}
}

//	Credit: BennettStaley
void IncrementInventoryItemCountByIndex(__int32 mCount, __int32 mIndex)
{
	APalPlayerCharacter* p_appc = Config.GetPalPlayerCharacter();
	if (!p_appc != NULL)
		return;

	APalPlayerController* p_apc = static_cast<APalPlayerController*>(p_appc->Controller);
	if (!p_apc)
		return;

	APalPlayerState* p_apps = static_cast<SDK::APalPlayerState*>(p_apc->PlayerState);
	if (!p_apps)
		return;

	UPalPlayerInventoryData* InventoryData = p_apps->GetInventoryData();
	if (!InventoryData)
		return;

	UPalItemContainerMultiHelper* InventoryMultiHelper = InventoryData->InventoryMultiHelper;
	if (!InventoryMultiHelper)
		return;

	TArray<class SDK::UPalItemContainer*> Containers = InventoryMultiHelper->Containers;
	if (Containers.Count() <= 0)
		return;

	UPalItemSlot* pSelectedSlot = Containers[0]->Get(mIndex);

	if (!pSelectedSlot != NULL)
		return;

	FPalItemId FirstItemId = pSelectedSlot->GetItemId();
	__int32 StackCount = pSelectedSlot->GetStackCount();
	__int32 mNewCount = StackCount += mCount;
	InventoryData->RequestAddItem(FirstItemId.StaticId, mNewCount, true);
}

//	
void AddItemToInventoryByName(UPalPlayerInventoryData* data, char* itemName, int count)
{
	// obtain lib instance
	static UKismetStringLibrary* lib = UKismetStringLibrary::GetDefaultObj();

	// Convert FNAME
	wchar_t  ws[255];
	swprintf(ws, 255, L"%hs", itemName);
	FName Name = lib->Conv_StringToName(FString(ws));

	// Call
	data->RequestAddItem(Name, count, true);
}

// Credit: asashi
void SpawnMultiple_ItemsToInventory(config::QuickItemSet Set)
{
	SDK::UPalPlayerInventoryData* InventoryData = Config.GetPalPlayerCharacter()->GetPalPlayerController()->GetPalPlayerState()->GetInventoryData();
	switch (Set)
	{
	case 0:
		for (int i = 0; i < IM_ARRAYSIZE(database::basic_items_stackable); i++)
			AddItemToInventoryByName(InventoryData, _strdup(database::basic_items_stackable[i].c_str()), 100);
		break;
	case 1:
		for (int i = 0; i < IM_ARRAYSIZE(database::basic_items_single); i++)
			AddItemToInventoryByName(InventoryData, _strdup(database::basic_items_single[i].c_str()), 1);
		break;
	case 2:
		for (int i = 0; i < IM_ARRAYSIZE(database::pal_unlock_skills); i++)
			AddItemToInventoryByName(InventoryData, _strdup(database::pal_unlock_skills[i].c_str()), 1);
		break;
	case 3:
		for (int i = 0; i < IM_ARRAYSIZE(database::spheres); i++)
			AddItemToInventoryByName(InventoryData, _strdup(database::spheres[i].c_str()), 100);
		break;
	case 4:
		for (int i = 0; i < IM_ARRAYSIZE(database::tools); i++)
			AddItemToInventoryByName(InventoryData, _strdup(database::tools[i].c_str()), 1);
		break;
	default:
		break;
	}
}

//	
void AnyWhereTP(FVector& vector, bool IsSafe)
{
	APalPlayerState* pPalPlayerState = Config.GetPalPlayerState();
	APalPlayerController* pPalPlayerController = Config.GetPalPlayerController();
	if (!pPalPlayerController || !pPalPlayerState)
		return;

	vector = { vector.X,vector.Y + 100,vector.Z };
	FGuid guid = pPalPlayerController->GetPlayerUId();
	pPalPlayerController->Transmitter->Player->RegisterRespawnLocation_ToServer(guid, vector);
	pPalPlayerState->RequestRespawn();
}

//	
void ExploitFly(bool IsFly)
{
	SDK::APalPlayerCharacter* pPalPlayerCharacter = Config.GetPalPlayerCharacter();
	if (!pPalPlayerCharacter)
		return;

	APalPlayerController* pPalPlayerController = pPalPlayerCharacter->GetPalPlayerController();
	if (!pPalPlayerController)
		return;

	IsFly ? pPalPlayerController->StartFlyToServer() : pPalPlayerController->EndFlyToServer();
}

//	credit: xCENTx
void SetFullbright(bool bIsSet)
{
	ULocalPlayer* pLocalPlayer = Config.GetLocalPlayer();
	if (!pLocalPlayer)
		return;

	UGameViewportClient* pViewport = pLocalPlayer->ViewportClient;
	if (!pViewport)
		return;

	pViewport->mViewMode = bIsSet ? 1 : 3;
}

//	
void SpeedHack(float mSpeed)
{
	UWorld* pWorld = Config.gWorld;
	if (!pWorld)
		return;

	ULevel* pLevel = pWorld->PersistentLevel;
	if (!pLevel)
		return;

	AWorldSettings* pWorldSettings = pLevel->WorldSettings;
	if (!pWorldSettings)
		return;

	pWorld->PersistentLevel->WorldSettings->TimeDilation = mSpeed;

	//	pWorldSettings->TimeDilation = mSpeed;
}

//	
void SetDemiGodMode(bool bIsSet)
{
	auto pCharacter = Config.GetPalPlayerCharacter();
	if (!pCharacter)
		return;

	auto pParams = pCharacter->CharacterParameterComponent;
	if (!pParams)
		return;

	auto mIVs = pParams->IndividualParameter;
	if (!mIVs)
		return;

	auto sParams = mIVs->SaveParameter;

	pParams->bIsEnableMuteki = bIsSet;	//	Credit: Mokobake
	if (!bIsSet)
		return;

	//	attempt additional parameters
	sParams.HP.Value = sParams.MaxHP.Value;
	sParams.MP.Value = sParams.MaxMP.Value;
	sParams.FullStomach = sParams.MaxFullStomach;
	sParams.PhysicalHealth = EPalStatusPhysicalHealthType::Healthful;
	sParams.SanityValue = 100.f;
	sParams.HungerType = EPalStatusHungerType::Default;
}

//	
void RespawnLocalPlayer(bool bIsSafe)
{
	APalPlayerController* pPalPlayerController = Config.GetPalPlayerController();
	APalPlayerState* pPalPlayerState = Config.GetPalPlayerState();
	if (!pPalPlayerController || !pPalPlayerState)
		return;

	bIsSafe ? pPalPlayerController->TeleportToSafePoint_ToServer() : pPalPlayerState->RequestRespawn();
}

void SetPlayerHealth(__int32 newHealth)
{
	APalPlayerCharacter* pPalPlayerCharacter = Config.GetPalPlayerCharacter();
	if (!pPalPlayerCharacter)
		return;

	UPalCharacterParameterComponent* pParams = pPalPlayerCharacter->CharacterParameterComponent;
	if (!pParams)
		return;

	FFixedPoint64 maxHP = pParams->GetMaxHP();
	if (newHealth > maxHP.Value)
		newHealth = maxHP.Value;

	FFixedPoint newHealthPoint = FFixedPoint(newHealth);
	pPalPlayerCharacter->ReviveCharacter_ToServer(newHealthPoint);
}

//	
void ReviveLocalPlayer()
{
	APalPlayerCharacter* pPalPlayerCharacter = Config.GetPalPlayerCharacter();
	if (!pPalPlayerCharacter)
		return;

	UPalCharacterParameterComponent* pParams = pPalPlayerCharacter->CharacterParameterComponent;
	if (!pParams)
		return;

	if (pParams->IsDying())
		pParams->ReviveFromDying();

	FFixedPoint64 maxHP = pParams->GetMaxHP();
	FFixedPoint newHealth = FFixedPoint(maxHP.Value);
	pPalPlayerCharacter->ReviveCharacter_ToServer(newHealth);
}

//	
void ResetStamina()
{
	APalPlayerCharacter* pPalCharacter = Config.GetPalPlayerCharacter();
	if (!pPalCharacter)
		return;

	UPalCharacterParameterComponent* pParams = pPalCharacter->CharacterParameterComponent;
	if (!pParams)
		return;

	pParams->ResetSP();


	//	Reset Pal Stamina ??
	TArray<APalCharacter*> outPals;
	Config.GetTAllPals(&outPals);
	DWORD palsSize = outPals.Count();
	for (int i = 0; i < palsSize; i++)
	{
		APalCharacter* cPal = outPals[i];
		if (!cPal || cPal->IsA(APalMonsterCharacter::StaticClass()))
			continue;

		UPalCharacterParameterComponent* pPalParams = pPalCharacter->CharacterParameterComponent;
		if (!pPalParams)
			return;

		pPalParams->ResetSP();
	}
}

//	
void GiveExperiencePoints(__int32 mXP)
{
	auto pPalPlayerState = Config.GetPalPlayerState();
	if (!pPalPlayerState)
		return;

	pPalPlayerState->GrantExpForParty(mXP);
}

//	
void SetPlayerAttackParam(__int32 mNewAtk)
{
	APalPlayerCharacter* pPalPlayerCharacter = Config.GetPalPlayerCharacter();
	if (!pPalPlayerCharacter)
		return;

	UPalCharacterParameterComponent* pParams = pPalPlayerCharacter->CharacterParameterComponent;
	if (!pParams)
		return;

	if (pParams->AttackUp != mNewAtk)
		pParams->AttackUp = mNewAtk;
}

//	
void SetPlayerDefenseParam(__int32 mNewDef)
{
	APalPlayerCharacter* pPalPlayerCharacter = Config.GetPalPlayerCharacter();
	if (!pPalPlayerCharacter)
		return;

	UPalCharacterParameterComponent* pParams = pPalPlayerCharacter->CharacterParameterComponent;
	if (!pParams)
		return;
	
	if (pParams->DefenseUp != mNewDef)
		pParams->DefenseUp = mNewDef;
}

//	
void SetInfiniteAmmo(bool bInfAmmo)
{
	APalPlayerCharacter* pPalCharacter = Config.GetPalPlayerCharacter();
	if (!pPalCharacter)
		return;

	UPalShooterComponent* pShootComponent = pPalCharacter->ShooterComponent;
	if (!pShootComponent)
		return;

	APalWeaponBase* pWeapon = pShootComponent->HasWeapon;
	if (pWeapon)
		pWeapon->IsRequiredBullet = bInfAmmo ? false : true;

}

//	
void SetCraftingSpeed(float mNewSpeed, bool bRestoreDefault)
{
	APalPlayerCharacter* pPalCharacter = Config.GetPalPlayerCharacter();
	if (!pPalCharacter)
		return;

	UPalCharacterParameterComponent* pParams = pPalCharacter->CharacterParameterComponent;
	if (!pParams)
		return;

	UPalIndividualCharacterParameter* ivParams = pParams->IndividualParameter;
	if (!ivParams)
		return;

	FPalIndividualCharacterSaveParameter sParams = ivParams->SaveParameter;
	TArray<FFloatContainer_FloatPair> mCraftSpeedArray = sParams.CraftSpeedRates.Values;

	if (mCraftSpeedArray.Count() > 0)
		mCraftSpeedArray[0].Value = bRestoreDefault ? 1.0f : mNewSpeed;
}

//	
void AddTechPoints(__int32 mPoints)
{
	APalPlayerState* mPlayerState = Config.GetPalPlayerState();
	if (!mPlayerState)
		return;

	UPalTechnologyData* pTechData = mPlayerState->TechnologyData;
	if (!pTechData)
		return;

	pTechData->TechnologyPoint += mPoints;
}

//	
void AddAncientTechPoints(__int32 mPoints)
{
	APalPlayerState* mPlayerState = Config.GetPalPlayerState();
	if (!mPlayerState)
		return;

	UPalTechnologyData* pTechData = mPlayerState->TechnologyData;
	if (!pTechData)
		return;

	pTechData->bossTechnologyPoint += mPoints;
}

//	
void RemoveTechPoints(__int32 mPoints)
{
	APalPlayerState* mPlayerState = Config.GetPalPlayerState();
	if (!mPlayerState)
		return;

	UPalTechnologyData* pTechData = mPlayerState->TechnologyData;
	if (!pTechData)
		return;

	pTechData->TechnologyPoint -= mPoints;
}

//	
void RemoveAncientTechPoint(__int32 mPoints)
{
	APalPlayerState* mPlayerState = Config.GetPalPlayerState();
	if (!mPlayerState)
		return;

	UPalTechnologyData* pTechData = mPlayerState->TechnologyData;
	if (!pTechData)
		return;

	pTechData->bossTechnologyPoint -= mPoints;
}

// credit: xCENTx
float GetDistanceToActor(AActor* pLocal, AActor* pTarget)
{
	if (!pLocal || !pTarget)
		return -1.f;
	
	FVector pLocation = pLocal->K2_GetActorLocation();
	FVector pTargetLocation = pTarget->K2_GetActorLocation();
	double distance = sqrt(pow(pTargetLocation.X - pLocation.X, 2.0) + pow(pTargetLocation.Y - pLocation.Y, 2.0) + pow(pTargetLocation.Z - pLocation.Z, 2.0));

	return distance / 100.0f;
}

// credit xCENTx
void ForgeActor(SDK::AActor* pTarget, float mDistance, float mHeight, float mAngle)
{
	APalPlayerCharacter* pPalPlayerCharacter = Config.GetPalPlayerCharacter();
	APlayerController* pPlayerController = Config.GetPalPlayerController();
	if (!pTarget || !pPalPlayerCharacter || !pPlayerController)
		return;

	APlayerCameraManager* pCamera = pPlayerController->PlayerCameraManager;
	if (!pCamera)
		return;

	FVector playerLocation = pPalPlayerCharacter->K2_GetActorLocation();
	FVector camFwdDir = pCamera->GetActorForwardVector() * ( mDistance * 100.f ); 
	FVector targetLocation = playerLocation + camFwdDir;

	if (mHeight != 0.0f)
		targetLocation.Y += mHeight;
	
	FRotator targetRotation = pTarget->K2_GetActorRotation();
	if (mAngle != 0.0f)
		targetRotation.Roll += mAngle;

	pTarget->K2_SetActorLocation(targetLocation, false, nullptr, true);
	pTarget->K2_SetActorRotation(targetRotation, true);
}

//	credit: 
void SendDamageToActor(APalCharacter* pTarget, int32 damage, bool bSpoofAttacker)
{
	APalPlayerState* pPalPlayerState = Config.GetPalPlayerState();
	APalPlayerCharacter* pPalPlayerCharacter = Config.GetPalPlayerCharacter();
	if (!pPalPlayerState || !pPalPlayerCharacter)
		return;

	FPalDamageInfo  info = FPalDamageInfo();
	info.AttackElementType = EPalElementType::Normal;
	info.Attacker = pPalPlayerCharacter;		//	@TODO: spoof attacker
	info.AttackerGroupID = Config.GetPalPlayerState()->IndividualHandleId.PlayerUId;
	info.AttackerLevel = 50;	
	info.AttackType = EPalAttackType::Weapon;
	info.bApplyNativeDamageValue = true;
	info.bAttackableToFriend = true;
	info.IgnoreShield = true;
	info.NativeDamageValue = damage;
	pPalPlayerState->SendDamage_ToServer(pTarget, info);
}

//	 NOTE: only targets pals
void DeathAura(__int32 dmgAmount, float mDistance, bool bIntensityEffect, bool bVisualAffect, EPalVisualEffectID visID)
{
	APalCharacter* pPalCharacter = Config.GetPalPlayerCharacter();
	if (!pPalCharacter)
		return;

	UPalCharacterParameterComponent* pParams = pPalCharacter->CharacterParameterComponent;
	if (!pParams)
		return;

	APalCharacter* pPlayerPal = pParams->OtomoPal;

	TArray<APalCharacter*> outPals;
	if (!Config.GetTAllPals(&outPals))
		return;

	DWORD palsCount = outPals.Count();
	for (auto i = 0; i < palsCount; i++)
	{
		APalCharacter* cEnt = outPals[i];
		
		if (!cEnt || !cEnt->IsA(APalMonsterCharacter::StaticClass()) || cEnt == pPlayerPal)
			continue;

		float distanceTo = GetDistanceToActor(pPalCharacter, cEnt);
		if (distanceTo > mDistance)
			continue;

		float dmgScalar = dmgAmount * (1.0f - distanceTo / mDistance);
		if (bIntensityEffect)
			dmgAmount = dmgScalar;

		UPalVisualEffectComponent* pVisComp = cEnt->VisualEffectComponent;
		if (bVisualAffect && pVisComp)
		{
			FPalVisualEffectDynamicParameter fvedp;
			if (!pVisComp->ExecutionVisualEffects.Count())
				pVisComp->AddVisualEffect_ToServer(visID, fvedp, 1);	//	uc: killer1478
		}
		SendDamageToActor(cEnt, dmgAmount);
	}
}

// credit: xCENTx
void TeleportAllPalsToCrosshair(float mDistance)
{
	TArray<APalCharacter*> outPals;
	Config.GetTAllPals(&outPals);
	DWORD palsCount = outPals.Count();
	for (int i = 0; i < palsCount; i++)
	{
		APalCharacter* cPal = outPals[i];

		if (!cPal || !cPal->IsA(APalMonsterCharacter::StaticClass()))
			continue;
		
		//	@TODO: displace with entity width for true distance, right now it is distance from origin
		//	FVector palOrigin;
		//	FVector palBounds;
		//	cPal->GetActorBounds(true, &palOrigin, &palBounds, false);
		//	float adj = palBounds.X * .5 + mDistance;

		ForgeActor(cPal, mDistance);
	}
}

// credit: xCENTx
void AddWaypointLocation(std::string wpName)
{
	APalCharacter* pPalCharacater = Config.GetPalPlayerCharacter();
	if (!pPalCharacater)
		return;

	FVector wpLocation = pPalCharacater->K2_GetActorLocation();
	FRotator wpRotation = pPalCharacater->K2_GetActorRotation();
	config::SWaypoint newWaypoint = config::SWaypoint("[WAYPOINT]" + wpName, wpLocation, wpRotation);
	Config.db_waypoints.push_back(newWaypoint);
}

// credit: xCENTx
//	must be called from a rendering thread with imgui context
void RenderWaypointsToScreen()
{
	APalCharacter* pPalCharacater = Config.GetPalPlayerCharacter();
	APalPlayerController* pPalController = Config.GetPalPlayerController();
	if (!pPalCharacater || !pPalController)
		return;

	ImDrawList* draw = ImGui::GetWindowDrawList();

	for (auto waypoint : Config.db_waypoints)
	{
		FVector2D vScreen;
		if (!pPalController->ProjectWorldLocationToScreen(waypoint.waypointLocation, &vScreen, false))
			continue;

		auto color = ImColor(1.0f, 1.0f, 1.0f, 1.0f);

		draw->AddText(ImVec2( vScreen.X, vScreen.Y ), color, waypoint.waypointName.c_str());
	}
}

///	OLDER METHODS
//SDK::FPalDebugOtomoPalInfo palinfo = SDK::FPalDebugOtomoPalInfo();
//SDK::TArray<SDK::EPalWazaID> EA = { 0U };
//void SpawnPal(char* PalName, bool IsMonster, int rank=1, int lvl = 1, int count=1)
//{
//    SDK::UKismetStringLibrary* lib = SDK::UKismetStringLibrary::GetDefaultObj();
//
//    //Convert FNAME
//    wchar_t  ws[255];
//    swprintf(ws, 255, L"%hs", PalName);
//    SDK::FName Name = lib->Conv_StringToName(SDK::FString(ws));
//    //Call
//    if (Config.GetPalPlayerCharacter() != NULL)
//    {
//        if (Config.GetPalPlayerCharacter()->GetPalPlayerController() != NULL)
//        {
//            if (Config.GetPalPlayerCharacter()->GetPalPlayerController())
//            {
//                if (Config.GetPalPlayerCharacter()->GetPalPlayerController()->GetPalPlayerState())
//                {
//                    if (IsMonster)
//                    {
//                        Config.GetPalPlayerCharacter()->GetPalPlayerController()->GetPalPlayerState()->RequestSpawnMonsterForPlayer(Name, count, lvl);
//                        return;
//                    }
//                    EA[0] = SDK::EPalWazaID::AirCanon;
//                    palinfo.Level = lvl;
//                    palinfo.Rank = rank;
//                    palinfo.PalName.Key = Name;
//                    palinfo.WazaList = EA;
//                    palinfo.PassiveSkill = NULL;
//                    Config.GetPalPlayerCharacter()->GetPalPlayerController()->GetPalPlayerState()->Debug_CaptureNewMonsterByDebugOtomoInfo_ToServer(palinfo);
//                }
//            }
//        }
//    }
//}