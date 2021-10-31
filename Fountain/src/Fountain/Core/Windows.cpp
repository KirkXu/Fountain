#include "ftpch.h"
#include "Fountain/Core/Window.h"

#ifdef FT_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Fountain
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef FT_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		FT_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}