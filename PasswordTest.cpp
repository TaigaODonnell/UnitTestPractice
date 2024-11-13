/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PracticeTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PracticeTest, no_letter_password){
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}
TEST(PracticeTest, number_password){
	Password my_password;
	int actual = my_password.count_leading_characters("3");
	ASSERT_EQ(1, actual);
}
TEST(PracticeTest, non_letter_password){
	Password my_password;
	int actual = my_password.count_leading_characters("*()*");
	ASSERT_EQ(1, actual);
}
TEST(PracticeTest, normal_password){
	Password my_password;
	int actual = my_password.count_leading_characters("AAABA");
	ASSERT_EQ(3, actual);
}

// =============================================================================

// =============================================================================
TEST(PracticeTest, password_with_capital_and_lower){
	Password my_password;
	bool actual = my_password.has_mixed_case("AaAaa");
	ASSERT_EQ(true, actual);
}

TEST(PracticeTest, password_correct_case){
	Password my_password;
	bool actual = my_password.has_mixed_case("HelloWorld");
	ASSERT_EQ(true, actual);
}

TEST(PracticeTest, password_with_lower_and_capital_and_number){
	Password my_password;
	bool actual = my_password.has_mixed_case("aAaAa21314");
	ASSERT_EQ(true, actual);
}

TEST(PracticeTest, password_with_lower_and_number){
	Password my_password;
	bool actual = my_password.has_mixed_case("aaaaa1");
	ASSERT_EQ(false, actual);
}

TEST(PracticeTest, password_with_number_and_capital){
	Password my_password;
	bool actual = my_password.has_mixed_case("A21A");
	ASSERT_EQ(false, actual);
}

TEST(PracticeTest, password_with_capital){
	Password my_password;
	bool actual = my_password.has_mixed_case("AAAAAA");
	ASSERT_EQ(false, actual);
}

TEST(PracticeTest, password_with_lower){
	Password my_password;
	bool actual = my_password.has_mixed_case("aaaaaa");
	ASSERT_EQ(false, actual);
}

TEST(PracticeTest, password_with_number){
	Password my_password;
	bool actual = my_password.has_mixed_case("123456");
	ASSERT_EQ(false, actual);
}

TEST(PracticeTest, password_with_special_character){
	Password my_password;
	bool actual = my_password.has_mixed_case("!@#$%^&*()");
	ASSERT_EQ(false, actual);
}

TEST(PracticeTest, password_with_nothing){
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}