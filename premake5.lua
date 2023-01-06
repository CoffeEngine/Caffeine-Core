
workspace "Caffeine" 
    configurations { "Debug","Release" } 
   
    project "Caffeine-Core"   
        kind "StaticLib"  
        language "C"   
        uuid "6f788d01-ed35-4f0b-bbdd-860c7a311d9b"

        targetdir "build/%{prj.name}/bin/%{cfg.buildcfg}"
        objdir "build/%{prj.name}/obj/%{cfg.buildcfg}"
        
        files { "sources/**.h","sources/**.c" }
        includedirs {"headers"}
        
        filter "configurations:Debug" 
            defines { "DEBUG" }  
            symbols "On" 
        
        filter "configurations:Release" 
            defines { "NDEBUG" }      
            optimize "On"