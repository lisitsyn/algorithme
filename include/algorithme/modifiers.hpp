/** Copyright (c) 2014 Sergey Lisitsyn <lisitsyn.s.o@gmail.com>
 *
 * BSD 2-clause license (see LICENSE)
 */

#ifndef ALGORITHME_MODIFIERS_H_
#define ALGORITHME_MODIFIERS_H_

#include <type_traits>

namespace algorithme 
{
	namespace impl
	{
		template <typename Type, typename Policy>
		struct modifier
		{
			modifier(const modifier& other);
			modifier& operator=(const modifier& other);
			inline modifier(Type& v) : value(v), parameter(Policy::default_parameter)
			{
			}
			inline const modifier& when(const bool condition) const
			{
				do_that = condition;
				return *this;
			}
			inline const modifier& by(const typename Policy::Parameter& parameter) const
			{
				this->parameter = parameter;
				return *this;
			}
			inline const modifier& with(const typename Policy::Parameter& parameter) const
			{
				this->parameter = parameter;
				return *this;
			}
			inline ~modifier()
			{
				static const Policy policy;
				if (do_that)
				{
					policy(value, parameter);
				}
			}
			Type& value;
			mutable typename Policy::Parameter parameter;
			mutable bool do_that;
		};

		template <typename Type>
		struct modifying_policy
		{
			typedef typename std::remove_volatile<Type>::type Parameter;
		};

		template <typename Type>
		struct addition_policy : public modifying_policy<Type>
		{
			typedef typename modifying_policy<Type>::Parameter Parameter;
			static const Parameter default_parameter = 1;
			inline void operator()(Type& v, const Parameter& p) const
			{
				v += p;
			}
		};

		template <typename Type>
		struct subtraction_policy : public modifying_policy<Type>
		{
			typedef typename modifying_policy<Type>::Parameter Parameter;
			static const Parameter default_parameter = 1;
			inline void operator()(Type& v, const Parameter& p) const
			{
				v -= p;
			}
		};

		template <typename Type>
		struct printing_policy
		{
			typedef std::string Parameter;
			static const Parameter default_parameter;
			inline void operator()(Type& v, const Parameter& p) const
			{
				std::cout << p << v << std::endl;
			}
		};
	}

	template <typename T>
	inline const impl::modifier<T, impl::addition_policy<T> > 
	increase(T& v)
	{
		return impl::modifier<T, impl::addition_policy<T> >(v);
	}

	template <typename T>
	inline const impl::modifier<T, impl::subtraction_policy<T> > 
	decrease(T& v)
	{
		return impl::modifier<T, impl::subtraction_policy<T> >(v);
	}

	template <typename T>
	inline const impl::modifier<T, impl::printing_policy<T> > 
	print(T& v)
	{
		return impl::modifier<T, impl::printing_policy<T> >(v);
	}

}

#endif
