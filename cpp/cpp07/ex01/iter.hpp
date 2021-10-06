#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void iter(T *arr, int n, void (*f)(const T&))
{
	for (int i = 0; i < n; i++)
		f(arr[i]);
}

#endif
