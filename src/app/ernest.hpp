/**
 * \file ernest.hpp
 * \author Rafael Pasquay (rafael@pasquay.com)
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

#ifndef SCRATCH_INCLUDE_GUARD__APP_ERNEST_ERNEST_HPP
#define SCRATCH_INCLUDE_GUARD__APP_ERNEST_ERNEST_HPP

namespace scratch { namespace app {

/**
 * \brief Ernest likes factorials. He'll compute them for you.
 * 
 * \param num
 *  Number to compute factorial of.
 * \returns unsigned int
 *  Factorial of num.
 * \throws FooException
 *  If factorial of num exceeds numerical limits.
 */
unsigned int factorial(unsigned int num);

}}

/** @} */

#endif // SCRATCH_INCLUDE_GUARD__APP_ERNEST_ERNEST_HPP
