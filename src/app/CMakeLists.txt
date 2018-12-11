### specify CMake version (see CMakeLists.txt at root level)
set_cmake_version()

project(app VERSION 1.0.0 DESCRIPTION "C++ template executable")

### configure version header
configure_file (
    "${CMAKE_CURRENT_LIST_DIR}/version.hpp.in"
    "${CMAKE_CURRENT_LIST_DIR}/version.hpp"
)

### Define executable and its sources
add_executable(app "main.cpp")

### specify include directories of executable target (usually only one)
target_include_directories(app
    PUBLIC "${SCRATCH_PROJECT_ROOT_DIR}/include/" # for public headers and libraries
    ### I could just write "${CMAKE_CURRENT_LIST_DIR}/" (which would be "<project root>/src/app")
    ### here but with the following approach you *have* to type e.g. #include "app/foo.hpp" if you
    ### want the foo.hpp file from app which makes it a bit more explicit in what file/target
    ### you're currently in. The biggest plus however is that you can have a directory "src/common"
    ### which does not contain sources for a target but rather code which can be shared without
    ### having two include paths here for src/ and src/app (a bit ugly in my eyes).  
    PRIVATE "${SCRATCH_PROJECT_ROOT_DIR}/src") # for "private" headers next to the source files

### specify which libraries this executable has to be linked against
target_link_libraries(app lib_ruben lib_stanley lib_rockwell)

### put this executable in a folder called "executables" in an IDE
set_target_properties(app PROPERTIES FOLDER "executables")

# add sources and headers 
grouped_sources(
    TARGET app
    PUBLIC_PREFIX ${CMAKE_SOURCE_DIR} # note that we're not using the same var here as in libraries!
    PUBLIC
    # list cpp files here
        "${CMAKE_CURRENT_LIST_DIR}/linwood.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/ernest.cpp"
    # list hpp files here
        "${CMAKE_CURRENT_LIST_DIR}/ernest.hpp"
        "${CMAKE_CURRENT_LIST_DIR}/exceptions.hpp"
        "${CMAKE_CURRENT_LIST_DIR}/linwood.hpp"
)
