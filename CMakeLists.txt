cmake_minimum_required(VERSION 3.25)

project(AviationGroundStation
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ============================================================
# telemetry_core
# ============================================================

# For a library to be used by an executable, we generally need:
#
# 1. Create/define the library target
# 2. Specify its include directories (if it has header files)
# 3. Link the library target to the executable that uses it
# 4. The target must exist before we can configure it with
#    target_link_libraries()
#
# Current telemetry_core is header-only, so there is no .cpp
# file to compile.


# INTERFACE means this target has no .cpp/source files to compile.
# It only provides information such as include directories
# and dependencies to targets that use it.
#
# Since telemetry_core currently contains only a header file,
# INTERFACE is appropriate.
add_library(telemetry_core INTERFACE)


# INTERFACE here means:
#   - telemetry_core itself has no source files to compile
#   - this include directory is provided to targets that
#     use telemetry_core
#
# PRIVATE would mean the include directory is only used
# internally by a compiled telemetry_core library.
#
# Since telemetry_core is currently header-only, INTERFACE
# is appropriate.
target_include_directories(telemetry_core
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/telemetry_core/include
)


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