#include <fmt/format.h>
#include <cppitertools/itertools.hpp>

int fib(int n) {
	int a = 0, b = 1;

	for ([[maybe_unused]] int i : iter::range(n)) {
		auto tmp = b;
		b = a + b;
		a = tmp;
	}

	return a;
}

int main() {
	for (int i : iter::range(15)) {
		fmt::print("fib({}) = {}\n", i, fib(i));
	}
}
