cmake_minimum_required (VERSION 2.6)
set(CMAKE_MODULE_PATH ../../cmake)
project (tshapes)
include (MacroOpenSplice)
include (osmacros)
find_package (OpenSplice REQUIRED)
find_package (Boost REQUIRED)
find_package (SimD REQUIRED)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${BOOST_INCLUDE_DIRS}
  ${OpenSplice_INCLUDE_DIRS}
  ${SimD_INCLUDE_DIRS}
)


set (idls ishape.idl)


foreach(idl ${idls})
	OpenSplice_IDLGEN (${idl})
        string (REGEX REPLACE "\(.*\).idl" "gen/\\1.cpp" VARS_1 ${idl})
        string (REGEX REPLACE "\(.*\).idl" "gen/\\1.h" VARS_2 ${idl})
        string (REGEX REPLACE "\(.*\).idl" "gen/\\1Dcps.cpp" VARS_3 ${idl})
        string (REGEX REPLACE "\(.*\).idl" "gen/\\1Dcps.h" VARS_4 ${idl})
        string (REGEX REPLACE "\(.*\).idl" "gen/\\1Dcps_impl.cpp" VARS_5 ${idl})
        string (REGEX REPLACE "\(.*\).idl" "gen/\\1Dcps_impl.h" VARS_6 ${idl})
        string (REGEX REPLACE "\(.*\).idl" "gen/\\1SplDcps.cpp" VARS_7 ${idl})
        string (REGEX REPLACE "\(.*\).idl" "gen/\\1SplDcps.h" VARS_8 ${idl})
        string (REGEX REPLACE "\(.*\).idl" "gen/ccpp_\\1.h" VARS_9 ${idl})
	set(OpenSplice_DATAMODEL ${OpenSplice_DATAMODEL} ${VARS_1} ${VARS_2} ${VARS_3} ${VARS_4} ${VARS_5} ${VARS_6} ${VARS_7} ${VARS_8} ${VARS_9})
endforeach(idl)

set (PUB_SOURCES
 tspub.cpp
 util.cpp
)
set (SUB_SOURCES
 tssub.cpp
 util.cpp
)

set (ASUB_SOURCES
  tssub-async.cpp
  util.cpp
)

set (PUB_EXE tspub)
set (SUB_EXE tssub)
set (ASUB_EXE tssub-async)
set (DATAMODEL datamodel)

add_executable (${PUB_EXE} ${PUB_SOURCES})
add_executable (${SUB_EXE} ${SUB_SOURCES})
add_executable (${ASUB_EXE} ${ASUB_SOURCES})
add_library (${DATAMODEL} STATIC ${OpenSplice_DATAMODEL})
#add_library (${DATAMODEL} SHARED ${OpenSplice_DATAMODEL})

add_definitions (
 ${OpenSplice_DEFINITIONS}
 ${DEFINITIONS}
)

# Linkar contra librerias deseadas.
target_link_libraries (
  ${DATAMODEL} 
  ${OpenSplice_LIBRARIES}
  ${BOOST_LIBRARIES}
  ${SimD_LIBRARIES}
)

target_link_libraries (${PUB_EXE}
 ${OpenSplice_LIBRARIES}
 ${BOOST_LIBRARIES}
 ${DATAMODEL} 
)

target_link_libraries (${SUB_EXE}
 ${OpenSplice_LIBRARIES}
 ${BOOST_LIBRARIES}
 ${DATAMODEL}
)

target_link_libraries (${ASUB_EXE}
${OpenSplice_LIBRARIES}
${BOOST_LIBRARIES}
${DATAMODEL}
)
