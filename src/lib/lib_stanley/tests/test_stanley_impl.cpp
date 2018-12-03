/**
 * \file test_stanley_impl.cpp
 * \author Rafael Pasquay (rafael@pasquay.com)
 * \brief Tests for code in file stanley_impl.cpp.
 * \version 0.1
 * \date 2018-10-30
 * 
 * @copyright Copyright (c) 2018
 * 
 * \ingroup lib_stanley
 * \addtogroup lib_stanley
 * @{
 */

#include <memory> // std::unique_prt
#include "test_stanley_impl_fixture.hpp"

/**
 * \brief Test of method `get_contianer()`.
 */
TEST_F(StanleyTest, get_container) {

    std::unique_ptr<scratch::stanley::StanleysContainer> container(stanley.get_container());

    ASSERT_NE(nullptr, container);

}

/**
 * \brief Test of method `get_secret()`.
 */
TEST_F(StanleyTest, container_get_secret) {

    ASSERT_EQ(42, container.get_secret());

}

/** @} */
