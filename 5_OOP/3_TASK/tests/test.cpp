#include "add.hpp"
#include <gtest/gtest.h>

TEST(AddTestSuit, TestNormal) {
	EXPECT_EQ((normal::add(5, 2)), 7);
}

TEST(AddTestSuit, TestFailedExpect) {
	EXPECT_NE((normal::add(23, 32)), 55);
	EXPECT_NE((normal::add(67, 0)), 67);
}

TEST(AddTestSuit, TestFailedAssert) {
	ASSERT_NE((normal::add(23, 32)), 55);
	EXPECT_NE((normal::add(67, 0)), 67);
}
