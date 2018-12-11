/**
 * \file test_rockwell.cpp
 * \author Rafael Pasquay (maintainer.scratch@pasquay.com)
 * \brief Tests for code in file rockwell.hpp.
 * \version 0.1
 * \date 2018-12-11
 * 
 * @copyright Copyright (c) 2018
 * 
 * \ingroup lib_rockwell
 * \addtogroup lib_rockwell
 * @{
 */

#include <gtest/gtest.h> // Google Test
#include <string>
#include "scratch/lib_rockwell/rockwell.hpp"

TEST(RockwellTest, get_value) {

    scratch::rockwell::Rockwell<int> rockwell_int(123);

    ASSERT_EQ(123, rockwell_int.get_value());

}

TEST(RockwellTest, name_value) {

    scratch::rockwell::Rockwell<int> rockwell_int(123);

    ASSERT_EQ(std::string("int"), rockwell_int.name_type());

}

/** @} */