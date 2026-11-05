#include <gtest/gtest.h>
#include "Rectangle.hpp"

TEST(RectangleTest, DefaultConstructor) {
    Rectangle r;
    EXPECT_DOUBLE_EQ(r.getSideA(), 0.0);
    EXPECT_DOUBLE_EQ(r.getSideB(), 0.0);
    EXPECT_EQ(r.values_size, 6);
}

TEST(RectangleTest, InitConstructor) {
    Rectangle r(6.0, 7.0);
    EXPECT_DOUBLE_EQ(r.getSideA(), 6.0);
    EXPECT_DOUBLE_EQ(r.getSideB(), 7.0);
}

TEST(RectangleTest, InitConstructorNormalizes) {
    Rectangle r(-6.7, 6e7);
    EXPECT_DOUBLE_EQ(r.getSideA(), 0.0);   // clamped from -1
    EXPECT_DOUBLE_EQ(r.getSideB(), 1e6);   // clamped from 2e6
}

TEST(RectangleTest, CopyConstructor) {
    Rectangle a(6.0, 7.0);
    Rectangle b(a);
    EXPECT_DOUBLE_EQ(b.getSideA(), 6.0);
    EXPECT_DOUBLE_EQ(b.getSideB(), 7.0);
    EXPECT_EQ(b.values_size, a.values_size);
}

TEST(RectangleTest, AssignmentOperator) {
    Rectangle a(4.0, 6.0);
    Rectangle b;
    b = a;
    EXPECT_DOUBLE_EQ(b.getSideA(), 4.0);
    EXPECT_DOUBLE_EQ(b.getSideB(), 6.0);
    EXPECT_EQ(b.values_size, a.values_size);
}

TEST(RectangleTest, SettersNormalize) {
    Rectangle r;
    r.setSideA(-5);
    r.setSideB(2e6);
    EXPECT_DOUBLE_EQ(r.getSideA(), 0.0);
    EXPECT_DOUBLE_EQ(r.getSideB(), 1e6);
}

TEST(RectangleTest, CalcArea) {
    Rectangle r(3.0, 5.0);
    EXPECT_DOUBLE_EQ(r.calcArea(), 15.0);
}
