solution "Graph"
    configurations  { "Debug", "Release" }
        if os.get() == "windows" then
            platforms { "x32", "x64"}
        elseif os.get() == "macosx" then
            platforms { "Universal" }
        end

project "Graph"
    kind        "ConsoleApp"
    language    "C++"

files
{
    "src/*.h",
    "src/*.cpp"
}

pchheader "src/PCH.h"
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



