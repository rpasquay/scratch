### specify CMake version (see CMakeLists.txt at root level)
set_cmake_version()

project(lib_ruben VERSION 0.4.3 DESCRIPTION "Exemplary static library")

### configure version header
configure_file (
  "${SCRATCH_PROJECT_ROOT_DIR}/include/scratch/lib_ruben/version.hpp.in"
  "${SCRATCH_PROJECT_ROOT_DIR}/include/scratch/lib_ruben/version.hpp"
)

### add a static library called "lib_ruben"
add_library(lib_ruben STATIC "")

### add version to library
set_target_properties(lib_ruben PROPERTIES VERSION ${PROJECT_VERSION})

### specify include directories (private only visible to library code)
target_include_directories(lib_ruben
    PUBLIC "${SCRATCH_PROJECT_ROOT_DIR}/include" # for public headers and libraries
    PRIVATE "${CMAKE_CURRENT_LIST_DIR}") # for "private" headers next to the source files

### add target's sources and group them in an IDE supporting that (e.g. MSVC)
grouped_sources(
    TARGET lib_ruben
    PRIVATE_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC_PREFIX ${SCRATCH_PROJECT_ROOT_DIR}
    PRIVATE # list source- and private header-files here
        "${CMAKE_CURRENT_LIST_DIR}/ruben.cpp"
    PUBLIC # list public header-files here
        "${SCRATCH_PROJECT_ROOT_DIR}/include/scratch/lib_ruben/ruben.hpp"
        "${SCRATCH_PROJECT_ROOT_DIR}/include/scratch/lib_ruben/exceptions.hpp"
        "${SCRATCH_PROJECT_ROOT_DIR}/include/scratch/lib_ruben/version.hpp"
)

### put this library in a folder called "shared" in an IDE
set_target_properties(lib_ruben PROPERTIES FOLDER "static")
