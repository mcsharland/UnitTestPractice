/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_string)
{
  Password my_password;
  int actual = my_password.count_leading_characters("");
  ASSERT_EQ(0, actual);
}

TEST(PasswordTest, multiple_single_letter)
{
  Password my_password;
  int actual = my_password.count_leading_characters("ZZZZZZZ");
  ASSERT_EQ(7, actual);
}

TEST(PasswordTest, multi_character)
{
  Password my_password;
  int actual = my_password.count_leading_characters("ZZzZzzZzZ");
  ASSERT_EQ(2, actual);
}

TEST(PasswordTest, no_repetition)
{
  Password my_password;
  int actual = my_password.count_leading_characters("abcdef");
  ASSERT_EQ(1, actual);
}

TEST(PasswordText, all_lowercase)
{
	Password my_password;
    int actual = my_password.has_mixed_case("abcdefgh");
	ASSERT_EQ(false, actual);
}

TEST(PasswordText, all_uppercase)
{
	Password my_password;
    int actual = my_password.has_mixed_case("ABCDEFGH");
	ASSERT_EQ(false, actual);
}

TEST(PasswordText, mixed_case)
{
	Password my_password;
    int actual = my_password.has_mixed_case("abCdeFgHI");
	ASSERT_EQ(true, actual);
}

TEST(PasswordText, single_mixed_case)
{
	Password my_password;
    int actual = my_password.has_mixed_case("aB");
	ASSERT_EQ(true, actual);
}

TEST(PasswordText, one_space)
{
	Password my_password;
    int actual = my_password.has_mixed_case(" ");
	ASSERT_EQ(false, actual);
}

TEST(PasswordText, empty_string)
{
	Password my_password;
    int actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordText, whitespace_seperated)
{
	Password my_password;
    int actual = my_password.has_mixed_case("a B");
	ASSERT_EQ(true, actual);
}