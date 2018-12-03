/**
 * \file test_ruben_fixture.hpp
 * \author Rafael Pasquay (rafael@pasquay.com)
 * \brief Fixture class for tests in file test_ruben.cpp.
 * \version 0.1
 * \date 2018-10-30
 * 
 * @copyright Copyright (c) 2018
 * 
 * \ingroup lib_ruben
 * \addtogroup lib_ruben
 * @{
 */
#include <gtest/gtest.h> // Google Test
#include "scratch/lib_ruben/ruben.hpp"

/**
 * \brief Fixture class for tests of Ruben's methods.
 * 
 * All test cases are methods of this class thats why one can simply access everything defined in
 * here like a regular method/member.
 */
class RubenTest : public ::testing::Test {
protected:

    RubenTest() : test_ruben() {}

    /**
     * \brief Instance of class Ruben wich is available to all test cases.
     * 
     * Inside test cases access this instance like a regular class member.
     */
    scratch::ruben::Ruben test_ruben; 

};

/** @} */
