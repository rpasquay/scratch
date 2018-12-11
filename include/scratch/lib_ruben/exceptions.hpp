/**
 * \file lib_ruben\exceptions.hpp
 * \author Rafael Pasquay (maintainer.scratch@pasquay.com)
 * \brief Static library "cli". Header providing exception declarations.
 * \version 1.0
 * \date 2018-10-21
 * 
 * \copyright Copyright (c) 2018
 * 
 * \ingroup lib_ruben
 * \addtogroup lib_ruben
 * @{
 */

#ifndef SCRATCH_INCLUDE_GUARD__LIB_RUBEN_EXCEPTIONS_HPP
#define SCRATCH_INCLUDE_GUARD__LIB_RUBEN_EXCEPTIONS_HPP

#include <stdexcept> // std::runtime_error

namespace scratch { namespace ruben {

/**
 * \brief Base exception for all exceptions thrown by lib "Ruben".
 */
class RubenException : public std::runtime_error {
public:

    /**
     * \brief Construct a new RubenException object.
     * 
     * \param msg
     *  Error message.
     */
    RubenException(const char* msg) : runtime_error(msg) {}
};

/**
 * \brief Thrown by Ruben to tell his secret in a dramatic way.
 */
class SecretException : public RubenException {
    public:

    /**
     * \brief Construct a new SecretException object.
     * 
     * \param msg
     *  Error message.
     */
    SecretException(const char* msg) : RubenException(msg) {}
};

}}

/** @} */

#endif // SCRATCH_INCLUDE_GUARD__LIB_RUBEN_EXCEPTIONS_HPP
