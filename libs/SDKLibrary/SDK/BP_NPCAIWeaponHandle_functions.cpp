#pragma once

// Dumped with Dumper-7!


#include "../SDK.hpp"

namespace SDK
{
//---------------------------------------------------------------------------------------------------------------------
// FUNCTIONS
//---------------------------------------------------------------------------------------------------------------------


// BlueprintGeneratedClass BP_NPCAIWeaponHandle.BP_NPCAIWeaponHandle_C
// (None)

class UClass* UBP_NPCAIWeaponHandle_C::StaticClass()
{
	static class UClass* Clss = nullptr;

	if (!Clss)
		Clss = UObject::FindClassFast("BP_NPCAIWeaponHandle_C");

	return Clss;
}


// BP_NPCAIWeaponHandle_C BP_NPCAIWeaponHandle.Default__BP_NPCAIWeaponHandle_C
// (Public, ClassDefaultObject, ArchetypeObject, WasLoaded, LoadCompleted)

class UBP_NPCAIWeaponHandle_C* UBP_NPCAIWeaponHandle_C::GetDefaultObj()
{
	static class UBP_NPCAIWeaponHandle_C* Default = nullptr;

	if (!Default)
		Default = static_cast<UBP_NPCAIWeaponHandle_C*>(UBP_NPCAIWeaponHandle_C::StaticClass()->DefaultObject);

	return Default;
}

}


