cmake_minimum_required(VERSION 3.20)
project(2024_project_Viki_Lauvrys)

# Enable FetchContent for dependencies
include(FetchContent)
set(BUILD_SHARED_LIBS OFF)

## WINDOWS
FetchContent_Declare(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FetchContent_MakeAvailable(SFML)

## LINUX
##find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

set(CMAKE_CXX_STANDARD 17)

# Define the executable target
add_executable(DOODLE_JUMP main.cpp
        src/gui/BG_TILE/BG_Tile.h
        src/gui/GAME/Game.h
        src/gui/PLAYER/Player.cpp
        src/gui/TILEMAP/TileMap.cpp
        src/gui/PLATFORM/Platform.cpp
        src/gui/GAME/Game.cpp
        src/gui/BG_TILE/BG_Tile.cpp
        src/gui/ENTITY_VIEW/EntityView.cpp
        src/gui/ENTITY_VIEW/EntityView.h)

# Define the library target
add_library(DOODLE_LIB SHARED
        src/logic/PLATFORM/Platform.h
        src/logic/CAMERA/Camera.h
        src/logic/OBSERVER/Observer.h
        src/logic/STOPWATCH/Stopwatch.h
        src/logic/PLAYER/Player.cpp
        src/logic/WORLD/World.cpp
        src/logic/SUBJECT/Subject.cpp
        src/logic/ENTITY/Entity.h
        src/logic/ENTITY_MODEL/EntityModel.h
        src/logic/RANDOM/Random.cpp
        src/logic/PLATFORM/Platform.cpp
        src/logic/STOPWATCH/Stopwatch.cpp
        src/logic/ENTITY_MODEL/EntityModel.cpp
        src/logic/CAMERA/Camera.cpp
        src/logic/SCORE/Score.cpp
        src/logic/PLATFORM/PlatformStatic.cpp
        src/logic/PLATFORM/PlatformHorizontal.cpp
        src/logic/PLATFORM/PlatformVertical.cpp
        src/logic/PLATFORM/PlatformTemporary.cpp
        src/logic/BONUS/BonusStrategy.h
        src/logic/BONUS/Bonus.h)

# Define the include directories
target_include_directories(DOODLE_JUMP PRIVATE ${SFML_SOURCE_DIR}/include)

# Handle platform-specific linking
if(UNIX AND NOT APPLE)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(UDEV libudev)
    if(UDEV_FOUND)
        message(STATUS "UDev found: ${UDEV_LIBRARIES}")
        target_include_directories(DOODLE_JUMP PRIVATE ${UDEV_INCLUDE_DIRS})
        target_link_libraries(DOODLE_JUMP PRIVATE ${UDEV_LIBRARIES})
    else()
        message(FATAL_ERROR "UDev not found. Please install libudev-dev.")
    endif()
    target_link_libraries(DOODLE_JUMP PRIVATE DOODLE_LIB sfml-graphics sfml-window sfml-system)
elseif(WIN32)
    target_link_libraries(DOODLE_JUMP PRIVATE DOODLE_LIB sfml-graphics sfml-window sfml-system opengl32 glu32 winmm gdi32)
endif()

# Additional settings for linking the correct SFML libraries
link_directories(${SFML_BINARY_DIR}/lib)
