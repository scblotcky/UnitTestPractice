/**
 * Unit Tests for Password class
 **/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
protected:
	PasswordTest() {}		   // constructor runs before each test
	virtual ~PasswordTest() {} // destructor cleans up after tests
	virtual void SetUp() {}	   // sets up before each test (after constructor) 
	virtual void TearDown() {} // clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, number_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("12345");

	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, single_upper_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Lamp");

	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, no_lower_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AL1EN");

	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, all_lower_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("hello");

	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, no_letter_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("45.7");

	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, one_letter_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("S");

	ASSERT_EQ(false, actual);
}