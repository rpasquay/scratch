### specify CMake version (see CMakeLists.txt at root level)
set_cmake_version()

project(lib_stanley VERSION 0.8.0 DESCRIPTION "Exemplary shared library")

### configure version header
configure_file (
  "${SCRATCH_PROJECT_ROOT_DIR}/include/scratch/lib_stanley/version.hpp.in"
  "${SCRATCH_PROJECT_ROOT_DIR}/include/scratch/lib_stanley/version.hpp"
)

### add a library called "lib_stanley"
add_library(lib_stanley SHARED "")

### add version to library
set_target_properties(lib_stanley PROPERTIES VERSION ${PROJECT_VERSION})

### specify include directories (private only visible to library code)
target_include_directories(lib_stanley
    PUBLIC "${SCRATCH_PROJECT_ROOT_DIR}/include" # for public headers and libraries
    PRIVATE "${CMAKE_CURRENT_LIST_DIR}") # for "private" headers next to the source files

### add target's sources and group them in an IDE supporting that (e.g. MSVC)
grouped_sources(
    TARGET lib_stanley
    PRIVATE_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC_PREFIX ${SCRATCH_PROJECT_ROOT_DIR}
    PRIVATE # list source- and private header-files here
        "${CMAKE_CURRENT_LIST_DIR}/stanley.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/stanley_impl.hpp"
        "${CMAKE_CURRENT_LIST_DIR}/stanley_impl.cpp"
    PUBLIC # list public header-files here
        "${SCRATCH_PROJECT_ROOT_DIR}/include/scratch/lib_stanley/stanley.hpp"
        "${SCRATCH_PROJECT_ROOT_DIR}/include/scratch/lib_stanley/version.hpp"
)

### put this library in a folder called "shared" in an IDE
set_target_properties(lib_stanley PROPERTIES FOLDER "shared")
