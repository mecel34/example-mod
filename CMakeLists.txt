cmake_minimum_required(VERSION 3.13)

# Geode SDK yolunu GitHub Actions / CLI dizinlerinden otomatik yakala
if(DEFINED ENV{GEODE_SDK})
    set(GEODE_SDK "$ENV{GEODE_SDK}")
elseif(EXISTS "${CMAKE_SOURCE_DIR}/geode-sdk-clone")
    set(GEODE_SDK "${CMAKE_SOURCE_DIR}/geode-sdk-clone")
endif()

if(GEODE_SDK)
    list(APPEND CMAKE_PREFIX_PATH "${GEODE_SDK}")
    set(Geode_DIR "${GEODE_SDK}")
endif()

project(PlatformerSaves VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Geode REQUIRED)

add_geode_mod(
    ebro1500.platformer_saves
    SOURCES src/main.cpp
)
