workspace "Mathex"
	architecture "x86"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Mathex"
	location "Mathex"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	--pchheader "mxpch.h"
	--pchsource "Mathex/src/mxpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS" -- for all the old C header warnings
	}

	includedirs
	{
		"%{prj.name}/src"
	}
	
	filter "system:windows"
		systemversion "latest"

		defines
		{
			"EM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"

		defines 
		{
			"M_DEBUG",
			"M_ENABLE_ASSERTS",
			"M_ENABLE_LOGS",
			"M_ENABLE_EXCEPTIONS"
		}
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "M_RELEASE"
		runtime "Release"
		optimize "on"

project "Mathex-Tests"
		location "Mathex-Tests"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		nuget "Microsoft.googletest.v140.windesktop.msvcstl.static.rt-static:1.8.1"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "pch.h"
		pchsource "Mathex-Tests/src/pch.cpp"

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		defines
		{
			"WIN32",
			"_CONSOLE"
		}

		includedirs
		{
			"%{prj.name}/src",
			"Mathex/src",
			"packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-static.1.8.1/build/native/include"
		}

		links
		{
			"Mathex"
		}
		
		filter "configurations:Debug"
			buildoptions "/MTd"
			defines 
			{
				"_DEBUG"
			}
			links
			{
				"packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-static.1.8.1/lib/native/v140/windesktop/msvcstl/static/rt-static/x86/Debug/gtest_maind.lib"
			}

		filter "configurations:Release"
		buildoptions "/MT"
			defines 
			{
				"NDEBUG"
			}
			links
			{
				"packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-static.1.8.1/lib/native/v140/windesktop/msvcstl/static/rt-static/x86/Release/gtest_main.lib"
			}

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
		"%{prj.name}/src",
		"Mathex/src"
	}

	links
	{
		"Mathex"
	}
	
	filter "system:windows"
		systemversion "latest"

		defines
		{
			"M_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "M_DEBUG"
		runtime "Debug"
		symbols "on"


	filter "configurations:Release"
		defines "M_RELEASE"
		runtime "Release"
		optimize "on"
		inlining "Auto"
