cmake_minimum_required (VERSION 2.6)

project (Framework)

# The version number.
set (Framwork_VERSION_MAJOR 1)
set (Framwork_VERSION_MINOR 0)

# sources and headers dir for the Graphics
set(GRAPHICS_SOURCE_DIR app/Graphics/src )

set(GRAPHICS_INCLUDE_DIR app/Graphics/include )

# source files and header files for the Graphics
set(GRAPHICS_SOURCES 
    ${GRAPHICS_SOURCE_DIR}/Graphics.cpp
    )

set(GRAPHICS_HEADERS 
    ${GRAPHICS_INCLUDE_DIR}/Graphics.h
    )

# sources and headers dir for the Game Manager
set(GAME_MANAGER_SOURCE_DIR app/GameManager/src )

set(GAME_MANAGER_INCLUDE_DIR app/GameManager/include )

# source files and header files for the Game Manager
set(GAME_MANAGER_SOURCES
    ${GAME_MANAGER_SOURCE_DIR}/GameManager.cpp
    )

set(GAME_MANAGER_HEADERS 
    ${GAME_MANAGER_INCLUDE_DIR}/GameManager.h
    )

# sources and headers dir for the Timer
set(TIMER_SOURCE_DIR app/Timer/src )

set(TIMER_INCLUDE_DIR app/Timer/include )

# source files and header files for the Timer
set(TIMER_SOURCES 
    ${TIMER_SOURCE_DIR}/Timer.cpp
    )

set(TIMER_HEADERS 
    ${TIMER_INCLUDE_DIR}/Timer.h
    )

# sources and headers dir for the main
set(MAIN_SOURCE_DIR app/main )

# source files and header files for the main
set(MAIN_SOURCES 
    ${MAIN_SOURCE_DIR}/main.cpp
    )

list(APPEND CMAKE_PREFIX_PATH buildtools/cmake/SDL2)

set(CMAKE_MODULE_PATH FindSDL2.cmake FindSDL2_image.cmake FindSDL2_ttf.cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)

# the install dir
set(INSTALL_DIR build/install/usr/local/bin)

# additional includes - NOT USED
include_directories(${SDL2_INCLUDE_DIRS} 
                    ${SDL2IMAGE_INCLUDE_DIRS} 
                    ${SDL2TTF_INCLUDE_DIRS}
                    ${GRAPHICS_INCLUDE_DIR} 
                    ${GAME_MANAGER_INCLUDE_DIR} 
                    ${TIMER_INCLUDE_DIR} 
                    )

# main file will be the master of the opration

set(TARGET_SOURCES_FILES 
    ${GRAPHICS_SOURCES}
    ${TIMER_SOURCES}
    ${GAME_MANAGER_SOURCES} 
    ${MAIN_SOURCES}
    )

set(TARGET_HEADER_FILES 
    ${SDL2_INCLUDE_DIRS} 
    ${GRAPHICS_HEADERS}
    ${TIMER_HEADERS}
    ${GAME_MANAGER_HEADERS} 
    )

add_definitions(-DDEBUG_BUILD)
add_definitions(-DDEBUG_LEVEL=4)
set(CMAKE_BUILD_TYPE Debug)

add_executable(Framework 
                ${TARGET_SOURCES_FILES} 
                ${TARGET_HEADER_FILES}
                )

target_link_libraries(Framework ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES})