# Set the proper module path 
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include (osmacros)

# Find required packages
find_package (OpenSplice REQUIRED)

# SimD uses Signal2 introduced in 1.39.0
SET (Boost_ADDITIONAL_VERSIONS "1.46.1" "1.46.0" "1.45.0" "1.44.0" "1.43.0" "1.43" "1.42.0" "1.42" "1.41.0" "1.41")
# MSVC will auto-link libraries so dont need to find them
IF (MSVC)
  find_package (Boost 1.39.0 REQUIRED)
ELSE (MSVC)
  find_package (Boost 1.39.0 REQUIRED thread signals program_options system)
ENDIF (MSVC)

# Set includes directories
include_directories(
  ${PROJECT_SOURCE_DIR}/src
  ${Boost_INCLUDE_DIR}
  ${OpenSplice_INCLUDE_DIRS}
)

link_directories(
  ${Boost_LIBRARY_DIRS}
)

# SimD source files
file (GLOB SimD_SOURCES *.cpp ./peer/*.cpp)

# install include files
#install (DIRECTORY "${PROJECT_SOURCE_DIR}/src/dds"
#     DESTINATION include PATTERN "*~" EXCLUDE PATTERN "*svn*" EXCLUDE )

#install (files "${PROJECT_SOURCE_DIR}/src/dds"
#     DESTINATION include FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY "${PROJECT_SOURCE_DIR}/src/dds" DESTINATION include PATTERN "*.hpp")

#install documentation
#install (DIRECTORY "${PROJECT_SOURCE_DIR}/docs"
#DESTINATION . PATTERN "*~" EXCLUDE PATTERN "*svn*" EXCLUDE )

# C++ Options
add_definitions( ${DEFINITIONS} )
# Options specifically for building the library
add_definitions( -DSIMD_API_BUILD )

# library setup
add_library(lib${PROJECT_NAME}  ${SimD_SOURCES} ${OpenSplice_LIBRARIES})

target_link_libraries (lib${PROJECT_NAME} ${OpenSplice_LIBRARIES} ${Boost_LIBRARIES})

add_custom_target( lib DEPENDS lib${PROJECT_NAME} )

# change lib_target properties
set_target_properties( lib${PROJECT_NAME} PROPERTIES
   # create *nix style library versions + symbolic links
   VERSION ${${PROJECT_NAME}_VERSION}
   SOVERSION ${${PROJECT_NAME}_SOVERSION}
   # allow creating static and shared libs without conflicts
   CLEAN_DIRECT_OUTPUT 1
   # avoid conflicts between library and binary target names
   OUTPUT_NAME ${PROJECT_NAME} )

install( TARGETS lib${PROJECT_NAME} DESTINATION lib PERMISSIONS
    OWNER_READ OWNER_WRITE OWNER_EXECUTE
    GROUP_READ GROUP_EXECUTE
    WORLD_READ WORLD_EXECUTE)


# force some variables that could be defined in the command line to be written to cache 
set( BUILD_SHARED_LIBS "${BUILD_SHARED_LIBS}" CACHE BOOL
   "Set to OFF to build static libraries" FORCE )
set( CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}" CACHE PATH
   "Where to install ${PROJECT_NAME}" FORCE )
set( CMAKE_BUILD_TYPE "${CMAKE_BUILD_TYPE}" CACHE STRING
   "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE )
set( CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" CACHE PATH
   "Path to custom CMake Modules" FORCE )
set( INSTALL_DOC "${INSTALL_DOC}" CACHE BOOL
   "Set to OFF to skip build/install Documentation" FORCE )

# display status message for important variables
MESSAGE( STATUS )
MESSAGE( STATUS "-------------------------------------------------------------------------------" )
MESSAGE( STATUS "BUILD_SHARED_LIBS = ${BUILD_SHARED_LIBS}" )
MESSAGE( STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}" )
MESSAGE( STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}" )
MESSAGE( STATUS "CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}" )
MESSAGE( STATUS "${PROJECT_NAME}_DEPENDS = \"${${PROJECT_NAME}_DEPENDS}\"" )
MESSAGE( STATUS "BUILD_WITH = \"${BUILD_WITH}\"" )
MESSAGE( STATUS "INSTALL_DOC = ${INSTALL_DOC}" )
MESSAGE( STATUS "Change a value with: cmake -D<Variable>=<Value>" )
MESSAGE( STATUS "-------------------------------------------------------------------------------" )
MESSAGE( STATUS "SimD v${${PROJECT_NAME}_SOVERSION}")
MESSAGE( STATUS "-------------------------------------------------------------------------------" )
MESSAGE( STATUS )
