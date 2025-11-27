#/*****************************************************************
# * Copyright (C) 2025 Robert Valler - All rights reserved.
# *
# * This file is part of the project: <insert project name here>
# *
# * This project can not be copied and/or distributed
# * without the express permission of the copyright holder
# *****************************************************************/
cmake_minimum_required(VERSION 3.22.0)
project ( hmi_stack )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Wall)
set(W1)
set(Wfloat-conversion)

#OPTIONS
option(TEST_ENABLE "Enable GTest" OFF)

# SET(GUI_FW_SETTING "QT_GUI" CACHE STRING "GUI Framework")
# SET_PROPERTY(CACHE GUI_FW_SETTING PROPERTY STRINGS QT_GUI DEARIMGUI_GUI)
# if(GUI_FW_SETTING STREQUAL "QT_GUI")
#     add_compile_definitions(QT_GUI=1 GUI_FW=QT_GUI)
# elseif(GUI_FW_SETTING STREQUAL "DEARIMGUI_GUI")
#     add_compile_definitions(DEARIMGUI_GUI=1 GUI_FW=DEARIMGUI_GUI)
# else()
#     message(FATAL_ERROR "Unknown GUI_FW_SETTING: ${GUI_FW_SETTING}")
# endif()


set(ProtobufIncludePath ${CMAKE_CURRENT_BINARY_DIR} CACHE INTERNAL src/messages)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


#PACKAGES
find_package(Threads REQUIRED)
find_package(Boost 1.88.0 REQUIRED COMPONENTS boost)
find_package(asio 1.36.0 REQUIRED)
find_package(protobuf 6.32.1 REQUIRED)
find_package(imgui 1.92.2 REQUIRED)
find_package(glfw3 3.3.8 REQUIRED)
find_package(GLEW 2.2.0 REQUIRED)
find_package(Qt6 COMPONENTS Core Widgets)
find_package(wxWidgets REQUIRED COMPONENTS core base)


if(TEST_ENABLE)
find_package(GTest REQUIRED)
endif()

#EXTERNAL INCLUDES
include_directories(${QT_USE_FILE})
include_directories(${IMGUI_INCLUDE_DIRS})

#INTERNAL INCLUDES
#include(${wxWidgets_USE_FILE})
include_directories(${CMAKE_SOURCE_DIR}/src/main)
include_directories(${CMAKE_SOURCE_DIR}/src/core)
include_directories(${CMAKE_SOURCE_DIR}/src/common)
include_directories(${CMAKE_SOURCE_DIR}/src/state)
include_directories(${CMAKE_SOURCE_DIR}/src/operations)
include_directories(${CMAKE_SOURCE_DIR}/src/gui)
include_directories(${CMAKE_SOURCE_DIR}/src/gui/Qt)
include_directories(${CMAKE_SOURCE_DIR}/src/gui/DearImGui)
include_directories(${CMAKE_SOURCE_DIR}/src/gui/wxWidgets)
include_directories(${CMAKE_SOURCE_DIR}/bindings)
include_directories(${CMAKE_SOURCE_DIR}/src/gui/Dummy)


#SOURCE FILES
file(GLOB APP_SOURCES
    ${CMAKE_SOURCE_DIR}/src/main/*.cpp
    ${CMAKE_SOURCE_DIR}/src/core/*.cpp
    ${CMAKE_SOURCE_DIR}/src/state/*.cpp
    ${CMAKE_SOURCE_DIR}/src/operations/*.cpp
    ${CMAKE_SOURCE_DIR}/src/gui/*.cpp
    ${CMAKE_SOURCE_DIR}/src/gui/Qt/*.cpp
    ${CMAKE_SOURCE_DIR}/src/gui/DearImGui/*.cpp
    ${CMAKE_SOURCE_DIR}/src/gui/wxWidgets/*.cpp
    ${CMAKE_SOURCE_DIR}/src/gui/Dummy/*.cpp
    ${CMAKE_SOURCE_DIR}/bindings/*.cpp
)

#HEADERS FILES
file(GLOB APP_HEADERS
    ${CMAKE_SOURCE_DIR}/src/core/*.h
    ${CMAKE_SOURCE_DIR}/src/common/*.h
    ${CMAKE_SOURCE_DIR}/src/state/*.h
    ${CMAKE_SOURCE_DIR}/src/operations/*.h
    ${CMAKE_SOURCE_DIR}/src/gui/*.h
    ${CMAKE_SOURCE_DIR}/src/gui/Qt/*.h
    ${CMAKE_SOURCE_DIR}/src/gui/Qt/*.ui
    ${CMAKE_SOURCE_DIR}/src/gui/DearImGui/*.h
    ${CMAKE_SOURCE_DIR}/src/gui/wxWidgets/*.h
    ${CMAKE_SOURCE_DIR}/src/gui/Dummy/*.h
    ${CMAKE_SOURCE_DIR}/bindings/*.h
)

#CONFIG FILES
file(GLOB APP_CONFIG
    ${CMAKE_SOURCE_DIR}/README.md
    ${CMAKE_SOURCE_DIR}/conanfile.py
)

add_executable(${PROJECT_NAME}
    ${APP_SOURCES}
    ${APP_HEADERS}
    ${APP_CONFIG}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${CMAKE_THREAD_LIBS_INIT}
    Qt6::Widgets
    imgui::imgui
    glfw
    GLEW::GLEW
    wxWidgets::wxWidgets
)

if(TEST_ENABLE)
################### TEST ###################
#INCLUDE
include_directories(${GTest_INCLUDE_DIRS})

#SOURCE FILES
file(GLOB_RECURSE TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/test/main.cpp
    ${CMAKE_SOURCE_DIR}/test/gtest_hmi.cpp
)

add_executable(${PROJECT_NAME}_TEST
    ${TEST_SOURCES}
)

target_link_libraries(${PROJECT_NAME}_TEST PRIVATE
    ${CMAKE_THREAD_LIBS_INIT}
    gtest::gtest
)
endif()

message("######################################################################")
message("# CONFIGURATION #")
message("#################")
message("# TEST_ENABLE:         [${TEST_ENABLE}]")
#message("# GUI_FW_SETTING:      [${GUI_FW_SETTING}]")
message("######################################################################")
