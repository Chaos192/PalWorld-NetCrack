#pragma once

// Dumped with Dumper-7!


#include "../SDK.hpp"

namespace SDK
{
//---------------------------------------------------------------------------------------------------------------------
// FUNCTIONS
//---------------------------------------------------------------------------------------------------------------------


// BlueprintGeneratedClass BP_ActionDefenseWait_Wait.BP_ActionDefenseWait_Wait_C
// (None)

class UClass* UBP_ActionDefenseWait_Wait_C::StaticClass()
{
	static class UClass* Clss = nullptr;

	if (!Clss)
		Clss = UObject::FindClassFast("BP_ActionDefenseWait_Wait_C");

	return Clss;
}


// BP_ActionDefenseWait_Wait_C BP_ActionDefenseWait_Wait.Default__BP_ActionDefenseWait_Wait_C
// (Public, ClassDefaultObject, ArchetypeObject, WasLoaded, LoadCompleted)

class UBP_ActionDefenseWait_Wait_C* UBP_ActionDefenseWait_Wait_C::GetDefaultObj()
{
	static class UBP_ActionDefenseWait_Wait_C* Default = nullptr;

	if (!Default)
		Default = static_cast<UBP_ActionDefenseWait_Wait_C*>(UBP_ActionDefenseWait_Wait_C::StaticClass()->DefaultObject);

	return Default;
}

}


