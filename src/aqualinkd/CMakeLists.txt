# Target name
set(target aqualinkd)

set(SOURCE_FILES 
  aqualinkd.c 
  aq_programmer.c 
  net_services.c 
  net_services_habridge.c 
  json_messages.c 
  devices_jandy.c 
  devices_pentair.c 
  color_lights.c 
  serialadapter.c 
  mongoose.c 
  timespec_subtract.c
)

# Create namespaced alias
add_executable(${target} ${SOURCE_FILES})
add_executable(${META_PROJECT_NAME}::${target} ALIAS ${target})

# 
# Project options
# 

set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
    FOLDER "${IDE_FOLDER}"
)

if(SUPPORT_PDA)
    target_sources(${target}
        PRIVATE
        pda.c 
        pda_menu.c 
        pda_aq_programmer.c
    )
endif()

if(SUPPORT_ONETOUCH)
    target_sources(${target}
        PRIVATE
        onetouch.c 
        onetouch_aq_programmer.c
    )
endif()

if(SUPPORT_IAQTOUCH)
    target_sources(${target}
        PRIVATE
        iaqtouch.c 
        iaqtouch_aq_programmer.c
    )
endif()

# 
# Include directories
# 

target_include_directories(${target}
    PRIVATE
    ${DEFAULT_INCLUDE_DIRECTORIES}
    ${PROJECT_BINARY_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_BINARY_DIR}/
)

# 
# Libraries
# 

if(WIN32)

  # Add support for GETOPT on Windows
  find_path(GETOPT_INCLUDE_DIR getopt.h)
  find_library(GETOPT_LIBRARY NAMES wingetopt getopt)
  if (GETOPT_INCLUDE_DIR AND GETOPT_LIBRARY)
    include_directories(SYSTEM ${GETOPT_INCLUDE_DIR})
    target_link_libraries(${target} PRIVATE ${GETOPT_LIBRARY})
  else()
    message(ERROR "Can not find getopt library for Windows.")
  endif()

endif()

target_link_libraries(${target}
    PRIVATE
    ${DEFAULT_LIBRARIES}
    ${META_PROJECT_NAME}::libaqualinkd
)

# 
# Compile definitions
# 

target_compile_definitions(${target}
    PRIVATE
    ${DEFAULT_COMPILE_DEFINITIONS}
    "-DMG_DISABLE_MD5"
    "-DMG_DISABLE_HTTP_DIGEST_AUTH"
    "-DMG_DISABLE_MD5"
    "-DMG_DISABLE_JSON_RPC"
)

# 
# Compile options
# 

target_compile_options(${target}
    PRIVATE
    ${DEFAULT_COMPILE_OPTIONS}
)

# 
# Linker options
# 

target_link_libraries(${target}
    PRIVATE
    ${DEFAULT_LINKER_OPTIONS}
)

# 
# Deployment
# 

# Executable
install(TARGETS ${target}
    RUNTIME DESTINATION ${INSTALL_BIN} COMPONENT runtime
    BUNDLE  DESTINATION ${INSTALL_BIN} COMPONENT runtime
)
