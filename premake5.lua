include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Fountain"
	architecture "x64"
	startproject "Fountainhead"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Fountain/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Fountain/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Fountain/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Fountain/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Fountain/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Fountain/vendor/entt/include"

group "Dependencies"
	include "vendor/premake"
	include "Fountain/vendor/GLFW"
	include "Fountain/vendor/Glad"
	include "Fountain/vendor/imgui"
group ""

include "Fountain"
include "Sandbox"
include "Fountainhead"