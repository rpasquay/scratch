/**
 * \file app\exceptions.hpp
 * \author Rafael Pasquay (maintainer.scratch@pasquay.com)
 * \brief Exemplary header file of target "app".
 * \version 1.0
 * \date 2018-10-21
 * 
 * \copyright Copyright (c) 2018
 * 
 * \ingroup app
 * \addtogroup app
 * @{
 */

#ifndef SCRATCH_INCLUDE_GUARD__APP_COMMON_EXCEPTIONS_HPP
#define SCRATCH_INCLUDE_GUARD__APP_COMMON_EXCEPTIONS_HPP

#include <stdexcept> // std::runtime_error

namespace scratch { namespace app {

    /**
     * \brief Base class for all exceptions common to app's modules.
     */
    class CommonException : public std::runtime_error {
    public:

        /**
         * \brief Construct a new CommonException object
         * 
         * \param message
         *  Error message.
         */
        CommonException(const char* message) : runtime_error(message) {}
    };

    /**
     * \brief Exception which can be thrown by multiple modules of a target.
     * 
     * E.g. related to files, user input, etc. Something too broad to put the exception in a module.
     */
    class FooException : public CommonException {
        public:

        /**
         * \brief Construct a new FooException object
         * 
         * \param message
         *  Error message.
         */
        FooException(const char* message) : CommonException(message) {}
    };

}}

/** @} */

#endif // SCRATCH_INCLUDE_GUARD__APP_COMMON_EXCEPTIONS_HPP
