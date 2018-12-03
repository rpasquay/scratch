/**
 * \file stanley.hpp
 * \author Rafael Pasquay (rafael@pasquay.com)
 * \brief Public header of dynamic library "Stanley".
 * \version 0.1
 * \date 2018-10-21
 * 
 * \copyright Copyright (c) 2018
 * \ingroup lib_stanley
 * \addtogroup lib_stanley
 * @{
 */

#ifndef SCRATCH_INCLUDE_GUARD__LIB_STANLEY_STANLEY_HPP
#define SCRATCH_INCLUDE_GUARD__LIB_STANLEY_STANLEY_HPP

/**
 * \macro LIB_STANLEY_API
 * \brief Required for shared libraries in Windows.
 * 
 * All functions exported by a shared library in Windows need to have their calling convention
 * set to `__declspec(dllexport)` when you're building the library (e.g the DLL).
 * When you include the function declarations in code using the shared library you need to use
 * `__declspec(dllimport)`. This macro is always set to the correct value even on operating systems
 * (like Linux) that do not require the different calling conventions be specified.
 */

#if defined(WIN32) && !defined(UNIT_TEST_NO_SHARED_LIB)
#if defined(_MSC_VER)
#pragma warning(disable: 4251)
#endif
    #if defined(lib_stanley_EXPORTS) // lib_stanley_EXPORTS is defined by CMake 
        #define LIB_STANLEY_API __declspec(dllexport)
    #else
        #define LIB_STANLEY_API __declspec(dllimport)
    #endif
#else
    #define LIB_STANLEY_API
#endif

#include <string> // std::string

namespace scratch { namespace stanley {

/**
 * \brief Interface for a container class.
 * 
 * Container for data returned by class Stanley.
 * Contains a secret number and a message.
 */
class StanleysContainer {

public:

    virtual ~StanleysContainer() = 0;

    /**
     * \brief Print message to standard out.
     */
    virtual void print_message() const = 0;

    /**
     * \brief Get the secret.
     * 
     * \returns unsigned int 
     *  Returns Stanley's secret number.
     */
    virtual unsigned int get_secret() const = 0;

};

inline scratch::stanley::StanleysContainer::~StanleysContainer() {}

/**
 * \brief Interface for a class provided by a dynamic library.
 */
class Stanley {

public:

    virtual ~Stanley() = 0; 

    /**
     * \brief Get a container with Stanley's secret.
     * 
     * The caller takes ownership of the returned pointer/object.
     * 
     * \returns StanleysContainer* 
     *  Pointer to a new instance of a class implementing interface StanleysContainer.
     */
    virtual StanleysContainer* get_container() const = 0;

};

inline scratch::stanley::Stanley::~Stanley() {}

/**
 * \brief Factory method for creating a new Stanley.
 * 
 * Returns a pointer to a new instance of a class implementing interface Stanley.
 * Ownership of the returned pointer/instance has the caller.
 * 
 * \returns Stanley*
 *  Returns pointer class providing interface Stanley.
 */
extern "C" LIB_STANLEY_API Stanley* create_stanley ();

}}

/** @} */

#endif // SCRATCH_INCLUDE_GUARD__LIB_STANLEY_STANLEY_HPP
