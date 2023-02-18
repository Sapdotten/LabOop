#include <gtest/gtest.h>

#include <character/character.h>

TEST(FunctionsTests, SumStubTest1) {
    // Arrange
    int num = 2;
    int pow = 3;
    
    // Act
    int r = pow_stub(num, pow);
    
    // Assert
    EXPECT_EQ(r, 8);
}

TEST(FunctionsTests, SumStubTest2) {
    // Arrange
    int num = 5;
    int pow = 4;
    
    // Act
    int r = pow_stub(num, pow);
    
    // Assert
    EXPECT_EQ(r, 625);
}

TEST(FunctionsTests, SumStubTest3) {
    // Arrange
    int num = -3;
    int pow = 3;

    // Act
    int r = pow_stub(num, pow);

    // Assert
    EXPECT_EQ(r, -27);
}
TEST(FunctionsTests, SumStubTest4) {
    // Arrange
    int num = 8;
    int pow = 2;

    // Act
    int r = pow_stub(num, pow);

    // Assert
    EXPECT_EQ(r, 64);
}