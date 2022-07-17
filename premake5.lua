include "./scripts/premake.utils.lua"

-- Workspace for lib
workspace "Win64Tools"
    w64t_setup_workspace()

    -- w64t library
    group "Lib"
        include "./src/w64t/premake5.lua"
    group ""

    -- Code samples
    group "Example"
        include "./src/examples/dialogs/premake5.lua"
    group ""
