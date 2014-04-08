/** Copyright (c) 2014 Sergey Lisitsyn <lisitsyn.s.o@gmail.com>
 *
 * BSD 2-clause license (see LICENSE)
 */

#ifndef ALGORITHME_UTILS_H_
#define ALGORITHME_UTILS_H_

#include <type_traits>

namespace algorithme
{
	namespace
	{
		template <typename T>
		inline auto pointer(const T& v) -> decltype(&v)
		{
			return &v;
		}

		template <typename T>
		inline auto value(const T& v) -> decltype(*v)
		{
			return *v;
		}
	}
}

#endif
