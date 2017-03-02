# CMake required version
cmake_minimum_required(VERSION 3.1)

# "Only interpret if() arguments as variables or keywords when unquoted."
cmake_policy(SET CMP0054 NEW)

# Set cmake build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
      "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
endif(NOT CMAKE_BUILD_TYPE)

# Options
option(SAMP_MAPANDREAS_USE_FOREIGN_EXTERNAL "Use foreign externals" OFF)
option(SAMP_MAPANDREAS_INCLUDE_PLUGIN "Include plugin to project" ON)

# Set project title
project(samp-plugin-mapandreas)

# Base path constants
set(SAMP_MAPANDREAS_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(SAMP_MAPANDREAS_BIN_ROOT ${CMAKE_CURRENT_BINARY_DIR})

# Set initial external directories
if ("${SAMP_MAPANDREAS_EXTERNAL}" STREQUAL "")
	set(SAMP_MAPANDREAS_EXTERNAL ${SAMP_MAPANDREAS_ROOT}/external)
endif()

# Module
set(CMAKE_MODULE_PATH
	${CMAKE_MODULE_PATH}
	${SAMP_MAPANDREAS_ROOT}/build/cmake
	${SAMP_MAPANDREAS_ROOT}/external/sampcmake
)

# Include externals
if (NOT SAMP_MAPANDREAS_USE_FOREIGN_EXTERNAL)
	include(MapAndreasExternal)
endif()

# Include other
include(MapAndreasFunctions)

# Add src
add_subdirectory(src)
