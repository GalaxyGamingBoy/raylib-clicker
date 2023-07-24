cmake_minimum_required(VERSION 3.14)

# PROJECT SETTINGS
project(raylib-clicker LANGUAGES CXX)
set(RAYLIB_VERSION 4.5.0)
set(SOURCES
    src/main.cpp
    src/objects/default/GameObject.h
    src/objects/default/GameObject.cpp
    src/objects/Clicker.h
    src/objects/Clicker.cpp
    src/scenes/default/Scene.h
    src/scenes/default/Scene.cpp
    src/scenes/GameScene.h
    src/scenes/GameScene.cpp
    src/utils/Utils.h
    src/objects/Score.h
    src/objects/Score.cpp
    src/objects/Hand.h
    src/objects/Hand.cpp)

set(FETCHCONTENT_QUIET FALSE)

# IF TRUE SET RAYLIB_DOWNLOADED_PATH & RAYLIB_CPP_DOWNLOADED_PATH
set(RAYLIB_DOWNLOADED_PATH $ENV{RAYLIB_DOWNLOADED_PATH})
set(RAYLIB_DOWNLOADED_CPP_PATH $ENV{RAYLIB_DOWNLOADED_CPP_PATH})

# GITHUB REPOS
set(RAYLIB_PATH https://github.com/raysan5/raylib.git)
set(RAYLIB_CPP_PATH https://github.com/RobLoach/raylib-cpp.git)

if(DEFINED ENV{RAYLIB_DOWNLOADED})
  set(RAYLIB_PATH ${RAYLIB_DOWNLOADED_PATH})
  set(RAYLIB_CPP_PATH ${RAYLIB_DOWNLOADED_CPP_PATH})
endif()

# raylib
find_package(raylib QUIET)
if(NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    GIT_REPOSITORY ${RAYLIB_PATH}
    GIT_TAG ${RAYLIB_VERSION}
    GIT_PROGRESS TRUE)
  FetchContent_MakeAvailable(raylib)
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if(NOT raylib_cpp_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib_cpp
    GIT_REPOSITORY ${RAYLIB_CPP_PATH}
    GIT_TAG v${RAYLIB_VERSION}
    GIT_PROGRESS TRUE)
  FetchContent_MakeAvailable(raylib_cpp)
endif()

# This is the main part:
add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp)
target_include_directories(${PROJECT_NAME} PUBLIC lib/)
# Web Configurations
if(${PLATFORM} STREQUAL "Web")
  # Tell Emscripten to build an example.html file.
  set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()
