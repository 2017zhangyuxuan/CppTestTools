#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "hello.h"


using namespace testing;
class MyMock : public GMockTest {
public:
    MOCK_METHOD(int, func, (int a), (override));
};

TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
    EXPECT_EQ(hello(), "hello world");

}

TEST(HelloTest, TestGmock) {
    MyMock mock;
    EXPECT_CALL(mock, func(_)).WillOnce(Return(10));
    EXPECT_EQ(mock.func(1), 10);
}

