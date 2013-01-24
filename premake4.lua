solution "Graph"
	configurations	{ "Debug", "Release" }
    platforms { "x32", "x64", "Universal" }

project "Graph"
	kind		"ConsoleApp"
	language	"C++"

files
{
	"src/*.h",
	"src/*.cpp"
}

pchheader "PCH.h"
pchsource "src/PCH.cpp"

configuration "windows"
    buildoptions { "-Zm256" }
    includedirs{
        "$(BOOSTDIR)"
    }

   
configuration "macosx"
    includedirs{
        "../boost",
    }



