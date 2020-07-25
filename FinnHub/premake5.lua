workspace "FinnHub"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["curl"] = "FinnHub/vendor/curl/include"

project "FinnHub"

	location"FinnHub"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputDir .. "/%{prj.name}")
	objdir("bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "gepch.h"
	pchsource "FinnHub/src/gepch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/curl/include/**.h",
		"%{prj.name}/vendor/curl/lib/**.h"
	}

	libdirs
	{
		"FinnHub/vendor/curl/lib"
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
		defines {"GE_DEBUG"}
		runtime "Debug"
		symbols "on"
		links
		{
			"libcurl-d"
		}

	filter "configurations:Release"
		defines {"GE_RELEASE"}
		runtime "Release"
		optimize "on"
		links
		{
			"libcurl"
		}

	filter "configurations:Dist"
		defines {"GE_DIST"}
		runtime "Release"
		optimize "on"
		links
		{
			"libcurl"
		}
		
	project "TestApplication"
	location"TestApplication"
	kind "ConsoleApp"
	
	cppdialect "C++17"
	language "C++"
	staticruntime "On"


	targetdir("bin/" .. outputDir .. "/%{prj.name}")
	objdir("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"FinnHub/src",
	}

	links
	{
		"FinnHub"
	}

	filter "system:windows"
		systemversion "latest"

	defines
	{
	}


	filter "configurations:Debug"
		defines "GE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "GE_DIST"
		runtime "Release"
		optimize "on"

