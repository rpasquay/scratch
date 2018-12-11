### Note that header-only libraries (or interface libraries as they're called by CMake) don't show
### up in MSVC (I honestly don't know about other IDEs). This is a bit stupid but also kind of makes
### some sense as a header-only library doesn't create output (e.g. some object/executable code).
### You'll notice that some settings can't be applied to header-only libraries.

### specify CMake version (see CMakeLists.txt at root level)
set_cmake_version()

project(lib_rockwell VERSION 1.2.0 DESCRIPTION "Exemplary header-only library")

### configure version header
configure_file (
  "${SCRATCH_PROJECT_ROOT_DIR}/include/scratch/lib_rockwell/version.hpp.in"
  "${SCRATCH_PROJECT_ROOT_DIR}/include/scratch/lib_rockwell/version.hpp"
)

### add a library called "lib_rockwell"
add_library(lib_rockwell INTERFACE)

### you cannot add version to a header-only library
# set_target_properties(lib_rockwell PROPERTIES VERSION ${PROJECT_VERSION})

### specify include directories (private only visible to library code)
target_include_directories(lib_rockwell
    INTERFACE "${SCRATCH_PROJECT_ROOT_DIR}/include") # for public (INTERFACE!) headers and libraries

### add target's sources and group them in an IDE supporting that (e.g. MSVC)
grouped_sources(
    TARGET lib_rockwell
    INTERFACE_PREFIX ${SCRATCH_PROJECT_ROOT_DIR}
    INTERFACE
        "${SCRATCH_PROJECT_ROOT_DIR}/include/scratch/lib_rockwell/rockwell.hpp"
        "${SCRATCH_PROJECT_ROOT_DIR}/include/scratch/lib_rockwell/version.hpp"
)

### unfortunately the property FOLDER also is not supported 
# set_target_properties(lib_rockwell PROPERTIES FOLDER "header-only")
