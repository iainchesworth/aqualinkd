# 
# Configuration for all sub-projects
# 

# Generate version-header
configure_file(version.h.in ${CMAKE_CURRENT_BINARY_DIR}/version.h @ONLY)

# Define project options
option(USE_DEBUG "Build a debug version of Aqualinkd" OFF)
if(USE_DEBUG)
	add_definitions(-DAQ_DEBUG -DAQ_TM_DEBUG)
endif()

option(SUPPORT_RS16 "Enable support for the RS16 panel" ON)
if(SUPPORT_RS16)
	add_definitions(-DAQ_RS16)
endif()

option(SUPPORT_PDA "Enable support for PDA" ON)
if(SUPPORT_PDA)
	add_definitions(-DAQ_PDA)
endif()

option(SUPPORT_ONETOUCH "Enable support for OneTouch" ON)
if(SUPPORT_ONETOUCH)
	add_definitions(-DAQ_ONETOUCH)
endif()

option(SUPPORT_IAQTOUCH "Enable support for iAqualink" ON)
if(SUPPORT_IAQTOUCH)
	add_definitions(-DAQ_IAQTOUCH)
endif()

# 
# Sub-projects
# 

set(IDE_FOLDER "")
add_subdirectory(libaqualinkd)
add_subdirectory(aqualinkd)
add_subdirectory(log-reader)
#add_subdirectory(player)
add_subdirectory(serial-logger)

# 
# Deployment
# 

# Deploy generated headers
#install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${META_PROJECT_NAME} DESTINATION include COMPONENT dev)
