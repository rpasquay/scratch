/**
 * \file linwood.hpp
 * \author Rafael Pasquay (maintainer.scratch@pasquay.com)
 * \brief Exemplary header file of target "app".
 * \version 1.0
 * \date 2018-10-21
 * 
 * \copyright Copyright (c) 2018
 */

#ifndef SCRATCH_INCLUDE_GUARD__APP_LINWOOD_LINWOOD_HPP
#define SCRATCH_INCLUDE_GUARD__APP_LINWOOD_LINWOOD_HPP

namespace scratch { namespace app {

    /**
     * \brief Check if a number is prime or not.
     * 
     * \param number
     *  The number to check if it is prime.
     * \returns true
     *  In case it is prime or might be prime.
     * \returns false
     *  Else.
     * \throws FooException
     *  If number is too big.
     */
    bool is_prime(unsigned int number);

}}

#endif // SCRATCH_INCLUDE_GUARD__APP_LINWOOD_LINWOOD_HPP
