#include <fmt/format.h>
#include <cppitertools/itertools.hpp>

#include <tuple>

int fib(int n) {
	int a = 0, b = 1;

	for ([[maybe_unused]] int i : iter::range(n)) {
		std::tie(a, b) = std::make_tuple(b, a + b);
	}

	return a;
}

int main() {
	for (int i : iter::range(15)) {
		fmt::print("fib({}) = {}\n", i, fib(i));
	}
}
