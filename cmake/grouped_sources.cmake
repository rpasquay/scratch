### Function for adding source files to a target while at the same time applying filters (think:
### virtual folders in the source code view of an IDE like MSVC) which mirror the actual source code
### structure in an IDE such as MSVC which sadly does not have such a feature.

function(grouped_sources)
    # Add (PUBLIC, PRIVATE and INTERFACE) sources to a target while adding at the same time filters 
    # (a filter is a virtual forlder in an IDE such as MSVC) which mirrors the file path of these
    # sources relative to a given prefix (path). 


    # specify single value arguments
    set(oneValueArgs TARGET PRIVATE_PREFIX PUBLIC_PREFIX INTERFACE_PREFIX)
    # specify multivalue arguments
    set(multiValueArgs PRIVATE PUBLIC INTERFACE)
    # parse arguments
    cmake_parse_arguments(grouped_sources
        "${options}" "${oneValueArgs}" "${multiValueArgs}" "${ARGN}")

    # check if arguments are valid

    if(NOT DEFINED grouped_sources_TARGET)
        message(FATAL_ERROR "grouped_sources: No target specified!")
    endif(NOT DEFINED grouped_sources_TARGET)

    if(DEFINED grouped_sources_PRIVATE AND NOT DEFINED grouped_sources_PRIVATE_PREFIX) 
        message(FATAL_ERROR "grouped_sources: Got argument \"PRIVATE\" without \"PRIVATE_PREFIX\".")
    elseif(NOT DEFINED grouped_sources_PRIVATE AND DEFINED grouped_sources_PRIVATE_PREFIX)
        message(FATAL_ERROR "grouped_sources: Got argument \"PRIVATE_PREFIX\" without \"PRIVATE\".")
    endif(DEFINED grouped_sources_PRIVATE AND NOT DEFINED grouped_sources_PRIVATE_PREFIX)

    if(DEFINED grouped_sources_PUBLIC AND NOT DEFINED grouped_sources_PUBLIC_PREFIX) 
        message(FATAL_ERROR "grouped_sources: Got argument \"PUBLIC\" without \"PUBLIC_PREFIX\".")
    elseif(NOT DEFINED grouped_sources_PUBLIC AND DEFINED grouped_sources_PUBLIC_PREFIX)
        message(FATAL_ERROR "grouped_sources: Got argument \"PUBLIC_PREFIX\" without \"PUBLIC\".")
    endif(DEFINED grouped_sources_PUBLIC AND NOT DEFINED grouped_sources_PUBLIC_PREFIX)

    if(DEFINED grouped_sources_INTERFACE AND NOT DEFINED grouped_sources_INTERFACE_PREFIX) 
        message(FATAL_ERROR "grouped_sources: Got argument \"INTERFACE\" without \"INTERFACE_PREFIX\".")
    elseif(NOT DEFINED grouped_sources_INTERFACE AND DEFINED grouped_sources_INTERFACE_PREFIX)
        message(FATAL_ERROR "grouped_sources: Got argument \"INTERFACE_PREFIX\" without \"INTERFACE\".")
    endif(DEFINED grouped_sources_INTERFACE AND NOT DEFINED grouped_sources_INTERFACE_PREFIX)

    # add private sources with respective prefix
    if(DEFINED grouped_sources_PRIVATE)
        target_sources(${grouped_sources_TARGET} PRIVATE ${grouped_sources_PRIVATE})
        source_group(TREE ${grouped_sources_PRIVATE_PREFIX} FILES ${grouped_sources_PRIVATE})
    endif(DEFINED grouped_sources_PRIVATE)
    # add public sources with respective prefix
    if(DEFINED grouped_sources_PUBLIC)
        target_sources(${grouped_sources_TARGET} PRIVATE ${grouped_sources_PUBLIC})
        source_group(TREE ${grouped_sources_PUBLIC_PREFIX} FILES ${grouped_sources_PUBLIC})
    endif(DEFINED grouped_sources_PUBLIC)
    # add interface sources with respective prefix    
    if(DEFINED grouped_sources_INTERFACE)
        target_sources(${grouped_sources_TARGET} PRIVATE ${grouped_sources_INTERFACE})
        source_group(TREE ${grouped_sources_INTERFACE_PREFIX} FILES ${grouped_sources_INTERFACE})
    endif(DEFINED grouped_sources_INTERFACE)
endfunction(grouped_sources)