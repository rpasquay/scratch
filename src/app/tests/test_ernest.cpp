#include <gtest/gtest.h> // Google Test
#include "app/ernest.hpp"
#include "app/exceptions.hpp"

/**
 * \brief Test Ernest's method `factorial()`.
 */
TEST(TestErnest, factorial) {

    ASSERT_EQ(1, scratch::app::factorial(0));

    ASSERT_EQ(120, scratch::app::factorial(5));

    ASSERT_THROW(scratch::app::factorial(42), scratch::app::FooException);

}
