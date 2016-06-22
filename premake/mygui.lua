project 'MyGUI'

	kind 'StaticLib'
	configure_lib_targetdir()
	targetname ('MyGUI-' .. platform_dir)

	files {
		sandbox_dir .. '/external/MyGUI/MyGUIEngine/**.h',
		sandbox_dir .. '/external/MyGUI/MyGUIEngine/**.cpp'
	}

	sysincludedirs {
		sandbox_dir .. '/external/MyGUI/MyGUIEngine/include',
		sandbox_dir .. '/include',
	}

	if os.is('windows') then
		defines 'MYGUI_CONFIG_INCLUDE="../../../sandbox/mygui/sb_mygui_config.h"'
	else
		defines 'MYGUI_CONFIG_INCLUDE="<sb_mygui_config.h>"'
	end