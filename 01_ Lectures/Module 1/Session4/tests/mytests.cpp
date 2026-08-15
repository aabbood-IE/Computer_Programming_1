#include <gtest/gtest.h>

extern "C" {
    #include "../include/sample_gtest/triangle.c"
}

// Test cases for getTriangleType function
TEST(TriangleTest, EquilateralTriangle) {
    EXPECT_EQ(getTriangleType(5, 5, 5), 1);
}

TEST(TriangleTest, IsoscelesTriangle) {
    EXPECT_EQ(getTriangleType(5, 5, 8), 2);
    EXPECT_EQ(getTriangleType(8, 5, 5), 2);
    EXPECT_EQ(getTriangleType(5, 8, 5), 2);
}

TEST(TriangleTest, ScaleneTriangle) {
    EXPECT_EQ(getTriangleType(3, 4, 5), 3);
    EXPECT_EQ(getTriangleType(5, 12, 13), 3);
    EXPECT_EQ(getTriangleType(8, 15, 17), 3);
}

TEST(TriangleTest, NotATriangle) {
    EXPECT_EQ(getTriangleType(1, 2, 3), 0);
    EXPECT_EQ(getTriangleType(2, 3, 1), 0);
    EXPECT_EQ(getTriangleType(3, 1, 2), 0);
}

TEST(TriangleTest, InvalidSideValue) {
    EXPECT_EQ(getTriangleType(0, 5, 5), -1);
    EXPECT_EQ(getTriangleType(5, 0, 5), -1);
    EXPECT_EQ(getTriangleType(5, 5, 0), -1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
