workspace "Fountain"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Fountain/vendor/GLFW/include"
IncludeDir["Glad"] = "Fountain/vendor/Glad/include"
IncludeDir["ImGui"] = "Fountain/vendor/imgui"

include "Fountain/vendor/GLFW"
include "Fountain/vendor/Glad"
include "Fountain/vendor/imgui"

project "Fountain"
	location "Fountain"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ftpch.h"
	pchsource "Fountain/src/ftpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"

	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"FT_PLATFORM_WINDOWS",
			"FT_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "FT_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "FT_RELEASE"
		runtime "Release"
		symbols "On"

	filter "configurations:Dist"
		defines "FT_DIST"
		runtime "Release"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Fountain/vendor/spdlog/include",
		"Fountain/src"
	}

	links
	{
		"Fountain"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"FT_PLATFORM_WINDOWS",
		}

	
	filter "configurations:Debug"
		defines "FT_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "FT_RELEASE"
		runtime "Release"
		symbols "On"

	filter "configurations:Dist"
		defines "FT_DIST"
		runtime "Release"
		symbols "On"


