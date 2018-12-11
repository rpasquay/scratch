### make this a macro so we can reuse it through the project
macro(set_cmake_version)
    ### this snippet comes from:
    ### https://cliutils.gitlab.io/modern-cmake/chapters/basics.html
    cmake_minimum_required(VERSION 3.1...3.13)

    if(${CMAKE_VERSION} VERSION_LESS 3.12)
        cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
    endif()
endmacro(set_cmake_version)

### specify CMake version (see CMakeLists.txt at root level)
set_cmake_version()

project(scratch VERSION 1.1.0 DESCRIPTION "C++ template project")

# enable targets (in MSVC called projects) being grouped into folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# add directory containing additional cmake scripts to search path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

include(CTest)
# include GoogleTest so we can use "gtest_discover_tests"
include(GoogleTest)

# include custom cmake code
include(force_out_of_source_build)
include(grouped_sources)

# this file contains CMake code for adding a target building the doxygen documentation
include(doxygen)

# this is special as it is code for downloading and building Google Test
include(setup_gtest)

### Require out-of-source builds
force_out_of_source_build()

### put all binary files in direcotry "bin" (not without subdirectories though)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

###### SETUP TARGETS ###############################################################################

# SCRATCH_PROJECT_ROOT_DIR is the path to the projects root directory (surprise).
# It helps to define paths to headers in /include from CMakeLists.txt files
# deeper down the directory structure (actually all are deeper down than the "main" ./CMakeLists.txt
# file at the project's root). If we would not use SCRATCH_PROJECT_ROOT_DIR we would have to write
# paths like "${CMAKE_CURRENT_LIST_DIR}/../include/" which is not nice. To be able to have the
# publich headers in "include/" and at the same time have the CMakeLists.txt files in the
# (sub-)directories where they belong we need this workaround.
set(SCRATCH_PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# add libraries
# note that unfortunately header only libraries do not show up in MSVC!

# add libraries
add_subdirectory("src/lib/lib_stanley")
add_subdirectory("src/lib/lib_ruben")
add_subdirectory("src/lib/lib_rockwell")
# ...

# add executables
add_subdirectory("src/app")
# ...

# add tests
add_subdirectory("src/lib/lib_ruben/tests")
add_subdirectory("src/lib/lib_stanley/tests")
add_subdirectory("src/lib/lib_rockwell/tests")
add_subdirectory("src/app/tests")
# ...
