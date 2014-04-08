#include <gtest/gtest.h>
#include <algorithme/containers.hpp>

#include <string>

class ContainersStringTest : public testing::Test 
{
protected:
	virtual void SetUp()
	{
		static const char alphabet[] = {"abcdefghijklmnopqrstuvw0123456789"};
		static const int alphabet_size = sizeof(alphabet)/sizeof(alphabet[0]);
		static const int min_size = 10;
		static const int max_size = 100;

		std::string test_string;
		test_string.reserve(max_size);
		std::generate_n(test_string.begin(), 10,//min_size + rand() % (max_size - min_size), 
				[]() -> char { return alphabet[rand() % alphabet_size]; });
		std::cout << "Test string " << test_string << "end";
		test_string_algorithme = test_string;
		test_string_std = test_string;
	}
	void TestResultsAreEqual()
	{
		EXPECT_EQ(test_string_algorithme, test_string_std) << "Fucker";
	}
	std::string test_string_algorithme;
	std::string test_string_std;
};

TEST_F(ContainersStringTest, Sort)
{
//	algorithme::sort(test_string_algorithme);
	std::sort(test_string_std.begin(), test_string_std.end());
	TestResultsAreEqual();
}

TEST(Containers,SortVector)
{
	std::vector<int> v = {1,6,2,9,3,0};
	algorithme::sort(v);
	ASSERT_EQ(std::is_sorted(v.begin(), v.end()), true);
}

TEST(Containers,IsSortedString)
{
	std::string s = "gfgdsfdsafds";
	std::sort(s.begin(), s.end());
	ASSERT_EQ(algorithme::is_sorted(s), true);
}

TEST(Containers,MinElementString)
{
	std::string s = "gfgdsfdsafds";
	ASSERT_EQ(*algorithme::min_element(s), 'a');
}

TEST(Containers,MaxElementString)
{
	std::string s = "gfgdsfdsafds";
	ASSERT_EQ(*algorithme::max_element(s), 's');
}

TEST(Containers,MinMaxElementString)
{
	std::string s = "gfgdsfdsafds";
	ASSERT_EQ(*(algorithme::minmax_element(s).first), 'a');
	ASSERT_EQ(*(algorithme::minmax_element(s).second), 's');
}

TEST(Containers,MinElementVector)
{
	std::vector<int> v = {3,2,6,4};
	ASSERT_EQ(*algorithme::min_element(v), 2);
}

TEST(Containers,MaxElementVector)
{
	std::vector<int> v = {3,2,6,4};
	ASSERT_EQ(*algorithme::max_element(v), 6);
}

TEST(Containers,MinMaxElementVector)
{
	std::vector<int> v = {3,2,6,4};
	ASSERT_EQ(*(algorithme::minmax_element(v).first), 2);
	ASSERT_EQ(*(algorithme::minmax_element(v).second), 6);
}


