#include <gtest/gtest.h>
#include <algorithme/basic_io.hpp>

#include <string>

TEST(BasicIO,Read)
{
	int i = 0;
	std::stringstream ss;
	ss << 3;
	algorithme::read(i, ss);
	ASSERT_EQ(i, 3);
}

TEST(BasicIO,Write)
{
	int i = 0;
	std::stringstream ss;
	algorithme::write(3, ss);
	ss >> i;
	ASSERT_EQ(i, 3);
}
