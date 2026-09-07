cmake_minimum_required(VERSION 3.13)

# Geode SDK yolunu GitHub Actions sanal ortamı ve yerel klasörlerden doğrudan yakala
if(DEFINED ENV{GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH "$ENV{GEODE_SDK}")
elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone")
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone")
endif()

project(PlatformerSaves VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Geode REQUIRED)

add_geode_mod(
    ebro1500.platformer_saves
    SOURCES src/main.cpp
)
