#include "gtest/gtest.h"
#include "lib.h"

TEST(testMain, testMainVersion)
{
	ASSERT_GT(version(), 0);
}

TEST(testMain, testParseByte)
{
    EXPECT_EQ(parseByte("0"), 0);
    EXPECT_EQ(parseByte("255"), 255);
    EXPECT_THROW(parseByte("256"), std::out_of_range);
    EXPECT_THROW(parseByte("-1"), std::out_of_range);
    EXPECT_THROW(parseByte("abc"), std::invalid_argument);
    EXPECT_THROW(parseByte("123a"), std::invalid_argument);
}

TEST(testMain, testSplitString)
{
    SS str = "1.2.3.4";
    std::vector<SS> expected = {"1", "2", "3", "4"};
    std::vector<SS> result = splitString(str, '.');
    EXPECT_EQ(result, expected);

    str = "10.20.30.40";
    expected = {"10", "20", "30", "40"};
    result = splitString(str, '.');
    EXPECT_EQ(result, expected);

    str = "1.2";
    expected = {"1", "2"};
    result = splitString(str, '.');
    EXPECT_EQ(result, expected);

    str = "1.2.3.4.5";
    expected = {"1", "2", "3", "4", "5"};
    result = splitString(str, '.');
    EXPECT_EQ(result, expected);
}

TEST(testMain, testParseIp)
{
    SS str = "1.2.3.4";
    IP expected = std::make_tuple(1, 2, 3, 4);
    IP result = parseIp(str);
    EXPECT_EQ(result, expected);

    str = "255.255.255.255";
    expected = std::make_tuple(255, 255, 255, 255);
    result = parseIp(str);
    EXPECT_EQ(result, expected);

    str = "0.0.0.0";
    expected = std::make_tuple(0, 0, 0, 0);
    result = parseIp(str);
    EXPECT_EQ(result, expected);

    str = "1.2.3";
    EXPECT_THROW(parseIp(str), std::invalid_argument);

    str = "1.2.3.4.5";
    EXPECT_THROW(parseIp(str), std::invalid_argument);

    str = "1.2.3.a";
    EXPECT_THROW(parseIp(str), std::invalid_argument);
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}