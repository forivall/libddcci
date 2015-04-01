cmake_minimum_required (VERSION 3.0)
project (libddcci)

set (LIBDDCCI_VERSION_MAJOR 0)
set (LIBDDCCI_VERSION_MINOR 0)
set (LIBDDCCI_VERSION_PATCH 1)

configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)

include_directories("${PROJECT_BINARY_DIR}")

option (COMPILE_EXAMPLE
        "Compile the example utilities" ON)

if (COMPILE_EXAMPLE)
  add_subdirectory("example")
endif (COMPILE_EXAMPLE)
