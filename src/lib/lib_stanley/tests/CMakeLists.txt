###
### Important: The way we test the shared library here is not compile it as a shared library
###     but "steal" its sources and compile the combined with the tests to an executable.
###     This way one can more easily test implementation details which otherwise would remain 
###     hidden or unpleasantly hard to test.
###

### specify CMake version (see CMakeLists.txt at root level)
set_cmake_version()

project(lib_stanley_tests VERSION 1.0.0 DESCRIPTION "Unit Tests for shared library example.")

# we need to add the sources of the executable target we want to test
get_target_property(LIB_STANLEY_SOURCES lib_stanley SOURCES)
get_target_property(LIB_STANLEY_INCLUDE_DIRS lib_stanley INCLUDE_DIRECTORIES)

# specify that no declspec(dllimport/dllexport) is specified when building tests
add_compile_definitions(UNIT_TEST_NO_SHARED_LIB)

# this executable consists of all test for target "lib_stanley"
add_executable(lib_stanley_tests "")

# this target shares its include directory with the target whose tests it contains
target_include_directories(lib_stanley_tests
    PRIVATE ${LIB_STANLEY_INCLUDE_DIRS}
    PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# specify libraries we need to link against
target_link_libraries(lib_stanley_tests
    # link against gtest_main since this allows us to not include an extra "main.cpp" for 
    # each test target as "gtest_main" comes with a "main()" entry point
    gtest_main gmock)

# we want this target to appear in the folder "tests" if the IDE supports that (MSVC)
set_target_properties(lib_stanley_tests PROPERTIES FOLDER "tests")

# add test source files and headers (fixtures)
grouped_sources(
    TARGET lib_stanley_tests
    PUBLIC_PREFIX ${CMAKE_CURRENT_LIST_DIR}
    PUBLIC
    # list source files (*.cpp) here
        "${CMAKE_CURRENT_LIST_DIR}/test_stanley_impl.cpp"
    # list fixture files (*.hpp) here
        "${CMAKE_CURRENT_LIST_DIR}/test_stanley_impl_fixture.hpp"
)

target_sources(lib_stanley_tests PRIVATE ${LIB_STANLEY_SOURCES}) # add sources of tested target

# add tests to CTest
gtest_discover_tests(lib_stanley_tests)

# clean up a bit
unset(LIB_STANLEY_SOURCES)
unset(LIB_STANLEY_INCLUDE_DIRS)
