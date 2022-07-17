-- Setup basic workspace
function w64t_setup_workspace()
    configurations { "Debug", "Release" }
    architecture "x64"
end

-- Common shared configuration
function w64t_setup_generic(name, path)
    -- Metadata
    location("%{wks.location}/" .. path)
    targetname(name)
    files { 
        "%{prj.location}/**.lua",
        "%{prj.location}/**.h", 
        "%{prj.location}/**.hh", 
        "%{prj.location}/**.hpp",
        "%{prj.location}/**.c",  
        "%{prj.location}/**.cc", 
        "%{prj.location}/**.cpp", 
        "%{prj.location}/**.cxx"  
    }

    -- Output location
    targetdir "%{wks.location}/build/%{cfg.architecture}-%{cfg.buildcfg}/bin/"
    debugdir "%{wks.location}"
    objdir "%{wks.location}/build/%{cfg.architecture}-%{cfg.buildcfg}/obj/%{prj.name}/"

    -- Language
    language "C++"
    cppdialect "C++17"

    -- Include from project
    includedirs { "%{prj.location}" }

    -- Default DEBUG/NDEBUG
    filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
    filter {}
    filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
    filter {}
end

-- Configures shared libary (w64t)
function w64t_setup_lib(name, path)
    w64t_setup_generic(name, path)
    kind("StaticLib")

end

-- Configures exe (example)
function w64t_setup_example(name, path)
    w64t_setup_generic(name, path)
    kind("ConsoleApp")

    includedirs { "%{wks.location}/src/w64t/" }
    libdirs { "%{wks.location}/build/%{cfg.architecture}-%{cfg.buildcfg}/bin/" }
    links { "w64t" }
end
