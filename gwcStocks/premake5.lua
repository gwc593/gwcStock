workspace "gwcStocks"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
--IncludeDir["GLFW"] = "gwcEngine/vendor/GLFW/include"


--include "gwcEngine/vendor/GLFW"

project "gwcStocks"

	location"gwcStocks"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputDir .. "/%{prj.name}")
	objdir("bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "gepch.h"
	pchsource "gwcStocks/src/gepch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",

	}

	includedirs
	{
		"%{prj.name}/src"
--		"%{IncludeDir.GLFW}",

	}
	
	links
	{

	}

	filter "system:windows"
		systemversion "latest"

	defines
	{

	}


	filter "configurations:Debug"
		defines {}
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines {}
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines {}
		runtime "Release"
		optimize "on"
