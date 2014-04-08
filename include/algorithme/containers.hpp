/** Copyright (c) 2014 Sergey Lisitsyn <lisitsyn.s.o@gmail.com>
 *
 * BSD 2-clause license (see LICENSE)
 */

#ifndef ALGORITHME_CONTAINERS_H_
#define ALGORITHME_CONTAINERS_H_

#include <algorithm>
#include <iterator>

namespace algorithme
{

	namespace
	{
		/** Applies function to all elements of the container.
		 */
		template <typename Container, typename Function>
		inline void
		for_each(Container& container, Function function)
		{
			std::for_each(std::begin(container), std::end(container), function);
		}

		/** Sorts elements in the container using the provided comparator (default 
		 * comparator is operator< which induces ascending order).
		 *
		 * Uses std::sort. Not stable in means of sorting.
		 * While inlined gives no additional overhead.
		 */
		template <typename Container, typename Comparator = std::less<typename Container::value_type> >
		inline void
		sort(Container& container, Comparator comparator = Comparator())
		{
			std::sort(std::begin(container), std::end(container), comparator);
		}

		/** Sorts elements in the container using the provided comparator (default
		 * comparator is operator< which induces ascending order).
		 *
		 * Uses std::stable_sort. Stable in means of sorting.
		 * While inlined gives no additional overhead.
		 */
		template <typename Container, typename Comparator = std::less<typename Container::value_type> >
		inline void 
		stable_sort(Container& container, Comparator comparator = Comparator())
		{
			std::stable_sort(std::begin(container), std::end(container), comparator);
		}

		/** Checks if the container is sorted using the provided comparator
		 * (default comparator is operator< which induces ascending order).
		 *
		 * Uses std::is_sorted. 
		 * While inlined gives no additional overhead.
		 */
		template <typename Container, typename Comparator = std::less<typename Container::value_type> >
		inline bool
		is_sorted(Container& container, Comparator comparator = Comparator())
		{
			std::is_sorted(std::begin(container), std::end(container), comparator);
		}

		/** Returns an iterator to the first element of the container that is 
		 * equal to the provided value.
		 *
		 * Uses std::find. Equality is tested using operator==.
		 * While inlined gives no additional overhead.
		 */
		template <typename Container>
		inline typename Container::iterator
		find(Container& container, const typename Container::value_type& value)
		{
			return std::find(std::begin(container), std::end(container), value); 
		}

		/** Returns an iterator to the minimal element of the container using
		 * the provided comparator (uses operator< by default).
		 *
		 * Uses std::min_element.
		 * While inlined gives no additional overhead.
		 */
		template <typename Container, typename Comparator = std::less<typename Container::value_type> >
		inline typename Container::iterator
		min_element(Container& container, Comparator comparator = Comparator())
		{
			return std::min_element(std::begin(container), std::end(container), comparator);
		}

		/** Returns an iterator to the maximal element of the container using
		 * the provided comparator (uses operator< by default).
		 *
		 * Uses std::max_element.
		 * While inlined gives no additional overhead.
		 */
		template <typename Container, typename Comparator = std::less<typename Container::value_type> >
		inline typename Container::iterator
		max_element(Container& container, Comparator comparator = Comparator())
		{
			return std::max_element(std::begin(container), std::end(container), comparator);
		}

		/** Returns a pair of iterators to the minimal element of the container as first and
		 * the maximal element of the container as second. 
		 * Uses the provided comparator (operator< by default).
		 *
		 * Uses std::minmax_element.
		 * While inlined gives no additional overhead.
		 */
		template <typename Container, typename Comparator = std::less<typename Container::value_type> >
		inline std::pair<typename Container::iterator, typename Container::iterator>
		minmax_element(Container& container, Comparator comparator = Comparator())
		{
			return std::minmax_element(std::begin(container), std::end(container), comparator);
		}
	}
}
#endif
