/**
 * \file test_ruben.cpp
 * \author Rafael Pasquay (rafael@pasquay.com)
 * \brief Tests for code in file ruben.cpp.
 * \version 0.1
 * \date 2018-10-30
 * 
 * @copyright Copyright (c) 2018
 * 
 * \ingroup lib_ruben
 * \addtogroup lib_ruben
 * @{
 */

#include "test_ruben_fixture.hpp"
#include "scratch/lib_ruben/exceptions.hpp"

/**
 * \brief Test method `get_secret()`.
 */
TEST_F(RubenTest, get_secrect) {

    ASSERT_EQ(42, test_ruben.get_secrect());

};

/**
 * \brief Test method `set_secret()`.
 */
TEST_F(RubenTest, set_secrect) {

    ASSERT_EQ(42, test_ruben.get_secrect());
    test_ruben.set_secrect(24);
    ASSERT_EQ(24, test_ruben.get_secrect());

}

/**
 * \brief Test method `throw_secret()`.
 */
TEST_F(RubenTest, throw_secrect) {

    ASSERT_THROW(test_ruben.throw_secrect(), scratch::ruben::SecretException);

}

/** @} */
