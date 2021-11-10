project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Fountain/vendor/spdlog/include",
		"%{wks.location}/Fountain/src",
		"%{wks.location}/Fountain/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Fountain"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "FT_DEBUG"
		runtime "Debug"
		symbols "on"

		postbuildcommands
		{
			"{COPY} \"%{LibraryDir.VulkanSDK_DebugDLL}\" \"%{cfg.targetdir}\""
		}

	filter "configurations:Release"
		defines "FT_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "FT_DIST"
		runtime "Release"
		optimize "on"
