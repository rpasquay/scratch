/**
 * \file rockwell.hpp
 * \author Rafael Pasquay (maintainer.scratch@pasquay.com)
 * \brief Public header of header-only library "Rockwell".
 * \version 1.0
 * \date 2018-10-21
 * 
 * \copyright Copyright (c) 2018
 * 
 * \ingroup lib_rockwell
 * \addtogroup lib_rockwell
 * @{
 */

#ifndef SCRATCH_INCLUDE_GUARD__LIB_ROCKWELL_ROCKWELL_HPP
#define SCRATCH_INCLUDE_GUARD__LIB_ROCKWELL_ROCKWELL_HPP

#include <string>

namespace scratch { namespace rockwell {

/**
 * \brief Very simple method to get a type's name at compile time using SFINAE.
 * 
 * This method is used if no specialised function for type T could be found. 
 * 
 * \returns
 *  It always returns "unknown value"
 */
template<typename T>
std::string name_a_type(T) {
    return std::string("unknown value");
}

/**
 * \brief Very simple method to get a type's name at compile time using SFINAE.
 * 
 * Specialization for type "int"
 * This method is used if T is of type int. 
 * 
 * \returns
 *  It always returns "int".
 */
template<>
std::string name_a_type<int>(int) {
    return std::string("int");
} 

/**
 * \brief Very simple method to get a type's name at compile time using SFINAE.
 * 
 * Specialization for type "float"
 * This method is used if T is of type float. 
 * 
 * \returns
 *  It always returns "float".
 */
template<>
std::string name_a_type<float>(float) {
    return std::string("float");
} 

/**
 * \brief Meet Rockwell. He's living in a header-only library and can remember a value !
 *
 * \tparam T
 *  The type of Rockwell's value.
 */
template<typename T>
class Rockwell {
public:

    /**
     * \brief Construct a Rockwell object by giving him a value to remember.
     * 
     * \param value
     *  Value for Rockwell to remember.
     */
    explicit Rockwell(T value);

    /**
     * \brief Get the value of Rockwell.
     * 
     * \returns
     *  The value which Rockwell remembers.
     */
    T get_value() const;

    /**
     * \brief Get the name of the type of the value that Rockwell stores.
     * 
     * \returns
     *  String holding the name of the type.
     *  E.g "int" for int or"unknown type" for ... unknown types.
     */
    std::string name_type() const;

private:

    /**
     * \brief The value only Rockwell knows.
     */
    T value_; 

};

}}

#include "rockwell.inl" // include template definitions

#endif // SCRATCH_INCLUDE_GUARD__LIB_ROCKWELL_ROCKWELL_HPP

/** @} */
