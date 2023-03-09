#include <gtest/gtest.h>

class CodeTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(CodeTest, BasicAssertions)
{
    ASSERT_EQ(4, 4);
};
