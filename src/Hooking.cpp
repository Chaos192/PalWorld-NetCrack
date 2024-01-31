#include "../pch.h"
#include "../include/Hooking.hpp"
namespace DX11_Base {
	Hooking::Hooking()
	{
		MH_Initialize();
#if DEBUG
		g_Console->printdbg("Hooking::Initialized\n", Console::Colors::pink);
#endif
		return;
	}

	Hooking::~Hooking()
	{
		MH_RemoveHook(MH_ALL_HOOKS);
	}

	void Hooking::Hook()
	{
		//������ע��HOOK
		g_GameVariables->Init();
		g_D3D11Window->Hook();
		Config.Init();
		MH_EnableHook(MH_ALL_HOOKS);
#if DEBUG
		g_Console->printdbg("Hooking::Hook Initialized\n", Console::Colors::pink);
#endif
		return;
	}

	void Hooking::Unhook()
	{
		g_D3D11Window->Unhook();
		MH_DisableHook((Tick)(Config.ClientBase + Config.offset_Tick));
		MH_RemoveHook((Tick)(Config.ClientBase + Config.offset_Tick));
		g_Console->DestroyConsole();
		g_Running = FALSE;
		return;
	}
}
