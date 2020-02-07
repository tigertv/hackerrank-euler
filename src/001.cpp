#include <iostream>

/******************************************************************************

If we list all the natural numbers below 10 that are multiples of 3 or 5, 
we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

******************************************************************************/

template <typename T>
T below_max(T i, T max) {
	T r = (max - 1) / i;
	return (r * (r + 1) * i) >> 1;
}

template <typename T>
T solution1(T a, T b, T max) {
	return below_max(a, max) + below_max(b, max) - below_max(a * b, max);
}

template <typename T>
T solution2(T a, T b, T max) {
	T r = (max - 1) / a;
	T sum = r * (r + 1) * a;
	r = (max - 1) / b;
	sum += r * (r + 1) * b;
	r = (max - 1) / (a * b);
	sum -= r * (r + 1) * (a * b);
	return sum >> 1;
}

template <typename T>
T solution3(T a, T b, T max) {
	T sum = 0;
	for(T i = a; i < max; i += a) sum += i;
	for(T i = b; i < max; i += b) sum += i;
	T p = a * b;
	for(T i = p; i < max; i += p) sum -= i;
	return sum;
}

template <typename T>
T solution4(T a, T b, T max) {
	T i = a * b;
	T n = (max - 1) / i;

	max = (max - 1) % i;
	T na = max / a;
	T nb = max / b;

	i *= n;
	T sum = (
		i * (n * (a + b - 1) + 1) + 
		a * na * (na + 1) + 
		b * nb * (nb + 1)
	) / 2 + i * (na + nb);
	
	return sum;
}

template <typename T>
T solution5(T a, T b, T max) {
	T sum = 0;
	T ia = a - 1;
	T ib = b - 1;
	for(T i = 1; i < max; i++) {
		if (ia == 0) {
			sum += i;
			ia = a;
		}
		if (ib == 0) {
			if (ia != a) {
				sum += i;
			} 
			ib = b;
		}

		ia--;
		ib--;
	}
	return sum;
}


int main() {
	// gcd(a,b) = 1
	const uint a = 3;
	const uint b = 5;
	const uint max = 1000;

	uint sum1 = solution1(a, b, max);
	uint sum2 = solution2(a, b, max);
	uint sum3 = solution3(a, b, max);
	uint sum4 = solution4(a, b, max);
	uint sum5 = solution5(a, b, max);

	std::cout << sum1 << std::endl;
	std::cout << sum2 << std::endl;
	std::cout << sum3 << std::endl;
	std::cout << sum4 << std::endl;
	std::cout << sum5 << std::endl;

	return 0;
}
