#pragma once

// Dumped with Dumper-7!


namespace SDK
{
//---------------------------------------------------------------------------------------------------------------------
// CLASSES
//---------------------------------------------------------------------------------------------------------------------

// 0x8 (0x50 - 0x48)
// BlueprintGeneratedClass BP_Status_AttackUP.BP_Status_AttackUP_C
class UBP_Status_AttackUP_C : public UPalStatusBase
{
public:
	struct FPointerToUberGraphFrame              UberGraphFrame;                                    // 0x48(0x8)(ZeroConstructor, Transient, DuplicateTransient)

	static class UClass* StaticClass();
	static class UBP_Status_AttackUP_C* GetDefaultObj();

	void OnLoaded_FD22363D4A5A9DE9CE4C0BABF4CAA7C0(class UObject* Loaded);
	void OnBeginStatus();
	void OnEndStatus();
	void ExecuteUbergraph_BP_Status_AttackUP(int32 EntryPoint, class UObject* K2Node_CustomEvent_Loaded, class UObject* Temp_object_Variable, class UNiagaraSystem* K2Node_DynamicCast_AsNiagara_System, bool K2Node_DynamicCast_bSuccess, class AActor* CallFunc_GetOwner_ReturnValue, class USceneComponent* CallFunc_K2_GetRootComponent_ReturnValue, FDelegateProperty_ K2Node_CreateDelegate_OutputDelegate, class UNiagaraComponent* CallFunc_SpawnSystemAttached_ReturnValue, class AActor* CallFunc_GetOwner_ReturnValue_1, class UPalCharacterParameterComponent* CallFunc_GetComponentByClass_ReturnValue, class AActor* CallFunc_GetOwner_ReturnValue_2, class UPalCharacterParameterComponent* CallFunc_GetComponentByClass_ReturnValue_1);
};

}


