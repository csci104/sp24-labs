#include <gtest/gtest.h>

#include "library.hpp"

TEST(SimpleReturnTest, Returns42)
{
    EXPECT_EQ(returns_42(), 42);
};

TEST(SimpleReturnTest, Returns37)
{
    EXPECT_EQ(returns_37(), 37);
};

TEST(SummationTest, SumsAreEqual)
{
    EXPECT_EQ(
        sum_arithmetic_sequence_closed_form(42),
        sum_arithmetic_sequence_recursive(42));

    EXPECT_EQ(
        sum_arithmetic_sequence_recursive(42),
        sum_arithmetic_sequence_loop(42));
}
