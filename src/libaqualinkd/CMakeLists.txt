# Target name
set(target libaqualinkd)

set(SOURCE_FILES
  aq_panel.c
  aq_serial.c 
  config.c
  utils.c 
  packetLogger.c   
  rs_msg_utils.c
)

# Create namespaced alias
add_library(${target} STATIC ${SOURCE_FILES} "types/protocol_types.h")
add_library(${META_PROJECT_NAME}::${target} ALIAS ${target})

# Export library for downstream projects
export(TARGETS ${target} NAMESPACE ${META_PROJECT_NAME}:: FILE ${PROJECT_BINARY_DIR}/cmake/${target}/${target}-export.cmake)

# 
# Project options
# 

set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
    FOLDER "${IDE_FOLDER}"
    VERSION ${META_VERSION}
    SOVERSION ${META_VERSION_MAJOR}
)

# 
# Include directories
# 

target_include_directories(${target}
    PRIVATE
    ${PROJECT_BINARY_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_BINARY_DIR}/

    PUBLIC
    ${DEFAULT_INCLUDE_DIRECTORIES}

    $<$<BOOL:${VTune_FOUND}>:${VTune_INCLUDE_DIRS}>

    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/>
    $<INSTALL_INTERFACE:include>
)

# 
# Libraries
# 

find_package(Threads REQUIRED)
#find_package(libwebsockets REQUIRED)

if(WIN32)

  find_package(unofficial-libconfuse CONFIG REQUIRED)
  target_link_libraries(${target} PUBLIC unofficial::libconfuse::libconfuse)
  
  find_package(json-c CONFIG REQUIRED)
  target_link_libraries(${target} PUBLIC json-c::json-c)
   
  # Add support for TinyCThread on Windows
  find_path(TINYCTHREAD_INCLUDE_DIR tinycthread.h)
  find_library(TINYCTHREAD_LIBRARY NAMES tinycthread)
  if (TINYCTHREAD_INCLUDE_DIR AND TINYCTHREAD_LIBRARY)
    target_include_directories(${target} SYSTEM PUBLIC ${TINYCTHREAD_INCLUDE_DIR})
    target_link_libraries(${target} PUBLIC ${TINYCTHREAD_LIBRARY})
  else()
    message(ERROR "Can not find the TinyCThread library for Windows.")
  endif()

  # Add support for the Win32 socket libraries
  find_library(WS2_32_LIBRARIES ws2_32)
  find_library(IPHLPAPI_LIBRARIES iphlpapi)
  if(WS2_32_LIBRARIES AND IPHLPAPI_LIBRARIES)
    target_link_libraries(${target} PUBLIC ${WS2_32_LIBRARIES})
    target_link_libraries(${target} PUBLIC ${IPHLPAPI_LIBRARIES})
  else()
    message(ERROR "Can not find socket libraries for Windows.")
  endif()

else()

  #find_package(libconfuse REQUIRED)
  #target_link_libraries(${target} PUBLIC ${LIBCONFUSE_LIBRARY})

  find_package(libjson-c REQUIRED) 
  target_link_libraries(${target} PUBLIC ${LIBJSON_C_LIBRARIES})
  
  #find_package(libm REQUIRED)
  #target_link_libraries(${target} PUBLIC ${LIBM_LIBRARIES})

endif()

target_link_libraries(${target}
    PRIVATE

    PUBLIC
    ${DEFAULT_LIBRARIES}
    Threads::Threads
    ${LIBWEBSOCKETS_LIBRARIES}

    $<$<BOOL:${VTune_FOUND}>:${VTune_LIBRARIES}>

    INTERFACE
)

# 
# Compile definitions
# 

target_compile_definitions(${target}
    PRIVATE

    PUBLIC
    ${DEFAULT_COMPILE_DEFINITIONS}

    INTERFACE
)

# 
# Compile options
# 

target_compile_options(${target}
    PRIVATE

    PUBLIC
    ${DEFAULT_COMPILE_OPTIONS}

    INTERFACE
)


# 
# Linker options
# 

target_link_libraries(${target}
    PRIVATE

    PUBLIC
    ${DEFAULT_LINKER_OPTIONS}

    INTERFACE
)

# 
# Deployment
# 

# Library
#install(TARGETS ${target}
#    EXPORT  "${target}-export"            COMPONENT dev
#    RUNTIME DESTINATION ${INSTALL_BIN}    COMPONENT runtime
#    LIBRARY DESTINATION ${INSTALL_SHARED} COMPONENT runtime
#    ARCHIVE DESTINATION ${INSTALL_LIB}    COMPONENT dev
#)

# CMake config
#install(EXPORT ${target}-export
#    NAMESPACE   ${META_PROJECT_NAME}::
#    DESTINATION ${INSTALL_CMAKE}/${target}
#    COMPONENT   dev
#)
