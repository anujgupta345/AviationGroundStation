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
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)