workspace "cookie-pong"
    location "build"
    configurations {"Debug", "Release"}

project "cookie-pong"
    kind "WindowedApp"
    language "C++"
    location "build"
    targetdir "bin/%{cfg.buildcfg}"

    includedirs {"include"}
    links {"SDL2main", "SDL2", "SDL2_mixer", "SDL2_ttf"}
    files {"**.h", "**.cc"}

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations.Release"
        defines {"NDEBUG"}
        optimize "On"