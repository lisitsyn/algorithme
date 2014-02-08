#include <gtest/gtest.h>
#include <algorithme/containers.hpp>

#include <string>

TEST(Containers,SortString)
{
	std::string s = "abcdefgh";
	algorithme::sort(s);
}

TEST(Containers,SortVector)
{
	std::vector<int> v = {3,4,5,6};
	algorithme::sort(v);
}

TEST(Containers,MinElementString)
{
	std::string s = "abcdefgh";
	algorithme::min_element(s);
}

TEST(Containers,MaxElementString)
{
	std::string s = "abcdefgh";
	algorithme::max_element(s);
}

TEST(Containers,MinMaxElementString)
{
	std::string s = "abcdefgh";
	algorithme::minmax_element(s);
}

TEST(Containers,MinElementVector)
{
	std::vector<int> v = {3,4,5,6};
	algorithme::min_element(v);
}

TEST(Containers,MaxElementVector)
{
	std::vector<int> v = {3,4,5,6};
	algorithme::max_element(v);
}

TEST(Containers,MinMaxElementVector)
{
	std::vector<int> v = {3,4,5,6};
	algorithme::minmax_element(v);
}


