/**
 * \file test_stanley_impl_fixture.hpp
 * \author Rafael Pasquay (rafael@pasquay.com)
 * \brief Fixture class for tests in file test_stanley_impl.cpp.
 * \version 0.1
 * \date 2018-10-30
 * 
 * @copyright Copyright (c) 2018
 * 
 * \ingroup lib_stanley
 * \addtogroup lib_stanley
 * @{
 */
#include <string> // std::stoi
#include <gtest/gtest.h> // Google Test
#include "stanley_impl.hpp"

/**
 * \brief Fixture class for tests of classes StanleyImpl and StanleyContainerImpl.
 */
class StanleyTest : public ::testing::Test {

protected:

    StanleyTest() : container("foo"), stanley() {};

    /**
     * \brief Instance of class StanleyImpl for usage by tests.
     */
    scratch::stanley::StanleyImpl stanley;

    /**
     * \brief Instance of class StanleyContainerImpl for usage by tests.
     */
    scratch::stanley::StanleysContainerImpl container;

};

/** @} */
