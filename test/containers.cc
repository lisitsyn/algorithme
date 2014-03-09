#include <gtest/gtest.h>
#include <algorithme/containers.hpp>

#include <string>

TEST(Containers,SortString)
{
	std::string s = "gfgdsfdsafds";
	algorithme::sort(s);
	ASSERT_EQ(std::is_sorted(s.begin(), s.end()), true);
}

TEST(Containers,SortVector)
{
	std::vector<int> v = {1,6,2,9,3,0};
	algorithme::sort(v);
	ASSERT_EQ(std::is_sorted(v.begin(), v.end()), true);
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


