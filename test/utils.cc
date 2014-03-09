#include <gtest/gtest.h>
#include <algorithme/utils.hpp>

using algorithme::value;
using algorithme::pointer;

TEST(Utils,PointerValue)
{
	int i = 3;
	ASSERT_EQ(value(pointer(i)), i);
}

TEST(Utils,PointerPointerValueValue)
{
	int i = 3;
	ASSERT_EQ(value(value(pointer(pointer(i)))), i);
}

