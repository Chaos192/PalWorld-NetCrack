#pragma once

// Dumped with Dumper-7!


#include "../SDK.hpp"

namespace SDK
{
namespace Params
{
//---------------------------------------------------------------------------------------------------------------------
// PARAMETERS
//---------------------------------------------------------------------------------------------------------------------

// 0x4 (0x4 - 0x0)
// Function BP_AINPC_Combat_CommonState_Rest.BP_AINPC_Combat_CommonState_Rest_C.StateTick
struct UBP_AINPC_Combat_CommonState_Rest_C_StateTick_Params
{
public:
	float                                        DeltaTime;                                         // 0x0(0x4)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

// 0x1C (0x1C - 0x0)
// Function BP_AINPC_Combat_CommonState_Rest.BP_AINPC_Combat_CommonState_Rest_C.ExecuteUbergraph_BP_AINPC_Combat_CommonState_Rest
struct UBP_AINPC_Combat_CommonState_Rest_C_ExecuteUbergraph_BP_AINPC_Combat_CommonState_Rest_Params
{
public:
	int32                                        EntryPoint;                                        // 0x0(0x4)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                        Pad_3021[0x4];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	class UBP_AIAction_NPC_CombatBase_C*         CallFunc_GetCombatAIActionRef_BPAIActionNPCCombat; // 0x8(0x8)(ZeroConstructor, NoDestructor, UObjectWrapper, HasGetValueTypeHash)
	class AController*                           CallFunc_GetController_ReturnValue;                // 0x10(0x8)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	float                                        K2Node_Event_DeltaTime;                            // 0x18(0x4)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};

}
}


