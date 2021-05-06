workspace "Fountain"
	architecture "x64"

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
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FT_PLATFORM_WINDOWS",
			"FT_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "FT_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "FT_RELEASE"
		buildoptions "/MD"
		symbols "On"

	filter "configurations:Dist"
		defines "FT_DIST"
		buildoptions "/MD"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FT_PLATFORM_WINDOWS",
		}

	
	filter "configurations:Debug"
		defines "FT_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "FT_RELEASE"
		buildoptions "/MD"
		symbols "On"

	filter "configurations:Dist"
		defines "FT_DIST"
		buildoptions "/MD"
		symbols "On"


