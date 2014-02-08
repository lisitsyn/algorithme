#include <gtest/gtest.h>
#include <algorithme/modifiers.hpp>

#include <string>

TEST(Modifiers, IncreaseTrue)
{
	volatile int i = 0;
	algorithme::increase(i).when(true);
	ASSERT_EQ(i, 1);
}

TEST(Modifiers, IncreaseByTrue)
{
	volatile int i = 0;
	algorithme::increase(i).by(3).when(true);
	ASSERT_EQ(i, 3);
}

TEST(Modifiers, IncreaseFalse)
{
	volatile int i = 0;
	algorithme::increase(i).when(false);
	ASSERT_EQ(i, 0);
}

TEST(Modifiers, DecreaseTrue)
{
	volatile int i = 0;
	algorithme::decrease(i).when(true);
	ASSERT_EQ(i, -1);
}

TEST(Modifiers, DecreaseByTrue)
{
	volatile int i = 0;
	algorithme::decrease(i).by(3).when(true);
	ASSERT_EQ(i, -3);
}

TEST(Modifiers, DecreaseFalse)
{
	volatile int i = 0;
	algorithme::decrease(i).when(false);
	ASSERT_EQ(i, 0);
}
