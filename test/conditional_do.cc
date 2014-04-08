#include <gtest/gtest.h>
#include <algorithme/conditional_do.hpp>

#include <string>

TEST(ConditionalDo, IncreaseValue)
{
	volatile int i = 0;
	algorithme::conditional_do([&] () { i++; }).when(true);
	ASSERT_EQ(i, 1);
}
