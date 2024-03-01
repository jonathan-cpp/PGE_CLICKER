# client/CMakeLists.txt

add_executable(${CLIENT_TARGET_NAME}
    # Client related source files
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/Client.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/managers/SceneManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/scenes/MainMenuScene.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/systems/RenderSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/systems/CollectorSystem.cpp

    # Common source files
)

target_include_directories(${CLIENT_TARGET_NAME} PUBLIC
    # Client related includes
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core
    ${CMAKE_CURRENT_SOURCE_DIR}/src/interfaces
    ${CMAKE_CURRENT_SOURCE_DIR}/src/components
    ${CMAKE_CURRENT_SOURCE_DIR}/src/managers
    ${CMAKE_CURRENT_SOURCE_DIR}/src/scenes
    ${CMAKE_CURRENT_SOURCE_DIR}/src/systems

    # Common includes
)

#=========================================================================================
# Link external libraries
#=========================================================================================

# EnTT
target_include_directories(${CLIENT_TARGET_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/libs/entt)

# PixelGameEngine
target_sources(${CLIENT_TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/libs/pge/olcPixelGameEngine.cpp)
target_include_directories(${CLIENT_TARGET_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/libs/pge)

# Set variable
set(RESOURCE_FOLDER_NAME "data")
set(RESOURCE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FOLDER_NAME}")

#=========================================================================================
# Post Build
#=========================================================================================

function(CopyLibToTarget LIB_NAME TARGET_NAME)
    add_custom_command(TARGET ${TARGET_NAME}    
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:${LIB_NAME}>
        $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

add_custom_command(
    TARGET ${CLIENT_TARGET_NAME}
    POST_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E copy_directory
    ${RESOURCE_SRC_DIR}
    $<TARGET_FILE_DIR:${CLIENT_TARGET_NAME}>/${RESOURCE_FOLDER_NAME}
)

configure_file(
    "config.h.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/core/Config.h" ESCAPE_QUOTES
)