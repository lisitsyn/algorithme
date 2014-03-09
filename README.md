Algorithme
==========

Some set of wrappers on top of the STL aimed to achieve less verbose code. Pretty
experimental stuff.

As a basic example - instead of

	std::sort(container.begin(), container.end())

we can use shorter

	algorithme::sort(container);

or instead of

	if (condition)
		i++;

some kind of magic

	algorithme::increase(i).when(condition);

