cmake_minimum_required(VERSION 2.8)

file(GLOB_RECURSE external_header include/*.h)
file(GLOB_RECURSE internal_header src/*.h)
file(GLOB_RECURSE srcs src/*.cpp)

add_library(${exe_name} ${external_header} ${internal_header} ${srcs})

# source filters
file(GLOB internal_header ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)
file(GLOB srcs ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
source_group(source FILES ${internal_header})
source_group(source FILES ${srcs})
SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR}/src)
FOREACH(subdir ${SUBDIRS})
	file(GLOB_RECURSE internal_module_header ${CMAKE_CURRENT_SOURCE_DIR}/src/${subdir}/*.h)
	file(GLOB_RECURSE module_srcs ${CMAKE_CURRENT_SOURCE_DIR}/src/${subdir}/*.cpp)
	source_group(source\\${subdir} FILES ${internal_module_header})
	source_group(source\\${subdir} FILES ${module_srcs})
ENDFOREACH()

# include filter
file(GLOB external_header ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
source_group(include FILES ${external_header})
SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)
FOREACH(subdir ${SUBDIRS})
	file(GLOB_RECURSE external_module_header ${CMAKE_CURRENT_SOURCE_DIR}/include/${subdir}/*.h)
	source_group(include\\${subdir} FILES ${external_module_header})
ENDFOREACH()

set_target_properties(${exe_name} PROPERTIES COMPILE_DEFINITIONS "COMPILING_DLL=1")
set_target_properties (${exe_name} PROPERTIES FOLDER lib)
include_directories(include)
include_directories(src)

### OpenCV ### 
set(save_debug_postfix ${CMAKE_DEBUG_POSTFIX})
set(CMAKE_DEBUG_POSTFIX d)


if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "AMD64")
	set(arch x64)
endif()

if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "IX86")
	set(arch x86)
endif()

if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "ARM")
	set(arch arm)
endif()

file(GLOB modules ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/OpenCv/${arch}/lib/*.lib)

FOREACH(module_name ${modules})
target_link_libraries(${exe_name} ${module_name})
ENDFOREACH()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/OpenCv/include)


set(CMAKE_DEBUG_POSTFIX ${save_debug_postfix})

