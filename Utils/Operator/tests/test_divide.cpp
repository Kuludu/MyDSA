#include <gtest/gtest.h>
#include "../Divide.cpp"

TEST(DivideTest, IntegerDivision) {
    Divide<int, int> divide(10, 2);
    EXPECT_EQ(divide.execute(), 5);
}

TEST(DivideTest, FloatingPointDivision) {
    Divide<double, double> divide(10.0, 2.0);
    EXPECT_DOUBLE_EQ(divide.execute(), 5.0);
}

TEST(DivideTest, DivisionByZeroInteger) {
    EXPECT_THROW(({
        Divide<int, int> divide(10, 0);
    }), std::runtime_error);
}

TEST(DivideTest, DivisionByZeroFloat) {
    EXPECT_THROW(({
        Divide<int, double> divide(10, 0.0);
    }), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}