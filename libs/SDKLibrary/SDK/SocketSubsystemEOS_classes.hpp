#pragma once

// Dumped with Dumper-7!


namespace SDK
{
//---------------------------------------------------------------------------------------------------------------------
// CLASSES
//---------------------------------------------------------------------------------------------------------------------

// 0x8 (0x848 - 0x840)
// Class SocketSubsystemEOS.NetDriverEOSBase
class UNetDriverEOSBase : public UIpNetDriver
{
public:
	bool                                         bIsPassthrough;                                    // 0x840(0x1)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                         bIsUsingP2PSockets;                                // 0x841(0x1)(ZeroConstructor, Config, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_F6[0x6];                                       // Fixing Size Of Struct [ Dumper-7 ]

	static class UClass* StaticClass();
	static class UNetDriverEOSBase* GetDefaultObj();

};

// 0x8 (0x33A0 - 0x3398)
// Class SocketSubsystemEOS.NetConnectionEOS
class UNetConnectionEOS : public UIpConnection
{
public:
	uint8                                        Pad_F8[0x8];                                       // Fixing Size Of Struct [ Dumper-7 ]

	static class UClass* StaticClass();
	static class UNetConnectionEOS* GetDefaultObj();

};

}


