/** Copyright (c) 2014 Sergey Lisitsyn <lisitsyn.s.o@gmail.com>
 *
 * BSD 2-clause license (see LICENSE)
 */

#ifndef ALGORITHME_BASICIO_H_
#define ALGORITHME_BASICIO_H_

#include <iostream>

namespace algorithme
{

	namespace 
	{
		/** Reads value from the provided stream (std::cin by default).
		 * Modifies given value in-place!
		 *
		 * Being inlined gives no overhead.
		 */
		template <typename T, typename S=std::istream>
		inline void read(T& variable, S& stream = std::cin)
		{
			stream >> variable;
		}

		/** Writes value to the provided stream (std::cout by default).
		 *
		 * Being inlined gives no overhead.
		 */
		template <typename T, typename S=std::istream>
		inline void write(const T& variable, S& stream = std::cout)
		{
			stream << variable;
		}
		
		/** Writes value as line to the provided stream (std::cout by default).
		 *
		 * Being inlined gives no overhead.
		 */
		template <typename T, typename S=std::istream>
		inline void writeln(const T& variable, S& stream = std::cout)
		{
			stream << variable << std::endl;
		}
	}
}

#endif
