/** Copyright (c) 2014 Sergey Lisitsyn <lisitsyn.s.o@gmail.com>
 *
 * BSD 2-clause license (see LICENSE)
 */

#ifndef ALGORITHME_BASICIO_H_
#define ALGORITHME_BASICIO_H_

#include <iostream>

namespace algorithme
{

	template <typename T, typename S=std::istream>
	void read(T& variable, S& stream = std::cin)
	{
		stream >> variable;
	}

	template <typename T, typename S=std::istream>
	void write(const T& variable, S& stream = std::cout)
	{
		stream << variable;
	}
	
	template <typename T, typename S=std::istream>
	void writeln(const T& variable, S& stream = std::cout)
	{
		write(variable, stream);
		stream << std::endl;
	}

}

#endif
