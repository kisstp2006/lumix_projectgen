project "projectgen"
	libType()
	files { 
		"src/**.c",
		"src/**.cpp",
		"src/**.h",
		"genie.lua"
	}
	defines { "BUILDING_projectgen" }
	links { "engine" }
	defaultConfigurations()

linkPlugin("projectgen")