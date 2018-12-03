### CMake script to configure Doxyfile if Doxygen is found.

find_package(Doxygen)

if (DOXYGEN_FOUND)

    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxyfile configured.")

    # add custom target which executes doxygen
    # note: ALL specifies that this target is added to the default target and run every time
    add_custom_target(doc_doxygen
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generate documentation with Doxygen."
        VERBATIM )

    # we want this target to appear in the folder "utility" if the IDE supports that (MSVC)
    set_target_properties(doc_doxygen PROPERTIES FOLDER "utility")

    # clean up
    unset(DOXYGEN_IN)
    unset(DOXYGEN_OUT)

else (DOXYGEN_FOUND)

  message("Doxygen not found on this system!")

endif (DOXYGEN_FOUND)
