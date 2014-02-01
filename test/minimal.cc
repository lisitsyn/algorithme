#include <gtest/gtest.h>
#include <algorithme/algorithme.hpp>

#include <string>

TEST(Minimal,SortString)
{
	std::string s = "abcdefgh";
	algorithme::sort(s);
}

TEST(Minimal,SortVector)
{
	std::vector<int> v = {3,4,5,6};
	algorithme::sort(v);
}

TEST(Minimal,MinElementString)
{
	std::string s = "abcdefgh";
	algorithme::min_element(s);
}

TEST(Minimal,MaxElementString)
{
	std::string s = "abcdefgh";
	algorithme::max_element(s);
}

TEST(Minimal,MinMaxElementString)
{
	std::string s = "abcdefgh";
	algorithme::minmax_element(s);
}

TEST(Minimal,MinElementVector)
{
	std::vector<int> v = {3,4,5,6};
	algorithme::min_element(v);
}

TEST(Minimal,MaxElementVector)
{
	std::vector<int> v = {3,4,5,6};
	algorithme::max_element(v);
}

TEST(Minimal,MinMaxElementVector)
{
	std::vector<int> v = {3,4,5,6};
	algorithme::minmax_element(v);
}


