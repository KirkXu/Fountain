include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Fountain"
	architecture "x86_64"
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

group "Dependencies"
	include "vendor/premake"
	include "Fountain/vendor/GLFW"
	include "Fountain/vendor/Glad"
	include "Fountain/vendor/imgui"
	include "Fountain/vendor/yaml-cpp"
group ""

include "Fountain"
include "Sandbox"
include "Fountainhead"
