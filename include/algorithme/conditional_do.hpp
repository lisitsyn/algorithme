/** Copyright (c) 2014 Sergey Lisitsyn <lisitsyn.s.o@gmail.com>
 *
 * BSD 2-clause license (see LICENSE)
 */

#ifndef ALGORITHME_CONDITIONAL_DO_H_
#define ALGORITHME_CONDITIONAL_DO_H_

#include <type_traits>

namespace algorithme 
{
	namespace impl
	{
		template <typename T>
		struct ConditionalTemporary
		{
			ConditionalTemporary() = delete;
			ConditionalTemporary& operator=(const ConditionalTemporary& other) = delete;

			inline ConditionalTemporary(const T& action_) : action(action_), do_that(true)
			{
			}
			inline ~ConditionalTemporary()
			{
				if (do_that) 
				{
					action();
				}
			}

			inline const ConditionalTemporary& when(bool condition) const
			{
				do_that = condition;
			}

			T action;
			mutable bool do_that;
		};
	}

	namespace
	{
		template <typename T>
		inline impl::ConditionalTemporary<T> conditional_do(const T& action)
		{
			return impl::ConditionalTemporary<T>(action);
		}
	}
}

#endif
