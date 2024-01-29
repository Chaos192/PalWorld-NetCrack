#pragma once
#include "SDK.hpp"
#include "config.h"
#include "include/helper.h"
#include "include/Console.hpp"
#include "include/Game.hpp"
#include "include/D3D11Window.hpp"
#include "include/Hooking.hpp"
using namespace DX11_Base;

DWORD WINAPI MainThread_Initialize()
{
    g_Console = std::make_unique<Console>();
#if DEBUG
    g_Console->InitializeConsole("Debug Console");
    g_Console->printdbg("ImGui Hook - Initializing . . .\n\n", Console::Colors::DEFAULT);
#endif
    ///  ESTABLISH GAME DATA   
    g_GameData = std::make_unique<GameData>();
    g_GameVariables = std::make_unique<GameVariables>();

    ///  CREATE WINDOW AND ESTABLISH HOOKS
    g_D3D11Window = std::make_unique<D3D11Window>();
    g_Hooking = std::make_unique<Hooking>();
    g_Menu = std::make_unique<Menu>();
    g_Hooking->Hook();

#if DEBUG
    g_Console->printdbg("Main::Initialized\nUWorld:\t0x%llX\n", Console::Colors::green, Config.gWorld);
#endif

    ///  RENDER LOOP
    g_Running = TRUE;
    while (g_Running)
    {
        if (GetAsyncKeyState(VK_INSERT) & 1)
        {
            g_GameVariables->m_ShowMenu = !g_GameVariables->m_ShowMenu;
            g_GameVariables->m_ShowHud = !g_GameVariables->m_ShowMenu;
        
        }
    }

    ///  EXIT
    FreeLibraryAndExitThread(g_hModule, EXIT_SUCCESS);
    return EXIT_SUCCESS;
}