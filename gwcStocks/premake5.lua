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
IncludeDir["curl"] = "gwcStocks/vendor/curl/include"

project "gwcStocks"

	location"gwcStocks"
	kind "ConsoleApp"
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
		"%{prj.name}/vendor/curl/include/**.h",
		"%{prj.name}/vendor/curl/lib/**.h"
	}

	libdirs
	{
		"gwcStocks/vendor/curl/lib"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.curl}"
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
		links
		{
			"libcurl-d"
		}

	filter "configurations:Release"
		defines {}
		runtime "Release"
		optimize "on"
		links
		{
			"libcurl"
		}

	filter "configurations:Dist"
		defines {}
		runtime "Release"
		optimize "on"
		links
		{
			"libcurl"
		}
