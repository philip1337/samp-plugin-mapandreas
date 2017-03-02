include(AMXConfig)
include(AddSAMPPlugin)

# Natives
set(SOURCE_NATIVES
	natives.cpp
	natives.h
)

# Map Andreras
set(SOURCE_MAPANDREAS
	MapAndreas.cpp
)

set(HEADER_MAPANDREAS
	MapAndreas.h
)

# Plugin stuff
set(SOURCE_PLUGIN_MAPANDREAS
	plugin.cpp
	plugin.def
)


# Plugin
mapandreas_add_library(mapandreas-lib
  ${SOURCE_MAPANDREAS}
  ${HEADER_MAPANDREAS}
)

# Plugin
mapandreas_add_library(mapandreas-plugin-lib
  ${SOURCE_MAPANDREAS}
  ${HEADER_MAPANDREAS}
  ${SOURCE_NATIVES}
)

# Plugin
if (SAMP_MAPANDREAS_INCLUDE_PLUGIN)
	mapandreas_add_samp_plugin(mapandreas
	  ${SOURCE_PLUGIN_MAPANDREAS}
	  ${SOURCE_MAPANDREAS}
	  ${HEADER_MAPANDREAS}
	  ${SOURCE_NATIVES}
	)
endif()

