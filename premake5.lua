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
IncludeDir["glm"] = "Fountain/vendor/glm"

include "Fountain/vendor/GLFW"
include "Fountain/vendor/Glad"
include "Fountain/vendor/imgui"

project "Fountain"
	location "Fountain"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ftpch.h"
	pchsource "Fountain/src/ftpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/**.hpp",
		"%{prj.name}/vendor/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"FT_PLATFORM_WINDOWS",
			"FT_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "FT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "FT_RELEASE"
		runtime "Release"
		symbols "on"

	filter "configurations:Dist"
		defines "FT_DIST"
		runtime "Release"
		symbols "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"Fountain/src",
		"Fountain/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Fountain"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"FT_PLATFORM_WINDOWS",
		}

	
	filter "configurations:Debug"
		defines "FT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "FT_RELEASE"
		runtime "Release"
		symbols "on"

	filter "configurations:Dist"
		defines "FT_DIST"
		runtime "Release"
		symbols "on"

