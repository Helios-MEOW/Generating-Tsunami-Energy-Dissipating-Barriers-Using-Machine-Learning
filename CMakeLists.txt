cmake_minimum_required(VERSION 3.21)

project(StudentShipSim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(TSUNAMI_BUILD_GUI "Build the Qt GUI executable" ON)
option(TSUNAMI_BUILD_MATPLOT_SMOKE "Build the standalone mathplot smoke-test executable in src/test.cpp" OFF)

add_library(tsunami_core INTERFACE)
target_include_directories(tsunami_core
    INTERFACE
        ${CMAKE_SOURCE_DIR}/src
)
target_compile_features(tsunami_core INTERFACE cxx_std_20)

if(TSUNAMI_BUILD_GUI)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTOUIC ON)

    find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

    qt_standard_project_setup()

    qt_add_executable(StudentShipSim
        src/main.cpp
        src/gui/MainWindow.cpp
        src/gui/MainWindow.hpp
        src/gui/MainWindow.ui
    )

    set_target_properties(StudentShipSim PROPERTIES
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
    )

    target_link_libraries(StudentShipSim
        PRIVATE
            tsunami_core
            Qt::Core
            Qt::Gui
            Qt::Widgets
    )
endif()

if(TSUNAMI_BUILD_MATPLOT_SMOKE)
    set(TSUNAMI_MATHPLOT_DIR "${CMAKE_SOURCE_DIR}/external/mathplot" CACHE PATH "Path to the mathplot source checkout")

    if(NOT EXISTS "${TSUNAMI_MATHPLOT_DIR}/mplot/Visual.h"
        OR NOT EXISTS "${TSUNAMI_MATHPLOT_DIR}/mplot/GraphVisual.h"
        OR NOT EXISTS "${TSUNAMI_MATHPLOT_DIR}/maths/sm/vvec"
        OR NOT EXISTS "${TSUNAMI_MATHPLOT_DIR}/mplot/fonts/verafonts.h")
        message(FATAL_ERROR
            "Mathplot is required for TSUNAMI_BUILD_MATPLOT_SMOKE, but the checkout is missing or incomplete.\n"
            "Expected it at: ${TSUNAMI_MATHPLOT_DIR}\n"
            "From the repository root, run:\n"
            "  powershell -ExecutionPolicy Bypass -File scripts/bootstrap_external.ps1\n"
            "Then rerun CMake."
        )
    endif()

    find_package(Freetype REQUIRED)
    find_package(glfw3 CONFIG REQUIRED)
    find_package(nlohmann_json CONFIG REQUIRED)
    find_package(OpenGL REQUIRED)

    add_library(tsunami_mathplot INTERFACE)
    target_include_directories(tsunami_mathplot
        INTERFACE
            ${TSUNAMI_MATHPLOT_DIR}
            ${TSUNAMI_MATHPLOT_DIR}/maths
    )
    target_compile_definitions(tsunami_mathplot
        INTERFACE
            MPLOT_FONTS_DIR="${TSUNAMI_MATHPLOT_DIR}/fonts"
    )
    target_link_libraries(tsunami_mathplot
        INTERFACE
            Freetype::Freetype
            glfw
            nlohmann_json::nlohmann_json
            OpenGL::GL
    )

    add_executable(MathplotSmokeTest src/test.cpp)
    target_link_libraries(MathplotSmokeTest PRIVATE tsunami_core tsunami_mathplot)
endif()

include(CTest)
