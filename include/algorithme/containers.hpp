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

	template <typename Container, typename Comparator = std::less<typename Container::value_type> >
	inline void
	sort(Container& container, Comparator comparator = Comparator())
	{
		std::sort(std::begin(container), std::end(container), comparator);
	}

	template <typename Container, typename Comparator = std::less<typename Container::value_type> >
	inline void 
	stable_sort(Container& container, Comparator comparator = Comparator())
	{
		std::stable_sort(std::begin(container), std::end(container), comparator);
	}

	template <typename Container>
	inline typename Container::iterator
	find(Container& container, const typename Container::value_type& value)
	{
		return std::find(std::begin(container), std::end(container), value); 
	}

	template <typename Container, typename Comparator = std::less<typename Container::value_type> >
	inline typename Container::iterator
	min_element(Container& container, Comparator comparator = Comparator())
	{
		return std::min_element(std::begin(container), std::end(container), comparator);
	}

	template <typename Container, typename Comparator = std::less<typename Container::value_type> >
	inline typename Container::iterator
	max_element(Container& container, Comparator comparator = Comparator())
	{
		return std::max_element(std::begin(container), std::end(container), comparator);
	}

	template <typename Container, typename Comparator = std::less<typename Container::value_type> >
	inline std::pair<typename Container::iterator, typename Container::iterator>
	minmax_element(Container& container, Comparator comparator = Comparator())
	{
		return std::minmax_element(std::begin(container), std::end(container), comparator);
	}

}
#endif
