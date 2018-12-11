/**
 * \file ruben.hpp
 * \author Rafael Pasquay (maintainer.scratch@pasquay.com)
 * \brief Public header of static library "Ruben".
 * \version 1.0
 * \date 2018-10-21
 * 
 * \copyright Copyright (c) 2018
 * 
 * \ingroup lib_ruben
 * \addtogroup lib_ruben
 * @{
 */

#ifndef SCRATCH_INCLUDE_GUARD__LIB_RUBEN_RUBEN_HPP
#define SCRATCH_INCLUDE_GUARD__LIB_RUBEN_RUBEN_HPP

#include "scratch/lib_ruben/exceptions.hpp"

namespace scratch { namespace ruben {

/**
 * \brief Class as part of a static library.
 * 
 * Ruben has a secret. He can give it to or throw it at you.
 */
class Ruben {

public:

    /**
     * \brief Construct a new Ruben object.
     * 
     * Initializes Ruben's secret to 42.
     */
    Ruben();

    Ruben(const Ruben& other) = default;

    Ruben(Ruben&& other) = default;

    Ruben& operator=(const Ruben& other) = default;

    Ruben& operator=(Ruben&& other) = default;

    ~Ruben() = default;

    /**
     * \brief Get Ruben's secret number.
     * 
     * \returns unsigned int
     *  The secret number of Ruben.
     */
    unsigned int get_secrect() const;

    /**
     * \brief Set Ruben's secret.
     * 
     * \param secret
     *  The new secret number for Ruben.
     */
    void set_secrect(const unsigned int secret);

    /**
     * \brief Throw an exception telling Ruben's secret.
     * 
     * \throws
     *  An exception containing the secret.
     */
    void throw_secrect() const;

private:

    unsigned int rubens_secret; /**< Ruben's secret number. */

};

}}

#endif // SCRATCH_INCLUDE_GUARD__LIB_RUBEN_RUBEN_HPP

/** @} */
