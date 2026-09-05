cmake_minimum_required(VERSION 3.25)

project(AviationGroundStation
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(libs/telemetry_core)

# ============================================================
# Applications
# ============================================================

add_executable(dashboard
    apps/dashboard/main.cpp
)

add_executable(network_simulator
    apps/network_simulator/main.cpp
)


# network_simulator depends on telemetry_core.
#
# PRIVATE means:
#   network_simulator uses telemetry_core,
#   but this dependency is not automatically propagated
#   to anything that might use network_simulator later.
#
# The network_simulator target must be created first using
# add_executable() before we can configure its libraries.
target_link_libraries(network_simulator
    PRIVATE
        telemetry_core
)

target_link_libraries(dashboard
    PRIVATE
        telemetry_core
)