function(mapandreas_add_samp_plugin name)
	# Add plugin
	add_samp_plugin(${name} ${ARGN})

	# Add libraries
	target_link_libraries(${name} sampsdk)

	# Directories
	target_include_directories(${name} PRIVATE ${SAMP_MAPANDREAS_EXTERNAL})			# Include externals

	# Plattform specified definitions
	if (WIN32)
		target_compile_definitions(
			${name}
			PRIVATE
			_CRT_SECURE_NO_WARNINGS
			NOMINMAX
			WIN32
		)
	else()
		target_compile_definitions(
			${name}
			PRIVATE
			LINUX
			NDEBUG
		)
	endif()	
endfunction()

function(mapandreas_add_library name)
	# Add plugin
	add_library(${name} ${ARGN})

	set_target_properties(${name} PROPERTIES PREFIX "")

	if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
		set_property(TARGET ${name} APPEND_STRING PROPERTY COMPILE_FLAGS " -m32")
		set_property(TARGET ${name} APPEND_STRING PROPERTY LINK_FLAGS    " -m32")
	endif()

	if(CMAKE_COMPILER_IS_GNUCXX)
		set_property(TARGET ${name} APPEND_STRING PROPERTY
				 COMPILE_FLAGS " -Wno-attributes")
	endif()

	if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
		set_property(TARGET ${name} APPEND_STRING PROPERTY
				 COMPILE_FLAGS " -Wno-ignored-attributes")
	endif()

	if(WIN32 AND CMAKE_COMPILER_IS_GNUCC)
		set_property(TARGET ${name} APPEND_STRING PROPERTY
				 LINK_FLAGS " -Wl,--enable-stdcall-fixup")
	endif()

	if(CYGWIN)
		set_property(TARGET ${name} APPEND PROPERTY COMPILE_DEFINITIONS "WIN32")
		set_property(TARGET ${name} APPEND_STRING PROPERTY LINK_FLAGS " -Wl,--kill-at")
	elseif(UNIX AND NOT WIN32 AND NOT APPLE)
		set_property(TARGET ${name} APPEND PROPERTY COMPILE_DEFINITIONS "LINUX")
	endif()

	if(MINGW)
		# Work around missing #include <stddef.h> in <SDK>/amx/amx.h.
		set_property(TARGET ${name} APPEND_STRING PROPERTY COMPILE_FLAGS " -include stddef.h")
	endif()
	
	# Add libraries
	target_link_libraries(${name} sampsdk)

	# Directories
	target_include_directories(${name} PRIVATE ${SAMP_MAPANDREAS_EXTERNAL})			# Include externals

	# Plattform specified definitions
	if (WIN32)
		target_compile_definitions(
			${name}
			PRIVATE
			_CRT_SECURE_NO_WARNINGS
			NOMINMAX
			WIN32
		)
	else()
		target_compile_definitions(
			${name}
			PRIVATE
			LINUX
			NDEBUG
		)
	endif()	
	
	# Target
	target_compile_features(${name}
		PUBLIC
			cxx_variadic_templates
			cxx_nullptr
		PRIVATE
			cxx_lambdas
	)
endfunction()

