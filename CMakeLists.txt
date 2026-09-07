cmake_minimum_required(VERSION 3.13)

# Geode SDK yolunu ortam değişkeninden veya klonlanan klasörden yükle
if(DEFINED ENV{GEODE_SDK})
    set(GEODE_SDK "$ENV{GEODE_SDK}")
else()
    set(GEODE_SDK "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone")
endif()

list(APPEND CMAKE_PREFIX_PATH "${GEODE_SDK}")

project(PlatformerSaves VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Geode REQUIRED)

add_geode_mod(
    ebro1500.platformer_saves
    SOURCES src/main.cpp
)
