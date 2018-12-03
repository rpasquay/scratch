### specify CMake version (see CMakeLists.txt at root level)
set_cmake_version()

project(app_tests VERSION 1.0.0 DESCRIPTION "Unit Tests for executable example.")

# Here we obtain the source files and include directories of the target we'd like to test.
get_target_property(APP_SOURCES app SOURCES)
get_target_property(APP_INCLUDE_DIRS app INCLUDE_DIRECTORIES)

# We don't want the main.cpp of "app" in here
list(REMOVE_ITEM APP_SOURCES "main.cpp") 

# Add a new executable for the tests. Again: no main.cpp/main() required.
add_executable(app_tests "")

# The tests share their include directory with the target whose tests it contains.
target_include_directories(app_tests PRIVATE ${APP_INCLUDE_DIRS})

# Specify libraries we need to link against:
target_link_libraries(app_tests
    # Link against gtest_main since this allows us to not include an extra "main.cpp" for 
    # each test target as "gtest_main" comes with a "main()" entry point.
    gtest_main gmock
    # Link against libraries required by the tested target
    lib_stanley lib_ruben)

# We want this target to appear in the (virtual) folder "tests" if the IDE supports that.
set_target_properties(app_tests PROPERTIES FOLDER "tests")

# Add test's source and header (fixture) files.
grouped_sources(
    TARGET app_tests
    PUBLIC_PREFIX ${CMAKE_CURRENT_LIST_DIR}
    PUBLIC
    # List source files (*.cpp) here:
        "${CMAKE_CURRENT_LIST_DIR}/test_ernest.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/test_linwood.cpp"
    # List fixture files (*.hpp) here:
        # ...
)

target_sources(app_tests PRIVATE ${APP_SOURCES})

# add tests to CTest
gtest_discover_tests(app_tests)

# Clean up a bit.
unset(APP_SOURCES)
unset(APP_INCLUDE_DIRS)
