#include <gtest/gtest.h> // Google Test
#include "app/linwood.hpp"
#include "app/exceptions.hpp"

/**
 * \brief Test Linwood's method `is_prime()`.
 */
TEST(TestLinwood, is_prime) {

    ASSERT_FALSE(scratch::app::is_prime(4));

    ASSERT_TRUE(scratch::app::is_prime(17));

    ASSERT_THROW(scratch::app::is_prime(200), scratch::app::FooException);

}
