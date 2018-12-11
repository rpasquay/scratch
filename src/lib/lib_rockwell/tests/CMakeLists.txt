### specify CMake version (see CMakeLists.txt at root level)
set_cmake_version()

project(
    lib_rockwell_tests VERSION 1.0.0 
    DESCRIPTION "Unit Tests for exemplary header-only library Rockwell.")

# this executable consists of all test for target "app"
add_executable(lib_rockwell_tests "")

target_include_directories(lib_rockwell_tests PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# specify libraries we need to link against
target_link_libraries(lib_rockwell_tests
    # link against gtest_main since this allows us to not include an extra "main.cpp" for 
    # each test target as "gtest_main" comes with a "main()" entry point
    gtest_main gmock
    # link against the tested static library
    lib_rockwell)

# we want this target to appear in the folder "tests" if the IDE supports that (MSVC)
set_target_properties(lib_rockwell_tests PROPERTIES FOLDER "tests")

# add test source files and headers (fixtures)
grouped_sources(
    TARGET lib_rockwell_tests
    PUBLIC_PREFIX ${CMAKE_CURRENT_LIST_DIR}
    PUBLIC
    # list source files (*.cpp) here
        "${CMAKE_CURRENT_LIST_DIR}/test_rockwell.cpp"
)

# add tests to CTest
gtest_discover_tests(lib_rockwell_tests)
