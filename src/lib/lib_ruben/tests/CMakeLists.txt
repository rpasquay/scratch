### specify CMake version (see CMakeLists.txt at root level)
set_cmake_version()

### Note: This file contains some rather long comments describing the differences to the test setup
###     of "lib_stanley". 

project(lib_ruben_tests VERSION 1.0.0 DESCRIPTION "Unit Tests for exemplary static library Ruben.")

### 
### Note: Since we're testing a static library here which does not have any functionality exposed
###     only via a "private header" (a header in its source directory and not in its public include
###     directory) we do not need to extract the library's sources and compile them into the
###     test executable. Instead we can just link against the static library.
###     
###     If however your static lib has "private stuff" only exposed via private headers, you
###     probably should follow the approach from "lib_stanley" and compile the sources into the test
###     executable.
###
# get_target_property(LIB_RUBEN_SOURCES lib_ruben SOURCES)
# get_target_property(LIB_RUBEN_INCLUDE_DIRS lib_ruben INCLUDE_DIRECTORIES)

# "add_compile_definitions(UNIT_TEST_NO_SHARED_LIB)"" not needed because static library is tested !

# this executable consists of all test for target "app"
add_executable(lib_ruben_tests "")

###
### Note: The commented line below also only is required if you want to test internal functionality
###     of the library (see the note above).
###
# this target shares its include directory with the target whose tests it contains
# target_include_directories(lib_ruben_tests PRIVATE ${LIB_RUBEN_INCLUDE_DIRS})

target_include_directories(lib_ruben_tests PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# specify libraries we need to link against
target_link_libraries(lib_ruben_tests
    # link against gtest_main since this allows us to not include an extra "main.cpp" for 
    # each test target as "gtest_main" comes with a "main()" entry point
    gtest_main gmock
    # link against the tested static library
    lib_ruben)

# we want this target to appear in the folder "tests" if the IDE supports that (MSVC)
set_target_properties(lib_ruben_tests PROPERTIES FOLDER "tests")

# add test source files and headers (fixtures)
grouped_sources(
    TARGET lib_ruben_tests
    PUBLIC_PREFIX ${CMAKE_CURRENT_LIST_DIR}
    PUBLIC
    # list source files (*.cpp) here
        "${CMAKE_CURRENT_LIST_DIR}/test_ruben.cpp"
    # list fixture files (*.hpp) here
        "${CMAKE_CURRENT_LIST_DIR}/test_ruben_fixture.hpp"
)

###
### Note: See the two notes above. Same story here.
###
# target_sources(lib_ruben_tests PRIVATE ${LIB_RUBEN_SOURCES}) # add sources of tested target

# add tests to CTest
gtest_discover_tests(lib_ruben_tests)

# clean up a bit

###
### Note: Again .. not needed in this setup ;)
###
# unset(LIB_RUBEN_SOURCES)
# unset(LIB_RUBEN_INCLUDE_DIRS)
