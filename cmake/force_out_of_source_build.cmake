### Macro to prevent in-source builds

macro(force_out_of_source_build)
    ### snippet found on:
    ### https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html
    file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
    if(EXISTS "${LOC_PATH}")
        message(FATAL_ERROR
        "You cannot build in a source directory (or any directory with a CMakeLists.txt file). \
        Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
    endif()
endmacro()